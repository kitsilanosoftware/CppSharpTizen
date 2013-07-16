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
 * @file		FSecPkcsPkcs05PbMacParameters.h
 * @brief		This is the header file for the %Pkcs05PbMacParameters class.
 *
 * This header file contains the declarations of the %Pkcs05PbMacParameters class.
 */

#ifndef _FSEC_PKCS_PKCS_05_PBMAC_PARAMETERS_H_
#define _FSEC_PKCS_PKCS_05_PBMAC_PARAMETERS_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsIAlgorithmParameters.h>
#include <FSecPkcsAlgorithmIdentifier.h>
#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs05PbMacParameters
 * @brief		This class implements the functionalities specified by the PKCS05 MAC scheme.
 *
 * @since		2.1
 *
 * The %Pkcs05PbMacParameters class implements the functionalities specified by the PKCS05 MAC scheme.
 *					PBMAC1 combines a password-based key derivation function, which will be PBKDF2
 *					for this version of PKCS #5, with an underlying message authentication
 *					scheme. The key length and any other parameters for
 *					the underlying message authentication scheme depend on the scheme.
 *
 *				This is defined in ASN.1 as demonstrated in the following code:
 * @code
 *				PBMAC1-params ::= SEQUENCE {
 *				keyDerivationFunc AlgorithmIdentifier {{PBMAC1-KDFs}},
 *				messageAuthScheme AlgorithmIdentifier {{PBMAC1-MACs}} }
 * @endcode
 *
 */

class _OSP_EXPORT_ Pkcs05PbMacParameters
	: public virtual IAlgorithmParameters
	, public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since			2.1
	 */
	Pkcs05PbMacParameters(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since			2.1
	 */
	virtual ~Pkcs05PbMacParameters(void);

	/**
	 * Initializes this instance of %Pkcs05PbMacParameters with the Tizen::Base::ByteBuffer instance that contains Password Based Message  @n
	 * Authentication Cryptography parameters structure(PBMAC1) in ASN.1 DER format.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData				DER encoded Tizen::Base::ByteBuffer contains %Pkcs05PbMacParameters.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes this %Pkcs05PbMacParameters with specified input parameter values.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	keyDerivationFunc		An instance of AlgorithmIdentifier, holding key derivation function
	 * @param[in]	messageAuthScheme		An instance of AlgorithmIdentifier, holding message authentication scheme
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const AlgorithmIdentifier& keyDerivationFunc, const AlgorithmIdentifier& messageAuthScheme);

	/**
	 * Gets the encoded form of the %Pkcs05PbMacParameters. @n
	 * It is assumed that each %Pkcs05PbMacParameters will have only a single form of encoding, for example ASN.1 DER.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *						else @c null if an error occurs.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

	/**
	 * Gets the reference to the AlgorithmIdentifier instance that identifies the underlying key derivation function. @n
	 * It will be an algorithm ID with an OID in the set PBES2-KDFs, which for this version of PKCS #5 will consist of ID-PBKDF2.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier holding the underlying key derivation function.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetKeyDerivationAlgorithm(void) const;

	/**
	 * Gets the algorithm identifier that identifies the underlying
	 * MAC algorithm. @n It shall be an OID like OID_HMAC_SHA1 or OID_HMAC_SHA2_224, and so on.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier holding the underlying MAC algorithm
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetMacAlgorithm(void) const;

	/**
	 * Gets the AlgorithmParameters that identifies the underlying Parameters such as PbKdf2, PbEs2, PbMac1. @n
	 * For this class %AlgorithmParameters will be of PbMac1 type.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to IAlgorithmParameters containing the algorithm identifier of underlying pseudo random function
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IAlgorithmParameters* CloneN(void) const;

	/**
	 * Get the PkcsAlgorithmParameterType value.
	 *
	 * @since		2.1
	 *
	 * @return		PkcsAlgorithmParameterType holding enum value @c PKCS_ALGO_PARAM_TYPE_PKCS05_MAC for PBMAC parameters
	 */
	virtual PkcsAlgorithmParameterType GetType(void) const;

	/**
	 * Checks whether the specified instance of %Pkcs05PbMacParameters equals the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]	rhs						An instance of %Pkcs05PbMacParameters
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %Pkcs05PbMacParameters.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value indicating the hash value of the current instance of %Pkcs05PbMacParameters
	 */
	virtual int GetHashCode(void) const;

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Pkcs05PbMacParameters(const Pkcs05PbMacParameters& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.Use CloneN() to get an exact copy of the instance. @n
	// Use Equals() to compare the contents of one instance with the other.
	//
	// @since		2.1
	Pkcs05PbMacParameters& operator =(const Pkcs05PbMacParameters& rhs);

private:
	class _Pkcs05PbMacParametersImpl* __pPkcs05PbMacParametersImpl;
	friend class _Pkcs05PbMacParametersImpl;

};  // Pkcs05PbMacParameters

} } } // Tizen::Security::Pkcs

#endif //_FSEC_PKCS_PKCS_05_PBMAC_PARAMETERS_H_
