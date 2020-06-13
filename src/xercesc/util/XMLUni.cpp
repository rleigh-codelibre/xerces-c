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
#include <xercesc/util/XMLUni.hpp>

namespace XERCES_CPP_NAMESPACE {

// ---------------------------------------------------------------------------
//  XMLUni: Static data
// ---------------------------------------------------------------------------

const XMLCh XMLUni::fgAnyString[]     =            u"ANY";
const XMLCh XMLUni::fgAttListString[] =            u"ATTLIST";
const XMLCh XMLUni::fgCommentString[] =            u"<!--";
const XMLCh XMLUni::fgCDATAString[] =              u"CDATA";
const XMLCh XMLUni::fgDefaultString[] =            u"#DEFAULT";
const XMLCh XMLUni::fgDocTypeString[] =            u"<!DOCTYPE";
const XMLCh XMLUni::fgEBCDICEncodingString[] =     u"EBCDIC";
const XMLCh XMLUni::fgElemString[] =               u"ELEMENT";
const XMLCh XMLUni::fgEmptyString[] =              u"EMPTY";
const XMLCh XMLUni::fgEncodingString[] =           u"encoding";
const XMLCh XMLUni::fgEntitString[] =              u"ENTIT";
const XMLCh XMLUni::fgEntityString[] =             u"ENTITY";
const XMLCh XMLUni::fgEntitiesString[] =           u"ENTITIES";
const XMLCh XMLUni::fgEnumerationString[] =        u"ENUMERATION";
const XMLCh XMLUni::fgExceptDomain[] =             u"http://apache.org/xml/messages/XML4CErrors";
const XMLCh XMLUni::fgFixedString[] =              u"#FIXED";
const XMLCh XMLUni::fgIBM037EncodingString[] =     u"EBCDIC-CP-US";
const XMLCh XMLUni::fgIBM037EncodingString2[] =    u"IBM037";
const XMLCh XMLUni::fgIBM1047EncodingString[] =    u"IBM1047";
const XMLCh XMLUni::fgIBM1047EncodingString2[] =   u"IBM-1047";
const XMLCh XMLUni::fgIBM1140EncodingString[] =    u"IBM1140";
const XMLCh XMLUni::fgIBM1140EncodingString2[] =   u"IBM01140";
const XMLCh XMLUni::fgIBM1140EncodingString3[] =   u"CCSID01140";
const XMLCh XMLUni::fgIBM1140EncodingString4[] =   u"CP01140";
const XMLCh XMLUni::fgIESString[] =                u"IES";
const XMLCh XMLUni::fgIDString[] =                 u"ID";
const XMLCh XMLUni::fgIDRefString[] =              u"IDREF";
const XMLCh XMLUni::fgIDRefsString[] =             u"IDREFS";
const XMLCh XMLUni::fgImpliedString[] =            u"#IMPLIED";
const XMLCh XMLUni::fgIgnoreString[] =             u"IGNORE";
const XMLCh XMLUni::fgIncludeString[] =            u"INCLUDE";
const XMLCh XMLUni::fgISO88591EncodingString[] =   u"ISO8859-1";
const XMLCh XMLUni::fgISO88591EncodingString2[] =  u"ISO-8859-1";
const XMLCh XMLUni::fgISO88591EncodingString3[] =  u"ISO_8859-1";
const XMLCh XMLUni::fgISO88591EncodingString4[] =  u"IBM-819";
const XMLCh XMLUni::fgISO88591EncodingString5[] =  u"IBM819";
const XMLCh XMLUni::fgISO88591EncodingString6[] =  u"LATIN1";
const XMLCh XMLUni::fgISO88591EncodingString7[] =  u"LATIN-1";
const XMLCh XMLUni::fgISO88591EncodingString8[] =  u"LATIN_1";
const XMLCh XMLUni::fgISO88591EncodingString9[] =  u"CP819";
const XMLCh XMLUni::fgISO88591EncodingString10[] = u"CSISOLATIN1";
const XMLCh XMLUni::fgISO88591EncodingString11[] = u"ISO-IR-100";
const XMLCh XMLUni::fgISO88591EncodingString12[] = u"L1";
const XMLCh XMLUni::fgLocalHostString[] =          u"localhost";
const XMLCh XMLUni::fgNoString[] =                 u"no";
const XMLCh XMLUni::fgNotationString[] =           u"NOTATION";
const XMLCh XMLUni::fgNDATAString[] =              u"NDATA";
const XMLCh XMLUni::fgNmTokenString[] =            u"NMTOKEN";
const XMLCh XMLUni::fgNmTokensString[] =           u"NMTOKENS";
const XMLCh XMLUni::fgPCDATAString[] =             u"#PCDATA";
const XMLCh XMLUni::fgPIString[] =                 u"<?";
const XMLCh XMLUni::fgPubIDString[] =              u"PUBLIC";
const XMLCh XMLUni::fgRefString[] =                u"REF";
const XMLCh XMLUni::fgRequiredString[] =           u"#REQUIRED";
const XMLCh XMLUni::fgStandaloneString[] =         u"standalone";
const XMLCh XMLUni::fgVersion1[] =                 u"1.";
const XMLCh XMLUni::fgVersion1_0[] =               u"1.0";
const XMLCh XMLUni::fgVersion1_1[] =               u"1.1";
const XMLCh XMLUni::fgSysIDString[] =              u"SYSTEM";
const XMLCh XMLUni::fgUnknownURIName[] =           u"http://apache.org/xml/UnknownNS";
const XMLCh XMLUni::fgUCS4EncodingString[] =       u"UCS4";
const XMLCh XMLUni::fgUCS4EncodingString2[] =      u"UCS-4";
const XMLCh XMLUni::fgUCS4EncodingString3[] =      u"UCS_4";
const XMLCh XMLUni::fgUCS4EncodingString4[] =      u"UTF-32";
const XMLCh XMLUni::fgUCS4EncodingString5[] =      u"ISO-10646-UCS-4";
const XMLCh XMLUni::fgUCS4BEncodingString[] =      u"UCS-4 (BE)";
const XMLCh XMLUni::fgUCS4BEncodingString2[] =     u"UCS-4BE";
const XMLCh XMLUni::fgUCS4LEncodingString[] =      u"UCS-4 (LE)";
const XMLCh XMLUni::fgUCS4LEncodingString2[] =     u"UCS-4LE";
const XMLCh XMLUni::fgUSASCIIEncodingString[] =    u"US-ASCII";
const XMLCh XMLUni::fgUSASCIIEncodingString2[] =   u"USASCII";
const XMLCh XMLUni::fgUSASCIIEncodingString3[] =   u"ASCII";
const XMLCh XMLUni::fgUSASCIIEncodingString4[] =   u"US_ASCII";
const XMLCh XMLUni::fgUTF8EncodingString[] =       u"UTF-8";
const XMLCh XMLUni::fgUTF8EncodingString2[] =      u"UTF8";
const XMLCh XMLUni::fgUTF16EncodingString[] =      u"UTF-16";
const XMLCh XMLUni::fgUTF16EncodingString2[] =     u"UCS2";
const XMLCh XMLUni::fgUTF16EncodingString3[] =     u"IBM1200";
const XMLCh XMLUni::fgUTF16EncodingString4[] =     u"IBM-1200";
const XMLCh XMLUni::fgUTF16EncodingString5[] =     u"UTF16";
const XMLCh XMLUni::fgUTF16EncodingString6[] =     u"UCS-2";
const XMLCh XMLUni::fgUTF16EncodingString7[] =     u"ISO-10646-UCS-2";
const XMLCh XMLUni::fgUTF16BEncodingString[] =     u"UTF-16 (BE)";
const XMLCh XMLUni::fgUTF16BEncodingString2[] =    u"UTF-16BE";
const XMLCh XMLUni::fgUTF16LEncodingString[] =     u"UTF-16 (LE)";
const XMLCh XMLUni::fgUTF16LEncodingString2[] =    u"UTF-16LE";
const XMLCh XMLUni::fgVersionString[] =            u"version";
const XMLCh XMLUni::fgValidityDomain[] =           u"http://apache.org/xml/messages/XMLValidity";
const XMLCh XMLUni::fgWin1252EncodingString[] =    u"WINDOWS-1252";
const XMLCh XMLUni::fgXMLChEncodingString[] =      u"XERCES-XMLCH";
const XMLCh XMLUni::fgXMLString[] =                u"xml";
//xml{S}
const XMLCh XMLUni::fgXMLStringSpace[] =           u"xml ";
const XMLCh XMLUni::fgXMLStringHTab[] =            u"xml\t";
const XMLCh XMLUni::fgXMLStringCR[] =              u"xml\r";
const XMLCh XMLUni::fgXMLStringLF[] =              u"xml\n";
//XML{S}
const XMLCh XMLUni::fgXMLStringSpaceU[] =          u"XML ";
const XMLCh XMLUni::fgXMLStringHTabU[] =           u"XML\t";
const XMLCh XMLUni::fgXMLStringCRU[] =             u"XML\r";
const XMLCh XMLUni::fgXMLStringLFU[] =             u"XML\n";
const XMLCh XMLUni::fgXMLDeclString[] =            u"<?xml";
//<?xml{S}
const XMLCh XMLUni::fgXMLDeclStringSpace[] =       u"<?xml ";
const XMLCh XMLUni::fgXMLDeclStringHTab[] =        u"<?xml\t";
const XMLCh XMLUni::fgXMLDeclStringLF[] =          u"<?xml\n";
const XMLCh XMLUni::fgXMLDeclStringCR[] =          u"<?xml\r";
//<?XML{S}
const XMLCh XMLUni::fgXMLDeclStringSpaceU[] =      u"<?XML ";
const XMLCh XMLUni::fgXMLDeclStringHTabU[] =       u"<?XML\t";
const XMLCh XMLUni::fgXMLDeclStringLFU[] =         u"<?XML\n";
const XMLCh XMLUni::fgXMLDeclStringCRU[] =         u"<?XML\r";
const XMLCh XMLUni::fgXMLNSString[] =              u"xmlns";
const XMLCh XMLUni::fgXMLNSColonString[] =         u"xmlns:";
const XMLCh XMLUni::fgXMLNSURIName[] =             u"http://www.w3.org/2000/xmlns/";
const XMLCh XMLUni::fgXMLErrDomain[] =             u"http://apache.org/xml/messages/XMLErrors";
const XMLCh XMLUni::fgXMLURIName[] =               u"http://www.w3.org/XML/1998/namespace";
const XMLCh XMLUni::fgInfosetURIName[] =           u"http://www.w3.org/TR/REC-xml";
const XMLCh XMLUni::fgYesString[] =                u"yes";
const XMLCh XMLUni::fgZeroLenString[] =            u"";
const XMLCh XMLUni::fgDTDEntityString[] =          u"[dtd]";
const XMLCh XMLUni::fgAmp[] =                      u"amp";
const XMLCh XMLUni::fgLT[] =                       u"lt";
const XMLCh XMLUni::fgGT[] =                       u"gt";
const XMLCh XMLUni::fgQuot[] =                     u"quot";
const XMLCh XMLUni::fgApos[] =                     u"apos";
const XMLCh XMLUni::fgWFXMLScanner[] =             u"WFXMLScanner";
const XMLCh XMLUni::fgIGXMLScanner[] =             u"IGXMLScanner";
const XMLCh XMLUni::fgSGXMLScanner[] =             u"SGXMLScanner";
const XMLCh XMLUni::fgDGXMLScanner[] =             u"DGXMLScanner";
const XMLCh XMLUni::fgXSAXMLScanner[] =            u"XSAXMLScanner";
const XMLCh XMLUni::fgCDataStart[] =               u"<![CDATA[";
const XMLCh XMLUni::fgCDataEnd[] =                 u"]]>";

//Exception strings
const XMLCh XMLUni::fgArrayIndexOutOfBoundsException_Name[] = u"ArrayIndexOutofBoundsException";
const XMLCh XMLUni::fgEmptyStackException_Name[] =            u"EmptyStackException";
const XMLCh XMLUni::fgIllegalArgumentException_Name[] =       u"IllegalArgumentException";
const XMLCh XMLUni::fgInvalidCastException_Name[] =           u"InvalidCastException";
const XMLCh XMLUni::fgIOException_Name[] =                    u"IOException";
const XMLCh XMLUni::fgNoSuchElementException_Name[] =         u"NoSuchElementException";
const XMLCh XMLUni::fgNullPointerException_Name[] =           u"NullPointerException";
const XMLCh XMLUni::fgXMLPlatformUtilsException_Name[] =      u"XMLPlatformException";
const XMLCh XMLUni::fgRuntimeException_Name[] =               u"RuntimeException";
const XMLCh XMLUni::fgTranscodingException_Name[] =           u"TranscodingException";
const XMLCh XMLUni::fgUnexpectedEOFException_Name[] =         u"UnexpectedEOFException";
const XMLCh XMLUni::fgUnsupportedEncodingException_Name[] =   u"UnsupportedEncodingException";
const XMLCh XMLUni::fgUTFDataFormatException_Name[] =         u"UTFDataFormatException";
const XMLCh XMLUni::fgNetAccessorException_Name[] =           u"NetAccessorException";
const XMLCh XMLUni::fgMalformedURLException_Name[] =          u"MalformedURLException";
const XMLCh XMLUni::fgNumberFormatException_Name[] =          u"NumberFormatException";
const XMLCh XMLUni::fgParseException_Name[] =                 u"ParseException";
const XMLCh XMLUni::fgInvalidDatatypeFacetException_Name[] =  u"InvalidDatatypeFacetException";
const XMLCh XMLUni::fgInvalidDatatypeValueException_Name[] =  u"InvalidDatatypeValueException";
const XMLCh XMLUni::fgSchemaDateTimeException_Name[] =        u"SchemaDateTimeException";
const XMLCh XMLUni::fgXPathException_Name[] =                 u"XPathException";
const XMLCh XMLUni::fgXSerializationException_Name[] =        u"XSerializationException";
const XMLCh XMLUni::fgXMLXIncludeException_Name[] =           u"XMLXIncludeException";
const XMLCh XMLUni::fgNegINFString[] =                        u"-INF";
const XMLCh XMLUni::fgNegZeroString[] =                       u"-0";
const XMLCh XMLUni::fgPosZeroString[] =                       u"0";
const XMLCh XMLUni::fgPosINFString[] =                        u"INF";
const XMLCh XMLUni::fgNaNString[] =                           u"NaN";
const XMLCh XMLUni::fgEString[] =                             u"E";
const XMLCh XMLUni::fgZeroString[] =                          u"0";
const XMLCh XMLUni::fgNullString[] =                          u"null";

const XMLCh XMLUni::fgSAX2CoreValidation[] =                            u"http://xml.org/sax/features/validation";
const XMLCh XMLUni::fgSAX2CoreNameSpaces[] =                            u"http://xml.org/sax/features/namespaces";
const XMLCh XMLUni::fgSAX2CoreNameSpacePrefixes[] =                     u"http://xml.org/sax/features/namespace-prefixes";
const XMLCh XMLUni::fgXercesDynamic[] =                                 u"http://apache.org/xml/features/validation/dynamic";
const XMLCh XMLUni::fgXercesSchema[] =                                  u"http://apache.org/xml/features/validation/schema";
const XMLCh XMLUni::fgXercesSchemaFullChecking[] =                      u"http://apache.org/xml/features/validation/schema-full-checking";
const XMLCh XMLUni::fgXercesLoadSchema[] =                              u"http://apache.org/xml/features/validating/load-schema";
const XMLCh XMLUni::fgXercesIdentityConstraintChecking[] =              u"http://apache.org/xml/features/validation/identity-constraint-checking";
const XMLCh XMLUni::fgXercesLoadExternalDTD[] =                         u"http://apache.org/xml/features/nonvalidating/load-external-dtd";
const XMLCh XMLUni::fgXercesContinueAfterFatalError[] =                 u"http://apache.org/xml/features/continue-after-fatal-error";
const XMLCh XMLUni::fgXercesValidationErrorAsFatal[] =                  u"http://apache.org/xml/features/validation-error-as-fatal";
const XMLCh XMLUni::fgXercesCalculateSrcOfs[] =                         u"http://apache.org/xml/features/calculate-src-ofs";
const XMLCh XMLUni::fgXercesStandardUriConformant[] =                   u"http://apache.org/xml/features/standard-uri-conformant";
const XMLCh XMLUni::fgXercesDOMHasPSVIInfo[] =                          u"http://apache.org/xml/features/dom-has-psvi-info";
const XMLCh XMLUni::fgXercesGenerateSyntheticAnnotations[] =            u"http://apache.org/xml/features/generate-synthetic-annotations";
const XMLCh XMLUni::fgXercesValidateAnnotations[] =                     u"http://apache.org/xml/features/validate-annotations";
const XMLCh XMLUni::fgXercesSchemaExternalSchemaLocation[] =            u"http://apache.org/xml/properties/schema/external-schemaLocation";
const XMLCh XMLUni::fgXercesSecurityManager[] =                         u"http://apache.org/xml/properties/security-manager";
const XMLCh XMLUni::fgXercesSchemaExternalNoNameSpaceSchemaLocation[] = u"http://apache.org/xml/properties/schema/external-noNamespaceSchemaLocation";
const XMLCh XMLUni::fgXercesScannerName[] =                             u"http://apache.org/xml/properties/scannerName";
const XMLCh XMLUni::fgXercesParserUseDocumentFromImplementation[] =     u"http://apache.org/xml/properties/parser-use-DOMDocument-from-Implementation";
const XMLCh XMLUni::fgXercesEntityResolver[] =                          u"http://apache.org/xml/properties/entity-resolver";
const XMLCh XMLUni::fgXercesUserAdoptsDOMDocument[] =                   u"http://apache.org/xml/features/dom/user-adopts-DOMDocument";
const XMLCh XMLUni::fgXercesCacheGrammarFromParse[] =                   u"http://apache.org/xml/features/validation/cache-grammarFromParse";
const XMLCh XMLUni::fgXercesUseCachedGrammarInParse[] =                 u"http://apache.org/xml/features/validation/use-cachedGrammarInParse";
const XMLCh XMLUni::fgXercesIgnoreCachedDTD[] =                         u"http://apache.org/xml/features/validation/ignoreCachedDTD";
const XMLCh XMLUni::fgXercesIgnoreAnnotations[] =                       u"http://apache.org/xml/features/schema/ignore-annotations";
const XMLCh XMLUni::fgXercesDisableDefaultEntityResolution[] =          u"http://apache.org/xml/features/disable-default-entity-resolution";
const XMLCh XMLUni::fgXercesSkipDTDValidation[] =                       u"http://apache.org/xml/features/validation/schema/skip-dtd-validation";
const XMLCh XMLUni::fgXercesHandleMultipleImports[] =                   u"http://apache.org/xml/features/validation/schema/handle-multiple-imports";
const XMLCh XMLUni::fgXercesLowWaterMark[] =                            u"http://apache.org/xml/properties/low-water-mark";

//Introduced in DOM Level 3
const XMLCh XMLUni::fgDOMCanonicalForm[] =                         u"canonical-form";
const XMLCh XMLUni::fgDOMCDATASections[] =                         u"cdata-sections";
const XMLCh XMLUni::fgDOMComments[] =                              u"comments";
const XMLCh XMLUni::fgDOMCharsetOverridesXMLEncoding[] =           u"charset-overrides-xml-encoding";
const XMLCh XMLUni::fgDOMCheckCharacterNormalization[] =           u"check-character-normalization";
const XMLCh XMLUni::fgDOMDatatypeNormalization[] =                 u"datatype-normalization";
const XMLCh XMLUni::fgDOMDisallowDoctype[] =                       u"disallow-doctype";
const XMLCh XMLUni::fgDOMElementContentWhitespace[] =              u"element-content-whitespace";
const XMLCh XMLUni::fgDOMEntities[] =                              u"entities";
const XMLCh XMLUni::fgDOMErrorHandler[] =                          u"error-handler";
const XMLCh XMLUni::fgDOMInfoset[] =                               u"infoset";
const XMLCh XMLUni::fgDOMIgnoreUnknownCharacterDenormalization[] = u"ignore-unknown-character-denormalization";
const XMLCh XMLUni::fgDOMNamespaces[] =                            u"namespaces";
const XMLCh XMLUni::fgDOMNamespaceDeclarations[] =                 u"namespace-declarations";
const XMLCh XMLUni::fgDOMNormalizeCharacters[] =                   u"normalize-characters";
const XMLCh XMLUni::fgDOMResourceResolver[] =                      u"resource-resolver";
const XMLCh XMLUni::fgDOMSchemaLocation[] =                        u"schema-location";
const XMLCh XMLUni::fgDOMSchemaType[] =                            u"schema-type";
const XMLCh XMLUni::fgDOMSplitCDATASections[] =                    u"split-cdata-sections";
const XMLCh XMLUni::fgDOMSupportedMediatypesOnly[] =               u"supported-media-types-only";
const XMLCh XMLUni::fgDOMValidate[] =                              u"validate";
const XMLCh XMLUni::fgDOMValidateIfSchema[] =                      u"validate-if-schema";
const XMLCh XMLUni::fgDOMWellFormed[] =                            u"well-formed";
const XMLCh XMLUni::fgDOMXMLSchemaType[] =                         u"http://www.w3.org/2001/XMLSchema";
const XMLCh XMLUni::fgDOMDTDType[] =                               u"http://www.w3.org/TR/REC-xml";
const XMLCh XMLUni::fgDOMWRTCanonicalForm[] =                      u"canonical-form";
const XMLCh XMLUni::fgDOMWRTDiscardDefaultContent[] =              u"discard-default-content";
const XMLCh XMLUni::fgDOMWRTEntities[] =                           u"entities";
const XMLCh XMLUni::fgDOMWRTFormatPrettyPrint[] =                  u"format-pretty-print";
const XMLCh XMLUni::fgDOMWRTNormalizeCharacters[] =                u"normalize-characters";
const XMLCh XMLUni::fgDOMWRTSplitCdataSections[] =                 u"split-cdata-sections";
const XMLCh XMLUni::fgDOMWRTValidation[] =                         u"validation";
const XMLCh XMLUni::fgDOMWRTWhitespaceInElementContent[] =         u"whitespace-in-element-content";
const XMLCh XMLUni::fgDOMWRTBOM[] = u"http://apache.org/xml/features/dom/byte-order-mark";
const XMLCh XMLUni::fgDOMXMLDeclaration[] = u"xml-declaration";

const XMLCh XMLUni::fgDOMWRTXercesPrettyPrint[] = u"http://apache.org/xml/features/pretty-print/space-first-level-elements";
const XMLCh XMLUni::fgXercescInterfacePSVITypeInfo[] = u"DOMPSVITypeInfo";
const XMLCh XMLUni::fgXercescInterfaceDOMDocumentTypeImpl[] = u"DOMDocumentTypeImpl";
const XMLCh XMLUni::fgXercescInterfaceDOMDocumentImpl[] = u"DOMDocumentImpl";
const XMLCh XMLUni::fgXercescInterfaceDOMMemoryManager[] = u"DOMMemoryManager";
const char XMLUni::fgXercescDefaultLocale[] = "en_US";
const XMLCh XMLUni::fgXMLDOMMsgDomain[] = u"http://apache.org/xml/messages/XMLDOMMsg";
const XMLCh XMLUni::fgDefErrMsg[] = u"Could not load message";
const XMLCh XMLUni::fgValueZero[] = u"0";
const XMLCh XMLUni::fgNegOne[] = u"-1";
const XMLCh XMLUni::fgValueOne[] = u"1";
const XMLCh XMLUni::fgLongMaxInc[] = u"9223372036854775807";
const XMLCh XMLUni::fgLongMinInc[] = u"-9223372036854775808";
const XMLCh XMLUni::fgIntMaxInc[] = u"2147483647";
const XMLCh XMLUni::fgIntMinInc[] = u"-2147483648";
const XMLCh XMLUni::fgShortMaxInc[] = u"32767";
const XMLCh XMLUni::fgShortMinInc[] = u"-32768";
const XMLCh XMLUni::fgByteMaxInc[] = u"127";
const XMLCh XMLUni::fgByteMinInc[] = u"-128";
const XMLCh XMLUni::fgULongMaxInc[] = u"18446744073709551615";
const XMLCh XMLUni::fgUIntMaxInc[] = u"4294967295";
const XMLCh XMLUni::fgUShortMaxInc[] = u"65535";
const XMLCh XMLUni::fgUByteMaxInc[] = u"255";
// http://www.w3.org/2001/05/xmlschema-errata#Errata2 §E2-25
const XMLCh XMLUni::fgLangPattern[] = u"([a-zA-Z]{1,8})(-[a-zA-Z0-9]{1,8})*";
const XMLCh XMLUni::fgBooleanValueSpace[][8] =
{ u"false",
  u"true",
  u"0",
  u"1"
};

const XMLSize_t XMLUni::fgBooleanValueSpaceArraySize = sizeof XMLUni::fgBooleanValueSpace / sizeof (XMLUni::fgBooleanValueSpace[0]);

const XMLCh XMLUni::fgXercesDoXInclude[] = u"DoXI";
}
