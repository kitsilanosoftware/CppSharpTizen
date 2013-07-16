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
 * @file		FBaseColMultiHashMap.h
 * @brief		This is the header file for the %MultiHashMap class.
 *
 * This header file contains the declarations of the %MultiHashMap class.
 */
#ifndef _FBASE_COL_MULTI_HASH_MAP_H_
#define _FBASE_COL_MULTI_HASH_MAP_H_

#include <FBaseObject.h>
#include <FBaseColIComparer.h>
#include <FBaseColIHashCodeProvider.h>
#include <FBaseColIMultiMap.h>


namespace Tizen { namespace Base { namespace Collection
{

class _MultiHashMapEntry;

/**
 * @class MultiHashMap
 * @brief This class represents a collection of associated keys and values that are organized based on the hash code of the key.
 *
 * @since 2.0
 *
 *  The %MultiHashMap class represents a collection of associated keys and values that are organized based on the hash code of the key.
 * There is no limit on the number of elements with the same key, but duplicated elements with the same key are not allowed.
 * The key and value cannot be @c null.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to use the %MultiHashMap class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::MultiHashMapSample(void)
 *	{
 *		MultiHashMap map(SingleObjectDeleter);
 *
 *		// Constructs a MultiHashMap instance with default values for capacity, load factor, hash code provider, and comparer
 *		map.Construct();
 *
 *		map.Add(new String(L"Zero"), new Integer(0));		// map.GetCount() : 1, map : (Zero -> 0)
 *		map.Add(new String(L"One"), new Integer(1));		// map.GetCount() : 2, map : (Zero -> 0), (one -> 1)
 *		map.Add(new String(L"Two"), new Integer(2));		// map.GetCount() : 3, map : (Zero -> 0), (one -> 1), (Two -> 2)
 *		map.Add(new String(L"Two"), new Integer(20));		// map.GetCount() : 4, map : (Zero -> 0), (One -> 1), (Two -> 2, 20)
 *
 *		// Gets values with the specified key
 *		Integer*	pValue = null;
 *		IEnumerator *pValueEnum = map.GetValuesN(String(L"Two"));
 *		while(pValueEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pValue = static_cast< Integer* > (pValueEnum->GetCurrent());
 *		}
 *
 *		delete pValueEnum;
 *
 *		// Removes values with the specified key     // String(L"Two"), Integer(2), Integer(20) are removed
 *		map.Remove(String(L"Two"));
 *
 *		// Uses an enumerator to access elements in the map
 *		IMapEnumerator* pMapEnum = map.GetMapEnumeratorN();
 *		String* pKey = null;
 *		while (pMapEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pKey = static_cast< String* > (pMapEnum->GetKey());
 *			pValue = static_cast< Integer* > (pMapEnum->GetValue());
 *		}
 *
 *		delete pMapEnum;
 *
 *		// Deallocates all objects
 *		// Because the destructor calls RemoveAll() internally, you do not need to call RemoveAll() to destroy all elements at the end.
 *		// map.RemoveAll();
 *	}
 * @endcode
 */
class _OSP_EXPORT_ MultiHashMap
	: public IMultiMap
	, public Object
{
public:
	using IMultiMap::Add;
	using IMultiMap::Remove;
	using IMultiMap::RemoveAll;
	using IMultiMap::SetValue;
	using IMultiMap::Contains;
	using IMultiMap::ContainsKey;

	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	The function pointer to type of the element deleter
	 * @remarks	To create an owing collection, set the element deleter value as @c SingleObjectDeleter. This gives the collection the ownership of elements and the collection will destroy elements. @n
	 *			On the other hand, to create a non-owning collection, you do not need to set the element deleter value, as @c NoOpDeleter is the default element deleter.
	 *			It means that you do not transfer the ownership of elements to the collection.
	 * @see		NoOpDeleter()
	 * @see		SingleObjectDeleter()
	 * @see		ArrayDeleter()
	 */
	explicit MultiHashMap(DeleterFunctionType deleter = NoOpDeleter);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~MultiHashMap(void);

	/**
	 * Initializes a new instance of %MultiHashMap with the specified capacity and load factor.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c capacity or the @c loadFactor is negative.
	 * @remarks		The GetHashCode() method of the key object is used for hashing and the
	 *				Equals() method of the key object is used for comparing the keys.
	 * @see			MultiHashMap()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75);

	/**
	 * Initializes a new instance of %MultiHashMap by copying the elements of the given map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map				The map to copy
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets @n
	 *								If it is @c 0, the default load factor(0.75) is used.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			MultiHashMap()
	 */
	result Construct(const IMultiMap& map, float loadFactor = 0.75);


	/**
	 * Initializes a new instance of the %MultiHashMap class, with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity @n
	 *							If it is @c 0, the default capacity (16) is used.
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c capacity or the @c loadFactor is negative.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			MultiHashMap()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProvider& provider, const IComparer& comparer);

	/**
	 * Initializes a new instance of the %MultiHashMap class by copying the elements of the specified map,
	 * with the specified load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map			A map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 *      		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			MultiHashMap()
	 */
	result Construct(const IMultiMap& map, float loadFactor, const IHashCodeProvider& provider, const IComparer& comparer);

	/**
	 * Adds the specified key-value pair to this map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey	The pointer to key to add
	 * @param[in]	pValue	The pointer to corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified pair of @c pKey and @c pValue already exists.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			Remove()
	 */
	virtual result Add(Object* pKey, Object* pValue);

	/**
	 * Gets an enumerator of this map.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumerator derived class) of this map, @n
	 *				else @c null if some exception occurs
	 * @remarks		If the key has multiple values, the enumeration proceeds as follows: {A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 * @see			IEnumerator()
	 * @see			IMapEnumerator()
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;

	/**
	 * Gets an enumerator of this map.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IMapEnumerator derived class) of this map, @n
	 *				else @c null if some exception occurs
	 * @remarks		If the key has multiple values, the enumeration proceeds as follows: {A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			IEnumerator()
	 * @see			IMapEnumerator()
	 */
	virtual IMapEnumerator* GetMapEnumeratorN(void) const;

	/**
	 * Gets an enumerator of the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumerator derived class) of the values associated with the specified key, @n
	 *				else @c null if some exception occurs
	 * @param[in]	key 	A key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual IEnumerator* GetValuesN(const Object& key) const;

	/**
	 * Gets a list of all unique keys in this map.
	 *
	 * @since 2.0
	 *
	 * @return		A list of all unique keys in this map
	 * @remarks		The %IList stores just the pointers to the elements in the map, not the elements themselves.
	 *          		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IList* GetKeysN(void) const;

	/**
	 * Gets a list of all the values in this map.
	 *
	 * @since 2.0
	 *
	 * @return		A list of all the values in this map
	 * @remarks		The IList stores just the pointers to the elements in the map, not the elements themselves.
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IList* GetValuesN(void) const;

	/**
	 * Removes all the values with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key);

	/**
	 * Removes the specified value associated with the specified key.
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
	 * @remarks		The specified key is also removed if there are no more values associated with it.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key, const Object& value);

	/**
	 * Removes all the object pointers in the @c collection. @n
	 *
	 * @since 2.0
	 *
	 * @remarks		This method can be called before deleting @c collection.
	 */
	virtual void RemoveAll(void);

	/**
	 * Sets the value associated with the given key with a new value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key for which the associated value needs to replace
	 * @param[in]	value	The value to replace
	 * @param[in]	pNewValue	The pointer to new value to replace the existing value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key and @c value pair is not found in the map.
	 * @remarks		To add a new key-value pair, use the Add() method.
	 * @see			Add()
	 * @see			GetValuesN()
	 */
	virtual result SetValue(const Object& key, const Object& value, Object* pNewValue);

	/**
	 * Gets the number of values currently stored in this map.
	 *
	 * @since 2.0
	 *
	 * @return		The number of values currently stored in this map
	 */
	virtual int GetCount(void) const;

	/**
	 * Gets the number of values whose key matches the key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key     A key to locate
	 * @param[out]	count	The number of values whose key is the @c key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 */
	virtual result GetCount(const Object& key, int& count) const;

	/**
	 * Checks whether the map contains the specified key and value.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified key and value pair, @n
	 *				else @c false
	 * @param[in]	key 	The key to locate
	 * @param[in]	value 	The value to locate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			ContainsKey()
	 * @see			ContainsValue()
	 */
	virtual bool Contains(const Object& key, const Object& value) const;

	/**
	 * Checks whether the map contains the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified key, @n
	 *				else @c false
	 * @param[in]	key 	The key to locate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			ContainsValue()
	 * @see			Contains()
	 */
	virtual bool ContainsKey(const Object& key) const;

	/**
	 * Checks whether the map contains the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value 	The value to locate
	 *
	 * @see				ContainsKey()
	 * @see				Contains()
	 */
	virtual bool ContainsValue(const Object& value) const;

	/**
	 * Compares the specified instance to the current instance for equality.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two instances are equal, @n
	 *				@c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true only if the specified object is also an instance of %MultiHashMap class,
	 *				both maps have the same number of elements, and both maps contain the same elements.
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return 	The hash value of the current instance
	 * @remarks	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 * 			the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @return		A function pointer to the existing element deleter
	 */
	virtual DeleterFunctionType GetDeleter(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map An instance of %MultiHashMap to initialize the current instance
	 */
	MultiHashMap(const MultiHashMap& map);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map An instance of %MultiHashMap
	 */
	MultiHashMap& operator =(const MultiHashMap& map);

	/**
	 * Copies all the pairs from the specified map to this map.
	 *
	 * @return		An error code
	 * @param[in]	map The map to copy
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c map is modified during the operation of this method.
	 */
	result AddAll(const IMultiMap& map);

	/**
	 * Gets a hash value for the specified object.
	 *
	 * @return		An @c int hash value for the specified object
	 * @param[in]	obj     The object to get hash value
	 */
	int Hash(const Object& obj) const;

	/**
	 * Rehashes the contents of this map into a new array with a
	 * larger capacity. @n
	 * This method is called automatically when the number of keys in this map reaches its threshold.
	 *
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity @n
	 *								It must be a power of two and be greater than current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result Resize(int newCapacity);

	/**
	 * Clears all key-value pairs in this map.
	 */
	void Reset(void);

	/**
	 * Sets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	A function pointer to the element deleter to set
	 */
	virtual void SetDeleter(DeleterFunctionType deleter);

	_MultiHashMapEntry** __pTable;
	int __count;
	int __capacity;
	float __loadFactor;
	int __threshold;
	IHashCodeProvider* __pProvider;
	IComparer* __pComparer;
	bool __needToRemoveProviderComparer;
	int __modCount;
	DeleterFunctionType __deleter;
	static const int DEFAULT_CAPACITY = 16;
	static const float DEFAULT_LOAD_FACTOR;

	friend class _MultiHashMapEnumerator;
	friend class _MultiHashMapImpl;
	class _MultiHashMapImpl* __pMultiHashMapImpl;

}; // MultiHashMap

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_MULTI_HASH_MAP_H_
