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
 * @file		FIoIChannelResponseEventListener.h
 * @brief		This is the header file for the %IChannelResponseEventListener interface.
 *
 * This header file contains the declarations of the %IChannelResponseEventListener interface.
 *
 */
#ifndef _FIO_ICHANNEL_RESPONSEEVENT_LISTENER_H_
#define _FIO_ICHANNEL_RESPONSEEVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseDataType.h>
#include <FBaseRtIEventListener.h>
#include <FBase.h>
#include <FAppTypes.h>

namespace Tizen { namespace Io
{

class ClientChannel;
/**
* @if OSPDEPREC
* @interface IChannelResponseEventListener
* @brief    <i> [Deprecated] </i> This interface provides event handlers for any response events received through a channel.
*
* @deprecated	This class is deprecated. Instead of using this class, use the MessagePortManager class.
* @since    2.0
*
*  The %IChannelResponseEventListener interface provides event handlers for receiving the channel response events.
* @endif
*/
class _OSP_EXPORT_ IChannelResponseEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since   2.0
	 */
	virtual ~IChannelResponseEventListener(void) {}

	/**
     * Called when a response is received from a server channel.
	 *
	 * @since        2.0
	 *
	 * @param[in] reqId				The request ID
	 * @param[in] clientChannel		The reference to the client channel
	 * @param[in] serverChannelId	The server channel ID
	 * @param[in] pArgs         	A pointer to an argument list of type String
	 *
	 */
	virtual void OnChannelResponseReceivedN(RequestId reqId, ClientChannel& clientChannel, const Tizen::Base::String& serverChannelId, Tizen::Base::Collection::IList* pArgs) = 0;


protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IChannelResponseEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since           2.0
	//
	virtual void IChannelResponseEventListener_Reserved3(void) {}
}; // IChannelResponseEventListener

} } // Tizen::Io

#endif // _FIO_ICHANNEL_RESPONSEEVENT_LISTENER_H_
