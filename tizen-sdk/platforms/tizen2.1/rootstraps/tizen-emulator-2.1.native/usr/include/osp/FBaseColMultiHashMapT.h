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
 * @file		FBaseColMultiHashMapT.h
 * @brief		This is the header file for the %MultiHashMapT class.
 *
 * This header file contains the declarations of the %MultiHashMapT class.
 */
#ifndef _FBASE_COL_MULTI_HASH_MAP_T_H_
#define _FBASE_COL_MULTI_HASH_MAP_T_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseColIComparerT.h>
#include <FBaseColIHashCodeProviderT.h>
#include <FBaseColIListT.h>
#include <FBaseColIMultiMapT.h>
#include <FBaseColMapEntryT.h>
#include <FBaseComparerT.h>
#include <FBaseFloat.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class KeyType, class ValueType > class __MultiHashMapEntryT;
template< class KeyType, class ValueType > class __MultiHashMapEnumeratorT;
template< class KeyType, class ValueType > class __EntryValueEnumeratorT;
template< class KeyType > class __MultiHashMapDefaultProviderT;

template< class ValueType > class __ValueNodeT;

/**
 * @class MultiHashMapT
 * @brief This class represents a template-based collection of associated keys and values that are organized based on the hash code of the key.
 *
 * @since 2.0
 *
 * The %MultiHashMapT class represents a template-based collection of associated keys and values that are organized based on the hash code of the key.
 * There is no limit on the number of elements with the same key, but duplicated elements with the same key are not allowed.
 * The key and value cannot be null. Several methods in the %MultiHashMapT class need an assignment(=) operator of KeyType, and assignment(=) and equivalent(==) operators of ValueType.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to use the %MultiHashMapT class.

 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::MultiHashMapTSample(void)
 *	{
 *		MultiHashMapT< int, int > map;
 *
 *		// Constructs a MultiHashMap instance with default capacity, load factor, hash code provider, and comparer
 *		map.Construct();
 *
 *		int key;
 *		int value;
 *
 *		map.Add(1, 1000);		// map.GetCount() : 1, map : (1 -> 1000)
 *		map.Add(2, 2000);		// map.GetCount() : 2, map : (1 -> 1000), (2 -> 2000)
 *		map.Add(3, 3000);		// map.GetCount() : 3, map : (1 -> 1000), (2 -> 2000), (3 -> 3000)
 *		map.Add(3, 30);			// map.GetCount() : 4, map : (1 -> 1000), (2 -> 2000), (3 -> 3000, 30)
 *
 *		// Gets values with the specified key
 *		key = 1;
 *		IEnumeratorT< int >*	pValueEnum = map.GetValuesN(key);
 *		while (pValueEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pValueEnum->GetCurrent(value);
 *		}
 *
 *		delete pValueEnum;
 *
 *		// Removes the values with the specified key
 *		key = 3;
 *		map.Remove(key);		// 30, 3000 removed
 *
 *		// Uses an enumerator to access elements in the map
 *		IMapEnumeratorT< int, int >*	pMapEnum = map.GetMapEnumeratorN();
 *		while (pMapEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pMapEnum->GetKey(key);
 *			pMapEnum->GetValue(value);
 *		}
 *
 *		delete pMapEnum;
 *	}
 *
 * @endcode
 */
