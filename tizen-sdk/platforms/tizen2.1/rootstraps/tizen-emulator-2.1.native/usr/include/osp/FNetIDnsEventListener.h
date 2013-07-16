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
 * @file	FNetIDnsEventListener.h
 * @brief	This is the header file for the %IDnsEventListener interface.
 *
 * This header file contains the declarations of the %IDnsEventListener interface.
 *
 */
#ifndef _FNET_IDNS_EVENT_LISTENER_H_
#define _FNET_IDNS_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net
{
class IpHostEntry;
/**
 * @interface	IDnsEventListener
 * @brief		This interface implements listeners for DNS events.
 *
 * @since		2.0
 *
 * The %IDnsEventListener interface provides methods for creating notifications about different types of DNS events. These events are only sent
 * out if a listener is added to the DNS object in the Construct() method. When a DNS event is generated, one of these methods is called. The
 * methods of this interface may be overridden and used in any application that uses DNS.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/domain_name_system_access.htm">Domain Name System Access</a>.
 *
 * @see	Tizen::Net::IpHostEntry
 */
class _OSP_EXPORT_ IDnsEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IDnsEventListener(void) {}

public:
	/**
	 * Called to notify the result of the Dns request.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pIpHostEntry			The information on the dns event
	 * @param[in]	r						The cause of the error
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_IN_PROGRESS			A previous request is in progress.
	 * @exception	E_INVALID_SERVER		The requested server is invalid.
	 * @exception	E_INVALID_DOMAIN		The requested domain of the server is invalid.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_TIMEOUT				An attempt to connect to the server has timed out.
	 * @exception	E_NOT_RESPONDING		There is no response.
	 * @exception	E_DNS_NOT_FOUND			The DNS lookup has failed.
	 * @remarks		Always check the error code before accessing the result.
	 *				If @c r is not E_SUCCESS, @c ipHostEntry may not exist.
	 */
	virtual void OnDnsResolutionCompletedN(IpHostEntry* pIpHostEntry, result r) = 0;
}; // IDnsEventListener

} } // Tizen::Net

#endif // _FNET_IDNS_EVENT_LISTENER_H_
