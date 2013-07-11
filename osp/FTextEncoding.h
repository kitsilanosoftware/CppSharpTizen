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
 * @file		FTextEncoding.h
 * @brief		This is the header file for the %Encoding class.
 *
 * This header file contains the declarations of the %Encoding class. @n
 * The %Encoding class is the base class for all character encoding classes.
 */
#ifndef _FTEXT_ENCODING_H_
#define _FTEXT_ENCODING_H_

// Include
#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseBuffer.h>
#include <FBaseColIList.h>
#include <FBaseString.h>
#include <FTextEncoder.h>
#include <FTextDecoder.h>


namespace Tizen { namespace Text
{

/**
 * @class	Encoding
 * @brief	This class implements character encoding.
 *
 * @since	2.0
 *
 * The %Encoding class is the base class for all classes that implement character encoding.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>.
 *
 * The following example demonstrates how to use the %Encoding class.
 *
 *	@code
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Text;
 *
 *	void
 *	MyClass::EncodingSample(void)
 *	{
 *		Encoding* pEnc = Encoding::GetEncodingN(L"ISO-8859-2");
 *
 *		String str(L"Encoding Test \u0104\u02D8");
 *
 *		int byteCount;
 *		pEnc->GetByteCount(str, byteCount);
 *
 *		// Encodes
 *		ByteBuffer* pBuffer = pEnc->GetBytesN(str);
 *
 *		int charCount;
 *		pEnc->GetCharCount(*pBuffer, charCount);
 *
 *		// Decodes
 *		String decodedStr;
 *		pEnc->GetString(*pBuffer, decodedStr);
 *
 *		if (str.Equals(decodedStr))
 *		{
 *			//....
 *		}
 *
 *		delete pBuffer;
 *
 *		delete pEnc;
 *	}
 *  @endcode
 */

class AsciiEncoding;
class Utf8Encoding;
class Ucs2Encoding;
class Latin1Encoding;
class GsmEncoding;

class _OSP_EXPORT_ Encoding
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Encoding(void);

	/**
	 * Gets the total number of bytes that are required to encode the specified string.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	str                      The string to encode
	 * @param[out]  byteCount                The total number of bytes that are required to encode the specified string
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified string is encoded.
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::String& str, int& byteCount) const;

	/**
	 * Gets the total number of bytes that are required to encode the specified characters.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                    An instance of Tizen::Base::WcharBuffer to encode
	 * @param[out]  byteCount                The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars is empty.
	 * @exception	E_INVALID_ENCODING_RANGE    The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters are encoded.
	 * @see	        GetMaxByteCount()
	 * @see	        GetByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars, int& byteCount) const;

	/**
	 * Gets the total number of bytes that are required to encode a range of characters in the specified Tizen::Base::WcharBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex            The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount              The total number of characters to encode
	 * @param[out]  byteCount            The total number of bytes that are required to encode the specified range of characters
	 * @exception	E_SUCCESS            The method is successful.
	 * @exception	E_INVALID_ARG        A specified input parameter is invalid, or the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE		 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW          This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters are encoded.
	 * @see			GetMaxByteCount()
	 * @see			GetByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount,
		int& byteCount) const;

	/**
	 * Encodes an instance of specified Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
	 * @param[in]	chars                An instance of Tizen::Base::WcharBuffer to encode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c chars is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetCharsN()
	 * @see			GetBytesN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars) const = 0;

	/**
	 * Encodes the specified string of type Tizen::Base::String to Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last encoded byte plus one and the position is zero.
	 * @param[in]	str                  The string to encode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c str is invalid or is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetString()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::String& str) const = 0;

	/**
	 * Encodes an instance of specified Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer as per the specified range. @n
	 * The position and limit of the %Tizen::Base::ByteBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
     * @param[in]	chars							The buffer containing the character array to encode
	 * @param[in]	charIndex					The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]	charCount					The total number of characters to encode
	 * @param[out]	bytes						The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]	byteIndex					The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid, or the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE				The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_UNDERFLOW					This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW					This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE	The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		This method encodes a range of characters in Tizen::Base::WcharBuffer into a range of bytes in Tizen::Base::ByteBuffer.
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount,
		Tizen::Base::ByteBuffer& bytes, int byteIndex) const = 0;

	/**
	 * Encodes an instance of Tizen::Base::String into an instance of Tizen::Base::ByteBuffer as per the specified range. @n
	 * The position and limit of the %Tizen::Base::ByteBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	str                     The string to encode
	 * @param[in]	charIndex               The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount                 The total number of characters to encode
	 * @param[out]  bytes                   The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   byteIndex                 The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE			 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetString()
	 */
	virtual result GetBytes(const Tizen::Base::String& str, int charIndex, int charCount,
		Tizen::Base::ByteBuffer& bytes, int byteIndex) const = 0;