template< class KeyType, class ValueType >
class MultiHashMapT
	: public IMultiMapT< KeyType, ValueType >
	, public Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	MultiHashMapT(void)
		: __pTable(null)
		, __count(0)
		, __capacity(0)
		, __loadFactor(0)
		, __threshold(0)
		, __pProvider(null)
		, __pComparer(null)
		, __defaultConstruct(false)
		, __modCount(0)
	{
	}

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~MultiHashMapT(void)
	{
		if (null != __pTable)
		{
			Reset();
			delete[] __pTable;
		}

		if (__defaultConstruct)
		{
			delete __pProvider;
			delete __pComparer;
		}

	}

	/**
	 * Initializes this instance of %MultiHashMapT with the given capacity and load factor.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the specified @c capacity or the @c loadFactor is negative.
	 * @remarks		The key type must be a primitive data type.
	 * @see			MultiHashMapT()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[%s] The capacity(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_INVALID_ARG), capacity);
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

		result r = E_SUCCESS;

		// set capacity
		if (capacity == 0)
		{
			__capacity = DEFAULT_CAPACITY;
		}
		else
		{
			__capacity = 1;
			while (__capacity < capacity)
			{
				__capacity <<= 1;
			}
		}

		// set load factor
		if (Float::Compare(loadFactor, 0) == 0)
		{
			__loadFactor = DEFAULT_LOAD_FACTOR;
		}
		else
		{
			__loadFactor = loadFactor;
		}

		// set threshold
		__threshold = static_cast< int >(__capacity * __loadFactor);

		// set hash code provider
		__pProvider = new __MultiHashMapDefaultProviderT< KeyType >();
		TryCatch(__pProvider != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		// set comparer
		__pComparer = new Tizen::Base::ComparerT< KeyType >();
		TryCatch(__pComparer != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		__defaultConstruct = true;

		__pTable = new __MultiHashMapEntryT< KeyType, ValueType >*[__capacity];
		TryCatch(__pTable != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		memset(__pTable, null, sizeof(__MultiHashMapEntryT< KeyType, ValueType >*) * __capacity);

		return r;

CATCH:
		__capacity = 0;
		delete __pProvider;
		delete __pComparer;

		return r;
	}

	/**
	 * Initializes this instance of %MultiHashMapT by copying the elements of the specified map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map			A map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor(0.75) is used.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @see			MultiHashMapT()
	 */
	result Construct(const IMultiMapT< KeyType, ValueType >& map, float loadFactor = 0.75)
	{
		TryReturn((loadFactor >= 0), E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

		result r = E_SUCCESS;

		if (Float::Compare(loadFactor, 0) == 0)
		{
			loadFactor = DEFAULT_LOAD_FACTOR;
		}

		int capacity = static_cast< int >(map.GetCount() / loadFactor) + 1;
		r = Construct(capacity, loadFactor);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		r = AddAll(map);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		return r;

CATCH:
		Reset();
		delete[] __pTable;
		__pTable = null;

		__capacity = 0;

		__pProvider = null;
		delete __pProvider;

		__pComparer = null;
		delete __pComparer;

		return r;
	}

	/**
	 * Initializes this instance of %MultiHashMapT that is empty,
	 * with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity @n
	 *							If it is @c 0, the default capacity(16) is used.
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor(0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the specified @c capacity or the @c loadFactor is negative.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			MultiHashMapT()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProviderT< KeyType >& provider,
					 const IComparerT< KeyType >& comparer)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[%s] The capacity(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_INVALID_ARG), capacity);
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

		result r = E_SUCCESS;
		// set capacity
		if (capacity == 0)
		{
			__capacity = DEFAULT_CAPACITY;
		}
		else
		{
			__capacity = 1;
			while (__capacity < capacity)
			{
				__capacity <<= 1;
			}
		}

		// set load factor
		if (Float::Compare(loadFactor, 0) == 0)
		{
			__loadFactor = DEFAULT_LOAD_FACTOR;
		}
		else
		{
			__loadFactor = loadFactor;
		}

		// set threshold
		__threshold = static_cast< int >(__capacity * __loadFactor);

		// set hash code provider
		__pProvider = const_cast< IHashCodeProviderT< KeyType >* >(&provider);

		// set comparer
		__pComparer = const_cast< IComparerT< KeyType >* >(&comparer);

		__pTable = new __MultiHashMapEntryT< KeyType, ValueType >*[__capacity];
		TryCatch(__pTable != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		memset(__pTable, null, sizeof(__MultiHashMapEntryT< KeyType, ValueType >*) * __capacity);

		return r;

CATCH:
		__capacity = 0;
		__pProvider = null;
		__pComparer = null;

		return r;
	}

	/**
	 * Initializes this instance of %MultiHashMapT by copying the elements of the specified map,
	 * with the specified load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map			A map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor(0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			MultiHashMapT()
	 */
	result Construct(const IMultiMapT< KeyType, ValueType >& map, float loadFactor, const IHashCodeProviderT< KeyType >& provider,
					 const IComparerT< KeyType >& comparer)
	{
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

		result r = E_SUCCESS;

		if (Float::Compare(loadFactor, 0) == 0)
		{
			loadFactor = DEFAULT_LOAD_FACTOR;
		}

		int capacity = static_cast< int >(map.GetCount() / loadFactor) + 1;

		r = Construct(capacity, loadFactor, provider, comparer);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		r = AddAll(map);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		return r;

CATCH:
		Reset();
		delete[] __pTable;
		__pTable = null;

		__capacity = 0;
		__pProvider = null;
		__pComparer = null;

		return r;
	}

	/**
	 * Adds the specified key-value pair to this map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		A key of the value to add
	 * @param[in]	value	A value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified pair of @c key and @c value already exists.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @remarks		SetItem() can be used to set value to a key that does not already exist.
	 *				However, setting a value to a key that already exists overwrites the value.
	 * @see			Remove()
	 * @see			SetValue()
	 */
	virtual result Add(const KeyType& key, const ValueType& value)
	{
		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);
		__ValueNodeT< ValueType >* pNode = null;
		__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i];
		while (null != pEntry)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				if (cmpResult == 0)
				{
					pNode = pEntry->pList;
					while (true)
					{
						if (pNode->value == value)
						{
							return E_OBJ_ALREADY_EXIST;
						}

						if (pNode->pNext != null)
						{
							pNode = pNode->pNext;
						}
						else
						{
							pEntry->modCount++;
							break;
						}
					}
					break;
				}
			}
			pEntry = pEntry->pNext;
		}

		__ValueNodeT< ValueType >* pNewNode = new __ValueNodeT< ValueType >(value);
		TryReturn(pNewNode != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		// key is not exist in this map.
		if (pEntry == null)
		{
			__MultiHashMapEntryT< KeyType, ValueType >* pNewEntry = new __MultiHashMapEntryT< KeyType, ValueType >(key, pNewNode, __pTable[i],
																												   hash);
			TryReturn(pNewEntry != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
			__pTable[i] = pNewEntry;
		}
		// key is already exist in this map, but value is not.
		else
		{
			// pNode is the last value associated to the key
			pNode->pNext = pNewNode;
		}

		__modCount++;

		if (__count++ >= __threshold)
		{
			r = Resize(__capacity * 2);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
		}

		return E_SUCCESS;
	}

	/**
	 * Gets an enumerator of this map.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the %IMapEnumeratorT derived class) of this map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If the key has multiple values, the Enumeration proceeds as follows: {A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IEnumeratorT< MapEntryT< KeyType, ValueType > >* GetEnumeratorN(void) const
	{
		result r = E_SUCCESS;

		__MultiHashMapEnumeratorT< KeyType, ValueType >* pEnum = new __MultiHashMapEnumeratorT< KeyType, ValueType >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		SetLastResult(E_SUCCESS);
		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Gets an IMapEnumerator of this map.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the %IMapEnumeratorT derived class) of this map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If the key has multiple values, the Enumeration proceeds like this: {A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumeratorT< KeyType, ValueType >* GetMapEnumeratorN(void) const
	{
		return dynamic_cast< IMapEnumeratorT< KeyType, ValueType >* >(GetEnumeratorN());
	}

	/**
	 * Gets an enumerator of the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumeratorT derived class) of the values associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	A key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual IEnumeratorT< ValueType >* GetValuesN(const KeyType& key) const
	{
		result r = E_OBJ_NOT_FOUND;

		int hash = Hash(key);
		int i = hash & (__capacity - 1);
		IEnumeratorT< ValueType >* pEnum = null;

		for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryCatch(r == E_SUCCESS, r = E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				if (0 == cmpResult)
				{
					pEnum = new __EntryValueEnumeratorT< KeyType, ValueType >(*pEntry, pEntry->modCount);
					TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
					r = E_SUCCESS;
					break;
				}

				r = E_OBJ_NOT_FOUND;
			}
		}

		SetLastResult(r);
		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Gets a list of all unique keys in this map.
	 *
	 * @since 2.0
	 *
	 * @return		A list of all unique keys in this map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IListT< KeyType >* GetKeysN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;
		int keyCount = 0;

		ArrayListT< KeyType >* pList = new ArrayListT< KeyType >();
		r = pList->Construct(__count);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		for (int i = 0; i < __capacity; i++)
		{
			for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				r = pList->Add(pEntry->key);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
				keyCount++;
			}
		}

		return pList;

CATCH:
		delete pList;

		SetLastResult(r);
		return null;
	}

	/**
	 * Gets a list of all the values in this map.
	 *
	 * @since 2.0
	 *
	 * @return		A list of all the values in this map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IListT< ValueType >* GetValuesN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		ArrayListT< ValueType >* pList = new ArrayListT< ValueType >();
		r = pList->Construct(__count);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		for (int i = 0; i < __capacity; i++)
		{
			for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
				{
					r = pList->Add(pNode->value);
					TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
				}
			}
		}

		return pList;

CATCH:
		delete pList;

		SetLastResult(r);
		return null;
	}

	/**
	 * Removes all the values for the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key)
	{
		result r = E_OBJ_NOT_FOUND;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		__MultiHashMapEntryT< KeyType, ValueType >* pPrev = __pTable[i];
		for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				r = E_OBJ_NOT_FOUND;

				if (cmpResult == 0)
				{
					__modCount++;
					if (pPrev == pEntry)
					{
						__pTable[i] = pEntry->pNext;
					}
					else
					{
						pPrev->pNext = pEntry->pNext;
					}

					__ValueNodeT< ValueType >* pNode = pEntry->pList;
					while (null != pNode)
					{
						__ValueNodeT< ValueType >* pTemp = pNode;
						pNode = pNode->pNext;
						delete pTemp;
						__count--;
					}
					delete pEntry;
					r = E_SUCCESS;
					break;
				}
			}
			pPrev = pEntry;
		}

		return r;
	}

	/**
	 * Removes the specified value associated with the specified key. @n
	 * The key is also removed if there is no value associated with it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key whose mapping is to remove from the map
	 * @param[in]	value	The value to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key and @c value pair is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key, const ValueType& value)
	{
		result r = E_OBJ_NOT_FOUND;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		__MultiHashMapEntryT< KeyType, ValueType >* pPrev = __pTable[i];
		for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				r = E_OBJ_NOT_FOUND;
				if (cmpResult == 0)
				{
					__ValueNodeT< ValueType >* pPrevNode = pEntry->pList;
					for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
					{
						if (value == pNode->value)
						{
							__modCount++;
							__count--;
							if (pPrevNode == pNode)
							{
								pEntry->pList = pNode->pNext;
							}
							else
							{
								pPrevNode->pNext = pNode->pNext;
							}

							delete pNode;

							pEntry->modCount++;

							if (null == pEntry->pList)
							{
								if (pPrev == pEntry)
								{
									__pTable[i] = pEntry->pNext;
								}
								else
								{
									pPrev->pNext = pEntry->pNext;
								}
								delete pEntry;
							}
							r = E_SUCCESS;
							break;
						}
						pPrevNode = pNode;
					}
					if (!IsFailed(r))
					{
						break;
					}
				}
			}
			pPrev = pEntry;
		}

		return r;
	}

	/**
	 * Removes all key-value pairs in this map.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void)
	{
		if (__count > 0)
		{
			__modCount++;
			Reset();
			__count = 0;
		}
	}

	/**
	 * Replaces the value associated with the key with the specified @c newValue.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key			A key
	 * @param[in]	value		A value to replace
	 * @param[in]	newValue	A new value to replace the existing value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	  The specified @c key and @c value pair is not found in the map.
	 * @remarks		To add a new key-value pair, use the Add() method.
	 * @see			Add()
	 * @see			GetValuesN()
	 */
	virtual result SetValue(const KeyType& key, const ValueType& value, const ValueType& newValue)
	{
		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);
		__ValueNodeT< ValueType >* pNode = null;
		bool pairExist = false;
		__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i];
		while (null != pEntry)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				if (cmpResult == 0)
				{
					pNode = pEntry->pList;
					while (true)
					{
						if (pNode->value == value)
						{
							__modCount++;
							pNode->value = newValue;
							pairExist = true;
							break;
						}
						if (pNode->pNext != null)
						{
							pNode = pNode->pNext;
						}
						else
						{
							pEntry->modCount++;
							break;
						}
					}
					break;
				}
			}
			pEntry = pEntry->pNext;
		}

		if (!pairExist)
		{
			r = E_OBJ_NOT_FOUND;
		}

		return r;
	}

	/**
	 * Gets the number of values currently stored in this map.
	 *
	 * @since 2.0
	 *
	 * @return		The number of values currently stored in this map
	 */
	virtual int GetCount(void) const
	{
		return __count;
	}

	/**
	 * Gets the number of values whose keys match the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key	A key to locate
	 * @param[out]	count	The number of values whose key is @c key
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 */
	virtual result GetCount(const KeyType& key, int& count) const
	{
		result r = E_OBJ_NOT_FOUND;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				if (0 == cmpResult)
				{
					int __count = 0;
					for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
					{
						__count++;
					}
					count = __count;
					r = E_SUCCESS;
					break;
				}

				r = E_OBJ_NOT_FOUND;
			}
		}

		return r;
	}

	/**
	 * Checks whether the map contains the specified key and value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[in]	value 	The value to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key and value pair, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The current state of the instance prohibits the execution of the specified operation, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsKey()
	 * @see			ContainsValue()
	 */
	virtual result Contains(const KeyType& key, const ValueType& value, bool& out) const
	{
		out = false;

		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				if (IsFailed(r))
				{
					AppLogException("[%s] Propagating.", GetErrorMessage(r));
					out = false;
					return E_INVALID_ARG;
				}

				if (cmpResult == 0)
				{
					for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
					{
						if (value == pNode->value)
						{
							r = E_SUCCESS;
							out = true;
							break;
						}
					}
					break;
				}
			}
		}

		return E_SUCCESS;
	}

	/**
	 * Checks whether the map contains the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 * @see			Contains()
	 */
	virtual result ContainsKey(const KeyType& key, bool& out) const
	{
		out = false;
		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				if (IsFailed(r))
				{
					AppLogException("[%s] Propagating.", GetErrorMessage(r));
					out = false;
					return E_INVALID_ARG;
				}
				if (cmpResult == 0)
				{
					out = true;
					break;
				}
			}
		}

		return E_SUCCESS;
	}

	/**
	 * Checks whether the map contains the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value 	The value to locate
	 *
	 * @see			ContainsKey()
	 * @see			Contains()
	 */
	virtual bool ContainsValue(const ValueType& value) const
	{
		bool out = false;
		for (int i = 0; i < __capacity; i++)
		{
			for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
				{
					if (value == pNode->value)
					{
						out = true;
						break;
					}
				}

				if (out)
					break;
			}

			if (out)
				break;
		}

		return out;
	}

	/**
	 * Compares the specified instance to the current instance for equality.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two instances are equal, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true only if the specified object is also an instance of the %MultiHashMapT class,
	 *				both maps have the same number of elements, and both maps contain the same elements.
	 */
	virtual bool Equals(const Object& obj) const
	{
		result r = E_SUCCESS;
		bool out = true;

		const MultiHashMapT< KeyType, ValueType >* other = dynamic_cast< const MultiHashMapT< KeyType, ValueType >* >(&obj);
		if (null == other) // obj is not MultiHashMapT<KeyType, ValueType>
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
			for (int i = 0; i < __capacity; i++)
			{
				for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
				{
					for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
					{
						r = other->Contains(pEntry->key, pNode->value, out);
					}
					if (!out)
					{
						break;
					}
				}
				if (!out)
				{
					break;
				}
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

		for (int i = 0; i < __capacity; i++)
		{
			for (__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				for (__ValueNodeT< ValueType >* pNode = pEntry->pList; null != pNode; pNode = pNode->pNext)
				{
					hash += reinterpret_cast< int >(&pNode->value);
				}
				hash += reinterpret_cast< int >(&pEntry->key);
			}
		}
		return hash;
	}
private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map An instance of %MultiHashMapT to initialize the current instance
	 */
	MultiHashMapT(const MultiHashMapT< KeyType, ValueType >& map);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map An instance of %MultiHashMapT
	 */
	MultiHashMapT< KeyType, ValueType >& operator =(const MultiHashMapT< KeyType, ValueType >& map);

	/**
	 * Copies all the pairs from the specified map to this map.
	 *
	 * @return		An error code
	 * @param[in]	map The map to copy
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c map is modified during the operation of this method.
	 */
	result AddAll(const IMultiMapT< KeyType, ValueType >& map)
	{
		result r = E_SUCCESS;

		IMultiMapT< KeyType, ValueType >* pMap = const_cast< IMultiMapT< KeyType, ValueType >* >(&map);
		IMapEnumeratorT< KeyType, ValueType >* pMapEnum = pMap->GetMapEnumeratorN();

		TryCatch(pMapEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while (true)
		{
			KeyType key;
			ValueType value;

			r = pMapEnum->MoveNext();
			// enumerator is reached to the end of collection
			if (E_OUT_OF_RANGE == r)
			{
				r = E_SUCCESS;
				break;
			}
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pMapEnum->GetKey(key);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pMapEnum->GetValue(value);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = Add(key, value);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
		}

		if (null != pMapEnum)
		{
			delete pMapEnum;
		}
		return r;

CATCH:
		if (null != pMapEnum)
		{
			delete pMapEnum;
		}
		return r;
	}

	/**
	 * Gets a hash value for the specified object.
	 *
	 * @return		The hash value for the specified object
	 * @param[in]	obj     The object to get hash value
	 */
	int Hash(const KeyType& obj) const
	{
		int h = __pProvider->GetHashCode(obj);

		h ^= (h >> 20) ^ (h >> 12);

		return h ^ (h >> 7) ^ (h >> 4);
	}

	/**
	 * Resizes the contents of this map into a new array with a
	 * larger capacity. @n
	 * This method is called automatically when the
	 * number of keys in this map reaches its threshold.
	 *
	 * @return		An error code
	 * @param[in]	newCapacity	The new capacity @n
	 *							It must be a power of 2 and must be greater than current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Resize(int newCapacity)
	{
		result r = E_SUCCESS;
		__MultiHashMapEntryT< KeyType, ValueType >** newTable = new __MultiHashMapEntryT< KeyType, ValueType >*[newCapacity];
		TryCatch(newTable != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
		for (int i = 0; i < newCapacity; i++)
		{
			newTable[i] = null;
		}

		for (int i = 0; i < __capacity; i++)
		{
			__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i];
			while (null != pEntry)
			{
				__MultiHashMapEntryT< KeyType, ValueType >* pNext = pEntry->pNext;
				int i = pEntry->hash & (newCapacity - 1);
				pEntry->pNext = newTable[i];
				newTable[i] = pEntry;
				pEntry = pNext;
			}
		}

		delete[] __pTable;
		__pTable = newTable;
		__capacity = newCapacity;
		__threshold = static_cast< int >(__capacity * __loadFactor);

		return r;

CATCH:
		return r;
	}

	/**
	 *  Clears all key-value pairs in this map.
	 *
	 */
	void Reset(void)
	{
		for (int i = 0; i < __capacity; i++)
		{
			__MultiHashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i];
			while (null != pEntry)
			{
				__MultiHashMapEntryT< KeyType, ValueType >* pNext = pEntry->pNext;
				__ValueNodeT< ValueType >* pNode = pEntry->pList;
				while (null != pNode)
				{
					__ValueNodeT< ValueType >* pTemp = pNode;
					pNode = pNode->pNext;
					delete pTemp;
				}
				delete pEntry;
				pEntry = pNext;
			}
			__pTable[i] = null;
		}
	}

	__MultiHashMapEntryT< KeyType, ValueType >** __pTable;
	int __count;
	int __capacity;
	float __loadFactor;
	int __threshold;
	IHashCodeProviderT< KeyType >* __pProvider;
	IComparerT< KeyType >* __pComparer;
	bool __defaultConstruct;
	int __modCount;

	static const int DEFAULT_CAPACITY = 16;
	static const float DEFAULT_LOAD_FACTOR;

	friend class __MultiHashMapEnumeratorT< KeyType, ValueType >;

}; // MultiHashMapT

