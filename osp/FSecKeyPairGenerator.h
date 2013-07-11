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
 * @file			FSecKeyPairGenerator.h
 * @brief		This is the header file for the %KeyPairGenerator class.
 *
 * This header file contains the declarations of the %KeyPairGenerator class.
 */
#ifndef _FSEC_KEY_PAIR_GENERATOR_H_
#define _FSEC_KEY_PAIR_GENERATOR_H_

#include <FSecIKeyPairGenerator.h>
#include <FSecISecureRandom.h>
#include <FSecIKeyParameters.h>


namespace Tizen { namespace Security
{

/**
 *  @class		KeyPairGenerator
 *  @brief		This class provides a pair of public and private keys for the Public key algorithm.
 *
 *  @since  2.0
 *
 *  The %KeyPairGenerator class generates a key pair and its parameters that consists of a public and private key. These are used in asymmetric ciphers. The generated key pair and parameters are based on the underlying key pair encryption algorithm. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *  @see Tizen::Security::IKeyPairGenerator
 *  @see Tizen::Security::KeyPair
 */
class _OSP_EXPORT_ KeyPairGenerator
	: public virtual IKeyPairGenerator
	, public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	KeyPairGenerator(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~KeyPairGenerator(void);

	/**
	 *	Constructs and initializes an instance of %KeyPairGenerator with the specified parameter.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	modulusBitSize	The modulus size in bits
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_ARG		The specified size is invalid. @n
	 *							The modulus size must be at least greater than or equal to @c 1024 bits @n
	 *							to generate cryptographically secure keys.
	 */
	virtual result Construct(int modulusBitSize);

	/**
	 *	Constructs and initializes an instance of %KeyPairGenerator with the specified parameters.
	 *
	 * @since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	modulusBitSize			The modulus size in bits @n
	 *										This is used for key generation.
	 *  @param[in]  algorithm				The algorithm used to generate the key parameters @n
	 *										The supported algorithms are RSA, DH, and KEA. The default value is RSA.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified size is invalid. @n
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The requested @c algorithm is not supported. @n
	 *							The modulus size must be at least greater than or equal to @c 1024 bits @n
	 *							to generate cryptographically secure keys.
	 */
	result Construct(int modulusBitSize, const Tizen::Base::String algorithm);

	/**
	*	Generates the key parameters based on the underlying key pair algorithm. @n
	*	For example, in case of the DH or KEA algorithm, this method generates key parameters based on the DSA
	*	algorithm (X186.3 specification).
	*	The supported algorithms are RSA, DH, and KEA.
	*	The generated key parameters may be required to create a key pair. The RSA algorithm
	*	does not call this method to generate a key pair.
	*
	*	@since			2.0
	*
	*	@return			A pointer to the IKeyParameters class that contains a subset of the domain parameters ('p' prime
	*					number, 'g' generator) that are used to generate a key pair, @n
	*					else @c null if the method fails to create the key parameters
	*	@param[in]	lInBits		The size of 'p', a prime number in bits @n
	*							The size must be @c 1024 bits, @c 2048 bits, or @c 3072 bits.
	*	@param[in]	nInBits		The size of 'g', a generator value in bits @n
	*							The size must be:
	*							- 160 bits, when @c lInBits is @c 1024 bits.
	*							- 254 or 256 bits, when @c lInBits is @c 2048 bits.
	*							- 256 bits, when @c lInBits is @c 3072 bits.
	*	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM		The requested algorithm is not supported.
	*	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	*	@exception	E_SYSTEM					A system error has occurred. @n
	*											The method has failed to operate with the OpenSSL library, or the Tizen::Base::ByteBuffer operation has failed.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Security::IKeyParameters* GenerateKeyParametersN(int lInBits = 1024, int nInBits = 160) const;

	/**
	 *	Generates a new key pair.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the KeyPair class, @n
	 *				else @c null if the method fails to create the key pair
	 *	@param[in]   pKeyParams				The domain parameters of the key exchange algorithm @n
	 *										These parameters are instantiated.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The requested algorithm is not supported.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Security::KeyPair* GenerateKeyPairN(Tizen::Security::IKeyParameters* pKeyParams) const;

	/**
	 *	Generates a new key pair.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the KeyPair class, @n
	                else @c null if the method fails to create the key pair
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM		The requested algorithm is not supported.
	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *	@exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the OpenSSL library, or the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::KeyPair* GenerateKeyPairN(void) const;

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	KeyPairGenerator(const KeyPairGenerator& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	KeyPairGenerator& operator =(const KeyPairGenerator& rhs);

private:
	Tizen::Base::String __algorithm;
	int __modulusBitSize;

	class _KeyPairGeneratorImpl* __pKeyPairGeneratorImpl;
	friend class _KeyPairGeneratorImpl;

}; //KeyPairGenerator

} } //Tizen::Security

#endif // _FSEC_KEY_PAIR_GENERATOR_H_
