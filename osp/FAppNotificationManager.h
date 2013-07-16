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
 * @file		FAppNotificationManager.h
 * @brief		This is the header file for the %NotificationManager class.
 *
 * This header file contains the declarations of the %NotificationManager class.
 */

#ifndef _FAPP_NOTIFICATION_MANAGER_H_
#define _FAPP_NOTIFICATION_MANAGER_H_

#include <FBase.h>
#include <FAppTypes.h>

namespace Tizen { namespace App
{

/**
 * @if OSPDEPREC
 * The maximum length of the notification message.
 *
 * @brief		<i> [Deprecated] </i>
 *
 * @deprecated	This variable is deprecated. Instead of using this variable, use the Tizen::Shell::MAX_NOTIFICATION_MESSAGE_LENGTH variable.
 * @since	2.0
 * @endif
 */
static const int MAX_NOTIFICATION_MESSAGE_LENGTH = 127;

/**
 * @if OSPDEPREC
 * The maximum length of the launch arguments for the notification in bytes.
 *
 * @brief		<i> [Deprecated] </i>
 *
 * @deprecated	This variable is deprecated. Instead of using this variable, use the Tizen::Shell::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH variable.
 * @since		2.0
 * @endif
 */
static const int MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH = 1024;

/**
 * @if OSPDEPREC
 * The maximum length of the notification badge number.
 *
 * @brief		<i> [Deprecated] </i>
 *
 * @deprecated	This variable is deprecated. Instead of using this variable, use the Tizen::Shell::MAX_NOTIFICATION_BADGE_NUMBER variable.
 * @since	2.0
 * @endif
 */
static const int MAX_NOTIFICATION_BADGE_NUMBER = 999;

/**
 * @if OSPDEPREC
 * @class		NotificationManager
 * @brief		<i> [Deprecated] </i> This class provides methods to alert the user about a notification.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %NotificationManager class provides methods to alert the user about a notification.
 * @n
 * For more information about the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/notifications.htm">Notifications</a>.
 *
 * The following example demonstrates how to use the %NotificationManager class.
 *
 * @code
 *
 *	result
 *	MyClass::NotificationSample(void)
 *	{
 *		int badgeNumber;
 *		NotificationManager* pNotiMgr = new NotificationManager();
 *		pNotiMgr->Construct();
 *		badgeNumber = pNotiMgr->GetBadgeNumber();
 *		badgeNumber++;
 *		pNotiMgr->Notify(L"A new message has arrived.", badgeNumber);
 *
 *	}
 *
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ NotificationManager
	: public Tizen::Base::Object
{

public:
	/**
	 * @if OSPDEPREC
	 * This is the default constructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @endif
	 */
	NotificationManager(void);

