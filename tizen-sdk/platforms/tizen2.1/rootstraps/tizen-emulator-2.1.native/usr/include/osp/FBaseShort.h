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
 * @file		FBaseShort.h
 * @brief		This is the header file for the %Short class.
 *
 * @see			Number()
 *
 * This header file contains the declarations of the %Short class.
 */
#ifndef _FBASE_SHORT_H_
#define _FBASE_SHORT_H_

#include <FBaseNumber.h>


namespace Tizen { namespace Base
{
/**
 *	@class	Short
 *	@brief	This class is the wrapper class for the @c signed @c short built-in type.
 *
 *	@since 2.0
 *
 *	The %Short class represents an integer value ranging from -32768 to 32767. The class is useful when passing
 *	a 16-bit @c signed integral value to a method that accepts only an instance of Object. Furthermore,
 *	this class provides methods for converting a %Short (and @c short) to a String, and a %String to %Short
 *	(and @c short).
 *
 * The following example demonstrates how to use the %Short class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	// This method checks whether the given string object contains a string
 *	// representation of the pre-defined minimum 16-bit integral value
 *	result
 *	MyClass::Verify(String& string, bool& out)
 *	{
 *		static const Short MINIMUM(1230);
 *
 *		result r = E_SUCCESS;
 *
 *		short s;
 *		r = Short::Parse(string, s)
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		out = (MINIMUM.Compare(s) == 0) ? true: false;
 *
 *		return r;
 *	CATCH:
 *		return r;
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ Short
	: public Number
{
public:
	/**
	 *	Initializes this instance of %Short with the specified @c value.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	A @c short value
	 */
	Short(short value = 0);

	/**
	 *	This is the copy constructor for the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value 	An instance of %Short
	 */
	Short(const Short& value);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since 2.0
	 */
	virtual ~Short(void);

	/**
	 * Assigns the value of the specified instance to the current instance of %Short.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %Short
	 */
	Short& operator =(const Short& rhs);

	/**
	 *	Compares the specified @c short values.
	 *
	 *	@since 2.0
	 *
	 *	@return	A 32-bit @c signed @c integer value
	 *	@param[in]	s1	The first @c short value to compare
	 *	@param[in]	s2	The second @c short value to compare
	 *
	 *	@code
	 *	<  0  if @c s1 is less than @c s2
	 *	== 0  if @c s1 is equal to @c s2
	 *	>  0  if @c s1 is greater than @c s2
	 *	@endcode
	 */
	static int Compare(short s1, short s2);

	/**
	 *	Compares the value of the current instance of the %Short class
	 *	with the value of the specified instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed 32-bit @c integer value
	 *	@param[in]	value An instance of the %Short class to compare
	 *
	 *	@code
	 *	<  0  if the value of the current instance is less than that of the specified instance
	 *	== 0  if the value of the current instance is equal to that of the specified instance
	 *	>  0  if the value of the current instance is greater than that of the specified instance
	 *	@endcode
	 */
	int CompareTo(const Short& value) const;

	/**
	 *	Checks whether the value of the specified instance of Object is equal to the value of the current instance of %Short.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the value of the specified instance of Object is equal to the value of the current instance of %Short, @n
	 *				else @c false
	 *	@param[in]	obj An instance of Object to compare
	 *	@remarks 	The method returns @c false if the specified object is not of the
	 *				type @c short.
	 * 	@see		Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;


	/**
	 *	Checks whether the value of the current instance is equal to the specified @c short value.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the value of the current instance is equal to the specified @c short value, @n
	 *				else @c false
	 *	@param[in]	value 	A @c short value to compare
	 */
	bool Equals(short value) const;

	/**
	 *	Gets the hash value of the current instance of %Short.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance of %Short
	 *	@remarks 	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs. @n
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	*        Gets the hash value of the specified @c short value.
	*
	*        @since 2.0
	*
	*        @return        An integer value indicating the hash value of the specified @c short value
	*        @param[in]   val   A @c short value to get the hash value
	*/
	static int GetHashCode(short val);

	/**
	 *	Decodes a string into a @c signed @c short.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	s	 A numeric value
	 *	@param[out]	ret	The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *	@remarks	This method accepts decimal, hexadecimal, and octal numbers given by the
	 *				following grammar:
	 *
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
	static result Decode(const String& s, short& ret);

	/**
	 *	Parses the specified string representing a numeric value and
	 *	returns the value as @c signed @c short.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	s				A string representing a numeric value
	 *	@param[out]	ret				The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *	@remarks
	 *				- This method assumes that the string representing the numeric value uses a radix 10.
	 *				- This method guarantees that the original value of out-parameter is not changed when the method returns error.
	 */
	static result Parse(const String& s, short& ret);

	/**
	 *	Parses the specified string representing a numeric value
	 *	using the specified radix and returns the value as @c signed @c short.
	 *
	 *	@since 2.0
	 *
	 *	@return		An error code
	 *	@param[in]	s		A string representing a numeric value
	 *	@param[in]	radix		The radix of the string representing a numeric value @n
	 *						It must either be @c 2, @c 8, @c 10, or @c 16.
	 *	@param[out]	ret				The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *	@exception	E_OUT_OF_RANGE The specified @c radix is invalid.
	 *	@remarks	This method guarantees that the original value of out-parameter is not changed when the method returns error.
	 */
	static result Parse(const String& s, int radix, short& ret);

	/**
	 *	Gets the @c signed @c char equivalent of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const;

	/**
	 *	Gets the @c signed @c short equivalent of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const;

	/**
	 *	Gets the @c signed @c int equivalent of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const;

	/**
	 *	Gets the @c signed @c long equivalent of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const;

	/**
	*	Gets the @c signed @c long @c long equivalent of the current instance of the %Short class.
	*
	*	@since 2.0
	*
	*	@return	A @c signed @c long @c long equivalent of the current instance
	*/
	virtual long long ToLongLong(void) const;

	/**
	 *	Gets the @c signed @c float equivalent of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const;

	/**
	 *	Gets the @c signed @c double equivalent of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *	@return	A @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const;

	/**
	 * Gets the string representing the value of the current instance of the %Short class.
	 *
	 *	@since 2.0
	 *
	 *  @return		A string representing the value of the current instance
	 */
	virtual String ToString(void) const;

	/**
	 *	Gets the string representing the specified @c signed @c short value.
	 *
	 *	@since 2.0
	 *
	 *	@return			A string containing a Unicode representation of the specified @c signed @c short value
	 *	@param[in]	value 	A @c signed @c short value to convert
	 */
	static String ToString(short value);

	/**
	 *	A constant holding the maximum value a @c short will be equal to 2^15-1.
	 *
	 *	@since 2.0
	 */
	static const short VALUE_MAX = (short) 0x7FFF;

	/**
	 *	A constant holding the minimum value a @c short will be equal to -2^15.
	 *
	 *	@since 2.0
	 */
	static const short VALUE_MIN = (short) 0x8000;

	/**
	 * A @c short value of this instance.
	 *
	 * @since 2.0
	 */
	short value;


private:
	friend class _ShortImpl;
	class _ShortImpl * __pShortImpl;

}; // Short

}} // Tizen::Base

#endif //_FBASE_SHORT_H_
