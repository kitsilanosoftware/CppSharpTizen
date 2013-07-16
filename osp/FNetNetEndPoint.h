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
 * @file		FNetNetEndPoint.h
 * @brief		This is the header file for the %NetEndPoint class.
 *
 * This header file contains the declarations of the %NetEndPoint class.
 */
#ifndef _FNET_NET_END_POINT_H_
#define _FNET_NET_END_POINT_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetIpAddress.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net
{
class _NetEndPointImpl;

/**
 * @class	NetEndPoint
 * @brief	This class identifies the network address.
 *
 * @since	2.0
 *
 * The %NetEndPoint class provides a base class that represents the network address of a resource or service.
 *
 */
class _OSP_EXPORT_ NetEndPoint
	: public Tizen::Base::Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since	2.0
	 */
	NetEndPoint(void);

	/**
	 * Initializes this instance of %NetEndPoint with the specified address and port number.
	 *
	 * @since       2.0
	 *
	 * @param[in]   ipAddress       The IP address of the target endpoint
	 * @param[in]   port			The port number
	 * @exception   E_SUCCESS       The instance is initialized successfully.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @remarks         The GetLastResult() method is used to check whether the %NetEndPoint instance is created successfully.
	 */
	NetEndPoint(const IpAddress& ipAddress, unsigned short port);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since			2.0
	 *
	 * @param[in]	rhs			An instance of %NetEndPoint
	 * @exception   E_SUCCESS       The instance is initialized successfully.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid.
	 * @remarks         The GetLastResult() method is used to check whether the %NetEndPoint instance is created successfully.
	 */
	NetEndPoint(const NetEndPoint& rhs);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~NetEndPoint(void);

	/**
	 * Gets the address family to which the calling %NetEndPoint instance belongs.
	 *
	 * @since       2.0
	 *
	 * @return		The address family of the calling instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	NetAddressFamily GetNetAddressFamily(void) const;

	/**
	 * Gets the port number of the endpoint.
	 *
	 * @since       2.0
	 *
	 * @return		The port number of the endpoint
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	unsigned short GetPort(void) const;

	/**
	 * Gets the IP address of the calling instance.
	 *
	 * @since       2.0
	 *
	 * @return		The IP address of the endpoint, @n
	 *				else @c null if the address information is invalid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	IpAddress* GetAddress(void) const;

	/**
	 * Gets the current endpoint.
	 *
	 * @since       2.0
	 *
	 * @return		The current endpoint, @n
	 *				else @c null string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The string output of this method is formatted as follows: IPADDRESS:PORT. @n
	 *				IPADDRESS is a string representing a number expressed in the Internet Standard "." (dotted) notation (for example, 165.213.173.7). @n
	 *				PORT is a string representing a port number in host byte order. For example, 165.213.173.7:2000 is a possible string. @n
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetNetEndPoint(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.0
	 *
	 * @return		The reference of this instance
	 * @param[in]	rhs An instance of %NetEndPoint
	 * @remarks		The GetLastResult() method is used to check whether the %NetEndPoint instance is copied successfully.
	 */
	NetEndPoint& operator =(const NetEndPoint& rhs);

	/**
	 * Compares the specified instance of %NetEndPoint with the calling instance.
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
	_NetEndPointImpl* __pNetEndPointImpl;

	friend class _NetEndPointImpl;
}; // NetEndPoint

} } //Tizen::Net

#endif // _FNET_NET_END_POINT_H_
