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
 * @file    FNetNfcINfcTagDiscoveryEventListener.h
 * @brief   This is the header file for the %INfcTagDiscoveryEventListener interface.
 *
 * This header file contains the declarations of the %INfcTagDiscoveryEventListener interface.
 */

#ifndef _FNET_NFC_INFC_TAG_DISCOVERY_EVENT_LISTENER_H_
#define _FNET_NFC_INFC_TAG_DISCOVERY_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Nfc
{

// Forward declaration
class TagConnection;

/**
 * @interface   INfcTagDiscoveryEventListener
 * @brief       This interface provides a listener for the events related to tag discovery.
 *
 * @since       2.0
 *
 * The %INfcTagDiscoveryEventListener interface specifies the methods used for creating the notifications about detecting the target tag.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ INfcTagDiscoveryEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~INfcTagDiscoveryEventListener(void) {}

	/**
	 * Called to notify the application when the tag is detected by the device.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pConnection         The connection established with the detected tag
	 * @remarks     TagConnection is inherited by NdefTagConnection if the current attached tag supports NDEF 
	 *              operations.
	 *              To verify this, use TagConnection::IsNdefConnection().
	 */
	virtual void OnNfcTagDetectedN(TagConnection* pConnection) = 0;

	/**
	 * Called to notify the application when the tag is lost by the device.
	 *
	 * @since       2.0
	 *
	 * @remarks     The operations of TagConnection returned by OnNfcTagDetectedN() are not processed further after 
	 *              this event is called, that is, the target tag is lost. Moreover, the TagConnection object cannot be 
	 *              reused even though the same tag is detected again by the device.
	 */
	virtual void OnNfcTagLost(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcTagDiscoveryEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcTagDiscoveryEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void INfcTagDiscoveryEventListener_Reserved3(void) {}
}; // INfcTagDiscoveryEventListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_INFC_TAG_DISCOVERY_EVENT_LISTENER_H_
