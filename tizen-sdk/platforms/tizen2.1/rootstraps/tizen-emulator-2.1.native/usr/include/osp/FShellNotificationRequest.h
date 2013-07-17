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
 * @file		FShellNotificationRequest.h
 * @brief		This is the header file for the %NotificationRequest class.
 *
 * This header file contains the declarations of the %NotificationRequest class.
 */

#ifndef _FSHELL_NOTIFICATION_REQUEST_H_
#define _FSHELL_NOTIFICATION_REQUEST_H_

#include <FBase.h>
#include <FShellNotificationManager.h>

namespace Tizen { namespace Shell
{

/**
 * @class		NotificationRequest
 * @brief		This class provides methods for handling a notification request.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %NotificationRequest class provides methods for handling a notification request. The request can contain following
 * items:
 * -# Constructing element of the notification area such as a notification title or alert text
 * -# Information of the indicator area such as an alert text
 * -# The path of the sound file to play when user selects the notification message of the notification area
 * -# The badge number or badge offset for notification area or main menu
 *
 * %NotificationRequest are of 2 types: bound to an application or not bound to any application. If %NotificationRequest is bound to an application, then
 * the associated application is launched by selecting the item in the notification area. Nothing happens when an unbounded %NotificationRequest is selected from a notification area.
 *
 * For more information about the class features, see <a href="../org.tizen.native.appprogramming/html/guide/shell/notifications.htm">Notifications</a>.
 *
 * @see	Tizen::Shell::NotificationManager
 */
class _OSP_EXPORT_ NotificationRequest
	: public Tizen::Base::Object
{

public:
	/**
	 * Initializes this instance of %NotificationRequest with the specified @c appBinding.
	 *
	 * @since	2.0
	 *
	 * @param[in]	appBinding	Set to @c true to bind %NotificationRequest to the destination application, @n
	 * 							else @c false
	 * @remarks	Selecting the posted notification in the notification area leads to launch of the associated application
	 * 			if %NotificationRequest is bound to the destination application.
	 * @see	SetAlertText()
	 */
	explicit NotificationRequest(bool appBinding = true);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %NotificationRequest
	 */
	NotificationRequest(const NotificationRequest& rhs);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %NotificationRequest
	 */
	NotificationRequest& operator =(const NotificationRequest& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~NotificationRequest(void);

	/**
	 * Checks whether the specified instance of %NotificationRequest equals the current instance.
	 *
	 * @since	2.0
	 *
	 * @return      @c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]   rhs     An instance of %NotificationRequest
	 * @remarks     This method returns @c false if the specified object is not %NotificationRequest.
	 */
	virtual bool Equals(const Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the badge number of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return		The badge number value
	 * @remarks	If the badge number is not set, then this method returns @c -1.
	 */
	int GetBadgeNumber(void) const;

	/**
	 * Sets the badge number of a notification message. @n
	 * %NotificationRequest has either badge number or badge number offset.
	 * If the badge number is set using %SetBadgeNumber(), then previous badge offset value is set to @c 0.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	value	The badge number value
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c value is less than @c 0 or greater than Shell::MAX_NOTIFICATION_BADGE_NUMBER.
	 */
	result SetBadgeNumber(int value);

	/**
	 * Gets the badge number offset of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return		The badge offset value
	 */
	int GetBadgeOffset(void) const;

	/**
	 * Sets the badge number offset of the notification message. @n
	 * %NotificationRequest has either badge number or badge number offset.
	 * If the badge number offset is set using %SetBadgeOffset(), then previous badge number value is set to @c -1 and ignored. @n
	 *
	 * When posting the notification message, badge offset value is added to the current badge number,
	 * which can be acquired by NotificationManager::GetBadgeNumber(). Setting badge offset to @c 0
	 * means explicitly specifying not to change the current badge value with the notification message.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	value	The badge number value
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The absolute value of the specified @c value is greater than Shell::MAX_NOTIFICATION_BADGE_NUMBER.
	 * @remarks	Even though this method does not return @c E_INVALID_ARG, it does not guarantee the success of NotificationManager::Notify().
	 * @see	SetBadgeNumber()
	 */
	result SetBadgeOffset(int value);

	/**
	 * Gets the alert text of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return	The alert text
	 */
	Tizen::Base::String GetAlertText(void) const;

	/**
	 * Sets an alert text of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	text	The alert text
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c text is empty or the length of @c text is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @remarks	
	 *				- @c text is displayed according to notification layout, and the length of the @c text depends on the font attributes or the variable font width.
	 *				- @c text is mandatory for a notification.
	 */
	result SetAlertText(const Tizen::Base::String& text);

	/**
	 * Gets the application message of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return The message for application
	 */
	Tizen::Base::String GetAppMessage(void) const;

	/**
	 * Sets the application message of a notification message. @n
	 * @c appMessage is delivered as the value of the %http://tizen.org/appcontrol/data/notification key
	 * for Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived().
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	appMessage		The message for the application
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c appMessage is empty or the length of @c appMessage is greater than Shell::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_INVALID_OPERATION	This instance is not bound to the application.
	 * @remarks	This method returns @c E_INVALID_OPERATION if the %NotificationRequest instance is not bound to the application.
	 */
	result SetAppMessage(const Tizen::Base::String& appMessage);

	/**
	 * Gets the title text of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return	The title text
	 */
	Tizen::Base::String GetTitleText(void) const;

	/**
	 * Sets the title text of a notification message.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	title	The title text
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c title is empty or the length of @c title is greater than Shell::MAX_NOTIFICATION_TITLE_LENGTH.
	 * @remarks	If @c title is not set, the application name is displayed.
	 */
	result SetTitleText(const Tizen::Base::String& title);

	/**
	 * Gets the file path of the icon image for a notification message.
	 *
	 * @since	2.0
	 *
	 * @return	The file path of an icon image
	 */
	Tizen::Base::String GetIconFilePath(void) const;

	/**
	 * Sets the file path of the icon image for a notification message.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	iconPath	The file path of the icon image
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified path is invalid.
	 * @remarks	If @c iconPath is not set, the application icon is displayed.
	 */
	result SetIconFilePath(const Tizen::Base::String& iconPath);

	/**
	 * Gets the file path of a sound file that is played for the notification message.
	 *
	 * @since	2.0
	 *
	 * @return	The file path of the sound file to play
	 */
	Tizen::Base::String GetSoundFilePath(void) const;

	/**
	 * Sets the file path of the sound file that is played for the notification message.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	soundPath	The file path of the sound file
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified path is invalid.
	 * @remarks	
	 *				- If the format of the sound file is not valid, then the sound file is not played properly when the notification message is displayed.
	 *				- If @c soundPath is not set, the default sound is played when the %NotificationRequest instance is delivered to the NotificationManager::Notify() method.
	 */
	result SetSoundFilePath(const Tizen::Base::String& soundPath);

	/**
	 * Gets the notification type for the ongoing activity notification.
	 *
	 * @since	2.0
	 *
	 * @return	The ongoing activity notification type
	 * @remarks	This information is only meaningful when the %NotificationRequest instance is delivered to the NotificationManager::NotifyOngoingActivity() method.
	 * @see	SetOngoingActivityType()
	 */
	OngoingActivityType GetOngoingActivityType(void) const;

	/**
	 * Sets the notification type for an ongoing activity.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	type	The notification type for an ongoing activity
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	The current progress value is not compatible to the specified @c type.
	 * @remarks	This information is only meaningful when the %NotificationRequest instance is delivered to the NotificationManager::NotifyOngoingActivity() method.
	 * @see	SetOngoingActivityProgress()
	 */
	result SetOngoingActivityType(OngoingActivityType type = ONGOING_ACTIVITY_TYPE_TEXT);

	/**
	 * Gets the progress value for an ongoing activity notification.
	 *
	 * @since	2.0
	 *
	 * @return	The progress value
	 */
	int GetOngoingActivityProgress(void) const;

	/**
	 * Sets the progress value with the specified @c value.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	value	The progress value
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	Either of the following conditions has occurred: @n
	 * 								- The specified @c value is less than @c 0.
     *								- The specified @c value does not lie between @c 0 and @c 100 for Shell::ONGOING_ACTIVITY_TYPE_PROGRESS_PERCENTAGE.
     *								- The notification type for an ongoing activity is not set.
	 * @exception	E_INVALID_OPERATION	This instance is in an invalid state. @n
	 * 								OngoingActivityType must be either Shell::ONGOING_ACTIVITY_TYPE_PROGRESS_BYTE or Shell::ONGOING_ACTIVITY_TYPE_PROGRESS_PERCENTAGE.
	 * @see	SetOngoingActivityType()
	 */
	result SetOngoingActivityProgress(int value);

	/**
	 * Gets the style of a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		The notification style
	 */
	NotificationStyle  GetNotificationStyle(void) const;

	/**
	 * Sets the style of a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	style			The notification style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c style is not valid.
	 */
	result SetNotificationStyle(NotificationStyle style);

	/**
	 * Gets a list of message text for a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		A string list of message text
	 */
	Tizen::Base::Collection::IList* GetMessageTextListN(void) const;

	/**
	 * Sets a string list of message text for a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	pTextList		A list of message text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c pTextList is empty or the length of @c pTextList is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @remarks		This information is only meaningful when the notification style is Shell::NOTIFICATION_STYLE_NORMAL. @n
	 *				Use the tab(\\t) character to separate the columns.
	 */
	result SetMessageTextList(const Tizen::Base::Collection::IList* pTextList);

	/**
	 * Gets a list of the message thumbnail image absolute file path for a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		A string list of thumbnail image file path
	 */
	Tizen::Base::Collection::IList* GetMessageThumbnailFilePathListN(void) const;

	/**
	 * Sets a string list of the message thumbnail image absolute file path for a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	pThumbnailPathList	A list of the thumbnail image file path
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified path is invalid.
	 * @remarks		This information is only meaningful when the notification style is Shell::NOTIFICATION_STYLE_THUMBNAIL.
	 */
	result SetMessageThumbnailFilePathList(const Tizen::Base::Collection::IList* pThumbnailPathList);

	/**
	 * Gets the notification count text of a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		The notification count text
	 */
	Tizen::Base::String GetNotificationCountText(void) const;

	/**
	 * Sets the notification count text of a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	notificationCountText	The notification count text
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c notificationCountText is empty or the length of @c notificationCountText is greater than Shell::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @remarks	This information is only meaningful when the notification style is Shell::NOTIFICATION_STYLE_NORMAL.
	 */
	result SetNotificationCountText(const Tizen::Base::String& notificationCountText);

	/**
	 * Gets the absolute file path of the background image for a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		The file path of a background image file
	 */
	Tizen::Base::String GetBackgroundImageFilePath(void) const;

	/**
	 * Sets the absolute file path of the background image for a notification message.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	imagePath		The file path of the background image
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified path is invalid.
	 */
	result SetBackgroundImageFilePath(const Tizen::Base::String& imagePath);


private:
	class _NotificationRequestImpl* __pNotificationRequestImpl;

	friend class _NotificationRequestImpl;
}; // NotificationRequest

} } // Tizen::App

#endif // _FSHELL_NOTIFICATION_REQUEST_H_
