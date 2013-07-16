//
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
 * @file		FSecCertICertificate.h
 * @brief		This is the header file for the %ICertificate interface.
 *
 * This header file contains the declarations of the %ICertificate interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_H_
#define _FSEC_CERT_ICERTIFICATE_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecIPublicKey.h>

namespace Tizen { namespace Security { namespace Cert
{

/**
 * @enum CertificateType
 *
 * Defines the type of certificate.
 *
 * @since		2.0
 */
enum CertificateType
{
	ROOT_CA,                        /**< The Factory-supplied certificates for SSL: ROOT CA */
	OPERATOR_DOMAIN,                /**< The Operator Domain */
	TRUSTED_THIRD_PARTY_DOMAIN,     /**< The Trusted Third Party Domain */
	USER_CERT,                      /**< The User Certificates */
	UNKNOWN_TYPE = 10,              /**< The unknown type */
}; //CertificateType

/**
 * @enum ValidityPeriod
 *
 * Defines the validity period.
 *
 * @since		2.0
 */
enum ValidityPeriod
{
	VALIDITY_PERIOD_VALID,          /**< The validity period */
	VALIDITY_PERIOD_EXPIRED,        /**< The expiry period */
	VALIDITY_PERIOD_NOT_YET_VALID,  /**< The period that is not yet valid */
}; //ValidityPeriod

/**
 * @interface	ICertificate
 * @brief		This interface manages a variety of identity certificates.
 *
 * @since		2.0
 *
 * The %ICertificate interface is an abstraction for certificates having different formats. For example, different types of certificates, such as X.509 and PGP, share
 * general functionalities, namely encoding and verifying, and some type of information like public keys. Despite containing different sets of information and having different ways for storing, and retrieving them,
 * the X.509, X.968, and WTLS certificates can all be implemented by using the %ICertificate interface.
 *
 * An identity certificate is a binding of a principal to a public key, which is vouched for by another principal.
 * A principal represents an entity, such as an individual user, a group, or a corporation. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Certificates</a>.
 *
 * The following example demonstrates how to use the %ICertificate interface.
 *
 *
 *  @code
 *
 *  void
 *  MyCertificate::Sample(void)
 *  {
 *		X509Certificate	*pCertificate	= null;
 *		String			serialNumber;
 *		String			algorithm;
 *		String			start;
 *		String			end;
 *		String			subjectName;
 *		String			issuerName;
 *		ByteBuffer		*pSignature = null;
 *		ByteBuffer		*pFingerprint = null;
 *		ByteBuffer		input;
 *		result			r = E_FAILURE;
 *
 *		String fileName(Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/UTsSecurity/Security/Domain3Certs/TestCert1-1.der");
 *		File			file;
 *		FileAttributes	attribute;
 *
 *		r = file.Construct(fileName, L"r");
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = file.GetAttributes(fileName, attribute);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = input.Construct((int)attribute.GetFileSize());
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = file.Read(input);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		input.Flip();
 *
 *		pCertificate	= new X509Certificate;
 *		pCertificate->Construct(input);
 *
 *		serialNumber	= pCertificate->GetSerialNumber();
 *		algorithm		= pCertificate->GetSignatureAlgorithm();
 *		start			= pCertificate->GetNotBefore();
 *		end				= pCertificate->GetNotAfter();
 *		subjectName		= pCertificate->GetSubject();
 *		issuerName		= pCertificate->GetIssuer();
 *
 *		pSignature = pCertificate->GetSignatureN();
 *		if (pSignature == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pFingerprint = pCertificate->GetFingerprintN();
 *		if (pFingerprint == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = E_SUCCESS;
 *
 *	CATCH:
 *		if (pCertificate)
 *		{
 *			delete pCertificate;
 *		}
 *		if (pSignature)
 *		{
 *			delete pSignature;
 *		}
 *		if (pFingerprint)
 *		{
 *			delete pFingerprint;
 *		}
 *	}
 *
 *  @endcode
 *
 */

class _OSP_EXPORT_ ICertificate
{

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~ICertificate(void) {}

	/**
	 * Gets the format name for this certificate.
	 *
	 * @since		2.0
	 *
	 * @return		The format of this certificate
	 */
	virtual Tizen::Base::String GetFormat(void) const = 0;

