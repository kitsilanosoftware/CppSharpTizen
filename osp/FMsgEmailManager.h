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
 * @file			FMsgEmailManager.h
 * @brief		This is the header file for the %EmailManager class.
 *
 * This header file contains the declarations of the %EmailManager class.
 */

#ifndef _FMSG_EMAIL_MANAGER_H_
#define _FMSG_EMAIL_MANAGER_H_

#include <FBase.h>
#include <FMsgIEmailListener.h>
#include <FMsgEmailMessage.h>
#include <FMsgRecipientList.h>

namespace Tizen { namespace Messaging
{
	// forward declaration for class extension
	class _EmailManagerImpl;

	/**
	* @class	EmailManager
	* @brief	This class provides methods to use the email messaging service.
	*
	* @since		2.0
	*
	* The %EmailManager class is used to send email messages.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*
	* The following example demonstrates how to use the %EmailManager class.
	*
	* @code
	*
	// Creates a listener to override the OnEmailMessageSent() method of IEmailListener
	// in order to be notified of a change in the state of the message being sent.

	class EmailListener
		: public IEmailListener
		, public Object
	{
	public:
		void OnEmailMessageSent(result r);
	};

	void
	EmailListener::OnEmailMessageSent(result r)
	{
		// Do something
	}

	class SendEmailMessage
		: public Object
	{
	public:
		void EmailTest(void);
	};

	void
	SendEmailMessage::EmailTest(void)
	{
		result r = E_SUCCESS;

		// Creates an EmailListener instance.
		EmailListener* pListener = new EmailListener();

		// Creates an %EmailManager instance with the listener as the callback to check the status of the message being sent.
		EmailManager* pEmailManager = new EmailManager();
		r = pEmailManager->Construct(*pListener);

		// Creates a recipient list instance and adds recipients.
		RecipientList recipient;
		r = recipient.Add (RECIPIENT_TYPE_TO, L"test10@tizen.org");
		r = recipient.Add (RECIPIENT_TYPE_CC, L"test09@tizen.org");
		r = recipient.Add (RECIPIENT_TYPE_BCC, L"test08@tizen.org");

		// Creates a email message instance.
		EmailMessage emailMessage;
		r = emailMessage.SetSubject(L"Subject!!!");
		r = emailMessage.SetText(L"Hello, World");
		r = emailMessage.AddAttachment(L"/Home/Res/testfile.dat");

		// Sends the message, and sets the @c saveToSentbox parameter to true if the message should be saved in the Sentbox; otherwise, set to false.
		// EmailListener callback is called once the message is completely sent.
		r = pEmailManager->Send(emailMessage, recipient, true);
	}
	*
	* @endcode
	*/
	class _OSP_EXPORT_ EmailManager
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		*	This is the default constructor for this class.
		*
		* @since		2.0
		*/
		EmailManager(void);

		/**
		*	This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~EmailManager(void);

	private:
		EmailManager(const EmailManager& value);
		EmailManager& operator =(const EmailManager& rhs);

		// Operation
	public:
		/**
		* Initializes this instance of %EmailManager with the specified parameter.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	listener		The listener to receive a send result asynchronously
		* @exception 	E_SUCCESS		The method is successful.
		* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
		*/
		result Construct(IEmailListener& listener);

		/**
		* Sends the email message.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.write @n
		* 				(%http://tizen.org/privilege/messaging.email is deprecated.)
		*
		* @return			An error code
		* @param[in]	message					The message to send
		* @param[in]	recipientList			The list of recipients
		* @param[in]	saveToSentbox			Set to @c true to save the message in the Sentbox, @n
		*										else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_ON_INITIALIZING		The mailbox is not completely loaded as yet.
		* @exception	E_STORAGE_FULL			The storage is full.
		* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_INVALID_ACCOUNT		The email account is not set.
		* @exception	E_INVALID_CONDITION		The profile is not set.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FDN_MODE				The FDN mode has been activated.
		* @exception	E_INVALID_ARG			The number of recipients is @c 0.
		* @exception	E_MAX_EXCEEDED			 The number of recipients has crossed the maximum limit (Maximum 20).
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		The value of the flag, @c saveToSentbox, is fixed to @c false in the emulator.
		* @see			IEmailListener::OnEmailMessageSent()
		*/
		result Send(const EmailMessage& message, const RecipientList& recipientList, bool saveToSentbox);

	private:
		_EmailManagerImpl* __pImpl;

		// friend class
		friend class _EmailManagerImpl;
	}; // EmailManager
} } // Tizen::Messaging

#endif // _FMSG_EMAIL_MANAGER_H_
