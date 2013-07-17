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
 * @file    FNetBtBluetoothManager.h
 * @brief   This is the header file for the %BluetoothManager class.
 *
 * This header file contains the declarations of the %BluetoothManager class.
 */
#ifndef _FNET_BT_BLUETOOTH_MANAGER_H_
#define _FNET_BT_BLUETOOTH_MANAGER_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetBtBluetoothTypes.h>

namespace Tizen { namespace Base
{
class String;
class ByteBuffer;
namespace Collection
{
class IList;
}
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declarations
class BluetoothDevice;
class IBluetoothManagerEventListener;
class IBluetoothDeviceEventListener;
class _BluetoothManagerImpl;

/**
 * @class   BluetoothManager
 * @brief   This class is used to obtain information about the local device or the paired devices, and to configure
 *          the %Bluetooth stack.
 * @since   2.0
 *
 * The %BluetoothManager class is used to obtain information about the local device or the paired devices and to configure the
 * %Bluetooth stack.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothManager
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct()
	 * method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 */
	BluetoothManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~BluetoothManager(void);

	/**
	 * Constructs and initializes an instance of the %BluetoothManager class with the specified listener.
	 *
	 * @since       2.0
	 * @feature     %http://tizen.org/feature/network.bluetooth
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to handle the %BluetoothManager event
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(IBluetoothManagerEventListener& listener);

	/**
	 * Activates %Bluetooth on a device.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.admin
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The %Bluetooth activation process is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, %Bluetooth is already activated.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         IBluetoothManagerEventListener::OnBluetoothActivated()
	 */
	result Activate(void);

	/**
	 * Deactivates %Bluetooth on a device.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.admin
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The %Bluetooth deactivation process is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the %Bluetooth is already deactivated.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         IBluetoothManagerEventListener::OnBluetoothDeactivated()
	 */
	result Deactivate(void);

	/**
	 * @if OSPDEPREC
	 * Checks whether a %Bluetooth-specific profile is available.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because multiple clients as well as multiple SPP servers with unique
	 *              service UUIDs are supported. In case of OPP server, invoke
	 *              BluetoothOppServer::StartService() directly without checking OPP server's availability.
	 *              If a new OPP server is not available, the method returns the E_SERVICE_UNAVAILABLE exception.
	 * @since       2.0
	 *
	 * @return      @c true if the specified type of connection is available, @n
	 *              else @c false
	 * @param[in]   type                    The connection type
	 *
	 * @endif
	 */
	bool IsAvailable(BluetoothConnectionType type) const;

	/**
	 * @if OSPDEPREC
	 * Gets the local device information.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because the return value of this method is a dangling pointer if this
	 *              instance of %BluetoothManager is deleted. In addition to this, the %BluetoothDevice class
	 *              represents only remote devices since Tizen. Instead of using this method, the GetLocalDeviceAddress()
	 *              and GetLocalDeviceName() methods are recommended.
	 * @since       2.0
	 *
	 * @return      The local device information
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	const BluetoothDevice* GetLocalDevice(void) const;

	/**
	 * Gets the local %Bluetooth device address.
	 *
	 * @since       2.0
	 *
	 * @return      The local %Bluetooth device address @n
	 *              The address is expressed as a @c 6 byte hexadecimal value delimited by colons. @n
	 *              For example, "00:3D:47:EF:8A:03".
	 */
	Tizen::Base::String GetLocalDeviceAddress(void) const;