	/**
	 * Gets the total number of characters that are generated by decoding an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[out]  charCount                The total number of characters that are generated by decoding a range of bytes in the specified Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters
	 *              that are generated when the specified range of bytes are encoded.
	 * @see			GetMaxCharCount()
	 * @see			GetCharCount()
	 */
	virtual result GetCharCount(const Tizen::Base::ByteBuffer& bytes, int& charCount) const;

	/**
	 * Gets the total number of characters that are generated by decoding a range of elements specified in the Tizen::Base::ByteBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                 An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   byteIndex             The index from where decoding begins
	 * @param[in]   byteCount             The total number of bytes to decode
	 * @param[out]  charCount             The total number of characters that are generated by decoding a range of bytes in the specified Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS             The method is successful.
	 * @exception	E_OUT_OF_MEMORY       The memory is insufficient.
	 * @exception	E_INVALID_ARG         A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE        The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW           This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters
	 *              that are generated when the specified range of bytes are encoded.
	 * @see			GetMaxCharCount()
	 * @see			GetCharCount()
	 */
	virtual result GetCharCount(const Tizen::Base::ByteBuffer& bytes, int byteIndex, int byteCount, int& charCount) const;

	/**
	 * Decodes an instance of Tizen::Base::ByteBuffer into an instance of Tizen::Base::WcharBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::WcharBuffer instance where the resultant decoded data is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last decoded byte plus one and the starting position is zero.
	 * @param[in]	bytes               An instance of Tizen::Base::ByteBuffer to decode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c bytes is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetBytesN()
	 */
	virtual Tizen::Base::WcharBuffer* GetCharsN(const Tizen::Base::ByteBuffer& bytes) const = 0;

	/**
	 * Decodes an instance of Tizen::Base::ByteBuffer into an instance of Tizen::Base::WcharBuffer as per the specified range. @n
	 * The position and limit of the %Tizen::Base::WcharBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                 An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   byteIndex             The index from where decoding begins
	 * @param[in]   byteCount             The total number of bytes to decode
	 * @param[out]  chars                 The Tizen::Base::WcharBuffer instance where the resultant decoded data is stored
	 * @param[in]   charIndex             The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE	         The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception   E_OVERFLOW	             This operation has caused the memory to overflow, or the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetBytes()
	 */
	virtual result GetChars(const Tizen::Base::ByteBuffer& bytes, int byteIndex, int byteCount,
		Tizen::Base::WcharBuffer& chars, int charIndex) const = 0;

	/**
	 * Gets a string that contains the decoded representation of a range of bytes in the specified Tizen::Base::ByteBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[out]  str                      A Tizen::Base::String instance @n
	 *                                       It contains the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytesN()
	 * @see			GetString()
	 */
	virtual result GetString(const Tizen::Base::ByteBuffer& bytes, Tizen::Base::String& str) const = 0;

	/**
	 * Gets a string that contains the decoded representation of a range of bytes in the specified Tizen::Base::ByteBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                    An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   index                    The index from where decoding begins
	 * @param[in]   count                    The total number of bytes to decode
	 * @param[out]  str                     A Tizen::Base::String instance @n
	 *                                      It contains the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetBytes()
	 * @see			GetString()
	 */
	virtual result GetString(const Tizen::Base::ByteBuffer& bytes, int index, int count, Tizen::Base::String& str) const = 0;

	/**
	 * Gets the maximum number of bytes that are required to encode the specified number of characters.
	 *
	 * @since			2.0
	 *
	 * @return		The maximum number of bytes that are required to encode the specified number of characters
	 * @param[in]	charCount     The total number of characters to encode
	 * @remarks     This method determines an appropriate buffer size for the byte arrays passed to GetBytes() for encoding.
	 * @see			GetByteCount()
	 * @see			GetBytes()
	 */
	virtual int GetMaxByteCount(int charCount) const = 0;

	/**
	 * Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum number of characters that are generated by decoding the specified number of bytes
	 * @param[in]	byteCount The total number of bytes to encode
	 * @remarks      This method determines an appropriate buffer size for character arrays passed to
	 *	            GetChars() or a decoder for encoding.
	 * @see			GetCharCount()
	 * @see			GetChars()
	 */
	virtual int GetMaxCharCount(int byteCount) const = 0;

	/**
	 * Gets the encoder for the current encoding.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Encoder instance for the current encoding
	 * @remarks     Contrary to GetBytes(), an encoder can convert partial sequences of characters into
	 *              partial sequences of bytes by maintaining an appropriate state between the conversions.
	 *              Currently, only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 * @see			GetBytes()
	 */
	virtual Encoder* GetEncoderN(void) const = 0;

	/**
	 * Gets the decoder for the current encoding.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Decoder instance for the current encoding
	 * @remarks     Contrary to GetChars(), a decoder can convert partial sequences of bytes
	 *              into partial sequences of characters by maintaining an appropriate state between the conversions.
	 *              Currently, only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 * @see			GetChars()
	 */
	virtual Decoder* GetDecoderN(void) const = 0;

	/**
	 * Gets the encoding type of the current instance.
	 *
	 * @since			2.0
	 *
	 * @return		An encoding type
	 */
	virtual Tizen::Base::String GetEncodingType(void) const = 0;

