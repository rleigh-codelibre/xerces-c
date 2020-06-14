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
#include <xercesc/util/regx/BlockRangeFactory.hpp>
#include <xercesc/util/regx/RangeToken.hpp>
#include <xercesc/util/regx/RegxDefs.hpp>
#include <xercesc/util/regx/TokenFactory.hpp>
#include <xercesc/util/regx/RangeTokenMap.hpp>

namespace XERCES_CPP_NAMESPACE {

// ---------------------------------------------------------------------------
//  Local static data
// ---------------------------------------------------------------------------
const int   BLOCKNAMESIZE = 93;

// Block Names IsX
// only define Specials as FEFF..FEFF, missing Specials as FFF0..FFFD, add manually
// only define private use as E000..F8FF,
//    missing 2 private use (F0000..FFFFD and 100000..10FFFD), add manually
const XMLCh *fgBlockNames[] =
{
    u"IsBasicLatin",
    u"IsLatin-1Supplement",
    u"IsLatinExtended-A",
    u"IsLatinExtended-B",
    u"IsIPAExtensions",
    u"IsSpacingModifierLetters",
    u"IsCombiningDiacriticalMarks",
    u"IsGreek",
    u"IsCyrillic",
    u"IsArmenian",
    u"IsHebrew",
    u"IsArabic",
    u"IsSyriac",
    u"IsThaana",
    u"IsDevanagari",
    u"IsBengali",
    u"IsGurmukhi",
    u"IsGujarati",
    u"IsOriya",
    u"IsTamil",
    u"IsTelugu",
    u"IsKannada",
    u"IsMalayalam",
    u"IsSinhala",
    u"IsThai",
    u"IsLao",
    u"IsTibetan",
    u"IsMyanmar",
    u"IsGeorgian",
    u"IsHangulJamo",
    u"IsEthiopic",
    u"IsCherokee",
    u"IsUnifiedCanadianAboriginalSyllabics",
    u"IsOgham",
    u"IsRunic",
    u"IsKhmer",
    u"IsMongolian",
    u"IsLatinExtendedAdditional",
    u"IsGreekExtended",
    u"IsGeneralPunctuation",
    u"IsSuperscriptsandSubscripts",
    u"IsCurrencySymbols",
    u"IsCombiningMarksforSymbols",
    u"IsLetterlikeSymbols",
    u"IsNumberForms",
    u"IsArrows",
    u"IsMathematicalOperators",
    u"IsMiscellaneousTechnical",
    u"IsControlPictures",
    u"IsOpticalCharacterRecognition",
    u"IsEnclosedAlphanumerics",
    u"IsBoxDrawing",
    u"IsBlockElements",
    u"IsGeometricShapes",
    u"IsMiscellaneousSymbols",
    u"IsDingbats",
    u"IsBraillePatterns",
    u"IsCJKRadicalsSupplement",
    u"IsKangxiRadicals",
    u"IsIdeographicDescriptionCharacters",
    u"IsCJKSymbolsandPunctuation",
    u"IsHiragana",
    u"IsKatakana",
    u"IsBopomofo",
    u"IsHangulCompatibilityJamo",
    u"IsKanbun",
    u"IsBopomofoExtended",
    u"IsEnclosedCJKLettersandMonths",
    u"IsCJKCompatibility",
    u"IsCJKUnifiedIdeographsExtensionA",
    u"IsCJKUnifiedIdeographs",
    u"IsYiSyllables",
    u"IsYiRadicals",
    u"IsHangulSyllables",
    u"IsPrivateUse",
    u"IsCJKCompatibilityIdeographs",
    u"IsAlphabeticPresentationForms",
    u"IsArabicPresentationForms-A",
    u"IsCombiningHalfMarks",
    u"IsCJKCompatibilityForms",
    u"IsSmallFormVariants",
    u"IsArabicPresentationForms-B",
    u"IsSpecials",
    u"IsHalfwidthandFullwidthForms",
    u"IsOldItalic",
    u"IsGothic",
    u"IsDeseret",
    u"IsByzantineMusicalSymbols",
    u"IsMusicalSymbols",
    u"IsMathematicalAlphanumericSymbols",
    u"IsCJKUnifiedIdeographsExtensionB",
    u"IsCJKCompatibilityIdeographsSupplement",
    u"IsTags",
};

const XMLInt32 blockRanges[] =
{
    0x0000,0x007F,0x0080,0x00FF,0x0100,0x017F,0x0180,0x024F,0x0250,0x02AF,0x02B0,0x02FF,
    0x0300,0x036F,0x0370,0x03FF,0x0400,0x04FF,0x0530,0x058F,0x0590,0x05FF,0x0600,0x06FF,
    0x0700,0x074F,0x0780,0x07BF,0x0900,0x097F,0x0980,0x09FF,0x0A00,0x0A7F,0x0A80,0x0AFF,
    0x0B00,0x0B7F,0x0B80,0x0BFF,0x0C00,0x0C7F,0x0C80,0x0CFF,0x0D00,0x0D7F,0x0D80,0x0DFF,
    0x0E00,0x0E7F,0x0E80,0x0EFF,0x0F00,0x0FFF,0x1000,0x109F,0x10A0,0x10FF,0x1100,0x11FF,
    0x1200,0x137F,0x13A0,0x13FF,0x1400,0x167F,0x1680,0x169F,0x16A0,0x16FF,0x1780,0x17FF,
    0x1800,0x18AF,0x1E00,0x1EFF,0x1F00,0x1FFF,0x2000,0x206F,0x2070,0x209F,0x20A0,0x20CF,
    0x20D0,0x20FF,0x2100,0x214F,0x2150,0x218F,0x2190,0x21FF,0x2200,0x22FF,0x2300,0x23FF,
    0x2400,0x243F,0x2440,0x245F,0x2460,0x24FF,0x2500,0x257F,0x2580,0x259F,0x25A0,0x25FF,
    0x2600,0x26FF,0x2700,0x27BF,0x2800,0x28FF,0x2E80,0x2EFF,0x2F00,0x2FDF,0x2FF0,0x2FFF,
    0x3000,0x303F,0x3040,0x309F,0x30A0,0x30FF,0x3100,0x312F,0x3130,0x318F,0x3190,0x319F,
    0x31A0,0x31BF,0x3200,0x32FF,0x3300,0x33FF,0x3400,0x4DB5,0x4E00,0x9FFF,0xA000,0xA48F,
    0xA490,0xA4CF,0xAC00,0xD7A3,0xE000,0xF8FF,0xF900,0xFAFF,0xFB00,0xFB4F,0xFB50,0xFDFF,
    0xFE20,0xFE2F,0xFE30,0xFE4F,0xFE50,0xFE6F,0xFE70,0xFEFE,0xFEFF,0xFEFF,0xFF00,0xFFEF,
    0x10300,0x1032F,0x10330,0x1034F,0x10400,0x1044F,0x1D000,0x1D0FF,0x1D100,0x1D1FF,
    0x1D400,0x1D7FF,0x20000,0x2A6D6,0x2F800,0x2FA1F,0xE0000,0xE007F, U'\0'
};

// ---------------------------------------------------------------------------
//  BlockRangeFactory: Constructors and Destructor
// ---------------------------------------------------------------------------
BlockRangeFactory::BlockRangeFactory()
{

}

BlockRangeFactory::~BlockRangeFactory() {

}

// ---------------------------------------------------------------------------
//  BlockRangeFactory: Range creation methods
// ---------------------------------------------------------------------------
void BlockRangeFactory::buildRanges(RangeTokenMap *rangeTokMap) {

    if (fRangesCreated)
        return;

    if (!fKeywordsInitialized) {
        initializeKeywordMap(rangeTokMap);
    }

    TokenFactory* tokFactory = rangeTokMap->getTokenFactory();

    //for performance, once the desired specials and private use are found
    //don't need to compareString anymore
    bool foundSpecial = false;
    bool foundPrivate = false;

    for (int i=0; i < BLOCKNAMESIZE; i++) {
        RangeToken* tok = tokFactory->createRange();
        tok->addRange(blockRanges[i*2], blockRanges[(i*2)+1]);

        if (!foundSpecial && XMLString::equals((XMLCh*)fgBlockNames[i] , (XMLCh*) fgBlockIsSpecials)) {
            tok->addRange(0xFFF0, 0xFFFD);
            foundSpecial = true;
        }
        if (!foundPrivate && XMLString::equals((XMLCh*)fgBlockNames[i] , (XMLCh*) fgBlockIsPrivateUse)) {
            tok->addRange(0xF0000, 0xFFFFD);
            tok->addRange(0x100000, 0x10FFFD);
            foundPrivate = true;
        }

        // Build the internal map.
        tok->createMap();
        rangeTokMap->setRangeToken(fgBlockNames[i], tok);
        tok = RangeToken::complementRanges(tok, tokFactory);
        // Build the internal map.
        tok->createMap();
        rangeTokMap->setRangeToken(fgBlockNames[i], tok , true);
    }

    fRangesCreated = true;
}

// ---------------------------------------------------------------------------
//  BlockRangeFactory: Range creation methods
// ---------------------------------------------------------------------------
void BlockRangeFactory::initializeKeywordMap(RangeTokenMap *rangeTokMap) {

    if (fKeywordsInitialized)
        return;

    for (int i=0; i< BLOCKNAMESIZE; i++) {
        rangeTokMap->addKeywordMap(fgBlockNames[i], fgBlockCategory);
    }

    fKeywordsInitialized = true;
}

}

/**
  * End of file BlockRangeFactory.cpp
  */
