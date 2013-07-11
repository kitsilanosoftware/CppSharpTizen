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
 * @file	FUiCtrlEditField.h
 * @brief	This is the header file for the %EditField class.
 *
 * This header file contains the declarations of the %EditField class and its helper classes.
 */

#ifndef _FUI_CTRL_EDIT_FIELD_H_
#define _FUI_CTRL_EDIT_FIELD_H_

#include <FBaseCharacter.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpPoint.h>
#include <FGrpRectangle.h>
#include <FLclLocale.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlEditTypes.h>
#include <FUiCtrlGroupTypes.h>
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
}}

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	EditField
 * @brief   This class defines a common behavior for an %EditField control.
 *
 * @since		2.0
 *
 * The %EditField  class displays a single-line text editor.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>.
 *
 * The following example demonstrates how to use the %EditField class.
 *
 * @code
// Sample code for EditFieldSample.h
#include <FUi.h>

class EditFieldSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ITextEventListener
{
public:
	EditFieldSample(void)
	: __pEditField(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// ITextEventListener
	virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);

private:
	Tizen::Ui::Controls::EditField* __pEditField;
};
 * @endcode
 *
 * @code
// Sample code for EditFieldSample.cpp
#include <FGraphics.h>

#include "EditFieldSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
EditFieldSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
EditFieldSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of EditField
	__pEditField = new EditField();
	__pEditField->Construct(Rectangle(50, 100, 400, 150));
	__pEditField->AddTextEventListener(*this);

	//Adds the edit field to the Form
	AddControl(*__pEditField);

	return r;
}

// ITextEventListener implementation
void
EditFieldSample::OnTextValueChanged(const Tizen::Ui::Control& source)
{
    // ....
}

void
EditFieldSample::OnTextValueChangeCanceled(const Tizen::Ui::Control& source)
{
    // ....
}
 * @endcode
 *
 */

