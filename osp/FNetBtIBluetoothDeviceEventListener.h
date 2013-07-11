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
 * @file    FNetBtIBluetoothDeviceEventListener.h
 * @brief   This is the header file for the %IBluetoothDeviceEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothDeviceEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_DEVICE_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_DEVICE_EVENT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declaration
class BluetoothDevice;

/**
 * @interface   IBluetoothDeviceEventListener
 * @brief       This interface implements the listener for %Bluetooth remote device events.
 *
 * @since       2.0
 *
 * The %IBluetoothDeviceEventListener interface specifies the methods used to create notifications for the different
 * kinds of %Bluetooth remote device events, including device discovery, service discovery, and pairing of the devices.
 * When a %Bluetooth device event is generated, one of these methods is called.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothDeviceEventListener
	: public Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IBluetoothDeviceEventListener(void) {}

	/**
	 * Called when the device discovery process for finding the nearby %Bluetooth devices has started.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r                   The start status
	 * @exception   E_SUCCESS           The device discovery process is launched successfully.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         BluetoothManager::StartDiscovery()
	 */
	virtual void OnBluetoothDiscoveryStarted(result r) = 0;

	/**
	 * Called when a remote device is found during the device discovery process.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pFoundDevice        The remote device that is found
	 * @remarks     This event may be issued only if the device discovery process has started successfully.
	 * @see         BluetoothManager::StartDiscovery()
	 */
	virtual void OnBluetoothRemoteDeviceFoundN(BluetoothDevice* pFoundDevice) = 0;

	/**
	 * Called when the device discovery process for finding the nearby %Bluetooth devices has completed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   isCompleted         Set to @c true if the device discovery process is successfully completed, @n
	 *                                  else @c false @n
	 *                                  For example, the discovery is canceled.
	 * @remarks     This event must be issued only if the discovery starts successfully.
	 * @see         BluetoothManager::CancelDiscovery()
	 */
	virtual void OnBluetoothDiscoveryDone(bool isCompleted) = 0;

	/**
	 * Called when a service list is received from a remote device using the service discovery process.
	 *
	 * @since       2.0
	 *
	 * @param[in]   targetDevice                The remote device that sends its service list
	 * @param[in]   serviceList                 The service list that is received
	 * @param[in]   r                           The result of receiving the service list
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_REMOTE_SERVICE_NOT_FOUND  The service list of the remote device is not found.
	 * @exception   E_SYSTEM                    A system error has occurred.
	 * @remarks     @c serviceList consists of Bluetooth::BluetoothServiceType values which are joined by OR
	 *              operator.
	 */
	virtual void OnBluetoothServiceListReceived(const BluetoothDevice& targetDevice, unsigned long serviceList, result r) = 0;

	/**
	 * Called when a new remote device is paired with this local device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pairedDevice      The device to pair with the local device
	 * @remarks     This method is able to be called even though the specified device already exists in the paired
	 *              device list. Because the authorized key with the remote device is no more valid. @n
	 *              @c pairedDevice may have no service list value and elements in the service UUID list because the
	 *              retrieving the service list from the remote device fails. In that case, call
	 *              BluetoothManager::RetrieveServiceList() to get the service list from the paired device. @n
	 *              If the pairing is explicitly requested by BluetoothManager::Pair() and the request fails,
	 *              IBluetoothDeviceEventListener::OnBluetoothPairingFailed() is called instead of this method.
	 * @see         BluetoothManager::Pair()
	 * @see         OnBluetoothPairingFailed()
	 */
	virtual void OnBluetoothPaired(const BluetoothDevice& pairedDevice) = 0;

	/**
	 * Called when the already paired device is unpaired with this local device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   unpairedDevice      The device to unpair with the local device
	 */
	virtual void OnBluetoothUnpaired(const BluetoothDevice& unpairedDevice) = 0;

	/**
	 * Called when the pairing request with the specific remote device fails.
	 *
	 * @since 2.0
	 *
	 * @param[in]   r                           The error result of the pairing request. @n
	 *                                          One of the following exception is thrown.
	 * @exception   E_OPERATION_CANCELED        The pairing operation is canceled explicitly.
	 * @exception   E_TIMEOUT                   The pairing request has timed out because the remote device does not
	 *                                          respond within 60 seconds.
	 * @exception   E_OPERATION_FAILED          The operation has failed.
	 * @see         BluetoothManager::Pair()
	 * @see         BluetoothManager::CancelPair()
	 * @see         OnBluetoothPaired()
	 */
	virtual void OnBluetoothPairingFailed(result r) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IBluetoothDeviceEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IBluetoothDeviceEventListener_Reserved2(void) {}

	//
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IBluetoothDeviceEventListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IBluetoothDeviceEventListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IBluetoothDeviceEventListener_Reserved5(void) {}
}; // IBluetoothDeviceEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_DEVICE_EVENT_LISTENER_H_
