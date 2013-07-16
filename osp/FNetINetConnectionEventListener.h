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
 * @file	FNetINetConnectionEventListener.h
 * @brief	This is the header file for the %INetConnectionEventListener interface.
 *
 * This header file contains the declarations of the %INetConnectionEventListener interface.
 *
 */
#ifndef _FNET_INET_CONNECTION_EVENT_LISTENER_H_
#define _FNET_INET_CONNECTION_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net
{
class NetConnection;

/**
 * @interface	INetConnectionEventListener
 * @brief		This interface implements the listeners for the network connection events.
 *
 * @since		2.0
 *
 *  The %INetConnectionEventListener interface specifies the methods for creating the notifications about the different kinds of network
 *	connection events. These events are only sent when %INetConnectionEventListener is added to a NetConnection instance, by invoking the
 *	NetConnection::AddNetConnectionListener() method. When a network connection event is generated, a method of this class is called.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 */
class _OSP_EXPORT_ INetConnectionEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~INetConnectionEventListener(void) {}

public:
	/**
	 * Called to notify the application that the network connection has been opened and connected. @n
	 * An application can send or receive the data.
	 *
	 * @since		2.0
	 *
	 * @param[in]	netConnection				The network connection
	 * @param[in]	r							An error code
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	 * @exception	E_DEVICE_UNAVAILABLE		The operation has failed due to a missing SIM card.
	 * @exception	E_NETWORK_UNAVAILABLE		The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE		The operation has failed because the device is out of the coverage area or in the emergency mode.
	 * @exception	E_RESOURCE_UNAVAILABLE		The network resource is unavailable.
	 * @exception	E_AUTHENTICATION			The authentication has failed.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception	E_NETWORK_FAILED			Requested but an error is received from the network.
	 * @exception	E_INVALID_SIM_STATE			The network has marked SIM as invalid for the CS and/or PS domain.
	 * @exception	E_FDN_MODE					The FDN is enabled and the number is not listed in the FDN list.
	 * @exception	E_DHCP						The DHCP operation has failed on WLAN.
	 * @exception	E_LINK						A link failure has occurred on WLAN.
	 */
	virtual void OnNetConnectionStarted(NetConnection& netConnection, result r) = 0;

	/**
	 * Called to notify the application that the network connection has been closed and disconnected.
	 *
	 * @since		2.0
	 *
	 * @param[in]	netConnection				The network connection
	 * @param[in]	r							An error code
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_NETWORK_UNAVAILABLE		The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE		The operation has failed because the device is out of the coverage area or in the emergency mode.
	 * @exception	E_RESOURCE_UNAVAILABLE		The network resource is unavailable.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception	E_NETWORK_FAILED			Requested but an error is received from the network.
	 * @exception	E_INVALID_SIM_STATE			The network has marked SIM as invalid for the CS and/or PS domain.
	 * @exception	E_FDN_MODE					The FDN is enabled and the number is not listed in the FDN list.
	 * @exception	E_DHCP						The DHCP operation has failed on WLAN.
	 * @exception	E_LINK						A link failure has occurred on WLAN.
	 * @remarks		This notification does not imply that the network is stopped permanently and cannot be used.
	 *				The network can be restarted using NetConnection::Start().
	 *				The NetConnection::Close() method is used to disconnect the connection
	 *              from the remote server or gateway permanently.
	 */
	virtual void OnNetConnectionStopped(NetConnection& netConnection, result r) = 0;

	/**
	 * Called to notify the application that the connection status has changed or is in an unstable or suspended state. @n
	 * Thus, an application may neither send nor receive data through Socket or Http until the network connection is resumed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	netConnection		The network connection
	 *
	 */
	virtual void OnNetConnectionSuspended(NetConnection& netConnection) = 0;

	/**
	 * Called to notify the application that the network has recovered from a suspended state. @n
	 * Thus, an application can send or receive data through Socket or Http from now on.
	 *
	 * @since		2.0
	 *
	 * @param[in]	netConnection		The network connection
	 */
	virtual void OnNetConnectionResumed(NetConnection& netConnection) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	 virtual void INetConnectionEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	 virtual void INetConnectionEventListener_Reserved2(void) {}
}; // INetConnectionEventListener

} } // Tizen::Net
#endif // _FNET_INET_CONNECTION_EVENT_LISTENER_H_
