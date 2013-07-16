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
 * @file		FSecCertICertificateSelector.h
 * @brief		This is the header file for the %ICertificateSelector interface.
 *
 * This header file contains the declarations of the %ICertificateSelector interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_SELECTOR_H_
#define _FSEC_CERT_ICERTIFICATE_SELECTOR_H_

#include <FSecCertICertificate.h>


namespace Tizen { namespace Security { namespace Cert
{

/**
 *  @interface	ICertificateSelector
 *  @brief			This interface is a selector that defines a set of criterion for selecting certificates.
 *
 *	@since			2.0
 *
 * The %ICertificateSelector interface is a selector that defines a set of criterion for selecting certificates.
 *	The classes that implement this interface are used to specify the certificates, which must be retrieved from a certificate store. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Certificates</a>.
 *
 */
class _OSP_EXPORT_ ICertificateSelector
{

public:
	/**
	 *	This is the destructor for this class.
	 *
	 *	@since		2.0
	 */
	virtual ~ICertificateSelector(void) {}

	/**
	 *	Gets the certificate type.
	 *
	 *	@since		2.0
	 *
	 *	@return		The certificate type
	 */
	virtual CertificateType GetType(void) const = 0;

	/**
	 * Sets the certificate type.
	 *
	 * @since	2.0
	 *
	 * @param[in]	certificateType		The certificate type
	 */
	virtual void SetType(CertificateType certificateType) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificateSelector_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificateSelector_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificateSelector_Reserved3(void) {}

}; // ICertificateSelector

} } } // Tizen::Security::Cert

#endif // _FSEC_CERT_ICERTIFICATE_SELECTOR_H_
