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
 * @file		FSecCryptoDesEdeCipher.h
 * @brief		This is the header file for the %DesEdeCipher class.
 *
 * This header file contains the declarations of the %DesEdeCipher class.
 */
#ifndef _FSEC_CRYPTO_DES_EDE_CIPHER_H_
#define _FSEC_CRYPTO_DES_EDE_CIPHER_H_

#include <FSecCryptoISymmetricCipher.h>

struct evp_cipher_st;


namespace Tizen { namespace Security { namespace Crypto
{

class _SymmetricCipher;
/**
 *	@class		DesEdeCipher
 *	@brief		This class provides methods for encryption and decryption using the Data Encryption Standard in the Encrypt-Decrypt-Encrypt (DES-EDE) mode.
 *
 *	@since       2.0
 *
 *	The %DesEdeCipher class provides symmetric cipher using the Data Encryption Standard in the Encrypt-Decrypt-Encrypt (DES-EDE) mode.
 *	Sets appropriate values for the requested mode/key bit/padding scheme and cipher operation (CIPHER_ENCRYPT or CIPHER_DECRYPT) parameters. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/ciphers.htm">Ciphers</a>.
 *
 *	@see	ISymmetricCipher
 * 	@see	DesCipher
 *	@see	AesCipher
 */
class _OSP_EXPORT_ DesEdeCipher
	: public virtual ISymmetricCipher
	, public Tizen::Base::Object
{

public:
	/**
	 *	The object is not fully constructed after this constructor is called. For full construction, @n
	 *	the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 */
	DesEdeCipher(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~DesEdeCipher(void);

	/**
	 *	Initializes this instance of %DesEdeCipher with the specified parameters.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	transformation			The name of the requested mode/key bit/padding scheme @n
	 *										For example, "CBC/NOPADDING" or "CBC/PKCS7PADDING".
	 *	@param[in]	opMode					The cipher operation mode @n
	 *										The valid values for %DesEdeCipher are @c CIPHER_ENCRYPT and @c CIPHER_DECRYPT.
	 *	@exception	E_SUCCESS				The method is successful.
	 *  @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid, or the specified @c opMode does not contain a valid value for the cipher operation.
	 *	@remarks	If @c opMode is not matching the actual operation, the result of the operation is @c null and an exception is returned. @n
	 *				For example, if @c opMode is set to @c CIPHER_ENCRYPT, @c CIPHER_WRAP, or @c CIPHER_UNWRAP and the DecryptN() method is used, then the result obtained is @c null and an exception is returned.
	 */
	virtual result Construct(const Tizen::Base::String& transformation, enum CipherOperation opMode);
	/**
	 *	Sets a symmetric key for encryption or decryption.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key						An instance of ISecretKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result SetKey(const Tizen::Security::ISecretKey& key);

	/**
	 *	Sets the initial vector.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	initialVector			The initial vector
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result SetInitialVector(const Tizen::Base::ByteBuffer& initialVector);

	/**
	 *	Encrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified instance of Tizen::Base::ByteBuffer is invalid or empty.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 *	@remarks	A secret key and an initial vector are set before calling this method.
	 */
	virtual Tizen::Base::ByteBuffer* EncryptN(const Tizen::Base::ByteBuffer& input);

	/**
	 *	Decrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified instance of Tizen::Base::ByteBuffer is invalid or empty.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *  @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	A secret key and an initial vector are set before calling this method.
	 */
	virtual Tizen::Base::ByteBuffer* DecryptN(const Tizen::Base::ByteBuffer& input);

	/**
	 *	Initializes a multiple-part encryption or decryption operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library.
	 *	@remarks	A secret key and an initial vector are set before calling this method.
	 */
	virtual result Initialize(void);

	/**
	 *	Updates a multiple-part encryption or decryption operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_INVALID_ARG			The specified instance of Tizen::Base::ByteBuffer is invalid or empty.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* UpdateN(const Tizen::Base::ByteBuffer& input);

	/**
	 *	Finalizes a multiple-part encryption or decryption operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* FinalizeN(void);

	/**
	 *	Wraps a key.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	secretKey				The secret key to wrap
	 *	@remarks	This operation is not supported in the %DesEdeCipher class.
	 *				Therefore, this method always returns @c null.
	 *	@remarks	The @c E_UNSUPPORTED_ALGORITHM exception is returned using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* WrapN(const Tizen::Base::ByteBuffer& secretKey);

	/**
	 *	Unwraps a previously wrapped key.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	wrappedKey				The wrapped key to unwrap
	 *	@remarks	This operation is not supported in the %DesEdeCipher class.
	 *				Therefore, this method always returns @c null.
	 *	@remarks	The @c E_UNSUPPORTED_ALGORITHM exception is returned using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* UnwrapN(const Tizen::Base::ByteBuffer& wrappedKey);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DesEdeCipher(const DesEdeCipher& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DesEdeCipher& operator =(const DesEdeCipher& rhs);

private:
	_SymmetricCipher* __pSymmetricCipher;
	const evp_cipher_st* __pCipherAlgorithm;
	Tizen::Base::String __cipherAlgorithm;

	class _DesEdeCipherImpl* __pDesEdeCipherImpl;
	friend class _DesEdeCipherImpl;

}; //DesEdeCipher

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_DES_EDE_CIPHER_H_
