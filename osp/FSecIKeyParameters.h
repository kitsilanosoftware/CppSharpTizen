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
 * @file			FSecIKeyParameters.h
 * @brief		This is the header file for the %IKeyParameters interface.
 *
 * This header file contains the declarations of the %IKeyParameters interface.
 */
#ifndef _FSEC_CRYPTO_IKEY_PARAMETERS_H_
#define _FSEC_CRYPTO_IKEY_PARAMETERS_H_

#include <FBaseByteBuffer.h>
#include <FSecCryptoTypes.h>

namespace Tizen { namespace Security
{

/**
 * @interface	IKeyParameters
 * @brief		This interface provides the abstract methods for retrieving the parameters of the key exchange algorithms.
 *
 * @since		2.0
 *
 * The %IKeyParameters interface provides the abstract methods for retrieving the parameters of the key exchange algorithms. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_exchange_algorithm.htm">Key exchanging</a>.
 *
 * @see			Tizen::Security::KeyPair
 */
class _OSP_EXPORT_ IKeyParameters
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IKeyParameters(void) {}

	/**
	 * Gets the value of the parameter for a specified key parameter type.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the parameter values, @n
	 *				else @c null if an error occurs
	 * @param[in]	paramType				The type of the parameter @n
	 *											For example, @c KEY_PARAMETER_DH_G.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE		The specified @c paramType is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetParameterValueN(KeyParameterType paramType) const = 0;

	/**
	 * Gets the size of the key parameter in bits for the specified key parameter type.
	 *
	 * @since		2.0
	 *
	 * @return		The size of the parameter, @n
	 *				else @c 0 if an error occurs
	 * @param[in]	keyParameterType		The type of the parameter @n
	 *										For example, @c PRIVATE_KEY_SIZE.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE		The specified @c paramType is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetParameterSize(KeyParameterType keyParameterType) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IKeyParameters_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IKeyParameters_Reserved2(void) {}

}; //IKeyParameters

} } //Tizen::Security

#endif //_FSEC_CRYPTO_IKEY_PAIR_PARAMETERS_H_
