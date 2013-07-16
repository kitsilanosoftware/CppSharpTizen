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
 * @file	FUiCtrlExpandableEditArea.h
 * @brief	This is the header file for the %ExpandableEditArea class.
 *
 * This header file contains the declarations of the %ExpandableEditArea class.
 */

#ifndef _FUI_CTRL_EXPANDABLE_EDIT_AREA_H_
#define _FUI_CTRL_EXPANDABLE_EDIT_AREA_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseTypes.h>
#include <FUiControl.h>
#include <FUiCtrlEditTypes.h>
#include <FUiCtrlIEditTextFilter.h>
#include <FUiCtrlITokenFilter.h>
#include <FUiIKeypadEventListener.h>
#include <FUiILanguageEventListener.h>
#include <FUiITextBlockEventListener.h>
#include <FUiITextEventListener.h>

// Forward declaration
namespace Tizen { namespace Graphics
{
class Rectangle;
}}	// Tizen::Graphics

namespace Tizen { namespace Ui { namespace Controls
{

class IExpandableEditAreaEventListener;

/**
 * @enum ExpandableEditAreaStyle
 *
 * Defines the possible styles of the expandable edit area.
 *
 * @since		2.0
 */
enum ExpandableEditAreaStyle
{
	EXPANDABLE_EDIT_AREA_STYLE_NORMAL,  /**< The normal expandable edit area */
	EXPANDABLE_EDIT_AREA_STYLE_TOKEN    /**< The token expandable edit area */
};


/**
 * @enum ExpandableEditAreaTitleStyle
 *
 * Defines the possible styles of the expandable edit area title.
 *
 * @since		2.0
 */
enum ExpandableEditAreaTitleStyle
{
	EXPANDABLE_EDIT_AREA_TITLE_STYLE_NONE = 0,      /**< The style with no title */
	EXPANDABLE_EDIT_AREA_TITLE_STYLE_INNER,         /**< The title appears as a right aligned text inside the edit text field */
	EXPANDABLE_EDIT_AREA_TITLE_STYLE_TOP            /**< The title appears at the top of the edit text field */
};


/**
 * @enum ExpandableEditAreaTokenStatus
 *
 * Defines the possible status of the expandable edit area tokens.
 *
 * @since		2.0
 */
enum ExpandableEditAreaTokenStatus
{
	EXPANDABLE_EDIT_AREA_TOKEN_STATUS_NORMAL = 0,   /**< The normal status */
	EXPANDABLE_EDIT_AREA_TOKEN_STATUS_SELECTED      /**< The selected status */
};


/**
 * @class	ExpandableEditArea
 * @brief	This class is an implementation of %ExpandableEditArea.
 *
 * @since	2.0
 *
 * The %ExpandableEditArea class displays a multi-line text editor the height of that is automatically adjusted according to the number of lines currently visible in the text box.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.
 *
* The following sample code demonstrates how to use the %ExpandableEditArea class.
*
* @code
// Sample code for ExpandableEditAreaSample.h
#include <FUi.h>

class ExpandableEditAreaSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IKeypadEventListener
	, public Tizen::Ui::Controls::IExpandableEditAreaEventListener
{
public:
	ExpandableEditAreaSample(void)
	: __pExpandableEdit(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	//IKeypadEventListener
	virtual void OnKeypadActionPerformed(Tizen::Ui::Control& source, Tizen::Ui::KeypadAction keypadAction);
	virtual void OnKeypadClosed(Tizen::Ui::Control& source);
	virtual void OnKeypadOpened(Tizen::Ui::Control& source);
	virtual void OnKeypadWillOpen(Tizen::Ui::Control& source);

	//IExpandableEditAreaEventListener
	virtual void OnExpandableEditAreaLineAdded(Tizen::Ui::Controls::ExpandableEditArea& source, int newLineCount);
	virtual void OnExpandableEditAreaLineRemoved(Tizen::Ui::Controls::ExpandableEditArea& source, int newLineCount);

private:
	Tizen::Ui::Controls::ExpandableEditArea* __pExpandableEdit;
};

* @endcode
*
* @code
// Sample code for ExpandableEditAreaSample.cpp
#include <FGraphics.h>

#include "ExpandableEditAreaSample.h"

using namespace Tizen::Graphics;;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
ExpandableEditAreaSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ExpandableEditAreaSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	__pExpandableEdit = new ExpandableEditArea();
	__pExpandableEdit->Construct(Rectangle(25, 100, GetClientAreaBounds().width - 50, 150),
			EXPANDABLE_EDIT_AREA_STYLE_NORMAL, EXPANDABLE_EDIT_AREA_TITLE_STYLE_NONE, 5);

	// Adds an instance of IKeypadEventListenerevent and an instance of IExpandableEditAreaEventListener
	__pExpandableEdit->AddKeypadEventListener(*this);
	__pExpandableEdit->AddExpandableEditAreaEventListener(*this);

	AddControl(__pExpandableEdit);

	// Sets a focus to the expandable edit area
	__pExpandableEdit->SetFocus();

	return r;
}

// IKeypadEventListener implementation
void
ExpandableEditAreaSample::OnKeypadActionPerformed(Tizen::Ui::Control& source, Tizen::Ui::KeypadAction keypadAction)
{
	// ....
}

void
ExpandableEditAreaSample::OnKeypadClosed(Tizen::Ui::Control& source)
{
	// ....
}

void
ExpandableEditAreaSample::OnKeypadOpened(Tizen::Ui::Control& source)
{
	// ....
}

void
ExpandableEditAreaSample::OnKeypadWillOpen(Tizen::Ui::Control& source)
{
	// ....
}

// IExpandableEditAreaEventListener implementation
void
ExpandableEditAreaSample::OnExpandableEditAreaLineAdded(Tizen::Ui::Controls::ExpandableEditArea& source, int newLineCount)
{
	// ....
}

void
ExpandableEditAreaSample::OnExpandableEditAreaLineRemoved(Tizen::Ui::Controls::ExpandableEditArea& source, int newLineCount)
{
	// ....
}
* @endcode
*/
class _OSP_EXPORT_ ExpandableEditArea
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	ExpandableEditArea(void);

	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ExpandableEditArea(void);

