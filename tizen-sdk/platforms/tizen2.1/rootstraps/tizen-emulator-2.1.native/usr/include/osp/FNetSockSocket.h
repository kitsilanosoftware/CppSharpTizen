//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
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
* @file		FNetSockSocket.h
* @brief	This is the header file for the %Socket class.
*
* This header file contains the declarations of the %Socket class. @n
* This class is a base class that provides methods for sending and receiving the data over a network.
*/

#ifndef _FNET_SOCK_SOCKET_H_
#define _FNET_SOCK_SOCKET_H_

#include <FBaseObject.h>
#include <FNetNetEndPoint.h>
#include <FNetNetConnection.h>
#include <FNetSockSocketTypes.h>
#include <FNetSockSocketLingerOption.h>
#include <FNetSockSocketIpMulticastRequestOption.h>
#include <FNetSockISocketEventListener.h>

namespace Tizen { namespace Net { namespace Sockets
{

class _SocketImpl;

/**
* @class	Socket
* @brief	This class is the base class that provides simple methods for sending and receiving the data over a network.
*
* @since    2.0
*
* The %Socket class is the base class that provides simple methods for sending and receiving the data over a network.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*/
class _OSP_EXPORT_ Socket
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since        2.0
	*/
	Socket(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since        2.0
	*
	* @see          Close()
	*/
	virtual ~Socket(void);

	/**
	* Initializes this instance of %Socket with the specified parameters. @n
	* The socket is initialized in a non-blocking mode by default.
	* Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %Socket in the blocking mode.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	netConnection				A run-time session where a %Socket instance is used
	* @param[in]	addressFamily				A ::NetSocketAddressFamily value
	* @param[in]	socketType					A ::NetSocketType value
	* @param[in]	protocol					A ::NetSocketProtocol value
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_MAX_EXCEEDED			All sockets are in use.
	* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	* @exception	E_UNSUPPORTED_TYPE		The socket type is not supported.
	* @exception	E_UNSUPPORTED_FAMILY		The address family is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_INVALID_CONNECTION		The network connection is invalid.
	* @exception	E_FAILURE					The method has failed.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks      The @c netConnection parameter specifies a run-time network connection. @n
	*				The @c addressFamily parameter specifies an address family. @n
	*				The @c socketType parameter specifies the type of the socket. @n
	*				The @c protocol parameter specifies the protocol used by the socket. @n
	*				The first parameter must be a valid run-time network connection.
	*				The three parameters (without @c netConnection) are not independent.
	*				Some address families restrict the protocols that can be used with them,
	*				and often the socket type is implicit in the protocol.
	*				If the combination of the address family, socket type, and protocol type results in
	*				an invalid socket, this method returns an error. @n
	*				This method is used for a socket of the type NET_SOCKET_PROTOCOL_TCP, NET_SOCKET_PROTOCOL_UDP, or NET_SOCKET_PROTOCOL_SSL. @n
	*				If the blocking mode is being used, and a method call is made which does not
	*				complete immediately, the application blocks the execution until the requested operation is completed. @n@n
	*				If the execution is to be continued even though the requested operation
	*				is not complete, the non-blocking mode should be used, which is the default mode in this method. @n
	*				For each socket used in the non-blocking mode, an event listener (ISocketEventListener) should be registered
	*				and maintained, so that it can receive asynchronous notifications of the socket events. @n
	*				To register the listener, AddSocketListener() should be used after calling this method. @n
	*				If a socket in the blocking mode needs to be used, Ioctl() (with NET_SOCKET_FIONBIO) should be called after initializing the socket
	*				through this method.
	* @see			Ioctl() for understanding the blocking/non-blocking mode
	*/
	result Construct(const NetConnection& netConnection, NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

	/**
	* Initializes this instance of %Socket with the specified parameters. @n
	* The socket is initialized in a non-blocking mode by default.
	* Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %Socket in the blocking mode.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	addressFamily				A ::NetSocketAddressFamily value
	* @param[in]	socketType					A ::NetSocketType value
	* @param[in]	protocol					A ::NetSocketProtocol value
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_MAX_EXCEEDED				All sockets are in use.
	* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
	* @exception	E_UNSUPPORTED_TYPE			The socket type is not supported.
	* @exception	E_UNSUPPORTED_FAMILY		The address family is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_INVALID_CONNECTION		The network connection is invalid.
	* @exception	E_FAILURE					The method has failed.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		The @c addressFamily parameter specifies an address family. @n
	*				The @c socketType parameter specifies the type of the socket. @n
	*				The @c protocol parameter specifies the protocol used by the socket. @n
	*				The three parameters are not independent.
	*				Some address families restrict the protocols that can be used with them,
	*				and often the socket type is implicit in the protocol.
	*				If the combination of the address family, socket type, and protocol type results in
	*				an invalid socket, this method returns an error. @n
	*				This method is used for a socket of the type NET_SOCKET_PROTOCOL_TCP, NET_SOCKET_PROTOCOL_UDP, or NET_SOCKET_PROTOCOL_SSL. @n
	*				If the blocking mode is being used, and a method call is made which does not
	*				complete immediately, the application blocks the execution
	*				until the requested operation is completed. @n@n
	*				If the execution is to be continued even though the requested operation
	*				is not complete, the non-blocking mode should be used, which is the default mode in this method. @n
	*				For each socket used in the non-blocking mode, an event listener (ISocketEventListener) should be registered
	*				and maintained, so that it can receive asynchronous notifications of the socket events. @n
	*				To register the listener, AddSocketListener() should be used after calling this method. @n
	*				If a socket in the blocking mode needs to be used, Ioctl (with NET_SOCKET_FIONBIO) should be called after initializing the socket
	*				through this method.
	* @see			Ioctl() for understanding the blocking/non-blocking mode
	*/
	result Construct(NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

public:
	/**
	* Closes the socket. @n
	* All the resources associated with the socket are freed.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		If the %Socket class is not initialized through one of the Construct() methods, or this method is called more than once,
	*				then this method returns E_INVALID_STATE.
	*/
	result Close(void);

	/**
	* Establishes a connection to a remote host for a connection-oriented socket. @n
	* This socket is of the type NET_SOCKET_TYPE_STREAM.
	*
	* @since            2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return			An error code
	* @param[in]		remoteEndPoint				An instance of NetEndPoint representing the remote device
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_SOCKET			The socket is invalid.
	* @exception		E_INVALID_STATE				The socket is not in a valid state.
	* @exception		E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
	* @exception		E_IN_PROGRESS				A previous request is in progress.
	* @exception		E_INVALID_ARG				The specified input parameter is invalid.
	* @exception		E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception		E_CONNECTION_FAILED			The socket is not connected.
	* @exception		E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception		E_ALREADY_CONNECTED			The socket is already connected.
	* @exception		E_UNSUPPORTED_FAMILY		The address family is not supported.
	* @exception		E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
	* @exception        E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception		E_SYSTEM					A system error has occurred.
	* @exception        E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks			If the socket is a connectionless socket (that is, of the type NET_SOCKET_TYPE_DATAGRAM), this method fails.
	*					After this method is called, ISocketEventListener::OnSocketConnected() is called. the data can be sent to and received from the remote device using Send() and Receive() respectively.
	*					If a connection-oriented protocol is used and Bind() is not called before calling this method, the underlying service provider
	*					assigns the local network address and port number.
	*/
	result Connect(const Tizen::Net::NetEndPoint& remoteEndPoint);

	/**
    * @page			SocketConnectPage        Compatibility for Connect()
    *
    * @section		SocketConnectPageIssueSection Issues
    * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SYSTEM.
    *
    * @section		SocketConnectPageResolutionSection Resolutions
    *  The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
    *  -# If the application provides a loopback address in NetEndPoint, it returns E_SUCCESS instead of E_SYSTEM.
    */

	/**
	* Sends the data to a socket of the type NET_SOCKET_TYPE_STREAM.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	buffer						An instance of Tizen::Base::ByteBuffer that contains the data to send
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception  E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method sends the data to the remote host specified in the Connect() or AcceptN() method.
	*				This method sends the data in the @c buffer parameter, starting from the current position of the buffer.
	*				After the operation, the position of the buffer is incremented by the number of bytes successfully sent.
	*				The new position cannot be larger than the original limit.
	*				This method can be used only for connection-oriented sockets.
	*				In the blocking mode, if space is not available in the send queue, the socket blocks until space becomes available.
	*				In the non-blocking mode, this method returns the error E_WOULD_BLOCK.
	*				This method may complete successfully even if it sends less than the number of bytes
	*				in the buffer. The application should keep track of the number of bytes sent
	*				and retry the operation until the application sends the bytes in the buffer.
	*				There is no guarantee that the data that is sent appears on the network immediately.
	*				To increase network efficiency, the underlying system may delay transmission until a significant amount
	*				of outgoing data is collected. The successful completion of this method means that the underlying
	*				system has had room to buffer the data for a network send.
	*				If it is important for the application to send every byte to the remote host immediately,
	*				use SetSockOpt() (with NET_SOCKET_TCP_NODELAY) of the type ::NetSocketOptName to enable no delay.
	*/
	result Send(Tizen::Base::ByteBuffer& buffer);

	/**
	* Sends the data to a socket of the type NET_SOCKET_TYPE_STREAM.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	pBuffer						The pointer to the buffer containing the data to send
	* @param[in]	length						The length of the data in the buffer
	* @param[out]	sentLength					The length of the data that is sent successfully
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method sends the data to the remote host specified in the Connect() or AcceptN() method.
	*				This method sends the data in the buffer of length @c length, starting from the current position of the buffer.
	*				This method can be used only for connection-oriented sockets.
	*				In the blocking mode, if space is not available in the send queue, the socket blocks until space becomes available.
	*				In the non-blocking mode, this method returns the error E_WOULD_BLOCK.
	*				This method may complete successfully even if it sends less than the number of bytes
	*				in the buffer. The application should keep track of the number of bytes sent
	*				and retry the operation until the application sends the bytes in the buffer.
	*				There is no guarantee that the data that is sent appears on the network immediately.
	*				To increase the network efficiency, the underlying system may delay the transmission until a significant amount
	*				of outgoing data is collected. The successful completion of this method means that the underlying
	*				system has had room to buffer the data for a network send.
	*				If it is important to send every byte to the remote host immediately,
	*				use SetSockOpt() (with NET_SOCKET_TCP_NODELAY) of the type ::NetSocketOptName to enable no delay.
	*/
	result Send(void* pBuffer, int length, int& sentLength);

	/**
	* Sends the data to a socket of the type NET_SOCKET_TYPE_DATAGRAM.
	*
	* @since            2.0
	*
	* @return			An error code
	* @param[in]		buffer						An instance of Tizen::Base::ByteBuffer containing the data to send
	* @param[in]		remoteEndPoint				An instance of NetEndPoint representing the destination for the data
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_SOCKET			The socket is invalid.
	* @exception		E_INVALID_STATE				The socket is not in a valid state.
	* @exception		E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception		E_INVALID_ARG				A specified input parameter is invalid.
	* @exception		E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception		E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
	* @exception		E_OUT_OF_RANGE				The message length has exceeded the maximum limit of the socket.
	* @exception        E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception		E_SYSTEM					A system error has occurred.
	* @remarks		This method sends the data to the remote host specified by the @c remoteEndPoint parameter.
	*				This method sends the data in the @c buffer parameter, starting from the current position of the buffer.
	*				After the operation, the position of the buffer is incremented by the number of bytes successfully sent.
	*				The new position cannot be larger than the original limit.
	*				This method can be used only for connectionless sockets.
	*				In the blocking mode, if space is not available in the send queue, the socket blocks
	*				until space becomes available. If the socket is in the non-blocking mode,
	*				the error E_WOULD_BLOCK is returned.
	*/
	result SendTo(Tizen::Base::ByteBuffer& buffer, const Tizen::Net::NetEndPoint& remoteEndPoint);

	/**
    * @page			SocketSendToPage1        Compatibility for SendTo()
    *
    * @section		SocketSendToPage1IssueSection Issues
    * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SYSTEM.
    *
    * @section      SocketSendToPage1ResolutionSection Resolutions
    * The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SUCCESS instead E_SYSTEM.
    */

	/**
	* Sends the data to a socket of the type NET_SOCKET_TYPE_DATAGRAM.
	*
	* @since            2.0
	*
	* @return			An error code
	* @param[in]		pBuffer					The pointer to the buffer containing the data to send
	* @param[in]		length					The length of the data in the buffer
	* @param[in]		remoteEndPoint			An instance of NetEndPoint representing the destination for the data
	* @param[out]		sentLength				The length of the data that is sent successfully
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_SOCKET		The socket is invalid.
	* @exception		E_INVALID_STATE			The socket is not in a valid state.
	* @exception		E_UNSUPPORTED_OPTION	The specified parameters are not supported.
	* @exception		E_INVALID_ARG			A specified input parameter is invalid.
	* @exception		E_WOULD_BLOCK			A non-blocking socket operation cannot be completed immediately.
	* @exception		E_HOST_UNREACHABLE		The network cannot be reached from this host at this time.
	* @exception		E_OUT_OF_RANGE			The message length has exceeded the maximum limit of the socket.
	* @exception        E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception		E_SYSTEM				A system error has occurred.
	* @remarks			This method sends the data to the remote host specified by the @c remoteEndPoint parameter.
	*					This method sends the data in the buffer. The length of the data is specified by @c length, starting from the current
	*					position of the buffer.
	*					This method can be used only for connectionless sockets.
	*					In the blocking mode, if space is not available in the send queue, the socket blocks
	*					until space becomes available. If the socket is in the non-blocking mode,
	*					the error E_WOULD_BLOCK is returned.
	*/
	result SendTo(void* pBuffer, int length, const Tizen::Net::NetEndPoint& remoteEndPoint, int& sentLength);

	/**
    * @page			SocketSendToPage2        Compatibility for SendTo()
    *
    * @section		SocketSendToPage2IssueSection Issues
    * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SYSTEM.
    *
    * @section      SocketSendToPage2ResolutionSection Resolutions
    * The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SUCCESS instead of E_SYSTEM.
    */

	/**
	* Receives the data from a socket of the type NET_SOCKET_TYPE_STREAM.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[out]	buffer						An instance of Tizen::Base::ByteBuffer that is the storage location for the received data
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method copies the data into the @c buffer parameter, starting from the current position of the buffer.
	*				After the operation, the position of the buffer is incremented by the number of bytes successfully received.
	*				The new position cannot be larger than the original limit.
	*				This method can only be called from connection-oriented sockets.
	*				If there is no data at the socket in the blocking mode,
	*				this method blocks until the data arrives. If the socket is in the non-blocking mode,
	*				the error E_WOULD_BLOCK is returned.
	*/
	result Receive(Tizen::Base::ByteBuffer& buffer) const;

	/**
	* Receives the data from a socket of the type NET_SOCKET_TYPE_STREAM.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[out]	pBuffer						The pointer to the buffer that is the storage location for the received data
	* @param[in]	length						The length of the data in the buffer
	* @param[out]	rcvdLength					The length of the data that is received successfully
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method copies the data into the buffer. The length of the data is specified by @c length, starting from the current
	*				position of the buffer.
	*				This method can be called only from connection-oriented sockets.
	*				If there is no data at the socket in the blocking mode,
	*				this method blocks until the data arrives. If the socket is in the non-blocking mode,
	*				the error E_WOULD_BLOCK is returned.
	*/
	result Receive(void* pBuffer, int length, int& rcvdLength) const;

	/**
	* Receives the data from a socket of the type NET_SOCKET_TYPE_DATAGRAM.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[out]	buffer						An instance of Tizen::Base::ByteBuffer that is the storage location for the received data
	* @param[out]	remoteEndPoint				The NetEndPoint of the remote server
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_OUT_OF_RANGE				The message length exceeded the maximum limit.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method copies the data into the specified buffer, starting from the current position of the buffer.
	*				After the operation, the position of the buffer is incremented by the number of bytes successfully received.
	*				The new position cannot be larger than the original limit.
	*				The method returns the remote host endpoint from which the data is sent.
	*				This method can only be called from connectionless sockets; that is,
	*				this method is used only if connectionless datagrams are to be received
	*				from an unknown host or multiple hosts.
	*				This method reads the first enqueued datagram received
	*				into the local network buffer. If the datagram received is larger
	*				than the remaining bytes of the buffer, this method returns the error E_OUT_OF_RANGE.
	*				If there is no data at the socket in the blocking mode,
	*				this method blocks until the data arrives. If the socket is in the non-blocking mode,
	*				the error E_WOULD_BLOCK is returned.
	*/
	result ReceiveFrom(Tizen::Base::ByteBuffer& buffer, Tizen::Net::NetEndPoint& remoteEndPoint) const;

	/**
    * @page			SocketReceiveFromPage1  Compatibility for ReceiveFrom()
    *
    * @section		SocketReceiveFromPage1IssueSection Issues
    * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SYSTEM.
    *
    * @section		SocketReceiveFromPage1ResolutionSection Resolutions
    * The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SUCCESS instead of E_SYSTEM.
    */

	/**
	* Receives the data from a socket of the type NET_SOCKET_TYPE_DATAGRAM.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[out]	pBuffer						The pointer to the buffer that is the storage location for the received data
	* @param[in]	length						The length of the data in the buffer
	* @param[out]	remoteEndPoint				The NetEndPoint of the remote server
	* @param[out]	rcvdLength					The length of the data that is received successfully
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_OUT_OF_RANGE				The message length exceeded the maximum limit.
	* @exception  E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method copies the data into the buffer. The length of the data is specified by @c length, starting from the current
	* 				position of the buffer.
	*				The method returns the remote host endpoint from which the data is sent.
	*				This method can only be called from connectionless sockets; that is,
	*				this method is used only if connectionless datagrams are to be received
	*				from an unknown host or multiple hosts.
	*				This method reads the first enqueued datagram received
	*				into the local network buffer. If the datagram received is larger
	*				than the value of @c length parameter, this method will return an error E_OUT_OF_RANGE.
	*				If there is no data at the socket in the blocking mode,
	*				this method blocks until the data arrives. If the socket is in the non-blocking mode,
	*				the error E_WOULD_BLOCK is returned.
	*/
	result ReceiveFrom(void* pBuffer, int length, Tizen::Net::NetEndPoint& remoteEndPoint, int& rcvdLength) const;

	/**
    * @page			SocketReceiveFromPage2  Compatibility for ReceiveFrom()
    *
    * @section		SocketReceiveFromPage2IssueSection Issues
    * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SYSTEM.
    *
    * @section		SocketReceiveFromPage2ResolutionSection Resolutions
    * The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
    * -# If the application provides a loopback address in NetEndPoint, it returns E_SUCCESS instead of E_SYSTEM.
    */

	/**
	* Binds the socket to a local address.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	localEndPoint				The local NetEndPoint to associate with the socket
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_ALREADY_BOUND				The address is already in use.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		Use this method if a specific local endpoint should be used.
	*				This method can be used on both the connectionless and connection-oriented protocols.
	*				For connection-oriented sockets, this method need not be called
	*				before using the Connect() method, unless a specific local endpoint needs to be used.
	*				This method must be called before the Listen() method.
	*/
	result Bind(const Tizen::Net::NetEndPoint& localEndPoint);

	/**
	* Places the socket in a listening state.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	backLog						The maximum length of the pending connections queue
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	* @exception	E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
	* @exception	E_ALREADY_CONNECTED			The socket is already connected.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		This method causes a connection-oriented socket to listen for
	*				the incoming connection attempts. The @c backlog parameter specifies
	*				the number of incoming connections that can be queued for acceptance.
	*				The Bind() method must be called before calling this method.
	*/
	result Listen(int backLog);

	/**
	* Accepts an incoming connection. @n
	* This method extracts the first connection from the queue of pending connections, and
	* creates a new socket with the same socket type, protocol type, and protocol family
	* as the listening socket.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		A new socket for a newly created connection with the same socket type, protocol type, and protocol family, @n
	*				else @c null if an error occurs
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		Before calling this method, the Listen() method must be called first
	*				to listen for and queue the incoming connection requests.
	*				In the blocking mode, this method blocks until an incoming connection attempt
	*				is queued. After accepting a connection, the original socket
	*				continues queuing the incoming connection requests until it is closed.
	*				Note that if no connection is pending in the queue and the socket is in the blocking mode,
	*				this method blocks until a new connection arrives. If the socket is in the non-blocking mode,
	*				the E_WOULD_BLOCK exception is thrown. The specific error code can be accessed using the GetLastResult() method.
	*/
	Socket* AcceptN(void) const;

	/**
	* Executes the specified command on the socket.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	cmd		                    The command to execute on the socket
	* @param[in,out] value						The value of the IOCTL command
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		This method manipulates the underlying device parameters of the socket descriptors. @n@n
	*				The NET_SOCKET_FIONBIO option is used for setting the non-blocking/blocking mode on a socket.
	*				Set the value to zero for enabling the blocking mode, or to a non-zero value for enabling the non-blocking mode.
	*				When a socket is created, by default, it operates in the non-blocking mode and the blocking mode is disabled. @n
	*				The NET_SOCKET_FIONREAD option is used for getting the number of bytes that are immediately available for reading. @n
	*				The NET_SOCKET_FIONWRITE option is used for getting the number of bytes that have not yet been
	*		        acknowledged by the other side of the connection. This option is not supported in this SDK. @n
	*				The NET_SOCKET_SIOCATMARK option is used to determine if all out of band (OOB) data has been read.
	*				Currently sockets do not support this option.
	*
	*/
	result Ioctl(NetSocketIoctlCmd cmd, unsigned long& value) const;

	/**
	* Sets the socket to the asynchronous mode by a specified message to the specified event handler when the socket events occur.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	socketEventType				The socket events of ::NetSocketEventType @n
	*											Multiple events can be combined using the bitwise "|" operator.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_TIMEOUT                   An attempt to connect to the server has timed out.
	*
	*/
	result AsyncSelectByListener(unsigned long socketEventType);

	/**
	* Adds the specified listener to the socket.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	listener				A reference to ISocketEventListener
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_SOCKET		The socket is invalid.
	* @exception	E_INVALID_STATE			The associated socket is not in a valid state.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OBJ_ALREADY_EXIST		The listener is already added.
	* @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, @n
	* 										because the caller thread is a worker thread.
	*/
	result AddSocketListener(ISocketEventListener& listener);

	/**
	* Removes the specified listener.
	*
	* @since        2.0
	*
	* @return       An error code
	* @param[in]	listener				A reference to ISocketEventListener
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OBJ_NOT_FOUND			The specified object is not found within the indicated range.
	* @exception	E_INVALID_SOCKET		The socket is invalid.
	* @exception	E_INVALID_STATE			The associated socket is not in a valid state.
	* @exception	E_SYSTEM				A system error has occurred.
	*/
	result RemoveSocketListener(ISocketEventListener& listener);

	/**
	* Gets the peer endpoint for this socket. @n
	* It returns a NetEndPoint containing the peer IP address and port number.
	*
	* @since        2.0
	*
	* @return		The peer endpoint for the calling %Socket instance, @n
	*				else @c null if the socket is not connected to any peer
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The socket is not in a valid state.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			GetLocalEndPoint()
	*/
	const NetEndPoint* GetPeerEndPoint(void);

	/**
	* Gets the local endpoint for this socket. @n
	* It returns a NetEndPoint containing the local IP address and port number.
	*
	* @since        2.0
	*
	* @return		The local endpoint for the calling %Socket instance, @n
	*				else @c null
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The socket is not in a valid state.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		This NetEndPoint must be cast to a %NetEndPoint before retrieving any information.
	*/
	const NetEndPoint* GetLocalEndPoint(void);

	/**
	* Gets an option of the socket.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	optionLevel					A ::NetSocketOptLevel value
	* @param[in]	optionName					A ::NetSocketOptName value
	* @param[out]	optionValue					The integer to receive the option setting
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INIT_FAILED				The socket is not initialized.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		The socket options determine the behavior of the current socket.
	*				Upon successful completion of this method,
	*				@c optionValue parameter contains the value of the specified socket option.
	*				For an option with a bool data type, a non-zero value is returned if the option is enabled. Otherwise,
	*				a zero value is returned. For an option with an integer data type, the method returns the appropriate value.
	*				The socket options are grouped by the level of protocol support. @n@n
	*				Listed below are the various socket options that can be obtained using this overload. These options are
	*				grouped by the appropriate NetSocketOptLevel.
	*				Use the appropriate %NetSocketOptLevel for the @c optionLevel parameter. The option that is chosen,
	*				must be specified in the @c optionName parameter. To set the current value of some of
	*				the listed options, use the SetSockOpt() method. @n@n
	*				The OptionNames are categorized under their specific option levels. @n@n
	*				NET_SOCKET_IPPROTO_TCP  @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_NODELAY: Disables the Nagle algorithm for send coalescing. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_MAXSEG: Specifies the MSS(Maximum Segment Size) for TCP. @n@n
	*				NET_SOCKET_IPPROTO_IP @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TTL: Time-to-live. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TOS: Type-of-service and precedence. @n@n
	*				NET_SOCKET_SOL_SOCKET @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_ACCEPTCONN: The socket is listening. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_BROADCAST: Permits the sending of broadcast messages. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_DONTROUTE : Do not route. Send the packet directly to the interface addresses. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_ERROR : For getting pending error and clear. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_KEEPALIVE: Uses keep-alive. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_LINGER: Lingers on close if data is present. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_OOBINLINE: Leaves the received Out Of Band data in line. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVBUF: Buffer size for receives. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVTIMEO: Receives a time-out. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_REUSEADDR: Allows the socket to be bound to an address that is already in use. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDBUF: Buffer size for sends. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDTIMEO: Sends a time-out. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_TYPE: Gets the socket type. @n
	* @see SetSockOpt()
	*/
	result GetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int& optionValue) const;

	/**
	* Gets the socket option status of SO_LINGER.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	optionLevel					The socket option level @n
	*											The @c optionLevel is NET_SOCKET_SOL_SOCKET.
	* @param[in]	optionName					The socket configuration option name @n
	*											The @c optionName is NET_SOCKET_SO_LINGER.
	* @param[out]	optionValue					The instance of LingerOption that is to receive the option setting
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INIT_FAILED				The socket is not initialized.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_SYSTEM					A system error has occurred.
	* @see Tizen::Net::Sockets::LingerOption
	*/
	result GetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, LingerOption& optionValue) const;

	/**
	* Changes an option of the socket.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	optionLevel					A ::NetSocketOptLevel value
	* @param[in]	optionName					A ::NetSocketOptName value
	* @param[in]	optionValue					The option value
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INIT_FAILED				The socket is not initialized.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_INVALID_STATE				The socket is not in a valid state.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method is used to change the value of the option specified by the @c optionName parameter.
	*				The socket options determine the behavior of the current socket. For an option with a bool data type,
	*				specify a non-zero value to enable the option, and a zero value to disable the option.
	*				For an option with an integer data type, specify the appropriate value. The socket options are grouped
	*				by the level of protocol support. @n@n
	*				Listed below are the various socket options that can be set using this overload. These options are
	*				grouped by the appropriate NetSocketOptLevel. If any of these options are to be set,
	*				use the appropriate %NetSocketOptLevel for the @c optionLevel parameter. The chosen option
	*				must be specified in the @c optionName parameter. To get the current value of some of
	*				the options listed, use the GetSockOpt() method. @n@n
	*				The OptionNames are categorized under their specific option levels. @n@n
	*				NET_SOCKET_IPPROTO_TCP @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_NODELAY: Disables the Nagle algorithm for send coalescing. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_MAXSEG: Specifies the MSS(Maximum Segment Size) for TCP. @n@n
	*				NET_SOCKET_IPPROTO_IP @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TTL: Time-to-live. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TOS: Type-of-service and precedence. @n@n
	*				NET_SOCKET_SOL_SOCKET @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_BROADCAST : Permits the sending of broadcast messages. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_DONTROUTE : Do not route. Send the packet directly to the interface addresses. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_KEEPALIVE: Uses keep-alive. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_LINGER: Lingers on close if data is present. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_OOBINLINE: Leaves the received Out Of Band data in line. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVBUF: Buffer size for receives. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVTIMEO: Receives a time-out. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_REUSEADDR: Allows the socket to be bound to an address that is already in use. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDBUF: Buffer size for sends. @n
	*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDTIMEO: Sends a time-out.
	*
	*
	*/
	result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int optionValue);

