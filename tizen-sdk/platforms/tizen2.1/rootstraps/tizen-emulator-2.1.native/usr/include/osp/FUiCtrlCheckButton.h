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
 * @file	FUiCtrlCheckButton.h
 * @brief	This is the header file for the %CheckButton class.
 *
 * This header file contains the declarations of the %CheckButton class and its helper classes.
 */

#ifndef _FUI_CTRL_CHECK_BUTTON_H_
#define _FUI_CTRL_CHECK_BUTTON_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlButton.h>
#include <FUiCtrlControlsTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum CheckButtonStatus
 *
 * Defines the %CheckButton status.
 *
 * @since	2.0
 */
enum CheckButtonStatus
{
	CHECK_BUTTON_STATUS_NORMAL,         /**< The normal status */
	CHECK_BUTTON_STATUS_DISABLED,       /**< The disabled status */
	CHECK_BUTTON_STATUS_PRESSED,        /**< The pressed status */
	CHECK_BUTTON_STATUS_HIGHLIGHTED     /**< The highlighted status */
};

/**
 * @enum CheckButtonStyle
 *
 * Defines the %CheckButton style.
 *
 * @since	2.0
 */
enum CheckButtonStyle
{
	CHECK_BUTTON_STYLE_MARK,                        /**< The mark style for multiple selection */
	CHECK_BUTTON_STYLE_MARK_WITH_DIVIDER,           /**< @if OSPDEPREC @deprecated This enum value is deprecated because the use of the divider style is no longer recommended @n
				                                             Instead of using the divider style, use the detailed button style. @endif */
	CHECK_BUTTON_STYLE_ONOFF,                       /**< @if OSPDEPREC @deprecated This enum value is deprecated because the use of the on-off style is no longer recommended @n
				                                             Instead of using the on-off style, use the on-off sliding style @endif*/
	CHECK_BUTTON_STYLE_ONOFF_WITH_DIVIDER,          /**< @if OSPDEPREC @deprecated This enum value is deprecated because the use of the on-off style is no longer recommended @endif */
	CHECK_BUTTON_STYLE_RADIO,                       /**< The radio style for single selection */
	CHECK_BUTTON_STYLE_RADIO_WITH_DIVIDER,          /**< @if OSPDEPREC @deprecated This enum value is deprecated because the use of the divider style is no longer recommended @n
				                                             Instead of using the divider style, use the detailed button style @endif*/
	CHECK_BUTTON_STYLE_ONOFF_SLIDING,               /**< The slider style on/off */
	CHECK_BUTTON_STYLE_MARK_WITH_DETAILED_BUTTON,   /**< The mark style with detail button */
	CHECK_BUTTON_STYLE_RADIO_WITH_DETAILED_BUTTON,  /**< The radio style with detail button */
	CHECK_BUTTON_STYLE_ONOFF_SLIDING_WITH_DIVIDER,  /**< The slider style On/Off with divider @b Since: @b 2.1 */
};

/**
 * @class	CheckButton
 * @brief	This class defines the common behavior of a %CheckButton control.
 *
 * @since	2.0
 *
 * The %CheckButton class displays a rectangular area, which can be selected, and shows the current selection.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_button.htm">Buttons</a>.
 *
 * The following example demonstrates how to use the %CheckButton class.
 *
 *
 * @code
// Sample code for CheckButtonSample.h
#include <FUi.h>

class CheckButtonSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	CheckButtonSample(void)
	: __pCheckButton(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private :
	static const int ID_BUTTON_CHECKED   = 101;
	static const int ID_BUTTON_UNCHECKED = 102;
	static const int ID_BUTTON_SELECTED  = 103;

	Tizen::Ui::Controls::CheckButton* __pCheckButton;
};

 *	@endcode
 *
 *	@code
// Sample Code for CheckButtonSample.cpp
#include <FGraphics.h>

#include "CheckButtonSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
CheckButtonSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
CheckButtonSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates a CheckButton
	__pCheckButton = new CheckButton();
	__pCheckButton->Construct(Rectangle(50, 50, 400, 100),
			CHECK_BUTTON_STYLE_RADIO_WITH_DIVIDER, BACKGROUND_STYLE_DEFAULT, false, L"CheckButton");
	__pCheckButton->SetActionId(ID_BUTTON_CHECKED, ID_BUTTON_UNCHECKED, ID_BUTTON_SELECTED);
	__pCheckButton->AddActionEventListener(*this);

	// Add a CheckButton to the Form
	AddControl(__pCheckButton);

	return r;
}

// Implements an IActionEventListener
void
CheckButtonSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON_CHECKED:
		// Todo:
		break;
	case ID_BUTTON_UNCHECKED:
		// Todo:
		break;
	case ID_BUTTON_SELECTED:
		// Todo:
		break;
	default:
		break;
	}
}

 * @endcode
 *
 */
