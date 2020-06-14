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
#include <xercesc/util/regx/UnicodeRangeFactory.hpp>
#include <xercesc/util/regx/TokenFactory.hpp>
#include <xercesc/util/regx/RangeToken.hpp>
#include <xercesc/util/regx/RangeTokenMap.hpp>
#include <xercesc/util/regx/RegxDefs.hpp>
#include <xercesc/util/regx/XMLUniCharacter.hpp>

namespace XERCES_CPP_NAMESPACE {

// ---------------------------------------------------------------------------
//  Local data
// ---------------------------------------------------------------------------

static const XMLCh *uniCategNames[] =
{
    u"Cn",     // UNASSIGNED
    u"Lu",     // UPPERCASE_LETTER
    u"Ll",     // LOWERCASE_LETTER
    u"Lt",     // TITLECASE_LETTER
    u"Lm",     // MODIFIER_LETTER
    u"Lo",     // OTHER_LETTER
    u"Mn",     // NON_SPACING_MARK
    u"Me",     // ENCLOSING_MARK
    u"Mc",     // COMBINING_SPACING_MARK
    u"Nd",     // DECIMAL_DIGIT_NUMBER
    u"Nl",     // LETTER_NUMBER
    u"No",     // OTHER_NUMBER
    u"Zs",     // SPACE_SEPARATOR
    u"Zl",     // LINE_SEPARATOR
    u"Zp",     // PARAGRAPH_SEPARATOR
    u"Cc",     // CONTROL
    u"Cf",     // FORMAT
    u"Co",     // PRIVATE_USE
    u"Cs",     // SURROGATE
    u"Pd",     // DASH_PUNCTUATION
    u"Ps",     // START_PUNCTUATION
    u"Pe",     // END_PUNCTUATION
    u"Pc",     // CONNECTOR_PUNCTUATION
    u"Po",     // OTHER_PUNCTUATION
    u"Sm",     // MATH_SYMBOL
    u"Sc",     // CURRENCY_SYMBOL
    u"Sk",     // MODIFIER_SYMBOL
    u"So",     // OTHER_SYMBOL
    u"Pi",     // INITIAL_PUNCTUATION
    u"Pf",     // FINAL_PUNCTUATION
    u"L",      // CHAR_LETTER
    u"M",      // CHAR_MARK
    u"N",      // CHAR_NUMBER
    u"Z",      // CHAR_SEPARATOR
    u"C",      // CHAR_OTHER
    u"P",      // CHAR_PUNCTUATION
    u"S",      // CHAR_SYMBOL
};

// ---------------------------------------------------------------------------
//  UnicodeRangeFactory: Constructors and Destructor
// ---------------------------------------------------------------------------
UnicodeRangeFactory::UnicodeRangeFactory()
{
}

UnicodeRangeFactory::~UnicodeRangeFactory() {

}

// ---------------------------------------------------------------------------
//  UnicodeRangeFactory: Range creation methods
// ---------------------------------------------------------------------------
void UnicodeRangeFactory::buildRanges(RangeTokenMap *rangeTokMap) {

    if (fRangesCreated)
        return;

    if (!fKeywordsInitialized) {
        initializeKeywordMap(rangeTokMap);
    }

    TokenFactory* tokFactory = rangeTokMap->getTokenFactory();
    RangeToken* ranges[UNICATEGSIZE];
    RangeToken* tok;

    for (int i=0; i < UNICATEGSIZE; i++) {
        ranges[i] = tokFactory->createRange();
    }

    for (int j=0; j < 0x10000; j++) {

        unsigned short charType = XMLUniCharacter::getType(j);

        ranges[charType]->addRange(j, j);
        charType = getUniCategory(charType);
        ranges[charType]->addRange(j, j);
    }

    ranges[XMLUniCharacter::UNASSIGNED]->addRange(0x10000, Token::UTF16_MAX);

    for (int k=0; k < UNICATEGSIZE; k++) {
        tok = RangeToken::complementRanges(ranges[k], tokFactory);
        // build the internal map.
        tok->createMap();
        rangeTokMap->setRangeToken(uniCategNames[k], ranges[k]);
        rangeTokMap->setRangeToken(uniCategNames[k], tok , true);
    }

    // Create all range
    tok = tokFactory->createRange();
    tok->addRange(0, Token::UTF16_MAX);
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniAll, tok);

