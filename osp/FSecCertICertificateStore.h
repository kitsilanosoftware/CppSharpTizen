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
 * @file			FSecCertICertificateStore.h
 * @brief		This is the header file for the %ICertificateStore interface.
 *
 * This header file contains the declarations of the %ICertificateStore interface.
 *
 */
#ifndef _FSEC_CERT_ICERTIFICATE_STORE_H_
#define _FSEC_CERT_ICERTIFICATE_STORE_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecIPrivateKey.h>
#include <FSecCertICertificate.h>
#include <FSecCertICertificateSelector.h>


namespace Tizen { namespace Security { namespace Cert
{

/**
 *	@interface	ICertificateStore
 *	@brief		This is the interface for retrieving and managing the certificates from a repository.
 *
 *	@since		2.0
 *
 *	The %ICertificateStore interface is used for retrieving and managing the certificates from a repository.
 */
class _OSP_EXPORT_ ICertificateStore
{

public:
	/**
	 *	This is the destructor for this class.
	 *
	 *	@since		2.0
	 */
	virtual ~ICertificateStore(void) {}

	/**
	 *  Gets the @c name of the certificate store.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[out]	name					The name of the certificate store
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result GetName(Tizen::Base::String& name) const = 0;

	/**
	 *	Sets a list of certificates that match the specified selector.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	selector				A selector that defines a set of criterion for selecting certificates
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The IPC operation has failed.
	 *	@exception	E_INVALID_ARG			The specified @c selector is invalid.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result SetCertificateSelector(const Tizen::Security::Cert::ICertificateSelector& selector) = 0;

	/**
	 *	Gets the count of certificates that match the specified selector.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[out] count					The count of certificates
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result GetCertificateCount(int& count) const = 0;

	/**
	 *	Gets each certificate that matches the specified selector.
	 *
	 *	@since		2.0
	 *
	 *	@return		The certificates that match the specified selector
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The Tizen::Base::ByteBuffer operation has failed.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *  @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ICertificate* GetNextCertificateN(void) const = 0;

	/**
	 *  Inserts the certificate into the certificate store.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	certificateType			The type of the Certificate (that is, ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *	@param[in]	certificate				A reference to the certificate to insert
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid, or
	 *										the specified @c certificateType is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *                                      Either the IPC operation or the file operation or the DB operation has failed.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result Insert(CertificateType certificateType, const Tizen::Security::Cert::ICertificate& certificate) = 0;

	/**
	 *  Updates the certificate in the certificate store.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	certificateType			The type of the Certificate (that is, ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *	@param[in]	oldCert					A reference to the old certificate
	 *	@param[in]	newCert					A reference to the new certificate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid, or
	 *											the specified @c certificateType is invalid.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *                                      Either the IPC operation or the file operation or the DB operation has failed.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result Update(CertificateType certificateType, const Tizen::Security::Cert::ICertificate& oldCert, const Tizen::Security::Cert::ICertificate& newCert) = 0;

	/**
	 *  Removes the certificate from the certificate store.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	certificateType			The type of the Certificate (that is, ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *	@param[in]	certificate				A reference to the certificate to remove
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid, or
	 *											the specified @c certificateType is invalid.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *                                      Either the IPC operation or the file operation or the DB operation has failed.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result Remove(CertificateType certificateType, const Tizen::Security::Cert::ICertificate& certificate) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificateStore_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificateStore_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificateStore_Reserved3(void) {}

}; //ICertificateStore

} } } //Tizen::Security::Cert

#endif //_FSEC_CERT_ICERTIFICATE_STORE_H_