	/**
	* Gets an encoding for the UTF-8 format.
	*
	* @since			2.0
	*
	* @return		An encoding for the UTF-8 format
	*
	* @see				Tizen::Text::Utf8Encoding
	*/
	static Utf8Encoding& GetUtf8Encoding(void);

	/**
	* Gets an encoding for the UCS-2 format.
	*
	* @since			2.0
	*
	* @return		An encoding for the UCS-2 format
	-*
	* @see				Tizen::Text::Ucs2Encoding
	*/
	static Ucs2Encoding& GetUcs2Encoding(void);

	/**
	* Gets an encoding for the GSM format.
	*
	* @since			2.0
	*
	* @return		An encoding for the GSM format
	*
	* @see				Tizen::Text::GsmEncoding
	*/
	static GsmEncoding& GetGsmEncoding(void);

	/**
	* Gets an encoding for the Latin1 format.
	*
	* @since			2.0
	*
	* @return		An encoding for the Latin1 format
	*
	* @see				Tizen::Text::Latin1Encoding
	*/
	static Latin1Encoding& GetLatin1Encoding(void);

	/**
	* Gets an encoding for the ASCII format.
	*
	* @since			2.0
	*
	* @return		An encoding for the ASCII format
	*
	* @see				Tizen::Text::AsciiEncoding
	*/
	static AsciiEncoding& GetAsciiEncoding(void);

	/**
	 * Gets an %Encoding instance from the specified encoding type.
	 *
	 * @since			2.0
	 *
	 * @return    An instance of %Encoding, @n
	 *                else @c null if the method fails
	 * @param[in]	encodingType    An encoding type @n
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_TYPE      The specified encoding type is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *			The supported encoding types are ASCII, GSM, UCS-2, UCS-2LE, UCS-2BE, UCS-4, UCS-4LE, UCS-4BE, UTF-8, UTF-16, UTF-16LE, UTF-16BE, @n
 	 *				UTF-32, UTF-32LE, UTF-32BE, ISO-8859-1~16 (except ISO-8859-12), Windows-874, Windows-1250 ~ Windows-1258, @n
	 *				KSC5601, BIG5, GB2312, Shift_JIS and ISO-2022-jp.
	 * @see			Tizen::Text::Encoding::GetAvailableEncodingsN()
	 */
	static Encoding* GetEncodingN(const Tizen::Base::String& encodingType);

	/**
	* Gets the encoding type of the specified %Encoding instance.
	*
	* @since			2.0
	*
	* @return		An encoding type
	* @param[in] encoding An instance of %Encoding
	*/
	static Tizen::Base::String GetEncodingType(const Encoding& encoding);

	/**
	 * Gets a list of all the available encodings.
	 *
	 * @since			2.0
	 *
	 * @return		A list of Tizen::Base::String instances (ASCII, UTF-8, ISO-8859-1, ISO-8859-2, Windows-1254, and so on), @n
	 *              else @c null if the method fails
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::Collection::IList* GetAvailableEncodingsN(void);

	/**
	 * Converts an instance of Tizen::Base::ByteBuffer from one encoding format to another.
	 *
	 * @since			2.0
	 *
	 * @return		A new buffer for storing the result of the conversion, @n
	 *				else @c null if an exception occurs @n
	 *				    The buffer limit is the position of the last converted byte plus one and the starting position is zero.
	 * @param[in]	src                      The source of the encoding
	 * @param[in]	dst                      The destination of the encoding
	 * @param[in]	srcBytes                 The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c srcBytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetBytes()
	 * @see			GetChars()
	 */
	static Tizen::Base::ByteBuffer* ConvertN(const Encoding& src, const Encoding& dst,
		const Tizen::Base::ByteBuffer& srcBytes);

	/**
	 * Converts a range of bytes in the Tizen::Base::ByteBuffer instance from one encoding format to another.
	 *
	 * @since			2.0
	 *
	 * @return		A new buffer for storing result of the conversion, @n
	 *				else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last converted byte plus one and the starting position is zero.
	 * @param[in]	src                      The source of the encoding
	 * @param[in]	dst                      The destination of the encoding
	 * @param[in]   srcBytes                 The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   index                    The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @param[in]   count                    The total number of bytes to convert
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c srcBytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or the specified @c index or @c count is greater than the length of the specified @c srcBytes.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c srcBytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetBytes()
	 * @see			GetChars()
	 */
	static Tizen::Base::ByteBuffer* ConvertN(const Encoding& src, const Encoding& dst, const Tizen::Base::ByteBuffer& srcBytes,
		int index, int count);

protected:
	Encoding(void);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Encoding_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Encoding_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Encoding_Reserved3(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Encoding_Reserved4(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Encoding_Reserved5(void) { }

	friend class _EncodingImpl;
	class _EncodingImpl* _pEncodingImpl;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	Encoding(const Encoding& encoding);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	Encoding& operator =(const Encoding& encoding);

}; // Encoding

} } // Tizen::Text

#endif //_FTEXT_ENCODING_H_
