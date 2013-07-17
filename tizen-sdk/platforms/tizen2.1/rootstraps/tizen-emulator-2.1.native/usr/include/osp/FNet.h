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
 * @file		FNet.h
 * @brief		This is the header file for the %Net namespace.
 *
 * This header file contains the declarations and descriptions of the %Net namespace.
 */

#ifndef _FNET_H_
#define _FNET_H_

#include <FNetNetTypes.h>
#include <FNetIpAddress.h>
#include <FNetIp4Address.h>
#include <FNetNetEndPoint.h>
#include <FNetNetAccountInfo.h>
#include <FNetNetAccountManager.h>
#include <FNetNetConnectionInfo.h>
#include <FNetINetConnectionEventListener.h>
#include <FNetNetConnection.h>
#include <FNetIManagedNetConnectionEventListener.h>
#include <FNetManagedNetConnection.h>
#include <FNetNetConnectionManager.h>
#include <FNetNetStatistics.h>
#include <FNetIpHostEntry.h>
#include <FNetIDnsEventListener.h>
#include <FNetDns.h>
#include <FNetDhcpClientInfo.h>
#include <FNetILocalDhcpServerEventListener.h>
#include <FNetLocalDhcpServer.h>

#include <FNetSockets.h>
#include <FNetHttp.h>
#include <FNetWifi.h>
#ifndef _EXCEPT_DEPENDENCY_
#include <FNetBluetooth.h>
#include <FNetNfc.h>
#endif

namespace Tizen
{
/**
 * @namespace	Tizen::Net
 * @brief		This namespace contains the classes and interfaces for network account, connection, and addressing utilities.
 * @since 2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *				@b Library : @b osp-net @n
 *
 * The %Net namespace contains the different classes for the %Net namespace. @n
 *
 * This namespace helps to access the data communication capabilities of Tizen. It is responsible for managing connections and
 *				accounts, and maintaining IP addresses and connections to the system through %Bluetooth, Hypertext Transfer Protocol (HTTP), Near Field
 *				Communication (NFC), %Sockets, and Wi-Fi. It also provides methods for retrieving information about a specific host from the Internet Domain
 *				Name %System (DNS).
 * @n
 * For more information on the %Net namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/net/net_namespace.htm">Net Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Net namespace.
 * @image html net_using_the_apis_classdiagram.png
 *
 */
namespace Net
{
} } // Tizen::Net
#endif // _FNET_H_
