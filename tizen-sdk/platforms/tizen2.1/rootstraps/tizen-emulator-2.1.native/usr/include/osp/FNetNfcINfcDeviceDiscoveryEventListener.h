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
 * @file    FNetNfcINfcDeviceDiscoveryEventListener.h
 * @brief   This is the header file for the %INfcDeviceDiscoveryEventListener interface.
 *
 * This header file contains the declarations of the %INfcDeviceDiscoveryEventListener interface.
 */

#ifndef _FNET_NFC_INFC_DEVICE_DISCOVERY_EVENT_LISTENER_H_
#define _FNET_NFC_INFC_DEVICE_DISCOVERY_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseResult.h>

namespace Tizen { namespace Net { namespace Nfc
{

/**
 * @interface   INfcDeviceDiscoveryEventListener
 * @brief       This interface provides a listener for the events related to device discovery.
 * @since 2.0
 *
 * The %INfcDeviceDiscoveryEventListener interface specifies the methods used for creating the notifications
 * about detecting a device.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ INfcDeviceDiscoveryEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~INfcDeviceDiscoveryEventListener(void) {}

	/**
	 * Called to notify the application when a device is detected.
	 *
	 * @since 2.0
	 */
	virtual void OnNfcDeviceDetected(void) = 0;

	/**
	 * Called to notify the application when a device is lost.
	 *
	 * @since 2.0
	 */
	virtual void OnNfcDeviceLost(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void INfcDeviceDiscoveryEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void INfcDeviceDiscoveryEventListener_Reserved2(void) {}
}; // INfcDeviceDiscoveryEventListener

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_INFC_DEVICE_DISCOVERY_EVENT_LISTENER_H_
