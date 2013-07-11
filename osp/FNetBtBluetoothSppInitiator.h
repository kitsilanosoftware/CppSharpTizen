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
 * @file    FNetBtBluetoothSppInitiator.h
 * @brief   This is the header file for the %BluetoothSppInitiator class.
 *
 * This header file contains the declarations of the %BluetoothSppInitiator class.
 */
#ifndef _FNET_BT_BLUETOOTH_SPP_INITIATOR_H_
#define _FNET_BT_BLUETOOTH_SPP_INITIATOR_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseUuId.h>
#include <FNetBtBluetoothTypes.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declarations
class BluetoothDevice;
class IBluetoothSppInitiatorEventListener;
class _BluetoothSppInitiatorImpl;

/**
 * @class   BluetoothSppInitiator
 * @brief   This class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) initiator, such as the
 *          outgoing connection requests.
 * @since   2.0
 *
 * The %BluetoothSppInitiator class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) initiator, such as
 * the outgoing connection requests.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothSppInitiator
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct()
	 * method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 */
	BluetoothSppInitiator(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~BluetoothSppInitiator(void);

	/**
	 * Constructs and initializes this instance of %BluetoothSppInitiator with the specified listener.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   listener                The event listener for the SPP initiator
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result Construct(IBluetoothSppInitiatorEventListener& listener);

	/**
	 * Connects to a remote SPP acceptor with the default service UUID - BT_SVC_UUID_SPP. @n
	 * This method establishes a connection after the SPP acceptor accepts the request.
	 *
	 * @since       2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.spp
	 *
	 * @return      An error code
	 * @param[in]   remoteDevice                The remote device to connect
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
	 *                                          For example, this instance has not been constructed as yet or
	 *                                          %Bluetooth is not activated.
	 * @exception   E_IN_PROGRESS               The connection process is in progress.
	 * @exception   E_ALREADY_CONNECTED         The connection with an SPP acceptor has already been established.
	 * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
	 * @exception   E_SERVICE_UNAVAILABLE       The SPP connection is unavailable.
	 * @exception   E_REMOTE_DEVICE_NOT_FOUND   The input device is not found. @n
	 *                                          This exception is currently not in use.
	 * @exception   E_FAILURE                   The method has failed.
	 * @see         IBluetoothSppAcceptorEventListener::OnSppConnectionRequested()
	 * @remarks     If the local device is not paired with the specified target device, the pairing process starts
	 *              internally before the connect request is sent.
	 */
	result Connect(const BluetoothDevice& remoteDevice);

	/**
	 * Connects to a remote SPP acceptor with the specified service UUID. @n
	 * This method establishes a connection after the SPP acceptor accepts the request.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.spp
	 *
	 * @return      An error code
	 * @param[in]   remoteDevice                The remote device to connect
	 * @param[in]   serviceUuid                 The UUID of SPP service to connect
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
	 *                                          For example, this instance has not been constructed as yet or
	 *                                          %Bluetooth is not activated.
	 * @exception   E_INVALID_ARG               A specified input parameter is invalid.
	 * @exception   E_IN_PROGRESS               The connection process is in progress.
	 * @exception   E_ALREADY_CONNECTED         The connection with an SPP acceptor has already been established.
	 * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
	 * @exception   E_SERVICE_UNAVAILABLE       The SPP connection is unavailable.
	 * @exception   E_REMOTE_DEVICE_NOT_FOUND   The input device is not found. @n
	 *                                          This exception is currently not in use.
	 * @exception   E_FAILURE                   The method has failed.
	 * @see         IBluetoothSppAcceptorEventListener::OnSppConnectionRequested()
	 * @remarks     If the local device is not paired with the specified target device, the pairing process starts
	 *              internally before the connect request is sent.
	 */
	result Connect(const BluetoothDevice& remoteDevice, const Tizen::Base::UuId& serviceUuid);

	/**
	 * Disconnects the current connection. @n
	 * If this method is called before the SPP acceptor accepts the connection request, the
	 * IBluetoothSppInitiatorEventListener::OnSppConnectionResponded() and E_SYSTEM is thrown. @n
	 * If this method is called on connection, the IBluetoothSppInitiatorEventListener::OnSppDisconnected() and
	 * E_SUCCESS is thrown.
	 *
	 * @since       2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.spp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or %Bluetooth is
	 *                                      not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the connection request is not sent or a connection with a
	 *                                      remote device is not established yet.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothSppInitiatorEventListener::OnSppConnectionResponded()
	 * @see         IBluetoothSppInitiatorEventListener::OnSppDisconnected()
	 * @see         IBluetoothSppAcceptorEventListener::OnSppDisconnected()
	 */
	result Disconnect(void);

	/**
	 * Sends the specified data.
	 *
	 * @since       2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.spp
	 *
	 * @return      An error code
	 * @param[in]   buffer                  The data to send
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or %Bluetooth is
	 *                                      not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the connection request is not sent or a connection with a
	 *                                      remote device is not established yet.
	 * @exception   E_INVALID_ARG           The argument has no data.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @remarks     The size of the buffer should not exceed @c 1000 bytes.
	 * @see         IBluetoothSppAcceptorEventListener::OnSppDataReceived()
	 */
	result SendData(const Tizen::Base::ByteBuffer& buffer);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying
	// of objects.
	//
	BluetoothSppInitiator(const BluetoothSppInitiator& value);
	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	// copying of objects.
	//
	BluetoothSppInitiator& operator =(const BluetoothSppInitiator& value);

private:
	_BluetoothSppInitiatorImpl* __pImpl;

}; // BluetoothSppInitiator

} } }
#endif // _FNET_BT_BLUETOOTH_SPP_INITIATOR_H_
