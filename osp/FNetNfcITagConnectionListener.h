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
 * @file    FNetNfcITagConnectionListener.h
 * @brief   This is the header file for the %ITagConnectionListener interface.
 *
 * This header file contains the declarations of the %ITagConnectionListener interface.
 */

#ifndef _FNET_NFC_ITAG_CONNECTION_LISTENER_H_
#define _FNET_NFC_ITAG_CONNECTION_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseResult.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Net { namespace Nfc
{

/**
 * @interface    ITagConnectionListener
 * @brief        This interface provides a listener for the events related to the tag connection.
 *
 * @since        2.0
 *
 * The %ITagConnectionListener interface provides methods that are used for creating notifications for the result of the actions of the 
 * TagConnection, such as sending a command.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ ITagConnectionListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~ITagConnectionListener(void) {}

	/**
	 * Called to notify the application when the response is received from the remote tag.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pResponse           The response of the command as the ByteBuffer object, @n
	 *                                  else @c null if the method is not successful
	 * @param[in]   r                   An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_ILLEGAL_ACCESS    The sent command is denied by the target. @n
	 *                                  The target tag is locked or protected for executing the command.
	 * @exception   E_NOT_RESPONDING    The target tag is not responding.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         TagConnection::SendCommand()
	 * @remarks     The input response (@c pResponse) must be deleted by the application to prevent memory leak.
	 */
	virtual void OnNfcResponseReceivedN(Tizen::Base::ByteBuffer* pResponse, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITagConnectionListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITagConnectionListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITagConnectionListener_Reserved3(void) {}
}; // ITagConnectionListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_ITAG_CONNECTION_LISTENER_H_
