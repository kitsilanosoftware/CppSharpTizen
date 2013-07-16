//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FUiITouchModeChangedEventListener.h
 * @brief		This is the header file for the %ITouchModeChangedEventListener interface.
 *
 * This header file contains the declarations of the %ITouchModeChangedEventListener interface. @n
 * If the touch mode of a device is changed, a method of this interface is called.
 * Therefore, if an application performs tasks related to the touch mode event, use the methods of this interface.
 *
 */

#ifndef _FUI_ITOUCH_MODE_CHANGED_EVENT_LISTENER_H_
#define _FUI_ITOUCH_MODE_CHANGED_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen {namespace Ui
{
class Control;

/**
 * @interface		ITouchModeChangedEventListener
 * @brief			This interface implements the listener for the touch mode changed event.
 *
 * @since	    2.0
 *
 * The %ITouchModeChangedEventListener interface is the listener interface for receiving touch mode change events.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ ITouchModeChangedEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since				2.0
	 */
	virtual ~ITouchModeChangedEventListener(void) {};

	/**
	 * Called when an action event occurs.
	 *
	 * @since				2.0
	 *
	 * @param[in]   source		    The source of the event
	 * @param[in]   isInTouchMode	The current mode
	 */
	virtual void OnTouchModeChanged(const Tizen::Ui::Control& source, bool isInTouchMode) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchModeChangedEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchModeChangedEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchModeChangedEventListener_Reserved3(void) {}

}; // ITouchModeChangedEventListener

} } // Tizen::Ui

#endif // _FUI_ITOUCH_MODE_CHANGED_EVENT_LISTENER_H_
