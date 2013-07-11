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
 * @file		FBaseBufferBase.h
 * @brief		This is the header file for the %BufferBase class.
 *
 * This header file contains the declarations of the %BufferBase class.
 */

#ifndef _FBASE_BUFFER_BASE_H_
#define _FBASE_BUFFER_BASE_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseRtMutex.h>

namespace Tizen { namespace Base
{

/**
 * @enum PositionTo
 *
 * Defines position.
 *
 * @since 2.0
 */
enum PositionTo
{
	POSITION_TO_ZERO = 0,   /**< The position is set to zero */
	POSITION_TO_MARK = 1,   /**< The position is set to the mark */
};


/**
 * @class	BufferBase
 * @brief	This class is the abstract base class of all buffer classes.
 *
 * @since 2.0
 *
 * The %BufferBase class is the abstract base class of all buffer classes.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/buffer.htm">Buffer</a>.
 *
 * @see		Tizen::Base::ByteBuffer, Tizen::Base::Buffer< Type >
 */

class _OSP_EXPORT_ BufferBase
	: public Object
{

// Forward declaration
protected:
	class _BufferData;

public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~BufferBase(void);

	/**
	 * Clears the calling %BufferBase object. @n
	 * The buffer's position is set to @c 0, the limit is set to the capacity, and the mark is discarded.
	 *
	 * @since 2.0
	 */
	void Clear(void);

	/**
	 * Copies the elements between the current position and limit (that are also known as remaining
	 * elements), to the beginning of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @remarks		After copying, the position is set to the number of elements copied rather than to @c 0,
	 *				so that an invocation of this method can be followed immediately by an invocation
	 *				of another relative set method. The limit is set to the capacity, and the mark is discarded.
	 */
	void Compact(void);

	/**
	 * Flips the calling %BufferBase instance. @n
	 * It sets the limit to the current position
	 * and sets the position to either @c 0 or the mark, depending on the input value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	    to    The value to set the buffer position @n
	 *                        The parameter may contain @c POSITION_TO_ZERO or @c POSITION_TO_MARK.
	 * @remarks		If @c to is POSITION_TO_ZERO (or unspecified), the position is set to @c 0 after setting a limit to
	 *				the current position, and the mark is discarded.
	 *				Otherwise, if @c to is POSITION_TO_MARK, the position is set to the mark and
	 *				the mark is not discarded. If the mark is undefined, the position is set to @c 0.
	 *
	 * The following example demonstrates how to use the %Flip() method.
	 *
	 * @code
	 *
	 *	ByteBuffer buf;
	 *	buf.Construct(10);				// buf's position is zero, limit is 10, and mark is undefined.
	 *
	 *	buf.SetPosition(7);				// Now, buf's position is 7 (limit and mark is unchanged).
	 *
	 *	buf.Flip();						// equal to "buf.Flip(POSITION_TO_ZERO)"
	 *									// buf's position : 0, limit : 7, mark is still undefined.
	 *
	 *	buf.SetPosition(3);
	 *	buf.SetMark();					// Both buf's position and mark are 3.
	 *
	 *	buf.SetPosition(5);				// buf's position is 5, limit is 7, and mark is 3.
	 *
	 *	buf.Flip(POSITION_TO_MARK);		// Now, buf's position is 3, and limit and mark are unchanged.
	 *
	 * @endcode
	 */
	void Flip(PositionTo to = POSITION_TO_ZERO);

	/**
	 * Gets the hash value of the calling object.
	 *
	 * @since 2.0
	 *
	 * @return		The hash value of the calling object
	 * @remarks     The hash code of a buffer depends only upon its remaining elements.
	 * @see			Tizen::Base::Object::Equals()
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Invalidates the mark of the calling instance of %BufferBase (set to @c -1).
	 *
	 * @since 2.0
	 *
	 * @see			SetMark()
	 */
	void InvalidateMark(void);

	/**
	 * Resets the position of the calling %BufferBase object to the previously marked position.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.@n
	 *									The mark has not been set.
	 * @remarks		Invoking this method neither changes nor discards the mark's value.
	 */
	result Reset(void);

	/**
	 * Rewinds the current instance of %BufferBase. @n
	 * It sets the position to
	 * @c 0, discards the mark, and leaves the limit unchanged.
	 *
	 * @since 2.0
	 */
	void Rewind(void);

	/**
	 * Shifts the limit of the current instance of %BufferBase. @n
	 * The new limit is the current limit plus the given amount.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	amount	The quantity of shift needed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of an argument is outside the valid range defined by the method. @n
	 *									The @c amount is larger than the capacity or smaller than @c 0 starting from the current limit.
	 * @remarks		If the position is larger than the new limit, it is set to the new limit.
	 *				If the mark is defined and larger than the new limit, it is discarded.
	 * @see			SetLimit()
	 */
	result ShiftLimit(int amount);

	/**
	 * Gets the capacity of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @return		The capacity of the calling object
	 */
	int GetCapacity(void) const;


	/**
	 * Gets the limit of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @return		The limit of the calling object
	 * @see				SetLimit()
	 */
	int GetLimit(void) const;


	/**
	 * Gets the mark of the calling %BufferBase instance. @n
	 * If the mark has not been set, it returns @c -1.
	 *
	 * @since 2.0
	 *
	 * @return		The mark of the calling %BufferBase instance
	 * @see				SetMark()
	 */
	int GetMark(void) const;


	/**
	 * Gets the current position of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @return		The current position of the calling %BufferBase instance
	 * @see				SetPosition()
	 */
	int GetPosition(void) const;


	/**
	 * Gets the number of elements between the current position and the limit
	 * of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of elements between the current position and the limit
	 * @see				HasRemaining()
	 */
	int GetRemaining(void) const;


	/**
	 * Sets the limit of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	limit	The new limit
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		 The value of an argument is outside the valid range defined by the method. @n
	 *									The @c limit is larger than the capacity or less than @c 0.
	 * @remarks		If the position is larger than the new limit, it is set to the new limit.
	 *				If the mark is defined and larger than the new limit, it is discarded.
	 * @see			GetLimit()
	 */
	result SetLimit(int limit);


	/**
	 * Sets the mark of the current instance of %BufferBase at the current position. @n
	 * If this method is called after InvalidateMark(), the mark is set to @c -1.
	 *
	 * @since 2.0
	 *
	 * @see			GetMark()
	 */
	void SetMark(void);


	/**
	 * Sets the position of the calling %BufferBase instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	position	The new position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		 The value of an argument is outside the valid range defined by the method. @n
	 *									The @c position is larger than the current limit or less than @c 0.
	 * @remarks		If the mark is defined and larger than the new position then it is discarded.
	 * @see			GetPosition()
	 */
	result SetPosition(int position);

	/**
	 * Returns @c true if there is at least one element between the current position and
	 * the limit of the current instance of %BufferBase. Otherwise, it returns @c false.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if there is at least one element between the current position and the limit of the current instance of %BufferBase, @n
	 *				 else @c false
	 * @see				GetRemaining()
	 */
	bool HasRemaining(void) const;

	/**
	 * Expands the capacity and the limit of the internal buffer with the specified capacity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity of this instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c capacity is less than the current capacity.
	 * @remarks		After calling this method, the address of the internal buffer may be either the same or a new location.
	 */
	result ExpandCapacity(int newCapacity);

protected:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction,
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	BufferBase(void);

	/**
	 * Initializes this instance of %BufferBase with the specified capacity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The number of elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								  The @c capacity is negative.
	 */
	result Construct(int capacity);

	/**
	 * Increments the reference count by one.
	 *
	 * @since 2.0
	 */
	long AddRef(void) const;


	/**
	 * Decrements the reference count by one.
	 *
	 * @since 2.0
	 *
	 * @return		The reference count after decrement
	 */
	long Release(void) const;

	/**
	 * Decreases the reference count. @n
	 * After that, it frees the resource (memory allocation) if the reference count is zero.
	 *
	 * @since 2.0
	 */
	virtual void Dispose(void);

	/*
	 * @class		_BufferData
	 * @brief		This class encapsulates the @c byte array used by the buffer classes.
	 *
	 * @since 2.0
	 *
	 */
	class _BufferData
	{
	public:
		//
		//  This is the default constructor for this class.
		//
		//  @since 2.0
		//
		_BufferData(void);

		//
		//  This is the destructor for this class.
		//
		// @since 2.0
		//
		virtual ~_BufferData(void);

		//
		// Gets the pointer to the byte array.
		//
		// @since 2.0
		// @return		Pointer to the @c byte array
		//
		byte* GetArray(void);


		// Attribute
		unsigned long long capacityInByte;
		long refCount;

	}; // _BufferData


	int _capacity;
	int _position;
	int _limit;
	int _mark;
	_BufferData* _pData;
	byte* __pArrayStart;


private:
	/**
	 * Returns the size of the type of the current %BufferBase instance.
	 *
	 * @return		The size of the type of the current %BufferBase instance
	 */
	virtual int GetTypeSize(void) const = 0;

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	BufferBase(const BufferBase& obj);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	BufferBase& operator =(const BufferBase& rhs);

	friend class _BufferBaseImpl;
	class _BufferBaseImpl * __pBufferBaseImpl;

}; // BufferBase

}} // Tizen::Base

#endif // _FBASE_BUFFER_BASE_H_
