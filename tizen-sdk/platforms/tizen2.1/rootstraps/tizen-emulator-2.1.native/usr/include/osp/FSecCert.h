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
 * @file			FSecCert.h
 * @brief		This is the header file for the %Cert namespace.
 *
 * This header file contains the declarations and descriptions of the %Cert namespace.
 */
#ifndef _FSEC_CERT_H_
#define _FSEC_CERT_H_

#include <FSecCertICertificate.h>
#include <FSecCertICertificatePath.h>
#include <FSecCertICertificateSelector.h>
#include <FSecCertICertificateStore.h>
#include <FSecCertX509Certificate.h>
#include <FSecCertX509CertificatePath.h>
#include <FSecCertX509CertificateSelector.h>
#include <FSecCertX509CertificateStore.h>


/**
 * @namespace	Tizen::Security::Cert
 * @brief		This namespace contains classes and interfaces for managing the X.509 digital certificate.
 * @since		2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FSecurity.h> @n
 *				@b Library : @b osp-appfw
 *
 * The %Cert namespace contains classes and interfaces for managing certificates, by getting information from security certificates and validating their paths. @n
 *
 * For more information on the %Cert namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Cert Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Cert namespace.
 * @image html security_cert_classdiagram.png
 *
 */
namespace Tizen { namespace Security { namespace Cert
{

} } } //Tizen::Security::Cert

#endif // _FSEC_CERT_H_