	/**
	 * Initializes this instance of %ExpandableEditArea with the specified parameters.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    rect             An instance of the Graphics::Rectangle class @n
	 *										This instance represents the x and y coordinates of the top-left corner of the expandable edit area along with
	 *										the width and height. @n
	 *										The optimal size of the control is defined in
	 *										<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]    style            The style of the expandable edit area
	 * @param[in]    titleStyle       The title style
	 * @param[in]    maxExpandableLines         The maximum number of lines to which the control can be expanded.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception    E_UNSUPPORTED_OPTION   The specified option is not supported. @n
	 *										The token style %ExpandabledEditArea does not support @c EXPANDABLE_EDIT_AREA_TITLE_STYLE_TOP.
	 * @exception    E_MAX_EXCEEDED         The number of lines has exceeded the maximum limit.
	 * @exception	E_INVALID_ARG           A specified input parameter is invalid, or @n
	 *										the specified @c maxLines is either negative or @c 0.
	 * @exception	E_SYSTEM                A system error has occurred.
	 * @remarks      By default, the line count is @c 1.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, ExpandableEditAreaStyle style, ExpandableEditAreaTitleStyle titleStyle, int maxExpandableLines = 10);

	/**
	 * Initializes this instance of %ExpandableEditArea with the specified parameters.
	 *
	 * @since        2.1
	 *
	 * @return       An error code
	 * @param[in]    rect             An instance of the Tizen::Graphics::FloatRectangle class @n
	 *										This instance represents the x and y coordinates of the top-left corner of the expandable edit area along with
	 *										the width and height. @n
	 *										The optimal size of the control is defined in
	 *										<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]    style            The style of the expandable edit area
	 * @param[in]    titleStyle       The title style
	 * @param[in]    maxExpandableLines         The maximum number of lines to which the control can be expanded.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception    E_UNSUPPORTED_OPTION   The specified option is not supported. @n
	 *										The token style %ExpandabledEditArea does not support @c EXPANDABLE_EDIT_AREA_TITLE_STYLE_TOP.
	 * @exception    E_MAX_EXCEEDED         The number of lines has exceeded the maximum limit.
	 * @exception	E_INVALID_ARG           A specified input parameter is invalid, or @n
	 *										the specified @c maxLines is either negative or @c 0.
	 * @exception	E_SYSTEM                A system error has occurred.
	 * @remarks      By default, the line count is @c 1.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, ExpandableEditAreaStyle style, ExpandableEditAreaTitleStyle titleStyle, int maxExpandableLines = 10);

// TEXT MANAGEMENT
	/**
	 * Appends the specified character at the end of the existing text.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]	character       The character to append
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_MAX_EXCEEDED  The number of items has exceeded the maximum limit. @n
	 *                              The number of characters has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	 *			- To display the changes, the control must be drawn again.
	 */
	result AppendCharacter(const Tizen::Base::Character& character);

	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   text            The text to append
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception	E_MAX_EXCEEDED  The number of items has exceeded the maximum limit @n
	 *                              The number of characters has exceeded the maximum limit.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks
	 *			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	 *			- To display the changes, the control must be drawn again.
	 */
	result AppendText(const Tizen::Base::String& text);

	/**
	* Appends the text that will be displayed by bitmap at the end of the existing text.
	*
	* @since 2.0
	*
	* @return             An error code
	* @param[in]   text            The text to append @n
	*                                                                  It will be displayed by the @c textImage.
	* @param[in]   textImage The alternate bitmap to display
	* @exception   E_SUCCESS        The method is successful.
	* @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds the maximum length of the text that can be displayed by % ExpanableEditArea.
	* @exception   E_UNSUPPORTED_OPERATION  The current state of the instance prohibits the execution of the specified operation. @n
	*                                                             The operation is not supported if the style is ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @remarks
	*			- The method modifies the text buffer that is managed by the %ExpanableEditArea control.
	*			- To display the changes, the control must be drawn again. The text to be appended will be displayed by the @c textImage.
	*/
	result AppendText(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap& textImage);

