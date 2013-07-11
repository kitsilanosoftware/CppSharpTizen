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
 * @file	FGrpFont.h
 * @brief	This is the header file for the %Font class.
 *
 * This header file contains the declarations of the %Font class.
 */

#ifndef _FGRP_FONT_H_
#define _FGRP_FONT_H_

#include <FBase.h>
#include <FBaseObject.h>
#include <FGrpDimension.h>
#include <FGrpFontCommon.h>

namespace Tizen { namespace Graphics
{
/**
 * @class	Font
 * @brief	This class provides methods to retrieve the font information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Font class encapsulates the characteristics, such as the size and style of a specific vector font.
 * Fonts are used to draw text on a Canvas.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/fonts.htm">Fonts</a>.
 *
 *
 */
class _OSP_EXPORT_ Font
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, one of the
	 *					Construct() methods must be called explicitly to initialize this instance.
	 */
	Font(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Font(void);

	/**
	 * Initializes this instance of %Font with the specified size and style. @n
	 * If the size and style are not specified, the default system font is set.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	style			The font style @n
	 *                                  For more information, see Tizen::Graphics::FontStyle.
	 * @param[in]	size				The font size in pixels @n
	 *										The size must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(int style, int size);

	/**
	 * Initializes this instance of %Font with the specified parameters.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since		2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompIoPathPage "IoPath" and @ref CompFontConstructPage "FontConstructor" issues.
	 * @endif
	 * @return		An error code
	 * @param[in]	fontNameOrPath		The local file path of a font-resource file or app font name or system font name @n
	 *									The app font name is retrieved using GetFaceName(Osp::Base::String& filepath).
	 *									The system font name is retrieved using GetSystemFontListN().
	 * @param[in]	style			The font style @n
	 *								Multiple styles can be combined using the bitwise OR operator.
	 * @param[in]	size			The font size in pixels @n
	 *								The size must be greater than @c 0.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND		The specified font cannot be found or accessed.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified font format is not supported.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @remarks Only TrueType font is supported.
	 *          The value of fontNameOrPath is considered system font name if it matches one of the retrieved values using GetSystemFontListN().
	 *          If not, it is considered local file path of a font-resource file.
	 */
	result Construct(const Tizen::Base::String& fontNameOrPath, int style, int size);

	/**
	 * @if OSPCOMPAT
	 * @page					CompFontConstructPage Compatibility for Construct().
	 * @section					CompFontConstructPageIssueSection Issues
	 * 							Implementing this method in OSP compatible applications has the following issues:   @n
	 *							-# In OSP, the value of 1 st parameter(fontNameOrPath) can be system font name or local font path. At first, it is compared to the retrieved values using GetSystemFontListN(). If the matched value is exist, it is considered system font name. Or, it is considered local file path of a font-resource file.
	 *							-# In Tizen, the value of 1 st parameter(fontNameOrPath) can be app font name or system font name or local font path. At first, it is compared to the font face names in app font resource folder. If the matched value is exist, it is considered app font name. Or, it is considered  system font name if it matches one of the retrieved values using GetSystemFontListN().
	 * @endif
	 */

	/**
	 * Initializes this instance of %Font with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	fontData		The font data
	 * @param[in]	style		The font style @n
	 *								Multiple styles can be combined using the bitwise OR operator.
	 * @param[in]	size			The font size in pixels @n
	 *						The size must be greater than @c 0.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified font format is not supported.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 */
	result Construct(const Tizen::Base::ByteBuffer& fontData, int style, int size);

	/**
	 * Gets the maximum height of the current instance of %Font.
	 *
	 * @since	2.0
	 *
	 * @return	The maximum height of the current instance of %Font, @n
	 *			else @c -1 if the method fails
	 */
	int GetMaxHeight(void) const;

	/**
	 * Gets the maximum width of the current instance of %Font.
	 *
	 * @since	2.0
	 *
	 * @return	The maximum width of the current instance of %Font, @n
	 *			else @c -1 if the method fails
	 */
	int GetMaxWidth(void) const;

	/**
	 * Gets the ascender of the current instance of %Font.
	 *
	 * @since	2.0
	 *
	 * @return     The ascender of the current instance of %Font, @n
	 *			else @c -1 if the method fails
	 */
	int GetAscender(void) const;

	/**
	 * Gets the descender of the current instance of %Font.
	 *
	 * @since	2.0
	 *
	 * @return     The descender of the current instance of %Font, @n
	 *			else @c -1 if the method fails
	 */
	int GetDescender(void) const;

	/**
	 * Gets the left bear of a character.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	character		A character for getting left bear
	 * @param[out]	leftBear         The left bear of the specified @c character
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_DATA_NOT_FOUND   The requested data does not exist.
	 */
	result GetLeftBear(wchar_t character, int& leftBear) const;

	/**
	 * Gets the right bear of a character.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	character		A character for getting the right bear
	 * @param[out]	rightBear		The right bear of the specified @c character
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_DATA_NOT_FOUND   The requested data does not exist.
	 */
	result GetRightBear(wchar_t character, int& rightBear) const;

	/**
	 * Gets the width and height of the font used in the specified text. @n
	 * This method retrieves the font dimension of the text.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since		2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see the issue description for @ref CompFontGetTextExtentPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	text			The string
	 * @param[in]	length		The length of @c text @n
	 *								The length must be greater than or equal to @c 0.
	 * @param[out]	dim				The width and height of the font of the @c text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of @c length is greater than the actual length of @c text.
	 */
	result GetTextExtent(const Tizen::Base::String& text, int length, Dimension& dim) const;

	/**
	 * @if OSPCOMPAT
	 * @page		CompFontGetTextExtentPage Compatibility for the file path.
	 * @section		CompFontGetTextExtentPageIssueSection Issues
	 * 				Implementing this method in OSP compatible applications has the following issues:   @n
	 *				-# The method returns exact height only if the font resource is designed to fit inside the emBox. @n
	 *
	 * @section		CompFontGetTextExtentPageSolutionSection Resolutions
	 *				This issue has been resolved in Tizen. @n
	 *				-# The method returns exact height regardless of font design. @n
	 *
	 * @endif
	 */

	/**
	 * Checks whether the font style of the current instance is bold.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the font style of the current instance is bold, @n
	 *				else @c false
	 */
	bool IsBold(void) const;

	/**
	 * Checks whether the font style for the current instance is italics.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the font style for the current instance is italics, @n
	 *				else @c false
	 */
	bool IsItalic(void) const;

	/**
	 * Checks whether the current instance has any style defined.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if an extra style is not defined for the current instance, @n
	 *					else @c false
	 */
	bool IsPlain(void) const;

	/**
	 * Checks whether the current instance has the strikeout style set.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the current instance has the strikeout style set, @n
	 *				else @c false
	 */
	bool IsStrikeOut(void) const;

	/**
	 * Checks whether the current instance has the underline style set.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the current instance has the underline style set, @n
	 *				else @c false
	 */
	bool IsUnderlined(void) const;

	/**
	 * Gets the font size of the current instance of %Font.
	 *
	 * @since		2.0
	 *
	 * @return		The font size, @n
	 *				else @c -1 if the method fails
	 */
	int GetSize(void) const;

	/**
	 * Sets the strikeout style for the current instance of %Font.
	 *
	 * @since		2.0
	 *
	 * @param[in]	strikeOut		Set to @c true to use the strikeout style for the current instance of %Font, @n
	 *								else @c false
	 */
	void SetStrikeOut(bool strikeOut);

	/**
	 * Sets the underline style for the current instance of %Font.
	 *
	 * @since		2.0
	 *
	 * @param[in]	underline		Set to @c true to use the underline style for the current instance of %Font, @n
	 *								else @c false
	 */
	void SetUnderline(bool underline);

	/**
	 * Gets the system font list.
	 *
	 * @since		2.0
	 *
	 * @return		The list of system fonts @n
	 *				The font list consists of Tizen::Base::String items.
	 * @remarks After using the system font list, you can call IList::RemoveAll(true) to clean up string items in the list.
	 */
	static Tizen::Base::Collection::IList* GetSystemFontListN(void);

	/**
	 * Gets the face name of the font file of the specific path.
	 *
	 * @since 2.0
	 *
	 * @return	The face name of the font file of the specific path
	 * @param[in]	filePath		The path of the font file
	 */
	static Tizen::Base::String GetFaceName(const Tizen::Base::String& filePath);

	/**
	 * Sets the character space.
	 *
	 * @since	2.0
	 *
	 * @param[in]          space    A character space
	 */
	void SetCharSpace(int space);

	/**
	 * Gets the character space.
	 *
	 * @since	2.0
	 *
	 * @return	The character space of this font instance, @n
	 *			else @c -1 if the method fails
	 */
	int GetCharSpace(void) const;

	/**
	 * Gets the face name.
	 *
	 * @since	2.0
	 *
	 * @return	The face name of this font instance
	 */
	Tizen::Base::String GetFaceName(void) const;

private:
	friend class _FontImpl;

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	/**
	 * @since 2.0
	 */
	class _FontImpl* __pImpl;

	/*
	 * This is the copy constructor for the Font class.
	 *
	 * @remarks		Do not use this constructor.
	 */
	Font(const Font& rhs);
	Font& operator =(const Font& rhs);

}; // Font

}} // Tizen::Graphics

#endif //_FGRP_FONT_H_