    // Create alpha range
    tok = tokFactory->createRange();
    tok->mergeRanges(ranges[XMLUniCharacter::UPPERCASE_LETTER]);
    tok->mergeRanges(ranges[XMLUniCharacter::LOWERCASE_LETTER]);
    tok->mergeRanges(ranges[XMLUniCharacter::OTHER_LETTER]);
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniIsAlpha, tok);

    // Create alpha-num range
    RangeToken* alnumTok = tokFactory->createRange();
    alnumTok->mergeRanges(tok);
    alnumTok->mergeRanges(ranges[XMLUniCharacter::DECIMAL_DIGIT_NUMBER]);
    // build the internal map.
    alnumTok->createMap();
    rangeTokMap->setRangeToken(fgUniIsAlnum, alnumTok);

    // Create word range
    tok = tokFactory->createRange();
    tok->mergeRanges(alnumTok);
    tok->addRange(u'_', u'_');
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniIsWord, tok);

    tok = RangeToken::complementRanges(tok, tokFactory);
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniIsWord, tok , true);

    // Create assigned range
    tok = RangeToken::complementRanges(
                ranges[XMLUniCharacter::UNASSIGNED],
                tokFactory,
                tokFactory->getMemoryManager());
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniAssigned,tok);

    // Create space range
    tok = tokFactory->createRange();
    tok->mergeRanges(ranges[XMLUniCharacter::SPACE_SEPARATOR]);
    tok->mergeRanges(ranges[XMLUniCharacter::LINE_SEPARATOR]);
    //tok->mergeRanges(ranges[XMLUniCharacter::PARAGRAPH_SEPARATOR]);
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniIsSpace, tok);

    tok = RangeToken::complementRanges(tok, tokFactory);
    // build the internal map.
    tok->createMap();
    rangeTokMap->setRangeToken(fgUniIsSpace, tok , true);

    RangeToken* const dummyToken =
        tokFactory->createRange();

    dummyToken->addRange(-1, -2);
    dummyToken->createMap();

    // build the internal maps.
    for (int l=0; l < UNICATEGSIZE; l++) {
        ranges[l]->createMap();
        ranges[l]->setCaseInsensitiveToken(dummyToken);
    }

    fRangesCreated = true;
}

// ---------------------------------------------------------------------------
//  UnicodeRangeFactory: Initialization methods
// ---------------------------------------------------------------------------
void UnicodeRangeFactory::initializeKeywordMap(RangeTokenMap *rangeTokMap) {

    if (fKeywordsInitialized)
        return;

    for (int k=0; k < UNICATEGSIZE; k++) {
        rangeTokMap->addKeywordMap(uniCategNames[k], fgUnicodeCategory);
    }

    rangeTokMap->addKeywordMap(fgUniAll, fgUnicodeCategory);
    rangeTokMap->addKeywordMap(fgUniIsAlpha, fgUnicodeCategory);
    rangeTokMap->addKeywordMap(fgUniIsAlnum, fgUnicodeCategory);
    rangeTokMap->addKeywordMap(fgUniIsWord, fgUnicodeCategory);
    rangeTokMap->addKeywordMap(fgUniAssigned, fgUnicodeCategory);
    rangeTokMap->addKeywordMap(fgUniIsSpace, fgUnicodeCategory);

    fKeywordsInitialized = true;
}

// ---------------------------------------------------------------------------
//  UnicodeRangeFactory: Helper methods
// ---------------------------------------------------------------------------
unsigned short UnicodeRangeFactory::getUniCategory(const unsigned short type)
{
    switch(type) {
    case XMLUniCharacter::UPPERCASE_LETTER:
    case XMLUniCharacter::LOWERCASE_LETTER:
    case XMLUniCharacter::TITLECASE_LETTER:
    case XMLUniCharacter::MODIFIER_LETTER:
    case XMLUniCharacter::OTHER_LETTER:
        return CHAR_LETTER;
    case XMLUniCharacter::NON_SPACING_MARK:
    case XMLUniCharacter::COMBINING_SPACING_MARK:
    case XMLUniCharacter::ENCLOSING_MARK:
        return CHAR_MARK;
    case XMLUniCharacter::DECIMAL_DIGIT_NUMBER:
    case XMLUniCharacter::LETTER_NUMBER:
    case XMLUniCharacter::OTHER_NUMBER:
        return CHAR_NUMBER;
    case XMLUniCharacter::SPACE_SEPARATOR:
    case XMLUniCharacter::LINE_SEPARATOR:
    case XMLUniCharacter::PARAGRAPH_SEPARATOR:
        return CHAR_SEPARATOR;
    case XMLUniCharacter::CONTROL:
    case XMLUniCharacter::FORMAT:
    case XMLUniCharacter::SURROGATE:
    case XMLUniCharacter::PRIVATE_USE:
    case XMLUniCharacter::UNASSIGNED:
        return CHAR_OTHER;
    case XMLUniCharacter::CONNECTOR_PUNCTUATION:
    case XMLUniCharacter::DASH_PUNCTUATION:
    case XMLUniCharacter::START_PUNCTUATION:
    case XMLUniCharacter::END_PUNCTUATION:
    case XMLUniCharacter::OTHER_PUNCTUATION:
    case XMLUniCharacter::INITIAL_PUNCTUATION:
    case XMLUniCharacter::FINAL_PUNCTUATION:
        return CHAR_PUNCTUATION;
    case XMLUniCharacter::MATH_SYMBOL:
    case XMLUniCharacter::CURRENCY_SYMBOL:
    case XMLUniCharacter::MODIFIER_SYMBOL:
    case XMLUniCharacter::OTHER_SYMBOL:
        return CHAR_SYMBOL;
    }

    return 0;
}

}

/**
  * End of file UnicodeRangeFactory.cpp
  */
