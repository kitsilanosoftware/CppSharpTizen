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
 * @file			FSecCertX509CertificatePath.h
 * @brief		This is the header file for the %X509CertificatePath class.
 *
 * This header file contains the declarations of the %X509CertificatePath class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_PATH_H_
#define _FSEC_CERT_X509_CERTIFICATE_PATH_H_

#include <FBaseObject.h>
#include <FSecCertICertificatePath.h>
#include <FSecCertX509Certificate.h>


namespace Tizen { namespace Security { namespace Cert
{

class _CertMgrSvcProxy;

/**
 *	@class		X509CertificatePath
 *	@brief		This class provides the certificate path.
 *
 *	@since		2.0
 *
 * The %X509CertificatePath class provides the certificate path. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Certificates</a>.
 */
class _OSP_EXPORT_ X509CertificatePath
	: public virtual ICertificatePath
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		2.0
	 */
	X509CertificatePath(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since		2.0
	 */
	virtual ~X509CertificatePath(void);

	/**
	 *	Gets the format name for the certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The format of the certificate
	 */
	virtual Tizen::Base::String GetFormat(void) const;

	/**
	 *	Adds a certificate to the certificate chain.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	certificate				A reference to a certificate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The certificate link list operation has failed.
	 */
	virtual result AddCertificate(const Tizen::Security::Cert::ICertificate& certificate);

	/**
	 *	Validates the specified certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The result of the certificate path validation
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *										The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ValidationResult Validate(void);

	/**
	 *	Validates the specified certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The result of the certificate path validation
	 *	@param[in]	trustAnchor				The most trusted Certificate Authority (CA)
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ValidationResult Validate(const Tizen::Security::Cert::ICertificate& trustAnchor);

	/**
	 *	Gets the length of the certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The length of the certificate path, @n
	 *				else @c -1 if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The certificate link list operation has failed.
	 */
	virtual int GetLength(void) const;

	/**
	 *	Gets the list of the certificates in this certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the ICertificate interface, @n
	 *				else @c null if an error occurs
	 *  @param[in]	nth						The nth certificate in the certificate path (starts from @c 0)
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The value of the specified @c nth is out of the valid range. @n
	 *										It must be less than GetLength().
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ICertificate* GetCertificateN(int nth) const;

	/**
	 *	Gets the trust anchor for the certificate path.
	 *
	 *	@since			2.0
	 *
	 *	@return		The root certificate, @n
	 *					else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The certificate link list operation or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ICertificate* GetTrustAnchorN(void) const;

private:
	X509CertificatePath(const X509CertificatePath& rhs);
	X509CertificatePath& operator =(const X509CertificatePath& rhs);

private:
	void* __certCtx;
	int __depth;
	int __trustAnchorIndex;

	class _X509CertificatePathImpl* __pX509CertificatePathImpl;
	friend class _X509CertificatePathImpl;

}; //X509CertificatePath

} } } //Tizen::Security::Cert

#endif //_FSEC_CERT_X509_CERTIFICATE_PATH_H_
