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
 * @file		FBaseColMapEntryT.h
 * @brief		This is the header file for the %MapEntryT class.
 *
 * This header file contains the declarations of the %MapEntryT class.
 */
#ifndef _FBASE_COL_MAP_ENTRY_T_H_
#define _FBASE_COL_MAP_ENTRY_T_H_

#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @class MapEntryT
 * @brief	This class represents a template-based key-value pair.
 *
 * @since 2.0
 *
 * The %MapEntryT class represents a template-based key-value pair.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/mapentry.htm">MapEntry</a>.
 *
 */
template< class KeyType, class ValueType >
class MapEntryT
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	MapEntryT(void)
		: __key(0)
		, __val(0)
	{
	}

	/**
	 * Initializes this instance of %MapEntryT with the specified key-value pair.
	 *
	 * @since 2.0
	 *
	 * @param[in]	key The key for this mapping
	 * @param[in]	value	The value for this mapping
	 */
	MapEntryT(const KeyType& key, const ValueType& value)
		: __key(key)
		, __val(value)
	{

	}

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~MapEntryT(void)
	{

	}

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	entry	An instance of %MapEntryT
	 */
	MapEntryT< KeyType, ValueType >& operator =(const MapEntryT< KeyType, ValueType >& entry)
	{
		if (&entry != this)
		{
			__key = entry.__key;
			__val = entry.__val;
		}

		return *this;
	}

	/**
	 * Gets the key corresponding to this entry.
	 *
	 * @since 2.0
	 *
	 * @return	The key corresponding to this entry
	 * @see			GetValue()
	 */
	virtual const KeyType& GetKey(void) const
	{
		return __key;
	}

	/**
	 * Gets the value corresponding to this entry.
	 *
	 * @since 2.0
	 *
	 * @return	The value corresponding to this entry
	 * @see			GetKey()
	 */
	virtual const ValueType& GetValue(void) const
	{
		return __val;
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
		hash += reinterpret_cast< int >(&__key);
		hash += reinterpret_cast< int >(&__val);
		return hash;
	}

private:
	KeyType __key;
	ValueType __val;

}; // MapEntryT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_MAP_ENTRY_T_H_