	/**
	* Deletes the character present at the current cursor position.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   index			The index
	* @exception   E_SUCCESS		The method is successful.
	* @exception   E_INVALID_ARG	The specified input parameter is invalid. @n
	*								The specified @c index is negative.
	* @exception   E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	*								Either the specified @c index is greater than the number of elements or less than @c 0.
	* @exception   E_SYSTEM		A system error has occurred.
	* @remarks
	*			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	*			- To display the changes, the control must be drawn again.
	*/
	result DeleteCharacterAt(int index);

	/**
	* Inserts a character at the specified index.
	*
	* @since       2.0
	*
	* @return	    An error code
	* @param[in]   index           The position to insert the character
	* @param[in]   character	    The character to insert
	* @exception   E_SUCCESS        The method is successful.
	* @exception   E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	*								Either the specified @c index is greater than the number of elements or less than @c 0.
	* @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds system limitations.
	* @exception   E_SYSTEM        A system error has occurred.
	* @remarks
	*			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	*			- To display the changes, the control must be drawn again.
	*/
	result InsertCharacterAt(int index, const Tizen::Base::Character& character);

	/**
	* Inserts the text at the specified index.
	*
	* @since       2.0
	*
	* @return	    An error code
	* @param[in]   index           The position to insert the text
	* @param[in]   text            The text to insert
	* @exception   E_SUCCESS        The method is successful.
	* @exception   E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	*								Either the specified @c index is greater than the number of elements or less than @c 0.
	* @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds system limitations.
	* @exception   E_SYSTEM	    A system error has occurred.
	*/
	result InsertTextAt(int index, const Tizen::Base::String& text);

	/**
	* Inserts the text that will be displayed by bitmap at the specified text position.
	*
	* @since 2.0
	*
	* @return             An error code
	* @param[in]   position           The position to insert the text
	* @param[in]   text            The text to insert @n
	*                                                                  It will be displayed by the @c textImage.
	* @param[in]   textImage The alternate bitmap to display
	* @exception   E_SUCCESS        The method is successful.
	* @exception   E_OUT_OF_RANGE  The specified @c position is outside the valid range. @n
	*                                Either the specified @c position is greater than the number of existing text in the % ExpanableEditArea or less than @c 0.
	* @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds the maximum length of the text that can be displayed by % ExpanableEditArea.
	* @exception   E_UNSUPPORTED_OPERATION  The current state of the instance prohibits the execution of the specified operation. @n
	*										The operation is not supported if the style 	is ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @remarks
	*			- The method modifies the text buffer that is managed by the %ExpanableEditArea control.
	*			- To display the changes, the control must be drawn again. The text to be inserted will be displayed by the @c textImage.
	*/
	result InsertTextAt(int position, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap& textImage);

	/**
	* Gets the portion of the text that is displayed by the %ExpandableEditArea control.
	*
	* @since        2.0
	*
	* @return       The specified portion of the text, @n
	*               else an empty string if an error occurs
	* @param[in]    start           The starting index of the range
	* @param[in]    end             The last index of the range
	* @exception    E_SUCCESS       The method is successful.
	* @exception    E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	*								 The specified @c start or @c end is greater than the number of elements or less than @c 0.
	* @exception    E_SYSTEM        A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @see          GetText()
	* @see          SetText()
	*/
	Tizen::Base::String GetText(int start, int end) const;

	/**
	* Gets the text of the %ExpandableEditArea control.
	*
	* @since        2.0
	*
	* @return       The text of the %ExpandableEditArea control, @n
	*               else an empty string if an error occurs
	* @exception    E_SUCCESS       The method is successful.
	* @exception    E_SYSTEM        A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::String GetText(void) const;

	/**
	* Gets the text length.
	*
	* @since       2.0
	*
	* @return      The length of the text, @n
	*	            else @c -1 if an error occurs
	* @exception   E_SUCCESS       The method is successful.
	* @exception   E_SYSTEM        A system error has occurred.
	* @remarks     The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetTextLength(void) const;

	/**
	* Sets the text to be displayed by the %ExpandableEditArea control.
	*
	* @since		2.0
	*
	* @param[in]	text            The text to set
	* @exception	E_SUCCESS       The method is successful.
	* @exception	E_INVALID_ARG   The specified input parameter is invalid, @n
	*								or the length of the specified @c text exceeds system limitations.
	* @exception	E_SYSTEM        A system error has occurred.
	* @remarks
	*			- To denote the end of a line use '\\n'.
	*			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	*			- To display the changes, the control must be drawn again.
	*/
	result SetText(const Tizen::Base::String& text);

	/**
	* Clears the text that is displayed by the %ExpandableEditArea control.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS       The method is successful.
	* @exception	E_SYSTEM        A system error has occurred.
	* @remarks
	*			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	*			- To display the changes, the control must be drawn again.
	*/
	result Clear(void);

