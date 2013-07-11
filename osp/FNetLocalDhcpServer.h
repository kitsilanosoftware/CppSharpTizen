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
 * @file	FNetLocalDhcpServer.h
 * @brief	This is the header file for the %LocalDhcpServer class.
 *
 * This header file contains the declarations of the %LocalDhcpServer class.
 */
#ifndef _FNET_LOCAL_DHCP_SERVER_H_
#define _FNET_LOCAL_DHCP_SERVER_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseColIList.h>

namespace Tizen { namespace Net
{
class NetConnection;
class ILocalDhcpServerEventListener;
class _LocalDhcpServerImpl;
/**
 * @class	LocalDhcpServer
 * @brief	This class provides methods for managing the local DHCP server.
 *
 * @since	2.0
 *
 *  The %LocalDhcpServer class provides methods for managing the local DHCP server. The Wi-Fi Direct or USB NDIS requires the local DHCP server
 *	for data communication.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/local_DHCP_server_access.htm">Local DHCP Server Access</a>.
 */
class _OSP_EXPORT_ LocalDhcpServer
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since   2.0
	 */
	virtual ~LocalDhcpServer(void);

	/**
	 * Gets a singleton instance of %LocalDhcpServer that it associated with the specified network connection.
	 *
	 * @since       2.0
	 *
	 * @return		An instance of %LocalDhcpServer
	 * @param[in]	netConnection		A run-time session where a local DHCP server used
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static LocalDhcpServer* GetInstance(const NetConnection& netConnection);

public:
	/**
	 * Sets a listener instance for the events about a local DHCP server.
	 *
	 * @since       2.0
	 *
	 * @param[in]	pListener			An instance of ILocalDhcpServerEventListener @n
	 *									If it is @c null, it will reset the event listener.
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, @n
	 * 									because the caller thread is a worker thread.
	 */
	result SetLocalDhcpServerEventListener(ILocalDhcpServerEventListener* pListener);

public:
	/**
	 * Gets a list of all the client information on the local DHCP server.
	 *
	 * @since       2.0
	 *
	 * @return		An IList containing indexes to the DhcpClientInfo on the local DHCP server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		In case of an error or if there is no active connection for the local DHCP server, @c null is returned.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetDhcpClientInfoListN(void) const;

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	LocalDhcpServer(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %LocalDhcpServer
	 */
	LocalDhcpServer(const LocalDhcpServer& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %LocalDhcpServer
	 */
	LocalDhcpServer& operator =(const LocalDhcpServer& rhs);

private:
	_LocalDhcpServerImpl* __pLocalDhcpServerImpl;
	friend class _LocalDhcpServerImpl;
}; // LocalDhcpServer

} } //Tizen::Net

#endif // _FNET_LOCAL_DHCP_SERVER_H_
