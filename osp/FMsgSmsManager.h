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
 * @file			FMsgSmsManager.h
 * @brief		This is the header file for the %SmsManager class.
 *
 * This header file contains the declarations of the %SmsManager class.
 */

#ifndef _FMSG_SMS_MANAGER_H_
#define _FMSG_SMS_MANAGER_H_

// Includes
#include <FMsgISmsListener.h>

#include <FMsgISmsMessageEventListener.h>


#include <FMsgSmsMessage.h>


#include <FMsgRecipientList.h>

namespace Tizen { namespace Messaging
{

	// forward declaration
	class _SmsManagerImpl;

	/**
	* @class	SmsManager
	* @brief	This class provides methods to use the SMS messaging service.
	*
	* @since		2.0
	*
	* The %SmsManager class is used to send, receive, and retrieve SMS messages.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*
	* The following example demonstrates how to use the %SmsManager class.
	*
	* @code
	*
	// Creates a listener to override the OnSmsMessageSent() function of ISmsListener
	// in order to be notified of a change in the state of the message being sent.

	class SmsListener
		: public ISmsListener
		, public Object
	{
	public:
		void OnSmsMessageSent(result r);
	};

	void
	SmsListener::OnSmsMessageSent(result r)
	{
		// Do something
	}

	class SendSmsMessage
		: public Object
	{
	public:
		void SmsTest(void);
	};

	void
	SendSmsMessage::SmsTest(void)
	{
		result r = E_SUCCESS;

		// Creates an SmsListener instance.
		SmsListener* pListener = new SmsListener();

		// Creates a SMS manager instance with the listener as the callback to check the status of the message being sent.
		SmsManager* pSmsManager = new SmsManager();
		r = pSmsManager->Construct(*pListener);

		// Creates a recipient list instance and adds recipients.
		RecipientList recipient;
		r = recipient.Add (RECIPIENT_TYPE_TO, L"01012345678");
		r = recipient.Add (RECIPIENT_TYPE_TO, L"01078901234");

		// Creates an SMS message instance.
		SmsMessage smsMessage;
		r = smsMessage.SetText(L"Hello, World");

		// Sends the message, and sets the saveToSentbox parameter to true if the message should be saved in the Sentbox; else, set to false.
		// SmsListener callback is called once the message has been completely sent.
		r = pSmsManager->Send(smsMessage, recipient, true);
	}
	*
	* @endcode
	*/
	class _OSP_EXPORT_ SmsManager
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		*	This is the default constructor for this class.
		*
		* @since		2.0
		*/
		SmsManager(void);

		/**
		*	This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~SmsManager(void);

	private:
		SmsManager(const SmsManager& value);
		SmsManager& operator =(const SmsManager& rhs);


		// Operation
	public:
		/**
		* Initializes this instance of %SmsManager with the specified parameter.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	listener			The listener to receive a send result asynchronously
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		*/
		result Construct(ISmsListener& listener);

		/**
		* Adds the event listener for receiving SMS messages.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		An error code
		* @param[in]	eventListener			The listener to receive SMS messages
		* @exception 	E_SUCCESS				The method is successful.
		* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_OBJ_ALREADY_EXIST		The listener already exists.
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		* @see			ISmsMessageEventListener
        * @see  		RemoveSmsMessageEventListener()
		*/
		result AddSmsMessageEventListener(ISmsMessageEventListener& eventListener);

		/**
		* Removes the event listener for receiving SMS messages.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		An error code
		* @param[in]	eventListener			The listener to receive SMS messages
		* @exception 	E_SUCCESS				The method is successful.
		* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_OBJ_NOT_FOUND			The listener is not found.
		* @exception	E_SYSTEM				A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		* @see			ISmsMessageEventListener
        * @see			AddSmsMessageEventListener()
		*/
		result RemoveSmsMessageEventListener(ISmsMessageEventListener& eventListener);

		/**
		* Sends the SMS message.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		An error code
		* @param[in]	message					The message to be sent
		* @param[in]	recipientList			The list of recipients
		* @param[in]	saveToSentbox			Set to @c true to save the message in the Sentbox, @n
		*										else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_ON_INITIALIZING		The mailbox is not completely loaded as yet.
		* @exception	E_STORAGE_FULL			The storage is full.
		* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FDN_MODE				The FDN mode has been activated.
		* @exception	E_INVALID_ARG			The number of recipients is @c 0.
		* @exception	E_MAX_EXCEEDED			The number of recipients has crossed the maximum limit (Maximum 10).
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		* @remarks		The CC and BCC recipients in the @c recipientList are ignored when sending an SMS message.
		* @see			ISmsListener::OnSmsMessageSent()
		*/
		result Send(const SmsMessage& message, const RecipientList& recipientList, bool saveToSentbox);

