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
 *	@file		FSecCryptoIHmac.h
 *	@brief	This is the header file for the %IHmac interface.
 *
 *	This header file contains the declarations of the %IHmac interface.
 */
#ifndef _FSEC_CRYPTO_IHMAC_H_
#define _FSEC_CRYPTO_IHMAC_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecISecretKey.h>


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@interface	IHmac
 *	@brief		This interface provides the functionality of a Hash Message Authentication Code (HMAC) algorithm.
 *
 *	@since		2.0
 *
 *	The %IHmac interface provides the functionality of a Hash Message Authentication Code (HMAC) algorithm. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/hashing.htm">Hashing</a>. @n
 *
 *	The following example demonstrates how to use the %IHmac interface.
 *
 *	@code
 *
 *	result
 *	MyClass::TestHmacSample(void)
 *	{
 *		const int messageLen	= 64;
 *		static const byte message[messageLen] = {
 *			0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
 *			0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
 *			0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
 *			0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60,
 *			0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
 *			0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,
 *			0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
 *			0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80
 *		};
 *
 *		const int macKeyLen	= 20;
 *		static const byte macKey[macKeyLen] = {
 *			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 *			0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
 *			0x20, 0x21, 0x22, 0x23
 *		};
 *
 *		const int sampleOutputLen	= 20;
 *		static const byte sampleOutput[sampleOutputLen] = {
 *			0x0f, 0xf4, 0xd8, 0x25, 0x33, 0xe5, 0xd8, 0x22,
 *			0x70, 0x8c, 0x8f, 0x76, 0xda, 0x9e, 0x6c, 0xaf,
 *			0x71, 0xea, 0x1a, 0x5b
 *		};
 *
 *		const int Sha1Len	= 20;
 *
 *		result r = E_FAILURE;
 *		IHmac *pHmac	= null;
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *		ByteBuffer keyBytes;
 *		SecretKeyGenerator *pKeyGen = null;
 *		ISecretKey	*pKey = null;
 *
 *		input.Construct(messageLen);
 *		input.SetArray(message, 0, messageLen);
 *		input.Flip();
 *
 *		keyBytes.Construct(macKeyLen);
 *		keyBytes.SetArray(macKey, 0, macKeyLen);
 *		keyBytes.Flip();
 *
 *		// HMAC Creation
 *		pHmac = new Sha1Hmac();
 *		if (pHmac == null)
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
 *		if (r != E_SUCCESS)
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
 *		r = pHmac->SetKey(*pKey);
 *		if (r != E_SUCCESS)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pOutput	= pHmac->GetHmacN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pOutput->GetPointer(), sampleOutput, Sha1Len) != 0)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = E_SUCCESS;
 *	CATCH:
 *		delete pHmac;
 *		delete pKeyGen;
 *		delete pOutput;
 *		delete pKey;
 *
 *		return r;
 *	}
 *
 *	result
 *	MyClass::TestHmacSample_Multipart(void)
 *	{
 *		const int messageLen	= 64;
 *		static const byte message[messageLen] = {
 *			0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
 *			0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
 *			0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
 *			0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60,
 *			0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
 *			0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,
 *			0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
 *			0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80
 *		};
 *
 *		// This contains the MAC key to be used.
 *		const int macKeyLen	= 20;
 *		static const byte macKey[macKeyLen] = {
 *			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 *			0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
 *			0x20, 0x21, 0x22, 0x23
 *		};
 *
 *		const int sampleOutputLen	= 20;
 *		static const byte sampleOutput[sampleOutputLen] = {
 *			0x0f, 0xf4, 0xd8, 0x25, 0x33, 0xe5, 0xd8, 0x22,
 *			0x70, 0x8c, 0x8f, 0x76, 0xda, 0x9e, 0x6c, 0xaf,
 *			0x71, 0xea, 0x1a, 0x5b
 *		};
 *
 *		const int Sha1Len	= 20;
 *		int	unitLen	= messageLen / 5;
 *		int dataLen = 0;
 *
 *		result r = E_FAILURE;
 *		IHmac *	pHmac	= null;
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *		ByteBuffer keyBytes;
 *		SecretKeyGenerator* pKeyGen = null;
 *		ISecretKey	*pKey	= null;
 *
 *		input.Construct(messageLen);
 *		input.SetArray(message, 0, messageLen);
 *		input.Flip();
 *
 *		keyBytes.Construct(macKeyLen);
 *		keyBytes.SetArray(macKey, 0, macKeyLen);
 *		keyBytes.Flip();
 *
 *		// HMAC Creation
 *		pHmac = new Sha1Hmac();
 *		if (pHmac == null)
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
 *		if (r != E_SUCCESS)
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
 *		r = pHmac->SetKey(*pKey);
 *		if (r != E_SUCCESS)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pHmac->Initialize();
 *		if (r != E_SUCCESS)
 *		{
 *			goto CATCH;
 *		}
 *
 *		for (int i = 0; i *	unitLen < messageLen; i++)
 *		{
 *			if (messageLen - (i *	unitLen) < unitLen)
 *			{
 *				dataLen = messageLen - (i *	unitLen);
 *			}
 *			else
 *			{
 *				dataLen = unitLen;
 *			}
 *
 *			// MessageLen == 98
 *			input.Construct(dataLen);
 *			input.SetArray(message + (i *	unitLen), 0, dataLen);
 *			input.Flip();
 *
 *			r = pHmac->Update(input);
 *			if (r != E_SUCCESS)
 *			{
 *				goto CATCH;
 *			}
 *
 *			input.Clear();
 *		}
 *
 *		pOutput	= pHmac->FinalizeN();
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pOutput->GetPointer(), sampleOutput, Sha1Len) != 0)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = E_SUCCESS;
 *	CATCH:
 *		delete pHmac;
 *		delete pKeyGen;
 *		delete pOutput;
 *		delete pKey;
 *
 *		return r;
 *	}
 *
 *	 @endcode
 */

class _OSP_EXPORT_ IHmac
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 *	@since		2.0
	 */
	virtual ~IHmac(void) {}

	/**
	 *	Sets the HMAC algorithm.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	algorithm				The name of the HMAC algorithm @n
	 *										For example, "HMACSHA2/224", "HMACSHA2/256", "HMACSHA2/384", or "HMACSHA2/512".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 */
	virtual result SetAlgorithm(const Tizen::Base::String& algorithm) = 0;

	/**
	 *	Sets the secret key.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key						An instance of ISecretKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result SetKey(const Tizen::Security::ISecretKey& key) = 0;

	/**
	 *	Gets the HMAC with a given input.
	 *
	 *	@since			2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* GetHmacN(const Tizen::Base::ByteBuffer& input) const = 0;

	/**
	 *	Initializes a multiple-part HMAC operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library.
	 */
	virtual result Initialize(void) = 0;

	/**
	 *	Updates a multiple-part HMAC operation while processing another data part.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual result Update(const Tizen::Base::ByteBuffer& input) = 0;

	/**
	 *	Finalizes a multiple-part HMAC operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *					else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* FinalizeN(void) = 0;

protected:
	//
	//	This method is for internal use only. Using this method can cause behavioral, security-related,
	//	and consistency-related issues in the application.
	//
	//	This method is reserved and may change its name at any time without prior notice.
	//
	//	@since 2.0
	//
	virtual void IHmac_Reserved1(void) {}

}; //IHmac

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_IHMAC_H_
