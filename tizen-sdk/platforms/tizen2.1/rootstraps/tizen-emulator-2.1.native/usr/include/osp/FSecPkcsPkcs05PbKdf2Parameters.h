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
 * @file		FSecPkcsPkcs05PbKdf2Parameters.h
 * @brief		This is the header file for the %Pkcs05PbKdf2Parameters class.
 *
 * This header file contains the declarations of the %Pkcs05PbKdf2Parameters class.
 */

#ifndef _FSEC_PKCS_PKCS_05_PBKDF2_PARAMETERS_H_
#define _FSEC_PKCS_PKCS_05_PBKDF2_PARAMETERS_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsIAlgorithmParameters.h>
#include <FSecPkcsAlgorithmIdentifier.h>
#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs05PbKdf2Parameters
 * @brief		This class implements the functionalities specified by the PKCS05 KDF2 scheme. 
 *
 * @since		2.1
 *
 * The %Pkcs05PbKdf2Parameters class implements the functionalities specified by the PKCS05 KDF2 scheme. PBKDF2 applies a pseudo random function to derive
 *					keys. The length of the derived key is essentially unbounded. However, the maximum effective search space for the derived key can
 *					be limited by the structure of the underlying pseudo random function.
 *
 *				This is defined in ASN.1 as demonstrated in the following code:
 * @code
 *				PBKDF2-params ::= SEQUENCE {
 *				salt CHOICE {
 *				specified OCTET STRING,
 *				otherSource AlgorithmIdentifier {{PBKDF2-SaltSources}}
 *				},
 *				iterationCount INTEGER (1..MAX),
 *				keyLength INTEGER (1..MAX) OPTIONAL,
 *				prf AlgorithmIdentifier {{PBKDF2-PRFs}} DEFAULT
 *				algid-hmacWithSHA1 }
 * @endcode
 *
 */

class _OSP_EXPORT_ Pkcs05PbKdf2Parameters
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
	Pkcs05PbKdf2Parameters(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~Pkcs05PbKdf2Parameters(void);

	/**
	 * Initializes this instance of %Pkcs05PbKdf2Parameters with the encoded Tizen::Base::ByteBuffer that contains Password Based Key Derivation Function parameters structure(PBKDF2) in ASN.1 DER format.
	  *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData					DER encoded Tizen::Base::ByteBuffer of %Pkcs05PbKdf2Parameters
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes the %Pkcs05PbKdf2Parameters with specified input parameters values.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	saltBuffer					An instance of Tizen::Base::ByteBuffer, holding salt value
	 * @param[in]	iterationCount			Integer value holding the positive integer specifying iteration count
	 *																for generation of password based key
	 * @param[in]	derivedKeyLength		Positive integer specifying length of password based key to generate
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remark		In this case, when pseudo random function algorithm is not passed, then default HMAC-SHA1 will be used.
	 */
	result Construct(const Tizen::Base::ByteBuffer& saltBuffer, int iterationCount, int derivedKeyLength = 0);

	/**
	 * Initializes this %Pkcs05PbKdf2Parameters with supplied input parameters values.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	saltBuffer					An instance of Tizen::Base::ByteBuffer, holding salt value
	 * @param[in]	iterationCount			Integer value holding the positive integer specifying iteration count
	 *																for generation of password based key
	 * @param[in]	prf									An instance of AlgorithIdentifier, holding the underlying pseudo random function to use to generate a password based key
	 * @param[in]	derivedKeyLength		Positive integer specifying length of password based key to generate
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& saltBuffer, int iterationCount, const AlgorithmIdentifier& prf, int derivedKeyLength = 0);

	/**
	 * Gets the encoded form of the %Pkcs05PbKdf2Parameters. @n
	 * It is assumed that each %Pkcs05PbKdf2Parameters will have only a single form of encoding, for example: ASN.1 DER.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

	/**
	 * Gets the salt byte buffer.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to salt Tizen::Base::ByteBuffer containing the specified salt value
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const Tizen::Base::ByteBuffer& GetSaltValue(void) const;

	/**
	 * Gets the iteration count. @n
	 * The purpose of this count is to increase the cost of producing keys from a password, thereby, also increasing the difficulty of attack.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value containing the iteration count for PBKDF2
	 *
	 */
	int GetIterationCount(void) const;

	/**
	 * Gets the derived key length. @n
	 * The %GetDerivedKeyLength() method returns the length of the derived key that is used to generate the password based key.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value containing the length of the derived key
	 *
	 */
	int GetDerivedKeyLength(void) const;

	/**
	 * Gets the reference to the AlgorithmIdentifier that identifies the underlying pseudo random function.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier containing the algorithm identifier of underlying pseudo random function
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetPrf(void) const;

	/**
	 *
	 * Gets the pointer to the AlgorithmParameters that identifies the underlying parameters such as PbKdf2,PbEs2,PbMac1. @n
	 * For this class %AlgorithmParameters will be of PbKdf2 type.
	 *
	 * @since		2.1
	 *
	 * @return		Pointer to IAlgorithmParameters containing the algorithm identifier of underlying pseudo random function, @n
	 *				else @c null if an error occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IAlgorithmParameters* CloneN(void) const;

	/**
	 * Gets the PkcsAlgorithmParameterType value.
	 *
	 * @since		2.1
	 *
	 * @return		PkcsAlgorithmParameterType holding enum value @c PKCS_ALGO_PARAM_TYPE_PKCS05_KDF02 for KDF2 Parameters
	 */
	virtual PkcsAlgorithmParameterType GetType(void) const;

	/**
	 * Checks whether the specified instance of %Pkcs05PbKdf2Parameters equals the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]	rhs							An instance of %Pkcs05PbKdf2Parameters
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %Pkcs05PbKdf2Parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value indicating the hash value of the current instance of %Pkcs05PbKdf2Parameters
	 */
	virtual int GetHashCode(void) const;

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Pkcs05PbKdf2Parameters(const Pkcs05PbKdf2Parameters& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.Use CloneN() to get an exact copy of the instance. @n
	// Use Equals() to compare the contents of one instance with the other.
	//
	// @since		2.1
	Pkcs05PbKdf2Parameters& operator =(const Pkcs05PbKdf2Parameters& rhs);

private:
	class _Pkcs05PbKdf2ParametersImpl* __pPkcs05PbKdf2ParametersImpl;
	friend class _Pkcs05PbKdf2ParametersImpl;
};  // Pkcs05PbKdf2Parameters

} } } // Tizen::Security::Pkcs

#endif //_FSEC_PKCS_PKCS_05_PBKDF2_PARAMETERS_H_
