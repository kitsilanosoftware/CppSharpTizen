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
 * @file		FSecPkcsPkcs05Schemes.h
 * @brief		This is the header file for the %Pkcs05Schemes class.
 *
 * This header file contains the declarations of the %Pkcs05Schemes class.
 */

#ifndef _FSEC_PKCS_PKCS_05_SCHEMES_H_
#define _FSEC_PKCS_PKCS_05_SCHEMES_H_

#include <FBaseByteBuffer.h>
#include <FSecPkcsPkcs05PbKdf2Parameters.h>
#include <FSecPkcsPkcs05PbEs2Parameters.h>
#include <FSecPkcsPkcs05PbMacParameters.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
  * @class		Pkcs05Schemes
  * @brief		This class implements the functionalities specified by the pkcs05 schemes like key derivation function,
  *						encryption and signature schemes.
  *
  * @since		2.1
  *
  * The %Pkcs05Schemes class implements the functionalities specified by the pkcs05 schemes like key derivation function,
  *						encryption and signature schemes.
  */

class _OSP_EXPORT_ Pkcs05Schemes
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	Pkcs05Schemes(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~Pkcs05Schemes(void);

	/**
	 * Initializes this instance of %Pkcs05Schemes with the values of the specified input parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	password					An instance of Tizen::Base::ByteBuffer holding the password
	 * @param[in]	derivedKeyLength	A positive integer that contains the length of derived key @n
	 *															It is a variable length in PbEs2 based on the underlying encryption operation.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& password, int derivedKeyLength);

	/**
	 * Generates the password based derived key using the PBKDF2 scheme. @n
	 * The length of the derived key is essentially unbounded. However, the maximum effective search space for
	 * the derived key may be limited by the structure of the underlying pseudo random function.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer that contains the derived key, @n
	 *				else @c null if an error occurs
	 * @param[in]	params						An instance of PbKdf2Parameters containing the Kdf2 parameter,
	 *															salt value, iteration count, and key length
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GenerateKeyKdf2N(const Pkcs05PbKdf2Parameters& params);

	/**
	 * Encrypts the message M under a password P to produce a ciphertext C, by applying selected key derivation function KDF
	 * (which is GenerateKeyKdf2N) and selected underlying encryption scheme (which can be any block chiper).
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer that contains the encrypted message, @n
	 *				else @c null if an error occurs
	 * @param[in]	params						An instance of the PbEs2Parameters parameter structure holding AlgorithmIdentifier for key derivation
	 *															function and AlgorithmIdentifier for underlying encryption scheme
	 * @param[in]	message						An instance of Tizen::Base::ByteBuffer holding the plain text to encrypt
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* EncryptionScheme2N(const Pkcs05PbEs2Parameters& params, const Tizen::Base::ByteBuffer& message);

	/**
	 * Decrypts the ciphertext C, under a password P to recover message M , by applying selected key derivation function KDF(which is GenerateKeyKdf2N)
	 * and selected underlying decryption algorithm (which can be any block cipher).
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer that contains the plain text message
	 * @param[in]	params						An instance of the PbEs2Parameters parameter structure holding AlgorithmIdentifier for key derivation
	 *															function and AlgorithmIdentifier for underlying encryption scheme
	 * @param[in]	message						An instance of Tizen::Base::ByteBuffer holding the cipher text to decrypt
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* DecryptionScheme2N(const Pkcs05PbEs2Parameters& params, const Tizen::Base::ByteBuffer& message);

	/**
	 * Gets a message M under a password P to generate a message authentication code T,
	 * by applying selected key derivation function KDF(which is GenerateKeyKdf2N) and selected underlying message authentication scheme
	 * (which can be any HMAC algorithm). @n GenerateMacN combines a password-based key derivation function, which shall be
	 * GenerateKeyKdf2N for this version of PKCS #5, with an underlying message authentication scheme
	 * The key length and any other parameters for the underlying message authentication scheme
	 * depend on the scheme.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to Tizen::Base::ByteBuffer containing the HMAC generated from message, @n
	 *				else @c null if an error occurs
	 * @param[in]	params						An instance of the PbMacParameters parameter structure holding AlgorithmIdentifier for key derivation
	 *															function and AlgorithmIdentifier for underlying encryption scheme
	 * @param[in]	message						An instance of Tizen::Base::ByteBuffer holding the message for which MAC needs to generate
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetPbHMacN(const Pkcs05PbMacParameters& params, const Tizen::Base::ByteBuffer& message);

	/**
	 * Verifies a message M under a password P to verify a message authentication code T,
	 * by applying a selected key derivation function KDF2 and a selected underlying message authentication scheme combines a
	 * password-based key derivation function, which shall be GenerateKeyKdf2N for this version of PKCS #5, with an underlying
	 * message authentication scheme (which can be any SHA-1 or any SHA-2 algorithm). @n The key length and any other parameters
	 * for the underlying message authentication scheme depend on the scheme.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	params							An instance of the PbMacParameters parameter structure holding AlgorithmIdentifier for key derivation
	 *																function and AlgorithmIdentifier for underlying encryption scheme
	 * @param[in]	message							An instance of Tizen::Base::ByteBuffer holding the message M
	 * @param[in]	mac									An instance of Tizen::Base::ByteBuffer holding the HMAC mac that needs to verify against the message
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM						The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	result VerifyPbMac(const Pkcs05PbMacParameters& params, const Tizen::Base::ByteBuffer& message, const Tizen::Base::ByteBuffer& mac);

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Pkcs05Schemes(const Pkcs05Schemes& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.
	//
	// @since		2.1
	Pkcs05Schemes& operator =(const Pkcs05Schemes& rhs);

private:
	class _Pkcs05SchemesImpl* __pPkcs05SchemesImpl;
	friend class _Pkcs05SchemesImpl;

}; //Pkcs05Schemes

} } } // Tizen::Security::Pkcs

#endif //_FSEC_PKCS_PKCS_05_SCHEMES_H_
