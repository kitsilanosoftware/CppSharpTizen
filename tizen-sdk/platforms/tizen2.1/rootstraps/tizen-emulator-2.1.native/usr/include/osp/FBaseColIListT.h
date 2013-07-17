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
 * @file		FBaseColIListT.h
 * @brief		This is the header file for the %IListT interface.
 *
 * This header file contains the declarations of the %IListT interface.
 */
#ifndef _FBASE_COL_ILIST_T_H_
#define _FBASE_COL_ILIST_T_H_

#include <FBaseColIBidirectionalEnumeratorT.h>
#include <FBaseColICollectionT.h>
#include <FBaseColIComparerT.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface IListT
 * @brief This interface represents a template-based collection of objects that can be individually accessed by an index.
 *
 * @since 2.0
 *
 * The %IListT interface represents a template-based collection of objects that can be individually accessed by an index.
 *
 */
template< class Type >
class IListT
	: public virtual ICollectionT< Type >
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IListT(void) {}

	/**
	 * Adds the specified object to the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	The object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		In a collection of contiguous elements, such as a list, the elements
	 *				that follow the insertion point move down to accommodate the new element.
	 *				If the collection is indexed, the indexes of the elements that are moved
	 *				are also updated. This behavior does not apply to collections where
	 *				elements are conceptually grouped into buckets, such as a hashtable.
	 * @see Remove()
	 */
	virtual result Add(const Type& obj) = 0;

	/**
	 * Adds the elements of the specified collection to the end of the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollectionT< Type >& collection) = 0;

	/**
	 * Searches for an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to locate
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 */
	virtual result IndexOf(const Type& obj, int& index) const = 0;

	/**
	 * Searches for an object starting from the specified index. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[in]	startIndex	The starting index for the search @n
	 *							It must be less than the number of elements.
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Type& obj, int startIndex, int& index) const = 0;

	/**
	 * Searches for an object within the specified range. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Type& obj, int startIndex, int count, int& index) const = 0;

	/**
	 * Searches for the last occurrence of an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[out]	index		The index of the last occurrence of the specified object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf(const Type& obj, int& index) const = 0;

	/**
	 * Inserts an object at the specified location in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj		The object to insert
	 * @param[in]	index	The index at which the object must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c index is greater than the number of elements in the list or less than @c 0.
	 * @remarks		If the @c index equals the number of elements in the list, the new element
	 *				is added at the end of the list.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result InsertAt(const Type& obj, int index) = 0;

	/**
	 * Inserts the elements of a collection in the list at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to insert
	 * @param[in]	startIndex	The starting index at which the collection must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c startIndex is greater than the number of elements in the list or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the specified @c collection is modified during the operation of this method.
	 * @remarks		If the @c startIndex equals the number of elements in the list, the new elements
	 *				are added at the end of the list.
	 * @see			RemoveItems()
	 * @see			AddItems()
	 */
	virtual result InsertItemsFrom(const ICollectionT< Type >& collection, int startIndex) = 0;

	/**
	 * Gets the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index	The index of the object to get
	 * @param[out]	obj	The object obtained from the list
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @see			SetAt()
	 */
	virtual result GetAt(int index, Type& obj) const = 0;

	/**
	 * Gets the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index	The index of the object to get
	 * @param[out]	obj	The object obtained from the list
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @see			SetAt()
	 */
	virtual result GetAt(int index, Type& obj) = 0;

	/**
	 * Gets all the elements of the list within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to %IListT with elements lying within the specified range, @n
	 *				else @c null if an exception occurs
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements in the list starting from @c startIndex
	 *										or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IListT< Type >* GetItemsN(int startIndex, int count) const = 0;

	/**
	 * Removes the first occurrence of the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	The object to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The object is not found.
	 */
	virtual result Remove(const Type& obj) = 0;

	/**
	 * Removes the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index at which the object must be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 */
	virtual result RemoveAt(int index) = 0;

	/**
	 * Removes all the elements from the list that are common to the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to remove from this list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @see			Remove()
	 * @see			RemoveAt()
	 */
	virtual result RemoveItems(const ICollectionT< Type >& collection) = 0;

	/**
	 * Removes all the elements within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements in the range
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @see			AddItems()
	 * @see			InsertItemsFrom()
	 */
	virtual result RemoveItems(int startIndex, int count) = 0;

	/**
	 * Removes all the elements in the list.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void) = 0;

	/**
	 * Sets the object at the specified index with the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	The new object
	 * @param[in]	index	The index at which the new object must be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(const Type& obj, int index) = 0;

	/**
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	comparer	The IComparerT implementation to use when comparing elements
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	virtual result Sort(const IComparerT< Type >& comparer) = 0;

	/**
	 * Checks whether the list contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the list contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj     The object to locate
	 */
	virtual bool Contains(const Type& obj) const = 0;

	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to check for containment in this list
	 * @param[out]	out			Set to @c true if the list contains all the elements of the specified collection, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @remarks		If the given @c collection is empty, the @c out parameter is set to @c true.
	 * @see			Contains()
	 */
	virtual result ContainsAll(const ICollectionT< Type >& collection, bool& out) const = 0;

	/**
	 * Gets a bidirectional enumerator (an instance of the IBidirectionalEnumeratorT derived class) of this list.
	 *
	 * @since 2.0
	 *
	 * @return        A pointer to a bidirectional enumerator interface of the %IListT derived class, @n
	 *                              else @c null if an exception occurs
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_OUT_OF_MEMORY         The memory is insufficient.
	 * @remarks      Use this method to obtain a bidirectional enumerator (an instance of the IBidirectionalEnumeratorT derived class)
	 *                              to iterate over a collection (an instance of the %IListT derived class).
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see           Tizen::Base::Collection::IBidirectionalEnumeratorT
	 */
	virtual IBidirectionalEnumeratorT< Type >* GetBidirectionalEnumeratorN(void) const = 0;

}; // IListT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_ILIST_T_H_
