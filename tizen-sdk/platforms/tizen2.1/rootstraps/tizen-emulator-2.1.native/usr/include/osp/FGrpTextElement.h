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
 * @file    FGrpTextElement.h
 * @brief   This is the header file for the %TextElement class.
 *
 * This header file contains the declarations of the %TextElement class.
 */

#ifndef _FGRP_TEXT_ELEMENT_H_
#define _FGRP_TEXT_ELEMENT_H_

#include <FBase.h>
#include <FBaseUtilTypes.h>
#include <FGrpFont.h>
#include <FGrpCanvas.h>
#include <FGrpColor.h>

namespace Tizen { namespace Graphics
{
/**
* @class   TextElement
* @brief   This class provides methods for the text elements.
*
* @since   2.0
*
* @final	This class is not intended for extension.
*
* The %TextElement class encapsulates the characteristics of a text, such as the constant string and font style.
* A text element draws the text on to a canvas.
*
* For more information on the attributes of %TextElement, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/enriched_text.htm">EnrichedText</a>.
*
*/
class _OSP_EXPORT_ TextElement
	: public Tizen::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		2.0
	*
	* @remarks     After creating an instance of this class, one of the
	*              Construct() methods must be called explicitly to initialize this instance.
	*/
	TextElement(void);

	/**
	* This is the destructor for this class.
	*
	* @since		2.0
	*/
	virtual ~TextElement(void);

	/**
	* Initializes the current instance of %TextElement with the specified text. @n
	* If the text is not specified, the default system font is set.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   text                The text string
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception   E_INVALID_ARG       The specified input parameter is invalid.
	*/
	result Construct(const Tizen::Base::String& text);

	/**
	* Initializes the current instance of %TextElement with the specified text. @n
	* The canvas is used for initializing the font's color attributes, such as the foreground color and the background color.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   text                The text string
	* @param[in]   canvas              The canvas to initialize the text element @n
	*                                  It sets the foreground and background colors of the text element.
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception   E_INVALID_ARG       A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Base::String& text, const Tizen::Graphics::Canvas& canvas);

	/**
	* Initializes the current instance of %TextElement.
	*
	* @since       2.0
	*
	* @return      An error code
	* @exception   E_SUCCESS            The method is successful.
	* @exception   E_OUT_OF_MEMORY      The memory is insufficient.
	* @exception    E_SYSTEM             An unknown operating system error has occurred.
	* @remarks     To set the text, use the SetText() method.
	*/
	result Construct(void);

	/**
	* Initializes the current instance of %TextElement to represent a linked text with the specified link information. @n
	* If the link information is not specified, the default system font is set.
	*
	* @since     2.0
	*
	* @return    An error code
	* @param[in] text             The linked text string
	* @param[in] linkType         The link type
	* @param[in] link             The string that contains the actual link
	* @exception E_SUCCESS        The method is successful.
	* @exception E_OUT_OF_MEMORY  The memory is insufficient.
	* @exception E_INVALID_ARG    Either the specified @c text is an empty string or @c linkType is @c LINK_TYPE_NONE
	* @exception E_SYSTEM         An unknown operating system error has occurred.
	* @see       Tizen::Base::Utility::LinkInfo
	*/
	result Construct(const Tizen::Base::String& text, Tizen::Base::Utility::LinkType linkType, const Tizen::Base::String& link);

	/**
	* Initializes the current instance of %TextElement with the specified text and autolink mask. @n
	* If the text and autolink mask are not specified, the default system font is set.
	*
	* @since     2.0
	*
	* @return    An error code
	* @param[in] text             The text string
	* @param[in] autoLink         The autolink mask @n
	*                             Multiple link types can be combined using the bitwise OR operator. @n
	*                             For more information, see <a href="../org.tizen.native.appprogramming/html/guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
	* @exception E_SUCCESS        The method is successful.
	* @exception E_INVALID_ARG    A specified input parameter is invalid.
	* @exception E_OUT_OF_MEMORY  The memory is insufficient.
	* @exception E_SYSTEM         An unknown operating system error has occurred.
	* @remarks   If @c text contains more than one detectable link, the first link is converted
	*            to a linked text and the rest of the links are ignored.
	* @see       Tizen::Base::Utility::LinkType
	*/
	result Construct(const Tizen::Base::String& text, unsigned long autoLink);

