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
 * @file		FNetIpAddress.h
 * @brief		This is the header file for the %IpAddress class.
 *
 * This header file contains the declarations of the %IpAddress class.
 */
#ifndef _FNET_IP_ADDRESS_H_
#define _FNET_IP_ADDRESS_H_

#include <FBaseObject.h>
#include <FBaseByteBuffer.h>
#include <FBaseString.h>
#include <FBaseResult.h>
#include <FBaseErrors.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net
{
class _IpAddressImpl;
/**
 * @class	IpAddress
 * @brief	This abstract class encapsulates an Internet Protocol (IP) address and the methods to manipulate it.
 *
 * @since	2.0
 *
 *  The %IpAddress class contains the address of a computer on an IP network. Different computers use different conventions for ordering the bytes
 *	within multi-byte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the
 *	least-significant byte first (known as little-endian order). To work with the computers that use different byte ordering, all integer values sent
 *	over the network are sent in network byte order. This class provides methods to change the order. An endpoint includes an IP address
 *	and a port.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/net_namespace.htm">Net Guide</a>.
 */
class _OSP_EXPORT_ IpAddress
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~IpAddress(void);

	/**
	 * Converts the specified unsigned short address from the host byte order to the network byte order.
	 *
	 * @since		2.0
	 *
	 * @return		The address as an unsigned @c short value, in the network @c byte order
	 * @param[in]	host	The IP address to be converted, expressed in host @c byte order
	 *
	 * @see			NetworkToHostOrder()
	 */
	static unsigned short HostToNetworkOrder(unsigned short host);

	/**
	 * Converts the specified unsigned long address from the host byte order to the network byte order.
	 *
	 * @since		2.0
	 *
	 * @return		The address as an unsigned @c long value, in the network @c byte order
	 * @param[in]	host	The IP address to be converted, expressed in host @c byte order
	 *
	 * @see			NetworkToHostOrder()
	 */
	static unsigned long HostToNetworkOrder(unsigned long host);

	/**
	 * Converts the specified short integer address from network byte order to host byte order.
	 *
	 * @since		2.0
	 *
	 * @return		The address as an unsigned @c short value, in the host @c byte order
	 * @param[in]	network		The IP address to be converted, expressed in the network @c byte order
	 *
	 * @see			HostToNetworkOrder()
	 */
	static unsigned short NetworkToHostOrder(unsigned short network);

	/**
	 * Converts the specified unsigned long address from the network byte order to the host byte order.
	 *
	 * @since		2.0
	 *
	 * @return		The address as an unsigned @c long value, in the host @c byte order
	 * @param[in]	network		The IP address to be converted, expressed in the network @c byte order
	 *
	 * @see				HostToNetworkOrder()
	*/
	static unsigned long NetworkToHostOrder(unsigned long network);

	/**
	 * Gets the address family to which the %IpAddress belongs.
	 *
	 * @since		2.0
	 *
	 * @return		The address family
	 */
	virtual NetAddressFamily GetNetAddressFamily(void) const = 0;

	/**
	 * Gets the raw IP address of the endpoint. @n
	 * An endpoint includes an IP address and a port.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	ipAddr				A ByteBuffer object for getting the raw IP address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c ipAddr is invalid.
	 * @exception	E_OVERFLOW			This operation has caused the memory to overflow.
	 * @remarks		The result @c ipAddr is in the host @c byte order. This method writes the raw address into the buffer parameter, starting from the
	 *				current position of the buffer. After the operation, the position of the buffer is incremented by the number of bytes successfully written
	 *				even if the operation fails. The new position cannot be larger than the original limit.
	 */
	virtual result GetAddress(Tizen::Base::ByteBuffer& ipAddr) const = 0;

	/**
	 * Gets the IP address of the endpoint as a string. @n
	 * An endpoint includes an IP address and a port.
	 *
	 * @since		2.0
	 *
	 * @return		The IP address, @n
	 *				else a null string if the address is not set
	 */
	virtual Tizen::Base::String ToString(void) const = 0;

	/**
	 * Creates and returns a copy of this instance.
	 *
	 * @since 2.0
	 *
	 * @return		The copy of this instance
	 * @remarks		The GetLastResult() method is used to check whether the %IpAddress instance is copied successfully.
	 */
	virtual IpAddress* CloneN(void) const = 0;

protected:
	/**
	 * This default constructor is intentionally declared as protected because this class cannot be constructed.
	 *
	 * @since	2.0
	 */
	IpAddress(void);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IpAddress_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IpAddress_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IpAddress_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IpAddress_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IpAddress_Reserved5(void) {}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of IpAddress
	 */
	IpAddress(const IpAddress& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %IpAddress
	 */
	IpAddress& operator =(const IpAddress& rhs);

protected:
	_IpAddressImpl* _pIpAddressImpl;

	friend class _IpAddressImpl;
}; // IpAddress

} } //Tizen::Net

#endif // _FNET_IP_ADDRESS_H_
