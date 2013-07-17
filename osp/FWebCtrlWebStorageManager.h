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
* @file            FWebCtrlWebStorageManager.h
* @brief                     This is the header file for the %WebStorageManager class.
*
* This header file contains the declarations of the %WebStorageManager class for a %Web control.
*/
#ifndef _FWEB_CTRL_WEB_STORAGE_MANAGER_H_
#define _FWEB_CTRL_WEB_STORAGE_MANAGER_H_

#include <unique_ptr.h>
#include <FBaseString.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}} // Tizen::Base::Collection

namespace Tizen { namespace Web { namespace Controls
{
class _WebStorageManagerImpl;
}}} // Tizen::Web::Control

namespace Tizen { namespace Web { namespace Controls
{

/**
* @enum WebStorageType
*
* Defines the web storage type.
*
* @since		2.1
*/
enum WebStorageType
{
	WEB_STORAGE_TYPE_APPLICATION_CACHE,	/**< The web storage type: application cache */
	WEB_STORAGE_TYPE_INDEXED_DATABASE,	/**< The web storage type: indexed database */
	WEB_STORAGE_TYPE_WEB_SQL_DATABASE,	/**< The web storage type: web database */
	WEB_STORAGE_TYPE_WEB_STORAGE,		/**< The web storage type: web storage */
	WEB_STORAGE_TYPE_FILE_SYSTEM		/**< The web storage type: file system */
};

/**
* @class		WebStorageManager
* @brief		This class holds the setting values for a %Web control.
*
* @since		2.1
*
* @final		This class is not intended for extension.
*
* The %WebStorageManager class holds the setting values for a %Web control.
*/
class _OSP_EXPORT_ WebStorageManager
	: public Tizen::Base::Object
{
public:

	/**
	 * Gets the list of origins for a given storage type. @n
	 * The @c WEB_STORAGE_TYPE_INDEXED_DATABASE is not supported.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		A pointer to IList containing origin(Tizen::Base::String) list, @n
	 * 					else @c null if no web storage data exists
	 * @param[in]	storageType		The web storage type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNSUPPORTED_TYPE	The specified @c storageType is not supported.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetOriginListN(WebStorageType storageType) const;

	/**
	 * Sets the default quota for a given origin for a given storage type. @n
	 * Only the @c WEB_STORAGE_TYPE_WEB_SQL_DATABASE and the @c WEB_STORAGE_TYPE_APPLICATION_CACHE are supported.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		An error code
	 * @param[in]	storageType		The web storage type
	 * @param[in]	origin			The origin
	 * @param[in]	quota			The quota of the web storage to set in bytes
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c origin is invalid.
	 * @exception	E_UNSUPPORTED_TYPE	The specified @c storageType is not supported.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result SetQuotaForOrigin(WebStorageType storageType, const Tizen::Base::String& origin, long quota);


	/**
	 * Gets the quota for a given origin for a given storage type. @n
	 * Only the @c WEB_STORAGE_TYPE_WEB_SQL_DATABASE is supported.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		The usage of the web storage in bytes
	 * @param[in]	storageType		The web storage type
	 * @param[in]	origin			The origin
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c origin is invalid.
	 * @exception	E_UNSUPPORTED_TYPE	The specified @c storageType is not supported.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	long GetQuotaForOrigin(WebStorageType storageType, const Tizen::Base::String& origin);

	/**
	 * Gets the usage for a given origin for a given storage type. @n
	 * The @c WEB_STORAGE_TYPE_INDEXED_DATABASE and the @c WEB_STORAGE_TYPE_FILE_SYSTEM are not supported.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		The usage of the web storage in bytes
	 * @param[in]	storageType		The web storage type
	 * @param[in]	origin			The origin
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c origin is invalid.
	 * @exception	E_UNSUPPORTED_TYPE	The specified @c storageType is not supported.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	long GetUsageForOrigin(WebStorageType storageType, const Tizen::Base::String& origin) const;

	/**
	 * Removes the data for a given origin for a given storage type. @n
	 * The @c WEB_STORAGE_TYPE_INDEXED_DATABASE is not supported.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		An error code
	 * @param[in]	storageType		The web storage type
	 * @param[in]	origin			The origin
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c origin is invalid.
	 * @exception	E_UNSUPPORTED_TYPE	The specified @c storageType is not supported.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see RemoveAll()
	 */
	result Remove(WebStorageType storageType, const Tizen::Base::String& origin);

	/**
	 * Removes all data for a given storage type.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		An error code
	 * @param[in]	storageType		The web storage type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNSUPPORTED_TYPE	The specified @c storageType is not supported.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see Remove()
	 */
	result RemoveAll(WebStorageType storageType);

	/**
	 * Gets the web storage manager instance.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the %WebStorageManager instance, @n
	 *					else @c null if it fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static WebStorageManager* GetInstance(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @remarks		This constructor is hidden.
	//
	WebStorageManager(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @remarks		This destructor is hidden.
	//
	virtual ~WebStorageManager(void);

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in] rhs			The instance of the % WebStorageManager class to copy from
	// @remarks		This constructor is hidden.
	//
	WebStorageManager(const WebStorageManager& rhs);

	//
	// Initializes the web storage manager instance.
	//
	// @since		2.1
	//
	static void InitWebStorageManager(void);

	//
	// Destroys the web storage manager instance.
	//
	// @since		2.1
	//
	static void DestroyWebStorageManager(void);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in] rhs			An instance of % WebStorageManager to assign from
	// @remarks		This operator is hidden.
	//
	WebStorageManager& operator=(const WebStorageManager& rhs);

private:
	_WebStorageManagerImpl* __pWebStorageManagerImpl;

	static WebStorageManager* __pInstance;

	friend class _WebStorageManagerImpl;

	friend struct std::default_delete<WebStorageManager>;
}; // WebStorageManager

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_WEB_STORAGE_MANAGER_H_
