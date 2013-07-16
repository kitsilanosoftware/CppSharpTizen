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
 * @file		FBaseColIMultiMap.h
 * @brief		This is the header file for the %IMultiMap interface.
 *
 * This header file contains the declarations of the %IMultiMap interface.
 */
#ifndef _FBASE_COL_IMULTI_MAP_H_
#define _FBASE_COL_IMULTI_MAP_H_

#include <FBaseColICollection.h>
#include <FBaseColTypes.h>
#include <FBaseColIMapEnumerator.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Collection
{

class IList;
class MapEntry;

/**
 * @interface IMultiMap
 * @brief	This interface represents a collection of key-value pairs.
 *
 * @since 2.0
 *
 * The %IMultiMap interface abstracts a collection of key-value pairs.
 * There is no limit on the number of elements with the same key, but duplicated elements with the same key are not allowed.
 * The key and value cannot be a @c null reference.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 */
class _OSP_EXPORT_ IMultiMap
	: public virtual ICollection
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IMultiMap(void) {}

	/**
	 * @if OSPDEPREC
	 * Adds the specified key-value pair to the map.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it has a problem of const reference argument.
	 *				Instead of using this method, use Add(Object* pKey, Object* pValue).
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key     The key to add
	 * @param[in]	value   The corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key and @c value already exist.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see Remove()
	 * @endif
	 */
	result Add(const Object& key, const Object& value)
	{
		return Add(const_cast< Object* >(&key), const_cast< Object* >(&value));
	}

	/**
	 * Adds the specified key-value pair to the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey	The pointer to key to add
	 * @param[in]	pValue	The pointer to corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c pKey and @c pValue already exist.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see Remove()
	 */
	virtual result Add(Object* pKey, Object* pValue) = 0;

	/**
	 * Gets the number of values stored in the map.
	 *
	 * @since 2.0
	 *
	 * @return		The number of values currently stored in the map
	 */
	virtual int GetCount(void) const = 0;

	/**
	 * Gets the number of values with keys matching the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The number of values with keys matching the specified key
	 * @param[in]	key 	The key to locate in the map
	 * @param[out]	count	The number of values with keys matching the specified key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 */
	virtual result GetCount(const Object& key, int& count) const = 0;

	/**
	 * Gets an enumerator of the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IEnumerator derived class with the values associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key 			The key to locate in the map
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IEnumerator* GetValuesN(const Object& key) const = 0;

	/**
	 * Gets a list of all unique keys in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all unique keys in the map, @n
	 *				else @c null if an exception occurs
	 * @remarks		The %IList stores just the pointers to the elements in the map, not the elements themselves.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IList* GetKeysN(void) const = 0;

	/**
	 * Gets a list of all the values in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @remarks		The IList stores just the pointers to the elements in the map, not the elements themselves.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual IList* GetValuesN(void) const = 0;

	/**
	 * Removes all the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key for which the associated values need to remove
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance. @n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method. @n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		Remove(key, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * Remove(key);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		Remove(key, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * Remove(key);
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			Add()
	 */
	result Remove(const Object& key, bool forceDeletion)
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

		result r = Remove(key);
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Removes all the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key for which the associated values need to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key) = 0;

	/**
	 * Removes the specified value associated with the specified key. @n
	 * The key is also removed if there are no more values associated with it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key for which the mapping is to remove from the map
	 * @param[in]	value 	The value to remove
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The @c key and @c value pair is not found in the map.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance. @n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method. @n
	 *				If both an element deleter and forceDeleteion are set, the remove operation follows @c forceDeletion setting.
	 * @remarks		Remove(key, value, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * Remove(key, value);
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		Remove(key, value, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * Remove(key, value);
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			Add()
	 */
	result Remove(const Object& key, const Object& value, bool forceDeletion)
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

		result r = Remove(key, value);
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Removes the specified value associated with the specified key. @n
	 * The key is also removed if there are no more values associated with it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key for which the mapping is to remove from the map
	 * @param[in]	value 	The value to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The @c key and @c value pair is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key, const Object& value) = 0;

	/**
	 * Removes all the object pointers in the collection. @n
	 * If the @c forceDeletion parameter is set to @c true, the method also removes all the objects. This method can be called before deleting the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	forceDeletion		Set to @c true to deallocate all objects, @n
	 * 								else @c false
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance. @n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method. @n
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
	 * This method can be called before deleting the collection.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void) = 0;

	/**
	 * Replaces the specified value associated with the specified key with a new value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key for which the associated value needs to replace
	 * @param[in]	value 	The value associated with the key
	 * @param[in]	newValue	The new value
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The key-value pair is not found in the map.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @remarks		Based on the specified element deleter, the set operation not only gets rid of an element from a list, but also deletes its object instance. @n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the set method. @n
	 *				If both an element deleter and forceDeleteion are set, the set operation follows @c forceDeletion setting.
	 * @remarks		SetValue(key, value, newValue, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * SetValue(key, value, const_cast< Object* >(&newValue));
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks		SetValue(key, value, newValue, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * SetValue(key, value, const_cast< Object* >(&newValue));
	 * SetDeleter(deleter);
	 * @endcode
	 * @see			Add()
	 * @see			GetValuesN()
	 */
	result SetValue(const Object& key, const Object& value, const Object& newValue, bool forceDeletion = false)
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

		result r = SetValue(key, value, const_cast< Object* >(&newValue));
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Replaces the specified value associated with the specified key with a new value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key	The key for which the associated value needs to replace
	 * @param[in]	value	The value associated with the key
	 * @param[in]	pNewValue	The pointer to new value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The key-value pair is not found in the map.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @see			Add()
	 * @see			GetValuesN()
	 */
	virtual result SetValue(const Object& key, const Object& value, Object* pNewValue) = 0;

	/**
	 * @if OSPDEPREC
	 * Checks whether the map contains the specified key-value pair.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it transfers a result of comparison in out-parameter form.
	 *				The return type will be changed into boolean type and this method will return the result.
	 *				Instead of using this method, use bool Contains(const Object& key, const Object& value).
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[in]	value 	The value to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key-value pair, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsKey()
	 * @see			ContainsValue()
	 * @endif
	 */
	result Contains(const Object& key, const Object& value, bool& out) const
	{
		out = Contains(key, value);
		result r = GetLastResult();
		return r;
	}

	/**
	 * Checks whether the map contains the specified key-value pair.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified key-value pair, @n
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
	virtual bool Contains(const Object& key, const Object& value) const = 0;

	/**
	 * @if OSPDEPREC
	 * Checks whether the map contains the specified key.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it transfers a result of comparison in out-parameter form.
	 *				The return type will be changed into boolean type and this method will return the result.
	 *				Instead of using this method, use bool ContainsKey(const Object& key).
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 * @see			Contains()
	 * @endif
	 */
	result ContainsKey(const Object& key, bool& out) const
	{
		out = ContainsKey(key);
		result r = GetLastResult();
		return r;
	}

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
	virtual bool ContainsKey(const Object& key) const = 0;

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
	virtual bool ContainsValue(const Object& value) const = 0;

	/**
	 * Gets an enumerator of the map.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IMapEnumerator class for the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @remarks		If a key has multiple values, the enumeration proceeds as follows: @n
	 * 				{A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			IEnumerator
	 * @see			IMapEnumerator
	 */
	virtual IMapEnumerator* GetMapEnumeratorN(void) const = 0;

	/**
	 * Gets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @return		A function pointer to the existing element deleter
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
	virtual void IMultiMap_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IMultiMap_Reserved2(void) { }

private:
	/**
	 * Sets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	A function pointer to the element deleter to set
	 */
	virtual void SetDeleter(DeleterFunctionType deleter) = 0;

}; // IMultiMap

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IMULTI_MAP_H_
