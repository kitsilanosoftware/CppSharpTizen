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
 * @file    FNetBtBluetoothTypes.h
 * @brief   This is the header file for the enumerations in the Bluetooth namespace.
 *
 * This header file contains the declarations and descriptions of the enumerations in the Bluetooth namespace.
 */
#ifndef _FNET_BT_BLUETOOTH_TYPES_H_
#define _FNET_BT_BLUETOOTH_TYPES_H_

#include <FBaseTypes.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

/**
 * @if OSPDEPREC
 * @enum        BluetoothDeviceStateType
 * Defines the states of the local %Bluetooth device.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated  This enum type is deprecated because the on/off states and the discoverable mode are not orthogonal.
 *              All the methods that use this enum type are also deprecated. Instead of using this enum type, it is
 *              recommended to use BluetoothManager::IsActivated() and the enum
 *              Bluetooth::BluetoothDiscoverableMode.
 * @since       2.0
 * @endif
 */
enum BluetoothDeviceStateType
{
	BT_DEVICE_STATE_OFF,                /**< @if OSPDEPREC The OFF state             @endif */
	BT_DEVICE_STATE_DISCOVERABLE,       /**< @if OSPDEPREC The DISCOVERABLE state    @endif */
	BT_DEVICE_STATE_NOT_DISCOVERABLE    /**< @if OSPDEPREC The NOT DISCOVERABLE state @endif */
};

/**
 * @enum        BluetoothDiscoverableMode
 * Defines the discoverable mode of the local %Bluetooth device.
 *
 * @since       2.0
 */
enum BluetoothDiscoverableMode
{
	BT_DISC_MODE_NOT_DISCOVERABLE,          /**< The mode NOT DISCOVERABLE by other devices */
	BT_DISC_MODE_DISCOVERABLE,              /**< The mode DISCOVERABLE by other devices     */
	BT_DISC_MODE_TIME_LIMITED_DISCOVERABLE  /**< The mode DISCOVERABLE by other devices during a certain amount of time */
};

/**
 * @enum        BluetoothConnectionType
 * Defines the %Bluetooth connection types.
 *
 * @since       2.0
 */
enum BluetoothConnectionType
{
	BT_CONNECTION_GENERIC,              /**< The GENERIC CONNECTION
	                                     *   @if OSPDEPREC
	                                     *   @deprecated    This enum field is deprecated.
	                                     *   @endif
	                                     */
	BT_CONNECTION_SPP_ACCEPTOR,         /**< The SPP ACCEPTOR CONNECTION  */
	BT_CONNECTION_SPP_INITIATOR,        /**< The SPP INITIATOR CONNECTION */
	BT_CONNECTION_OPP_SERVER,           /**< The OPP SERVER CONNECTION    */
	BT_CONNECTION_OPP_CLIENT,           /**< The OPP CLIENT CONNECTION    */
	BT_CONNECTION_MAX
};

/**
 * @enum        BluetoothHealthDataChannelType
 * Defines the transmission type of %BluetoothHealth data channel.
 *
 * @since 2.0
 */
enum BluetoothHealthDataChannelType
{
	BT_HEALTH_DATA_CHANNEL_NONE,         /**< The any type of data channel */
	BT_HEALTH_DATA_CHANNEL_RELIABLE,    /**< The data channel type for transmitting data with the reliable manner of
	                                     *   which the confidence in the exchange is at its highest (for example, measurement
	                                     *   and alert information)
	                                     */
	BT_HEALTH_DATA_CHANNEL_STREAMING    /**< The data channel type for transmitting data when the timeliness of the
	                                     *   delivery of each frame is more important than the reliable delivery of
	                                     *   every frame (for example, an ECG waveform, where low latency is critical)
	                                     */
};

/**
 * @enum        BluetoothServiceClassType
 * Defines the service class type (part of the class of the device), returned from the device discovery.
 *
 * @since        2.0
 */
enum BluetoothServiceClassType
{
	BT_COD_SVC_LIMITED_DISCOVERABLE_MODE = 0x0020,      /**< The LIMITED DISCOVERABLE MODE          */
	BT_COD_SVC_POSITIONING = 0x0100,                    /**< The POSITIONING service class type     */
	BT_COD_SVC_NETWORKING = 0x0200,                     /**< The NETWORKING service class type      */
	BT_COD_SVC_RENDERING = 0x0400,                      /**< The RENDERING service class type       */
	BT_COD_SVC_CAPTURING = 0x0800,                      /**< The CAPTURING service class type       */
	BT_COD_SVC_OBJECT_TRANSFER = 0x1000,                /**< The OBJECT TRANSFER service class type */
	BT_COD_SVC_AUDIO = 0x2000,                          /**< The AUDIO service class type           */
	BT_COD_SVC_TELEPHONY = 0x4000,                      /**< The TELEPHONY service class type       */
	BT_COD_SVC_INFORMATION = 0x8000,                    /**< The INFORMATION service class type     */
	BT_COD_SVC_ALL = 0x01FF,                            /**< The ALL services class type            */
	BT_COD_SVC_UNKNOWN = 0x0000                         /**< The UNKNOWN service class type         */
};

