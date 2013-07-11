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
 * @file		FMsgIEmailListener.h
 * @brief		This is the header file for the %IEmailListener interface.
 *
 * This header file contains the declarations of the %IEmailListener interface.
 */

#ifndef _FMSG_IEMAIL_EVENT_LISTENER_H_
#define _FMSG_IEMAIL_EVENT_LISTENER_H_

// Includes
#include <FBase.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{

	/**
	* @interface	IEmailListener
	* @brief		This is the listener interface for receiving email sent status.
	*
	* @since		2.0
	*
	* The %IEmailListener interface must be implemented to receive the status of the sent email messages asynchronously. An application must register this interface using the EmailManager::Construct() method.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _OSP_EXPORT_ IEmailListener
		: virtual public Tizen::Base::Runtime::IEventListener
	{
		// Lifecycle
	public:
		/**
		 * This is the destructor for this class.
		 *
		 * @since		2.0
		 */
		virtual ~IEmailListener(void) {}

		// Operation
	public:
		/**
		* Called when the email message is sent.
		*
		* @since		2.0
		*
		* @param[in]	r						The result of sending the email message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_FAILURE				The method has failed to send the message.
		* @see			EmailManager::Send()
		*/
		virtual void OnEmailMessageSent(result r) = 0;

	protected:
		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void IEmailListener_Reserved1(void) {}

		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void IEmailListener_Reserved2(void) {}
	}; // IEmailListener
} } // Tizen::Messaging

#endif // _FMSG_IEMAIL_EVENT_LISTENER_H_
