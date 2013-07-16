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
 * @file	FUiCtrlEditArea.h
 * @brief	This is the header file for the %EditArea class.
 *
 * This header file contains the declarations of the %EditArea class and its helper classes.
 */

#ifndef _FUI_CTRL_EDIT_AREA_H_
#define _FUI_CTRL_EDIT_AREA_H_

#include <FBaseString.h>
#include <FBaseCharacter.h>
#include <FGrpBitmap.h>
#include <FGrpColor.h>
#include <FGrpPoint.h>
#include <FGrpRectangle.h>
#include <FUiContainer.h>
#include <FUiControl.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlEditTypes.h>
#include <FUiCtrlIEditTextFilter.h>
#include <FUiCtrlInputTypes.h>
#include <FUiIActionEventListener.h>
#include <FUiIKeypadEventListener.h>
#include <FUiILanguageEventListener.h>
#include <FUiIScrollPanelEventListener.h>
#include <FUiITextBlockEventListener.h>
#include <FUiITextEventListener.h>
#include <FUiIUiLinkEventListener.h>

namespace Tizen { namespace Locales
{
class Locale;
}} // Tizen::Locales

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	EditArea
 * @brief	This class defines the common behavior for the %EditArea control.
 *
 * @since	2.0
 *
 * The %EditArea  class displays a multi-line text editor.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>.
 *
 * The following example demonstrates how to use the %EditArea class.
 *
 * @code
// Sample code for EditAreaSample.h
#include <FUi.h>

class EditAreaSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ITextEventListener
{
public:
	EditAreaSample(void)
	: __pEditArea(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// ITextEventListener
	virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);

private:
	Tizen::Ui::Controls::EditArea* __pEditArea;
};
 * @endcode
 *
 * @code
// Sample code for EditAreaSample.cpp
#include <FGraphics.h>

#include "EditAreaSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
EditAreaSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
EditAreaSample::OnInitializing(void)
{
    result r = E_SUCCESS;

	// Creates an instance of EditArea
	__pEditArea = new EditArea();
	__pEditArea->Construct(Rectangle(50, 100, 400, 150));
	__pEditArea->AddTextEventListener(*this);

	// Adds the edit area to the form
	AddControl(__pEditArea);

	return r;
}

// ITextEventListener implementation
void
EditAreaSample::OnTextValueChanged(const Tizen::Ui::Control& source)
{
    // ....
}

void
EditAreaSample::OnTextValueChangeCanceled(const Tizen::Ui::Control& source)
{
    // ....
}
 * @endcode
 *
 */
