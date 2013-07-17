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
 * @file		FSecPkcsAlgorithmIdentifier.h
 * @brief		This is the header file for the %AlgorithmIdentifier class.
 *
 * This header file contains the declarations of the %AlgorithmIdentifier class.
 */

#ifndef _FSEC_PKCS_ALGORITHM_IDENTIFIER_H_
#define _FSEC_PKCS_ALGORITHM_IDENTIFIER_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsIAlgorithmParameters.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		AlgorithmIdentifier
 * @brief		This class implements the ASN.1 specified %AlgorithmIdentifier, which is used for
 *				creating the standard %AlgorithmIdentifier object.
 *
 * @since		2.1
 *
 * The %AlgorithmIdentifier class implements the ASN.1 specified %AlgorithmIdentifier, which is used for
 *				creating the standard %AlgorithmIdentifier object.
 *              %AlgorithmIdentifier structure consists the OID value of the algorithm along with the parameters of that algorithm.
 *
 *              This is defined in ASN.1 as demonstrated in the following code:
 * @code
 *              AlgorithmIdentifier { ALGORITHM-IDENTIFIER:InfoObjectSet }
 *              ::=
 *              SEQUENCE {
 *              algorithm ALGORITHM-IDENTIFIER.&id({InfoObjectSet}),
 *              parameters ALGORITHM-IDENTIFIER.&Type({InfoObjectSet}
 *              {@algorithm}) OPTIONAL }
 *              ALGORITHM-IDENTIFIER ::= TYPE-IDENTIFIER
 * @endcode
 *
 */

class _OSP_EXPORT_ AlgorithmIdentifier
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 */
	AlgorithmIdentifier(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~AlgorithmIdentifier(void);

	/**
	 * Initializes the %AlgorithmIdentifier with supplied input parameter values.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	objectId			The object identifier of a particular algorithm @n
	 * 									Object IDs are defined by standard bodies for algorithms and other crypto objects.
	 *									Object ID of %AlgorithmIdentifier can be described in string format like 1.2.3.4
	 * @param[in]	pParams				A pointer to the AlgorithmParameters object @n 
	 *									This is an optional parameter and contains a list of user specified input parameters for the specified algorithm. For example, for Symmetric algorithms Initial vector, IV is required as an input. The default value of this parameter is @c null.
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_ALGORITHM		The object ID of the input algorithm is not supported.
	 */
	result Construct(const Tizen::Base::String& objectId, const IAlgorithmParameters* pParams = null);

	/**
	 * Initializes this instance of %AlgorithmIdentifier with the DER encoded Tizen::Base::ByteBuffer that contains @n
	 * the ASN.1 specified %AlgorithmIdentifier structure.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData					An instance of DER encoded Tizen::Base::ByteBuffer
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Checks whether the specified instance of %AlgorithmIdentifier equals the current instance.
	 *
	 * @since			2.1
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *            else @c false
	 * @param[in]	rhs									An instance of %AlgorithmIdentifier
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %AlgorithmIdentifier.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value indicating the hash value of the current instance of %AlgorithmIdentifier
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the copy of %AlgorithmIdentifier instance.
	 *
	 * @since		2.1
	 *
	 * @return		Pointer to %AlgorithmIdentifier, containing the copy of the specified instance, @n
	 *						else @c null if an error occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	AlgorithmIdentifier* CloneN(void) const;

	/**
	 * Gets the parameters of algorithm.
	 *
	 * @since		2.1
	 *
	 * @return		Pointer to IAlgorithmParameters, containing the parameter list of algorithm, @n
	 *						else @c null if an no parameters exist
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	IAlgorithmParameters* GetParametersN(void) const;

	/**
	 * Gets the object ID value of an algorithm in string format.
	 *
	 * @since			2.1
	 *
	 * @return		Object ID of %AlgorithmIdentifier in string format like 1.2.3.4
	 *
	 */
	Tizen::Base::String GetAlgorithmObjectId(void) const;

	/**
	 * Gets the encoded form of the %AlgorithmIdentifier. @n
	 * It is assumed that each %AlgorithmIdentifier type will have only a single form of encoding that is DER encoding.
	 *
	 * @since		2.1
	 *
	 * @return		Pointer to the DER encoded Tizen::Base::ByteBuffer, @n
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
	AlgorithmIdentifier(const AlgorithmIdentifier& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.Use CloneN() to get an exact copy of the instance. @n
	// Use Equals() to compare the contents of one instance with the other.
	//
	// @since		2.1
	AlgorithmIdentifier& operator =(const AlgorithmIdentifier& rhs);

private:
	class _AlgorithmIdentifierImpl* __pAlgorithmIdentifierImpl;
	friend class _AlgorithmIdentifierImpl;
}; // AlgorithmIdentifier

} } } // Tizen::Security::Pkcs

#endif //_FSEC_PKCS_ALGORITHM_IDENTIFIER_H_
