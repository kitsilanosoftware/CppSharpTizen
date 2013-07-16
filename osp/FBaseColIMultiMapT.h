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
 * @file		FBaseColIMultiMapT.h
 * @brief		This is the header file for the %IMultiMapT interface.
 *
 * This header file contains the declarations of the %IMultiMapT interface.
 */
#ifndef _FBASE_COL_IMULTI_MAP_T_H_
#define _FBASE_COL_IMULTI_MAP_T_H_

#include <FBaseColICollectionT.h>
#include <FBaseColIMapEnumeratorT.h>
#include <FBaseColMapEntryT.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class Type > class IListT;

/**
 * @interface IMultiMapT
 * @brief	This interface represents a template-based collection of key-value pairs.
 *
 * @since 2.0
 *
 * The %IMultiMapT interface abstracts a template-based collection of key-value pairs.
 * There is no limit on the number of elements with the same key, but duplicated elements with the same key are not allowed.
 * The key and value cannot be a @c null reference.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 */
template< class KeyType, class ValueType >
class IMultiMapT
	: public virtual ICollectionT< MapEntryT< KeyType, ValueType > >
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IMultiMapT(void) {}

	/**
	 * Adds the specified key-value pair to the map.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key to add
	 * @param[in]	value	The corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key and @c value already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see Remove()
	 */
	virtual result Add(const KeyType& key, const ValueType& value) = 0;

	/**
	 * Gets the number of values stored in the map.
	 *
	 * @since 2.0
	 *
	 * @return	The number of values currently stored in the map
	 */
	virtual int GetCount(void) const = 0;

	/**
	 * Gets the number of values whose key matches the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The number of values whose key matches the specified key
	 * @param[in]	key	The key to locate in the map
	 * @param[out]	count	The number of values whose key matches the specified key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 */
	virtual result GetCount(const KeyType& key, int& count) const = 0;

	/**
	 * Gets an enumerator of the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IEnumeratorT derived class with the values associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	The key to locate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual IEnumeratorT< ValueType >* GetValuesN(const KeyType& key) const = 0;

	/**
	 * Gets a list of all unique keys in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all unique keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IListT< KeyType >* GetKeysN(void) const = 0;

	/**
	 * Gets a list of all the values in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IListT< ValueType >* GetValuesN(void) const = 0;

	/**
	 * Removes all the values associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key The key whose associated values need to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key) = 0;

	/**
	 * Removes the specified value associated with the specified key. @n
	 * The key is also removed if there are no more values associated with it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key	The key whose mapping is to remove from the map
	 * @param[in]	value	The value to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key and @c value pair is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key, const ValueType& value) = 0;

	/**
	 * Removes all the key-value pairs in the map.
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
	 * @param[in]	key			The key whose associated value needs to replace
	 * @param[in]	value		The value associated with the key
	 * @param[in]	newValue	The new value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key and @c value pair is not found in the map.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @see			Add()
	 * @see			GetValuesN()
	 */
	virtual result SetValue(const KeyType& key, const ValueType& value, const ValueType& newValue) = 0;

	/**
	 * Checks whether the map contains the specified key-value pair.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key to locate
	 * @param[in]	value	The value to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key-value pair, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful. @n
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsKey()
	 * @see			ContainsValue()
	 */
	virtual result Contains(const KeyType& key, const ValueType& value, bool& out) const = 0;

	/**
	 * Checks whether the map contains the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key to locate
	 * @param[out]	out 	Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful. @n
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 * @see			Contains()
	 */
	virtual result ContainsKey(const KeyType& key, bool& out) const = 0;

	/**
	 * Checks whether the map contains the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		Set to @c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey()
	 * @see			Contains()
	 */
	virtual bool ContainsValue(const ValueType& value) const = 0;

	/**
	 * Gets an enumerator of the map.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IMapEnumeratorT class for the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If a key has multiple values, the enumeration proceeds as follows: @n
	 * 				{A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ... @n
	 *         		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumeratorT< KeyType, ValueType >* GetMapEnumeratorN(void) const = 0;

}; // IMultiMapT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IMULTI_MAP_T_H_
