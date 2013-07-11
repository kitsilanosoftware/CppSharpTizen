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
 * @file			FSecCertICertificatePath.h
 * @brief		This is the header file for the %ICertificatePath interface.
 *
 * This header file contains the declarations of the %ICertificatePath interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_PATH_H_
#define _FSEC_CERT_ICERTIFICATE_PATH_H_

#include <FBaseString.h>
#include <FSecCertICertificate.h>
#include <FSecCertTypes.h>

namespace Tizen { namespace Security { namespace Cert
{

class ICertificatePathValidationResult;
/**
 *  @interface	ICertificatePath
 *  @brief			This interface validates the certificate path and gets more information about it.
 *
 *  @since			2.0
 *
 * The %ICertificatePath interface validates the certificate path and gets more information about it. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/certificate_namespace.htm">Certificates</a>. @n
 *
 *  The following example demonstrates how to use the %ICertificatePath interface.
 *
 *  @code
 *
 *  void
 *  MyCertificatePath::Sample(void)
 *  {
 *		X509Certificate	*pCertificate1	= null;
 *		X509Certificate	*pCertificate2	= null;
 *
 *		ICertificate    *pTrustCa = null;
 *		ByteBuffer		input1, input2;
 *		int             depth = 0;
 *		ValidationResult valResult;
 *		result			r = E_FAILURE;
 *
 *		ICertificatePath	*pCertPath	= null;
 *
 *		String fileName1(Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/UTsSecurity/Security/Domain3Certs/TestCert1-1.der");
 *		String fileName2(Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/UTsSecurity/Security/Domain3Certs/TestCert1-2.der");
 *		File			file1, file2;
 *		FileAttributes	attribute1, attribute2;
 *
 *		r = file1.Construct(fileName1, L"r");
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = file1.GetAttributes(fileName1, attribute1);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = input1.Construct((int)attribute1.GetFileSize());
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = file1.Read(input1);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		input1.Flip();
 *
 *		r = file2.Construct(fileName2, L"r");
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = file2.GetAttributes(fileName2, attribute2);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = input2.Construct((int)attribute2.GetFileSize());
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = file2.Read(input2);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		input2.Flip();
 *
 *		// Certificate1
 *		pCertificate1 = new X509Certificate;
 *		pCertificate1->Construct(input1);
 *
 *		// Certificate2
 *		pCertificate2 = new X509Certificate;
 *		pCertificate2->Construct(input2);
 *
 *		// Certificate Path
 *		pCertPath	 = new X509CertificatePath();
 *		if (pCertPath == null)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCertPath->AddCertificate(*pCertificate1);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pCertPath->AddCertificate(*pCertificate2);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *
 *		// Certificate Path Validation Result
 *		valResult = pCertPath->Validate();
 *		if (valResult != VALIDATION_SUCCESS)
 *		{
 *			goto CATCH;
 *		}
 *
 *		depth = pCertPath->GetLength();
 *		if (depth == 0)
 *		{
 *			goto CATCH;
 *		}
 *
 *		for (int i = 0; i < depth; i++)
 *		{
 *			ICertificate *pOutCert = pCertPath->GetCertificateN(i);
 *
 *			if (pOutCert)
 *			{
 *				String subjectName;
 *				subjectName = pOutCert->GetSubject();
 *			}
 *
 *			delete pOutCert;
 *		}
 *
 *		pTrustCa = pCertPath->GetTrustAnchorN();
 *		if (pTrustCa)
 *		{
 *			String subjectName;
 *			subjectName = pTrustCa->GetSubject();
 *		}
 *
 *		delete pTrustCa;
 *
 *		r = E_SUCCESS;
 *
 *	CATCH:
 *		delete pCertificate1;
 *		delete pCertificate2;
 *		delete pCertPath;
 *	}
 *
 *  @endcode
 *
 */

class _OSP_EXPORT_ ICertificatePath
{

public:
	/**
	 *	This is the destructor for this class.
	 *
	 *	@since		2.0
	 */
	virtual ~ICertificatePath(void) {}

	/**
	 *  Gets the format of the certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The format of the certificate
	 */
	virtual Tizen::Base::String GetFormat(void) const = 0;

	/**
	 *  Adds a certificate to the certificate chain.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	certificate			A reference to a certificate
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_ARG		The specified @c certificate or the certificate data is invalid.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate link list operation has failed.
	 */
	virtual result AddCertificate(const Tizen::Security::Cert::ICertificate& certificate) = 0;

	/**
	 *  Validates the specified certificate path.
	 *
	 *	@since			2.0
	 *
	 *	@return			The result of the certificate path validation
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ValidationResult Validate(void) = 0;

	/**
	 *  Validates the specified certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The result of the certificate path validation
	 *	@param[in]	trustAnchor			The most trusted Certificate Authority (CA)
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_INVALID_ARG		The specified input parameter is invalid.
	 *	@exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate link list operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ValidationResult Validate(const Tizen::Security::Cert::ICertificate& trustAnchor) = 0;

	/**
	 *	Gets the trust anchor for the certificate path.
	 *
	 *	@since			2.0
	 *
	 *	@return		The root certificate, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND		The certificate is not found.
	 *	@exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate link list operation or
	 *									the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ICertificate* GetTrustAnchorN(void) const = 0;

	/**
	 *  Gets the length of the certificate path.
	 *
	 *	@since		2.0
	 *
	 *	@return		The length of the certificate path, @n
	 *				else @c -1 if an error occurs
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate list is empty.
	 */
	virtual int GetLength(void) const = 0;

	/**
	 *	Gets the list of certificates in this certificate path.
	 *
	 *	@since			2.0
	 *
	 *	@return		A pointer to the ICertificate interface, @n
	 *				else @c null if an error occurs
	 *	@param[in]	nth					The nth certificate in the certificate path (starts from @c 0)
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_INVALID_ARG		The value of the specified @c nth is out of the valid range. @n
	 *									It must be less than GetLength().
	 *	@exception	E_OBJ_NOT_FOUND		The certificate is not found.
	 *	@exception	E_SYSTEM			A system error has occurred. @n
	 *									The certificate list is empty.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Security::Cert::ICertificate* GetCertificateN(int nth) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificatePath_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificatePath_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICertificatePath_Reserved3(void) {}

}; //ICertificatePath

} } } //Tizen::Security::Cert

#endif //_FSEC_CERT_ICERTIFICATE_PATH_H_
