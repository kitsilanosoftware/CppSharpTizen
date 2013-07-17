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
 * @file			FSecCryptoISignature.h
 * @brief		This is the header file for the %ISignature interface.
 *
 * This header file contains the declarations of the %ISignature interface.
 */
#ifndef _FSEC_CRYPTO_ISIGNATURE_H_
#define _FSEC_CRYPTO_ISIGNATURE_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecIKey.h>

namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@interface	ISignature
 *	@brief		This interface provides the functionality of a digital signature algorithm.
 *
 *	@since		2.0
 *
 *	The %ISignature interface provides the functionality of a digital signature algorithm. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/ciphers.htm">Ciphers</a>. @n
 *
 *	The following example demonstrates how to use the %ISignature interface.
 *
 *  @code
 *
 *	void
 *	MyClass::TestSignatureSample(void)
 *	{
 *		result r = E_FAILURE;
 *		ISignature *pSignature = null;
 *		IKeyPairGenerator *pKeyPairGen = null;
 *		KeyPair *pKeyPair = null;
 *		IPrivateKey *pPriKey = null;
 *		IPublicKey *pPubKey = null;
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *		ByteBuffer keyBytes;
 *		ByteBuffer iv;
 *		byte pArray[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
 *		int size = 1024;
 *		bool res = false;
 *
 *		r = input.Construct(16);
 *		r = input.SetArray(pArray, 0, 16);
 *		input.Flip();
 *
 *		pSignature = new RsaSignature();
 *		if (pSignature == null)
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
 *		r = pSignature->SetPrivateKey(*pPriKey);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pOutput = pSignature->SignN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		r = pSignature->SetPublicKey(*pPubKey);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		res = pSignature->Verify(input, *pOutput);
 *		if (res == false)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		r	= E_SUCCESS;
 *
 *  CATCH:
 *		delete pSignature;
 *		delete pOutput;
 *		delete pKeyPairGen;
 *		delete pKeyPair;
 *   }
 *
 *  @endcode
 */

class _OSP_EXPORT_ ISignature
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 *  @since		2.0
	 */
	virtual ~ISignature(void) {}

	/**
	 *	Sets an asymmetric private key for signature.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key							An instance of IKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	virtual result SetPrivateKey(const Tizen::Security::IKey& key) = 0;

	/**
	 *	Sets an asymmetric public key for verification.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key							An instance of IKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	virtual result SetPublicKey(const Tizen::Security::IKey& key) = 0;

	/**
	 *	Signs the data.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer instance that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input						An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND				The specified key is not found.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the openssl library, or
	 *											the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* SignN(const Tizen::Base::ByteBuffer& input) = 0;

	/**
	 *	Verifies the data. @n
	 *	The verification is done by comparing the @c signedData to the signature created by the @c data.
	 *
	 *	@since		2.0
	 *
	 *	@return		@c true if the signed data is correct, @n
	 *				else @c false
	 *	@param[in]	data						An instance of Tizen::Base::ByteBuffer that contains the original data
	 *	@param[in]	signedData					An instance of Tizen::Base::ByteBuffer that contains the signed data
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND				The specified key is not found.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the openssl library, or
	 *											the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual bool Verify(const Tizen::Base::ByteBuffer& data, const Tizen::Base::ByteBuffer& signedData) = 0;

protected:
	//
	//	This method is for internal use only. Using this method can cause behavioral, security-related,
	//	and consistency-related issues in the application.
	//
	//	This method is reserved and may change its name at any time without prior notice.
	//
	//	@since 2.0
	//
	virtual void ISignature_Reserved1(void) {}

}; //ISignature

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_ISIGNATURE_H_
