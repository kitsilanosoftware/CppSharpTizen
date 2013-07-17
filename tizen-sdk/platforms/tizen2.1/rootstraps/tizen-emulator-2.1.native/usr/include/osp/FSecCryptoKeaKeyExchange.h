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
  *	@file		FSecCryptoKeaKeyExchange.h
  *	@brief		This is the header file for the %KeaKeyExchange class.
 *
  *	This header file contains the declarations of the %KeaKeyExchange class.
 */
#ifndef _FSEC_CRYPTO_KEA_KEY_EXCHANGE_H_
#define _FSEC_CRYPTO_KEA_KEY_EXCHANGE_H_

#include <FSecCryptoIKeyExchange.h>


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@class		KeaKeyExchange
 *	@brief		This class provides methods for performing the key exchange mechanism using Key Exchange Algorithm (KEA).
 *
  *	@since       2.0
 *
 *	The %KeaKeyExchange class provides a KEA key exchange between two communicating users. @n
 *
  *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_exchange_algorithm.htm">Key exchanging</a>.
 *
  *	@see	IKeyExchange
  *	@see	KeyPairGenerator
 *
  *	The following example demonstrates how to use the %KeaKeyExchange class.
  *	@code
 *
 *	void KeaGenerateSecretExample(void)
 *	{
 *
 *		result r = E_SUCCESS;
 *		KeyPair *pKeyPairAlice1 = null;
 *		IPrivateKey *pPriKeyAlice1 = null;
 *		IPrivateKey *pPriKeyAlice2 = null;
 *		KeyPair *pKeyPairAlice2 = null;
 *		IPublicKey *pPubKeyAlice1 = null;
 *		IPublicKey *pPubKeyAlice2 = null;
 *
 *		KeyPair *pKeyPairBob1 = null;
 *		IPrivateKey *pPriKeyBob1 = null;
 *		IPrivateKey *pPriKeyBob2 = null;
 *		KeyPair *pKeyPairBob2 = null;
 *		IPublicKey *pPubKeyBob1 = null;
 *		IPublicKey *pPubKeyBob2 = null;
 *
 *
 *		KeyPairGenerator *pKeyPairGen = null;
 *		IKeyParameters *pKeyParams = null;
 *
 *		int size = 1024;
 *		KeaKeyExchange *pKeaKeyExchangeAlice = null;
 *		KeaKeyExchange *pKeaKeyExchangeBob = null;
 *		ByteBuffer *pBuffer = null;
 *		ByteBuffer *pBuffer1 = null;
 *
 *
 *		// Generates the key.
 *		pKeyPairGen = new KeyPairGenerator();
 *		if (pKeyPairGen == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		r = pKeyPairGen->Construct(size, L"KEA");
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pKeyParams = pKeyPairGen->GenerateKeyParametersN();
 *		if (pKeyParams == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pKeyPairAlice1 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *		if (pKeyPairAlice1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyPairAlice2 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *		if (pKeyPairAlice2 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPriKeyAlice1 = pKeyPairAlice1->GetPrivateKey();
 *		if (pPriKeyAlice1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPubKeyAlice1 = pKeyPairAlice1->GetPublicKey();
 *		if (pPubKeyAlice1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPriKeyAlice2 = pKeyPairAlice2->GetPrivateKey();
 *		if (pPriKeyAlice2 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPubKeyAlice2 = pKeyPairAlice2->GetPublicKey();
 *		if (pPubKeyAlice2 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyPairBob1 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *		if (pKeyPairBob1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyPairBob2 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *		if (pKeyPairBob2 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPriKeyBob1 = pKeyPairBob1->GetPrivateKey();
 *		if (pPriKeyBob1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPubKeyBob1 = pKeyPairBob1->GetPublicKey();
 *		if (pPubKeyBob1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPriKeyBob2 = pKeyPairBob2->GetPrivateKey();
 *		if (pPriKeyBob2 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pPubKeyBob2 = pKeyPairBob2->GetPublicKey();
 *		if (pPubKeyBob2 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		pKeaKeyExchangeAlice = new KeaKeyExchange();
 *		if (pKeaKeyExchangeAlice == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeaKeyExchangeBob = new KeaKeyExchange();
 *		if (pKeaKeyExchangeBob == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeaKeyExchangeAlice->Construct(*pKeyParams);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeaKeyExchangeAlice->DoPhase(*pPriKeyAlice1, *pPubKeyBob1);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeaKeyExchangeBob->Construct(*pKeyParams);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeaKeyExchangeBob->DoPhase(*pPriKeyBob1, *pPubKeyAlice1);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pBuffer =  pKeaKeyExchangeAlice->GenerateSecretN(*pPriKeyAlice2, *pPubKeyBob2);
 *		if (pBuffer == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pBuffer1 = pKeaKeyExchangeBob->GenerateSecretN(*pPriKeyBob2, *pPubKeyAlice2);
 *		if (pBuffer1 == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		if (*pBuffer == *pBuffer1)
 *		{
 *			AppLog("Secret is Generated Successfully");
 *		}
 *		else
 *		{
 *			goto CATCH;
 *		}
 *
 *	CATCH:
 *
 *		delete pKeyPairGen;
 *		delete pKeyPairAlice1;
 *		delete pKeyPairAlice2;
 *		delete pKeyPairBob1;
 *		delete pKeyPairBob2;
 *		delete pBuffer;
 *		delete pBuffer1;
 *		delete pKeaKeyExchangeAlice;
 *		delete pKeaKeyExchangeBob;
 *		delete pKeyParams;
 *	}
 *	@endcode
 *
 */

class _OSP_EXPORT_ KeaKeyExchange
	: public virtual IKeyExchange
	, public Tizen::Base::Object
{

public:
	/**
	 *	The object is not fully constructed after this constructor is called. For full construction, @n
	 *	the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 */
	KeaKeyExchange(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~KeaKeyExchange(void);

	/**
	 *	Computes the shared secret in a phase-wise manner. @n
	 *	The %DoPhase() method requires the first party's private key(s) and the second party's public key(s)
	 *	to generate the shared secret.
	 *	This method is used in algorithms such as the KEA algorithm and also for a multi-party key exchange.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	privateKey				The private key component of the first party to instantiate
	 *	@param[in]	publicKey				The public key component of the second party to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *
	 */
	virtual result DoPhase(Tizen::Security::IPrivateKey& privateKey, Tizen::Security::IPublicKey& publicKey);

	/**
	 *	Initializes this instance of %IKeyExchange with the specified key parameters.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keyParameters			The domain parameters of the key exchange algorithm @n
	 *										This parameter needs to be instantiated.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	virtual result Construct(const Tizen::Security::IKeyParameters& keyParameters);

	/**
	 *	Generates the final shared secret among two parties.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the generated secret key, @n
	 *				else @c null if the method fails to generate the secret key
	 *	@param[in]	privateKey				The private key component of the first party to instantiate
	 *	@param[in]	publicKey				The public key component of the second party to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the openssl library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GenerateSecretN(Tizen::Security::IPrivateKey& privateKey, Tizen::Security::IPublicKey& publicKey);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	KeaKeyExchange(const KeaKeyExchange& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	KeaKeyExchange& operator =(const KeaKeyExchange& rhs);

private:
	Tizen::Base::ByteBuffer* __pParamsP;
	Tizen::Base::ByteBuffer* __pParamsG;

	Tizen::Base::ByteBuffer* __pPrivateComponent;
	Tizen::Base::ByteBuffer* __pPublicComponent;

	class _KeaKeyExchangeImpl* __pKeaKeyExchangeImpl;
	friend class _KeaKeyExchangeImpl;

}; //KeaKeyExchange

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_KEA_KEY_EXCHANGE_H_
