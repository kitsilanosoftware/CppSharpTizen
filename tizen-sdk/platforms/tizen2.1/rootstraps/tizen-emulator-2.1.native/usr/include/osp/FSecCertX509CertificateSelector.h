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
 * @file			FSecCertX509CertificateSelector.h
 * @brief		This is the header file for the %X509CertificateSelector class.
 *
 * This header file contains the declarations of the %X509CertificateSelector class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_SELECTOR_H_
#define _FSEC_CERT_X509_CERTIFICATE_SELECTOR_H_

#include <FSecCertICertificateSelector.h>


namespace Tizen { namespace Security { namespace Cert
{

/**
 *	@class		X509CertificateSelector
 *	@brief		This class is used for managing a variety of identity certificates.
 *
 *	@since		2.0
 *
 * The %X509CertificateSelector class is a selector that defines a set of criterion for selecting certificates. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Certificates</a>.
 *
 *  @see		ICertificate
 *  @see		Tizen::Security::Cert::ICertificateSelector
 */
class _OSP_EXPORT_ X509CertificateSelector
	: public virtual ICertificateSelector
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the constructor for this class.
	 *
	 *	@since		2.0
	 */
	X509CertificateSelector(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since		2.0
	 */
	virtual ~X509CertificateSelector(void);

	/**
	 *	Gets the certificate type.
	 *
	 *	@since		2.0
	 *
	 * @return  The certificate type
	 */
	virtual CertificateType GetType(void) const;

	/**
	 * Sets the certificate type.
	 *
	 *	@since		2.0
	 *
	 * @param[in]	certificateType		The certificate type
	 */
	virtual void SetType(CertificateType certificateType);

private:
	X509CertificateSelector(const X509CertificateSelector& rhs);
	X509CertificateSelector& operator =(const X509CertificateSelector& rhs);

private:
	CertificateType __certType;

	class _X509CertificateSelectorImpl* __pX509CertificateSelectorImpl;
	friend class _X509CertificateSelectorImpl;

}; // X509CertificateSelector

} } } // Tizen::Security::Cert

#endif // _FSEC_CERT_X509_CERTIFICATE_SELECTOR_H_