	/**
	* Enables or disables SO_LINGER with the specified linger time in seconds. @n
	* The maximum timeout value is platform-specific. This setting only affects socket close.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	optionLevel					The socket option level @n
	* 											The @c optionLevel is NET_SOCKET_SOL_SOCKET.
	* @param[in]	optionName					The socket configuration option name @n
	*											The @c optionName is NET_SOCKET_SO_LINGER.
	* @param[in]	optionValue					An instance of LingerOption that holds the option setting
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INIT_FAILED				The socket is not initialized.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_INVALID_STATE				The socket is in an invalid state.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_SYSTEM					A system error has occurred.
	*
	*/
	result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, const LingerOption& optionValue);

	/**
	* Enables the adding or dropping of a membership for the specified multicast group. @n
	* Multicast datagram packets are transmitted only to the multicast group members. @n
	* A socket must join a multicast group before the data is received. @n
	* Do not call NET_SOCKET_SO_IP_ADD_MEMBERSHIP with the same group more than once on the same network interface.
	*
	* @since        2.0
	*
	* @return		An error code
	* @param[in]	optionLevel					Set to @c NET_SOCKET_IPPROTO_IP
	* @param[in]	optionName					Set to either @c NET_SOCKET_IP_ADD_MEMBERSHIP or @c NET_SOCKET_IP_DROP_MEMBERSHIP only
	* @param[in]	optionValue					An instance of IpMulticastRequestOption that contains the network interface and group address for multicasting
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The socket is invalid.
	* @exception	E_INIT_FAILED				The socket is not initialized.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.
	* @exception	E_INVALID_STATE				The socket is in an invalid state.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_IN_PROGRESS				A previous request is in progress.
	* @exception	E_CONNECTION_FAILED			The socket is not connected.
	* @exception	E_SYSTEM					A system error has occurred.
	*
	*/
	result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, const IpMulticastRequestOption& optionValue);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @param[in]	rhs		An instance of %Socket
	*/
	Socket(const Socket& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @return		A reference to this instance
	* @param[in]	rhs			An instance of %Socket
	*/
	Socket& operator =(const Socket& rhs);

private:
	_SocketImpl* __pSocketImpl;

	friend class _SocketImpl;
};

} } }   // Tizen::Net::Sockets
#endif // _FNET_SOCK_SOCKET_H_
