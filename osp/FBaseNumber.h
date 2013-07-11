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
 * @file		FBaseNumber.h
 * @brief		This is the header file for the %Number class.
 *
 * This header file contains the declarations and definitions of the %Number class. @n
 * This class is the abstract base class of all wrapped numeric types.
 */
#ifndef _FBASE_NUMBER_H_
#define _FBASE_NUMBER_H_

#include <FBaseObject.h>
#include <FBaseString.h>


namespace Tizen { namespace Base
{
/**
 *	@class	Number
 *	@brief	This class is the base class of all wrapped numeric types.
 *
 *	@since 2.0
 *
 *	The %Number class is the abstract base class of all wrapped numeric classes.
 *	The subclasses of %Number must provide methods to convert the represented
 *	numeric value to @c char, @c short, @c int, @c long, @c float, and @c double.
 *
 * The following example demonstrates how to use the %Number class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::NumberSample(void)
 *	{
 *		Long ld(0x12345678L);
 *		int i = ld.Toint(); 		// i == 0x5678
 *		char ch = ld.ToChar();	// ch == 0x78 or 120
 *		// ...
 *		Int8 j(ch);
 *		Float f1(j.ToFloat()); // f1 == 120.0
 *		// ...
 *		Double d(120.100005L);
 *		Float f2(d.ToFloat()); 	// f2 == 120.10001
 *		Integer k(f2.ToInt()); 	// k == 120
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ Number
	: public Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Number(void) { };

	/**
	 *	Gets the @c signed @c char equivalent of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const = 0;

	/**
	 *	Gets the @c signed @c short equivalent of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const = 0;

	/**
	 *	Gets the @c signed @c int equivalent of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const = 0;

	/**
	 *	Gets the @c signed @c long equivalent of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const = 0;

	/**
	*	Gets the @c signed @c long @c long equivalent of the current instance of the %Number class.
	*
	*	@since 2.0
	*
	*	@return		The @c signed @c long @c long equivalent of the current instance
	*/
	virtual long long ToLongLong(void) const = 0;

	/**
	 *	Gets the @c signed @c float equivalent of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const = 0;

	/**
	 *	Gets the @c signed @c double equivalent of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const = 0;

	/**
	 *	Gets the string representing the value of the current instance of the %Number class.
	 *
	 *	@since 2.0
	 *
	 *	@return		The string representing the value of the current instance
	 */
	virtual String ToString(void) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void Number_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void Number_Reserved2(void) { }

}; // Number

}}   // Tizen::Base

#endif // _FBASE_NUMBER_H_
