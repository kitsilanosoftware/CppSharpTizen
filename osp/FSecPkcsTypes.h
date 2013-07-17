//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FSecPkcsTypes.h
 * @brief		This is the header file for the declarations of the %PkcsAlgorithmParameterType and %Pkcs08TagValue enumerators and the AttributeType OID List.
 *
 * This header file contains the declarations of the %PkcsAlgorithmParameterType and %Pkcs08TagValue enumerators and the AttributeType OID List.
 */

#ifndef _FSEC_PKCS_TYPES_H_
#define _FSEC_PKCS_TYPES_H_

#include <FBaseString.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @enum    PkcsAlgorithmParameterType
 *
 * Defines the types of parameters.
 *
 * @since		2.1
 */
enum PkcsAlgorithmParameterType
{
	PKCS_ALGO_PARAM_TYPE_IV,              /**< The parameter type is initial vector */
	PKCS_ALGO_PARAM_TYPE_PKCS05_PBES02,   /**< The parameter type is pkcs5 password based encryption scheme2 */
	PKCS_ALGO_PARAM_TYPE_PKCS05_KDF02,    /**< The parameter type is pkcs5 password based key derivation scheme2 */
	PKCS_ALGO_PARAM_TYPE_PKCS05_MAC,      /**< The parameter type is pkcs5 message authentication scheme */
	PKCS_ALGO_PARAM_TYPE_RC2,             /**< The parameter type is rc2 cbc */
	PKCS_ALGO_PARAM_TYPE_UNKOWN = 0xFFFFFFFF  /**< An unknown parameter type */
}; //PkcsAlgorithmParameterType;

/**
 * @enum	Pkcs08TagValue
 *
 * Defines the Asn1 tag type.
 *
 * @since 2.1
 */
enum Pkcs08TagValue
{
	PKCS08_TAG_RESERVED = 0, /**< Reserved for use by the encoding rules */
	PKCS08_TAG_BOOLEAN = 1, /**< An arbitrary bool value */
	PKCS08_TAG_INTEGER = 2, /**< An arbitrary integer value */
	PKCS08_TAG_BITSTRING = 3, /**< An arbitrary string of bits */
	PKCS08_TAG_OCTETSTRING = 4, /**< An arbitrary string of octets */
	PKCS08_TAG_NULL = 5, /**< A null value */
	PKCS08_TAG_OBJECT_ID = 6, /**< An object identifier */
	PKCS08_TAG_OBJECT_DES = 7, /**< An object descriptor providing a brief description of an object */
	PKCS08_TAG_EXTERNAL = 8, /**< An arbitrary external value */
	PKCS08_TAG_REAL = 9, /**< An arbitrary real value */
	PKCS08_TAG_ENUM = 10, /**< An enumerated value */
	PKCS08_TAG_EMBEDDED = 11, /**< An embedded value */
	PKCS08_TAG_UTF8STRING = 12, /**< An arbitrary utf8 string */
	PKCS08_TAG_REL_OBJ_ID = 13, /**< A relative object ID */
	PKCS08_TAG_SEQUENCE = 16, /**< An ordered collection of one or more types */
	PKCS08_TAG_SET = 17, /**< An unordered collection of one or more types */
	PKCS08_TAG_CHAR_STRING = 18, /**< A numeric string */
	PKCS08_TAG_PRINTABLE_STRING = 19, /**< An arbitrary string of printable characters */
	PKCS08_TAG_TELETEXT_STRING = 20, /**< A teletext string, T61 string */
	PKCS08_TAG_VIDEOTEXT_STRING = 21, /**< A videotext string */
	PKCS08_TAG_IA5STRING = 22, /**< An arbitrary string of IA5 (ASCII) characters */
	PKCS08_TAG_UTC_TIME = 23, /**< A coordinated universal time or Greenwich Mean Time (GMT) value */
	PKCS08_TAG_GEN_TIME = 24, /**< A generalized time */
	PKCS08_TAG_GRAPHICS_STRING = 25, /**< A graphic string */
	PKCS08_TAG_VISIBLE_STRING = 26, /**< A visible string, ISO64 string */
	PKCS08_TAG_GENERAL_STRING = 27, /**< A general string */
	PKCS08_TAG_UNIVERSAL_STRING = 28, /**< A universal string */
	PKCS08_TAG_CHARACTER_STRING = 29, /**< An arbitrary character string */
	PKCS08_TAG_BMP_STRING = 30, /**< A bmp string */
	PKCS08_TAG_UNKNOWN = -1 /**< An unknown tag type */
}; // Pkcs08TagValue;

