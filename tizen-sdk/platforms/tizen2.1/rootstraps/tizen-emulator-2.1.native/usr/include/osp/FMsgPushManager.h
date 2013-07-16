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
 * @file		FMsgPushManager.h
 * @brief		This is the header file for the %PushManager class.
 *
 * This header file contains the declarations of the %PushManager class.
 */

#ifndef _FMSG_PUSH_MANAGER_H_
#define _FMSG_PUSH_MANAGER_H_

#include <FBase.h>
#include <FMsgIPushManagerListener.h>
#include <FMsgIPushEventListener.h>

namespace Tizen { namespace Messaging
{
class _PushManagerImpl;

/**
* @class	PushManager
* @brief	This class provides methods to use the push messaging service.
*
* @since	2.0
*
* @remarks	If an application package contains multiple applications, only one application can use the push messaging service at a time.
*
* @pre		In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
*
*
* The %PushManager class provides methods to register, unregister, and use the push messaging service.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
*
* @see      Tizen::Shell::NotificationManager
*
* The following example demonstrates how to use the %PushManager class.
*
* @code
*
	#include <FBase.h>
	#include <FMessaging.h>

	using namespace Tizen::Base;
	using namespace Tizen::Messaging;

	// Creates a listener to override the methods of IPushManagerListener and IPushEventListener.
	class MyClass
		: public Object
		, public IPushEventListener
		, public IPushManagerListener
	{
	public:
		MyClass(void) {}
		~MyClass(void) {}

		//IPushManagerListener and IPushEventListener
		void OnPushServiceRegistered(RequestId reqId, const String& registrationId, result r, const String& errorCode, const String& errorMsg);
		void OnPushServiceUnregistered(RequestId reqId, result r, const String& errorCode, const String& errorMsg);
		void OnPushMessageReceived(const PushMessage& message);

		void Initialize(void);
		void EnablePushService(void);
		void DisablePushService(void);

	private:
		PushManager* pPushManager;
	};

	void
	MyClass::OnPushServiceRegistered(RequestId reqId, const String& registrationId, result r, const String& errorCode, const String& errorMsg)
	{
		if (E_SUCCESS == r)
		{
			// The application must send registrationId to the application server.
		}
		else
		{
			// Error
		}
	}

	void
	MyClass::OnPushServiceUnregistered(RequestId reqId, result r, const String& errorCode, const String& errorMsg)
	{
		// Do something
	}

	void
	MyClass::OnPushMessageReceived(const PushMessage& message)
	{
		// Do something
	}

	void
	MyClass::Initialize(void)
	{
		// Creates a PushManager instance.
		pPushManager = new PushManager();
		pPushManager->Construct(*this, *this);
	}

	void
	MyClass::EnablePushService(void)
	{
		RequestId reqId;
		result r = E_SUCCESS;

		r = pPushManager->RegisterPushService(reqId);
		if (IsFailed(r))
		{
			return;
		}

		// The result of registration will be notified by IPushManagerListener::OnPushServiceRegistered().
	}

	void
	MyClass::DisablePushService(void)
	{
		// The application must notify the application server to stop sending push messages for this device.

		RequestId reqId;
		result r = E_SUCCESS;

		r = pPushManager->UnregisterPushService(reqId);
		if (IsFailed(r))
		{
			return;
		}

		// The result of unregistration will be notified by IPushManagerListener::OnPushServiceUnregistered().
	}

    *
    * @endcode
    */
class _OSP_EXPORT_ PushManager
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	PushManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~PushManager(void);

public:
	/**
	* Initializes this instance of the %PushManager class with the specified parameters.
	*
	* @since		2.0
	* @privlevel    public
	* @privilege	%http://tizen.org/privilege/push
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	* @feature		%http://tizen.org/feature/network.push
	* @return		An error code
	* @param[in]	managerListener		A listener that receives the result of the %PushManager
	*                                   class asynchronous methods
	* @param[in]	eventListener		A listener that receives the incoming push messages
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception	E_SYSTEM            A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception    E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @b Since: @b 2.1
	*				For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks	Before calling this method, check whether the feature is supported by 
	*			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	* @see			IPushManagerListener
	* @see			IPushEventListener
	*/
	result Construct(IPushManagerListener& managerListener, IPushEventListener& eventListener);

