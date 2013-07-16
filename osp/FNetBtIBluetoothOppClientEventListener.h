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
 * @file    FNetBtIBluetoothOppClientEventListener.h
 * @brief   This is the header file for the %IBluetoothOppClientEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothOppClientEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_OPP_CLIENT_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_OPP_CLIENT_EVENT_LISTENER_H_

#include <FBaseString.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

/**
 * @interface   IBluetoothOppClientEventListener
 * @brief       This interface provides a listener for the %BluetoothOppClient events.
 *
 * @since       2.0
 *
 * The %IBluetoothOppClientEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothOppClient events. When a BluetoothOppClient event is generated, one of these methods
 * is called.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothOppClientEventListener
	: public Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IBluetoothOppClientEventListener(void) {}

	/**
	 * Called when the OPP server responded to the push request.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r                   The response status
	 * @exception   E_SUCCESS           The push request is accepted by the OPP server and the file transfer has begun.
	 * @exception   E_REJECTED          The push request is rejected by the OPP server. @n
	 *                                  This exception is currently not in use.
	 * @exception   E_TIMEOUT           The push request is out of time.
	 * @exception   E_SYSTEM            A failure has occurred from the underlying system. @n
	 *                                  This failure includes the rejection by the OPP server.
	 */
	virtual void OnOppPushResponded(result r) = 0;

	/**
	 * Called when the file is being transferred. @n
	 * Gets the progress information of the file transfer.
	 *
	 * @since       2.0
	 *
	 * @param[in]   percent             The progress in percentage ranging from @c 1 to @c 100 percent
	 * @see         BluetoothOppClient::SetMinProgressInterval()
	 */
	virtual void OnOppTransferInProgress(int percent) = 0;

	/**
	 * Called when the file transfer has finished.
	 *
	 * @since       2.0
	 * @param[in]   filePath            The path of the file (including the file name) to transfer
	 * @param[in]   fileSize            The size of the file to transfer
	 * @param[in]   isCompleted         Set to @c true if the transfer is successfully completed, @n
	 *                                  else @c false
	 */
	virtual void OnOppTransferDone(const Tizen::Base::String& filePath, int fileSize, bool isCompleted) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothOppClientEventListener_Reserved1(void) {};
}; // IBluetoothOppClientEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_OPP_CLIENT_EVENT_LISTENER_H_
