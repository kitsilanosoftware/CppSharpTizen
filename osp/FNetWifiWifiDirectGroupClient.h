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
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file    FNetWifiWifiDirectGroupClient.h
 * @brief   This is the header file for the %WifiDirectGroupClient class.
 *
 * This header file contains the declarations of the %WifiDirectGroupClient class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_GROUP_CLIENT_H_
#define _FNET_WIFI_WIFI_DIRECT_GROUP_CLIENT_H_

#include <FNetWifiWifiDirectGroupMember.h>

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiDirectGroupClientImpl;

/**
 * @if OSPDEPREC
 * @class        WifiDirectGroupClient
 * @brief        <i> [Deprecated] </i> This class provides methods for the Wi-Fi Direct group client management.
 * @deprecated   This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs
 *               with ease irrespective of the role (for example, group owner, group client, and so on). @n
 *               Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to
 *               use these APIs.@n
 *               As the APIs have been integrated into WifiDirectDevice class, use WifiDirectDevice class instead.
 *
 * @since        2.0
 *
 * The %WifiDirectGroupClient class provides methods to manage the Wi-Fi Direct client.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 * @endif
 */

class _OSP_EXPORT_ WifiDirectGroupClient
	: public WifiDirectGroupMember
{
public:
	/**
	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The %WifiDirectGroupClient class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role.
	 *
	 * @since       2.0
	 * @endif
	 */
	virtual ~WifiDirectGroupClient(void);

	/**
	 * @if OSPDEPREC
	 * Closes the connection.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The %WifiDirectGroupClient class is deprecated. Therefore, this method is also deprecated, because
	 *              previously the Wi-Fi Direct APIs were provided centered on the role(e.g. group owner, group client).@n
	 *              So it was necessary to use APIs in accordance with the strict role; however, it has been revised to
	 *              allow using APIs with ease without discerning the role. @n
	 *              It is integrated into WifiDirectDevice class. Use the WifiDirectDevice::Disconnect() method.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/wifi.wifidirect.admin
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @exception   E_IN_PROGRESS       A previous request is in progress.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, when the member type of a device is not a Wi-Fi Direct group client.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see         IWifiDirectGroupClientListener::OnWifiDirectAssociationTerminated()
	 * @endif
	 */
	result Disassociate(void);

	/**
	 * @if OSPDEPREC
	 * Requests the WifiDirectDeviceInfo of the Wi-Fi Direct group owner.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  The %WifiDirectGroupClient class is deprecated. Therefore, this method is also deprecated, because
	 *              previously the Wi-Fi Direct APIs were provided centered on the role(e.g. group owner, group client) @n
	 *              so it was necessary to use APIs in accordance with the strict role; however, it has been revised to
	 *              allow using APIs with ease without discerning the role. @n
	 *              Instead of using this method, use the WifiDirectDevice::GetGroupOwnerInfoN() method.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/wifi.wifidirect.read, %http://tizen.org/privilege/network.connection
	 *              and %http://tizen.org/privilege/socket @n
	 *              All the above privileges are required.
	 *
	 * @return      An error code
	 * @param[in]   portNumber           A port number to connect to the group member information service
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_SYSTEM             A system error has occurred.
	 * @exception   E_IN_PROGRESS        The previous request for the group owner information is in progress.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of this operation. @n
	 *                                   For example, when the member type of a device is not a Wi-Fi Direct group client.
	 * @exception   E_OUT_OF_RANGE       The specified port number is less than 1024 or greater than 65535.
	 * @exception   E_PRIVILEGE_DENIED   The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED The user blocks an application from calling this method. @b Since: @b 2.1
	 *
	 * @remarks     The port number used by the group owner must be specified if the group owner changes the port number
	 *              in WifiDirectGroupOwner::StartGroupMemberInfoService().
	 * @see         IWifiDirectGroupClientListener::OnWifiDirectGroupOwnerInfoReceived()
	 * @endif
	 */
	result RequestGroupOwnerInfo(int portNumber = DEFAULT_PORT);

	/**
	 * @if OSPDEPREC
	 * Requests the WifiDirectDeviceInfo list of the Wi-Fi Direct group members.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  %WifiDirectGroupClient class is deprecated, therefore, this method is also deprecated. @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role (for example, group
	 *              owner, group client, and so on) and so it was necessary to use these APIs. @n
	 *              Now the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the
	 *              role. @n
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/wifi.wifidirect.read, %http://tizen.org/privilege/network.connection
	 *              and %http://tizen.org/privilege/socket @n
	 *              All the above privileges are required.
	 *
	 * @return      An error code
	 * @param[in]   portNumber           A port number to connect to the group member information service
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_SYSTEM             A system error has occurred.
	 * @exception   E_IN_PROGRESS        The previous request for the group owner information is in progress.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of this operation. @n
	 *                                   For example, when the member type of a device is not a Wi-Fi Direct group client.
	 * @exception   E_OUT_OF_RANGE       The specified port number is less than 1024 or greater than 65535.
	 * @exception   E_PRIVILEGE_DENIED   The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks     The port number used by the group owner should be specified if the group owner changed the port
	 *              number in WifiDirectGroupOwner::StartGroupMemberInfoService().
	 * @see         IWifiDirectGroupClientListener::OnWifiDirectAllGroupMemberInfoReceivedN()
	 * @endif
	 */
	result RequestAllGroupMemberInfo(int portNumber = DEFAULT_PORT);

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @remarks     After creating an instance of this class, the Construct() method must be called explicitly
	 *              to initialize this instance.
	 *
	 * @see         Construct()
	 */
	WifiDirectGroupClient(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]   value                An instance of %WifiDirectGroupClient
	 */
	WifiDirectGroupClient(const WifiDirectGroupClient& value);

	/**
	 * Initializes this instance of %WifiDirectGroupClient with the specified parameter.
	 *
	 * @return An error code
	 *
	 * @param[in]   wifiDirectGroupClientImpl A reference to the _WifiDirectGroupClientImpl instance
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_SYSTEM             A system error has occurred.
	 */
	result Construct(_WifiDirectGroupClientImpl& wifiDirectGroupClientImpl);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	* copying of objects.
	*
	* @param[in]   rhs                   An instance of %WifiDirectGroupClient
	*/
	WifiDirectGroupClient& operator=(const WifiDirectGroupClient& rhs);

private:
	static const int DEFAULT_PORT = 3895;

	_WifiDirectGroupClientImpl* __pWifiDirectGroupClientImpl;

	friend class _WifiDirectGroupClientImpl;
}; // WifiDirectGroupClient

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_GROUP_CLIENT_H_
