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
 * @file		FMsgIPushEventListener.h
 * @brief		This is the header file for the %IPushEventListener interface.
 *
 * This header file contains the declaration of the %IPushEventListener interface.
 */

#ifndef _FMSG_IPUSH_EVENT_LISTENER_H_
#define _FMSG_IPUSH_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FMsgPushMessage.h>

namespace Tizen { namespace Messaging
{
/**
* @interface	IPushEventListener
* @brief		This is the listener interface for receiving push messages.
*
* @since		2.0
*
* The %IPushEventListener interface must be implemented to receive the push messages. An application must register this interface using the PushManager::Construct() method.
*/
class _OSP_EXPORT_ IPushEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IPushEventListener(void) {}

public:
	/**
	* Called when a push message is received from the server.
	*
	* @since		2.0
	*
	* @param[in]	message		The push message
	*/
	virtual void OnPushMessageReceived(const PushMessage& message) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPushEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPushEventListener_Reserved2(void) {}
}; // IPushEventListener

} } // Tizen::Messaging
#endif // _FMSG_IPUSH_EVENT_LISTENER_H_