	/**
	 * Sets the title of the %ExpandableEditArea control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   title			The title to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the
	 * 										execution of the specified operation. @n This operation
	 * 										is not supported if the title is not set.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetTitleText(const Tizen::Base::String& title);

	/**
	 * Gets the title of the %ExpandableEditArea control.
	 *
	 * @since		2.0
	 *
	 * @return		The title text of the entered string, @n
	 *			    else empty string if an error occurs
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetTitleText(void) const;

// GUIDE TEXT
	/**
	 * Gets the guide text.
	 *
	 * @since       2.0
	 *
	 * @return	    The guide text, @n
	 *              else an empty string if an error occurs
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetGuideText()
	 */
	Tizen::Base::String GetGuideText(void) const;

	/**
	* Sets the guide text to be displayed, when there is no data in the search field.
	*
	* @since       2.0
	*
	* @return	    An error code
	* @param[in]   guideText		 The guide text
	* @exception   E_SUCCESS        The method is successful.
	* @exception   E_SYSTEM         A system error has occurred.
	* @see         GetGuideText()
	*/
	result SetGuideText(const Tizen::Base::String& guideText);

// LINE MANAGEMENT
	/**
	 * Gets the maximum line count supported by the flexible text edit.
	 *
	 * @since       2.0
	 *
	 * @return      The maximum line count, @n
	 *	            else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetMaxLineCount(void) const;

	/**
	 * Gets the line spacing.
	 *
	 * @since 2.0
	 * @return 	The line spacing, @n
	 * 		    else @c -1 if an error occurs
	 * @see 	SetLineSpacing ()
	 */
	int GetLineSpacing(void) const;

	/**
	 * Gets the line spacing.
	 *
	 * @since 2.1
	 * @return 	The line spacing, @n
	 * 		    else @c -1.0f if an error occurs
	 * @see 	SetLineSpacing ()
	 */

	float GetLineSpacingF(void) const;

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra.
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 *
	 * @since 2.0
	 * @return 	An error code
	 * @param[in]   multiplier		 The line spacing multiplier
	 * @param[in]   extra		 The extra line spacing
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       This exception is returned when @c multiplier or @c extra is less than 0.
	 * @see 	GetLineSpacing ()
	 */
	result SetLineSpacing(int multiplier, int extra);

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra.
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 *
	 * @since 2.1
	 * @return 	An error code
	 * @param[in]   multiplier		 The line spacing multiplier
	 * @param[in]   extra		 The extra line spacing
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       This exception is returned when @c multiplier or @c extra is less than 0.
	 * @see 	GetLineSpacing ()
	 */
	result SetLineSpacing(int multiplier, float extra);

	/**
	* Gets the current line count.
	*
	* @since       2.0
	*
	* @return      The line count of the text
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_SYSTEM            A system error has occurred.
	* @remarks     The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetTextLineCount(void) const;

// TEXT SIZE
	/**
	 * Gets the text size.
	 *
	 * @since       2.0
	 *
	 * @return      The size of the text, @n
	 *	            else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
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
	 *	            else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	float GetTextSizeF(void) const;

	/**
	* Sets the text size.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   size                The text size
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_INVALID_ARG       The specified @c size is invalid, @n
	*									or the specified @c size is a negative integer.
	* @exception   E_SYSTEM            A system error has occurred.
	* @see         GetTextSize()
	*/
	result SetTextSize(int size);

	/**
	* Sets the text size.
	*
	* @since       2.1
	*
	* @return      An error code
	* @param[in]   size                The text size
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_INVALID_ARG       The specified @c size is invalid, @n
	*									or the specified @c size is a negative integer.
	* @exception   E_SYSTEM            A system error has occurred.
	* @see         GetTextSizeF()
	*/
	result SetTextSize(float size);

// MARGINS
	/**
	 * Gets the margin of the specified margin type.
	 *
	 * @since       2.0
	 *
	 * @return      The margin value of the specified margin type, @n
	 *	            else @c -1 if an error occurs
	 * @param[in]   marginType      The margin type
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	int GetMargin(EditMarginType marginType) const;

	/**
	 * Gets the margin of the specified margin type.
	 *
	 * @since       2.1
	 *
	 * @return      The margin value of the specified margin type, @n
	 *	            else @c -1.0f if an error occurs
	 * @param[in]   marginType      The margin type
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	float GetMarginF(EditMarginType marginType) const;

	/**
	 * Sets the margin for the specified margin type.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   marginType          The margin type
	 * @param[in]   margin              The margin to set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *                                  The specified @c margin cannot be negative integer.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         GetMargin()
	 */
	result SetMargin(EditMarginType marginType, int margin);
	/**
	 */

	/*
	 * Sets the margin for the specified margin type.
	 *
	 * @since       2.1
	 * @return      An error code
	 * @param[in]   marginType          The margin type
	 * @param[in]   margin              The margin to set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *                                  The specified @c margin cannot be negative integer.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         GetMargin()
	 */
	result SetMargin(EditMarginType marginType, float margin);
	/*
	 */

// LOWER CASE
	/**
	 * Enables or disables the lowercase mode.

	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   enable              Set to @c true to enable the lowercase mode, @n
	 *	                                else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     When the lowercase mode is enabled, the text input starts with a lowercase character.
	 * @see         IsLowerCaseModeEnabled()
	 */
	result SetLowerCaseModeEnabled(bool enable);

