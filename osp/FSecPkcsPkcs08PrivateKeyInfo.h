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
 * @file		FSecPkcsPkcs08PrivateKeyInfo.h
 * @brief		This is the header file for the %Pkcs08PrivateKeyInfo class.
 *
 * This header file contains the declarations of the %Pkcs08PrivateKeyInfo class.
 */

#ifndef _FSEC_PKCS_PKCS_08_PRIVATE_KEY_INFO_H_
#define _FSEC_PKCS_PKCS_08_PRIVATE_KEY_INFO_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsAlgorithmIdentifier.h>
#include <FSecPkcsPkcs08Attribute.h>
#include <FSecPkcsPkcs08AttributeValue.h>


namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs08PrivateKeyInfo
 * @brief		This class implements the functionalities specified by the %Pkcs08PrivateKeyInfo class.
 *
 * @since		2.1
 *
 * The %Pkcs08PrivateKeyInfo class implements the functionalities specified by the %Pkcs08PrivateKeyInfo class.
 * This class represents the structure of Pkcs08 Private Key Info.
 *
 * This is defined in ASN.1 as demonstrated in the following code:
 * @code
 *				PrivateKeyInfo ::= SEQUENCE {
 *				version Version,
 *				privateKeyAlgorithm AlgorithmIdentifier {{PrivateKeyAlgorithms}},
 *				privateKey PrivateKey,
 *				attributes [0] Attributes OPTIONAL }
 * @endcode
 */

class _OSP_EXPORT_ Pkcs08PrivateKeyInfo
	: public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 */
	Pkcs08PrivateKeyInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~Pkcs08PrivateKeyInfo(void);

	/**
	 * Initializes this instance of %Pkcs08PrivateKeyInfo with the encoded byte buffer that contains  @n
	 * pkcs08 private key info structure(PrivateKeyInfo) in ASN.1 DER format. @n
	 * It parses this encoded buffer and extracts the appropriate values of private key, its algorithm ID, and attributes.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData					An instance of Tizen::Base::ByteBuffer containing DER encoded PrivateKeyInfo structure
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes this instance of %Pkcs08PrivateKeyInfo with the values of the specified input parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code.
	 * @param[in]	keyAlgorithmId			An instance of AlgorithmIdentifier holding algorithm identifier of the private key algorithm
	 * @param[in]	privateKey					An instance of Tizen::Base::ByteBuffer holding private key
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 */
	result Construct(const AlgorithmIdentifier& keyAlgorithmId, const Tizen::Base::ByteBuffer& privateKey);

	/**
	 * Gets the private key syntax version number of PrivateKeyInfo object @n
	 * that is used for storing private key and its related information and default value of this version is @c 0.
	 *
	 * @since		2.1
	 *
	 * @return		An integer value that contains the version
	 *
	 */
	int GetVersion(void) const;

	/**
	 * Gets the reference to AlgorithmIdentifier that identifies the secret key algorithm.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier that contains the algorithm identifier of the %Pkcs08PrivateKeyInfo object
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetPrivateKeyAlgorithm(void) const;

	/**
	 * Gets the reference to Tizen::Base::ByteBuffer that contains the private key in binary format.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to Tizen::Base::ByteBuffer that contains the private key of the %Pkcs08PrivateKeyInfo object
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const Tizen::Base::ByteBuffer& GetPrivateKey(void) const;

	/**
	 * Gets the attributes of the type Pkcs08Attribute that are extended information of the private key in context.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to Tizen::Base::Collection::ArrayList that contains the list of attributes of type Pkcs08Attribute
	 */
	const Tizen::Base::Collection::ArrayList& GetAttributes(void) const;

	/**
	 * Adds the attributes in private key information that is extended information of the private key in context.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	attributes					An instance of Pkcs08Attribute
	 */
	result AddAttribute(const Pkcs08Attribute& attributes);

	/**
	 * Removes the attribute in private key information that is extended information of the private key in context.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	attributes					An instance of Pkcs08Attribute
	 */
	result RemoveAttribute(const Pkcs08Attribute& attributes);	
	
	/**
	 * Gets the DER encoded %Pkcs08PrivateKeyInfo structure.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer that contains the DER encoded private key information
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
	Pkcs08PrivateKeyInfo(const Pkcs08PrivateKeyInfo& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.
	//
	// @since		2.1
	Pkcs08PrivateKeyInfo& operator =(const Pkcs08PrivateKeyInfo& rhs);

private:
	class _Pkcs08PrivateKeyInfoImpl* __pPkcs08PrivateKeyInfoImpl;
	friend class _Pkcs08PrivateKeyInfoImpl;

}; //Pkcs08PrivateKeyInfo

}}} // Tizen::Security::Pkcs

#endif // _FSEC_PKCS_PKCS_08_PRIVATE_KEY_INFO_H_
