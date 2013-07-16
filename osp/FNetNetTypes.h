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
* @file			FNetNetTypes.h
* @brief		This is the header file for defining the types for the Net namespace.
*
* This header file contains the definitions of the various types and enumerators for the NetConnection operations.
*/
#ifndef _FNET_NET_TYPES_H_
#define _FNET_NET_TYPES_H_

#include <FBase.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseErrorDefine.h>


namespace Tizen { namespace Net
{

/**
 * The network account ID.
 *
 * @since 2.0
 */
typedef int NetAccountId;

/**
 * @enum	NetConnectionState
 *
 * Defines the state of the network connection.
 *
 * @since	2.0
 */
enum NetConnectionState
{
	NET_CONNECTION_STATE_NONE,          /**< The initial state */
	NET_CONNECTION_STATE_STARTING,      /**< The network connection is being established */
	NET_CONNECTION_STATE_STARTED,       /**< The network connection has been established */
	NET_CONNECTION_STATE_STOPPING,      /**< The network connection is being disconnected */
	NET_CONNECTION_STATE_STOPPED,       /**< The network connection has been disconnected */
	NET_CONNECTION_STATE_SUSPENDED,     /**< The network connection has been suspended */
	NET_CONNECTION_STATE_SUSPEND = 5,   // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	NET_CONNECTION_STATE_RESUMED,       /**< The network connection is established, and recovered from SUSPEND state - enable to send/receive packet data */
	NET_CONNECTION_STATE_AVAILABLE,     // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	NET_CONNECTION_STATE_UNAVAILABLE,   // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    NetConnectionStoppedReason
 *
 * Defines the reason for stoppage of the network connection.
 *
 * @since 2.0
 */
enum NetConnectionStoppedReason
{
	NET_CONNECTION_STOPPED_REASON_RESOURCE_RELEASED,    /**< The network connection managed by system stopped because the network resources have been released */
	NET_CONNECTION_STOPPED_REASON_NETWORK_FAILED,       /**< The network has failed */
	NET_CONNECTION_STOPPED_REASON_DEVICE_OFFLINE,       /**< The operation has failed because the device is in offline mode */
	NET_CONNECTION_STOPPED_REASON_SERVICE_UNAVAILABLE,  /**< The device is out of the coverage area or in an emergency mode */
	NET_CONNECTION_STOPPED_REASON_RESOURCE_UNAVAILABLE, /**< The network resource is unavailable */
	NET_CONNECTION_STOPPED_REASON_SYSTEM                /**< A system error has occurred */
};

/**
 * @enum    NetProtocolType
 *
 * Defines the network protocol type.
 *
 * @since	2.0
 */
enum NetProtocolType
{
	NET_PROTO_TYPE_IPV4 = 1,            /**< The IPV4 type */
	NET_PROTO_TYPE_PPP,             		/**< The PPP type */
	NET_PROTO_TYPE_IPV6,            		/**< The IPV6 type, currently NOT supported */
	NET_PROTO_TYPE_NONE = 0         // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. Network Protocol type not set
};

/**
 * @enum    NetAddressFamily
 *
 * Defines the network address family.
 *
 * @since	2.0
 */
enum NetAddressFamily
{

	NET_AF_IPV4 = 1,            	/**< The default @n An IPv4 address [RFC791] is represented in decimal format with dots as delimiters. */
	NET_AF_IPV6,            			/**< An IPv6 address [RFC2373] is generally represented in hexadecimal numbers with colons as delimiters @n It can also be a combination of hexadecimal and decimal numbers with dots and colons as delimiters. */
	NET_AF_ALPHANUMERIC,    /**< A generic alphanumeric address (as defined by alphanum in [RFC2396]) */
	NET_AF_APN,             		/**< A GPRS APN as defined in [GENFORM] */
	NET_AF_NONE = 0         	// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. Network Address Family not set
};

/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @enum    NetStatisticsInfoType
 *
 * Defines the various kinds of data call statistics information.
 *
 * @since	2.0
 */
enum NetStatisticsInfoType
{
	NET_STAT_SENT_SIZE = 2,								/**< The size of the packet sent, since the time the network is last reactivated */
	NET_STAT_RCVD_SIZE = 3,								/**< The size of the packet received, since the time the network is last reactivated */
	NET_STAT_TOTAL_SENT_SIZE = 8,					/**< The cumulated size of the packet sent since the last reset */
	NET_STAT_TOTAL_RCVD_SIZE = 9,					/**< The cumulated size of the packet received since the last reset */
	NET_STAT_NONE = 0           						// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. Network Statistics Info Type not set
};

/**
 * @enum    NetPreferenceType
 *
 * Defines the preferred network.
 *
 * @since	2.0
 */
enum NetPreferenceType
{
	NET_WIFI_FIRST,					/**< The preference type to follow preferred mode (Wi-Fi first) @n
			                        			*	This preference type works like NET_PS_ONLY on the Emulator. */
	NET_PS_ONLY,						/**< The preference type to only operate services for the PS domain */
	NET_CS_ONLY,                     // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	NET_WIFI_ONLY                    /**< The preference type to only operate services for Wi-Fi */
};

/**
 * @enum    NetBearerType
 *
 * Defines the bearer type.
 *
 * @since	2.0
 */
enum NetBearerType
{
	NET_BEARER_PS = 1,                 /**< The bearer type for the PS domain */
	NET_BEARER_CS,                  		// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	NET_BEARER_WIFI,               		/**< The bearer type for Wi-Fi */
	NET_BEARER_WIFI_DIRECT,         /**< The bearer type for Wi-Fi Direct @n
			                        				*	This bearer type cannot be tested on the Emulator. */
	NET_BEARER_USB,                 	/**< The bearer type for USB NDIS mode @n
			                        				*	Can use this bearer type via USB Tethering mode. @n
			                        				*	This bearer type cannot be tested on the Emulator. */
	NET_BEARER_MMS,                 	/**< The bearer type for MMS */
	NET_BEARER_NONE = 0             // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. Network Bearer Type not set
};

/**
 * @enum    NetAddressScheme
 *
 * Defines the network IP or Domain Name %System (DNS) scheme.
 *
 * @since	2.0
 */
enum NetAddressScheme
{
	NET_ADDRESS_SCHEME_DYNAMIC = 1, /**< The Dynamic IP or DNS Address */
	NET_ADDRESS_SCHEME_STATIC,      /**< The Static IP or DNS Address */
	NET_ADDRESS_SCHEME_NONE = 0     // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. Network Address Scheme not set
};

/**
 * @enum    NetNapAuthType
 *
 * Defines the authentication type of the network.
 *
 * @since	2.0
 *
 * @remarks  There is no relevant data.
 */
enum NetNapAuthType
{
	NET_NAPAUTH_PAP = 1,						/**< The PAP (Password Authentication Protocol) type */
	NET_NAPAUTH_CHAP,							/**< The CHAP (Challenge/Handshake Authentication Protocol) type */
	NET_NAPAUTH_NONE = 0					// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application. Network NAP Authentication Type not set
};

/**
 * @enum    NetProxyType
 *
 * Defines the proxy type of the network.
 *
 * @since 2.0
 */
enum NetProxyType
{
    NET_PROXY_TYPE_NONE = 0,  /**< No use of proxy */
    NET_PROXY_TYPE_MANUAL     /**< Manual configuration */
};


} } //Tizen::Net

#endif // _FNET_NET_TYPES_H_