class _OSP_EXPORT_ EditField
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	EditField(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~EditField(void);

	/**
	 * Initializes this instance of the %EditField control with the specified parameters.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		rect		An instance of the Graphics::Rectangle class @n
	 *										This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *										the width and height of the control.
	 * @param[in]   style			The style of the %EditField control
	 * @param[in]   inputStyle		The input style of the %EditField control
	 * @param[in]   showTitle				Set to @c true to display the title, @n
	 *								else @c false
	 * @param[in]   limitLength		The limit for the length of the text in the %EditField control
	 * @param[in]   groupStyle		The table view style of the %EditField control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c limitLength is less than or equal to @c 0, or @n
	 *										either the @c rect.width or the @c rect.height is less than @c 0.
	 * @exception   E_UNSUPPORTED_OPTION    The specified option is not supported. @n
	 *										The title is not supported by small style %EditField.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container. Therefore, some methods may fail if the control has been used
	 *				earlier. The %EditField style of SMALL property cannot be used together with group styles. @n
	 *				If the specified size is less than the minimum size, %EditField is constructed with the minimum size.
	 * @remarks		Following are the input styles used for creating the different orientations of a keypad: @n
	 *              -	INPUT_STYLE_FULLSCREEN: The orientation is decided by the G-sensor value. @n
	 *              -	INPUT_STYLE_OVERLAY: The orientation is the same as that of a parent form.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, EditFieldStyle style = EDIT_FIELD_STYLE_NORMAL, InputStyle inputStyle = INPUT_STYLE_FULLSCREEN, bool showTitle = false, int limitLength = 100, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Initializes this instance of the %EditField control.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]	rect                    The bounds of %EditField
	 * @param[in]    style           The style of the %EditField control
	 * @param[in]    inputStyle      The input style of the %EditField control
	 * @param[in]    titleStyle      The title style
	 * @param[in]	enableClear	            Set to @c true to enable the clear button, @n
	 *										else @c false
	 * @param[in]    limitLength     The limit of the length of text in the %EditField control
	 * @param[in]    groupStyle      The table view style of the %EditField control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_ARG           A specified input parameter is invalid. @n
	 *                                      The specified @c limitLength is less than or equal to @c 0. @n
	 *								        The specified @c rect.width or the @c rect.height is less than @c 0.
	 * @exception	E_UNSUPPORTED_OPTION	The specified option is not supported. @n
	 *										Title is not supported in small style %EditField.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		 A control is fully usable only after it has been added to a container. Therefore, some methods may fail if the control is used earlier.
	 *				The %EditField style of SMALL property cannot be used together with group styles. @n
	 *               If the specified size is less than the minimum size, EditFied() is constructed with the minimum size.
	 * @remarks      Following are the input styles used for creating different orientations of a keypad: @n
	 *										-   INPUT_STYLE_FULLSCREEN: The orientation is decided by the G-sensor value.@n
	 *										-   INPUT_STYLE_OVERLAY: The orientation is similar to the parent Form.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, EditFieldStyle style, InputStyle inputStyle, EditFieldTitleStyle titleStyle, bool enableClear = false, int limitLength = 100, GroupStyle groupStyle = GROUP_STYLE_NONE);

public:
	/**
	 * Gets the horizontal text alignment of the %EditField control.
	 *
	 * @since		2.0
	 *
	 * @return		The horizontal text alignment
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	    The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextAlignment()
	 */
	HorizontalAlignment GetTextAlignment(void) const;

	/**
	 * Sets the horizontal text alignment of the %EditField control.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetTextAlignment()
	 */
	result SetTextAlignment(HorizontalAlignment alignment);

	/**
	 * Checks whether the view mode is enabled.
	 *
	 * @since       2.0
	 *
	 * @return		@c true if the view mode is enabled, @n
	 *              else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *				In the view mode, the auto-detected links are displayed as linked text.
	 * @see   SetViewModeEnabled()
	 */
	bool IsViewModeEnabled(void) const;

	/**
	 * Enables or disables the view mode.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	enable              Set to @c true to enable the view mode, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		In the view mode, the auto-detected links are displayed as linked text.
	 * @see         IsViewModeEnabled()
	 */
	result SetViewModeEnabled(bool enable);

	/**
	 * Sets the auto-link mask.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	autoLinks				The auto-link mask @n
	 *										Multiple link types can be combined using bitwise OR operator (see Tizen::Base::Utility::LinkType). @n
	 *										For more information, see <a href="../org.tizen.native.appprogramming/html/guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation @n
	 *										The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		When @c autoLinks is set to @c 0, the auto-link detection is disabled.
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
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation @n
	 *										The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAutoLinkMask()
	 */
	unsigned long GetAutoLinkMask(void) const;

	/**
	 * Adds a link event listener.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY. @n
	 *				The added listener is notified when the links are selected by the user.
	 * @see			RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.
	 * @see			AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Gets the margin value of the specified margin type.
	 *
	 * @since       2.0
	 *
	 * @return	    The margin value of the specified margin type, @n
	 *				else @c -1 if an error occurs
	 * @param[in]   marginType		The margin type
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	int GetMargin(EditMarginType marginType) const;

	/**
	 * Sets the margin for the specified margin type.
	 *
	 * @since       2.0
	 *
	 * @return	    An error code
	 * @param[in]   marginType		The margin type
	 * @param[in]   margin			The margin to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The specified @c margin cannot be a negative integer.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see         GetMargin()
	 */
	result SetMargin(EditMarginType marginType, int margin);

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
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *										The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM                A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadAction()
	 */
	Tizen::Ui::KeypadAction GetKeypadAction(void) const;

	/**
	 * Sets the keypad action type.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   keypadAction			The keypad action
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *										The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Based on the specified value of @c keypadAction, the enter key label of the keypad changes accordingly.
	 * @see         GetKeypadAction()
	 */
	result SetKeypadAction(Tizen::Ui::KeypadAction keypadAction);

	/**
	 * Sets the visibility of the command buttons of the overlay style keypad.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	visible					Set to @c true to set the visibility of the overlay keypad command buttons, @n
	 *                                      else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *										The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result SetOverlayKeypadCommandButtonVisible(bool visible);

	/**
	 * Checks whether the command buttons of the overlay style keypad are visible.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the overlay command buttons are visible, @n
	 *              else @c false
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *											The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception   E_SYSTEM                    A system error has occurred.
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
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *										The input style is not @c INPUT_STYLE_OVERLAY.
	 * @exception   E_SYSTEM				A system error has occurred.
	 * @see         ShowKeypad()
	 */
	result HideKeypad(void);

	/**
	 * Gets the position of the ellipsis.
	 *
	 * @since       2.0
	 *
	 * @return      The ellipsis position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetEllipsisPosition()
	 */
	EllipsisPosition GetEllipsisPosition(void) const;

	/**
	 * Sets the position of the ellipsis.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   position	The ellipsis position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see         GetEllipsisPosition()
	 */
	result SetEllipsisPosition(EllipsisPosition position);

	/**
	 * Gets the text size.
	 *
	 * @since       2.0
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	size			The text size
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid. @n
	 *								The @c size cannot be a negative integer.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	 * Gets the color of the %EditField control for the specified status.
	 *
	 * @since        2.0
	 *
	 * @return       The color, @n
	 *				 else RGBA(0,0,0,0) if an error occurs
	 * @param[in]    status				The status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(EditStatus status) const;

	/**
	 * Gets the text color of the specified text color type.
	 *
	 * @since		2.0
	 *
	 * @return		The color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	type			The text color type
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(EditTextColor type) const;

	/**
	 * Sets the background bitmap of the %EditField control for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status			The status
	 * @param[in]   bitmap			The background bitmap
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetBackgroundBitmap(EditStatus status, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the %EditField control for the specified status.
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
	 * Sets the text color of the %EditField control for the specified text color type.
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
	 * Gets a portion of text that is displayed by the %EditField control.
	 *
	 * @since		2.0
	 *
	 * @return      The specified portion of the text, @n
	 *				else an empty string if an error occurs
	 * @param[in]   start			The starting index of the range
	 * @param[in]   end				The last index of the range
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or @n
	 *								the index is greater than the number of elements or less than @c 0.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetText()
	 */
	Tizen::Base::String GetText(int start, int end) const;

	/**
	 * Adds a keypad event listener. @n
	 * The added listener is notified when the keypad associated with the %EditField control is opened or closed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   listener	The event listener to be added
	 * @see         RemoveKeypadEventListener()
	 */
	void AddKeypadEventListener(IKeypadEventListener& listener);

	/**
	 * Removes the specified keypad event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]   listener	The event listener to be removed
	 * @see         AddKeypadEventListener()
	 */
	void RemoveKeypadEventListener(IKeypadEventListener& listener);

	/**
	 * Adds a text block event listener. @n
	 * The added listener is notified when the text block is selected.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @remarks		Programmatically modifying the text block does not cause the text block selection event to fire.
	 * @see			RemoveTextBlockEventListener()
	 */
	void AddTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified text block event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Adds the ITextEventListener instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to be added
	 */
	void AddTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Removes the ITextEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to be removed
	 */
	void RemoveTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Adds the specified listener instance to listen to the scroll panel events.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be added
	 * @remarks     To listen to the scroll panel events, the parent of EditArea must be an instance of ScrollPanel. @n
	 *              When OnOverlayControlCreated() or OnOvelayControlClosed() is called, the application resets the bounds of the controls placed
	 *              within the ScrollPanel control. ScrollPanel is automatically drawn again after this method is called.
	 * @see			RemoveScrollPanelEventListener()
	 */
	void AddScrollPanelEventListener(Tizen::Ui::IScrollPanelEventListener& listener);

	/**
	 * Removes the specified scroll panel event listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be removed
	 */
	void RemoveScrollPanelEventListener(Tizen::Ui::IScrollPanelEventListener& listener);

	/**
	 * Adds the specified listener instance. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Adds the specified listener instance for language events. @n
	 * The added listener is notified when the input language is changed.
	 *
	 * @since      2.0
	 *
	 * @param[in]  listener				The listener to be added
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
	 * @param[in]  listener				The listener to be removed
	 * @see            AddLanguageEventListener()
	 */
	void RemoveLanguageEventListener(Tizen::Ui::ILanguageEventListener& listener);

	/**
	 * Gets the remaining length of the %EditField control.
	 *
	 * @since	2.0
	 *
	 * @return	The remaining length of the %EditField control, @n
	 *			else @c -1 if an error occurs
	 */
	int GetRemainingLength(void) const;

	/**
	 * Enables or disables the lowercase mode.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable the lowercase mode, @n
	 *                      else @c false
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
	 * 			   or the current mode to initially set the keypad to, from this list. It is recommended to use EditFieldStyle in the Construct() method instead.
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    categories             The categories to be set @n
	 *                              Multiple input categories can be combined using bitwise OR operator (see Tizen::Ui::Controls::EditInputModeCategory).
	 * @param[in]    enable			The category value to set
	 * @exception    E_SUCCESS				The method is successful.
	 * @exception    E_INVALID_ARG			A specified input mode category is invalid.
	 * @exception	 E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation @n
	 *										The specified @c categories cannot be supported with the current keypad style.
	 * @exception    E_SYSTEM				A system error has occurred.
	 * @endif
	 */
	result SetInputModeCategory(unsigned long categories, bool enable);

	/**
	 * @if OSPDEPREC
	 * Sets the current input mode category.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated We no longer provide a method to specify the list of styles which the user can set the keypad to, @n
	 * 			   or the current mode to initially set the keypad to, from this list. It is recommended to use EditFieldStyle in the Construct() method instead.
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
	 * @deprecated This method is deprecated because we no longer provide a method to specify the list of styles which the user can set the keypad to.
	 * @since	2.0
	 *
	 * @return  A bitwise combination of Tizen::Ui::Controls::EditInputModeCategory, @n
	 *			else EDIT_INPUTMODE_ALPHA if an error occurs
	 * @endif
	 */
	unsigned long GetInputModeCategory(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the current input mode category.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because we no longer provide a method to specify the list of styles which the user can set the keypad to.
	 * @since    2.0
	 *
	 * @return   The current input mode category
	 * @endif
	 */
	EditInputModeCategory GetCurrentInputModeCategory(void) const;

	/**
	 * Sets the cursor in the %EditField control at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position		The cursor position that is to be set
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
	 * Gets the text that is displayed by the %EditField control.
	 *
	 * @since	2.0
	 *
	 * @return	The text of the %EditField control, @n
	 *          else an empty string if an error occurs
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets the length of the text that is displayed by the %EditField control.
	 *
	 * @since	2.0
	 *
	 * @return	The length of the text, @n
	 *          else @c -1 if an error occurs
	 */
	int GetTextLength(void) const;

	/**
	 * Sets the text of the %EditField control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	text			The text to be displayed by the %EditField control
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
	 * @param[in]	text        The text to be inserted
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception   E_SYSTEM    A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result InsertTextAtCursorPosition(const Tizen::Base::String& text);

	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text        The text to be appended
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception   E_SYSTEM    A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result AppendText(const Tizen::Base::String& text);

	/**
	 * Appends the specified character at the end of the existing text.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	character		The character to be appended
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %EditField control. To display the
	 *              changes, the control must be drawn again.
	 */
	result AppendCharacter(const Tizen::Base::Character& character);

	/**
	 * Clears the text that is displayed by the %EditField control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %EditField control. To display the
	 *              changes, the control must be drawn again.
	 */
	result Clear(void);

	/**
	 * Deletes a character at the current cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %EditField control. To display the
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
	 * Sets the guide text.
	 *
	 * @since		2.0
	 *
	 * @param[in]	guideText    The guide text
	 * @remarks		This is the default text that is displayed in the %EditField
	 *              control when the focus is given to it and no text is entered.
	 */
	void SetGuideText(const Tizen::Base::String& guideText);

	/**
	 * Gets the guide text.
	 *
	 * @since       2.0
	 *
	 * @return      The guide text, @n
	 *              else an empty string if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetGuideText()
	 */
	Tizen::Base::String GetGuideText(void) const;

	/**
	 * Gets the text color of the guide text.
	 *
	 * @since       2.0
	 *
	 * @return      The guide text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
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
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @see         GetGuideTextColor()
	 */
	result SetGuideTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the title for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The title text color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status			The state of the %EditField control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTitleTextColor()
	 */
	Tizen::Graphics::Color GetTitleTextColor(EditStatus status) const;

	/**
	 * Sets the text color of the title for the specified status.
	 *
	 * @since       2.0
	 *
	 * @return	    An error code
	 * @param[in]	status			The state of the %EditField control
	 * @param[in]   color			The title text color
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @see         GetTitleTextColor()
	 */
	result SetTitleTextColor(EditStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Enables or disables the keypad.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable the keypad,
	 *                      else @c false
	 */
	void SetKeypadEnabled(bool enable);

	/**
	 * Checks whether the keypad is enabled.
	 *
	 * @since        2.0
	 *
	 * @return       @c true if the keypad is enabled, @n
	 *               else @c false
	 */
	bool IsKeypadEnabled(void) const;

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
	 * Displays the keypad.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.
	 */
	result ShowKeypad(void);

	/**
	 * Gets the range of the current text block that is selected.
	 *
	 * @since		2.0
	 *
	 * @param[out]	start   The starting index of the current block
	 * @param[out]	end     The end index of the current block
	 */
	void GetBlockRange(int& start, int& end) const;

	/**
	 * Begins the text block from the current cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Move the cursor position to the end of the text block.
	 * @see         SetCursorPosition()
	 * @see         ReleaseBlock()
	 * @see			IsBlocked()
	 */
	result BeginBlock(void);

	/**
	 * Releases the selection of the current text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
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
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @see         Cut(), Paste(), Remove()
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
	 * @see			Copy(), Remove(), Paste()
	 */
	result Cut(void);

	/**
	 * Pastes the copied text at the cursor position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @see			Copy(), Cut(), Remove()
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
	 * @see			Copy(), Cut(), Paste()
	 */
	result Remove(void);

	/**
	 * Checks whether the text in the %EditField control is clipped.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the text is clipped, @n
	 *			else @c false
	 * @remarks	'clipped' means that the text is copied to the clipboard.
	 * @see		Copy(), Cut(), Paste(), Remove()
	 */
	bool IsClipped(void) const;

	/**
	 * Sets the title of the %EditField control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   title			The title to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetTitleText(const Tizen::Base::String& title);

	/**
	 * Gets the title text of the %EditField control.
	 *
	 * @since		2.0
	 *
	 * @return		The title text, @n
	 *				else an empty string if an error occurs
	 */
	Tizen::Base::String GetTitleText(void) const;

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
	 * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.
	 */
	result SetOverlayKeypadCommandButton(CommandButtonPosition position, const Tizen::Base::String& text, int actionId);

	/**
	 * Gets the text of the specified command button.
	 *
	 * @since		2.0
	 *
	 * @return		The text of the specified command button
	 * @param[in]	position    The position of the command button
	 * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.
	 */
	Tizen::Base::String GetOverlayKeypadCommandButtonText(CommandButtonPosition position) const;

	/**
	 * Gets the action ID of the specified command button.
	 *
	 * @since		2.0
	 *
	 * @return		The action ID of the specified command button
	 * @param[in]	position    The position of the command button
	 * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.
	 */
	int GetOverlayKeypadCommandButtonActionId(CommandButtonPosition position) const;

	/**
	 * Sets the input language.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  languageCode				The language to be set
	 * @exception  E_SUCCESS				The method is successful.
	 * @exception  E_OUT_OF_MEMORY                   The memory is insufficient.
	 * @remarks     The application can set the language of the current keypad that is associated with the current %EditField. @n
	 *             This method only works if the language to set is supported by the current preloaded keypad.
	 */
	result SetCurrentLanguage(Tizen::Locales::LanguageCode languageCode);

	/**
	 * Gets the current input language.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[out] language               The current input language
	 * @exception  E_SUCCESS				The method is successful.
	 * @remarks     The application can get the current language of the keypad that is associated with the current %EditField.
	 */
	result GetCurrentLanguage(Tizen::Locales::LanguageCode& language) const;

protected:
	friend class _EditFieldImpl;

private:
	EditField(const EditField&);
	EditField& operator =(const EditField&);

}; // EditField

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_EDIT_FIELD_H_
