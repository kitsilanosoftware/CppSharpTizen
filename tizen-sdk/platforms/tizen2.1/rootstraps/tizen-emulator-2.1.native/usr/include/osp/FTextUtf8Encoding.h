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
 * @file		FTextUtf8Encoding.h
 * @brief		This is the header file for the %Utf8Encoding class.
 *
 * This header file contains the declarations of the %Utf8Encoding class.
 * This class is derived from the Encoding class.
 */
#ifndef _FTEXT_UTF8_ENCODING_H_
#define _FTEXT_UTF8_ENCODING_H_

#include <FTextEncoding.h>
#include <FTextUtf8Encoder.h>
#include <FTextUtf8Decoder.h>


namespace Tizen { namespace Text
{

/**
 * @class	Utf8Encoding
 * @brief	This class is an implementation of the UTF-8 encoding.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Utf8Encoding class is an implementation of the UTF-8 encoding.
 * Universal Transformation Format-8 (UTF-8) is a translated language used on the internet. It converts Unicode to 8-bit bytes. UTF-8 encoding supports all the Unicode character values and surrogates.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>.
 *
 * The following example demonstrates how to use the %Utf8Encoding class.
 *
 *  @code
 *	#include <FBase.h>
 *	#include <FText.h>
 *
  *	using namespace Tizen::Base;
 *	using namespace Tizen::Text;
 *
 *	void
 *	MyClass::Utf8EncodingSample(void)
 *	{
 *		Utf8Encoding utf8;
 *
 *		String str(L"(\u03a0) and (\u03a3)");
 *
 *		int byteCount;
 *		utf8.GetByteCount(str, byteCount);
 *
 *		// Encodes
 *		ByteBuffer* pBuffer = utf8.GetBytesN(str);
 *
 *		int charCount;
 *		utf8.GetCharCount(*pBuffer, charCount);
 *
 *		// Decodes
 *		String decodedStr;
 *		utf8.GetString(*pBuffer, decodedStr);
 *
 *		if (str.Equals(decodedStr))	
 *		{
 *			//....
 *		}
 *
 *		delete pBuffer;
 *	}
 * @endcode
 *
 */


class _OSP_EXPORT_ Utf8Encoding
	: public Encoding
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Utf8Encoding(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Text::Encoding::~Encoding().
	 *
	 * @since	2.0
	 */
	virtual ~Utf8Encoding(void);

	/**
	 * Gets the total number of bytes that are generated by encoding an instance of specified string. @n
	 * The %GetByteCount() method determines the total number of bytes that are generated when the specified string is encoded.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	str                       The string to encode
	 * @param[out]  byteCount                 The total number of bytes required to encode the string
	 * @exception	E_SUCCESS                 The method is successful.
	 * @exception	E_INVALID_ARG             A specified input parameter is invalid, or
	 *                                        the specified @c str is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::String& str, int& byteCount) const;

	/**
	 * Gets the total number of bytes that are generated by encoding an instance of specified Tizen::Base::WcharBuffer. @n
	 * The %GetByteCount() method determines the exact number of bytes
	 * produced if the given array of characters is encoded.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                 An instance of Tizen::Base::WcharBuffer to encode
	 * @param[out]  byteCount              The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c chars is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars, int& byteCount) const;

	/**
	 * Gets the total number of bytes that are required to encode a range of characters in the specified Tizen::Base::WcharBuffer instance. @n
	 * The %GetByteCount() method determines the total number of bytes that are generated when the specified array of characters is encoded.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                    An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex                The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount                  The total number of characters to encode
	 * @param[out]  byteCount                 The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE		     The value of an argument is outside the valid range defined by the method, or
	 *										  the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount, int& byteCount) const;

	/**
	 * Encodes an instance of the specified Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		                        A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *                                      else @c null if an exception occurs @n
	 *						                The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
	 * @param[in]	chars                   An instance of Tizen::Base::WcharBuffer to encode
	 * @exception	E_SUCCESS                   The method is successful.
	 * @exception	E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_INVALID_ARG           The specified @c chars is empty or invalid.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetCharsN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars) const;

	/**
	 * Encodes an instance of the specified Tizen::Base::String into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		                        A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *                                      else @c null if an exception occurs @n
	 *						                The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
	 * @param[in]	str                     A string to encode
	 * @exception	E_SUCCESS                   The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c str is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetString()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::String& str) const;

	/**
	 * Encodes an instance of Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer as per the specified range. @n
	 * The position and limit of the pointer to the %Tizen::Base::ByteBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                     An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex                 The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount                   The total number of characters to encode
	 * @param[out]  bytes                     The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   byteIndex                 The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or
	 *                                       the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *                                         the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or
	 *                                        the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount,
		Tizen::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/**
	 * Encodes an instance of Tizen::Base::String into an instance of Tizen::Base::ByteBuffer as per the specified range. @n
	 * The position and limit of the pointer to the %Tizen::Base::ByteBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	str                          A string to encode
	 * @param[in]	charIndex                    The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount                      The total number of characters to encode
	 * @param[out]  bytes                        The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   byteIndex                      The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE		     The value of an argument is outside the valid range defined by the method, or
	 *                                         the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or
	 *										   the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetString()
	 */
	virtual result GetBytes(const Tizen::Base::String& str, int charIndex, int charCount,
		Tizen::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/**
	 * Gets the total number of characters that are generated by decoding an instance of Tizen::Base::ByteBuffer. @n
	 * The %GetCharCount() method determines the exact number of characters
	 * produced if the given range of bytes is converted.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[out]  charCount                The total number of characters that are generated by decoding the specified Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Tizen::Base::ByteBuffer& bytes, int& charCount) const;

	/**
	 * Gets the total number of characters that are generated by decoding a range of elements specified in the Tizen::Base::ByteBuffer instance. @n
	 * The %GetCharCount() method determines the exact number of characters
	 * produced if the given range of bytes is converted.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                         An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   byteIndex                    The index from where decoding begins
	 * @param[in]   byteCount                     The total number of bytes to decode
	 * @param[out]  charCount                 The total number of characters that are generated by decoding the specified Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE        The value of an argument is outside the valid range defined by the method, or
	 *										   the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *								          the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Tizen::Base::ByteBuffer& bytes, int byteIndex, int byteCount, int& charCount) const;

	/**
	 * Decodes an instance of the specified Tizen::Base::ByteBuffer into an instance of Tizen::Base::WcharBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		              A pointer to the Tizen::Base::WcharBuffer instance where the resultant decoded data is stored, @n
	 *                                      else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last decoded byte plus one and the position is zero.
	 * @param[in]	bytes                  An instance of Tizen::Base::ByteBuffer to decode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c bytes is empty or invalid.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetBytesN()
	 */
	virtual Tizen::Base::WcharBuffer* GetCharsN(const Tizen::Base::ByteBuffer& bytes) const;

	/**
	 * Decodes an instance of Tizen::Base::ByteBuffer into an instance of Tizen::Base::WcharBuffer as per the specified range. @n
	 * The position and limit of the pointer to the %Tizen::Base::WcharBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   byteIndex                The index from where decoding begins
	 * @param[in]   byteCount                The total number of bytes to decode
	 * @param[out]  chars                    The Tizen::Base::WcharBuffer instance where the resultant decoded data is stored
	 * @param[in]   charIndex                The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c bytes or @c chars is empty.
	 * @exception	E_OUT_OF_RANGE	         The value of an argument is outside the valid range defined by the method, or
	 *									       the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception   E_OVERFLOW	             This operation has caused the memory to overflow, or
	 *										   the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetBytes()
	 */
	virtual result GetChars(const Tizen::Base::ByteBuffer& bytes, int byteIndex, int byteCount,
		Tizen::Base::WcharBuffer& chars, int charIndex = 0) const;

	/**
	 * Gets a string containing the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[out]  str                        A Tizen::Base::String instance @n
	 *                                           It contains the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetBytesN()
	 */
	virtual result GetString(const Tizen::Base::ByteBuffer& bytes, Tizen::Base::String& str) const;

	/**
	 * Gets a string containing the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   index                    The index from where decoding begins
	 * @param[in]   count                    The total number of bytes to decode
	 * @param[out]  str                      A Tizen::Base::String instance @n
	 *                                       It contains the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or
	 *										  the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or
	 *										 the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetBytes()
	 */
	virtual result GetString(const Tizen::Base::ByteBuffer& bytes, int index, int count, Tizen::Base::String& str) const;


	/**
	 * Gets the maximum number of bytes required for encoding a given number of characters.
	 *
	 * @since			2.0
	 *
	 * @return		The maximum number of bytes required for encoding a given number of characters
	 * @param[in]	charCount The total number of characters to encode
	 * @remarks     This method determines an appropriate buffer size for the byte arrays passed to GetBytes() for encoding.
	 * @see			GetByteCount()
	 * @see			GetBytes()
	 */
	virtual int GetMaxByteCount(int charCount) const;


	/**
	* Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	*
	* @since				2.0
	*
	* @return			The maximum number of characters generated by decoding the specified number of bytes
	* @param[in]		byteCount The total number of bytes to encode
	* @remarks     This method determines an appropriate buffer size for the character arrays passed to
	*	            GetChars() or a decoder for encoding.
	* @see			GetCharCount()
	* @see			GetChars()
	*/
	virtual int GetMaxCharCount(int byteCount) const;

	/**
	 * Gets the encoder for the current encoding.
	 *
	 * @since				2.0
	 *
	 * @return			A pointer to the Encoder instance for the current encoding
	 * @remarks     Contrary to GetBytes(), an encoder can convert partial sequences of characters into
	 *              partial sequences of bytes by maintaining the appropriate states between the conversions.
	 * @see			GetBytes()
	 */
	virtual Encoder* GetEncoderN(void) const;

	/**
	 * Gets the decoder for the current encoding.
	 *
	 * @since				2.0
	 *
	 * @return			A pointer to the Decoder instance for the current encoding
	 * @remarks     Contrary to GetChars(), a decoder can convert partial sequences of bytes
	 *              into partial sequences of characters by maintaining the appropriate states between the conversions.
	 * @see			GetChars()
	 */
	virtual Decoder* GetDecoderN(void) const;

	/**
	* Gets the encoding type of the current instance.
	*
	* @since			2.0
	*
	* @return		An encoding type
	*/
	virtual Tizen::Base::String GetEncodingType(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	Utf8Encoding(const Utf8Encoding& utf8Encoding);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	Utf8Encoding& operator =(const Utf8Encoding& utf8Encoding);

	friend class Utf8Decoder;
	friend class _Utf8EncodingImpl;
	class _Utf8EncodingImpl* __pUtf8EncodingImpl;
};

} } // Tizen::Text
#endif //_FTEXT_UTF8_ENCODING_H_
