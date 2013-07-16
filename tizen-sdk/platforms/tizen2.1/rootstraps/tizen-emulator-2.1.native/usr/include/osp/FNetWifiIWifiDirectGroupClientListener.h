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
 * @file        FNetWifiIWifiDirectGroupClientListener.h
 * @brief       This is the header file for the %IWifiDirectGroupClientListener interface.
 *
 * This header file contains the declarations of the %IWifiDirectGroupClientListener interface.
 */
#ifndef _FNET_WIFI_IWIFI_DIRECT_GROUP_CLIENT_LISTENER_H_
#define _FNET_WIFI_IWIFI_DIRECT_GROUP_CLIENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
} } } // Tizen::Base::Collection

namespace Tizen { namespace Net { namespace Wifi
{
class WifiDirectDeviceInfo;

/**
 * @if OSPDEPREC
 * @interface   IWifiDirectGroupClientListener
 * @brief       <i> [Deprecated] </i> This interface implements listeners for the WifiDirectGroupClient events.
 * @deprecated  The WifiDirectGroupClient class is deprecated, therefore, this interface is also deprecated. @n
 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role(for example, group owner,
 *              group client, and so on) and so it was necessary to use these APIs. @n
 *              The Wi-Fi Direct APIs have now been revised to allow the use of APIs with ease irrespective of the
 *              role. Now the APIs have been integrated into the IWifiDirectDeviceListener interface. @n
 *              Instead of using the %IWifiDirectGroupClientListener interface, use the %IWifiDirectDeviceListener
 *              interface.
 *
 * @since       2.0
 *
 * The %IWifiDirectGroupClientListener interface represents a listener that is used to obtain the Wi-Fi Direct client
 * status or information.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 * @endif
 */

class _OSP_EXPORT_ IWifiDirectGroupClientListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupClient class is deprecated, therefore, this destructor is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role(for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              However, now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease
	 *              irrespective of the role.
	 *
	 * @since       2.0
	 * @endif
	 */
	virtual ~IWifiDirectGroupClientListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called to notify the application when the connection to a Wi-Fi Direct group owner is terminated.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupClient class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role(for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role. @n
	 *              As these APIs have now been integrated into the IWifiDirectDeviceListener interface, use
	 *              IWifiDirectDeviceListener::OnWifiDirectDisconnected() method instead.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId       An ID for a Wi-Fi Direct device
	 * @param[in]   reason              The reason to terminate this association
	 * @param[in]   r                   An error code
	 * @exception   E_SUCCESS           The disassociation is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @exception   E_NOT_RESPONDING    The target is not responding.
	 * @remarks
	 *              - When a device is disconnected by itself using WifiDirectGroupClient::Disassociate() method, this
	 *              event is invoked with Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_SELF_INITIATED. @n
	 *              - When a device is disconnected by a group owner using WifiDirectGroupOwner::Disconnect() method, due
	 *              to no range, or due to abrupt connection loss to the group owner, this event is invoked with
	 *              Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_DISCONNECTED.
	 * @see         WifiDirectGroupClient::Disassociate()
	 * @endif
	 */
	virtual void OnWifiDirectAssociationTerminated(WifiDirectDeviceId localDeviceId,
			WifiDirectAssociationTerminationReason reason, result r) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application when the request to acquire the WifiDirectDeviceInfo from a Wi-Fi Direct group
	 * owner is received.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupClient class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role(for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role. @n
	 *              So the APIs have been integrated into the WifiDirectDevice class. Hence, use the
	 *              WifiDirectDevice::GetGroupOwnerInfoN() method instead.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId                   An ID for a Wi-Fi Direct device
	 * @param[in]   wifiDirectGroupOwnerDeviceInfo  The WifiDirectDeviceInfo instance of the Wi-Fi Direct group owner
	 * @param[in]   r                               An error code
	 * @exception   E_SUCCESS                       The request for acquiring group owner information is successful.
	 * @exception   E_SYSTEM                        A system error has occurred.
	 * @exception   E_ALREADY_BOUND                 The specified port number is already in use.
	 * @exception   E_OUT_OF_MEMORY                 The memory is insufficient.
	 * @exception   E_NOT_RESPONDING                The target is not responding.
	 * @see         WifiDirectGroupClient::RequestGroupOwnerInfo()
	 * @endif
	 */
	virtual void OnWifiDirectGroupOwnerInfoReceived(WifiDirectDeviceId localDeviceId,
			const WifiDirectDeviceInfo& wifiDirectGroupOwnerDeviceInfo, result r) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application that the WifiDirectDeviceInfo list of group members has been received.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The WifiDirectGroupClient class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role(for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              This is because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease
	 *              irrespective of the role. @n
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId             An ID for a Wi-Fi Direct device
	 * @param[in]   pWifiDirectDeviceInfoList The list of WifiDirectDeviceInfo, @n
	 *                                        else @c null if it fails
	 * @param[in]   r                         An error code
	 * @exception   E_SUCCESS                 The response has been received successfully.
	 * @exception   E_SYSTEM                  A system error has occurred.
	 * @exception   E_ALREADY_BOUND           The specified port number is already in use.
	 * @exception   E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception   E_NOT_RESPONDING          The group owner is not reachable.
	 * @see         WifiDirectGroupClient::RequestAllGroupMemberInfo()
	 * @endif
	 */
	virtual void OnWifiDirectAllGroupMemberInfoReceivedN(WifiDirectDeviceId localDeviceId,
			Tizen::Base::Collection::IList* pWifiDirectDeviceInfoList, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupClientListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupClientListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupClientListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupClientListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectGroupClientListener_Reserved5(void) {}
}; // IWifiDirectGroupClientListener

} } } //Tizen::Net::Wifi
#endif // _FNET_WIFI_IWIFI_DIRECT_GROUP_CLIENT_LISTENER_H_
