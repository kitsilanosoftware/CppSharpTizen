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
* @file		FNetSockSocketIpMulticastRequestOption.h
* @brief	This is the header file for the %IpMulticastRequestOption class.
*
* This header file contains the declarations of the %IpMulticastRequestOption class.
*/

#ifndef _FNET_SOCK_SOCKET_IP_MULTICAST_REQUEST_OPTION_H_
#define _FNET_SOCK_SOCKET_IP_MULTICAST_REQUEST_OPTION_H_

#include <FBaseObject.h>
#include <FNetNetEndPoint.h>

namespace Tizen { namespace Net { namespace Sockets
{

class _IpMulticastRequestOptionImpl;

/**
* @class	IpMulticastRequestOption
* @brief	This class supports the multicasting in sockets for sending and receiving multicast datagram packets.
*			For multicasting, a socket must be of type NET_SOCKET_TYPE_DATAGRAM.
*
* @since	2.0
*
* The %IpMulticastRequestOption class supports the multicasting in sockets for sending and receiving multicast datagram packets.
*			For multicasting, a socket must be of type NET_SOCKET_TYPE_DATAGRAM.
*
*	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*
* @see		Tizen::Net::Sockets::Socket::SetSockOpt(NetSocketOptLevel, NetSocketOptName, const IpMulticastRequestOption&)
*
* The following example demonstrates how to use the %IpMulticastRequestOption class with the multicast sender.
*
*	@code
*				result res = E_SUCCESS;
*
*				// Creates the socket.
*				Socket* pSocket = new Socket();
*				res = pSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_DATAGRAM, NET_SOCKET_PROTOCOL_UDP);
*
*				// Adds the listener.
*				MySocketListener* pSockListener = new MySocketListener();
*				res = pSocket->AddSocketListener(*pSockListener);
*
*				// Selects the async event(non-blocking mode).
*				res = pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_WRITE);
*
*				// Creates the multicast group end point to send the data.
*				Ip4Address multicastAddr("224.1.1.1"); // Multicast group address
*				unsigned short multicastPort = XXXX;  // Multicast group port
*				NetEndPoint multicastEndPoint(multicastAddr, multicastPort);
*
*				// Creates the data to send.
*				const char* pSendData = "Send";
*				Tizen::Base::ByteBuffer txBuffer;
*				txBuffer.Construct(strlen(pSendData) + 1);
*				txBuffer.SetArray((byte*)pSendData, 0, strlen(pSendData));
*				txBuffer.Flip();
*
*				// Sends the data to the multicast group
*				res = ptSocket->SendTo(txBuffer, multicastEndPoint);
*	@endcode
*
* The following example demonstrates how to use the %IpMulticastRequestOption class with the multicast receiver.
*
*	@code
*				result res = E_SUCCESS;
*
*				// Creates the socket.
*				Socket* pSocket = new Socket();
*				res = pSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_DATAGRAM, NET_SOCKET_PROTOCOL_UDP);
*
*				// Adds the listener.
*				MySocketListener* pSockListener = new MySocketListener();
*				res = pSocket->AddSocketListener(*pSockListener);
*
*				// Selects the async event(non-blocking mode).
*				res = pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_READ);
*
*				// Binds the local interface end point to receive the data.
*				Ip4Address localAddr(NET_SOCKET_INADDR_ANY); // Any incoming interface
*				unsigned short localPort = XXXX;  // Multicast group port
*				NetEndPoint localEndPoint(localAddr, localPort);
*				res = pSocket->Bind(localEndPoint);
*
*				// Creates the multicast group end point.
*				Ip4Address multicastAddr("224.1.1.1"); // Multicast group address
*				unsigned short multicastPort = YYYY;  // Any available port, which will not be used for other operations
*				NetEndPoint multicastEndPoint(multicastAddr, multicastPort);
*
*				// Creates the local interface end point.
*				Ip4Address interfaceAddr(NET_SOCKET_INADDR_ANY); // Local interface address
*				unsigned short interfacePort = ZZZZ;  // Any available port, which will not be used for other operations
*				NetEndPoint interfaceEndPoint(interfaceAddr, interfacePort);
*
*				// Specifies the IpMulticastRequestOption.
*				IpMulticastRequestOption ipMreq(multicastEndPoint, interfaceEndPoint);
*
*				// Joins the multicast group.
*				res = pSocket->SetSockOpt(NET_SOCKET_IPPROTO_IP, NET_SOCKET_IP_ADD_MEMBERSHIP, ipMreq);
*
*				// Creates the buffer to receive the data.
*				Tizen::Base::ByteBuffer rxBuffer;
*				rxBuffer.Construct(MAX_BUFFER_SIZE);
*
*				// Receives the data from the multicast group.
*				res = pSocket->ReceiveFrom(rxBuffer, localEndPoint);
*	@endcode
*/
class _OSP_EXPORT_ IpMulticastRequestOption
	: public Tizen::Base::Object
{

public:
	/**
	 * Initializes this instance of %IpMulticastRequestOption with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @param[in]	multicastAddress		A NetEndPoint instance containing the IP address and port of the multicast group to join
	 * @param[in]	interfaceAddress		A NetEndPoint instance containing the IP address and port of the network interface on which the datagram
	 *										packets will be received
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	IpMulticastRequestOption(const NetEndPoint& multicastAddress, const NetEndPoint& interfaceAddress);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~IpMulticastRequestOption(void);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @param[in]	rhs			An instance of %IpMulticastRequestOption
	*/
	IpMulticastRequestOption(const IpMulticastRequestOption& rhs);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since		2.0
	*
	* @return		A reference to this instance
	* @param[in]	rhs			An instance of %IpMulticastRequestOption
	*/
	IpMulticastRequestOption& operator =(const IpMulticastRequestOption& rhs);

public:
	/**
	 * Sets the multicast group NetEndPoint instance with the specified instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	multicastAddress		A NetEndPoint instance containing the IP address and port of the multicast group to join
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result SetMulticastEndPoint(NetEndPoint& multicastAddress);

	/**
	 * Sets the network interface NetEndPoint with the specified instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	interfaceAddress		A NetEndPoint instance containing the address and port of the network interface on which the datagram
	 *										packets will be received
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result SetInterfaceEndPoint(NetEndPoint& interfaceAddress);

	/**
	* Gets the NetEndPoint of the multicast group.
	*
	* @since		2.0
	*
	* @return		The multicast group NetEndPoint, @n
	*				else @c null if the multicast group %NetEndPoint is @c null
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			The group end point is in an invalid state.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	const NetEndPoint* GetMulticastEndPoint(void) const;

	/**
	* Gets the NetEndPoint of the network interface.
	*
	* @since		2.0
	*
	* @return		The network interface NetEndPoint, @n
	*				else @c null if the network interface %NetEndPoint is @c null
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The interface end point is in an invalid state.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	const NetEndPoint* GetInterfaceEndPoint(void) const;

	/**
	 * Compares the specified instance of %IpMulticastRequestOption with the calling instance.
	 *
	 * @since		2.0
	 * @return		@c true if the values match, @n
	 *			else @c false
	 * @param[in]	obj 	The other Object to be compared
	 * @see 		Object::Equals()
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return  	The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	IpMulticastRequestOption(void);

private:
	_IpMulticastRequestOptionImpl* __pIpMulticastRequestOptionImpl;

	friend class _IpMulticastRequestOptionImpl;
};

} } } // Tizen::Net::Sockets
#endif // _FNET_SOCK_SOCKET_IP_MULTICAST_REQUEST_OPTION_H_
