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
 * @file		FBaseColIMapEnumerator.h
 * @brief		This is the header file for the %IMapEnumerator interface.
 *
 * This header file contains the declarations of the %IMapEnumerator interface.
 */
#ifndef _FBASE_COL_IMAP_ENUMERATOR_H_
#define _FBASE_COL_IMAP_ENUMERATOR_H_

#include <FBaseColIEnumerator.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Collection
{

class MapEntry;

/**
 * @interface IMapEnumerator
 * @brief	This interface supports simple iteration over a map.
 *
 * @since 2.0
 *
 * @remarks
 * An enumerator remains valid as long as the map remains unchanged.
 * If changes are made to the map, such as adding, modifying, or
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to any method returns an E_INVALID_OPERATION message.
 *
 * The %IMapEnumerator interface supports simple iteration over a map.
 * One can only access the elements in a collection through %IMapEnumerator. The elements cannot be modified through this interface.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 */
class _OSP_EXPORT_ IMapEnumerator
	: public virtual IEnumerator
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IMapEnumerator(void) {}

	/**
	 * Gets the current object from the collection.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the current object in the collection, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	 Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetLastResult()
	 */
	virtual Object* GetCurrent(void) const = 0;

	/**
	 * Gets the current key in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the current key in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	   Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				GetLastResult()
	 */
	virtual Object* GetKey(void) const = 0;

	/**
	 * Gets the current value in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the current value in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	 Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				GetLastResult()
	 */
	virtual Object* GetValue(void) const = 0;

}; // IMapEnumerator

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IMAP_ENUMERATOR_H_
