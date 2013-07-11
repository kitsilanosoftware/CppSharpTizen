//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseUuId.h
 * @brief		This is the header file for the %UuId class.
 *
 * This header file contains the declarations of the %UuId class.
 */
#ifndef _FBASE_UU_ID_H_
#define _FBASE_UU_ID_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FBaseString.h>

#ifndef ClassId
#define ClassId UUID
#endif

namespace Tizen { namespace Base
{
/**
 * @class	UuId
 * @brief	This class is the base class of the wrapped UUID types and provides useful operators.
 *
 * @since 2.0
 *
 * The %UuId class is the base class of the wrapped UUID types and provides useful operators. The UUID consists of 32 hexadecimal digits displayed in 5 groups separated by hyphens to form a total of 36 characters (32 digits and 4 hyphens '-').
 *
 * It also provides operators for assignment and equality, and methods for parsing, comparing, and generalization.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/base_namespace.htm">Base Guide</a>.
 *
 * The following example demonstrates how to use the %UuId class.
 *
 * @code
 *
 * #include <FBase.h>
 *
 * using namespace Tizen::Base;
 *
 * void
 * MyClass::UuIdSamples(void)
 * {
 *		UuId uuid;
 *		String str(L"A02D0DA1-80A0-4E73-B61F-793263C029EE");
 *		String uuidStr_upper
 *		UuId::Parse(str, uuid);		// UuId = A02D0DA1-80A0-4E73-B61F-793263C029EE
 *		
 *		String uuidStr = uuid.ToString();
 *		uuidStr.ToUpper(uuidStr_upper);
 *		
 *		if (str.Equals(uuidStr_upper))
 *		{
 *			// ...
 *		}
 *
 * }
 * @endcode
 */
class _OSP_EXPORT_ UuId
	: public Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * The %UuId is set to @c 0.
	 *
	 * @since 2.0
	 */
	UuId(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in] uuid		An instance of %UuId
	 */
	UuId(const UuId& uuid);

	/**
	 * @if OSPDEPREC
	 * Initializes an instance of %UuId with the value of the specified UUID.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as a UUID type is deprecated.
	 * Instead of using this method, use the UuId(const byte uuid[16]) method.
	 * @since 2.0
	 *
	 * @param[in] uuid		An instance of UUID
	 * @endif
	 */
	UuId(const UUID& uuid);

	/**
	 * Initializes an instance of %UuId with the uuid value.
	 *
	 * @since 2.0
	 *
	 * @param[in] uuid		A byte array of uuid value
	 */
	UuId(const byte uuid[16]);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~UuId(void);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified instance of %UuId is equal to the specified UUID.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as a UUID type is deprecated.
	 * @since 2.0
	 *
	 * @return		@c true if the UUID and the %UuId instance are equal, @n
	 *				else @c false
	 * @param[in]	uuid1		An instance of UUID
	 * @param[in] uuid2		An instance of %UuId
	 * @endif
	 */
	_OSP_EXPORT_ friend bool operator ==(const UUID& uuid1, const UuId& uuid2);

	/**
	 * Checks whether the current instance of %UuId is equal to the specified instance of %UuId.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two IDs are equal, @n
	 *				else @c false
	 * @param[in]	uuid		An instance of %UuId
	 */
	bool operator ==(const UuId& uuid) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified instance of %UuId is not equal to the specified UUID.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as a UUID type is deprecated.
	 * @since 2.0
	 *
	 * @return		@c true if the two IDs are not equal, @n
	 *				else @c false
	 * @param[in]	uuid1		An instance of UUID
	 * @param[in] uuid2		An instance of %UuId
	 * @endif
	 */
	_OSP_EXPORT_ friend bool operator !=(const UUID& uuid1, const UuId& uuid2);

	/**
	 * Checks whether the current instance of %UuId is not equal to the specified instance of %UuId.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two IDs are not equal, @n
	 *				else @c false
	 * @param[in]	uuid		An instance of %UuId
	 */
	bool operator !=(const UuId& uuid) const;

	/**
	 * Assigns the value of the specified instance to the current instance of %UuId.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the current instance
	 * @param[in]	uuid		An instance of %UuId
	 */
	UuId& operator =(const UuId& uuid);

	/**
	 * Checks whether the specified instance of Object is equal to the current instance of %UuId.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance of Object is equal to the current instance of %UuId, @n
	 *				else @c false
	 * @param[in]	obj	An instance of Object to compare
	 * @remarks 	This method can be overridden to support value equality. Furthermore, the method must return the same result as the equality operator.
	 * @see			Tizen::Base::Object::GetHashCode()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance of %UuId.
	 *
	 * @since 2.0
	 *
	 * @return		The integer value equivalent of the hash value of the current instance of %UuId
	 * @remarks 	Two equal instances must return the same hash value. For better performance,
	 *			the used hash function must generate a random distribution for all inputs. @n
	 *			The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the string representing the value of the current instance when implemented by a class.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the String class with the unicode representation of the value of the current instance @n
	 *			If an error such as E_OUT_OF_MEMORY occurs, an empty string is returned.
	 */
	String ToString(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the UUID of the %UuId instance.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as a UUID type is deprecated.
	 * @since 2.0
	 *
	 * @return		The UUID
	 * @endif
	 */
	UUID ToUUID(void) const;

	/**
	 * Parses the specified string representing a %UuId value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str			A string representing the %UuId value
	 * @param[out]	uuid		An instance of %UuId
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The string does not contain an %UuId that can be parsed.
	 * @remarks	The format of a string representing a %UuId value is xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx (For example, 130DF2EC-8233-4975-B03D-F0AD99E3449D).
	 */
	static result Parse(const String& str, UuId& uuid);

	/**
	 * Generates a new %UuId instance with a random value.
	 *
	 * @since 2.0
	 *
	 * @return		A new %UuId instance
	 */
	static UuId* GenerateN(void);

	/**
	 * Get a new invalid %UuId instance.
	 *
	 * @since 2.0
	 *
	 * @return		A new invalid %UuId instance
	 */
	static UuId GetInvalidUuId(void);

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is an invalid UUID.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
	 *				Use GetInvalidUuId(void) instead of this object.
	 * @since 2.0
	 * @endif
	 */
	static const UuId INVALID_UUID;

	/**
	 * A byte array of uuid value.
	 *
	 * @since 2.0
	 */
	byte uuid[16];

private:
	static void ConvertToUuId(byte uuid[16]);

	friend class _UuIdImpl;
	class _UuIdImpl * __pUuIdImpl;

}; // UuId

}} // Tizen::Base

#endif
