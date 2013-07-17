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
 * @file		FUiIKeyEventListener.h
 * @brief		This is the header file for the %IKeyEventListener interface.
 *
 * This header file contains the declarations of the %IKeyEventListener interface. @n
 * If a key event is generated, a method of this interface is called. @n
 * If an application performs tasks related to the key event, use the methods of this interface.
 */
#ifndef _FUI_IKEY_EVENT_LISTENER_H_
#define _FUI_IKEY_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseTypes.h>
#include <FUiKeyTypes.h>

namespace Tizen {namespace Ui
{
class Control;

/**
 * @interface	IKeyEventListener
 * @brief		This interface implements the listener for the key event.
 *
 * @since		2.0
 *
 * @remarks	Use the ITextEventListener interface to listen to key events related to the virtual keypad used with EditField and EditArea.
 *
 * The %IKeyEventListener interface is the listener interface for receiving key events, which are fired when hardware keyboard keys are pressed or
 * released. The class that processes a key event implements this interface, and the instance created with that class is
 * registered with a UI control, using the Control::AddKeyEventListener() method. When the key event occurs, a method of that
 * instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 *
 *
 */
class _OSP_EXPORT_ IKeyEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	 //
	 // This method is for internal use only.
	 // Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	 //
	 // This is the destructor for this class.
	 //
	 // @since				2.0
	 //
	virtual ~IKeyEventListener(void) {}


	/**
	 * Called when a key is pressed.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	keyCode		The key code
	 */
	virtual void OnKeyPressed(const Tizen::Ui::Control& source, Tizen::Ui::KeyCode keyCode) = 0;


	/**
	 * Called when a key is released.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	keyCode		The key code
	 */
	virtual void OnKeyReleased(const Tizen::Ui::Control& source, Tizen::Ui::KeyCode keyCode) = 0;


	/**
	 * Called when a key is pressed and held down for some time.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	keyCode		The key code
	 * @remarks	The key long pressed event is fired after the key pressed event is initially generated.
	 */
	virtual void OnKeyLongPressed(const Tizen::Ui::Control& source, Tizen::Ui::KeyCode keyCode) = 0;

protected:
	// Reserved virtual methods for later extension
	//
	//  The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IKeyEventListener_Reserved1(void) {}

	// Reserved virtual methods for later extension
	//
	//  The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IKeyEventListener_Reserved2(void) {}

	// Reserved virtual methods for later extension
	//
	//  The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IKeyEventListener_Reserved3(void) {}

}; // IKeyEventListener

} } // Tizen::Ui

#endif //_FUI_IKEY_EVENT_LISTENER_H_