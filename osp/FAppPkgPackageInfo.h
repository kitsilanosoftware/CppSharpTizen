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
 * @file	FAppPkgPackageInfo.h
 * @brief	This is the header file for the %PackageInfo class.
 *
 * This header file contains the declarations of the %PackageInfo class.
 */

#ifndef _FAPP_PKG_PACKAGE_INFO_H_
#define _FAPP_PKG_PACKAGE_INFO_H_

#include <FBase.h>
#include <FAppTypes.h>
#include <FAppPkgPackageManager.h>

namespace Tizen { namespace App { namespace Package
{

/**
 * @class		PackageInfo
 * @brief		This class represents the information of a package.
 *
 * @since	2.0
 *
 * @final		This class is not intended for extension.
 *
 * The %PackageInfo class provides the information of a package.
 *
 */
class _OSP_EXPORT_ PackageInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~PackageInfo(void);

	/**
	 * Gets a package ID.
	 *
	 * @since	2.0
	 *
	 * @return A package ID
	 */
	PackageId GetId(void) const;

	/**
	 * Gets the version of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The version of a package
	 */
	Tizen::Base::String GetVersion(void) const;

	/**
	 * Gets the display name of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The display name of a package
	 */
	Tizen::Base::String GetDisplayName(void) const;

	/**
	 * Gets the description of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The description of a package, @n
	 *          else an empty string is returned if there is no value
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the author of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The author of a package, @n
	 *          else an empty string is returned if there is no value
	 */
	Tizen::Base::String GetAuthor(void) const;

	/**
	 * Gets the URL of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The URL of a package, @n
	 *          else an empty string is returned if there is no value
	 */
	Tizen::Base::String GetUrl(void) const;

	/**
	 * Gets the date and time when a package is installed.
	 *
	 * @since	2.0
	 *
	 * @return	An instance of Tizen::Base::DateTime when a package is installed
	 */
	Tizen::Base::DateTime GetInstallationTime(void) const;

	/**
	 * Checks whether a package is installed in the external storage.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if a package is installed in the external storage, @n
	 * 			else @c false
	 */
	bool IsInstalledInExternalStorage(void) const;

	/**
	 * Checks whether it is possible to uninstall a package.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if it is possible to uninstall a package, @n
	 * 			else @c false
	 */
	bool IsUninstallable(void) const;

	/**
	 * Checks whether it is possible to move a package to either internal or external storage.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if it is possible to move a package to either internal or external storage, @n
	 * 			else @c false
	 */
	bool IsMovable(void) const;

	/**
	 * Checks whether a package is downloaded.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if a package is downloaded, @n
	 * 			else @c false
	 */
	bool IsDownloaded(void) const;

	/**
	 * Gets the size of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The size of a package
	 */
	long long GetSize(void) const;

	/**
	 * Gets the data size of a package.
	 *
	 * @since	2.0
	 *
	 * @return	The data size of a package
	 */
	long long GetDataSize(void) const;

	/**
	 * Gets the main application ID of a package.
	 *
	 * @since	2.0
	 *
	 * @return The main application ID
	 */
	AppId GetMainAppId(void) const;

	/**
	 * Gets the store client package ID that installed the package.
	 *
	 * @since	2.0
	 *
	 * @return The store client package ID
	 */
	PackageId GetStoreClientId(void) const;

	/**
	 * Gets the application information list of a package.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the list of the PackageAppInfo instances
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetPackageAppInfoListN(void) const;

	/**
	 * Gets the application information with the specific application ID.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to PackageAppInfo
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The application information is not found.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::App::Package::PackageAppInfo* GetPackageAppInfoN(const AppId& appId) const;

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally
 declared as private so that only the platform can create an instance.
	 */
	PackageInfo(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PackageInfo(const PackageInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PackageInfo& operator =(const PackageInfo& rhs);

private:
	class _PackageInfoImpl * __pPackageInfoImpl;

	friend class _PackageInfoImpl;
	friend class _PackageManagerImpl;

}; // PackageInfo

} } } // Tizen::App::Package

#endif // _FAPP_PKG_PACKAGE_INFO_H_
