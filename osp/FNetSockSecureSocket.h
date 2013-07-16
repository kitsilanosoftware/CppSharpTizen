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
 * @file		FNetSockSecureSocket.h
 * @brief	This is the header file for the %SecureSocket class.
 *
 * This header file contains the declarations of the %SecureSocket class. @n
 * This class provides secured simple methods for sending and receiving the data over a network.
 */

#ifndef _FNET_SOCK_SECURE_SOCKET_H_
#define _FNET_SOCK_SECURE_SOCKET_H_

#include <FBaseObject.h>
#include <FNetNetEndPoint.h>
#include <FNetNetConnection.h>
#include <FNetSockSocketTypes.h>
#include <FNetSockISecureSocketEventListener.h>

namespace Tizen { namespace Net { namespace Sockets
{

class _SecureSocketImpl;

/**
 * @enum     NetSecureSocketSslVersion
 *
 * Defines the secure socket version.
 *
 * @since    2.0
 */
enum NetSecureSocketSslVersion
{
	NET_SOCK_SSL_VERSION_SSLV3 = 0x0300,                    /**< The secure socket version is SSLv3 @n
				                                                 The value for SSLv3 is 0x0300. */
	NET_SOCK_SSL_VERSION_TLSV1 = 0x0301,                     /**< The secure socket version is TLSv1 @n
				                                                 The value for TLSv1 is 0x0301. */
	NET_SOCK_SSL_VERSION_NONE = 0x0000                     // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. SSL version not set
};

/**
 * @enum     NetSecureSocketSslCipherSuiteID
 *
 * Defines the CipherSuite ID.
 *
 * @since    2.0
 */
enum NetSecureSocketSslCipherSuiteID
{
	//NET_SOCK_TLS_SSL_RSA_WITH_NULL_MD5 =                  0x0001,		/*< The CipherSuite ID is 0x0001 */
	//NET_SOCK_TLS_SSL_RSA_WITH_NULL_SHA =                  0x0002,		/*< The CipherSuite ID is 0x0002 */
	//NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_RC4_40_MD5 =         0x0003,		/**< The CipherSuite ID is 0x0003 */
	NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_MD5 = 0x0004,                     /**< The CipherSuite ID is 0x0004 */
	NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_SHA = 0x0005,                     /**< The CipherSuite ID is 0x0005 */
	//NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5 =     0x0006,		/*< The CipherSuite ID is 0x0006 */
	//NET_SOCK_TLS_SSL_RSA_WITH_IDEA_CBC_SHA =              0x0007,		/*< The CipherSuite ID is 0x0007 */
	NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0008,            /**< The CipherSuite ID is 0x0008 */
	NET_SOCK_TLS_SSL_RSA_WITH_DES_CBC_SHA = 0x0009,                     /**< The CipherSuite ID is 0x0009 */
	NET_SOCK_TLS_SSL_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,                /**< The CipherSuite ID is 0x000A */
	//NET_SOCK_TLS_SSL_DH_DSS_WITH_3DES_EDE_CBC_SHA =       0x000D,		/*< The CipherSuite ID is 0x000D */
	//NET_SOCK_TLS_SSL_DH_RSA_WITH_3DES_EDE_CBC_SHA =       0x0010,		/*< The CipherSuite ID is 0x0010 */
	//NET_SOCK_TLS_SSL_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA =  0x0011,		/*< The CipherSuite ID is 0x0001 */
	//NET_SOCK_TLS_SSL_DHE_DSS_WITH_DES_CBC_SHA =           0x0012,		/*< The CipherSuite ID is 0x0002 */
	//NET_SOCK_TLS_SSL_DHE_DSS_WITH_3DES_EDE_CBC_SHA =      0x0013,		/*< The CipherSuite ID is 0x0003 */
	//NET_SOCK_TLS_SSL_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA =  0x0014,		/*< The CipherSuite ID is 0x0004 */
	//NET_SOCK_TLS_SSL_DHE_RSA_WITH_DES_CBC_SHA =           0x0015,		/*< The CipherSuite ID is 0x0005 */
	//NET_SOCK_TLS_SSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA =      0x0016,		/*< The CipherSuite ID is 0x0006 */
	//NET_SOCK_TLS_SSL_DH_anon_EXPORT_WITH_RC4_40_MD5 =     0x0017,		/*< The CipherSuite ID is 0x0007 */
	//NET_SOCK_TLS_SSL_DH_anon_WITH_RC4_128_MD5 =           0x0018,		/*< The CipherSuite ID is 0x0008 */
	//NET_SOCK_TLS_SSL_DH_anon_EXPORT_WITH_DES40_CBC_SHA =  0x0019,		/*< The CipherSuite ID is 0x0009 */
	//NET_SOCK_TLS_SSL_DH_anon_WITH_DES_CBC_SHA =           0x001A,		/*< The CipherSuite ID is 0x001A */
	//NET_SOCK_TLS_SSL_DH_anon_WITH_3DES_EDE_CBC_SHA =      0x001B,		/*< The CipherSuite ID is 0x001B */
	NET_SOCK_TLS_SSL_RSA_WITH_AES_128_CBC_SHA = 0x002F,                 /**< The CipherSuite ID is 0x002F */
	//NET_SOCK_TLS_SSL_DH_DSS_WITH_AES_128_CBC_SHA =        0x0030,		/*< The CipherSuite ID is 0x0030 */
	//NET_SOCK_TLS_SSL_DH_RSA_WITH_AES_128_CBC_SHA =        0x0031,		/*< The CipherSuite ID is 0x0031 */
	//NET_SOCK_TLS_SSL_DHE_DSS_WITH_AES_128_CBC_SHA =       0x0032,		/*< The CipherSuite ID is 0x0032 */
	//NET_SOCK_TLS_SSL_DHE_RSA_WITH_AES_128_CBC_SHA =       0x0033,		/*< The CipherSuite ID is 0x0033 */
	//NET_SOCK_TLS_SSL_DH_anon_WITH_AES_128_CBC_SHA =       0x0034,		/*< The CipherSuite ID is 0x0034 */
	//NET_SOCK_TLS_SSL_RSA_WITH_AES_256_CBC_SHA =           0x0035,		/*< The CipherSuite ID is 0x0035 */
	//NET_SOCK_TLS_SSL_DH_DSS_WITH_AES_256_CBC_SHA =        0x0036,		/*< The CipherSuite ID is 0x0036 */
	//NET_SOCK_TLS_SSL_DH_RSA_WITH_AES_256_CBC_SHA =        0x0037,		/*< The CipherSuite ID is 0x0037 */
	//NET_SOCK_TLS_SSL_DHE_DSS_WITH_AES_256_CBC_SHA =       0x0038,		/*< The CipherSuite ID is 0x0038 */
	//NET_SOCK_TLS_SSL_DHE_RSA_WITH_AES_256_CBC_SHA =       0x0039,		/*< The CipherSuite ID is 0x0039 */
	//NET_SOCK_TLS_SSL_DH_anon_WITH_AES_256_CBC_SHA =       0x003A,		/*< The CipherSuite ID is 0x003A */

