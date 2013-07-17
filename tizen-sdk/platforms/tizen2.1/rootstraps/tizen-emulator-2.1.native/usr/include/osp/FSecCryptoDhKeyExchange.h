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
 * @file			FSecCryptoDhKeyExchange.h
 * @brief		This is the header file for the %DhKeyExchange class.
 *
 * This header file contains the declarations of the %DhKeyExchange class.
 */
#ifndef _FSEC_CRYPTO_DH_KEYEXCHANGE_H_
#define _FSEC_CRYPTO_DH_KEYEXCHANGE_H_

#include <FSecCryptoIKeyExchange.h>


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@class		DhKeyExchange
 *	@brief		This class provides methods for a key exchange mechanism using the Diffie-Hellman (DH) algorithm.
 *
 *	@since       2.0
 *
 *	The %DhKeyExchange class provides a DH key exchange between two communicating users. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_exchange_algorithm.htm">Key exchanging</a>.
 *
 *	@see	IKeyExchange
 *	@see	KeyPairGenerator
 *
 *	The following example demonstrates how to use the %DhKeyExchange class.
 *	@code
 *
 *	void DhGenerateSecretExample(void)
 *	{
 *		result r = E_SUCCESS;
 *		KeyPair *pKeyPair = null;
 *		KeyPair *pKeyPair1 = null;
 *		IPrivateKey *pPriKey = null;
 *		IPublicKey *pPubKey = null;
 *		IPrivateKey *pPriKey1 = null;
 *		IPublicKey *pPubKey1 = null;
 *		KeyPairGenerator *pKeyPairGen = null;
 *		IKeyParameters *pKeyParams = null;
 *		int size = 1024;
 *		DhKeyExchange  *pDhKeyExchangeAlice = null;
 *		DhKeyExchange  *pDhKeyExchangeBob = null;
 *		ByteBuffer *pBuffer = null;
 *		ByteBuffer *pBuffer1 = null;
 *
 *		SetLastResult(E_SUCCESS);
 *		// Generates the key.
 *		pKeyPairGen = new KeyPairGenerator();
 *		if (pKeyPairGen == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		r = pKeyPairGen->Construct(size, "DH");
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyParams = pKeyPairGen->GenerateKeyParametersN();
 *		if (pKeyParams == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pKeyPair = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *		if (pKeyPair == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyPair1 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *		if (pKeyPair1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pPubKey = pKeyPair->GetPublicKey();
 *		if (pPubKey == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pPriKey = pKeyPair->GetPrivateKey();
 *		if (pPriKey == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pPubKey1 = pKeyPair1->GetPublicKey();
 *		if (pPubKey1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pPriKey1 = pKeyPair1->GetPrivateKey();
 *		if (pPriKey1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pDhKeyExchangeAlice  = new DhKeyExchange ();
 *		if (pDhKeyExchangeAlice == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pDhKeyExchangeBob  = new DhKeyExchange ();
 *		if (pDhKeyExchangeBob == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		// Calling the Construct API.
 *		r = pDhKeyExchangeAlice->Construct(*pKeyParams);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pDhKeyExchangeBob->Construct(*pKeyParams);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pBuffer = pDhKeyExchangeAlice->GenerateSecretN(*pPriKey, *pPubKey1);
 *		if (pBuffer == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pBuffer1 = pDhKeyExchangeBob->GenerateSecretN(*pPriKey1, *pPubKey);
 *		if (pBuffer1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		if (*pBuffer == *pBuffer1)
 *		{
 *			AppLog("The secret is generated SuccessFully");
 *		}
 *		else
 *		{
 *			goto CATCH;
 *		}
 *
 *	CATCH:
 *		delete pKeyPairGen;
 *		delete pKeyPair;
 *		delete pKeyPair1;
 *		delete pBuffer;
 *		delete pBuffer1;
 *		delete pDhKeyExchangeAlice;
 *		delete pDhKeyExchangeBob;
 *		delete pKeyParams;
 *
 *	}
 *
 *	@endcode
 *
 */

class _OSP_EXPORT_ DhKeyExchange
	: public virtual IKeyExchange
	, public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 */
	DhKeyExchange(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~DhKeyExchange(void);

	/**
	 *	Initializes this instance of %DhKeyExchange with the specified key parameters.
	 *
	 *	@since      2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keyParameters			The domain parameters ('p' prime number and 'g' generator) of DH
	 *										algorithm that needs to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid, or the specified @c keyParameters does not contain a valid value.        */
	virtual result Construct(const Tizen::Security::IKeyParameters& keyParameters);

	/**
	 *	Generates the final shared secret between two parties.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the generated secret key, @n
	 *				else @c null if the method fails to generate the secret key
	 *	@param[in]	privateKey				The private key component of the first party that needs to instantiate
	 *	@param[in]	publicKey				The public key component of the second party that needs to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *  @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GenerateSecretN(Tizen::Security::IPrivateKey& privateKey, Tizen::Security::IPublicKey& publicKey);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DhKeyExchange(const DhKeyExchange& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DhKeyExchange& operator =(const DhKeyExchange& rhs);

private:
	Tizen::Base::ByteBuffer* __pParamsP;
	Tizen::Base::ByteBuffer* __pParamsG;

	class _DhKeyExchangeImpl* __pDhKeyExchangeImpl;
	friend class _DhKeyExchangeImpl;

}; //DhKeyExchange

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_DH_KEYEXCHANGE_H_
