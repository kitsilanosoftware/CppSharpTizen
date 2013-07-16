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
 * @file		FMsgSmsMessage.h
 * @brief		This is the header file for the %SmsMessage class.
 *
 * This header file contains the declarations of the %SmsMessage class.
 */

#ifndef _FMSG_SMS_MESSAGE_H_
#define _FMSG_SMS_MESSAGE_H_

namespace Tizen { namespace Base
{
class String;
class DateTime;
} }

#include <FBaseObject.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{
	// forward declaration for class extension
	class _SmsMessageImpl;
	class RecipientList;

	/**
	* @class	SmsMessage
	* @brief	This class provides methods for handling an SMS message.
	*
	* @since		2.0
	*
	* The %SmsMessage class provides methods for handling SMS messages. It allows you to set and get the body text of an SMS message.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _OSP_EXPORT_ SmsMessage
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since		2.0
		*/
		SmsMessage(void);

		/**
		*	This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~SmsMessage(void);

		/**
		* This is the copy constructor for the %SmsMessage class.
		*
		* @since		2.0
		*
		* @param[in]	value	An instance of %SmsMessage
		*/
		SmsMessage(const SmsMessage& value);

	public:

		/**
		* This assignment operator copies an SMS message from the specified instance of %SmsMessage to the calling instance of %SmsMessage.
		*
		* @since		2.0
		*
		* @return			A reference to the %SmsMessage instance
		* @param[in]	rhs		A reference to the %SmsMessage instance to copy
		*/
		SmsMessage& operator =(const SmsMessage& rhs);

		/**
		* Compares the calling instance with the specified instance.
		*
		* @since		2.0
		*
		* @return			@c true if the specified instance of Tizen::Base::Object is equal to the calling %SmsMessage instance, @n
		*						else @c false
		* @param[in]		obj		The object to compare
		*/
		virtual bool Equals(const Tizen::Base::Object& obj) const;

		/**
		* Gets the hash value of the current instance.
		*
		* @since		2.0
		*
		* @return			The hash value of the current instance
		*/
		virtual int GetHashCode(void) const;

		// Operation
	public:
		/**
		* Sets the body of the SMS message.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	text				The body of the SMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The body length of the message exceeds the maximum limit (Maximum 80 characters).
		* @see			GetText()
		*/
		result SetText(const Tizen::Base::String& text);

		/**
		* Gets the body of the SMS message.
		*
		* @since		2.0
		*
		* @return		The body of the SMS message
		* @remarks		
		*				- If the message is from the Inbox, Sentbox, or Outbox, it may contain only @c 160 bytes for the body text.
		* 				- To check whether the message contains more than @c 160 bytes for the body text, use the HasMoreText() method.
		* 				- To get the full body text, use the SmsManager::GetFullText() method with its message ID.
		* @see			SetText()
        * @see  		HasMoreText()
        * @see   		GetId()
        * @see   		SmsManager::GetFullText()
		*/
		Tizen::Base::String GetText(void) const;


		/**
		* Gets the sender address of the SMS message.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return			The sender address of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is only allowed to the incoming message or the message from the Inbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*/
		Tizen::Base::String GetSenderAddress(void) const;

		/**
		* Gets the received time of the SMS message.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return			The received time of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is only allowed to the incoming message or the message from the Inbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		
		*				- The specific error code can be accessed using the GetLastResult() method.
		* 				- In case of an error, this method returns the instance denoting 00:00:00, January 1, 1.
		*/
		Tizen::Base::DateTime GetReceivedTime(void) const;

		/**
		* Gets the unique ID of the SMS message.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return		The unique ID of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Inbox, Sentbox, or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		
		*				- In case of an error, this method returns the negative value. For example, @c -1.
		*		 		- The specific error code can be accessed using the GetLastResult() method.
		*/
		int GetId(void) const;

		/**
		* Gets the sent time of the SMS message.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return		The sent time of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Sentbox or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*		 		In case of an error, this method returns the instance denoting 00:00:00, January 1, 1.
		*/
		Tizen::Base::DateTime GetSentTime(void) const;

		/**
		* Gets the type of the SMS message box.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return		The type of the SMS message box
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Inbox, Sentbox, or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		
		*				- In case of an error, this method returns the SMS_MESSAGE_BOX_TYPE_NONE value.
		*		 		- The specific error code can be accessed using the GetLastResult() method.
		*/
		SmsMessageBoxType GetMessageBoxType(void) const;

		/**
		* Gets the list of the recipients.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return		The list of the recipient
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Sentbox or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*/
		RecipientList GetRecipientList(void) const;

		/**
		* Checks whether the SMS message contains more than @c 160 bytes for the body text.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.read @n
		* 				(%http://tizen.org/privilege/messaging.sms is deprecated.)
		*
		* @return		@c true if this SMS message contains more than @c 160 bytes for the body text, @n
		*				else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Inbox, Sentbox, or Outbox.
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		
		*				- If the return value is @c true, the SMS message contains more than @c 160 bytes for the body text.
		* 				- To get the full body text, use SmsManager::GetFullText().
		*		 		- The specific error code can be accessed using the GetLastResult() method.
		*/
		bool HasMoreText(void) const;

	private:
		_SmsMessageImpl* __pImpl;

		// friend class
		friend class _SmsMessageImpl;
	}; // SmsMessage
} } // Tizen::Messaging

#endif // _FMSG_SMS_MESSAGE_H_
