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
 * @file		FSecPkcsRc2CbcParameters.h
 * @brief		This is the header file for the %Rc2CbcParameters class.
 *
 * This header file contains the declarations of the %Rc2CbcParameters class.
 */

#ifndef _FSEC_PKCS_RC2_CBC_PARAMETERS_H_
#define _FSEC_PKCS_RC2_CBC_PARAMETERS_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsIAlgorithmParameters.h>
#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Rc2CbcParameters
 * @brief		This class implements the functionalities specified by the Rc2 Cbc mode parameter.
 *
 * @since		2.1
 *
 * The %Rc2CbcParameters class implements the functionalities specified by the Rc2 Cbc mode parameter.
 *					This class represents the Rc2 cbc mode parameter for symmetric ciphers RC2.
 *					ASN.1 format for RC2-CBC-Parameter ::= SEQUENCE {
 *					rc2ParameterVersion INTEGER OPTIONAL,
 *					iv OCTET STRING (SIZE(8)) }
 *
 */

class _OSP_EXPORT_ Rc2CbcParameters
	: public virtual IAlgorithmParameters
	, public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 */
	Rc2CbcParameters(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~Rc2CbcParameters();

	/**
	 * Initializes this instance of %Rc2CbcParameters with the values of the specified input parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	initialVector			An instance of Tizen::Base::ByteBuffer containing the initial vector
	 * @param[in]	version						An integer value that defines the rc2 cbc parameter version @n
	 *															As per Pkcs 5 standard, possible values can be 160,120,58, or any value
	 *															greater than or equal to 256.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& initialVector, int version = 0);

	/**
	 * Gets a copy of this instance.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to IAlgorithmParameters, containing a copy of this instance
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IAlgorithmParameters* CloneN(void) const;

	/**
	 * Gets the algorithm parameter type enum value for %Rc2CbcParameters.
	 *
	 * @since		2.1
	 *
	 * @return		An enum value containing the @c PKCS_ALGO_PARAM_TYPE_RC2 value for %Rc2CbcParameters parameter
	 *
	 */
	virtual PkcsAlgorithmParameterType GetType(void) const;

	/**
	 * Checks whether the specified instance of %Rc2CbcParameters equals the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]	rhs						An instance of %Rc2CbcParameters
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %Rc2CbcParameters.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value indicating the hash value of the current instance of %Rc2CbcParameters
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the rc2 cbc parameter version value.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value that contains the rc2 cbc parameter version
	 *
	 */
	int GetVersion(void) const;

	/**
	 * Gets an instance of Tizen::Base::ByteBuffer that contains the initial vector value.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to Tizen::Base::ByteBuffer containing the initial vector data
	 *
	 */
	const Tizen::Base::ByteBuffer& GetInitialVector(void) const;

	/**
	 * Gets the encoded form of %Rc2CbcParameters. @n
	 * It is assumed that each %Rc2CbcParameters type will have only a single form of encoding that is DER encoding.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the DER encoded Tizen::Base::ByteBuffer, @n
	 *						else @c null if an error occurs
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_SYSTEM						The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Rc2CbcParameters(const Rc2CbcParameters& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.Use GetCloneN() to get an exact copy of the instance.
	//
	// @since		2.1
	Rc2CbcParameters& operator =(const Rc2CbcParameters& rhs);

private:
	class _Rc2CbcParametersImpl* __pRc2CbcParametersImpl;
	friend class _Rc2CbcParametersImpl;

}; // Rc2CbcParameters

} } } // Tizen::Security::Pkcs

#endif // _FSEC_PKCS_RC2_CBC_PARAMETERS_H_
