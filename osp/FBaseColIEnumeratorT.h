//
// Open Service Platform
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
 * @file		FBaseColIEnumeratorT.h
 * @brief		This is the header file for the %IEnumeratorT interface.
 *
 * This header file contains the declarations of the %IEnumeratorT interface.
 *
 */
#ifndef _FBASE_COL_IENUMERATOR_T_H_
#define _FBASE_COL_IENUMERATOR_T_H_

#include <FBaseTypes.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface IEnumeratorT
 * @brief	This interface supports simple iteration over a template-based collection.
 *
 * @since 2.0
 *
 * @remarks
 * An enumerator remains valid as long as the collection remains unchanged.
 * If changes are made to the collection, such as adding, modifying, or
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to GetCurrent(), MoveNext(), or Reset() fails and returns
 * E_INVALID_OPERATION.
 *
 * The %IEnumeratorT interface supports simple iteration over a template-based collection.
 * One can only access the elements in a collection through %IEnumeratorT. The elements cannot be modified through this interface.
 *
 */
template< class Type >
class IEnumeratorT
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IEnumeratorT(void) {}

	/**
	 * Gets the current object in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj A pointer to the current object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The enumerator is currently positioned before the first element or
	 *									after the last element or the collection is modified after the enumerator is created.
	 */
	virtual result GetCurrent(Type& obj) const = 0;

	/**
	 * Moves %IEnumeratorT to the next element of the collection. @n
	 * After the enumerator is first created or reset using the Reset() method,
	 * the first call to this method positions the enumerator to the first element in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the collection.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 * @see			Reset()
	 */
	virtual result MoveNext(void) = 0;

	/**
	 * Positions the enumerator before the first element in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 */
	virtual result Reset(void) = 0;

}; // IEnumeratorT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IENUMERATOR_T_H_
