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
 * @file    FNetBtIBluetoothSppInitiatorEventListener.h
 * @brief   This is the header file for the %IBluetoothSppInitiatorEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothSppInitiatorEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_SPP_INITIATOR_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_SPP_INITIATOR_EVENT_LISTENER_H_

#include <FBaseByteBuffer.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

/**
 * @interface   IBluetoothSppInitiatorEventListener
 * @brief       This interface provides a listener for the %BluetoothSppInitiator events.
 *
 * @since       2.0
 *
 * The %IBluetoothSppInitiatorEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothSppInitiator events. When a %BluetoothSppInitiator event is generated, one of these
 * methods is called.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothSppInitiatorEventListener
	: public Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IBluetoothSppInitiatorEventListener(void) {}

	/**
	 * Called to notify when an SPP acceptor responds to the connection request.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r               The status of the connection response
	 * @exception   E_SUCCESS       The connection request is accepted by the SPP acceptor and the file transfer has
	 *                              begun.
	 * @exception   E_REJECTED      The connection request is rejected by the SPP acceptor. @n
	 *                              This exception is currently not in use.
	 * @exception   E_TIMEOUT       The connection request has timed out.
	 * @exception   E_SYSTEM        A failure has occurred from the underlying system. @n
	 *                              This failure includes the rejection by the SPP acceptor.
	 */
	virtual void OnSppConnectionResponded(result r) = 0;

	/**
	 * Called to notify that the connection is disconnected.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r               The disconnection status
	 * @exception   E_SUCCESS       The connection is terminated successfully.
	 * @exception   E_SYSTEM        The method has failed to disconnect.
	 */
	virtual void OnSppDisconnected(result r) = 0;

	/**
	 * Called to notify when the data has been received.
	 *
	 * @since       2.0
	 *
	 * @param[in]   buffer          The data to receive
	 */
	virtual void OnSppDataReceived(Tizen::Base::ByteBuffer& buffer) = 0;
}; // IBluetoothSppInitiatorEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_SPP_INITIATOR_EVENT_LISTENER_H_
