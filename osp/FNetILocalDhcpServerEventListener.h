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
 * @file	FNetILocalDhcpServerEventListener.h
 * @brief	This is the header file for the %ILocalDhcpServerEventListener interface.
 *
 * This header file contains the declarations of the %ILocalDhcpServerEventListener interface.
 *
 */
#ifndef _FNET_ILOCAL_DHCP_SERVER_EVENT_LISTENER_H_
#define _FNET_ILOCAL_DHCP_SERVER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net
{
class LocalDhcpServer;
class DhcpClientInfo;
/**
 * @interface	ILocalDhcpServerEventListener
 * @brief		This interface defines the listeners for the local DHCP server events.
 *
 * @since		2.0
 *
 * The %ILocalDhcpServerEventListener interface provides methods for creating notifications about the different kinds of DHCP server events.
 * These events are only sent out when %ILocalDhcpServerEventListener is added to a LocalDhcpServer instance, by invoking the
 * SetLocalDhcpServerEventListener() method. When a %LocalDhcpServer event is generated, one of these methods is called. The methods of this
 * interface may be overridden and used in any application that uses the local DHCP server.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/local_DHCP_server_access.htm">Local DHCP Server Access</a>.
 *
 * @see	Tizen::Net::DhcpClientInfo
 */
class _OSP_EXPORT_ ILocalDhcpServerEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/** This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ILocalDhcpServerEventListener(void) {}

public:
	/**
	 * Called to notify the application that the client network connection on the local DHCP server has been connected.
	 *
	 * @since       2.0
	 *
	 * @param[in]	localDhcpServer		The requested local DHCP server
	 * @param[in]	dhcpClientInfo		The connected client information on the local DHCP server event
	 */
	virtual void OnDhcpClientConnectedN(LocalDhcpServer& localDhcpServer, DhcpClientInfo& dhcpClientInfo) = 0;

	/**
	 * Called to notify the application that the client network connection on the local DHCP server has been disconnected.
	 *
	 * @since       2.0
	 *
	 * @param[in]	localDhcpServer		The requested local DHCP server
	 * @param[in]	dhcpClientInfo		The disconnected client information on the local DHCP server event
	 */
	virtual void OnDhcpClientDisconnectedN(LocalDhcpServer& localDhcpServer, DhcpClientInfo& dhcpClientInfo) = 0;

protected:
	// Reserved virtual methods for later extension.

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ILocalDhcpServerEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ILocalDhcpServerEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void ILocalDhcpServerEventListener_Reserved3(void) {}
}; // ILocalDhcpServerEventListener

} } // Tizen::Net

#endif // _FNET_ILOCAL_DHCP_SERVER_EVENT_LISTENER_H_
