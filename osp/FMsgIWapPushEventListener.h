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
* @file			FMsgIWapPushEventListener.h
* @brief		This is the header file for the %IWapPushEventListener interface.
*
* This header file contains the declarations of the %IWapPushEventListener interface.
*/

#ifndef _FMSG_IWAP_PUSH_EVENT_LISTENER_H_
#define _FMSG_IWAP_PUSH_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FMsgWapPushMessage.h>

namespace Tizen { namespace Messaging
{
/**
* @interface	IWapPushEventListener
* @brief		This interface is the listener interface for receiving WAP Push messages.
*
* @since		2.0
*
* The %IWapPushEventListener interface must be implemented to receive WAP Push messages. An application must register this interface using the WapPushManager::AddWapPushEventListener() method.
*/
class _OSP_EXPORT_ IWapPushEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived 
	* classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IWapPushEventListener(void) {}

public:
	/**
	* Called when a WAP Push message is received.
	*
	* @since		2.0
	*
	* @param[in]	message		The WAP push message
	*/
	virtual void OnWapPushMessageReceived(const WapPushMessage& message) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IWapPushEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IWapPushEventListener_Reserved2(void) {}
}; // IWapPushEventListener

} } // Tizen::Messaging
#endif // _FMSG_IWAP_PUSH_EVENT_LISTENER_H_
