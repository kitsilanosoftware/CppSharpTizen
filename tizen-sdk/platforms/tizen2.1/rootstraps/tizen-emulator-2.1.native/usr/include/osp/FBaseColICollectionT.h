//
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
 * @file		FBaseColICollectionT.h
 * @brief		This is the header file for the %ICollectionT interface.
 *
 * This header file contains the declarations of the %ICollectionT interface.
 *
 */
#ifndef _FBASE_COL_BASE_ICOLLECTION_T_H_
#define _FBASE_COL_BASE_ICOLLECTION_T_H_

#include <FBaseTypes.h>
#include <FBaseColIEnumeratorT.h>
#include <FBaseRtMutex.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface ICollectionT
 * @brief	This interface represents a template-based collection of objects.
 *			It defines the size, and enumerators.
 *
 * @since 2.0
 *
 * The %ICollectionT interface represents a template-based collection of objects.
 *			It defines the size, and enumerators.
 */
template< class Type >
class ICollectionT
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ICollectionT(void) {}

	/**
	 * Gets the number of objects currently stored in the collection.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in the collection
	 */
	virtual int GetCount(void) const = 0;

	/**
	 * Gets the enumerator of the %ICollectionT derived class,
	 * or returns @c null if an exception occurs.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to an enumerator interface of the %ICollectionT derived class, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	  The memory is insufficient.
	 * @remarks		Use this method to obtain an enumerator (an instance of the IEnumeratorT derived class)
	 *				to iterate over a collection (an instance of the %ICollectionT derived class).
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
	 */
	virtual IEnumeratorT< Type >* GetEnumeratorN(void) const = 0;

}; // ICollectionT

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_ICOLLECTION_T_H_