/**
 * @enum        BluetoothMajorDeviceClassType
 * Defines the major device class (part of the class of the device).
 *
 * @since        2.0
 */
enum BluetoothMajorDeviceClassType
{
	BT_COD_MAJ_DEV_CLS_MISC = 0x00,                     /**< The MISC major device class type             */
	BT_COD_MAJ_DEV_CLS_COMPUTER = 0x01,                 /**< The COMPUTER major device class type         */
	BT_COD_MAJ_DEV_CLS_PHONE = 0x02,                    /**< The PHONE major device class type            */
	BT_COD_MAJ_DEV_CLS_LAN_ACCESS_POINT = 0x03,         /**< The LAN ACCESS POINT major device class type */
	BT_COD_MAJ_DEV_CLS_AUDIO = 0x04,                    /**< The AUDIO major device class type            */
	BT_COD_MAJ_DEV_CLS_PERIPHERAL = 0x05,               /**< The PERIPHERAL major device class type       */
	BT_COD_MAJ_DEV_CLS_IMAGING = 0x06,                  /**< The IMAGING major device class type          */
	BT_COD_MAJ_DEV_CLS_UNCLASSIFIED = 0x1F              /**< The UNCLASSIFIED major device class type     */
};

/**
 * @enum        BluetoothMinorDeviceClassType
 * Defines the minor device class (part of the class of the device).
 *
 * @since        2.0
 */
enum BluetoothMinorDeviceClassType
{
	BT_COD_MIN_DEV_CLS_UNCLASSIFIED = 0x00,                 /**< The UNCLASSIFIED minor device class type          */

	BT_COD_MIN_DEV_CLS_DESKTOP_WORKSTATION = 0x04,          /**< The DESKTOP WORKSTATION minor device class type   */
	BT_COD_MIN_DEV_CLS_SERVER_CLASS_COMPUTER = 0x08,        /**< The SERVER CLASS COMPUTER minor device class type */
	BT_COD_MIN_DEV_CLS_LAPTOP = 0x0C,                       /**< The LAPTOP minor device class type                */
	BT_COD_MIN_DEV_CLS_HANDHELD_PC_OR_PDA = 0x10,           /**< The HANDHELD PC OR PDA minor device class type    */
	BT_COD_MIN_DEV_CLS_PALM_SIZED_PC_OR_PDA = 0x14,         /**< The PALM SIZED PC OR PDA minor device class type  */
	BT_COD_MIN_DEV_CLS_WEARABLE_COMPUTER = 0x18,            /**< The WEARABLE COMPUTER minor device class type     */

	BT_COD_MIN_DEV_CLS_CELLULAR = 0x04,                     /**< The CELLULAR minor device class type                     */
	BT_COD_MIN_DEV_CLS_CORDLESS = 0x08,                     /**< The CORDLESS minor device class type                     */
	BT_COD_MIN_DEV_CLS_SMART_PHONE = 0x0C,                  /**< The SMART PHONE minor device class type                  */
	BT_COD_MIN_DEV_CLS_WIRED_MODEM_OR_VOICE_GATEWAY = 0x10, /**< The WIRED MODEM OR VOICE GATEWAY minor device class type */
	BT_COD_MIN_DEV_CLS_COMMON_ISDN_ACCESS = 0x14,           /**< The COMMON ISDN ACCESS minor device class type           */

	BT_COD_MIN_DEV_CLS_FULLY_AVAILABLE = 0x04,              /**< The FULLY AVAILABLE minor device class type           */
	BT_COD_MIN_DEV_CLS_1_TO_17_PERCENT_UTILIZED = 0x20,     /**< The 1_TO_17_PERCENT_UTILIZED minor device class type  */
	BT_COD_MIN_DEV_CLS_17_TO_33_PERCENT_UTILIZED = 0x40,    /**< The 17_TO_33_PERCENT_UTILIZED minor device class type */
	BT_COD_MIN_DEV_CLS_33_TO_50_PERCENT_UTILIZED = 0x60,    /**< The 33_TO_50_PERCENT_UTILIZED minor device class type */
	BT_COD_MIN_DEV_CLS_50_to_67_PERCENT_UTILIZED = 0x80,    /**< The 50_to_67_PERCENT_UTILIZED minor device class type */
	BT_COD_MIN_DEV_CLS_67_TO_83_PERCENT_UTILIZED = 0xA0,    /**< The 67_TO_83_PERCENT_UTILIZED minor device class type */
	BT_COD_MIN_DEV_CLS_83_TO_99_PERCENT_UTILIZED = 0xC0,    /**< The 83_TO_99_PERCENT_UTILIZED minor device class type */
	BT_COD_MIN_DEV_CLS_NO_SERVICE_AVAILABLE = 0xE0,         /**< The NO SERVICE AVAILABLE minor device class type      */

