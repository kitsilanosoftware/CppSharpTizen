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
 * @file		FBaseDouble.h
 * @brief		This is the header file for the %Double class.
 *
 * @see			Tizen::Base::Number
 *
 * This header file contains the declarations of the %Double class.
 */
#ifndef _FBASE_DOUBLE_H_
#define _FBASE_DOUBLE_H_

#include <FBaseNumber.h>


namespace Tizen { namespace Base
{
/**
 *	@class	Double
 *	@brief	This class is the wrapper class for the @c signed @c double built-in type.
 *
 *	@since 2.0
 *
 *  The %Double class is the wrapper class for the @c signed @c double built-in type.
 *
 *	It represents a double-precision 64-bit number with values ranging from negative
 *	1.79769313486232e308 to positive 1.79769313486232e308. This class is useful when passing a @c double
 *	value to a method expecting an instance of Object, such as Tizen::Base::Collection::Queue or
 *	Tizen::Base::Collection::Stack. Furthermore, this class provides methods for converting
 *	%Double (and @c double) to String, and String to %Double (and @c double).
 *
 *  The following example demonstrates how to use the %Double class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	// This method checks whether the given string object contains a string
 *	// representation of the pre-defined minimum double value.
 *	result
 *	MyClass::Verify(const String& string, bool& out)
 *	{
 *		static const Double MINIMUM(1.23L);
 *
 *		result r = E_SUCCESS;
 *
 *		double d;
 *		r = Double::Parse(string, d);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		out = (MINIMUM.CompareTo(d) == 0) ? true: false;
 *
 *		return r;
 *	CATCH:
 *		return r;
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ Double
	: public Number
{
public:
	/**
	 * Initializes this instance of %Double with the specified value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value 	A @c double value
	 */
	Double(double value = 0.0L);


	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value   An instance of %Double
	 */
	Double(const Double& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Double(void);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %Double
	 */
	Double& operator =(const Double& rhs);

	/**
	 * Compares two @c double values.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @code
	 * <  0  if the value of @c d1 is less than the value of @c d2
	 * == 0  if the value of @c d1 is equal to the value of @c d2
	 * >  0  if the value of @c d1 is greater than the value of @c d2
	 * @endcode
	 * @param[in]	d1	The first @c double value to compare
	 * @param[in]	d2	The second @c double value to compare
	 */
	static int Compare(double d1, double d2);

	/**
	 * Compares the value of the current instance of %Double with the value of the specified @c signed @c double.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @code
	 * <  0  if the value of the current instance is less than the specified @c signed @c double
	 * == 0  if the value of the current instance is equal to the specified @c signed @c double
	 * >  0  if the value of the current instance is greater than the specified @c signed @c double
	 * @endcode
	 * @param[in]	value   A @c signed @c double value
	 */
	int CompareTo(double value) const;

	/**
	 * Compares the value of the current instance of %Double with the value of the specified instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @code
	 * <  0  if the value of the current instance is less than the value of the specified instance
	 * == 0  if the value of the current instance is equal to the value of the specified instance
	 * >  0  if the value of the current instance is greater than the value of the specified instance
	 * @endcode
	 * @param[in]	value   An instance of %Double
	 */
	int CompareTo(const Double& value) const;

	/**
	 * Checks whether the value of the specified instance of Object is equal to the value of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the specified instance of %Object is equal to the value of the current instance of %Double, @n
	 *				else @c false
	 * @param[in]	obj An instance of Object to compare
	 * @see			Tizen::Base::Object::Equals
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance of %Double.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance of %Double
	 *	@remarks 	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs. @n
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	*        Gets the hash value of the specified @c double value.
	*
	*        @since 2.0
	*
	*        @return        An integer value indicating the hash value of the specified @c double value
	*        @param[in]   val   A @c double value to get the hash value
	*/
	static int GetHashCode(double val);

	/**
	 * Parses the specified string representing a numeric value and returns the value as @c signed @c double (as out parameter).
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	s				A unicode representation of @c signed @c double value
	 * @param[out]	ret 			The converted numeric value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 * @remarks		
	 * 					- This method guarantees that the original value of out-parameter is not changed when the method returns error.
	 * 					- The behavior of this method is dependent on the system default locale setting.
	 */
	static result Parse(const String& s, double& ret);

	/**
	 * Gets the @c signed @c char equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const;

	/**
	 * Gets the @c signed @c short equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const;

	/**
	 * Gets the @c signed @c int equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const;

	/**
	 * Gets the @c signed @c long equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const;

	/**
	 * Gets the @c signed @c long @c long equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c long @c long equivalent of the current instance
	 */
	virtual long long ToLongLong(void) const;

	/**
	 * Gets the @c signed @c float equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const;

	/**
	 * Gets the @c signed @c double equivalent of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return	A @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const;

	/**
	 * Gets the string representing the value of the current instance of %Double.
	 *
	 * @since 2.0
	 *
	 * @return		A string containing a Unicode representation of the value of the current instance
	 * @remarks		
	 *				- If the value of the current instance is Not-a-Number (NaN), the result is the string "NaN". Furthermore, infinity
	 *				produces the result "Infinity". @n
	 *				6 digits are given for the precision of this method. Use String::Format() to set the specific precision.
	 * 				- The behavior of this method is dependent on the system default locale setting.
	 */
	virtual String ToString(void) const;

	/**
	 * Gets the string representing the specified @c double value.
	 *
	 * @since 2.0
	 *
	 * @return		A string containing a Unicode representation of the specified @c double value
	 * @param[in]	value A @c double value to convert
	 * @remarks		
	 * 				- If the input value is Not-a-Number (NaN), the result is the string "NaN". Furthermore, infinity
	 *				produces the result "Infinity". @n
	 *				6 digits are given for the precision of this method. Use String::Format() to set the specific precision.
	 * 				- The behavior of this method is dependent on the system default locale setting.
	 */
	static String ToString(double value);

	/**
	 * Gets the IEEE 754 floating-point "double format" bit layout representation of the specified @c double value.
	 *
	 * @since 2.0
	 *
	 * @return		The bits that represent the floating-point number in the IEEE 754 floating-point "double format" bit layout
	 * @param[in]	value 	A @c double value to convert
	 */
	static long long ToBits(double value);

	/**
	 * Gets the @c double value equivalent of the specified floating-point value represented in the IEEE 754 floating-point "double format" bit layout.
	 *
	 * @since 2.0
	 *
	 * @return		The @c double floating-point value with the same bit pattern
	 * @param[in]	value 	The floating-point value to convert
	 */
	static double ToDoubleFromBits(long long value);

	/**
	 * Checks whether the current value of %Double is equal to negative or positive infinity.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the current value equals negative or positive infinity, @n
	 *				else @c false
	 */
	bool IsInfinity(void) const;

	/**
	 * Checks whether the specified @c double value is equal to negative or positive infinity.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified value equals negative or positive infinity, @n
	 *				else @c false
	 * @param[in]	value  	A @c double value to check
	 */

	static bool IsInfinity(double value);

	/**
	 * Checks whether the current value is Not-a-Number.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the current value is Not-a-Number, @n
	 *				else @c false
	 */
	bool IsNaN(void) const;

	/**
	 * Checks whether the specified value is Not-a-Number.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified value is Not-a-Number, @n
	 *				else @c false
	 * @param[in]	value  	A @c double value to check
	 */
	static bool IsNaN(double value);

	/**
	 * Gets a constant holding the largest positive finite value of type @c double. @n
	 * This is equal to the value defined in Limit.h of the C library.
	 *
	 * @since 2.0
	 *
	 * @return		A constant holding the largest positive finite value of type @c double
	 */
	static double GetMaxValue(void);

	/**
	 * Gets a constant holding the smallest positive non-zero value of type @c double. @n
	 * This is equal to the value defined in Limit.h of the C library.
	 *
	 * @since 2.0
	 *
	 * @return		A constant holding the smallest possible non-zero value of type @c double
	 */
	static double GetMinValue(void);

	/**
	 * A @c double value of this instance.
	 *
	 * @since 2.0
	 */
	double value;


private:
	/**
	 *	Checks if the specified @c double value is finite.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the specified value is finite, @n
	 *				else @c false
	 *	@param[in]	value   A @c double value to check
	 */
	static bool IsFinite(double d);

	static const int __DBL_MAX_10_EXP = 308;

	friend class _DoubleImpl;
	class _DoubleImpl * __pDoubleImpl;

}; // Double

}} // Tizen::Base

#endif //_FBASE_DOUBLE_H_
