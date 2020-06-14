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
#include "XSTSHarnessHandlers.hpp"
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax/SAXParseException.hpp>
#include <xercesc/sax/SAXException.hpp>
#include <xercesc/validators/common/Grammar.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/parsers/SAX2XMLReaderImpl.hpp>

// ---------------------------------------------------------------------------
//  XSTSHarnessHandlers: Constructors and Destructor
// ---------------------------------------------------------------------------
XSTSHarnessHandlers::XSTSHarnessHandlers(const XMLCh* baseURL, const XMLCh* scanner) : BaseHarnessHandlers(baseURL)
{
    fParser = XMLReaderFactory::createXMLReader();
    fParser->setProperty(XMLUni::fgXercesScannerName, (void*)scanner);
    fParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
    fParser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, true);
    fParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    fParser->setFeature(XMLUni::fgXercesSchema, true);
    fParser->setFeature(XMLUni::fgXercesHandleMultipleImports, true);
    fParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
    fParser->setFeature(XMLUni::fgXercesDynamic, false);
    fParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);
    fParser->setFeature(XMLUni::fgXercesIdentityConstraintChecking, true);
    fParser->setErrorHandler(&fErrorHandler);
    ((SAX2XMLReaderImpl*)fParser)->setXMLEntityResolver(&fEntityResolver);
}

XSTSHarnessHandlers::~XSTSHarnessHandlers()
{
    delete fParser;
}

static XMLCh urlW3C[] = u"http://www.w3.org/XML/Schema";

static XMLCh szTestSuite[] =              u"TestSuite";
static XMLCh szTestGroup[] =              u"testGroup";
static XMLCh szSchemaTest[] =             u"schemaTest";
static XMLCh szInstanceTest[] =           u"instanceTest";
static XMLCh szDocumentationReference[] = u"documentationReference";
static XMLCh szSchemaDocument[] =         u"schemaDocument";
static XMLCh szInstanceDocument[] =       u"instanceDocument";
static XMLCh szExpected[] =               u"expected";
static XMLCh szValidity[] =               u"validity";

static XMLCh szXLINK[] =    u"http://www.w3.org/1999/xlink";
static XMLCh szHREF[] =     u"href";
static XMLCh szNAME[] =     u"name";
static XMLCh szVALID[] =    u"valid";
static XMLCh szINVALID[] =  u"invalid";

static XMLCh szTestSuite2[] = u"http://www.w3.org/XML/2004/xml-schema-test-suite/";
static XMLCh szTestSetRef[] = u"testSetRef";

// ---------------------------------------------------------------------------
//  XSTSHarnessHandlers: Implementation of the SAX DocumentHandler interface
// ---------------------------------------------------------------------------
void XSTSHarnessHandlers::startElement(const XMLCh* const uri
                                   , const XMLCh* const localname
                                   , const XMLCh* const /* qname */
                                   , const Attributes& attrs)
{
    if(XMLString::equals(uri, szTestSuite) || XMLString::equals(uri, szTestSuite2))
    {
        if(XMLString::equals(localname, szTestSetRef))
        {
            XMLURL testSet, backupBase(fBaseURL);
            testSet.setURL(fBaseURL, attrs.getValue(szXLINK, szHREF));

            fBaseURL=testSet;
            SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();
            try
            {
                parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
                parser->setContentHandler(this);
                parser->setErrorHandler(this);
                parser->parse(testSet.getURLText());
            }
            catch (...)
            {
            }
            delete parser;
            fBaseURL=backupBase;

        }
        else if(XMLString::equals(localname, szTestGroup))
        {
            fCurrentTest.fExpectedResult=unknown;
            fCurrentTest.fSpecReference.setURL(urlW3C);
            fCurrentTest.fTestName[0]=0;
            fCurrentTest.fXMLName.setURL(dummy);
            fCurrentTest.fXSDNames.removeAllElements();
            StrX x(attrs.getValue(szNAME));
            const char* groupName=x.localForm();
            if(XMLString::equals(groupName,"addB194") ||
               XMLString::equals(groupName,"particlesZ033_c") ||
               XMLString::equals(groupName,"particlesZ033_d") ||
               XMLString::equals(groupName,"particlesZ033_e") ||
               XMLString::equals(groupName,"particlesZ033_f") ||
               XMLString::equals(groupName,"particlesZ033_g") ||
               XMLString::equals(groupName,"particlesZ035_a") ||
               XMLString::equals(groupName,"particlesZ036_b1") ||
               XMLString::equals(groupName,"particlesZ036_b2") ||
               XMLString::equals(groupName,"particlesZ036_c") ||
               XMLString::equals(groupName,"wildG032")
               )
                fCurrentTest.fSkipped=true;
            else
                fCurrentTest.fSkipped=false;
            fParser->resetCachedGrammarPool();
        }
        else if(XMLString::equals(localname, szDocumentationReference))
        {
            const XMLCh* ref=attrs.getValue(szXLINK, szHREF);
            if(ref && *ref)
                fCurrentTest.fSpecReference.setURL(ref);
            else
                fCurrentTest.fSpecReference.setURL(dummy);
        }
        else if(XMLString::equals(localname, szSchemaTest) ||
                XMLString::equals(localname, szInstanceTest))
        {
            XMLString::copyString(fCurrentTest.fTestName, attrs.getValue(szNAME));
        }
        else if(XMLString::equals(localname, szSchemaDocument))
        {
            fCurrentTest.fXSDNames.addElement(new XMLURL(fBaseURL, attrs.getValue(szXLINK, szHREF)));
        }
        else if(XMLString::equals(localname, szInstanceDocument))
        {
            fCurrentTest.fXMLName.setURL(fBaseURL, attrs.getValue(szXLINK, szHREF));
        }
        else if(XMLString::equals(localname, szExpected))
        {
            const XMLCh* validity=attrs.getValue(szValidity);
            if(XMLString::equals(validity, szVALID))
                fCurrentTest.fExpectedResult=valid;
            else if(XMLString::equals(validity, szINVALID))
                fCurrentTest.fExpectedResult=invalid;
            else
                fCurrentTest.fExpectedResult=unknown;
        }
    }
}

