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
 * @file		FBaseColIList.h
 * @brief		This is the header file for the %IList interface.
 *
 * This header file contains the declarations of the %IList interface.
 */
#ifndef _FBASE_COL_ILIST_H_
#define _FBASE_COL_ILIST_H_

#include <FBaseColIBidirectionalEnumerator.h>
#include <FBaseColICollection.h>
#include <FBaseColIComparer.h>
#include <FBaseColTypes.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface IList
 * @brief	This interface represents a collection of objects that can be individually accessed by an index.
 *
 * @since 2.0
 *
 * The %IList interface represents a collection of objects that can be individually accessed by an index.
 *
 */
class _OSP_EXPORT_ IList
	: public virtual ICollection
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IList(void) {}

	/**
	 * @if OSPDEPREC
	 * Adds the specified object to the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it has a problem of const reference argument.
	 *				Instead of using this method, use Add(Object* pObj).
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj		The object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		In a collection of contiguous elements, such as a list, the elements
	 *				that follow the insertion point move down to accommodate the new element.
	 *				If the collection is indexed, the indexes of the elements that are moved
	 *				are also updated. This behavior does not apply to collections where
	 *				elements are conceptually grouped into buckets, such as a hashtable.
	 *				This method performs a shallow copy. It adds the pointer only; not the element itself.
	 * @see Remove()
	 * @endif
	 */
	result Add(const Object& obj)
	{
		return Add(const_cast< Object* >(&obj));
	}

	/**
	 * Adds the specified object to the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		In a collection of contiguous elements, such as a list, the elements
	 *				that follow the insertion point move down to accommodate the new element.
	 *				If the collection is indexed, the indexes of the elements that are moved
	 *				are also updated. This behavior does not apply to collections where
	 *				elements are conceptually grouped into buckets, such as a hashtable.
	 *				This method performs a shallow copy. It adds the pointer only; not the element itself.
	 * @see Remove()
	 */
	virtual result Add(Object* pObj) = 0;

	/**
	 * Adds the elements of the specified collection to the end of the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to add to the list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It adds the pointer only; not the element itself.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollection& collection) = 0;

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
	virtual result IndexOf(const Object& obj, int& index) const = 0;

	/**
	 * @if OSPDEPREC
	 * Inserts an object at the specified location in the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it has a problem of const reference argument.
	 *				Instead of using this method, use InsertAt(const Object* pObj, int index).
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
	 *      		This method performs a shallow copy. It inserts the pointer only; not the element itself.
	 * @see			Add()
	 * @see			RemoveAt()
	 * @endif
	 */
	result InsertAt(const Object& obj, int index)
	{
		return InsertAt(const_cast< Object* >(&obj), index);
	}

	/**
	 * Inserts an object at the specified location in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to insert
	 * @param[in]	index	The index at which the object must be inserted
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is greater than the number of elements in the list or less than @c 0.
	 * @remarks		If the @c index equals the number of elements in the list, the new element
	 *				is added at the end of the list.
	 *      		This method performs a shallow copy. It inserts the pointer only; not the element itself.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result InsertAt(Object* pObj, int index) = 0;

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
	virtual result IndexOf(const Object& obj, int startIndex, int& index) const = 0;

	/**
	 * Searches for an object within the specified range. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to locate
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
	virtual result IndexOf(const Object& obj, int startIndex, int count, int& index) const = 0;

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
	virtual result LastIndexOf(const Object& obj, int& index) const = 0;

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
	 *      		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			RemoveItems()
	 * @see			AddItems()
	 */
	virtual result InsertItemsFrom(const ICollection& collection, int startIndex) = 0;

	/**
	 * Gets the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		The object at the specified location, @n
	 *				else @c null if the @c index is not valid
	 * @param[in]	index	The index of the object to get
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual const Object* GetAt(int index) const = 0;

	/**
	 * Gets the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		The object at the specified location, @n
	 *				else @c null if the @c index is not valid
	 * @param[in]	index	The index of the object to get
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual Object* GetAt(int index) = 0;

	/**
	 * Gets all the elements of the list within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to an %IList with elements lying within the specified range, @n
	 *				else @c null if an exception occurs
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements in the list starting from @c startIndex
	 *										or less than @c 0.
	 * @remarks		The %IList stores just the pointers to the elements in the list, not the elements themselves.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IList* GetItemsN(int startIndex, int count) const = 0;

	/**
	 * Removes the first occurrence of the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to remove
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method.@n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		Remove(obj, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * Remove(obj);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		Remove(obj, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * Remove(obj);
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	result Remove(const Object& obj, bool forceDeletion)
	{
		DeleterFunctionType deleter = GetDeleter();

		if (forceDeletion)
		{
			SetDeleter(SingleObjectDeleter);
		}
		else
		{
			SetDeleter(NoOpDeleter);
		}

		result r = Remove(obj);
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Removes the first occurrence of the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result Remove(const Object& obj) = 0;

	/**
	 * Removes the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index at which the object must be removed
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method.@n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		RemoveAt(index, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * RemoveAt(index);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		RemoveAt(index, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * RemoveAt(index);
	 * SetDeleter(deleter);
	 * @endcode
	 */
	result RemoveAt(int index, bool forceDeletion)
	{
		DeleterFunctionType deleter = GetDeleter();

		if (forceDeletion)
		{
			SetDeleter(SingleObjectDeleter);
		}
		else
		{
			SetDeleter(NoOpDeleter);
		}

		result r = RemoveAt(index);
		SetDeleter(deleter);
		return r;
	}

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
	 * Removes all the elements within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements in the range
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method.@n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		RemoveItems(startIndex, count, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * RemoveItems(startIndex, count);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		RemoveItems(startIndex, count, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * RemoveItems(startIndex, count);
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			AddItems()
	 */
	result RemoveItems(int startIndex, int count, bool forceDeletion)
	{
		DeleterFunctionType deleter = GetDeleter();

		if (forceDeletion)
		{
			SetDeleter(SingleObjectDeleter);
		}
		else
		{
			SetDeleter(NoOpDeleter);
		}

		result r = RemoveItems(startIndex, count);
		SetDeleter(deleter);
		return r;
	}

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
	 */
	virtual result RemoveItems(int startIndex, int count) = 0;

	/**
	 * Removes all the elements from the list that are common to the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection 			The collection to be removed from this list
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method.@n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		RemoveItems(collection, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * RemoveItems(collection);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		RemoveItems(collection, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * RemoveItems(collection);
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			Remove()
	 * @see			RemoveAt()
	 */
	result RemoveItems(const ICollection& collection, bool forceDeletion)
	{
		DeleterFunctionType deleter = GetDeleter();

		if (forceDeletion)
		{
			SetDeleter(SingleObjectDeleter);
		}
		else
		{
			SetDeleter(NoOpDeleter);
		}

		result r = RemoveItems(collection);
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Removes all the elements from the list that are common to the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection 			The collection to remove from this list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @see			Remove()
	 * @see			RemoveAt()
	 */
	virtual result RemoveItems(const ICollection& collection) = 0;

	/**
	 * Removes all the object pointers in the collection. @n
	 * If the deallocate param is set to @c true, it removes all the objects in the collection. @n
	 * This method can be called just before deleting the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	forceDeletion		Set to @c true to deallocate all the objects, @n
	 * 							else @c false
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method.@n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		RemoveAll(@b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * RemoveAll();
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		RemoveAll(@b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * RemoveAll();
	 * SetDeleter(deleter);
	 * @endcode
	 */
	void RemoveAll(bool forceDeletion)
	{
		DeleterFunctionType deleter = GetDeleter();

		if (forceDeletion)
		{
			SetDeleter(SingleObjectDeleter);
		}
		else
		{
			SetDeleter(NoOpDeleter);
		}

		RemoveAll();
		SetDeleter(deleter);
	}

	/**
	 * Removes all the object pointers in the collection. @n
	 * This method can be called just before deleting the collection.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void) = 0;

	/**
	 * Replaces the object at the specified index with the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj     The new object
	 * @param[in]	index	The index at which the new object must be set
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @remarks		Based on the specified element deleter, the set operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the set method.@n
	 *				If both an element deleter and forceDeleteion are set, the set operation follows @c forceDeletion setting.
	 * @remarks		SetAt(obj, index, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * SetAt(const_cast< Object* >(&obj), index);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		SetAt(obj, index, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * SetAt(const_cast< Object* >(&obj), index);
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			GetAt()
	 */
	result SetAt(const Object& obj, int index, bool forceDeletion = false)
	{
		DeleterFunctionType deleter = GetDeleter();

		if (forceDeletion)
		{
			SetDeleter(SingleObjectDeleter);
		}
		else
		{
			SetDeleter(NoOpDeleter);
		}

		result r = SetAt(const_cast< Object* >(&obj), index);
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Replaces the object at the specified index with the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj	The pointer to new object
	 * @param[in]	index	The index at which the new object must be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(Object* pObj, int index) = 0;

	/**
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	comparer	The IComparer implementation to use when comparing elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	virtual result Sort(const IComparer& comparer) = 0;

	/**
	 * Checks whether the list contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the list contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj 	The object to locate
	 */
	virtual bool Contains(const Object& obj) const = 0;

	/**
	 * @if OSPDEPREC
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it transfers a result of comparison in out-parameter form.
	 *				The return type will be changed into boolean type and this method will return the result.
	 *				Instead of using this method, use bool ContainsAll(const ICollection& collection).
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
	 * @endif
	 */
	result ContainsAll(const ICollection& collection, bool& out) const
	{
		out = ContainsAll(collection);
		result r = GetLastResult();
		return r;
	}

	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the list contains all the elements of the specified collection, @n
	 *					else @c false
	 * @param[in]	collection	The collection to check for containment in this list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If the given @c collection is empty, this method will return @c true.
	 * @see			Contains()
	 */
	virtual bool ContainsAll(const ICollection& collection) const = 0;

	/**
	* Gets a bidirectional enumerator (an instance of the IBidirectionalEnumerator derived class) of this list.
	*
	* @since 2.0
	*
	* @return        A pointer to a bidirectional enumerator interface of the %IList derived class, @n
	*                              else @c null if an exception occurs
	* @remarks      Use this method to obtain a bidirectional enumerator (an instance of the IBidirectionalEnumerator derived class)
	*                              to iterate over a collection (an instance of the %IList derived class).
	*                   The specific error code can be accessed using GetLastResult() method.
	* @see           Tizen::Base::Collection::IBidirectionalEnumerator
	*/
	virtual IBidirectionalEnumerator* GetBidirectionalEnumeratorN(void) const = 0;

	/**
	 * This method is for distinguishing between ArrayList and LinkedList.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if it is an ArrayList, @n
	 *			else @c false if it is a LinkedList.
	 */
	virtual bool IsRandomAccessible(void) const
	{
		return false;
	}

	/**
	 * Gets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An function pointer to the existing element deleter
	 */
	virtual DeleterFunctionType GetDeleter(void) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IList_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IList_Reserved2(void) {}

private:
	/**
	 * Sets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	A function pointer to the element deleter to set
	 */
	virtual void SetDeleter(DeleterFunctionType deleter) = 0;

}; // IList

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_ILIST_H_
