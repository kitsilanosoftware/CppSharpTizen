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
* @file		FNetSockISecureSocketEventListener.h
* @brief	This is the header file for the %ISecureSocketEventListener interface.
*
* This header file contains the declarations of the %ISecureSocketEventListener interface.
*/

#ifndef _FNET_SOCK_ISECURE_SOCKET_EVENT_LISTENER_H_
#define _FNET_SOCK_ISECURE_SOCKET_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net { namespace Sockets
{

class SecureSocket;

/**
* @interface	ISecureSocketEventListener
* @brief		This interface contains an event listener for the applications, which issues secure socket requests.
*
* @since        2.0
*
*				The %ISecureSocketEventListener interface specifies the methods used for creating the notifications about the different kinds of socket
*				events. These events are sent out when using a secure socket in a non-blocking mode. An event listener is added by calling the
*				SecureSocket::AddSecureSocketListener() method. One of these methods is called when a socket event is generated.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*/
class _OSP_EXPORT_ ISecureSocketEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{


public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since	2.0
	*/
	virtual ~ISecureSocketEventListener(void) {}


public:
	/**
	* Called to notify a connecting secure socket that its connection attempt has been completed successfully.
	*
	* @since		2.0
	*
	* @param[in]	socket		The SecureSocket instance
	*/
	virtual void OnSecureSocketConnected(SecureSocket& socket) = 0;

	/**
	* Called to notify the registered secure socket that the peer secure socket has been closed due to normal or forced termination of network. @n
	* It is also used to notify a connecting secure socket that its connection attempt has resulted in an error.
	*
	* @since        2.0
	*
	* @param[in]	socket		The SecureSocket instance
	* @param[in]	reason		The reason of type NetSocketClosedReason for a closed secure socket
	* @remarks		If the reason is NET_SOCKET_CLOSED_REASON_NO_CERTIFICATE, start the Application control (L"tizen.certificatemanager") for getting the selected client certificate. @n
	*               For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_certmgr.htm">here</a>.
	*/
	virtual void OnSecureSocketClosed(SecureSocket& socket, NetSocketClosedReason reason) = 0;

	/**
	* Called to notify a secure socket that the data is ready to be retrieved.
	*
	* @since        2.0
	*
	* @param[in]	socket		The SecureSocket instance
	* @remarks		This data can be retrieved by calling Receive().
	*/
	virtual void OnSecureSocketReadyToReceive(SecureSocket& socket) = 0;


	/**
	* Called to notify a secure socket that the data can be sent.
	*
	* @since        2.0
	*
	* @param[in]	socket		The SecureSocket instance
	* @remarks		This data can be sent by calling Send().
	*/
	virtual void OnSecureSocketReadyToSend(SecureSocket& socket) = 0;

	/**
	* Called to notify a secure socket that the verification of the server's certificate has failed. @n
	* Either of the following decisions can be taken after the verification fails: @n
	* - Continue with SSL handshaking without verification.
	* - Close the secure socket.
	*
	* @since        2.0
	*
	* @param[in]    socket	 The SecureSocket instance
	*/
	virtual void OnSecureSocketServCertFailed(SecureSocket& socket) = 0;

	/**
	 * Called to notify a secure socket that it has received a new connection from a peer.
	 *
	 * @since        2.0
	 *
	 * @param[in]	socket		The SecureSocket instance
	 */
	virtual void OnSecureSocketAccept(SecureSocket& socket) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ISecureSocketEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ISecureSocketEventListener_Reserved2(void) {}

};

} } } // Tizen::Net::Sockets
#endif // _FNET_SOCK_ISECURE_SOCKET_EVENT_LISTENER_H_
