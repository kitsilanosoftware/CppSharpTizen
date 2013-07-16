//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file		FIoIMessagePortListener.h
 * @brief		This is the header file for the %IMessagePortListener interface.
 *
 * This header file contains declarations of the %IMessagePortListener interface.
 */

#ifndef _FIO_IMESSAGE_PORT_LISTENER_H_
#define _FIO_IMESSAGE_PORT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseColIMap.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Io
{

class RemoteMessagePort;

/**
* @interface IMessagePortListener
* @brief    This interface provides event handlers to receive messages from other applications.
*
* @since    2.0
*
* The %IMessagePortListener interface provides event handlers to receive messages from other applications.
*/
class _OSP_EXPORT_ IMessagePortListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since   2.0
	 */
	virtual ~IMessagePortListener(void) {}

	/**
	 * Called when a message is received from a remote application. @n
	 * This method will be called only if the remote application uses bidirectional communication method - RemoteMessagePort::SendMessage(const LocalMessagePort* pLocalMessagePort, const Tizen::Base::Collection::IMap* pMessagee).
	 * The RemoteMessagePort instance can be used to send a response message to the message port of the remote application.
	 *
	 * @since        2.0
	 *
	 * @param[in] pRemoteMessagePort	The message port of a remote application which has sent this message
	 * @param[in] pMessage				A pointer to an argument map of key (String) and value (String or ByteBuffer) pair
	 */
	virtual void OnMessageReceivedN(RemoteMessagePort* pRemoteMessagePort, Tizen::Base::Collection::IMap* pMessage) {}

	/**
	 * Called when a message is received from a remote application. @n
	 * This method will be called only if the remote application uses unidirectional communication method - RemoteMessagePort::SendMessage(const Tizen::Base::Collection::IMap* pMessage).
	 *
	 * @since        2.0
	 *
	 * @param[in] pMessage				A pointer to an argument map of key (String) and value (String or ByteBuffer) pair
	 */
	virtual void OnMessageReceivedN(Tizen::Base::Collection::IMap* pMessage) {}

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IMessagePortListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IMessagePortListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IMessagePortListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IMessagePortListener_Reserved4(void) {}
}; // IMessagePortListener

} } // Tizen::Io

#endif // _FIO_IMESSAGE_PORT_LISTENER_H_
