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
 * @file		FBaseColIEnumerator.h
 * @brief		This is the header file for the %IEnumerator interface.
 *
 * This header file contains the declarations of the %IEnumerator interface.
 *
 */
#ifndef _FBASE_COL_IENUMERATOR_H_
#define _FBASE_COL_IENUMERATOR_H_

#include <FBaseTypes.h>

namespace Tizen {namespace Base
{
class Object;
}}

namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface IEnumerator
 * @brief	This interface supports simple iteration over a collection.
 *
 * @since 2.0
 *
 * @remarks
 * An enumerator remains valid as long as the collection remains unchanged.
 * If changes are made to the collection, such as adding, modifying, or
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to GetCurrent(), MoveNext(), or Reset() fails and returns
 * E_INVALID_OPERATION.
 *
 * The %IEnumerator interface supports simple iteration over a collection.
 * One can only access the elements in a collection through %IEnumerator. The elements cannot be modified through this interface.
 *
 */
class _OSP_EXPORT_ IEnumerator
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IEnumerator(void) {}

	/**
	 * Gets the current object in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		The current object in the collection, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element
	 *									or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetLastResult()
	 */
	virtual Tizen::Base::Object* GetCurrent(void) const = 0;

	/**
	 * Moves %IEnumerator to the next element of the collection. @n
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

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEnumerator_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEnumerator_Reserved2(void) { }

}; // IEnumerator

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IENUMERATOR_H_
