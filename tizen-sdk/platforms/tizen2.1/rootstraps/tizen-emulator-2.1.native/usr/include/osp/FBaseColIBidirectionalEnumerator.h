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
 * @file		FBaseColIBidirectionalEnumerator.h
 * @brief		This is the header file for the %IBidirectionalEnumerator interface.
 *
 * This header file contains the declarations of the %IBidirectionalEnumerator interface.
 *
 */
#ifndef _FBASE_COL_IBIDIRECTIONAL_ENUMERATOR_H_
#define _FBASE_COL_IBIDIRECTIONAL_ENUMERATOR_H_

#include <FBaseColIEnumerator.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface IBidirectionalEnumerator
 * @brief	This interface supports a bidirectional iteration over a collection.
 *
 * @since 2.0
 *
 * @remarks
 * An enumerator remains valid as long as the collection remains unchanged.
 * If changes are made to the collection, such as adding, modifying, or
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to GetCurrent(), MoveNext(), MovePrevious(), Reset(), or ResetLast() fails (E_INVALID_OPERATION).
 *
 * The %IBidirectionalEnumerator interface supports a bidirectional iteration over a collection.
 *	One can only access the elements in a collection through %IBidirectionalEnumerator. The elements cannot be modified through this interface.
 */
class _OSP_EXPORT_ IBidirectionalEnumerator
	: public virtual IEnumerator
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IBidirectionalEnumerator(void) {}

	/**
	 * Moves %IBidirectionalEnumerator to the previous element of the collection. @n
	 * A call to the MovePrevious() method after the ResetLast() method positions the enumerator to the last element in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the front of the collection.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @see			Tizen::Base::Collection::IEnumerator::MoveNext()
	 * @see			ResetLast()
	 */
	virtual result MovePrevious(void) = 0;

	/**
	 * Positions the enumerator after the last element in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 * @see			Tizen::Base::Collection::IEnumerator::Reset()
	 * @see			MovePrevious()
	 */
	virtual result ResetLast(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBidirectionalEnumerator_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IBidirectionalEnumerator_Reserved2(void) { }

}; // IBidirectionalEnumerator

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IBIDIRECTIONAL_ENUMERATOR_H_