	/**
	 * Gets the certificate type.
	 *
	 * @since		2.0
	 *
	 * @return		The type of this certificate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred. @n
	 *                              The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual CertificateType GetType(void) const = 0;

	/**
	 * Gets the encoded form of the certificate. @n
	 * It is assumed that each certificate type has a single form of encoding. For example, X.509 certificates can be encoded as ASN.1 DER.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The certificate link list operation or the
	 *                                  Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetEncodedDataN(void) const = 0;

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
	 *									The certificate parsing operation or
	 *									the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetFingerprintN(void) const = 0;

	/**
	 *  Verifies whether the certificate is signed using the private key corresponding to the specified public key.
	 *
	 *	@since		2.0
	 *
	 *	@return		@c true if the certificate is signed using the private key corresponding to the specified public key, @n
	 *				else @c false
	 *	@param[in]	publicKey			A reference to IPublicKey
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_ARG		The specified @c publicKey is invalid or empty.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate parsing operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool Verify(const Tizen::Security::IPublicKey& publicKey) = 0;

	/**
	 * Gets the public key of this certificate.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the IPublicKey interface, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND		The key is not found.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::IPublicKey* GetPublicKeyN(void) const = 0;

	/**
	 * Gets the @c serialNumber value from the certificate. @n
	 * The serial number is an integer assigned by the Certification Authority (CA) to each certificate. It is unique for each certificate issued by a
	 * given CA (that is, the issuer name and serial number must identify a unique certificate). @n
	 *
	 * This is defined in ASN.1 as demonstrated in the following code:
	 *
	 *	@code
	 *	serialNumber		 CertificateSerialNumber.
	 *
	 *	CertificateSerialNumber  ::=  INTEGER
	 *  @endcode
	 *
	 * Since the serial number can be greater than the system's maximum value for @c int, the output parameter type is @c ByteBuffer, instead of @c int.
	 *
	 * @since		2.0
	 *
	 * @return		The serial number of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The method has failed to get the certificate serial number information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetSerialNumber(void) const = 0;

	/**
	 * Checks whether the certificate is currently valid. @n
	 * It is valid if the current date and time are within the validity period given in the certificate. @n
	 * The validity period consists of two date and time values: the initial date and time, and the final date and time until the validity of the certificate. @n
	 *
	 * This is defined in ASN.1 as demonstrated in the following code:
	 *
	 * @code
	 * validity             Validity
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
	 * @since			2.0
	 *
	 * @return		The validity period of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual ValidityPeriod CheckValidityPeriod(void) = 0;


	/**
	 * Gets the notBefore value of Tizen::Base::String type from the validity period of the certificate. @n
	 *	This value represents the date and time before which the certificate is not valid.
	 *
	 * @since		2.0
	 *
	 * @return		A string representing the date and time value before which the certificate is not valid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The method has failed to get the certificate validity information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Security::Cert::X509Certificate::CheckValidityPeriod() for relevant ASN.1 definitions
	 */
	virtual Tizen::Base::String GetNotBefore(void) const = 0;


	/**
	 * Gets the notAfter value of Tizen::Base::String type from the validity period of the certificate. @n
	 *	This value represents the date and time after which the certificate is not valid.
	 *
	 * @since		2.0
	 *
	 * @return		A string representing the date and time value after which the certificate is not valid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The method has failed to get the certificate validity information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Security::Cert::X509Certificate::CheckValidityPeriod() for relevant ASN.1 definitions
	 */
	virtual Tizen::Base::String GetNotAfter(void) const = 0;

	/**
	 * Gets the name of the issuer of the certificate.
	 *
	 * @since		2.0
	 *
	 * @return		The name of the issuer of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  The method has failed to get the certificate issuer information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetIssuer(void) const = 0;

	/**
	 * Gets the subject name of the certificate.
	 *
	 * @since		2.0
	 *
	 * @return		The subject name of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The method has failed to get the certificate issuer information.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::String GetSubject(void) const = 0;

	/**
	 * Gets the signature of the certificate.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate link list operation or
	 *									the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetSignatureN(void) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificate_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificate_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificate_Reserved3(void) {}

}; //ICertificate

} } } //Tizen::Security::Cert

#endif //_FSEC_CERT_ICERTIFICATE_H_
