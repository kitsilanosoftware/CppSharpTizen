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
 * @file		FTextEncoder.h
 * @brief		This is the header file for the %Encoder class.
 *
 * This header file contains the declarations of the %Encoder class.
 *
 */
#ifndef _FTEXT_ENCODER_H_
#define _FTEXT_ENCODER_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseBuffer.h>

namespace Tizen { namespace Text
{
/**
 * @class	Encoder
 * @brief	This class is an implementation of the character encoder.
 *
 * @since	2.0
 *
 * The %Encoder class converts blocks of characters to blocks of encoded bytes
 * through successive calls to the GetBytesN() method. This class maintains the state consistency information between
 * successive calls to %GetBytesN(), enabling it to encode a character into a sequence of bytes,
 * such as surrogate pairs, that span adjacent blocks.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/text/converting_text_data_separate_blocks.htm">Converting Text Data in Separate Blocks</a>.
 */

class _OSP_EXPORT_ Encoder
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Encoder(void) { };

	/**
	 * Gets the total number of bytes that are required to encode a range of characters in the specified Tizen::Base::WcharBuffer instance.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	chars An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in] charCount The total number of characters to encode
	 * @param[in] flush Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *						else @c false
	 * @param[out]  byteCount The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE		 The value of an argument is outside the valid range defined by the method, or
	 *										   the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @see				Decoder::GetCharCount()
	 */
	virtual result GetByteCount(const Tizen::Base::WcharBuffer& chars,
		int charIndex, int charCount, int& byteCount, bool flush = false) const = 0;

	/**
	 * Encodes an instance of the specified Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *						else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last encoded byte plus one in the buffer and the starting position is zero.
	 * @param[in]	chars An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]   flush Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *				else @c false
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c chars is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see	      Decoder::GetCharsN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars, bool flush = false) const = 0;

	/**
	 * Encodes an instance of Tizen::Base::WcharBuffer into an instance of Tizen::Base::ByteBuffer as per the specified range.
	 *
	 * @since			2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer instance where the resultant encoded string is stored, @n
	 *					else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last encoded byte in the buffer and the starting position is zero.
	 * @param[in]	chars An instance of Tizen::Base::WcharBuffer to encode
	 * @param[in]	charIndex The index from where encoding begins in the Tizen::Base::WcharBuffer instance
	 * @param[in]   charCount The total number of characters to encode
	 * @param[in] flush Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *						else @c false
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE       The value of an argument is outside the valid range defined by the method, or
	 *                                         the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *                                         the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The pointer to the Tizen::Base::ByteBuffer instance is not terminated by a @c null character.
	 * @see	        Decoder::GetCharsN()
	 */
	virtual Tizen::Base::ByteBuffer* GetBytesN(const Tizen::Base::WcharBuffer& chars, int charIndex, int charCount,
		bool flush = false) const = 0;

protected:
	Encoder(void)
		: _pEncoderImpl(null){};
	friend class _EncoderImpl;
	class _EncoderImpl* _pEncoderImpl;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	Encoder(const Encoder& encoder);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	Encoder& operator =(const Encoder& encoder);
};

} } // Tizen::Text
#endif //_FTEXT_ENCODER_H_
