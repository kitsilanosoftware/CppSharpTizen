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
 * @file		FBaseByteBuffer.h
 * @brief		This is the header file for the %ByteBuffer class.
 *
 * This header file contains the declarations of the %ByteBuffer class.
 */

#ifndef _FBASE_BYTE_BUFFER_H_
#define _FBASE_BYTE_BUFFER_H_

#include <FBaseBufferBase.h>
#include <FBaseBuffer.h>


namespace Tizen { namespace Base
{

/**
 * @class	ByteBuffer
 * @brief	This class provides a contiguous sequence of the @c byte (@c unsigned @c char) built-in type.
 *
 * @since 2.0
 *
 * The %ByteBuffer class provides a means of encapsulating a sequence of bytes in memory. It defines
 * methods to read and write all primitive built-in types (except @c bool), to and from a sequence of
 * bytes. These methods read the size of primitive type bytes from a @c byte sequence and
 * convert it to the actual primitive type.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/buffer.htm">Buffer</a>.
 *
 * @see		Tizen::Base::BufferBase
 *
 * The following example demonstrates how to use the %ByteBuffer class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::ByteBufferSample(void)
 *	{
 *		// Defines the maximum buffer size : capacity
 *		const int BUFFER_SIZE_MAX = 1024;
 *
 *		// Initializes a buf using the Construct method to the capacity
 *		ByteBuffer buf;
 *		buf.Construct(BUFFER_SIZE_MAX);
 *
 *		// Copies five values into the buf
 *		for (int i = 0; i < 5; i++)
 *		{
 *			byte b = 'A' + i;
 *
 *			// Writes byte b to the current position of the buf
 *			buf.SetByte(b); // The position is incremented by one
 *		}
 *		// The position is moved to 5
 *
 *		// Flips the buf
 *		buf.Flip();
 *		// Now, position = 0 and limit = 5        
 *
 *		// Reads bytes from the buf using "relative access method"
 *		while (buf.HasRemaining())
 *		{
 *			byte b;
 *
 *			// Reads byte b from the current position of the buf
 *			buf.GetByte(b); // The position is incremented by one
 *		}
 *
 *
 *		// Clears the buf
 *		buf.Clear();
 *		// The buf's position = 0 and limit = capacity
 *
 *		// Writes int values to the buf
 *		for (int i = 0; i < 5; i++)
 *		{
 *			// Writes int value at the current position
 *			buf.SetInt(i); // The position is incremented by sizeof(int)
 *		}
 *
 *		// Flips the buf
 *		buf.Flip();
 *		// Now, position = 0 and limit = sizeof(int) * 5
 *
 *		// Creates a new view, IntBuffer.
 *		// Capacity of intBuf = 5
 *		// The content of intBuf is from the buf's position to the buf's limit
 *		IntBuffer* pIntBuf = buf.AsIntBufferN();
 *
 *		// Tests whether the change in view buffer(IntBuffer) is visible in original buffer(ByteBuffer)
 *		pIntBuf->Set(4, 9);
 *
 *		// Reads int values from the buf using "absolute access method"
 *		for (int i = 0; i < 5; i++)
 *		{
 *			int out;
 *
 *			// Reads int value from the buf with the specified index.
 *			buf.GetInt((i * sizeof(int)), out);		// 0, 1, 2, 3, 9
 *													//  The position is not changed
 *		}
 *
 *		delete pIntBuf;
 *
 *	}
 *
 * @endcode
 */
class _OSP_EXPORT_ ByteBuffer
	: public BufferBase
{

public:
	/**
	 * The object is not fully constructed after this constructor is called.
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 *
	 * @remarks		After creating an instance of the %ByteBuffer class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see				Construct()
	 */
	ByteBuffer(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ByteBuffer(void);

	/**
	 * Initializes this instance of %ByteBuffer which is a view of the specified buffer. @n
	 * This is the copy constructor for the %ByteBuffer class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	buffer          The %ByteBuffer instance used to initialize new object
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the source buffer is not constructed.
	 * @see				ByteBuffer()
	 */
	result Construct(const ByteBuffer& buffer);

	/**
	 * Initializes this instance of %ByteBuffer with the specified @c capacity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		The number of elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *				                the specified @c capacity is negative.
	 * @see				ByteBuffer()
	 */
	result Construct(int capacity);

	/**
	* Initializes this instance of %ByteBuffer with the specified @c buffer which is shared with this instance.
	*
	* @since 2.0
	*
	* @return           An error code
	* @param[in]       pBuffer                The buffer which is shared
	* @param[in]       index                  The starting index of the buffer from where the first @c byte value is read
	* @param[in]       length                 The number of bytes to read from the given buffer @n This is a limit of this instance.
	* @param[in]       capacity               The capacity of this instance
	* @exception       E_SUCCESS           The method is successful.
	* @exception       E_INVALID_ARG     A specified input parameter is invalid, or
	*                                               the @c pBuffer is @c null.
	* @exception       E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure, or
	*                                               the @c index is larger than the @c length.
	*/
	result Construct(const byte *pBuffer, int index, int length, int capacity);

	/**
	 * Gets the reference to the byte value at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the @c byte value
	 * @param[in]	index	The index of the @c byte value in the calling %ByteBuffer instance @n
	 *						It must be less than the limit.
	 */
	byte& operator [](int index);

	/**
	 * Gets the byte value at the specified index of const object.
	 *
	 * @since 2.0
	 *
	 * @return		A value to the @c byte value
	 * @param[in]	index	The index of the @c byte value in the calling %ByteBuffer instance @n
	 *						It must be less than the limit.
	 */
	byte operator [](int index) const;

	/**
	 * Compares the two %ByteBuffer instances.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the input buffer is equal to the calling %ByteBuffer instance, @n
	 *				else @c false
	 * @param[in]	buffer	The %ByteBuffer instance to compare with the current instance
	 * @remarks		This method returns @c true only if the two buffers have the same number of
	 *						remaining elements, and the two sequences of remaining elements are equal
	 *						(considered independently, irrespective of their starting positions).
	 * @see				Equals()
	 */
	bool operator ==(const ByteBuffer& buffer) const;

	/**
	 * Checks whether the current instance and the specified instance of %ByteBuffer are not equal.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two objects are not the same, @n
	 *				else @c false
	 * @param[in]	buffer	The buffer to compare with the current instance
	 * @remarks		This method returns @c false only if the two buffers being compared have the same
	 *						number of remaining elements, and the two sequences of remaining elements are equal
	 *						(considered independently, irrespective of their starting positions).
	 * @see				Equals()
	 */
	bool operator !=(const ByteBuffer& buffer) const;

	/**
	 * Creates a new @c double buffer view for the content of the byte buffer.
	 *	
	 * @since 2.0
	 *
	 * @return		DoubleBuffer A pointer to the current position of the calling object
	 * @remarks		The content of the view buffer starts at the current position of the calling buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of this buffer divided by the size of @c double.
	 *				Any change to the byte buffer content is visible in the @c double buffer view, and vice versa.
	 */
	DoubleBuffer* AsDoubleBufferN(void) const;

	/**
	 * Creates a new @c float buffer view for the content of the byte buffer.
	 *
	 * @since 2.0	
	 *
	 * @return		FloatBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of the calling buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of the calling buffer divided by the size of @c float.
	 *				Any change to the byte buffer content is visible in the @c float buffer view, and vice versa.
	 */
	FloatBuffer* AsFloatBufferN(void) const;

	/**
	 * Creates a new @c int buffer view for the content of the byte buffer.
	 *
	 * @since 2.0	
	 *
	 * @return		IntBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of the calling buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of calling buffer divided by the size of @c int.
	 *				Any change to the byte buffer content is visible in the Int buffer view, and vice versa.
	 */
	IntBuffer* AsIntBufferN(void) const;

	/**
	 * Creates a new @c long buffer view for the content of the byte buffer.
	 *
	 * @since 2.0	
	 *
	 * @return		LongBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the @c long buffer view, and vice versa.
	 */
	LongBuffer* AsLongBufferN(void) const;

	/**
	 * Creates a new @c long @c long buffer view for the content of the byte buffer.
	 *
	 * @since 2.0	
	 *
	 * @return		LongLongBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the @c long @c long buffer view, and vice versa.
	 */
	LongLongBuffer* AsLongLongBufferN(void) const;

	/**
	 * @if OSPDEPREC
	 * Creates a new @c mchar buffer view of the underlying content of the byte buffer.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the AsWcharBufferN() method.
	 * @since 2.0	
	 *
	 * @return		McharBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of the calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the @c mchar buffer view, and vice versa.
	 * @endif
	 */
	McharBuffer* AsMcharBufferN(void) const;

	/**
	 * Creates a new wchar Buffer view of the underlying content of the byte buffer.
	 *
	 * @since 2.0
	 *
	 * @return		WcharBuffer pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer start at the current position of this buffer. @n
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of the calling buffer divided by the size of @c long. @n
	 *				Any changes to the calling buffer's content (that is, the content of %ByteBuffer instance) @n
	 *				are visible in the WcharBuffer view, and vice versa.
	 */
	WcharBuffer* AsWcharBufferN(void) const;

	/**
	 * Creates a new @c short buffer view for the content of the byte buffer.
	 *
	 * @since 2.0
	 *
	 * @return		ShortBuffer pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit
	 *				are equal to the remaining part of calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the @c short buffer view, and vice versa.
	 */
	ShortBuffer* AsShortBufferN(void) const;

	/**
	 * Copies the remaining bytes of the input %ByteBuffer instance into the calling %ByteBuffer object. @n
	 * It returns E_OVERFLOW if the remaining bytes in the current instance are less
	 * than the remaining bytes in the input instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	buffer		The source buffer from which bytes are read @n
	 *							It must not be the calling object.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The source buffer is same as destination buffer,
	 *								that is, the current instance of the buffer.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow. @n
	 *								The number of remaining bytes of the current buffer is smaller than
	 *								the number of remaining bytes of the input buffer.
	 * @remarks		After the copy operation, the current (destination) buffer's position and the given
	 *				(source) buffer's positions are incremented by the number of bytes copied (the number of
	 *				remaining bytes of the given buffer). @n
	 *				If the remaining part of the current instance is greater than or equal to the remaining part of the input instance,
	 *				the effect of this method and the ReadFrom(%ByteBuffer) method is the same. But when the remaining part of the
	 *				current instance is less, the ReadFrom() method copies the number of remaining elements of the current
	 *				instance while this method returns E_OVERFLOW and does not copy.
	 * @see			ReadFrom()
	 *
	 * The following example demonstrates how to use the %CopyFrom() method.
	 *
	 * @code
	 *
	 *	// Creates instances of ByteBuffer to act as source and destination buffers
	 *	ByteBuffer srcBuf;
	 *	ByteBuffer destBuf;
	 *
	 *	// Declares an array of byte values
	 *	byte pArray[] = {'A','B','C','D','E','F','G','H','I','J'};
	 *
	 *	// Initializes the source array with a capacity of ten elements.
	 *	srcBuf.Construct(10);
	 *
	 *	// Copies the ten values from pArray starting at position 0 to the srcBuf
	 *	// Now, srcBuf's position = 10
	 *	srcBuf.SetArray(pArray, 0, 10);
	 *
	 *	// Flips the buffer: The limit is set to the current position and
	 *	// then the position is set to zero
	 *	srcBuf.Flip();			// srcBuf's position = 0 and limit = 10
	 *
	 *
	 *	destBuf.Construct(20);
	 *
	 *	// Copies from the srcBuf to the destBuf
	 *	// Now, srcBuf's position = 10, the destBuf's position = 10
	 *	destBuf.CopyFrom(srcBuf);
	 *
	 * @endcode
	 *
	 * The following example has exactly the same effect as the above %CopyFrom() method.
	 *
	 * @code
	 *	
	 *	int copyNum = srcBuf.GetRemaining();
	 *	for (int i = 0; i < copyNum; i++)
	 *	{
	 *		byte b;
	 *
	 *		// Reads from source buffer
	 *		srcBuf.GetByte(b);			// The srcBuf position is incremented by 1
	 *
	 *		// Writes to destination buffer
	 *		destBuf.SetByte(b);			// The destBuf position is incremented by 1
	 *
	 *	}
	 * @endcode
	 */
	result CopyFrom(ByteBuffer& buffer);

	/**
	 * Gets the specified number of bytes from the current instance of %ByteBuffer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	pArray		A pointer to the destination array into which the bytes are written
	 * @param[in]	index		The starting index in the array of the first byte to write
	 * @param[in]	length		The number of bytes to write to the given array
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c pArray is @c null.
	 * @exception	E_OUT_OF_RANGE	A specified input parameter is invalid. @n
	 *								The @c index or @c length is less than @c 0.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the remaining bytes of this buffer are smaller than @c length.
	 * @remarks		This method copies @c length bytes from the current instance of %ByteBuffer to the given array,
	 *				starting at the current position and at the given index in the array.
	 *				After the copy operation, the position is incremented by @c length bytes.
	 * @see			SetArray()
	 */
	result GetArray(byte* pArray, int index, int length);

	/**
	 * Gets the @c byte value from the buffer at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c byte value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the current position is not smaller than the limit.
	 * @see			SetByte()
	 */
	result GetByte(byte& value);

	/**
	 * Gets the @c byte value at the given index. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of the current %ByteBuffer instance, from which the byte is read
	 * @param[out]	value 		The @c byte value at the given @c index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or
	 *								the @c index is not smaller than the limit or less than @c 0.
	 * @see			SetByte()
	 */
	result GetByte(int index, byte& value) const;

	/**
	 * Gets the size of @c double number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c double equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c double value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c double.
	 * @remarks		This method reads the next size of @c double number of bytes at the current position,
	 *				composing it into a @c double value, and then increments the position by the size of @c double.
	 * @see			SetDouble()
	 */
	result GetDouble(double& value);

	/**
	 * Gets the size of @c double number of bytes at the given index and converts it to the equivalent @c double value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value		The @c double value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c double or less than @c 0.
	 * @remarks		This method reads size of @c double number of bytes at the given index,
	 *				composing them into a @c double value.
	 * @see			SetDouble()
	 */
	result GetDouble(int index, double& value) const;

	/**
	 * Gets the size of @c float number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c float equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c float value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c float.
	 * @remarks		This method reads the next size of @c float number of bytes at the current position,
	 *				composing it into a @c float value, and then increments the position by the size of @c float.
	 * @see			SetFloat()
	 */
	result GetFloat(float& value);

	/**
	 * Gets the size of @c float number of bytes at the given index and converts it to equivalent @c float value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c float value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c float or less than @c 0.
	 * @remarks		This method reads the size of @c float number of bytes at the given index,
	 *				composing it into a @c float value.
	 * @see			SetFloat()
	 */
	result GetFloat(int index, float& value) const;

	/**
	 * Gets the size of @c int number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c int equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c int value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c int.
	 * @remarks		This method reads the next size of @c int number of bytes at the current position,
	 *				composing them into an @c int value, and then increments the position by the size of @c int.
	 * @see			SetInt()
	 */
	result GetInt(int& value);

	/**
	 * Gets the size of @c int number of bytes at the given index and converts it to the equivalent @c int value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c int value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c int or negative.
	 * @remarks		This method reads the size of @c int number of bytes at the given index,
	 *				composing it into an @c int value.
	 * @see			SetInt()
	 */
	result GetInt(int index, int& value) const;

	/**
	 * Gets the size of @c long number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c long equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c long value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c long.
	 * @remarks		This method reads the next size of @c long number of bytes at the current position,
	 *				composing it into a @c long value, and then increments the position by the size of @c long.
	 * @see			SetLong()
	 */
	result GetLong(long& value);

	/**
	 * Gets the size of @c long number of bytes at the given index and converts it to equivalent @c long value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c long value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c long or less than @c 0.
	 * @remarks		This method reads the size of @c long number of bytes at the given index,
	 *				composing it into a @c long value.
	 * @see			SetLong()
	 */
	result GetLong(int index, long& value) const;

	/**
	 * Gets the size of @c long @c long number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c long @c long equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c long @c long value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c long @c long.
	 * @remarks		This method reads the next size of @c long @c long number of bytes at the current position,
	 *				composing it into a @c long @c long value, and then increments the position by the size of @c long @c long.
	 * @see			SetLongLong()
	 */	
	result GetLongLong(long long& value);

	/**
	 * Gets the size of @c long @c long number of bytes at the given index and converts it to the equivalent @c long @c long value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c long @c long value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c long @c long or less than @c 0.
	 * @remarks		This method reads the size of @c long @c long number of bytes at the given index,
	 *				composing it into a @c long @c long value.
	 * @see			SetLongLong()
	 */
	result GetLongLong(int index, long long& value) const;

	/**
	 * @if OSPDEPREC
	 * Gets the size of @c wchar_t number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c wchar_t equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the GetWchar(wchar_t& value) method.
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value       The @c wchar_t value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c wchar_t.
	 * @remarks		This method reads the next size of @c wchar_t number of bytes at the current position,
	 *				composing it into a @c wchar_t value, and then increments the position by the size of @c wchar_t.
	 * @see			SetMchar()
	 * @endif
	 */
	result GetMchar(wchar_t& value);

	/**
	 * Gets the size of @c wchar_t number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c wchar_t equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return 	An error code
	 * @param[out]	value       The @c wchar_t value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_UNDERFLOW          The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *                                                   		the remaining bytes of this buffer are smaller than the size of @c wchar_t.
	 * @remarks      	This method reads the next size of @c wchar_t number of bytes at the current position,
	 *                   		composing it into a @c wchar_t value, and then increments the position by the size of @c wchar_t.
	 * @see			SetWchar()
	 */
	result GetWchar(wchar_t& value);

	/**
	 * @if OSPDEPREC
	 * Provides a way for absolute indexing and reading. @n
	 * It reads the size of @c wchar_t number of bytes at the given index and converts it to equivalent @c wchar_t value.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the GetWchar(int index, wchar_t& value) method.
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index       The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value       The @c wchar_t value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c wchar_t or less than @c 0.
	 * @remarks		This method reads the size of @c wchar_t number of bytes at the given index,
	 *				composing it into a @c wchar_t value.
	 * @see			SetMchar()
	 * @endif
	 */
	result GetMchar(int index, wchar_t& value) const;

	/**
	 * Provides a way for absolute indexing and reading. @n
	 * It reads the size of @c wchar_t number of bytes at the given index and converts it to equivalent @c wchar_t value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index      The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value      The @c wchar_t value at the given index
	 * @exception	E_SUCCESS        		The method is successful.
	 * @exception	E_OUT_OF_RANGE          	The specified index is outside the bounds of the data structure, or
	 *                                                   			the @c index is larger than the limit minus size of @c wchar_t or less than @c 0.
	 * @remarks      	This method reads the size of @c wchar_t number of bytes at the given index,
	 *                   		composing it into a @c wchar_t value.
	 * @see			SetWchar()
	 */
	result GetWchar(int index, wchar_t& value) const;

	/**
	 * Gets the size of @c short number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c short equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value 		The @c short value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c short.
	 * @remarks		This method reads the next size of @c short number of bytes at the current position,
	 *				composing it into a @c short value, and then increments the position by the size of @c short.
	 * @see			SetShort()
	 */
	result GetShort(short& value);

	/**
	 * Gets the size of @c short number of bytes at the given index and converts it to the equivalent @c short value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c short value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c short or less than @c 0.
	 * @remarks		This method reads the size of @c short number of bytes at the given index,
	 *				composing it into a @c short value.
	 * @see			SetShort()
	 */
	result GetShort(int index, short& value) const;

	/**
	 * Copies the remaining bytes of the input %ByteBuffer instance into the calling %ByteBuffer instance
	 * if the remaining part of the current instance is greater than or equal to the remaining part of the input instance. @n
	 * Otherwise, the number of bytes copied is equal to the number of remaining elements of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	buffer		The source buffer from which bytes are read @n
	 *							It must not be the calling %ByteBuffer instance.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *								
	 * @remarks		After the copy operation, the current (destination) buffer's position and the given
	 *				(source) buffer's position are	incremented by the number of elements copied (the lesser of
	 *				the number of elements remaining in the current buffer and the given buffer). @n
	 *				If the remaining part of the current instance is greater than or equal to the remaining part of the input instance,
	 *				the effect of this method is the same as the CopyFrom() method. But when the remaining part of the
	 *				current instance is less, the CopyFrom() method returns E_OVERFLOW and does not transfer;
	 *				whereas this method copies the number of remaining elements of the current instance.
	 * @see			CopyFrom()
	 *
	 * The following example demonstrates how to use the %ReadFrom() method.
	 *
	 * @code
	 *
	 *	// Creates instances of %ByteBuffer to act as source and destination buffers
	 *	ByteBuffer srcBuf;
	 *	ByteBuffer destBuf;
	 *
	 *	// Declares an array of byte values
	 *	byte pArray[] = {'A','B','C','D','E','F','G','H','I','J'};
	 *
	 *	// Initializes the source array with capacity of ten elements.
	 *	srcBuf.Construct(10);
	 *
	 *	// Copies the 10 values from pArray starting at position 0 to srcBuf
	 *	// Now, srcBuf's position = 10
	 *	srcBuf.SetArray(pArray, 0, 10);
	 *
	 *	// Flips the buffer: The limit is set to the current position and
	 *	// then the position is set to zero
	 *	srcBuf.Flip();	// srcBuf's position = 0 and limit = 10
	 *
	 *	// Initializes the destination buffer with capacity of ten elements
	 *	destBuf.Construct(10);
	 *
	 *	// Sets the limit of destBuf to 5
	 *	destBuf.SetLimit(5);
	 *
	 *	// Reads from the srcBuf to the destBuf
	 *	// The destBuf's remaining is 5, smaller than the srcBuf's (10)
	 *	// Therefore, five elements are transferred
	 *	// srcBuf's position = 5, destBuf's position = 5
	 *	destBuf.ReadFrom(srcBuf);
	 *
	 *
	 * @endcode
	 *
	 * The following example has exactly the same effect as the above %ReadFrom() method.
	 *
	 * @code
	 *
	 *	int copyNum = (destBuf.GetRemaining() < srcBuf.GetRemaing())? destBuf.GetRemaining() : srcBuf.GetRemaining();
	 *	for (int i = 0; i < copyNum; i++)
	 *	{
	 *		byte b;
	 *
	 *		// Reads from the source buffer
	 *		srcBuf.GetByte(b); // The srcBuf position is incremented by 1
	 *
	 *		// Writes to the destination buffer
	 *		destBuf.SetByte(b);	// The destBuf position is incremented by 1
	 *
	 *	}
	 *
	 * @endcode
	 */
	result ReadFrom(ByteBuffer& buffer);

	/**
	 * Sets the @c byte values on the specified array to the current instance of %ByteBuffer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pArray		The array from which bytes are read
	 * @param[in]	index		The starting index of the array from where the first @c byte value is read
	 * @param[in]	length		The number of bytes to read from the given array
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c pArray is @c null.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or
	 *								the @c index or length is less than @c 0.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes are smaller than @c length.
	 * @remarks		This method copies the specified number (@c length) of @c byte values into
	 *				the calling object of buffer from the source array,
	 *				starting from the current position, and at the given index in the array.
	 *				After the copy operation, the position is incremented by @c length.
	 * @see			GetArray()
	 */
	result SetArray(const byte* pArray, int index, int length);

	/**
	 * Sets the given @c byte value into the calling %ByteBuffer object
	 * at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c byte value to write to the current instance of %ByteBuffer
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the current position is not smaller than the limit.
	 * @see			GetByte()
	 */
	result SetByte(byte value);

	/**
	 * Sets the given @c byte value into the calling %ByteBuffer object at the specified index. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of the current instance of %ByteBuffer at which the byte is written
	 * @param[in]	value		The @c byte value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is not smaller than the limit or less than @c 0.
	 * @see			GetByte()
	 */
	result SetByte(int index, byte value);

	/**
	 * Sets the given @c double value into the calling %ByteBuffer object
	 * at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c double value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c double.
	 * @remarks		This method writes the size of @c double number of bytes containing the given @c double value
	 *				into the calling buffer, at the current position, and then increments the position by the size of @c double.
	 * @see			GetDouble()
	 */
	result SetDouble(double value);

	/**
	 * Sets the given @c float value into the calling %ByteBuffer object
	 * at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c float value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c float.
	 * @remarks		This method writes the size of @c float number of bytes containing the given @c float value
	 *				into this buffer at the current position, and then increments the position by the size of @c float.
	 * @see			GetFloat()
	 */
	result SetFloat(float value);

	/**
	 * Sets the given @c int value into the calling %ByteBuffer instance at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value	The @c int value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c int.
	 * @remarks		This method writes the size of @c int number of bytes containing the given @c int value
	 *				into this buffer at the current position, and then increments the position by the size of @c int.
	 * @see			GetInt()
	 */
	result SetInt(int value);

	/**
	 * Sets the given @c long value into the calling %ByteBuffer instance at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c long value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than size of @c long.
	 * @remarks		This method writes the size of @c long number of bytes containing the given @c long value
	 *				into this buffer at the current position, and then increments the position by the size of @c long.
	 * @see			GetLong()
	 */
	result SetLong(long value);

	/**
	 * Sets the given @c long @c long value into the calling %ByteBuffer object at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c long @c long value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c long @c long.
	 * @remarks		This method writes the size of @c long @c long number of bytes containing the given @c long @c long value
	 *				into this buffer at the current position, and then increments the position by the size of @c long @c long.
	 * @see			GetLongLong()
	 */
	result SetLongLong(long long value);

	/**
	 * @if OSPDEPREC
	 * Sets the given @c wchar_t value into the calling %ByteBuffer object at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the SetWchar(wchar_t value) method.
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c wchar_t value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than size of @c wchar_t.
	 * @remarks		This method writes the size of @c wchar_t number of bytes containing the given @c wchar_t value
	 *				into this buffer at the current position, and then increments the position by the size of @c wchar_t.
	 * @see			GetMchar()
	 * @endif
	 */
	result SetMchar(wchar_t value);

	/**
	 * Sets the given @c wchar_t value into the calling %ByteBuffer object at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value    		The @c wchar_t value to write
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_OVERFLOW     	The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *                                       			the remaining bytes of this buffer are smaller than size of @c wchar_t.
	 * @remarks      	This method writes the size of @c wchar_t number of bytes containing the given @c wchar_t value
	 *                  		into this buffer at the current position, and then increments the position by the size of @c wchar_t.
	 * @see			GetWchar()
	 */
	result SetWchar(wchar_t value);

	/**
	 * Sets the given @c short value into the current instance of %ByteBuffer at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	value		The @c short value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c short.
	 * @remarks		This method writes the size of @c short number of bytes containing the given @c short value
	 *				into this buffer at the current position, and then increments the position by the size of @c short.
	 * @see			GetShort()
	 */
	result SetShort(short value);

	/**
	 * Sets a @c double value at the specified index of the current instance of %ByteBuffer. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of current instance of %ByteBuffer at which the bytes are written
	 * @param[in]	value		The @c double value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c double or less than @c 0.
	 * @remarks		This method writes the size of @c double number of bytes containing the given @c double value
	 *				into this buffer at the given index.
	 * @see			GetDouble()
	 */
	result SetDouble(int index, double value);

	/**
	 *  Sets a @c float value at the specified index of the calling %ByteBuffer object. @n
	 *  Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of current instance of %ByteBuffer at which the bytes are written
	 * @param[in]	value		The @c float value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c float or less than @c 0.
	 * @remarks		This method writes the size of @c float number of bytes containing the given @c float value
	 *				into this buffer at the given index.
	 * @see			GetFloat()
	 */
	result SetFloat(int index, float value);

	/**
	 * Sets a @c int value at the specified index of the calling %ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of current instance of %ByteBuffer at which the bytes are written
	 * @param[in]	value		The @c int value to write
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c int or less than @c 0.
	 * @remarks		This method writes the size of @c int number of bytes containing the given @c int value
	 *				into this buffer at the given index.
	 * @see			GetInt()
	 */
	result SetInt(int index, int value);

	/**
	 * Sets a @c long value at the specified index of the calling %ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index at which the bytes are written
	 * @param[in]	value		The @c long value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c long or less than @c 0.
	 * @remarks		This method writes size of @c long number of bytes containing the given @c long value
	 *				into this buffer at the given index.
	 * @see			GetLong()
	 */
	result SetLong(int index, long value);

	/**
	 * Sets a @c long @c long value at the specified index of the calling %ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index at which the bytes will be written
	 * @param[in]	value		The @c long @c long value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c long @c long or less than @c 0.
	 * @remarks		This method writes the size of @c long @c long number of bytes containing the given @c long @c long value
	 *				into this buffer at the given index.
	 * @see			GetLongLong()
	 */
	result SetLongLong(int index, long long value);

	/**
	 * @if OSPDEPREC
	 * Sets a @c wchar_t value at the specified index of the calling %ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as @c mchar type is changed to @c wchar_t type.
	 * Instead of using this method, use the SetWchar(int index, wchar_t value) method.
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index at which the bytes will be written
	 * @param[in]	value		The @c wchar_t value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c wchar_t or less than @c 0.
	 * @remarks		This method writes the size of @c wchar_t number of bytes containing the given @c wchar_t value
	 *				into this buffer at the given index.
	 * @see			GetMchar()
	 * @endif
	 */
	result SetMchar(int index, wchar_t value);

	/**
	 * Sets a @c wchar_t value at the specified index of the calling %ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index    		The index at which the bytes will be written
	 * @param[in]	value    		The @c wchar_t value to write
	 * @exception	E_SUCCESS        		The method is successful.
	 * @exception	E_OUT_OF_RANGE          	The specified index is outside the bounds of the data structure, or
	 *                                                   			the @c index is larger than the limit minus the size of @c wchar_t or less than @c 0.
	 * @remarks      	This method writes the size of @c wchar_t number of bytes containing the given @c wchar_t value
	 *                   		into this buffer at the given index.
	 * @see			GetWchar()
	 */
	result SetWchar(int index, wchar_t value);

	/**
	 * Sets a @c short value at the specified index of the calling %ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of at which the bytes are written
	 * @param[in]	value		The @c short value to write
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c short or less than @c 0.
	 * @remarks		This method writes the size of @c short number of bytes containing the given @c short value
	 *				into this buffer at the given index.
	 * @see			GetShort()
	 */
	result SetShort(int index, short value);

	/**
	 * Creates a new %ByteBuffer whose content is a shared portion of
	 * the content of the calling %ByteBuffer object.
	 *
	 * @since 2.0
	 *
	 * @return		%ByteBuffer pointer to the current position of the calling object
	 * @remarks		The content of the new buffer starts at the current position of the calling %ByteBuffer object.
	 *				The new buffer's position is zero, its capacity and limit are
	 *				the number of bytes remaining of the current instance of %ByteBuffer,
	 *				and its mark is undefined.
	 */
	ByteBuffer* SliceN(void) const;

	/**
	 * Gets the pointer to the raw array of the calling buffer. @n
	 * If the capacity is zero, it returns @c null.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the raw array of the calling buffer
	 */
	const byte* GetPointer(void) const;

	/**
	 * Gets the pointer to the raw array of the calling buffer. @n
	 * If the capacity is zero, it returns @c null.
	 *
	 * @since 2.1
	 *
	 * @return		A pointer(non-const) to the raw array of the calling buffer
	 */
	byte* GetPointer(void);

	/**
	 * Compares the input Object with the calling %ByteBuffer instance.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the input object equals the calling %ByteBuffer instance, @n
	 *				else @c false
	 * @param[in]	obj	The object instance to compare with the calling object
	 * @remarks		This method returns @c true only if the specified object is also an instance of
	 *				the %ByteBuffer class, the two buffers have the same number of remaining elements, and the two
	 *				sequences of remaining elements are equal (considered independent of their starting positions).
	 * @see			Tizen::Base::BufferBase::GetHashCode()
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 *	Gets the hash value of the current instance.
	 *
	 *	@since 2.0
	 *
	 *	@return		The hash value of the current instance
	 *	@remarks    	The hash code of a buffer depends only upon its remaining elements.
	 */
	virtual int GetHashCode(void) const;

private:
	/**
	 * This copy constructor is intentionally declared as private to prohibit copying of objects by users.
	 */
	ByteBuffer(const ByteBuffer& buffer)
		:__pByteBufferImpl(null)
	{
		Construct(buffer);
	}

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ByteBuffer& operator =(const ByteBuffer& buffer);

	/**
	 * Returns the size of byte(1).
	 *
	 * @return		The size of byte(1)
	 */
	virtual int GetTypeSize(void) const;


	friend class _ByteBufferImpl;
	class _ByteBufferImpl * __pByteBufferImpl;

}; // ByteBuffer

}} // Tizen::Base

#endif // _FBASE_BYTE_BUFFER_H_
