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

#if !defined(XERCESC_INCLUDE_GUARD_XMLUNIDEFS_HPP)
#define XERCESC_INCLUDE_GUARD_XMLUNIDEFS_HPP

#include <xercesc/util/XercesDefs.hpp>

namespace XERCES_CPP_NAMESPACE {

// ---------------------------------------------------------------------------
//  Constants for the Unicode characters of interest to us in an XML parser
// ---------------------------------------------------------------------------

const XMLCh chNull                  = u'\u0000';
const XMLCh chHTab                  = u'\u0009';
const XMLCh chLF                    = u'\u000A';
const XMLCh chVTab                  = u'\u000B';
const XMLCh chFF                    = u'\u000C';
const XMLCh chCR                    = u'\u000D';
const XMLCh chAmpersand             = u'\u0026';
const XMLCh chAsterisk              = u'\u002A';
const XMLCh chAt                    = u'\u0040';
const XMLCh chBackSlash             = u'\u005C';
const XMLCh chBang                  = u'\u0021';
const XMLCh chCaret                 = u'\u005E';
const XMLCh chCloseAngle            = u'\u003E';
const XMLCh chCloseCurly            = u'\u007D';
const XMLCh chCloseParen            = u'\u0029';
const XMLCh chCloseSquare           = u'\u005D';
const XMLCh chColon                 = u'\u003A';
const XMLCh chComma                 = u'\u002C';
const XMLCh chDash                  = u'\u002D';
const XMLCh chDollarSign            = u'\u0024';
const XMLCh chDoubleQuote           = u'\u0022';
const XMLCh chEqual                 = u'\u003D';
const XMLCh chForwardSlash          = u'\u002F';
const XMLCh chGrave                 = u'\u0060';
const XMLCh chNEL                   = u'\u0085';
const XMLCh chOpenAngle             = u'\u003C';
const XMLCh chOpenCurly             = u'\u007B';
const XMLCh chOpenParen             = u'\u0028';
const XMLCh chOpenSquare            = u'\u005B';
const XMLCh chPercent               = u'\u0025';
const XMLCh chPeriod                = u'\u002E';
const XMLCh chPipe                  = u'\u007C';
const XMLCh chPlus                  = u'\u002B';
const XMLCh chPound                 = u'\u0023';
const XMLCh chQuestion              = u'\u003F';
const XMLCh chSingleQuote           = u'\u0027';
const XMLCh chSpace                 = u'\u0020';
const XMLCh chSemiColon             = u'\u003B';
const XMLCh chTilde                 = u'\u007E';
const XMLCh chUnderscore            = u'\u005F';

const XMLCh chSwappedUnicodeMarker  = u'\uFFFE';
const XMLCh chUnicodeMarker         = u'\uFEFF';

const XMLCh chDigit_0               = u'\u0030';
const XMLCh chDigit_1               = u'\u0031';
const XMLCh chDigit_2               = u'\u0032';
const XMLCh chDigit_3               = u'\u0033';
const XMLCh chDigit_4               = u'\u0034';
const XMLCh chDigit_5               = u'\u0035';
const XMLCh chDigit_6               = u'\u0036';
const XMLCh chDigit_7               = u'\u0037';
const XMLCh chDigit_8               = u'\u0038';
const XMLCh chDigit_9               = u'\u0039';

const XMLCh chLatin_A               = u'\u0041';
const XMLCh chLatin_B               = u'\u0042';
const XMLCh chLatin_C               = u'\u0043';
const XMLCh chLatin_D               = u'\u0044';
const XMLCh chLatin_E               = u'\u0045';
const XMLCh chLatin_F               = u'\u0046';
const XMLCh chLatin_G               = u'\u0047';
const XMLCh chLatin_H               = u'\u0048';
const XMLCh chLatin_I               = u'\u0049';
const XMLCh chLatin_J               = u'\u004A';
const XMLCh chLatin_K               = u'\u004B';
const XMLCh chLatin_L               = u'\u004C';
const XMLCh chLatin_M               = u'\u004D';
const XMLCh chLatin_N               = u'\u004E';
const XMLCh chLatin_O               = u'\u004F';
const XMLCh chLatin_P               = u'\u0050';
const XMLCh chLatin_Q               = u'\u0051';
const XMLCh chLatin_R               = u'\u0052';
const XMLCh chLatin_S               = u'\u0053';
const XMLCh chLatin_T               = u'\u0054';
const XMLCh chLatin_U               = u'\u0055';
const XMLCh chLatin_V               = u'\u0056';
const XMLCh chLatin_W               = u'\u0057';
const XMLCh chLatin_X               = u'\u0058';
const XMLCh chLatin_Y               = u'\u0059';
const XMLCh chLatin_Z               = u'\u005A';

const XMLCh chLatin_a               = u'\u0061';
const XMLCh chLatin_b               = u'\u0062';
const XMLCh chLatin_c               = u'\u0063';
const XMLCh chLatin_d               = u'\u0064';
const XMLCh chLatin_e               = u'\u0065';
const XMLCh chLatin_f               = u'\u0066';
const XMLCh chLatin_g               = u'\u0067';
const XMLCh chLatin_h               = u'\u0068';
const XMLCh chLatin_i               = u'\u0069';
const XMLCh chLatin_j               = u'\u006A';
const XMLCh chLatin_k               = u'\u006B';
const XMLCh chLatin_l               = u'\u006C';
const XMLCh chLatin_m               = u'\u006D';
const XMLCh chLatin_n               = u'\u006E';
const XMLCh chLatin_o               = u'\u006F';
const XMLCh chLatin_p               = u'\u0070';
const XMLCh chLatin_q               = u'\u0071';
const XMLCh chLatin_r               = u'\u0072';
const XMLCh chLatin_s               = u'\u0073';
const XMLCh chLatin_t               = u'\u0074';
const XMLCh chLatin_u               = u'\u0075';
const XMLCh chLatin_v               = u'\u0076';
const XMLCh chLatin_w               = u'\u0077';
const XMLCh chLatin_x               = u'\u0078';
const XMLCh chLatin_y               = u'\u0079';
const XMLCh chLatin_z               = u'\u007A';

const XMLCh chYenSign               = u'\u00A5';
const XMLCh chWonSign               = u'\u20A9';

const XMLCh chLineSeparator         = u'\u2028';
const XMLCh chParagraphSeparator    = u'\u2029';

}

#endif
