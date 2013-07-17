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
 * @file    FNetWifiWifiDirectGroupInfo.h
 * @brief   This is the header file for the %WifiDirectGroupInfo class.
 *
 * This header file contains the declarations of the %WifiDirectGroupInfo class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_GROUP_INFO_H_
#define _FNET_WIFI_WIFI_DIRECT_GROUP_INFO_H_

#include <FBaseObject.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiDirectGroupInfoImpl;

/**
 * @class   WifiDirectGroupInfo
 * @brief   This class provides methods for the Wi-Fi Direct group information.
 *
 * @since   2.0
 *
 * The %WifiDirectGroupInfo class provides methods to get or set the information for a Wi-Fi Direct group.
 */

class _OSP_EXPORT_ WifiDirectGroupInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	WifiDirectGroupInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   value   An instance of %WifiDirectGroupInfo
	 */
	WifiDirectGroupInfo(const WifiDirectGroupInfo& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since       2.0
	 */
	virtual ~WifiDirectGroupInfo(void);

	/**
	 * @if OSPDEPREC
	 * Gets the autonomous group owner mode.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because this class has been modified and is now composed of information
	 *              exclusively required to configure a group. @n
	 *              So, a new API has been added. Instead of using this API, use
	 *              WifiDirectDevice::CreateAutonomousGroup() API.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the autonomous group owner mode is activated, @n
	 *              else @c false
	 * @endif
	 */
	bool GetAutonomousGroupOwnerMode(void) const;

	/**
	 * Gets the intent of a group owner. @n It is used during the negotiation phase.
	 *
	 * @since       2.0
	 *
	 * @return      An intent value
	 */
	int GetGroupOwnerIntent(void) const;

	/**
	 * Gets the maximum number of clients to be associated.
	 *
	 * @since       2.0
	 *
	 * @return      The maximum number of clients to be associated
	 */
	int GetMaxNumberOfClients(void) const;

	/**
	 * @{	
	 * @if OSPDEPREC
	 * Gets the SSID.
	 *
	 * @deprecated  This method is deprecated because this class has been modified and is now composed of information
	 *              that is exclusively required to configure a group. @n
	 *              So, new APIs have been added. Instead of using the %GetSsid() method, use the
	 *              WifiDirectDevice::GetGroupOwnerInfoN() or WifiDirectDevice::GetLocalDeviceInfo() method.
	 *
	 * @since       2.0
	 * @return      The SSID
	 * @endif
	 * @}
	 */
	Tizen::Base::String GetSsid(void) const;

	/**
	 */

	/**
	 * @if OSPDEPREC
	 * Gets the BSS ID.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because this class has been modified and is now composed of information
	 *              that is exclusively required to configure a group. @n
	 *              So, a new API has been added. Instead of using the %GetBssId() method, use the
	 *              WifiDirectDevice::GetGroupOwnerInfoN() method.
	 *
	 * @since       2.0
	 *
	 * @return      The BSS ID
	 * @endif
	 */
	Tizen::Base::String GetBssId(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of a currently working channel.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because this class has been modified and is now composed of information
	 *              exclusively required to configure a group. @n
	 *              So this API has been moved to the WifiDirectDevice class.
	 *
	 * @since       2.0
	 *
	 * @return      The Wi-Fi radio channel
	 * @endif
	 */
	WifiRadioChannel GetOperatingChannel(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the mode for an autonomous group owner.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because this class has been modified and is now composed of information
	 *              exclusively required to configure a group. @n
	 *              So, a new API has been added. Instead of using the %SetAutonomousGroupOwnerMode() method, use the
	 *              WifiDirectDevice::CreateAutonomousGroup() method.
	 *
	 * @since       2.0
	 *
	 * @param[in]   mode            Set to @c true if autonomous group owner mode is enabled, @n
	 *                              else @c false
	 * @endif
	 */
	void SetAutonomousGroupOwnerMode(bool mode);

	/**
	 * Sets the intent of a group owner.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   intent          The intent to become a group owner
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   Either the specified @c intent is less than @c 0, or exceeds
	 *                              Wifi::MAX_WIFI_DIRECT_GROUP_OWNER_INTENT.
	 * @remarks
	 *              - A higher intent value means that the intent to become a group owner is higher.
	 *              - If Wifi::MAX_WIFI_DIRECT_GROUP_OWNER_INTENT is selected, it means that a device insists to be a
	 *                group owner only.
	 *              - If two devices participating in a group creation select the intent value as
	 *                Wifi::MAX_WIFI_DIRECT_GROUP_OWNER_INTENT, the group creation fails.
	 */
	result SetGroupOwnerIntent(int intent);

	/**
	 * Sets the maximum number of clients to be associated.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   numberOfClient  The maximum number of clients to associate
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   Either the specified @c numberOfClient is less than @c 0 or exceeds
	 *                              Wifi::MAX_WIFI_DIRECT_CONNECTED_CLIENTS.
	 */
	result SetMaxNumberOfClients(int numberOfClient);

	/**
	 * Checks whether the specified instance of %WifiDirectGroupInfo equals the current instance.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]   obj             An instance of %WifiDirectGroupInfo
	 * @remarks     This method returns @c false if the specified object is not %WifiDirectGroupInfo.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since       2.0
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Assigns the value of the specified instance to the current instance of %WifiDirectGroupInfo.
	 *
	 * @since       2.0
	 *
	 * @return      A reference to the %WifiDirectGroupInfo instance
	 * @param[in]   rhs             An instance of %WifiDirectGroupInfo
	 */
	WifiDirectGroupInfo& operator =(const WifiDirectGroupInfo& rhs);

private:
	_WifiDirectGroupInfoImpl* __pWifiDirectGroupInfoImpl;

	friend class _WifiDirectGroupInfoImpl;
}; // WifiDirectGroupInfo

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_GROUP_INFO_H_
