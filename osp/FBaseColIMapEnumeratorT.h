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
 * @file		FBaseColIMapEnumeratorT.h
 * @brief		This is the header file for the %IMapEnumeratorT interface.
 *
 * This header file contains the declarations of the %IMapEnumeratorT interface.
 */
#ifndef _FBASE_COL_IMAP_ENUMERATOR_T_H_
#define _FBASE_COL_IMAP_ENUMERATOR_T_H_

#include <FBaseColIEnumeratorT.h>
#include <FBaseColMapEntryT.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface IMapEnumeratorT
 * @brief	This interface supports simple iteration over a template-based map.
 *			Using this method, you can only access the elements in the map. You cannot modify the elements.
 *
 * @since 2.0
 *
 * @remarks
 * An enumerator remains valid as long as the map remains unchanged.
 * If changes are made to the map, such as adding, modifying, or
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to any method returns an E_INVALID_OPERATION message.
 *
 * The %IMapEnumeratorT interface supports simple iteration over a template-based map.
 *			Using this method, you can only access the elements in the map. You cannot modify the elements.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 */
template< class KeyType, class ValueType >
class IMapEnumeratorT
	: public virtual IEnumeratorT< MapEntryT< KeyType, ValueType > >
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IMapEnumeratorT(void) {}

	/**
	 * Gets the current key in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	key The current key
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The enumerator is currently positioned before the first element or after the last element or the collection is modified after the enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result GetKey(KeyType& key) const = 0;

	/**
	 * Gets the current value in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value The current value
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The enumerator is currently positioned before the first element or after the last element or the collection is modified after the enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result GetValue(ValueType& value) const = 0;

}; // IMapEnumeratorT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IMAP_ENUMERATOR_H_
