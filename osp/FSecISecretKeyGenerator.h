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
 * @file		FSecISecretKeyGenerator.h
 * @brief		This is the header file for the %ISecretKeyGenerator interface.
 *
 * This header file contains the declarations of the %ISecretKeyGenerator interface.
 */
#ifndef _FSEC_ISECRET_KEY_GENERATOR_H_
#define _FSEC_ISECRET_KEY_GENERATOR_H_

#include <FSecISecretKey.h>
#include <FBaseString.h>


namespace Tizen { namespace Security
{

/**
 * @interface	ISecretKeyGenerator
 * @brief		This interface provides the abstract methods for generating a secret (symmetric) key.
 *
 * @since       2.0
 *
 * The %ISecretKeyGenerator interface provides the abstract methods for generating a secret (symmetric) key. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 * @see	Tizen::Security::ISecretKey
 */
class _OSP_EXPORT_ ISecretKeyGenerator
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~ISecretKeyGenerator(void) {}

	/**
	 * Generates a new secret key.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the ISecretKey interface, @n
	 *				else @c null if the secret key generation fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The method has failed to operate with the OpenSSL library.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::ISecretKey* GenerateKeyN(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISecretKeyGenerator_Reserved1(void) {}


}; //ISecretKeyGenerator

} } //Tizen::Security

#endif // _FSEC_ISECRET_KEY_GENERATOR_H_
