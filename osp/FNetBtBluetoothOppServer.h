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
 * @file        FNetBtBluetoothOppServer.h
 * @brief       This is the header file for the %BluetoothOppServer class.
 *
 * This header file contains the declarations of the %BluetoothOppServer class.
 */
#ifndef _FNET_BT_BLUETOOTH_OPP_SERVER_H_
#define _FNET_BT_BLUETOOTH_OPP_SERVER_H_

#include <FBaseObject.h>
#include <FBaseResult.h>

namespace Tizen { namespace Base
{
class String;
} }

namespace Tizen { namespace Net { namespace Bluetooth
{

// forward declarations
class IBluetoothOppServerEventListener;
class _BluetoothOppServerImpl;

/**
 * @class    BluetoothOppServer
 * @brief    This class provides methods to handle the %Bluetooth Object Push Profile (OPP) server, such as the
 *           incoming connection requests.
 *
 * @since    2.0
 *
 * The %BluetoothOppServer class provides methods to handle the %Bluetooth Object Push Profile (OPP) server, such as the incoming
 * connection requests.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _OSP_EXPORT_ BluetoothOppServer
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct()
	 * method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 */
	BluetoothOppServer(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~BluetoothOppServer(void);

	/**
	 * Constructs and initializes this instance of %BluetoothOppServer with the specified listener.
	 *
	 * @since       2.0
	 * @feature     %http://tizen.org/feature/network.bluetooth
	 *
	 * @return      An error code
	 * @param[in]   listener                The event listener for the OPP server
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     Before calling this method, check whether the feature is supported by
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(IBluetoothOppServerEventListener& listener);

	/**
	 * Accepts a push request from a remote OPP client. @n
	 * The %AcceptPush() method starts the file transfer.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or %Bluetooth is
	 *                                      not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the service is not started yet or a push request is not
	 *                                      received from a remote device.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothOppClientEventListener::OnOppPushResponded()
	 */
	result AcceptPush(void);

	/**
	 * Rejects a push request from a remote OPP client.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or %Bluetooth is
	 *                                      not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the service is not started yet or a push request is not
	 *                                      received from a remote device.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_FAILURE               The method has failed.
	 * @see         IBluetoothOppClientEventListener::OnOppPushResponded()
	 */
	result RejectPush(void);

	/**
	 * Sets the destination path of the file to be received.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   dstPath                 The new destination file path
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, trying to change the path on Push transition is prohibited.
	 * @exception   E_INACCESSIBLE_PATH     The specified @c dstPath is inaccessible.
	 * @exception   E_FAILURE               The method has failed.
	 */
	result SetDestinationPath(const Tizen::Base::String& dstPath);

	/**
	 * Starts the OPP service and associates a listener with it.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @param[in]   dstPath                 The new destination file path
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, %Bluetooth is not activated.
	 * @exception   E_IN_PROGRESS           The service has already started.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SERVICE_UNAVAILABLE   The OPP service is unavailable.
	 * @exception   E_INACCESSIBLE_PATH     The specified @c dstPath is inaccessible.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, The stop process is in progress.
	 * @exception   E_FAILURE               The method has failed.
	 */
	result StartService(const Tizen::Base::String& dstPath);

	/**
	 * Stops the OPP service. @n
	 * The %StopService() method cancels the file transfer before stopping the service.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the service is not started as yet.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_IN_PROGRESS           The stop process is in progress.
	 * @exception   E_FAILURE               The method has failed.
	 */
	result StopService(void);

	/**
	 * Stops the file transfer in progress which was started by the client. @n
	 * If the %StopTransfer() method is called during the file transfer, the IBluetoothOppServerEventListener::OnOppTransferDone()
	 * method is called with @c isCompleted as @c false.
	 *
	 * @since 2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/bluetooth.opp
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, %Bluetooth is not activated.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the file transfer is not in progress.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_OPERATION_FAILED      The operation has failed.
	 */
	result StopTransfer(void);

	/**
	 * Sets the minimum interval of invocation of IBluetoothOppServerEventListener::OnOppTransferInProgress() in
	 * percentage. @n
	 * The default value is @c 5.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   percent                 The minimum period of progress interval as a percentage value
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The value of the argument is outside the valid range defined by the method.
	 * @see         IBluetoothOppServerEventListener::OnOppTransferInProgress()
	 */
	result SetMinProgressInterval(int percent);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying
	// of objects.
	//
	BluetoothOppServer(const BluetoothOppServer& value);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	// copying of objects.
	//
	BluetoothOppServer& operator =(const BluetoothOppServer& value);

private:
	_BluetoothOppServerImpl* __pImpl;

}; // BluetoothOppServer

} } }
#endif // _FNET_BT_BLUETOOTH_OPP_SERVER_H_