//
// @class	__ValueNodeT
// @brief	This class is a node for MultiHashMapT.
// @since 2.0
//
template< class ValueType >
class __ValueNodeT
	: public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	v	An object to include in this node
	 */
	__ValueNodeT(const ValueType& v)
		: pNext(null)
		, value(v)
	{
	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__ValueNodeT(void)
	{
	}

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	__ValueNodeT< ValueType >* pNext;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	ValueType value;

}; // __ValueNodeT

//
// @class	__MultiHashMapEntryT
// @brief	This class is an entry for MultiHashMapT class.
// @since 2.0
//
template< class KeyType, class ValueType >
class __MultiHashMapEntryT
	: public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	keyType		A key to include in this entry
	 * @param[in]	list	A list of values whose key is specified @n
	 *						It cannot be @c null.
	 * @param[in]	next	A pointer to the next entry
	 * @param[in]	h		An hash value of the key
	 */
	__MultiHashMapEntryT(const KeyType& keyType, __ValueNodeT< ValueType >* list, __MultiHashMapEntryT< KeyType, ValueType >* next, int h)
		: key(keyType)
		, pList(list)
		, pNext(next)
		, hash(h)
		, modCount(0)
	{
	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__MultiHashMapEntryT(void)
	{
	}

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	KeyType key;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	__ValueNodeT< ValueType >* pList;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	__MultiHashMapEntryT< KeyType, ValueType >* pNext;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	int hash;

	/**
	 * Internal variable.
	 *
	 * @since 2.0
	 */
	int modCount;

	friend class __EntryValueEnumeratorT< KeyType, ValueType >;

}; // __MultiHashMapEntryT

