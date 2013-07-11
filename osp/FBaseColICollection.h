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
 * @file		FBaseColICollection.h
 * @brief		This is the header file for the %ICollection interface.
 *
 * This header file contains the declarations of the %ICollection interface.
 *
 */
#ifndef _FBASE_COL_ICOLLECTION_H_
#define _FBASE_COL_ICOLLECTION_H_

#ifdef ICollection
#undef ICollection
#endif

#include <FBaseTypes.h>
#include <FBaseColIEnumerator.h>
#include <FBaseRtMutex.h>


#ifdef ICollection
#undef ICollection
#endif

namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface ICollection
 * @brief	This interface represents a collection of objects.
 *			It defines the size, enumerators, and the synchronization mechanism of a collection.
 *
 * @since 2.0
 *
 * The %ICollection interface represents a collection of objects. It defines the size, enumerators, and the synchronization mechanism of a collection.
 *
 */
class _OSP_EXPORT_ ICollection
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ICollection(void) {}

	/**
	 * Gets the number of objects currently stored in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		An integer value indicating the number of objects currently stored in the collection
	 */
	virtual int GetCount(void) const = 0;

	/**
	 * Gets the enumerator of the %ICollection derived class,
	 * or returns @c null if some exception occurs.
	 *
	 * @since 2.0
	 *
	 * @return	    A pointer to an enumerator interface of the %ICollection derived class, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	 * @remarks		Use this method to obtain an enumerator (an instance of the IEnumerator derived class)
	 *				to iterate over a collection (an instance of the %ICollection derived class).
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 *
	 */
	virtual IEnumerator* GetEnumeratorN(void) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICollection_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ICollection_Reserved2(void) { }

}; // ICollection

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_ICOLLECTION_H_
