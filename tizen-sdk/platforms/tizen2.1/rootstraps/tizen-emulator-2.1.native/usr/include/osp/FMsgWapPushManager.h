//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 3.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-3.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
* @file			FMsgWapPushManager.h
* @brief		This is the header file for the %WapPushManager class.
*
* This header file contains the declarations of the %WapPushManager class.
*/

#ifndef _FMSG_WAP_PUSH_MANAGER_H_
#define _FMSG_WAP_PUSH_MANAGER_H_

namespace Tizen { namespace Base
{
class String;
} }

#include <FMsgIWapPushEventListener.h>

namespace Tizen { namespace Messaging
{
class _WapPushManagerImpl;

/**
* @class	WapPushManager
* @brief	This class provides methods to use the WAP Push messaging service.
*
* @since		2.0
*
* @final	This class is not intended for extension.
*
* The %WapPushManager class provides methods to use the WAP Push messaging service.
*/
class _OSP_EXPORT_ WapPushManager
	: public Tizen::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		2.0
	*/
	WapPushManager(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~WapPushManager(void);

public:
	/**
	* Adds the event listener for receiving WAP Push messages for a specific WAP Push application ID.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/wappush
	*
	* @feature		%http://tizen.org/feature/network.telephony
	* @return		An error code
	* @param[in]	wapApplicationId		The X-Wap-Application-Id indicating a WAP Push application ID
	* @param[in]	listener				A listener for receiving the incoming WAP Push messages
	* @exception    E_SUCCESS           	The method is successful.
	* @exception    E_OBJ_ALREADY_EXIST		The specified @c wapApplicationId is already registered, or
	* 										the listener already exists.
	* @exception	E_INVALID_ARG			The specified @c wapApplicationId is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception  	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @b Since: @b 2.1
	* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks    	Before calling this method, check whether the feature is supported by 
	*				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	* @see			IWapPushEventListener
    * @see      	RemoveWapPushEventListener()
	*/
	result AddWapPushEventListener(const Tizen::Base::String& wapApplicationId, IWapPushEventListener& listener);

	/**
	* Removes the event listener for receiving WAP Push messages for a specific WAP Push application
	* ID.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/wappush
	*
	* @feature		%http://tizen.org/feature/network.telephony
	* @return		An error code
	* @param[in]	wapApplicationId		The X-Wap-Application-Id indicating a WAP Push
	*										application ID
	* @param[in]	listener				A listener for receiving the incoming WAP Push messages
	* @exception    E_SUCCESS           	The method is successful.
	* @exception    E_OBJ_NOT_FOUND			The specified @c wapApplicationId is not registered, or
	* 										the specified @c listener is not found.
	* @exception	E_INVALID_ARG			The specified @c wapApplicationId is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception  	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @b Since: @b 2.1
	* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks    	Before calling this method, check whether the feature is supported by 
	*				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	* @see			IWapPushEventListener
    * @see      	AddWapPushEventListener()
	*/
	result RemoveWapPushEventListener(const Tizen::Base::String& wapApplicationId, IWapPushEventListener& listener);

	/**
	* Registers a condition to receive WAP Push message.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/wappush
	*
	* @feature		%http://tizen.org/feature/network.telephony
	* @return		An error code
	* @param[in]	wapApplicationId	The X-Wap-Application-Id indicating a WAP push application ID
	* @param[in]	contentType			The MIME content type of the content
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		The specified @c contentType or @c wapApplicationId is invalid.
	* @exception	E_ILLEGAL_ACCESS	The application does not have the permission to register the conditions.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception  	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @b Since: @b 2.1
	* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception    E_ALREADY_SET		The condition is already registered.
	* @remarks    	Before calling this method, check whether the feature is supported by 
	*				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	* @see			UnregisterCondition()
	*/
	result RegisterCondition(const Tizen::Base::String& wapApplicationId, const Tizen::Base::String& contentType);

	/**
	* Unregisters a condition to receive WAP push message.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/wappush
	*
	* @feature		%http://tizen.org/feature/network.telephony
	* @return		An error code
	* @param[in]	wapApplicationId	The X-Wap-Application-Id indicating a WAP push application ID
	* @param[in]	contentType			The MIME content type of the content
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		The specified @c contentType or @c wapApplicationId is invalid.
	* @exception	E_ILLEGAL_ACCESS	The application does not have the permission to unregister the conditions.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception  	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @b Since: @b 2.1
	* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks    	Before calling this method, check whether the feature is supported by 
	*				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	* @see			RegisterCondition()
	*/
	result UnregisterCondition(const Tizen::Base::String& wapApplicationId, const Tizen::Base::String& contentType);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of WapPushManager
	 */
	WapPushManager(const WapPushManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of WapPushManager
	 */
	WapPushManager& operator =(const WapPushManager& rhs);

private:
	_WapPushManagerImpl* __pWapPushManagerImpl;

	friend class _WapPushManagerImpl;
}; // WapPushManager

} } // Tizen::Messaging
#endif // _FMSG_WAP_PUSH_MANAGER_H_
