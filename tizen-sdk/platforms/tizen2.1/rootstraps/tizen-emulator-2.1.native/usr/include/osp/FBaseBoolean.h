//
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
 * @file		FBaseBoolean.h
 * @brief		This is the header file for the %Boolean class.
 *
 * This header file contains the declarations of the %Boolean class.
 */
#ifndef _FBASE_BOOLEAN_H_
#define _FBASE_BOOLEAN_H_

#include <FBaseObject.h>
#include <FBaseString.h>


namespace Tizen { namespace Base
{
/**
 *	@class	Boolean
 *	@brief	This class is the wrapper class for the @c bool data type.
 *
 *	@since 2.0
 *
 * The %Boolean class wraps a bool type value. This enables passing a bool value to a method that only accepts an instance of the Object class.
 * It provides methods to convert %Boolean instances to String and %String instances to %Boolean.
 *
 * The following example demonstrates how to use the %Boolean class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::Test(void)
 *	{
 *		Boolean b1(true);
 *
 *		String string1(b1.ToString());		// string1 == L"true"
 *
 *
 *		// Compares the string1 with L"true"
 *		if (Boolean::Parse(string1))
 *		{
 *			// ...
 *		}
 *
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ Boolean
	: public Object
{
public:
	/**
	 *	Initializes this instance of the %Boolean class with the specified @c value.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	The input @c bool value to initialize the %Boolean instance
	 */
	Boolean(bool value);

	/**
	 *	Copying of objects using this copy constructor is allowed.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	An instance of the %Boolean class
	 */
	Boolean(const Boolean& value);

	/**
	 *	Initializes this instance of %Boolean with the specified input string. @n
     *  If the input is "true" (ignoring case), the object is initialized to @c true,
	 *	else @c false.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	An instance of String
	 */
	Boolean(const String& value);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since 2.0
	 */
	virtual ~Boolean(void);

	/**
	 *	Compares the values of two %Boolean instances.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the values of the objects are equal, @n
	 *				    else @c false.
	 *	@param[in]	rhs		An instance of %Boolean to compare with the current instance
	 */
	bool operator ==(const Boolean& rhs) const;

	/**
	 *	Checks whether the two %Boolean instances are not equal.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the values of the objects are not equal, @n
	 *				    else @c false
	 *	@param[in]	rhs		An instance of %Boolean to compare with the current instance
	 */
	bool operator !=(const Boolean& rhs) const;

	/**
	 *	Copying of objects using this copy assignment operator is allowed.
	 *
	 *	@since 2.0
	 *
	 *  @param[in]	rhs	An instance of %Boolean
	 */
	Boolean& operator =(const Boolean& rhs);

	/**
	 *	Converts an instance of the Object class to an instance of %Boolean and then
	 *	compares it with the calling %Boolean instance.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the value of @c obj matches the value of the calling %Boolean instance, @n
	 *				    else @c false
	 *	@param[in]	obj		A reference to the Object instance to compare with the calling %Boolean instance
	 *	@see				Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance.
	 *
	 *	@since 2.0
	 *
	 *	@return		The hash value of the current instance
	 *	@remarks    	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 *	Converts a bool value to an instance of %Boolean and then
	 *	compares it with the calling %Boolean instance.
	 *
	 *	@since 2.0
	 *
	 *  @return			@c true if the parameter matches the calling %Boolean instance, @n
	 *                   else @c false
	 *  @param[in]	value	The @c bool value to compare to this instance
	 */
	bool Equals(bool value) const;

	/**
	 * Returns the value of the calling object as @c bool.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the %Boolean instance as bool
	 */
	bool ToBool(void) const;

	/**
	 *	Parses the specified string and converts it to a @c bool value.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the value of the specified string is "true", @n
	 *				else @c false
	 *	@param[in]	s			An instance of String
	 *	@remarks	This method is case sensitive. @n
	 *				It only accepts lowercase strings.
	 *
	 *	@code
	 *	bool b1 = Boolean::Parse(trueString); // trueString is L"true"
	 *	bool b1 = Boolean::Parse(falseString); // falseString is L"false"
	 *	@endcode
	 */
	static bool Parse(const String& s);

	/**
	 *	Parses the specified string and converts it to a @c bool value. @n
	 *	Case sensitivity can be controlled.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the value of the specified string is "true", @n
	 *				else @c false
	 *	@param[in]	s					An instance of String
	 *	@param[in]	caseSensitive	Set to @c true to perform a
	 *								case sensitive comparison of string @c s
	 *	@remarks	If @c caseSensitive is @c true, L"True" returns @c false, else @c true.
	 *
	 *  @code
	 *  bool b1 = Boolean::Parse(L"True", false ); // Returns @c true
	 *  bool b1 = Boolean::Parse(L"True", true); // Returns @c false
	 *  @endcode
	 */
	static bool Parse(const String& s, bool caseSensitive);

	/**
	 *	Converts the value of the calling instance from @c bool to String.
	 *
	 *	@since 2.0
	 *
	 *	@return	@c true if this instance is @c true, @n
	 *			else @c false
	 */
	String ToString(void) const;

	/**
	 *	Converts a @c bool parameter to a String
	 *	instance of the %String class and returns the string representation of the
	 *	input @c bool value (@c true or @c false).
	 *
	 *	@since 2.0
	 *
	 *	@return	@c true if the parameter is @c true, @n
	 *			else @c false
	 *	@param[in]	value	A @c bool value to convert to String
	 */
	static String ToString(bool value);

	/**
	 *	Returns a %Boolean instance whose value corresponds to the
	 *	primitive value @c true.
	 *
	 *	@since 2.0
	 *
	 *	@return		A %Boolean instance equivalent to @c true
	 */
	static const Boolean GetTrue(void);

	/**
	 *	Returns a %Boolean instance whose value corresponds to the primitive
	 *	value @c false.
	 *
	 *	@since 2.0
	 *
	 *	@return		A %Boolean instance equivalent to @c false
	 */
	static const Boolean GetFalse(void);

	/**
	 * A boolean value of this instance.
	 *
	 * @since 2.0
	 */
	bool value;

private:
	friend class _BooleanImpl;
	class _BooleanImpl * __pBooleanImpl;

}; // Boolean

}} // Tizen::Base

#endif //_FBASE_BOOLEAN_H_
