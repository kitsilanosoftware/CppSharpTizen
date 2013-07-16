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
 * @file		FBaseColMapEntry.h
 * @brief		This is the header file for the %MapEntry class.
 *
 * This header file contains the declarations of the %MapEntry class.
 */
#ifndef _FCOL_MAP_ENTRY_H_
#define _FCOL_MAP_ENTRY_H_

#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @class MapEntry
 * @brief	This class represents a key-value pair.
 *
 * @since 2.0
 *
 * The %MapEntry class represents a key-value pair.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/mapentry.htm">MapEntry</a>.
 */
class _OSP_EXPORT_ MapEntry
	: public Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	key	The key
	 * @param[in]	value	The value
	 */
	MapEntry(const Object& key, const Object& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~MapEntry(void);

	/**
	 * Gets the key corresponding to this entry.
	 *
	 * @since 2.0
	 *
	 * @return	The key corresponding to this entry
	 * @see			GetValue()
	 */
	virtual const Object* GetKey(void) const;

	/**
	 * Gets the value corresponding to this entry.
	 *
	 * @since 2.0
	 *
	 * @return	The value corresponding to this entry
	 * @see			GetKey()
	 */
	virtual const Object* GetValue(void) const;

	/**
	 * Gets the key corresponding to this entry.
	 *
	 * @since 2.0
	 *
	 * @return	The key corresponding to this entry
	 * @see			GetValue()
	 */
	virtual Object* GetKey(void);

	/**
	 * Gets the value corresponding to this entry.
	 *
	 * @since 2.0
	 *
	 * @return	The value corresponding to this entry
	 * @see			GetKey()
	 */
	virtual Object* GetValue(void);

	/**
	 * Compares the value of the given Object to the
	 * value of the calling object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the values are equal, @n
	 *				else @c false
	 * @param[in]	obj		The object to compare with the calling object
	 * @remarks 	Returns @c false if the given object is not a %MapEntry object.
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

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	MapEntry(void);
	Object* _pKey;
	Object* _pValue;

private:
	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	entry The instance of the MapEntry class to copy from
	 */
	MapEntry(const MapEntry& entry);

	/**
	 * Assigns the value of the specified instance to the current instance of %MapEntry.
	 *
	 * @param[in]	entry An instance of %MapEntry
	 */
	MapEntry& operator =(const MapEntry& entry);

	friend class _MapEntryImpl;
	class _MapEntryImpl* __pMapEntryImpl;

}; // MapEntry

}}} // Tizen::Collection

#endif // _FCOL_MAP_ENTRY_H_