	// Samsung does not support below cipher suites
	//TLS_SSL_ECDH_ECDSA_WITH_NULL_SHA_DRAFT09 =              0x0047,
	//TLS_SSL_ECDH_ECDSA_NULL_SHA =                           0x0047,
	//TLS_SSL_ECDH_ECDSA_WITH_RC4_128_SHA_DRAFT09 =           0x0048,
	//TLS_SSL_ECDH_ECDSA_WITH_DES_CBC_SHA_DRAFT09 =           0x0049,
	//TLS_SSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA_DRAFT09 =      0x004A,
	//TLS_SSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA_DRAFT09 =       0x004B,
	//TLS_SSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA_DRAFT09 =       0x004C,
	//TLS_SSL_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA =           0x0063,
	//TLS_SSL_DHE_DSS_EXPORT1024_WITH_RC4_56_SHA =            0x0065,
	//TLS_SSL_DHE_DSS_WITH_RC4_128_SHA =                      0x0066,
	//TLS_SSL_PSK_WITH_RC4_128_SHA =                          0x008A,
	//TLS_SSL_PSK_WITH_3DES_EDE_CBC_SHA =                     0x008B,
	//TLS_SSL_PSK_WITH_AES_128_CBC_SHA =                      0x008C,
	//TLS_SSL_PSK_WITH_AES_256_CBC_SHA =                      0x008D,
	//TLS_SSL_DHE_PSK_WITH_RC4_128_SHA =                      0x008E,
	//TLS_SSL_DHE_PSK_WITH_3DES_EDE_CBC_SHA =                 0x008F,
	//TLS_SSL_DHE_PSK_WITH_AES_128_CBC_SHA =                  0x0090,
	//TLS_SSL_DHE_PSK_WITH_AES_256_CBC_SHA =                  0x0091,
	//TLS_SSL_RSA_PSK_WITH_RC4_128_SHA =                      0x0092,
	//TLS_SSL_RSA_PSK_WITH_3DES_EDE_CBC_SHA =                 0x0093,
	//TLS_SSL_RSA_PSK_WITH_AES_128_CBC_SHA =                  0x0094,
	//TLS_SSL_RSA_PSK_WITH_AES_256_CBC_SHA =                  0x0095,
	//TLS_SSL_ECDH_ECDSA_WITH_NULL_SHA =                      0xC001,
	//TLS_SSL_ECDH_ECDSA_WITH_RC4_128_SHA =                   0xC002,
	//TLS_SSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA =              0xC003,
	//TLS_SSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA =               0xC004,
	//TLS_SSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA =               0xC005,
	//TLS_SSL_ECDHE_ECDSA_WITH_NULL_SHA          =            0xC006,
	//TLS_SSL_ECDHE_ECDSA_WITH_RC4_128_SHA       =            0xC007,
	//TLS_SSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA  =            0xC008,
	//TLS_SSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA   =            0xC009,
	//TLS_SSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA   =            0xC00A,
	//TLS_SSL_ECDH_anon_WITH_NULL_SHA            =            0xC015,
	//TLS_SSL_ECDH_anon_WITH_RC4_128_SHA         =            0xC016,
	//TLS_SSL_ECDH_anon_WITH_3DES_EDE_CBC_SHA    =            0xC017,
	//TLS_SSL_ECDH_anon_WITH_AES_128_CBC_SHA     =            0xC018,
	//TLS_SSL_ECDH_anon_WITH_AES_256_CBC_SHA     =            0xC019,
	//TLS_SSL_ECMQV_ECDSA_WITH_NULL_SHA             =         0xFF4F,
	//TLS_SSL_ECMQV_ECDSA_WITH_RC4_128_SHA          =         0xFF50,
	//TLS_SSL_ECMQV_ECDSA_WITH_3DES_EDE_CBC_SHA     =         0xFF52,
	//TLS_SSL_ECMQV_ECDSA_WITH_AES_128_CBC_SHA      =         0xFF53,
	//TLS_SSL_ECMQV_ECDSA_WITH_AES_256_CBC_SHA      =         0xFF54,

