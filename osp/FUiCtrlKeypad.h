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
* @file		FUiCtrlKeypad.h
* @brief	This is the header file for the %Keypad class.
*
* This header file contains the declarations of the %Keypad class.
*/

#ifndef _FUI_CTRL_KEYPAD_H_
#define _FUI_CTRL_KEYPAD_H_

#include <FUiCtrlInputTypes.h>
#include <FUiCtrlEditTypes.h>
#include <FUiCtrlIEditTextFilter.h>
#include <FUiITextEventListener.h>
#include <FUiWindow.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
* @if OSPDEPREC
* @enum     KeypadInputModeCategory
*
* Defines the keypad input mode.
*
* @brief	<i> [Deprecated] </i>
* @deprecated We no longer provide a method to specify the list of styles which the user can set the keypad to, @n
*			  or the current mode to initially set the keypad to, from this list. It is recommended to use the styles offered KeypadStyle enumeration instead.
* @since		2.0
* @endif
*/
enum KeypadInputModeCategory
{
	KEYPAD_MODE_ALPHA = 0x0001,                             /**< @if OSPDEPREC The alphabetic input mode @endif */
	KEYPAD_MODE_PREDICTIVE = 0x0002,                        /**< @if OSPDEPREC The predictive input mode @endif */
	KEYPAD_MODE_NUMERIC = 0x0004,                           /**< @if OSPDEPREC The numeric input mode @endif */
	KEYPAD_MODE_SYMBOL = 0x0008                             /**< @if OSPDEPREC The symbolic input mode @endif */
};

/**
* @class	Keypad
* @brief	This class displays a keypad on top of the screen.
*
* @since	2.0
*
* The %Keypad class displays the full screen keypad without using an EditField or EditArea.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_keypad.htm">Keypad</a>.
*
* The following example demonstrates how to use the %Keypad class.
*
* @code
// Sample code for KeypadSample.h
#include <FUi.h>

class KeypadSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::ITextEventListener
{
public:
	KeypadSample(void)
	: __pKeypad(null){}

	bool Initialize(void);
	void ShowKeypad(bool show);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	// ITextEventListener
	virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);


private:
	static const int ID_BUTTON  = 101;

	Tizen::Ui::Controls::Keypad *__pKeypad;
};

// Sample code for KeypadSample.cpp
#include "KeypadSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
KeypadSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
KeypadSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Button and adds it to the form
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 50, 150, 150), L"Show Keypad");
	pButton->SetActionId(ID_BUTTON);
	pButton->AddActionEventListener(*this);
	AddControl(pButton);

	// Creates an instance of Keypad
	__pKeypad = new Keypad();
	__pKeypad->Construct(KEYPAD_STYLE_NORMAL, KEYPAD_MODE_ALPHA);

	// Adds an instance of ITextEventListener
	__pKeypad->AddTextEventListener(*this);

	return r;
}

void
KeypadSample::ShowKeypad(bool show)
{
	// Changes to desired show state
	__pKeypad->SetShowState(show);

	//Calls Show() of the control
	if (show)
	{
		__pKeypad->Show();
	}
	// Calls Invalidate() of the container
	else
	{
		Invalidate(true);
	}
}

result
KeypadSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the keypad
	__pKeypad->Destroy();

	return r;
}

// IActionEventListener implementation
void
KeypadSample::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON:
		{
			ShowKeypad(true);
		}
		break;

	default:
		break;
	}
}

// ITextEventListener implementation
void
KeypadSample::OnTextValueChanged(const Tizen::Ui::Control& source)
{
	// ....
}

void
KeypadSample::OnTextValueChangeCanceled(const Tizen::Ui::Control& source)
{
	// ....
}
* @endcode
*/

