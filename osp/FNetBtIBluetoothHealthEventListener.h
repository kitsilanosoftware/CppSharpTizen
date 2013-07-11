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
 * @file    FNetBtIBluetoothHealthEventListener.h
 * @brief   This is the header file for the %IBluetoothHealthEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothHealthEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_HEALTH_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_HEALTH_EVENT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>
#include <FNetBtBluetoothTypes.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

class BluetoothDevice;

/**
 * @interface   IBluetoothHealthEventListener
 * @brief       This interface provides a listener for the %BluetoothHealth events.
 * @since 2.0
 *
 * The %IBluetoothHealthEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothHealth events. When a %BluetoothHealth event is generated, one of these methods is called.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothHealthEventListener
	: virtual public Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IBluetoothHealthEventListener(void) {}

	/**
	 * Called to notify when a connection with a health device is established.
	 *
	 * @since 2.0
	 * @param[in]   channelId           The channel ID of the established connection, @n
	 *                                  else an invalid ID (-1) if the method is not successful
	 * @param[in]   dataType            The type of data used in the established connection which is defined in
	 *                                  ISO/IEEE 11073-20601 and represents type of health device such as thermometer,
	 *                                  heart rate monitor, weight scale, and so on
	 * @param[in]   channelType         The data channel type of the established connection
	 * @param[in]   pRemoteDevice       The remote health device to connect with the local device, @n
	 *                                  else @c null if the method is not successful
	 * @param[in]   r                   The result of the connection request. @n
	 *                                  One of the following exception is thrown.
	 * @exception   E_SUCCESS           The connection is established successfully.
	 * @exception   E_OPERATION_FAILED  The connection request has failed.
	 */
	virtual void OnHealthConnected(int channelId, int dataType, BluetoothHealthDataChannelType channelType,
			const BluetoothDevice* pRemoteDevice, result r) = 0;

	/**
	 * Called to notify that the connection with the specified channel ID is disconnected.
	 *
	 * @since 2.0
	 *
	 * @param[in]   channelId           The channel ID of the terminated connection
	 * @param[in]   r                   The disconnection status. @n
	 *                                  One of the following exception is thrown.
	 * @exception   E_SUCCESS           The specified connection (channel) is terminated successfully.
	 * @exception   E_OPERATION_FAILED  The method has failed to disconnect.
	 */
	virtual void OnHealthDisconnected(int channelId, result r) = 0;

	/**
	 * Called to notify when the data has been received on the specified channel.
	 *
	 * @since 2.0
	 *
	 * @param[in]   channelId           The channel ID of the connection to receive data
	 * @param[in]   buffer              The data to receive
	 */
	virtual void OnHealthDataReceived(int channelId, Tizen::Base::ByteBuffer& buffer) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothHealthEventListener_Reserved1(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothHealthEventListener_Reserved2(void) {};

	//
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-relatedissues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothHealthEventListener_Reserved3(void) {};

}; // IBluetoothHealthEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_HEALTH_EVENT_LISTENER_H_
