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


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/XMLUniDefs.hpp>
#include "PSVIUni.hpp"

using namespace XERCES_CPP_NAMESPACE;


const XMLCh PSVIUni::fgPsvColon[] =                 u"psv:";
const XMLCh PSVIUni::fgAllDeclarationsProcessed[] = u"allDeclarationsProcessed";
const XMLCh PSVIUni::fgAttribute[] =                u"attribute";
const XMLCh PSVIUni::fgAttributes[] =               u"attributes";
const XMLCh PSVIUni::fgAttributeType[] =            u"attributeType";
const XMLCh PSVIUni::fgBaseURI[] =                  u"baseURI";
const XMLCh PSVIUni::fgCanonicalRepresentation[] =  u"psv:canonicalRep";
const XMLCh PSVIUni::fgCharacter[] =                u"character";
const XMLCh PSVIUni::fgCharacterEncodingScheme[] =  u"characterEncodingScheme";
const XMLCh PSVIUni::fgChildren[] =                 u"children";
const XMLCh PSVIUni::fgComment[] =                  u"comment";
const XMLCh PSVIUni::fgContent[] =                  u"content";
const XMLCh PSVIUni::fgDocument[] =                 u"document";
const XMLCh PSVIUni::fgDocTypeDeclaration[] =       u"docTypeDeclaration";
const XMLCh PSVIUni::fgDocumentElement[] =          u"documentElement";
const XMLCh PSVIUni::fgElement[] =                  u"element";
const XMLCh PSVIUni::fgInScopeNamespaces[] =        u"inScopeNamespaces";
const XMLCh PSVIUni::fgLocalName[] =                u"localName";
const XMLCh PSVIUni::fgNamespace[] =                u"namespace";
const XMLCh PSVIUni::fgNamespaceAttributes[] =      u"namespaceAttributes";
const XMLCh PSVIUni::fgNamespaceName[] =            u"namespaceName";
const XMLCh PSVIUni::fgNormalizedValue[] =          u"normalizedValue";
const XMLCh PSVIUni::fgNotations[] =                u"notations";
const XMLCh PSVIUni::fgPrefix[] =                   u"prefix";
const XMLCh PSVIUni::fgProcessingInstruction[] =    u"processingInstruction";
const XMLCh PSVIUni::fgReferences[] =               u"references";
const XMLCh PSVIUni::fgSpecified[] =                u"specified";
const XMLCh PSVIUni::fgStandalone[] =               u"standalone";
const XMLCh PSVIUni::fgTarget[] =                   u"target";
const XMLCh PSVIUni::fgText[] =                     u"text";
const XMLCh PSVIUni::fgTextContent[] =              u"textContent";
const XMLCh PSVIUni::fgUnparsedEntities[] =         u"unparsedEntities";
const XMLCh PSVIUni::fgVersion[] =                  u"version";


