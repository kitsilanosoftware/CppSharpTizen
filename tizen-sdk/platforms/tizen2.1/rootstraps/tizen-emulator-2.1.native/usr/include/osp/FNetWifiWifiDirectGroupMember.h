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
 * @file    FNetWifiWifiDirectGroupMember.h
 * @brief   This is the header file for the %WifiDirectGroupMember class.
 *
 * This header file contains the declarations of the %WifiDirectGroupMember class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_GROUP_MEMBER_H_
#define _FNET_WIFI_WIFI_DIRECT_GROUP_MEMBER_H_

#include <FBaseObject.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Net { namespace Wifi
{
class WifiDirectGroupMemberImpl;
/**
 * @if OSPDEPREC
 * @class       WifiDirectGroupMember
 * @brief       <i> [Deprecated] </i> This class provides methods for the Wi-Fi Direct group member.
 * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with
 *              ease irrespective of the role (for example, group owner, group client, and so on). @n
 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to
 *              use these APIs.
 *
 * @since       2.0
 *
 * The %WifiDirectGroupMember class provides methods for the Wi-Fi Direct group member.
 * @endif
 */

class _OSP_EXPORT_ WifiDirectGroupMember
	: public Tizen::Base::Object
{
public:
	/**
	 * @if OSPDEPREC
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs
	 *              with ease irrespective of the role (for example, group owner, group client, and so on). @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary
	 *              to use these APIs.
	 * @since       2.0
	 * @endif
	 */
	virtual ~WifiDirectGroupMember(void){}

	/**
	 * @if OSPDEPREC
	 * Gets the type of the Wi-Fi Direct group member.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs
	 *              with ease irrespective of the role (for example, group owner, group client, and so on). @n
	 *              Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary
	 *              to use these APIs.
	 *
	 * @since       2.0
	 *
	 * @return      The type of the Wi-Fi Direct group member
	 * @endif
	 */
	WifiDirectGroupMemberType GetGroupMemberType(void) const;

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	WifiDirectGroupMember(void);

	/**
	 * This is the copy constructor for the %WifiDirectGroupMember class. @n
	 * Do @b not use directly.
	 *
	 * @since       2.0
	 *
	 * @param[in]   value       An instance of %WifiDirectGroupMember
	 */
	WifiDirectGroupMember(const WifiDirectGroupMember& value);

	/**
	 * Assigns the value of the specified instance to the current instance of %WifiDirectGroupMember. @n
	 * Do @b not use directly.
	 *
	 * @since       2.0
	 *
	 * @param[in]   rhs         An instance of %WifiDirectGroupMember
	 */
	WifiDirectGroupMember& operator =(const WifiDirectGroupMember& rhs);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void WifiDirectGroupMember_Reserved1(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void WifiDirectGroupMember_Reserved2(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void WifiDirectGroupMember_Reserved3(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void WifiDirectGroupMember_Reserved4(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void WifiDirectGroupMember_Reserved5(void){ }

protected:
	WifiDirectGroupMemberType _groupMemberType;
	WifiDirectGroupMemberImpl* _pWifiDirectGroupMemberImpl;

	friend class WifiDirectGroupMemberImpl;
}; // WifiDirectGroupMember

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_GROUP_MEMBER_H_
