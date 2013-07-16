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
* @file			FMsgIEtwsPrimaryNotificationEventListener.h
* @brief		This is the header file for the %IEtwsPrimaryNotificationEventListener interface.
*
* This header file contains the declarations of the %IEtwsPrimaryNotificationEventListener interface.
*/

#ifndef _FMSG_IETWS_PRIMARY_NOTIFICATION_EVENT_LISTENER_H_
#define _FMSG_IETWS_PRIMARY_NOTIFICATION_EVENT_LISTENER_H_

#include <FMsgICbsMessageEventListener.h>

namespace Tizen { namespace Messaging
{
	class EtwsPrimaryNotification;

	/**
	* @interface	IEtwsPrimaryNotificationEventListener
	* @brief		This interface is the listener interface for receiving ETWS primary notification.
	*
	* @since		2.0
	*
	* The %IEtwsPrimaryNotificationEventListener interface must be implemented to handle incoming ETWS primary notification.
	* An application must register this interface using the SmsManager::SetEtwsPrimaryNotificationEventListener() method.
	*/
	class _OSP_EXPORT_ IEtwsPrimaryNotificationEventListener
		: virtual public Tizen::Messaging::ICbsMessageEventListener
	{
	public:
		/**
		* This polymorphic destructor should be overridden if required. @n
		* This way, the destructors of the derived classes are called when the destructor of this interface is called.

		*
		* @since		2.0
		*/
		virtual ~IEtwsPrimaryNotificationEventListener(void) {}

		/**
		* Called when the ETWS primary notification is received.
		*
		* @since		2.0
		*
		* @param[in]	message			The ETWS primary notification that is received
		* @see			SmsManager::SetEtwsPrimaryNotificationEventListener()
		*/
		virtual void OnEtwsPrimaryNotificationReceived(const EtwsPrimaryNotification& message) = 0;

	protected:
		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void IEtwsPrimaryNotificationEventListener_Reserved1(void) {}

		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void IEtwsPrimaryNotificationEventListener_Reserved2(void) {}
	}; // IEtwsPrimaryNotificationEventListener
} } // Tizen::Messaging
#endif // _FMSG_IETWS_PRIMARY_NOTIFICATION_EVENT_LISTENER_H_