	BT_COD_MIN_DEV_CLS_HEADSET_PROFILE = 0x04,              /**< The HEADSET PROFILE minor device class type       */
	BT_COD_MIN_DEV_CLS_HANDSFREE = 0x08,                    /**< The HANDSFREE minor device class type             */
	BT_COD_MIN_DEV_CLS_SIM_CARD_READER = 0x18,              /**< The SIM CARD READER minor device class type       */

};

/**
 * @enum        BluetoothServiceType
 * Defines the %Bluetooth service type.
 *
 * @since       2.0
 */
enum BluetoothServiceType
{
	BT_SVC_RES_SERVICE = 0x00000001,           /**< The Reserved service type                           */
	BT_SVC_SPP_SERVICE = 0x00000002,           /**< The Serial port profile service type                */
	BT_SVC_DUN_SERVICE = 0x00000004,           /**< The Dial-up networking profile service type         */
	BT_SVC_FAX_SERVICE = 0x00000008,           /**< The Fax profile service type                        */
	BT_SVC_LAP_SERVICE = 0x00000010,           /**< The LAN access profile service type                 */
	BT_SVC_HSP_SERVICE = 0x00000020,           /**< The Headset profile service type                    */
	BT_SVC_HFP_SERVICE = 0x00000040,           /**< The Hands-free profile service type                 */
	BT_SVC_OPP_SERVICE = 0x00000080,           /**< The Object push service type                        */
	BT_SVC_FTP_SERVICE = 0x00000100,           /**< The File transfer service type                      */
	BT_SVC_CTP_SERVICE = 0x00000200,           /**< The Cordless Terminal service type                  */
	BT_SVC_ICP_SERVICE = 0x00000400,           /**< The Intercom Terminal service type                  */
	BT_SVC_SYNC_SERVICE = 0x00000800,          /**< The Synchronization service type                    */
	BT_SVC_BPP_SERVICE = 0x00001000,           /**< The Print server service type                       */
	BT_SVC_BIP_SERVICE = 0x00002000,           /**< The Basic Imaging service type                      */
	BT_SVC_PANU_SERVICE = 0x00004000,          /**< The PAN User service type                           */
	BT_SVC_NAP_SERVICE = 0x00008000,           /**< The PAN Network access point service type           */
	BT_SVC_GN_SERVICE = 0x00010000,            /**< The PAN Group Ad-hoc networks service type          */
	BT_SVC_SAP_SERVICE = 0x00020000,           /**< The SIM Access Profile service type                 */
	BT_SVC_A2DP_SERVICE = 0x00040000,          /**< An advanced audio distribution service type         */
	BT_SVC_AVRCP_SERVICE = 0x00080000,         /**< An A/V remote control service type                  */
	BT_SVC_HID_SERVICE = 0x00100000,           /**< The HID profile service type                        */
	BT_SVC_VDP_SERVICE = 0x00200000,           /**< The VDP profile service type                        */
	BT_SVC_PBAP_SERVICE = 0x00400000,          /**< The PhoneBook Access service type                   */
	BT_SVC_HSP_HS_SERVICE = 0x00800000,        /**< The Headset service type                            */
	BT_SVC_HFP_HS_SERVICE = 0x01000000,        /**< The Hands-free Headset service type                 */
	BT_SVC_HCRP_SERVICE = 0x02000000,          /**< The Hardcopy cable replacement profile service type */
	BT_SVC_DID_SERVICE = 0x04000000,           /**< The device identification profile service type      */
	BT_SVC_HDP_SERVICE = 0x08000000,           /**< The health device profile service type              */
	BT_SVC_MAP_SERVICE = 0x10000000,           /**< The message access profile service type             */
	BT_SVC_ALL_SERVICE = 0x01FFFFFF,           /**< The All-services-supported-by-BTA service type
	                                            *   @if OSPDEPREC
	                                            *   @deprecated    This enum field is deprecated.
	                                            *   @endif

                                                */
	BT_SVC_NONE = 0                            /**< The No service or unknown service type              */
};