class _OSP_EXPORT_ EditArea
	: public Tizen::Ui::Control
{
// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	EditArea(void);

	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~EditArea(void);

	/**
	 * Initializes this instance of the %EditArea control with the specified parameters.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	rect		An instance of the Graphics::Rectangle class @n
	 *                                  This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *                                  the width and height of the control.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	inputStyle			Determines whether the fullscreen keypad or overlay keypad is displayed
	 * @param[in]	limitLength			The maximum limit of the length of the text that can be displayed by %EditArea
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.@n
	 *									The specified @c limitLength is less than or equal to @c 0. @n
	 *									The @c rect.width or the @c rect.height is less than 0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- Some methods of the control will only work as expected when it becomes 'displayable'.
	 *				For more information, see Control::IsDisplayable().
	 *				- The orientation of the full-screen style keypad is determined by the current device orientation.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, InputStyle inputStyle = INPUT_STYLE_FULLSCREEN, int limitLength = 1000);

	/**
	* Initializes this instance of the %EditArea control with the specified parameters.
	*
	* @since			2.1
	*
	* @return		An error code
	* @param[in]	rect		An instance of the Tizen::Graphics::FloatRectangle class @n
	*									This instance represents the x and y coordinates of the top-left corner of the created window along with
	*									the width and height of the control.@n
	*									The optimal size of the control is defined in
	*									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	* @param[in]	inputStyle			Determines whether the fullscreen keypad or overlay keypad is displayed
	* @param[in]	limitLength 		The maximum limit of the length of the text that can be displayed by %EditArea
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.@n
	*									The specified @c limitLength is less than or equal to @c 0. @n
	*									The @c rect.width or the @c rect.height is less than 0.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks
	*				- Some methods of the control will only work as expected when it becomes 'displayable'.
	*				For more information, see Control::IsDisplayable().
	*				- The orientation of the full-screen style keypad is determined by the current device orientation.
	*/
	result Construct(const Tizen::Graphics::FloatRectangle& rect, InputStyle inputStyle = INPUT_STYLE_FULLSCREEN, int limitLength = 1000);

public:
	/**
	 * Gets the horizontal text alignment.
	 *
	 * @since		2.0
	 *
	 * @return		The horizontal text alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextAlignment()
	 */
	HorizontalAlignment GetTextAlignment(void) const;

	/**
	 * Sets the horizontal text alignment.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	alignment           The horizontal text alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetTextAlignment()
	 */
	result SetTextAlignment(HorizontalAlignment alignment);

	/**
	 * Checks whether the view mode is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the view mode is enabled, @n
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetViewModeEnabled()
	 */
	bool IsViewModeEnabled(void) const;

	/**
	 * Enables or disables the view mode.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	enable				Set to @c true to enable the view mode, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When the view mode is enabled, the auto-detected links will be displayed as linked text.
	 * @see			IsViewModeEnabled()
	 */
	result SetViewModeEnabled(bool enable);

	/**
	 * Sets the auto-link mask.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	autoLinks				The auto-link mask @n
	 *							Multiple link types can be combined using bitwise OR. @n For more information,
	 *							see <a href="../org.tizen.native.appprogramming/html/guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										The operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		When @c autoLinks is set to zero, the auto-link detection is disabled.
	 * @see			Tizen::Base::Utility::LinkType
	 * @see			GetAutoLinkMask()
	 * @see			IsViewModeEnabled()
	 * @see			SetViewModeEnabled()
	 */
	result SetAutoLinkMask(unsigned long autoLinks);

	/**
	 * Gets the auto-link mask.
	 *
	 * @since		2.0
	 *
	 * @return		The auto-link mask
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										This operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAutoLinkMask()
	 */
	unsigned long GetAutoLinkMask(void) const;

	/**
	 * Adds the specified link event listener.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @remarks		This method is supported when the input style is ::INPUT_STYLE_OVERLAY.@n
	 *				The added listener will be notified when the links are selected by the user.
	 * @see			RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 * @remarks		This method is supported when the input style is ::INPUT_STYLE_OVERLAY.
	 * @see			AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Gets the line spacing.
	 *
	 * @since		2.0
	 *
	 * @return		The line spacing,  @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetLineSpacing()
	 */
	int GetLineSpacing(void) const;

	/**
	 * Gets the line spacing.
	 *
	 * @since		2.1
	 *
	 * @return		The line spacing,  @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetLineSpacing()
	 */
	float GetLineSpacingF(void) const;

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra.
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 * @since          2.0
	 *
	 * @return         An error code
	 * @param[in]      multiplier		The line spacing multiplier
	 * @param[in]      extra            The extra line spacing
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the specified line spacing value cannot be supported.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see            GetLineSpacing()
	 */
	result SetLineSpacing(int multiplier, int extra);

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra.
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 * @since          2.1
	 *
	 * @return         An error code
	 * @param[in]      multiplier		The line spacing multiplier
	 * @param[in]      extra            The extra line spacing
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the specified line spacing value cannot be supported.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see            GetLineSpacingF()
	 */
	result SetLineSpacing(int multiplier, float extra);

	/**
	 * Gets the margin value of the specified margin type.
	 *
	 * @since		2.0
	 *
	 * @return      The margin value, @n
	 *              else @c -1 if an error occurs
	 * @param[in]	marginType			The margin type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	int GetMargin(EditMarginType marginType) const;

	/**
	 * Gets the margin value of the specified margin type.
	 *
	 * @since		2.1
	 *
	 * @return      The margin value, @n
	 *              else @c -1 if an error occurs
	 * @param[in]	marginType			The margin type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	float GetMarginF(EditMarginType marginType) const;

	/**
	 * Sets the margin value for the specified margin type.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   marginType		The margin type
	 * @param[in]   margin			The margin value to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The specified @c margin cannot be a negative integer.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see         GetMargin()
	 */
	result SetMargin(EditMarginType marginType, int margin);

	/**
	 * Sets the margin value for the specified margin type.
	 *
	 * @since		2.1
	 *
	 * @return      An error code
	 * @param[in]   marginType		The margin type
	 * @param[in]   margin			The margin value to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The specified @c margin cannot be a negative integer.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see         GetMarginF()
	 */
	result SetMargin(EditMarginType marginType, float margin);

	/**
	 * Enables or disables the keypad action.
	 *
	 * @since 2.0
	 * @return      An error code
	 * @param[in]	enable	Set to @c true to enable the keypad action, @n
	 *						else @c false
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION  The underlying input method does not support this operation.
	 * @remarks     Depending on the value of input param, the enter key have a enable or disable look accordingly.
	 */
	result SetKeypadActionEnabled(bool enable);

	/**
	 * Checks whether the keypad action is enabled.
	 *
	 * @since 2.0
	 * @return		@c true if the keypad action is enabled, @n
	 *				else @c false
	 */
	bool IsKeypadActionEnabled(void) const;

	/**
	 * Gets the keypad action type.
	 *
	 * @since		2.0
	 *
	 * @return      The keypad action
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										This operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Ui::KeypadAction GetKeypadAction(void) const;

	/**
	 * Sets the keypad action type.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   keypadAction			The keypad action
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										This operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception   E_SYSTEM				A system error has occurred.
	 * @remarks     Depending on the value of @c keypadAction specified, the enter key label of the keypad will change accordingly.
	 */
	result SetKeypadAction(Tizen::Ui::KeypadAction keypadAction);

	/**
	 * Gets the keypad style.
	 *
	 * @since		2.0
	 *
	 * @return		The keypad style
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadStyle()
	 */
	KeypadStyle GetKeypadStyle(void) const;

	/**
	 * Sets the keypad style.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   keypadStyle			The keypad style
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		The specified input parameter is invalid. @n
	 *                                  The specified @c keypadStyle cannot be @c KEYPAD_STYLE_PASSWORD.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     Depending on the value of the specified @c keypadStyle, the keypad's layout will change accordingly.
	 * @see         GetKeypadStyle()
	 */
	result SetKeypadStyle(KeypadStyle keypadStyle);

	/**
	* Checks whether the text prediction is enabled.
	*
	* @since 2.0
	* @return                @c true if the text prediction is enabled, @n
	*                                 else @c false
	* @exception          E_SUCCESS                The method is successful.
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
	 * Sets the visibility of the command buttons of the overlay style keypad.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	visible					Set to @c true to make the overlay keypad command buttons visible, @n
	 *										else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										This operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result SetOverlayKeypadCommandButtonVisible(bool visible);

	/**
	 * Checks whether the command buttons of the overlay style keypad are visible.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the overlay command buttons are set to be visible, @n
	 *              else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										This operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsOverlayCommandButtonVisible(void) const;

	/**
	 * Hides the keypad.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *										This operation is not supported if the input style is not ::INPUT_STYLE_OVERLAY.
	 * @exception   E_SYSTEM				A system error has occurred.
	 * @see         ShowKeypad()
	 */
	result HideKeypad(void);

	/**
	 * Gets the text size.
	 *
	 * @since       2.0
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the text size.
	 *
	 * @since       2.1
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	float GetTextSizeF(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	size			The text size
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid. @n
	 *								The specified @c size cannot be a negative integer.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	 * Sets the text size.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	size			The text size
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid. @n
	 *								The specified @c size cannot be a negative integer.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetTextSizeF()
	 */
	result SetTextSize(float size);

	/**
	 * Gets the color of %EditArea for the specified status.
	 *
	 * @since        2.0
	 *
	 * @return       The color, @n
	 *				 else RGBA (0,0,0,0) if an error occurs
	 * @param[in]    status				The status
	 * @exception    E_SUCCESS			The method is successful.
	 * @exception    E_SYSTEM			A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(EditStatus status) const;

	/**
	 * Gets the text color of the specified text color type.
	 *
	 * @since		2.0
	 *
	 * @return		The color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	type			The text color type
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(EditTextColor type) const;

	/**
	 * Sets the background bitmap of the %EditArea control for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status			The status
	 * @param[in]   bitmap			The background bitmap
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetBackgroundBitmap(EditStatus status, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the %EditArea control for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status			The status
	 * @param[in]	color			The color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(EditStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the %EditArea control for the specified text color type.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	type			The text color type
	 * @param[in]	color			The text color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetTextColor()
	 */
	result SetTextColor(EditTextColor type, const Tizen::Graphics::Color& color);

	/**
	 * Gets a portion of text that is displayed by the %EditArea control.
	 *
	 * @since		2.0
	 *
	 * @return      The specified portion of the text, @n
	 *				else an empty string if an error occurs
	 * @param[in]   start			The starting index of the range
	 * @param[in]   end				The last index of the range
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure. @n
	 *								The index is greater than the number of elements or less than @c 0.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetText()
	 */
	Tizen::Base::String GetText(int start, int end) const;

	/**
	 * Adds the specified keypad event listener. @n
	 * The added listener is notified when the keypad associated with the %EditArea control is opened or closed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   listener	The event listener to add
	 * @see         RemoveKeypadEventListener()
	 */
	void AddKeypadEventListener(Tizen::Ui::IKeypadEventListener& listener);

	/**
	 * Removes the specified keypad event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]   listener	The event listener to remove
	 * @see         AddKeypadEventListener()
	 */
	void RemoveKeypadEventListener(Tizen::Ui::IKeypadEventListener& listener);

	/**
	 * Adds a text block event listener.
	 * The added listener is notified when the text block is selected.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @remarks		Programmatically modifying the text block does not cause the text block selection event to fire.
	 * @see			RemoveTextBlockEventListener()
	 */
	void AddTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified text block event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 * @see         AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Adds a listener instance. @n
	 * The added listener can listen to the text related events.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to add
	 * @see			RemoveTextEventListener()
	 */
	void AddTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to remove
	 * @see			AddTextEventListener()
	 */
	void RemoveTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Adds a listener instance to listen to the scroll panel events.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to add
	 * @remarks
	 *			- To listen to scroll panel events, the parent of the %EditArea control must be an instance of ScrollPanel.
	 *			- When OnOverlayControlCreated() or OnOvelayControlClosed() is called, the application resets the bounds of the controls placed
	 *              within the %ScrollPanel. %ScrollPanel is automatically redrawn after this method is called.
	 * @see			RemoveScrollPanelEventListener()
	 */
	void AddScrollPanelEventListener(Tizen::Ui::IScrollPanelEventListener& listener);

	/**
	 * Removes the scroll panel event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to remove
	 * @see			AddScrollPanelEventListener()
	 */
	void RemoveScrollPanelEventListener(Tizen::Ui::IScrollPanelEventListener& listener);

	/**
	 * Adds a listener instance. @n
	 * The added listener is notified when the action event is fire by the command buttons of the keypad.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			RemoveActionEventListener()
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The event listener to remove
	 * @see			AddActionEventListener()
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Adds a listener instance for language events. @n
	 * The added listener is notified when the input language is changed.
	 *
	 * @since      2.0
	 *
	 * @param[in]  listener               The listener to add
	 * @remarks    The application can recognize when the language is changed from the keypad by adding Tizen::Ui::ILanguageEventListener.
	 * @see            RemoveLanguageEventListener()
	 */
	void AddLanguageEventListener(Tizen::Ui::ILanguageEventListener& listener);

	/**
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since      2.0
	 *
	 * @param[in]  listener               The listener to remove
	 * @see             AddLanguageEventListener()
	 */
	void RemoveLanguageEventListener(Tizen::Ui::ILanguageEventListener& listener);

	/**
	 * Gets the remaining length of the %EditArea control.
	 *
	 * @since	2.0
	 *
	 * @return	The remaining length of the %EditArea control, @n
	 *			else @c -1 if an error occurs.
	 */
	int GetRemainingLength(void) const;

	/**
	 * Enables or disables the lowercase mode.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable the lowercase mode, @n
	 *						else @c false
	 */
	void SetLowerCaseModeEnabled(bool enable);

	/**
	 * Checks whether the lowercase mode is enabled.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the lowercase mode is enabled, @n
	 *			else @c false
	 */
	bool IsLowerCaseModeEnabled(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the input mode category.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated We no longer provide a method to specify the list of styles which the user can set the keypad to, @n
	 *			   or the current mode to initially set the keypad to, from this list. It is recommended to use SetKeypadStyle() method instead.
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    categories     The categories to set @n
	 *                                      Multiple input categories can be combined using bitwise OR.
	 * @param[in]    enable			The category value to set
	 * @exception    E_SUCCESS				The method is successful.
	 * @exception    E_INVALID_ARG			A specified input mode category is invalid.
	 * @exception	 E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation @n
	 *										The specified @c categories cannot be supported with the current keypad style.
	 * @exception    E_SYSTEM				A system error has occurred.
	 * @see		EditInputModeCategory
	 * @endif
	 */
	result SetInputModeCategory(unsigned long categories, bool enable);

	/**
	 * @if OSPDEPREC
	 * Sets the current input mode category.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated We no longer provide a method to specify the list of styles which the user can set the keypad to, @n
	 *			   or the current mode to initially set the keypad to, from this list. It is recommended to use SetKeypadStyle() method instead.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	inputModeCategory   An item of input category
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result SetCurrentInputModeCategory(EditInputModeCategory inputModeCategory);

	/**
	 * @if OSPDEPREC
	 * Gets the input mode category.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because we no longer provide a method to specify the list of styles @n
	 *			  which the user can set the keypad to. It is recommended to use GetKeypadStyle() method instead.
	 * @since	2.0
	 *
	 * @return  A bitwise combination of Tizen::Ui::Controls::EditInputModeCategory, @n
	 *			else @c EDIT_INPUTMODE_ALPHA if an error occurs
	 * @endif
	 */
	unsigned long GetInputModeCategory(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the current input mode category.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because we no longer provide a method to specify the list of styles @n
	 *			  which the user can set the keypad to. It is recommended to use GetKeypadStyle() method instead.
	 * @since    2.0
	 *
	 * @return   The current input mode category
	 * @endif
	 */
	EditInputModeCategory GetCurrentInputModeCategory(void) const;

	/**
	 * Sets the cursor at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position        The cursor position to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c position is less than @c 0 or greater than the maximum length.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetCursorPosition(int position);

	/**
	 * Gets the cursor position.
	 *
	 * @since			2.0
	 *
	 * @return			The current cursor position, @n
	 *                  else @c -1 if an error occurs
	 */
	int GetCursorPosition(void) const;

	/**
	 * Gets the text that is displayed by the %EditArea control.
	 *
	 * @since	2.0
	 *
	 * @return	The text of the %EditArea control, @n
	 *          else an empty string if an error occurs
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets the length of the text that is displayed by the %EditArea control.
	 *
	 * @since	2.0
	 *
	 * @return	The length of the text, @n
	 *          else @c -1 if an error occurs
	 */
	int GetTextLength(void) const;

	/**
	 * Sets the text of the %EditArea control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	text			The text to display by the %EditArea control
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The length of the specified @c text exceeds the system limitation or the limit length.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result SetText(const Tizen::Base::String& text);

	/**
	 * Inserts the specified text at the current cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text        The text to insert
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.@n
	 */
	result InsertTextAtCursorPosition(const Tizen::Base::String& text);

	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text            The text to append
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.@n
	 */
	result AppendText(const Tizen::Base::String& text);

	/**
	 * Appends the specified character at the end of the existing text.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   character       The character to append
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %EditArea control. To display the
	 *              changes, the control must be drawn again.
	 */
	result AppendCharacter(const Tizen::Base::Character& character);

	/**
	 * Inserts the text that will be displayed by bitmap at the specified text position.
	 *
	 * @since 2.0
	 *
	 * @return             An error code
	 * @param[in]   position       The position to insert the text
	 * @param[in]   text            The text to insert
	 * @param[in]   textImage    The alternate bitmap to draw
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_OUT_OF_RANGE  The specified @c position is outside the valid range. @n
	 *                              Either the specified @c position is greater than the number of existing text in the %EditArea or less than @c 0.
	 * @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds the maximum length of the text that can be displayed by %EditArea.
	 * @remarks
	 *			- The method modifies the text buffer that is managed by the %EditArea control.
	 *			- To display the changes, the control must be drawn again. The text to be inserted will be displayed by @c textImage.
	 */
	result InsertTextAt(int position, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap& textImage);

	/**
	 * Appends the text that will be displayed by bitmap at the end of the existing text.
	 *
	 * @since 2.0
	 *
	 * @return             An error code
	 * @param[in]   text            The text to append
	 * @param[in]   textImage    The alternate bitmap to draw
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds the maximum length of the text that can be displayed by %EditArea.
	 * @remarks
	 *			- The method modifies the text buffer that is managed by the %EditArea control.
	 *			- To display the changes, the control must be drawn again. The text to be appended will be displayed by @c textImage.
	 */
	result AppendText(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap& textImage);

	/**
	 * Clears the text that is displayed by the %EditArea control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %EditArea control. To display the
	 *              changes, the control must be drawn again.
	 */
	result Clear(void);

	/**
	 * Deletes a character at the current cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception   E_SUCCESS	The method is successful.
	 * @exception   E_SYSTEM	A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %EditArea control. To display the
	 *              changes, the control must be drawn again.
	 */
	result DeleteCharacterAtCursorPosition(void);

	/**
	 * Gets the range of the current text block.
	 *
	 * @since        2.0
	 *
	 * @param[out]   start   The first index of the current text block
	 * @param[out]   end     The last index of the current text block
	 */
	void GetCurrentTextRange(int& start, int& end) const;

	/**
	 * Displays the guide text when there is no text in the %EditArea control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	guideText    The guide text
	 * @remarks		This is the default text that is displayed in the %EditArea control when the focus is given to it.
	 */
	void SetGuideText(const Tizen::Base::String& guideText);

	/**
	 * Gets the guide text.
	 *
	 * @since       2.0
	 *
	 * @return      The guide text, @n
	 *              else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetGuideText()
	 */
	Tizen::Base::String GetGuideText(void) const;

	/**
	 * Gets the text color of the guide text.
	 *
	 * @since       2.0
	 *
	 * @return      The guide text color
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetGuideTextColor()
	 */
	Tizen::Graphics::Color GetGuideTextColor(void) const;

	/**
	 * Sets the text color of the guide text.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   color            The guide text color
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @see         GetGuideTextColor()
	 */
	result SetGuideTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Enables or disables the keypad.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable the keypad, @n
	 *						else @c false
	 */
	void SetKeypadEnabled(bool enable);

	/**
	 * Checks whether the keypad is enabled.
	 *
	 * @since        2.0
	 *
	 * @return		@c true if the keypad is enabled, @n
	 *				else @c false
	 */
	bool IsKeypadEnabled(void) const;

	/**
	 * Shows the keypad.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method is supported only when the input style is ::INPUT_STYLE_OVERLAY.
	 */
	result ShowKeypad(void);

	/**
	 * Gets the line count.
	 *
	 * @since	2.0
	 *
	 * @return	The line count
	 */
	int GetTextLineCount(void) const;

	/**
	 * Gets the range of the current text block.
	 *
	 * @since		2.0
	 *
	 * @param[out]	start   The starting index of the current text block
	 * @param[out]	end     The end index of the current text block
	 */
	void GetBlockRange(int& start, int& end) const;

	/**
	 * Begins the text block from the current cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		Move the cursor position to the end of the text block.
	 * @see         SetCursorPosition()
	 * @see         ReleaseBlock()
	 * @see			IsBlocked()
	 */
	result BeginBlock(void);

	/**
	 * Releases the text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see         BeginBlock()
	 * @see			IsBlocked()
	 */
	result ReleaseBlock(void);

	/**
	 * Checks whether a portion of the text is blocked.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the text is blocked, @n
	 *			else @c false
	 * @see     BeginBlock()
	 * @see		ReleaseBlock()
	 */
	bool IsBlocked(void) const;

	/**
	 * Copies the text block to the clipboard.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see         Cut()
	 * @see		Paste()
	 * @see		Remove()
	 */
	result Copy(void);

	/**
	 * Cuts the text block and copies it to the clipboard.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			Copy()
	 * @see			Remove()
	 * @see			Paste()
	 */
	result Cut(void);

	/**
	 * Pastes the copied text at the cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			Copy()
	 * @see			Cut()
	 * @see			Remove()
	 */
	result Paste(void);

	/**
	 * Removes the text that is marked by the text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			Copy()
	 * @see			Cut()
	 * @see			Paste()
	 */
	result Remove(void);

	/**
	 * Checks whether the text in the %EditArea control has been clipped.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the text has been clipped, @n
	 *			else @c false
	 * @remarks	'Clipped' means that the text has been copied to the clipboard.
	 * @see		Copy()
	 * @see		Cut()
	 * @see		Paste()
	 * @see		Remove()
	 */
	bool IsClipped(void) const;

	/**
	 * Sets the command button properties of the keypad.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	position			The position of the command button
	 * @param[in]	text				The label of the command button
	 * @param[in]	actionId			The action ID
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks		This method is supported when the input style is ::INPUT_STYLE_OVERLAY.
	 */
	result SetOverlayKeypadCommandButton(CommandButtonPosition position, const Tizen::Base::String& text, int actionId);

	/**
	 * Gets the text of the specified command button.
	 *
	 * @since		2.0
	 *
	 * @return		The text of the specified command button
	 * @param[in]	position    The position of the command button
	 * @remarks		This method is supported when the input style is ::INPUT_STYLE_OVERLAY.
	 */
	Tizen::Base::String GetOverlayKeypadCommandButtonText(CommandButtonPosition position) const;

	/**
	 * Gets the action ID of the specified command button.
	 *
	 * @since		2.0
	 *
	 * @return		The action ID of the specified command button
	 * @param[in]	position    The position of the command button
	 * @remarks		This method is supported when the input style is ::INPUT_STYLE_OVERLAY.
	 */
	int GetOverlayKeypadCommandButtonActionId(CommandButtonPosition position) const;

	/**
	 * Sets the input language.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  languageCode               The language to set
	 * @exception  E_SUCCESS              The method is successful.
	 * @exception  E_OUT_OF_MEMORY   The memory is insufficient.
	 * @remarks
	 *			- The application can set the language of the current keypad that is associated with the current %EditArea.
	 *			- This method only works if the language to set is supported by the current preloaded keypad.
	 */
	result SetCurrentLanguage(Tizen::Locales::LanguageCode languageCode);

	/**
	 * Gets the current input language.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[out] language               The current input language
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks   The application can get the current language of the keypad that is associated with the current %EditArea.
	 */
	result GetCurrentLanguage(Tizen::Locales::LanguageCode& language) const;

	/**
	 * Sets the text filter.
	 *
	 * @since		2.1
	 *
	 * @param[in]		pFilter	The filter to set
 	 * @remarks		The %EditArea control checks with the registered filter to decide whether the user-entered text should be replaced or not.
	 */
	void  SetEditTextFilter(IEditTextFilter* pFilter);

	/**
	* Sends opaque command to the input method.
	*
	* @since     2.1
	*
	* @param[in] command            The opaque command to send
	* @remarks
	*			- This method can be used to provide domain-specific features that are only known between certain input methods and their clients.
	*			- This method may not work, depending on the active Input Method.
	*/
	void SendOpaqueCommand (const Tizen::Base::String& command);

protected:
	friend class _EditAreaImpl;

private:
	EditArea(const EditArea&);
	EditArea& operator =(const EditArea&);
}; // EditArea

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_EDIT_AREA_H_
