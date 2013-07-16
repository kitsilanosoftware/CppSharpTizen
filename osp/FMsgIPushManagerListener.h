//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file		FMsgIPushManagerListener.h
 * @brief		This is the header file for the %IPushManagerListener interface.
 *
 * This header file contains the declarations of the %IPushManagerListener interface.
 */

#ifndef _FMSG_IPUSH_MANAGER_LISTENER_H_
#define _FMSG_IPUSH_MANAGER_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Messaging
{
/**
* @interface	IPushManagerListener
* @brief		This interface is the listener interface that receives the registration result.
*
* @since		2.0
*
* The %IPushManagerListener interface must be implemented to receive results of the push event registration. An application must register this interface using the PushManager::Construct() method.
*/
class _OSP_EXPORT_ IPushManagerListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IPushManagerListener(void) {}

public:
	/**
	* Called when the result is received from PushManager::RegisterPushService().
	*
	* @since		2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	registrationId		The registration ID of the device @n
	*                                   The application must deliver this ID to the application server.
	* @param[in]	r					The result of the request
	* @param[in]	errorCode			The error code from the server
	* @param[in]	errorMsg			The error message from the server
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			An unknown operating system error has occurred.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	* @exception	E_SERVER			An error has occurred on the server side.
	* @exception	E_SERVICE_UNAVAILABLE	The service is unavailable. @n
	* Check whether the push service registration is completed. For more information, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	* @see			PushManager::RegisterPushService()
	*/
	virtual void OnPushServiceRegistered(RequestId reqId, const Tizen::Base::String& registrationId, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMsg) = 0;

	/**
	* Called when the result is received from PushManager::UnregisterPushService().
	*
	* @since		2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	r					The result of the request
	* @param[in]	errorCode			The error code from the server
	* @param[in]	errorMsg			The error message from the server
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			An unknown operating system error has occurred.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	* @exception	E_SERVER			An error has occurred on the server side.
	* @see			PushManager::UnregisterPushService()
	*/
	virtual void OnPushServiceUnregistered(RequestId reqId, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMsg) = 0;

	/**
	* Called when the result is received from PushManager::SendPushMessage().
	*
	* @since		2.0
	*
	* @param[in]	reqId						The request ID
	* @param[in]	registrationId				The registration ID of the recipient
	* @param[in]	r							The result of the request, @n
	* 															The following exceptions may be given through this parameter.
	* @param[in]	errorCode					The error code from the server
	* @param[in]	errorMsg					The error message from the server
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_DATA				An invalid data is received from the server.
	* @exception	E_CONNECTION_FAILED 		The network connection has failed.
	* @exception	E_REMOTE_DEVICE_NOT_FOUND 	The registration ID is invalid, so the recipient is not found.
	* @exception	E_AUTHENTICATION 			The appSecret is invalid, so application authentication has failed.
	* @exception	E_SERVER					An error has occurred on the server side.
	* @exception	E_SERVICE_UNAVAILABLE	  	The service is unavailable. @n
	* Check whether the push service registration is completed. For more information, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	* @see			PushManager::SendPushMessage()
	*/
	virtual void OnPushMessageSent(RequestId reqId, const Tizen::Base::String& registrationId, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMsg) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPushManagerListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPushManagerListener_Reserved3(void) {}
}; // IPushManagerListener

} } // Tizen::Messaging
#endif // _FMSG_IPUSH_MANAGER_LISTENER_H_