const XMLCh PSVIUni::fgAbstract[] =                      u"psv:abstract";
const XMLCh PSVIUni::fgAnnotation[] =                    u"psv:annotation";
const XMLCh PSVIUni::fgAnnotations[] =                   u"psv:annotations";
const XMLCh PSVIUni::fgApplicationInformation[] =        u"psv:applicationInformation";
const XMLCh PSVIUni::fgAttributeDeclaration[] =          u"psv:attributeDeclaration";
const XMLCh PSVIUni::fgAttributeGroupDefinition[] =      u"psv:attributeGroupDefinition";
const XMLCh PSVIUni::fgAttributeUse[] =                  u"psv:attributeUse";
const XMLCh PSVIUni::fgAttributeUses[] =                 u"psv:attributeUses";
const XMLCh PSVIUni::fgAttributeWildcard[] =             u"psv:attributeWildcard";
const XMLCh PSVIUni::fgBaseTypeDefinition[] =            u"psv:baseTypeDefinition";
const XMLCh PSVIUni::fgComplexTypeDefinition[] =         u"psv:complexTypeDefinition";
const XMLCh PSVIUni::fgCompositor[] =                    u"psv:compositor";
const XMLCh PSVIUni::fgContentType[] =                   u"psv:contentType";
const XMLCh PSVIUni::fgDeclaration[] =                   u"psv:declaration";
const XMLCh PSVIUni::fgDerivationMethod[] =              u"psv:derivationMethod";
const XMLCh PSVIUni::fgDisallowedSubstitutions[] =       u"psv:disallowedSubstitutions";
const XMLCh PSVIUni::fgDocumentLocation[] =              u"psv:documentLocation";
const XMLCh PSVIUni::fgPsvDocument[] =                   u"psv:document";
const XMLCh PSVIUni::fgElementDeclaration[] =            u"psv:elementDeclaration";
const XMLCh PSVIUni::fgFacetFixed[] =                    u"psv:fixed";
const XMLCh PSVIUni::fgFacets[] =                        u"psv:facets";
const XMLCh PSVIUni::fgFields[] =                        u"psv:fields";
const XMLCh PSVIUni::fgFinal[] =                         u"psv:final";
const XMLCh PSVIUni::fgFundamentalFacets[] =             u"psv:fundamentalFacets";
const XMLCh PSVIUni::fgIdentityConstraintCategory[] =    u"psv:identityConstraintCategory";
const XMLCh PSVIUni::fgIdentityConstraintDefinition[] =  u"psv:identityConstraintDefinition";
const XMLCh PSVIUni::fgIdentityConstraintDefinitions[] = u"psv:identityConstraintDefinitions";
const XMLCh PSVIUni::fgIdentityConstraintTable[] =       u"psv:identityConstraintTable";
const XMLCh PSVIUni::fgIdIdrefTable[] =                  u"psv:idIdrefTable";
const XMLCh PSVIUni::fgItemTypeDefinition[] =            u"psv:itemTypeDefinition";
const XMLCh PSVIUni::fgMaxOccurs[] =                     u"psv:maxOccurs";
const XMLCh PSVIUni::fgMemberTypeDefinition[] =          u"psv:memberTypeDefinition";
const XMLCh PSVIUni::fgMemberTypeDefinitions[] =         u"psv:memberTypeDefinitions";
const XMLCh PSVIUni::fgMinOccurs[] =                     u"psv:minOccurs";
const XMLCh PSVIUni::fgModelGroup[] =                    u"psv:modelGroup";
const XMLCh PSVIUni::fgModelGroupDefinition[] =          u"psv:modelGroupDefinition";
const XMLCh PSVIUni::fgName[] =                          u"psv:name";
const XMLCh PSVIUni::fgNamespaceConstraint[] =           u"psv:namespaceConstraint";
const XMLCh PSVIUni::fgNamespaces[] =                    u"psv:namespaces";
const XMLCh PSVIUni::fgNamespaceSchemaInformation[] =    u"psv:namespaceSchemaInformation";
const XMLCh PSVIUni::fgNil[] =                           u"psv:nil";
const XMLCh PSVIUni::fgNillable[] =                      u"psv:nillable";
const XMLCh PSVIUni::fgNotation[] =                      u"psv:notation";
const XMLCh PSVIUni::fgNotationDeclaration[] =           u"psv:notationDeclaration";
const XMLCh PSVIUni::fgParticle[] =                      u"psv:particle";
const XMLCh PSVIUni::fgParticles[] =                     u"psv:particles";
const XMLCh PSVIUni::fgPrimitiveTypeDefinition[] =       u"psv:primitiveTypeDefinition";
const XMLCh PSVIUni::fgProcessContents[] =               u"psv:processContents";
const XMLCh PSVIUni::fgProhibitedSubstitutions[] =       u"psv:prohibitedSubstitutions";
const XMLCh PSVIUni::fgPublicIdentifier[] =              u"psv:publicIdentifier";
const XMLCh PSVIUni::fgReferencedKey[] =                 u"psv:referencedKey";
const XMLCh PSVIUni::fgRequired[] =                      u"psv:required";
const XMLCh PSVIUni::fgSchemaAnnotations[] =             u"psv:schemaAnnotations";
const XMLCh PSVIUni::fgSchemaComponents[] =              u"psv:schemaComponents";
const XMLCh PSVIUni::fgSchemaDefault[] =                 u"psv:schemaDefault";
const XMLCh PSVIUni::fgSchemaDocument[] =                u"psv:schemaDocument";
const XMLCh PSVIUni::fgSchemaDocuments[] =               u"psv:schemaDocuments";
const XMLCh PSVIUni::fgSchemaErrorCode[] =               u"psv:schemaErrorCode";
const XMLCh PSVIUni::fgSchemaInformation[] =             u"psv:schemaInformation";
const XMLCh PSVIUni::fgSchemaNamespace[] =               u"psv:schemaNamespace";
const XMLCh PSVIUni::fgSchemaNormalizedValue[] =         u"psv:schemaNormalizedValue";
const XMLCh PSVIUni::fgSchemaSpecified[] =               u"psv:schemaSpecified";
const XMLCh PSVIUni::fgScope[] =                         u"psv:scope";
const XMLCh PSVIUni::fgSelector[] =                      u"psv:selector";
const XMLCh PSVIUni::fgSimpleTypeDefinition[] =          u"psv:simpleTypeDefinition";
const XMLCh PSVIUni::fgSubstitutionGroupAffiliation[] =  u"psv:substitutionGroupAffiliation";
const XMLCh PSVIUni::fgSubstitutionGroupExclusions[] =   u"psv:substitutionGroupExclusions";
const XMLCh PSVIUni::fgSystemIdentifier[] =              u"psv:systemIdentifier";
const XMLCh PSVIUni::fgTargetNamespace[] =               u"psv:targetNamespace";
const XMLCh PSVIUni::fgTerm[] =                          u"psv:term";
const XMLCh PSVIUni::fgTypeDefinition[] =                u"psv:typeDefinition";
const XMLCh PSVIUni::fgUserInformation[] =               u"psv:userInformation";
const XMLCh PSVIUni::fgValidationAttempted[] =           u"psv:validationAttempted";
const XMLCh PSVIUni::fgValidationContext[] =             u"psv:validationContext";
const XMLCh PSVIUni::fgValidity[] =                      u"psv:validity";
const XMLCh PSVIUni::fgValue[] =                         u"psv:value";
const XMLCh PSVIUni::fgValueConstraint[] =               u"psv:valueConstraint";
const XMLCh PSVIUni::fgVariety[] =                       u"psv:variety";
const XMLCh PSVIUni::fgWildcard[] =                      u"psv:wildcard";
const XMLCh PSVIUni::fgXpath[] =                         u"psv:xpath";

