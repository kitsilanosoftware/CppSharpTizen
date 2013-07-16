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
 * @file		FNetNetConnectionInfo.h 
 * @brief		This is the header file for the %NetConnectionInfo class.
 *
 * This header file contains the declarations of the %NetConnectionInfo class.
 */
#ifndef _FNET_NET_CONNECTION_INFO_H_
#define _FNET_NET_CONNECTION_INFO_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetNetTypes.h>
#include <FNetIpAddress.h>

namespace Tizen { namespace Net {
class _NetConnectionInfoImpl;

/**
 * @class	NetConnectionInfo 
 * @brief	This class represents a base type for the information related to a network connection.
 *
 * @since	2.0
 *
 * 	The %NetConnectionInfo class provides methods to obtain information related to a network connection. %NetConnectionInfo is valid when 
 *	NetConnection is not in the "NET_CONNECTION_STATE_STOPPED" state.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 */
class _OSP_EXPORT_ NetConnectionInfo
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @remarks		The GetLastResult() method is used to check whether the %NetConnectionInfo instance is created successfully.
	 */
	NetConnectionInfo(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~NetConnectionInfo(void);

	/** 
	 * Gets the operating bearer type of a mobile station.
	 *
	 * @since		2.0
	 *
	 * @return		The operating bearer type of a specific network connection, @n
	 *				else @c NET_BEARER_NONE if this instance is invalid
	 */
	 NetBearerType GetBearerType(void) const;

	/** 
	 * Gets the operation protocol of a mobile station.
	 *
	 * @since		2.0
	 *
	 * @return		The protocol type of a specific network connection, @n
	 *				else @c NET_PROTO_TYPE_NONE if this instance is invalid
	 */
	 NetProtocolType GetProtocolType(void) const;

	/** 
	 * Gets the Access Point Name.
	 *
	 * @since		2.0
	 *
	 * @return		The Access Point Name as a string, @n
	 *				else a null string if the Access Point Name is empty or this instance is invalid
	 */
	Tizen::Base::String GetAccessPointName(void) const;

	/** 
	 * Gets the local address scheme.
	 *
	 * @since		2.0
	 *
	 * @return		The address scheme for the local address, @n
	 *				else @c NET_ADDRESS_SCHEME_NONE if this instance is invalid
	 */
	NetAddressScheme GetLocalAddressScheme(void) const;

	/** 
	 * Gets the local address information.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the IpAddress instance representing the local address in the calling instance
	 * @remarks		If GetLocalAddressScheme() is NET_ADDRESS_SCHEME_STATIC, this method returns the statically assigned local addresses. @n
	 *				If %GetLocalAddressScheme() is NET_ADDRESS_SCHEME_DYNAMIC, this method returns the dynamically assigned local addresses. @n
	 *				In any case, check whether the IpAddress pointer is @c null or not.
	 */
	const IpAddress* GetLocalAddress(void) const;

	/** 
	 * Gets the setting for the DNS address scheme.
	 *
	 * @since		2.0
	 *
	 * @return		The address scheme for the DNS address, @n
	 *				else @c NET_ADDRESS_SCHEME_NONE if this instance is invalid
	 *
	 */
	NetAddressScheme GetDnsAddressScheme(void) const;

	/** 
	 * Gets the primary DNS address.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the IpAddress instance representing the primary DNS Address of the network connection
	 * @remarks		If GetDnsAddressScheme() is NET_ADDRESS_SCHEME_STATIC, this method returns the statically assigned local addresses. @n
	 *				If %GetDnsAddressScheme() is NET_ADDRESS_SCHEME_DYNAMIC, this method returns the dynamically assigned local addresses. @n
	 *				In any case, check whether the IpAddress pointer is @c null or not, because the DNS address field is not mandatory.
	 */
	const IpAddress* GetPrimaryDnsAddress(void) const;

	/** 
	 * Gets the secondary DNS address.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the IpAddress instance representing the secondary DNS Address of the network connection
	 * @remarks		If GetDnsAddressScheme() is NET_ADDRESS_SCHEME_STATIC, this method returns the statically assigned local addresses. @n
	 *				If %GetDnsAddressScheme() is NET_ADDRESS_SCHEME_DYNAMIC, this method returns the dynamically assigned local addresses. @n
	 *				In any case, check whether the IpAddress pointer is @c null or not, because the DNS address field is not mandatory.
	 */
	const IpAddress* GetSecondaryDnsAddress(void) const;

	/** 
	 * Gets the subnet mask address.
	 *
	 * @since 		2.0
	 *
	 * @return		A pointer to the IpAddress instance representing the subnet mask address of the network connection
	 * @remarks   	In any case, check whether the IpAddress pointer is @c null or not, because the subnet mask address field is not mandatory.
	 */
	const IpAddress* GetSubnetMaskAddress(void) const;
	
	/** 
	 * Gets the default gateway address.
	 *
	 * @since		2.0
	 *
	 * @return     	A pointer to the IpAddress instance representing the default gateway address of the network connection
	 * @remarks    	In any case, check whether the IpAddress pointer is @c null or not, because the gateway address field is not mandatory.
	 */
	const IpAddress* GetDefaultGatewayAddress(void) const;

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs			An instance of %NetConnectionInfo
	 * @remarks		The GetLastResult() method is used to check whether the %NetConnectionInfo instance is created successfully.
	 */
	NetConnectionInfo(const NetConnectionInfo& rhs);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.0
	 *
	 * @return		The reference of this instance
	 * @param[in]	rhs An instance of %NetConnectionInfo
	 * @remarks		The GetLastResult() method is used to check whether the %NetConnectionInfo instance is copied successfully.
	 */
	NetConnectionInfo& operator =(const NetConnectionInfo& rhs);

	/**
	 * Compares the specified instance of %NetConnectionInfo with the calling instance.
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
	_NetConnectionInfoImpl* __pNetConnectionInfoImpl;

	friend class _NetConnectionInfoImpl;
}; // NetConnectionInfo

} } //Tizen::Net

#endif // _FNET_NET_CONNECTION_INFO_H_
