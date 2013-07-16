//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file		FSecCryptoTypes.h
 * @brief		This is the header file that defines the different enumerations.
 *
 * This header file defines the different enumerations that can be used for cryptography.
 */
#ifndef _FSEC_CRYPTO_TYPES_H_
#define _FSEC_CRYPTO_TYPES_H_


namespace Tizen { namespace Security { namespace Crypto
{

/**
 * @enum CipherOperation
 *
 * Defines the cipher operation.
 *
 * @since		2.0
 */

enum CipherOperation
{
	CIPHER_ENCRYPT = 0,             /**<The encrypt mode */
	CIPHER_DECRYPT = 1,             /**<The decrypt mode */
	CIPHER_WRAP = 2,                /**<The wrap mode */
	CIPHER_UNWRAP = 3               /**<The unwrap mode */
};  // CipherOperation

} } } //Tizen::Security:Crypto


namespace Tizen { namespace Security
{

/**
 * @enum    KeyParameterType
 *
 * Defines the type of key parameters for asymmetric algorithms.
 *
 * @since		2.0
 */
enum KeyParameterType
{
	KEY_PARAMETER_DH_P = 0,                             /**< The DH param P	*/
	KEY_PARAMETER_DH_G = 1,                             /**< The DH param G	*/
	KEY_PARAMETER_DH_PRIVATE_KEY_SIZE = 2,              /**< The DH private key size */
	KEY_PARAMETER_KEA_P = 3,                            /**< The KEA param P */
	KEY_PARAMETER_KEA_G = 4,                            /**< The KEA param G */
	KEY_PARAMETER_KEA_PRIVATE_KEY_SIZE = 5              /**< The KEA private key size */
}; //KeyParameterType

} } //Tizen::Security

#endif // _FSEC_CRYPTO_TYPES_H_
