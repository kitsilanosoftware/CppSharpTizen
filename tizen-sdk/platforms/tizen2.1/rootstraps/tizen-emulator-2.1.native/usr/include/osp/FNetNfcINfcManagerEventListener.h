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
 * @file    FNetNfcINfcManagerEventListener.h
 * @brief   This is the header file for the %INfcManagerEventListener interface.
 *
 * This header file contains the declarations of the %INfcManagerEventListener interface.
 */

#ifndef _FNET_NFC_INFC_MANAGER_EVENT_LISTENER_H_
#define _FNET_NFC_INFC_MANAGER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseResult.h>

namespace Tizen { namespace Net { namespace Nfc
{

/**
 * @interface   INfcManagerEventListener
 * @brief       This interface provides a listener for the events related to the Near field Communication (NFC)
 *              manager.
 *
 * @since       2.0
 *
 * The %INfcManagerEventListener interface specifies the method used for creating the notifications about a change in
 * the NfcManager status.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ INfcManagerEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~INfcManagerEventListener(void) {}

	/**
	 * Called to notify when the NFC feature is activated on the device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r               The activation status
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	virtual void OnNfcActivated(result r) = 0;

	/**
	 * Called to notify when the NFC feature is deactivated on the device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   r               The deactivation status
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	virtual void OnNfcDeactivated(result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcManagerEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcManagerEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcManagerEventListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcManagerEventListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and
	// consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcManagerEventListener_Reserved5(void) {}

}; // INfcManagerEventListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_INFC_MANAGER_EVENT_LISTENER_H_