class _OSP_EXPORT_ Keypad
	: public Tizen::Ui::Window
{
//Lifecycle
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	Keypad(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~Keypad(void);

	/**
	 * Initializes this instance of %Keypad with the specified parameters.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   keypadStyle	        The style of %Keypad
	 * @param[in]   limitLength         The limit of the length of text in EditField
	 * @exception   E_SUCCESS	        The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid, or @n
	 *									the specified @c limitLength is less than or equal to @c 0.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks
	 *			- If the keypad style is set to password, the input mode category is ignored.
	 *			- The orientation mode of the keypad is decided based on the G-sensor value.
	 *			- The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(KeypadStyle keypadStyle, int limitLength);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %Keypad with input styles.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated We no longer provide a method to specify the list of styles which the user can set the keypad to. @n
	 *			   It is recommended to use the other Construct() method and the KeypadStyle enumeration instead.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	keypadStyle		    The style of %Keypad
	 * @param[in]	category		    The initial category that the keypad would show first
	 * @param[in]   limitLength		    The limit of the length of text in EditField
	 * @exception	E_SUCCESS	        The method is successful.
	 * @exception	E_INVALID_ARG	    A specified input parameter is invalid, or @n
	 *									the specified @c limitLength is less than or equal to @c 0.
	 * @exception	E_SYSTEM	        A system error has occurred.
	 * @remarks
	 *			- If the keypad style is set to password, the input mode category is ignored.
	 *			- The orientation mode of the keypad is decided based on the G-sensor value.
	 * @endif
	 */
	result Construct(KeypadStyle keypadStyle, KeypadInputModeCategory category, int limitLength = 100);

	/**
	* Checks whether the text prediction is enabled.
	*
	* @since 2.0
	* @return                @c true if the text prediction is enabled, @n
	*                                 else @c false
	* @see                      SetTextPredictionEnabled()
	*/
	bool IsTextPredictionEnabled(void) const;

	/**
	* Enables or disables the text prediction.
	*
	* @since 2.0
	* @param[in]           enable                       Set to @c true to enable the text prediction, @n
	*                                                                    else @c false
	* @return                An error code
	* @exception           E_SUCCESS                The method is successful.
	* @exception		E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @see                      IsTextPredictionEnabled()
	*/
	result SetTextPredictionEnabled(bool enable);

	/**
	 * Enables single-line editing.
	 *
	 * @since          2.0
	 *
	 * @return         An error code
	 * @param[in]      enabled                      Set to @c true to enable single-line editing, @n
	 *												else @c false
	 * @exception      E_SUCCESS                    The method is successful.
	 * @exception      E_INVALID_OPERATION          The current state of the instance prohibits the execution of the specified operation. @n
	 *                                              The %Keypad control is currently visible.
	 * @exception      E_UNSUPPORTED_OPERATION      The current state of the instance does not support the execution of the specified operation. @n
	 *                                              The password style does not support multi-line editing.
	 * @exception      E_SYSTEM                     A system error has occurred.
	 * @remarks        By default, the single-line editing is disabled and the %Keypad control supports multi-lines (except the password style that only supports single-line editing).
	 */
	result SetSingleLineEnabled(bool enabled);

	/**
	 * Checks whether single-line editing is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if single-line editing is enabled, @n
	 *				else @c false
	 */
	bool IsSingleLineEnabled(void) const;

	/**
	 * Adds a ITextEventListener instance. @n
	 * The added listener can listen to text changed events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The listener to add
	 */
	void AddTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Removes a ITextEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The listener to remove
	 */
	void RemoveTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Gets the text of the %Keypad control.
	 *
	 * @since		2.0
	 *
	 * @return		The string value
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Sets the text of the %Keypad control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	text	The text to set
	 */
	void SetText(Tizen::Base::String text);

	/**
	 * Sets the text filter.
	 *
	 * @since		2.1
	 *
	 * @param[in]		pFilter The filter
	 * @remarks 	The %Keypad control checks with the registered filter to decide whether the user-entered text should be replaced.
	 */
	void  SetEditTextFilter(IEditTextFilter* pFilter);

	/**
	* Sends opaque command to the input method.
	*
	* @since     2.1
	*
	* @param[in] command            The opaque command
	* @remarks
	*			- This method can be used to provide domain-specific features that are only known between certain input methods and their clients.
	*			- This method may not work, depending on the active Input Method.
	*/
	void SendOpaqueCommand (const Tizen::Base::String& command);

protected:
	friend class _KeypadImpl;

private:
	Keypad(const Keypad&);
	Keypad& operator =(const Keypad&);

}; // Keypad

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_KEYPAD_H_
