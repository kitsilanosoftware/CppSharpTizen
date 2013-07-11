//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseColIComparer.h
 * @brief		This is the header file for the %IComparer interface.
 *
 * This header file contains the declarations of the %IComparer interface.
 */
#ifndef _FBASE_COL_ICOMPARER_H_
#define _FBASE_COL_ICOMPARER_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Collection
{
/**
 * @interface IComparer
 * @brief This interface allows a derived class to compare 2 objects of the same type.
 *
 * @since 2.0
 *
 * The %IComparer interface allows a derived class to compare 2 objects of the same type.
 */
class _OSP_EXPORT_ IComparer
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IComparer(void) { }

public:
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
	 * @exception	E_INVALID_ARG	The specified object instances are not of the expected type.
	 * @remarks		The value of @c cmp can be:
	 *
	 * @code
	 * <  0  if the value of @c obj1 is less than the value of @c obj2
	 * == 0  if the value of @c obj1 is equal to the value of @c obj2
	 * >  0  if the value of @c obj1 is greater than the value of @c obj2
	 * @endcode
	 */
	virtual result Compare(const Tizen::Base::Object& obj1, const Tizen::Base::Object& obj2, int& cmp) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IComparer_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IComparer_Reserved2(void) { }

}; // IComparer
}}} // Tizen::Base::Collection

#endif // _FBASE_COL_ICOMPARER_H_
