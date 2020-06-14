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
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/validators/schema/SchemaSymbols.hpp>

namespace XERCES_CPP_NAMESPACE {

// ---------------------------------------------------------------------------
//  SchemaSymbols: Static data
// ---------------------------------------------------------------------------
const XMLCh SchemaSymbols::fgURI_XSI[] =                        u"http://www.w3.org/2001/XMLSchema-instance";
const XMLCh SchemaSymbols::fgURI_SCHEMAFORSCHEMA[] =            u"http://www.w3.org/2001/XMLSchema";
// deprecated (typo)
const XMLCh SchemaSymbols::fgXSI_SCHEMALOCACTION[] =            u"schemaLocation";
// deprecated (typo)
const XMLCh SchemaSymbols::fgXSI_NONAMESPACESCHEMALOCACTION[] = u"noNamespaceSchemaLocation";
const XMLCh SchemaSymbols::fgXSI_SCHEMALOCATION[] =             u"schemaLocation";
const XMLCh SchemaSymbols::fgXSI_NONAMESPACESCHEMALOCATION[] =  u"noNamespaceSchemaLocation";
const XMLCh SchemaSymbols::fgXSI_TYPE[] =                       u"type";

const XMLCh SchemaSymbols::fgELT_ALL[] =            u"all";
const XMLCh SchemaSymbols::fgELT_ANNOTATION[] =     u"annotation";
const XMLCh SchemaSymbols::fgELT_ANY[] =            u"any";
// Is this correct?  Or should it be "*"?
const XMLCh SchemaSymbols::fgELT_WILDCARD[] =       u"any";
const XMLCh SchemaSymbols::fgELT_ANYATTRIBUTE[] =   u"anyAttribute";
const XMLCh SchemaSymbols::fgELT_APPINFO[] =        u"appinfo";
const XMLCh SchemaSymbols::fgELT_ATTRIBUTE[] =      u"attribute";
const XMLCh SchemaSymbols::fgELT_ATTRIBUTEGROUP[] = u"attributeGroup";
const XMLCh SchemaSymbols::fgELT_CHOICE[] =         u"choice";
const XMLCh SchemaSymbols::fgELT_COMPLEXTYPE[] =    u"complexType";
const XMLCh SchemaSymbols::fgELT_CONTENT[] =        u"content";
const XMLCh SchemaSymbols::fgELT_DOCUMENTATION[] =  u"documentation";
const XMLCh SchemaSymbols::fgELT_DURATION[] =       u"duration";
const XMLCh SchemaSymbols::fgELT_ELEMENT[] =        u"element";
const XMLCh SchemaSymbols::fgELT_ENCODING[] =       u"encoding";
const XMLCh SchemaSymbols::fgELT_ENUMERATION[] =    u"enumeration";
const XMLCh SchemaSymbols::fgELT_FIELD[] =          u"field";
const XMLCh SchemaSymbols::fgELT_WHITESPACE[] =     u"whiteSpace";
const XMLCh SchemaSymbols::fgELT_GROUP[] =          u"group";
const XMLCh SchemaSymbols::fgELT_IMPORT[] =         u"import";
const XMLCh SchemaSymbols::fgELT_INCLUDE[] =        u"include";
const XMLCh SchemaSymbols::fgELT_REDEFINE[] =       u"redefine";
const XMLCh SchemaSymbols::fgELT_KEY[] =            u"key";
const XMLCh SchemaSymbols::fgELT_KEYREF[] =         u"keyref";
const XMLCh SchemaSymbols::fgELT_LENGTH[] =         u"length";
const XMLCh SchemaSymbols::fgELT_MAXEXCLUSIVE[] =   u"maxExclusive";
const XMLCh SchemaSymbols::fgELT_MAXINCLUSIVE[] =   u"maxInclusive";
const XMLCh SchemaSymbols::fgELT_MAXLENGTH[] =      u"maxLength";
const XMLCh SchemaSymbols::fgELT_MINEXCLUSIVE[] =   u"minExclusive";
const XMLCh SchemaSymbols::fgELT_MININCLUSIVE[] =   u"minInclusive";
const XMLCh SchemaSymbols::fgELT_MINLENGTH[] =      u"minLength";
const XMLCh SchemaSymbols::fgELT_NOTATION[] =       u"notation";
const XMLCh SchemaSymbols::fgELT_PATTERN[] =        u"pattern";
const XMLCh SchemaSymbols::fgELT_PERIOD[] =         u"period";
const XMLCh SchemaSymbols::fgELT_TOTALDIGITS[] =    u"totalDigits";
const XMLCh SchemaSymbols::fgELT_FRACTIONDIGITS[] = u"fractionDigits";
const XMLCh SchemaSymbols::fgELT_SCHEMA[] =         u"schema";
const XMLCh SchemaSymbols::fgELT_SELECTOR[] =       u"selector";
const XMLCh SchemaSymbols::fgELT_SEQUENCE[] =       u"sequence";
const XMLCh SchemaSymbols::fgELT_SIMPLETYPE[] =     u"simpleType";
const XMLCh SchemaSymbols::fgELT_UNION[] =          u"union";
const XMLCh SchemaSymbols::fgELT_LIST[] =           u"list";
const XMLCh SchemaSymbols::fgELT_UNIQUE[] =         u"unique";
const XMLCh SchemaSymbols::fgELT_COMPLEXCONTENT[] = u"complexContent";
const XMLCh SchemaSymbols::fgELT_SIMPLECONTENT[] =  u"simpleContent";
const XMLCh SchemaSymbols::fgELT_RESTRICTION[] =    u"restriction";
const XMLCh SchemaSymbols::fgELT_EXTENSION[] =      u"extension";

const XMLCh SchemaSymbols::fgATT_ABSTRACT[] =                   u"abstract";
const XMLCh SchemaSymbols::fgATT_ATTRIBUTEFORMDEFAULT[] =       u"attributeFormDefault";
const XMLCh SchemaSymbols::fgATT_BASE[] =                       u"base";
const XMLCh SchemaSymbols::fgATT_ITEMTYPE[] =                   u"itemType";
const XMLCh SchemaSymbols::fgATT_MEMBERTYPES[] =                u"memberTypes";
const XMLCh SchemaSymbols::fgATT_BLOCK[] =                      u"block";
const XMLCh SchemaSymbols::fgATT_BLOCKDEFAULT[] =               u"blockDefault";
const XMLCh SchemaSymbols::fgATT_DEFAULT[] =                    u"default";
const XMLCh SchemaSymbols::fgATT_ELEMENTFORMDEFAULT[] =         u"elementFormDefault";
const XMLCh SchemaSymbols::fgATT_SUBSTITUTIONGROUP[] =          u"substitutionGroup";
const XMLCh SchemaSymbols::fgATT_FINAL[] =                      u"final";
const XMLCh SchemaSymbols::fgATT_FINALDEFAULT[] =               u"finalDefault";
const XMLCh SchemaSymbols::fgATT_FIXED[] =                      u"fixed";
const XMLCh SchemaSymbols::fgATT_FORM[] =                       u"form";
const XMLCh SchemaSymbols::fgATT_ID[] =                         u"id";
const XMLCh SchemaSymbols::fgATT_MAXOCCURS[] =                  u"maxOccurs";
const XMLCh SchemaSymbols::fgATT_MINOCCURS[] =                  u"minOccurs";
const XMLCh SchemaSymbols::fgATT_NAME[] =                       u"name";
const XMLCh SchemaSymbols::fgATT_NAMESPACE[] =                  u"namespace";
const XMLCh SchemaSymbols::fgATT_NILL[] =                       u"nil";
const XMLCh SchemaSymbols::fgATT_NILLABLE[] =                   u"nillable";
const XMLCh SchemaSymbols::fgATT_PROCESSCONTENTS[] =            u"processContents";
const XMLCh SchemaSymbols::fgATT_REF[] =                        u"ref";
const XMLCh SchemaSymbols::fgATT_REFER[] =                      u"refer";
const XMLCh SchemaSymbols::fgATT_SCHEMALOCATION[] =             u"schemaLocation";
const XMLCh SchemaSymbols::fgATT_SOURCE[] =                     u"source";
const XMLCh SchemaSymbols::fgATT_SYSTEM[] =                     u"system";
const XMLCh SchemaSymbols::fgATT_PUBLIC[] =                     u"public";
const XMLCh SchemaSymbols::fgATT_TARGETNAMESPACE[] =            u"targetNamespace";
const XMLCh SchemaSymbols::fgATT_TYPE[] =                       u"type";
const XMLCh SchemaSymbols::fgATT_USE[] =                        u"use";
const XMLCh SchemaSymbols::fgATT_VALUE[] =                      u"value";
const XMLCh SchemaSymbols::fgATT_MIXED[] =                      u"mixed";
const XMLCh SchemaSymbols::fgATT_VERSION[] =                    u"version";
const XMLCh SchemaSymbols::fgATT_XPATH[] =                      u"xpath";
const XMLCh SchemaSymbols::fgATTVAL_TWOPOUNDANY[] =             u"##any";
const XMLCh SchemaSymbols::fgATTVAL_TWOPOUNDLOCAL[] =           u"##local";
const XMLCh SchemaSymbols::fgATTVAL_TWOPOUNDOTHER[] =           u"##other";
const XMLCh SchemaSymbols::fgATTVAL_TWOPOUNDTRAGETNAMESPACE[] = u"##targetNamespace";
const XMLCh SchemaSymbols::fgATTVAL_POUNDALL[] =                u"#all";
const XMLCh SchemaSymbols::fgATTVAL_BASE64[] =                  u"base64";
const XMLCh SchemaSymbols::fgATTVAL_BOOLEAN[] =                 u"boolean";
const XMLCh SchemaSymbols::fgATTVAL_DEFAULT[] =                 u"default";
const XMLCh SchemaSymbols::fgATTVAL_ELEMENTONLY[] =             u"elementOnly";
const XMLCh SchemaSymbols::fgATTVAL_EMPTY[] =                   u"empty";
const XMLCh SchemaSymbols::fgATTVAL_EXTENSION[] =               u"extension";
const XMLCh SchemaSymbols::fgATTVAL_FALSE[] =                   u"false";
const XMLCh SchemaSymbols::fgATTVAL_FIXED[] =                   u"fixed";
const XMLCh SchemaSymbols::fgATTVAL_HEX[] =                     u"hex";
const XMLCh SchemaSymbols::fgATTVAL_ID[] =                      u"ID";
const XMLCh SchemaSymbols::fgATTVAL_LAX[] =                     u"lax";
const XMLCh SchemaSymbols::fgATTVAL_MAXLENGTH[] =               u"maxLength";
const XMLCh SchemaSymbols::fgATTVAL_MINLENGTH[] =               u"minLength";
const XMLCh SchemaSymbols::fgATTVAL_MIXED[] =                   u"mixed";
const XMLCh SchemaSymbols::fgATTVAL_NCNAME[] =                  u"NCName";
const XMLCh SchemaSymbols::fgATTVAL_OPTIONAL[] =                u"optional";
const XMLCh SchemaSymbols::fgATTVAL_PROHIBITED[] =              u"prohibited";
const XMLCh SchemaSymbols::fgATTVAL_QNAME[] =                   u"QName";
const XMLCh SchemaSymbols::fgATTVAL_QUALIFIED[] =               u"qualified";
const XMLCh SchemaSymbols::fgATTVAL_REQUIRED[] =                u"required";
const XMLCh SchemaSymbols::fgATTVAL_RESTRICTION[] =             u"restriction";
const XMLCh SchemaSymbols::fgATTVAL_SKIP[] =                    u"skip";
const XMLCh SchemaSymbols::fgATTVAL_STRICT[] =                  u"strict";
const XMLCh SchemaSymbols::fgATTVAL_STRING[] =                  u"string";
const XMLCh SchemaSymbols::fgATTVAL_TEXTONLY[] =                u"textOnly";
const XMLCh SchemaSymbols::fgATTVAL_TIMEDURATION[] =            u"timeDuration";
const XMLCh SchemaSymbols::fgATTVAL_TRUE[] =                    u"true";
const XMLCh SchemaSymbols::fgATTVAL_UNQUALIFIED[] =             u"unqualified";
const XMLCh SchemaSymbols::fgATTVAL_URI[] =                     u"uri";
const XMLCh SchemaSymbols::fgATTVAL_URIREFERENCE[] =            u"uriReference";
const XMLCh SchemaSymbols::fgATTVAL_SUBSTITUTIONGROUP[] =       u"substitutionGroup";
const XMLCh SchemaSymbols::fgATTVAL_SUBSTITUTION[] =            u"substitution";
const XMLCh SchemaSymbols::fgATTVAL_ANYTYPE[] =                 u"anyType";
const XMLCh SchemaSymbols::fgWS_PRESERVE[] =                    u"preserve";
const XMLCh SchemaSymbols::fgWS_COLLAPSE[] =                    u"collapse";
const XMLCh SchemaSymbols::fgWS_REPLACE[] =                     u"replace";
const XMLCh SchemaSymbols::fgDT_STRING[] =                      u"string";
const XMLCh SchemaSymbols::fgDT_TOKEN[] =                       u"token";
const XMLCh SchemaSymbols::fgDT_LANGUAGE[] =                    u"language";
const XMLCh SchemaSymbols::fgDT_NAME[] =                        u"Name";
const XMLCh SchemaSymbols::fgDT_NCNAME[] =                      u"NCName";
const XMLCh SchemaSymbols::fgDT_INTEGER[] =                     u"integer";
const XMLCh SchemaSymbols::fgDT_DECIMAL[] =                     u"decimal";
const XMLCh SchemaSymbols::fgDT_BOOLEAN[] =                     u"boolean";
const XMLCh SchemaSymbols::fgDT_NONPOSITIVEINTEGER[] =          u"nonPositiveInteger";
const XMLCh SchemaSymbols::fgDT_NEGATIVEINTEGER[] =             u"negativeInteger";
const XMLCh SchemaSymbols::fgDT_LONG[] =                        u"long";
const XMLCh SchemaSymbols::fgDT_INT[] =                         u"int";
const XMLCh SchemaSymbols::fgDT_SHORT[] =                       u"short";
const XMLCh SchemaSymbols::fgDT_BYTE[] =                        u"byte";
const XMLCh SchemaSymbols::fgDT_NONNEGATIVEINTEGER[] =          u"nonNegativeInteger";
const XMLCh SchemaSymbols::fgDT_ULONG[] =                       u"unsignedLong";
const XMLCh SchemaSymbols::fgDT_UINT[] =                        u"unsignedInt";
const XMLCh SchemaSymbols::fgDT_USHORT[] =                      u"unsignedShort";
const XMLCh SchemaSymbols::fgDT_UBYTE[] =                       u"unsignedByte";
const XMLCh SchemaSymbols::fgDT_POSITIVEINTEGER[] =             u"positiveInteger";
const XMLCh SchemaSymbols::fgDT_DATETIME[] =                    u"dateTime";
const XMLCh SchemaSymbols::fgDT_DATE[] =                        u"date";
const XMLCh SchemaSymbols::fgDT_TIME[] =                        u"time";
const XMLCh SchemaSymbols::fgDT_DURATION[] =                    u"duration";
const XMLCh SchemaSymbols::fgDT_DAY[] =                         u"gDay";
const XMLCh SchemaSymbols::fgDT_MONTH[] =                       u"gMonth";
const XMLCh SchemaSymbols::fgDT_MONTHDAY[] =                    u"gMonthDay";
const XMLCh SchemaSymbols::fgDT_YEAR[] =                        u"gYear";
const XMLCh SchemaSymbols::fgDT_YEARMONTH[] =                   u"gYearMonth";
const XMLCh SchemaSymbols::fgDT_BASE64BINARY[] =                u"base64Binary";
const XMLCh SchemaSymbols::fgDT_HEXBINARY[] =                   u"hexBinary";
const XMLCh SchemaSymbols::fgDT_FLOAT[] =                       u"float";
const XMLCh SchemaSymbols::fgDT_DOUBLE[] =                      u"double";
const XMLCh SchemaSymbols::fgDT_URIREFERENCE[] =                u"uriReference";
const XMLCh SchemaSymbols::fgDT_ANYURI[] =                      u"anyURI";
const XMLCh SchemaSymbols::fgDT_QNAME[] =                       u"QName";
const XMLCh SchemaSymbols::fgDT_NORMALIZEDSTRING[] =            u"normalizedString";
const XMLCh SchemaSymbols::fgDT_ANYSIMPLETYPE[] =               u"anySimpleType";
const XMLCh SchemaSymbols::fgRegEx_XOption[] =                  u"X";
const XMLCh SchemaSymbols::fgRedefIdentifier[] =                u"_rdfn";

const int SchemaSymbols::fgINT_MIN_VALUE = 0x80000000;
const int SchemaSymbols::fgINT_MAX_VALUE = 0x7fffffff;

}

/**
  * End of file SchemaSymbols.cpp
  */

