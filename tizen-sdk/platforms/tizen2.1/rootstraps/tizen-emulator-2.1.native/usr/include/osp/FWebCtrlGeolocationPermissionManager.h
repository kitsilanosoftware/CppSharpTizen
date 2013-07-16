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
 * @file		FWebCtrlGeolocationPermissionManager.h
 * @brief		This is the header file for the %GeolocationPermissionManager class.
 * @privlevel          platform
 *
 * This header file contains the declarations of the %GeolocationPermissionManager class.
 *
 */
#ifndef _FWEB_CTRL_GEOLOCATION_PERMISSION_MANAGER_H_
#define _FWEB_CTRL_GEOLOCATION_PERMISSION_MANAGER_H_

#include <unique_ptr.h>
#include <FBaseString.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}} // Tizen::Base::Collection

namespace Tizen { namespace Web { namespace Controls
{

class _GeolocationPermissionManagerImpl;

/**
 * @class		GeolocationPermissionManager
 * @brief		This class provides methods to manage geolocation permissions.
 *
 * @since		2.0
 *
 * The %GeolocationPermissionManager class provides methods to manage geolocation permissions decided by a user from origins using html5 JavaScript geolocation APIs.
 * @n
 * Origin consists of the scheme, host, and port.
 */

class _OSP_EXPORT_ GeolocationPermissionManager
	: public Tizen::Base::Object
{ 
public:

	/**
	 * Gets the origin list stored at the geolocation database.
	 *
	 * @since		2.0
	 * @privlevel		platform
	 * @privilege	%http://tizen.org/privilege/geolocationpermission.read
	 *
	 * @return	A pointer to Tizen::Base::Collection::IList containing origin(Tizen::Base::String) list, @n
	 * 				else @c null if no geolocation permission data exists
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	 Tizen::Base::Collection::IList* GetOriginListN(void) const;

	/**
	 * Checks whether geolocation permission is allowed or not for the specified @c origin.
	 *
	 * @since		2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/geolocationpermission.read
	 *
	 * @return		@c true if geolocation permission is allowed, @n
	 * 					else @c false
	 * @param[in]	origin			The origin
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_DATA_NOT_FOUND	There is no permission data for the specified @c origin.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsPermissionAllowed(const Tizen::Base::String& origin) const;

	/**
	 * Removes the geolocation data for the specified @c origin.
	 *
	 * @since		2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/geolocationpermission.write
	 *
	 * @return		An error code
	 * @param[in]	origin			The origin
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_DATA_NOT_FOUND	There is no permission data for the specified @c origin.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see RemoveAll()
	 */
	result Remove(const Tizen::Base::String& origin);

	/**
	 * Removes all elements in the list.
	 * 
	 * @since		2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/geolocationpermission.write
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see Remove()
	 */
	result RemoveAll(void);

	/**
	 * Gets the geolocation permission manager instance.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the %GeolocationPermissionManager instance, @n
	 *					else @c null if it fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static GeolocationPermissionManager* GetInstance(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @remarks		This constructor is hidden.
	//
	GeolocationPermissionManager(void);

 	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @remarks		This destructor is hidden.
	//
	virtual ~GeolocationPermissionManager(void);

	//
	// Initializes this instance of the %Web control with the specified parameters.
	//
	// @since		2.0
	//
	// @return		An error code
	//
	result Construct(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in] 	rhs			The instance of the % GeolocationPermissionManager class to copy from
	// @remarks		This constructor is hidden.
	//
	GeolocationPermissionManager(const GeolocationPermissionManager& rhs);

	//
	// Initializes the geolocation permission manager instance.
	//
	// @since		2.0
	//
	static void InitGeolocationPermissionManager(void);

	//
	// Destroys the geolocation permission manager instance.
	//
	// @since		2.0
	//
	static void DestroyGeolocationPermissionManager(void);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in] 	rhs			An instance of % GeolocationPermissionManager to assign from
	// @remarks		This operator is hidden.
	//
	GeolocationPermissionManager& operator=(const GeolocationPermissionManager& rhs);

private:

	_GeolocationPermissionManagerImpl* __pGeolocationPermissionManagerImpl;

	static GeolocationPermissionManager* __pInstance;

	friend class _GeolocationPermissionManagerImpl;

	friend struct std::default_delete<GeolocationPermissionManager>;
}; // GeolocationPermissionManager

}}} // Tizen::Web::Controls

#endif // _FWEB_CTRL_GEOLOCATION_PERMISSION_MANAGER_H_
