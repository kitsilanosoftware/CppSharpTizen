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
 * @file		FBaseColHashMapT.h
 * @brief		This is the header file for the %HashMapT class.
 *
 * This header file contains the declarations of the %HashMapT class.
 */
#ifndef _FBASE_COL_HASH_MAP_T_H_
#define _FBASE_COL_HASH_MAP_T_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseColIComparerT.h>
#include <FBaseColIHashCodeProviderT.h>
#include <FBaseColIListT.h>
#include <FBaseColIMapT.h>
#include <FBaseColArrayListT.h>
#include <FBaseColMapEntryT.h>
#include <FBaseComparerT.h>
#include <FBaseFloat.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class KeyType, class ValueType > class __HashMapEntryT;
template< class KeyType, class ValueType > class __HashMapEnumeratorT;
template< class KeyType > class __HashMapDefaultProviderT;

/**
 * @class HashMapT
 * @brief This class provides a template-based collection of associated keys and values
 * that are organized based on the hash code of the key.
 *
 * @since 2.0
 *
 * The %HashMapT class provides a template-based collection of associated keys and values
 * that are organized based on the hash code of the key.
 * It contains unique keys and each key maps to one single value.
 * The key and value cannot be a null reference. Several methods in the %HashMapT class need assignment (=) operators of KeyType and ValueType.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to use the %HashMapT class.

 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::HashMapTSample(void)
 *	{
 *		HashMapT<int, int> map;
 *
 *		// Constructs a %HashMapT instance with default capacity, load factor, hash code provider, and comparer
 *		map.Construct();
 *
 *		map.Add(1, 100);	// map.GetCount() : 1
 *		map.Add(2, 200);	// map.GetCount() : 2
 *		map.Add(3, 300);	// map.GetCount() : 3
 *
 *		int key;
 *		int value;
 *
 *		// Gets a value with the specified key
 *		key = 1;
 *		map.GetValue(key, value);	// value : 100
 *
 *		// Removes the value with the specified key
 *		map.Remove(key);
 *
 *		// Uses an enumerator to access elements in the map
 *		IMapEnumeratorT<int, int>*	pMapEnum = map.GetMapEnumeratorN();
 *		while (pMapEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pMapEnum->GetKey(key);
 *			pMapEnum->GetValue(value);
 *		}
 *
 *		delete pMapEnum;
 *	}
 * @endcode
 */
