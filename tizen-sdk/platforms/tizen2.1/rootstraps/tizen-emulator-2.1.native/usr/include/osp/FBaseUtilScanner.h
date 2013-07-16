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
 * @file	FBaseUtilScanner.h
 * @brief	This is the header file for the %Scanner class.
 *
 * This header file contains declarations and definitions of the %Scanner class.
 *
 */

#ifndef _FBASE_UTIL_SCANNER_H_
#define _FBASE_UTIL_SCANNER_H_

#include <FBaseString.h>
#include <FBaseUtilRegularExpression.h>

namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	Scanner
 * @brief	This class provides to parse primitive types and strings, and supports to use regular expressions and various encoding schemes.
 * @since 2.1
 *
 * The %Scanner class breaks the input, which can be either a %String instance or strings from a file, into tokens using a delimiter.
 * The delimiter is set to whitespace as a default value. The resulting tokens are converted into values of different types according
 * to the methods in %Scanner.
 *
 * The following example demonstrates how to use the %Scanner class.
 * @code
 *
 *	String str = L"1 12 34.5 58 false";
 *	Scanner scan;
 *	bool ret = false;
 *
 *	scan.Construct(str);
 *
 *	ret = scan.IsNextTokenConvertibleToSignedChar();	//ret true
 *	signed char val;
 *	scan.GetNextSignedChar(val);	//val 1
 *
 *	ret = scan.IsNextTokenConvertibleToShort(10);	//ret true
 *	short shortVal;
 *	scan.GetNextShort(shortVal);	//shortVal 12
 *
 *	ret = scan.IsNextTokenConvertibleToInt(10);	//ret false
 *	ret = scan.IsNextTokenConvertibleToFloat();	//ret true
 *	float floatVal;
 *	scan.GetNextFloat(floatVal);	//floatVal 34.5
 *
 *	ret = scan.IsNextTokenConvertibleToInt(16);	//ret true
 *	int intVal;
 *	scan.GetNextInt(intVal, 16);	//intVal 88
 *
 *	ret = scan.IsNextTokenConvertibleToBool();	//ret true
 *	scan.GetNextBool(ret);	//ret false
 *
 * @endcode
 */
