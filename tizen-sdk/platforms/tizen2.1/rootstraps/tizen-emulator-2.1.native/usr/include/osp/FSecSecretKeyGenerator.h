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
 * @file			FSecSecretKeyGenerator.h
 * @brief		This is the header file for the %SecretKeyGenerator class.
 *
 * This header file contains the declarations of the %SecretKeyGenerator class.
 */
#ifndef _FSEC_SECRET_KEY_GENERATOR_H_
#define _FSEC_SECRET_KEY_GENERATOR_H_

#include <FSecISecretKeyGenerator.h>
#include <FSecISecureRandom.h>
#include <FSecISecretKey.h>


namespace Tizen { namespace Security
{

/**
 *	@class		SecretKeyGenerator
 *	@brief		This class is used for generating a secret (symmetric) key.
 *
 *	@since       2.0
 *
 *  The %SecretKeyGenerator class generates a secret key, which is used in symmetric ciphers. The generated secret key is based on an encryption algorithm. @n
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *	@see ISecretKeyGenerator
 */
class _OSP_EXPORT_ SecretKeyGenerator
	: public virtual ISecretKeyGenerator
	, public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 */
	SecretKeyGenerator(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~SecretKeyGenerator(void);

	/**
	 *	Constructs and initializes this instance of %SecretKeyGenerator with the specified key.
	 *
	 *	@since           2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keyBytes				The key of type Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c keyBytes is invalid or an empty Tizen::Base::ByteBuffer.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(const Tizen::Base::ByteBuffer& keyBytes);

	/**
	 *	Constructs and initializes this instance of %SecretKeyGenerator for the specified @c algorithm.
	 *
	 *	@since           2.0
	 *
	 *	@return		An error code
	 *	@param[in]	algorithm				The name of the secure random generator algorithm @n
	 *											For example, "AES","DES", or "3DES".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c algorithm is invalid or an empty string.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(const Tizen::Base::String& algorithm);

	/**
	 *	Constructs and initializes this instance of %SecretKeyGenerator with the specified key size. @n
	 *	The default algorithm is Advanced Encryption Standard (AES).
	 *
	 *	@since           2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keySize					The key size
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c keySize is @c 0 or negative.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(int keySize);

	/**
	 *	Generates a new secret key.
	 *
	 *	@since           2.0
	 *
	 *	@return		A pointer to the ISecretKey interface, @n
	 *					else @c null if it fails to generate a secret key
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM                A system error has occurred.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::ISecretKey* GenerateKeyN(void);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	SecretKeyGenerator(const SecretKeyGenerator& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	SecretKeyGenerator& operator =(const SecretKeyGenerator& rhs);

private:
	Tizen::Base::String __algorithm;
	int __keyGenSize;
	Tizen::Security::ISecureRandom* __pRandom;
	Tizen::Base::ByteBuffer __keyBytes;

	class _SecretKeyGeneratorImpl* __pSecretKeyGeneratorImpl;
	friend class _SecretKeyGeneratorImpl;

}; //SecretKeyGenerator

} } //Tizen::Security

#endif // _FSEC_SECRET_KEY_GENERATOR_H_
