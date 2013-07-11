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
 * @file		FBaseColIMapT.h
 * @brief		This is the header file for the %IMapT interface.
 *
 * This header file contains the declarations of the %IMapT interface.
 */
#ifndef _FBASE_COL_IMAP_T_H_
#define _FBASE_COL_IMAP_T_H_

#include <FBaseColICollectionT.h>
#include <FBaseColIMapEnumeratorT.h>
#include <FBaseColMapEntryT.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class Type > class IListT;

/**
 * @interface IMapT
 * @brief	This interface abstracts a template-based collection of key-value pairs.
 *
 * @since 2.0
 *
 * The %IMapT interface abstracts a template-based collection of key-value pairs. An %IMapT
 * contains unique keys and each key maps to a single value.
 * The key and value cannot be a @c null reference.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 */
template< class KeyType, class ValueType >
class IMapT
	: public virtual ICollectionT< MapEntryT< KeyType, ValueType > >
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IMapT(void) {}

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
	 *								  the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key already exists.
	 * @see Remove()
	 */
	virtual result Add(const KeyType& key, const ValueType& value) = 0;

	/**
	 * Gets the value associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		The value associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key		The key to find the associated value
	 * @param[out]	value	The value associated with the key
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			SetValue()
	 */
	virtual result GetValue(const KeyType& key, ValueType& value) const = 0;

	/**
	 * Gets the value associated with the specified key.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	key		The key to find the associated value
	 * @param[out]	value	The value associated with the key
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			SetValue()
	 */
	virtual result GetValue(const KeyType& key, ValueType& value) = 0;

	/**
	 * Gets a list of all the keys in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IListT interface returned by the GetValuesN() method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IListT< KeyType >* GetKeysN(void) const = 0;

	/**
	 * Gets a list of all the values in the map.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to a list of all values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IListT< ValueType >* GetValuesN(void) const = 0;

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
	virtual result Remove(const KeyType& key) = 0;

	/**
	 * Removes all key-value pairs in the map.
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
	 * @param[in]	key		The key whose value is to replace
	 * @param[in]	value	The new value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @see			Add()
	 * @see			GetValue()
	 */
	virtual result SetValue(const KeyType& key, const ValueType& value) = 0;

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
	 *								The map contains the specified key.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 */
	virtual result ContainsKey(const KeyType& key, bool& out) const = 0;

	/**
	 * Checks whether the map contains the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey()
	 */
	virtual bool ContainsValue(const ValueType& value) const = 0;

	/**
	 * Gets an instance of the IMapEnumeratorT class for the map.
	 *
	 * @since 2.0
	 *
	 * @return		An object of this map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 * @see			Tizen::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumeratorT< KeyType, ValueType >* GetMapEnumeratorN(void) const = 0;

}; // IMapT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IMAP_T_H_