	/**
	* Initializes the current instance of %TextElement to represent a linked text with the specified link information. @n
	* If the link information is not specified, the default system font is set.
	*
	* @since     2.0.
	*
	* @return    An error code
	* @param[in] text             The linked text string
	* @param[in] linkType         The link type
	* @param[in] link             The string that contains the actual link
	* @param[in] canvas           The canvas to initialize the text element @n
	*                             It sets the foreground and background colors of the text element.
	* @exception E_SUCCESS        The method is successful.
	* @exception E_OUT_OF_MEMORY  The memory is insufficient.
	* @exception E_INVALID_ARG    Either the specified @c text is an empty string or @c linkType is @c LINK_TYPE_NONE.
	* @exception E_SYSTEM         An unknown operating system error has occurred.
	*/
	result Construct(const Tizen::Base::String& text, Tizen::Base::Utility::LinkType linkType, const Tizen::Base::String& link, const Tizen::Graphics::Canvas& canvas);

	/**
	* Initializes the current instance of %TextElement with the specified text, autolink mask, and graphics canvas. @n
	* If the parameters are not specified, the default system font is set.
	*
	* @since     2.0
	*
	* @return    An error code
	* @param[in] text             The text string @n
	*					If the text contains more than one detectable link, the first link is converted to a linked text and rest of the links are ignored.
	* @param[in] autoLink         The autolink mask @n
	*                             Multiple link types can be combined using the bitwise OR operator. @n
	*                             For more information, see <a href="../org.tizen.native.appprogramming/html/guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
	* @param[in] canvas           The canvas to initialize the text element @n
	*                             It sets the foreground and background colors of the text element.
	* @exception E_SUCCESS        The method is successful.
	* @exception E_INVALID_ARG    A specified input parameter is invalid.
	* @exception E_OUT_OF_MEMORY  The memory is insufficient.
	* @exception E_SYSTEM         An unknown operating system error has occurred.
	* @see       Tizen::Base::Utility::LinkType
	*/
	result Construct(const Tizen::Base::String& text, unsigned long autoLink, const Tizen::Graphics::Canvas& canvas);

	/**
	* Gets the string that contains the actual link.
	*
	* @since		2.0
	*
	* @return		The string that contains the actual link @n
	*			If the text element contains no linked text, the method returns an empty string.
	*/
	Tizen::Base::String GetLink(void) const;

	/**
	* Gets the type of the link of the text element. @n
	* The link type is the first auto-detected link.
	*
	* @since		2.0
	*
	* @return		The string that contains the actual link @n
	* 			If the text element contains no linked text, the method returns @c LINK_TYPE_NONE.
	*/
	Tizen::Base::Utility::LinkType GetLinkType(void) const;

	/**
	* Sets the text of %TextElement with the specified string.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   text            The string to set
	* @exception   E_SUCCESS       The method is successful.
	*/
	result SetText(const Tizen::Base::String& text);

	/**
	* Sets the font of %TextElement.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   font                The font to set
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_INVALID_ARG       The specified input parameter is invalid.
	*/
	result SetFont(const Tizen::Graphics::Font& font);

	/**
	* Sets the text color of %TextElement.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   color               The color to set
	* @exception   E_SUCCESS           The method is successful.
	*/
	result SetTextColor(const Tizen::Graphics::Color& color);

	/**
	* Sets the background color of %TextElement.
	*
	* @since       2.0
	*
	* @return      An error code
	* @param[in]   color               The color to set
	* @exception   E_SUCCESS           The method is successful.
	 */
	result SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	* Sets the outline color of %TextElement.
	*
	* @since       2.0
	*
	* @return              An error code
	* @param[in]   color   The color to set
	* @exception   E_SUCCESS           The method is successful.
	*/
	result SetOutlineColor(const Tizen::Graphics::Color& color);

	/**
	* Gets the text of %TextElement.
	*
	* @since       2.0
	*
	* @return      A string containing the text
	*/
	Tizen::Base::String GetText(void) const;

	/**
	* Gets the text color of %TextElement.
	*
	* @since       2.0
	*
	* @return The foreground color
	*/
	Tizen::Graphics::Color GetTextColor(void) const;

	/**
	* Gets the background color of %TextElement.
	*
	* @since       2.0
	*
	* @return The background color
	*/
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	* Gets the outline color of %TextElement.
	*
	* @since       2.0
	*
	* @return The outline color
	*/
	Tizen::Graphics::Color GetOutlineColor(void) const;

private:
	friend class _TextElementImpl;

	//
	// This value is for internal use only. Using this value can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	/**
	 * @since 2.0
	 */
	class _TextElementImpl * __pImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TextElement(const TextElement& font);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TextElement& operator =(const TextElement& rhs);

}; // TextElement

} } // Tizen::Graphics

#endif  // _FGRP_TEXT_ELEMENT_H_
