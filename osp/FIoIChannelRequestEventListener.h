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
 * @file		FIoIChannelRequestEventListener.h
 * @brief		This is the header file for the %IChannelRequestEventListener interface.
 *
 * This header file contains the declarations of the %IChannelRequestEventListener interface.
 */

#ifndef _FIO_ICHANNEL_REQUESTEVENT_LISTENER_H_
#define _FIO_ICHANNEL_REQUESTEVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseDataType.h>
#include <FBaseRtIEventListener.h>
#include <FBase.h>
#include <FAppTypes.h>

namespace Tizen { namespace Io
{

class ServerChannel;

/**
* @if OSPDEPREC
* @interface IChannelRequestEventListener
* @brief    <i> [Deprecated] </i> This interface provides event handlers for any request events received through a channel.
*
* @deprecated	This interface is deprecated. Instead of using this interface, use the IMessagePortListener interface.
* @since    2.0
*
* The %IChannelRequestEventListener interface provides event handlers to receive channel request event.
* @endif
*/
class _OSP_EXPORT_ IChannelRequestEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since   2.0
	 */
	virtual ~IChannelRequestEventListener(void) {}

	/**
	 * Called when a request is received from the client channel.
	 *
	 * @since        2.0
	 *
	 * @param[in] reqId               The request ID
	 * @param[in] serverChannel       The reference to the server channel
	 * @param[in] clientChannelId     The client channel ID
	 * @param[in] pArgs               A pointer to an argument list of type String
	 */
	virtual void OnChannelRequestReceivedN(RequestId reqId, ServerChannel& serverChannel, const Tizen::Base::String& clientChannelId, Tizen::Base::Collection::IList* pArgs) = 0;


protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IChannelRequestEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IChannelRequestEventListener_Reserved2(void) {}
}; // IChannelRequestEventListener

} } // Tizen::Io

#endif // _FIO_ICHANNEL_REQUESTEVENT_LISTENER_H_
