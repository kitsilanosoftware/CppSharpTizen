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

namespace Tizen {namespace Ui
{
class Control;
/**
 * @enum	KeyCode
 *
 * Defines the list of keys supported by the system. @n
 * Note that certain keys may not be available on all devices. @n
 * Please use the Tizen::Ui::KeyboardMap class to query the availability of a specific key on the target device.
 *
 * @since	2.0
 */
enum KeyCode
{
	/**
	 *	The invalid key
	 */
	KEY_INVALID		= 0x0000,

	/**
	 *	The up side key
	 */
	KEY_SIDE_UP,

	/**
	 *	The down side key
	 */
	KEY_SIDE_DOWN,

	/**
	 *	The Ok key
	 */
	KEY_OK,

	/**
	 *	The clear key
	 */
	KEY_CLEAR,

	/**
	 *	The camera key
	 */
	KEY_CAMERA,

	/**
	*	The task switcher key
	*/
	KEY_SWITCH,

	/**
	*	The 0 key
	*/
	KEY_0,

	/**
	*	The 1 key
	*/
	KEY_1,

	/**
	*	The 2 key
	*/
	KEY_2,

	/**
	*	The 3 key
	*/
	KEY_3,

	/**
	*	The 4 key
	*/
	KEY_4,

	/**
	*	The 5 key
	*/
	KEY_5,

	/**
	*	The 6 key
	*/
	KEY_6,

	/**
	*	The 7 key
	*/
	KEY_7,

	/**
	*	The 8 key
	*/
	KEY_8,

	/**
	*	The 9 key
	*/
	KEY_9,

	/**
	*	The asterisk key
	*/
	KEY_ASTERISK,

	/**
	*	The sharp key
	*/
	KEY_SHARP,

	/**
	*	The left directional key
	*/
	KEY_LEFT,

	/**
	*	The up directional key
	*/
	KEY_UP,

	/**
	*	The down directional key
	*/
	KEY_DOWN,

	/**
	*	The right directional key
	*/
	KEY_RIGHT,

	/*
	*	The Placeholder
	*/
	KEY_MAX,

	/**
	*	The A key
	*/
	KEY_A,

	/**
	*	The B key
	*/
	KEY_B,

	/**
	*	The C key
	*/
	KEY_C,

	/**
	*	The D key
	*/
	KEY_D,

	/**
	*	The E key
	*/
	KEY_E,

	/**
	*	The F key
	*/
	KEY_F,

	/**
	*	The G key
	*/
	KEY_G,

	/**
	*	The H key
	*/
	KEY_H,

	/**
	*	The I key
	*/
	KEY_I,

	/**
	*	The J key
	*/
	KEY_J,

	/**
	*	The K key
	*/
	KEY_K,

	/**
	*	The L key
	*/
	KEY_L,

	/**
	*	The M key
	*/
	KEY_M,

	/**
	*	The N key
	*/
	KEY_N,

	/**
	*	The O key
	*/
	KEY_O,

	/**
	*	The P key
	*/
	KEY_P,

	/**
	*	The Q key
	*/
	KEY_Q,

	/**
	*	The R key
	*/
	KEY_R,

	/**
	*	The S key
	*/
	KEY_S,

	/**
	*	The T key
	*/
	KEY_T,

	/**
	*	The U key
	*/
	KEY_U,

	/**
	*	The V key
	*/
	KEY_V,

	/**
	*	The W key
	*/
	KEY_W,

	/**
	*	The Y key
	*/
	KEY_Y,

	/**
	*	The X key
	*/
	KEY_X,

	/**
	*	The Z key
	*/
	KEY_Z,

	/**
	*	The backspace key
	*/
	KEY_BACKSPACE,

	/**
	*	The comma key
	*/
	KEY_COMMA,

	/**
	*	The enter key
	*/
	KEY_ENTER,

	/**
	*	The Caps Lock key
	*/
	KEY_CAPSLOCK,

	/**
	*	The Question key
	*/
	KEY_QUESTION,

	/**
	*	The Alt key
	*/
	KEY_ALT,

	/**
	*	The Language Symbol key
	*/
	KEY_SYM,

	/**
	*	The Language Setting key
	*/
	KEY_SETTING,

	/**
	*	The Space key
	*/
	KEY_SPACE,

	/**
	*	The Dot key
	*/
	KEY_DOT,

	/**
	*	The Function key
	*/
	KEY_FN,

	/**
	*	The camera half shutter key
	*/
	KEY_CAMERA_HALF_SHUTTER,

	/**
	*	The Character symbol 1 key
	*/
	KEY_CHAR_SYM_1,

	/**
	*	The Character symbol 2 key
	*/
	KEY_CHAR_SYM_2,

	/**
	* The Character symbol 3 key
	*/
	KEY_CHAR_SYM_3,

	/**
	*	The Character symbol 4 key
	*/
	KEY_CHAR_SYM_4,

	/**
	*	The Character symbol 5 key
	*/
	KEY_CHAR_SYM_5,

	/**
	*	The Character symbol 6 key
	*/
	KEY_CHAR_SYM_6,

	/**
	*	The Character symbol 7 key
	*/
	KEY_CHAR_SYM_7,

	/**
	*	The Character symbol 8 key
	*/
	KEY_CHAR_SYM_8,

	/**
	*	The Character symbol 9 key
	*/
	KEY_CHAR_SYM_9,

	/**
	*	The Character symbol A key
	*/
	KEY_CHAR_SYM_A,

	/**
	*	The Character symbol B key
	*/
	KEY_CHAR_SYM_B,

	/**
	*	The Character symbol C key
	*/
	KEY_CHAR_SYM_C,

	/**
	*	The Character symbol D key
	*/
	KEY_CHAR_SYM_D,

	/**
	*	The Character symbol E key
	*/
	KEY_CHAR_SYM_E,

	/**
	*	The Character symbol F key
	*/
	KEY_CHAR_SYM_F,

	/**
	*	The Special function 1 key
	*/
	KEY_FN_1,

	/**
	*	The Special function 2 key
	*/
	KEY_FN_2,

	/**
	*	The Special function 3 key
	*/
	KEY_FN_3,

	/**
	*	The Special function 4 key
	*/
	KEY_FN_4,

	/**
	*	The Special function 5 key
	*/
	KEY_FN_5,

	/**
	*        The power key
	*/
	KEY_POWER_HOLD,

	/**
	*		 The delete key
	*/
	KEY_DELETE,

	/*
	*	placeholder key
	*/
	KEY_HARDWARE_MAX
};


/**
 * @enum 	KeyState
 *
 *	Defines the state of the key.
 *
 * @since	2.0
 */
enum KeyState
{
	KEY_PRESSED = 0x0001,       /**< The key is pressed */
	KEY_RELEASED = 0x0002,      /**< The key is released */
	KEY_LONGPRESSED = 0x0003    /**< The key pressed and held down over a predefined duration */
};

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
 * registered with a UI control, using the control's AddKeyEventListener() method. When the key event occurs, a method of that
 * instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 *
 *
 */
class _OSP_EXPORT_ IKeyEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 *
	 */
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
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IKeyEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IKeyEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IKeyEventListener_Reserved3(void) {}

}; // IKeyEventListener

}} // Tizen::Ui

#endif //_FUI_IKEY_EVENT_LISTENER_H_
