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
 * @file		FBaseColLinkedListT.h
 * @brief		This is the header file for the %LinkedListT class.
 *
 * This header file contains the declarations of the %LinkedListT class.
 */
#ifndef _FCOL_LINKED_LIST_T_H_
#define _FCOL_LINKED_LIST_T_H_

#include <FBaseResult.h>
#include <FBaseColIComparerT.h>
#include <FBaseColIListT.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class Type > class __LinkedListEnumeratorT;
template< class Type > class __LinkedListNodeT;

/**
 * @class LinkedListT
 * @brief This class represents a template-based collection of objects that can be individually accessed by index.
 *
 * @since 2.0
 *
 * The %LinkedListT class represents a template-based collection of objects that can be individually accessed by index.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/arraylist_linkedlist.htm">ArrayList and LinkedList</a>.
 *
 * The following example demonstrates how to use the %LinkedListT class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::LinkedListTSample(void)
 *	{
 *		LinkedListT<int> list;
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
 *		list.InsertAt(int4, 1);	// 1,4,2,3
 *
 *		ComparerT<int>* pIntComparer = new ComparerT<int>();
 *		list.Sort(*pIntComparer);	// 1,2,3,4
 *
 *		delete pIntComparer;
 *
 *		list.Remove(int3);	// 1,2,4
 *		list.RemoveAt(0);	// 2,4
 *
 *		// Uses an enumerator to access elements in the list
 *		IEnumeratorT<int>* pEnum = list.GetEnumeratorN();;
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
class LinkedListT
	: public IListT< Type >
	, public Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	LinkedListT(void)
		: __pListHead(null)
		, __pListTail(null)
		, __count(0)
		, __modCount(0)
	{
	}

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~LinkedListT(void)
	{
		__modCount++;

		RemoveAll();
	}

	/**
	 * Adds the specified object to the end of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj An object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see Remove()
	 */
	virtual result Add(const Type& obj)
	{
		result r = E_SUCCESS;

		if (null == __pListHead)
		{
			r = InsertFirst(obj);
		}
		else
		{
			r = InsertLast(obj);
		}
		if (r != E_SUCCESS)
		{
			AppLogException("[%s] Propagating.", GetErrorMessage(r));
		}

		return r;
	}

	/**
	 * Adds the elements of the specified collection to the end of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollectionT< Type >& collection)
	{
		result r = InsertItemsFrom(collection, __count);
		if (r != E_SUCCESS)
		{
			AppLogException("[%s] Propagating.", GetErrorMessage(r));
		}

		return r;
	}

	/**
	 * Gets an enumerator to this list.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumeratorT derived class) of this list, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumeratorT
	 */
	virtual IEnumeratorT< Type >* GetEnumeratorN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		__LinkedListEnumeratorT< Type >* pEnum = new __LinkedListEnumeratorT< Type >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

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
	 * @return        An instance of the IBidirectionalEnumeratorT derived class if successful, @n
	 *                              else @c null if an exception occurs
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_OUT_OF_MEMORY       The memory is insufficient.
	 * @remarks      Use this method to obtain a bidirectional enumerator (an instance of the IBidirectionalEnumeratorT derived class)
	 *                              to iterate over a collection (an instance of the IListT derived class).
	 *                   The specific error code can be accessed using the GetLastResult() method.
	 * @see           Tizen::Base::Collection::IBidirectionalEnumeratorT
	 */
	virtual IBidirectionalEnumeratorT< Type >* GetBidirectionalEnumeratorN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		__LinkedListEnumeratorT< Type >* pEnum = new __LinkedListEnumeratorT< Type >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Gets the object at the specified index of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index of the object to read
	 * @param[out]	obj An object to get from this list
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see			SetAt()
	 */
	virtual result GetAt(int index, Type& obj) const
	{
		TryReturn(index >= 0 && index < __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		__LinkedListNodeT< Type >* pNode = GetNode(index);
		if (pNode != null)
		{
			obj = pNode->pObj;
		}
		return E_SUCCESS;
	}

	/**
	 * Gets the object at the specified index of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index of the object to read
	 * @param[out]	obj An object to get from this list
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see			SetAt()
	 */
	virtual result GetAt(int index, Type& obj)
	{
		TryReturn(index >= 0 && index < __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		__LinkedListNodeT< Type >* pNode = GetNode(index);
		if (pNode != null)
		{
			obj = pNode->pObj;
		}
		return E_SUCCESS;
	}

	/**
	 * Gets an IListT-derived instance with the specified range from the calling list object.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the IListT derived instance, @n
	 *				else @c null if an exception occurs.
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IListT< Type >* GetItemsN(int startIndex, int count) const
	{
		ClearLastResult();

		result r = E_SUCCESS;
		LinkedListT< Type >* pList = null;
		__LinkedListNodeT< Type >* pNode = null;
		__LinkedListNodeT< Type >* pPrevNode = null;

		TryCatch(startIndex >= 0 && count >= 0, r = E_OUT_OF_RANGE,
			"[%s] Both of the startIndex(%d) and count(%d) MUST be greater than or equal to 0.",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count);
		TryCatch(startIndex < __count, r = E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be less than the number of elements(%d).", GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);
		TryCatch(count <= __count && (startIndex + count <= __count), r = E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) + count(%d) MUST be less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count, __count);

		pList = new LinkedListT< Type >();

		pNode = GetNode(startIndex);
		if ((pList != null) && (pNode != null))
		{
			r = pList->InsertFirst(pNode->pObj);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			pNode = pNode->pNext;
			pPrevNode = pList->__pListTail;

			for (int i = 0; i < (count - 1); i++)
			{
				if (pNode != null)
				{
					pPrevNode = pList->InsertNext(pPrevNode, pNode->pObj);
					TryCatch(pPrevNode != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));
					pNode = pNode->pNext;
				}
			}
		}

		return pList;

CATCH:
		SetLastResult(r);
		delete pList;

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
	 */
	virtual result IndexOf(const Type& obj, int& index) const
	{
		result r = E_SUCCESS;
		if (__count == 0)
		{
			r = E_OBJ_NOT_FOUND;
		}
		else
		{
			r = IndexOf(obj, 0, __count, index);
		}

		return r;
	}

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
	virtual result IndexOf(const Type& obj, int startIndex, int& index) const
	{
		TryReturn((startIndex >= 0 && startIndex < __count), E_OUT_OF_RANGE,
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
	 * @param[in]	obj         The object to locate
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Type& obj, int startIndex, int count, int& index) const
	{
		TryReturn(startIndex >= 0 && count >= 0, E_OUT_OF_RANGE,
			"[%s] Both of the startIndex(%d) and count(%d) MUST be greater than or equal to 0.",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count);
		TryReturn(startIndex < __count, E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) MUST be less than the number of elements(%d).", GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);
		TryReturn(count <= __count && (startIndex + count <= __count), E_OUT_OF_RANGE,
			"[%s] The startIndex(%d) + count(%d) MUST be less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), startIndex, count, __count);

		result r = E_OBJ_NOT_FOUND;
		__LinkedListNodeT< Type >* pNode = GetNode(startIndex);
		for (int i = 0; i < count; i++)
		{
			if (pNode != null)
			{
				if (obj == pNode->pObj)
				{
					index = (startIndex + i);
					r = E_SUCCESS;
					break;
				}
				pNode = pNode->pNext;
			}
		}

		return r;
	}

	/**
	 * Inserts the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	An object to insert
	 * @param[in]	index	The index at which the object must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is greater than the number of elements or less than @c 0.
	 * @remarks		If the @c index equals to the number of elements then the new element
	 *				is added at the end of this list.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result InsertAt(const Type& obj, int index)
	{
		TryReturn(index >= 0 && index <= __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, and less than or equal to the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		result r = E_SUCCESS;

		__LinkedListNodeT< Type >* pPrevNode = null;
		if (index == 0)
		{
			r = InsertFirst(obj);
		}
		else if (index == __count)
		{
			r = InsertLast(obj);
		}
		else
		{
			pPrevNode = GetNode(index - 1);
			if (pPrevNode != null)
			{
				InsertNext(pPrevNode, obj);
			}
			r = GetLastResult();
		}
		if (r != E_SUCCESS)
		{
			AppLogException("[%s] Propagating.", GetErrorMessage(r));
		}

		return r;
	}


	/**
	 * Inserts the elements of the @c collection at the location specified.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to insert
	 * @param[in]	startIndex	The starting index at which the collection must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the specified @c collection is modified during the operation of this method.
	 * @remarks		If the @c startIndex equals to the number of elements then the new elements
	 *				are added at the end of this list.
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
			__LinkedListNodeT< Type >* pPrevNode = null;
			;
			if (startIndex == __count)
			{
				pPrevNode = __pListTail;
			}
			else if (startIndex > 0)
			{
				pPrevNode = GetNode(startIndex - 1);
			}

			ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
			pEnum = pCol->GetEnumeratorN();
			TryCatch(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

			while (true)
			{
				Type obj;
				r = pEnum->MoveNext();

				if (E_OUT_OF_RANGE == r)
				{
					r = E_SUCCESS;
					break;
				}
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				r = pEnum->GetCurrent(obj);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				if (null == pPrevNode)
				{
					r = InsertFirst(obj);
					TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
					pPrevNode = __pListHead;
				}
				else
				{
					pPrevNode = InsertNext(pPrevNode, obj);
					TryCatch(pPrevNode != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));
				}
			}
		}

		if (null != pEnum)
		{
			delete pEnum;
		}

		return r;

CATCH:
		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;
	}

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
	virtual result LastIndexOf(const Type& obj, int& index) const
	{
		result r = E_OBJ_NOT_FOUND;
		__LinkedListNodeT< Type >* pNode = __pListTail;
		for (int i = (__count - 1); i >= 0; i--)
		{
			if (obj == pNode->pObj)
			{
				index = i;
				r = E_SUCCESS;
				break;
			}
			pNode = pNode->pPrev;
		}

		return r;
	}

	/**
	 * Removes the first occurrence of the specified object from the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	An object to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			Add()
	 * @see			RemoveAt()
	 * @see			RemoveAll()
	 */
	virtual result Remove(const Type& obj)
	{
		result r = E_OBJ_NOT_FOUND;
		__LinkedListNodeT< Type >* pNode = __pListHead;
		while (null != pNode)
		{
			if (pNode->pObj == obj)
			{
				RemoveNode(pNode);
				r = E_SUCCESS;
				break;
			}
			pNode = pNode->pNext;
		}

		return r;
	}

	/**
	 * Removes all the elements in the specified @c collection.
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
	virtual result RemoveItems(const ICollectionT< Type >& collection)
	{
		result r = E_SUCCESS;

		ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
		IEnumeratorT< Type >* pEnum = pCol->GetEnumeratorN();
		TryCatch(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while (true)
		{
			Type temp;
			r = pEnum->MoveNext();

			if (E_OUT_OF_RANGE == r)
			{
				r = E_SUCCESS;
				break;
			}
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pEnum->GetCurrent(temp);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = Remove(temp);
			TryLog(r == E_SUCCESS, "[%s] Remove() failed.", GetErrorMessage(r));
		}

		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;

CATCH:
		if (null != pEnum)
		{
			delete pEnum;
		}
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
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see			InsertAt()
	 */
	virtual result RemoveAt(int index)
	{
		TryReturn(index < __count && index >= 0, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, and less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		RemoveNode(GetNode(index));
		return E_SUCCESS;
	}

	/**
	 * Removes all elements within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @see			AddItems()
	 * @see			InsertItemsFrom()
	 */
	virtual result RemoveItems(int startIndex, int count)
	{
		TryReturn(startIndex >= 0 && count >= 0, E_OUT_OF_RANGE,
				  "[%s] Both of the startIndex(%d) and count(%d) MUST be greater than or equal to 0.",
				  GetErrorMessage(E_OUT_OF_RANGE), startIndex, count);
		TryReturn(startIndex < __count, E_OUT_OF_RANGE,
				  "[%s] The startIndex(%d) MUST be less than the number of elements(%d).", GetErrorMessage(E_OUT_OF_RANGE), startIndex, __count);
		TryReturn(count <= __count && (startIndex + count <= __count), E_OUT_OF_RANGE,
				  "[%s] The startIndex(%d) + count(%d) MUST be less than or equal to the number of elements(%d).",
				  GetErrorMessage(E_OUT_OF_RANGE), startIndex, count, __count);

		if (count > 0)
		{
			__LinkedListNodeT< Type >* pNode = GetNode(startIndex);
			for (int i = 0; i < count; i++)
			{
				if (pNode != null)
				{
					__LinkedListNodeT< Type >* pNextNode = pNode->pNext;
					RemoveNode(pNode);
					pNode = pNextNode;
				}
			}
		}
		return E_SUCCESS;
	}

	/**
	 * Removes all the elements from this list.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void)
	{
		if (__count > 0)
		{
			__modCount++;
			__LinkedListNodeT< Type >* pNode = __pListHead;
			__LinkedListNodeT< Type >* pTemp;
			while (null != pNode)
			{
				pTemp = pNode->pNext;
				delete pNode;
				pNode = pTemp;
				__count--;
			}
			__pListHead = null;
			__pListTail = null;
		}
	}

	/**
	 * Sets the object at the specified index with the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	An object to set
	 * @param[in]	index	The index at which the object must be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(const Type& obj, int index)
	{
		TryReturn(index >= 0 && index < __count, E_OUT_OF_RANGE,
			"[%s] The index(%d) MUST be greater than or equal to 0, less than the number of elements(%d).",
			GetErrorMessage(E_OUT_OF_RANGE), index, __count);

		__modCount++;
		__LinkedListNodeT< Type >* pNode = GetNode(index);
		if (pNode != null)
		{
			pNode->pObj = obj;
		}

		return E_SUCCESS;
	}

	/**
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	comparer The IComparerT implementation to use when comparing the elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c comparer is not valid.
	 */
	virtual result Sort(const IComparerT< Type >& comparer)
	{
		if (0 == __count)
		{
			return E_SUCCESS;
		}

		result r = QuickSort(0, (__count - 1), comparer);
		if (r != E_SUCCESS)
		{
			AppLogException("[%s] Propagating.", GetErrorMessage(r));
		}

		return r;
	}

	/**
	 * Gets the number of objects currently stored in this list.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in this list
	 */
	virtual int GetCount(void) const
	{
		return __count;
	}

	/**
	 * Checks whether the list contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the list contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj     The object to locate
	 * @see			ContainsAll()
	 */
	virtual bool Contains(const Type& obj) const
	{
		if (__count == 0)
		{
			return false;
		}

		__LinkedListNodeT< Type >* pNode = GetNode(0);
		for (int i = 0; i < __count; i++)
		{
			if (pNode != null)
			{
				if (obj == pNode->pObj)
				{
					return true;
				}
				pNode = pNode->pNext;
			}
		}

		return false;
	}

	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to check for containment in this list
	 * @param[out]	out 		Set to @c true if this list contains all of the elements in the specified collection, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @remarks		If the given @c collection is empty, the @c out parameter is set to @c true.
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
		TryCatch(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while (true)
		{
			Type temp;

			r = pEnum->MoveNext();

			if (E_OUT_OF_RANGE == r)
			{
				r = E_SUCCESS;
				out = true;
				break;
			}
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pEnum->GetCurrent(temp);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			if (false == Contains(temp))
			{
				out = false;
				break;
			}
		}

		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;

CATCH:
		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;
	}

	/**
	 * Compares the given object with the calling LinkedList object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance equals to the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the calling object
	 * @remarks		This method returns @c true only if the specified object is also an instance of LinkedList class,
	 *				both lists have the same size, and all corresponding pairs of elements in the two lists are equal.
	 *				In other words, two lists are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const
	{
		bool out = true;

		const LinkedListT< Type >* other = dynamic_cast< const LinkedListT< Type >* >(&obj);
		if (null == other)
		{
			out = false;
		}
		else if (other == this)
		{
			out = true;
		}
		else if (__count != other->__count)
		{
			out = false;
		}
		else
		{
			__LinkedListNodeT< Type >* pNode = __pListHead;
			__LinkedListNodeT< Type >* pOtherNode = other->__pListHead;
			for (int i = 0; i < __count; i++)
			{
				if (!(pNode->pObj == pOtherNode->pObj))
				{
					out = false;
					break;
				}
				pNode = pNode->pNext;
				pOtherNode = pOtherNode->pNext;
			}
		}

		return out;
	}

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return 	The hash value of the current instance
	 * @remarks	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 * 			the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const
	{
		int hash = 0;
		if (__count > 0)
		{
			__LinkedListNodeT< Type >* pNode = __pListHead;
			while (pNode != null)
			{
				hash += reinterpret_cast< int >(pNode);
				pNode = pNode->pNext;
			}
		}

		return hash;
	}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list The %LinkedListT object to initialize the new object
	 */
	LinkedListT(const LinkedListT< Type >& list);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list An instance of %LinkedListT
	 */
	LinkedListT< Type >& operator =(const LinkedListT< Type >& list);

	/**
	 * Gets the node at the specified index.
	 *
	 * @return		A node at the specified index
	 * @param[in]	index The index of the node to read
	 */
	__LinkedListNodeT< Type >* GetNode(int index) const
	{
		if (index >= __count)
		{
			return null;
		}

		__LinkedListNodeT< Type >* pNode = __pListHead;
		for (int i = 0; i < index; i++)
		{
			pNode = pNode->pNext;
		}

		return pNode;
	}

	/**
	 * Inserts an object to the beginning of the %LinkedList.
	 *
	 * @return		An error code
	 * @param[in]	obj     The object to insert
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertFirst(const Type& obj)
	{
		result r = E_SUCCESS;
		__LinkedListNodeT< Type >* pNode = new __LinkedListNodeT< Type >(obj);
		TryCatch(pNode != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		__modCount++;
		__count++;
		if (null == __pListHead)
		{
			__pListHead = pNode;
			__pListTail = pNode;
		}
		else
		{
			pNode->pNext = __pListHead;
			__pListHead->pPrev = pNode;
			__pListHead = pNode;
		}

		return r;

CATCH:
		return r;
	}

	/**
	 * Inserts an object to the end of the LinkedList.
	 *
	 * @return		An error code
	 * @param[in]	obj     The object to insert
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertLast(const Type& obj)
	{
		__LinkedListNodeT< Type >* pNode = InsertNext(__pListTail, obj);
		if (pNode == null)
		{
			AppLogException("[%s] Propagating.", GetErrorMessage(GetLastResult()));
		}

		return GetLastResult();
	}

	/**
	 * Inserts an object after the specified node.
	 *
	 * @return		An error code
	 * @param[in]	obj     The object to insert
	 * @param[in]	pPrevNode The node after which the object must be inserted
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SUCCESS		The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	__LinkedListNodeT< Type >* InsertNext(__LinkedListNodeT< Type >* pPrevNode, const Type& obj)
	{
		ClearLastResult();
		result r = E_SUCCESS;
		__LinkedListNodeT< Type >* pNode = new __LinkedListNodeT< Type >(obj);
		TryCatch(pNode != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		__modCount++;
		__count++;
		if (null == __pListHead)
		{
			__pListHead = pNode;
			__pListTail = pNode;
		}
		else if (pPrevNode == __pListTail)
		{
			pNode->pPrev = __pListTail;
			__pListTail->pNext = pNode;
			__pListTail = pNode;
		}
		else
		{
			TryCatch(pPrevNode != null, r = E_INVALID_ARG, "[%s] The pPrevNode is null.", GetErrorMessage(E_INVALID_ARG));
			pNode->pPrev = pPrevNode;
			pNode->pNext = pPrevNode->pNext;
			pPrevNode->pNext->pPrev = pNode;
			pPrevNode->pNext = pNode;
		}

		return pNode;

CATCH:
		SetLastResult(r);
		if (pNode != null)
		{
			delete pNode;
			pNode = null;
		}

		return pNode;
	}

	/**
	 * Removes the specified node.
	 *
	 * @param[in]	pNode The pointer of the node to remove
	 */
	void RemoveNode(__LinkedListNodeT< Type >* pNode)
	{
		AppAssertf((null != pNode), "pNode is null.\n");
		AppAssertf((__count > 0), "__count is zero.\n");

		__modCount++;
		__count--;
		if (__count == 0)
		{
			__pListHead = null;
			__pListTail = null;
		}
		else if (pNode == __pListHead)
		{
			__pListHead = pNode->pNext;
			__pListHead->pPrev = null;
		}
		else if (pNode == __pListTail)
		{
			__pListTail = pNode->pPrev;
			__pListTail->pNext = null;
		}
		else
		{
			pNode->pNext->pPrev = pNode->pPrev;
			pNode->pPrev->pNext = pNode->pNext;
		}
		delete pNode;
	}

	/**
	 * Sorts the specified sub-list within the calling instance.
	 *
	 * @param[in]	startIndex	The starting index of the sub-list to sort
	 * @param[in]	endIndex	The ending index of the sub-list to sort
	 * @param[in]	pComparer	The comparer function to sort the list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the comparer has failed to compare the elements.
	 */
	result QuickSort(int startIndex, int endIndex, const IComparerT< Type >& comparer)
	{
		result r = E_SUCCESS;

		if (startIndex < endIndex)
		{
			int middleIndex;
			int i = startIndex - 1;
			int j = endIndex + 1;
			Type startObj = Type();
			__LinkedListNodeT< Type >* pNodeI = null;
			__LinkedListNodeT< Type >* pNodeJ = null;
			__LinkedListNodeT< Type >* pNode = GetNode(startIndex);

			if (pNode != null)
			{
				startObj = pNode->pObj;
			}

			while (true)
			{
				int compareResult = 1;
				while ((compareResult > 0) && (j > static_cast< int >(startIndex)))
				{
					j--;
					pNodeJ = (null == pNodeJ) ? GetNode(j) : pNodeJ->pPrev;
					if (pNodeJ != null)
					{
						r = comparer.Compare(pNodeJ->pObj, startObj, compareResult);
						TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
					}
				}

				compareResult = -1;
				while ((compareResult < 0) && (i < static_cast< int >(endIndex)))
				{
					i++;
					pNodeI = (null == pNodeI) ? GetNode(i) : pNodeI->pNext;
					if (pNodeI != null)
					{
						r = comparer.Compare(pNodeI->pObj, startObj, compareResult);
						TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
					}
				}

				if (i < j)
				{
					if ((pNodeJ != null) && (pNodeI != null))
					{
						Type temp = pNodeJ->pObj;
						pNodeJ->pObj = pNodeI->pObj;
						pNodeI->pObj = temp;
					}
				}
				else
				{
					middleIndex = j;
					break;
				}
			}

			r = QuickSort(startIndex, middleIndex, comparer);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));

			r = QuickSort(middleIndex + 1, endIndex, comparer);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
		}

		return r;
	}

	__LinkedListNodeT< Type >* __pListHead;
	__LinkedListNodeT< Type >* __pListTail;
	int __count;
	int __modCount;
	friend class __LinkedListEnumeratorT< Type >;

}; // LinkedListT

//
// @class	__LinkedListNodeT
// @brief	This is a node for LinkedListT.
// @since 2.0
//
template< class Type >
class __LinkedListNodeT
	: public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	obj	An object to include in this node
	 */
	__LinkedListNodeT(const Type& obj)
		: pPrev(null)
		, pNext(null)
		, pObj(obj)
	{
	}

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	__LinkedListNodeT< Type >* pPrev;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	__LinkedListNodeT< Type >* pNext;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	Type pObj;

}; // __LinkedListNodeT

//
// @class	__LinkedListEnumeratorT
// @brief	This class is an implementation of IEnumeratorT for %LinkedListT.
// @since 2.0
//
template< class Type >
class __LinkedListEnumeratorT
	: public IBidirectionalEnumeratorT< Type >
	, public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	list		A list to enumerate
	 * @param[in]	modCount	The modification count to detect the change in the list
	 */
	__LinkedListEnumeratorT(const LinkedListT< Type >& list, int modCount)
		: __list(list)
		, __pNode(null)
		, __modCount(modCount)
	{

	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__LinkedListEnumeratorT(void)
	{

	}

	/**
	 * Gets the current object in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The current object
	 * @exception	E_INVALID_OPERATION	  Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	                                    - The list is modified after this enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetCurrent(Type& obj) const
	{
		TryReturn(__modCount == __list.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn(__pNode != null, E_INVALID_OPERATION,
			"[%s] Current position is before the first element or past the last element.", GetErrorMessage(E_INVALID_OPERATION));

		obj = __pNode->pObj;
		return E_SUCCESS;
	}


	/**
	 * Moves this enumerator to the next element of the list. @n
	 * When this enumerator is first created or after call to Reset(),
	 * the first call to MoveNext() positions this enumerator to the first element in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the list is modified after this enumerator is created.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the list.
	 * @see			Reset()
	 */
	result MoveNext(void)
	{
		TryReturn(__modCount == __list.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		if (null == __pNode)
		{
			__pNode = __list.__pListHead;
			if (null == __pNode)
			{
				return E_OUT_OF_RANGE;
			}
		}
		else
		{
			if (null != __pNode->pNext)
			{
				__pNode = __pNode->pNext;
			}
			else
			{
				return E_OUT_OF_RANGE;
			}
		}

		return E_SUCCESS;
	}

	/**
	 * Positions this enumerator before the first elements in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the list is modified after this enumerator is created.
	 */
	result Reset(void)
	{
		TryReturn(__modCount == __list.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__pNode = null;
		return E_SUCCESS;
	}

	result MovePrevious(void)
	{
		TryReturn(__modCount == __list.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		if (__pNode == null)
		{
			__pNode = __list.__pListTail;
			if (__pNode == null)
			{
				return E_OUT_OF_RANGE;
			}
		}
		else
		{
			if (__pNode->pPrev != null)
			{
				__pNode = __pNode->pPrev;
			}
			else
			{
				return E_OUT_OF_RANGE;
			}
		}

		return E_SUCCESS;
	}

	result ResetLast(void)
	{
		return Reset();
	}

private:
	const LinkedListT< Type >& __list;
	__LinkedListNodeT< Type >* __pNode;
	int __modCount;

}; // __LinkedListEnumeratorT

}}} // Tizen::Base::Collection

#endif // _FCOL_LINKED_LIST_T_H_
