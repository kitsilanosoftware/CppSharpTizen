//
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
 * @file		FBaseString.h
 * @brief		This is the header file for the %String class.
 *
 * This header file contains the declarations of the %String class.
 */
#ifndef _FBASE_STRING_H_
#define _FBASE_STRING_H_

#include <FBaseObject.h>


namespace Tizen { namespace Base
{
/**
 *	@class	String
 *	@brief	This class represents a mutable sequence of Unicode characters.
 *
 *	@since 2.0
 *
 *	The %String class represents a mutable sequence of Unicode characters. Operations that change the Unicode text, such as append, insert, and remove, are contained in the %String class.
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/string.htm">String</a>.
 *
 * The following example demonstrates how to use the %String class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::StringSample(void)
 *	{
 *		String str;			    // capacity == 16, length == 0
 *
 *		str.Append((int)100);   // str == L"100"
 *
 *		str.Insert(L"abc", 0);  // str == L"abc100"
 *
 *		String str2(L"STRING TEST");
 *
 *		String subStr;
 *
 *		str2.SubString(7, 4, subStr);  // subStr == L"TEST"
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ String
	: public Object
{
public:
	/**
	 *	This is the default constructor for this class. @n
	 *	It creates an empty %String instance with the default capacity of @c 16 bytes.
	 *
	 *	@since 2.0
	 */
	String(void);

	/**
 	 *	Initializes this instance of %String with the specified capacity.
	 *
	 * @since 2.0
	 *
	 * @param[in]	capacity The default capacity of this instance
	 */
	String(int capacity);

	/**
	 * Initializes this instance of %String with the specified Unicode character.
	 *
	 * @since 2.0
	 *
	 * @param[in]	ch			A Unicode character
	 */
	String(wchar_t ch);

	/**
	 * Initializes this instance of %String with the specified Unicode string.
	 *
	 * @since 2.0
	 *
	 * @param[in]	pValue		A pointer to an array of Unicode characters
	 */
	String(const wchar_t* pValue);

	/**
	 * Initializes this instance of %String with the specified character string.
	 *
	 * @since 2.0
	 *
	 * @param[in]	pValue		A pointer to an array of UTF-8 characters
	 */
	String(const char* pValue);

	/**
	 *	Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	An instance of %String
	 */
	String(const String& value);

	/**
	 * TThis destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 *
	 *	@remarks		The internally allocated memory block is freed when the instance is destroyed.
	 */
	virtual ~String(void);

	/**
	 * Returns the Unicode character at the specified @c index.
	 *
	 * @since 2.0
	 *
	 * @return        A const reference to the Unicode character
	 * @param[in]    index An index within the current instance of %String
	 */
	const wchar_t& operator [](int index) const;

	/**
	 * Returns a reference to the Unicode character at the specified @c index.
	 *
	 * @since 2.0
	 *
	 * @return        A reference to the Unicode character
	 * @param[in]    index An index within the current instance of %String
	 */
	wchar_t& operator [](int index);

	/**
	 * 	Copies the text from the specified
	 * 	Unicode string to the calling instance of %String.
	 *
	 *	@since 2.0
	 *
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	pRhs A pointer to an array of Unicode characters
	 */
	String& operator =(const wchar_t* pRhs);

	/**
	 * 	Copying of objects using this copy assignment operator is allowed.
	 *
	 *	@since 2.0
	 *
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	rhs An instance of %String
	 */
	String& operator =(const String& rhs);

	/**
 	 * 	Appends the text from the specified array of Unicode characters
	 * 	to the calling instance of %String.
	 *
	 *	@since 2.0
	 *
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	pRhs	A pointer to an array of Unicode characters
	 */
	String& operator +=(const wchar_t* pRhs);

	/**
	 * 	Appends the text from the specified instance of %String
	 * 	to the calling instance of %String.
	 *
	 *	@since 2.0
	 *
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	rhs An instance of %String to copy
	 */
	String& operator +=(const String& rhs);

	/**
	 * Concatenates the two strings.
	 *
	 * @since 2.0
	 *
	 * @return			The concatenated %String instance
	 * @param[in]	lhs A reference to the %String instance on the left-hand side of the operator
	 * @param[in]	rhs A reference to the %String instance on the right-hand side of the operator
	 */
	_OSP_EXPORT_ friend String operator +(const String& lhs, const String& rhs);

