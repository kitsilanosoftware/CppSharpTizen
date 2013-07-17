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
 * @file		FNetIp4Address.h
 * @brief		This is the header file for the %Ip4Address class.
 *
 * @since		2.0
 *
 * This header file contains the declarations of the %Ip4Address class.
 */
#ifndef _FNET_IP4_ADDRESS_H_
#define _FNET_IP4_ADDRESS_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FNetIpAddress.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net
{
class _Ip4AddressImpl;
/**
 * @class	Ip4Address
 * @brief	This class represents an Internet Protocol version 4 (IPv4) address.
 *
 * @since	2.0
 *
 *  The %Ip4Address class specifies the IPv4 address.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/net_namespace.htm">Net Guide</a>. @n
 *
 * The following example demonstrates how to use the %Ip4Address class.
 *
 * @code
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Net;
 *
 *	result
 *	MyClass::SomeMethod(void)
 *	{
 *		result r = E_SUCCESS;
 *
 *		Tizen::Base::String ip4String(L"192.168.0.1");
 *		Ip4Address* pIp4Address = new Ip4Address(ip4String);
 *
 *		// Gets the raw IP address.
 *		int sizeOfIp4Address = 4;
 *		ByteBuffer bb;
 *		r = bb.Construct(sizeOfIp4Address);
 *		r = pIp4Address->GetAddress(bb);
 *
 *		// Success
 *		return (r);
 *	}
 * @endcode
 */
class _OSP_EXPORT_ Ip4Address
	: public IpAddress
{
public:
	/**
	 * Initializes this instance of %Ip4Address with the address specified as a string.
	 *
	 * @since		2.0
	 *
	 * @param[in]	ipAddr			The IP Address as a string @n
	 *								This string represents the IP address in dot-decimal notation (for example, 165.213.173.7)  .
	 * @exception	E_SUCCESS		The instance is created successfully.
	 * @exception	E_INVALID_ARG	The specified @c ipAddr is invalid.
	 * @remarks		The GetLastResult() method is used to check whether the %Ip4Address instance is created successfully.
	 */
	Ip4Address(const Tizen::Base::String& ipAddr);

	/**
	 * Initializes this instance of %Ip4Address with the address specified as an integer.
	 *
	 * @since		2.0
	 *
	 * @param[in]	ipAddr			A unsigned @c long number containing the raw IP address @n
	 *								This is a 32-bit unsigned number. It should be in host byte order.
	 * @exception	E_SUCCESS		The instance is created successfully.
	 * @exception	E_INVALID_ARG	The specified @c ipAddr is invalid.
	 * @remarks		The GetLastResult() method is used to check whether the %Ip4Address instance is created successfully.
	 * @see			IpAddress::NetworkToHostOrder()
	 * @see			IpAddress::HostToNetworkOrder()
	 */
	Ip4Address(unsigned long ipAddr);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since			2.0
	 *
	 * @param[in]	rhs			An instance of %Ip4Address
	 * @remarks		The GetLastResult() method is used to check whether the %Ip4Address instance is created successfully.
	 */
	Ip4Address(const Ip4Address& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~Ip4Address(void);

public:
	/**
	 * Gets the address family to which the %Ip4Address belongs.
	 *
	 * @since		2.0
	 *
	 * @return		NET_AF_IPV4
	 */
	NetAddressFamily GetNetAddressFamily(void) const;

	/**
	 * Gets the raw IP address.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	ipAddr			A Tizen::Base::ByteBuffer object containing the raw IP address
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The length of the remaining bytes of @c ipAddr is less than @c 4.
	 * @remarks		This method returns the raw IP address of the %Ip4Address object. The result is in host byte order. This method writes the raw address
	 *				in the buffer parameter, starting from the current position. After the operation, the position of the buffer is incremented by the number
	 *				of bytes successfully written even if the operation fails. The new position cannot be larger than the original limit.
	 */
	result GetAddress(Tizen::Base::ByteBuffer& ipAddr) const;

	/**
	 * Gets the raw IP address as an integer. @n
	 * The result is in host byte order.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	ipAddr				An unsigned @c long integer containing the raw IP address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @see			IpAddress::NetworkToHostOrder()
	 * @see			IpAddress::HostToNetworkOrder()
	 */
	result GetAddress(unsigned long& ipAddr) const;

	/**
	 * Gets the IP address of the endpoint in textual presentation. @n
	 * An endpoint consists of an IP address and a port.
	 *
	 * @since		2.0
	 *
	 * @return		The %Ip4Address, @n
	 *				else a null string if the address is not set
	 * @remarks		%Ip4Address is in the standard dot-decimal notation.
	 */
	Tizen::Base::String ToString(void) const;

	/**
	 * Creates and returns a copy of this instance.
	 *
	 * @since 2.0
	 *
	 * @return		The copy of this instance
	 * @remarks		The GetLastResult() method is used to check whether the %IpAddress instance is copied successfully.
	 */
	virtual IpAddress* CloneN(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return		The reference of this instance
	 * @param[in]	rhs An instance of %Ip4Address
	 */
	Ip4Address& operator =(const Ip4Address& rhs);

	/**
	 * Compares the specified instance of %Ip4Address with the calling instance.
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
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	Ip4Address(void);

private:
	_Ip4AddressImpl* __pIp4AddressImpl;

	friend class _Ip4AddressImpl;
}; // Ip4Address

} } //Tizen::Net

#endif // _FNET_IP4_ADDRESS_H_
