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
* @file			FNetSockSocketTypes.h
* @brief		This is the header file for the enumerators of the Socket namespace.
*
* This header file contains the definitions of the enumerators for the Socket operations.
*/

#ifndef _FNET_SOCK_SOCKET_TYPES_H_
#define _FNET_SOCK_SOCKET_TYPES_H_

#include <FNetNetTypes.h>

namespace Tizen { namespace Net { namespace Sockets
{

/**
 * @enum    NetSocketEventType
 *
 * Defines the socket event types.
 *
 * @since	2.0
 */
enum NetSocketEventType
{
	NET_SOCKET_EVENT_WRITE = 0x01,                  /**< The write event */
	NET_SOCKET_EVENT_READ = 0x02,                   /**< The read event */
	NET_SOCKET_EVENT_CLOSE = 0x04,                  /**< The close event */
	NET_SOCKET_EVENT_ACCEPT = 0x08,                 /**< The accept event */
	NET_SOCKET_EVENT_CONNECT = 0x10,                /**< The connect event */
	NET_SOCKET_EVENT_SERVCERT_FAIL = 0x20,          /**< The server's certificate failed event @n
				                                         Only for %SecureSocket. */
	NET_SOCKET_EVENT_NONE = 0x00                          // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    NetSocketAddressFamily
 *
 * Defines an address family.
 *
 * @since	2.0
 */
enum NetSocketAddressFamily
{
	//NET_SOCKET_AF_LOCAL = 1,                            /*< The local socket for loopback*/
	NET_SOCKET_AF_IPV4 = 2,                             /**< An IP version 4 address family */
	//NET_SOCKET_AF_IPV6,						/*< An IP version 6 address family */
	NET_SOCKET_AF_NONE = 0                             // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    NetSocketType
 *
 * Defines a socket type.
 *
 * @since	2.0
 */
enum NetSocketType
{
	NET_SOCKET_TYPE_STREAM = 1,                         /**< The stream socket */
	NET_SOCKET_TYPE_DATAGRAM,                        /**< The datagram socket */
	NET_SOCKET_TYPE_NONE = 0                           // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    NetSocketProtocol
 *
 * Defines a protocol type.
 *
 * @since	2.0
 */
enum NetSocketProtocol
{
	NET_SOCKET_PROTOCOL_TCP = 1,                        /**< The TCP protocol */
	NET_SOCKET_PROTOCOL_UDP,                        /**< The UDP protocol */
	NET_SOCKET_PROTOCOL_SSL,                         /**< The SSL protocol */
	NET_SOCKET_PROTOCOL_NONE = 0                       // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum	    NetSocketIoctlCmd
 *
 * Defines the commands that control the socket I/O.
 *
 * @since	2.0
 */
enum NetSocketIoctlCmd
{
	NET_SOCKET_FIONBIO = 1,                             /**< The command to set the non-blocking/blocking mode on a socket */
	NET_SOCKET_FIONREAD,                            /**< The command to determine the amount of data pending in the network input buffer */
	NET_SOCKET_FIONWRITE,                           /**< The functionality is not supported in this SDK */
	NET_SOCKET_SIOCATMARK,                           /**< The command to determine whether all out-of-band data is read */
	NET_SOCKET_IOCTLCMD_NONE = 0                       // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    NetSocketOptLevel
 *
 * Defines the socket option levels. @n
 * The level decides the context of the option.
 *
 * @since	2.0
 */
enum NetSocketOptLevel
{
	NET_SOCKET_IPPROTO_TCP = 1,                         /**< The socket options apply only to the TCP sockets */
	NET_SOCKET_IPPROTO_IP,                          /**< The socket options apply only to the IP sockets */
	NET_SOCKET_SOL_SOCKET,                           /**< The socket options apply to all the sockets */
	NET_SOCKET_OPTLEVEL_NONE = 0                       // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
* @enum     NetSocketOptName
*
* Defines the socket configuration option names.
*
* @since	2.0
*/
enum NetSocketOptName
{
	NET_SOCKET_TCP_NODELAY = 1,                         /**< The option name is Level: NET_SOCKET_IPPROTO_TCP - Set/Get is possible */
	NET_SOCKET_TCP_MAXSEG,                          /**< The option name is Level: NET_SOCKET_IPPROTO_TCP - Set/Get is possible */
	NET_SOCKET_IP_TTL,                              /**< The option name is Level: NET_SOCKET_IPPROTO_IP - Set/Get is possible */
	NET_SOCKET_IP_TOS,                              /**< The option name is Level: NET_SOCKET_IPPROTO_IP - Set/Get is possible */
	NET_SOCKET_IP_ADD_MEMBERSHIP,                   /**< The option name is Level: NET_SOCKET_IPPROTO_IP - Only Set is possible */
	NET_SOCKET_IP_DROP_MEMBERSHIP,                  /**< The option name is Level: NET_SOCKET_IPPROTO_IP - Only Set is possible */
	NET_SOCKET_SO_ACCEPTCONN,                       /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible */
	NET_SOCKET_SO_BROADCAST,                        /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_DEBUG,                            // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported)
	NET_SOCKET_SO_DONTROUTE,                        /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_ERROR,                            /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible */
	NET_SOCKET_SO_KEEPALIVE,                        /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_LINGER,                           /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_OOBINLINE,                        /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_RCVBUF,                           /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_RCVLOWAT,                          // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported)
	NET_SOCKET_SO_RCVTIMEO,                         /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_REUSEADDR,                        /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_SNDBUF,                           /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_SNDLOWAT,                         // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported)
	NET_SOCKET_SO_SNDTIMEO,                         /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_TYPE,                             /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible */

	//Secure Socket only
	NET_SOCKET_SO_SSLVERSION,                       /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_SSLCIPHERSUITEID,                 /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
	NET_SOCKET_SO_SSLCERTVERIFY,                    /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible */
	NET_SOCKET_SO_SSLCERTID,                         /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible */
	NET_SOCKET_SO_SSLCLIENTCERTVERIFY,               /**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible */
	NET_SOCKET_OPTNAME_NONE = 0                        // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
* @enum     NetSocketClosedReason
*
* Defines a socket closed reason.
*
* @since	2.0
*/
enum NetSocketClosedReason
{
	NET_SOCKET_CLOSED_REASON_NORMAL = 1,                    /**< A normal closed status by peer */
	NET_SOCKET_CLOSED_REASON_TIMEOUT,                   /**< The connection attempt failed due to timeout */
	NET_SOCKET_CLOSED_REASON_NETWORK_UNAVAILABLE,       /**< The network is unavailable */
	NET_SOCKET_CLOSED_REASON_SYSTEM,                    /**< An internal error has occurred */
	NET_SOCKET_CLOSED_REASON_NO_CERTIFICATE,            /**< The reason is there is no client's SSL certificate */
	NET_SOCKET_CLOSED_REASON_BY_USER,                    /**< The connection closed by user */
	NET_SOCKET_CLOSED_REASON_NONE = 0                      // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

} } } // Tizen::Net::Sockets
#endif //_FNET_SOCK_SOCKET_TYPES_H_