	/**
	 * @if OSPDEPREC
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @endif
	 */
	virtual ~NotificationManager(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %NotificationManager.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @endif
	 */
	result Construct(void);

	/**
	 * @if OSPDEPREC
	 * Gets the current badge number of the application icon.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		The current badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_OBJ_NOT_FOUND     The application is not installed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method. @n
	 *          In case of failure, this method returns @c -1.
	 * @endif
	 */
	int GetBadgeNumber(void);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a badge number.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *                                  the specified @c badgeNumber is less than @c 0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result Notify(int badgeNumber);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a message.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result Notify(const Tizen::Base::String& messageText);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a message and badge number.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c badgeNumber is less than @c 0, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result Notify(const Tizen::Base::String& messageText, int badgeNumber);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a message and badge number. @n
	 * If the user checks the message, @c launchArguments is delivered to the application. @n
	 * @c launchArguments is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @param[in]	launchArguments		The message for application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c badgeNumber is less than @c 0. @n
	 *									- The length of the specified @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of the specified @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see			IAppControlProviderEventListener::OnAppControlRequestReceived()
	 * @endif
	 */
	result Notify(const Tizen::Base::String& messageText, int badgeNumber, const Tizen::Base::String& launchArguments);

	/**
	 * @if OSPDEPREC
	 * Removes the notification message.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since			2.0
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	 This method returns @c E_SUCCESS when there is no outstanding notification.
	 * @endif
	 */
	result RemoveNotification(void);

	/**
	 * @if OSPDEPREC
	 * Notifies the user about the ongoing activity using a message.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since				2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOngoingActivity(const Tizen::Base::String& messageText);

	/**
	 * @if OSPDEPREC
	 * Notifies the user about the ongoing activity using a message. @n
	 * @c launchArguments is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since				2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]  launchArguments	The launch arguments for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The length of the specified @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of the specified @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOngoingActivity(const Tizen::Base::String& messageText, const Tizen::Base::String& launchArguments);

	/**
	 * @if OSPDEPREC
	 * Removes the notification message for the ongoing activity.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since			2.0
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	 This method returns @c E_SUCCESS when there is no outstanding notification.
	 * @endif
	 */
	result RemoveOngoingActivityNotification(void);

	/**
	 * @if OSPDEPREC
	 * Gets the badge number of the application icon.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		The current badge number
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OBJ_NOT_FOUND     The application is not installed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method. @n
	 *			In case of failure, this method returns @c -1.
	 * @endif
	 */
	int GetBadgeNumber(const AppId& appId);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a badge number on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *                                  the specified @c badgeNumber is less than @c 0.
	 * @exception	E_APP_NOT_INSTALLED  The application is not installed.
	 * @exception	E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the %Tizen platform policy.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOnBehalf(const AppId& appId, int badgeNumber);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a message on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_APP_NOT_INSTALLED  The application is not installed.
	 * @exception	E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the %Tizen platform policy.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOnBehalf(const AppId& appId, const Tizen::Base::String& messageText);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a message and badge number on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since	2.0
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c badgeNumber is less than @c 0. @n
	 *									- The length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_APP_NOT_INSTALLED  The application is not installed.
	 * @exception	E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the %Tizen platform policy.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOnBehalf(const AppId& appId, const Tizen::Base::String& messageText, int badgeNumber);

	/**
	 * @if OSPDEPREC
	 * Notifies the user using a message and badge number on behalf of the specified application. @n
	 * If the user checks the message, the @c launchArguments is delivered to the application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since               2.0
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return             An error code
	 * @param[in]  appId				The application ID
	 * @param[in]  messageText		The notification message
	 * @param[in]  launchArguments	The launch arguments for the application
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *								- A specified input parameter is invalid. @n
	 *								- The length of the specified @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *								- The length of the specified @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception  E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception  E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the %Tizen platform policy.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOnBehalf(const AppId& appId, const Tizen::Base::String& messageText, const Tizen::Base::String& launchArguments);

	/**
	 * @if OSPDEPREC
	 * Notifies the user about the ongoing activity using a message on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since				2.0
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception   E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOngoingActivityOnBehalf(const AppId& appId, const Tizen::Base::String& messageText);

	/**
	 * @if OSPDEPREC
	 * Notifies the user about the ongoing activity using a message on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since				2.0
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	messageText			The notification message
	 * @param[in]  launchArguments	The launch arguments for application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception   E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the %Tizen platform policy.
	 * @exception E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOngoingActivityOnBehalf(const AppId& appId, const Tizen::Base::String& messageText, const Tizen::Base::String& launchArguments);

	/**
	 * @if OSPDEPREC
	 * Removes the notification message for the ongoing activity on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since			2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		Although there is no outstanding notification for the calling application, this method returns @c E_SUCCESS.
	 * @endif
	 */
	result RemoveOngoingActivityNotificationOnBehalf(const AppId& appId);

	/**
	 * @if OSPDEPREC
	 * Removes the notification message on behalf of the specified application.
	 *
	 * @brief		<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this class, use the Tizen::Shell::NotificationManager class.
	 * @since			2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		Although there is no outstanding notification for the calling application, this method returns @c E_SUCCESS.
	 * @endif
	 */
	result RemoveNotificationOnBehalf(const AppId& appId);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	NotificationManager(const NotificationManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	NotificationManager& operator =(const NotificationManager& rhs);

private:
	class _NotificationManagerImpl * __pNotificationManagerImpl;

	friend class _NotificationManagerImpl;
}; // NotificationManager

} } // Tizen::App

#endif // _FAPP_NOTIFICATION_MANAGER_H_
