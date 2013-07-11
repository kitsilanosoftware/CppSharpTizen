//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file			FSecCertX509Certificate.h
 * @brief		This is the header file for the %X509Certificate class.
 *
 * This header file contains the declarations of the %X509Certificate class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_H_
#define _FSEC_CERT_X509_CERTIFICATE_H_

#include <FBase.h>
#include <FSecCertICertificate.h>

namespace Tizen { namespace Security { namespace Cert
{

/**
 * @class	X509Certificate
 * @brief	This class is used for managing a variety of identity certificates.
 *
 * @since	2.0
 *
 * The %X509Certificate class is used for managing a variety of identity certificates. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Certificates</a>.
 *
 * @see		ICertificate
 */
class _OSP_EXPORT_ X509Certificate
	: public virtual ICertificate
	, public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	X509Certificate(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~X509Certificate(void);

	/**
	 * Initializes this instance of %X509Certificate with the specified input buffer.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	input				An instance of Tizen::Base::ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The Tizen::Base::ByteBuffer operation has failed.
	 */
	result Construct(const Tizen::Base::ByteBuffer& input);

	/**
	 * Gets the format name for this certificate.
	 *
	 * @since		2.0
	 *
	 * @return		The format of this certificate
	 */
	virtual Tizen::Base::String GetFormat(void) const;

	/**
	 * Gets the certificate type.
	 *
	 * @since		2.0
	 *
	 * @return		The certificate type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual CertificateType GetType(void) const;

	/**
	 * Gets the encoded form of the certificate. @n
	 * It is assumed that each certificate type will have only a single form of encoding. For example, X.509 certificates will be encoded as ASN.1 DER.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate link list operation or
	 *                                  the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

	/**
	 * Gets the fingerprint of the certificate. @n
	 * It is the hashed value of the encoding of the certificate.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate parsing operation or
	 *                                  the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetFingerprintN(void) const;

	/**
	 * Verifies whether the certificate is signed using the private key that corresponds to the specified public key.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the certificate is signed using the private key that corresponds to the specified public key, @n
	 *				else @c false
	 * @param[in]	publicKey			A reference to IPublicKey
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c publicKey is invalid or empty.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate parsing operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Verify(const Tizen::Security::IPublicKey& publicKey);

	/**
	 * Gets the public key of this certificate.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to IPublicKey, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND		The key is not found.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::IPublicKey* GetPublicKeyN(void) const;

	// (X.509 only, that is, not inherited from the ICertificate interface)
	/**
	 * Gets the specification version value (version number) from the certificate. @n
	 *
	 * The ASN.1 definition for this is as follows:
	 *
	 * @code
	 * version  [0] EXPLICIT Version DEFAULT v1
	 * Version ::=  INTEGER  {  v1(0), v2(1), v3(2)  }
	 * @endcode
	 *
	 * @since		2.0
	 *
	 * @return		The version number of the X.509 certificate (that is, 1, 2, or 3)
	 */
	int GetSpecVersion(void) const;

	/**
	 * Gets the serial number value from the certificate. @n
	 * The serial number is an integer assigned by the Certification Authority (CA) to each certificate. It is unique for each certificate issued by a given
	 * CA (that is, the issuer name and serial number must identify a unique certificate). @n
	 *
	 * The ASN.1 definition for this is as follows:
	 *
	 * @code
	 * serialNumber     CertificateSerialNumber
	 *
	 * CertificateSerialNumber  ::=  INTEGER
	 * @endcode
	 *
	 * This serial number can be greater than the system's maximum defined value for @c int, the output parameter type is @c ByteBuffer, instead of @c int.
	 *
	 * @since			2.0
	 *
	 * @return		The serial number of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetSerialNumber(void) const;

	/**
	 * Checks whether the certificate is currently valid. @n
	 * It is valid if the current date and time are within the validity period given in the certificate. The validity period consists of two date and time
	 * values: the initial date and time, and the final date and time until the validity of the certificate. @n
	 *
	 * It is defined in ASN.1 as:
	 *
	 *  @code
	 *	validity             Validity
	 *
	 *	Validity ::= SEQUENCE {
	 *		notBefore      CertificateValidityDate,
	 *		notAfter       CertificateValidityDate }
	 *
	 *	CertificateValidityDate ::= CHOICE {
	 *		utcTime        UTCTime,
	 *		generalTime    GeneralizedTime }
	 *  @endcode
	 *
	 * @since		2.0
	 *
	 * @return		The validity period of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual ValidityPeriod CheckValidityPeriod(void);

	/**
	 *  Gets the notBefore value of @c String type from the validity period of the certificate. @n
	 *	This value represents the date and time before which the certificate is not valid.
	 *
	 * @since			2.0
	 *
	 * @return		A string representing the date and time value before which the certificate is not valid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The method has failed to get the certificate validity information.
	 * @see			Tizen::Security::Cert::X509Certificate::CheckValidityPeriod(void) for relevant ASN.1 definitions.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetNotBefore(void) const;


	/**
	 *	Gets the notAfter value of @c String type from the validity period of the certificate. @n
	 *	This value represents the date and time after which the certificate is not valid.
	 *
	 * @since			2.0
	 *
	 * @return		A string representing the date and time value after which the certificate is not valid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The method has failed to get the certificate validity information.
	 * @see			Tizen::Security::Cert::X509Certificate::CheckValidityPeriod(void) for relevant ASN.1 definitions.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetNotAfter(void) const;

	/**
	 * Gets the name of the issuer of the certificate.
	 *
	 * @since			2.0
	 *
	 * @return		The name of the issuer of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The method has failed to get the certificate issuer information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetIssuer(void) const;

	/**
	 * Gets the subject name of the certificate.
	 *
	 * @since			2.0
	 *
	 * @return		The subject name of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The method has failed to get the certificate issuer information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetSubject(void) const;

	/**
	 * Gets the signature algorithm identifier from the given certificate. @n
	 * For example, the string "SHA-1/DSA". @n
	 *
	 * The ASN.1 definition for this is as follows:
	 *
	 *  @code
	 *	signatureAlgorithm   AlgorithmIdentifier
	 *		AlgorithmIdentifier  ::=  SEQUENCE  {
	 *		algorithm               OBJECT IDENTIFIER,
	 *		parameters              ANY DEFINED BY algorithm OPTIONAL  }
	 *  @endcode
	 *
	 * The algorithm name is determined from the algorithm OID string.
	 *
	 * @since			2.0
	 *
	 * @return		The signature algorithm of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetSignatureAlgorithm(void) const;

	/**
	 * Gets the signature of the certificate.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *					else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate link list operation or
	 *                                  the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetSignatureN(void) const;

private:
	X509Certificate(const X509Certificate& rhs);
	X509Certificate& operator =(const X509Certificate& rhs);

private:
	void* __certHandle;
	Tizen::Base::String __certFormat;
	class _X509CertificateImpl* __pX509CertificateImpl;
	friend class _X509CertificateImpl;

}; //X509Certificate

} } } //Tizen::Security::Cert

#endif // _FSEC_CERT_X509_CERTIFICATE_H_