const XMLCh PSVIUni::fgAll[] =           u"all";
const XMLCh PSVIUni::fgAny[] =           u"any";
const XMLCh PSVIUni::fgAppinfo[] =       u"appinfo";
const XMLCh PSVIUni::fgAtomic[] =        u"atomic";
const XMLCh PSVIUni::fgChoice[] =        u"choice";
const XMLCh PSVIUni::fgDefault[] =       u"default";
const XMLCh PSVIUni::fgDocumentation[] = u"documentation";
const XMLCh PSVIUni::fgElementOnly[] =   u"elementOnly";
const XMLCh PSVIUni::fgEmpty[] =         u"empty";
const XMLCh PSVIUni::fgExtension[] =     u"extension";
const XMLCh PSVIUni::fgFalse[] =         u"false";
const XMLCh PSVIUni::fgFull[] =          u"full";
const XMLCh PSVIUni::fgGlobal[] =        u"global";
const XMLCh PSVIUni::fgInfoset[] =       u"infoset";
const XMLCh PSVIUni::fgInvalid[] =       u"invalid";
const XMLCh PSVIUni::fgKey[] =           u"key";
const XMLCh PSVIUni::fgKeyref[] =        u"keyref";
const XMLCh PSVIUni::fgLax[] =           u"lax";
const XMLCh PSVIUni::fgList[] =          u"list";
const XMLCh PSVIUni::fgLocal[] =         u"local";
const XMLCh PSVIUni::fgMixed[] =         u"mixed";
const XMLCh PSVIUni::fgNone[] =          u"none";
const XMLCh PSVIUni::fgNotKnown[] =      u"notKnown";
const XMLCh PSVIUni::fgNsNamespace[] =   u"nsNamespace";
const XMLCh PSVIUni::fgOnePointZero[] =  u"1.0";
const XMLCh PSVIUni::fgPartial[] =       u"partial";
const XMLCh PSVIUni::fgRestrict[] =      u"restrict";
const XMLCh PSVIUni::fgRestriction[] =   u"restriction";
const XMLCh PSVIUni::fgSchema[] =        u"schema";
const XMLCh PSVIUni::fgSequence[] =      u"sequence";
const XMLCh PSVIUni::fgSimple[] =        u"simple";
const XMLCh PSVIUni::fgSkip[] =          u"skip";
const XMLCh PSVIUni::fgStrict[] =        u"strict";
const XMLCh PSVIUni::fgSubstitution[] =  u"substitution";
const XMLCh PSVIUni::fgTotal[] =         u"total";
const XMLCh PSVIUni::fgTrue[] =          u"true";
const XMLCh PSVIUni::fgUnbounded[] =     u"unbounded";
const XMLCh PSVIUni::fgUnion[] =         u"union";
const XMLCh PSVIUni::fgUnique[] =        u"unique";
const XMLCh PSVIUni::fgUnknown[] =       u"unknown";
const XMLCh PSVIUni::fgValid[] =         u"valid";
const XMLCh PSVIUni::fgVCFixed[] =       u"fixed";
const XMLCh PSVIUni::fgXMLChNull[] =     u"";

