//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseUtilStringTokenizer.h
 * @brief		This is the header file for the %StringTokenizer class.
 *
 * @see			String()
 *
 * This header file contains the declarations of the %StringTokenizer class.
 */

#ifndef _FBASE_UTIL_STRING_TOKENIZER_H_
#define _FBASE_UTIL_STRING_TOKENIZER_H_

#include <FBaseObject.h>
#include <FBaseString.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	StringTokenizer
 * @brief	This class is used to break a String into tokens.
 *
 * @since 2.0
 *
 * The %StringTokenizer class is used to break a String into tokens. It also provides ways to count the number of tokens.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/string_tokenizer.htm">String Tokenizer</a>.
 *
 * The following example demonstrates how to use the %StringTokenizer class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::StringTokenizerSample(void)
 *	{
 *		String str(L"Tizen-StringTokenizer/Sample code");
 *		String delim(L" /-");
 *
 *		// Creates a StringTokenizer instance
 *		StringTokenizer strTok(str, delim);
 *
 *		int count = strTok.GetTokenCount();		// count == 4
 *
 *		String token;
 *		while (strTok.HasMoreTokens())
 *		{
 *			strTok.GetNextToken(token);			// Tizen, StringTokenizer, Sample, code
 *		}
 *	}
 * @endcode
 *
 *
 */

class _OSP_EXPORT_ StringTokenizer
	: public Object
{
public:
	/**
	 * Initializes an instance of %StringTokenizer with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value		An instance of String to parse
	 * @param[in]	delimiters	The delimiters
	 * @param[in]	isToken		A flag indicating whether to return the delimiters as tokens @n
	 *							Set to @c true to treat the delimiters as tokens, @n
	 *							else @c false to skip the delimiters.
	 *
	 */
	StringTokenizer(const String& value, const String& delimiters = L" \t\n\r\f", bool isToken = false);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 *
	 * @remarks		The internally allocated memory block is freed when the instance is destroyed.
	 */
	virtual ~StringTokenizer(void);

	/**
	 * Gets the token count indicating the number of times the GetNextToken() method can be called before it returns an error code.
	 *
	 * @since 2.0
	 *
	 * @return		An integer value indicating the number of times the GetNextToken() method can be called
	 */
	int GetTokenCount(void);

	/**
	 * Checks whether there are any more tokens in the string after the current position.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if there is at least one more token in the string after the current position, @n
	 *				else @c false
	 */
	bool HasMoreTokens(void);

	/**
	 * Gets the next token from the string tokenizer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	token	The next token
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The string tokenizer has no more tokens.
	 */
	result GetNextToken(String& token);

	/**
	 * Sets the new delimiters.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	delimiters	The new delimiters
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *
	 * The following example demonstrates how to use the %SetDelimiters() method.
	 *
	 * @code
	 *
	 *	String str(L"Tizen-Framework-Utility::StringTokenizer/class");
	 *	String delim(L":-");
	 *
	 *	String token;
	 *
	 *	StringTokenizer strTok(str, delim);
	 *
	 *	for (int i = 0; i < 3; i++)
	 *	{
	 *		strTok.GetNextToken(token);			// Tizen, Framework, Utility
	 *	}
	 *
	 *	String newDelim(L"/");
	 *
	 *	strTok.SetDelimiters(newDelim);
	 *	strTok.GetNextToken(token);				// token == L"::StringTokenizer"
	 *
	 * @endcode
	 */
	result SetDelimiters(const String& delimiters);

private:
	//
	// Sets the maximum characters of delimiters.
	//
	// @return	An @c wchar_t value indicating the maximum characters
	//
	wchar_t SetMaxDelimChar(void);

	//
	// Skips the delimiters starting from the specified position.
	//
	// @return	If the delimiter is not regarded as a token, the method returns the index of the first non-delimiter character. @n
	//			If the delimiter is regarded as a token, the method returns the starting position.
	// @param[in]	position	The position from where the delimiters need to skip
	//
	int SkipDelimiters(int position);

	//
	// Scans the tokens starting from the specified position.
	//
	// @return		The index of the next delimiter after the specified position
	// @param[in] position	The position to start scan
	//
	int ScanToken(int position);


private:
	String __string;
	String __delimiters;
	int __curPosition;
	int __newPosition;
	int __maxStrLen;
	wchar_t __maxDelimChar;
	bool __isToken;
	bool __isDelimChanged;

	friend class _StringTokenizerImpl;
	class _StringTokenizerImpl* __pStringTokenizerImpl;

}; // StringTokenizer

}}} // Tizen::Base::Utility

#endif //_FBASE_UTIL_STRING_TOKENIZER_H_
