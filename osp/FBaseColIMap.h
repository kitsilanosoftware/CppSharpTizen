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
 * @file		FBaseColIMap.h
 * @brief		This is the header file for the %IMap interface.
 *
 * This header file contains the declarations of the %IMap interface.
 */
#ifndef _FBASE_COL_IMAP_H_
#define _FBASE_COL_IMAP_H_

#include <FBaseColICollection.h>
#include <FBaseColTypes.h>
#include <FBaseColIMapEnumerator.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Collection
{

class IList;
class MapEntry;

/**
 * @interface IMap
 * @brief	This interface represents a collection of key-value pairs.
 *
 * @since 2.0
 *
 * The %IMap interface abstracts a collection of key-value pairs. An %IMap instance
 * contains unique keys and each key maps to a single value.
 * The key and value cannot be a @c null reference.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 */
class _OSP_EXPORT_ IMap
	: public virtual ICollection
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IMap(void) {}

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
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key already exists.
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
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c pKey already exists.
	 * @remarks	This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see Remove()
	 */
	virtual result Add(Object* pKey, Object* pValue) = 0;

	/**
	 * Checks if the key exists. If the key doesn't exist, Add() is called. Unless, SetValue() is called.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey	The pointer to key to add
	 * @param[in]	pValue	The pointer to corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @remarks	This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			Add()
	 * @see			SetValue()
	 */
	result AddIfNotExistOrSet(Object* pKey, Object* pValue)
	{
		if (!ContainsKey(*pKey))
		{
			return Add(pKey, pValue);
		}
		else
		{
			return SetValue(*pKey, pValue);
		}
	}

	/**
	 * Gets the value associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key 	The key to find the associated value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual const Object* GetValue(const Object& key) const = 0;

	/**
	 * Gets the value associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key 	The key to find the associated value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual Object* GetValue(const Object& key) = 0;

	/**
	 * Gets a list of all the keys in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @remarks		The order of the keys is the same as the corresponding values in the IList interface returned by the GetValuesN() method.
	 * @remarks		The %IList interface stores just the pointers to the elements in the map, not the elements themselves.
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
	 * @see			GetKeysN()
	 */
	virtual IList* GetValuesN(void) const = 0;

	/**
	 * Removes the value associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key to remove
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		Based on the specified element deleter, the remove operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the remove method.@n
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
	 * Removes the value associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key for which the value is to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key) = 0;

	/**
	 * Removes all the object pointers in the collection. @n
	 * If the @c forceDeletion parameter is set to @c true, the method also removes all the objects. This method can be called before deleting the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	forceDeletion		Set to @c true to deallocate all the objects, @n
	 * 								else @c false
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
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void) = 0;

	/**
	 * Replaces the value associated with the specified key with the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key 	The key for which the value is to replace
	 * @param[in]	value 	The new value
	 * @param[in]	forceDeletion		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks	Use the Add() method to add a new key-value pair.
	 * @remarks		Based on the specified element deleter, the set operation not only gets rid of an element from a list, but also deletes its object instance.@n
	 *				The element deleter style is recommended rather than using the @c forceDeletetion argument in the set method.@n
	 *				If both an element deleter and forceDeleteion are set, the set operation follows @c forceDeletion setting.
	 * @remarks	SetValue(key, value, @b true) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(SingleObjectDeleter);
	 * SetValue(key, const_cast< Object* >(&value));
	 * SetDeleter(deleter);
	 * @endcode
	 * @remarks	SetValue(key, value, @b false) internally works as the below code:
	 * @code
	 * DeleterFunctionType deleter = GetDeleter();
	 * SetDeleter(NoOpDeleter);
	 * SetValue(key, const_cast< Object* >(&value));
	 * SetDeleter(deleter);
	 * @endcode
	 * @see		Add()
	 * @see		GetValue()
	 */
	result SetValue(const Object& key, const Object& value, bool forceDeletion = false)
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

		result r = SetValue(key, const_cast< Object* >(&value));
		SetDeleter(deleter);
		return r;
	}

	/**
	 * Replaces the value associated with the specified key with the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in] key		The key for which the value is to replace
	 * @param[in]	pValue	The pointer to new value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks	Use the Add() method to add a new key-value pair.
	 * @see		Add()
	 * @see		GetValue()
	 */
	virtual result SetValue(const Object& key, Object* pValue) = 0;

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
	 */
	virtual bool ContainsValue(const Object& value) const = 0;

	/**
	* Gets an instance of the IMapEnumerator for the map.
	*
	* @since 2.0
	*
	* @return			IMapEnumerator object of this map, @n
	* 				else @c null if an exception occurs
	* @exception	E_SUCCESS		The method is successful.
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
	virtual void IMap_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IMap_Reserved2(void) { }

private:
	/**
	 * Sets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	A function pointer to the element deleter to set
	 */
	virtual void SetDeleter(DeleterFunctionType deleter) = 0;

}; // IMap

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IMAP_H_
