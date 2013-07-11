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
 * @file		FMsgIMmsListener.h
 * @brief		This is the header file for the %IMmsListener interface.
 *
 * This header file contains the declarations of the %IMmsListener interface.
 */

#ifndef _FMSG_IMMS_LISTENER_H_
#define _FMSG_IMMS_LISTENER_H_

// Includes
#include <FBase.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{


	/**
	* @interface	IMmsListener
	* @brief		This is the listener interface for receiving MMS sent status.
	*
	* @since		2.0
	*
	* The %IMmsListener interface must be implemented to receive the status of the sent MMS messages asynchronously. An application must register this interface using the MmsManager::Construct() method.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _OSP_EXPORT_ IMmsListener
		: virtual public Tizen::Base::Runtime::IEventListener
	{
		// Lifecycle
	public:
		/**
		 * This is the destructor for this class.
		 *
		 * @since		2.0
		 */
		virtual ~IMmsListener(void) {}

		// Operation
	public:
		/**
		* Called when the Multimedia Messaging Service(MMS) message is sent.
		*
		* @since		2.0
		*
		* @param[in]	r						The result of sending the MMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_CONTENT		The content is invalid.
		* @exception	E_NETWORK_UNAVAILABLE	The network has a problem.
		* @exception	E_SERVICE_UNAVAILABLE	The service is unavailable.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FAILURE				The method has failed to send the message.
		* @see			MmsManager::Send()
		*/
		virtual void OnMmsMessageSent(result r) = 0;

	protected:
		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void IMmsListener_Reserved1(void) {}

		//
		// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
		//
		// This method is reserved and may change its name at any time without prior notice.
		//
		// @since		2.0
		//
		virtual void IMmsListener_Reserved2(void) {}
	}; // IMmsListener
} } // Tizen::Messaging

#endif // _FMSG_IMMS_LISTENER_H_