	NET_SOCK_TLS_SSL_SYSTEM_DEFAULT_CIPHERSUITES = 0xFFFF,               /**< If the user selects this ID, the %SecureSocket instance decides the cipher suite bundle itself @n
				                                                          *	For the OAF SSL, the below cipher suites will be included in "ClientHello" message: @n
				                                                          *	NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_MD5
				                                                          *	NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_SHA
				                                                          *	NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_DES40_CBC_SHA
				                                                          *	NET_SOCK_TLS_SSL_RSA_WITH_DES_CBC_SHA
				                                                          *	NET_SOCK_TLS_SSL_RSA_WITH_3DES_EDE_CBC_SHA
				                                                          *	NET_SOCK_TLS_SSL_RSA_WITH_AES_128_CBC_SHA
				                                                          */
	NET_SOCK_TLS_SSL_NULL_WITH_NULL_NULL = 0x0000                      // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. The CipherSuite ID is 0x0000
};

/**
 * @class	SecureSocket
 * @brief	This class provides the Secure %Sockets Layer (SSL) supported socket with security features.
 *
 * @since	2.0
 *
 * The %SecureSocket class provides the Secure Sockets Layer (SSL) supported socket with security features.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
 */
class _OSP_EXPORT_ SecureSocket
	: public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since    2.0
	 */
	SecureSocket(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since    2.0
	 *
	 * @see      Close()
	 */
	virtual ~SecureSocket(void);

	/**
	 * Initializes this instance of %SecureSocket with the specified parameters. @n
	 * The secure socket is initialized in a non-blocking mode by default.
	 * Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %SecureSocket in the blocking mode.
	 *
	 * @since        2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/socket
	 *
	 * @return		An error code
	 * @param[in]	netConnection			A run-time session where a %SecureSocket instance is used
	 * @param[in]	addressFamily			A ::NetSocketAddressFamily value
	 * @param[in]	socketType				The secure socket type @n
	 *										The value should be NET_SOCKET_TYPE_STREAM.
	 * @param[in]	protocol				The protocol used by this secure socket @n
	 *										The value should be NET_SOCKET_PROTOCOL_SSL.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_WOULD_BLOCK			A non-blocking secure socket operation cannot be completed immediately.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED			All sockets are in use.
	 * @exception	E_UNSUPPORTED_OPTION	The specified parameters are not supported.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	 * @exception	E_UNSUPPORTED_TYPE		The secure socket type is not supported.
	 * @exception	E_UNSUPPORTED_FAMILY	The address family is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_FAILURE				The method has failed due to an undefined error.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks      The @c netConnection parameter specifies a run-time network connection. @n
	 *				The @c addressFamily parameter specifies an address family. @n
	 *				The @c socketType parameter specifies the type of the secure socket. SSL only supports stream-based protocols. @n
	 *				The @c protocol parameter specifies the protocol used by the secure socket. SSL protocol is defined as NET_SOCKET_PROTOCOL_SSL. @n
	 *				The first parameter must be a valid run-time network connection. The three parameters are not independent. Some address families
	 *				restrict the protocols that can be used with them, and often the secure socket type is implicit in the protocol. If the combination
	 *				of the address family, socket type, and protocol type results in an invalid secure socket, this method returns an error. @n For each
	 *				secure socket used in the non-blocking mode, an event listener (ISecureSocketEventListener) should be registered and maintained.
	 *				so that it can receive asynchronous notifications of the secure socket events. AddSecureSocketListener() is used to
	 *				register an event listener. @n
	 *				If a secure socket in the blocking mode needs to be used, Ioctl() (with NET_SOCKET_FIONBIO) should be called after initializing the secure socket
	 *				through this method.
	 * @see			Ioctl() for understanding the blocking/non-blocking mode
	 */
	result Construct(const Tizen::Net::NetConnection& netConnection, NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

	/**
	 * Initializes this instance of %SecureSocket with the specified parameters. @n
	 * The secure socket is initialized in a non-blocking mode by default.
	 * Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %SecureSocket in the blocking mode.
	 *
	 * @since        2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/socket
	 *
	 * @return		An error code
	 * @param[in]	addressFamily			A ::NetSocketAddressFamily value
	 * @param[in]	socketType				The secure socket type @n
	 *										The value should be NET_SOCKET_TYPE_STREAM.
	 * @param[in]	protocol				The protocol used by this secure socket @n
	 *										The value should be NET_SOCKET_PROTOCOL_SSL.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_WOULD_BLOCK			A non-blocking secure socket operation cannot be completed immediately.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED			All sockets are in use.
	 * @exception	E_UNSUPPORTED_OPTION	The specified parameters are not supported.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	 * @exception	E_UNSUPPORTED_TYPE		The secure socket type is not supported.
	 * @exception	E_UNSUPPORTED_FAMILY	The address family is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_FAILURE				The method has failed due to an undefined error.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The @c addressFamily parameter specifies an address family. @n
	 *               The @c socketType parameter specifies the type of the secure socket. SSL only supports stream-based protocols. @n
	 *               The @c protocol parameter specifies the protocol used by the secure socket. The SSL protocol is defined as NET_SOCKET_PROTOCOL_SSL. @n
	 *               The three parameters are not independent. Some address families restrict the protocols that can be used with them, and often the
	 *				secure socket type is implicit in the protocol. If the combination of the address family, socket type, and protocol type results in
	 *               an invalid secure socket, this method returns an error. @n
	 *               For each secure socket used in the non-blocking mode, an event listener
	 *				(ISecureSocketEventListener) should be registered and maintained, so that it can receive asynchronous notifications of the secure socket
	 *				events. AddSecureSocketListener() is used to register an event listener. @n
	 *				If a secure socket in the blocking mode needs to be used, Ioctl() (with NET_SOCKET_FIONBIO) should be called after initializing the secure socket
	 *				through this method.
	 * @see			Ioctl() for understanding the blocking/non-blocking mode
	 */
	result Construct(NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

public:
	/**
	 * Closes the secure socket. @n
	 * All the resources associated with the secure socket are freed.
	 *
	 * @since        2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/socket
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		If the %SecureSocket class is not initialized through one of the Construct() methods or this method is called more than once,
	 *				then this method returns E_INVALID_STATE.
	 */
	result Close(void);

	/**
	 * Establishes a connection to a remote host.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/socket
	 *
	 * @return			An error code
	 * @param[in]		remoteEndPoint				An instance of NetEndPoint representing the remote device
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception		E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception		E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
	 * @exception		E_IN_PROGRESS				A previous request is in progress.
	 * @exception		E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception		E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
	 * @exception       E_INVALID_CERTIFICATE       The client certificate verification has failed on server.
	 * @exception		E_CERTIFICATE_VERIFICATION_FAILED  The server certificate verification has failed.
	 * @exception		E_CONNECTION_FAILED			The secure socket is not connected.
	 * @exception		E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception		E_ALREADY_CONNECTED			The secure socket is already connected.
	 * @exception		E_UNSUPPORTED_FAMILY		The address family is not supported.
	 * @exception		E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
	 * @exception        E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception		E_SYSTEM					A system error has occurred.
	 * @exception        E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 *
	 * @remarks		Starts connection to a remote peer including SSL handshaking.
	 *				After this method is called, ISecureSocketEventListener::OnSecureSocketConnected() is called. The data is sent to and received from the remote
	 *				device using Send() and Receive() respectively. If the Bind() method is not called before calling this
	 *				method, the underlying service provider assigns the local network address and port number.
	 */
	result Connect(const Tizen::Net::NetEndPoint& remoteEndPoint);

	/**
	 * @page			SecureSocketConnectPage		Compatibility for Connect()
	 *
	 * @section		SecureSocketConnectPageIssueSection Issues
	 * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
	 * -# If the application provides a loopback address in NetEndPoint, it returns E_SYSTEM.
	 *
	 * @section		SecureSocketConnectPageResolutionSection Resolutions
	 *  The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
	 *  -# If the application provides a loopback address in NetEndPoint, it returns E_SUCCESS instead of E_SYSTEM.
	 */

	/**
	 * Sends the data to a secure socket of the type NET_SOCKET_TYPE_STREAM.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[in]	buffer						An instance of Tizen::Base::ByteBuffer that contains the data to send
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_CONNECTION_FAILED			The secure socket is not connected.
	 * @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		This method sends the data to the remote host specified in the Connect() method.
	 *               This method sends the data in the @c buffer parameter, starting from the current position of the buffer. After the operation,
	 *				the position of the buffer is incremented by the number of bytes successfully sent. The new position cannot be larger than the
	 *				original limit. This method can be used only for connection-oriented sockets.
	 *				In the blocking mode, if space is not available in the send queue, the secure socket blocks until space becomes available.
	*				In the non-blocking mode, this method returns the error E_WOULD_BLOCK. This method may
	 *				complete successfully even if it sends less bytes than the number of bytes present in the buffer. The application
	 *				should keep track of the number of bytes sent and retry the operation until the application sends the bytes in the
	 *				buffer. There is no guarantee that the data that is sent appears on the network immediately. To increase network efficiency, the
	 *				underlying system may delay the transmission until a significant amount of outgoing data is collected. A successful completion of this
	 *				method means that the underlying system has had room to buffer the data for a network send. If it is important for the
	 *				application to send every byte to the remote host immediately, use SetSockOpt() (with NET_SOCKET_TCP_NODELAY) of the type
	 *				::NetSocketOptName to enable no delay.
	 */
	result Send(Tizen::Base::ByteBuffer& buffer);

	/**
	 * Sends the data to a secure socket of the type NET_SOCKET_TYPE_STREAM.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[in]	pBuffer					The pointer to the buffer containing the data to send
	 * @param[in]	length					The length of the data in the buffer
	 * @param[out]	sentLength				The length of the data sent successfully
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_SOCKET		The secure socket is invalid.
	 * @exception	E_INVALID_STATE			The secure socket is not in a valid state.
	 * @exception	E_UNSUPPORTED_OPTION	The specified parameters are not supported.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_WOULD_BLOCK			A non-blocking secure socket operation cannot be completed immediately.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_CONNECTION_FAILED		The secure socket is not connected.
	 * @exception	E_TIMEOUT				An attempt to connect to the server has timed out.
	 * @exception    E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This method sends the data to the remote host specified in the Connect() method.
	 *               This method sends the data in the buffer of length @c length, starting from the current position of the buffer.
	 *               In the blocking mode, if space is not available in the send queue, the secure socket blocks until space becomes available.
	 *				 In the non-blocking mode, this method returns the error E_WOULD_BLOCK.
	 *               This method may complete successfully even if it sends less bytes than the number of bytes
	 *               in the buffer. The application should keep track of the number of bytes sent
	 *               and retry the operation until the application sends the bytes in the buffer.
	 *               There is no guarantee that the data that is sent appears on the network immediately.
	 *               To increase the network efficiency, the underlying system may delay the transmission until a significant amount
	 *               of outgoing data is collected. A successful completion of this method means that the underlying
	 *               system has had room to buffer the data for a network send.
	 *				If it is important for the application to send every byte to the remote host immediately,
	 *				use SetSockOpt() (with NET_SOCKET_TCP_NODELAY) of the type ::NetSocketOptName to enable no delay.
	 */
	result Send(void* pBuffer, int length, int& sentLength);

	/**
	 * Receives the data from a secure socket of the type NET_SOCKET_TYPE_STREAM.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[out]	buffer						An instance of Tizen::Base::ByteBuffer that is the storage location for the received data
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception	E_IN_PROGRESS				A previous request is in progress.
	 * @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		This method copies the data into the @c buffer parameter, starting from the current position of the buffer.
	 *               After the operation, the position of the buffer is incremented by the number of bytes successfully received.
	 *               The new position cannot be larger than the original limit. This method can be called from connection-oriented sockets only.
	 *				 If there is no data at the secure socket in the blocking mode,
	 *				 this method blocks until the data arrives. If the secure socket is in the non-blocking mode,
	 *				 the error E_WOULD_BLOCK is returned.
	 *
	 */
	result Receive(Tizen::Base::ByteBuffer& buffer) const;

	/**
	 * Receives the data from a secure socket of the type NET_SOCKET_TYPE_STREAM.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[out]	pBuffer						The pointer to the buffer that is the storage location for the received data
	 * @param[in]	length						The length of the data in the buffer
	 * @param[out]	rcvdLength					The length of the data that is received successfully
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception	E_IN_PROGRESS				A previous request is in progress.
	 * @exception    E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		This method copies the data into the buffer of length @c length, starting from the current position of the buffer.
	 *				This method can be called from the connection-oriented sockets only.
	*				If there is no data at the secure socket in the blocking mode,
	*				this method blocks until the data arrives. If the secure socket is in the non-blocking mode,
	*				the error E_WOULD_BLOCK is returned.
	 */
	result Receive(void* pBuffer, int length, int& rcvdLength) const;

	/**
	* Binds the secure socket to a local address.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	localEndPoint				The local NetEndPoint to associate with the secure socket
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_SOCKET			The secure socket is invalid.
	* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
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
	* Places the secure socket in a listening state.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		An error code
	* @param[in]	backLog						The maximum length of the pending connections queue
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
	* @exception	E_INVALID_SOCKET			The secure socket is invalid.
	* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		The specified parameter is not supported.
	* @exception	E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
	* @exception	E_ALREADY_CONNECTED			The secure socket is already connected.
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
	* The %AcceptN() method extracts the first connection from the queue of pending connections, and
	* creates a new secure socket with the same socket type, protocol type, and protocol family
	* as the listening secure socket.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/socket
	*
	* @return		A new secure socket for a newly created connection with the same socket type, protocol type, and protocol family, @n
	*				else @c null if an error occurs
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
	* @exception	E_INVALID_CERTIFICATE		The server certificate verification has failed on client.
	* @exception	E_CERTIFICATE_VERIFICATION_FAILED  The client certificate verification has failed.
	* @exception	E_INVALID_SOCKET			The secure socket is invalid.
	* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
	* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		Before calling this method, the Listen() method must be called first
	*				to listen for and queue the incoming connection requests.
	*				In the blocking mode, this method blocks until an incoming connection attempt
	*				is queued. After accepting a connection, the original socket
	*				continues queuing the incoming connection requests until it is closed.
	*				Note that if no connection is pending in the queue and the secure socket is in the blocking mode,
	*				this method blocks until a new connection arrives. If the secure socket is in the non-blocking mode,
	*				the E_WOULD_BLOCK exception is thrown. The specific error code can be accessed using the GetLastResult() method.
	*/
	SecureSocket* AcceptN(void) const;

	/**
	 * Executes the specified command on the socket.
	 *
	 * @since        2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/socket
	 *
	 * @return		An error code
	 * @param[in]	cmd		                    The command to execute on the secure socket
	 * @param[in,out] value						The value of the IOCTL command
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception   E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks     This method manipulates the underlying device parameters of the secure socket descriptors. @n@n
	 *              The NET_SOCKET_FIONBIO option is used for setting the non-blocking/blocking mode on a secure socket.
	 *              Set the value to zero for enabling the blocking mode, or to a non-zero value for enabling the non-blocking mode.
	 *              When a secure socket is created, by default, it operates in the non-blocking mode and the blocking mode is disabled.
	 *
	 */
	result Ioctl(NetSocketIoctlCmd cmd, unsigned long& value) const;

	/**
	 * Sets the secure socket to the asynchronous mode by a specified message to the specified event handler when the secure socket events occur.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[in]	socketEventType			The secure socket events of ::NetSocketEventType @n
	 *										Multiple events can be combined using the bitwise "|" operator.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_SOCKET		The secure socket is invalid.
	 * @exception	E_INVALID_STATE			The secure socket is not in a valid state.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_TIMEOUT               An attempt to connect to the server has timed out.
	 *
	 * The following example demonstrates how to use the %AsyncSelectByListener() method to set a secure socket to the asynchronous mode.
	 *
	 *	@code
	 *	result res = E_SUCCESS;
	 *
	 *	// Creates the secure socket.
	 *	SecureSocket* pClientSocket = new SecureSocket();
	 *	res = pClientSocket->Construct(NET_SOCKET_AF_IPV4,NET_SOCKET_TYPE_STREAM,NET_SOCKET_PROTOCOL_SSL);
	 *
	 *	// Adds listener.
	 *	MySocketSecureClientListener* pSockClientListener = new MySocketSecureClientListener();
	 *	res = pClientSocket->AddSecureSocketListener(*pSockClientListener);
	 *
	 *	// Selects asynchronous event (non-blocking mode).
	 *	res = pClientSocket->AsyncSelectByListener(NET_SOCKET_EVENT_CONNECT| NET_SOCKET_EVENT_CLOSE);
	 *
	 *	// Creates peer endpoint.
	 *	Ip4Address peerAddr("XXX.XXX.XXX.XXX"); //Secure socket server address.
	 *	unsigned short peerPort = YYY;  // Port
	 *	NetEndPoint* pPeerEndPoint = new NetEndPoint(peerAddr, peerPort);
	 *
	 *	// Connects the secure socket.
	 *	res = pClientSocket->Connect(*pPeerEndPoint);
	 *	@endcode
	 */
	result AsyncSelectByListener(unsigned long socketEventType);

	/**
	 * Adds a listener to the secure socket. @n
	 * The listener can listen to the events when they are fired.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[in]	listener				A reference to ISecureSocketEventListener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_SOCKET		The secure socket is invalid.
	 * @exception	E_INVALID_STATE			The associated secure socket is not in a valid state.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_OBJ_ALREADY_EXIST		The listener is already added.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, @n
	 * 										because the caller thread is a worker thread.
	 */
	result AddSecureSocketListener(ISecureSocketEventListener& listener);

	/**
	 * Removes a listener from the secure socket.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]	listener				A reference to ISecureSocketEventListener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified object is not found within the indicated range.
	 * @exception	E_INVALID_SOCKET		The secure socket is invalid.
	 * @exception	E_INVALID_STATE			The associated secure socket is not in a valid state.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RemoveSecureSocketListener(ISecureSocketEventListener& listener);

	/**
	 * Gets an option of the secure socket.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[in]	optionLevel					A ::NetSocketOptLevel value
	 * @param[in]	optionName					A ::NetSocketOptName value
	 * @param[out]	optionValue					The integer to receive the option setting
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_INIT_FAILED				The secure socket is not initialized.
	 * @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_IN_PROGRESS				A previous request is in progress.
	 * @exception	E_CONNECTION_FAILED			The secure socket is not connected.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The secure socket options determine the behavior of the current secure socket.
	 *				Upon the successful completion of this method, the integer variable specified
	 *				by the @c optionValue parameter contains the value of the specified secure socket option.
	 *				For an option with a bool data type, a non-zero value is returned if the option is enabled. Otherwise,
	 *				a zero value is returned. For an option with an integer data type, the method returns the appropriate value.
	 *				The secure socket options are grouped by the level of protocol support.
	 *				Listed below are the various secure socket options that can be obtained using this overload. These options are
	 *				grouped by the appropriate NetSocketOptLevel.
	 *				If any of these options are to be obtained, use the appropriate %NetSocketOptLevel for the @c optionLevel parameter. The option that
	 *				is chosen, must be specified in the @c optionName parameter. To set the current value of some of the listed options, use the
	 *				SetSockOpt() method. @n@n
	 *				The NET_SOCKET_SOL_SOCKET options that can be set using this overloaded method are: @n
	 *				&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLVERSION: Gets the SSL version of the secure socket. @n
	 *				&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCIPHERSUITEID: Gets the SSL cipher suite ID of the secure socket.
	 * @see          SetSockOpt()
	 */
	result GetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int& optionValue) const;

	/**
	 * Changes an option of the secure socket.
	 *
	 * @since        2.0
	 *
	 * @return		An error code
	 * @param[in]	optionLevel					A ::NetSocketOptLevel value
	 * @param[in]	optionName					A ::NetSocketOptName value
	 * @param[in]	optionValue					The option value
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_SOCKET			The secure socket is invalid.
	 * @exception	E_INIT_FAILED				The secure socket is not initialized.
	 * @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				The secure socket is not in a valid state.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_IN_PROGRESS				A previous request is in progress.
	 * @exception	E_CONNECTION_FAILED			The secure socket is not connected.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		This method is used to change the value of the option specified by the @c optionName parameter.
	 *				The secure socket options determine the behavior of the current secure socket. For an option with a bool data type,
	 *				specify a non-zero value to enable the option, and a zero value to disable the option.
	 *				For an option with an integer data type, specify the appropriate value. The secure socket options are grouped
	 *				by the level of protocol support.
	 *				Listed below are the various secure socket options that can be set using this overload. These options are
	 *				grouped by the appropriate NetSocketOptLevel.  If any of these options are to be set, use the appropriate %NetSocketOptLevel for the
	 *				@c optionLevel parameter. The chosen option must be specified in the @c optionName parameter.
	 *				To get the current value of some of the options listed, use the GetSockOpt() method. @n@n
	 *					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLVERSION: To enable the SSL version of the secure socket. @n
	 *					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCIPHERSUITEID: To set the SSL cipher suite ID of the secure socket. @n
	 *					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCERTVERIFY: To disable server certificate verification on the secure client socket. @n
	 *					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCLIENTCERTVERIFY: To enable client certificate verification on the secure server socket. @n
	 *					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCERTID: To set the SSL certificate ID for the client authentication. Start the Application control (L"tizen.certificatemanager") for getting the selected client certificate. For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_certmgr.htm">here</a>. @n
	 */
	result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int optionValue);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %SecureSocket
	 */
	SecureSocket(const SecureSocket& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @return		A reference to this instance
	 * @param[in]	rhs				An instance of %SecureSocket
	 */
	SecureSocket& operator =(const SecureSocket& rhs);

private:
	_SecureSocketImpl* __pSecureSocketImpl;

	friend class _SecureSocketImpl;
};

} } } // Tizen::Net::Sockets
#endif // _FNET_SOCK_SECURE_SOCKET_H_
