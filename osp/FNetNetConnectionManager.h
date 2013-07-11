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
 * @file		FNetNetConnectionManager.h
 * @brief		This is the header file for the %NetConnectionManager class.
 *
 * This header file contains the declarations of the %NetConnectionManager class.
 */
#ifndef _FNET_NET_CONNECTION_MANAGER_H_
#define _FNET_NET_CONNECTION_MANAGER_H_

#include <FBase.h>
#include <FNetNetTypes.h>
#include <FNetNetConnection.h>
#include <FNetManagedNetConnection.h>

namespace Tizen { namespace Net
{
class _NetConnectionManagerImpl;

/**
 * @class	NetConnectionManager
 * @brief	This class provides methods for managing the network connections.
 *
 * @since   2.0
 *
 *  The %NetConnectionManager class provides methods for creating and retrieving connections for data communication.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 */
class _OSP_EXPORT_ NetConnectionManager
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	NetConnectionManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~NetConnectionManager(void);

	/**
	 * Initializes this instance of %NetConnectionManager.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 */
	result Construct(void);

public:
	/**
	 * Creates a new network connection.
	 *
	 * @since       2.0
	 *
	 * @return		A NetConnection instance containing the account information, @n
	 *				else @c null if an error occurs
	 * @param[in]	netAccountId		The index of the network account to which this %NetConnection is bound
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception	E_MAX_EXCEEDED		Unable to setup a new connection due to too many existing connections.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetConnection* CreateNetConnectionN(NetAccountId netAccountId);

	/**
	 * Gets an instance of the current connection that is managed by the system.
	 *
	 * @since       2.0
	 *
	 * @return		A ManagedNetConnection instance containing the account information, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	ManagedNetConnection* GetManagedNetConnectionN(void) const;

	/**
	 * Gets the preferred network.
	 *
	 * @since       2.0
	 *
	 * @return		The preferred network, @n
	 *				else @c NET_WIFI_FIRST if there is an error or if the preferred network is not set
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetPreferenceType GetNetPreference(void) const;

	/**
	 * Sets the preferred network.
	 *
	 * @since       2.0
	 * @privilege	%http://tizen.org/privilege/network.connection
	 *
	 * @return		An error code
	 * @param[in]	netPreference		The preferred network
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	This operation is not allowed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		If this method is not used, the default connection works in the Wi-Fi first mode.
	 */
	result SetNetPreference(NetPreferenceType netPreference);

public:
	/**
	 * Gets the connection information that is related to a network account.
	 *
	 * @since       2.0
	 *
	 * @return		A NetConnectionInfo instance specifying the information on this network connection, @n
	 *				else @c null if there is an error or if an active connection is not found
	 * @param[in]	netAccountId		The network account ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static NetConnectionInfo* GetNetConnectionInfoN(NetAccountId netAccountId);

	/**
	 * Gets a list of all the network connections information that is used by the system.
	 *
	 * @since       2.0
	 *
	 * @return		An IList containing indexes to the active %NetConnectionInfo in the network, @n
	 *				else @c null if there is an error or if there is no active connection in the system
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::Collection::IList* GetAllNetConnectionInfoN(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %NetConnectionManager
	 */
	NetConnectionManager(const NetConnectionManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %NetConnectionManager
	 */
	NetConnectionManager& operator =(const NetConnectionManager& rhs);

private:
	_NetConnectionManagerImpl* __pNetConnectionManagerImpl;

	friend class _NetConnectionManagerImpl;
}; // NetConnectionManager

} } //Tizen::Net

#endif // _FNET_NET_CONNECTION_MANAGER_H_
