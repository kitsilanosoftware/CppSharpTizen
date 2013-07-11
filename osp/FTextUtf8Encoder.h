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
 * @file		FTextUtf8Encoder.h
 * @brief		This is the header file for the %Utf8Encoder class.
 *
 * This header file contains the declarations of the %Utf8Encoder class.
 *
 */
#ifndef _FTEXT_UTF8_ENCODER_H_
#define _FTEXT_UTF8_ENCODER_H_

#include <FTextEncoder.h>
#include <FBaseByteBuffer.h>


namespace Tizen { namespace Text
{

/**
 * @class	Utf8Encoder
 * @brief	This class is an implementation of the UTF-8 encoder.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Utf8Encoder class converts the blocks of characters into encoded blocks of bytes.
 * Universal Transformation Format-8 (UTF-8) is a translated language that is used on the internet. It converts the
 * unicode into 8-bit bytes. @n UTF-8 encoding supports all unicode character values and surrogates.
 * Note that %Utf8Encoder is not used in reality, because keeping the internal state of encoding from unicode
 * to UTF-8 can be avoided if the translation unit is even.
 * This means that the real implementation of %Utf8Encoder is the same as that of Utf8Encoding in this state.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/text/converting_text_data_separate_blocks.htm">Converting Text Data in Separate Blocks</a>.
 *
 * The following example demonstrates how to use the %Utf8Encoder class.

 *
 * @code
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Text;
 *
 *	void
 *	MyClass::Utf8EncoderSample(void)
 *	{
 *		Utf8Encoder utf8En;
 *
 *		// Fills a WcharBuffer with the unicode strings to encode it into UTF8 format bytes.
 *		WcharBuffer* pMB = PrepareUtf8EncoderSample();
 *
 *		int charBufSize = pMB->GetCapacity();
 *
 *		int byteCount = 0;
 *		utf8En.GetByteCount(*pMB, 0, charBufSize, byteCount);
 *
 *		ByteBuffer enBytes;
 *		enBytes.Construct(byteCount);
 *
 *		int charIndex = 0;
 *		int charCount = 100;
 *
 *		while (charIndex < charBufSize)
 *		{
 *			ByteBuffer* pBB = null;
 *
 *			if (charBufSize - charIndex < charCount)
 *			{
 *				charCount = charBufSize - charIndex;
 *			}
 *
 *			// Converts Unicode to Utf8 using Utf8Encoder.
 *			pBB = utf8En.GetBytesN(*pMB, charIndex, charCount); // flush is false
 *
 *			enBytes.CopyFrom(*pBB);
 *			charIndex += charCount;
 *
 *			delete pBB;
 *		}
 *
 *		enBytes.SetByte('\0');
 *		enBytes.Rewind();
 *
 *		delete pMB;
 *	}
 * @endcode
 */


class _OSP_EXPORT_ Utf8Encoder
	: public Encoder
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 */
	Utf8Encoder(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Text::Encoder::~Encoder().
	 *
	 * @since	2.0
	 */
	virtual ~Utf8Encoder(void);

	/**
	 * Gets the total number of bytes that are required to encode a range of characters in the specified Tizen::Base::WcharBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars                  An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex              The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount                 The total number of characters to encode
	 * @param[in]   flush                     Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *						                else @c false
	 * @param[out]  byteCount               The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE			 The value of an argument is outside the valid range defined by the method, or
	 *										 the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										 the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see			Utf8Decoder::GetCharCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars,
		int charIndex, int charCount, int& byteCount, bool flush = false) const;

	/**
	 * Encodes an instance of Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		                   A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *                                 else @c null if an exception occurs @n
	 *						           The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
	 * @param[in]	chars              An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]   flush              Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *				                   else @c false
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY      The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c chars is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see	        Utf8Decoder::GetCharsN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars, bool flush = false) const;

	/**
	 * Encodes an instance of Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer as per the specified range.
	 *
	 * @since			2.0
	 *
	 * @return		                   A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *                                 else @c null if an exception occurs @n
	 *						            The buffer limit is the position of the last encoded byte and the starting position is zero.
	 * @param[in]	chars               An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex               The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount The total number of characters to encode
	 * @param[in]   flush                    Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *				                         else @c false
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE          The value of an argument is outside the valid range defined by the method, or
	 *                                       the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *                                        the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The pointer to the Tizen::Base::ByteBuffer instance is not terminated by a @c null character.
	 * @see	        Utf8Decoder::GetCharsN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount,
		bool flush = false) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	Utf8Encoder(const Utf8Encoder& utf8Encoder);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	Utf8Encoder& operator =(const Utf8Encoder& utf8Encoder);

	friend class _Utf8EncoderImpl;
	class _Utf8EncoderImpl* __pUtf8EncoderImpl;
};

} } // Tizen::Text
#endif //_FTEXT_UTF8_ENCODER_H_
