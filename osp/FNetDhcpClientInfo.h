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
 * @file		FNetDhcpClientInfo.h
 * @brief		This is the header file for the %DhcpClientInfo class.
 *
 * This header file contains the declarations of the %DhcpClientInfo class.
 */
#ifndef _FNET_DHCP_CLIENT_INFO_H_
#define _FNET_DHCP_CLIENT_INFO_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FNetIpAddress.h>

namespace Tizen { namespace Net
{
class _DhcpClientInfoImpl;

/**
 * @class	DhcpClientInfo
 * @brief	This class represents a client information on the local Dynamic Host Configuration Protocol (DHCP) server.
 *
 * @since	2.0
 *
 * The %DhcpClientInfo class provides functionality for getting information on the local DHCP server.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/local_DHCP_server_access.htm">Local DHCP Server Access</a>.
 */
class _OSP_EXPORT_ DhcpClientInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~DhcpClientInfo(void);

public:
	/**
	 * Gets the name of the DHCP client device.
	 *
	 * @since		2.0
	 *
	 * @return		The name of the DHCP client device, @n
	 *				else a null string if the name is not set or not constructed
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the IP address of the DHCP client device.
	 *
	 * @since		2.0
	 *
	 * @return		The IpAddress pointer
	 * @remarks		This method returns a dynamically assigned IP address.
	 */
	const IpAddress* GetIpAddress(void) const;

	/**
	 * Gets the MAC address of the DHCP client device.
	 *
	 * @since		2.0
	 *
	 * @return		The MAC address in the form '00-00-00-00-00-00'
	 * @remarks     In case of the Wi-Fi Direct bearer type, the MAC address is virtual and is used only for the frame packetization.
	 *              This MAC address is different from the MAC address provided by the WifiManager or the WifiDirectDevice class.
	 */
	Tizen::Base::String GetMacAddress(void) const;

	/**
	 * Compares the specified instance of %DhcpClientInfo with the calling instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the values match, @n
	 *			    else @c false
	 * @param[in]	rhs 	The other Object to compare
	 * @see 		Object::Equals()
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
	/*
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	DhcpClientInfo(void);

	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]    rhs	An instance of %DhcpClientInfo
	 */
	DhcpClientInfo(const DhcpClientInfo& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %DhcpClientInfo
	 */
	DhcpClientInfo& operator =(const DhcpClientInfo& rhs);

private:
	_DhcpClientInfoImpl* __pDhcpClientInfoImpl;

	friend class _DhcpClientInfoImpl;
}; // DhcpClientInfo

} } //Tizen::Net

#endif // _FNET_DHCP_CLIENT_INFO_H_
