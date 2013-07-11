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
 * @file    FNetBtBluetoothOppClient.h
 * @brief   This is the header file for the %BluetoothOppClient class.
 *
 * This header file contains the declarations of the %BluetoothOppClient class.
 */
#ifndef _FNET_BT_BLUETOOTH_OPP_CLIENT_H_
#define _FNET_BT_BLUETOOTH_OPP_CLIENT_H_

#include <FBaseObject.h>
#include <FBaseResult.h>

namespace Tizen { namespace Base
{
class String;
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declarations
class BluetoothDevice;
class IBluetoothOppClientEventListener;
class _BluetoothOppClientImpl;

/**
 * @class   BluetoothOppClient
 * @brief   This class provides methods to handle the %Bluetooth Object Push Profile (OPP) client, such as the
 *          outgoing connection requests.
 *
 * @since   2.0
 *
 * The %BluetoothOppClient class provides methods to handle the %Bluetooth Object Push Profile (OPP) client, such as the outgoing
 * connection requests.
 * @n
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothOppClient
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method
	 * must be called right after calling this constructor.
	 *
	 * @since       2.0
	 */
	BluetoothOppClient(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~BluetoothOppClient(void);

	/**
	 * Constructs and initializes this instance of %BluetoothOppClient with the specified listener.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   listener                The event listener for the OPP client
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result Construct(IBluetoothOppClientEventListener& listener);

	/**
	 * Pushes a file to a remote OPP server. @n
	 * The file transfer starts when the OPP server accepts the request.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since       2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues@n
	 *					For more information, see @ref CompIoPathPage "here".
	 * @endif
	 * @privilege   %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @param[in]   remoteDevice                The remote OPP server
	 * @param[in]   filePath                    The path of the source file
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
	 *                                          For example, %Bluetooth is not activated.
	 * @exception   E_IN_PROGRESS               The push process is in progress.
	 * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
	 * @exception   E_SERVICE_UNAVAILABLE       The OPP service is unavailable.
	 * @exception   E_INACCESSIBLE_PATH         The specified @c filePath is inaccessible.
	 * @exception   E_REMOTE_DEVICE_NOT_FOUND   The input device is not found. @n
	 *                                          This exception is currently not in use.
	 * @exception   E_FAILURE                   The method has failed.
	 * @see         IBluetoothOppServerEventListener::OnOppPushRequested()
	 * @remarks     If the local device is not paired with the specified target device, the pairing process starts
	 *              internally before the push request is sent.
	 */
	result PushFile(const BluetoothDevice& remoteDevice, const Tizen::Base::String& filePath);

	/**
	 * Cancels the file push request in progress. @n
	 * If this method is called before the OPP server accepts the push request, the
	 * IBluetoothOppClientEventListener::OnOppPushResponded() method is called and the exception E_SYSTEM is thrown. @n
	 * If this method is called during the file transfer, the IBluetoothOppClientEventListener::OnOppTransferDone()
	 * method is called with @c isCompleted as @c false.
	 *
	 * @since       2.0
	 * @privilege  %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the push request is not sent or accepted by a remote device.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothOppClientEventListener::OnOppPushResponded()
	 * @see         IBluetoothOppClientEventListener::OnOppTransferDone()
	 */
	result CancelPush(void);

	/**
	 * Sets the minimum interval of invocation of IBluetoothOppClientEventListener::OnOppTransferInProgress() in
	 * percentage. @n
	 * The default value is @c 5.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   percent                 The minimum period of progress interval as a percentage value
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The value of an argument is outside the valid range defined by the method.
	 * @see         IBluetoothOppClientEventListener::OnOppTransferInProgress()
	 */
	result SetMinProgressInterval(int percent);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying
	// of objects.
	//
	BluetoothOppClient(const BluetoothOppClient& value);
	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	// copying of objects.
	//
	BluetoothOppClient& operator =(const BluetoothOppClient& value);

private:
	_BluetoothOppClientImpl* __pImpl;

}; // BluetoothOppClient

} } }
#endif // _FNET_BT_BLUETOOTH_OPP_CLIENT_H_
