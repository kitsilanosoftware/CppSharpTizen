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
 * @file    FMsgISmsEventListener.h
 * @brief   This is the header file for the %ISmsEventListener interface.
 *
 * This header file contains the declarations of the %ISmsEventListener interface.
 */

#ifndef _FMSG_ISMS_EVENT_LISTENER_H_
#define _FMSG_ISMS_EVENT_LISTENER_H_

#include <FBase.h>

namespace Tizen { namespace Messaging
{

	class SmsMessage;


	/**
	* @interface	ISmsEventListener
	* @brief		This interface is the listener interface for receiving SMS messages.
	*
	* @since		2.0
	*
	* The %ISmsEventListener interface is the listener interface for receiving SMS messages.
    * An application implements this interface and registers it using the SmsManager::AddSmsEventListener() method to receive SMS messages.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _OSP_EXPORT_ ISmsEventListener
		: virtual public Tizen::Base::Runtime::IEventListener
	{
		// Lifecycle
	public:
		/**
		 * This is the destructor for this class.
		 *
		 * @since		2.0
		 */
		virtual ~ISmsEventListener(void) {}

		// Operations
	public:
		/**
		* Called when an SMS message is received.
		*
		* @since		2.0
		*
		* @param[in]	port				A port number
		* @param[in]	dateTime			The date and time when the message is received
		* @param[in]	message				The message that is received
		* @see			SmsManager::AddSmsEventListener()
        * @see  		SmsManager::RemoveSmsEventListener()
		*/
		virtual void OnSmsMessageReceived(int port, const Tizen::Base::DateTime& dateTime, const SmsMessage& message) = 0;

	protected:
		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void ISmsEventListener_Reserved1(void) {}

		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void ISmsEventListener_Reserved2(void) {}
	}; // ISmsEventListener

} } // Tizen::Messaging
#endif // _FMSG_ISMS_EVENT_LISTENER_H_