	/**
	 * Checks whether the lowercase mode is enabled.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the lowercase mode is enabled, @n
	 *	            else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetLowerCaseModeEnabled()
	 */
	bool IsLowerCaseModeEnabled(void) const;

// CURSOR MANAGEMENT
	/**
	 * Gets the cursor position.
	 *
	 * @since        2.0
	 *
	 * @return       The current cursor position, @n
	 *				 else @c -1 if an error occurs
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_SYSTEM           A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCursorPosition(void) const;

	/**
	 * Sets the cursor at the specified position.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    position        The cursor position to set
	 * @exception    E_SUCCESS       The method is successful.
	 * @exception    E_OUT_OF_RANGE  The specified @c position is less than @c 0 or greater than the maximum length.
	 * @exception    E_SYSTEM        A system error has occurred.
	 */
	result SetCursorPosition(int position);

// TEXT BLOCKING
	/**
	 * Gets the start and end indexes of the currently selected text block.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[out]  start              The start index of the text block
	 * @param[out]  end                The end index of the text block
	 * @exception   E_SUCCESS          The method is successful.
	 * @exception   E_SYSTEM           A system error has occurred.
	 * @remarks     The method returns the start and end indexes as @c 0 if no text block is selected.
	 * @see         ReleaseBlock()
	 * @see         SetBlockRange()
	 */
	result GetBlockRange(int& start, int& end) const;

	/**
	* Releases the selection of the current text block.
	*
	* @since       2.0
	*
	* @return      An error code
	* @exception   E_SUCCESS          The method is successful.
	* @exception   E_SYSTEM           A system error has occurred.
	* @see         GetBlockRange()
	* @see         SetBlockRange()
	*/
	result ReleaseBlock(void);

	/**
	* Removes the text content of the current text block.
	*
	* @since        2.0
	*
	* @return       An error code
	* @exception    E_SUCCESS          The method is successful.
	* @exception    E_OBJ_NOT_FOUND    The specified instance is not found, @n
	*									or the text block is not selected.
	* @exception    E_SYSTEM           A system error has occurred.
	*/
	result RemoveTextBlock(void);

	/**
	* Sets the block range for the text.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   start           The start index of the text block
	* @param[in]   end             The end index of the text block
	* @exception   E_SUCCESS       The method is successful.
	* @exception   E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	*								Either the index is greater than the number of elements or less than @c 0.
	* @exception   E_SYSTEM        A system error has occurred.
	* @see         ReleaseBlock()
	* @see         GetBlockRange()
	*/
	result SetBlockRange(int start, int end);

// KEYPAD MANAGEMENT
	/**
	 * Gets the keypad action type.
	 *
	 * @since       2.0
	 *
	 * @return      The keypad action
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadAction()
	 */
	Tizen::Ui::KeypadAction GetKeypadAction(void) const;

	/**
	* Gets the keypad style.
	*
	* @since       2.0
	*
	* @return      The keypad style
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_SYSTEM            A system error has occurred.
	* @remarks     The specific error code can be accessed using the GetLastResult() method.
	* @see         SetKeypadStyle()
	*/
	KeypadStyle GetKeypadStyle(void) const;

	/**
	* Hides the keypad associated with the %ExpandableEditArea control.
	*
	* @since       2.0
	*
	* @return      An error code
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_SYSTEM            A system error has occurred.
	* @see         ShowKeypad()
	*/
	result HideKeypad(void);

	/**
	* Checks whether the keypad is enabled.
	*
	* @since       2.0
	*
	* @return      @c true if the keypad is enabled, @n
	*	            else @c false
	* @exception   E_SUCCESS            The method is successful.
	* @exception   E_SYSTEM             A system error has occurred.
	* @remarks     The specific error code can be accessed using the GetLastResult() method.
	* @see         SetKeypadEnabled()
	*/
	bool IsKeypadEnabled(void) const;

	/**
	 * Sets the keypad action type.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   keypadAction			The keypad action
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_SYSTEM				A system error has occurred.
	 * @remarks     Depending on the value of @c keypadAction, the enter key label of the keypad will change accordingly.
	 * @see         GetKeypadAction()
	 */
	result SetKeypadAction(Tizen::Ui::KeypadAction keypadAction);

	/**
	* Sets the keypad style.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   keypadStyle         The keypad style
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
	*                                  The specified @c keypadStyle is @c KEYPAD_STYLE_PASSWORD.
	* @exception   E_SYSTEM            A system error has occurred.
	* @remarks     Depending on the value of the keypad style, the layout of the keypad will change accordingly.
	* @see         GetKeypadStyle()
	*/
	result SetKeypadStyle(KeypadStyle keypadStyle);

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
	* @see                    IsTextPredictionEnabled()
	*/
	result SetTextPredictionEnabled(bool enable);

