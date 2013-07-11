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
 * @file	FNetWifiWifiDirectDevice.h
 * @brief	This is the header file for the %WifiDirectDevice class.
 *
 * This header file contains the declarations of the %WifiDirectDevice class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_DEVICE_H_
#define _FNET_WIFI_WIFI_DIRECT_DEVICE_H_

#include <FBaseObject.h>
#include <FNetWifiWifiTypes.h>


namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiDirectDeviceImpl;
class IWifiDirectDeviceListener;
class IWifiDirectGroupOwnerListener;
class IWifiDirectGroupClientListener;
class WifiDirectGroupInfo;
class WifiDirectDeviceInfo;
class WifiDirectGroupMember;

/**
 * @class   WifiDirectDevice
 * @brief   This class provides methods for the Wi-Fi Direct device.
 *
 * @since   2.0
 *
 * The %WifiDirectDevice class provides methods to manage the Wi-Fi Direct device, create a Wi-Fi Direct group,
 * scan Wi-Fi Direct devices, associate a Wi-Fi Direct group owner, create a WifiDirectGroupMember instance,
 * and allow the listener to get events related to a Wi-Fi Direct device and group.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _OSP_EXPORT_ WifiDirectDevice
	: public Tizen::Base::Object
{
public:
    /**
     *
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since   2.0
     */
    virtual ~WifiDirectDevice(void);

    /**
     * Adds a listener for Wi-Fi Direct device.
     *
     * @since   2.0
     *
     * @return      An error code
     * @param[in]   listener        A reference to the listener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @exception   E_OBJ_ALREADY_EXIST The listener is already added.
     */
    result AddWifiDirectDeviceListener(IWifiDirectDeviceListener& listener);

    /**
     * @if OSPDEPREC
     * Adds a listener for the Wi-Fi Direct group owner.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated, therefore, this method also is deprecated. @n
	 *	 Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n

     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        A reference to the IWifiDirectGroupOwnerListener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @exception   E_OBJ_ALREADY_EXIST The listener is already added.
     * @endif
     */
    result AddWifiDirectGroupOwnerListener(IWifiDirectGroupOwnerListener& listener);

    /**
     * @if OSPDEPREC
     * Adds a listener for the Wi-Fi Direct group client.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupClient class is deprecated, therefore, this method also is deprecated. @n
	 * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        A reference to the IWifiDirectGroupClientListener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @exception   E_OBJ_ALREADY_EXIST The listener is already added.
     * @endif
     */
    result AddWifiDirectGroupClientListener(IWifiDirectGroupClientListener& listener);

    /**
     * Removes a listener for the Wi-Fi Direct device.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        A reference to the IWifiDirectDeviceListener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OBJ_NOT_FOUND The specified object is not found within the indicated range.
     */
    result RemoveWifiDirectDeviceListener(IWifiDirectDeviceListener& listener);

    /**
     * @if OSPDEPREC
     * Removes a listener for the Wi-Fi Direct group owner.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated, therefore, this method also is deprecated. @n
     *               Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        A reference to the IWifiDirectGroupOwnerListener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OBJ_NOT_FOUND The specified object is not found within the indicated range.
     * @endif
     */
    result RemoveWifiDirectGroupOwnerListener(IWifiDirectGroupOwnerListener& listener);

    /**
     * @if OSPDEPREC
     * Removes a listener for the Wi-Fi Direct group client.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupClient class is deprecated, therefore, this method also is deprecated. @n
     * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     *
	 * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        A reference to the IWifiDirectGroupClientListener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OBJ_NOT_FOUND The specified object is not found within the indicated range.
     * @endif
     */
    result RemoveWifiDirectGroupClientListener(IWifiDirectGroupClientListener& listener);

    /**
     * Activates the local Wi-Fi device by using the Wi-Fi Direct enabled.
     *
     * @since   2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @exception   E_SUCCESS           The activation is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       The activate process is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the Wi-Fi Direct device is already activated.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see IWifiDirectDeviceListener::OnWifiDirectDeviceActivated()
     */
    result Activate(void);

    /**
     * Checks whether the local device is activated.
     *
     * @since 2.0
     *
     * @return  @c true if the local device is activated, @n
     *          else @c false
     * @exception   E_SUCCESS       The hidden mode is set successfully.
     * @exception   E_SYSTEM        A system error has occurred.
     */
    bool IsActivated(void) const;

    /**
     * Deactivates the local Wi-Fi device.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @exception   E_SUCCESS           The deactivation is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       The deactivate process is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the Wi-Fi Direct device is already deactivated.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     *
     * @see IWifiDirectDeviceListener::OnWifiDirectDeviceDeactivated()
     */
    result Deactivate(void);

    /**
     * Gets the current setting information of a Wi-Fi Direct group.
     *
     * @since 2.0
     *
     * @return      The Wi-Fi Direct group information if successful, @n
     *              else @c null
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    WifiDirectGroupInfo* GetGroupSettingInfoN(void) const;

    /**
     * Gets the current setting information of a Wi-Fi Direct device.
     *
     * @since 2.0
     *
     * @return      The Wi-Fi Direct device information if successful, @n
     *              else @c null
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    WifiDirectDeviceInfo* GetLocalDeviceInfoN(void) const;

    /**
     * Gets the preferred method for the Wi-Fi Protected Setup (WPS) configuration.
     *
     * @since 2.0
     *
     * @return      The preferred configuration mode for WPS
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     *              @c WIFI_WPS_CONFIG_MODE_NONE will be returned in case of the E_SYSTEM exception.
     */
    WifiWpsConfigurationMode GetWpsConfigurationModePreference(void) const;

    /**
     * Sets the name of a local device.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   name                The name for a local device
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_ARG       The specified device name is an empty string.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the Wi-Fi Direct device is already activated.
     * @remarks     This method does not affect the system setting and the device name is only valid during the
     *              group lifetime. @n
     *              When an application in the deactivated state calls this method, the peer devices
     *              detect the device specified in the @c name parameter.
     *              For example, use this method before using Activate(). @n
     *              The specified device name is automatically truncated if its size is greater than @c 64 bytes.
     */
    result SetLocalDeviceName(const Tizen::Base::String& name);

    /**
    * Sets the preferred method for the WPS configuration.
    *
    * @since 2.0
    *
    * @return           An error code
    * @param[in] mode   The preferred mode for the WPS configuration
    * @exception E_SUCCESS              The method is successful.
    * @exception E_SYSTEM               A system error has occurred.
    * @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
    *                                For example, the Wi-Fi Direct device is a group member.
    * @remarks   The preferred configuration mode of the system is the PIN-DISPLAY method. @n
    *            This method can change the preferred configuration method for the WPS procedure.
    *            If the remote device does not support the specified configuration method,
    *            the common configuration method is selected between the two devices automatically.
    *            Therefore, this method does not guarantee the use of specified WPS configuration method. @n
    *            Before calling Connect() method, the user preferred WPS configuration mode should be specified using the SetWpsConfigurationModePreference() method.
    */
    result SetWpsConfigurationModePreference(WifiWpsConfigurationMode mode);

    /**
     * @if OSPDEPREC
     * Creates a Wi-Fi Direct group by negotiating with the specified Wi-Fi Direct device for the group owner.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role (for example, group owner, group client, and so on). @n
     * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to use these APIs.
     *              Instead of using this API, use Connect() or CreateAutonomousGroup() API.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return      An error code
     * @param[in]   pWifiDirectGroupInfo        The pointer of a WiFiDirectGroupInfo
     * @param[in]   pWifiDirectRemoteDeviceInfo The pointer of a WiFiDirectDeviceInfo
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_ARG       The specified @c pWifiDirectRemoteDeviceInfo contains an invalid argument.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the Wi-Fi Direct group is already created.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @remarks It is not mandatory for this method to contain values in both the parameters. @n
     * If @c pWifiDirectGroupInfo is specified and the group is created with the specified group configuration information,
     * this group configuration information is valid until the group is destroyed.
     * If @c pWifiDirectGroupInfo is not specified, the Wi-Fi Direct group is created as per the default system configuration settings. @n
     * If @c pWifiDirectRemoteDeviceInfo is not specified, the Wi-Fi Direct group is created with the
     * first found device having the same local device name.
     * Use SetLocalDeviceName() method to set the device name before activation. @n
     * To obtain a list of Wi-Fi Direct devices which can be candidates for the @c pWifiDirectRemoteDeviceInfo
     * parameter, use the Scan() method prior using this method.
     * To connect a specified Wi-Fi Direct group owner directly, the Scan() and Associate() methods can be used. @n
     * Before this method is called, the event listeners should be added in order to ensure the completion of
     * group creation and to process the request as a group owner or client. @n
     * If the autonomous group owner mode is set to @c true in the specified @c pWifiDirectGroupInfo parameter,
     * @c pWifiDirectRemoteDeviceInfo should be set to @c null and IWifiDirectGroupClientListener would not be required.
     * @see IWifiDirectDeviceListener::OnWifiDirectGroupCreatedN()
     * @endif
     */
    result CreateGroup(const WifiDirectGroupInfo* pWifiDirectGroupInfo = null, const WifiDirectDeviceInfo* pWifiDirectRemoteDeviceInfo = null);

    /**
     * @if OSPDEPREC
     * Cancels Wi-Fi Direct group creation.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role (for example, group owner, group client, and so on). @n
     * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to use these APIs. @n
     *              Instead of using this API, use CancelConnect() API
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, when there is no group being created.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see	CreateGroup()
	 * @see	IWifiDirectDeviceListener::OnWifiDirectGroupCreatedN()
	 * @endif
     */
    result CancelGroupCreation(void);

    /**
     * Scans Wi-Fi Direct Devices which are in the specified type.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.read
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the Wi-Fi Direct device is deactivated.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @remarks     This operation does not work while the Wi-Fi connection to the AP is in progress or established.
     * @see         IWifiDirectDeviceListener::OnWifiDirectScanCompletedN()
     */
    result Scan(void);

    /**
     * Cancels the Wi-Fi Direct previous scan operation.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.read
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the scan operation is not in process.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see         IWifiDirectDeviceListener::OnWifiDirectScanCompletedN()
     */
    result CancelScan(void);

    /**
     * @if OSPDEPREC
     * Establishes a connection with a specific group owner.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role (for example, group owner, group client, and so on). @n
     * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to use these APIs. @n
     *              Instead of using this API, use Connect() API
     *
     * @since 2.0
     * @privilege    %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return       An error code
     * @param[in]    wifiDirectGroupOwnerDeviceInfo	The WifiDirectDeviceInfo value of a group owner
     * @exception    E_SUCCESS           The method is successful.
     * @exception    E_SYSTEM            A system error has occurred.
     * @exception    E_IN_PROGRESS       A previous request or group creation is in progress.
     * @exception    E_INVALID_ARG       The specified @c wifiDirectGroupOwnerDeviceInfo contains an invalid argument.
     * @exception    E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                   For example, the member type of a device is already a group owner or client.
     * @exception    E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @remarks      If a connection is already established with other device, the previous connection should be disconnected
     *               before using this method.
     * @see          IWifiDirectDeviceListener::OnWifiDirectAssociationCompleted()
     * @endif
     */
    result Associate(const WifiDirectDeviceInfo& wifiDirectGroupOwnerDeviceInfo);

    /**
     * @if OSPDEPREC
     * Gets the Wi-Fi Direct member instance.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role (for example, group owner, group client, and so on). @n
     * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to use these APIs.
     *
     * @since 2.0
     *
     * @return      The Wi-Fi Direct member instance if successful, @n
     *              else @c null if the status of device is @c WIFI_DIRECT_GROUP_MEMBER_TYPE_NONE
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the member type of a device is not a group owner or client.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @endif
     */
    WifiDirectGroupMember* GetWifiDirectMemberN(void) const;

    /**
     * Checks whether the local Wi-Fi Direct device is currently discoverable.
     *
     * @since 2.0
     *
     * @return      @c true if the local Wi-Fi Direct device is currently discoverable, @n
     *              else @c false
     * @remarks     At times, even though the Wi-Fi Direct device is activated the device cannot be discovered due to the visibility
     *				setting, or if the device is performing some operation, such as Wi-Fi scanning.
     */
    bool IsDiscoverable(void) const;

    /**
     * Connects to the Wi-Fi Direct connection with the specified peer device.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @param[in]   remoteDeviceInfo  The remote peer device to connect.
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_SYSTEM                A system error has occurred.
     * @exception   E_IN_PROGRESS           The previous request is in progress.
     * @exception   E_INVALID_ARG           The specified @c remoteDeviceInfo is invalid.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this operation. @n
     *                                      For example, the local device is already connected except in the case of group owner.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     *
     * @remarks   If the local device does not belong to a group owner or client, a group negotiation request is sent to the remote device and the configured group information is used at this time. @n
     *            If the local device is a group owner, a request to join the group is sent to the remote device.
     *
     * @see IWifiDirectDeviceListener::OnWifiDirectConnected()
     * @see SetGroupSettingInfo()
     * @see SetWpsConfigurationModePreference()
     */
    result Connect(const WifiDirectDeviceInfo& remoteDeviceInfo);

    /**
     * Cancels the request for Wi-Fi Direct connection.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_SYSTEM                A system error has occurred.
     * @exception   E_IN_PROGRESS           The previous request is in progress.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this operation. @n
     *                                      For example, the local device is not connecting.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     *
     * @see IWifiDirectDeviceListener::OnWifiDirectConnected()
     */
    result CancelConnect(void);

    /**
     * Creates a Wi-Fi Direct group as the group owner.
     *
     * @since 2.0
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_SYSTEM                A system error has occurred.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this operation. @n
     *                                 For example, the local device is already deactivated or connected.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     *
     * @see IWifiDirectDeviceListener::OnWifiDirectAutonomousGroupCreated()
     *
     */
    result CreateAutonomousGroup(void);

    /**
     * Sets the configuration information of a Wi-Fi Direct group.
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @param[in]   groupSettingInfo   The group setting information
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this operation. @n
     *                                      For example, the local device is already deactivated or connected.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     *
     * @remarks This method should be called before using Connect() to configure the group information.
     */
    result SetGroupSettingInfo(const WifiDirectGroupInfo& groupSettingInfo);

    /**
     * Disconnects the specified peer device.
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @param[in]   peerDeviceInfo      The peer device to disconnect
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       The previous request is in progress.
     * @exception   E_INVALID_ARG       The specified @c remoteDeviceInfo is invalid.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the local device is not connected.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     *
     * @see IWifiDirectDeviceListener::OnWifiDirectDisconnected()
     */
    result Disconnect(const WifiDirectDeviceInfo& peerDeviceInfo);

    /**
     * Leaves the currently participating Wi-Fi Direct group.
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return  An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       The previous request is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the local device is not a group owner or client.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     *
     * @see IWifiDirectDeviceListener::OnWifiDirectGroupLeft()
     * @remarks If the local device belongs to a group owner, the group will be destroyed and the IWifiDirectDeviceListener::OnWifiDirectDisconnected() event method will not occur for each client connection.
     */
    result LeaveGroup(void);


    /**
     * Gets information of the group owner of a Wi-Fi Direct group.
     *
     * @since 2.0
     *
     * @return    The Wi-Fi Direct group owner information if successful, @n
     *           else null
     * @exception E_SUCCESS           The method is successful.
     * @exception E_SYSTEM            A system error has occurred.
     * @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                For example, the local device is not connected.
     * @remarks The specific error code can be accessed using the GetLastResult() method
     */
    WifiDirectDeviceInfo* GetGroupOwnerInfoN(void) const;

    /**
     * Gets the list of the Wi-Fi Direct group clients.
     *
     * @since 2.0
     *
     * @return   A pointer to the list that contains the WifiDirectDeviceInfo instances of the group clients if successful, @n
     *           else @c null
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, the local device is not a group owner.
     */
    Tizen::Base::Collection::IList* GetGroupClientInfoListN(void) const;

    /**
     * Gets the index of a currently working channel.
     *
     * @since 2.0
     *
     * @return  The Wi-Fi radio channel
     *
     * @remarks If the member type of the local device is not a group owner or client, the channel does not contain valid information.
     */
    WifiRadioChannel GetOperatingChannel(void) const;

private:
    /**
     *
     * This default constructor is intentionally declared as private so that only the platform can create an instance.
     * @remarks     After creating an instance of this class, the Construct() method must be called explicitly
     *              to initialize this instance.
     * @see         Construct()
     */
    WifiDirectDevice(void);

    /**
     * This copy constructor is intentionally declared as private to prohibit copying of objects by users.
     *
     * @param[in]   value   An instance of %WifiDirectDevice
     */
    WifiDirectDevice(const WifiDirectDevice& value);

    /**
     * Initializes this instance of %WifiDirectDevice.
     *
     * @return      An error code
     * @param[in]   localDeviceId   An ID for a Wi-Fi Direct device
     *
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @exception   E_INVALID_ARG   The specified @c localDeviceId is invalid.
     */
    result Construct(WifiDirectDeviceId localDeviceId);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to
     * prohibit copying of objects.
     *
     * @param[in]   rhs An instance of %WifiDirectDevice
     */
    WifiDirectDevice& operator =(const WifiDirectDevice& rhs);

private:
    _WifiDirectDeviceImpl* __pWifiDirectDeviceImpl;

    friend class _WifiDirectDeviceImpl;
}; // WifiDirectDevice

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_DEVICE_H_
