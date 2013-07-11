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
 * @file    FNetWifi.h
 * @brief   This is the header file for the %Wifi namespace.
 *
 * This header file contains the declarations and descriptions of the %Wifi namespace.
 */

#ifndef _FNET_WIFI_H_
#define _FNET_WIFI_H_

#include <FNetWifiWifiTypes.h>
#include <FNetWifiWifiManager.h>
#include <FNetWifiWifiBssInfo.h>
#include <FNetWifiWifiSecurityInfo.h>
#include <FNetWifiIWifiManagerEventListener.h>

#include <FNetWifiWifiNetAccountInfo.h>
#include <FNetWifiIWifiDirectDeviceListener.h>
#include <FNetWifiIWifiDirectGroupOwnerListener.h>
#include <FNetWifiIWifiDirectGroupClientListener.h>
#include <FNetWifiWifiDirectDevice.h>
#include <FNetWifiWifiDirectDeviceInfo.h>
#include <FNetWifiWifiDirectDeviceManager.h>
#include <FNetWifiWifiDirectGroupClient.h>
#include <FNetWifiWifiDirectGroupInfo.h>
#include <FNetWifiWifiDirectGroupMember.h>
#include <FNetWifiWifiDirectGroupOwner.h>

namespace Tizen { namespace Net
{

/**
  * @namespace   Tizen::Net::Wifi
  * @brief       This namespace contains the classes and interfaces for the Wi-Fi management and Wi-Fi Direct functionalities.
  * @since       2.0
  *
  * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
  *              @b Library : @b osp-wifi @n
  *
  * The %Net::Wifi namespace contains the classes and interfaces for Wi-Fi management and Wi-Fi Direct functionalities. It provides a rich set of methods
  * to manage the Wi-Fi devices and accounts, and to communicate over a Wi-Fi channel. Additionally, the Wi-Fi Direct functionalities are provided to manage
  * the Wi-Fi Direct device, create a Wi-Fi Direct group, scan Wi-Fi Direct devices, associate to a Wi-Fi Direct group owner, get the WifiDirectGroupOwner or
  * the WifiDirectGroupClient instance, and allow the listener to get the events related to Wi-Fi Direct device and group.
  *
  * This namespace provides the Wi-Fi and Wi-Fi Direct functionalities. The Wi-Fi related operations are provided by classes like WifiManager and WifiSecurityInfo.
  * The Wi-Fi Direct related operations are provided by classes like WifiDirectDevice.
  *
  * For more information on the %Wifi namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a> and <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
  *
  * The following diagram illustrates the relationships between the Wi-Fi classes belonging to the %Wifi namespace.
  * @image html net_wi-fi_using_the_apis_classdiagram.png
  *
  * The following diagram illustrates the relationships between the Wi-Fi Direct classes belonging to the %Wifi namespace.
  * @image html net_wi-fi_direct_using_the_apis_classdiagram.png
  *
  */
namespace Wifi
{

} } } // Tizen::Net::Wifi

#endif // _FNET_WIFI_H_
