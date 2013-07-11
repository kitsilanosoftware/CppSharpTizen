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
 * @file		FMsgPushMessage.h
 * @brief		This is the header file for the %PushMessage class.
 *
 * This header file contains the declarations of the %PushMessage class.
 */

#ifndef _FMSG_PUSH_MESSAGE_H_
#define _FMSG_PUSH_MESSAGE_H_

#include <FBase.h>
#include <FShellNotificationRequest.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{
class _PushMessageImpl;

/**
* @class	PushMessage
* @brief	This class provides methods for handling a push message.
*
* @since	2.0
*
* The %PushMessage class provides methods for handling a push message. It allows you to get the body text and
* the received time of a push message.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
*/
class _OSP_EXPORT_ PushMessage
	: public Tizen::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		2.0
	*/
	PushMessage(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~PushMessage(void);

public:
	/**
	* Gets the date and time (UTC time) of the message when it is received.
	*
	* @since		2.0
	*
	* @return		The date and time (UTC time) when the message is received
	*/
	Tizen::Base::DateTime GetReceivedTime(void) const;

	/**
	* @if OSPDEPREC
	* Gets the body of the message.
	* 
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. Instead of using this method, use Tizen::Shell::NotificationRequest::GetAppMessage() method.
	*
	* @since		2.0
	*
	* @return		The body of the message
	* @endif
	*/
	Tizen::Base::String GetText(void) const;

	/**
	* Sets an action of the push message.
	*
	* @since		2.0
	*
	* @return       An error code
	* @param[in]    action          An action of the push message
	* @exception    E_SUCCESS       The method is successful.
	* @exception    E_INVALID_ARG   The specified input parameter is invalid.
	*/
	result SetAction(PushAction action);

	/**
	* Gets an action of the push message.
	*
	* @since		2.0
	*
	* @return      	An action of the push message
	*/
	PushAction GetAction(void) const;

	/**
	* Sets the notification of the push message.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]    notificationRequest        The notification request
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG              The specified input parameter is invalid.
	* @exception    E_OUT_OF_MEMORY            The memory is insufficient.
	* @remarks   	PushMessage supports to set only alert text of NotificationRequest instance, and others are ignored.
	* @see 			Tizen::Shell::NotificationRequest
	*/
	result SetNotification(const Tizen::Shell::NotificationRequest& notificationRequest);

	/**
	* Gets the notification of the push message.
	*
	* @since		2.0
	*
	* @return		The notification request
	* @remarks   	PushMessage supports to get only alert text of NotificationRequest instance, and others are ignored.
	* @see 			Tizen::Shell::NotificationRequest
	*/
	Tizen::Shell::NotificationRequest GetNotification(void) const;

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @param[in]	rhs				An instance of %PushMessage
	*/
	PushMessage(const PushMessage& rhs);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since		2.0
	*
	* @return		A reference to this instance
	* @param[in]	rhs				An instance of %PushMessage
	*/
	PushMessage& operator =(const PushMessage& rhs);

	/**
	* Compares the specified instance of %PushMessage with the calling instance.
	*
	* @since		2.0
	*
	* @return		@c true, if the values match, @n
	*				else @c false
	* @param[in]	obj 	The other Object to be compared
	* @see 			Tizen::Base::Object::Equals()
	*/
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return		The current instance's hash value
	*/
	virtual int GetHashCode(void) const;

private:
	/**
	 * This constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @param[in]	dateTime	The date and time (UTC time) when the message is received
	 * @param[in]	text		The message body text
	 */
	PushMessage(const Tizen::Base::DateTime& dateTime, const Tizen::Base::String& text);

private:
	_PushMessageImpl* __pPushMessageImpl;

	friend class _PushMessageImpl;
}; // PushMessage

} } // Tizen::Messaging
#endif // _FMSG_PUSH_MESSAGE_H_