	/**
	 * 	Checks the two strings for equality.
	 *
	 *	@since 2.0
	 *
	 * 	@return			@c true if the text of the specified %String instance equals the calling instance's text, @n
	 *				else @c false
	 * 	@param[in]	rhs A reference to the %String instance on the right-hand side of the operator
	 * 	@remarks		The operator performs an ordinal comparison of each Unicode character.
	 */
	bool operator ==(const String& rhs) const;

	/**
	 * 	Checks the two strings for inequality.
	 *
	 *	@since 2.0
	 *
	 * 	@return			@c true if the text of the specified %String instance is not equal to the calling instance's text, @n
	 *				else @c false
	 * 	@param[in]	rhs A reference to the %String instance on the right-hand side of the operator
	 * 	@remarks		The operator performs an ordinal comparison of each Unicode character.
	 */
	bool operator !=(const String& rhs) const;

	/**
	 *	Checks whether the string is empty.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the current instance is a zero-length %String instance L"", @n
	 *				else @c false
	 */
	bool IsEmpty(void) const;

	/**
	 * Appends the specified @c wchar_t value to this %String instance after converting it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ch A @c wchar_t value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(wchar_t ch);

	/**
	 * Appends the specified @c char value to this %String instance after converting it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ch A @c char value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(char ch);

	/**
	 * Appends the string representing the specified 32-bit @c int value to this
	 * instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	i A 32-bit integer value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(int i);

	/**
	 * Appends the string representing the specified @c short value to this
	 * instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	s A @c short value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(short s);

	/**
	 * Appends the string representing the specified @c long value to this
	 * instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	l A @c long value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(long l);

	/**
	 * Appends the string representing the specified @c long @c long value to this
	 * instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ll A @c long @c long value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(long long ll);

	/**
	 * Appends the string representing the specified @c float value to this
	 * instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	f A @c float value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(float f);

	/**
	 * Appends the string representing the specified @c double value to this
	 * instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	d A @c double value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(double d);

	/**
	 * Appends the specified null-terminated Unicode text to this instance
	 * of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	p A pointer to a Unicode character array
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A @c null pointer is passed.
	 */
	result Append(const wchar_t* p);

	/**
	 * Appends the specified instance of %String to this instance
	 * of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str An instance of %String to append
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Append(const String& str);

	/**
	 * Clears the current instance and sets it to an empty %String instance. @n
	 * The capacity is set to @c 16 bytes, which is the default capacity.
	 *
	 * @since 2.0
	 */
	void Clear(void);

	/**
	 * Compares the values of the two strings.
	 *
	 *  @since 2.0
	 *
	 *	@return			A 32-bit @c signed integer value
	 *	@param[in]	str0	The first %String instance to compare
	 *	@param[in]	str1	The second %String instance to compare
	 *	@remarks		This method performs an ordinal comparison of each Unicode
	 *				character contained in the two given %String instances.
	 *				For instance, "U+xxx" is greater than "U+XXX", but smaller than "U+yyy".
	 *
	 *	@code
	 *	<  0  if the value of the first instance is less than the value of the second instance
	 *	== 0  if the value of the first instance is equal to the value of the second instance
	 *	>  0  if the value of the first instance is greater than the value of the second instance
	 *	@endcode
	 */
	static int Compare(const String& str0, const String& str1);

	/**
	 * Compares the value of the current instance to the value of the specified instance
	 * of %String.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 *@code
	 *				<  0  if the value of the current instance is less than the value of the specified %String instance
	 *				== 0  if the value of the current instance is equal to the value of the specified %String instance
	 *				>  0  if the value of the current instance is greater than the value of the specified %String instance
	 *@endcode
	 * @param[in]	str		An instance of %String to compare
	 * @remarks		This method performs an ordinal comparison of each Unicode character. For instance,
	 *				L"U+xxx" is greater than L"U+XXX", but smaller than L"U+yyy".
	 */
	int CompareTo(const String& str) const;

	/**
	 * Ensures that the specified length is less than or equal to the capacity of
	 * the current instance of %String. @n
	 * Otherwise, it expands the capacity of the internal buffer to a value that is greater than or equal to the specified length.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	minLength		A minimum length to ensure
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c minLength is negative.
	 */
	result EnsureCapacity(int minLength);

