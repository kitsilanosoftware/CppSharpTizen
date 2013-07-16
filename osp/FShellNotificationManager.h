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
 * @file		FShellNotificationManager.h
 * @brief		This is the header file for the %NotificationManager class.
 *
 * This header file contains the declarations of the %NotificationManager class.
 */

#ifndef _FSHELL_NOTIFICATION_MANAGER_H_
#define _FSHELL_NOTIFICATION_MANAGER_H_

#include <FBase.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base
{
namespace Collection
{
class IMap;
}
} }

namespace Tizen { namespace Shell
{

class NotificationRequest;
class IBadgeEventListener;

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
 * @enum	NotificationStyle
 *
 * Defines the notification style.
 *
 * @since	2.1
 */
enum NotificationStyle
{
	NOTIFICATION_STYLE_NORMAL = 1,		/**< The notification is normal style */
	NOTIFICATION_STYLE_THUMBNAIL		/**< The notification is thumbnail style */
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
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		The current badge number if the method is successful, @n
	 *				else @c -1 if the method fails
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
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified input parameter is invalid.
	 * 									- The specified @c badgeNumber is less than @c 0 or the @c badgeNumber is greater than Shell::MAX_NOTIFICATION_BADGE_NUMBER.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(int badgeNumber);

	/**
	 * Notifies the user with a message.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified input parameter is invalid.
	 *									- The specified @c messageText is empty or the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const Tizen::Base::String& messageText);

	/**
	 * Notifies the user who has @c badgeNumber as badge number with a message.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified @c messageText is empty or the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * 									- The specified @c badgeNumber is less than @c 0 or the @c badgeNumber is greater than Shell::MAX_NOTIFICATION_BADGE_NUMBER.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const Tizen::Base::String& messageText, int badgeNumber);

	/**
	 * Notifies the user who has @c badgeNumber as badge number with a message. @n
	 * If the user selects this message, @c launchArguments is delivered to the application. @n
	 * @c launchArguments is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @param[in]	launchArguments		The message for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c badgeNumber is less than @c 0 or the @c badgeNumber is greater than Shell::MAX_NOTIFICATION_BADGE_NUMBER. @n
	 *									- The specified @c messageText is empty or the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The specified @c launchArguments is empty or the length of @c launchArguments is greater than Shell::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const Tizen::Base::String& messageText, int badgeNumber, const Tizen::Base::String& launchArguments);

	/**
	 * Notifies the user with a request message. @n
	 * The notification request may have various pieces of information such as alert text, title text, launch arguments, and so on.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	request			The notification request
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result Notify(const NotificationRequest& request);

	/**
	 * The user who is identified with the @c appId is notified with a request message. @n
	 * The request may have various pieces of information such as alert text, title text, launch arguments, and so on.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 *				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	request			The notification request
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyByAppId(const Tizen::App::AppId& appId, const NotificationRequest& request);

	/**
	 * Removes the notification message.
	 *
	 * @since	2.0
	 * @privlevel	public
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
	 * Removes the notification message on behalf of the specified application.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application did not have the privilege to call this method.
	 * @remarks		Although there is no outstanding notification for the calling application, this method returns @c E_SUCCESS.
	 */
	result RemoveNotificationByAppId(const Tizen::App::AppId& appId);

	/**
	 * Notifies the user about the ongoing activity using a message.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified input parameter is invalid. @n
	 * 									- The specified @c messageText is empty or the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const Tizen::Base::String& messageText);

	/**
	 * Notifies the user about the ongoing activity using a message. @n
	 * If the user selects the message, @c launchArguments is delivered to the application. @n
	 * @c launchArguments is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]  launchArguments	The launch arguments for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c messageText is empty or the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The specified @c launchArguments is empty or the length of @c launchArguments is greater than Shell::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const Tizen::Base::String& messageText, const Tizen::Base::String& launchArguments);

	/**
	 * Notifies the user about the ongoing activity using a request message. @n
	 * The request may have various pieces of information such as alert text, title text, launch arguments, and so on.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	request			The notification request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const NotificationRequest& request);

	/**
	 * Notifies the user about the ongoing activity using a request message. @n
	 * The request may have various information like alert text, title text, launch arguments, and so on.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	request			The notification request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivityByAppId(const Tizen::App::AppId& appId, const NotificationRequest& request);

	/**
	 * Removes the notification message for the ongoing activity.
	 *
	 * @since	2.0
	 * @privlevel	public
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
	 * Removes the notification message for ongoing activity on behalf of the specified application.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		Although there is no outstanding notification for the calling application, this method returns @c E_SUCCESS.
	 */
	result RemoveOngoingActivityNotificationByAppId(const Tizen::App::AppId& appId);

