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
 * @file		FSecPkcs.h
 * @brief		This is the header file for the %Pkcs namespace.
 *
 * This header file contains the declarations of the %Pkcs namespace.
 *
 */
#ifndef _FSEC_PKCS_H_
#define _FSEC_PKCS_H_

#include <FSecPkcsAlgorithmIdentifier.h>
#include <FSecPkcsIAlgorithmParameters.h>
#include <FSecPkcsPkcs05PbMacParameters.h>
#include <FSecPkcsPkcs05PbEs2Parameters.h>
#include <FSecPkcsPkcs05PbKdf2Parameters.h>
#include <FSecPkcsRc2CbcParameters.h>
#include <FSecPkcsInitialVector.h>
#include <FSecPkcsTypes.h>
#include <FSecPkcsPkcs05Schemes.h>
#include <FSecPkcsPkcs08PrivateKeyInfo.h>
#include <FSecPkcsPkcs08EncryptedPrivateKeyInfo.h>
#include <FSecPkcsPkcs08Attribute.h>
#include <FSecPkcsPkcs08AttributeValue.h>

/**
 * @namespace	Tizen::Security::Pkcs
 * @brief		This namespace contains classes and interfaces for managing the PKCS 5 and 8 implementation.
 * @since		2.1
 *
 * @remarks		@b Header @b %file: @b \#include @b <FSecurity.h> @n
 *				@b Library : @b osp-appfw
 *
 *
 *	The %Pkcs namespace provides classes and interfaces for managing PKCS 5 and 8 implementation.
 *	It provides a mechanism for password based key derivation, encryption/decryption @n
 *	mac genaration/verification.
 *	It also provides a standard format to store private key and encrypted private key.
 *
 *	 For more information on the %Pkcs namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/security/public_key_cryptography.htm">Pkcs Guide</a>. @n
 *
 *	The following diagram illustrates the relationships between the classes belonging to the %Pkcs namespace.
 *	@image html security_pkcs_classdiagram.png
 *
 */

namespace Tizen { namespace Security { namespace Pkcs
{

} } } //Tizen::Security::Pkcs

#endif // _FSEC_PKCS_H_