	/**
	 * Checks whether the value of the specified instance of Object is equal to the value of the current instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the specified instance of Object is equal to the value of the current instance of %String, @n
	 *				else @c false
	 * @param[in]	obj		An instance of Object to compare
	 * @remarks		This method returns @c false if the specified @c obj is not a string.
	 * @see				Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of %String. @n
	 * Case sensitivity can be controlled.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the values match, @n
	 *				else @c false
	 * @param[in]	str				An instance of %String to compare with the
	 *								calling instance
	 * @param[in]	caseSensitive	Set to @c true to perform a case sensitive ordinal comparison of the strings, @n
	 *								else @c false
	 *
	 * @remarks		This method performs an ordinal comparison of each Unicode
	 *			character contained in the two given %String instances.
	 */
	bool Equals(const String& str, bool caseSensitive) const;

	/**
	 * Formats the inputs as per the specified format and sets the value of the calling instance to the resultant string.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	length			The maximum number of wide characters to write, including the terminating @c null character
	 * @param[in]	pFormat			The wide character format specifier
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c length is negative or @c pFormat is @c null.
	 * @remarks		If an "l" modifier is present in @c pFormat (for example, L"@%ls"), it is a pointer to an array of wide characters. @n
	 * @remarks		A pointer to an array of UTF-8 characters is not allowed in the Format() method (for example, Format(20, L"@%s", pUTF8Str)).
	 * The following format specifiers are supported in this method:
	 * @code
	 * specifier    Output
	 * ---------    ------
	 * c            single byte character
	 * d(or i)      signed decimal integer
	 * u            unsigned decimal integer
	 * x            unsigned hexadecimal integer
	 * f            decimal floating point
	 * e            scientific notation using e character
	 * g            use the shorter of %e or %f
	 * s            single byte character string
	 * ls(or S)     wide-character string
	 * lld          64-bit signed decimal integer
	 *
	 * @endcode
	 *
	 * The following example demonstrates how to use the %Format() method.
	 * @code
	 *
	 *	String str;
	 *
	 *	int value = 10;
	 *	wchar_t* testStr = L"TEST";
	 *
	 *	str.Format(25, L"FORMAT %d %ls", value, testStr);	// str == L"FORMAT 10 TEST"
	 *
	 * @endcode
	 */
	result Format(int length, const wchar_t* pFormat, ...);

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 *	@return		The hash value of the current instance
	 * @remarks     Two equal instances must return the same hash value. For better performance,
	 *				the hash function used must generate a random distribution
	 *				for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 *  Gets the character at the specified position.
	 *
	 *  @since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	indexAt					The position of the character
	 *	@param[out]	ch						The character at the specified index
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result GetCharAt(int indexAt, wchar_t& ch) const;

	/**
	 * Searches for a character in the calling instance. @n
	 * Gets the index of the first character that matches to
	 * the specified character in this instance.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]	ch						The Unicode character to locate
	 * @param[in]	startIndex				The starting position of search
	 * @param[out]	indexOf					The index of the character
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OBJ_NOT_FOUND			The specified character is not found.
	 *	@exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result IndexOf(wchar_t ch, int startIndex, int& indexOf) const;

	/**
	 * Searches for a specified substring in the calling instance. @n
	 * Gets the starting index of the first occurrence of the specified substring.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str						An instance of %String to locate
	 * @param[in]	startIndex				The starting position of the search
	 * @param[out]	indexOf					The index of the substring
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified string is not found.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result IndexOf(const String& str, int startIndex, int& indexOf) const;

	/**
	 * Inserts the string representing the specified Unicode character
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 *
	 * @param[in]	ch						A Unicode character to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(wchar_t ch, int indexAt);

	/**
	 * Inserts the string representing the specified @c char value
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 *
	 * @param[in]	ch						A @c char value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(char ch, int indexAt);

	/**
	 * Inserts the string representing the specified 16-bit integer
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	s						A 16-bit integer value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(short s, int indexAt);

	/**
	 * Inserts the string representing the specified 32-bit integer
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	i						A 32-bit integer value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(int i, int indexAt);

	/**
	 * Inserts the string representing the specified @c long value
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	l						A @c long value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(long l, int indexAt);

	/**
	 * Inserts the string representing the specified @c long @c long value
	 * at the specified position in the calling instance.
 	 *
 	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ll						A @c long @c long value to insert
     * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(long long ll, int indexAt);

	/**
	 * Inserts the string representing the specified @c float value
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	f						A @c float value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(float f, int indexAt);

	/**
	 * Inserts the string representing the specified @c double value
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	d						A @c double value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(double d, int indexAt);

	/**
	 * Inserts the string representing the specified @c null-terminated
	 * string at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	p						An instance of %String to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_INVALID_ARG			A @c null pointer is passed.
	 */
	result Insert(const wchar_t* p, int indexAt);

