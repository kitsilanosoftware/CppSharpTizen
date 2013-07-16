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
 * @file        FNetWifiIWifiDirectDeviceListener.h
 * @brief       This is the header file for the %IWifiDirectDeviceListener interface.
 *
 * This header file contains the declarations of the %IWifiDirectDeviceListener interface.
 */
#ifndef _FNET_WIFI_IWIFI_DIRECT_DEVICE_LISTENER_H_
#define _FNET_WIFI_IWIFI_DIRECT_DEVICE_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetWifiWifiTypes.h>
#include <FNetWifiWifiDirectGroupMember.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
} } } // Tizen::Base::Collection

namespace Tizen { namespace Net { namespace Wifi
{
class WifiDirectGroupInfo;
class WifiDirectDeviceInfo;

/**
 * @interface   IWifiDirectDeviceListener
 * @brief       This interface implements listeners for the WifiDirectDevice events.
 *
 * @since       2.0
 *
 * The %IWifiDirectDeviceListener interface represents a listener to get the Wi-Fi Direct device status or information.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _OSP_EXPORT_ IWifiDirectDeviceListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IWifiDirectDeviceListener(void) {}

	/**
	 * Called to notify the application that the local Wi-Fi Direct mode is enabled.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId   The ID of the Wi-Fi Direct device
	 * @param[in]   r               An error code
	 * @exception   E_SUCCESS       The activation is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         WifiDirectDevice::Activate()
	 */
	virtual void OnWifiDirectDeviceActivated(WifiDirectDeviceId localDeviceId, result r) = 0;

	/**
	 * Called to notify the application that the local Wi-Fi Direct mode is disabled.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId   An ID for a Wi-Fi Direct device
	 * @param[in]   r               An error code
	 * @exception   E_SUCCESS       The deactivation is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         WifiDirectDevice::Deactivate()
	 */
	virtual void OnWifiDirectDeviceDeactivated(WifiDirectDeviceId localDeviceId, result r) = 0;

	/**
	 * Called to notify the application when a Wi-Fi Direct connection is established with a remote device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId           An ID for a Wi-Fi Direct device
	 * @param[in]   remoteDeviceInfo        The remote device
	 * @param[in]   r                       An error code
	 *
	 * @exception   E_SUCCESS               The Wi-Fi Direct group has been created successfully.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @exception   E_OPERATION_CANCELED    The operation has been cancelled explicitly.
	 * @exception   E_AUTHENTICATION        The authentication has failed during the Wi-Fi connection process.
	 * @exception   E_NOT_RESPONDING        The remote device is not responding.
	 * @see         WifiDirectDevice::Connect()
	 * @see         WifiDirectDevice::CancelConnect()
	 */
	virtual void OnWifiDirectConnected(WifiDirectDeviceId localDeviceId, const WifiDirectDeviceInfo& remoteDeviceInfo,
			result r) = 0;

	/**
	 * Called to notify the application when the Wi-Fi Direct connection is disconnected with a peer device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId   An ID for a Wi-Fi Direct device
	 * @param[in]   peerMacAddress  The mac address of the peer device
	 * @param[in]   r               An error code
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         WifiDirectDevice::Disconnect()
	 */
	virtual void OnWifiDirectDisconnected(WifiDirectDeviceId localDeviceId, const Tizen::Base::String& peerMacAddress,
			result r) = 0;

	/**
	  * Called to notify the application when an autonomous group is created.
	  *
	  * @since      2.0
	  *
	  * @param[in]  localDeviceId   An ID for a Wi-Fi Direct device
	  * @param[in]  r               An error code
	  * @exception  E_SUCCESS       The method is successful.
	  * @exception  E_SYSTEM        A system error has occurred.
	  * @see        WifiDirectDevice::CreateAutonomousGroup()
	  */
	virtual void OnWifiDirectAutonomousGroupCreated(WifiDirectDeviceId localDeviceId, result r) = 0;

