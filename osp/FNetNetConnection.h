//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FNetNetConnection.h
 * @brief		This is the header file for the %NetConnection class.
 *
 * This header file contains the declarations of the %NetConnection class.
 */
#ifndef _FNET_NET_CONNECTION_H_
#define _FNET_NET_CONNECTION_H_

#include <FBase.h>
#include <FNetNetTypes.h>
#include <FNetNetConnectionInfo.h>
#include <FNetINetConnectionEventListener.h>

namespace Tizen { namespace Net
{
class _NetConnectionImpl;

/**
 * @class	NetConnection
 * @brief	This class provides methods for all the network connections.
 *
 * @since	2.0
 *
 * The %NetConnection class provides methods for managing the connections for data communication.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 *
 * The following example demonstrates how to use the %NetConnection class.
 *
 * @code

// Start the network connection.
using namespace Tizen::Net;

void
Test(void)
{
	// Account ID
	NetAccountId accountId = INVALID_HANDLE;
	result r = E_SUCCESS;

	// Account manager
	NetAccountManager netAccountManager;
	r = netAccountManager.Construct();
	accountId = netAccountManager.GetNetAccountId();

	// Construct a listener.
	TestListener* pMyListener = new TestListener();

	// NetConnection instance allocation.
	NetConnection* pNetConnection = new NetConnection;

	// Construct NetConnection.
	r = pNetConnection->Construct(accountId);

	// __NetConnectionEvent AddListener.
	r = pNetConnection->AddNetConnectionListener(pMyListener);

	// NetConnection connect.
	r = pNetConnection->Start();
}
 * @endcode
 */
class _OSP_EXPORT_ NetConnection
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	NetConnection(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~NetConnection(void);

	/**
	 * Initializes this instance of %NetConnection with the specified parameter. @n
	 * It automatically binds @c netAccountId with %NetConnection. This method registers an application for receiving the network connection events. @n
	 * A network connection is based on a configured network account for starting the connection. In order to start the network connection, create a new
	 * network account or obtain the information of an existing network account, and call the Start() method.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		netAccountId		The index of the network account to which this %NetConnection is bound
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_MAX_EXCEEDED		Unable to setup a new connection due to too many existing connections.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception		E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_INVALID_PROXY		The proxy address is invalid.
	 * @remarks			If the application gets the last result by E_INVALID_PROXY, it must use a warning pop-up to notify the user.
	 */
	result Construct(NetAccountId netAccountId);

public:
	/**
	 * Adds a listener to %NetConnection. @n
	 * The added listener can listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener				A reference to INetConnectionEventListener
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST		The listener is already added.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, @n
	 * 										because the caller thread is a worker thread.
	 */
	result AddNetConnectionListener(INetConnectionEventListener& listener);

	/**
	 * Removes the specified INetConnectionEventListener instance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener				A reference to INetConnectionEventListener
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @exception	E_OBJ_NOT_FOUND			The eventListener is not found.
	 */
	result RemoveNetConnectionListener(INetConnectionEventListener& listener);

	/**
	 * Starts the network connection.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/network.connection
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @exception	E_INVALID_ACCOUNT		The specified network account ID is invalid.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied to the resources bound to this %NetConnection.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_SERVICE_LIMITED		A connection is already active. Therefore, cannot setup a co-existing network connection.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		When the network is available, after calling this method, the OnNetConnectionStarted() method of the registered
	 *				INetConnectionEventListener instance is called.
	 * @see			Stop()
	 */
	result Start(void);

	/**
	 * Stops the network connection.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/network.connection
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied to the resources bound to this %NetConnection.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		This method stops the network connection of an application.  Additionally, it does not ensure immediate disconnection of the network
	 *				service (for example, 3G data service or Wi-Fi). The network service remains active till all the applications stop using the network
	 *				connection. Once stopped, the network connection can be restarted using the Start() method.
	 * @see			Start(), Close()
	 */
	result Stop(void);

	/**
	 * Closes the network connection. @n
	 * All the resources associated with the network connection are freed. This is a forced operation. The Close() method disconnects the network connection
	 * with a remote server or gateway.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/network.connection
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied to the resources bound to this %NetConnection.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		This method stops the network connection of an application. Additionally, it does not ensure immediate disconnection of the network
	 *				service (for example, 3G data service or Wi-Fi). The network service remains active till all the applications stop using the network
	 *				connection.
	 * @see			Stop()
	 */
	result Close(void);

	/**
	 * Gets the network account ID of this instance. @n
	 * This ID is used to establish a network connection with a remote server or gateway.
	 *
	 * @since		2.0
	 *
	 * @return		The NetAccountId of this %NetConnection which is bound at Construct(), @n
	 *				else @c INVALID_HANDLE if %NetConnection is invalid or not constructed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance may be closed.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	NetAccountId GetNetAccountId(void) const;

	/**
	 * Gets the network connection information.
	 *
	 * @since		2.0
	 *
	 * @return		A NetConnectionInfo instance specifying information on this network connection
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		The access is denied.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		This method requires a NetConnectionInfo instance reference. The network connection information is only available when the network
	 *				connection is "Active". For other states, this method returns @c null.
	 * @warning     Do not delete the returned NetConnectionInfo instance. This instance directly references the internal connection information of
	 *				%NetConnection.
	 */
	const NetConnectionInfo* GetNetConnectionInfo(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the connection information for the specified account.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated because it is moved to the NetConnectionManager class.
	 * @since       2.0
	 *
	 * @return		A NetConnectionInfo instance specifying information on this network connection, @n
	 *				else @c null in case of an error or if an active connection is not found
	 * @param[in]	netAccountId		The network account
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	static NetConnectionInfo* GetNetConnectionInfoN(NetAccountId netAccountId);

	/**
	 * @if OSPDEPREC
	 * Gets a list of all the connection information used by the system.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it is moved to the NetConnectionManager class.
	 * @since       2.0
	 *
	 * @return		An IList containing indexes to NetConnectionInfo in the network, @n
	 *				else @c null in case of an error or if an active connection is not found
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	static Tizen::Base::Collection::IList* GetAllNetConnectionInfoN(void);


	/**
	 * Gets the state of the network connection.
	 *
	 * @since		2.0
	 *
	 * @return		The state of the network connection
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance may be closed.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	NetConnectionState GetConnectionState(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	value			An instance of %NetConnection
	 */
	NetConnection(const NetConnection& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %NetConnection
	 */
	NetConnection& operator =(const NetConnection& rhs);

private:
	_NetConnectionImpl* __pNetConnectionImpl;

	friend class _NetConnectionImpl;
}; // NetConnection

} } //Tizen::Net

#endif // _FNET_NET_CONNECTION_H_
