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
 * @file		FBaseColArrayListT.h
 * @brief		This is the header file for the %ArrayListT class.
 *
 * This header file contains the declarations of the %ArrayListT class.
 */
#ifndef _FBASE_COL_ARRAY_LIST_T_H_
#define _FBASE_COL_ARRAY_LIST_T_H_

#include <FBaseResult.h>
#include <FBaseColIListT.h>
#include <FBaseColIComparerT.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class Type > class __ArrayListEnumeratorT;

/**
 * @class ArrayListT
 * @brief This class provides a template-based collection of objects that can be individually accessed by an index.
 *
 * @since 2.0
 *
 * The %ArrayListT class provides a template-based collection of objects that can be individually accessed by an index.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/arraylist_linkedlist.htm">ArrayList and LinkedList</a>.
 *
 * The following example demonstrates how to use the %ArrayListT class to create and initialize an %ArrayListT instance and to print out its values.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::ArrayListTSample(void)
 *	{
 *		ArrayListT< int > list;
 *
 *		list.Construct();
 *
 *		int int1 = 1;
 *		int int2 = 2;
 *		int int3 = 3;
 *		int int4 = 4;
 *
 *		list.Add(int1);		// 1
 *		list.Add(int2);		// 1,2
 *		list.Add(int3);		// 1,2,3
 *
 *		int temp;
 *		for (int i = 0; i < list.GetCount(); i++)
 *		{
 *			list.GetAt(i, temp);
 *		}
 *
 *		list.InsertAt(int4, 1);		// 1,4,2,3
 *
 *		ComparerT< int >* pIntComparer = new ComparerT<int>();
 *		list.Sort(*pIntComparer);	// 1,2,3,4
 *
 *		delete pIntComparer;
 *
 *		list.Remove(int3);			// 1,2,4
 *
 *		list.RemoveAt(0);			// 2,4
 *
 *		// Uses an enumerator to access elements in the list
 *		IEnumeratorT< int >* pEnum = list.GetEnumeratorN();
 *		while (pEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pEnum->GetCurrent(temp);
 *		}
 *
 *		delete pEnum;
 *	}
 * @endcode
 */
