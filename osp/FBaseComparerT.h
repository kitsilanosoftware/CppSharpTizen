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
 * @file		FBaseComparerT.h
 * @brief		This is the header file for the %ComparerT class.
 *
 * This file contains declarations of the %ComparerT class.
 */
#ifndef _FBASE_COMPARER_T_H_
#define _FBASE_COMPARER_T_H_

// Includes
#include <FBaseTypes.h>
#include <FBaseColIComparerT.h>


namespace Tizen { namespace Base
{
/**
 * @class ComparerT
 *
 * @brief	This class checks for equivalence between 2 values of the same primitive type.
 * @since 2.0
 *
 * The %ComparerT class checks for equivalence between 2 values of the same primitive type.
 *
 * The following example demonstrates how to use the %ComparerT class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::ComparerTSample(void)
 *	{
 *		double d1 = 123;
 *		double d2 = 124;
 *		ComparerT<double> comparer;
 *
 *		// Compares 2 instances of Double
 *		int cmp;
 *		comparer.Compare(d1, d2, cmp);
 *		if (cmp < 0)
 *		{
 *			// ...
 *		}
 *	}
 * @endcode
 */
template<class Type>
class ComparerT
	: public virtual Tizen::Base::Collection::IComparerT <Type>
	, public Object
{
public:
	/**
	 * This constructor initializes a new instance of the %ComparerT class.
	 *
	 * @since 2.0
	 */
	ComparerT(void) { }


	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ComparerT(void) { }

	/**
	 * Compares two given instances of the same type.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj1    The first object to compare
	 * @param[in]	obj2    The second object to compare
	 * @param[out]  cmp		The result of comparison
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified objects are not of the expected type.
 	 * @remarks		@c cmp can take one of the following values:
	 * @code
	 * <  0  if the value of @c obj1 is less than the value of @c obj2
	 * == 0  if the value of @c obj1 is equal to the value of @c obj2
	 * >  0  if the value of @c obj1 is greater than the value of @c obj2
	 * @endcode
	 */
	virtual result Compare(const Type& obj1, const Type& obj2, int& cmp) const
	{
		if (obj1 > obj2)
		{
			cmp = 1;
		}
		else if (obj1 < obj2)
		{
			cmp = -1;
		}
		else
		{
			cmp = 0;
		}

		return E_SUCCESS;
	}

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ComparerT(const ComparerT& obj);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ComparerT& operator =(const ComparerT& rhs);

}; // ComparerT

template<>
class ComparerT <Tizen::Base::String>
	: public virtual Tizen::Base::Collection::IComparerT <Tizen::Base::String>
	, public Object
{
public:
	/**
	 * This constructor initializes a new instance of the %ComparerT class.
	 *
	 * @since 2.1
	 */
	ComparerT(void) { }

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.1
	 */
	virtual ~ComparerT(void) { }

	/**
	 * Compare two String instances.
	 *
	 * @since 2.1
	 *
	 * @return       Always returns E_SUCCESS
	 * @param[in]    str1     The String instance to compare
	 * @param[in]    str2     The String instance to compare
	 * @param[in]    cmp      An integer value for result
	 */
	virtual result Compare(const Tizen::Base::String& str1, const Tizen::Base::String& str2, int& cmp) const
	{
		cmp = String::Compare(str1, str2);
		return E_SUCCESS;
	}
private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ComparerT(const ComparerT& obj);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ComparerT& operator =(const ComparerT& rhs);

}; // ComparerT <Tizen::Base::String>

}} // Tizen::Base

#endif // _FBASE_COMPARER_T_H_
