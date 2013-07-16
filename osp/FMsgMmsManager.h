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
 * @file			FMsgMmsManager.h
 * @brief		This is the header file for the %MmsManager class.
 *
 * This header file contains the declarations of the %MmsManager class.
 */


#ifndef _FMSG_MMS_MANAGER_H_
#define _FMSG_MMS_MANAGER_H_

// Includes
#include <FBase.h>
#include <FMsgIMmsListener.h>
#include <FMsgMmsMessage.h>
#include <FMsgRecipientList.h>

namespace Tizen { namespace Messaging
{

	// forward declaration for class extension
	class _MmsManagerImpl;

	/**
	* @class	MmsManager
	* @brief	This class provides methods to use the MMS messaging service.
	*
	* @since		2.0
	*
	* The %MmsManager class is used to send MMS messages.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*
	* The following example demonstrates how to use the %MmsManager class.
	*
	* @code
	*
	// Creates a listener to override the OnMmsMessageSent() method of IMmsListener
	// in order to be notified of a change in the state of the message being sent.

	class MmsListener
		: public IMmsListener
		, public Object
	{
	public:
		void OnMmsMessageSent(result r);
	};
	void MmsListener::OnMmsMessageSent(result r)
	{
		// Do something.
	}

	class SendMmsMessage
		: public Object
	{
	public:
		void MmsTest(void);
	};

	void
	SendMmsMessage::MmsTest(void)
	{
		result r = E_SUCCESS;

		// Creates an MmsListener instance.
		MmsListener* pListener = new MmsListener();

		// Creates an MMS manager instance with the listener as the callback to check the status of the message being sent.
		MmsManager* pMmsManager = new MmsManager();
		r = pMmsManager->Construct(*pListener);

		// Creates a recipient list instance and add recipients.
		RecipientList recipient;
		r = recipient.Add (RECIPIENT_TYPE_TO, L"01012345678");
		r = recipient.Add (RECIPIENT_TYPE_CC, L"01012345679");
		r = recipient.Add (RECIPIENT_TYPE_BCC, L"01012345670");

		// Creates an MMS message instance.
		MmsMessage mmsMessage;
		r = mmsMessage.SetSubject(L"Subject!!!");
		r = mmsMessage.SetText(L"Hello, World");
		r = mmsMessage.AddAttachment(MMS_IMAGE, L"/Home/Res/image.jpg");
		r = mmsMessage.AddAttachment(MMS_IMAGE, L"/Home/Res/audio.wav");

		// Sends the message, and set the saveToSentbox parameter to true if the message should be saved in the Sentbox; otherwise, set to false.
		// MmsListener callback is called once the message has been completely sent.
		r = pMmsManager->Send(mmsMessage, recipient, true);
	}
	*
	* @endcode
	*/
	class _OSP_EXPORT_ MmsManager
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		*	This is the default constructor for this class.
		*
		* @since		2.0
		*/
		MmsManager(void);

		/**
		*	This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~MmsManager(void);

	private:
		MmsManager(const MmsManager& value);
		MmsManager& operator =(const MmsManager& rhs);

		// Operation
	public:
		/**
		* Initializes this instance of %MmsManager with the specified parameter.
		*
		* @since		2.0
		*
		* @feature		%http://tizen.org/feature/network.telephony.mms
		* @return		An error code
		* @param[in]	listener		The listener to receive a send result asynchronously
		* @exception 	E_SUCCESS		The method is successful.
		* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
		* @exception  	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @b Since: @b 2.1
		* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
		* @remarks	Before calling this method, check whether the feature is supported by 
		*			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
		*/
		result			Construct(IMmsListener &listener);

		/**
		* Sends the MMS message.
		*
		* @since		2.0
		* @privlevel	public
		* @privilege	%http://tizen.org/privilege/messaging.write @n
		* 				(%http://tizen.org/privilege/messaging.mms is deprecated.)
		*
		* @return		An error code
		* @param[in]	message					The message to send
		* @param[in]	recipientList			The list of recipients
		* @param[in]	saveToSentbox			Set to @c true to save the message in the Sentbox, @n
		*										else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_ON_INITIALIZING		The mailbox is not completely loaded as yet.
		* @exception	E_STORAGE_FULL			The storage is full.
		* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_INVALID_CONDITION		The profile is not set.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FDN_MODE				The FDN mode has been activated.
		* @exception	E_INVALID_ARG			The number of recipients is @c 0 or the message is empty.
		* @exception	E_MAX_EXCEEDED			The number of recipients has crossed the maximum limit (Maximum 10).
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @exception    E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
		* @remarks		
		*				- Some service providers may not support sending MMS messages with an empty subject or body.
		*				- In this case, the result of the status report will be the E_FAILURE exception.
		*				- The CC and BCC recipients in the @c recipientList are merged with the TO recipients when sending an MMS message.
		* @see			IMmsListener::OnMmsMessageSent()
		*/
		result Send(const MmsMessage& message, const RecipientList& recipientList, bool saveToSentbox);

	private:
		_MmsManagerImpl* __pImpl;

	// friend class
	friend class _MmsManagerImpl;
	}; // MmsManager
} } // Tizen::Messaging
#endif // _FMSG_MMS_MANAGER_H_
