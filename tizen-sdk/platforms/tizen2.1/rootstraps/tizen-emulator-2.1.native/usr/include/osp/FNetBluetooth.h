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
 * @file        FNetBluetooth.h
 * @brief       This is the header file for the %Bluetooth namespace.
 *
 * This header file contains the declarations and descriptions of the %Bluetooth namespace.
 */
#ifndef _FNET_BLUETOOTH_H_
#define _FNET_BLUETOOTH_H_

#include <FNetBtBluetoothTypes.h>
#include <FNetBtBluetoothDevice.h>
#include <FNetBtBluetoothManager.h>
#include <FNetBtIBluetoothDeviceEventListener.h>
#include <FNetBtIBluetoothManagerEventListener.h>
#include <FNetBtBluetoothOppServer.h>
#include <FNetBtIBluetoothOppServerEventListener.h>
#include <FNetBtBluetoothOppClient.h>
#include <FNetBtIBluetoothOppClientEventListener.h>
#include <FNetBtBluetoothSppAcceptor.h>
#include <FNetBtIBluetoothSppAcceptorEventListener.h>
#include <FNetBtBluetoothSppInitiator.h>
#include <FNetBtIBluetoothSppInitiatorEventListener.h>
#include <FNetBtBluetoothHealth.h>
#include <FNetBtIBluetoothHealthEventListener.h>

namespace Tizen { namespace Net
{
/**
 * @namespace   Tizen::Net::Bluetooth
 * @brief       This namespace contains the classes and interfaces for %Bluetooth services.
 * @since       2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *              @b Library : @b osp-bluetooth @n
 *
 * The %Bluetooth namespace contains the classes and interfaces for %Bluetooth services that provide the mechanisms for
 * peer-to-peer communication involving connecting, sending, and receiving data over a %Bluetooth connection. It
 * consists of the submodules that support different profiles such as GAP, OPP, and SPP.
 * @n
 * For more information on the %Bluetooth namespace features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes within the %Bluetooth namespace.
 * @image html net_bluetooth_using_the_apis_classdiagram.png
 *
 */
namespace Bluetooth
{
} } } // Tizen::Net::Bluetooth
#endif // _FNET_BLUETOOTH_H_