template< class KeyType, class ValueType >
class HashMapT
	: public IMapT< KeyType, ValueType >
	, public Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	HashMapT(void)
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
	virtual ~HashMapT(void)
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
	 * Initializes this instance of %HashMapT with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c capacity or the @c loadFactor is negative.
	 * @remarks		To work properly, the key type must be of a primitive number type.
	 * @see			HashMapT()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[%s] The capacity(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_INVALID_ARG), capacity);
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

		result r = E_SUCCESS;

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

		if (Float::Compare(loadFactor, 0) == 0)
		{
			__loadFactor = DEFAULT_LOAD_FACTOR;
		}
		else
		{
			__loadFactor = loadFactor;
		}

		__threshold = static_cast< int >(__capacity * __loadFactor);

		__pProvider = new __HashMapDefaultProviderT< KeyType >();
		TryCatch(__pProvider != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		__pComparer = new Tizen::Base::ComparerT< KeyType >();
		TryCatch(__pComparer != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		__defaultConstruct = true;

		__pTable = new __HashMapEntryT< KeyType, ValueType >*[__capacity];
		TryCatch(__pTable != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		memset(__pTable, null, sizeof(__HashMapEntryT< KeyType, ValueType >*) * __capacity);

		return r;

CATCH:
		__capacity = 0;
		delete __pProvider;
		delete __pComparer;

		return r;
	}

	/**
	 * Initializes this instance of %HashMapT by copying the elements of a specified map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map			The map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @see			HashMapT()
	 */
	result Construct(const IMapT< KeyType, ValueType >& map, float loadFactor = 0.75)
	{
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

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

		delete __pProvider;
		__pProvider = null;

		delete __pComparer;
		__pComparer = null;

		return r;
	}

	/**
	 * Initializes this instance of an empty %HashMapT class, with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity @n
	 *							If it is @c 0, the default capacity (16) is used.
	 * @param[in]	loadFactor	The maximum ratio of the elements to buckets @n
	 *							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProviderT-derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparerT-derived class to use when comparing keys
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	Either of the following conditions has occurred: @n
	 *								- A specified input parameter is invalid. @n
	 *								- The specified @c capacity is negative. @n
	 *								- The @c loadFactor is negative.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMapT()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProviderT< KeyType >& provider,
					 const IComparerT< KeyType >& comparer)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[%s] The capacity(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_INVALID_ARG), capacity);
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

		result r = E_SUCCESS;

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

		if (Float::Compare(loadFactor, 0) == 0)
		{
			__loadFactor = DEFAULT_LOAD_FACTOR;
		}
		else
		{
			__loadFactor = loadFactor;
		}

		__threshold = static_cast< int >(__capacity * __loadFactor);

		__pProvider = const_cast< IHashCodeProviderT< KeyType >* >(&provider);

		__pComparer = const_cast< IComparerT< KeyType >* >(&comparer);

		__pTable = new __HashMapEntryT< KeyType, ValueType >*[__capacity];
		TryCatch(__pTable != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		memset(__pTable, null, sizeof(__HashMapEntryT< KeyType, ValueType >*) * __capacity);

		return r;

CATCH:
		__capacity = 0;
		__pProvider = null;
		__pComparer = null;

		return r;
	}

	/**
	 * Initializes this instance of %HashMapT by copying the elements of a specified map,
	 * with a specified load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map			The map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *                           If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProviderT-derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparerT-derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The @c loadFactor is negative. @n
	 *									- The @c provider is a @c null or the @c comparer is a @c null.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMapT()
	 */
	result Construct(const IMapT< KeyType, ValueType >& map, float loadFactor, const IHashCodeProviderT< KeyType >& provider,
					 const IComparerT< KeyType >& comparer)
	{
		TryReturn((loadFactor >= 0), E_INVALID_ARG, "[%s] The loadFactor(%f) MUST be greater than or equal to 0.0.", GetErrorMessage(E_INVALID_ARG), loadFactor);

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
	 * Adds the specified key-value pair to a map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key of the value to add
	 * @param[in]	value	The value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key already exists.
	 * @see Remove()
	 */
	virtual result Add(const KeyType& key, const ValueType& value)
	{
		__HashMapEntryT< KeyType, ValueType >* pNewEntry;

		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);
		bool out = false;

		r = ContainsKey(key, out);
		TryReturn((!out), E_OBJ_ALREADY_EXIST, "[%s] The key is already exist in this collection.", GetErrorMessage(E_OBJ_ALREADY_EXIST));
		TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));

		r = E_SUCCESS;
		pNewEntry = new __HashMapEntryT< KeyType, ValueType >(key, value, __pTable[i], hash);
		TryReturn(pNewEntry != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
		__pTable[i] = pNewEntry;
		__modCount++;

		if (__count++ >= __threshold)
		{
			r = Resize(__capacity * 2);
			TryReturn(r == E_SUCCESS, r, "[%s] Propagating.", GetErrorMessage(r));
		}

		return E_SUCCESS;
	}

	/**
	 * Gets the elements of a map in an instance of the IMapEnumeratorT-derived class.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IMapEnumeratorT-derived class if successful, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IEnumeratorT< MapEntryT< KeyType, ValueType > >* GetEnumeratorN(void) const
	{
		result r = E_SUCCESS;

		__HashMapEnumeratorT< KeyType, ValueType >* pEnum = new __HashMapEnumeratorT< KeyType, ValueType >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		SetLastResult(E_SUCCESS);
		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Gets the elements of a map in an instance of the IMapEnumeratorT class.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IMapEnumeratorT class if successful, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumeratorT< KeyType, ValueType >* GetMapEnumeratorN(void) const
	{
		return dynamic_cast< IMapEnumeratorT< KeyType, ValueType >* >(GetEnumeratorN());
	}

	/**
	 * Gets the value associated with a specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	The key to locate
	 * @param[out]	value	The value associated with the key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									The comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			SetValue()
	 */
	virtual result GetValue(const KeyType& key, ValueType& value) const
	{
		result r = E_OBJ_NOT_FOUND;

		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

				if (cmpResult == 0)
				{
					value = pEntry->value;
					return E_SUCCESS;
				}
			}
		}

		return E_OBJ_NOT_FOUND;
	}

	/**
	 * Gets the value associated with a specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	The key to locate
	 * @param[out]	value	The value associated with the key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			SetValue()
	 */
	virtual result GetValue(const KeyType& key, ValueType& value)
	{
		return (static_cast< const HashMapT< KeyType, ValueType >* >(this))->GetValue(key, value);
	}

	/**
	 * Gets a list of all the keys in a map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to an IListT object containing all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IListT interface returned by the GetValuesN() method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IListT< KeyType >* GetKeysN(void) const
	{
		result r = E_SUCCESS;

		ArrayListT< KeyType >* pList = new ArrayListT< KeyType >();
		TryCatch(pList != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		r = pList->Construct(__count);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				r = pList->Add(pEntry->key);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		SetLastResult(E_SUCCESS);
		return pList;

CATCH:
		delete pList;

		SetLastResult(r);
		return null;
	}

	/**
	 * Gets all the values in a map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to an IListT object containing all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IListT< ValueType >* GetValuesN(void) const
	{
		result r = E_SUCCESS;

		ArrayListT< ValueType >* pList = new ArrayListT< ValueType >();
		TryCatch(pList != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		r = pList->Construct(__count);
		TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				r = pList->Add(pEntry->value);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		SetLastResult(E_SUCCESS);
		return pList;

CATCH:
		delete pList;

		SetLastResult(r);
		return null;
	}

	/**
	 * Removes the value associated with a specified key.
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

		__HashMapEntryT< KeyType, ValueType >* pPrev = __pTable[i];
		for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

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

					delete pEntry;
					__count--;

					return E_SUCCESS;
				}
			}
			pPrev = pEntry;
		}

		return E_OBJ_NOT_FOUND;
	}

	/**
	 * Removes all key-value pairs in the map.
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
	 * Replaces the value associated with a specified key with a new value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key for which the value is to replace
	 * @param[in]	value	The new value to replace
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @see			Add()
	 * @see			GetValue()
	 */
	virtual result SetValue(const KeyType& key, const ValueType& value)
	{
		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		int cmpResult = -1;
		for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));
				if (cmpResult == 0)
				{
					pEntry->value = value;
					break;
				}
			}
		}

		if (cmpResult != 0)
		{
			r = E_OBJ_NOT_FOUND;
		}

		__modCount++;

		return r;
	}

	/**
	 * Gets the number of pairs currently stored in a map.
	 *
	 * @since 2.0
	 *
	 * @return		The pairs stored in the map
	 */
	virtual int GetCount(void) const
	{
		return __count;
	}

	/**
	 * Checks whether a map contains the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key	The key to locate
	 * @param[out]	out 	Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 */
	virtual result ContainsKey(const KeyType& key, bool& out) const
	{
		out = false;

		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagating.", GetErrorMessage(r));

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
	 * Checks whether a map contains the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey()
	 */
	virtual bool ContainsValue(const ValueType& value) const
	{
		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				if (value == pEntry->value)
				{
					return true;
				}
			}
		}

		return false;
	}

	/**
	 * Compares two instances of the %HashMapT class.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two instances match, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the two instances contain the same number of elements and all the elements of each other.
	 */
	virtual bool Equals(const Object& obj) const
	{
		const HashMapT< KeyType, ValueType >* other = dynamic_cast< const HashMapT< KeyType, ValueType >* >(&obj);
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
			for (int i = 0; i < __capacity; i++)
			{
				for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
				{
					ValueType otherValue;
					result r = other->GetValue(pEntry->key, otherValue);
					if (IsFailed(r))
					{
						return false;
					}
					if (pEntry->value != otherValue)
					{
						return false;
					}
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
	 * 			the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const
	{
		int hash = 0;
		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				hash += reinterpret_cast< int >(&pEntry->key);
				hash += reinterpret_cast< int >(&pEntry->value);
			}
		}
		return hash;
	}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map The instance of the %HashMapT class to copy from
	 */
	HashMapT(const HashMapT< KeyType, ValueType >& map);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map An instance of %HashMapT
	 */
	HashMapT< KeyType, ValueType >& operator =(const HashMapT< KeyType, ValueType >& map);

	/**
	 * Copies all the pairs from a specified map to this map.
	 *
	 * @return		An error code
	 * @param[in]	map The map to copy
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
	 *									The @c map is modified during the operation of this method.
	 */
	result AddAll(const IMapT< KeyType, ValueType >& map)
	{
		result r = E_SUCCESS;

		IMapT< KeyType, ValueType >* pMap = const_cast< IMapT< KeyType, ValueType >* >(&map);
		IMapEnumeratorT< KeyType, ValueType >* pMapEnum = pMap->GetMapEnumeratorN();

		TryCatch(pMapEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while ((r = pMapEnum->MoveNext()) != E_OUT_OF_RANGE)
		{
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			KeyType key;
			ValueType value;

			r = pMapEnum->GetKey(key);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pMapEnum->GetValue(value);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			int hash = Hash(key);
			int i = hash & (__capacity - 1);
			__HashMapEntryT< KeyType, ValueType >* pNewEntry = new __HashMapEntryT< KeyType, ValueType >(key, value, __pTable[i], hash);

			TryCatch(pNewEntry != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
			__pTable[i] = pNewEntry;
			__count++;
		}

		if (null != pMapEnum)
		{
			delete pMapEnum;
		}

		return E_SUCCESS;

CATCH:
		if (null != pMapEnum)
		{
			delete pMapEnum;
		}

		return r;
	}

	/**
	 * Gets the hash value for a specified object.
	 *
	 * @return		The hash value for the specified object
	 * @param[in]	obj		The object to get hash value
	 */
	int Hash(const KeyType& obj) const
	{
		int h = __pProvider->GetHashCode(obj);

		h ^= (h >> 20) ^ (h >> 12);

		return h ^ (h >> 7) ^ (h >> 4);
	}

	/**
	 * Resizes the content of a map to a new array with a greater capacity.
	 *
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity @n
	 *								It must be a power of two and greater than the current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	This method is called automatically when the number of keys in a map reaches its threshold.
	 */
	result Resize(int newCapacity)
	{
		result r = E_SUCCESS;
		__HashMapEntryT< KeyType, ValueType >** pNewTable = new __HashMapEntryT< KeyType, ValueType >*[newCapacity];
		TryReturn(pNewTable != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		memset(pNewTable, null, sizeof(__HashMapEntryT< KeyType, ValueType >*) * newCapacity);

		for (int i = 0; i < __capacity; i++)
		{
			__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i];
			while (null != pEntry)
			{
				__HashMapEntryT< KeyType, ValueType >* pNext = pEntry->pNext;
				int i = pEntry->hash & (newCapacity - 1);
				pEntry->pNext = pNewTable[i];
				pNewTable[i] = pEntry;
				pEntry = pNext;
			}
		}

		delete[] __pTable;
		__pTable = pNewTable;
		__capacity = newCapacity;
		__threshold = static_cast< int >(__capacity * __loadFactor);

		return r;
	}

	/**
	 * Clears all key-value pairs in this map.
	 */
	void Reset(void)
	{
		for (int i = 0; i < __capacity; i++)
		{
			__HashMapEntryT< KeyType, ValueType >* pEntry = __pTable[i];
			while (null != pEntry)
			{
				__HashMapEntryT< KeyType, ValueType >* pNext = pEntry->pNext;
				delete pEntry;
				pEntry = pNext;
			}
			__pTable[i] = null;
		}
	}

	__HashMapEntryT< KeyType, ValueType >** __pTable;
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

	friend class __HashMapEnumeratorT< KeyType, ValueType >;

}; // HashMapT

//
// @class	__HashMapEntryT
// @brief	This is an entry for the %HashMapT class.
// @since 2.0
//
template< class KeyType, class ValueType >
class __HashMapEntryT
	: public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	k		The key to include in this entry
	 * @param[in]	v		The value to include in this entry
	 * @param[in]	next	A pointer to the next entry
	 * @param[in]	h		A hash value of the key
	 */
	__HashMapEntryT(const KeyType& k, const ValueType& v, __HashMapEntryT< KeyType, ValueType >* next, int h)
		: key(k)
		, value(v)
		, hash(h)
		, pNext(next)
	{
	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__HashMapEntryT(void)
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
	ValueType value;

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
	__HashMapEntryT< KeyType, ValueType >* pNext;

}; // __HashMapEntryT

//
// @class	__HashMapEnumeratorT
// @brief	This is an implementation of the IMapEnumeratorT interface for the %HashMapT class.
// @since 2.0
//
template< class KeyType, class ValueType >
class __HashMapEnumeratorT
	: public IMapEnumeratorT< KeyType, ValueType >
	, public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	map			The map to enumerate
	 * @param[in]	modCount	The modification count to detect the change in the map
	 */
	__HashMapEnumeratorT(const HashMapT< KeyType, ValueType >& map, int modCount)
		: __map(map)
		, __modCount(modCount)
		, __pEntry(null)
		, __index(-1)
	{

	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__HashMapEnumeratorT(void)
	{

	}

	/**
	 * Gets the current object in the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The current object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									This enumerator is currently positioned before the first element or
	 *									past the last element or the map is modified after this enumerator is created.
	 */
	virtual result GetCurrent(MapEntryT< KeyType, ValueType >& obj) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__pEntry != null), E_INVALID_OPERATION, "[%s] Invalid position(pEntry is null).", GetErrorMessage(E_INVALID_OPERATION));

		obj = MapEntryT< KeyType, ValueType >(__pEntry->key, __pEntry->value);
		return E_SUCCESS;
	}

	/**
	 * Moves this enumerator to the next elements of the map.
	 * When this enumerator is first created, or when the Reset() method is called, or when the MoveNext() method is first called, the enumerator positions itself to the first element in the map.
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
	virtual result MoveNext(void)
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		if ((null != __pEntry) && (null != __pEntry->pNext))
		{
			__pEntry = __pEntry->pNext;
			return E_SUCCESS;
		}
		else
		{
			while (++__index < __map.__capacity)
			{
				__pEntry = __map.__pTable[__index];
				if (null != __pEntry)
				{
					return E_SUCCESS;
				}
			}
		}

		return E_OUT_OF_RANGE;
	}

	/**
	 * Positions the enumerator before the first element in a map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the map is modified after this enumerator is created.
	 */
	virtual result Reset(void)
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__index = -1;
		__pEntry = null;
		return E_SUCCESS;
	}

	/**
	 * Gets the current key in a map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	key The current key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									This enumerator is currently positioned before the first element or
	 *									past the last element or the map is modified after this enumerator is created.
	 */
	virtual result GetKey(KeyType& key) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__pEntry != null), E_INVALID_OPERATION, "[%s] Invalid position(pEntry is null).", GetErrorMessage(E_INVALID_OPERATION));

		key = __pEntry->key;
		return E_SUCCESS;
	}

	/**
	 * Gets the current value in a map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value The current value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									This enumerator is currently positioned before the first element or
	 *									past the last element or the map is modified after the enumerator is created.
	 */
	virtual result GetValue(ValueType& value) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__pEntry != null), E_INVALID_OPERATION, "[%s] Invalid position(pEntry is null).", GetErrorMessage(E_INVALID_OPERATION));

		value = __pEntry->value;
		return E_SUCCESS;
	}

private:
	const HashMapT< KeyType, ValueType >& __map;
	int __modCount;
	__HashMapEntryT< KeyType, ValueType >* __pEntry;
	int __index;

}; // __HashMapEnumeratorT

//
// @class	__HashMapDefaultProviderT
// @brief	This is an implementation of the IHashCodeProviderT interface for the HashMap class.
// @since 2.0
//
template< class KeyType >
class __HashMapDefaultProviderT
	: public IHashCodeProviderT< KeyType >
	, public Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since 2.0
	*/
	__HashMapDefaultProviderT(void) {}

	/**
	* This is the destructor for this class.
	*
	* @since 2.0
	*/
	virtual ~__HashMapDefaultProviderT(void) {}

	/**
	* Gets the hash code of the specified object.
	*
	* @since 2.0
	*
	* @return		The hash code of the specified object
	* @see			Tizen::Base::Object::GetHashCode
	*/
	virtual int GetHashCode(const KeyType& obj) const
	{
		return (int) obj;
	}

}; // __HashMapDefaultProviderT

template< class KeyType, class ValueType >
const float HashMapT< KeyType, ValueType >::DEFAULT_LOAD_FACTOR = 0.75;

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_HASH_MAP_T_H_
