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
 * @file		FBaseDoubleComparer.h
 * @brief		This is the header file for the %DoubleComparer class.
 *
 * @see			Double and Tizen::Base::Collection::IComparer
 *
 * This header file contains the declarations of the %DoubleComparer class.
 */
#ifndef _FBASE_DOUBLE_COMPARER_H_
#define _FBASE_DOUBLE_COMPARER_H_

#include <FBaseObject.h>
#include <FBaseColIComparer.h>


namespace Tizen { namespace Base
{
/**
 *	@class	DoubleComparer
 *	@brief	This class checks for equivalence between 2 instances of the Double type.
 *
 *	@since 2.0
 *
 *	The %DoubleComparer class checks for equivalence between 2 instances of the Double type.
 *
 *  For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/collection_comparison.htm">Collection Comparisons</a>.
 *
 *  The following example demonstrates how to use the %DoubleComparer class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::DoubleComparerSample(void)
 *	{
 *		Double d1(123);
 *		Double d2(124);
 *		DoubleComparer comparer;
 *
 *		// Compare 2 instances of Double
 *		int cmp;
 *		comparer.Compare(d1, d2, cmp);
 *		if (cmp < 0)
 *		{
 *			// ...
 *		}
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ DoubleComparer
	: public Object
	, public virtual Tizen::Base::Collection::IComparer
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	DoubleComparer(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~DoubleComparer(void);

	/**
	 *	Compares two given instances of type Double.
	 *
	 *	@since 2.0
	 *
	 *	@return		An error code
	 *	@param[in]	obj1 	The first instance of type %Double
	 *	@param[in]	obj2 	The second instance of type %Double
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
	DoubleComparer(const DoubleComparer& obj);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	DoubleComparer& operator =(const DoubleComparer& rhs);

	friend class _DoubleComparerImpl;
	class _DoubleComparerImpl * __pDoubleComparerImpl;

}; // DoubleComparer

}} // Tizen::Base

#endif // _FBASE_DOUBLE_COMPARER_H_
