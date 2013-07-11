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
 * @file    FNetWifiWifiTypes.h
 * @brief   This is the header file for the enumerations in the Wifi namespace.
 *
 * This header file contains the type declarations of the Wifi namespace.
 */
#ifndef _FNET_WIFI_WIFI_TYPES_H_
#define _FNET_WIFI_WIFI_TYPES_H_

#include <FBaseTypes.h>
#include <FBaseByteBuffer.h>

namespace Tizen { namespace Net { namespace Wifi
{

/**
 * The Wi-Fi Direct Device ID.
 *
 * @since   2.0
 */
typedef int WifiDirectDeviceId;

/**
 * The maximum number of associated clients.
 *
 * @since   2.0
 */
static const int MAX_WIFI_DIRECT_CONNECTED_CLIENTS = 8;

/**
 * The maximum number of group owners intent for negotiation.
 *
 * @since   2.0
 */
static const int MAX_WIFI_DIRECT_GROUP_OWNER_INTENT = 15;

/**
 * @enum    WifiPowerStatus
 *
 * Defines the power status of the local Wi-Fi device.
 *
 * @since   2.0
 * @see     WifiManager::GetPowerStatus()
 */
enum WifiPowerStatus
{
	WIFI_POWER_STATUS_OFF = 0,      /**<  The local Wi-Fi device is turned off */
	WIFI_POWER_STATUS_ON,           /**<  The local Wi-Fi device is turned on */
	WIFI_POWER_STATUS_DEEP_SLEEP,   /**<  The local Wi-Fi device enters deep sleep mode */
};

/**
 * @enum    WifiBssType
 *
 * Defines the type of Basic Service Set (BSS).
 *
 * @since 2.0
 */
enum WifiBssType
{
	WIFI_BSS_TYPE_INFRASTRUCTURE = 0,   /**< The infrastructure type which usually consists of a single Access Point (AP) @n
				                         *   However, in order to provide sufficient coverage, it could be necessary to use two
				                         *   or more APs. @n
				                         *    Logically, there needs to be an interconnection among APs, and this concept is
				                         *   called Distribution %System (DS). @n
				                         *   Connecting with multiple APs through DS creates a wireless network of an arbitrary
				                         *   size. @n
				                         *   This is called Extended Service Set (ESS). Finally, a logical connection point to
				                         *   the wired LAN is supported by a concept designated as Portal. */
	WIFI_BSS_TYPE_INDEPENDENT,          /**<  The simplest Wi-Fi configuration is called as Independent Basic Service Set (IBSS)
	                                     *    or ad hoc @n
				                         *    The IBSS is a self-contained network that only supports direct communication
				                         *    between Stations (STAs) that belong to the same BSS. @n
				                         *    The most common example of this connection is the use of Wi-Fi to establish
				                         *    peer-to-peer network connection between two STAs. */
	WIFI_BSS_TYPE_ANY,                  /**<  The type with no specification */
	WIFI_BSS_TYPE_MAX = 65535           // This enum value is for internal use only. Using this enum value can cause behavioral,
	                                    // security-related, and consistency-related issues in the application.
};

/**
 * @enum    WifiAuthenticationType
 *
 * Defines IEEE 802.11 authentication.
 * IEEE 802.11 authentication operates at the link level between IEEE 802.11 stations (STAs).
 * IEEE 802.11 does not provide end-to-end (message origin to message destination) or user-to-user authentication.
 *
 * @since 2.0
 */
enum WifiAuthenticationType
{
	WIFI_AUTHENTICATION_OPEN = 0,           /**<  The Open %System Authentication that admits any STA to the DS */
	WIFI_AUTHENTICATION_SHARED,             /**<  The Shared Key Authentication relies on the WEP to demonstrate knowledge of a
	                                         *    WEP encryption key */
	WIFI_AUTHENTICATION_WPA,                /**<  The Enterprise Authentication that supports WPA (Wi-Fi Protected Access) */
	WIFI_AUTHENTICATION_WPA_PSK,            /**<  The Personal Authentication that supports WPA; PSK stands for PreShared Key */
	WIFI_AUTHENTICATION_WPA2,               /**<  The Enterprise Authentication that supports WPA2 */
	WIFI_AUTHENTICATION_WPA2_PSK,           /**<  The Personal Authentication that supports WPA2; PSK stands for PreShared Key */
	WIFI_AUTHENTICATION_WPA_WPA2_MIXED_PSK, /**<  The Personal Authentication that supports both WPA and WPA2; PSK stands for
	                                         *    PreShared Key */
	WIFI_AUTHENTICATION_MAX = 65535         // This enum value is for internal use only. Using this enum value can cause
	                                        // behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    WifiEncryptionType
 *
 * Defines the IEEE 802.11 encryption that provides the data confidentiality aspects of a closed wired media.
 *
 * @since 2.0
 */
enum WifiEncryptionType
{
	WIFI_ENCRYPTION_NONE = 0,       /**<  The type with no encryption */
	WIFI_ENCRYPTION_WEP,            /**<  The Wired Equivalent Privacy @n This is only used for open and shared methods. */
	WIFI_ENCRYPTION_TKIP,           /**<  The Temporal Key Integrity Protocol */
	WIFI_ENCRYPTION_AES,            /**<  The Advanced Encryption Standard */
	WIFI_ENCRYPTION_TKIP_AES_MIXED, /**<  The TKIP and AES are both supported */
	WIFI_ENCRYPTION_MAX = 65535     // This enum value is for internal use only. Using this enum value can cause behavioral,
	                                // security-related, and consistency-related issues in the application.
};

/**
 * @enum    WifiEapType
 *
 * Defines the Extensible Authentication Protocol (EAP) method types that provide a specific authentication mechanism.
 *
 * @since 2.0
 */
enum WifiEapType
{
	WIFI_EAP_NONE = 0,       /**<  The method type where no EAP method is used */
	WIFI_EAP_SIM,            /**<  The EAP-SIM; EAP for GSM Subscriber Identity */
	WIFI_EAP_AKA,            /**<  The EAP-AKA; EAP for UMTS Authentication and Key Agreement */
	WIFI_EAP_TTLS_MSCHAPV2,  /**<  The EAP-TTLS/MSCHAPv2; Tunnel MSCHAPv2 through TTLS(Tunneled Transport Layer Security) */
	WIFI_EAP_PEAP_MSCHAPV2,  /**<  The PEAPv0/EAP-MSCHAPv2; Tunnel MSCHAPv2 through PEAP(Protected Extensible Authentication
	                          *    Protocol) */
	WIFI_EAP_PEAP_GTC,       /**<  The PEAPv1/EAP-GTC; Tunnel GTC through PEAP(Protected Extensible Authentication Protocol) */
	WIFI_EAP_TLS             /**<  The EAP-TLS, Not supported yet */
};

/**
 * @if OSPDEPREC
 * @enum    WifiWepKeyLen
 *
 * Defines the Wired Equivalent Privacy (WEP) key length.
 *
 * @brief   <i> [Deprecated] </i>
 * @deprecated  This enum is deprecated because the SetNetworkKeyWep() method is also deprecated.
 *
 * @since 2.0
 * @endif
 */
enum WifiWepKeyLen
{
	WIFI_WEP_KEY_LEN_64BIT = 0,     /**< @if OSPDEPREC The WEP key of length 64bits @n
	                                 *   The minimum length of the WEP key is 5 digits (40bits). @endif */
	WIFI_WEP_KEY_LEN_128BIT,        /**< @if OSPDEPREC The WEP key of length 128bits @n
	                                 *   The minimum length of the WEP key is 13 digits (104bits). @endif */
	WIFI_WEP_KEY_LEN_MAX = 65535    // This enum value is for internal use only. Using this enum value can cause behavioral,
	                                // security-related, and consistency-related issues in the application.
};

/**
 * @if OSPDEPREC
 * @enum    WifiWepKeyIndex
 *
 * Defines the Wired Equivalent Privacy (WEP) key index.
 *
 * @brief   <i> [Deprecated] </i>
 * @deprecated  This enum is deprecated because the SetNetworkKeyWep() method is also deprecated.
 *
 * @since 2.0
 *
 * @remarks Only WIFI_WEP_KEY_INDEX_1 is supported now.
 * @endif
 */
enum WifiWepKeyIndex
{
	WIFI_WEP_KEY_INDEX_1 = 1,   /**< @if OSPDEPREC The WEP Key Index 1 @endif */
	WIFI_WEP_KEY_INDEX_2 = 2,   /**< @if OSPDEPREC The WEP Key Index 2 @endif */
	WIFI_WEP_KEY_INDEX_3 = 3,   /**< @if OSPDEPREC The WEP Key Index 3 @endif */
	WIFI_WEP_KEY_INDEX_4 = 4,   /**< @if OSPDEPREC The WEP Key Index 4 @endif */
};

/**
 * @enum    WifiRadioChannel
 *
 * Defines the BSS radio channel.
 *
 * @since   2.0
 */
enum WifiRadioChannel
{
    WIFI_RADIO_CHANNEL_1        = 1,        /**< The Radio Channel 1 */
    WIFI_RADIO_CHANNEL_2        = 2,        /**< The Radio Channel 2 */
    WIFI_RADIO_CHANNEL_3        = 4,        /**< The Radio Channel 3 */
    WIFI_RADIO_CHANNEL_4        = 8,        /**< The Radio Channel 4 */
    WIFI_RADIO_CHANNEL_5        = 16,       /**< The Radio Channel 5 */
    WIFI_RADIO_CHANNEL_6        = 32,       /**< The Radio Channel 6 */
    WIFI_RADIO_CHANNEL_7        = 64,       /**< The Radio Channel 7 */
    WIFI_RADIO_CHANNEL_8        = 128,      /**< The Radio Channel 8 */
    WIFI_RADIO_CHANNEL_9        = 256,      /**< The Radio Channel 9 */
    WIFI_RADIO_CHANNEL_10       = 512,      /**< The Radio Channel 10 */
    WIFI_RADIO_CHANNEL_11       = 1024,     /**< The Radio Channel 11 */
    WIFI_RADIO_CHANNEL_12       = 2048,     /**< The Radio Channel 12 */
    WIFI_RADIO_CHANNEL_13       = 4096,     /**< The Radio Channel 13 */
    WIFI_RADIO_CHANNEL_14       = 8192,     /**< The Radio Channel 14 */
    WIFI_RADIO_CHANNEL_UNKNOWN = 0          // This enum value is for internal use only. Using this enum value can cause
                                            // behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum    WifiDirectDeviceStatus
 *
 * Defines the status of a Wi-Fi Direct device.
 *
 * @since   2.0
 */
enum WifiDirectDeviceStatus
{
	WIFI_DIRECT_DEVICE_DEACTIVATED = 0,     /**< The Wi-Fi interface is deactivated */
	WIFI_DIRECT_DEVICE_ACTIVATED            /**< The Wi-Fi interface is activated */
};

/**
 * @enum    WifiDirectGroupMemberType
 *
 * Defines the type of a Wi-Fi Direct device.
 *
 * @since   2.0
 */
enum WifiDirectGroupMemberType
{
	WIFI_DIRECT_GROUP_MEMBER_TYPE_NONE = 0,  /**< The Wi-Fi Direct Group Non-member @n That is, the device does not belong to any
	                                          * group. */
	WIFI_DIRECT_GROUP_MEMBER_TYPE_OWNER,     /**< The Wi-Fi Direct Group Owner */
	WIFI_DIRECT_GROUP_MEMBER_TYPE_CLIENT     /**< The Wi-Fi Direct Group Client */
};

/**
 * @enum    WifiDirectDeviceTypeCategory
 *
 * Defines the category of the Wi-Fi Direct device type.
 *
 * @since   2.0
 */
enum WifiDirectDeviceTypeCategory
{
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_COMPUTER = 0,               /**< The PC, Server, %Media Center, UMPC, Notebook, Desktop,
	                                                              *   MID, Netbook, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_INPUT_DEVICE,               /**< The Keyboard, Mouse, Joystick, Trackball, Gaming
	                                                              *   controller, Remote, Touchscreen, Biometric reader, Barcode
	                                                              *   reader, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_PRINTER_SCANNER_FAX_COPIER, /**< The Printer, Print Server, Scanner, Fax, Copier,
	                                                              *   All-in-one, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_CAMERA,                     /**< The Digital still camera, Video camera, %Web camera,
	                                                              *   %Security camera, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_STORAGE,                    /**< The NAS */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_NETWORK_INFRASTRUCTURE,     /**< The AP, Router, Switch, Gateway, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_DISPLAY,                    /**< The Television, Electronic picture frame, Projector,
	                                                              *   Monitor, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_MULTIMEDIA_DEVICE,          /**< The DAR, PVR, MCX, Set-top box, %Media server, %Media
	                                                              *   adapter, %Media extender, Portable video player, and so
	                                                              *   on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_GAMING_DEVICE,              /**< The Xbox, Playstation, Game console, Game console adaptor,
	                                                              *   Portable gaming device, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_TELEPHONE,                  /**< The Windows Mobile, Phone, Smartphone, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_AUDIO_DEVICE,               /**< The Audio tuner, Audio receiver, Speaker, Portable Music
	                                                              *   Player, Headset, Headphone, Microphone, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_OTHERS = 255                /**< A device which is not classified into the above types */
};

/**
 * @if OSPDEPREC
 * @enum    WifiDirectAssociationTerminationReason
 *
 * Defines the reason for the Wi-Fi Direct group client association's termination.
 *
 * @brief   <i> [Deprecated] </i>
 * @deprecated   This method is deprecated because the Wi-Fi Direct APIs have been revised to allow the use of APIs with ease irrespective of the role (for example, group owner, group client, and so on). @n
     * Earlier, the Wi-Fi Direct APIs were strictly provided depending on the role and so it was necessary to use these APIs.
 *
 * @since   2.0
 * @endif
 */
enum WifiDirectAssociationTerminationReason
{
	WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_SELF_INITIATED = 0, /**< @if OSPDEPREC The enumerator that is delivered to a group owner or
	                                                                *   group client who initiates the disassociation request @endif */
	WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_DISCONNECTED        /**< @if OSPDEPREC The enumerator that is delivered to a group owner or
	                                                                *   group client who receives the disassociation request or
	                                                                *   when a client is disconnected due to out of range or
	                                                                *   abrupt connection loss to the group owner @endif */
};

/**
 * @enum WifiWpsConfigurationMode
 *
 * Defines the configuration method for the Wi-Fi Protected Setup (WPS).
 *
 * @since     2.0
 */
enum WifiWpsConfigurationMode
{
	WIFI_WPS_CONFIG_MODE_NONE = 0,          /**< The configuration mode with no method to be provided */
	WIFI_WPS_CONFIG_MODE_PIN_DISPLAY,       /**< A method to display the PIN code */
	WIFI_WPS_CONFIG_MODE_PIN_KEYPAD,        /**< A method to provide the keypad to input the PIN */
	WIFI_WPS_CONFIG_MODE_PBC                /**< A method of Push Button Configuration (PBC) */
};



} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_TYPES_H_