class _OSP_EXPORT_ Scanner
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since 2.1
	*/
	Scanner(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.1
	*/
	virtual ~Scanner(void);

	/**
	* Initializes the current instance of %Scanner with the specified instance of String.
	*
	* @since 2.1
	* @return       An error code
	* @param[in]    inputStr       The string to scan
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_INVALID_ARG  The length of the specified @c string parameter is @c 0.
	*/
	result Construct(const String& inputStr);

	/**
	* Initializes the current instance of %Scanner with a file that includes the strings that are being scanned.
	*
	* @since 2.1
	* @return       An error code
	* @param[in]    inputFilePath  The file to read to construct input data
	* @param[in]    encodingScheme The encoding type of the file
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_FILE_NOT_FOUND        The input file does not exist.
	* @exception    E_IO      The file operation is invalid.
	* @exception    E_INVALID_ARG  The specified encoding scheme does not exist.
	* @remarks      The supported encoding schemes are ASCII, GSM, UCS-2, UCS-2LE, UCS-2BE, UCS-4, UCS-4LE, UCS-4BE, UTF-8, UTF-16, UTF-16LE, UTF-16BE, UTF-32, UTF-32LE, UTF-32BE, ISO-8859-1~16 (except ISO-8859-12), Windows-874, Windows-1250 ~ Windows-1258, KSC5601, BIG5, GB2312, Shift_JIS, and ISO-2022-jp.
	*/
	result Construct(const String& inputFilePath, const String& encodingScheme);

	/**
	* Gets the substring of the input data matching to the pattern constructed from the specified string. @n
	* Delimiter will be ignored and the returned string does not include any line terminator.
	* If such a pattern in the input data is not found upto the next line terminator, return an empty string through the out parameter, matchedStr.
	*
	* @since 2.1
	* @return       An error code
	* @param[in]    patternStr       The string to construct the pattern
	* @param[out]   matchedStr       The matched string or empty string
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_INVALID_ARG  The length of the specified @c string parameter is @c 0.
	* @exception    E_DATA_NOT_FOUND  No substring is found in the input data of current instance.
	*/
	result FindInLine(const String& patternStr, String& matchedStr);

	/**
	* Gets the substring matching the pattern from the input data. @n
	* Delimiter will be ignored and the returned string does not include any line terminator.
	* If such a pattern in the input data is not found upto the next line terminator, return an empty string through the out parameter, matchedStr.
	*
	* @since 2.1
	* @return       An error code
	* @param[in]    pattern  The pattern to compile for finding substring from input data
	* @param[out]   matchedStr       The matched string or empty string
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_DATA_NOT_FOUND  No substring is found in the input data of current instance.
	*/

	result FindInLine(const RegularExpression& pattern, String& matchedStr);

	/**
	* Gets the next token as @c signed @c char. @n Next token is converted to @c signed @c char using default radix.
	* The @c signed @c char can hold value from -128 to 127.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextSignedChar	The next token as a @c signed @c char
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT    The next token cannot be translated into a valid signed @c char value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextSignedChar(signed char& nextSignedChar) const;

	/**
	* Gets the next token as @c signed @c char. @n Next token is converted to @c signed @c char using specified @c radix.
	* The @c signed @c char can hold value from -128 to 127.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextSignedChar	The next token as a @c signed @c char
	* @param[in]    radix     The radix to use for conversion
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT    The next token cannot be translated into a valid @c signed @c char value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/

	result GetNextSignedChar(signed char& nextSignedChar, int radix) const;

	/**
	* Gets the next token as @c int. @n Next token is converted to signed integer using default radix.
	* The signed integer can hold value from -2^31 to 2^31-1.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextInt  The next token as a signed integer
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid integer value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextInt(int& nextInt) const;

	/**
	* Gets the next token as @c int. @n Next token is converted to signed integer using specified @c radix.
	* The signed integer can hold value from -2^31 to 2^31-1.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextInt  The next token as a signed integer
	* @param[in]    radix     The radix to use for conversion
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid integer value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextInt(int& nextInt, int radix) const;

	/**
	* Gets the next token as @c short. @n Next token is converted to signed @c short using default radix.
	* The signed @c short can hold value from -2^15 to 2^15-1.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextShort         The next token as a signed @c short
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid @c short value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextShort(short& nextShort) const;

	/**
	* Gets the next token as @c short. @n Next token is converted to signed @c short using specified @c radix.
	* The signed @c short can hold value from -2^15 to 2^15-1.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextShort         The next token as a signed @c short
	* @param[in]    radix     The radix to use for conversion
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid @c short value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextShort(short& nextShort, int radix) const;

	/**
	* Gets the next token as @c long @c long. @n Next token is converted to signed @c long @c long using default radix.
	* The signed @c long @c long can hold value from -2^63 to 2^63-1.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextLongLong    The next token as a signed @c long @c long
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid @c long @c long value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextLongLong(long long& nextLongLong) const;

	/**
	* Gets the next token as @c long @c long. @n Next token is converted to signed @c long @c long using specified @c radix.
	* The signed @c long @c long can hold value from -2^63 to 2^63-1.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextLongLong    The next token as a signed @c long @c long
	* @param[in]    radix     The radix to use for conversion
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid @c long @c long value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextLongLong(long long& nextLongLong, int radix) const;

	/**
	* Gets the next token as @c float. @n Next token is converted to @c float.
	* The signed @c float can hold a single-precision 32-bit floating number.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextFloat          The next token as a @c float
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT     The next token cannot be translated into a valid @c float value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextFloat(float& nextFloat) const;

	/**
	* Gets the next token as @c double. @n Next token is converted to @c double.
	* The signed @c double can hold a double-precision 64-bit floating number.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextDouble       The next token as a @c double
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT    The next token cannot be translated into a valid @c double value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextDouble(double& nextDouble) const;

	/**
	* Gets the next token as @c bool. @n Next token is converted to boolean.
	* Nothing can be converted, except true/TRUE or false/FALSE.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextBool	The next token as @c bool
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_NUM_FORMAT    The next token cannot be translated into a valid @c bool value.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextBool(bool& nextBool) const;

	/**
	* Gets the input string up to next line delimiter and advances the %Scanner to the beginning of the next line. @n
	* The returned string does not include any line terminator.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextLine The next line as an instance of String
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining lines for the current instance of %Scanner.
	*
	* The following example demonstrates how to use the %GetNextLine() method.
	*
	* @code
	*
	*	String str = "1 hundred bricks\n2 bricks\n3 hundred bricks\n4 bricks";
	*	bool res = false;
	*	String out;
	*	Scanner scan;
	*
	*	scan.Construct(str);
	*
	*	if (scan.HasNextLine())
	*	{
	*		scan.GetNextLine(out); //returns 1 hundred bricks
	*	}
	*	else
	*	{
	*		return;
	*	}
	*
	* @endcode
	*/
	result GetNextLine(String& nextLine) const;

	/**
	* Gets the next token as String.
	*
	* @since 2.1
	* @return       An error code
	* @param[out]   nextTok  The next token as an instance of String
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*
	* The following example demonstrates how to use the %GetNextToken() method.
	* @code
	*
	*	String str = "1 hundred bricks 2 bricks 3 hundred bricks 4 bricks";
	*	bool res =  false;
	*	String out;
	*	Scanner scan;
	*
	*	scan.Construct(str);
	*	String delimiter(L"\\s*bricks\\s*");
	*	scan.SetDelimiter(delimiter);
	*
	*	if (scan.HasNext())
	*	{
	*		scan.GetNextToken(out); //returns 1 hundred
	*	}
	*	else
	*	{
	*		return;
	*	}
	*
	* @endcode
	*/
	result GetNextToken(String& nextTok) const;

	/**
	* Gets the next token as String if it matches to the pattern constructed from the specified string.
	*
	* @since 2.1
	* @return       An error code
	* @param[in]    pattern  The string to construct the pattern
	* @param[out]   nextTok  The next token as an instance of String, @n
	*                        else an empty string if not matched
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_DATA_NOT_FOUND        The next token does not match to the pattern.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextToken(const String& pattern, String& nextTok) const;

	/**
	* Gets the next token as String if it matches to the pattern.
	*
	* @since 2.1
	* @return       An error code
	* @param[in]    pattern  The pattern to find.
	* @param[out]   nextTok  The next token as an instance of String, @n
	*                        else an empty string if not matched
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_DATA_NOT_FOUND        The next token does not match to the pattern.
	* @exception    E_DATA_NOT_ENOUGH          There are no remaining tokens for the current instance of %Scanner.
	*/
	result GetNextToken(const RegularExpression& pattern, String& nextTok) const;

	/**
	* Gets the radix of this %Scanner.
	*
	* @since 2.1
	* @return       The current radix value
	*/
	int GetRadix(void) const;

	/**
	* Gets the delimiter of this %Scanner.
	*
	* @since 2.1
	* @return       The current delimiter string
	*/
	String GetDelimiter(void) const;

	/**
	* Checks whether the current instance of %Scanner has another token.
	*
	* @since 2.1
	* @return       @c true if the current instance has another token, @n
	*	   	else @c false
	*/
	bool HasNextToken(void) const;

	/**
	* Checks whether the next token matches to the pattern constructed from the specified string.
	*
	* @since 2.1
	* @return       @c true if the next token matches to the pattern constructed from the specified string, @n
	*	   	else @c false
	* @param[in]    pattern  The string to construct the pattern
	*/
	bool HasNextToken(const String& pattern) const;

	/**
	* Checks whether the next token matches to the pattern.
	*
	* @since 2.1
	* @return       @c true if the next token matches to the pattern, @n
	*	   	else @c false
	* @param[in]    pattern  The pattern to find
	*/
	bool HasNextToken(const RegularExpression& pattern) const;

	/**
	* Checks whether the next token can be translated into a valid @c signed @c char value in the default radix.
	* The @c signed @c char can hold value from -128 to 127.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c signed @c char value in the current radix, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToSignedChar(void) const;

	/**
	* Checks whether the next token can be translated into a valid @c signed @c char value in the specified @c radix.
	* The @c signed @c char can hold value from -128 to 127.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c signed @c char value in the current radix, @n
	*			else @c false
	* @param[in]    radix     The radix to use to translate the token as a valid @c signed @c char value
	*/
	bool IsNextTokenConvertibleToSignedChar(int radix) const;

	/**
	* Checks whether the next token can be translated into a valid @c int value in the default radix. @n
	* The signed integer can hold value from -2^31 to 2^31-1.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c int value in the current radix, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToInt(void) const;

	/**
	* Checks whether the next token can be translated into a valid @c int value in the specified @c radix. @n
	* The signed integer can hold value from -2^31 to 2^31-1.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c int value in the current radix, @n
	*	   	else @c false
	* @param[in]    radix     The radix to use to translate the token as a valid @c int value
	*/
	bool IsNextTokenConvertibleToInt(int radix) const;

	/**
	* Checks whether the next token can be translated into a valid @c short value in the default radix. @n
	* The signed @c short can hold value from -2^15 to 2^15-1.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c short value in the current radix, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToShort(void) const;

	/**
	* Checks whether the next token can be translated into a valid @c short value in the specified @c radix. @n
	* The signed @c short can hold value from -2^15 to 2^15-1.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c short value in the current radix, @n
	*	   	else @c false
	* @param[in]    radix     The radix to use to translate the token as a valid @c short value
	*/
	bool IsNextTokenConvertibleToShort(int radix) const;

	/**
	* Checks whether the next token can be translated into a valid @c long @c long value. @n
	* The signed @c long @c long can hold value from -2^63 to 2^63-1.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c long @c long value in the current radix, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToLongLong(void) const;

	/**
	* Checks whether the next token can be translated into a valid @c float value. @n
	* The signed @c float can hold a single-precision 32-bit floating number.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c float value in the current radix, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToFloat(void) const;

	/**
	* Checks whether the next token can be translated into a valid @c double value. @n
	* The signed @c double can hold a double-precision 64-bit floating number.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c double value in the current radix, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToDouble(void) const;

	/**
	* Checks whether the next token can be translated into a valid @c bool value. @n
	* Nothing can be converted except true/TRUE or false/FALSE.
	*
	* @since 2.1
	* @return       @c true if the next token can be translated into a valid @c bool value, @n
	*	   	else @c false
	*/
	bool IsNextTokenConvertibleToBool(void) const;

	/**
	* Checks whether the input data of the current instance of %Scanner has another line.
	*
	* @since 2.1
	* @return       @c true if the input data of the current instance of %Scanner has another line, @n
	*	   	else @c false
	*/
	bool HasNextLine(void) const;

	/**
	* Sets the radix of the current instance of %Scanner to the specified @c radix.
	*
	* @since 2.1
	* @param[in]    radix     The radix to use for conversion
	*
	*/
	void SetRadix(int radix);

	/**
	* Sets the delimiter of the current instance of %Scanner to the pattern constructed from the specified delimiter.
	*
	* @since 2.1
	* @param[in]    patternStr	The delimiter to construct the pattern
	*/
	void SetDelimiter(const String& patternStr);

	/**
	* Sets the delimiter of the current instance of %Scanner to the specified @c pattern.
	*
	* @since 2.1
	* @param[in]    pattern  The pattern to use as a delimiter
	*/
	void SetDelimiter(const RegularExpression& pattern);

	/**
	* Skips the pattern constructed from the specified string.
	*
	* @since 2.1
	* @param[in]    patternStr  The string to construct the pattern
	* @remarks      If no match to the specified pattern is found at the current position, nothing is skipped.
	*
	* The following example demonstrates how to use the %Skip() method.
	*
	* @code
	*
	*	const String str("28 1   Ball 2 Ball 3.4 Ball 5 Ball red Ball blue Ball 8 89  67 21474836899.11 NaN 3.4e+5 +23   89 01010 456 123.456");
	*	const String skipStr("28 1   ");
	*	bool res = false;
	*	String out;
	*	Scanner scan;
	*
	*	scan.Construct(str);
	*
	*	//Skips "28 1" from input string
	*	scan.Skip(skipStr);
	*
	*	if (scan1.HasNextToken())
	*	{
	*		scan.GetNextToken(out); //returns Ball
	*	}
	*	else
	*	{
	*		return;
	*	}
	*
	* @endcode
	*/
	void Skip(const String& patternStr);

	/**
	* Skips the specified @c pattern.
	*
	* @since 2.1
	* @param[in]    pattern  The pattern to use to skip
	* @remarks      If no match to the specified pattern is found at the current position, nothing is skipped.
	*/
	void Skip(const RegularExpression& pattern);

private:
	friend class _ScannerImpl;
	class _ScannerImpl* __pScannerImpl;
}; // Scanner

}}}   // Tizen::Base::Utility

#endif // _FBASE_UTIL_SCANNER_H_
