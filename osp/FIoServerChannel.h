//
// Open Service Platform
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
 * @file		FIoServerChannel.h
 * @brief		This is the header file for the %ServerChannel class.
 *
 * This header file contains the declarations of the %ServerChannel class.
 */
#ifndef _FIO_SERVER_CHANNEL_H_
#define _FIO_SERVER_CHANNEL_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FAppTypes.h>
#include <FIoIChannelRequestEventListener.h>

namespace Tizen { namespace Io
{
/**
* @if OSPDEPREC
* @class    ServerChannel
* @brief    <i> [Deprecated] </i> This class provides methods to receive a request from a client application.
*
* @deprecated	This class is deprecated. Instead of using this class, use LocalMessagePort, RemoteMessagePort, and MessagePortManager classes.
* @since    2.0
*
* @final	This class is not intended for extension.
*
* The %ServerChannel class provides methods to receive a request from a client application. An application can receive a request from another application using the %ServerChannel class. The instance of %ServerChannel is retrieved using ServerChannel::GetInstance().
* @n
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/io/channels.htm">Channel Communication</a>.
*
* The following example demonstrates how to use the %ServerChannel class.
*
* @code
*
* #include <FBase.h>
* #include <FIo.h>
*
* using namespace Tizen::Base;
* using namespace Tizen::Base::Collection;
* using namespace Tizen::Io;
* using namespace Tizen::App;
*
* class MyAppClass
*	: public Tizen::Io::IChannelRequestEventListener
* {
* public:
*	result Initialize(void);
*	ArrayList* GetOnlineFriends(void);
*	void virtual OnChannelRequestReceivedN(RequestId reqId, Tizen::Io::ServerChannel& serverChannel
*										, const Tizen::Base::String& clientChannelId
*										, Tizen::Base::Collection::IList* pArgs);
* };
*
* result
* MyAppClass::Initialize(void)
* {
*	result r = E_SUCCESS;
*
*	// Sets the channel request event listener.
*	ServerChannel::GetInstance()->SetChannelRequestEventListener(this);
*
*	return r;
* }
*
* ArrayList*
* MyAppClass::GetOnlineFriends(void)
* {
*	ArrayList* pDataList = new ArrayList();
*	pDataList->Construct();

*	String* pData = new String(L"Tom");
*	String* pData2 = new String(L"Jane");
*
*	pDataList->Add(*pData);
*	pDataList->Add(*pData2);
*
*	return pDataList;
* }
*
* void
* MyAppClass::OnChannelRequestReceivedN(RequestId reqId, ServerChannel& serverChannel
*										, const String& clientChannelId
*										, IList* pArgs)
* {
*	// Handles the request.
*	ArrayList* pList = GetOnlineFriends();
*
*	// Sends the response to the client.
*	serverChannel.SendResponse(clientChannelId, reqId, pList);
*
*	// Removes the arguments.
*	pList->RemoveAll(true);
*	delete pList;
*
*	pArgs->RemoveAll(true);
*	delete pArgs;
* }
*
* @endcode
* @endif
*/

class _OSP_EXPORT_ ServerChannel
	: public Tizen::Base::Object
{
public:
	/**
	* Sets the request event listener. @n
	* The listener is called when a request arrives. To reset the event listener, @c null must be passed.
	*
	* @since 2.0
	*
	* @param[in] pRequestListener    The request event listener
	*/
	void SetChannelRequestEventListener(IChannelRequestEventListener* pRequestListener);

	/**
	* Gets the default server channel of the application.
	*
	* @since    2.0
	*
	* @return	A pointer to the %ServerChannel instance, @n
	*			else @c null if it fails
	* @exception	E_SUCCESS           The method is successful.
	* @exception	E_SYSTEM            The method cannot proceed due to a severe system error.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/

	static ServerChannel* GetInstance(void);

	/**
	* Gets the specific server channel of the application.
	*
	* @since 	2.0
	*
	* @return	A pointer to the %ServerChannel instance, @n
	*			else @c null if it fails
	* @param[in] 	channelName         The channel name
	* @exception	E_SUCCESS           The method is successful.
	* @exception	E_SYSTEM            The method cannot proceed due to a severe system error.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static ServerChannel* GetInstance(const Tizen::Base::String& channelName);

	/**
	* Sends a response to the specific client channel of an application specified by the clientChannelId.
	*
	* @since        2.0
	*
	* @return    An error code
	* @param[in] 	clientChannelId     The client channel ID which can be either application ID or appicationID.ChannelName
	* @param[in] 	reqId               The request ID
	* @param[in] 	pArgs               A pointer to an argument list of type String
	* @exception 	E_SUCCESS           The method is successful.
	* @exception 	E_OBJ_NOT_FOUND     The specified client channel is not found.
	* @exception 	E_SYSTEM            The method cannot proceed due to a severe system error.
	*/
	result SendResponse(const Tizen::Base::String& clientChannelId, RequestId reqId, const Tizen::Base::Collection::IList* pArgs);


private:
	/**
	 * This default constructor is intentionally declared as private to implement the Singleton semantic.
	 */
	ServerChannel(void);

	/**
	* This destructor is intentionally declared as private to implement the Singleton semantic.
	*/
	virtual ~ServerChannel(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	ServerChannel(const ServerChannel& serverChannel);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	ServerChannel& operator =(const ServerChannel& serverChannel);

	static void InitSingleton(void);

	static void DestroySingleton(void);

	friend class _ServerChannelImpl;

	class _ServerChannelImpl * __pServerChannelImpl;

	static ServerChannel* __pServerChannelInstance;
}; // ServerChannel

} } // Tizen::Io

#endif //_FIO_SERVER_CHANNEL_H_