	/**
	* Registers the push messaging service for the current application. @n
	* The %RegisterPushService() method is asynchronous.
	*
	* @since		2.0
	* @privlevel    public
	* @privilege	%http://tizen.org/privilege/push
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	*
	* @return		An error code
	* @param[out]	reqId				The request ID
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception	E_SYSTEM            A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	* @see			IPushManagerListener::OnPushServiceRegistered()
	*/
	result RegisterPushService(RequestId& reqId);

	/**
	* Unregisters the push messaging service for the current application. @n
	* The %UnregisterPushService() method is asynchronous.
	*
	* @since		2.0
	* @privlevel    public
	* @privilege	%http://tizen.org/privilege/push
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	*
	* @return		An error code
	* @param[out]	reqId				The request ID
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception	E_SYSTEM            A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	* @see			IPushManagerListener::OnPushServiceUnregistered()
	*/
	result UnregisterPushService(RequestId& reqId);

	/**
	* Checks whether the push messaging service registration has been completed for the current application.
	*
	* @since		2.0
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	*
	* @return		@c true if the registration is completed, @n
	*               else @c false
	*/
	bool IsPushServiceRegistered(void) const;

	/**
	* Gets the unread push messages. @n
	* If an application receives unread messages with the %GetUnreadMessagesN() method, the messages are removed from the system.
	*
	* @since		2.0
	* @privlevel    public
	* @privilege	%http://tizen.org/privilege/push
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	*
	* @return		A pointer to the list that contains unread push messages
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- If the user launches the application using a ticker or a quick panel,
	*			the push message related to the notification is delivered to the application
	*			as a launch argument.
	*			- The launch arguments are the input parameters for
	*			Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceivedN().
	*			- This method returns all the unread messages including the message
	*			delivered as a launch argument.
	* @see			Tizen::App::IAppControlProviderEventListener
	*/
	Tizen::Base::Collection::IList* GetUnreadMessagesN(void);

	/**
	* Sends the push message to a single recipient. @n
	* The %SendPushMessage() method is asynchronous.
	*
	* @since		2.0
	* @privlevel    public
	* @privilege	%http://tizen.org/privilege/push and %http://tizen.org/privilege/http @n
	* 								Both privileges are required.
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	*
	* @return		An error code
	* @param[in]	message 			The push message
	* @param[in]	registrationId		The registration ID of the recipient
	* @param[in]	appSecret			The secret code of the application issued by the push server to authenticate the application
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	* @see								IPushManagerListener::OnPushMessageSent()
	*/
	result SendPushMessage(const PushMessage& message, const Tizen::Base::String& registrationId, const Tizen::Base::String& appSecret, RequestId& reqId);


	/**
	* Sends the push message to multiple recipients. @n
	* The %SendPushMessage() method is asynchronous.
	*
	* @since		2.0
	* @privlevel    public
	* @privilege	%http://tizen.org/privilege/push and %http://tizen.org/privilege/http @n
	* 								Both privileges are required.
	*
	* @pre			In order to use the push messaging service, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/push_messaging.htm">Push Messaging Guide</a>.
	*
	* @return		An error code
	* @param[in]	message 			The push message
	* @param[in]	registrationIdList	The list of registration IDs of the recipients
	* @param[in]	appSecret			The secret code of the application issued by the push server to authenticate the application
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_MAX_EXCEEDED		The number of registration IDs has crossed the maximum limit.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks	The maximum limit can be checked by using GetMaxRecipientCount().
	* @see								IPushManagerListener::OnPushMessageSent()
	*/
	result SendPushMessage(const PushMessage& message, const Tizen::Base::Collection::IList& registrationIdList, const Tizen::Base::String& appSecret, RequestId& reqId);

	/**
	* Gets the maximum number of recipients sent by a multiple SendPushMessage() method.
	*
	* @since		2.0
	*
	* @return		The maximum number of recipients
	*/
	static int GetMaxRecipientCount(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of PushManager
	 */
	PushManager(const PushManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @return		A reference to this instance
	 * @param[in]	rhs				An instance of PushManager
	 */
	PushManager& operator =(const PushManager& rhs);

private:
	_PushManagerImpl* __pPushManagerImpl;

	friend class _PushManagerImpl;
}; // PushManager

} } // Tizen::Messaging
#endif // _FMSG_PUSH_MANAGER_H_
