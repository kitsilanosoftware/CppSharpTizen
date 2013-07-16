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
 * @file	FSysIDeviceEventListener.h
 * @brief	This is the header file for the %IDeviceEventListener interface.
 *
 * This header file contains the declarations of the %IDeviceEventListener interface.
 */

#ifndef _FSYS_IDEVICE_EVENT_LISTENER_H_
#define _FSYS_IDEVICE_EVENT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>
#include <FSysDeviceManager.h>

namespace Tizen { namespace System
{

/**
 * @interface	IDeviceEventListener
 * @brief	This interface is the listener of the device state changes.
 *
 * @since	2.0
 *
 * The %IDeviceEventListener interface must be registered and implemented by an application to receive device events from the system.
 *
 * @see DeviceManager
 */
class _OSP_EXPORT_ IDeviceEventListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class. This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IDeviceEventListener(void) {}

	/**
	* Called when a device state is changed.
	*
	* @since	2.0
	*
	* @param[in]	deviceType	The types of a device
	* @param[in]	state		The device state of type Tizen::Base::String
	*/
	virtual void OnDeviceStateChanged(DeviceType deviceType, const Tizen::Base::String& state) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnIDeviceEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnIDeviceEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnIDeviceEventListener_Reserved3(void) {}

}; // IDeviceEventListener

} } // Tizen::System

#endif // _FSYS_IDEVICE_EVENT_LISTENER_H_
