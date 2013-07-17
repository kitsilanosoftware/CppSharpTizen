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
 * @file			FSecIKeyPairGenerator.h
 * @brief		This is the header file for the %IKeyPairGenerator interface.
 *
 * This header file contains the declarations of the %IKeyPairGenerator interface.
 */
#ifndef _FSEC_IKEY_PAIR_GENERATOR_H_
#define _FSEC_IKEY_PAIR_GENERATOR_H_

#include <FBaseString.h>
#include <FSecKeyPair.h>


namespace Tizen { namespace Security
{

/**
 * @interface	IKeyPairGenerator
 * @brief		This interface provides the abstract methods for generating a pair of public and private keys.
 *
 * @since		2.0
 *
 * The %IKeyPairGenerator interface provides the abstract methods for generating a pair of public and private keys. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 * @see			Tizen::Security::KeyPair
 */
class _OSP_EXPORT_ IKeyPairGenerator
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 *	@since		2.0
	 */
	virtual ~IKeyPairGenerator(void){}

	/**
	 * Constructs and initializes an instance of %IKeyPairGenerator with the specified modulus size.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	modulusBitSize		The modulus size in bits
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c modulusBitSize is invalid. @n
	 *							The modulus size must be atleast greater than or equal to @c 1024 bits @n
	 *							to generate cryptographically secure keys.
	 */
	virtual result Construct(int modulusBitSize) = 0;

	/**
	 * Generates a new key pair.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the KeyPair class, @n
	 *				else @c null if the method fails to generate the key pair
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_ALGORITHM		The requested algorithm is not supported.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred. @n
	 *											The method has failed to operate with the OpenSSL library.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::KeyPair* GenerateKeyPairN(void) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IKeyPairGenerator_Reserved1(void) {}

}; //IKeyPairGenerator

} } //Tizen::Security

#endif // _FSEC_IKEY_PAIR_GENERATOR_H_
