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
 * @file		FSecCryptoIKeyExchange.h
 * @brief		This is the header file for the %IKeyExchange interface.
 *
 * This header file contains the declarations of the %IKeyExchange interface.
 */
#ifndef _FSEC_CRYPTO_IKEY_EXCHANGE_H_
#define _FSEC_CRYPTO_IKEY_EXCHANGE_H_

#include <FBaseByteBuffer.h>
#include <FSecCryptoTypes.h>
#include <FSecKeyPair.h>
#include <FSecIKeyParameters.h>

namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@interface	IKeyExchange
 *	@brief		This interface provides methods for the Key Exchange algorithm.
 *
 *	@since		2.0
 *
 *	The %IKeyExchange interface provides methods to exchange secure keys between two communicating users. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_exchange_algorithm.htm">Key exchanging</a>.
 *
 *	@see	KeyPairGenerator
 */
class _OSP_EXPORT_ IKeyExchange
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 *	@since		2.0
	 */
	virtual ~IKeyExchange(void) {}

	/**
	 *	Initializes this instance of %IKeyExchange with the specified key parameters.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keyParameters			The domain parameters of the key exchange algorithm that needs to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@remarks	The key parameters can be @c null depending on the underlying key exchange algorithm.
	 */
	virtual result Construct(const Tizen::Security::IKeyParameters& keyParameters) = 0;

	/**
	 *	Generates the final version of the shared secret amongst the two parties.
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
	virtual Tizen::Base::ByteBuffer* GenerateSecretN(Tizen::Security::IPrivateKey& privateKey, Tizen::Security::IPublicKey& publicKey) = 0;


protected:
	//
	//	This method is for internal use only. Using this method can cause behavioral, security-related,
	//	and consistency-related issues in the application.
	//
	//	This method is reserved and may change its name at any time without prior notice.
	//
	//	@since 2.0
	//
	virtual void IKeyExchange_Reserved1(void) {}

	//
	//	This method is for internal use only. Using this method can cause behavioral, security-related,
	//	and consistency-related issues in the application.
	//
	//	This method is reserved and may change its name at any time without prior notice.
	//
	//	@since 2.0
	//
	virtual void IKeyExchange_Reserved2(void) {}

	//
	//	This method is for internal use only. Using this method can cause behavioral, security-related,
	//	and consistency-related issues in the application.
	//
	//	This method is reserved and may change its name at any time without prior notice.
	//
	//	@since 2.0
	//
	virtual void IKeyExchange_Reserved3(void) {}

}; //IKeyExchange

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_IKEY_EXCHANGE_H_