const XMLCh PSVIUni::fgAg[] =             u"ag";
const XMLCh PSVIUni::fgAnnot[] =          u"annot";
const XMLCh PSVIUni::fgAttr[] =           u"attr";
const XMLCh PSVIUni::fgAu[] =             u"au";
const XMLCh PSVIUni::fgElt[] =            u"elt";
const XMLCh PSVIUni::fgIdc[] =            u"idc";
const XMLCh PSVIUni::fgMg[] =             u"mg";
const XMLCh PSVIUni::fgNot[] =            u"not";
const XMLCh PSVIUni::fgType[] =           u"type";
const XMLCh PSVIUni::fgBounded[] =        u"psv:bounded";
const XMLCh PSVIUni::fgCardinality[] =    u"psv:cardinality";
const XMLCh PSVIUni::fgEnumeration[] =    u"psv:enumeration";
const XMLCh PSVIUni::fgFractionDigits[] = u"psv:fractionDigits";
const XMLCh PSVIUni::fgLength[] =         u"psv:length";
const XMLCh PSVIUni::fgMaxExclusive[] =   u"psv:maxExclusive";
const XMLCh PSVIUni::fgMaxInclusive[] =   u"psv:maxInclusive";
const XMLCh PSVIUni::fgMaxLength[] =      u"psv:maxLength";
const XMLCh PSVIUni::fgMinExclusive[] =   u"psv:minExclusive";
const XMLCh PSVIUni::fgMinInclusive[] =   u"psv:minInclusive";
const XMLCh PSVIUni::fgMinLength[] =      u"psv:minLength";
const XMLCh PSVIUni::fgNumeric[] =        u"psv:numeric";
const XMLCh PSVIUni::fgOrdered[] =        u"psv:ordered";
const XMLCh PSVIUni::fgPattern[] =        u"psv:pattern";
const XMLCh PSVIUni::fgTotalDigits[] =    u"psv:totalDigits";
const XMLCh PSVIUni::fgWhiteSpace[] =     u"psv:whiteSpace";


const XMLCh PSVIUni::fgNamespaceInfoset[] =   u"http://www.w3.org/2001/05/XMLInfoset";
const XMLCh PSVIUni::fgXsi[] =                u"xsi";
const XMLCh PSVIUni::fgNamespaceInstance[] =  u"http://www.w3.org/2001/XMLSchema-instance";
const XMLCh PSVIUni::fgPsv[] =                u"psv";
const XMLCh PSVIUni::fgNamespacePsvi[] =      u"http://apache.org/xml/2001/PSVInfosetExtension";
const XMLCh PSVIUni::fgXml[] =                u"xml";
const XMLCh PSVIUni::fgNamespaceXmlSchema[] = u"http://www.w3.org/2001/XMLSchema";
