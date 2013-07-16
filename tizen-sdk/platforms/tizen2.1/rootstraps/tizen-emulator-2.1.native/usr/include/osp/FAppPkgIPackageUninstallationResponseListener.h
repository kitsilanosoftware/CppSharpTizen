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
  * @file	FAppPkgIPackageUninstallationResponseListener.h
 * @brief	This is the header file for the %IPackageUninstallationResponseListener interface.
 *
 * This header file contains the declarations of the %IPackageUninstallationResponseListener interface.
 *
 */
#ifndef _FAPP_PKG_IPACKAGE_UNINSTALLATION_RESPONSE_LISTENER_H_
#define _FAPP_PKG_IPACKAGE_UNINSTALLATION_RESPONSE_LISTENER_H_

#include <FAppPkgPackageManager.h>
#include <FAppPkgIPackageInstallationEventListener.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App { namespace Package
{

/**
 * @interface	IPackageUninstallationResponseListener
 * @brief		This interface defines a listener for the asynchronous package uninstallation operation.
 *
 * @since	2.0
 *
 * The %IPackageUninstallationResponseListener interface defines a listener for the asynchronous package uninstallation operation.
 *
 */
class _OSP_EXPORT_ IPackageUninstallationResponseListener
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
	virtual ~IPackageUninstallationResponseListener(void) {}

	/**
     * Called when a package uninstallation is completed. @n
	 * The value of @c uninstallationResult is @c true if the uninstallation is successful, else @c false.
     *
     * @since	2.0
     *
     * @param[in]      packageId                     The package ID
     * @param[in]      uninstallationResult          Set to @c true if the uninstallation is successful, @n
	 *                                               else @c false
     *
     */
	virtual void OnPackageUninstallationResponseReceived(const PackageId& packageId, bool uninstallationResult) = 0;


protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageUninstallationResponseListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageUninstallationResponseListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IPackageUninstallationResponseListener_Reserved3(void) {}

}; // IPackageUninstallationResponseListener

} } } // Tizen::App::Package

#endif // _FAPP_PKG_IPACKAGE_UNINSTALLATION_RESPONSE_LISTENER_H_
