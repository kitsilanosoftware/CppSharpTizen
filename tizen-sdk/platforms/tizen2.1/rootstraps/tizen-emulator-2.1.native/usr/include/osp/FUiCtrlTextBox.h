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
 * @file	FUiCtrlTextBox.h
 * @brief	This is the header file for the %TextBox class.
 *
 * This header file contains the declarations of the %TextBox class and its helper classes.
 */

#ifndef _FUI_CTRL_TEXT_BOX_H_
#define _FUI_CTRL_TEXT_BOX_H_

#include <FGrpRectangle.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiControl.h>
#include <FUiITextBlockEventListener.h>
#include <FUiIUiLinkEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{
class _TextBoxImpl;
};
};
};

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum	TextBoxBorder
 *
 * Defines the possible types of text box borders.
 *
 * @since	2.0
 */
enum TextBoxBorder
{
	TEXT_BOX_BORDER_NONE,       /**< No border */
	TEXT_BOX_BORDER_ROUNDED     /**< The rounded border */
};


/**
 * @enum    TextBoxStatus
 *
 * Defines the possible states of the text box.
 *
 * @since	2.0
 */
enum TextBoxStatus
{
	TEXT_BOX_STATUS_NORMAL,         /**< The normal state */
	TEXT_BOX_STATUS_HIGHLIGHTED,    /**< The focus-highlighted state */
	TEXT_BOX_STATUS_DISABLED        /**< The disabled state */
};


/**
 * @enum    TextBoxTextColor
 *
 * Defines the possible text colors.
 *
 * @since	2.0
 */
enum TextBoxTextColor
{
	TEXT_BOX_TEXT_COLOR_NORMAL,         /**< The default text color */
	TEXT_BOX_TEXT_COLOR_HIGHLIGHTED,    /**< The highlighted text color */
	TEXT_BOX_TEXT_COLOR_DISABLED,       /**< The disabled text color */
	TEXT_BOX_TEXT_COLOR_BLOCKED,        /**< The text block color */
	TEXT_BOX_TEXT_COLOR_LINK            /**< The link text color */
};


/**
 * @enum    TextBoxTextStyle
 *
 * Defines the possible text styles.
 *
 * @since	2.0
 */
enum TextBoxTextStyle
{
	TEXT_BOX_TEXT_STYLE_NORMAL = 0x0000,                /**< The normal text style */
	TEXT_BOX_TEXT_STYLE_BOLD = 0x0001,                  /**< The bold text style */
	TEXT_BOX_TEXT_STYLE_ITALIC = 0x0002,                /**< The italic text style */
	TEXT_BOX_TEXT_STYLE_UNDERLINE = 0x0004,             /**< The underline text style */
	TEXT_BOX_TEXT_STYLE_STRIKEOUT = 0x0008,             /**< The strikeout text style */
	TEXT_BOX_TEXT_STYLE_MAX = 0x7FFF                    /**< The placeholder */
};

