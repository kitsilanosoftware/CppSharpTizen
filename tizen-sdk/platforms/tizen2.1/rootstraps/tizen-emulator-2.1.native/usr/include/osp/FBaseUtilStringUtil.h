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
 * @file		FBaseUtilStringUtil.h
 * @brief		This is the header file for the %StringUtil class.
 *
 * This header file contains the declarations of the %StringUtil class.
 */
#ifndef _FBASE_UTIL_STRING_UTIL_H_
#define _FBASE_UTIL_STRING_UTIL_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FBaseBuffer.h>
#include <FBaseResult.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	StringUtil
 * @brief	This class provides various utility methods for String.
 *
 * @since 2.0
 *
 * The %StringUtil class provides various utility methods for String.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %StringUtil class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::StringUtilSample(void)
 *	{
 *		String str1(L"Sigma and Pi : \u03A0 and \u03A3");
 *		String str2;
 *
 *		// String to McharBuffer
 *		McharBuffer* pMb = StringUtil::StringToMbN(str1);
 *
 *		// Gets a length of string in McharBuffer
 *		int length = StringUtil::GetStringLengthInMb(*pMb);
 *
 *		// McharBuffer to String
 *		StringUtil::MbToString(*pMb, str2);
 *
 *		if (str1.Equals(str2))
 *		{
 *			// ...
 *		}
 *
 *		delete pMb;
 *	}
 * @endcode
 */
class _OSP_EXPORT_ StringUtil
{
public:
	/**
	 * @if OSPDEPREC
	 * Converts an McharBuffer to a null-terminated string. @n
	 * The position of the buffer is not changed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the WcharBufferToString(const WcharBuffer& mb, String& str) method.
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		mb		An instance of McharBuffer
	 * @param[out]		str		The current position
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid, or
	 *									@c null does not exist between the position and limit of buffer.
	 * @endif
	 */
	static result MbToString(const McharBuffer& mb, String& str);

	/**
	 * Converts an WcharBuffer to a null-terminated string. @n
	 * The position of the buffer is not changed.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		wb		An instance of WcharBuffer
	 * @param[out]		str		The current position
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid, or
	 *									@c null does not exist between the position and limit of buffer.
	 */
	static result WcharBufferToString(const WcharBuffer& wb, String& str);

	/**
	 * @if OSPDEPREC
	 * Gets a new McharBuffer from the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the StringToWcharBufferN(const String& str) method.
	 * @since 2.0
	 *
	 * @return			A pointer to the McharBuffer instance from the specified string, @n
	 *					else @c null if an exception occurs
	 * @param[in]		str		The string to read
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c str is an empty string.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	static McharBuffer* StringToMbN(const String& str);

	/**
	 * Gets a new WcharBuffer from the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the WcharBuffer instance from the specified string, @n
	 *					else @c null if an exception occurs
	 * @param[in]		str		The string to read
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c str is an empty string.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static WcharBuffer* StringToWcharBufferN(const String& str);

	/**
	 * @if OSPDEPREC
	 * Gets a new McharBuffer from a substring of the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the StringToWcharBufferN(const String& str, int index, int length) method.
	 * @since 2.0
	 *
	 * @return			A pointer to the McharBuffer instance from the substring of the specified string, @n
	 *					else @c null if an exception occurs
	 * @param[in]		str		The string to read
	 * @param[in]		index	The starting index for the substring in the string @n
	 *							It must not be longer than the length of the string.
	 * @param[in]		length	The length of the substring @n
	 *							It must not be longer than the length of the given string minus the specified @c index.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c str is an empty string.
	 * @exception		E_OUT_OF_RANGE		The @c index and @c length are outside the bounds of the data structure.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	static McharBuffer* StringToMbN(const String& str, int index, int length);

	/**
	 * Gets a new WcharBuffer from a substring of the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the WcharBuffer instance from the substring of the specified string, @n
	 *					else @c null if an exception occurs
	 * @param[in]		str		The string to read
	 * @param[in]		index	The starting index for the substring in the string @n
	 *							It must not be longer than the length of the string.
	 * @param[in]		length	The length of the substring @n
	 *							It must not be longer than the length of the given string minus the specified @c index.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c str is an empty string.
	 * @exception		E_OUT_OF_RANGE		The @c index and @c length are outside the bounds of the data structure.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static WcharBuffer* StringToWcharBufferN(const String& str, int index, int length);

	/**
	 * @if OSPDEPREC
	 * Gets the string length in the McharBuffer. @n
	 * The string length is the length from the current position of the %McharBuffer to the @c null character.
	 * The position of the buffer is not changed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the GetStringLengthInWcharBuffer(const WcharBuffer& wb) method.
	 *
	 * @since 2.0
	 *
	 * @return			The length of the McharBuffer instance, @n
	 *					else @c -1 if the %McharBuffer instance is not terminated with the @c null character
	 * @param[in]		mb		An instance of McharBuffer
	 * @remarks			If @c null does not exist between the position and the limit of the buffer, the method returns @c -1.
	 * @endif
	 */
	static int GetStringLengthInMb(const McharBuffer& mb);

