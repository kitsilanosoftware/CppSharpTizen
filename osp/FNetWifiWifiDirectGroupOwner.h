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
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file    FNetWifiWifiDirectGroupOwner.h
 * @brief   This is the header file for the %WifiDirectGroupOwner class.
 *
 * This header file contains the declarations of the %WifiDirectGroupOwner class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_GROUP_OWNER_H_
#define _FNET_WIFI_WIFI_DIRECT_GROUP_OWNER_H_

#include <FNetWifiWifiDirectGroupMember.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
} } } // Tizen::Base::Collection

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiDirectGroupOwnerImpl;
class WifiDirectDeviceInfo;

/**
 * @if OSPDEPREC
 * @class   WifiDirectGroupOwner
 * @brief   <i> [Deprecated] </i> This class provides methods for the Wi-Fi Direct group owner management.
 * @deprecated   This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role (for example, group owner, group client, and so on). @n
 * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to use these APIs. @n
 * As the APIs have been integrated into the WifiDirectDevice class, use IWifiDirectDevice class instead.
 *
 * @since   2.0
 *
 * The %WifiDirectGroupOwner class provides methods to manage the Wi-Fi Direct group.
 * @endif
 */

class _OSP_EXPORT_ WifiDirectGroupOwner
    : public WifiDirectGroupMember
{
public:
    /**
     * @if OSPDEPREC
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     *
     * @since 2.0
     * @endif
     */
    virtual ~WifiDirectGroupOwner(void);

    /**
     * @if OSPDEPREC
     * Destroys a Wi-Fi Direct group.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
* Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     *              As the APIs have been integrated into the WifiDirectDevice class, use WifiDirectDevice::LeaveGroup() API instead.
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, when the member type of a device is not a Wi-Fi Direct group owner.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see         IWifiDirectGroupOwnerListener::OnWifiDirectGroupDestroyed()
     * @endif
     */
    result DestroyGroup(void);

    /**
     * @if OSPDEPREC
     * Disconnects a specified Wi-Fi Direct group client.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
	 *              As the APIs have been integrated into the WifiDirectDevice class, use WifiDirectDevice::Disconnect() API instead.
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
     *
     * @return      An error code
     * @param[in]   wifiDirectRemoteDeviceInfo  The device information of a group client to disconnect
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_ARG       A specified input parameter is invalid.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
     *                                  For example, when the member type of a device is not a Wi-Fi Direct group owner.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see         IWifiDirectGroupOwnerListener::OnWifiDirectClientDisassociated()
     * @endif
     */
    result Disconnect(const WifiDirectDeviceInfo& wifiDirectRemoteDeviceInfo);

    /**
     * @if OSPDEPREC
     * Gets the list of information of all the members of the Wi-Fi Direct group.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated ,therefore, this method is also deprecated. @n
* Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
      *              Instead of GetAllGroupMemberInfoListN() method, use WifiDirectDevice::GetGroupOwnerInfoN() for group owner information and WifiDirectDevice::GetGroupClientInfoListN() for group clients information.
     *
     * @since 2.0
     *
     * @return      The list of WifiDirectDeviceInfo
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, when the member type of a device is not a Wi-Fi Direct group owner.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @endif
     */
    Tizen::Base::Collection::IList* GetAllGroupMemberInfoListN(void) const;

    /**
     * @if OSPDEPREC
     * Starts the group member information service.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  This method is deprecated, therefore, this method is also deprecated. @n
	 * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.read, %http://tizen.org/privilege/network.connection and %http://tizen.org/privilege/socket @n
     *              All the above privileges are required
     *
     * @return      An error code
     * @param[in]   portNumber          A port number to start group member information service
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_OUT_OF_RANGE      The specified port number is less than 1024 or greater than 65535.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
     *                                  For example, member type of @c wifiDirectDevice is not the group owner or client.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see       IWifiDirectGroupOwnerListener::OnWifiDirectGroupMemberInfoServiceStarted()
     * @endif
     */
    result StartGroupMemberInfoService(int portNumber = DEFAULT_PORT);

    /**
     * @if OSPDEPREC
     * Stops the group member information service.
     *
     * @brief   <i> [Deprecated] </i>
     * @deprecated  %WifiDirectGroupOwner class is deprecated, therefore, this method is also deprecated. @n
	 * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group owner, group client, and so on) and so it was necessary to use these APIs. @n
	 * Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role. @n
     *
     * @since 2.0
     *
     * @privilege   %http://tizen.org/privilege/wifi.wifidirect.read, %http://tizen.org/privilege/network.connection and %http://tizen.org/privilege/socket @n
     *              All the above privileges are required
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_IN_PROGRESS       A previous request is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see         IWifiDirectGroupOwnerListener::OnWifiDirectGroupMemberInfoServiceStopped()
     * @endif
     */
    result StopGroupMemberInfoService(void);

private:
    /**
     * This default constructor is intentionally declared as private so that only the platform can create an instance.
     *
     * @remarks     After creating an instance of this class, the Construct() method must be explicitly called to
     *              initialize this instance.
     * @see         Construct()
     */
    WifiDirectGroupOwner(void);

    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]   value   An instance of %WifiDirectGroupOwner
     */
    WifiDirectGroupOwner(const WifiDirectGroupOwner& value);

    /**
     * Initializes this instance of WifiDirectGroupOwner with the specified listener.
     *
     * @return      An error code
     *
     * @param[in]   wifiDirectDeviceImpl    A reference to the __WifiDirectDeviceImpl instance
     *
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result Construct(_WifiDirectGroupOwnerImpl& wifiDirectGroupOwnerImpl);

    /**
     * The implementation of this copy assignment operator is intentionally blank and
     * declared as private to prohibit copying of objects.
     *
     * @param[in]   rhs An instance of %WifiDirectGroupOwner
     */
    WifiDirectGroupOwner& operator =(const WifiDirectGroupOwner& rhs);

private:
    static const int DEFAULT_PORT = 3895;

    _WifiDirectGroupOwnerImpl* __pWifiDirectGroupOwnerImpl;

    friend class _WifiDirectGroupOwnerImpl;
}; // WifiDirectGroupOwner

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_GROUP_OWNER_H_
