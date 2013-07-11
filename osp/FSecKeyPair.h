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
 * @file		FSecKeyPair.h
 * @brief		This is the header file for the %KeyPair class.
 *
 * This header file contains the declarations of the %KeyPair class.
 */
#ifndef _FSEC_KEY_PAIR_H_
#define _FSEC_KEY_PAIR_H_

#include <FSecIKey.h>
#include <FSecIPublicKey.h>
#include <FSecIPrivateKey.h>
#include <FBaseObject.h>


namespace Tizen { namespace Security
{

/**
 *  @class		KeyPair
 *  @brief		This class is a simple holder for a key pair (a public and a private key).
 *
 *  @since		2.0
 *
 *  The %KeyPair class manages a pair of keys comprising of a public and a private key, which are used in asymmetric ciphers. The key pairs are mainly used to encrypt messages and provide digital signatures. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *  @see	IKeyPairGenerator
 *  @see	Tizen::Security::IPublicKey
 *  @see	Tizen::Security::IPrivateKey
 */
class _OSP_EXPORT_ KeyPair
	: public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 */
	KeyPair(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~KeyPair(void);

	/**
	 *	Constructs and initializes the current instance of %KeyPair with the specified public and private keys.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	publicKey				An instance of IPublicKey
	 *	@param[in]	privateKey				An instance of IPrivateKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c publicKey or @c privateKey is invalid.
	 */
	result Construct(Tizen::Security::IPublicKey& publicKey, Tizen::Security::IPrivateKey& privateKey);

	/**
	 *	Gets the public key component of the current instance of %KeyPair.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to IPublicKey
	 */
	Tizen::Security::IPublicKey* GetPublicKey(void) const;

	/**
	 *	Gets the private key component of the current instance of %KeyPair.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to IPrivateKey
	 */
	Tizen::Security::IPrivateKey* GetPrivateKey(void) const;

	/**
	 *	Sets the public key.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	pubKey					An instance of Tizen::Base::ByteBuffer that contains the public key
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c pubKey is invalid.
	 *	@remarks	Only ASN.1 encoding format is supported for input buffer.
	 */
	result SetPublicKey(const Tizen::Base::ByteBuffer& pubKey);

	/**
	 *	Sets the private key.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	privKey					An instance of Tizen::Base::ByteBuffer that contains the private key
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c privKey is invalid.
	 *	@remarks	Only ASN.1 encoding format is supported for input buffer.
	 */
	result SetPrivateKey(const Tizen::Base::ByteBuffer& privKey);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	KeyPair(const KeyPair& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	KeyPair& operator =(const KeyPair& rhs);

private:
	Tizen::Security::IPublicKey* __pPubKey;
	Tizen::Security::IPrivateKey* __pPriKey;

	class _KeyPairImpl* __pKeyPairImpl;
	friend class _KeyPairImpl;

}; //KeyPair

} } //Tizen::Security

#endif // _FSEC_KEY_PAIR_H_