	/**
	 * Gets the string length in the WcharBuffer. @n
	 * The string length is the length from the current position of the %WcharBuffer to the @c null character.
	 * The position of the buffer is not changed.
	 *
	 * @since 2.0
	 *
	 * @return			The length of the WcharBuffer instance, @n
	 *					else @c -1 if the %WcharBuffer instance is not terminated with the @c null character
	 * @param[in]		wb		An instance of WcharBuffer
	 * @remarks			If @c null does not exist between the position and the limit of the buffer, the method returns @c -1.
	 */
	static int GetStringLengthInWcharBuffer(const WcharBuffer& wb);

	/**
	 * Gets a new ByteBuffer encoded from the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the ByteBuffer instance encoded from the specified string, @n
	 * 					else @c null if an exception occurs
	 * @param[in]		unicodeString	A string to encode
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG	The specified input parameter is invalid.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Tizen::Base::ByteBuffer
	 * @see				Tizen::Base::String
	 */
	static ByteBuffer* StringToUtf8N(const String& unicodeString);

	/**
	 * Decodes a null-terminated UTF-8 string into a Unicode string. @n
	 * The position of the buffer is not changed.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		pUtf8String		A pointer to a String instance containing UTF-8 codes
	 * @param[out]		unicodeString	A string containing Unicode characters
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				The specified @c pUtf8String is a @c null reference.
	 * @exception		E_INVALID_ENCODING_RANGE	The indicated string contains UTF-8 code that is outside the bounds specified by the character encoding scheme.
	 *
	 * The following example demonstrates how to use the %Utf8ToString() method.
	 *
	 * @code
	 *
	 *	 const char* pUtf8String = "Utf8ToString";
	 *
	 *	 String str;
	 *
	 *	 // Decodes a UTF-8 string into a Unicode string
	 *	 StringUtil::Utf8ToString(pUtf8String, str);
	 *
	 * @endcode
	 */
	static result Utf8ToString(const char* pUtf8String, String& unicodeString);

	/**
	 * Decodes a string consisting of base 64 digits to a ByteBuffer. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the ByteBuffer instance decoded from the specified string, @n
	 * 					else @c null if an exception occurs
	 * @param[in]		base64String	A string to decode
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid. @n
	 *										The specified @c base64String is not a valid Base64 string.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 *
	 * The following example demonstrates how to use the %DecodeBase64StringN() method.
	 *
	 * @code
	 *
	 *	const char* pChar = "abcdefg123456";
	 *	int size = strlen(pChar);
	 *
	 *	String encodedStr;
	 *	ByteBuffer buffer;
	 *	buffer.Construct(size + 1);
	 *
	 *	buffer.SetArray((byte*)pChar, 0, size);
	 *	buffer.SetByte('\0');
	 *	buffer.Flip();
	 *
	 *	StringUtil::EncodeToBase64String(buffer, encodedStr);
	 *
	 *	// Decodes a String consisting of base 64 digits to a ByteBuffer
	 *	ByteBuffer* pDecodedBuffer = StringUtil::DecodeBase64StringN(encodedStr);
	 *
	 * @endcode
	 */
	static ByteBuffer* DecodeBase64StringN(const String& base64String);

	/**
	 * Encodes a ByteBuffer into a string consisting of base 64 characters. @n
	 * The position of the buffer is not changed.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		buffer			An instance of ByteBuffer to encode
	 * @param[out]		encodedString	An instance of String consisting of base 64 characters
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid, or
	 *										the @c buffer is empty.
	 *
	 * The following example demonstrates how to use the %EncodeToBase64String() method.
	 *
	 * @code
	 *
	 *	const char* pChar = "abcdefg123456";
	 *	int size = strlen(pChar);
	 *
	 *	String encodedStr;
	 *	ByteBuffer buffer;
	 *	buffer.Construct(size + 1);
	 *
	 *	buffer.SetArray((byte*)pChar, 0, size);
	 *	buffer.SetByte('\0');
	 *	buffer.Flip();
	 *
	 *	// Encodes a ByteBuffer into a String consisting of base 64 characters
	 *	StringUtil::EncodeToBase64String(buffer, encodedStr);
	 *
	 * @endcode
	 */
	static result EncodeToBase64String(const ByteBuffer& buffer, String& encodedString);

private:
	/**
	 * This default constructor is intentionally declared as private because this class cannot be constructed.
	 */
	StringUtil(void);

	/**
	 * This destructor is intentionally declared as private because this class cannot be constructed.
	 */
	~StringUtil(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	The instance of the StringUtil
	 */
	StringUtil(const StringUtil& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %StringUtil
	 */
	StringUtil& operator =(const StringUtil& rhs);
}; // StringUtil

}}} // Tizen::Base::Utility

#endif // _FBASE_UTIL_STRING_UTIL_H_
