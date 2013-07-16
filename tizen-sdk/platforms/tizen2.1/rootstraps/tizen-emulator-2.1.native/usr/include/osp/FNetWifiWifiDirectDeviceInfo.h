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
 * @file    FNetWifiWifiDirectDeviceInfo.h
 * @brief   This is the header file for the %WifiDirectDeviceInfo class.
 *
 * This header file contains the declarations of the %WifiDirectDeviceInfo class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_DEVICE_INFO_H_
#define _FNET_WIFI_WIFI_DIRECT_DEVICE_INFO_H_

#include <FBaseObject.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
template<class type>
class IListT;
} } } // Tizen::Base::Collection

namespace Tizen { namespace Net
{
class IpAddress;
} } // Tizen::Net

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiDirectDeviceInfoImpl;

/**
 * @class   WifiDirectDeviceInfo
 * @brief   This class provides methods for the Wi-Fi Direct device information.
 *
 * @since   2.0
 *
 * The %WifiDirectDeviceInfo class provides methods for getting information related to a Wi-Fi Direct device.
 */
class _OSP_EXPORT_ WifiDirectDeviceInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	WifiDirectDeviceInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]   value   An instance of %WifiDirectDeviceInfo
	 */
	WifiDirectDeviceInfo(const WifiDirectDeviceInfo& value);

	/**
	 * Initializes this instance of %WifiDirectDeviceInfo with the specified device name
	 * and the MAC address.
	 *
	 * @since       2.0
	 *
	 * @param[in]   deviceName  The device name @n
	 *                          The length of @c deviceName must not exceed 64 characters.
	 * @param[in]   macAddr     The MAC address @n
	 *                          The value of @c macAddr must be in the form '00-00-00-00-00-00'.
	 *
	 */
	WifiDirectDeviceInfo(const Tizen::Base::String& deviceName, const Tizen::Base::String& macAddr);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~WifiDirectDeviceInfo(void);

	/**
	 * Gets the ID of the device.
	 *
	 * @since       2.0
	 *
	 * @return      The ID of the Wi-Fi Direct device
	 * @remarks
	 *              - This value is only available for local device information query, such as
	 *                WifiDirectDeviceManager::GetAllDeviceInfoN() or WifiDirectDevice::GetLocalDeviceInfoN().
	 *              - When the value is not available, the return value is @c -1.
	 */
	WifiDirectDeviceId GetDeviceId(void) const;

	/**
	 * Gets the device name.
	 *
	 * @since       2.0
	 *
	 * @return      The device name
	 */
	Tizen::Base::String GetDeviceName(void) const;

	/**
	 * Gets the MAC address of the device.
	 *
	 * @since       2.0
	 *
	 * @return      The MAC address in the form '00-00-00-00-00-00'
	 * @remarks     This MAC address is different from the MAC address provided by the WifiManager or DhcpClientInfo
	 *              class. Especially, the MAC address which is provided in DhcpClientInfo is a virtual MAC address for
	 *              data communication during a Wi-Fi Direct group member.
	 */
	Tizen::Base::String GetMacAddress(void) const;

	/**
	 * Gets the IP address of the device.
	 *
	 * @since       2.0
	 *
	 * @return      An IpAddress pointer to the local address in the calling instance
	 * @remarks     The IP address is provided only using WifiDirectDevice::GetGroupOwnerInfoN(),
	 *              WifiDirectDevice::GetGroupClientInfoListN(), or WifiDirectDevice::GetLocalDeviceInfoN() after
	 *              becoming a group member.
	 */
	const Tizen::Net::IpAddress* GetIpAddress(void) const;

	/**
	 * Gets the SSID.
	 *
	 * @since       2.0
	 *
	 * @return      The SSID
	 * @remarks     This method returns an empty string if the member type of a device is not a Wi-Fi Direct group
	 *              owner or client.
	 */
	Tizen::Base::String GetSsid(void) const;

	/**
	 * Gets the status of the device.
	 *
	 * @since       2.0
	 *
	 * @return      The status of the Wi-Fi Direct device
	 */
	WifiDirectDeviceStatus GetDeviceStatus(void) const;

	/**
	 * Gets the member type of the Wi-Fi Direct device.
	 *
	 * @since       2.0
	 *
	 * @return      The member type of the Wi-Fi Direct device
	 */
	WifiDirectGroupMemberType GetGroupMemberType(void) const;

	/**
	 * Gets the category of the Wi-Fi Direct device type.
	 *
	 * @since       2.0
	 *
	 * @return      The category of the Wi-Fi Direct device type
	 */
	WifiDirectDeviceTypeCategory GetDeviceTypeCategory(void) const;

	/**
	 * Gets the list of supporting WPS configuration modes.
	 *
	 * @since       2.0
	 *
	 * @return      The list of supporting WPS configuration modes
	 * @remarks     The result of this method is available only using WifiDirectDevice::Scan() or
	 *              WifiDirectDevice::GetLocalDeviceInfoN().
	 */
	const Tizen::Base::Collection::IListT <WifiWpsConfigurationMode>* GetSupportedWpsConfigurationModeList(void) const;

	/**
	 * Checks whether the specified instance of %WifiDirectDeviceInfo equals the current instance.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]   obj         An instance of %WifiDirectDeviceInfo
	 * @remarks     This method returns @c false if the specified object is not %WifiDirectDeviceInfo.
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
	 * Assigns the value of the specified instance to the current instance of %WifiDirectDeviceInfo.
	 *
	 * @since        2.0
	 *
	 * @return      A reference to this instance
	 * @param[in]   rhs         An instance of %WifiDirectDeviceInfo
	 */
	WifiDirectDeviceInfo& operator =(const WifiDirectDeviceInfo& rhs);

private :
	_WifiDirectDeviceInfoImpl* __pWifiDirectDeviceInfoImpl;

	friend class _WifiDirectDeviceInfoImpl;
}; // WifiDirectDeviceInfo

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_DEVICE_INFO_H_
