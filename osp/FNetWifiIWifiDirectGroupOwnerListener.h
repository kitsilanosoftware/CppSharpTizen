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
 * @file        FNetWifiIWifiDirectGroupOwnerListener.h
 * @brief       This is the header file for the %IWifiDirectGroupOwnerListener interface.
 *
 * This header file contains the declarations of the %IWifiDirectGroupOwnerListener interface.
 */
#ifndef _FNET_WIFI_IWIFI_DIRECT_GROUP_OWNER_LISTENER_H_
#define _FNET_WIFI_IWIFI_DIRECT_GROUP_OWNER_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetWifiWifiTypes.h>
#include <FNetNetConnection.h>

namespace Tizen { namespace Net
{
class NetConnection;
} } // Tizen::Net

namespace Tizen { namespace Net { namespace Wifi
{
class WifiDirectDeviceInfo;

/**
 * @if OSPDEPREC
 * @interface   IWifiDirectGroupOwnerListener
 * @brief       <i> [Deprecated] </i> This interface implements listeners for the WifiDirectGroupOwner events.
 * @deprecated  The WifiDirectGroupOwner class is deprecated, therefore, this interface is also deprecated. @n
 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role(for example, group owner,
 *              group client, and so on) and so it was necessary to use these APIs. Now the Wi-Fi Direct APIs have been
 *              revised to allow the use of APIs with ease irrespective of the role. @n
 *              As the APIs have been integrated into the IWifiDirectDeviceListener interface. Hence, use the
 *              IWifiDirectDeviceListener interface instead.
 *
 * @since       2.0
 *
 * The %IWifiDirectGroupOwnerListener interface represents a listener that is used to obtain the Wi-Fi Direct group
 * owner's status or information.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 * @endif
 */

class _OSP_EXPORT_ IWifiDirectGroupOwnerListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * @if OSPDEPREC
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupOwner class is deprecated, therefore, this destructor is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. Now the Wi-Fi Direct
	 *              APIs have been revised to allow the use of APIs with ease irrespective of the role.
	 *
	 * @since       2.0
	 * @endif
	 */
	virtual ~IWifiDirectGroupOwnerListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called to notify the application that a successful association has occurred with a client.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role. @n
	 *              As the APIs have been integrated into the IWifiDirectDeviceListener interface, use the
	 *              IWifiDirectDeviceListener::OnWifiDirectConnected() method instead.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId           An ID for a Wi-Fi Direct device
	 * @param[in]   wifiDirectClientInfo    The WifiDirectDeviceInfo instance of an associated node
	 * @endif
	 */
	virtual void OnWifiDirectClientAssociated(WifiDirectDeviceId localDeviceId,
			const WifiDirectDeviceInfo& wifiDirectClientInfo) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application that a disassociation has occurred with a client.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role. @n
	 *              As the APIs have been integrated into the IWifiDirectDeviceListener interface, use the
	 *              IWifiDirectDeviceListener::OnWifiDirectDisconnected() method instead.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId           An ID for a Wi-Fi Direct device
	 * @param[in]   wifiDirectClientInfo    The WifiDirectDeviceInfo instance of a disassociated node
	 * @param[in]   reason                  The reason of termination of an association
	 * @remarks     - When a client is disconnected by a group owner using WifiDirectGroupOwner::Disconnect, this event
	 *                is invoked with Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_SELF_INITIATED. @n
	 *              - When a client is disconnected by itself using WifiDirectGroupClient::Disassociate(), due to no
	 *                range, or due to abrupt connection loss to the group owner, this event is invoked with
	 *                Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_DISCONNECTED.
	 * @endif
	 */
	virtual void OnWifiDirectClientDisassociated(WifiDirectDeviceId localDeviceId,
			const WifiDirectDeviceInfo& wifiDirectClientInfo, WifiDirectAssociationTerminationReason reason) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application when the Wi-Fi Direct group is destroyed.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role. @n
	 *              As the APIs have been integrated into the IWifiDirectDeviceListener interface, use the
	 *              IWifiDirectDeviceListener::OnWifiDirectDisconnected() or
	 *              IWifiDirectDeviceListener::OnWifiDirectGroupLeft() method instead.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId       An ID for a Wi-Fi Direct device
	 * @param[in]   r                   An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         WifiDirectGroupOwner::DestroyGroup()
	 * @endif
	 */
	virtual void OnWifiDirectGroupDestroyed(WifiDirectDeviceId localDeviceId, result r) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application that the group member information service has started.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId       An ID for a Wi-Fi Direct device
	 * @param[in]   pNetConnection      The network connection that started with the Wi-Fi Direct net account, @n
	 *                                  else @c null if the system fails to start the network connection @n
	 * @param[in]   r                   An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_ALREADY_BOUND     The specified port number is already in use.
	 * @see         WifiDirectGroupOwner::StartGroupMemberInfoService()
	 * @endif
	 */
	virtual void OnWifiDirectGroupMemberInfoServiceStarted(WifiDirectDeviceId localDeviceId,
			const Tizen::Net::NetConnection* pNetConnection, result r) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application that the group member information service has stopped.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The %WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId       An ID for a Wi-Fi Direct device
	 * @param[in]   r                   An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         WifiDirectGroupOwner::StopGroupMemberInfoService()
	 * @endif
	 */
	virtual void OnWifiDirectGroupMemberInfoServiceStopped(WifiDirectDeviceId localDeviceId, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupOwnerListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupOwnerListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupOwnerListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupOwnerListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupOwnerListener_Reserved5(void) {}
}; // IWifiDirectGroupOwnerListener

} } } //Tizen::Net::Wifi
#endif // _FNET_WIFI_IWIFI_DIRECT_GROUP_OWNER_LISTENER_H_
