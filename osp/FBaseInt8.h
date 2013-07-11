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
 * @file		FBaseInt8.h
 * @brief		This is the header file for the %Int8 class.
 *
 * @see			Tizen::Base::Number
 *
 * This header file contains the declarations of the %Int8 class.
 */
#ifndef _FBASE_INT8_H_
#define _FBASE_INT8_H_

#include <FBaseNumber.h>


namespace Tizen { namespace Base
{
/**
 * @class	Int8
 * @brief	This class is the wrapper class for the @c signed @c char built-in type.
 *
 * @since 2.0
 *
 * The %Int8 class represents an integer value ranging from -128 to 127. The class is useful when passing an 8-bit
 * signed integral value to a method that accepts only an instance of Object. Furthermore, this class provides
 * methods for converting %Int8 (and @c char) to String, and %String to %Int8 (and @c char).
 *
 * The following example demonstrates how to use the %Int8 class.
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	// This method checks whether the given string object contains a string
 *	// representation of the pre-defined minimum 8-bit integral value.
 *	result
 *	MyClass::Verify(String& string, bool& out)
 *	{
 *		static const Int8 MINIMUM(123);
 *
 *		result r = E_SUCCESS;
 *
 *		char ch;
 *		r = Int8::Parse(string, ch);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		out = (MINIMUM.CompareTo(ch) == 0) ? true: false;
 *
 *		return r;
 *	CATCH:
 *		return r;
 *	}
 * @endcode
 */
class _OSP_EXPORT_ Int8
	: public Number
{
public:
	/**
	 * Initializes this instance of %Int8 with the specified value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value 	A @c char value
	 */
	Int8(char value = 0);


	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value 	An instance of %Int8
	 */
	Int8(const Int8& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Int8(void);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %Int8
	 */
	Int8& operator =(const Int8& rhs);

	/**
	 * Compares two @c char values.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @code
	 * <  0  if the value of ch1 is less than the value of ch2
	 * == 0  if the value of ch1 is equal to the value of ch2
	 * >  0  if the value of ch1 is greater than the value of ch2
	 * @endcode
	 * @param[in]	ch1	The first @c char value to compare
	 * @param[in]	ch2	The second @c char value to compare
	 */
	static int Compare(char ch1, char ch2);

	/**
	 * Compares the value of the current instance with the value of the specified instance of the %Int8 class.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @code
	 * <  0  if the value of the current instance is less than the value of the specified instance
	 * == 0  if the value of the current instance is equal to the value of the specified instance
	 * >  0  if the value of the current instance is greater than the value of the specified instance
	 * @endcode
	 * @param[in]	value 	An instance of the %Int8 class to compare
	 */
	int CompareTo(const Int8& value) const;

	/**
	 * Checks whether the value of the specified instance of %Int8 is equal to the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the specified instance is equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	obj An instance of Object to compare
	 * @see			Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance of %Int8.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance of %Int8
	 *	@remarks 	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs. @n
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	*   Gets the hash value of the specified @c char value.
	*
	*   @since 2.0
	*
	*   @return     An integer value indicating the hash value of the specified @c char value
	*   @param[in]   val   A @c char value to get the hash value
	*/
	static int GetHashCode(char val);

	/**
	 * Decodes a string into a @c signed @c char.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	s	A string representing a numeric value
	 * @param[out]	ret	The result of the operation
	 * @exception	E_SUCCESS	 The method is successful.
	 * @exception	E_NUM_FORMAT The specified string does not contain a number that can be parsed.
	 * @remarks		This method accepts decimal, hexadecimal, and octal numbers given by the
	 *				following grammar:
	 * @code
	 *	- DecodableString:
	 *		Sign[opt] DecimalNumeral
	 *		Sign[opt] 0x HexDigits
	 *		Sign[opt] 0X HexDigits
	 *		Sign[opt] # HexDigits
	 *		Sign[opt] 0 OctalDigits
	 *	- Sign:
	 *		'-'
	 * @endcode
	 */
	static result Decode(const String& s, char& ret);

	/**
	 * Parses the @c signed @c char equivalent of the specified string representing a numeric value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	s	A string representing a numeric value
	 * @param[out]	ret	The result of the operation
	 * @exception	E_SUCCESS	 The method is successful.
	 * @exception	E_NUM_FORMAT The specified string does not contain a byte that can be parsed.
	 * @remarks		This method assumes that the string representing the numeric value
	 *				uses a radix 10.
	 */
	static result Parse(const String& s, char& ret);

	/**
	 * Parses the specified string representing a numeric value and
     * returns the value as @c signed @c char (as out parameter).
     *
	 * @since 2.0
	 *
	 * @return		The @c signed @c char equivalent of the specified string representing the numeric value using the specified index
	 * @param[in]	s	A string representing a numeric value
	 * @param[in]	radix	The radix of the string representing a numeric value @n
	 *						It must either be 2, 8, 10, or 16.
     * @param[out]	ret		The result of the operation
	 * @exception	E_SUCCESS	 The method is successful.
	 * @exception	E_NUM_FORMAT The specified string does not contain a number that can be parsed.
	 * @exception	E_OUT_OF_RANGE The specified @c radix is invalid.
	 */
	static result Parse(const String& s, int radix, char& ret);

	/**
	 * Gets the @c signed @c char equivalent of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return	The @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const;

	/**
	 * Gets the @c signed @c short equivalent of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return	The @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const;

	/**
	 * Gets the @c signed @c int equivalent of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return	The @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const;

	/**
	 * Gets the @c signed @c long equivalent of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return	The @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const;

	/**
	* Gets the @c signed @c long @c long equivalent of the current instance of %Int8.
	*
	* @since 2.0
	*
	* @return	The @c signed @c long @c long equivalent of the current instance
	*/
	virtual long long ToLongLong(void) const;

	/**
	 * Gets the @c signed @c float equivalent of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return	The @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const;

	/**
	 * Gets the @c signed @c double equivalent of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return	The @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const;

	/**
	 * Gets the string representing the value of the current instance of %Int8.
	 *
	 * @since 2.0
	 *
	 * @return		A string representing the value of the current instance
	 */
	virtual String ToString(void) const;

	/**
	 * Gets the string representing the specified @c signed @c char value using radix @c 10.
	 *
	 * @since 2.0
	 *
	 * @return		A string containing a Unicode representation of the specified @c char value using radix 10
	 * @param[in]	value 	A @c char value
	 */
	static String ToString(char value);

	/**
	 * A constant holding the maximum value of type @c char. @n
	 * A @c short character can hold a value of upto 2^7-1.
	 *
	 * @since 2.0
	 */
	static const char VALUE_MAX = (signed char) 0x7F;

	/**
	 * A constant holding the minimum value of type @c char. @n
	 * A @c short character can hold a value of upto -2^7.
	 *
	 * @since 2.0
	 */
	static const char VALUE_MIN = (signed char) 0x80;

	/**
	 * A @c signed @c char value of this instance.
	 *
	 * @since 2.0
	 */
	signed char value;


private:
	friend class _Int8Impl;
	class _Int8Impl * __pInt8Impl;

}; // Int8

}} // Tizen::Base

#endif //_FBASE_INT8_H_
