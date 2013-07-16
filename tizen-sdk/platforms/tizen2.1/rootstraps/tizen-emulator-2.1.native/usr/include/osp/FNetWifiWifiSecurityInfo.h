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
 * @file    FNetWifiWifiSecurityInfo.h
 * @brief   This is the header file for the %WifiSecurityInfo class.
 *
 * This header file contains the declarations of the %WifiSecurityInfo class.
 */
#ifndef _FNET_WIFI_WIFI_SECURITY_INFO_H_
#define _FNET_WIFI_WIFI_SECURITY_INFO_H_

#include <FBaseObject.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiSecurityInfoImpl;

/**
 * @class   WifiSecurityInfo
 * @brief   This class provides methods to manage the security information of a Wi-Fi network.
 *
 * @since   2.0
 *
 * The %WifiSecurityInfo class is used with the WifiNetAccountInfo class to set and get the security information of a Wi-Fi
 * network.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */
class _OSP_EXPORT_ WifiSecurityInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	WifiSecurityInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   value       An instance of %WifiSecurityInfo
	 */
	WifiSecurityInfo(const WifiSecurityInfo& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~WifiSecurityInfo(void);

	/**
	 * Gets the authentication type of this account.
	 *
	 * @since       2.0
	 *
	 * @return      The authentication type of this account
	*/
	WifiAuthenticationType GetAuthenticationType(void) const;

	/**
	 * Gets the encryption type of this account.
	 *
	 * @since       2.0
	 *
	 * @return      The encryption type
	 * @remarks     If the encryption type is @c WIFI_ENCRYPTION_TKIP_AES_MIXED, either SetNetworkKeyAes() or
	 *              SetNetworkKeyTkip() can be used to set the key.
	 */
	WifiEncryptionType GetEncryptionType(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the Wired Equivalent Privacy (WEP) key data.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the key value does not need to set for each encryption type.
	 *              Instead of using this method, use SetNetworkKey().
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   keyLen          A WifiWepKeyLen enumerator value
	 * @param[in]   keyIndex        The key index of WEP key to set
	 * @param[in]   key             The key data to set
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The length of the specified @c key exceeds @c 10 bytes when the value of @c keyLen
	 *                              is Wifi::WIFI_WEP_KEY_LEN_64BIT, or the length of the specified @c key exceeds
	 *                              @c 26 bytes when the value of @c keyLen is Wifi::WIFI_WEP_KEY_LEN_128BIT.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result SetNetworkKeyWep(WifiWepKeyLen  keyLen, WifiWepKeyIndex keyIndex, const Tizen::Base::String& key);

	/**
	 * @if OSPDEPREC
	 * Sets the Advanced Encryption Standard (AES) key data.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the key value does not need to set for each encryption type.
	 *              Instead of using this method, use SetNetworkKey().
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   key             The key data to set
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The length of the specified @c key exceeds @c 64 bytes.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result SetNetworkKeyAes(const Tizen::Base::String& key);

	/**
	 * @if OSPDEPREC
	 * Sets the Temporal Key Integrity Protocol (TKIP) key data.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the key value does not need to set for each encryption type.
	 *              Instead of using this method, use SetNetworkKey().
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   key             The key data to set
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The length of the specified @c key exceeds @c 64 bytes.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result SetNetworkKeyTkip(const Tizen::Base::String& key);

	/**
	 * Sets the Extensible Authentication Protocol (EAP) method information.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   type                        The EAP method type
	 * @param[in]   userId                      The user ID to set @n
	 *                                          Its length must not exceed @c 256 bytes.
	 * @param[in]   password                    The password to set @n
	 *                                          Its length must not exceed @c 256 bytes.
	 * @param[in]   validateServerCertificate   Set to @c true to determine the validation of the server certificate, @n
	 *                                          else @c false
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_INVALID_ARG               The length of the specified @c userId or @c password exceeds @c 256 bytes.
	 * @exception   E_UNSUPPORTED_TYPE          The input @c type is not supported.
	 * @exception   E_SYSTEM                    A system error has occurred.
	 */
	result SetEapMethodInfo(WifiEapType type, const Tizen::Base::String& userId, const Tizen::Base::String& password,
			bool validateServerCertificate = true);

	/**
	 * Sets the network key.
	 *
	 * @since       2.0
	 *
	 * @param[in]   key         The network key
	 */
	void SetNetworkKey(const Tizen::Base::String& key);

	/**
	 * Sets the authentication type.
	 *
	 * @since       2.0
	 *
	 * @param[in]   authType    The authentication type
	 */
	void SetAuthenticationType(WifiAuthenticationType authType);

	/**
	 * Checks whether the specified instance of %WifiSecurityInfo equals the current instance.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the specified instance equals the current instance, @n
	 *              else @c false
	 * @param[in]   obj         An instance of %WifiSecurityInfo
	 * @remarks     This method returns @c false if the specified object is not %WifiSecurityInfo.
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
	 * Assigns the value of the specified instance to the current instance of %WifiSecurityInfo.
	 *
	 * @since       2.0
	 *
	 * @return      The reference of this instance
	 * @param[in]   rhs         An instance of %WifiSecurityInfo
	 */
	WifiSecurityInfo& operator=(const WifiSecurityInfo& rhs);

private:
	_WifiSecurityInfoImpl* __pWifiSecurityInfoImpl;

	friend class _WifiSecurityInfoImpl;
}; // WifiSecurityInfo

} } } //Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_SECURITY_INFO_H_
