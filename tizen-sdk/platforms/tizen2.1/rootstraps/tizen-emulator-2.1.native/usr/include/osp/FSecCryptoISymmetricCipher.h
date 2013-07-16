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
 *	@file		FSecCryptoISymmetricCipher.h
 *	@brief	This is the header file for the %ISymmetricCipher interface.
 *
 *	This header file contains the declarations of the %ISymmetricCipher interface.
 */
#ifndef _FSEC_CRYPTO_ISYMMETRIC_CIPHER_H_
#define _FSEC_CRYPTO_ISYMMETRIC_CIPHER_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecISecretKey.h>
#include <FSecCryptoTypes.h>


namespace Tizen { namespace Security { namespace Crypto
{
/**
 *	@interface	ISymmetricCipher
 *	@brief		This interface provides the functionalities of a symmetric cryptographic cipher for encryption and decryption.
 *
 *	@since		2.0
 *
 *	The %ISymmetricCipher interface provides the functionalities of a symmetric cryptographic cipher for encryption and decryption. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/ciphers.htm">Ciphers</a>. @n
 *
 *	The following example demonstrates how to use the %ISymmetricCipher interface.
 *	@code
 *
 *	void
 *	MyClass::TestSymmetricCipherSample(void)
 *	{
 *		// #####AES CBC Test Vector(128-bits key)#####
 *		// PlainText: 48 Bytes
 *		const int messageLen	= 48;
 *		static const byte message[messageLen] = {
 *			0x87, 0x3C, 0x66, 0x1D, 0x2C, 0x0D, 0x49, 0x2D,
 *			0x6C, 0x76, 0xBE, 0x44, 0x57, 0x39, 0xB8, 0x28,
 *			0x84, 0x5E, 0x2A, 0x15, 0x18, 0x3B, 0x1D, 0x00,
 *			0xA7, 0x6E, 0x80, 0x4D, 0x22, 0xF1, 0x2A, 0x6B,
 *			0xBA, 0xFE, 0xA8, 0x02, 0x2B, 0xC2, 0x97, 0x01,
 *			0x59, 0x0F, 0x3C, 0x2A, 0x67, 0x8B, 0x98, 0x69
 *		};
 *
 *		// CipherText: 48 Bytes
 *		const int cipherLen	= 48;
 *		static const byte cipher[cipherLen] = {
 *			0x10, 0x84, 0x9D, 0x24, 0xEB, 0x22, 0xE0, 0x7F,
 *			0xA8, 0x57, 0xE9, 0xA0, 0x4F, 0xE2, 0x3D, 0xE5,
 *			0xC1, 0x51, 0x7E, 0xEB, 0xF8, 0xB3, 0x3A, 0xA2,
 *			0xDC, 0xF4, 0x8B, 0xDC, 0x14, 0x0A, 0xC7, 0x58,
 *			0x85, 0x6B, 0x0D, 0xE9, 0x30, 0x8B, 0xA1, 0x71,
 *			0xD5, 0x0B, 0x14, 0x97, 0xEF, 0xAD, 0x22, 0x8D
 *		};
 *
 *		// KEY: 16Bytes
 *		const int secretKeyLen	= 16;
 *		static const byte secretKey[secretKeyLen] = {
 *			0x62, 0x5C, 0xC7, 0x7E, 0xEA, 0x7B, 0xA5, 0x4D,
 *			0x47, 0xCE, 0xAF, 0x26, 0x9E, 0xB1, 0x6C, 0x2D
 *		};
 *
 *		// IV: 16Bytes
 *		const int ivectorLen	= 16;
 *		static const byte ivector[ivectorLen] = {
 *				0x3E, 0xB5, 0x01, 0x45, 0xE4, 0xF8, 0x75, 0x3F,
 *			0x08, 0x9D, 0x9F, 0x57, 0x3B, 0x63, 0xEF, 0x4B
 *		};
 *
 *		result r = E_FAILURE;
 *		String transformation;
 *		ISymmetricCipher	*pCipherEnc	= null;
 *		ISymmetricCipher	*pCipherDec	= null;
 *		SecretKeyGenerator	*pKeyGen	= null;
 *		ISecretKey			*pKey		= null;
 *		ByteBuffer			input;
 *		ByteBuffer			*pOutput	= null;
 *		ByteBuffer			*pOutput2	= null;
 *		ByteBuffer			keyBytes;
 *		ByteBuffer			iv;
 *
 *		// Input
 *		input.Construct(messageLen);
 *		input.SetArray(message, 0, messageLen);
 *		input.Flip();
 *
 *		// Key
 *		keyBytes.Construct(secretKeyLen);
 *		keyBytes.SetArray(secretKey, 0, secretKeyLen);
 *		keyBytes.Flip();
 *
 *		// IV setting
 *		iv.Construct(ivectorLen);
 *		iv.SetArray(ivector, 0, ivectorLen);
 *		iv.Flip();
 *
 *		pCipherEnc = new AesCipher();
 *		if (pCipherEnc == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		transformation  = "CBC/128/NOPADDING";
 *
 *		r = pCipherEnc->Construct(transformation, CIPHER_ENCRYPT);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		// Generates the key.
 *		pKeyGen = new SecretKeyGenerator();
 *		if (pKeyGen == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeyGen->Construct(keyBytes);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKey = pKeyGen->GenerateKeyN();
 *		if (pKey == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCipherEnc->SetKey(*pKey);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCipherEnc->SetInitialVector(iv);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pOutput = pCipherEnc->EncryptN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		pCipherDec = new AesCipher();
 *		if (pCipherDec == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCipherDec->Construct(transformation, CIPHER_DECRYPT);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCipherDec->SetKey(*pKey);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCipherDec->SetInitialVector(iv);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pOutput2 = pCipherDec->DecryptN(*pOutput);
 *		if (pOutput2 == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pOutput->GetPointer(), cipher, cipherLen) != 0)
 *		{
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pOutput2->GetPointer(), input.GetPointer(), input.GetRemaining()) != 0)
 *		{
 *			goto CATCH;
 *		}
 *
 *	CATCH:
 *		delete pCipherEnc;
 *		delete pCipherDec;
 *		delete pKeyGen;
 *		delete pOutput;
 *		delete pOutput2;
 *		delete pKey;
 *	}
 *
 *	 @endcode
 *
 *
 */

class _OSP_EXPORT_ ISymmetricCipher
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 *	@since		2.0
	 */
	virtual ~ISymmetricCipher(void) {}

