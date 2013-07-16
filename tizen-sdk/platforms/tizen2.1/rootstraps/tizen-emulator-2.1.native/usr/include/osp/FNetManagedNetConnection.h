//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
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
 * @file	FNetManagedNetConnection.h 
 * @brief	This is the header file for the %ManagedNetConnection class.
 *
 * This header file contains the declarations of the %ManagedNetConnection class.
 */
#ifndef _FNET_MANAGED_NET_CONNECTION_H_
#define _FNET_MANAGED_NET_CONNECTION_H_

#include <FBase.h>
#include <FNetNetTypes.h>
#include <FNetNetConnectionInfo.h>
#include <FNetIManagedNetConnectionEventListener.h>

namespace Tizen { namespace Net
{
class _ManagedNetConnectionImpl;

/**
 * @class	ManagedNetConnection 
 * @brief	This class provides methods for the network connection managed by the system.
 *
 * @since	2.0
 *
 * 	The %ManagedNetConnection class provides functionalities for accessing the information about the default connection for data communication 
 *	managed by the system. Once the connection is established, the applications can use sockets and HTTP interfaces.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/default_network_connection.htm">Default Network Connection</a>.
 */
class _OSP_EXPORT_ ManagedNetConnection
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ManagedNetConnection(void);

public:
	/**
	 * Sets a listener object to the current instance of %ManagedNetConnection.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pListener			An instance of IManagedNetConnectionEventListener @n
	 *									If this is @c null, it will reset the event listener.
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, @n
	 * 									because the caller thread is a worker thread.
	 */
	result SetManagedNetConnectionEventListener(IManagedNetConnectionEventListener* pListener);

	/** 
	 * Gets the network account on which the current instance is based, to establish a connection with a remote server or a gateway.
	 *
	 * @since		2.0
	 *
	 * @return		The NetAccountId of the current instance of %ManagedNetConnection, @n
	 *				else @c INVALID_HANDLE if the network connection managed by the system is inactive
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The network connection is inactive.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetAccountId GetNetAccountId(void) const;

	/**
	 * Gets the connection state of the current instance of %ManagedNetConnection.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of NetConnectionState specifying the state of the network connection, @n
	 *				else @c NET_CONNECTION_STATE_STOPPED if the network connection managed by the system is inactive
	 */
	NetConnectionState  GetConnectionState(void) const;

	/**
	 * Gets the information about the current network connection.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to an instance of NetConnectionInfo specifying the information about this network connection
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The network connection is inactive.
	 * @remarks		This method requires a NetConnectionInfo instance reference.
	 *				%NetConnectionInfo is only available when the network connection managed by the system is active. In other states, this returns null.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 * @warning 	Do not delete the returned NetConnectionInfo instance. This instance is directly referencing the internal connectionInfo of 
	 *				%ManagedNetConnection.
	 */
	const NetConnectionInfo* GetNetConnectionInfo(void) const;

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct
	 */
	ManagedNetConnection(void);

private:
	/** 
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %ManagedNetConnection
	 */	
	ManagedNetConnection(const ManagedNetConnection& rhs);

	/** 
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %ManagedNetConnection
	 */
	ManagedNetConnection& operator =(const ManagedNetConnection& rhs);

private:
	_ManagedNetConnectionImpl* __pManagedNetConnectionImpl;

	friend class _ManagedNetConnectionImpl;
}; // ManagedNetConnection

} } //Tizen::Net

#endif // _FNET_MANAGED_NET_CONNECTION_H_
