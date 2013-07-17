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
* @file		FNetSockSocketUtility.h
* @brief	This is the header file for the %SocketUtility class.
*
* This header file contains the declarations of the %SocketUtility class. @n
* This class provides utility methods for socket operations.
*/

#ifndef _FNET_SOCK_SOCKET_UTILITY_H_
#define _FNET_SOCK_SOCKET_UTILITY_H_

#include <FBaseCol.h>

namespace Tizen { namespace Net { namespace Sockets
{

class _SocketUtilityImpl;

/**
* @class	SocketUtility
* @brief	This class provides the utility methods for the Socket class.
*
* @since    2.0
*
* The %SocketUtility class provides the utility methods for the Socket class.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*/
class _OSP_EXPORT_ SocketUtility
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*/
	SocketUtility(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~SocketUtility(void);

	/**
	* Initializes this instance of %SocketUtility.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				Interface creation has failed.
	*/
	result Construct(void);

	/**
	* Determines the status of one or more sockets.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return			An error code
	* @param[in,out]	pCheckRead					A Tizen::Base::Collection::IList of Socket instances to check for readability
	* @param[in,out]	pCheckWrite				A Tizen::Base::Collection::IList of Socket instances to check for writability
	* @param[in,out]	pCheckError				A Tizen::Base::Collection::IList of Socket instances to check for errors
	* @param[in]		microSeconds				The time to wait for a response, in microseconds
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_SOCKET			The socket is invalid.
	* @exception		E_INVALID_STATE				The socket is in an invalid state.
	* @exception		E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	* @exception		E_INVALID_ARG				A specified input parameter is invalid.
	* @exception		E_TIMEOUT					The time limit has expired.
	* @exception		E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception        E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception		E_SYSTEM					A system error has occurred.
	* @exception        E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		This method determines the status of one or more
	*               Socket instances. There must be at least one socket in an Tizen::Base::Collection::IList
	*               before this method is used.
	*               To check sockets for readability and writability use @c pCheckRead and @c pCheckWrite of type
	*				%IList respectively by calling this method.
	*               To detect error conditions, use @c pCheckError.
	*               After calling this method, the %IList is filled with only those sockets that satisfy the conditions. @n
	*               All the receive operations succeed without blocking in the following cases: @n
	*				-#  If the socket is in a listening state, the readability means that a call to Accept() succeeds without blocking.
	*				-#  If the connection on a socket is accepted, the readability means that the data is available for reading. @n
	*               The readability can also indicate whether the remote socket has shutdown the connection. In this
	*               case a call to SecureSocket::Receive() or Socket::Receive() returns immediately with @c 0 bytes.
	*               If a non-blocking call to SecureSocket::Connect() or Socket::Connect() is made, the writability means that the connection is
	*				successful and the @c pCheckError parameter identifies the sockets that are not
	*				connected successfully. @n
	*               If a connection has already been established, the writability means that all the send operations
	*				have succeeded without blocking.
	*/
	result Select(Tizen::Base::Collection::IList* pCheckRead, Tizen::Base::Collection::IList* pCheckWrite, Tizen::Base::Collection::IList* pCheckError, int microSeconds);

	/**
	* Converts the specified unsigned @c short integer from a host @c byte order to a network @c byte order.
	*
	* @since		2.0
	*
	* @return		An unsigned @c short integer in network @c byte order
	* @param[in]	hostShort		An unsigned @c short integer in host @c byte order
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			NtoHS()
	*/
	unsigned short HtoNS(unsigned short hostShort);

	/**
	* Converts the specified unsigned @c long integer from a host @c byte order to a network @c byte order.
	*
	* @since		2.0
	*
	* @return		An unsigned @c long integer in network @c byte order
	* @param[in]	hostLong		An unsigned @c long integer in host @c byte order
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			NtoHL()
	*/
	unsigned long HtoNL(unsigned long hostLong);

	/**
	* Converts the specified unsigned @c short integer from a network @c byte order to a host @c byte order.
	*
	* @since		2.0
	*
	* @return		An unsigned @c short integer in host @c byte order
	* @param[in]	netShort		An unsigned @c short integer in network @c byte order
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			HtoNS()
	*/
	unsigned short NtoHS(unsigned short netShort);

	/**
	* Converts the specified unsigned @c long integer from a network @c byte order to a host @c byte order.
	*
	* @since		2.0
	*
	* @return		An unsigned @c long integer in host @c byte order
	* @param[in]	netLong			An unsigned @c long integer in network @c byte order
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			HtoNL()
	*/
	unsigned long NtoHL(unsigned long netLong);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @param[in]	rhs			An instance of %SocketUtility
	*/
	SocketUtility(const SocketUtility& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @return		A reference to this instance
	* @param[in]	rhs			An instance of %SocketUtility
	*/
	SocketUtility& operator =(const SocketUtility& rhs);

private:
	_SocketUtilityImpl* __pSocketUtilityImpl;

	friend class _SocketUtilityImpl;
};

} } } // Tizen::Net::Sockets
#endif // _FNET_SOCK_SOCKET_UTILITY_H_
