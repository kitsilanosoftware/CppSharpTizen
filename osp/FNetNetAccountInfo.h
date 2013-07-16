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
 * @file		FNetNetAccountInfo.h
 * @brief		This is the header file for the %NetAccountInfo class.
 *
 * This header file contains the declarations of the %NetAccountInfo class.
 */
#ifndef _FNET_NET_ACCOUNT_INFO_H_
#define _FNET_NET_ACCOUNT_INFO_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseResult.h>
#include <FBaseErrors.h>
#include <FNetNetTypes.h>
#include <FNetIpAddress.h>
#include <FNetIp4Address.h>
#include <FNetNetEndPoint.h>

namespace Tizen { namespace Net
{
class _NetAccountInfoImpl;

/**
 * @class	NetAccountInfo
 * @brief	This class provides methods for all the network accounts.
 *
 * @since	2.0
 *
 * The %NetAccountInfo class provides configuration parameters for setting up network connections.
 * %NetAccountInfo contains the base information required to connect to various bearers and it is designed to be
 * used in Programmed Data Processor (PDP) context activation. The Wi-Fi accounts are derived from this class
 * and contain additional information specific to Wi-Fi (such as SSID).
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/network_accounts.htm">Network Accounts</a>.
 */
class _OSP_EXPORT_ NetAccountInfo
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since	2.0
	*
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	NetAccountInfo(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~NetAccountInfo(void);

	/**
	 * Initializes this instance of %NetAccountInfo with the specified %NetAccountInfo instance. @n
	 * Only the data part is cloned. Attributes such as NetAccountId and the connection status, which are linked with the registry are set to default values.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	netAccountInfo		A %NetAccountInfo instance to initialize the calling instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c netAccountInfo is invalid.
	 */
	result Construct(const NetAccountInfo& netAccountInfo);

	/**
	 * Initializes this instance of %NetAccountInfo.
	 *
	 * @since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS			The method is successful.
	 */
	result Construct(void);

	/**
	 * Gets an account ID.
	 *
	 * @since		2.0
	 *
	 * @return		The account ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetAccountId GetAccountId(void) const;

	/**
	 * Gets the name of an account.
	 *
	 * @since		2.0
	 *
	 * @return		The name of the account, @n
	 *				else a null string if the name is not set or not constructed
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAccountName()
	 */
	Tizen::Base::String GetAccountName(void) const;

	/**
	 * Sets the name of an account. @n
	 * If this method fails, the state of this instance does not change.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	accountName				The name of an account
	 * @exception	E_SUCCESS				The method is successful.
	 * @see			GetAccountName()
	 */
	result SetAccountName(const Tizen::Base::String& accountName);

	/**
	 * Gets the protocol type.
	 *
	 * @since		2.0
	 *
	 * @return		The type of the protocol
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetProtocolType()
	 */
	NetProtocolType GetProtocolType(void) const;

	/**
	 * Sets the protocol type.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	netProtocolType			The type of the protocol
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		If this method fails, the state of this instance does not change.
	 * @see			GetProtocolType()
	 */
	result SetProtocolType(NetProtocolType netProtocolType);

	/**
	 * Gets an Access Point Name.
	 *
	 * @since		2.0
	 *
	 * @return		The Access Point Name, @n
	 *				else a null string if the name is not set or the instance is not constructed
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAccessPointName()
	 */
	Tizen::Base::String GetAccessPointName(void) const;

	/**
	 * Sets the name of the access point. @n
	 * If this method fails, the state of this instance does not change.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	accessPointName			The Access Point Name
	 * @exception	E_SUCCESS				The method is successful.
	 * @see			GetAccessPointName()
	 */
	result SetAccessPointName(const Tizen::Base::String& accessPointName);

	/**
	 * Gets the setting for the local address scheme. @n
	 * This scheme can be dynamic or static.
	 *
	 * @since		2.0
	 *
	 * @return		The address scheme
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLocalAddress()
	 * @see			GetLocalAddress()
	 */
	NetAddressScheme GetLocalAddressScheme(void) const;

	/**
	 * Gets the local address.
	 *
	 * @since			2.0
	 *
	 * @return			The local address, @n
	 *					else @c null if an error occurs or the dynamic address scheme is being used
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_OPERATION		This operation is not allowed in the dynamic address scheme.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetLocalAddress()
	 */
	const IpAddress* GetLocalAddress(void) const;

	/**
	 * Enables or disables the use of a static local IP address.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	localAddrScheme			An indicator specifying whether to use a static local IP address
	 * @param[in]	pLocalAddress			The local IP address @n
	 *										If @c localAddrScheme is set to NET_ADDRESS_SCHEME_STATIC, the local IP address assigned is static.
	 *										If @c localAddrScheme is set to NET_ADDRESS_SCHEME_DYNAMIC or NET_ADDRESS_SCHEME_NONE, this parameter is ignored.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @see			GetLocalAddress()
	 */
	result SetLocalAddress(NetAddressScheme localAddrScheme, const IpAddress* pLocalAddress);

	/**
	 * Gets the setting for the DNS address scheme.
	 *
	 * @since		2.0
	 *
	 * @return		The address scheme for the DNS
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetPrimaryDnsAddress()
	 * @see			GetSecondaryDnsAddress()
	 * @see			SetDnsAddress()
	 */
	NetAddressScheme GetDnsAddressScheme(void) const;

	/**
	 * Gets the setting for the primary DNS address.
	 *
	 * @since			2.0
	 *
	 * @return			The IpAddress of primary DNS address, @n
	 *					else @c null if an error occurs or the dynamic address scheme is being used
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_OPERATION		This operation is not allowed in the dynamic address scheme.
	 * @remarks			When this instance is got by NetAccountManager::GetNetAccountInfoN(),
	 *					- this method returns a statically assigned primary DNS address pointer if the DNS address scheme is NET_ADDRESS_SCHEME_STATIC
	 *					- this method returns @n null if the DNS address scheme is @c NET_ADDRESS_SCHEME_DYNAMIC @n
	 *			The specific error code can be accessed using the GetLastResult() method.
	 * @see				GetSecondaryDnsAddress()
	 */
	const IpAddress* GetPrimaryDnsAddress(void) const;

	/**
	 * Gets the setting for the secondary DNS address.
	 *
	 * @since			2.0
	 *
	 * @return			The secondary DNS IP address, @n
	 *					else @c null if an error occurs or the dynamic address scheme is being used
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_OPERATION		This operation is not allowed in the dynamic address scheme.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetDnsAddress()
	 */
	const IpAddress* GetSecondaryDnsAddress(void) const;

	/**
	 * Enables or disables the use of a static DNS address with the specified IpAddress objects. @n
	 * If @c dnsAddrScheme is NET_ADDRESS_SCHEME_DYNAMIC, both @c primaryDnsAddress and @c secondaryDnsAddress are ignored. @n
	 * If @c dnsAddrScheme is NET_ADDRESS_SCHEME_STATIC, @c primaryDnsAddress must be a valid IpAddress.
	 * However, @c pSecondaryDnsAddress can be @c null.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	dnsAddrScheme			An indicator specifying whether or not to use a static DNS address
	 * @param[in]	pPrimaryDnsAddress		The statically assigned primary DNS address if @c dnsAddrScheme is NET_ADDRESS_SCHEME_STATIC
	 * @param[in]	pSecondaryDnsAddress	The statically assigned secondary DNS address if @c dnsAddrScheme is NET_ADDRESS_SCHEME_STATIC
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @see			GetPrimaryDnsAddress()
	 * @see			GetSecondaryDnsAddress()
	 */
	result SetDnsAddress(NetAddressScheme dnsAddrScheme, const IpAddress* pPrimaryDnsAddress, const IpAddress* pSecondaryDnsAddress);

	/**
	 * Gets the proxy address of the network accounts.
	 *
	 * @since		2.0
	 *
	 * @return		The proxy address, @n
	 *				else @c null if an error occurs or the address is not set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified address format is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const NetEndPoint* GetProxyAddress(void) const;

	/**
	 * Sets the proxy address of the network accounts.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pProxyEndPoint			A pointer to a NetEndPoint instance containing the IP address and port
	 * @exception	E_SUCCESS				The method is successful.
	 */
	result SetProxyAddress(const NetEndPoint* pProxyEndPoint);

	/**
	 * Gets the authentication configuration of network accounts. @n
	 * The user is not provided with read access to the credential information present in the registry if the network account information is extracted from
	 * the registry using @ref NetAccountManager::GetNetAccountInfoN().
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	authenticationType	The type of the authentication used
	 * @param[out]	id					The ID
	 * @param[out]	password			The password
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_ILLEGAL_ACCESS	The user is not provided with read access to the credential information present in the registry, if the network
	 *									account information is extracted from the registry using NetAccountManager::GetNetAccountInfoN().
	 * @remarks		If this method fails, the state of this instance does not change.
	 * @see			SetAuthenticationInfo()
	 *
	 */
	result GetAuthenticationInfo(NetNapAuthType& authenticationType, Tizen::Base::String& id, Tizen::Base::String& password) const;

	/**
	 * Sets the authentication configuration of the network accounts.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	authenticationType	The type of the authentication used
	 * @param[in]	id					The ID
	 * @param[in]	password			The password
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		If this method fails, the state of this instance does not change.
	 * @see			GetAuthenticationInfo()
	 *
	 */
	result SetAuthenticationInfo(NetNapAuthType authenticationType, const Tizen::Base::String& id, const Tizen::Base::String& password);

	/**
	 * Gets the operational bearer type of this account.
	 *
	 * @since		2.0
	 *
	 * @return		The operational bearer type
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetBearerType GetBearerType(void) const;

	/**
	 * Gets the current URL of a home page.
	 *
	 * @since                    2.0
	 *
	 * @return                  The current URL of a home page
	 * @see                      SetHomeUrl()
	 */
	Tizen::Base::String GetHomeUrl(void) const;

	/**
	 * Sets a URL as a home page.
	 *
	 * @since                  2.0
	 *
	 * @param[in]	homeUrl 	The URL to set as a home page
	 * @see                    GetHomeUrl()
	 */
	void SetHomeUrl(const Tizen::Base::String& homeUrl);

	/**
	 * Gets the maximum length of the user name.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum length of the user name
	 */
	int GetMaximumLengthOfId(void) const;

	/**
	 * Gets the maximum length of the password.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum length of the password
	 */
	int GetMaximumLengthOfPassword(void) const;

	/**
	 * Gets the maximum length of the account name.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum length of the account name
	 */
	int GetMaximumLengthOfAccountName(void) const;

	/**
	 * Gets a value that indicates whether the network account is read-only. @n
	 * If it returns @c true, this account is read-only; so any change to this account is not permitted. @n
	 * When it returns @c false, modification is possible.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if this account is read only, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsReadOnly(void) const;

	/**
	 * Compares the specified instance of %NetAccountInfo with the calling instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the values match, @n
	 *				else @c false
	 * @param[in]	rhs 	The other Tizen::Base::Object to compare
	 * @see 		Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return  	The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %NetAccountInfo
	 */
	NetAccountInfo(const NetAccountInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs An instance of %NetAccountInfo
	 */
	NetAccountInfo& operator =(const NetAccountInfo& rhs);

private:
	_NetAccountInfoImpl* __pNetAccountInfoImpl;

	friend class _NetAccountInfoImpl;
}; // NetAccountInfo

} } //Tizen::Net

#endif // _FNET_NET_ACCOUNT_INFO_H_