		/**
		* Gets the total number of SMS messages in the specified message box.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		The total number of SMS messages in the specified message box
		* @param[in]	type				The type of message box
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @exception	E_SYSTEM			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
		* @remarks		In case of an error, this method returns the negative value. For example, @c -1. @n
		*		 		The specific error code can be accessed using the GetLastResult() method.
		*/
		int GetTotalMessageCount(SmsMessageBoxType type) const;

		/**
		* Searches the SMS messages by keyword and|or sender address in the Inbox.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		A pointer to the list of the SmsMessage class instances
		* @param[in]	pKeyword			A part of the body text as a keyword (partial match) @n
		*									In case of @c null or an empty string, this method searches all SMS messages in the Inbox regardless of the keyword.
		* @param[in]	pSenderAddress		A telephone number as a sender address (exact match) @n
		*									In case of @c null or an empty string, this method searches all SMS messages in the Inbox regardless of the sender address.
		* @param[in]	startIndex			The start index (base 0)
		* @param[in]	count				The count of SMS messages to search
		* @param[out]	totalResultCount	The total count of the searched result
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
		*									- The specified @c pKeyword string length is less than @c 2 or greater than @c 30. @n
		* 									- The specified @c startIndex value is less than @c 0. @n
		* 									- The specified @c count value is less than @c 0 or greater than @c 20.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_SYSTEM			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
		* 		The search with the specified keywords searches using only the first 50 characters of the body text. @n
		* 		The SMS messages in the searched result contain only @c 160 bytes for the body text. @n
		* 				To check whether there is additional text, use the SmsMessage::HasMoreText() method. @n
		* 				To get the full body text, use GetFullText() with its message ID.
		* @see			SmsMessage
        * @see   		GetFullText()
		*/
		Tizen::Base::Collection::IList* SearchInboxN(const Tizen::Base::String* pKeyword, const Tizen::Base::String* pSenderAddress, int startIndex, int count, int& totalResultCount) const;

		/**
		* Searches the SMS messages by keyword in the specified message box.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		A pointer to the list of the SmsMessage class instances
		* @param[in]	type				The type of message box
		* @param[in]	pKeyword			A part of the body text as a keyword (partial match) @n
		*									In case of @c null or an empty string, this method searches all SMS messages in the specified message box.
		* @param[in]	startIndex			The start index (base 0)
		* @param[in]	count				The count of SMS messages to search
		* @param[out]	totalResultCount	The total count of the searched result
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
		*									- The specified @c type is invalid. @n
		* 									- The specified @c pKeyword string length is less than @c 2 or greater than @c 30. @n
		* 									- The specified @c startIndex value is less than @c 0. @n
		* 									- The specified @c count value is less than @c 0 or greater than @c 20.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_SYSTEM			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
		* 		The search with the specified keywords searches using only the first 50 characters of the body text. @n
		* 		The SMS messages in the searched result contain only @c 160 bytes for the body text. @n
		* 				To check whether there is additional text, use the SmsMessage::HasMoreText() method. @n
		* 				To get the full body text, use the GetFullText() method with its message ID.
		* @see			SmsMessage, GetFullText()
		*/
		Tizen::Base::Collection::IList* SearchMessageBoxN(SmsMessageBoxType type, const Tizen::Base::String* pKeyword, int startIndex, int count, int& totalResultCount) const;

		/**
		* Gets the full text of the SMS message in the message box using the message ID.
		*
		* @since		2.0
		*
		* @privilege	%http://tizen.org/privilege/messaging.sms
		*
		* @return		The full text of the specified SMS message
		* @param[in]	messageId			The unique ID of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c messageId is invalid, or it must be greater than or equal to @c 0.
		* @exception	E_OBJ_NOT_FOUND		The SMS message with the specified @c messageId is not found.
		* @exception	E_SYSTEM			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
		* 				In case of an error, this method returns an empty string.
		* @see			SmsMessage::HasMoreText()
		*/
		Tizen::Base::String GetFullText(int messageId) const;

	private:
		_SmsManagerImpl* __pImpl;

		// friend class
		friend class _SmsManagerImpl;
	}; // SmsManager
} } // Tizen::Messaging

#endif // _FMSG_SMS_MANAGER_H_
