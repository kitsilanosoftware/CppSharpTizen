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
 * @file    FNetNfcINdefMessageDiscoveryEventListener.h
 * @brief   This is the header file for the %INdefMessageDiscoveryEventListener interface.
 *
 * This header file contains the declarations of the %INdefMessageDiscoveryEventListener interface.
 */

#ifndef _FNET_NFC_INDEF_MESSAGE_DISCOVERY_EVENT_LISTENER_H_
#define _FNET_NFC_INDEF_MESSAGE_DISCOVERY_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Nfc
{

// Forward declaration
class NdefMessage;

/**
 * @interface   INdefMessageDiscoveryEventListener
 * @brief       This interface provides a listener for the events related to the NDEF message discovery.
 *
 * @since       2.0
 *
 * The %INdefMessageDiscoveryEventListener interface specifies the methods used for creating notifications about the NDEF message discovered from the 
 * target tag.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ INdefMessageDiscoveryEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~INdefMessageDiscoveryEventListener(void) {}

	/**
	 * Called to notify the application when an NDEF message, that includes the NDEF records with the specified filter 
	 * type, is detected.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pMessage        The detected NDEF message
	 * @remarks     This method can be used for read-only access to the data on the target without opening a connection 
	 *              to it. @n
	 *              The input NdefMessage object must be deleted by the application after use, even outside this 
	 *              method. The NdefMessage::RemoveAllRecords() method must be called with @c true as the input value 
	 *              immediately before the NdefMessage object is deleted.
	 */
	virtual void OnNdefMessageDetectedN(NdefMessage* pMessage) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void INdefMessageDiscoveryEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void INdefMessageDiscoveryEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void INdefMessageDiscoveryEventListener_Reserved3(void) {}
}; // INdefMessageDiscoveryEventListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_INDEF_MESSAGE_DISCOVERY_EVENT_LISTENER_H_
