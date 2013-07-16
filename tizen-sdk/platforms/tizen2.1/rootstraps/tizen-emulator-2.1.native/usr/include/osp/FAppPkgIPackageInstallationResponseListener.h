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
 * @file	FAppPkgIPackageInstallationResponseListener.h
 * @brief	This is the header file for the %IPackageInstallationResponseListener interface.
 *
 * This header file contains the declarations of the %IPackageInstallationResponseListener interface.
 *
 */
#ifndef _FAPP_PKG_IPACKAGE_INSTALLATION_RESPONSE_LISTENER_H_
#define _FAPP_PKG_IPACKAGE_INSTALLATION_RESPONSE_LISTENER_H_

#include <FAppPkgPackageManager.h>
#include <FAppPkgIPackageInstallationEventListener.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App { namespace Package
{

/**
 * @interface	IPackageInstallationResponseListener
 * @brief		This interface defines a listener for the asynchronous package installation operation.
 *
 * @since	2.0
 *
 * The %IPackageInstallationResponseListener interface defines a listener for the asynchronous package installation operation.
 *
 */
class _OSP_EXPORT_ IPackageInstallationResponseListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
     * This polymorphic destructor should be overridden if required.
     * This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since	2.0
     *
     */
	virtual ~IPackageInstallationResponseListener(void) {}

	/**
     * Called when a package installation is completed. @n
	 * The value of @c installationResult is @c PACKAGE_INSTALLATION_RESULT_SUCCESS if the installation is successful.
     *
     * @since	2.0
     *
     * @param[in]	packageId			The package ID
     * @param[in]	installationResult		The installation result
     *
     */
	virtual void OnPackageInstallationResponseReceived(const PackageId& packageId, PackageInstallationResult installationResult) = 0;

	/**
     * Called when a package installation is in progress.
     *
     * @since	2.0
     *
     * @param[in]	packageId			The package ID
     * @param[in]	progress		The progress of an installation in percentage
     *
     */
	virtual void OnPackageInstallationInProgressResponseReceived(const PackageId& packageId, int progress) = 0;


protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageInstallationResponseListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageInstallationResponseListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageInstallationResponseListener_Reserved3(void) {}

}; // IPackageInstallationResponseListener

} } } // Tizen::App::Package

#endif // _FAPP_PKG_IPACKAGE_INSTALLATION_RESPONSE_LISTENER_H_
