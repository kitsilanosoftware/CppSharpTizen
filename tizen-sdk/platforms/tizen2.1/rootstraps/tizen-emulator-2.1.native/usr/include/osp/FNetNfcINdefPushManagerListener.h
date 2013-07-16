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
// WITHOUT  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file    FNetNfcINdefPushManagerListener.h
 * @brief   This is the header file for the %INdefPushManagerListener interface.
 *
 * This header file contains the declarations of the %INdefPushManagerListener interface.
 */

#ifndef _FNET_NFC_INDEF_PUSH_MANAGER_LISTENER_H_
#define _FNET_NFC_INDEF_PUSH_MANAGER_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseResult.h>

namespace Tizen { namespace Net { namespace Nfc
{
/**
 * @interface   INdefPushManagerListener
 * @brief       This interface provides a listener for the events related to the %NfcPushManager.
 * @since 2.0
 *
 * The %INdefPushManagerListener interface specifies the methods used for receiving the status of the pushed NDEF
 * message asynchronously.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ INdefPushManagerListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~INdefPushManagerListener(void) {}

	/**
	 * Called when the push operation to the target device is completed.
	 *
	 * @since 2.0
	 *
	 * @param[in]   r                   The result of pushed NDEF message @n
	 *                                  The following exceptions may be given through this parameter.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_NOT_RESPONDING    The device is not responding.
 	 * @exception   E_OPERATION_FAILED  The operation has failed.
	 */
	virtual void OnNdefPushMessageSent(result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void INdefPushManagerListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void INdefPushManagerListener_Reserved2(void) {}
}; // INdefPushManagerListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_INDEF_PUSH_MANAGER_LISTENER_H_