template< class Type >
class ArrayListT
	: public IListT< Type >
	, public Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize this instance.
	 */
	ArrayListT(void)
		: __capacity(0)
		, __count(0)
		, __pObjArray(null)
		, __modCount(0)
		, __pComparer(null)
	{
	}

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ArrayListT(void)
	{
		if (__pObjArray != null)
		{
			delete[] __pObjArray;
		}
	}

	/**
	 * Initializes this instance of %ArrayListT with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity of the class @n
	 *                              The default capacity is @c 10.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 * @remarks		If the number of elements added to the list reaches its current capacity,
	 *				the capacity is automatically increased by memory reallocation.
	 *				Thus, if the size of the list can be estimated,
	 *				specifying the initial capacity eliminates the need to perform a number of
	 *				resizing operations while adding elements to the list.
	 * @see			ArrayListT()
	 */
	result Construct(int capacity = DEFAULT_CAPACITY)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[%s] The capacity(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_INVALID_ARG), capacity);

		result r = SetCapacity(capacity);
		TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));

		return r;
	}

	/**
	 * Initializes this instance of %ArrayListT with the specified parameter. @n
	 * The capacity of the list is the same as the number of elements copied to it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	A collection of elements to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @see			ArrayListT()
	 */
	result Construct(const ICollectionT< Type >& collection)
	{
		result r = AddItems(collection);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		return r;

CATCH:
		delete[] __pObjArray;
		__pObjArray = null;

		return r;
	}

	/**
	 * Adds the specified object to the end of the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	An object to add to the list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see			Remove()
	 */
	virtual result Add(const Type& obj)
	{
		if (__count >= __capacity)
		{
			result r = SetCapacity(__capacity + DEFAULT_CAPACITY);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
		}

		__pObjArray[__count++] = obj;

		__modCount++;

		return E_SUCCESS;
	}

	/**
	 * Adds the elements of the specified collection to the end of the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection A collection of elements to add to the list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollectionT< Type >& collection)
	{
		result r = E_SUCCESS;

		IEnumeratorT< Type >* pEnum = null;
		int count = collection.GetCount();
		if (count > 0)
		{
			if (count > (__capacity - __count))
			{
				r = SetCapacity(__count + count);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
			}

			ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
			pEnum = pCol->GetEnumeratorN();
			TryReturn(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

			__modCount++;

			while ((r = pEnum->MoveNext()) != E_OUT_OF_RANGE)
			{
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				Type item;
				r = pEnum->GetCurrent(item);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				__pObjArray[__count++] = item;
			}
		}

		delete pEnum;
		return E_SUCCESS;

CATCH:
		delete pEnum;
		return r;
	}

	/**
	 * Gets the elements of the list in an instance of the IEnumeratorT derived class.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IEnumeratorT derived class if successful, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumeratorT
	 */
	virtual IEnumeratorT< Type >* GetEnumeratorN(void) const
	{
		result r = E_SUCCESS;

		__ArrayListEnumeratorT< Type >* pEnum = new __ArrayListEnumeratorT< Type >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		SetLastResult(E_SUCCESS);
		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Gets a bidirectional enumerator (an instance of the IBidirectionalEnumeratorT derived class) of this list.
	 *
	 * @since 2.0
	 *
	 * @return        An instance of the IBidirectionalEnumeratorT derived class, @n
	 *                              else @c null if an exception occurs
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_OUT_OF_MEMORY       The memory is insufficient.
	 * @remarks      Use this method to obtain a bidirectional enumerator (an instance of the IBidirectionalEnumeratorT derived class)
	 *                              to iterate over a collection (an instance of the IListT derived class).
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see           Tizen::Base::Collection::IBidirectionalEnumeratorT
	 */
	virtual IBidirectionalEnumeratorT< Type >* GetBidirectionalEnumeratorN(void) const
	{
		result r = E_SUCCESS;

		__ArrayListEnumeratorT< Type >* pEnum = new __ArrayListEnumeratorT< Type >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		SetLastResult(E_SUCCESS);
		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Gets the object at the specified @c index of the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index of the object to read
	 * @param[out]	obj An object to get from this list
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			SetAt()
	 */
	virtual result GetAt(int index, Type& obj) const
	{
		TryReturn(index >= 0 && index < __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0 and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		obj = __pObjArray[index];
		return E_SUCCESS;
	}

	/**
	 * Gets the object at the specified @c index of the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index of the object to read
	 * @param[out]	obj An object to get from this list
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			SetAt()
	 */
	virtual result GetAt(int index, Type& obj)
	{
		TryReturn(index >= 0 && index < __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0 and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		obj = __pObjArray[index];
		return E_SUCCESS;
	}

	/**
	 * Gets a list of a specified number of elements starting from a specified index.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IListT derived class within the specified range of the list, @n
	 *				else @c null if an exception occurs
	 * @param[in]	startIndex	The index to start reading elements from
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IListT< Type >* GetItemsN(int startIndex, int count) const
	{
		result r = E_SUCCESS;

		ArrayListT< Type >* pList = null;

		TryCatch(startIndex >= 0 && count >= 0, r = E_OUT_OF_RANGE,
			"[%s] Both of the startIndex(%d) and count(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_OUT_OF_RANGE), startIndex, count);
		TryCatch(startIndex < __count, r = E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be less than the number of elements(%d).", GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);
		TryCatch(count <= __count && (startIndex + count <= __count), r = E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) + count(%d) MUST be less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count, __count);

		pList = new ArrayListT< Type >();

		r = pList->Construct(count);
		TryCatch(r == E_SUCCESS, delete pList, "[%s] Propagating.", GetErrorMessage(r));

		for (int i = startIndex; i < (startIndex + count); i++)
		{
			pList->__pObjArray[pList->__count++] = __pObjArray[i];
		}

		SetLastResult(E_SUCCESS);
		return pList;

CATCH:
		SetLastResult(r);
		return null;
	}

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
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Type& obj, int& index) const
	{
		return IndexOf(obj, 0, __count, index);
	}

	/**
	 * Searches for an object starting from the specified @c index. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to locate
	 * @param[in]	startIndex	The starting index for the search @n
	 *							It must be less than the number of elements.
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either equal to or greater than the number of elements or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Type& obj, int startIndex, int& index) const
	{
		TryReturn(startIndex >= 0 && startIndex < __count, E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be greater than or equal to 0, and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);

		return IndexOf(obj, startIndex, (__count - startIndex), index);
	}

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
	 *										- The specified @c index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Type& obj, int startIndex, int count, int& index) const
	{
		TryReturn(startIndex >= 0 && count >= 0, E_OUT_OF_RANGE,
			"[%s] Both of the startIndex(%d) and count(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_OUT_OF_RANGE), startIndex, count);
		TryReturn(startIndex < __count, E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be less than the number of elements(%d).", GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);
		TryReturn(count <= __count && (startIndex + count <= __count), E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) + count(%d) MUST be less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count, __count);

		int arrayListCount = startIndex + count;
		for (int i = startIndex; i < arrayListCount; i++)
		{
			if (obj == __pObjArray[i])
			{
				index = i;
				return E_SUCCESS;
			}
		}

		return E_OBJ_NOT_FOUND;
	}

	/**
	 * Inserts an object at a specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj		The object to insert
	 * @param[in]	index	The index at which the object must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the @c index is greater than the number of elements or less than @c 0.
	 * @remarks		The elements that follow the insertion point move down to accommodate the new element.
	 *				If the @c index equals the number of elements in the list, the new element
	 *				is added at the end of the list.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result InsertAt(const Type& obj, int index)
	{
		TryReturn(index >= 0 && index <= __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, and less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		result r = E_SUCCESS;

		if (__count >= __capacity)
		{
			r = SetCapacity(__capacity + DEFAULT_CAPACITY);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
		}

		for (int i = __count; i > index; i--)
		{
			__pObjArray[i] = __pObjArray[i - 1];
		}

		__count++;
		__modCount++;
		__pObjArray[index] = obj;

		return E_SUCCESS;
	}

	/**
	 * Inserts the elements of a collection at a specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to insert
	 * @param[in]	startIndex	The index from which the collection must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c startIndex is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the @c collection is modified during the operation of this method.
	 * @remarks		The elements that follow the insertion point move down to accommodate the new elements.
	 *				If the @c startIndex equals the number of elements in the list, the new elements
	 *				are added at the end of the list.
	 * @see			RemoveItems()
	 * @see			AddItems()
	 */
	virtual result InsertItemsFrom(const ICollectionT< Type >& collection, int startIndex)
	{
		TryReturn(startIndex >= 0 && startIndex <= __count, E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be greater than or equal to 0, and less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);

		result r = E_SUCCESS;

		IEnumeratorT< Type >* pEnum = null;
		int count = collection.GetCount();

		if (count > 0)
		{
			if (count > (__capacity - __count))
			{
				r = SetCapacity(__count + count);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
			}

			__count += count;
			for (int i = (__count - 1); i >= (startIndex + count); i--)
			{
				__pObjArray[i] = __pObjArray[i - count];
			}

			ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
			pEnum = pCol->GetEnumeratorN();
			TryReturn(pEnum != null, GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

			__modCount++;

			while ((r = pEnum->MoveNext()) != E_OUT_OF_RANGE)
			{
				Type item;

				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				r = pEnum->GetCurrent(item);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				__pObjArray[startIndex++] = item;
			}
		}

		delete pEnum;
		return E_SUCCESS;

CATCH:
		delete pEnum;
		return r;
	}

	/**
	 * Searches for the last occurrence of an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to locate
	 * @param[out]	index		The index of the last occurrence of the specified object
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf(const Type& obj, int& index) const
	{
		for (int i = (__count - 1); i >= 0; i--)
		{
			if (obj == __pObjArray[i])
			{
				index = i;
				return E_SUCCESS;
			}
		}

		return E_OBJ_NOT_FOUND;
	}

	/**
	 * Removes the first occurrence of a specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	The object to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			Add()
	 * @see			RemoveAt()
	 * @see			RemoveAll()
	 */
	virtual result Remove(const Type& obj)
	{
		int index;
		result r = IndexOf(obj, index);
		if (IsFailed(r))
		{
			return E_OBJ_NOT_FOUND;
		}
		else
		{
			return RemoveAt(index);
		}
	}

	/**
	 * Removes all the elements of a specified collection from the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to remove from this list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @see			Remove()
	 * @see			RemoveAt()
	 */
	virtual result RemoveItems(const ICollectionT< Type >& collection)
	{
		result r = E_SUCCESS;
		int oldCount = __count;

		ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
		IEnumeratorT< Type >* pEnum = pCol->GetEnumeratorN();
		TryCatch(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while ((r = pEnum->MoveNext()) != E_OUT_OF_RANGE)
		{
			Type item;

			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pEnum->GetCurrent(item);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = Remove(item);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
		}

		if (__count < oldCount)
		{
			Trim();
		}

		delete pEnum;
		return E_SUCCESS;

CATCH:
		delete pEnum;
		return r;
	}

	/**
	 * Removes an object from a specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index of the object that is to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is greater than or equal to the number of elements or less than @c 0.
	 * @remarks		The elements that follow the deleted object move up the list to occupy the empty location.
	 * @see			InsertAt()
	 * @see			Remove()
	 */
	virtual result RemoveAt(int index)
	{
		TryReturn(index < __count && index >= 0, E_OUT_OF_RANGE,
			"[%s] The index MUST be greater than or equal to 0, and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		__modCount++;
		__count--;

		for (int i = index; i < __count; i++)
		{
			__pObjArray[i] = __pObjArray[i + 1];
		}

		Trim();

		return E_SUCCESS;
	}

	/**
	 * Removes all the elements within a specified range.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @remarks		The elements that follow the deleted elements move up the list to occupy the empty locations.
	 * @see			AddItems()
	 * @see			InsertItemsFrom()
	 */
	virtual result RemoveItems(int startIndex, int count)
	{
		TryReturn(startIndex >= 0 && count >= 0, E_OUT_OF_RANGE,
			"[%s] Both of the startIndex(%d) and count(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_OUT_OF_RANGE), startIndex, count);
		TryReturn(startIndex < __count, E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be less than the number of elements(%d).", GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);
		TryReturn(count <= __count && (startIndex + count <= __count), E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) + count(%d) MUST be less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count, __count);

		if (count > 0)
		{
			Type* newArray = new Type[__capacity];
			TryReturn(newArray != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

			__modCount++;
			__count -= count;

			for (int i = 0; i < startIndex; i++)
			{
				newArray[i] = __pObjArray[i];
			}
			for (int i = startIndex; i < __count; i++)
			{
				newArray[i] = __pObjArray[i + count];
			}

			delete[] __pObjArray;
			__pObjArray = newArray;
		}

		return E_SUCCESS;
	}

	/**
	 * Removes all elements in the list.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void)
	{
		if (__count != 0)
		{
			delete[] __pObjArray;
			__pObjArray = null;

			__count = 0;
			__capacity = 0;

			__modCount++;
		}

	}

	/**
	 * Sets the object at a specified @c index of the current instance of ByteBuffer with the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj		The object to set
	 * @param[in]	index	The index at which the object must be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(const Type& obj, int index)
	{
		TryReturn(index >= 0 && index < __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		__modCount++;

		__pObjArray[index] = obj;

		return E_SUCCESS;
	}

	/**
	 * Sets the capacity of the list to a specified value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	newCapacity	The new capacity to set for the list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c newCapacity is negative.
	 * @remarks		If the new capacity is less than the current capacity, the memory
	 *				is truncated and the elements within the truncated memory are destroyed.
	 * @see			Construct()
	 * @see			Trim()
	 * @see			GetCapacity()
	 */
	virtual result SetCapacity(int newCapacity)
	{
		TryReturn(newCapacity >= 0, E_INVALID_ARG, "[%s] The newCapacity(%d) MUST be greater than or equal to 0.",
			GetErrorMessage(E_INVALID_ARG), newCapacity);

		result r = E_SUCCESS;
		if (__capacity != newCapacity)
		{
			Type* newArray = null;
			if (newCapacity > 0)
			{
				newArray = new Type[newCapacity];
				TryCatch(newArray != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

				if (__pObjArray != null)
				{
					int count = __count < newCapacity ? __count : newCapacity;
					for (int i = 0; i < count; i++)
					{
						newArray[i] = __pObjArray[i];
					}
				}
			}
			if (__pObjArray != null)
			{
				delete[] __pObjArray;
			}
			if (__count > newCapacity)
			{
				__modCount++;
				__count = newCapacity;
			}
			__pObjArray = newArray;
			__capacity = newCapacity;
		}

		return r;

CATCH:
		return r;
	}

	/**
	 * Sorts the elements in the list using a comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	comparer A pointer to IComparerT
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c comparer is not valid.
	 */
	virtual result Sort(const IComparerT< Type >& comparer)
	{
		if (0 == __count)
			return E_SUCCESS;

		__pComparer = const_cast< IComparerT< Type >* >(&comparer);
		result r = QuickSort(0, (__count - 1));
		if (IsFailed(r))
		{
			AppLogException("[%s] Propagating.", GetErrorMessage(r));
			__pComparer = null;

			return r;
		}

		return E_SUCCESS;
	}

	/**
	 * Trims the capacity of a list to the actual number of elements in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetCapacity()
	 */
	virtual void Trim(void)
	{
		if (__capacity == 0)
		{
			return;
		}

		result r = SetCapacity(__count);
		if (IsFailed(r))
		{
			AppLogException("[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
		}
	}

	/**
	 * Gets the current capacity of the list.
	 *
	 * @since 2.0
	 *
	 * @return	The current capacity of the list
	 * @see			SetCapacity()
	 */
	int GetCapacity(void) const
	{
		return __capacity;
	}

	/**
	 * Gets the number of objects currently stored in the list.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects stored in the list
	 */
	virtual int GetCount(void) const
	{
		return __count;
	}

	/**
	 * Checks whether a list contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the object is present in the list, @n
	 *				else @c false
	 * @param[in]	obj The object to locate
	 * @see			ContainsAll()
	 */
	virtual bool Contains(const Type& obj) const
	{
		if (__count == 0)
		{
			return false;
		}

		for (int i = 0; i < __count; i++)
		{
			if (obj == __pObjArray[i])
			{
				return true;
			}
		}

		return false;
	}

	/**
	 * Checks whether the list contains all the elements of the specified @c collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to check for in the list
	 * @param[out]	out			@c true if the list contains all the elements of the specified @c collection, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		If the given @c collection is empty, the @c out parameter will be set to @c true.
	 * @see			Contains()
	 */
	virtual result ContainsAll(const ICollectionT< Type >& collection, bool& out) const
	{
		result r = E_SUCCESS;
		out = false;

		if (collection.GetCount() == 0)
		{
			out = true;
			return E_SUCCESS;
		}

		ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
		IEnumeratorT< Type >* pEnum = pCol->GetEnumeratorN();
		TryReturn(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while ((r = pEnum->MoveNext()) != E_OUT_OF_RANGE)
		{
			Type item;

			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pEnum->GetCurrent(item);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			if (false == Contains(item))
			{
				delete pEnum;

				return E_SUCCESS;
			}
		}


		delete pEnum;

		out = true;

		return E_SUCCESS;

CATCH:
		delete pEnum;

		return r;
	}

	/**
	 * Compares two instances of the %ArrayListT class.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two instances match, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the two instances contain the same elements in the same order.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const
	{
		const ArrayListT< Type >* other = dynamic_cast< const ArrayListT< Type >* >(&obj);
		if (null == other)
		{
			return false;
		}
		else if (other == this)
		{
			return true;
		}
		else if (__count != other->__count)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < __count; i++)
			{
				if (__pObjArray[i] != other->__pObjArray[i])
				{
					return false;
				}
			}
		}

		return true;
	}

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return 	The hash value of the current instance
	 * @remarks	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 * 		the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const
	{
		int hash = 0;
		for (int i = 0; i < __count; i++)
		{
			if (&(__pObjArray[i]) != null)
			{
				hash += reinterpret_cast< int >(&(__pObjArray[i]));
			}
		}
		return hash;
	}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list The instance of the %ArrayListT class to copy from
	 */
	ArrayListT(const ArrayListT< Type >& list);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list An instance of %ArrayListT
	 */
	ArrayListT< Type >& operator =(const ArrayListT< Type >& list);

	/**
	 * Sorts a section of a list using a comparer.
	 *
	 * @return		An error code
	 * @param[in]	startIndex The start index of the section of the list
	 * @param[in]	endIndex The end index of the section of the list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the elements.
	 */
	result QuickSort(int startIndex, int endIndex)
	{
		result r = E_SUCCESS;

		if (startIndex < endIndex)
		{
			int middleIndex;
			int i = startIndex - 1;
			int j = endIndex + 1;
			while (true)
			{
				int compareResult = 1;
				while ((compareResult > 0) && (j > static_cast< int >(startIndex)))
				{
					j--;

					r = __pComparer->Compare(__pObjArray[j], __pObjArray[startIndex], compareResult);
					TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
				}

				compareResult = -1;
				while ((compareResult < 0) && (i < static_cast< int >(endIndex)))
				{
					i++;

					r = __pComparer->Compare(__pObjArray[i], __pObjArray[startIndex], compareResult);
					TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
				}

				if (i < j)
				{
					Type temp = __pObjArray[j];
					__pObjArray[j] = __pObjArray[i];
					__pObjArray[i] = temp;
				}
				else
				{
					middleIndex = j;
					break;
				}
			}

			r = QuickSort(startIndex, middleIndex);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));

			r = QuickSort(middleIndex + 1, endIndex);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
		}

		return r;
	}

	int __capacity;
	int __count;
	Type* __pObjArray;
	int __modCount;
	IComparerT< Type >* __pComparer;
	static const int DEFAULT_CAPACITY = 10;

	friend class __ArrayListEnumeratorT< Type >;

}; // ArrayListT

//
// @class	__ArrayListEnumeratorT
// @brief	This class is an implementation of the IEnumeratorT interface for the %ArrayListT class.
// @since 2.0
//
template< class Type >
class __ArrayListEnumeratorT
	: public IBidirectionalEnumeratorT< Type >
	, public Tizen::Base::Object
{
public:
	__ArrayListEnumeratorT(const ArrayListT< Type >& list, int modCount)
		: __list(list)
		, __modCount(modCount)
		, __position(-1)
	{
	}

	virtual ~__ArrayListEnumeratorT(void)
	{
	}

	virtual result GetCurrent(Type& obj) const
	{
		TryReturn((__modCount == __list.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__position > -1) && (__position < static_cast <int>(__list.__count)), E_INVALID_OPERATION,
			"[%s] Current position(%d) is before the first element or past the last element.", GetErrorMessage(E_INVALID_OPERATION), __position);

		obj = __list.__pObjArray[__position];
		return E_SUCCESS;
	}

	virtual result MoveNext(void)
	{
		TryReturn((__modCount == __list.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		if ((__position + 1) >= static_cast< int >(__list.__count))
		{
			return E_OUT_OF_RANGE;
		}
		else
		{
			__position++;
		}

		return E_SUCCESS;
	}

	virtual result Reset(void)
	{
		TryReturn((__modCount == __list.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__position = -1;
		return E_SUCCESS;
	}

	virtual result MovePrevious(void)
	{
		TryReturn(__modCount == __list.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		TryReturn(__position > 0, E_OUT_OF_RANGE, "[%s] Reached start of the list, no previous element", GetErrorMessage(E_OUT_OF_RANGE));

		__position--;

		return E_SUCCESS;
	}

	virtual result ResetLast(void)
	{
		TryReturn(__modCount == __list.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__position = __list.__count;
		return E_SUCCESS;
	}

private:
	const ArrayListT< Type >& __list;
	int __modCount;
	int __position;

}; //__ArrayListEnumeratorT

} } } // Tizen::Base::Collection

#endif // _FBASE_COL_ARRAY_LIST_T_H_
