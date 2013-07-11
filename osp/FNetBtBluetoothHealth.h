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
 * @file    FNetBtBluetoothHealth.h
 * @brief   This is the header file for the %BluetoothHealth class.
 *
 * This header file contains the declarations of the %BluetoothHealth class.
 */
#ifndef _FNET_BT_BLUETOOTH_HEALTH_H_
#define _FNET_BT_BLUETOOTH_HEALTH_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetBtBluetoothTypes.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

class BluetoothDevice;
class IBluetoothHealthEventListener;
class _BluetoothHealthImpl;

/**
 * @class   BluetoothHealth
 * @brief   This class provides the methods to handle the %Bluetooth Health Device Profile (HDP), such as the
 *          establishing a connection and exchanging data through the data channel.
 * @since 2.0
 *
 * @final   This class is not intended for extension.
 *
 * This %BluetoothHealth class provides the methods to handle the %Bluetooth Health Device Profile (HDP), which is a
 * profile that defines the requirements for qualified %Bluetooth healthcare and fitness (referred to as 'health')
 * device implementations. @n
 * This class allows Sink device such as mobile phone to establish a connection and exchange data to Source devices
 * such as blood pressure monitors, weight scales, glucose meters, thermometers, and pulse oximeters.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothHealth
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct()
	 * method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	BluetoothHealth(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~BluetoothHealth(void);

	/**
	 * Constructs an instance of %BluetoothHealth with the specified listener.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   listener                The event listener for the %BluetoothHealth. @n
	 *                                      Listener must be allocated at heap, not stack.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	The device does not support the %Bluetooth feature.
	 * @exception   E_OPERATION_FAILED      The method has failed.
	 */
	result Construct(IBluetoothHealthEventListener& listener);

	/**
	 * Starts %Bluetooth health as a role of sink with the specified data type.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.health
	 *
	 * @return      An error code
	 * @param[in]   dataType                The type of data used in communication which is defined in ISO/IEEE
	 *                                      11073-20601 and represents type of health device such as thermometer,
	 *                                      heart rate monitor, weight scale, and so on
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         %Bluetooth is not activated.
	 * @exception   E_IN_PROGRESS           The sink role with the specified data type has already started.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the sink role already started with another data type.
	 * @exception   E_SERVICE_UNAVAILABLE   The sink role with the specified data type is currently busy with another
	 *                                      instance or application.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_OPERATION_FAILED      The method has failed.
	 * @remarks     One %BluetoothHealth instance supports only a sink role with the specific data type at one time and
	 *              only one sink role for the specific data type can be enabled system-widely. For providing sink
	 *              roles with various data types, make multiple %BluetoothHealth instances with different data types.
	 */
	result StartAsSink(int dataType);

	/**
	 * Stops %Bluetooth health as a role of sink. @n
	 * This method disconnects all established channels before stop.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.health
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the sink role is not started yet.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_OPERATION_FAILED      The method has failed.
	 */
	result Stop(void);

	/**
	 * Connects to a new channel with a remote health device which has source role. @n
	 * This method establishes a channel after the source device accepts the request.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.health
	 *
	 * @return      An error code
	 * @param[in]   remoteDevice            The remote device to connect
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the sink role is not started yet.
	 * @exception   E_DEVICE_BUSY           The pairing and connection process is in progress.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_OPERATION_FAILED      The method has failed.
	 * @see         IBluetoothHealthEventListener::OnHealthConnected()
	 * @remarks     If the local device is not paired with the specified target device, the pairing process starts
	 *              internally before the connect request is sent.
	 */
	result ConnectToSource(const BluetoothDevice& remoteDevice);

	/**
	 * Disconnects the connection which has the specified channel ID. @n
	 * After calling this method, the IBluetoothHealthEventListener::OnHealthDisconnected() is called regardless of
	 * whether this method is called during connection or before connection is established.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.health
	 *
	 * @return      An error code
	 * @param[in]   channelId               The ID of the specified channel to disconnect
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, there is no connection with the specified channel ID.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_OPERATION_FAILED      The method has failed.
	 * @see         IBluetoothHealthEventListener::OnHealthDisconnected()
	 * @remarks     @c channelId value can be obtained by IBluetoothHealthEventListener::OnHealthConnected() after the
	 *              specific channel is established.
	 */
	result Disconnect(int channelId);

	/**
	 * Sends the specified data on the specified channel.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.health
	 *
	 * @return      An error code
	 * @param[in]   channelId               The ID of the specified channel on which the data is sent
	 * @param[in]   buffer                  The data to send
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, there is no connection with the specified channel ID.
	 * @exception   E_INVALID_ARG           The input buffer has no data.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_OPERATION_FAILED      The operation has failed.
	 * @see         IBluetoothHealthEventListener::OnHealthDataReceived()
	 * @remarks     @c channelId value can be obtained by IBluetoothHealthEventListener::OnHealthConnected() after the
	 *              specific channel is established.
	 */
	result SendData(int channelId, const Tizen::Base::ByteBuffer& buffer);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying
	// of objects.
	//
	BluetoothHealth(const BluetoothHealth& value);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	// copying of objects.
	//
	BluetoothHealth& operator =(const BluetoothHealth& rhs);

private:
	_BluetoothHealthImpl* __pImpl;

}; // BluetoothHealth

} } }
#endif // _FNET_BT_BLUETOOTH_HEALTH_H_