	/**
	* Enables or disables the keypad.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   enable			Set to @c true to enable the virtual keypad, @n
	*								else @c false
	* @exception   E_SUCCESS		The method is successful.
	* @exception   E_SYSTEM		A system error has occurred.
	* @see         IsKeypadEnabled()
	*/
	result SetKeypadEnabled(bool enable);

	/**
	* Shows the keypad.
	*
	* @since       2.0
	*
	* @return      An error code
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_SYSTEM            A system error has occurred.
	* @see         HideKeypad()
	*/
	result ShowKeypad(void);

// TOKEN FILTER
	/**
	 * Sets the text token filter.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   pFilter                 The filter
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *										The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     The %ExpandableEditArea control checks with the registered filter to decide whether the user-entered text should be replaced.
	 */
	result SetTokenFilter(const ITokenFilter* pFilter);

	/**
	* Gets the text token filter.
	*
	* @since        2.0
	*
	* @return       The filter, @n
	*				 else @c null if an error occurs
	* @exception    E_SUCCESS                   The method is successful.
	* @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	*											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @exception    E_SYSTEM                    A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	ITokenFilter* GetTokenFilter(void) const;

	/**
	* Appends the specified token.
	*
	* @since        2.0
	*
	* @return       An error code
	* @param[in]    token                   The token to append
	* @exception    E_SUCCESS               The method is successful.
	* @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	*											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @exception    E_INVALID_ARG           The specified input parameter is invalid. @n
	*                                           The length of the specified @c token is @c 0.
	* @exception    E_SYSTEM                A system error has occurred.
	*/
	result AppendToken(const Tizen::Base::String& token);

	/**
	 * Inserts the token at the specified index.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]	 index						The position to insert the token
	 * @param[in]    token                      The token to add
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_ARG              A specified input parameter is invalid. @n
	 *                                          The length of the specified @c token is @c 0.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 */
	result InsertTokenAt(int index, const Tizen::Base::String& token);

	/**
	 * Gets the token text at the specified index.
	 *
	 * @since        2.0
	 *
	 * @return       The token text at the specified index, @n
	 *               else an empty string if an error occurs
	 * @param[in]	   index						          The position to get the token
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_OUT_OF_RANGE				The specified index parameter is outside the bounds of the data structure. @n
	 *											Either the index is greater than the number of elements or less than @c 0.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetTokenAt(int index) const;

	/**
	 * Gets the total token count.
	 *
	 * @since        2.0
	 *
	 * @return       The total token count, @n
	 *	             else @c -1 if an error occurs
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTokenCount(void) const;

	/**
	 * Gets the index of the token that is selected.
	 *
	 * @since        2.0
	 *
	 * @return       The index of the selected token, @n
	 *	             else @c -1 if no token is selected or if an error occurs
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetSelectedTokenIndex(void) const;

	/**
	* Checks whether the token editing mode is enabled.
	*
	* @since        2.0
	*
	* @return       @c true if the editing mode is enabled, @n
	*	             else @c false
	* @exception    E_SUCCESS                   The method is successful.
	* @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	*											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @exception    E_SYSTEM                    A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	bool IsTokenEditModeEnabled(void) const;

	/**
	* Removes the token at the specified index.
	*
	* @since        2.0
	*
	* @return       An error code
	* @param[in]    index                   The index of the token to remove
	* @exception    E_SUCCESS               The method is successful.
	* @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	*											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @exception    E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n
	*											Either the index is greater than the number of elements or less than @c 0.
	* @exception    E_SYSTEM                A system error has occurred.
	*/
	result RemoveTokenAt(int index);

	/**
	* Sets the selected state of the specified token.
	*
	* @since        2.0
	*
	* @return       An error code
	* @param[in]    index                   The index of the token to select
	* @param[in]    selected                Set to @c true to select the specified token, @n
	*											else @c false to unselect
	* @exception    E_SUCCESS               The method is successful.
	* @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	*											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @exception    E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n
	*											Either the index is greater than the number of elements or less than @c 0.
	* @exception    E_SYSTEM                A system error has occurred.
	* @remarks      The currently selected token gets unselected automatically.
	*/
	result SetTokenSelected(int index, bool selected);

	/**
	* Enables or disables the token edit mode.
	*
	* @since        2.0
	*
	* @return       An error code
	* @param[in]    enable	                    Set to @c true to enable the token editing mode, @n
	*											else @c false
	* @exception    E_SUCCESS               The method is successful.
	* @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	*											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	* @exception    E_SYSTEM                A system error has occurred.
	*/
	result SetTokenEditModeEnabled(bool enable);

// LIMIT LENGTH
	/**
	 * Gets the limit length.
	 *
	 * @since		2.0
	 *
	 * @return      The limit length, @n
	 *	            else @c -1 if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *			- The default limit length is @c 2048.
	 * @see         SetLimitLength()
	 */
	int GetLimitLength(void) const;

