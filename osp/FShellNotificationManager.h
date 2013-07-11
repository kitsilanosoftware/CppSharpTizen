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
 * @file		FShellNotificationManager.h
 * @brief		This is the header file for the %NotificationManager class.
 *
 * This header file contains the declarations of the %NotificationManager class.
 */

#ifndef _FSHELL_NOTIFICATION_MANAGER_H_
#define _FSHELL_NOTIFICATION_MANAGER_H_

#include <FBase.h>
#include <FAppTypes.h>

namespace Tizen { namespace Shell
{

class NotificationRequest;

/**
 * The maximum length of a notification message.
 *
 * @since	2.0
 */
static const int MAX_NOTIFICATION_MESSAGE_LENGTH = 1024;

/**
 * The maximum length of the launch arguments for a notification in bytes.
 *
 * @since	2.0
 */
static const int MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH = 1024;

/**
 * The maximum length of a notification badge number.
 *
 * @since	2.0
 */
static const int MAX_NOTIFICATION_BADGE_NUMBER = 999;

/**
 * The maximum length of a title text.
 *
 * @since	2.0
 */
static const int MAX_NOTIFICATION_TITLE_LENGTH = 1024;

/**
 * @enum	OngoingActivityType
 *
 * Defines the notification type for an ongoing activity.
 *
 * @since	2.0
 */
enum OngoingActivityType
{
	ONGOING_ACTIVITY_TYPE_TEXT = 1,			/**< The progress is indicated with a text */
	ONGOING_ACTIVITY_TYPE_PROGRESS_BYTE,	/**< The progress is indicated with the number of bytes */
	ONGOING_ACTIVITY_TYPE_PROGRESS_PERCENTAGE	/**< The progress is indicated with percentage */
};


/**
 * @class		NotificationManager
 * @brief		This class provides methods to alert the user about a notification.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %NotificationManager class provides methods to alert the user about notifications.
 * @n
 * For more information about the class features, see <a href="../org.tizen.native.appprogramming/html/guide/shell/notifications.htm">Notifications</a>.
 *
 * The following example demonstrates how to use the %NotificationManager class.
 *
 * @code
 *	void
 *	MyClass::NotificationSample(void)
 *	{
 *		int badgeNumber;
 *		NotificationManager notiMgr;
 *		notiMgr.Construct();
 *		badgeNumber = notiMgr.GetBadgeNumber();
 *		badgeNumber++;
 *		notiMgr.Notify(L"A new message has arrived.", badgeNumber);
 *	}
 * @endcode
 *
 */
class _OSP_EXPORT_ NotificationManager
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	NotificationManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~NotificationManager(void);

	/**
	 * Initializes this instance of %NotificationManager.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 */
	result Construct(void);

	/**
	 * Gets the current badge number of an application icon.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		The current badge number if the method is successful, @n
					else @c -1 if the method fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	int GetBadgeNumber(void);

	/**
	 * Notifies the user who has @c badgeNumber as a badge number.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *                                  the specified @c badgeNumber is less than @c 0.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(int badgeNumber);

	/**
	 * Notifies the user with a message.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const Tizen::Base::String& messageText);

	/**
	 * Notifies the user who has @c badgeNumber as badge number with a message.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c badgeNumber is less than @c 0, or
	 *									the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const Tizen::Base::String& messageText, int badgeNumber);

	/**
	 * Notifies the user who has @c badgeNumber as badge number with a message. @n
	 * If the user selects this message, @c launchArguments is delivered to the application. @n
	 * @c launchArguments is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @param[in]	launchArguments		The message for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c badgeNumber is less than @c 0. @n
	 *									- The length of the specified @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of the specified @c launchArguments is greater than Shell::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const Tizen::Base::String& messageText, int badgeNumber, const Tizen::Base::String& launchArguments);

	/**
	 * Notifies the user with a request message. @n
	 * The notification request may have various pieces of information such as alert text, title text, launch arguments, and so on.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	request			The notification request
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified @c request does not have valid badge number value. @n
	 * 									- The specified @c request does not have alert text. @n
	 * 									- The specified @c request has invalid icon file path.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const NotificationRequest& request);

	/**
	 * Removes the notification message.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	 This method returns @c E_SUCCESS when there is no outstanding notification.
	 */
	result RemoveNotification(void);

	/**
	 * Notifies the user about the ongoing activity using a message.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const Tizen::Base::String& messageText);

	/**
	 * Notifies the user about the ongoing activity using a message. @n
	 * If the user selects the message, @c launchArguments is delivered to the application. @n
	 * @c launchArguments is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]  launchArguments	The launch arguments for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The length of the specified @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of the specified @c launchArguments is greater than Shell::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const Tizen::Base::String& messageText, const Tizen::Base::String& launchArguments);

	/**
	 * Notifies the user about the ongoing activity using a request message. @n
	 * The request may have various pieces of information such as alert text, title text, launch arguments, and so on.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	request			The notification request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified @c request does not have either alert text or progress value. @n
	 * 									- The specified @c request has invalid icon file path.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const NotificationRequest& request);

	/**
	 * Removes the notification message for the ongoing activity.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	 This method returns @c E_SUCCESS when there is no outstanding notification.
	 */
	result RemoveOngoingActivityNotification(void);

	/**
	 * Gets the badge number of the application icon mentioned in the @c appId.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/notification
	 *
	 * @return		The current badge number if the method is successful, @n
					else @c -1 if the method fails
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_APP_NOT_INSTALLED     The application is not installed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method. @n
	 *
	 */
	int GetBadgeNumberByAppId(const Tizen::App::AppId& appId);

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

#endif // _FSHELL_NOTIFICATION_MANAGER_H_