	/**
	 * Called to notify the application when a local device leaves the group.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId   An ID for a Wi-Fi Direct device
	 * @param[in]   r               An error code
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         WifiDirectDevice::LeaveGroup()
	 */
	virtual void OnWifiDirectGroupLeft(WifiDirectDeviceId localDeviceId, result r) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application about the result and related information when a group is created or when a
	 * request to create a group is cancelled.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the Wi-Fi direct APIs have been revised to allow the use of APIs
	 *              with ease irrespective of the role (for example, group owner, group client, and so on). @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary
	 *              to use these APIs. @n
	 *              Instead of using this method, use OnWifiDirectConnected() or OnWifiDirectAutonomousGroupCreated()
	 *              method.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId                   An ID for a Wi-Fi Direct device
	 * @param[in]   wifiDirectGroupInfo             The WifiDirectGroupInfo instance set by the winning group owner after
	 *                                              negotiation
	 * @param[in]   wifiDirectGroupOwnerDeviceInfo  The WifiDirectDeviceInfo instance of the group owner
	 * @param[in]   pWifiDirectMember               The WifiDirectGroupMember instance that is casted to the instance of
	 *                                              WifiDirectGroupOwner or WifiDirectGroupClient as a result of negotiation
	 *                                              after the creation of a group
	 * @param[in]   r                               An error code
	 * @exception   E_SUCCESS                       The Wi-Fi Direct group creation is successful.
	 * @exception   E_SYSTEM                        A system error has occurred.
	 * @exception   E_OPERATION_CANCELED            The operation has been cancelled explicitly.
	 * @exception   E_AUTHENTICATION                The authentication has failed during the Wi-Fi connection process.
	 * @exception   E_DHCP                          The DHCP operation has failed.
	 * @exception   E_NOT_RESPONDING                The target is not responding.
	 * @exception   E_REJECTED                      The connection request has been rejected.
	 * @exception   E_REMOTE_DEVICE_NOT_FOUND       The Wi-Fi Direct device has not been found.
	 * @remarks     If a device becomes a group client, then the WifiDirectGroupInfo::GetGroupOwnerIntent() and
	 *              WifiDirectGroupInfo::GetMaxNumberOfClients() methods will not contain valid information.
	 * @see         WifiDirectDevice::CreateGroup()
	 * @see         WifiDirectDevice::CancelGroupCreation()
	 * @endif
	 */
	virtual void OnWifiDirectGroupCreatedN(WifiDirectDeviceId localDeviceId, const WifiDirectGroupInfo& wifiDirectGroupInfo,
			const WifiDirectDeviceInfo& wifiDirectGroupOwnerDeviceInfo, WifiDirectGroupMember* pWifiDirectMember, result r)
	{ delete pWifiDirectMember; }

	/**
	 * Called to notify the application when the scan is completed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId               An ID for a Wi-Fi Direct device
	 * @param[in]   pWifiDirectDeviceInfoList   The WifiDirectDeviceInfo information list representing the
	 *                                          Wi-Fi Direct devices discovered by scan
	 * @param[in]   r                           An error code
	 * @exception   E_SUCCESS                   The scan is successful.
	 * @exception   E_SYSTEM                    A system error has occurred.
	 * @exception   E_OPERATION_CANCELED        The operation has been cancelled explicitly.
	 * @see         WifiDirectDevice::Scan()
	 * @see         WifiDirectDevice::CancelScan()
	 */
	virtual void OnWifiDirectScanCompletedN(WifiDirectDeviceId localDeviceId,
			Tizen::Base::Collection::IList* pWifiDirectDeviceInfoList, result r) = 0;

	/**
	 * @if OSPDEPREC
	 * Called to notify the application when the connection to a Wi-Fi Direct group owner is completely established.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the Wi-Fi direct APIs have been revised to allow the use of APIs
	 *              with ease irrespective of the role (for example, group owner, group client, and so on). @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary
	 *              to use these APIs. @n
	 *              Instead of using this method, use OnWifiDirectConnected() method.
	 *
	 * @since       2.0
	 *
	 * @param[in]   localDeviceId                   An ID for a Wi-Fi Direct device
	 * @param[in]   wifiDirectGroupOwnerDeviceInfo  The WifiDirectDeviceInfo of the connected Wi-Fi Direct group
	 *                                              owner
	 * @param[in]   r                               An error code
	 * @exception   E_SUCCESS                       The association is successful.
	 * @exception   E_SYSTEM                        A system error has occurred.
	 * @exception   E_AUTHENTICATION                The authentication has failed during the Wi-Fi connection process.
	 * @exception   E_DHCP                          The DHCP operation has failed.
	 * @exception   E_NOT_RESPONDING                The target is not responding.
	 * @exception   E_REJECTED                      The connection request has been rejected.
	 * @exception   E_REMOTE_DEVICE_NOT_FOUND       The Wi-Fi Direct device has not been found.
	 * @see         WifiDirectDevice::Associate()
	 * @endif
	 */
	virtual void OnWifiDirectAssociationCompleted(WifiDirectDeviceId localDeviceId,
			const WifiDirectDeviceInfo& wifiDirectGroupOwnerDeviceInfo, result r) {}

	/**
	 * Called to notify the application when a remote device is found during the Wi-Fi Direct scan process.
	 *
	 * @since       2.1
	 *
	 * @param[in]   localDeviceId       An ID for a Wi-Fi Direct device
	 * @param[in]   remoteDeviceInfo    The remote device that is found
	 * @see         WifiDirectDevice::Scan()
	 */
	virtual void OnWifiDirectRemoteDeviceFound(WifiDirectDeviceId localDeviceId, const WifiDirectDeviceInfo& remoteDeviceInfo) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectDeviceListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectDeviceListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectDeviceListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void OnWifiDirectDeviceListener_Reserved4(void) {}

}; // IWifiDirectDeviceListener

} } } //Tizen::Net::Wifi
#endif // _FNET_WIFI_IWIFI_DIRECT_DEVICE_LISTENER_H_
