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
 * @file	FAppPkgIPackageInstallationEventListener.h
 * @brief	This is the header file for the %IPackageInstallationEventListener interface.
 *
 * This header file contains the declarations of the %IPackageInstallationEventListener interface.
 */

#ifndef _FAPP_PKG_IPACKAGE_INSTALLATION_EVENT_LISTENER_H_
#define _FAPP_PKG_IPACKAGE_INSTALLATION_EVENT_LISTENER_H_

#include <FAppPkgPackageManager.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App { namespace Package
{
/**
 * @enum		PackageInstallationResult
 *
 * Defines the result of package installation.
 *
 * @since	2.0
 */
enum PackageInstallationResult
{
	PACKAGE_INSTALLATION_RESULT_SUCCESS = 0,				/**< Success */
	PACKAGE_INSTALLATION_RESULT_INVALID_PACKAGE,			/**< An invalid package */
	PACKAGE_INSTALLATION_RESULT_STORAGE_FULL,				/**< The installation target storage is full. */
};

/**
* @interface	IPackageInstallationEventListener
* @brief		This interface defines a listener for a package installation and uninstallation.
*
* @since	2.0
*
* The %IPackageInstallationEventListener interface defines a listener for a package installation and uninstallation.
*/
class _OSP_EXPORT_ IPackageInstallationEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IPackageInstallationEventListener(void) {}

	/**
	 * Called when a package installation is completed. @n
	 * The value of @c installationResult is @c PACKAGE_INSTALLATION_RESULT_SUCCESS if the installation is successful.
	 *
	 * @since	2.0
	 *
	 * @param[in]	packageId				The package ID
	 * @param[in]	installationResult		The installation result
	 */
	virtual void OnPackageInstallationCompleted(const PackageId& packageId, PackageInstallationResult installationResult) = 0;

	/**
	 * Called when a package uninstallation is completed. @n
	 * The value of @c uninstallationResult is @c true if the uninstallation is successful, else @c false.
	 *
	 * @since	2.0
	 *
	 * @param[in]	packageId			The package ID
	 * @param[in]	uninstallationResult		Set to @c true if the uninstallation is successful, @n
	 *											else @c false
	 */
	virtual void OnPackageUninstallationCompleted(const PackageId& packageId, bool uninstallationResult) = 0;

	/**
	 * Called when a package installation is in progress.
	 *
	 * @since	2.0
	 *
	 * @param[in]	packageId			The package ID
	 * @param[in]	progress		The progress of an installation in percentage
	 */
	virtual void OnPackageInstallationInProgress(const PackageId& packageId, int progress) = 0;


protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageInstallationEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageInstallationEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageInstallationEventListener_Reserved3(void) {}

}; // IPackageInstallationEventListener

} } } // Tizen::App::Package

#endif // _FAPP_PKG_IPACKAGE_INSTALLATION_EVENT_LISTENER_H_
