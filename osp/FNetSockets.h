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
* @file		FNetSockets.h
* @brief	This is the header file for the %Sockets namespace.
*
* This header file contains the declarations and descriptions of the %Sockets namespace.
*/

#ifndef _FNET_SOCKETS_H_
#define _FNET_SOCKETS_H_

#include <FNetSockSocket.h>
#include <FNetSockISocketEventListener.h>
#include <FNetSockSecureSocket.h>
#include <FNetSockISecureSocketEventListener.h>
#include <FNetSockSocketIpMulticastRequestOption.h>
#include <FNetSockSocketLingerOption.h>
#include <FNetSockSocketUtility.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net
{
/**
* @namespace	Tizen::Net::Sockets
* @brief		This namespace contains the classes and interfaces for Transmission Control Protocol (TCP) or User Datagram Protocol (UDP) socket
*				programming.
* @since        2.0
*
* @remarks      @b Header @b %file: @b \#include @b <FNet.h> @n
*				@b Library : @b osp-net @n
*
* The %Tizen::Net::Sockets sub-namespace implements the socket data communication protocols by providing a rich set of methods for connecting,
*				sending, and receiving data over a network.
*
* For more information on the %Sockets namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*
* The following diagram illustrates the relationships between the classes belonging to the %Sockets namespace.
* @image html net_socket_using_the_apis_classdiagram.png
*
* The following example demonstrates how to use a TCP client non-blocking socket.
*
*				@code
*				result res = E_SUCCESS;
*
*				// Creates the socket.
*				Socket* pClientSocket = new Socket();
*				res = pClientSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_STREAM, NET_SOCKET_PROTOCOL_TCP);
*
*				// Adds listener.
*				MySocketClientListener* pSockClientListener = new MySocketClientListener();
*				res = pClientSocket->AddSocketListener(*pSockClientListener);
*
*				// Selects asynchronous event (non-blocking mode).
*				res = pClientSocket->AsyncSelectByListener(NET_SOCKET_EVENT_CONNECT| NET_SOCKET_EVENT_CLOSE);
*
*				// Creates peer endpoint.
*				Ip4Address peerAddr("XXX.XXX.XXX.XXX"); // Server socket address.
*				unsigned short peerPort = YYY;  // Port
*				NetEndPoint* pPeerEndPoint = new NetEndPoint(peerAddr, peerPort);
*
*				// Connects the socket.
*				res = pClientSocket->Connect(*pPeerEndPoint);
*				@endcode
*/
namespace Sockets
{
} } } // Tizen::Net::Sockets
#endif // _FNET_SOCKETS_H_
