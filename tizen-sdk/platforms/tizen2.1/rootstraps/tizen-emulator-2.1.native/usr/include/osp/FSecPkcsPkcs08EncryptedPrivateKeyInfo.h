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
 * @file		FSecPkcsPkcs08EncryptedPrivateKeyInfo.h
 * @brief		This is the header file for the %Pkcs08EncryptedPrivateKeyInfo class.
 *
 * This header file contains the declarations of the %Pkcs08EncryptedPrivateKeyInfo class.
 */

#ifndef _FSEC_PKCS_PKCS_08_ENCRYPTED_PRIVATE_KEY_INFO_H_
#define _FSEC_PKCS_PKCS_08_ENCRYPTED_PRIVATE_KEY_INFO_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsAlgorithmIdentifier.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs08EncryptedPrivateKeyInfo
 * @brief		This class provides methods to encrypt a private key.
 *
 * @since		2.1
 *
 * The %Pkcs08EncryptedPrivateKeyInfo class provides methods to encrypt a private key. An encrypted private key structure consist
 *					of an encryption algorithm and the encrypted Pkcs08PrivateKeyInfo.
 *
 *				This is defined in ASN.1 as demonstrated in the following code:
 * @code
 *				EncryptedPrivateKeyInfo ::= SEQUENCE {
 *				encryptionAlgorithm AlgorithmIdentifier {{KeyEncryptionAlgorithms}},
 *				encryptedData EncryptedData
 *				}
 * @endcode
 */

class _OSP_EXPORT_ Pkcs08EncryptedPrivateKeyInfo
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 */
	Pkcs08EncryptedPrivateKeyInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~Pkcs08EncryptedPrivateKeyInfo(void);

	/**
	 * Initializes this instance of %Pkcs08EncryptedPrivateKeyInfo with the encoded Tizen::Base::ByteBuffer that contains  @n
	 * the EncryptedPrivateKeyInfo structure(EncryptedPrivateKeyInfo) in ASN.1 DER format.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData					The DER encoded Tizen::Base::ByteBuffer that contains the Pkcs08 EncryptedPrivateKeyInfo structure
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes this instance of %Pkcs08EncryptedPrivateKeyInfo with the values of the specified input parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	algorithmId					An instance of AlgorithmIdentifier
	 * @param[in]	encryptedData				An encrypted private key
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 */
	result Construct(const AlgorithmIdentifier& algorithmId, const Tizen::Base::ByteBuffer& encryptedData);

	/**
	 * Initializes this instance of %Pkcs08EncryptedPrivateKeyInfo with the values of the specified input parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	algorithmId						An instance of AlgorithmIdentifier that identifies the secret key algorithm
	 * @param[in]	key										The key for encrypting privateKeyInfo
	 * @param[in]	encodedPrivateKeyInfo	An instance of Tizen::Base::ByteBuffer containing encoded privateKeyInfo
	 * @exception	E_SUCCESS							The method is successful.
	 * @exception	E_INVALID_ARG					A specified input parameter is invalid.
	 *
	 */
	result Construct(const AlgorithmIdentifier& algorithmId, const Tizen::Base::ByteBuffer& key, const Tizen::Base::ByteBuffer& encodedPrivateKeyInfo);

	/**
	 * Gets a reference to AlgorithmIdentifier that identifies the encryption algorithm under which the private key is encrypted.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to AlgorithmIdentifier that contains the algorithm identifier of %Pkcs08EncryptedPrivateKeyInfo object
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const AlgorithmIdentifier& GetAlgorithm(void) const;

	/**
	 * Gets a pointer to Tizen::Base::ByteBuffer that contains the encrypted private key.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer class that contains the private key of the %Pkcs08EncryptedPrivateKeyInfo object, @n
	 *				else @c null if an error occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncryptedDataN(void) const;

	/**
	 * Decrypts the %Pkcs08EncryptedPrivateKeyInfo object using a key or password.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer that contains the decrypted private key of the %Pkcs08EncryptedPrivateKeyInfo object, @n
	 *				else @c null if an error occurs
	 * @param[in]	key				An instance of Tizen::Base::ByteBuffer holding a key to decrypt the private key using a particular @n
	 *											secret key algorithm
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_SYSTEM						The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* DecryptN(const Tizen::Base::ByteBuffer& key);

	/**
	 * Gets the ASN.1 DER encoded pkcs08 encrypted private key structure.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
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
	Pkcs08EncryptedPrivateKeyInfo(const Pkcs08EncryptedPrivateKeyInfo& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.
	//
	// @since		2.1
	Pkcs08EncryptedPrivateKeyInfo& operator =(const Pkcs08EncryptedPrivateKeyInfo& rhs);

private:
	class _Pkcs08EncryptedPrivateKeyInfoImpl* __pPkcs08EncryptedPrivateKeyInfoImpl;
	friend class _Pkcs08EncryptedPrivateKeyInfoImpl;


}; //Pkcs08EncryptedPrivateKeyInfo

}}} // Tizen::Security::Pkcs

#endif // _FSEC_PKCS_PKCS_08_ENCRYPTED_PRIVATE_KEY_INFO_H_