	/**
	 * Sets the limit length.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   limitLength		The limit text length to set
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	The specified input parameter is invalid, @n
	 *								or the specified limit length is @c 0 or negative.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- The method modifies the text buffer that is managed by the %ExpandableEditArea control.
	 *			- To display the changes, the control must be drawn again.
	 * @see         GetLimitLength()
	 */
	result SetLimitLength(int limitLength);

// APPEARANCES
	/**
	 * Gets the color of the %ExpandableEditArea control for the specified status.
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
	 * Gets the text color of the specified text type.
	 *
	 * @since        2.0
	 *
	 * @return       The text color, @n
	 *				 else RGBA (0,0,0,0) if an error occurs
	 * @param[in]    type                The text type
	 * @exception    E_SUCCESS			The method is successful.
	 * @exception    E_INVALID_ARG		The specified type is not supported, or @n
	 *									the specified @c type is @c EDIT_TEXT_COLOR_LINK.
	 * @exception    E_SYSTEM			A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(EditTextColor type) const;

	/**
	 * Gets the text color of the guide text.
	 *
	 * @since       2.0
	 *
	 * @return	    The guide text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetGuideTextColor()
	 */
	Tizen::Graphics::Color GetGuideTextColor(void) const;

	/**
	 * Gets the text color of the title for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The title text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	status			The state of the %ExpandableEditArea control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTitleTextColor()
	 */
	Tizen::Graphics::Color GetTitleTextColor(EditStatus status) const;

	/**
	 * Gets the color of the tokens for the specified status.
	 *
	 * @since        2.0
	 *
	 * @return       The token color, @n
	 *				 else RGBA (0,0,0,0) if an error occurs
	 * @param[in]    status                     The status
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetTokenColor
	 */
	Tizen::Graphics::Color GetTokenColor(ExpandableEditAreaTokenStatus status) const;

	/**
	 * Gets the text color of tokens.
	 *
	 * @since        2.0
	 *
	 * @return       The text color, @n
	 *				 else RGBA (0,0,0,0) if an error occurs
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetTokenTextColor()
	 */
	Tizen::Graphics::Color GetTokenTextColor(void) const;

	/**
	 * Gets the text color of tokens at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return       The text color, @n
	 * 				else RGBA (0,0,0,0) if an error occurs
	 * @exception    E_SUCCESS					The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits	the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetSelectedTokenTextColor()
	 */
	Tizen::Graphics::Color GetSelectedTokenTextColor(void) const;

