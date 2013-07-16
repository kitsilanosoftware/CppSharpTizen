//
//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpEnrichedText.h
 * @brief	This is the header file for the %EnrichedText class.
 *
 * This header file contains the definitions of the %EnrichedText class.
 *
 */

#ifndef _FGRP_ENRICHED_TEXT_H_
#define _FGRP_ENRICHED_TEXT_H_

#include <FBase.h>
#include <FBaseUtilLinkInfo.h>
#include <FGrpTextElement.h>

namespace Tizen { namespace Graphics
{
/**
 * @enum TextHorizontalAlignment
 *
 * Defines the horizontal alignment of the text.
 *
 * @since		2.0
 */
enum TextHorizontalAlignment
{
	TEXT_ALIGNMENT_LEFT = 1,                    /**< The position of the text is towards the left of the object */
	TEXT_ALIGNMENT_CENTER,                  /**< The position of the text is towards the center of the object */
	TEXT_ALIGNMENT_RIGHT,                   /**< The position of the text is towards the right of the object */
	TEXT_ALIGNMENT_HORIZONTAL_MAX,          // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	TEXT_ALIGNMENT_HORIZONTAL_MIN = 0          // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum TextVerticalAlignment
 *
 * Defines the vertical alignment of the text.
 *
 * @since		2.0
 */
enum TextVerticalAlignment
{
	TEXT_ALIGNMENT_TOP = 1,					/**< The position of the text is towards the top of the object */
	TEXT_ALIGNMENT_MIDDLE,					/**< The position of the text is towards the middle of the object */
	TEXT_ALIGNMENT_BOTTOM,					/**< The position of the text is towards the bottom of the object */
	TEXT_ALIGNMENT_BASELINE,				/**< The position of the text is aligned along the baseline of the object */
	TEXT_ALIGNMENT_VERTICAL_MAX,			// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	TEXT_ALIGNMENT_VERTICAL_MIN = 0			// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum TextWrap
 *
 * Defines the style of wrapping of the text in %EnrichedText.
 *
 * @since		2.0
 */
enum TextWrap
{
	TEXT_WRAP_NONE = 1,                     /**< The wrapping of text is not applied */
	TEXT_WRAP_CHARACTER_WRAP,           /**< The wrapping of text is applied at the character unit */
	TEXT_WRAP_WORD_WRAP,                /**< The wrapping of text is applied at the word unit */
	TEXT_WRAP_MAX,                      // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	TEXT_WRAP_MIN = 0                      // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @class	EnrichedText
 * @brief	This class provides enriched text content.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %EnrichedText class provides methods that enable your application to support texts with various styles, such
 * as font, color, and layout. An %EnrichedText instance can be drawn to a Canvas.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/enriched_text.htm">EnrichedText</a>.
 *
 * The following example demonstrates how to use the %EnrichedText class.
 *
 * @code
#include <FApp.h>
#include <FBase.h>
#include <FGraphics.h>

using namespace Tizen::App;
using namespace Tizen::Graphics;

bool
MyClass::EnrichedTextSample(Canvas& canvas)
{
    result r = E_SUCCESS;
    EnrichedText* pEnrichedText = null;
    TextElement* pTextElement1 = null;
    TextElement* pTextElement2 = null;

    // Creates an EnrichedText instance and sets the attributes
    pEnrichedText = new EnrichedText();
    r = pEnrichedText->Construct(Dimension(200, 200));
    if (IsFailed(r))
    {
        goto CATCH;
    }
    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_RIGHT);
    pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_BOTTOM);
    pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
    pEnrichedText->SetTextAbbreviationEnabled(true);

    // Creates a TextElement and sets attributes
    pTextElement1 = new TextElement();
    r = pTextElement1->Construct(L"0123456789");
    if (IsFailed(r))
    {
        goto CATCH;
    }
    pTextElement1->SetTextColor(Color::GetColor(COLOR_ID_BLUE));
    {
        Font font;
        font.Construct(FONT_STYLE_BOLD, 40);
        pTextElement1->SetFont(font);
    }