	/**
	 * Inserts the string representing the specified instance of %String
	 * at the specified position in the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str						An instance of %String to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Insert(const String& str, int indexAt);

	/**
	 * Searches the calling instance for the last occurrence of the specified character and returns its index. @n
	 * The search begins at the @c startIndex position and proceeds backward towards the beginning.
	 *
	 *  @since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	ch						The Unicode character to locate
	 *	@param[in]	startIndex				The starting position of search
	 *	@param[out]	indexOf					The index of character
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OBJ_NOT_FOUND			The specified character is not found.
	 *	@exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result LastIndexOf(wchar_t ch, int startIndex, int& indexOf) const;

	/**
	 * Searches the calling instance for the last occurrence of the specified substring and returns its index. @n
	 * The search begins at the @c startIndex position and proceeds backward towards the beginning.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str						An instance of %String to locate
	 * @param[in]	startIndex				The starting position of search
	 * @param[out]	indexOf					The index of the substring
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified character is not found.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 * @remarks	If the substring is empty, E_SUCCESS is returned and the value of @c indexOf is set to @c startIndex.
	 */
	result LastIndexOf(const String& str, int startIndex, int& indexOf) const;

	/**
	 * Removes the characters within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex				The position where the removal begins
	 * @param[in]	length					The number of characters to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is out of range. @n
	 *										- The specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0. @n
	 *										- The specified @c count is either greater than the length of substring starting from @c startIndex or less than @c 0.
	 */
	result Remove(int startIndex, int length);

	/**
	 * Replaces all occurrences of the specified characters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	original The character to replace
	 * @param[in]	replace The character to replace all occurrences of @c original
	 */
	void Replace(wchar_t original, wchar_t replace);

	/**
	 * Replaces all occurrences of the specified string.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	original				An instance of %String to replace
	 * @param[in]	replace					An instance of %String to replace all occurrences of @c original
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c original is an empty string.
	 */
	result Replace(const String& original, const String& replace);

	/**
	 * Replaces all occurrences of the specified string within the substring
	 * of this instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	original				An instance of %String to replace
	 * @param[in]	replace					An instance of %String to replace all occurrences of @c original
	 * @param[in]	startIndex				The starting position of the substring
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c original is an empty string.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result Replace(const String& original, const String& replace, int startIndex);

	/**
	 * Reverses the sequence of characters in the calling instance.
	 *
	 * @since 2.0
	 *
	 */
	void Reverse(void);

	/**
	 * Sets the capacity of this instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c capacity is negative.
	 * @remarks		If the new capacity is smaller than the current length, then
	 *				the text contained in this instance is truncated.
	 */
	result SetCapacity(int newCapacity);

	/**
	 * Sets the character at the specified index with the given character.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ch						A new character
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result SetCharAt(wchar_t ch, int indexAt);

	/**
	 * Sets the length of this instance of %String.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	newLength		The new length
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c newLength is negative.
	 * @remarks		If the new length is greater than the current length, the
	 *				string is padded with spaces. On the other hand,
	 *				if the new length is smaller than the current length, then
	 *				the text contained in this instance is truncated.
	 */
	result SetLength(int newLength);

	/**
	 * Gets a substring starting from the given index.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex				The starting index of the substring
	 * @param[out]	out						The substring
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result SubString(int startIndex, String& out) const;

	/**
	 * Gets a substring of the given length starting from the specified index.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex				The starting position of the substring
	 * @param[in]	length					The length of the substring
	 * @param[out]	out						The substring
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is out of range. @n
	 *										- The specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0. @n
	 *										- The specified @c length is either greater than the length of substring starting from @c startIndex or less than @c 0.
	 */
	result SubString(int startIndex, int length, String& out) const;

	/**
	 *	Checks whether this instance contains the specified text from the given index.
	 *
	 *  @since 2.0
	 *
	 *	@return			@c true if this instance starts with the specified text, @n
	 *				else @c false
	 *	@param[in]	str					The string to match
	 *	@param[in]	startIndex			The start position of the string
	 */
	bool StartsWith(const String& str, int startIndex) const;