/**
 * @class	TextBox
 * @brief	This class is an implementation of a %TextBox control.
 *
 * @since	2.0
 *
 * The %TextBox class displays a non-editable text field.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_textbox.htm">TextBox</a>.
 *
 * The following example demonstrates how to use the %TextBox class.
 *
 * @code
// Sample code for TextBoxSample.h
#include <FUi.h>

class TextBoxSample
    	: public Tizen::Ui::Controls::Form
{
public:
	TextBoxSample(void)
	: __pTextBox(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

private:
	Tizen::Ui::Controls::TextBox* __pTextBox;
};
 * @endcode
 *
 * @code
// Sample code for TextBoxSample.cpp
#include <FGraphics.h>

#include "TextBoxSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
TextBoxSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
TextBoxSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of TextBox
	__pTextBox = new TextBox();
	__pTextBox->Construct(Rectangle(50, 50, GetClientAreaBounds().width-80, 300), TEXT_BOX_BORDER_ROUNDED);

	// Sets properties on the text box
	__pTextBox->SetTextSize(50);
	__pTextBox->SetText(L"Tizen Developer");
	__pTextBox->SetTextColor(TEXT_BOX_TEXT_COLOR_HIGHLIGHTED, Color::GetColor(COLOR_ID_RED));
	__pTextBox->AppendText(L"\nTizen SDK");

	// Adds the text box to the form
	AddControl(__pTextBox);

	return r;
}
* @endcode
*/
class _OSP_EXPORT_ TextBox
	: public Tizen::Ui::Control
{
// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 *
	 */
	TextBox(void);

	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~TextBox(void);

	/**
	 * Initializes this instance of %TextBox with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect	            An instance of the Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the control.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	border	            The border style
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, TextBoxBorder border = TEXT_BOX_BORDER_ROUNDED);

	/**
	 * Initializes this instance of %TextBox with the specified parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Tizen::Graphics::FloatRectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the control.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	border				The border style
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, TextBoxBorder border = TEXT_BOX_BORDER_ROUNDED);

// Operation
public:
	/**
	 * Sets the auto-link mask.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	autoLinks		The auto-link mask @n
	 *						Multiple link types can be combined using the bitwise OR operator (see Tizen::Base::Utility::LinkType). @n For more information,
	 *						see <a href="../org.tizen.native.appprogramming/html/guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When @c autoLinks is set to @c 0, the auto-link detection is disabled.
	 * @see			Tizen::Base::Utility::LinkType
	 * @see			GetAutoLinkMask()
	 */
	result SetAutoLinkMask(unsigned long autoLinks);

	/**
	 * Gets the auto-link mask.
	 *
	 * @since		2.0
	 *
	 * @return		The auto-link mask
	 * @exception	E_SUCCESS				The method is successful.
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
	 * @param[in]	listener    The event listener to add
	 * @see			RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The event listener to remove
	 * @see			AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

// Text
	/**
	 * Appends the specified character at the end of the text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	character		The character to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- The method modifies the text buffer that is managed by the %TextBox control.
	 *			-To display the changes, the control must be drawn again.
	 */
	result AppendCharacter(const Tizen::Base::Character& character);

	/**
	 * Appends the specified text at the end of the text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text			The text to append
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks
	 *			-To denote the end of a line use '\\n'.
	 *			-The method modifies the text buffer that is managed by the %TextBox control.
	 *			-To display the changes, the control must be drawn again.
	 */
	result AppendText(const Tizen::Base::String& text);

	/**
	 * Clears the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			-The method modifies the text buffer that is managed by the %TextBox control.
	 *			-To display the changes, the control must be drawn again.
	 */
	result Clear(void);

	/**
	 * Gets the number of the lines contained in the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return		The line count of the text, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLineCount(void) const;

	/**
	 * Gets the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return		The text of the %TextBox control, @n
	 *			    else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets a portion of the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return		The specified portion of the text, @n
	 *              else an empty string if an error occurs
	 * @param[in]	start	        The starting index of the range
	 * @param[in]	end	            The last index of the range
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	 *								The index is greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Tizen::Base::String GetText(int start, int end) const;

	/**
	 * Gets the length of the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return		The length of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTextLength(void) const;

	/**
	 * Inserts the character at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index		    The position at which to insert the character
	 * @param[in]	character	    The character to insert
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result InsertCharacterAt(int index, const Tizen::Base::Character& character);

	/**
	 * Inserts the text at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index		    The position at which to insert the text
	 * @param[in]	text		    The text to insert
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result InsertTextAt(int index, const Tizen::Base::String& text);

	/**
	 * Sets the text to be displayed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text            The text to display
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks
	 *			-To denote the end of a line use '\\n'.
	 *			-The method modifies the text buffer that is managed by the %TextBox control.
	 *			-To display the changes, the control must be drawn again.
	 */
	result SetText(const Tizen::Base::String& text);

// Line Spacing
	/**
	 * Gets the line spacing.
	 *
	 * @since		2.0
	 *
	 * @return      The line spacing,  @n
	 *              else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLineSpacing()
	 */
	int GetLineSpacing(void) const;

	/**
	 * Gets the line spacing.
	 *
	 * @since		2.1
	 *
	 * @return      The line spacing,  @n
	 *              else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLineSpacing()
	 */
	float GetLineSpacingF(void) const;

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra. @n
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 *
	 * @since          2.0
	 *
	 * @return         An error code
	 * @param[in]      multiplier			The line spacing multiplier
	 * @param[in]      extra				The extra line spacing
	 * @exception      E_SUCCESS			The method is successful.
	 * @exception      E_INVALID_ARG		A specified input parameter is invalid. @n
	 *										The specified line spacing value cannot be supported.
	 * @exception      E_SYSTEM				A system error has occurred.
	 * @see            GetLineSpacing()
	 */
	result SetLineSpacing(int multiplier, int extra);

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra. @n
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 *
	 * @since          2.1
	 *
	 * @return         An error code
	 * @param[in]      multiplier			The line spacing multiplier
	 * @param[in]      extra				The extra line spacing
	 * @exception      E_SUCCESS			The method is successful.
	 * @exception      E_INVALID_ARG		A specified input parameter is invalid. @n
	 *										The specified line spacing value cannot be supported.
	 * @exception      E_SYSTEM				A system error has occurred.
	 * @see            GetLineSpacingF()
	 */
	result SetLineSpacing(int multiplier, float extra);

	// Text Alignment
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
	 * @param[in]	alignment		The horizontal text alignment
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetTextAlignment()
	 */
	result SetTextAlignment(HorizontalAlignment alignment);

	// Text Size
	/**
	 * Gets the text size of the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the text size of the %TextBox control.
	 *
	 * @since		2.1
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextSize()
	 */
	float GetTextSizeF(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	size                The text size
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       The specified input parameter is invalid. @n
	 *									The specified @c size cannot be a negative integer.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see			GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	 * Sets the text size.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	size                The text size
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       The specified input parameter is invalid. @n
	 *									The specified @c size cannot be a negative integer.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see			GetTextSizeF()
	 */
	result SetTextSize(float size);

	// Text Font
	/**
	 * @if OSPDEPREC
	 * Gets the font typeface name and the style mask of the %TextBox control.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated. Instead of using this method, use the GetTextStyle() method.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	typefaceName        The name of the font typeface
	 * @param[out]	style               The text style (see TextBoxTextStyle)
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks     Multiple styles can be combined using the bitwise OR operator.
	 * @see			SetFontType()
	 * @see			Tizen::Graphics::Font::GetSystemFontListN()
	 * @see			TextBoxTextStyle
	 * @endif
	 */
	result GetFontType(Tizen::Base::String& typefaceName, unsigned long& style) const;

	/**
	* Gets the text style mask of the %TextBox control.
	*
	* @since 2.0
	*
	* @return                  A bitwise combination of Tizen::Ui::Controls::TextBoxTextStyle
	* @see                      SetTextStyle()
	* @see                      TextBoxTextStyle
	*/
	unsigned long GetTextStyle(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the font and the style mask of the %TextBox control.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated. Instead of using this method, use the SetTextStyle() method.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	typefaceName        The name of the font typeface
	 * @param[in]	style               The text style @n
	 *								    Multiple styles can be combined using the bitwise OR operator(see TextBoxTextStyle).
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       A specified input parameter is invalid, or the specified font typeface is not supported.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks	    The specified font typeface must be one of the system fonts. @n
	 *              @c italic and @c bold cannot be applied at the same time. If the specified style mask contains both @c italic and @c bold, @c italic will
	 *				be applied.
	 * @see			GetFontType()
	 * @see			Tizen::Graphics::Font::GetSystemFontListN()
	 * @see			TextBoxTextStyle
	 * @endif
	 */
	result SetFontType(const Tizen::Base::String& typefaceName, unsigned long style);

	/**
	* Sets the text style mask of the %TextBox control.
	*
	* @since 2.0
	*
	* @return                  An error code
	* @param[in]    style               The text style @n
	*                      Multiple styles can be combined using the bitwise OR operator (see Tizen::Ui::Controls::TextBoxTextStyle).
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_OUT_OF_MEMORY  The memory is insufficient.
	* @see                      GetTextStyle()
	* @see                      TextBoxTextStyle
	*/
	result SetTextStyle(unsigned long style);

	using Control::SetFont;
	/**
	 * @if OSPDEPREC
	 * Sets the font to render the text.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated. Instead of using this method, use the SetFont(const String& fontName) method of superclass.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	font             The text font
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_SYSTEM         A system error has occurred.
	 * @remarks		All previously set text attributes (style, weight, decoration, and size) will be discarded.
	 * @endif
	 */
	result SetFont(const Tizen::Graphics::Font& font);

// Text Block
	/**
	 * Releases the selection of the current text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @see			GetBlockRange()
	 * @see			SetBlockRange()
	 */
	result ReleaseBlock(void);

	/**
	 * Gets the start and the end index of the currently selected text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	start	           The start index of the text block
	 * @param[out]	end                The end index of the text block
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @remarks		The method returns @c start = 0 and @c end = 0 if there is no selected text block.
	 * @see			ReleaseBlock()
	 * @see			SetBlockRange()
	 */
	result GetBlockRange(int& start, int& end) const;

	/**
	 * Sets the specified block of the text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	start	        The start index of the text block
	 * @param[in]	end             The end index of the text block
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	 *								Either the @c start or @c end parameters are greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @see			ReleaseBlock()
	 * @see			GetBlockRange()
	 */
	result SetBlockRange(int start, int end);

// Appearances
	/**
	 * Gets the color of the %TextBox control for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The color of the %TextBox control, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	status			The state of the %TextBox control
	 * @exception	E_SUCCESS           The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetColor()
	 */
	Tizen::Graphics::Color GetColor(TextBoxStatus status) const;

	/**
	 * Gets the text color of the specified text color type.
	 *
	 * @since		2.0
	 *
	 * @return		The color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	type				The text color type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(TextBoxTextColor type) const;

	/**
	 * Sets the background bitmap of the %TextBox control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status			The state of the %TextBox control
	 * @param[in]	bitmap			The background bitmap
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @see			SetBackgroundColor()
	 */
	result SetBackgroundBitmap(TextBoxStatus status, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the %TextBox control for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status          The state of the %TextBox control
	 * @param[in]	color           The color to set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(TextBoxStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the %TextBox control for the specified text type.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	type             The text color type
	 * @param[in]	color            The text color to set
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_SYSTEM         A system error has occurred.
	 * @see			GetTextColor()
	 */
	result SetTextColor(TextBoxTextColor type, const Tizen::Graphics::Color& color);

	/**
	 * Adds a text block event listener.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @remarks		Programmatically modifying the text selection does not cause the text block selection event to fire.
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
	 * @see			AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

protected:
	friend class _TextBoxImpl;

private:
	TextBox(const TextBox& value);
	TextBox& operator =(const TextBox& value);
};  //TextBox
}}} //Tizen::Ui::Controls

#endif  // _FUI_CTRL_TEXT_BOX_H_
