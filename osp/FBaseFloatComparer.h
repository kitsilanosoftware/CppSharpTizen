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
 * @file		FBaseFloatComparer.h
 * @brief		This is the header file for the %FloatComparer class.
 *
 * @see			Float and Tizen::Base::Collection::IComparer
 *
 * This header file contains the declarations of the %FloatComparer class.
 */
#ifndef _FBASE_FLOAT_COMPARER_H_
#define _FBASE_FLOAT_COMPARER_H_

#include <FBaseObject.h>
#include <FBaseColIComparer.h>


namespace Tizen { namespace Base
{
/**
 *	@class	FloatComparer
 *	@brief	This class checks for equivalence between 2 instances of the Float type.
 *
 *	@since 2.0
 *
 *	The %FloatComparer class checks for equivalence between 2 instances of the Float type.
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/collection_comparison.htm">Collection Comparisons</a>.
 *
 *	The following example demonstrates how to use the %FloatComparer class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::FloatComparerSample(void)
 *	{
 *		Float f1(123);
 *		Float f2(124);
 *		FloatComparer comparer;
 *
 *		// Compares 2 instances of Float
 *		int cmp;
 *		comparer.Compare(f1, f2, cmp);
 *		if (cmp < 0)
 *		{
 *			// ...
 *		}
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ FloatComparer
	: public Object
	, public Tizen::Base::Collection::IComparer
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since 2.0
	 */
	FloatComparer(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since 2.0
	 */
	virtual ~FloatComparer(void);

	/**
	 *	Compares two given instances of type Float.
	 *
	 *	@since 2.0
	 *
	 *  @return		An error code
	 *	@param[in]	obj1 	The first instance of type Float
	 *	@param[in]	obj2 	The second instance of type Float
	 *	@param[out] cmp		The result of comparison
	 *  @exception	E_SUCCESS		The method is successful.
	 *  @exception	E_INVALID_ARG	The specified object instances are not of the expected type.
	 *  @remarks	The value of @c cmp can be:
	 *
	 *	@code	
	 *	<  0  if the value of @c obj1 is less than the value of @c obj2
	 *	== 0  if the value of @c obj1 is equal to the value of @c obj2
	 *	>  0  if the value of @c obj1 is greater than the value of @c obj2
	 *	@endcode
	 */
	virtual result Compare(const Tizen::Base::Object& obj1, const Tizen::Base::Object& obj2, int& cmp) const;


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FloatComparer(const FloatComparer& obj);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FloatComparer& operator =(const FloatComparer& rhs);

	friend class _FloatComparerImpl;
	class _FloatComparerImpl * __pFloatComparerImpl;

}; // FloatComparer

}} // Tizen::Base

#endif // _FBASE_FLOAT_COMPARER_H_