class _OSP_EXPORT_ CheckButton
	: public Tizen::Ui::Control
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CheckButton(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~CheckButton(void);

	/**
	 * Initializes this instance of %CheckButton with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Tizen::Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window
	 *									along with the width and height of the window.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	style				The style of the %CheckButton control
	 * @param[in]	backgroundStyle		The background style set of the %CheckButton control
	 * @param[in]   showTitle		Set to @c true to enable the title, @n
	 *								else @c false
	 * @param[in]   text				The text of the %CheckButton control
	 * @param[in]   groupStyle			The group style of the %CheckButton control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.@n
	 *									The specified size is less than the minimum size of the control.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  The background style of @c BACKGROUND_STYLE_NONE does not work with group styles except ::GROUP_STYLE_NONE.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, CheckButtonStyle style, BackgroundStyle backgroundStyle =
						 BACKGROUND_STYLE_DEFAULT, bool showTitle = false, const Tizen::Base::String& text = L"", GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Initializes this instance of %CheckButton with the specified parameters.
	 *
     * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Tizen::Graphics::FloatRectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window
	 *									along with the width and height of the window.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	style				The style of the %CheckButton control
	 * @param[in]	backgroundStyle		The background style set of the %CheckButton control
	 * @param[in]   showTitle		Set to @c true to enable the title, @n
	 *								else @c false
	 * @param[in]   text				The text of the %CheckButton control
	 * @param[in]   groupStyle			The group style of the %CheckButton control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.@n
	 *									The specified size is less than the minimum size of the control.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  The background style of @c BACKGROUND_STYLE_NONE does not work with group styles except ::GROUP_STYLE_NONE.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, CheckButtonStyle style, BackgroundStyle backgroundStyle =
							 BACKGROUND_STYLE_DEFAULT, bool showTitle = false, const Tizen::Base::String& text = L"", GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Sets the selected status of the %CheckButton control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	select	Set to @c true if the %CheckButton control is selected, @n
	 *				else @c false
	 */
	void SetSelected(bool select);

	/**
	 * Checks whether the %CheckButton control has been selected.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the %CheckButton is selected, @n
	 *				else @c false
	 */
	bool IsSelected(void) const;

public:
	/**
	 * Adds an IActionEventListener instance. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Sets the action IDs for the %CheckButton control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   checkedActionId			The action ID for the checked state
	 * @param[in]   uncheckedActionId		The action ID for the unchecked state
	 * @param[in]   selectedActionId		The action ID for the selected state
	 */
	void SetActionId(int checkedActionId, int uncheckedActionId, int selectedActionId = -1);

	/**
	 * Gets the action ID for the checked state.
	 *
	 * @since		2.0
	 *
	 * @return		An integer value representing the action ID
	 */
	int GetCheckedActionId(void) const;

	/**
	 * Gets the action ID for the unchecked state.
	 *
	 * @since		2.0
	 *
	 * @return		An integer value representing the action ID
	 */
	int GetUncheckedActionId(void) const;

	/**
	 * Gets the action ID for the selected state.
	 *
	 * @since		2.0
	 *
	 * @return		An integer value representing the action ID
	 */
	int GetSelectedActionId(void) const;

public:
	/**
	 * Sets the text that the %CheckButton control displays.
	 *
	 * @since		2.0
	 *
	 * @param[in]   text	The text of the %CheckButton control
	 */
	void SetText(const Tizen::Base::String& text);

	/**
	 * Sets the horizontal alignment of the text of the %CheckButton control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   alignment	The horizontal text alignment
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Sets the vertical alignment of the text of the %CheckButton control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   alignment	The vertical text alignment
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

public:
	/**
	 * Gets the text of the %CheckButton control.
	 *
	 * @since	2.0
	 *
	 * @return	The text of the %CheckButton control
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets the horizontal alignment of the text of the %CheckButton control.
	 *
	 * @since	2.0
	 * @return	The horizontal text alignment
	 */
	HorizontalAlignment GetTextHorizontalAlignment(void) const;

	/**
	 * Gets the vertical alignment of the text of the %CheckButton control.
	 *
	 * @since	2.0
	 * @return	The vertical text alignment
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;

	/**
	 * Sets the title text of the %CheckButton control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]   title				The title text to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTitleText(const Tizen::Base::String& title);

	/**
	 * Gets the title text of the %CheckButton control.
	 *
	 * @since		2.0
	 * @return		The title text
	 */
	Tizen::Base::String GetTitleText(void) const;

	//Normal color
	/**
	 * Sets the text color of the %CheckButton control.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color   The text color to set
	 */
	void SetTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control.
	 *
	 * @since			2.0
	 *
	 * @return    The text color
	 */
	Tizen::Graphics::Color GetTextColor(void) const;

	//Normal color
	/**
	 * Sets the title text color of the %CheckButton control.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color   The text color to set
	 */
	void SetTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of the %CheckButton control.
	 *
	 * @since			2.0
	 *
	 * @return		The text color
	 */
	Tizen::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * Sets the color of the %CheckButton control for the specified status.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]	color					The color to set
	 * @param[in]   status                  The status
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.@n
	 *										The operation is not supported if the background style is ::BACKGROUND_STYLE_NONE.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetColor(CheckButtonStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the %CheckButton control for the specified status.
	 *
	 * @since       2.0
	 * @return      The color, @n
	 *				else RGBA (0, 0, 0, 0) if an error occurs
	 * @param[in]   status              The status
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The background style is not proper.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(CheckButtonStatus status) const;

	/**
	 * Sets the text color of the %CheckButton control for the pressed status.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in]	color				The text color to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetPressedTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control for the pressed status.
	 *
	 * @since      2.0
	 * @return     The text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetPressedTextColor(void) const;

	/**
	 * Sets the title text color of the %CheckButton control for the pressed status.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] color				The pressed title text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetPressedTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of the %CheckButton for the pressed status.
	 *
	 * @since      2.0
	 *
	 * @return     The title text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetPressedTitleTextColor(void) const;

	/**
	 * Sets the text color of the %CheckButton control for the highlighted status.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in]	color				The text color to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetHighlightedTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control for the highlighted status.
	 *
	 * @since      2.0
	 *
	 * @return     The text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetHighlightedTextColor(void) const;

	/**
	 * Sets the title text color of the %CheckButton control for the highlighted status.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] color				The highlighted title text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetHighlightedTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of the %CheckButton control for the highlighted status.
	 *
	 * @since      2.0
	 *
	 * @return     The title text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetHighlightedTitleTextColor(void) const;

	/**
	 * Sets the text color of the %CheckButton control for the disabled status.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in]	color				The text color to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetDisabledTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control for the disabled status.
	 *
	 * @since      2.0
	 *
	 * @return     The text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetDisabledTextColor(void) const;

	/**
	 * Sets the title text color of the %CheckButton control for the disabled status.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] color                The disabled title text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetDisabledTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of %CheckButton for the disabled status.
	 *
	 * @since      2.0
	 *
	 * @return     The title text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetDisabledTitleTextColor(void) const;

protected:
	friend class _CheckButtonImpl;

private:
	friend class RadioGroup;

	//
	// This is the copy constructor for this class.
	//
	CheckButton(const CheckButton& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %CheckButton.
	//
	CheckButton& operator =(const CheckButton& rhs);

}; // CheckButton

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_CHECK_BUTTON_H_
