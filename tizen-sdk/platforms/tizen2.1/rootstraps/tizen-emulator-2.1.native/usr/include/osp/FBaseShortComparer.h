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
 * @file		FBaseShortComparer.h
 * @brief		This is the header file for the %ShortComparer class.
 *
 * @see			Short
 * @see         Tizen::Base::Collection::IComparer
 *
 * This header file contains the declarations of the %ShortComparer class.
 */
#ifndef _FBASE_SHORT_COMPARER_H_
#define _FBASE_SHORT_COMPARER_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FBaseColIComparer.h>


namespace Tizen { namespace Base
{
/**
 *	@class	ShortComparer
 *	@brief	This class compares 2 instances of the Short type for equivalence.
 *
 *	@since 2.0
 *
 *	The %ShortComparer class compares 2 instances of the Short type for equivalence.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/collection_comparison.htm">Collection Comparisons</a>.
 *
 * The following example demonstrates how to use the %ShortComparer class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::ShortComparerSample(void)
 *	{
 *		Short s1(123);
 *		Short s2(124);
 *		ShortComparer comparer;
 *
 *		int cmp;
 *		comparer.Compare(s1, s2, cmp);
 *		if (cmp < 0)
 *		{
 *			// ...
 *		}
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ ShortComparer
	: public Object
	, public virtual Tizen::Base::Collection::IComparer
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	ShortComparer(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ShortComparer(void);

	/**
	 *	Compares two given instances of type Short.
	 *
	 *	@since 2.0
	 *
	 *  @return			An error code
	 *	@param[in]	obj1 			An object of Short to compare
	 *	@param[in]	obj2 			An object of Short to compare
	 *	@param[out] cmp				The result of comparison
	 *  @exception	E_SUCCESS		The method is successful.
	 *  @exception	E_INVALID_ARG	The specified object instances are not of the expected type.
	 *  @remarks		The value of @c cmp can be:
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
	ShortComparer(const ShortComparer& obj);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ShortComparer& operator =(const ShortComparer& rhs);

	friend class _ShortComparerImpl;
	class _ShortComparerImpl * __pShortComparerImpl;

}; // ShortComparer

}} // Tizen::Base

#endif // _FBASE_SHORT_COMPARER_H_