	/**
	 *	Checks whether the given string is present at the end of the calling instance.
	 *
	 *  @since 2.0
	 *
	 *	@return			@c true if this instance ends with the specified text, @n
	 *				else @c false
	 *	@param[in]	str				An instance of %String to match
	 */
	bool EndsWith(const String& str) const;

	/**
	 *	@if OSPDEPREC
	 *	Gets the lowercase form of the string in the calling instance. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use the ToLowerCase(%String& out) method that supports Unicode characters other than the English alphabets.
	 *  @since 2.0
	 *
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 * 	@endif
	 */
	result ToLower(String& out) const;

	/**
	 *	Gets the lowercase form of the string in the calling instance. @n
     *	Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 */
	result ToLowerCase(String& out) const;

	/**
	 *	@if OSPDEPREC
	 *	Gets the uppercase form of the string in the calling instance. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use the ToUpperCase(%String& out) method that supports Unicode characters other than the English alphabets.
	 *  @since 2.0
	 *
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 * 	@endif
	 */
	result ToUpper(String& out) const;

	/**
	 *	Gets the uppercase form of the string in the calling instance. @n
     *	Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 */
	result ToUpperCase(String& out) const;

	/**
	 *	@if OSPDEPREC
	 *	Converts all the letters in this instance to lowercase. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use the ToLowerCase() method that supports Unicode characters other than the English alphabets.
	 *
	 *  @since 2.0
	 * 	@endif
	 */
	void ToLower(void);

	/**
	 *	Converts all the letters in this instance to lowercase. @n
	 *  Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since 2.0
	 */
	void ToLowerCase(void);

	/**
	 *	@if OSPDEPREC
	 *	Converts all the letters in this instance to uppercase. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 * 	@brief	<i> [Deprecated] </i>
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use the ToUpperCase() method that supports Unicode characters other than the English alphabets.
	 *
	 *  @since 2.0
	 * 	@endif
	 */
	void ToUpper(void);

	/**
	 *	Converts all the letters in this instance to uppercase. @n
     *	Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since 2.0
	 */
	void ToUpperCase(void);

	/**
	 *	Trims the leading and trailing whitespace characters.
	 *
	 *  @since 2.0
	 */
	void Trim(void);

	/**
	 * Gets the current capacity of this %String instance.
	 *
	 * @since 2.0
	 *
	 * @return		The capacity of this %String instance
	 */
	int GetCapacity(void) const;

	/**
	 * Gets the length of the text contained in this %String instance.
	 *
	 * @since 2.0
	 *
	 * @return		The length of this %String instance
	 */
	int GetLength(void) const;

	/**
	 * Gets a pointer to the instance's internal buffer.
	 *
	 * @since 2.0
	 *
	 * @return		A Unicode pointer to the calling instance's internal buffer
	 * @remarks		GetPointer() does not guarantee that every call to this function returns same address.
	 */
	const wchar_t* GetPointer(void) const;

	/**
	* Checks whether this instance contains the specified substring.
	*
	*  @since 2.0
	*
	*  @return                 @c true if this instance contains the specified substring, @n
	*                              else @c false
	*  @param[in]    str       The string to match
	*/
	bool Contains(const String& str) const;

	/**
	 * A constant holding the default capacity of %String.
	 *
	 * @since 2.0
	 */
	static const unsigned long DEFAULT_CAPACITY = 16;

private:
	//
	// Allocates an internal buffer with the specified capacity.
	// @return		An error code
	// @param[in]	capacity The initial capacity of this instance of %String
	//
	bool AllocateCapacity(int capacity);

	//
	// Expands the size of the internal buffer that is greater than or equal
	// to the specified capacity.
	// @return		@c true if the capacity is expanded, @n
	//              else @c false
	// @param[in]	capacity The new capacity of this instance of %String
	//
	bool ExpandCapacity(int minCapacity);

	//
	// Initializes __pValue and __pRefCount
	//
	// @since 2.0
	//
	result InitializeToDefault(int capacity);

	//
	// Copies __pValue and subtract and initialize __pRefCount
	//
	// @since 2.0
	//
	result CopyOnWrite(int capacity);

	//
	// Swaps member-wisely
	//
	// @since 2.0
	//
	void Swap(String& str);

	int __capacity;
	int __length;
	mutable int __hash;
	mutable int* __pRefCount;
	mutable wchar_t* __pValue;

	static const float GROWTH_FACTOR;

	class _StringImpl * __pStringImpl;
	friend class _StringImpl;
}; // String

}} // Tizen::Base
#endif // _FBASE_STRING_H_