/*
-- Basic object identifiers in Pkcs05 and Pkcs08
*/

_OSP_EXPORT_ extern const wchar_t OID_PKCS_05[];    /**< An object identifier for pkcs05 */
_OSP_EXPORT_ extern const wchar_t OID_PBKDF2[];  /**< An object identifier for password based key derivation function scheme2 */
_OSP_EXPORT_ extern const wchar_t OID_PBES2[];   /**< An object identifier for password based encryption scheme2 */
_OSP_EXPORT_ extern const wchar_t OID_PBMAC1[];  /**< An object identifier for password based message authentication scheme1 */
_OSP_EXPORT_ extern const wchar_t OID_HMAC_SHA1[];  /**< An object identifier for hmac-sha1 */
_OSP_EXPORT_ extern const wchar_t OID_HMAC_SHA2_224[];  /**< An object identifier for hmac-sha224 */
_OSP_EXPORT_ extern const wchar_t OID_HMAC_SHA2_256[];  /**< An object identifier for hmac-sha256 */
_OSP_EXPORT_ extern const wchar_t OID_HMAC_SHA2_384[]; /**< An object identifier for hmac-sha384 */
_OSP_EXPORT_ extern const wchar_t OID_HMAC_SHA2_512[]; /**< An object identifier for hmac-sha512 */
_OSP_EXPORT_ extern const wchar_t OID_DES_CBC[];  /**< An object identifier for des-cbc mode */
_OSP_EXPORT_ extern const wchar_t OID_DES_CBC_EDE3[];   /**< An object identifier for des-cbc-ede3 mode */
_OSP_EXPORT_ extern const wchar_t OID_AES_128_CBC[];    /**< An object identifier for aes-128-cbc mode */
_OSP_EXPORT_ extern const wchar_t OID_AES_192_CBC[];   /**< An object identifier for aes-192-cbc mode */
_OSP_EXPORT_ extern const wchar_t OID_AES_256_CBC[];   /**< An object identifier for aes-256-cbc mode */
_OSP_EXPORT_ extern const wchar_t OID_RC2_CBC[];    /**< An object identifier for rc2-cbc mode */
_OSP_EXPORT_ extern const wchar_t OID_PKCS_08[];    /**< An object identifier for pkcs08 */
_OSP_EXPORT_ extern const wchar_t OID_RSA_ENCRYPTION[];   /**< An object identifier for RSA encryption scheme */


/*
-- Basic object identifiers in Pkcs08 for AttributeType
*/

_OSP_EXPORT_ extern const wchar_t OID_ATTR_NAME[];  /**< An object identifier for attribute type name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_SURNAME[];    /**< An object identifier for attribute type surname */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_GIVEN_NAME[]; /**< An object identifier for attribute type of any given name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_INITIAL[];   /**< An object identifier for attribute type initial */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_GEN_QUALIFIER[];  /**< An object identifier for attribute type generation qualifier */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_COMMON_NAME[]; /**< An object identifier for attribute type common name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_LOCALITY_NAME[];  /**< An object identifier for attribute type locality name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_STATE_OR_PROV_NAME[];   /**< An object identifier for attribute type state/province name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_ORG_NAME[]; /**< An object identifier for attribute type of any organization name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_ORG_UNIT_NAME[];    /**< An object identifier for any organization unit name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_TITLE[]; /**< An object identifier for attribute type title */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_DN_QUALIFIER[];   /**< An object identifier for distinguished name qualifier */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_COUNTRY_NAME[];    /**< An object identifier for attribute type country name */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_SERIAL_NUMBER[];   /**< An object identifier for attribute type serial number */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_PSEUDONYM[]; /**< An object identifier for attribute type pseudonym */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_DOMAIN_COMPONENT[]; /**< An object identifier for any domain component */
_OSP_EXPORT_ extern const wchar_t OID_ATTR_EMAIL_ADDRESS[];  /**< An object identifier for any email address */

} } } // Tizen::Security::Pkcs




#endif // _FSEC_PKCS_TYPES_H_
