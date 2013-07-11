//
// Open Service Platform
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
 *	@file		FSecCrypto.h
 *	@brief		This is the header file for the %Crypto namespace.
 *
 *	This header file contains the declarations and descriptions of the %Crypto namespace.
 */
#ifndef _FSEC_CRYPTO_H_
#define _FSEC_CRYPTO_H_

#include <FSecCryptoTypes.h>
#include <FSecCryptoAesCipher.h>
#include <FSecCryptoDesCipher.h>
#include <FSecCryptoDesEdeCipher.h>
#include <FSecCryptoRc2Cipher.h>
#include <FSecCryptoRc4Cipher.h>
#include <FSecCryptoCastCipher.h>
#include <FSecCryptoSkipJackCipher.h>
#include <FSecCryptoIAsymmetricCipher.h>
#include <FSecCryptoIHash.h>
#include <FSecCryptoIHmac.h>
#include <FSecCryptoISignature.h>
#include <FSecCryptoISymmetricCipher.h>
#include <FSecCryptoMd5Hash.h>
#include <FSecCryptoMd5Hmac.h>
#include <FSecCryptoRsaCipher.h>
#include <FSecCryptoRsaSignature.h>
#include <FSecCryptoSha1Hash.h>
#include <FSecCryptoSha1Hmac.h>
#include <FSecCryptoSha2Hash.h>
#include <FSecCryptoSha2Hmac.h>
#include <FSecCryptoIKeyExchange.h>
#include <FSecCryptoDhKeyExchange.h>
#include <FSecCryptoKeaKeyExchange.h>


/**
 *	@namespace		Tizen::Security::Crypto
 *	@brief			This namespace contains classes and interfaces for the cryptographic primitives.
 *
 *	@since			2.0
 *
 *	@remarks		@b Header @b %file: @b \#include @b <FSecurity.h> @n
 *					@b Library : @b osp-appfw
 *
 *	The %Crypto namespace provides classes and methods to handle encryption and decryption using hashing, symmetric and asymmetric ciphers. It also provides a mechanism for sending messages over an insecure channel using a key pair (public and private keys). @n
 *
 *	 For more information on the %Crypto namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/security/cryptography.htm">Crypto Guide</a>. @n
 *
 *	The following diagram illustrates the relationships between the classes belonging to the %Crypto namespace.
 *	@image html security_crypto_classdiagram.png
 *
 */
namespace Tizen { namespace Security { namespace Crypto
{

} } } // Tizen::Security::Crypto

#endif // _FSEC_CRYPTO_H_