	/**
	 * Gets the local %Bluetooth device name.
	 *
	 * @since       2.0
	 *
	 * @return      The local %Bluetooth device name
	 */
	Tizen::Base::String GetLocalDeviceName(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the operational mode of the %Bluetooth unit.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  %BluetoothDeviceStateType is deprecated. Therefore, this method is also deprecated, because the
	 *              return value of this method is of type %BluetoothDeviceStateType. Instead of using this method, the
	 *              IsActivated() and GetDiscoverableMode() methods are recommended.
	 *
	 * @since       2.0
	 *
	 * @return      The operational mode
	 * @endif
	 */
	BluetoothDeviceStateType GetLocalDeviceState(void) const;

	/**
	 * Checks whether the local %Bluetooth is activated.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the local %Bluetooth is activated, @n
	 *              else @c false
	 */
	bool IsActivated(void) const;

	/**
	 * Gets the discoverable mode of the local device.
	 *
	 * @since       2.0
	 * @return      The discoverable mode of the local device
	 */
	BluetoothDiscoverableMode GetDiscoverableMode(void) const;

	/**
	 */

	/**
	 * Gets the remaining time, in seconds, until the discoverable mode is changed from
	 * ::BT_DISC_MODE_TIME_LIMITED_DISCOVERABLE to be ::BT_DISC_MODE_NOT_DISCOVERABLE. @n
	 * The %GetRemainingTimeAsDiscoverable() method is valid only if the current discoverable mode is @c
	 * BT_DISC_MODE_TIME_LIMITED_DISCOVERABLE.
	 *
	 * @since 2.0
	 *
	 * @return      The remaining time, in seconds, until the local device is not discoverable @n
	 *              @c 0 is returned if the current discoverable mode is not ::BT_DISC_MODE_TIME_LIMITED_DISCOVERABLE.
 	 */
	int GetRemainingTimeAsDiscoverable(void) const;

	/**
	 * Checks whether the device discovery is in progress.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the device discovery is in progress, @n
	 *              else @c false
	 */
	bool IsDiscoveryInProgress(void) const;

	/**
	 * Sets a name of the local device. @n
 	 * The searching device detects the local devices in close proximity based on the specified device name, and the
 	 * name is only valid while an application is active.
 	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.admin
	 *
	 * @return      An error code
	 * @param[in]   deviceName              The new device name @n
	 *                                      The specified device name is automatically truncated if its size is greater
	 *                                      than @c 64 bytes.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified device name is an empty string.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     This method does not affect the system settings.
	 */
	result SetLocalDeviceName(const Tizen::Base::String& deviceName);

	/**
	 * Sets the discoverable mode of the local device.
	 *
	 * @since 2.0
	 * @privlevel   platform
	 * @privilege   %http://tizen.org/privilege/bluetoothmanager
	 *
	 * @return      An error code
	 * @param[in]   mode                    The new discoverable mode
	 * @param[in]   seconds                 The duration in seconds for which the local device is discoverable @n
	 *                                      The specified duration is adopted only if the specified @c mode is
	 *                                      @c BT_DISC_MODE_TIME_LIMITED_DISCOVERABLE.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c seconds should be greater than 0 if the specified @c mode
	 *                                      is @c BT_DISC_MODE_TIME_LIMITED_DISCOVERABLE.
	 * @exception   E_INVALID_OPERATION     %Bluetooth is not activated.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         IBluetoothManagerEventListener::OnBluetoothDiscoverableModeChanged()
	 */
	result SetDiscoverableMode(BluetoothDiscoverableMode mode, int seconds = 0);

	/**
	 * @if OSPDEPREC
	 * Refreshes the paired device list.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because the paired device list of this instance of %BluetoothManager is
	 *              refreshed automatically. An application should not call this method to refresh the list.
	 * @since       2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @endif
	 */
	result RefreshPairedDeviceList(void);

	/**
	 * @if OSPDEPREC
	 * Searches for an element that matches a %Bluetooth address.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because the return value of this method is a dangling pointer, if this
	 *              instance of %BluetoothManager is deleted. In addition to this, it is also an invalid pointer if the
	 *              paired device list is updated internally. Instead of using this method, GetPairedDeviceByAddressN()
	 *              is recommended.
	 * @since       2.0
	 *
	 * @return      The instance of %BluetoothDevice containing the specified address, @n
	 *              else @c null if the search is not successful
	 * @param[in]   deviceAddress           The address to locate
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The specified device is not found in the paired device list.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	const BluetoothDevice* GetPairedDeviceByAddress(const Tizen::Base::ByteBuffer& deviceAddress) const;

	/**
	 * Gets an element that matches a %Bluetooth address.
	 *
	 * @since       2.0
	 *
	 * @return      The instance of %BluetoothDevice containing the specified address, @n
	 *              else @c null if the search is not successful
	 * @param[in]   deviceAddress           The address to locate
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The specified device is not found in the paired device list.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	BluetoothDevice* GetPairedDeviceByAddressN(const Tizen::Base::ByteBuffer& deviceAddress) const;

	/**
	 * Gets the elements matching a device name in the paired device list.
	 *
	 * @since       2.0
	 *
	 * @return      A list containing the matching devices, @n
	 *              else @c null if the search is not successful
	 * @param[in]   deviceName              The name of the device to locate
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The specified device is not found in the paired device list.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetPairedDeviceByNameN(const Tizen::Base::String& deviceName) const;

	/**
	 * @if OSPDEPREC
	 * Gets the element at the specified index.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because the return value of this method is a dangling pointer, if this
	 *              instance of %BluetoothManager is deleted. In addition to this, it is also an invalid pointer if the
	 *              paired device list is updated internally. Instead of using this method, GetPairedDeviceListN() and
	 *              Tizen::Base::Collection::IList::GetAt() are recommended.
	 * @since       2.0
	 *
	 * @return      The instance of %BluetoothDevice at the specified index, @n
	 *              else @c null if there is no element
	 * @param[in]   index                   The index in the list
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The specified index is not found in the paired device list.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	const BluetoothDevice* GetPairedDeviceAt(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the paired device list.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because the return value of this method is a dangling pointer, if this
	 *              instance of %BluetoothManager is deleted. In addition to this, some elements of the list may also
	 *              be invalid pointers if the paired device list is updated internally. Instead of using this method,
	 *              GetPairedDeviceListN() is recommended.
	 * @since       2.0
	 *
	 * @return      A pointer to the paired device list on success, @n
	 *              else @c null
	 * @exception   E_SUCCESS               The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	const Tizen::Base::Collection::IList* GetPairedDeviceList(void) const;

	/**
	 * Gets the paired device list.
	 *
	 * @since       2.0
	 *
	 * @return      A pointer to the paired device list on success, @n
	 *              else @c null
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetPairedDeviceListN(void) const;

	/**
	 * Sets a remote device event listener for searching devices and services.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   pListener               The device event listener to set @n
	 *                                      If the specified listener is @c null, the listener currently set is
	 *                                      unregistered.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     Only one event listener can be set.
	 */
	result SetBluetoothDeviceListener(IBluetoothDeviceEventListener* pListener);

	/**
	 * Starts the device discovery process.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.gap
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The device discovery process is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this
	 *                                      operation.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         IBluetoothDeviceEventListener::OnBluetoothDiscoveryStarted()
	 * @see         IBluetoothDeviceEventListener::OnBluetoothRemoteDeviceFoundN()
	 * @see         IBluetoothDeviceEventListener::OnBluetoothDiscoveryDone()
	 */
	result StartDiscovery(void);

	/**
	 * Cancels the device discovery process.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.gap
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The termination of the device discovery process is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this
	 *                                      operation. @n
	 *                                      For example, the discovery has not started as yet.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         IBluetoothDeviceEventListener::OnBluetoothDiscoveryDone()
	 */
	result CancelDiscovery(void);

	/**
	 * Retrieves the service list from a remote device.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.gap
	 *
	 * @return      An error code
	 * @param[in]   pairedDevice            A remote device that is already paired with the local device
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The retrieving is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this
	 *                                      operation. @n
	 *                                      For example, the discovery is in progress.
	 * @exception   E_NOT_PAIRED            The input device is not found in the paired device list.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     The target remote device should be a paired device.
	 * @see         IBluetoothDeviceEventListener::OnBluetoothServiceListReceived()
	 */
	result RetrieveServiceList(const BluetoothDevice& pairedDevice);

	/**
	 * Pairs with the specified remote device.
	 *
	 * @since 2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.gap
	 *
	 * @return      An error code
	 * @param[in]   remoteDevice            The remote %Bluetooth device to pair with
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this
	 *                                      operation. @n
	 *                                      For example, the %Bluetooth is not activated.
	 * @exception   E_DEVICE_BUSY           The device cannot be approached because other operation is in progress.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     IBluetoothDeviceEventListener::OnBluetoothPaired() is called if the pairing is successful, @n
	 *              IBluetoothDeviceEventListener::OnBluetoothPairingFailed() if the pairing has failed.
	 */
	result Pair(const BluetoothDevice& remoteDevice);

	/**
	 * Stops the pairing process.
	 *
	 * @since 2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.gap
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this
	 *                                      operation. @n
	 *                                      For example, the pairing process is not in progress.
	 * @exception   E_IN_PROGRESS           The termination of the pairing process is in progress.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     If the canceling of the pairing process is successful, @n
	 *              IBluetoothDeviceEventListener::OnBluetoothPairingFailed() is called with @c E_OPERATION_CANCELED.
	 */
	result CancelPair(void);

	/**
	 * Unpairs with a paired device. @n
	 * The process of unpairing is to remove a specified device from the paired device list. No notification is
	 * transmitted to the remote device. @n
	 * The %Unpair() method is synchronous. Only when the result of this method is @c E_SUCCESS, the unpaired event is fired.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.gap
	 *
	 * @return      An error code
	 * @param[in]   pairedDevice            The paired device to unpair
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of this
	 *                                      operation. @n
	 *                                      For example, the %Bluetooth is not activated, or retrieving the service
	 *                                      list is in progress.
	 * @exception   E_NOT_PAIRED            The input device is not found in the paired device list.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         IBluetoothDeviceEventListener::OnBluetoothUnpaired()
	 */
	result Unpair(const BluetoothDevice& pairedDevice);

private:
	//
	// The implementation of this copy constructor is intentionally blank to prohibit copying of objects.
	//
	BluetoothManager(const BluetoothManager& value);

	//
	// The implementation of this copy assignment operator is intentionally blank to prohibit copying of objects.
	//
	BluetoothManager& operator =(const BluetoothManager& value);

private:
	_BluetoothManagerImpl* __pImpl;

	friend class _BluetoothManagerImpl;

}; // BluetoothManager

} } }
#endif // _FNET_BT_BLUETOOTH_MANAGER_H_