/**
 * The serial port profile UUID (00001101-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_SPP[];

/**
 * The LAN access profile UUID (00001102-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_LAP[];

/**
 * The dial-up networking profile UUID (00001103-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_DUN[];

/**
 * The synchronization profile UUID (00001104-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_SYNC[];

/**
 * The object push profile UUID (00001105-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_OPP[];

/**
 * The file transfer profile UUID (00001106-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_FTP[];

/**
 * The synchronization profile UUID (00001107-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_SYNC_COMMAND[];

/**
 * The headset profile UUID (00001108-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HSP[];

/**
 * The cordless telephony profile UUID (00001109-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_CTP[];

/**
 * The advanced audio distribution profile source UUID (0000110A-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_A2DP_SOURCE[];

/**
 * The advanced audio distribution profile - sink UUID (0000110B-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_A2DP_SINK[];

/**
 * The audio/video remote control profile - target UUID (0000110C-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_AVRCP_TARGET[];

/**
 * The advanced audio distribution profile UUID (0000110D-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_A2DP[];

/**
 * The audio/video remote control profile UUID (0000110E-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_AVRCP[];

/**
 * The audio/video remote control profile - controller UUID (0000110F-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_AVRCP_CONTROLLER[];

/**
 * The intercom profile UUID (00001110-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_ICP[];

/**
 * The fax profile UUID (00001111-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_FAX[];

/**
 * The headset profile audio gateway UUID (00001112-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HSP_AG[];

/**
 * The personal area networking profile - user UUID (00001115-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_PAN_PANU[];

/**
 * The personal area networking profile - network access point UUID (00001116-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_PAN_NAP[];

/**
 * The personal area networking profile - group ad-hoc networks UUID (00001117-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_PAN_GN[];

/**
 * The basic printing profile - direct printing UUID (00001118-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BPP_DIRECT_PRINTING[];

/**
 * The basic printing profile - reference printing UUID (00001119-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BPP_REFERENCE_PRINTING[];

/**
 * The basic imaging profile UUID (0000111A-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BIP[];

/**
 * The basic imaging profile - imaging responder UUID (0000111B-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BIP_RESPONDER[];

/**
 * The basic imaging profile - imaging automatic archive UUID (0000111C-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BIP_AUTOMATIC_ARCHIVE[];

/**
 * The basic imaging profile - imaging referenced objects UUID (0000111D-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BIP_REFERENCED_OBJECTS[];

/**
 * The hands-free profile UUID (0000111E-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HFP[];

/**
 * The hands-free profile - audio gateway UUID (0000111F-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HFP_AG[];

/**
 * The basic printing profile - direct printing referenced objects UUID (00001120-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BPP_DIRECT_PRINTING_RO[];

/**
 * The basic printing profile - reflected UI UUID (00001121-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BPP_REFLECTED_UI[];

/**
 * The basic printing profile - basic printing UUID (00001122-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BPP_BASIC_PRINTING[];

/**
 * The basic printing profile - printing status UUID (00001123-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_BPP_PRINTING_STATUS[];

/**
 * The human interface device profile UUID (00001124-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HID[];

/**
 * The hardcopy cable replacement profile UUID (00001125-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HCRP[];

/**
 * The hardcopy cable replacement profile - print UUID (00001126-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HCRP_PRINT[];

/**
 * The hardcopy cable replacement profile - scan UUID (00001127-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HCRP_SCAN[];

/**
 * The SIM access profile UUID (0000112D-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_SAP[];

/**
 * The phone book access - client equipment UUID (0000112E-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_PBAP_PCE[];

/**
 * The phone book access - server equipment UUID (0000112F-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_PBAP_PSE[];

/**
 * The phone book access UUID (00001130-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_PBAP[];

/**
 * The headset profile - headset UUID (00001131-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HSP_HS[];

/**
 * The message access profile - message access server UUID (00001132-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_MAP_ACCESS_SERVER[];

/**
 * The message access profile - message notification server UUID (00001133-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_MAP_NOTIFICATION_SERVER[];

/**
 * The message access profile - message access profile UUID (00001134-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_MAP_ACCESS_PROFILE[];

/**
 * The device identification profile - PNP information UUID (00001200-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_DID_PNP_INFORMATION[];

/**
 * The generic networking UUID (00001201-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_GENERIC_NETWORKING[];

/**
 * The generic file transfer UUID (00001202-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_GENERIC_FILE_TRANSFER[];

/**
 * The generic audio UUID (00001203-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_GENERIC_AUDIO[];

/**
 * The generic telephony UUID (00001204-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_GENERIC_TELEPHONY[];

/**
 * The video distribution profile - source UUID (00001303-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_VDP_SOURCE[];

/**
 * The video distribution profile - sink UUID (00001304-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_VDP_SINK[];

/**
 * The video distribution profile - distribution UUID (00001305-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_VDP_DISTRIBUTION[];

/**
 * The health device profile UUID (00001400-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HDP[];

/**
 * The health device profile - source UUID (00001401-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HDP_SOURCE[];

/**
 * The health device profile - sink UUID (00001402-0000-1000-8000-00805F9B34FB).
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const byte BT_SVC_UUID_HDP_SINK[];

} } }
#endif // _FNET_BT_BLUETOOTH_TYPES_H_
