//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file			FUiIFocusEventListener.h
 * @brief		This is the header file for the %IFocusEventListener interface.
 *
 * This header file contains the declarations of the %IFocusEventListener interface.
 */

#ifndef _FUI_IFOCUS_EVENT_LISTENER_H_
#define _FUI_IFOCUS_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{

class Control;

/**
 * @enum		FocusStatus
 *
 * Defines constants used to identify focus status.
 *
 * @since		2.0
 *
 */

enum FocusStatus
{
	FOCUS_GAINED = 0,   // The Control has gained focus
	FOCUS_LOST = 1      // The Control has lost focus
};

/**
 * @interface		IFocusEventListener
 * @brief			This interface is used as the argument to focus the event listener.
 *
 * @since			2.0
 *
 * The %IFocusEventListener interface is the listener interface for receiving focus events.
 * The class that processes a focus event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control's AddFocusEventListener() method. When the focus event occurs, a method of that instance is
 * invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ IFocusEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 *
	 */
	virtual ~IFocusEventListener(void) {}

	/**
	 * Called when Control gains the input focus.
	 *
	 * @since				2.0
	 *
	 * @param[in]   source		The source of the event
	 */
	virtual void OnFocusGained(const Tizen::Ui::Control& source) = 0;

	/**
	 * Called when Control loses the input focus.
	 *
	 * @since				2.0
	 *
	 * @param[in]   source		The source of the event
	 */
	virtual void OnFocusLost(const Tizen::Ui::Control& source) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IFocusEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IIFocusEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IIFocusEventListener_Reserved3(void) {}
}; // IFocusEventListener

}} // Tizen::Ui

#endif // _FUI_IFOCUS_EVENT_LISTENER_H_
