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
 * @file			FSecCertTypes.h
 * @brief		This is the header file for the %CertTypes definitions.
 *
 * This header file contains the %CertTypes definitions.
 */
#ifndef _FSEC_CERT_TYPES_H_
#define _FSEC_CERT_TYPES_H_

namespace Tizen { namespace Security { namespace Cert
{

/**
 * @enum ValidationResult
 *
 * Defines the validation result.
 *
 * @since		2.0
 */
enum ValidationResult
{
	VALIDATION_SUCCESS = 0,                         /**<	Success */
	VALIDATION_ERROR_INVALID_PATH,          /**<	The certificate path does not validate */
	VALIDATION_ERROR_NO_ROOT,                   /**<	The root certificate is not found */
	VALIDATION_ERROR_CERT_EXPIRED,          /**<	The certificate date falls outside the validity period */
	VALIDATION_ERROR_CERT_REVOKED,          /**<	The certificate has been revoked */
	VALIDATION_ERROR_INVALID_SIGNATURE, /**<	The signature is not valid */

}; //ValidationResult

} } } //Tizen::Security::Cert

#endif // _FSEC_CERT_TYPES_H_
