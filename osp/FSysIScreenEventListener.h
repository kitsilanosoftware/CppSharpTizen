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
 * @file	FSysIScreenEventListener.h
 * @brief	This is the header file of the %IScreenEventListener interface.
 *
 * This header file contains the declarations of the %IScreenEventListener interface.
 */

#ifndef _FSYS_ISCREEN_EVENT_LISTENER_H_
#define _FSYS_ISCREEN_EVENT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace System
{

/**
 * @interface	IScreenEventListener
 * @brief	This interface is the listener of the screen event.
 *
 * @since	2.0
 *
 * The %IScreenEventListener interface must be registered and implemented by an application to receive screen events from the system.
 *
 */
class _OSP_EXPORT_ IScreenEventListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * Called when the screen turns on. @n
	 * Gets the released resources or resumes the operations that were paused or stopped in OnScreenOff().
	 *
	 * @since 2.0
	 */
	virtual void OnScreenOn(void) = 0;

	/**
	 * Called when the screen turns off. @n
	 * Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	 *Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	 *Similarly, do not perform lengthy operations in this listener method. All operations must be quick ones.
	 *
	*@since 2.0
	 */
	virtual void OnScreenOff(void) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnIScreenEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnIScreenEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnIScreenEventListener_Reserved3(void) {}

}; // IScreenEventListener

} } // Tizen::System

#endif // _FSYS_ISCREEN_EVENT_LISTENER_H_
