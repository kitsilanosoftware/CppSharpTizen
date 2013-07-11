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
 * @file	FAppPkgPackageAppInfo.h
 * @brief	This is the header file for the %PackageAppInfo class.
 *
 * This header file contains the declarations of the %PackageAppInfo class.
 */

#ifndef _FAPP_PKG_PACKAGE_APP_INFO_H_
#define _FAPP_PKG_PACKAGE_APP_INFO_H_

#include <FBase.h>
#include <FAppTypes.h>
#include <FAppPkgPackageManager.h>

namespace Tizen { namespace App { namespace Package
{

/**
 * @class		PackageAppInfo
 * @brief		This class represents the information of the application in package.
 *
 * @since	2.0
 *
 * @final		This class is not intended for extension.
 *
 * The %PackageAppInfo class provides the information of the application in package.
 *
 */
class _OSP_EXPORT_ PackageAppInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~PackageAppInfo(void);

	/**
	 * Gets an application ID.
	 *
	 * @since	2.0
	 *
	 * @return An application ID
	 */
	AppId GetAppId(void) const;

	/**
	 * Gets the name of an application.
	 *
	 * @since	2.0
	 *
	 * @return	The name of an application
	 */
	Tizen::Base::String GetAppName(void) const;

	/**
	 * Gets the display name of an application.
	 *
	 * @since	2.0
	 *
	 * @return	The display name of an application
	 */
	Tizen::Base::String GetAppDisplayName(void) const;

	/**
	 * Gets the category list of an application.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the list of the Tizen::Base::String instances, @n
	 * 				else @c null if it fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAppCategoryListN(void) const;

	/**
	 * Checks whether an application is visible on the menu.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if an application is visible on the menu, @n
	 * 			else @c false
	 * @remarks If the return value is @c false, it is recommended not to display the application on the menu.
	 */
	bool IsMenuIconVisible(void) const;

	/**
	 * Checks whether an application is the main application of the package.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if an application is the main application of the package, @n
	 * 			else @c false
	 */
	bool IsMainApp(void) const;

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally
 declared as private so that only the platform can create an instance.
	 */
	PackageAppInfo(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PackageAppInfo(const PackageAppInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PackageAppInfo& operator =(const PackageAppInfo& rhs);

private:
	class _PackageAppInfoImpl* __pPackageAppInfoImpl;

	friend class _PackageAppInfoImpl;
	friend class _PackageInfoImpl;
	friend class _PackageManagerImpl;

}; // PackageAppInfo

} } } // Tizen::App::Package

#endif // _FAPP_PKG_PACKAGE_APP_INFO_H_
