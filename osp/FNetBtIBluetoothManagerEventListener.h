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
 * @file    FNetBtIBluetoothManagerEventListener.h
 * @brief   This is the header file for the %IBluetoothManagerEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothManagerEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_MANAGER_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_MANAGER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetBtBluetoothTypes.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

/**
 * @interface   IBluetoothManagerEventListener
 * @brief       This interface implements the listener for the %BluetoothManager events.
 *
 * @since       2.0
 *
 * The %IBluetoothManagerEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothManager events. When a BluetoothManager event is generated, one of these methods is
 * called.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothManagerEventListener
	: public Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IBluetoothManagerEventListener(void) {}

	/**
	 * Called when %Bluetooth is activated on the device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r               The activation status
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	virtual void OnBluetoothActivated(result r) = 0;

	/**
	 * Called when %Bluetooth is deactivated on the device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r               The deactivation status
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	virtual void OnBluetoothDeactivated(result r) = 0;

	/**
	 * Called when the discoverable mode is changed on the device.
	 *
	 * @since 2.0
	 *
	 * @param[in]   mode            The new discoverable mode to change
	 */
	virtual void OnBluetoothDiscoverableModeChanged(BluetoothDiscoverableMode mode) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothManagerEventListener_Reserved1(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothManagerEventListener_Reserved2(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothManagerEventListener_Reserved3(void) {};
}; // IBluetoothManagerEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_MANAGER_EVENT_LISTENER_H_
