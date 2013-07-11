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
 * @file		FSecCryptoRsaCipher.h
 * @brief		This is the header file for the %RsaCipher class.
 *
 * This header file contains the declarations of the %RsaCipher class.
 */
#ifndef _FSEC_CRYPTO_RSA_CIPHER_H_
#define _FSEC_CRYPTO_RSA_CIPHER_H_

#include <FSecCryptoIAsymmetricCipher.h>
#include <FSecIPublicKey.h>
#include <FSecIPrivateKey.h>
#include <FBase.h>


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@class		RsaCipher
 *	@brief		This class provides methods for encryption and decryption using the Rivest Shamir Adleman (RSA) algorithm.
 *
 *	@since		2.0
 *
 *	The %RsaCipher class provides methods to encrypt and decrypt messages, and is used in the asymmetric cipher
 *	operations. @n
 *
 *	For more information on using the Rivest Shamir Adleman (RSA) algorithm for asymmetric ciphers, see <a href="../org.tizen.native.appprogramming/html/guide/security/ciphers.htm">Ciphers</a>.
 *
 *	@see Tizen::Security::KeyPair
 *	@see Tizen::Security::IPublicKey
 *	@see Tizen::Security::IPrivateKey
 */
class _OSP_EXPORT_ RsaCipher
	: public virtual IAsymmetricCipher
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		2.0
	 */
	RsaCipher(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~RsaCipher(void);

	/**
	 *	Sets an asymmetric private key for encryption or decryption.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key						An instance of IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result SetPrivateKey(const Tizen::Security::IKey& key);

	/**
	 *	Sets an asymmetric public key for encryption or decryption.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key						An instance of IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result SetPublicKey(const Tizen::Security::IKey& key);

	/**
	 *	Encrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* EncryptN(const Tizen::Base::ByteBuffer& input);

	/**
	 *	Decrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* DecryptN(const Tizen::Base::ByteBuffer& input);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	RsaCipher(const RsaCipher& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	RsaCipher& operator =(const RsaCipher& rhs);

private:
	Tizen::Base::ByteBuffer __privateKey;
	Tizen::Base::ByteBuffer __publicKey;

	class _RsaCipherImpl* __pRsaCipherImpl;
	friend class _RsaCipherImpl;

}; //RsaCipher

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_RSA_CIPHER_H_
