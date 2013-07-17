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
 * @file		FSecCertX509CertificateStore.h
 * @brief		This is the header file for the %X509CertificateStore class.
 *
 * This header file contains the declarations of the %X509CertificateStore class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_STORE_H_
#define _FSEC_CERT_X509_CERTIFICATE_STORE_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FSecIPrivateKey.h>
#include <FSecCertICertificateStore.h>
#include <FSecCertICertificateSelector.h>

namespace Tizen { namespace Security { namespace Cert
{

class _CertMgrSvcProxy;

/**
 *	@class	X509CertificateStore
 *	@brief	This class is used for retrieving and managing certificates from a repository.
 *
 *	@since	2.0
 *
 *	The %X509CertificateStore class is used for retrieving and managing certificates from a repository.
 */
class _OSP_EXPORT_ X509CertificateStore
	: public virtual ICertificateStore
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		2.0
	 */
	X509CertificateStore(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since		2.0
	 */
	virtual ~X509CertificateStore(void);

	/**
	 *	Gets the name of the current certificate store.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.read
	 *
	 *	@return			An error code
	 *	@param[out]		name				The name of the certificate store
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	virtual result GetName(Tizen::Base::String& name) const;

	/**
	 *	Sets a list of certificates that match the specified @c selector.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.read
	 *
	 *	@return			An error code
	 *	@param[in]		selector			A selector that defines a set of criterion for selecting certificates
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception		E_SYSTEM			A system error has occurred. @n
	 *										The IPC operation has failed.
	 *	@exception		E_INVALID_ARG		The specified @c selector is invalid.
	 *	@exception		E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	virtual result SetCertificateSelector(const Tizen::Security::Cert::ICertificateSelector& selector);

	/**
	 *	Gets a count of certificates that match the specified selector.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.read
	 *
	 *	@return			An error code
	 *	@param[out]		count					The count of certificates
	 *	@exception		E_SUCCESS				The method is successful.
	 *	@exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result GetCertificateCount(int& count) const;

	/**
	 *	Gets each certificate that matches the specified selector.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.read
	 *
	 *	@return			The certificates that matches the specified selector
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception		E_OBJ_NOT_FOUND		The certificate is not found.
	 *	@exception		E_SYSTEM			A system error has occurred. @n
	 *										The Tizen::Base::ByteBuffer operation has failed.
	 *	@exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	virtual Tizen::Security::Cert::ICertificate* GetNextCertificateN(void) const;

	/**
	 *	Inserts the certificate into the certificate store.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.write
	 *
	 *	@return			An error code
	 *	@param[in]		certificateType		The type of the Certificate (ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *	@param[in]		certificate			A reference to the certificate to insert
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception		E_INVALID_ARG		The specified @c certificate or the certificate data is invalid, or
	 *										the specified @c certificateType is invalid.
	 *	@exception		E_SYSTEM			A system error has occurred. @n
	 *                                      Either the IPC operation or the file operation or the DB operation has failed.
	 *	@exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	virtual result Insert(CertificateType certificateType, const Tizen::Security::Cert::ICertificate& certificate);

	/**
	 *  Updates the certificate in the certificate store.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.write
	 *
	 *	@return			An error code
	 *	@param[in]		certificateType		The type of the Certificate (ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *	@param[in]		oldCert				A reference to the old certificate
	 *	@param[in]		newCert				A reference to the new certificate
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception		E_INVALID_ARG		The specified @c certificate or the certificate data is invalid, or
	 *										the specified @c certificateType is invalid.
	 *	@exception		E_OBJ_NOT_FOUND		The certificate is not found.
	 *	@exception		E_SYSTEM			A system error has occurred. @n
	 *                                      Either the IPC operation or the file operation or the DB operation has failed.
	 *	@exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	virtual result Update(CertificateType certificateType, const Tizen::Security::Cert::ICertificate& oldCert, const Tizen::Security::Cert::ICertificate& newCert);

	/**
	 *  Removes the certificate from the certificate store.
	 *
	 *	@since			2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.write
	 *
	 *	@return			An error code
	 *	@param[in]		certificateType		The type of the Certificate (ROOT_CA, OPERATOR_DOMAIN, TRUSTED_THIRD_PARTY_DOMAIN)
	 *	@param[in]		certificate			A reference to the certificate to remove
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception		E_INVALID_ARG		The specified @c certificate or the certificate data is invalid, or
	 *										the specified @c certificateType is invalid.
	 *	@exception		E_OBJ_NOT_FOUND		The certificate is not found.
	 *	@exception		E_SYSTEM			A system error has occurred. @n
	 *                                      Either the IPC operation or the file operation or the DB operation has failed.
	 *	@exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	virtual result Remove(CertificateType certificateType, const Tizen::Security::Cert::ICertificate& certificate);

	/**
	 *  Inserts the user certificate of PKCS 12 format into the certificate store.
	 *
	 *	@since 2.0
	 *
	 *	@privlevel		partner
	 *	@privilege		%http://tizen.org/privilege/certificate.write
	 *
	 *	@return			An error code
	 *  @param[in]		filePath			The file path of PKCS 12 certificate to insert
	 *  @param[in]		password			The password string to decrypt PKCS 12 certificate
	 *	@exception		E_SUCCESS			The method is successful.
	 *	@exception		E_INVALID_ARG		The specified @c certificate or the certificate data is invalid.
	 *	@exception		E_SYSTEM			The method cannot proceed due to a severe system error.
	 *	@exception		E_DATA_NOT_FOUND	A root CA certificate does not exist.
	 *	@exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result InsertPkcs12(const Tizen::Base::String& filePath, const Tizen::Base::String& password);

private:
	X509CertificateStore(const X509CertificateStore& rhs);
	X509CertificateStore& operator =(const X509CertificateStore& rhs);

private:
	class _X509CertificateStoreImpl* __pX509CertificateStoreImpl;
	friend class _X509CertificateStoreImpl;

}; //X509CertificateStore

} } } //Tizen::Security::Cert

#endif //_FSEC_CERT_X509_CERTIFICATE_STORE_H_
