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
 * @enum PackageType
 *
 * Defines the package types.
  *
 * @since	2.0
 */
enum PackageType
{
	PACKAGE_TYPE_TPK,			/**< TIZEN Native package */
	PACKAGE_TYPE_WGT,			/**< TIZEN %Web package */
	PACKAGE_TYPE_RPM,			/**< TIZEN Core package */
};

/**
 * @class		PackageManager
 * @brief		This class gets the information of packages and manages package installation or uninstallation.
 *
 * @since	2.0
 *
 * @final		This class is not intended for extension.
 *
 * The %PackageManager class provides methods to install or uninstall the packages, retrieves the information of the packages that are installed on the device.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/package_namespace.htm">Package Management</a>.
 *
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
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/package.info @n
	 * 					 (%http://tizen.org/privilege/packageinfo is deprecated.)
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
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/package.info @n
	 * 					 (%http://tizen.org/privilege/packageinfo is deprecated.)
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
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/package.info @n
	 * 					 (%http://tizen.org/privilege/packageinfo is deprecated.)
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
	PackageInfo* GetPackageInfoN(const PackageId& packageId) const;

	/**
	 * Gets the application information with the specific application ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/package.info @n
	 * 					 (%http://tizen.org/privilege/packageinfo is deprecated.)
	 *
	 * @return		A pointer to PackageAppInfo
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	PackageAppInfo* GetPackageAppInfoN(const AppId& appId) const;

	/**
	 * Gets the package information list.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/package.info @n
	 * 					 (%http://tizen.org/privilege/packageinfo is deprecated.)
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
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/package.info @n
	 * 					 (%http://tizen.org/privilege/packageinfo is deprecated.)
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
	 * Installs a package. @n
	 * The %InstallPackage() method operates asynchronously, that is, it ends immediately without an installation response. The application is notified when the installation is completed, so the response is available through the IPackageInstallationResponseListener::OnPackageInstallationCompleted() method, if this method returns @c E_SUCCESS.
	 *
	 * @since	2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/packagemanager.install
	 *
	 * @return		An error code
	 * @param[in]	packageId			The package ID
	 * @param[in]	packagePath			The package path
	 * @param[in]	pListener			The response listener
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		A listener instance ownership is transferred to the platform. After notifying result, the listener instance is removed automatically. A reuse of the listener instance is not allowed.
	 * @see			IPackageInstallationResponseListener
	 */
	result InstallPackage(const PackageId& packageId, const Tizen::Base::String& packagePath, IPackageInstallationResponseListener* pListener);

	/**
	 * Uninstalls a package with the specified package ID. @n
	 * The %UninstallPackage() method operates asynchronously, that is, it ends immediately without an uninstallation response. The application is notified when the uninstallation is completed, so the response is available through the IPackageUninstallationResponseListener::OnPackageUninstallationCompleted() method, if this method returns @c true.
	 *
	 * @since	2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/packagemanager.install
	 *
	 * @return		An error code
	 * @param[in]	packageId				The package ID
	 * @param[in]	pListener				The response listener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @exception	E_PKG_NOT_INSTALLED		The package is not installed.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		A listener instance ownership is transferred to the platform. After notifying result, the listener instance is removed automatically. A reuse of the listener instance is not allowed.
	 * @see			IPackageUninstallationResponseListener
	 */
	result UninstallPackage(const PackageId& packageId, IPackageUninstallationResponseListener* pListener);

	/**
	 *  Moves a package with the specified package ID to an external storage.
	 *
	 * @since	2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/packagemanager.setting @n
	 * 					 (%http://tizen.org/privilege/packagesetting is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	packageId				The package ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION		The package is already installed in an external storage.
	 * @exception	E_STORAGE_FULL			The storage is full.
	 * @exception	E_PKG_NOT_INSTALLED		The package is not installed.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result MoveToExternalStorage(const PackageId& packageId);

	/**
	 * Moves a package with the specified package ID to an internal storage.
	 *
	 * @since	2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/packagemanager.setting @n
	 * 					 (%http://tizen.org/privilege/packagesetting is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	packageId				The package ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION		The package is already installed in an internal storage.
	 * @exception	E_STORAGE_FULL			The storage is full.
	 * @exception	E_PKG_NOT_INSTALLED		The package is not installed.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result MoveToInternalStorage(const PackageId& packageId);

	/**
	* Gets a package information from a specific file. @n The supported file extensions are tpk and wgt.
	*
	* @since         2.1
	* @privlevel     platform
	* @privilege     %http://tizen.org/privilege/packagemanager.info
	*
	* @return        A pointer to the %PackageInfo instance, @n
	*               else @c null if it fails
	* @param[in]    filePath                           The package file path
	* @exception    E_SUCCESS                          The method is successful.
	* @exception    E_INVALID_ARG                      The specified input parameter is invalid.
	* @exception    E_FILE_NOT_FOUND                   The specified file cannot be found or accessed.
	* @exception    E_UNSUPPORTED_FORMAT               The specified format is invalid or not supported.
	* @exception    E_PARSING_FAILED                   The method has failed to parse the package file or xml file(s) inside the package.
	* @exception    E_PRIVILEGE_DENIED                 The application does not have the privilege to call this method.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	PackageInfo* GetPackageInfoFromFileN(const Tizen::Base::String& filePath) const;

	/**
	* Gets the package information list with the package filter.
	*
	* @since         2.1
	* @privlevel     public
	* @privilege     %http://tizen.org/privilege/package.info
	*
	* @return        A pointer to the list of the %PackageInfo instances, @n
	*                else @c null if it fails
	* @param[in]     packageFilterMap         The predefined key(Tizen::Base::String)-value(Tizen::Base::Boolean) pairs for the package filter @n
	* For more information on the predefined key-value pairs for package filter,
	*       see <a href="../org.tizen.native.appprogramming/html/guide/app/package_app_filter.htm">the predefined key-value pairs for package filter</a>.
	* @exception    E_SUCCESS                            The method is successful.
	* @exception    E_INVALID_ARG                        The specified input parameter is invalid.
	* @exception    E_SYSTEM                             The method cannot proceed due to a severe system error.
	* @exception    E_PRIVILEGE_DENIED                   The application does not have the privilege to call this method.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::Collection::IList* GetPackageInfoListN(const Tizen::Base::Collection::IMap& packageFilterMap) const;

	/**
	* Gets the application information list with the package app filter.
	*
	* @since         2.1
	* @privlevel     public
	* @privilege     %http://tizen.org/privilege/package.info
	*
	* @return        A pointer to the list of the %PackageAppInfo instances, @n
	*                else @c null if it fails
	* @param[in]     packageAppFilterMap      The predefined key(Tizen::Base::String)-value(Tizen::Base::String or Tizen::Base::Boolean) pairs for the package app filter @n
	* For more information on the predefined key-value pairs for package app filter,
	*       see <a href="../org.tizen.native.appprogramming/html/guide/app/package_app_filter.htm">the predefined key-value pairs for package app filter</a>.
	* @exception    E_SUCCESS                            The method is successful.
	* @exception    E_INVALID_ARG                        The specified input parameter is invalid.
	* @exception    E_SYSTEM                             The method cannot proceed due to a severe system error.
	* @exception    E_PRIVILEGE_DENIED                   The application does not have the privilege to call this method.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::Collection::IList* GetPackageAppInfoListN(const Tizen::Base::Collection::IMap& packageAppFilterMap) const;

	/**
	* Gets the application information list with the package filter and package app filter.
	*
	* @since         2.1
	* @privlevel     public
	* @privilege     %http://tizen.org/privilege/package.info
	*
	* @return        A pointer to the list of the %PackageAppInfo instances, @n
	*                              else @c null if it fails
	* @param[in] packageFilterMap        The predefined key(Tizen::Base::String)-value(Tizen::Base::Boolean) pairs for the package filter @n
	* @param[in] packageAppFilterMap     The predefined and user defined key(Tizen::Base::String)-value(Tizen::Base::String or Tizen::Base::Boolean) pairs for the package app filter @n
	*                                    The user defined key-value pairs can be added in <Metadata> of manifest.xml.
	*
	* For more information on the predefined key-value pairs for package filter,
	*              see <a href="../org.tizen.native.appprogramming/html/guide/app/package_app_filter.htm">the predefined key-value pairs for package filter</a>.
	* For more information on the predefined key-value pairs for package app filter,
	*              see <a href="../org.tizen.native.appprogramming/html/guide/app/package_app_filter.htm">the predefined key-value pairs for package app filter</a>.
	*
	* @exception    E_SUCCESS                            The method is successful.
	* @exception    E_INVALID_ARG                        A specified input parameter is invalid.
	* @exception    E_SYSTEM                             The method cannot proceed due to a severe system error.
	* @exception    E_PRIVILEGE_DENIED                   The application does not have the privilege to call this method.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::Collection::IList* GetPackageAppInfoListN(const Tizen::Base::Collection::IMap& packageFilterMap, const Tizen::Base::Collection::IMap& packageAppFilterMap) const;

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
