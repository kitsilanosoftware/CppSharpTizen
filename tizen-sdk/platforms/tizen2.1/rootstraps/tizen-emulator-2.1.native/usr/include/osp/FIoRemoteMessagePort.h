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
 * @file		FIoRemoteMessagePort.h
 * @brief		This is the header file for the %RemoteMessagePort class.
 *
 * This header file contains declarations of the %RemoteMessagePort class.
 */
#ifndef _FIO_REMOTE_MESSAGE_PORT_H_
#define _FIO_REMOTE_MESSAGE_PORT_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FBaseColIMap.h>
#include <FAppTypes.h>

namespace Tizen { namespace Io
{

class LocalMessagePort;

/**
* @class    RemoteMessagePort
* @brief    This class provides methods for sending messages to message ports of another application.
*
* @since    2.0
*
* @final	This class is not intended for extension.
*
* The %RemoteMessagePort class provides methods for sending messages to message ports of another application.
*
* For more information on the class features,
* see <a href="../org.tizen.native.appprogramming/html/guide/io/messageport.htm">Message Port Communication</a>.
*
* @see Tizen::Io::MessagePortManager
* @see Tizen::Io::LocalMessagePort
*
* @code
*
* #include <FBase.h>
* #include <FIo.h>
*
* using namespace Tizen::Base;
* using namespace Tizen::Base::Collection;
* using namespace Tizen::Io;
*
* class MyAppClass
*		: public Tizen::Io::IMessagePortListener
* {
* public:
*	void Initialize(void);
*	virtual void OnMessageReceivedN(RemoteMessagePort* pRemoteMessagePort, IMap* pMessage);
*	void GetOnlineFriends(void);
*
* private:
*	LocalMessagePort* pLocalPort;
*	RemoteMessagePort* pRemotePort;
* };
*
* void
* MyAppClass::Initialize(void)
* {
*	pLocalPort = MessagePortManager::RequestLocalMessagePort(L"PortA");
*	pLocalPort->AddMessagePortListener(*this);
*
*	pRemotePort = MessagePortManager::RequestRemoteMessagePort(L"1234567890.RemoteApp", L"PortB");
* }
*
* void
* MyAppClass::OnMessageReceivedN(RemoteMessagePort* pRemoteMessagePort, IMap* pMessage)
* {
*   String* pValue = static_cast<String*>(pMessage->GetValue(String(L"Reply")));
*
*	AppLog("My friend's name is %ls", pValue->GetPointer());
*
*	delete pMessage;
* }
*
* void
* MyAppClass::GetOnlineFriends(void)
* {
*	HashMap* pMap = new HashMap(SingleObjectDeleter);
*	pMap->Construct();
*
*	pMap->Add(new String(L"Request"), new String(L"Friend"));
*
*	pRemotePort->SendMessage(pLocalPort, pMap);
*
*	delete pMap;
* }
*
* @endcode
*/

class _OSP_EXPORT_ RemoteMessagePort
	: public Tizen::Base::Object
{
public:

	/**
	* Gets the name of a remote message port.
	*
	* @since    2.0
	*
	* @return		The name of a remote message port
	*/
	Tizen::Base::String GetName(void) const;

	/**
	* Gets the ID of a remote application.
	*
	* @since    2.0
	*
	* @return		The ID of a remote application
	*/
	Tizen::App::AppId GetAppId(void) const;

	/**
	* Checks whether an instance is a trusted message port or not.
	*
	* @since    2.0
	*
	* @return		@c true if the instance is a trusted message port, @n
	*				else @c false
	*/
	bool IsTrusted(void) const;

	/**
	 * Sends a message to the message port of a remote application. This method is used for the unidirectional communication.
	 *
	 * @since    2.0
	 *
	 * @return       An error code
	 * @param[in]     pMessage            A pointer to an argument map of key (String) and value (String or ByteBuffer) pair @n
	 *									  The recommended message size is under 4KB.
	 * @exception     E_SUCCESS           The method is successful.
	 * @exception     E_INVALID_ARG       The message argument is not a map of key (String) and value (String or ByteBuffer) pair.
	 * @exception     E_OBJ_NOT_FOUND     The message port of the target application is not found.
	 * @exception     E_MAX_EXCEEDED      The size of @c pMessage has exceeded the maximum limit.
	 * @exception     E_SYSTEM            The method has failed due to a severe system error.
	 * @remarks       The recommended message size is under 4KB because severe system performance degradation may occur for large messages. @c E_MAX_EXCEEDED may be returned for messages over 4KB size.
	 */
	result SendMessage(const Tizen::Base::Collection::IMap* pMessage);


	/**
	 * Sends a message to the message port of a remote application. This method is used for the bidirectional communication.
	 *
	 * @since    2.0
	 *
	 * @return       An error code
	 * @param[in]     pLocalMessagePort    The local message port
	 * @param[in]     pMessage            A pointer to an argument map of key (String) and value (String or ByteBuffer) pair @n
	 *									  The recommended message size is under 4KB.
	 * @exception     E_SUCCESS           The method is successful.
	 * @exception     E_INVALID_ARG       Either of the following conditions has occurred: @n
	 *									  - The local message port is @c null. @n
	 *									  - The message argument is not a map of key (String) and value (String or ByteBuffer) pair.
	 * @exception     E_OBJ_NOT_FOUND     The message port of the target application is not found.
	 * @exception     E_MAX_EXCEEDED      The size of @c pMessage has exceeded the maximum limit.
	 * @exception     E_SYSTEM            The method has failed due to a severe system error.
	 * @remarks       The recommended message size is under 4KB because severe system performance degradation may occur for large messages. @c E_MAX_EXCEEDED may be returned for messages over 4KB size.
	 */
	result SendMessage(const LocalMessagePort* pLocalMessagePort, const Tizen::Base::Collection::IMap* pMessage);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	RemoteMessagePort(void);

	/**
	* This destructor is intentionally declared as private so that only the platform can delete an instance.
	*/
	virtual ~RemoteMessagePort(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	RemoteMessagePort(const RemoteMessagePort& localMessagePort);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	RemoteMessagePort& operator =(const RemoteMessagePort& localMessagePort);


	friend class _RemoteMessagePortImpl;

	class _RemoteMessagePortImpl * __pRemoteMessagePortImpl;

}; // RemoteMessagePort

} } // Tizen::Io

#endif //_FIO_REMOTE_MESSAGE_PORT_H_
