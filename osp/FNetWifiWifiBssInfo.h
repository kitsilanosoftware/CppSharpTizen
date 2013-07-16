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
 * @file    FNetWifiWifiBssInfo.h
 * @brief   This is the header file for the %WifiBssInfo class.
 *
 * This header file contains the declarations of the %WifiBssInfo class.
 */
#ifndef _FNET_WIFI_WIFI_BSS_INFO_H_
#define _FNET_WIFI_WIFI_BSS_INFO_H_

#include <FBaseObject.h>
#include <FNetNetTypes.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Net
{
class IpAddress;
} }

namespace Tizen { namespace Net { namespace Wifi
{
class WifiSecurityInfo;
class _WifiBssInfoImpl;

/**
 * @class   WifiBssInfo
 * @brief   This class provides methods for managing the BSS information of a Wi-Fi network.
 *
 * @since   2.0
 *
 * The %WifiBssInfo class provides methods for managing the BSS information of a Wi-Fi network.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */

class _OSP_EXPORT_ WifiBssInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since   2.0
	 */
	WifiBssInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 * @since   2.0
	 *
	 * @param[in]   value               An instance of %WifiBssInfo
	 */
	WifiBssInfo(const WifiBssInfo& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~WifiBssInfo(void);

	/**
	 * Gets the SSID of this BSS.
	 *
	 * @since   2.0
	 *
	 * @return  The SSID
	 */
	Tizen::Base::String GetSsid(void) const;

	/**
	 * Gets the ID of this BSS.
	 *
	 * @since   2.0
	 *
	 * @return      The BSSID expressed as a 6 byte hexadecimal value delimited by dashes. @n
	 *              For example, "00-3D-47-EF-8A-03".
	 */
	Tizen::Base::String GetBssId(void) const;

	/**
	 * Gets the type of this BSS.
	 *
	 * @since   2.0
	 *
	 * @return      The type of this BSS
	 */
	WifiBssType GetBssType(void) const;

	/**
	 * Gets the radio channel of this BSS.
	 *
	 * @since   2.0
	 *
	 * @return      The radio channel of this BSS
	 */
	WifiRadioChannel GetRadioChannel(void) const;

	/**
	 * Gets the security information of this BSS.
	 *
	 * @since   2.0
	 *
	 * @return      The authentication and encryption type of this BSS
	 */
	const WifiSecurityInfo* GetSecurityInfo(void) const;

	/**
	 * Gets the Received Signal Strength Indication (RSSI) value of the BSS at the time of scanning.
	 *
	 * @since   2.0
	 *
	 * @return      The RSSI value in dBm
	 */
	long GetRssi(void) const;

	/**
	 * Gets the data rate of this BSS.
	 *
	 * @since       2.0
	 *
	 * @return      The data rate value (Mbps), @n
	 *              else @c -1.0 if the supported data rate is unknown
	 */
	float GetDataRate(void) const;

	/**
	 * Sets the SSID.
	 *
	 * @since 2.0
	 *
	 * @param[in] ssid The SSID
	 */
	void SetSsid(const Tizen::Base::String& ssid);

	/**
	 * Checks whether an access point (BSS) is known or not. @n
	 * The access point becomes a known BSS if it has been connected with this device.
	 *
	 * @since 2.0
	 *
	 * @return      @c true if the access point is known, @n
	 *              else @c false
	 * @see         SetUnknown()
	 */
	bool IsKnown(void) const;

	/**
	 * Sets the access point (BSS) unknown.
	 *
	 * @since 2.0
	 *
	 * @see         IsKnown()
	 */
	void SetUnknown(void);

	/**
	 * Gets the local IP address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      The address scheme for the local IP address
	 */
	Tizen::Net::NetAddressScheme GetLocalAddressScheme(void) const;

	/**
	 * Sets the local IP address scheme. @n
	 * The %SetLocalAddressScheme() method allows determining whether to use static address or dynamic address.
	 *
	 * @since 2.0
	 *
	 * @param[in]   scheme              The address scheme for the local IP address
	 */
	void SetLocalAddressScheme(Tizen::Net::NetAddressScheme scheme);

	/**
	 * Gets the local IP address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      The local address configured to this access point, @n
	 *              else @c null if an error occurs or there is no previously set address
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetLocalAddress()
	 */
	const Tizen::Net::IpAddress* GetLocalAddress(void) const;

	/**
	 * Sets the local IP address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   pAddress            The new address to assign
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation.
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The existing local address is unset when the input argument is @c null.
	 * @see         GetLocalAddress()
	 */
	result SetLocalAddress(const Tizen::Net::IpAddress* pAddress);

	/**
	 * Gets the subnet mask address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      The subnet mask address configured to this access point, @n
	 *              else @c null if an error occurs or there is no previously set address
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetSubnetMaskAddress()
	 */
	const Tizen::Net::IpAddress* GetSubnetMaskAddress(void) const;

	/**
	 * Sets the subnet mask address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   pAddress            The new address to assign
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The existing subnet mask address is unset when the input argument is @c null.
	 * @see         GetSubnetMaskAddress()
	 */
	result SetSubnetMaskAddress(const Tizen::Net::IpAddress* pAddress);

	/**
	 * Gets the default gateway address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      The default gateway address configured to this access point, @n
	 *              else @c null if an error occurs or there is no previously set address
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetDefaultGatewayAddress()
	 */
	const Tizen::Net::IpAddress* GetDefaultGatewayAddress(void) const;

	/**
	 * Sets the default gateway address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   pAddress            The new address to assign
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The existing gateway address is unset when the input argument is @c null.
	 * @see         GetDefaultGatewayAddress()
	 */
	result SetDefaultGatewayAddress(const Tizen::Net::IpAddress* pAddress);

	/**
	 * Gets the primary DNS address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      The primary DNS address configured to this access point, @n
	 *              else @c null if an error occurs or there is no previously set address
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetPrimaryDnsAddress()
	 */
	const Tizen::Net::IpAddress* GetPrimaryDnsAddress(void) const;

	/**
	 * Sets the primary DNS address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   pAddress            The new address to assign
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The existing primary DNS address is unset when the input argument is @c null.
	 * @see         GetPrimaryDnsAddress()
	 */
	result SetPrimaryDnsAddress(const Tizen::Net::IpAddress* pAddress);

	/**
	 * Gets the secondary DNS address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      The secondary DNS address configured to this access point, @n
	 *              else @c null if an error occurs or there is no previously set address
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetSecondaryDnsAddress()
	 */
	const Tizen::Net::IpAddress* GetSecondaryDnsAddress(void) const;

	/**
	 * Sets the secondary DNS address in the static address scheme.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   pAddress            The new address to assign
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the address scheme for the IP address is @c NET_ADDRESS_SCHEME_DYNAMIC.
	 * @remarks     The existing secondary DNS address is unset when the input argument is @c null.
	 * @see         GetSecondaryDnsAddress()
	 */
	result SetSecondaryDnsAddress(const Tizen::Net::IpAddress* pAddress);

	/**
	 * Gets the proxy type.
	 *
	 * @since 2.0
	 *
	 * @return      The proxy type
	 * @see         SetProxyType()
	 */
	Tizen::Net::NetProxyType GetProxyType(void) const;

	/**
	 * Sets the proxy type.
	 *
	 * @since 2.0
	 *
	 * @param[in]   type                The proxy type
	 * @see         GetProxyType()
	 */
	void SetProxyType(Tizen::Net::NetProxyType type);

	/**
	 * Gets the proxy address.
	 *
	 * @since 2.0
	 *
	 * @return      The proxy address, @n
	 *              else an empty string if an error occurs or there is no previously set address
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation. @n
	 *                                  For example, the specified input type is @c NET_PROXY_TYPE_NONE.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetProxyAddress()
	 */
	Tizen::Base::String GetProxyAddress(void) const;

	/**
	 * Sets the proxy address.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   address             The proxy address containing the IP address and port. @n
	 *                                  For example, 'proxy.example.com:3125' or '192.168.0.1:8080'.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of this operation.
	 *                                  For example, the specified input type is @c NET_PROXY_TYPE_NONE.
	 * @remarks     The existing proxy address is unset when the input argument is an empty string.
	 * @see         GetProxyAddress()
	 */
	result SetProxyAddress(const Tizen::Base::String& address);

	/**
	 * Checks whether the specified instance of %WifiBssInfo equals the current instance.
	 *
	 * @since   2.0
	 *
	 * @return       @c true if the specified instance equals the current instance, @n
	 *               else @c false
	 * @param[in]    obj An instance of %WifiBssInfo
	 * @remarks      The method returns @c false if the specified object is not %WifiBssInfo.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since   2.0
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Assigns the value of the specified instance to the current instance of %WifiBssInfo.
	 *
	 * @since   2.0
	 *
	 * @return      The reference of this instance
	 * @param[in]   rhs                 An instance of %WifiBssInfo
	 */
	WifiBssInfo& operator=(const WifiBssInfo& rhs);

private:
	_WifiBssInfoImpl *__pWifiBssInfoImpl;

	friend class _WifiBssInfoImpl;
}; // WifiBssInfo

} } } //Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_BSS_INFO_H_