	/**
	 * Sets the background bitmap of the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   status          The status
	 * @param[in]   bitmap          The background bitmap
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result SetBackgroundBitmap(EditStatus status, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   status          The status of the %ExpandableEditArea control
	 * @param[in]   color           The color
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         GetColor()
	 */
	result SetColor(EditStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the guide text.
	 *
	 * @since       2.0
	 *
	 * @return	    An error code
	 * @param[in]   color		     The guide text color
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @see         GetGuideTextColor()
	 */
	result SetGuideTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the title for the specified status.
	 *
	 * @since       2.0
	 *
	 * @return	    An error code
	 * @param[in]	status			The status of the %ExpandableEditArea control
	 * @param[in]   color			The title text color
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @see         GetTitleTextColor()
	 */
	result SetTitleTextColor(EditStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   type             The text type
	 * @param[in]   color            The text color
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @see         GetTextColor()
	 */
	result SetTextColor(EditTextColor type, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the tokens at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return       An error code
	 * @param[in]    color			The token text color
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits	the execution of the specified operation. @n
	 *											The	operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM					A system error has occurred.
	 * @see          GetSelectedTokenTextColor()
	 */
	result SetSelectedTokenTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the color of the tokens for the specified status.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    status                     The status
	 * @param[in]    color                      The token color
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @see          GetTokenColor()
	 */
	result SetTokenColor(ExpandableEditAreaTokenStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the tokens.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    color                      The token text color
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *											The operation is not supported if the style is not ::EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @see          GetTokenTextColor()
	 */
	result SetTokenTextColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Enables or disables the auto resizing if the candidate word list appears.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated     This API is deprecated because it is no longer necessary to handle the resizing of expandable edit area.
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   enable                  Set to @c true to enable the auto resizing, @n
	 *										else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *                                      The current style of the %ExpandableEditArea does not support the operation.
	 * @remarks     Note that when this option is enabled, the normal style %ExpandableEditArea is auto resized and the line added and removed events are
	 *				generated if the candidate word list pop-up appears during the predictive texting. @n
	 *              The operation is not supported by the token style %ExpandableEditArea.
	 * @see         IsAutoResizingEnabled()
	 * @see         Tizen::Ui::Controls::IExpandableEditAreaEventListener
	 * @endif
	 */
	result SetAutoResizingEnabled(bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the auto-resizing is enabled.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated     This API is deprecated because it is no longer necessary to handle the resizing of expandable edit area.
	 * @since       2.0
	 *
	 * @return      @c true if the auto-resizing is enabled, @n
	 *				else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *										The current style of the %ExpandableEditArea control does not support the operation.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetAutoResizingEnabled()
	 * @endif
	 */
	bool IsAutoResizingEnabled(void) const;

	/**
	* Sets the input language.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[in]  languageCode               The language to set
	* @exception  E_SUCCESS              The method is successful.
	* @exception  E_OUT_OF_MEMORY                   The memory is insufficient.
	* @remarks
	*			- The application can set the language of the current keypad that is associated with the current %ExpandableEditArea.
	*			- This method only works if the language to set is supported by the current preloaded keypad.
	*/
	result SetCurrentLanguage(Tizen::Locales::LanguageCode languageCode);

	/**
	* Gets the current input language.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[out] language               The current input language
	* @exception     E_SUCCESS                             The method is successful.
	* @remarks   The application can get the current language of the keypad that is associated with the current %ExpandableEditArea.
	*/
	result GetCurrentLanguage(Tizen::Locales::LanguageCode& language) const;

// EVENT LISTENER MANAGEMENT
	/**
	 * Adds the specified IExpandableEditAreaEventListener instance. @n
	 * The added listener can listen to events when a line is added or removed or when a button is pressed.
	 *
	 * @since       2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see         RemoveExpandableEditAreaEventListener()
	 */
	void AddExpandableEditAreaEventListener(IExpandableEditAreaEventListener& listener);

	/**
	 * Adds the specified IKeypadEventListener instance. @n
	 * The added listener is notified if the keypad associated with the edit area is opened or closed.
	 *
	 * @since       2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see         RemoveKeypadEventListener()
	 */
	void AddKeypadEventListener(Tizen::Ui::IKeypadEventListener& listener);

	/**
	 * Adds the specified ITextBlockEventListener instance.
	 *
	 * @since       2.0
	 *
	 * @param[in]	listener		The event listener to add
	 * @remarks		Programmatically modifying the text block does not cause the text block selection event to fire.
	 * @see         RemoveTextBlockEventListener()
	 */
	void AddTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	* Adds the specified ITextEventListener instance. @n
	* The added listener can listen to the text-changed event.
	*
	* @since       2.0
	*
	* @param[in]	listener		The listener to add
	* @see         RemoveTextEventListener()
	*/
	void AddTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Removes the specified IExpandableEditAreaEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]	listener		The event listener to remove
	 * @see         AddActionEventListener()
	 */
	void RemoveExpandableEditAreaEventListener(IExpandableEditAreaEventListener& listener);

	/**
	 * Removes the specified IKeypadEventListener listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]	listener		The event listener to remove
	 * @see         AddKeypadEventListener()
	 */
	void RemoveKeypadEventListener(Tizen::Ui::IKeypadEventListener& listener);

	/**
	 * Removes the specified ITextBlockEventListener listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]   listener		The event listener to remove
	 * @see         AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified ITextEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 *
	 * @param[in]   listener		The listener to remove
	 * @see         AddTextEventListener()
	 */
	void RemoveTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	* Adds a listener instance for language events. @n
	* The added listener is notified when the input language is changed.
	*
	* @since 2.0
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
	* @since 2.0
	*
	* @param[in]  listener               The listener to remove
	* @see             AddLanguageEventListener()
	*/

	void RemoveLanguageEventListener(Tizen::Ui::ILanguageEventListener& listener);

	/**
	 * Enables or disables the auto shrinking if the focus is lost.
	 *
	 * @since 2.0
	 *
	 * @param[in]   enable                  Set to @c true to enable the auto shrinking, @n
	 *										else @c false
	 * @remarks     Note that when this option is enabled, the %ExpandableEditArea is auto shrinked
	 *				if the %ExpandableEditArea lost its focus. @n
	 * @see         IsAutoShrinkModeEnabled()
	 */
	void SetAutoShrinkModeEnabled(bool enable);

	/**
	 * Checks whether the auto-shrinking is enabled.
	 *
	 * @since 2.0
	 *
	 * @return      @c true if the auto-shrinking is enabled, @n
	 *				else @c false
	 * @see         SetAutoShrinkModeEnabled()
	 */
	bool IsAutoShrinkModeEnabled(void) const;

	/**
	 * Sets the text filter.
	 *
	 * @since		2.1
	 *
	 * @param[in]		pFilter The filter to set
	 * @remarks 	The %ExpandableEditArea control checks with the registered filter to decide whether the user-entered text should be replaced or not.
	 */
	void  SetEditTextFilter(IEditTextFilter* pFilter);

	/**
	* Sends opaque command to the input method.
	*
	* @since     2.1
	*
	* @param[in] command            The opaque command to send
	* @remarks   This method can be used to provide domain-specific features that are only known between certain input methods and their clients.
	*                   This method may not work, depending on the active Input Method.
	*/
	void SendOpaqueCommand (const Tizen::Base::String& command);

protected:
	friend class _ExpandableEditAreaImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ExpandableEditArea(const ExpandableEditArea& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ExpandableEditArea& operator =(const ExpandableEditArea& rhs);
};	// ExpandableEditArea

}}} // Tizen::Ui::Controls

#endif      // _FUI_CTRL_EXPANDABLE_EDIT_AREA_H_
