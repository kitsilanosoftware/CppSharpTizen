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
 * @file		FUiIKeypadEventListener.h
 * @brief		This is the header file for the %IKeypadEventListener interface.
 *
 * This header file contains the declarations of the %IKeypadEventListener interface.
 */
#ifndef _FUI_IKEYPAD_EVENT_LISTENER_H_
#define _FUI_IKEYPAD_EVENT_LISTENER_H_

// Includes
#include <FBaseRtIEventListener.h>
#include <FUiCtrlEditTypes.h>

namespace Tizen { namespace Graphics
{
class Dimension;
}} // Tizen::Graphics

// Namespace declaration
namespace Tizen { namespace Ui
{

class Control;

/**
 * @enum    KeypadAction
 *
 * Defines the possible keypad action types.
 *
 * @since		2.0
 */
enum KeypadAction
{
	KEYPAD_ACTION_ENTER,    /**< The Enter key */
	KEYPAD_ACTION_GO,       /**< The Go key */
	KEYPAD_ACTION_NEXT,     /**< The Next key */
	KEYPAD_ACTION_SEND,     /**< The Send key */
	KEYPAD_ACTION_SEARCH,   /**< The Search key */
	KEYPAD_ACTION_LOGIN,    /**< The Login key */
	KEYPAD_ACTION_SIGN_IN,  /**< The Sign-In key */
	KEYPAD_ACTION_JOIN,     /**< The Join key */
	KEYPAD_ACTION_DONE      /**< The Done key */
};

/**
 * @interface	IKeypadEventListener
 * @brief	    This interface implements the listener for the keypad events.
 *
 * @since	    2.0
 *
 * The %IKeypadEventListener interface is the listener interface for receiving software keypad events.
 * The class that processes a software keypad event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddKeypadEventListener() method. When the software keypad event occurs, a
 * method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>, <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_searchbar.htm">SearchBar</a> and <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.

 */
class _OSP_EXPORT_ IKeypadEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IKeypadEventListener(void) {}


// Operation
public:
	/**
	 * Called when the keypad is about to be shown on the screen.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @remarks		When the software keypad appears on the screen, the client area of the current Form is adjusted to account for the space that is taken
	 *              up by the software keypad.
	 * @see         Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadWillOpen(Tizen::Ui::Control& source) = 0;

	/**
	 * Called when the keypad is shown on the screen.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @remarks		When the software keypad appears on the screen, the client area of the current Form is adjusted to account for the space that is taken
	 *              up by the software keypad.
	 * @see			Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadOpened(Tizen::Ui::Control& source) = 0;

	/**
	 * Called when the keypad is hidden from the screen.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @see			Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadClosed(Tizen::Ui::Control& source) = 0;

	/**
	 * Called when the keypad action button is pressed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The source of the event
	 * @param[in]	keypadAction	The keypad action
	 * @see         KeypadAction
	 */
	virtual void OnKeypadActionPerformed(Tizen::Ui::Control& source, Tizen::Ui::KeypadAction keypadAction) = 0;

	/**
	 * Called when the keypad bounds are changed, for instance when the predictive text window which is located in the upper side of the keypad is shown.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @see			Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadBoundsChanged(Tizen::Ui::Control& source) {};

// Reserves
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IKeypadEventListener_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IKeypadEventListener_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IKeypadEventListener_Reserved3(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IKeypadEventListener_Reserved4(void) { }
}; // IKeypadEventListener
}} // Tizen::Ui

#endif // _FUI_IKEYPAD_EVENT_LISTENER_H_