//
// @class	__MultiHashMapEnumeratorT
// @brief	This class is an implementation of IMapEnumeratorT for %MultiHashMapT.
// @since 2.0
//
template< class KeyType, class ValueType >
class __MultiHashMapEnumeratorT
	: public IMapEnumeratorT< KeyType, ValueType >
	, public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	map			A map to enumerate
	 * @param[in]	modCount	The modification count to detect the change in the map
	 */
	__MultiHashMapEnumeratorT(const MultiHashMapT< KeyType, ValueType >& map, int modCount)
		: __map(map)
		, __modCount(modCount)
		, __pEntry(null)
		, __pNode(null)
		, __index(-1)
	{
	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__MultiHashMapEnumeratorT(void)
	{
	}

	/**
	 * Gets the current object in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The current object
	 * @exception	E_INVALID_OPERATION	  Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	 *                                   - The map is modified after this enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetCurrent(MapEntryT< KeyType, ValueType >& obj) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__pEntry != null && __pNode != null), E_INVALID_OPERATION,
			"[%s] Invalid position(pEntry or pNode is null).", GetErrorMessage(E_INVALID_OPERATION));

		obj = MapEntryT< KeyType, ValueType >(__pEntry->key, __pNode->value);
		return E_SUCCESS;
	}

	/**
	 * Moves this enumerator to the next element of the map. @n
	 * After the enumerator is first created or reset using the Reset() method,
	 * the first call to this method positions the enumerator to the first element in the @c collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the map is modified after this enumerator is created.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the map.
	 * @see			Reset()
	 */
	result MoveNext(void)
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		result r = E_SUCCESS;
		if ((null != __pNode) && (__pNode->pNext != null))
		{
			__pNode = __pNode->pNext;
		}
		else if ((null != __pEntry) && (__pEntry->pNext != null))
		{
			__pEntry = __pEntry->pNext;
			__pNode = __pEntry->pList;
		}
		else
		{
			while (true)
			{
				if (++__index >= static_cast< int >(__map.__capacity))
				{
					// Do not log the E_OUT_OF_RANGE, because it is normal or trivial in most cases.
					r = E_OUT_OF_RANGE;
					break;
				}
				__pEntry = __map.__pTable[__index];
				if (null != __pEntry)
				{
					__pNode = __pEntry->pList;
					break;
				}
			}
		}

		return r;
	}

	/**
	 * Positions this enumerator before the first element in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the map is modified after this enumerator is created.
	 */
	result Reset(void)
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__index = -1;
		__pEntry = null;
		__pNode = null;
		return E_SUCCESS;
	}

	/**
	 * Gets the current key in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	key The current key
	 * @exception	E_INVALID_OPERATION	  Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	 *									-  The map is modified after this enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetKey(KeyType& key) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__pEntry != null && __pNode != null), E_INVALID_OPERATION,
			"[%s] Invalid position(pEntry or pNode is null).", GetErrorMessage(E_INVALID_OPERATION));

		key = __pEntry->key;
		return E_SUCCESS;
	}

	/**
	 * Gets the current value in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value The current value
	 * @exception	E_INVALID_OPERATION	  Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	 *									- The map is modified after the enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetValue(ValueType& value) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__pEntry != null && __pNode != null), E_INVALID_OPERATION,
			"[%s] Invalid position(pEntry or pNode is null).", GetErrorMessage(E_INVALID_OPERATION));

		value = __pNode->value;
		return E_SUCCESS;
	}

private:
	const MultiHashMapT< KeyType, ValueType >& __map;
	int __modCount;
	__MultiHashMapEntryT< KeyType, ValueType >* __pEntry;
	__ValueNodeT< ValueType >* __pNode;
	int __index;

}; // __MultiHashMapEnumeratorT

//
// @class	__EntryValueEnumeratorT
// @brief	This class is an implementation of IEnumeratorT to enumerate values whose key is the same.
// @since 2.0
//
template< class KeyType, class ValueType >
class __EntryValueEnumeratorT
	: public IEnumeratorT< ValueType >
	, public Object
{
public:
	/**
	 * Initializes an instance of __EntryValueEnumeratorT with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	entry		An entry to enumerate
	 * @param[in]	modCount	The modification count to detect the change in the entry
	 */
	__EntryValueEnumeratorT(const __MultiHashMapEntryT< KeyType, ValueType >& entry, int modCount)
		: __entry(entry)
		, __modCount(modCount)
		, __pNode(null)
	{
	}


	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__EntryValueEnumeratorT(void)
	{
	}

	/**
	 * Gets the current value in the entry.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The current value
	 * @exception	E_INVALID_OPERATION	Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	 *									- The entry is modified after this enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetCurrent(ValueType& obj) const
	{
		TryReturn((__modCount == __entry.modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn(__pNode != null, E_INVALID_OPERATION, "[%s] Invalid position(pNode is null).", GetErrorMessage(E_INVALID_OPERATION));

		obj = __pNode->value;
		return E_SUCCESS;
	}

	/**
	 * Moves this enumerator to the next element of the entry. @n
	 * After the enumerator is first created or reset using the Reset() method,
	 * the first call to this method positions the enumerator to the first element in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the entry is modified after this enumerator is created.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the entry.
	 * @see			Reset()
	 */
	result MoveNext(void)
	{
		TryReturn((__modCount == __entry.modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		result r = E_SUCCESS;
		if (null == __pNode)
		{
			__pNode = __entry.pList;
			AppAssert(null != __pNode);
		}
		else if ((null != __pNode) && (__pNode->pNext != null))
		{
			__pNode = __pNode->pNext;
		}
		else
		{
			// Do not log the E_OUT_OF_RANGE, because it is normal or trivial in most cases.
			r = E_OUT_OF_RANGE;
		}

		return r;
	}

	/**
	 * Positions this enumerator before the first element in the entry.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the entry is modified after this enumerator is created.
	 */
	result Reset(void)
	{
		TryReturn((__modCount == __entry.modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__pNode = null;
		return E_SUCCESS;
	}

private:
	const __MultiHashMapEntryT< KeyType, ValueType >& __entry;
	int __modCount;
	__ValueNodeT< ValueType >* __pNode;

}; // __EntryValueEnumeratorT

//
// @class	__MultiHashMapDefaultProviderT
// @brief	This class is an implementation of IHashCodeProviderT for HashMap.
// @since 2.0
//
template< class KeyType >
class __MultiHashMapDefaultProviderT
	: public IHashCodeProviderT< KeyType >
	, public Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since 2.0
	*/
	__MultiHashMapDefaultProviderT(void) {}

	/**
	* This is the destructor for this class.
	*
	* @since 2.0
	*/
	virtual ~__MultiHashMapDefaultProviderT(void) {}

	// Operation

	/**
	* Gets the hash code of the specified instance.
	*
	* @since 2.0
	*
	* @return		The hash code
	* @see			Tizen::Base::Object::GetHashCode()
	*/
	virtual int GetHashCode(const KeyType& obj) const
	{
		return (int) obj;
	}

}; // __MultiHashMapDefaultProviderT

template< class KeyType, class ValueType >
const float MultiHashMapT< KeyType, ValueType >::DEFAULT_LOAD_FACTOR = 0.75;

}}}   // Tizen::Base::Collection

#endif //_FBASE_COL_MULTI_HASH_MAP_T_H_