    // Creates another TextElement and sets the attributes
    pTextElement2 = new TextElement();
    r = pTextElement2->Construct(L"abcdefghijklmn\nABCDEFGHIJKLMN");
    if (IsFailed(r))
    {
        goto CATCH;
    }
    pTextElement2->SetTextColor(Color::GetColor(COLOR_ID_VIOLET));

    // Adds the TextElement and the bitmap to the EnrichedText
    pEnrichedText->Add(*pTextElement1);
    pEnrichedText->Add(*pTextElement2);

    // Draws
    {
        canvas.SetBackgroundColor(Color::GetColor(COLOR_ID_BLACK));
        canvas.Clear();
        canvas.FillRectangle(Color::GetColor(COLOR_ID_WHITE), Rectangle(50, 50, 380, 380));

        // Draws the covered area of the EnrichedText in the Canvas coordinate
        int width, height;
        pEnrichedText->GetSize(width, height);
        canvas.FillRectangle(Color::GetColor(COLOR_ID_GREY), Rectangle(60, 60, width, height));

        // Draws the EnrichedText at the specified Point
        canvas.DrawText(Point(60, 60), *pEnrichedText);
        canvas.Show();
    }

    // Cleans up
    pEnrichedText->RemoveAll(true);
    delete pEnrichedText;

    return true;

CATCH:
    if (pEnrichedText)
    {
        pEnrichedText->RemoveAll(true);
        delete pEnrichedText;
    }

