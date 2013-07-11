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
 * @file		FSecCryptoIAsymmetricCipher.h
 * @brief		This is the header file for the %IAsymmetricCipher interface.
 *
 * This header file contains the declarations of the %IAsymmetricCipher interface.
 */
#ifndef _FSEC_CRYPTO_IASYMMETRIC_CIPHER_H_
#define _FSEC_CRYPTO_IASYMMETRIC_CIPHER_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecIKey.h>
#include <FSecIPublicKey.h>
#include <FSecIPrivateKey.h>
#include <FSecCryptoTypes.h>


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@interface	IAsymmetricCipher
 *	@brief		This interface provides the functionality of an asymmetric cryptographic cipher for encryption and decryption.
 *
 *	@since		2.0
 *
 *	The %IAsymmetricCipher interface provides the functionality of an asymmetric cryptographic cipher for encryption and decryption. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/ciphers.htm">Ciphers</a>. @n
 *
 *	The following example demonstrates how to use the %IAsymmetricCipher interface.
 *
 *	@code
 *
 *	void
 *	MyClass::TestAsymmetricCipherSample(void)
 *	{
 *		result r = E_FAILURE;
 *		IAsymmetricCipher *pCipher = null;
 *		IKeyPairGenerator *pKeyPairGen = null;
 *		KeyPair *pKeyPair = null;
 *		IPrivateKey *pPriKey = null;
 *		IPublicKey *pPubKey = null;
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *		ByteBuffer *pDecOutput = null;
 *		ByteBuffer keyBytes;
 *		ByteBuffer iv;
 *		byte pArray[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
 *		int size = 1024;
 *
 *		r = input.Construct(16);
 *		r = input.SetArray(pArray, 0, 16);
 *		input.Flip();
 *
 *		pCipher = new RsaCipher();
 *		if (pCipher == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		// Generates the key.
 *		pKeyPairGen = new KeyPairGenerator();
 *		if (pKeyPairGen == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeyPairGen->Construct(size);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyPair = pKeyPairGen->GenerateKeyPairN();
 *		if (pKeyPair == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPubKey = pKeyPair->GetPublicKey();
 *		if (pPubKey == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPriKey = pKeyPair->GetPrivateKey();
 *		if (pPriKey == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCipher->SetPublicKey(*pPubKey);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pOutput = pCipher->EncryptN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		r = pCipher->SetPrivateKey(*pPriKey);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pDecOutput = pCipher->DecryptN(*pOutput);
 *		if (pDecOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pDecOutput->GetPointer(), input.GetPointer(), input.GetRemaining()) != 0)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r	= E_SUCCESS;
 *
 *	CATCH:
 *		delete pCipher;
 *		delete pOutput;
 *		delete pDecOutput;
 *		delete pKeyPairGen;
 *		delete pKeyPair;
 *	}
 *
 *	@endcode
 */

class _OSP_EXPORT_ IAsymmetricCipher
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IAsymmetricCipher(void) {}

	/**
	 *	Sets an asymmetric private key for encryption or decryption.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key							An instance of IKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	virtual result SetPrivateKey(const Tizen::Security::IKey& key) = 0;

	/**
	 *	Sets an asymmetric public key for encryption or decryption.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key							An instance of IKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	virtual result SetPublicKey(const Tizen::Security::IKey& key) = 0;

	/**
	 *	Encrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input						An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM		The algorithm is not supported.
	 *	@exception	E_KEY_NOT_FOUND				The specified key is not found.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the openssl library, or
	 *											the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* EncryptN(const Tizen::Base::ByteBuffer& input) = 0;

	/**
	 *	Decrypts the data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input						An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM		The algorithm is not supported.
	 *	@exception	E_KEY_NOT_FOUND				The specified key is not found.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the openssl library, or
	 *											the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* DecryptN(const Tizen::Base::ByteBuffer& input) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IAsymmetricCipher_Reserved1(void) {}

}; //IAsymmetricCipher

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_IASYMMETRIC_CIPHER_H_
