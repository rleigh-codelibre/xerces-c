/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id$
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include "XMLHarnessHandlers.hpp"
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax/SAXParseException.hpp>
#include <xercesc/sax/SAXException.hpp>
#include <xercesc/validators/common/Grammar.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/util/BinInputStream.hpp>

// ---------------------------------------------------------------------------
//  XMLHarnessHandlers: Constructors and Destructor
// ---------------------------------------------------------------------------
XMLHarnessHandlers::XMLHarnessHandlers(const XMLCh* baseURL, const XMLCh* scanner) : BaseHarnessHandlers(baseURL)
, fTestBaseURL(5)
{
    fParser = XMLReaderFactory::createXMLReader();
    fParser->setProperty(XMLUni::fgXercesScannerName, (void*)scanner);
    fParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    fParser->setFeature(XMLUni::fgXercesDynamic, false);
    fParser->setErrorHandler(&fErrorHandler);
    
    fTestBaseURL.push(new XMLURL(fBaseURL));
}

XMLHarnessHandlers::~XMLHarnessHandlers()
{
    delete fParser;
}

static XMLCh szTest[]= u"TEST";
static XMLCh szTestCases[]= u"TESTCASES";
static XMLCh szID[]= u"ID";
static XMLCh szURI[]= u"URI";
static XMLCh szType[]= u"TYPE";
static XMLCh szValid[]= u"valid";
static XMLCh szInvalid[]= u"invalid";
static XMLCh szNotWellFormed[]= u"not-wf";
static XMLCh szError[]= u"error";
static XMLCh szBase[]= u"xml:base";
static XMLCh szNamespace[]= u"NAMESPACE";
static XMLCh szNO[]= u"no";
static XMLCh szVersion[] = u"VERSION";
static XMLCh szEdition[] = u"EDITION";
static XMLCh szFive[]= u"5";

// ---------------------------------------------------------------------------
//  XMLHarnessHandlers: Implementation of the SAX DocumentHandler interface
// ---------------------------------------------------------------------------
void XMLHarnessHandlers::startElement(const XMLCh* const /* uri */
                                   , const XMLCh* const localname
                                   , const XMLCh* const /* qname */
                                   , const Attributes& attrs)
{
    if(XMLString::equals(localname, szTestCases))
    {
        const XMLCh* baseUrl=attrs.getValue(szBase);
        XMLURL newBase;
        XMLURL prevBase=*fTestBaseURL.peek();
        if(baseUrl!=NULL)
            newBase.setURL(prevBase, baseUrl);
        else
            newBase=prevBase;
        fTestBaseURL.push(new XMLURL(newBase));
    }
    else if(XMLString::equals(localname, szTest))
    {
        const XMLCh* useNS=attrs.getValue(szNamespace);
        const XMLCh* testName=attrs.getValue(szID);
        const XMLCh* version=attrs.getValue(szVersion);
        if(version == NULL || XMLString::equals(version, XMLUni::fgVersion1_0))
        {
            const XMLCh* editions=attrs.getValue(szEdition);
            // skip tests that don't apply to v.1.0 5th Edition
            if(editions)
            {
                BaseRefVectorOf<XMLCh>* tokens = XMLString::tokenizeString(editions);
                bool appliesTo5 = false;
                for (XMLSize_t i = 0; i < tokens->size(); i++) {
                    if (XMLString::equals(tokens->elementAt(i), szFive)) {
                        appliesTo5 = true;
                        break;
                    }
                }
                delete tokens;
                if(!appliesTo5)
                    return;
            }
        }

        XMLURL testSet;
        testSet.setURL(*fTestBaseURL.peek(), attrs.getValue(szURI));
        bool success=true, fatalFailure=false;
        try
        {
            if(useNS!=NULL && XMLString::equals(useNS, szNO))
            {
                fParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, false);
                fParser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
            }
            else
            {
                fParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
                fParser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, true);
            }
            fErrorHandler.resetErrors();
            fParser->parse(testSet.getURLText());
        }
        catch (const OutOfMemoryException&)
        {
            fatalFailure=true;
            std::cout << "Test " << StrX(testName) << " ran out of memory" << std::endl;
            success=false;
        }
        catch(const XMLException& exc)
        {
            std::cout << "Test " << StrX(testName) << " threw " << StrX(exc.getMessage()) << std::endl;
            success=false;
        }
        catch (...)
        {
            fatalFailure=true;
            std::cout << "Test " << StrX(testName) << " crashed" << std::endl;
            success=false;
            exit(1);
        }
        fTests++;
        if(fatalFailure)
        {
            fFailures++;
            printFile(testSet);
        }
        else
        {
            ValidityOutcome expResult=unknown;
            const XMLCh* validity=attrs.getValue(szType);
            if(XMLString::equals(validity, szValid))
                expResult=valid;
            else if(XMLString::equals(validity, szInvalid) || XMLString::equals(validity, szNotWellFormed) || XMLString::equals(validity, szError) )
                expResult=invalid;
            else
                std::cerr << "Unknown result type " << StrX(validity) << std::endl;
            if(success && !fErrorHandler.getSawErrors())
            {
                if(expResult!=valid)
                {
                    fFailures++;
                    std::cout << "Test " << StrX(testName) << " succeeded but was expected to fail" << std::endl;
                    printFile(testSet);
                }
            }
            else
            {
                if(expResult!=invalid)
                {
                    fFailures++;
                    std::cout << "Test " << StrX(testName) << " failed but was expected to pass" << std::endl;
                    std::cout << "Reported error: " << StrX(fErrorHandler.getErrorText()) << std::endl;
                    printFile(testSet);
                }
            }
        }
    }
}

void XMLHarnessHandlers::endElement(const XMLCh* const /* uri */, const XMLCh* const localname, const XMLCh* const /* qname */)
{
    if(XMLString::equals(localname, szTestCases))
    {
        fTestBaseURL.pop();
    }
}
