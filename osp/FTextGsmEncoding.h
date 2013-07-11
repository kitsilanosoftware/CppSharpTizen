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
 * @file		FTextGsmEncoding.h
 * @brief		This is the header file for the %GsmEncoding class.
 *
 * This header file contains the declarations of the %GsmEncoding class.
 * The %GsmEncoding class is derived from the Encoding class.
 */
#ifndef _FTEXT_GSM_ENCODING_H_
#define _FTEXT_GSM_ENCODING_H_

#include <FTextEncoding.h>


namespace Tizen { namespace Text
{
/**
 * @class	GsmEncoding
 * @brief	This class is an implementation of the GSM character encoding.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %GsmEncoding class is an implementation of the GSM character encoding.
 * The Global System for Mobile Communications (GSM) consists of 128 European characters. It supports a 7-bit
 * default alphabet extension table for encoding. It is a target-dependent encoding type.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>.
 *
 * The following example demonstrates how to use the %GsmEncoding class.
 *
 *	@code
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Text;
 *
 *	void
 *	MyClass::GsmEncodingSample(void)
 *	{
 *		GsmEncoding gsm;
 *
 *		String str(L"GSM Encoding test");
 *
 *		int byteCount;
 *		gsm.GetByteCount(str, byteCount);
 *
 *		// Encodes
 *		ByteBuffer* pBuffer = gsm.GetBytesN(str);
 *
 *		int charCount;
 *		gsm.GetCharCount(*pBuffer, charCount);
 *
 *		// Decodes
 *		String decodedStr;
 *		gsm.GetString(*pBuffer, decodedStr);
 *
 *		if (str.Equals(decodedStr))	
 *		{
 *			//....
 *		}
 *
 *		delete pBuffer;
 *	}
 *  @endcode
 */

class _OSP_EXPORT_ GsmEncoding
	: public Encoding
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 */
	GsmEncoding(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Text::Encoding::~Encoding().
	 *
	 * @since	2.0
	 */
	virtual ~GsmEncoding(void);

	/**
	 * Gets the total number of bytes that are required to encode a specified Tizen::Base::String instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	str                     A string to encode
	 * @param[out]  byteCount               The total number of bytes required to encode the specified string
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified string is encoded.
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::String& str, int& byteCount) const;

	/**
	 * Gets the total number of bytes that are required to encode a specified Tizen::Base::WcharBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                 An instance of Tizen::Base::WcharBuffer to encode
	 * @param[out]  byteCount             The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars is empty.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters is encoded.
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars, int& byteCount) const;

	/**
	 * Gets the total number of bytes that are required to encode a range of characters in the specified Tizen::Base::WcharBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars          An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount        The total number of characters to encode
	 * @param[out]  byteCount      The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE			 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters is encoded.
	 * @see			GetMaxByteCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount, int& byteCount) const;

	/**
	 * Encodes an instance of the specified Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
	 * @param[in]	chars                An instance of Tizen::Base::WcharBuffer to encode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c chars is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		 The pointer to the Tizen::Base::ByteBuffer instance is not terminated by a @c null character.
	 * @see			GetCharsN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars) const;

	/**
	 * Encodes an instance of the specified Tizen::Base::String into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
	 * @param[in]	str                  A string to encode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c str is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The pointer to the Tizen::Base::ByteBuffer instance is not terminated by a @c null character.
	 * @see			GetString()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::String& str) const;

	/**
	 * Encodes an instance of Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer as per the specified range. @n
	 * The position and limit of the %Tizen::Base::ByteBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount                 The total number of characters to encode
	 * @param[out]  bytes                     The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   byteIndex                 The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method encodes a range of characters in Tizen::Base::WcharBuffer into a range of bytes in Tizen::Base::ByteBuffer.
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount,
		Tizen::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/**
	 * Encodes an instance of Tizen::Base::String into an instance of Tizen::Base::ByteBuffer as per the specified range. @n
	 * The position and limit of the %Tizen::Base::ByteBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	str                   A string to encode
	 * @param[in]	charIndex             The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount               The total number of characters to encode
	 * @param[out]  bytes                  The Tizen::Base::ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   byteIndex               The starting index of the resultant encoding in the Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE		     The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetString()
	 */
	virtual result GetBytes(const Tizen::Base::String& str, int charIndex, int charCount,
		Tizen::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/**
	 * Gets the total number of characters that are generated by decoding an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes              An instance of Tizen::Base::ByteBuffer to decode
	 * @param[out]  charCount          The total number of characters that are generated by decoding the specified Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters
	 *              that are generated when the specified range of bytes are decoded.
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Tizen::Base::ByteBuffer& bytes, int& charCount) const;

	/**
	 * Gets the total number of characters that are generated by decoding a range of elements specified in the Tizen::Base::ByteBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes             An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   byteIndex          The index from where decoding begins
	 * @param[in]   byteCount         The total number of bytes to decode
	 * @param[out]  charCount         The total number of characters that are generated by decoding the specified Tizen::Base::ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE            The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW               This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters
	 *              that are generated when the specified range of bytes are decoded.
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Tizen::Base::ByteBuffer& bytes, int byteIndex, int byteCount, int& charCount) const;

	/**
	 * Decodes an instance of Tizen::Base::ByteBuffer into an instance of Tizen::Base::WcharBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::WcharBuffer instance where the resultant decoded data is stored, @n
	 *				else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last decoded byte plus one and the starting position is zero.
	 * @param[in]	bytes                An instance of Tizen::Base::ByteBuffer to decode
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c bytes is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetBytesN()
	 */
	virtual Tizen::Base::WcharBuffer* GetCharsN(const Tizen::Base::ByteBuffer& bytes) const;

	/**
	 * Decodes an instance of Tizen::Base::ByteBuffer into an instance of Tizen::Base::WcharBuffer as per the specified range. @n
	 * The position and limit of the %Tizen::Base::WcharBuffer instance is not changed.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bytes                  An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   byteIndex              The index from where decoding begins
	 * @param[in]   byteCount              The total number of bytes to decode
	 * @param[out]  chars                  The Tizen::Base::WcharBuffer instance where the resultant decoded data is stored
	 * @param[in]   charIndex              The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes or @c chars is empty.
	 * @exception	E_OUT_OF_RANGE	         The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception   E_OVERFLOW	             This operation has caused the memory to overflow, or the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
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
	 * @param[in]	bytes               An instance of Tizen::Base::ByteBuffer to decode
	 * @param[out]  str                 A Tizen::Base::String instance @n
	 *                                  It contains the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
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
	 * @param[in]	bytes                      An instance of Tizen::Base::ByteBuffer to decode
	 * @param[in]   index                      The index from where decoding begins
	 * @param[in]   count                      The total number of bytes to decode
	 * @param[out]  str                        A Tizen::Base::String instance @n
	 *                                         It contains the decoded representation of the specified Tizen::Base::ByteBuffer instance.
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			GetBytes()
	 */
	virtual result GetString(const Tizen::Base::ByteBuffer& bytes, int index, int count, Tizen::Base::String& str) const;


	/**
	 * Gets the maximum number of bytes required for encoding the specified number of characters.
	 *
	 * @since			2.0
	 *
	 * @return		The maximum number of bytes required for encoding the specified number of characters
	 * @param[in]	charCount    The total number of characters to encode
	 * @remarks   This method determines an appropriate buffer size for the byte arrays passed to GetBytes() for encoding.
	 * @see			GetByteCount()
	 */
	virtual int GetMaxByteCount(int charCount) const;


	/**
	* Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	*
	* @since			2.0
	*
	* @return		The maximum number of characters that are generated by decoding the specified number of bytes
	* @param[in]	byteCount The total number of bytes to encode
	* @remarks   This method determines an appropriate buffer size for character arrays passed to
	*	          GetChars() or a decoder for encoding.
	* @see				GetByteCount()
	*/
	virtual int GetMaxCharCount(int byteCount) const;


	/**
	 * Gets an encoder for the current encoding.
	 *
	 * @since				2.0
	 *
	 * @return			A pointer to the Encoder instance for the current encoding
	 * @remarks     Contrary to GetBytes(), an encoder can convert partial sequences of characters into
	 *              partial sequences of bytes by maintaining the appropriate state between the conversions.
	 *              Currently only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 * @see			GetBytes()
	 */
	virtual Encoder* GetEncoderN(void) const;

	/**
	 * Gets a decoder for the current encoding.
	 *
	 * @since				2.0
	 *
	 * @return			A pointer to the Decoder instance for the current encoding
	 * @remarks     Contrary to GetChars(), a decoder can convert partial sequences of bytes
	 *              into partial sequences of characters by maintaining the appropriate state between the conversions.
	 *              Currently only UTF-8 encoding supports this method. The other classes return a value of @c null.
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
	GsmEncoding(const GsmEncoding& gsmEncoding);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	GsmEncoding& operator =(const GsmEncoding& gsmEncoding);

	friend class _GsmEncodingImpl;
	class _GsmEncodingImpl* __pGsmEncodingImpl;
};

} } // Tizen::Text
#endif //_FTEXT_GSM_ENCODING_H_
