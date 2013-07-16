//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file		FIoMessagePortManager.h
 * @brief		This is the header file for the %MessagePortManager class.
 *
 * This header file contains declarations of the %MessagePortManager class.
 */
#ifndef _FIO_MESSAGE_PORT_MANAGER_H_
#define _FIO_MESSAGE_PORT_MANAGER_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FIoLocalMessagePort.h>
#include <FIoRemoteMessagePort.h>
#include <FAppTypes.h>

namespace Tizen { namespace Io
{

/**
* @class    MessagePortManager
* @brief    This class provides methods for managing message ports.
*
* @since    2.0
*
* @final	This class is not intended for extension.
*
* The %MessagePortManager class provides methods for managing message ports.
*
* For more information on the class features,
* see <a href="../org.tizen.native.appprogramming/html/guide/io/messageport.htm">Message Port Communication</a>.
*
* @see Tizen::Io::LocalMessagePort
* @see Tizen::Io::RemoteMessagePort
*/

class _OSP_EXPORT_ MessagePortManager
{
public:
	/**
	* Requests for a LocalMessagePort instance with the specified message port name. @n
	* This method returns the same %LocalMessagePort instance if it has already been called with the same message port name. @n
	*
	* @since    2.0
	*
	* @return	A pointer to the LocalMessagePort instance, @n
	*			else @c null if it fails
	* @param[in]     localMessagePortName	The name of a local message port
	* @exception     E_SUCCESS           The method is successful.
	* @exception     E_INVALID_ARG       The @c localMessagePortName is empty.
	* @exception     E_SYSTEM            The method has failed due to a severe system error.
	* @remarks       It is not recommended to use the message port names that start with "http://tizen.org/messageport". @c E_INVALID_ARG may be returned because they are reserved by platform.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static LocalMessagePort* RequestLocalMessagePort(const Tizen::Base::String& localMessagePortName);

	/**
	* Requests the RemoteMessagePort instance with the specified remote application ID and message port name. @n
	* This method returns the same %RemoteMessagePort instance if it has already been called with the same remote application ID and message port name.
	*
	* @since    2.0
	*
	* @return	A pointer to the RemoteMessagePort instance, @n
	*			else @c null if it fails
	* @param[in]     remoteAppId			The remote application ID
	* @param[in]     remoteMessagePortName	The remote message port name
	* @exception     E_SUCCESS           The method is successful.
	* @exception     E_INVALID_ARG       The remote application ID or the remote message port name is empty.
	* @exception     E_OBJ_NOT_FOUND     The message port of the target application is not found.
	* @exception     E_SYSTEM            The method cannot proceed due to a severe system error.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static RemoteMessagePort* RequestRemoteMessagePort(const Tizen::App::AppId& remoteAppId, const Tizen::Base::String& remoteMessagePortName);

	/**
	* Requests for a trusted LocalMessagePort instance with the specified message port name. @n
	* This method returns the same %LocalMessagePort instance if it has already been called with the same message port name. @n
	* Communications over a trusted message port is allowed only if both the applications are signed with a certificate that is uniquely assigned to the developer.
	*
	* @since    2.0
	*
	* @return	A pointer to the trusted LocalMessagePort instance, @n
	*			else @c null if it fails
	* @param[in]     localMessagePortName	The name of a local message port
	* @exception     E_SUCCESS           The method is successful.
	* @exception     E_INVALID_ARG       The @c localMessagePortName is empty.
	* @exception     E_SYSTEM            The method has failed due to a severe system error.
	* @remarks       It is not recommended to use the message port names that start with "http://tizen.org/messageport". @c E_INVALID_ARG may be returned because they are reserved by platform.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static LocalMessagePort* RequestTrustedLocalMessagePort(const Tizen::Base::String& localMessagePortName);

	/**
	* Requests the trusted RemoteMessagePort instance with the specified message port name. @n
	* This method returns the same %RemoteMessagePort instance if it has already been called with the same remote application ID and message port name. @n
	* This message port allows communications only if the applications are signed with the same certificate which is uniquely assigned to the developer.
	*
	* @since    2.0
	*
	* @return	A pointer to the trusted RemoteMessagePort instance, @n
	*			else @c null if it fails
	* @param[in]     remoteAppId			The remote application ID
	* @param[in]     remoteMessagePortName	The name of a remote message port
	* @exception     E_SUCCESS           The method is successful.
	* @exception     E_INVALID_ARG       Either @c remoteAppId or @c remoteMessagePortName is empty.
	* @exception     E_OBJ_NOT_FOUND     The message port of the target application is not found.
	* @exception     E_CERTIFICATE_VERIFICATION_FAILED    The target application is not signed with the same certificate.
	* @exception     E_SYSTEM            The method has failed due to a severe system error.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static RemoteMessagePort* RequestTrustedRemoteMessagePort(const Tizen::App::AppId& remoteAppId, const Tizen::Base::String& remoteMessagePortName);

private:
	/**
	* This default constructor is intentionally declared as private because this class cannot be constructed.
	*/
	MessagePortManager(void);

	/**
	* This destructor is intentionally declared as private because this class cannot be constructed.
	*/
	virtual ~MessagePortManager(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	MessagePortManager(const MessagePortManager& messagePortManager);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	MessagePortManager& operator =(const MessagePortManager& messagePortManager);

}; // MessagePortManager

} } // Tizen::Io

#endif //_FIO_MESSAGE_PORT_MANAGER_H_