void XSTSHarnessHandlers::endElement(const XMLCh* const uri,
	                                 const XMLCh* const localname,
	                                 const XMLCh* const /*qname*/)
{
    if(XMLString::equals(uri, szTestSuite) || XMLString::equals(uri, szTestSuite2))
    {
        if(XMLString::equals(localname, szSchemaTest))
        {
            if(fCurrentTest.fSkipped)
            {
                fTests++;
                fFailures++;
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " skipped" << std::endl;
                return;
            }
            bool success=true, fatalFailure=false;
            try
            {
                fErrorHandler.resetErrors();
                for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                {
                    Grammar* grammar=fParser->loadGrammar(fCurrentTest.fXSDNames.elementAt(i)->getURLText(), Grammar::SchemaGrammarType, true);
                    success=(success && (grammar!=NULL));
                }
            }
            catch (const OutOfMemoryException&)
            {
                fatalFailure=true;
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " ran out of memory" << std::endl;
                success=false;
            }
            catch(const XMLException& exc)
            {
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " threw " << StrX(exc.getMessage()) << std::endl;
                success=false;
            }
            catch (...)
            {
                fatalFailure=true;
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " crashed" << std::endl;
                success=false;
                exit(1);
            }
            fTests++;
            if(fatalFailure)
            {
                // skip the rest of the group, as we had problems with the schema itself
                fCurrentTest.fSkipped=true;
                fFailures++;
                for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                    printFile(*fCurrentTest.fXSDNames.elementAt(i));
            }
            else
            {
                if(success && !fErrorHandler.getSawErrors())
                {
                    if(fCurrentTest.fExpectedResult!=valid)
                    {
                        // skip the rest of the group, as we had problems with the schema itself
                        fCurrentTest.fSkipped=true;
                        fFailures++;
                        std::cout << "Test " << StrX(fCurrentTest.fTestName) << " succeeded but was expected to fail" << std::endl;
                        for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                            printFile(*fCurrentTest.fXSDNames.elementAt(i));
                    }
                }
                else
                {
                    if(fCurrentTest.fExpectedResult!=invalid)
                    {
                        // skip the rest of the group, as we had problems with the schema itself
                        fCurrentTest.fSkipped=true;
                        fFailures++;
                        std::cout << "Test " << StrX(fCurrentTest.fTestName) << " failed but was expected to pass" << std::endl;
                        std::cout << "Reported error: " << StrX(fErrorHandler.getErrorText()) << std::endl;
                        for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                            printFile(*fCurrentTest.fXSDNames.elementAt(i));
                    }
                }
            }
        }
        else if(XMLString::equals(localname, szInstanceTest))
        {
            if(fCurrentTest.fSkipped)
            {
                fTests++;
                fFailures++;
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " skipped" << std::endl;
                return;
            }
            bool success=true, fatalFailure=false;
            try
            {
                fErrorHandler.resetErrors();
                fParser->parse(fCurrentTest.fXMLName.getURLText());
            }
            catch (const OutOfMemoryException&)
            {
                fatalFailure=true;
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " ran out of memory" << std::endl;
                success=false;
            }
            catch(const XMLException& exc)
            {
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " threw " << StrX(exc.getMessage()) << std::endl;
                success=false;
            }
            catch (...)
            {
                fatalFailure=true;
                std::cout << "Test " << StrX(fCurrentTest.fTestName) << " crashed" << std::endl;
                success=false;
                exit(1);
            }
            fTests++;
            if(fatalFailure)
            {
                fFailures++;
                for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                    printFile(*fCurrentTest.fXSDNames.elementAt(i));
                printFile(fCurrentTest.fXMLName);
            }
            else
            {
                if(success && !fErrorHandler.getSawErrors())
                {
                    if(fCurrentTest.fExpectedResult!=valid)
                    {
                        fFailures++;
                        std::cout << "Test " << StrX(fCurrentTest.fTestName) << " succeeded but was expected to fail" << std::endl;
                        for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                            printFile(*fCurrentTest.fXSDNames.elementAt(i));
                        printFile(fCurrentTest.fXMLName);
                    }
                }
                else
                {
                    if(fCurrentTest.fExpectedResult!=invalid)
                    {
                        fFailures++;
                        std::cout << "Test " << StrX(fCurrentTest.fTestName) << " failed but was expected to pass" << std::endl;
                        std::cout << "Reported error: " << StrX(fErrorHandler.getErrorText()) << std::endl;
                        for(XMLSize_t i=0;i<fCurrentTest.fXSDNames.size();i++)
                            printFile(*fCurrentTest.fXSDNames.elementAt(i));
                        printFile(fCurrentTest.fXMLName);
                    }
                }
            }
        }
    }
}
