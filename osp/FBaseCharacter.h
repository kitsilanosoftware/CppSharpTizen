//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseCharacter.h
 * @brief		This is the header file for the %Character class.
 *
 * This header file contains the declarations of the %Character class.
 */
#ifndef _FBASE_CHARACTER_H_
#define _FBASE_CHARACTER_H_

#include <FBaseObject.h>
#include <FBaseString.h>


namespace Tizen { namespace Base
{
/**
 *	@enum	UnicodeCategory
 *
 *	Defines the constants used to distinguish the categories of Unicode characters.
 *
 *	@since 2.0
 */
enum UnicodeCategory
{
	UNICODE_SURROGATE = 1,          /**<	The surrogate Unicode category		*/
	UNICODE_MODIFIER,               /**<	The spacing modifier Unicode category		*/
	UNICODE_ARROW,                  /**<	@if OSPDEPREC @deprecated This enum value is deprecated because this category is not valid anymore. @endif*/
	UNICODE_SPACE,                  /**<	The space Unicode category			*/
	UNICODE_PUNCTUATION,            /**<	The punctuation Unicode category	*/
	UNICODE_CONTROL,                /**<	The control Unicode category		*/
	UNICODE_MATH,                   /**<	The math Unicode category			*/
	UNICODE_DIGIT,                  /**<	The digit Unicode category			*/
	UNICODE_HANGUL,                 /**<	@if OSPDEPREC @deprecated This enum value is deprecated because this category is not valid anymore. @endif*/
	UNICODE_HANJA,                  /**<	@if OSPDEPREC @deprecated This enum value is deprecated because this category is not valid anymore. @endif*/
	UNICODE_COMBINING,              /**<	@if OSPDEPREC @deprecated This enum value is deprecated because this category is not valid anymore. @endif*/
	UNICODE_LANGUAGE,               /**<	@if OSPDEPREC @deprecated This enum value is deprecated because this category is not valid anymore. @endif*/
	UNICODE_UPPERCASE,              /**<	The uppercase Unicode category*/
	UNICODE_LOWERCASE,              /**<	The lowercase Unicode category*/
	UNICODE_TITLECASE,              /**<	The titlecase Unicode category*/
	UNICODE_LETTER,                 /**<	The letter Unicode category*/
	UNICODE_MARK,                   /**<	The mark Unicode category*/
	UNICODE_CURRENCY,               /**<	The currency Unicode category*/
	UNICODE_SEPARATOR,              /**<	The separator Unicode category*/
	UNICODE_OTHER                   /**<	The other Unicode category		*/
};


/**
 *	@class	Character
 *	@brief	This class is the wrapper class for the @c wchar_t built-in type.
 *
 *	@since 2.0
 *
 *	The %Character class wraps a value of the @c wchar_t type. It also provides
 *	several methods for determining a Unicode character's category, and for
 *	converting the case of intrinsic characters. The class is useful when
 *	passing a Unicode character to a method expecting an instance of Object.
 *
 * The following example demonstrates how to use the %Character class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	// This method converts the first character of the given @c string to the upper case.
 *	void
 *	MyClass::CharacterSample(String& str)
 *	{
 *		wchar_t chr, upper;
 *
 *		str.GetCharAt(0, chr);
 *
 *    // Converts to upper case
 *		upper = Character::ToUpper(chr);
 *
 *		str.SetCharAt(upper, 0);
 *  }
 *	@endcode
 */
class _OSP_EXPORT_ Character
	: public Object
{
public:
	/**
	 *	Initializes this instance of %Character with the specified parameter.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	A multi-byte character used to initialize the %Character instance
	 */
	Character(wchar_t value);

	/**
	 *	Copying of objects using this copy constructor is allowed.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	An instance of %Character
	 */
	Character(const Character& value);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since 2.0
	 */
	virtual ~Character(void);

	/**
	 *	Copying of objects using this copy assignment operator is allowed.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	rhs	An instance of %Character
	 */
	Character& operator =(const Character& rhs);

	/**
	 *	Compares (ordinal comparison) the value of the calling instance
	 *	with the value of the input %Character instance.
	 *
	 *	@since 2.0
	 *
	 *	@return		A 32-bit @c signed integer value
	 *  @param[in]	value 	The character instance to compare with
	 *
	 *	@code
	 *	@li <  0  if the value of the current instance is less than the value of the input instance
	 *	@li == 0  if the value of the current instance is equal to the value of the input instance
	 *	@li >  0  if the value of the current instance is greater than the value of the input instance
	 *	@endcode
	 *	
	 */
	int CompareTo(const Character& value) const;

	/**
	 *	Checks whether the value of the Object parameter is equal
	 *	to the value of the calling object.
	 *
	 *	@since 2.0
	 *	@return		@c true if the input Object is equal to the calling %Object, @n
	 *				else @c false
	 *	@param[in]	obj		The object to compare with the calling object
	 *	@see			Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance.
	 *
	 *	@since 2.0
	 *
	 *	@return		The hash value of the current instance
	 *	@remarks 	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 *	Returns the value of the current instance as a
	 *	@c wchar_t.
	 *
	 *	@since 2.0
	 *
	 *	@return		The value of this instance as
	 *				a @c wchar_t
	 */
	wchar_t ToMchar(void) const;

	/**
	 *	@if OSPDEPREC
	 *	Converts the Unicode characters of the calling object to its equivalent lowercase. @n
	 *	The Unicode characters other than English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToLowerCase() method that supports Unicode characters other than English alphabets.
	 *
	 *	@since 2.0
	 * 	@endif
	 */
	void ToLower(void);


	/**
	 *	Converts the Unicode characters of the calling object to its equivalent lowercase. @n
	 *	The Unicode characters other than English alphabets are also supported.
	 *
	 *	@since 2.0
	 */
	void ToLowerCase(void);


	/**
	 *	@if OSPDEPREC
	 *	Converts the Unicode characters of the current object to its equivalent uppercase. @n
	 *	The Unicode characters other than English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToUpperCase() method that supports the Unicode characters other than English alphabets.
	 *
	 *	@since 2.0
	 * 	@endif
	 */
	void ToUpper(void);


	/**
	 *	Converts the Unicode characters of the current object to its equivalent uppercase. @n
	 *	The Unicode characters other than English alphabets are also supported.
	 *
 	 *	@since 2.0
	 */
	void ToUpperCase(void);


	/**
	 *	Returns a string representing the value of the calling %Character instance.
	 *
	 *	@since 2.0
	 *
	 *	@return		An instance of String class that
	 *				contains a Unicode representation of the calling instance
	 */
	String ToString(void) const;

	/**
	 *	Returns a string representation of the input
	 *	@c wchar_t value.
	 *
	 *	@since 2.0
	 *
	 *	@return		An instance of the String class
	 *				that contains the Unicode representation of the
	 *				input value
	 *	@param[in]	value 	The Unicode character to convert
	 */
	static String ToString(wchar_t value);

	/**
	 *	Categorizes a Unicode character into a group identified by
	 *	one of the UnicodeCategory values.
	 *
	 *	@since 2.0
	 *
	 *	@return		    A value of type UnicodeCategory that identifies the group that contains the specified @c ch
	 *	@param[in]	ch 	The Unicode character to categorize
	 *
	 */
	static UnicodeCategory GetUnicodeCategory(wchar_t ch);

	/**
	 *	@if OSPDEPREC
	 *	Converts the input Unicode character to its equivalent lowercase. @n
	 *	The Unicode characters other than English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToLowerCase(wchar_t ch) method that supports the Unicode characters other than English alphabets.
	 *
	 *	@since 2.0
	 *	@return		An lowercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 * 	@endif
	 */
	static wchar_t ToLower(wchar_t ch);

	/**
	 *	Converts the input Unicode character to its equivalent lowercase. @n
	 *	The Unicode characters other than English alphabets are also supported.
	 *
	 *	@since 2.0
	 *
	 *	@return		An lowercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 */
	static wchar_t ToLowerCase(wchar_t ch);

	/**
	 *	@if OSPDEPREC
	 *	Converts the input Unicode character to its equivalent uppercase. @n
	 *  The Unicode characters other than English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToUpperCase(wchar_t ch) method that supports Unicode characters other than English alphabets.
	 *
	 *	@since 2.0
	 *	@return		An uppercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 * 	@endif
	 */
	static wchar_t ToUpper(wchar_t ch);

	/**
	 *	Converts the input Unicode character to its equivalent uppercase. @n
	 *	The Unicode characters other than English alphabets are also supported.
	 *
	 *	@since 2.0
	 *
	 *	@return		An uppercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 */
	static wchar_t ToUpperCase(wchar_t ch);

	/**
	 *	Checks whether the input character is an alphanumeric character (letter or digit). @n
	 *	A character is considered to be an alphanumeric character if either Character::isLetter(wchar_t ch) or Character::isDigit(wchar_t ch) returns true for the character
	 * 	@if OSPCOMPAT
	 * 	@brief <i> [Compatibility] </i>
	 * 	@endif
	 *	@since 2.0
	 * 	@if OSPCOMPAT
	 *	@compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *			For more information, see @ref CompCharacterIsAlphaNumericPage "here".
	 * 	@endif
	 *	@return		@c true if the input character is alphanumeric, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */
	static bool IsAlphaNumeric(wchar_t ch);

	/**
	 * 	@if OSPCOMPAT
	 * 	@page			CompCharacterIsAlphaNumericPage Compatibility for IsAlphaNumeric()
	 * 	@section		CompCharacterIsAlphaNumericPageIssueSection Issues
	 *				Implementing this method in OSP compatible applications has the following issues: @n
	 *
	 *	-# The method returns true only if the character is alphabet character and cannot checks other Unicode character in Letter and digit category.
	 *
	 * 	@section		CompCharacterIsAlphaNumericPageSolutionSection Resolutions
	 *
	 * 	This issue has been resolved in Tizen. @n
	 * 	@endif
	 */


	/**
	 *	Checks whether the input character is a digit.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the input character is a digit, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */
	static bool IsDigit(wchar_t ch);

	/**
	 *	Checks whether the input character is a Unicode letter.
	 * 	@if OSPCOMPAT
	 * 	@brief <i> [Compatibility] </i>
	 * 	@endif
	 *	@since 2.0
	 * 	@if OSPCOMPAT
	 *	@compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *			For more information, see @ref CompCharacterIsLetterPage "here".
	 * 	@endif
	 *	@return		@c true if the input character is an alphabet, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */
	static bool IsLetter(wchar_t ch);

	/**
	 * 	@if OSPCOMPAT
	 *	@page			CompCharacterIsLetterPage Compatibility for IsLetter()
	 *	@section		CompCharacterIsLetterPageIssueSection Issues
	 *				Implementing this method in OSP compatible applications has the following issues: @n
	 *
	 *	-# The method returns true only if the character is alphabet character and cannot checks other Unicode character in Letter category.
	 *
	 *	@section		CompCharacterIsLetterPageSolutionSection Resolutions
	 *
	 *	This issue has been resolved in Tizen. @n
	 * 	@endif
	 */

	/**
	 *	@if OSPDEPREC
	 *	Checks whether the input character is an lowercase alphabet.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use IsLowerCase(wchar_t ch) method that supports Unicode characters.
	 *	@since 2.0
	 *
	 *	@return		@c true if the input character is an lowercase English alphabet, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 * 	@endif
	 */
	static bool IsLower(wchar_t ch);

	/**
	 *	Checks whether the input character is an lowercase alphabet. @n
	 *	Unicode characters other than English alphabets are also supported.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the input character is an lowercase alphabet, @n
	 *				else @c false
	 *	@param[in]	ch The Unicode character
	 */
	static bool IsLowerCase(wchar_t ch);

	/**
	 *	@if OSPDEPREC
	 *	Checks whether the input character is an uppercase alphabet.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use IsUpperCase(wchar_t ch) method that also supports Unicode characters other than English alphabets.
	 *	@since 2.0
	 *
	 *	@return		@c true if the input character is an uppercase alphabet, @n
	 *				else @c false
	 *	@param[in]	ch The Unicode character
	 * 	@endif
	 */
	static bool IsUpper(wchar_t ch);

	/**
	 *	Checks whether the input character is an uppercase alphabet. @n
	 *	Unicode characters other than English alphabets are also supported.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the input character is an uppercase alphabet, @n
	 *				else @c false
	 *	@param[in]	ch The Unicode character
	 */
	static bool IsUpperCase(wchar_t ch);

	/**
	 *	Returns the value of the input character in the supplied radix. @n
	 * The value of radix must be between RADIX_MIN and RADIX_MAX.
	 *
	 *	@since 2.0
	 *
	 *	@return		A integer value of the input character in the supplied radix
	 *	@param[in]	ch   The character to determine the value
	 *	@param[in]	radix   The radix
	 */
	static int ToDigit(wchar_t ch, int radix);

	/**
	 *	Returns the value which represents the input digit with specified radix. @n
	 * The value of radix must be between RADIX_MIN and RADIX_MAX.
	 *
	 *	@since 2.0
	 *
	 *	@return		A Unicode character of the input digit with specified radix; null character (U+0000) otherwise
	 *	@param[in]	digit   The digit to determine the value
	 *	@param[in]	radix   The radix
	 */
	static wchar_t ForDigit(int digit, int radix);

	/**
	 *	Gets the numeric value of the input unicode character. @n
     * This is used when some numeric values are fractions, negative, or too large for @c int value.
	 *
	 *	@since 2.0
	 *
	 *	@return		A @c double value @n NO_NUMERIC_VALUE for characters without any numeric values in the Unicode %Character.
	 *	@param[in]	ch	A Unicode character
	 */
	static double GetNumericValue(wchar_t ch);

	/**
	 *	Checks whether the input character is defined, which usually means that it is assigned a character in the Unicode.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the Unicode character is an assigned character, @n
	 *			    else @c false
	 *	@param[in]	ch	A Unicode character
	 */
	static bool IsDefined(wchar_t ch);

	/**
	 *	Checks whether the input character is a whitespace character. @n
	 *	A character is considered to be a whitespace character if and only if it satisfies one of the following criteria:
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the Unicode character is a whitespace character, @n
	 *			    else @c false
	 *	@param[in]	ch	A Unicode character
	 *
	 *	@code
	 *	It is a Unicode Separator character, but is not also a non-breaking space (U+00A0 NBSP or U+2007 Figure Space or U+202F Narrow NBSP).
	 *	It is U+0009 HORIZONTAL TABULATION.
	 *	It is U+000A LINE FEED.
	 *	It is U+000B VERTICAL TABULATION.
	 *	It is U+000C FORM FEED.
	 *	It is U+000D CARRIAGE RETURN.
	 *	It is U+001C FILE SEPARATOR.
	 *	It is U+001D GROUP SEPARATOR.
	 *	It is U+001E RECORD SEPARATOR.
	 *	It is U+001F UNIT SEPARATOR.
	 *	@endcode
	 */
	static bool IsWhitespace(wchar_t ch);


	/**
	 *	Checks whether the input character is a title character.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the Unicode character is a title character, @n
	 *			    else @c false
	 *	@param[in]	ch	A Unicode character
	 */
	static bool IsTitleCase(wchar_t ch);

	/**
	 *	Returns the title case equivalent for the input character if it exists.
	 *
	 *	@since 2.0
	 *
	 *	@return		A title case character equivalent for the input character. The character itself is returned if none is defined
	 *	@param[in]	ch	A Unicode character
	 */
	static wchar_t ToTitleCase(wchar_t ch);

	/**
	 *	Checks whether the input character is an ISO control code or not.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the Unicode character is an ISO control character, @n
	 *			    else @c false
	 *	@param[in]	ch	A Unicode character
	 */
	static bool IsISOControl(wchar_t ch);


	/**
	 * A constant holding the largest value of type @c wchar_t, 0xFFFF.
	 *
	 * @since 2.0
	 */
	static const wchar_t VALUE_MAX = 0x10FFFF;

	/**
	 * A constant holding the smallest value of type wchar_t, 0x0000.
	 *
	 * @since 2.0
	 */
	static const wchar_t VALUE_MIN = 0x0000;

	/**
	 * The minimum radix available for conversion to and from strings.@n
	 * As value as RADIX_BINARY.
	 *
	 * @since 2.0
	 */
	static const int RADIX_MIN = 2;

	/**
	 * The radix for binary number.
	 *
	 * @since 2.0
	 */
	static const int RADIX_BINARY = 2;

	/**
	 * The radix for decimal number.
	 *
	 * @since 2.0
	 */
	static const int RADIX_DECIMAL = 10;

	/**
	 * The radix for octal number.
	 *
	 * @since 2.0
	 */
	static const int RADIX_OCTAL = 8;

	/**
	 * The radix for hexadecimal number.
	 *
	 * @since 2.0
	 */
	static const int RADIX_HEXADECIMAL = 16;

	/**
	 * The maximum radix available for conversion to and from strings. Same value as RADIX_HEXADECIMAL.
	 *
	 * @since 2.0
	 */
	static const int RADIX_MAX = 36;

	/**
	 * Special value that is returned by GetNumericValue(wchar_t ch) when no numeric value is defined for the unicode character.
	 *
	 * @since 2.0
	 */
	static constexpr double NO_NUMERIC_VALUE = -123456789;

private:
	friend class Int8;
	friend class Short;
	friend class Long;
	friend class Integer;

	wchar_t __val;

	friend class _CharacterImpl;
	class _CharacterImpl * __pCharacterImpl;

}; // Character

}} // Tizen::Base

#endif // _FBASE_CHARACTER_H_
