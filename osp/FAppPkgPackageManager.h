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
 * @file	FAppPkgPackageManager.h
 * @brief	This is the header file for the %PackageManager class.
 *
 * This header file contains the declarations of the %PackageManager class.
 */

#ifndef _FAPP_PKG_PACKAGE_MANAGER_H_
#define _FAPP_PKG_PACKAGE_MANAGER_H_

#include <FBase.h>
#include <FAppTypes.h>

namespace Tizen { namespace App { namespace Package
{

class PackageInfo;
class PackageAppInfo;
class IPackageInstallationEventListener;
class IPackageInstallationResponseListener;
class IPackageUninstallationResponseListener;


/**
 * @class		PackageManager
 * @brief		This class gets the information of packages and manages package installation or uninstallation.
 *
 * @since	2.0
 *
 * @final		This class is not intended for extension.
 *
 * The %PackageManager class provides methods to install or uninstall the packages, retrieves the information of the packages that are installed on the device.
 */
class _OSP_EXPORT_ PackageManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the package ID from the application ID.
	 *
	 * @since	2.0
	 *
	 * @return		The package ID, @n
	 *				else @c packageId.IsEmtpy() == true is returned if an error occurs
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static PackageId GetPackageIdByAppId(const AppId& appId);

	/**
	 * Adds a package installation event listener.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/packageinfo
	 *
	 * @return		An error code
	 * @param[in]	listener			The package installation event listener
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result AddPackageInstallationEventListener(IPackageInstallationEventListener& listener);

	/**
	 * Removes a package installation event listener.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/packageinfo
	 *
	 * @return		An error code
	 * @param[in]	listener			The package installation event listener
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The listener is not added or is already removed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result RemovePackageInstallationEventListener(IPackageInstallationEventListener& listener);

	/**
	 * Gets a package information with the specific package ID.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/packageinfo
	 *
	 * @return		A pointer to PackageInfo
	 * @param[in]	packageId				The package ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PKG_NOT_INSTALLED		The package is not installed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::App::Package::PackageInfo* GetPackageInfoN(const PackageId& packageId) const;

	/**
	 * Gets the application information with the specific application ID.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/packageinfo
	 *
	 * @return		A pointer to PackageAppInfo
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::App::Package::PackageAppInfo* GetPackageAppInfoN(const AppId& appId) const;

	/**
	 * Gets the package information list.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/packageinfo
	 *
	 * @return		A pointer to the list of the PackageInfo instances, @n
	 * 				else @c null if it fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetPackageInfoListN(void) const;

	/**
	 * Checks whether a package is installed.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/packageinfo
	 *
	 * @return	@c true if a package is installed, @n
	 * 			else @c false
	 * @param[in]	packageId				The package ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsPackageInstalled(const PackageId& packageId) const;

	/**
	 * Gets the package manager instance.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the %PackageManager instance, @n
	 *				else @c null
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static PackageManager* GetInstance(void);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	PackageManager(void);

	/**
	 * This destructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~PackageManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	PackageManager(const PackageManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	PackageManager& operator =(const PackageManager& rhs);

private:
	class _PackageManagerImpl* __pPackageManagerImpl;
	friend class _PackageManagerImpl;

}; // PackageManager

} } } // Tizen::App::Package

#endif // _FAPP_PKG_PACKAGE_MANAGER_H_
