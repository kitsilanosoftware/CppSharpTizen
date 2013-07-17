//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FSecPkcsIAlgorithmParameters.h
 * @brief		This is the header file for the %IAlgorithmParameters interface.
 *
 * This header file contains the declarations of the %IAlgorithmParameters interface.
 */

#ifndef _FSEC_PKCS_IALGORITHM_PARAMETERS_H_
#define _FSEC_PKCS_IALGORITHM_PARAMETERS_H_

#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @interface	IAlgorithmParameters
 * @brief		This interface is an interface class for cryptographic algorithm parameters such as IV, etc. It provides the generic
 *					functionalities that must be supported by all derived algorithm parameters such PbKdf2Parameters, PbEs2Parameters.
 *
 * @since		2.1
 *
 * The %IAlgorithmParameters interface is an interface class for cryptographic algorithm parameters such as IV, etc. It provides the generic
 *					functionalities that must be supported by all derived algorithm parameters such PbKdf2Parameters, PbEs2Parameters.
 *					This is an abstract class and hence, object of this class cannot be instantiated.
 *
 */

class _OSP_EXPORT_ IAlgorithmParameters
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, @n
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.1
	 */
	virtual ~IAlgorithmParameters(void) {}

	/**
	 * Gets the copy of parameters of the specified algorithm type.
	 *
	 * @since			2.1
	 *
	 * @return		Pointer to AlgorithmParameters, containing the instance of algorithm parameter , @n
	 *						else @c null if an error occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IAlgorithmParameters* CloneN(void) const = 0;

	/**
	 * Gets the PKCS algorithm parameter type enumerated value.
	 *
	 * @since			2.1
	 *
	 * @return		PkcsAlgorithmParamterType, containing the enumerated value of PkcsAlgorithmParameterType
	 *
	 */
	virtual PkcsAlgorithmParameterType GetType(void) const = 0;


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.1
	//
	virtual void IAlgorithmParameters_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.1
	//
	virtual void IAlgorithmParameters_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.1
	//
	virtual void IAlgorithmParameters_Reserved3(void) {}

}; // IAlgorithmParameters

} } } // Tizen::Security::Pkcs

#endif // _FSEC_PKCS_IAGORITHM_PARAMETERS_H_
