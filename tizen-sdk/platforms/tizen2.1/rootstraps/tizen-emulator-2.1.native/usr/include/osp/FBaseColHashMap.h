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
 * @file		FBaseColHashMap.h
 * @brief		This is the header file for the %HashMap class.
 *
 * This header file contains the declarations of the %HashMap class.
 */
#ifndef _FBASE_COL_HASH_MAP_H_
#define _FBASE_COL_HASH_MAP_H_

#include <FBaseColIComparer.h>
#include <FBaseColIHashCodeProvider.h>
#include <FBaseColIMap.h>

namespace Tizen { namespace Base { namespace Collection
{

class _HashMapEntry;

/**
 * @class HashMap
 * @brief This class represents a collection of associated keys and values that are organized based on the hash code of the key.
 *
 * @since 2.0
 *
 * The %HashMap class contains unique keys and each key maps to one single value.
 * The key and value cannot be a @c null reference.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to use the %HashMap class to create and initialize a %HashMap instance and to use its methods.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *
 *	void
 *	MyClass::HashMapSample(void)
 *	{
 *		HashMap map(SingleObjectDeleter);
 *
 *		// Constructs a %HashMap instance with default capacity, load factor, hash code provider, and comparer
 *		map.Construct();
 *
 *		map.Add(new String(L"Zero"), new Integer(0));		// map.GetCount() : 1, map : (Zero -> 0)
 *		map.Add(new String(L"One"), new Integer(1));		// map.GetCount() : 2, map : (Zero -> 0), (one -> 1)
 *		map.Add(new String(L"Two"), new Integer(2));		// map.GetCount() : 3, map : (Zero -> 0), (one -> 1), (Two -> 2)
 *
 *		// Gets a value with the specified key
 *		Integer*	pValue = static_cast< Integer* > (map.GetValue(String(L"Zero")));		// pValue : 0
 *
 *		// Removes the value with the specified key
 *		map.Remove(String(L"Zero"));											// map.GetCount() : 2, map : (one -> 1), (Two -> 2)
 *
 *		// Uses an enumerator to access elements in the list
 *		IMapEnumerator*	pMapEnum = map.GetMapEnumeratorN();
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
class _OSP_EXPORT_ HashMap
	: public IMap
	, public Object
{
public:
	using IMap::Add;
	using IMap::Remove;
	using IMap::RemoveAll;
	using IMap::SetValue;
	using IMap::ContainsKey;
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
	explicit HashMap(DeleterFunctionType deleter = NoOpDeleter);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~HashMap(void);

	/**
	 * Initializes an instance of an empty %HashMap class with the initial capacity and load factor.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, @n
	 *								the @c capacity or the @c loadFactor is negative.
	 * @remarks		The GetHashCode() method of key objects is used for hashing and
	 *				the Equals() method of key objects is used for comparing keys.
	 * @see			HashMap()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75);

	/**
	 * Initializes an instance of a %HashMap class by copying the elements of the specified @c map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map				The map to copy
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies only the pointer; not the element itself.
	 * @see			HashMap()
	 */
	result Construct(const IMap& map, float loadFactor = 0.75);

	/**
	 * Initializes an instance of an empty %HashMap class with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity @n
	 *								If it is @c 0, the default capacity(16) is used.
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets @n
	 *								If it is @c 0, the default load factor(0.75) is used.
	 * @param[in]	provider		An instance of the IHashCodeProvider derived class that supplies the hash codes for all the keys in this map
	 * @param[in]	comparer		An instance of the IComparer derived class to use when comparing the keys
	 *
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c capacity or the @c loadFactor is negative.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMap()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProvider& provider, const IComparer& comparer);

	/**
	 * Initializes an instance of a %HashMap class by copying the elements of the specified map with the specified load factor, hash code provider, and comparer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	map			The map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor(0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies only the pointer; not the element itself.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMap()
	 */
	result Construct(const IMap& map, float loadFactor, const IHashCodeProvider& provider, const IComparer& comparer);

