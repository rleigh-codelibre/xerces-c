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
#include <xercesc/util/regx/ParserForXMLSchema.hpp>
#include <xercesc/util/regx/TokenFactory.hpp>
#include <xercesc/util/regx/RangeToken.hpp>
#include <xercesc/util/regx/TokenInc.hpp>
#include <xercesc/util/regx/RegxDefs.hpp>
#include <xercesc/util/ParseException.hpp>
#include <xercesc/util/RuntimeException.hpp>
#include <xercesc/util/PlatformUtils.hpp>

namespace XERCES_CPP_NAMESPACE {

// ---------------------------------------------------------------------------
//  ParserForXMLSchema: Constructors and Destructors
// ---------------------------------------------------------------------------
ParserForXMLSchema::ParserForXMLSchema(MemoryManager* const manager)
    : RegxParser(manager)
{

}

ParserForXMLSchema::~ParserForXMLSchema() {

}

// ---------------------------------------------------------------------------
//  ParserForXMLSchema: Parsing/Processing methods
// ---------------------------------------------------------------------------
Token* ParserForXMLSchema::processCaret() {

    // XML Schema treats "^" like any other char
    processNext();
    return getTokenFactory()->createChar(u'^');
}

Token* ParserForXMLSchema::processDollar() {

    // XML Schema treats "$" like any other char
    processNext();
    return getTokenFactory()->createChar(u'$');
}

Token* ParserForXMLSchema::processPlus(Token* const tok) {

    // XML Schema doesn't support reluctant quantifiers
    processNext();
    return getTokenFactory()->createConcat(tok,
                               getTokenFactory()->createClosure(tok));
}

Token* ParserForXMLSchema::processStar(Token* const tok) {

    // XML Schema doesn't support reluctant quantifiers
    processNext();
    return getTokenFactory()->createClosure(tok);
}

Token* ParserForXMLSchema::processQuestion(Token* const tok) {

    // XML Schema doesn't support reluctant quantifiers
    processNext();

    TokenFactory* tokFactory = getTokenFactory();
    Token* retTok = tokFactory->createUnion();
    retTok->addChild(tok, tokFactory);
    retTok->addChild(tokFactory->createToken(Token::T_EMPTY), tokFactory);
    return retTok;
}

Token* ParserForXMLSchema::processParen() {

    // XML Schema doesn't support back references
    processNext();
    Token* retTok = getTokenFactory()->createParenthesis(parseRegx(true), 0);

    if (getState() != REGX_T_RPAREN) {
        ThrowXMLwithMemMgr(ParseException, XMLExcepts::Parser_Factor1, getMemoryManager());
    }

    processNext();
    return retTok;
}

Token* ParserForXMLSchema::processBackReference() {

    // XML Schema doesn't support back references
    ThrowXMLwithMemMgr(RuntimeException, XMLExcepts::Regex_NotSupported, getMemoryManager());
    return 0; // for compilers that complain about no return value
}

// ---------------------------------------------------------------------------
//  ParserForXMLSchema: Helper methods
// ---------------------------------------------------------------------------
bool ParserForXMLSchema::checkQuestion(const XMLSize_t ) {

    // XML Schema doesn't support reluctant quantifiers
    return false;
}


XMLInt32 ParserForXMLSchema::decodeEscaped() {

    // XML Schema doesn't support an escaped "$"
    if (getState() != REGX_T_BACKSOLIDUS)
        ThrowXMLwithMemMgr(ParseException,XMLExcepts::Parser_Next1, getMemoryManager());

    XMLInt32 ch = getCharData();

    switch (ch) {
    case u'n':
        ch = u'\n';
        break;
    case u'r':
        ch = u'\r';
        break;
    case u't':
        ch = u'\t';
        break;
    case u'\\':
    case u'|':
    case u'.':
    case u'^':
    case u'-':
    case u'?':
    case u'*':
    case u'+':
    case u'{':
    case u'}':
    case u'(':
    case u')':
    case u'[':
    case u']':
        break;
    default:
        {
        XMLCh chString[] = {u'\\', (XMLCh)ch, u'\0'};
        ThrowXMLwithMemMgr1(ParseException,XMLExcepts::Parser_Process2, chString, getMemoryManager());
        }
    }

    return ch;
}

}

/**
  * End of file ParserForXMLSchema.cpp
  */
