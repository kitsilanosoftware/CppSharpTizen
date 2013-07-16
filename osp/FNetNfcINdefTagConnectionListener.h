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
 * @file    FNetNfcINdefTagConnectionListener.h
 * @brief   This is the header file for the %INdefTagConnectionListener interface.
 *
 * This header file contains the declarations of the %INdefTagConnectionListener interface.
 */

#ifndef _FNET_NFC_INDEF_TAG_CONNECTION_LISTENER_H_
#define _FNET_NFC_INDEF_TAG_CONNECTION_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseResult.h>

namespace Tizen { namespace Net { namespace Nfc
{

class NdefMessage;

/**
 * @interface   INdefTagConnectionListener
 * @brief       This interface provides a listener for the events related to the NDEF tag connection.
 *
 * @since       2.0
 *
 * The %INdefTagConnectionListener interface specifies the methods used for creating the notifications about the result
 * of an action for the NdefTagConnection, such as reading and writing the NDEF data.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ INdefTagConnectionListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~INdefTagConnectionListener(void) {}

	/**
	 * Called to notify the application when the read operation from the target tag is completed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pMessage                The read NdefMessage object, @n
	 *                                      else @c null if the method is not successful
	 * @param[in]   r                       An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_DATA_NOT_FOUND        The target tag has no NDEF record.
	 * @exception   E_INVALID_FORMAT        The read data cannot be formulated to the NDEF message.
	 * @exception   E_NOT_RESPONDING        The target tag is not responding.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     The input NdefMessage object must be deleted by the application after use, even outside this
	 *              method. The NdefMessage::RemoveAllRecords() method must be called with @c true as the input value
	 *              right before the %NdefMessage object is deleted.
	 * @see         NdefTagConnection::Read()
	 */
	virtual void OnNdefReadCompletedN(NdefMessage* pMessage, result r) = 0;

	/**
	 * Called to notify the application when the write operation on the target tag is completed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r                       An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_ILLEGAL_ACCESS        The write operation on the target tag is denied. @n
	 *                                      The target tag is locked or protected for the write operation.
	 * @exception   E_STORAGE_FULL          The storage capacity of the target tag is full.
	 * @exception   E_NOT_RESPONDING        The target tag is not responding.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         NdefTagConnection::Write()
	 */
	virtual void OnNdefWriteCompleted(result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void INdefTagConnectionListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void INdefTagConnectionListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void INdefTagConnectionListener_Reserved3(void) {}
}; // INdefTagConnectionListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_INDEF_TAG_CONNECTION_LISTENER_H_