	/**
	 * Gets the badge number of the application icon mentioned in the @c appId.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification @n
	 * 				(%http://tizen.org/privilege/notificationmanager is deprecated.)
	 *
	 * @return		The current badge number if the method is successful, @n
	 *				else @c -1 if the method fails
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_APP_NOT_INSTALLED     The application is not installed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method. @n
	 *
	 */
	int GetBadgeNumberByAppId(const Tizen::App::AppId& appId);

	/**
	 * Notifies the user with a message. @n
	 * It will disappear in a few seconds.
	 *
	 * @since	2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified input parameter is invalid.
	 * 									- The specified @c messageText is empty or the length of @c messageText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The message is displayed in the status bar.
	 */
	result NotifyTextMessage(const Tizen::Base::String& messageText);

	/**
	 * Notifies the user using a request message and try implicit AppControl resolution when the user selects the message on the notification area. @n
	 * The request may have various information like alert text, title text, launch arguments, and so on.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	operationId			The operation ID
	 * @param[in]	pUriData			A pointer to the URI data
	 * @param[in]	pDataType			A pointer to the MIME type (RFC 2046) data
	 * @param[in]	pExtraData			A pointer to an argument map of key and value pair where the key is of type Tizen::Base::String and the value is of type %Tizen::Base::String to deliver to the resolved application @n
	 *									The maximum size is @c 16 kilo bytes.
	 * @param[in]	request				The notification request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		For more information on the implicit AppControl resolution, see <a href="../org.tizen.native.appprogramming/html/guide/app/resolving_appcontrols.htm">here</a>.
	 *
	 */
	result NotifyByAppControl(const Tizen::Base::String& operationId, const Tizen::Base::String* pUriData, const Tizen::Base::String* pDataType,
							  const Tizen::Base::Collection::IMap* pExtraData, const NotificationRequest& request);

	/**
	 * Notifies the user about the ongoing activity using a request message and try implicit AppControl resolution when the user selects the message on the notification area. @n
	 * The request may have various information like alert text, title text, launch arguments, and so on.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/notification
	 *
	 * @return		An error code
	 * @param[in]	operationId			The operation ID
	 * @param[in]	pUriData			A pointer to the URI data
	 * @param[in]	pDataType			A pointer to the MIME type (RFC 2046) data
	 * @param[in]	pExtraData			A pointer to an argument map of key and value pair where the key is of type Tizen::Base::String and the value is of type %Tizen::Base::String to deliver to the resolved application @n
	 *									The maximum size is @c 16 kilo bytes.
	 * @param[in]	request				The notification request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		For more information on the implicit AppControl resolution, see <a href="../org.tizen.native.appprogramming/html/guide/app/resolving_appcontrols.htm">here</a>.
	 */
	result NotifyOngoingActivityByAppControl(const Tizen::Base::String& operationId, const Tizen::Base::String* pUriData, const Tizen::Base::String* pDataType,
											 const Tizen::Base::Collection::IMap* pExtraData, const NotificationRequest& request);

	/**
     * Adds an IBadgeEventListener instance to the %NotificationManager instance. @n
     * The listener gets notified when a badge number is updated. @n
     *
     * @since            2.1
     *
     * @return		An error code
     * @param[in]	listener					The listener to add
     * @exception	E_SUCCESS					The method is successful.
     * @exception	E_OBJ_ALREADY_EXIST			The listener is already added.
     * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
     * @remarks          Internally platform does not have the ownership of this pointer, so caller should manage the listener object properly.
	 * @see              NotificationManager::Notify()
     */
    result AddBadgeEventListener(IBadgeEventListener& listener);

	/**
     * Removes an IBadgeEventListener instance from the %NotificationManager instance.
     *
     * @since            2.1
     *
     * @return      An error code
     * @param[in]	listener			The listener to remove
     * @exception	E_SUCCESS           The method is successful.
     * @exception	E_OBJ_NOT_FOUND		The listener is not found.
     * @exception	E_SYSTEM            The method cannot proceed due to a severe system error.
     * @remarks          Internally platform does not have the ownership of this pointer, so caller should manage the listener object properly.
     */
	result RemoveBadgeEventListener(IBadgeEventListener& listener);

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
