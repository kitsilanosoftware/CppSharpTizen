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
 * @file		FIoClientChannel.h
 * @brief		This is the header file for the %ClientChannel class.
 *
 * This header file contains the declarations of the %ClientChannel class.
 */
#ifndef _FIO_CLIENT_CHANNEL_H_
#define _FIO_CLIENT_CHANNEL_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FAppTypes.h>
#include <FIoIChannelResponseEventListener.h>

namespace Tizen { namespace Io
{

/**
* @if OSPDEPREC
* @class    ClientChannel
* @brief    <i> [Deprecated] </i> This class provides methods for sending a request to another application.
*
* @deprecated	This class is deprecated. Instead of using this class, use LocalMessagePort, RemoteMessagePort, and MessagePortManager classes.
* @since    2.0
*
* @final	This class is not intended for extension.
*
* The %ClientChannel class provides methods for sending a request to another application's ServerChannel. To receive a response
* for the request, set the ChannelResponseEventListener interface. The instance of %ClientChannel can be retrieved
* using ClientChannel::GetInstance().
* @n
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/io/channels.htm">Channel Communication</a>.
*
* The following example demonstrates how to use the %ClientChannel class.
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
*	: public Tizen::Io::IChannelResponseEventListener
* {
* public:
*	result Initialize(void);
*	void virtual OnChannelResponseReceivedN(RequestId reqId, Tizen::Io::ClientChannel& clientChannel
*												, const Tizen::Base::String& serverChannelId
*												, Tizen::Base::Collection::IList* pArgs);
*	void GetOnlineFriends(void);
* };
*
* void
* MyAppClass::Initialize(void)
* {
*	// Sets the channel response event listener.
*	ClientChannel::GetInstance()->SetChannelResponseEventListener(this);
* }
*
* void
* MyAppClass::OnChannelResponseReceivedN(RequestId reqId, ClientChannel& clientChannel
*										, const String& serverChannelId
*										, IList* pArgs)
* {
*	// Handles the channel response.
*	for(int i = 0; i < pArgs->GetCount(); i++)
*	{
*		AppLog("pData[%d]=%S", i, ((String*)(pArgs->GetAt(i)))->GetPointer());
*	}
*
*	// Cleans up the arguments.
*	pArgs->RemoveAll(true);
*	delete pArgs;
* }
*
* void
* MyAppClass::GetOnlineFriends(void)
* {
*	RequestId reqId = 0;
*
*	ArrayList* pDataList = new ArrayList();
*	pDataList->Construct();
*
*	String* pData = new String(L"GetList");
*	String* pData2 = new String(L"Friend");
*
*	pDataList->Add(*pData);
*	pDataList->Add(*pData2);
*
*	ClientChannel::GetInstance()->SendRequest(L"1234567890.ContactSvc", pDataList, reqId);
*
*	pDataList->RemoveAll(true);
*	delete pDataList;
* }
*
* @endcode
* @endif
*/

class _OSP_EXPORT_ ClientChannel
	: public Tizen::Base::Object
{
public:
	/**
	* Gets the default client channel of the application.
	*
	* @since 2.0
	*
	* @return	A pointer to the %ClientChannel instance, @n
	*			else @c null if it fails
	* @exception	E_SUCCESS           The method is successful.
	* @exception	E_SYSTEM            The method cannot proceed due to a severe system error.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static ClientChannel* GetInstance(void);

	/**
	* Gets the specific client channel of the application.
	*
	* @since 2.0
	*
	* @return	A pointer to the %ClientChannel instance, @n
	*			else @c null if it fails
	* @param[in]     channelName         The channel name
	* @exception     E_SUCCESS           The method is successful.
	* @exception     E_SYSTEM            The method cannot proceed due to a severe system error.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static ClientChannel* GetInstance(const Tizen::Base::String& channelName);

	/**
	* Sets the response event listener. @n
	* The listener is called when a response is received. To reset the event listener, @c null must be passed.
	*
	* @since 2.0
	*
	* @param[in] pResponseListener    The response event listener
	*/
	void SetChannelResponseEventListener(IChannelResponseEventListener* pResponseListener);

	/**
	 * Sends a request to the specific server channel of an application specified by the serverChannelId.
	 *
	 * @since 2.0
	 *
	 * @return       An error code
	 * @param[in]     serverChannelId    The server channel ID which can be either application ID or appicationID.ChannelName
	 * @param[in]     pArgs               A pointer to an argument list of type String
	 * @param[out]    reqId               The request ID
	 * @exception     E_SUCCESS           The method is successful.
	 * @exception     E_OBJ_NOT_FOUND     The server channel is not found.
	 * @exception     E_SYSTEM            The method cannot proceed due to a severe system error.
	 */
	result SendRequest(const Tizen::Base::String& serverChannelId, const Tizen::Base::Collection::IList* pArgs, RequestId& reqId);


private:
	/**
	* This default constructor is intentionally declared as private to implement the Singleton semantic.
	*/
	ClientChannel(void);

	/**
	* This destructor is intentionally declared as private to implement the Singleton semantic.
	*/
	virtual ~ClientChannel(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	ClientChannel(const ClientChannel& clientChannel);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	ClientChannel& operator =(const ClientChannel& clientChannel);

	static void InitSingleton(void);

	static void DestroySingleton(void);

	static ClientChannel* __pClientChannelInstance;

	friend class _ClientChannelImpl;

	class _ClientChannelImpl* __pClientChannelImpl;

}; // ClientChannel

} } // Tizen::Io

#endif //_FIO_CLIENT_CHANNEL_H_
