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
 * @file		FBaseLong.h
 * @brief		This is the header file for the %Long class.
 *
 * @see			Number()
 *
 * This header file contains the declarations of the %Long class.
 */
#ifndef _FBASE_LONG_H_
#define _FBASE_LONG_H_

#include <FBaseNumber.h>


namespace Tizen { namespace Base
{
/**
 *	@class	Long
 *	@brief	This class is the wrapper class for the @c signed @c long built-in type.
 *
 *	@since 2.0
 *
 *	The %Long class represents an integer value ranging from -2147483648 to 2147483647
 *	, that is, -(2^31) to +((2^31)-1). The class is useful when passing a 32-bit @c signed
 *	integral value to a method that accepts only an instance of Object. Furthermore,
 *	this class provides methods for converting %Long (and @c long) to String, and %String
 *	to %Long (and @c long).
 *
 * The following example demonstrates how to use the %Long class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	// This method checks whether the given string object contains a string
 *	// representation of the pre-defined minimum 32-bit integral value
 *	result
 *	MyClass::Verify(String& string, bool& out)
 *	{
 *		static const Long MINIMUM(1230);
 *		result r = E_SUCCESS;
 *
 *		long l;
 *		r = Long::Parse(string, l);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		out = (MINIMUM.CompareTo(l) == 0) ? true: false;
 *
 *		return r;
 *	CATCH:
 *		return r;
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ Long
	: public Number
{
public:
	/**
	 *	Initializes this instance of %Long with the specified value.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	A @c long value
	 */
	Long(long value = 0);

	/**
	 *	Copying of objects using this copy constructor is allowed.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	An instance of %Long
	 */
	Long(const Long& value);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since 2.0
	 */
	virtual ~Long(void);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %Long
	 */
	Long& operator =(const Long& rhs);

	/**
	 *	Compares two @c long values.
	 *
	 *	@since 2.0
	 *
	 *	@return		A 32-bit @c signed integer value
	 *	@code
	 *	<  0  if the value of @c l1 is less than the value of @c l2
	 *	== 0  if the value of @c l1 is equal to the value of @c l2
	 *	>  0  if the value of @c l1 is greater than the value of @c l2
	 *	@endcode
	 *	@param[in]	l1	The first @c long value to compare
	 *	@param[in]	l2	The second @c long value to compare
	 */
	static int Compare(long l1, long l2);

	/**
	 *	Compares the value of the current instance with the value of the specified instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		A 32-bit @c signed integer value
	 *
	 *	@code
	 *	<  0  if the value of the current instance is less than the value of the specified instance
	 *	== 0  if the value of the current instance is equal to the value of the specified instance
	 *	>  0  if the value of the current instance is greater than the value of the specified instance
	 *	@endcode
	 *	@param[in]	value 	An instance of the %Long class to compare
	 */
	int CompareTo(const Long& value) const;

	/**
	 *	Checks whether the value of the specified instance of %Object is equal to the value of the current instance of %Long.
	 *
	 *	@since 2.0
	 *
	 *	@return 	@c true if the value of the specified instance of %Object is equal to the value of the current instance of %Long, @n
	 *				else @c false
	 *	@param[in]	obj 	An instance of %Object to compare
	 *	@see		Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance of %Long.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance of %Long
	 *	@remarks 	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs. @n
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	*        Gets the hash value of the specified @c long value.
	*
	*        @since 2.0
	*
	*        @return        An integer value indicating the hash value of the specified @c long value
	*        @param[in]   val   A @c long value to get the hash value
	*/
	static int GetHashCode(long val);

	/**
	 *	Decodes a string into a @c signed @c long.
	 *
	 *	@since 2.0
	 *
	 *	@return		An error code
	 *	@param[in]	s				A string representing a numeric value
	 *	@param[out]	ret				The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *	@remarks	This method accepts decimal, hexadecimal, and octal numbers given by the
	 *				following grammar:
	 *	@code
	 *	- DecodableString:
	 *		Sign[opt] DecimalNumeral
	 *		Sign[opt] 0x HexDigits
	 *		Sign[opt] 0X HexDigits
	 *		Sign[opt] # HexDigits
	 *		Sign[opt] 0 OctalDigits
	 *	- Sign:
	 *		'-'
	 *	@endcode
	 */
	static result Decode(const String& s, long& ret);

	/**
	 *	Parses the @c signed @c long equivalent of the specified string representing a numeric value.
	 *
	 *	@since 2.0
	 *
	 *  @return		An error code
	 *  @param[in]	s				A string representing a numeric value
	 *  @param[out]	ret				The result of the operation
	 *  @exception	E_SUCCESS		The method is successful.
	 *  @exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *  @remarks	This method assumes that the string representing the numeric value
	 *				uses a radix 10.
	 */
	static result Parse(const String& s, long& ret);

	/**
	 *	Parses the @c signed @c long equivalent of the specified string representing a numeric value using the specified radix.
	 *
	 *	@since 2.0
	 *
	 *	@return		An error code
	 *	@param[in]	s			A string representing a numeric value
	 *  @param[in]	radix		The radix of the string representing a numeric value @n
	 *							It must be either 2, 8, 10, or 16.
	 *	@param[out]	ret				The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *  @exception	E_OUT_OF_RANGE The specified @c radix is invalid.
	 */
	static result Parse(const String& s, int radix, long& ret);

	/**
	 *	Gets the @c signed @c char equivalent of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const;

	/**
	 *	Gets the @c signed @c short equivalent of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const;

	/**
	 *	Gets the @c signed @c int equivalent of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const;

	/**
	 *	Gets the @c signed @c long equivalent of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const;

	/**
	*	Gets the @c signed @c long @c long equivalent of the current instance of the %Long class.
	*
	*	@since 2.0
	*
	*	@return		The @c signed @c long @c long equivalent of the current instance
	*/
	virtual long long ToLongLong(void) const;

	/**
	 *	Gets the @c signed @c float equivalent of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const;

	/**
	 *	Gets the @c signed @c double equivalent of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const;

	/**
	 *	Gets the string representing the value of the current instance of the %Long class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The string representing the value of the current instance
	 */
	virtual String ToString(void) const;

	/**
	 *	Gets the string representing the specified @c signed @c long value.
	 *
	 *	@since 2.0
	 *
	 *	@return		The string containing a Unicode representation of the specified @c signed @c long value
	 *	@param[in]	value 	A @c signed @c long value to convert
	 */
	static String ToString(long value);

	/**
	 *	A constant holding the maximum value a @c short can have; 2^31-1.
	 *
	 *	@since 2.0
	 */
	static const long VALUE_MAX = (long) 0x7FFFFFFF;

	/**
	 *	A constant holding the minimum value a @c short can have; -2^31.
	 *
	 *	@since 2.0
	 */
	static const long VALUE_MIN = (long) 0x80000000;

	/**
	 * A @c long value of this instance.
	 *
	 * @since 2.0
	 */
	long value;


private:
	friend class _LongImpl;
	class _LongImpl * __pLongImpl;

}; // Long

}} // Tizen::Base

#endif //_FBASE_LONG_H_
