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
 * @file		FIoLocalMessagePort.h
 * @brief		This is the header file for the %LocalMessagePort class.
 *
 * This header file contains declarations of the %LocalMessagePort class.
 */
#ifndef _FIO_LOCAL_MESSAGE_PORT_H_
#define _FIO_LOCAL_MESSAGE_PORT_H_

#include <FBaseResult.h>
#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FBaseString.h>

namespace Tizen { namespace Io
{

class IMessagePortListener;

/**
* @class    LocalMessagePort
* @brief    This class provides methods for receiving messages from other applications.
*
* @since    2.0
*
* @final	This class is not intended for extension.
*
* The %LocalMessagePort class provides methods for receiving messages from other applications.
*
* For more information on the class features,
* see <a href="../org.tizen.native.appprogramming/html/guide/io/messageport.htm">Message Port Communication</a>.
*
* @see Tizen::Io::MessagePortManager
* @see Tizen::Io::RemoteMessagePort
*
* The following example demonstrates how to use the %LocalMessagePort class.
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
*	IMap* GetOnlineFriends(void);
*
* private:
*	LocalMessagePort* pLocalPort;
* };
*
* void
* MyAppClass::Initialize(void)
* {
*	pLocalPort = MessagePortManager::RequestLocalMessagePort(L"PortB");
*	pLocalPort->AddMessagePortListener(*this);
* }
*
* void
* MyAppClass::OnMessageReceivedN(RemoteMessagePort* pRemoteMessagePort, IMap* pMessage)
* {
*   String* pValue = static_cast<String*> (pMessage->GetValue(String(L"Request")));
*
*	if (*pValue == L"Friend")
*	{
*		HashMap* pMap = GetOnlineFriends();
*		pRemoteMessagePort->SendMessage(pLocalPort, pMap);
*
*		delete pMap;
*	}

*	delete pMessage;
* }
*
* IMap*
* MyAppClass::GetOnlineFriends(void)
* {
*	HashMap* pMap = new HashMap(SingleObjectDeleter);
*	pMap->Construct();
*
*	pMap->Add(new String(L"Reply"), new String(L"Kim"));
*
*	return pMap;
* }
*
* @endcode
*/

class _OSP_EXPORT_ LocalMessagePort
	: public Tizen::Base::Object
{
public:
	/**
	* Adds a message port listener that is called when a message is received.
	*
	* @since    2.0
	*
	* @return		An error code
	* @param[in]	listener    The message port listener
	* @exception	E_SUCCESS           The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST     The listener instance already exists.
	*/
	result AddMessagePortListener(IMessagePortListener& listener);

	/**
	* Removes a message port listener.
	*
	* @since    2.0
	*
	* @return		An error code
	* @param[in] 	listener    The message port listener
	* @exception	E_SUCCESS           The method is successful.
	* @exception	E_OBJ_NOT_FOUND     The listener instance is not found.
	*/
	result RemoveMessagePortListener(IMessagePortListener& listener);

	/**
	* Gets the name of a local message port.
	*
	* @since    2.0
	*
	* @return		The name of a local message port
	*/
	Tizen::Base::String GetName(void) const;

	/**
	* Checks whether an instance is a trusted message port or not.
	*
	* @since    2.0
	*
	* @return		@c true if this instance is a trusted message port, @n
	*				else @c false
	*/
	bool IsTrusted(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	LocalMessagePort(void);

	/**
	* This destructor is intentionally declared as private so that only the platform can delete an instance.
	*/
	virtual ~LocalMessagePort(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	LocalMessagePort(const LocalMessagePort& localMessagePort);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	LocalMessagePort& operator =(const LocalMessagePort& localMessagePort);


	friend class _LocalMessagePortImpl;

	class _LocalMessagePortImpl * __pLocalMessagePortImpl;

}; // LocalMessagePort

} } // Tizen::Io

#endif //_FIO_LOCAL_MESSAGE_PORT_H_
