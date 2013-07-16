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
 * @file    FNetBtIBluetoothSppAcceptorEventListener.h
 * @brief   This is the header file for the %IBluetoothSppAcceptorEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothSppAcceptorEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_SPP_ACCEPTOR_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_SPP_ACCEPTOR_EVENT_LISTENER_H_

#include <FBaseByteBuffer.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declaration
class BluetoothSppAcceptor;
class BluetoothDevice;

/**
 * @interface   IBluetoothSppAcceptorEventListener
 * @brief       This interface provides a listener for the %BluetoothSppAcceptor events.
 *
 * @since       2.0
 *
 * The %IBluetoothSppAcceptorEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothSppAcceptor events. When a BluetoothSppAcceptor event is generated, one of these methods
 * is called.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothSppAcceptorEventListener
	: public Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IBluetoothSppAcceptorEventListener(void) {}

	/**
	 * Called to notify an incoming connection request from a remote SPP initiator.
	 *
	 * @since       2.0
	 *
	 * @param[in]   device          The remote device to request the connection
	 * @remarks     If BluetoothSppAcceptor::SendData() is invoked in this callback, it does not work as expected.
	 *              Therefore, it must be invoked outside this callback thread.
	 */
	virtual void OnSppConnectionRequested(const BluetoothDevice& device) = 0;

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
	 * Called to notify when the data is received.
	 *
	 * @since       2.0
	 *
	 * @param[in]   buffer          The data to receive as a Tizen::Base::ByteBuffer
	 */
	virtual void OnSppDataReceived(Tizen::Base::ByteBuffer& buffer) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothSppAcceptorEventListener_Reserved1(void) {};
}; // IBluetoothSppAcceptorEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_SPP_ACCEPTOR_EVENT_LISTENER_H_
