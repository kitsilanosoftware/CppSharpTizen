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
 * @file    FNetBtIBluetoothOppServerEventListener.h
 * @brief   This is the header file for the %IBluetoothOppServerEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothOppServerEventListener interface.
 */
#ifndef _FNET_BT_IBLUETOOTH_OPP_SERVER_EVENT_LISTENER_H_
#define _FNET_BT_IBLUETOOTH_OPP_SERVER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declaration
class BluetoothOppServer;
class BluetoothDevice;
/**
 * @interface    IBluetoothOppServerEventListener
 * @brief        This interface provides a listener for the %BluetoothOppServer events.
 *
 * @since        2.0
 *
 * The %IBluetoothOppServerEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothOppServer events. When a BluetoothOppServer event is generated, one of these methods
 * is called.
 * @n
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ IBluetoothOppServerEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes
	 * are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IBluetoothOppServerEventListener(void) {}

	/**
	 * Called when an incoming push request is received from a remote OPP client.
	 *
	 * @since       2.0
	 *
	 * @param[in]   device          The remote device to request the connection
	 */
	virtual void OnOppPushRequested(const BluetoothDevice& device) = 0;

	/**
	 * Called when the file is being transferred. @n
	 * Gets the progress information of the file transfer.
	 *
	 * @since       2.0
	 *
	 * @param[in]   percent         The progress in percentage ranging from @c 1 to @c 100 percent
	 * @see         BluetoothOppServer::SetMinProgressInterval()
	 */
	virtual void OnOppTransferInProgress(int percent) = 0;

	/**
	 * Called when the file transfer has finished.
	 *
	 * @since           2.0
	 *
	 * @param[in]       fileName        The name of the file to transfer
	 * @param[in]       fileSize        The size of the file to transfer
	 * @param[in]       isCompleted     Set to @c true if the transfer is successfully completed, @n
	 *                                  else @c false
	 * @remarks         If the name of the received file already exists in the destination path, the received file is renamed
	 *                  automatically and @c isCompleted is set to @c true. For renaming, the specified postfix is appended to
	 *                  the original file name. The postfix consists of an underscore and three digit sequence numbers starting
	 *                  from 001. For example, "MySong.mp3" may be changed to "MySong_001.mp3".
	 */
	virtual void OnOppTransferDone(const Tizen::Base::String& fileName, int fileSize, bool isCompleted) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBluetoothOppServerEventListener_Reserved1(void) {};
}; // IBluetoothOppServerEventListener

} } }
#endif // _FNET_BT_IBLUETOOTH_OPP_SERVER_EVENT_LISTENER_H_
