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
 * @file		FSecCryptoRsaSignature.h
 * @brief		This is the header file for the %RsaSignature class.
 *
 * This header file contains the declarations of the %RsaSignature class.
 */
#ifndef _FSEC_CRYPTO_RSA_SIGNATURE_H_
#define _FSEC_CRYPTO_RSA_SIGNATURE_H_

#include <FSecCryptoISignature.h>
#include <FBase.h>


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@class		RsaSignature
 *	@brief		This class implements the Rivest Shamir Adleman (RSA) signatures.
 *
 *	@since		2.0
 *
 *	The %RsaSignature class implements the Rivest Shamir Adleman (RSA) signatures. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/ciphers.htm">Ciphers</a>.
 *
 *	@see ISignature
 *	@see IKeyPairGenerator
 *	@see KeyPair
 *	@see IPublicKey
 *	@see IPrivateKey
 *	@see PublicKey
 *	@see PrivateKey
 */
class _OSP_EXPORT_ RsaSignature
	: public virtual ISignature
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		2.0
	 */
	RsaSignature(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~RsaSignature(void);

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
	virtual result SetPrivateKey(const Tizen::Security::IKey& key);

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
	virtual result SetPublicKey(const Tizen::Security::IKey& key);

	/**
	 *	Signs the data.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input						An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND				The specified key is not found.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the OpenSSL library, or
	 *											the Tizen::Base::ByteBuffer operation has failed.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* SignN(const Tizen::Base::ByteBuffer& input);

	/**
	 *	Verifies the data. @n
	 *	The verification is done by comparing the @c signedData to the signature created by the @c data.
	 *
	 *	@since		2.0
	 *
	 *	@return		@c true if the signed data is correct, @n
	 *				else @c false
	 *	@param[in]	data						An instance of Tizen::Base::ByteBuffer that contains the original data
	 *	@param[in]	signedData					A instance of Tizen::Base::ByteBuffer that contains the signed data
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG				The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND				The specified key is not found.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the OpenSSL library, or
	 *											the Tizen::Base::ByteBuffer operation has failed.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Verify(const Tizen::Base::ByteBuffer& data, const Tizen::Base::ByteBuffer& signedData);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	RsaSignature(const RsaSignature& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	RsaSignature& operator =(const RsaSignature& rhs);

private:
	Tizen::Base::ByteBuffer __privateKey;
	Tizen::Base::ByteBuffer __publicKey;

	class _RsaSignatureImpl* __pRsaSignatureImpl;
	friend class _RsaSignatureImpl;

}; //RsaSignature

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_RSA_SIGNATURE_H_
