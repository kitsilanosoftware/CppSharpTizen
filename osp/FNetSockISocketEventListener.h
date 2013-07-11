//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//


/**
* @file		FNetSockISocketEventListener.h
* @brief	This is the header file for the %ISocketEventListener interface.
*
* This header file contains the declarations of the %ISocketEventListener interface.
*/

#ifndef _FNET_SOCK_ISOCKET_EVENT_LISTENER_H_
#define _FNET_SOCK_ISOCKET_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net { namespace Sockets
{

class Socket;

/**
* @interface	ISocketEventListener
* @brief		This interface contains a listener for the socket events.
*
* @since        2.0
*
*				The %ISocketEventListener interface specifies methods used for creating notifications about the different kinds of socket events.
*				These events are only sent out when using the socket in a non-blocking mode. A listener is registered by calling the AddSocketListener()
*				method. One of these methods is called when a socket event is generated.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*
* The following example demonstrates how to use the %ISocketEventListener interface.
*
* @code
using namespace Tizen::Net::Sockets;

class TestListener
	: public Object
	, public virtual ISocketEventListener
{
public:
	TestListener() {}

	~TestListener() {}

	void OnSocketConnected(Socket& socket)
	{
		AppLog("OnConnected\n");
	}

	void OnSocketClosed(Socket& socket, NetSocketClosedReason reason)
	{
		AppLog("OnClosed\n");
	}

	void OnSocketReadyToReceive(Socket& socket)
	{
		AppLog("OnReadyToReceive\n");
	}

	void OnSocketReadyToSend(Socket& socket)
	{
		AppLog("OnReadyToSend\n");
	}
};
* @endcode
*/
class _OSP_EXPORT_ ISocketEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{


public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ISocketEventListener(void) {}


public:
	/**
	* Called to notify a connecting socket that its connection attempt has been completed successfully.
	*
	* @since        2.0
	*
	* @param[in]	socket		The Socket instance
	*/
	virtual void OnSocketConnected(Socket& socket) = 0;

	/**
	* Called to notify the registered socket that the peer socket has been closed due to normal or forced termination of the network. @n
	* It is also used to notify a connecting socket that its connection attempt has resulted in an error.
	*
	* @since        2.0
	*
	* @param[in]	socket		The Socket instance
	* @param[in]	reason		The reason of type NetSocketClosedReason for a closed socket
	*/
	virtual void OnSocketClosed(Socket& socket, NetSocketClosedReason reason) = 0;

	/**
	* Called to notify a socket that the data is ready to be retrieved.
	*
	* @since        2.0
	*
	* @param[in]	socket		The Socket instance
	* @remarks		The data can be retrieved by calling Receive() or ReceiveFrom().
	*/
	virtual void OnSocketReadyToReceive(Socket& socket) = 0;

	/**
	* Called to notify a socket that the data can be sent.
	*
	* @since        2.0
	*
	* @param[in]	socket		The Socket instance
	* @remarks		The data can be sent using Send() or SendTo().
	*/
	virtual void OnSocketReadyToSend(Socket& socket) = 0;

	/**
	* Called to notify a socket that it has received a new connection from a peer.
	*
	* @since        2.0
	*
	* @param[in]	socket		The Socket instance
	*/
	virtual void OnSocketAccept(Socket& socket) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ISocketEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ISocketEventListener_Reserved2(void) {}

};

} } } // Tizen::Net::Sockets
#endif // _FNET_SOCK_ISOCKET_EVENT_LISTENER_H_