	/**
	 *	Initializes this instance of %ISymmetricCipher with the specified operation mode and padding scheme.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	transformation			The name of the requested mode or key bit or padding scheme
	 *	@param[in]	opMode					The cipher operation mode @n
	 *										For example, @c CIPHER_ENCRYPT, @c CIPHER_DECRYPT, @c CIPHER_WRAP, or @c CIPHER_UNWRAP.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c opMode does not contain a valid value for the cipher operation.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 */
	virtual result Construct(const Tizen::Base::String& transformation, enum CipherOperation opMode = Tizen::Security::Crypto::CIPHER_ENCRYPT) = 0;

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
	virtual result SetKey(const Tizen::Security::ISecretKey& key) = 0;

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
	virtual result SetInitialVector(const Tizen::Base::ByteBuffer& initialVector) = 0;

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
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* EncryptN(const Tizen::Base::ByteBuffer& input) = 0;

	/**
	 *	Decrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* DecryptN(const Tizen::Base::ByteBuffer& input) = 0;

	/**
	 *	Initializes a multiple-part encryption or decryption operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library.
	 */
	virtual result Initialize(void) = 0;

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
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* UpdateN(const Tizen::Base::ByteBuffer& input) = 0;

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
	 *	@remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* FinalizeN(void) = 0;

	/**
	 *	Wraps the specified key.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	secretKey				The secret key to wrap
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
 	 *	@remarks		The specific error code can be accessed using the GetLastResult() method.
	 *	@remarks		This operation is only supported in AesCipher.
	 */
	virtual Tizen::Base::ByteBuffer* WrapN(const Tizen::Base::ByteBuffer& secretKey) = 0;

	/**
	 *	Unwraps a previously wrapped key.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	wrappedKey				The wrapped key to unwrap
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c wrappedKey Tizen::Base::ByteBuffer is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks		The specific error code can be accessed using the GetLastResult() method.
	 *	@remarks		This operation is only supported in AesCipher.
	 */
	virtual Tizen::Base::ByteBuffer* UnwrapN(const Tizen::Base::ByteBuffer& wrappedKey) = 0;

protected:
	//
	//	This method is for internal use only. Using this method can cause behavioral, security-related,
	//	and consistency-related issues in the application.
	//
	//	This method is reserved and may change its name at any time without prior notice.
	//
	//	@since 2.0
	//
	virtual void ISymmetricCipher_Reserved1(void) {}

}; //ISymmetricCipher

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_ISYMMETRIC_CIPHER_H_
