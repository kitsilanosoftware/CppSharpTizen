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
 * @file        FNetBtBluetoothSppAcceptor.h
 * @brief       This is the header file for the %BluetoothSppAcceptor class.
 *
 * This header file contains the declarations of the %BluetoothSppAcceptor class.
 */
#ifndef _FNET_BT_BLUETOOTH_SPP_ACCEPTOR_H_
#define _FNET_BT_BLUETOOTH_SPP_ACCEPTOR_H_

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
class IBluetoothSppAcceptorEventListener;
class _BluetoothSppAcceptorImpl;

/**
 * @class   BluetoothSppAcceptor
 * @brief   This class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) acceptor, such as an
 *          incoming connection request.
 * @since   2.0
 *
 * The %BluetoothSppAcceptor class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) acceptor, such as an
 * incoming connection request.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothSppAcceptor
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct()
	 * method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 */
	BluetoothSppAcceptor(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~BluetoothSppAcceptor(void);

	/**
	 * Initializes this instance of %BluetoothSppAcceptor with the specified listener.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   listener                The event listener for SPP acceptor
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result Construct(IBluetoothSppAcceptorEventListener& listener);

	/**
	 * Accepts a connection request from a remote SPP initiator. @n
	 * This method establishes a connection.
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
	 *                                      For example, the service is not started yet or the connection request is
	 *                                      not yet received from a remote device.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothSppInitiatorEventListener::OnSppConnectionResponded()
	 */
	result AcceptConnection(void);

	/**
	 * Rejects a connection request from a remote SPP initiator.
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
	 *                                      For example, the service is not started yet or the connection request is
	 *                                      not yet received from a remote device.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothSppInitiatorEventListener::OnSppConnectionResponded()
	 */
	result RejectConnection(void);

	/**
	 * Starts the SPP service with the default service UUID - BT_SVC_UUID_SPP.
	 *
	 * @since       2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.spp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or %Bluetooth is
	 *                                      not activated.
	 * @exception   E_IN_PROGRESS           The service has already started.
	 * @exception   E_ALREADY_CONNECTED     The connection with an SPP initiator has already been established.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SERVICE_UNAVAILABLE   The SPP service with the specified UUId is unavailable.
	 * @exception   E_FAILURE               The method has failed.
	 */
	result StartService(void);

	/**
	 * Starts the SPP service with the specified service UUID.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/bluetooth.spp
	 *
	 * @return      An error code
	 * @param[in]   serviceUuid             The UUID of SPP service
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or %Bluetooth is
	 *                                      not activated.
	 * @exception   E_INVALID_ARG           The specified input parameter is invalid.
	 * @exception   E_IN_PROGRESS           The service has already started.
	 * @exception   E_ALREADY_CONNECTED     The connection with an SPP initiator has already been established.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SERVICE_UNAVAILABLE   The SPP service with the specified UUId is unavailable.
	 * @exception   E_FAILURE               The method has failed.
	 */
	result StartService(const Tizen::Base::UuId& serviceUuid);

	/**
	 * Stops the SPP service. @n
	 * This method disconnects the current connection before stopping the service.
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
	 *                                      For example, the service is not started yet.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 */
	result StopService(void);

	/**
	 * Disconnects the current connection.
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
	 *                                      For example, the service is not started yet or a connection with a remote
	 *                                      device is not established.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothSppAcceptorEventListener::OnSppDisconnected()
	 * @see         IBluetoothSppInitiatorEventListener::OnSppDisconnected()
	 */
	result Disconnect(void);

	/**
	 * Sends the data.
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
	 *                                      For example, the service is not started yet or a connection with a remote
	 *                                      device is not established.
	 * @exception   E_INVALID_ARG           The specified @c buffer is empty.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @remarks     The size of the buffer should not exceed @c 1000 bytes.
	 * @see         IBluetoothSppInitiatorEventListener::OnSppDataReceived()
	 */
	result SendData(const Tizen::Base::ByteBuffer& buffer);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying
	// of objects.
	//
	BluetoothSppAcceptor(const BluetoothSppAcceptor& value);
	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	// copying of objects.
	//
	BluetoothSppAcceptor& operator =(const BluetoothSppAcceptor& value);

private:
	_BluetoothSppAcceptorImpl* __pImpl;

}; // BluetoothSppAcceptor

} } }
#endif // _FNET_BT_BLUETOOTH_SPP_ACCEPTOR_H_
