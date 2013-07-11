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
 * @file        FNetBtBluetoothDevice.h
 * @brief       This is the header file for the %BluetoothDevice class.
 *
 * This header file contains the declarations of the %BluetoothDevice class.
 */
#ifndef _FNET_BT_BLUETOOTH_DEVICE_H_
#define _FNET_BT_BLUETOOTH_DEVICE_H_

#include <FNetBtBluetoothTypes.h>
#include <FBaseResult.h>
#include <FBaseObject.h>

// forward declarations
namespace Tizen { namespace Base
{
class ByteBuffer;
class String;
namespace Collection
{
class IList;
}
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declarations
class _BluetoothDeviceImpl;

/**
 * @class   BluetoothDevice
 * @brief   This class provides information about a remote %Bluetooth device.
 * @since   2.0
 *
 * The %BluetoothDevice class provides information about a remote %Bluetooth device.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothDevice
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	BluetoothDevice(void);

	/**
	 * @if OSPDEPREC
	 * Initializes an instance of %BluetoothDevice with the specified parameters.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This constructor is deprecated because most of the information is generated internally.
	 *              Therefore, creating a %BluetoothDevice instance directly by the application is not recommended.
	 *              Instead of using this method for copying an instance, the copy constructor is recommended.
	 * @since       2.0
	 *
	 * @param[in]   address                 The %Bluetooth device address
	 * @param[in]   deviceName              The name of the device
	 * @param[in]   majorClassType          The major class type of a %Bluetooth device
	 * @param[in]   minorClassType          The minor class type of a %Bluetooth device
	 * @param[in]   serviceClassList        The service class type list
	 * @param[in]   serviceList             The service type list
	 * @remarks     The @c serviceClassList parameter consists of Bluetooth::BluetoothServiceClassType values, which are
	 *              joined by the logical OR operator. @n
	 *              The @c serviceList parameter consists of Bluetooth::BluetoothServiceType values which are joined by the
	 *              logical OR operator.
	 * @endif
	 */
	BluetoothDevice(const Tizen::Base::ByteBuffer& address, const Tizen::Base::String& deviceName, BluetoothMajorDeviceClassType majorClassType, BluetoothMinorDeviceClassType minorClassType, unsigned long serviceClassList, unsigned long serviceList);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]   value                   An instance of %BluetoothDevice
	 */
	BluetoothDevice(const BluetoothDevice& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~BluetoothDevice(void);

	/**
	 * Gets the address of a %Bluetooth device which consists of 6 bytes.
	 *
	 * @since       2.0
	 *
	 * @return      The address of a %Bluetooth device
	 */
	const Tizen::Base::ByteBuffer* GetAddress(void) const;

	/**
	 * Sets the address of a %Bluetooth device.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   address                 An address of the %Bluetooth device
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified address is invalid @n
	 *                                      The size of the address should be 6 bytes.
	 * @remarks     @c address must have 6 byte data (remaining elements). @n
	 *              Setting the address of the %BluetoothDevice instance which is obtained from the paired list does not
	 *              affect the information of the paired list in the system.
	 */
	result SetAddress(const Tizen::Base::ByteBuffer& address);

	/**
	 * Gets the %Bluetooth device name.
	 *
	 * @since       2.0
	 *
	 * @return      The %Bluetooth device name
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Checks whether this device is paired with the local device.
	 *
	 * @since 2.0
	 *
	 * @return      @c true if this device is paired with the local device, @n
	 *              else @c false
	 */
	bool IsPaired(void) const;

	/**
	 * Gets the Received Signal Strength Indication (RSSI) value of a device at the time of device discovery (scan).
	 *
	 * @since 2.0
	 *
	 * @return      The RSSI value in dBm
	 */
	int GetRssi(void) const;

	/**
	 * Gets the major device class.
	 *
	 * @since       2.0
	 *
	 * @return      The major device class
	 */
	BluetoothMajorDeviceClassType GetMajorDeviceClassType(void) const;

	/**
	 * Gets the minor device class.
	 *
	 * @since       2.0
	 *
	 * @return      The minor device class
	 */
	BluetoothMinorDeviceClassType GetMinorDeviceClassType(void) const;

	/**
	 * Gets the service class of the %Bluetooth device. @n
	 * This service class list consists of Bluetooth::BluetoothServiceClassType values, which are joined by the logical OR
	 * operator.
	 *
	 * @since       2.0
	 *
	 * @return      The service class of the device
	 * @remarks     This operation is not supported in the local device acquired by BluetoothManager::GetLocalDevice().
	 */
	unsigned long GetServiceClassList(void) const;

	/**
	 * Gets the %Bluetooth device service list. @n
	 * This service list consists of Bluetooth::BluetoothServiceType values, which are joined by the logical OR operator.
	 *
	 * @since       2.0
	 *
	 * @return      The %Bluetooth device service list
	 * @remarks     This operation is not supported in the local device acquired by BluetoothManager::GetLocalDevice().
	 */
	unsigned long GetServiceList(void) const;

	/**
	 * Gets the %Bluetooth device service UUID list. @n
	 * This service list consists of Tizen::Base::UuId instances that represent service UUIDs that the device supports.
	 *
	 * @since 2.0
	 *
	 * @return      The %Bluetooth device service UUID list
	 * @remarks     This operation returns @c null, if it is called in the local device acquired by
	 *              BluetoothManager::GetLocalDevice().
	 */
	const Tizen::Base::Collection::IList* GetServiceUuidList(void) const;

	/**
	 * Compares the calling instance with the specified instance.
	 *
	 * @since       2.0
	 * @return      @c true if both the instances are equal, @n
	 *              else @c false
	 * @param[in]   obj                    The object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since       2.0
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets a new instance of %BluetoothDevice generated using the result of the %Bluetooth AppControl.
	 *
	 * @since       2.0
	 * @return      The %Bluetooth device containing the specified information extracted from the input data if successful,
	 * @n
	 *              else @c null
	 * @param[in]   appControlResult        The data list, which is the result of the %Bluetooth AppControl
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c appControlResult contains an invalid value. @n
	 *                                      The result of %Bluetooth AppControl is only permitted to be used as an input
	 *                                      argument.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	static BluetoothDevice* GetInstanceFromAppControlResultN(const Tizen::Base::Collection::IList& appControlResult);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return      A reference to the %BluetoothDevice instance
	 * @param[in]   rhs                     A reference to the %BluetoothDevice instance to copy
	 */
	BluetoothDevice& operator =(const BluetoothDevice& rhs);

private:
	_BluetoothDeviceImpl* __pImpl;

	friend class _BluetoothDeviceImpl;

}; // BluetoothDevice

} } }
#endif // _FNET_BT_BLUETOOTH_DEVICE_H_
