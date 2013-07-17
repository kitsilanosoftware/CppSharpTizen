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
 * @file		FSecPkcsInitialVector.h
 * @brief		This is the header file for the %InitialVector class.
 *
 * This header file contains the declarations of the %InitialVector class.
 */

#ifndef _FSEC_PKCS_INITIAL_VECTOR_H_
#define _FSEC_PKCS_INITIAL_VECTOR_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsIAlgorithmParameters.h>
#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		InitialVector
 * @brief		This class implements the functionalities specified by the %InitialVector class.
 *
 * @since		2.1
 *
 * The %InitialVector class implements the functionalities specified by the %InitialVector class.
 *					This class represents the Initial Vector parameter for symmetric ciphers such as DES, AES, DES_EDE.
 *					This %InitialVector parameters will be used by both PKCS05 and PKCS08 related classes at the time of encryption.
 *
 *
 */

class _OSP_EXPORT_ InitialVector
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
	InitialVector(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.1
	*/

	virtual ~InitialVector(void);

	/**
	 * Initializes this instance of %InitialVector with the specified input buffer.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 *
	 * @param[in]	initialVector		An instance of Tizen::Base::ByteBuffer, holding the initial vector data
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& initialVector);

	/**
	 * Gets copy of this instance.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to IAlgorithmParameters, containing the copy of this instance
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IAlgorithmParameters* CloneN(void) const;

	/**
	 * Gets the algorithm parameter type enum value for Initial Vector.
	 *
	 * @since		2.1
	 *
	 * @return		PkcsAlgorithmParameterType		Enum value containing the PKCS_ALGO_PARAM_TYPE_IV value for Initial Vector parameter
	 *
	 */
	virtual PkcsAlgorithmParameterType GetType(void) const;

	/**
	 * Checks whether the specified instance of %InitialVector equals the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]	rhs					An instance of %InitialVector
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %InitialVector.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value indicating the hash value of the current instance of %InitialVector
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the instance of Tizen::Base::ByteBuffer that contains the Initial Vector value.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the Tizen::Base::ByteBuffer class that contains the output
	 */
	const Tizen::Base::ByteBuffer& GetInitialVector(void) const;

	/**
	 * Gets the encoded form of the InitialVector. @n
	 * It is assumed that each InitialVector type will have only a single form of encoding that is DER encoding.
	 *
	 * @since		2.1
	 *
	 * @return		Pointer to the DER encoded Tizen::Base::ByteBuffer, @n
	 *							else @c null if an error occurs
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
	InitialVector(const InitialVector& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.Use CloneN() to get an exact copy of the instance. @n
	// Use Equals() to compare the contents of one instance with the other.
	//
	// @since		2.1
	InitialVector& operator =(const InitialVector& rhs);

private:
	class _InitialVectorImpl* __pInitialVectorImpl;
	friend class _InitialVectorImpl;

}; // InitialVector

} } } //Tizen::Security::Pkcs

#endif //_FSEC_PKCS_INITIAL_VECTOR_H_
