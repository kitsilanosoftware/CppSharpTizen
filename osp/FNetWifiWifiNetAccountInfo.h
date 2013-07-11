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
 * @file    FNetWifiWifiNetAccountInfo.h
 * @brief   This is the header file for the %WifiNetAccountInfo class.
 *
 * This header file contains the declarations of the %WifiNetAccountInfo class.
 */
#ifndef _FNET_WIFI_WIFI_NET_ACCOUNT_INFO_H_
#define _FNET_WIFI_WIFI_NET_ACCOUNT_INFO_H_

#include <FBaseObject.h>
#include <FNetNetAccountInfo.h>
#include <FNetWifiWifiSecurityInfo.h>

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiNetAccountInfoImpl;
class WifiSecurityInfo;

/**
 * @class   WifiNetAccountInfo
 * @brief   This class provides the functionality to control the WLAN network accounts.
 *
 * @since   2.0
 *
 * The %WifiNetAccountInfo class provides the functionality to control the WLAN network accounts and the basic network accounts. This class inherits the
 * NetAccountInfo class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */

class _OSP_EXPORT_ WifiNetAccountInfo
	: public Tizen::Net::NetAccountInfo
{
public:
    /**
     * This is the destructor for this class.
     *
     *
     * @since   2.0
     */
    virtual ~WifiNetAccountInfo(void);

    /**
     * Gets the BSSID of this account.
     *
     * @since       2.0
	 *
     * @return      The BSS ID in the form '00-00-00-00-00-00'
     * @remarks     This operation is not yet supported.
     */
    Tizen::Base::String GetBssId(void) const;

    /**
     * Gets the SSID of this account.
     *
     * @since   2.0
	 *
     * @return  The SSID of this account
     */
    Tizen::Base::String GetSsid(void) const;

    /**
     * Gets the type of BSS of this account.
     *
     * @since   2.0
	 *
     * @return  The type of BSS of this account
     */
    WifiBssType GetBssType(void) const;

    /**
     * Gets the security information of this account.
     *
     * @since   2.0
	 *
     * @return  The authentication and encryption type of this account
     */
    const WifiSecurityInfo* GetSecurityInfo(void) const;

    /**
     * Gets the radio channel of this account. @n
     * If this value is not set, the default value is WIFI_RADIO_CHANNEL_UNKNOWN.
     *
     * @since   2.0
	 *
     * @return  The radio channel of this account
     * @remarks This operation is not yet supported.
     */
    WifiRadioChannel GetRadioChannel(void) const;

    /**
     * Checks whether the specified instance of %WifiNetAccountInfo equals the current instance.
     *
     * @since    2.0
	 *
     * @return   @c true if the specified instance equals the current instance, @n
     *           else @c false
     * @param[in]    obj An instance of %WifiNetAccountInfo
     * @remarks  This method returns @c false if the specified object is not %WifiNetAccountInfo.
     */
    virtual bool Equals(const Tizen::Base::Object& obj) const;

    /**
     * Gets the hash value of the current instance.
     *
     * @since    2.0
     *
     * @return   The hash value of the current instance
     */
    virtual int GetHashCode(void) const;

private:
    /**
     * This default constructor is intentionally declared as private so that only the platform can create an instance.
     *
     */
    WifiNetAccountInfo(void);

    /**
     * This copy constructor is intentionally declared as private to prohibit copying of objects by users.
     *
     * @param[in]   value   An instance of %WifiNetAccountInfo
     */
    WifiNetAccountInfo(const WifiNetAccountInfo& value);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]   rhs     An instance of %WifiNetAccountInfo        
     */
    WifiNetAccountInfo& operator=(const WifiNetAccountInfo& rhs);

private:
    _WifiNetAccountInfoImpl* __pWifiNetAccountInfoImpl;

    friend class _WifiNetAccountInfoImpl;
}; // WifiNetAccountInfo

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_NET_ACCOUNT_INFO_H_
