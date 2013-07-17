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
 * @file		FSecPkcsPkcs05PbEs2Parameters.h
 * @brief		This is the header file for the %Pkcs05PbEs2Parameters class.
 *
 * This header file contains the declarations of the %Pkcs05PbEs2Parameters class.
 */

#ifndef _FSEC_PKCS_PKCS_05_PBES2_PARAMETERS_H_
#define _FSEC_PKCS_PKCS_05_PBES2_PARAMETERS_H_


#include <FBaseByteBuffer.h>
#include <FSecPkcsIAlgorithmParameters.h>
#include <FSecPkcsAlgorithmIdentifier.h>
#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs05PbEs2Parameters
 * @brief		This class implements the functionalities specified by the PKCS05 encryption scheme 2.
 *
 * @since		2.1
 *
 * The %Pkcs05PbEs2Parameters class implements the functionalities specified by the PKCS05 encryption scheme 2.
 *					PBES2 combines a password-based key derivation function, which is PBKDF2
 *					for PKCS #5 version 2.1, with an underlying encryption scheme.
 *					The key length and any other parameters for the underlying encryption scheme depends on the scheme.
 *
 *              This is defined in ASN.1 as demonstrated in the following code:
 * @code
 *              PBES2-params ::= SEQUENCE {
 *              keyDerivationFunc AlgorithmIdentifier {{PBES2-KDFs}},
 *              encryptionScheme AlgorithmIdentifier {{PBES2-Encs}} }
 * @endcode
 *
 */

class _OSP_EXPORT_ Pkcs05PbEs2Parameters
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
	Pkcs05PbEs2Parameters(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~Pkcs05PbEs2Parameters(void);

	/**
	 * Initializes this instance of %Pkcs05PbEs2Parameters with the encoded Tizen::Base::ByteBuffer, which contain Password Based Encryption Parameters Structure(PBES2) in ASN.1 DER format.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData				The DER encoded Tizen::Base::ByteBuffer containing %Pkcs05PbEs2Parameters
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes this %Pkcs05PbEs2Parameters with specified input parameters values.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	keyDerivationFunction		An instance of AlgorithmIdentifier, holding key derivation function
	 * @param[in]	encryptionScheme		An instance of AlgorithmIdentifier, holding encryption scheme
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const AlgorithmIdentifier& keyDerivationFunction, const AlgorithmIdentifier& encryptionScheme);

	/**
	 * Gets the encoded form of the %Pkcs05PbEs2Parameters. @n
	 * It is assumed that each %Pkcs05PbEs2Parameters will have only a single form of encoding example ASN.1 DER.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *						else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

	/**
	 * Gets the reference to the AlgorithmIdentifier instance, which identifies the underlying key derivation function. @n
	 * It will be an algorithm ID with an OID in the set PBES2-KDFs, which for this version of PKCS #5 will consist of id-PBKDF2.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier holding the underlying key derivation function
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetKeyDerivationAlgorithm(void) const;

	/**
	 * Gets the reference to the AlgorithmIdentifier instance, which identifies the underlying encryption algorithm. @n
	 * It shall be an OID in the set PBES2-Encs, whose definition is left to the application.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier holding the underlying encryption algorithm
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetEncryptionScheme(void) const;

	/**
	 * Gets the AlgorithmParameters that identifies the underlying parameters such as PbKdf2, PbEs2, PbMac1. @n
	 * For this class %AlgorithmParameters will be of PBES2 type.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to IAlgorithmParameters containing the algorithm identifier of underlying pseudo random function, @n
	 *				else @c null if an error occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IAlgorithmParameters* CloneN(void) const;

	/**
	 *
	 * Gets the PkcsAlgorithmParameterType value.
	 *
	 * @since		2.1
	 *
	 * @return		PkcsAlgorithmParameterType holding enum value @c PKCS_ALGO_PARAM_TYPE_PKCS05_PBES02 for PBES2 Parameters
	 *
	 */
	virtual PkcsAlgorithmParameterType GetType(void) const;

	/**
	 * Checks whether the specified instance of %Pkcs05PbEs2Parameters equals the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]	rhs							An instance of %Pkcs05PbEs2Parameters
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %Pkcs05PbEs2Parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value indicating the hash value of the current instance of %Pkcs05PbEs2Parameters
	 */
	virtual int GetHashCode(void) const;

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Pkcs05PbEs2Parameters(const Pkcs05PbEs2Parameters& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.Use CloneN() to get an exact copy of the instance. @n
	// Use Equals() to compare the contents of one instance with the other.
	//
	// @since		2.1
	Pkcs05PbEs2Parameters& operator =(const Pkcs05PbEs2Parameters& rhs);

private:
	class _Pkcs05PbEs2ParametersImpl* __pPkcs05PbEs2ParametersImpl;
	friend class _Pkcs05PbEs2ParametersImpl;
};  //Pkcs05PbEs2Parameters

} } } // Tizen::Security::Pkcs

#endif // _FSEC_PKCS_PKCS_05_PBES2_PARAMETERS_H_