    return false;
}
 *	@endcode
 *
 *
 *
 *
 */

class _OSP_EXPORT_ EnrichedText
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly
	 *				to initialize this instance.
	 */
	EnrichedText(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~EnrichedText(void);

	/**
	 * Initializes this instance of %EnrichedText with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	dim					The dimension to set for %EnrichedText @n
	 *									The width and height must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::Dimension& dim);

	/**
	 * Initializes this instance of %EnrichedText with a specified parameter.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	dim					The FloatDimension to set for %EnrichedText @n
	 *									The width and height must be greater than @c 0.0f.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::FloatDimension& dim);

	/**
	 * Inserts the TextElement instance in the %EnrichedText instance at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	elementIndex		The index at which the text element is to add
	 * @param[in]	element				The TextElement to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result InsertAt(int elementIndex, TextElement& element);

	/**
	 * Removes the TextElement instance at the specified index of the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	elementIndex		The index of TextElement
	 * @param[in]	deallocate			Set to @c true to deallocate the TextElement instance, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result RemoveAt(int elementIndex, bool deallocate);

	/**
	 * Removes the TextElement instance from the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	element			The TextElement to remove
	 * @param[in]	deallocate			Set to @c true to deallocate the TextElement instance, @n
	 *										else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 *
	 */
	result Remove(TextElement& element, bool deallocate);

	/**
	 * Adds the specified TextElement instance to the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	element				The TextElement to append
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 *
	 */
	result Add(TextElement& element);

	/**
	 * @if OSPDEPREC
	 * Removes all the %TextElement instances from the %EnrichedText instance.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of this method, use the RemoveAll().
	 * @since		2.0
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	deallocate			Set to @c true to deallocate the %TextElement instance, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @see         RemoveAll()
	 *
	 */
	result RemoveAllTextElements(bool deallocate);

	/**
	 * Removes all the text and image elements from the %EnrichedText instance.
	 *
	 * @since          2.0
	 *
	 * @return         An error code
	 * @param[in]      deallocate			Set to @c true to deallocate the elements to remove, @n
	 *										else @c false
	 * @exception      E_SUCCESS            The method is successful.
	 * @exception      E_SYSTEM             An unknown operating system error has occurred.
	 *
	 */
	result RemoveAll(bool deallocate);

	/**
	 * Gets the %TextElement instance at the specified index from the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		The %TextElement instance at the specified index, @n
	 *				else @c null if the method fails
	 * @param[in]	elementIndex		The index of the %TextElement
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	TextElement* GetTextElementAt(int elementIndex) const;

	/**
	 * Gets the count of the %TextElement instances.
	 *
	 * @since		2.0
	 *
	 * @return		The count of the %TextElement instances
	 */
	int GetTextElementCount(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   size                The new size of the %EnrichedText instance @n
	 *                                  The width and height must be greater than @c 0.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The value of the parameter is outside the valid range defined by the method.
	 */
	result SetSize(const Tizen::Graphics::Dimension& size);

	/**
	 * Sets the text size.
	 *
	 * @since		2.1
	 *
	 * @return      An error code
	 * @param[in]   size                The new size of the %EnrichedText instance @n
	 *                                  The width and height must be greater than @c 0.0f.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The value of the parameter is outside the valid range defined by the method.
	 */
	result SetSize(const Tizen::Graphics::FloatDimension& size);

	/**
	 * Sets the text size.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   width	The new width of %EnrichedText @n
	 *					It must be greater than @c 0.
	 * @param[in]   height	The new height of %EnrichedText @n
	 *					It must be greater than @c 0.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 */
	result SetSize(int width, int height);

	/**
	 * Sets the text size.
	 *
	 * @since		2.1
	 *
	 * @return      An error code
	 * @param[in]   width	The new width of %EnrichedText @n
	 *					It must be greater than @c 0.0f.
	 * @param[in]   height	The new height of %EnrichedText @n
	 *					It must be greater than @c 0.0f.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 */
	result SetSize(float width, float height);

	/**
	 * Gets the size.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of %Dimension containing the width and the height of the %EnrichedText instance
	 *
	 */
	Tizen::Graphics::Dimension GetSize(void) const;

	/**
	 * Gets the size.
	 *
	 * @since		2.1
	 *
	 * @return		An instance of FloatDimension containing the width and the height of the %EnrichedText instance
	 *
	 */
	Tizen::Graphics::FloatDimension GetSizeF(void) const;

	/**
	 * Gets the size of the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @param[out]	width		The width of the control
	 * @param[out]	height		The height of the control
	 */
	void GetSize(int& width, int& height) const;

	/**
	 * Gets the size of the %EnrichedText instance.
	 *
	 * @since		2.1
	 *
	 * @param[out]	width		The width of the control
	 * @param[out]	height		The height of the control
	 */
	void GetSize(float& width, float& height) const;

	/**
	 * Gets the width of the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		The width
	 */
	int GetWidth(void) const;

	/**
	 * Gets the width of the %EnrichedText instance.
	 *
	 * @since		2.1
	 *
	 * @return		The width
	 */
	float GetWidthF(void) const;

	/**
	 * Gets the height of the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		The height
	 */
	int GetHeight(void) const;

	/**
	 * Gets the height of the %EnrichedText instance.
	 *
	 * @since		2.1
	 *
	 * @return		The height
	 */
	float GetHeightF(void) const;

	/**
	 * Sets the vertical alignment.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	alignment		The vertical alignment of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result SetVerticalAlignment(TextVerticalAlignment alignment);

	/**
	 * Sets the horizontal alignment.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	alignment			The horizontal alignment of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result SetHorizontalAlignment(TextHorizontalAlignment alignment);

	/**
	 * Gets the vertical alignment.
	 *
	 * @since		2.0
	 *
	 * @return		alignment			The vertical alignment of the text
	 */
	TextVerticalAlignment GetVerticalAlignment(void) const;

	/**
	 * Gets the horizontal alignment.
	 *
	 * @since		2.0
	 *
	 * @return		alignment		The horizontal alignment of the text
	 */
	TextHorizontalAlignment GetHorizontalAlignment(void) const;

	/**
	 * Sets the text wrap style.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	wrap				The text wrapping style
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result SetTextWrapStyle(TextWrap wrap);

	/**
	 * Gets the text wrap style.
	 *
	 * @since		2.0
	 *
	 * @return		wrap		The text wrapping style in the %EnrichedText bounds
	 */
	TextWrap GetTextWrapStyle(void) const;

	/**
	 * Sets the text abbreviation status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	enable				Set to @c true to enable text abbreviation, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetTextAbbreviationEnabled(bool enable);

	/**
	 * Checks whether the text abbreviation is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the text abbreviation is enabled, @n
	 *				else @c false
	 */
	bool IsTextAbbreviationEnabled(void) const;

	/**
	 * Sets the line spacing.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	lineSpace			The space between lines
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 *
	 */
	result SetLineSpace(int lineSpace);

	/**
	 * Sets the line spacing.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	lineSpace			The space between lines
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 *
	 */
	result SetLineSpace(float lineSpace);

	/**
	 * Gets the line spacing.
	 *
	 * @since		2.0
	 *
	 * @return		space		The space between lines
	 */
	int GetLineSpace(void) const;

	/**
	 * Gets the line spacing.
	 *
	 * @since		2.1
	 *
	 * @return		space		The space between lines
	 */
	float GetLineSpaceF(void) const;

	/**
	 * Refreshes the texts and bitmap according to the %EnrichedText instance's attributes. @n
	 * If some attributes are changed (such as changes using @ref SetSize), you can get the exact
	 * information of the text position or the number of lines after this method is called.
	 *
	 * @since		2.0
	 */
	void Refresh(void);

	/**
	 * Gets the total line count of the text in the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		The total line count
	 */
	int GetTotalLineCount(void) const;

	/**
	 * Gets the height of the text in the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		The line height
	 */
	int GetTotalLineHeight(void) const;

	/**
	 * Gets the height of the text in the %EnrichedText instance.
	 *
	 * @since		2.1
	 *
	 * @return		The line height
	 */
	float GetTotalLineHeightF(void) const;

	/**
	 * Gets the displayed line count of the text in the %EnrichedText instance.
	 *
	 * @since		2.0
	 *
	 * @return		The displayed line count
	 */
	int GetDisplayLineCount(void) const;

	/**
	 * Gets the length of the specified line.
	 *
	 * @since		2.0
	 *
	 * @return		The line length, @n
	 *				else @c -1 if the method fails
	 * @param[in]	lineIndex			The index of the specified line
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLineLength(int lineIndex) const;

	/**
	 * Gets the first character index of the specified line.
	 *
	 * @since		2.0
	 *
	 * @return		The first text offset, @n
	 *				else @c -1 if the method fails
	 * @param[in]	lineIndex			The line index of the %EnrichedText object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetFirstTextIndex(int lineIndex) const;

	/**
	 * Gets the line index of the specified character.
	 *
	 * @since		2.0
	 *
	 * @return		The line index, @n
	 *				else @c -1 if the method fails
	 * @param[in]	textIndex			The text index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLineIndex(int textIndex) const;

	/**
	 * Gets the line height of the specified line.
	 *
	 * @since		2.0
	 *
	 * @return		The line height, @n
	 *				else @c -1 if the method fails
	 * @param[in]	lineIndex			The line index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLineHeight(int lineIndex) const;

	/**
	 * Gets the line height of a specified line.
	 *
	 * @since		2.1
	 *
	 * @return		The line height, @n
	 *				else @c -1.0f if the method fails
	 * @param[in]	lineIndex			The line index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	float GetLineHeightF(int lineIndex) const;

	/**
	 * Gets the text length of the %EnrichedText object.
	 *
	 * @since		2.0
	 *
	 * @return		The text length
	 */
	int GetTextLength(void) const;

	/**
	 * Gets the extent of the %EnrichedText instance on the assumption that all TextElements are
	 * expanded to one line.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	startTextIndex		The starting text index of the %EnrichedText instance
	 * @param[in]	textLength			The length of the specified text @n
	 *									It must be greater than or equal to @c 0.
	 * @param[out]  width				The width of the specified text
	 * @param[out]  height				The height of the specified text
	 * @param[out]  actualLength		The actual text length measured
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result GetTextExtent(int startTextIndex, int textLength, int& width, int& height, int& actualLength) const;

	/**
	 * Gets the extent of the %EnrichedText instance on the assumption that all TextElements are
	 * expanded to one line.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	startTextIndex		The starting text index of the %EnrichedText instance
	 * @param[in]	textLength			The length of the specified text @n
	 *									It must be greater than or equal to @c 0.
	 * @param[out]  width				The width of the specified text
	 * @param[out]  height				The height of the specified text
	 * @param[out]  actualLength		The actual text length measured
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result GetTextExtent(int startTextIndex, int textLength, float& width, float& height, int& actualLength) const;

	/**
	 * Gets the extent of the %EnrichedText instance on the assumption that all TextElements are
	 * expanded to one line.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startTextIndex		The starting text index of the EnrichedText
	 * @param[in]	textLength			The length of the specified text @n
	 *									It must be greater than or equal to @c 0.
	 * @param[out]  size				The extent of the specified text
	 * @param[out]  actualLength		The actual text length measured
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result GetTextExtent(int startTextIndex, int textLength, Tizen::Graphics::Dimension& size, int& actualLength) const;

	/**
	 * Gets the extent of the %EnrichedText instance on the assumption that all TextElements are
	 * expanded to one line.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	startTextIndex		The starting text index of the %EnrichedText instance
	 * @param[in]	textLength			The length of the specified text @n
	 *									It must be greater than or equal to @c 0.
	 * @param[out]  size				The extent of the specified text
	 * @param[out]  actualLength		The actual text length measured
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result GetTextExtent(int startTextIndex, int textLength, Tizen::Graphics::FloatDimension& size, int& actualLength) const;

	/**
	 * Gets the extent of the %EnrichedText instance on the assumption that all TextElements are
	 * not expanded to one line. @n The %GetTextExtent() method is useful for finding the extent of %EnrichedText spanning multiple lines.
	 *
	 * @since 2.0
	 * @return		An instance of Dimension containing the extent of the %EnrichedText instance, @n
	 * 				else (-1, -1) if the method fails
	 */
	Tizen::Graphics::Dimension GetTextExtent(void) const;

	/**
	 * Gets the extent of the %EnrichedText instance on the assumption that all TextElements are
	 * not expanded to one line. @n The %GetTextExtentF() method is useful for finding the extent of %EnrichedText spanning multiple lines.
	 *
	 * @since 2.1
	 * @return		An instance of FloatDimension containing the extent of the %EnrichedText instance, @n
	 * 				else (-1.0f, -1.0f) if the method fails
	 */
	Tizen::Graphics::FloatDimension GetTextExtentF(void) const;

	/**
	 * Adds the specified bitmap image to the %EnrichedText instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bitmap					The bitmap to draw @n
	 *						The bitmap must be constructed before being passed to this method.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM                An unknown operating system error has occurred.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Add(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Inserts the specified bitmap image to the %EnrichedText instance at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	bitmap					The @c bitmap to draw @n
	 *						The bitmap must be constructed before being passed to this method.
	 * @param[in]	elementIndex		    The index at which the @c bitmap image is to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_SYSTEM                An unknown operating system error has occurred.
	 * @exception   E_OUT_OF_RANGE			The value of the argument is outside the valid range defined by the method.
	 * @exception   E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 */
	result InsertAt(int elementIndex, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Gets the information about the link at the specified position.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  point              A point that is within the %EnrichedText object
	 * @param[out] linkInfo           The LinkInfo object that represents the link at the specified position
	 * @exception  E_SUCCESS          The method is successful.
	 * @exception  E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception  E_OBJ_NOT_FOUND    The required instance is not found.
	 * @remarks    This method throws @c E_OBJ_NOT_FOUND if there is no linked text at the specified position.
	 * @see        Tizen::Base::Utility::LinkInfo
	 */
	result GetLinkInfoFromPosition(const Point& point, Tizen::Base::Utility::LinkInfo& linkInfo) const;

	/*
	 * Gets the information about the link at the specified position.
	 *
	 * @since      2.1
	 *
	 * @return     An error code
	 * @param[in]  point              A point that is within the %EnrichedText object
	 * @param[out] linkInfo           The LinkInfo object that represents the link at the specified position
	 * @exception  E_SUCCESS          The method is successful.
	 * @exception  E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception  E_OBJ_NOT_FOUND    The required instance is not found.
	 * @remarks    This method throws @c E_OBJ_NOT_FOUND if there is no linked text at the specified position.
	 * @see        Tizen::Base::Utility::LinkInfo
	 */
	result GetLinkInfoFromPosition(const FloatPoint& point, Tizen::Base::Utility::LinkInfo& linkInfo) const;

	/**
	 * Gets the information about the link at the specified position.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  x                  The x-coordinate of a point that is within the %EnrichedText object
	 * @param[in]  y                  The y-coordinate of a point that is within the %EnrichedText object
	 * @param[out] linkInfo           The LinkInfo object that represents the link at the specified position
	 * @exception  E_SUCCESS          The method is successful.
	 * @exception  E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception  E_OBJ_NOT_FOUND    The required instance is not found.
	 * @remarks    This method throws @c E_OBJ_NOT_FOUND if there is no linked text at the specified position.
	 * @see        Tizen::Base::Utility::LinkInfo
	 */
	result GetLinkInfoFromPosition(int x, int y, Tizen::Base::Utility::LinkInfo& linkInfo) const;

	/**
	 * Gets the information about the link at a specified position.
	 *
	 * @since      2.1
	 *
	 * @return     An error code
	 * @param[in]  x                  The x-coordinate of a point that is within the %EnrichedText object
	 * @param[in]  y                  The y-coordinate of a point that is within the %EnrichedText object
	 * @param[out] linkInfo           The LinkInfo object that represents the link at the specified position
	 * @exception  E_SUCCESS          The method is successful.
	 * @exception  E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception  E_OBJ_NOT_FOUND    The required instance is not found.
	 * @remarks    This method throws @c E_OBJ_NOT_FOUND if there is no linked text at the specified position.
	 * @see        Tizen::Base::Utility::LinkInfo
	 */
	result GetLinkInfoFromPosition(float x, float y, Tizen::Base::Utility::LinkInfo& linkInfo) const;

	/**
	 * Gets the vertical alignment among text and bitmap element.
	 *
	 * @since		2.0
	 *
	 * @return		The vertical alignment among the text and the bitmap element
	 */
	TextVerticalAlignment GetElementVerticalAlignment(void) const;

	/**
	 * Sets the vertical alignment among text and bitmap element.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	alignment		The vertical alignment among the text and the bitmap element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		This method sets how one element is positioned relative to the other elements. @n
	 *				The vertical alignment of text and bitmap elements are decided based on the maximum height among elements.
	 * @remarks		The default alignment @c TEXT_ALIGNMENT_BOTTOM.
	 */
	result SetElementVerticalAlignment(TextVerticalAlignment alignment);

private:
	friend class _EnrichedTextImpl;

	//
	// This value is for internal use only. Using this value can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	/**
	 * @since 2.0
	 */
	class _EnrichedTextImpl * __pImpl;

	EnrichedText(const EnrichedText& font);
	EnrichedText& operator =(const EnrichedText& rhs);

}; // EnrichedText

} } // Tizen::Graphics

#endif  //  _FGRP_ENRICHED_TEXT_H_