	/**
	 * Adds the specified key-value pair to a map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey	The pointer to key of the value to add
	 * @param[in]	pValue	The pointer to value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c pKey already exists.
	 * @remarks		This method performs a shallow copy. It adds only the pointer; not the element itself.
	 * @see			Remove()
	 */
	virtual result Add(Object* pKey, Object* pValue);

	/**
	 * Gets an enumerator (an instance of the IMapEnumerator derived class) of this map.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IMapEnumerator derived class, if successful @n
	 *				else @c null if an exception occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;

	/**
	 * Gets the elements of the map in an instance of the IMapEnumerator derived class.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IMapEnumerator derived class, @n
	 *				else @c null if an exception occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumerator* GetMapEnumeratorN(void) const;

	/**
	 * Gets the value associated with the specified @c key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key		The key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual const Object* GetValue(const Object& key) const;

	/**
	 * Gets the value associated with the specified @c key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key		The key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual Object* GetValue(const Object& key);

	/**
	 * Gets a list of all the keys in a map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to an IList object containing all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @remarks		The order of the keys is the same as the corresponding values in the IList interface returned by the GetValuesN() method.
	 *              The IList stores just the pointers to the elements in the map, not the elements themselves.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IList* GetKeysN(void) const;

	/**
	 * Gets all the values in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to an IList object containing all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @remarks		The IList stores just the pointers to the elements in the map, not the elements themselves.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IList* GetValuesN(void) const;

	/**
	 * Removes the values associated with the specified @c key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the comparer has failed to compare keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key);

	/**
	 * Removes all the object pointers in the collection. @n
	 * The %RemoveAll() method can be called before deleting a collection.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void);

	/**
	 * Sets the value associated with the specified @c key by allocating it a new value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key	The key whose value is to replace
	 * @param[in]	pValue	The pointer to new value to replace
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		To add a new key-value pair, use the Add() method.
	 * @see			Add()
	 * @see			GetValue()
	 */
	virtual result SetValue(const Object& key, Object* pValue);

	/**
	 * Gets the number of pairs currently stored in the map.
	 *
	 * @since 2.0
	 *
	 * @return		The pairs stored in the map
	 */
	virtual int GetCount(void) const;

	/**
	 * Checks whether the map contains the specified @c key.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified @c key, @n
	 *				else @c false
	 * @param[in]	key 	The key to locate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			ContainsValue()
	 */
	virtual bool ContainsKey(const Object& key) const;

	/**
	 * Checks whether the map contains the specified @c value.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified @c value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey()
	 */
	virtual bool ContainsValue(const Object& value) const;

	/**
	 * Compares two instances of the %HashMap class.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two instances match, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the two instances contain the same number of elements and all the elements contained in each other.
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
	 * @param[in]	map		The instance of the %HashMap class to copy from
	 */
	HashMap(const HashMap& map);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	map		An instance of %HashMap
	 */
	HashMap& operator =(const HashMap& map);

	/**
	 * Copies all the pairs from the specified @c map to this map.
	 *
	 * @return		An error code
	 * @param[in]	map The map to copy
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c map is modified during the operation of this method.
	 */
	result AddAll(const IMap& map);

	/**
	 * Gets the hash value for the specified object.
	 *
	 * @return		The hash value for the specified object
	 * @param[in]	obj
	 */
	int Hash(const Object& obj) const;

	/**
	 * Rehashes the content of a map to a new array with a greater capacity.
	 *
	 * @return		An error code
	 * @param[in[	newCapacity	The new capacity @n
	 *							It must be a power of two and must be greater than the current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks	This method is called automatically when the number of keys in a map reaches its threshold.
	 */
	result Resize(int newCapacity);

	/**
	 *  Clears all key-value pairs in a map.
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

	_HashMapEntry** __pTable;
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

	friend class _HashMapEnumerator;
	friend class _HashMapImpl;
	class _HashMapImpl* __pHashMapImpl;

}; // HashMap

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_HASH_MAP_H_
