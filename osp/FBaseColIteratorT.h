//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FBaseColIteratorT.h
 * @brief		This is the header file for the %IteratorT class.
 *
 * This header file contains the declarations of the %IteratorT class.
 */

#ifndef _FBASE_COL_ITERATOR_T_H_
#define _FBASE_COL_ITERATOR_T_H_

#include <algorithm>	// std::swap (Before C++11)
#include <iterator>
#include <unique_ptr.h>
#include <FBaseLog.h>
#include <FBaseColIList.h>
#include <FBaseColIBidirectionalEnumerator.h>

namespace Tizen { namespace Base { namespace Collection
{
/**
 * @class	IteratorT
 * @brief	This class provides an iterator that is used to convert IList to STL containers. @n
 *			StlConverter provides static methods to get this iterator from %IList.
 *
 * @since	2.1
 *
 * @remarks	The %IteratorT class satisfies only requirements of C++ standard library InputIterator concept due to limitations of %Tizen collection.
 * 			So, this class can be used with C++ standard library algorithms which requires only InputIterator concept for their arguments.
 *
 * The %IteratorT class provides an iterator that is used to convert IList to STL containers.
 * StlConverter provides static methods to get this iterator from IList.
 */

template < typename T >
class IteratorT
	: public std::iterator< std::input_iterator_tag, T >
{
public:
	/**
	 * Initializes an instance of %IteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	list		 A reference to the IList instance to convert
	 * @param[in]	isPostEnd	 A boolean value to check the end of a list
	 */
	explicit IteratorT(const IList& list, bool isPostEnd = false)
		: __pList(&list)
		, __isPostEnd(isPostEnd)
		, __index(0)
		, __pEnum(__pList->GetBidirectionalEnumeratorN())
		, __currentObj(null)
	{
		if (__pList->GetCount() != 0)
		{
			if (!__isPostEnd)
			{
				__pEnum->MoveNext();
				__currentObj = static_cast< T >(__pEnum->GetCurrent());
			}
			else
			{
				__index = __pList->GetCount();
				__pEnum->MovePrevious();
			}
		}
		else
		{
			// Control reaches here intentionally because begin() should be equal to end()
			__isPostEnd = true;
		}
	}

	/**
	 * This is the copy constructor of the %IteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs	A reference to the %IteratorT instance
	 */
	IteratorT(const IteratorT< T >& rhs)
		: __pList(rhs.__pList)
		, __isPostEnd(rhs.__isPostEnd)
		, __index(rhs.__index)
		, __pEnum(__pList->GetBidirectionalEnumeratorN())
		, __currentObj(rhs.__currentObj)
	{
		if (!__isPostEnd)
		{
			for (int i = 0; i <= __index; ++i)
			{
				__pEnum->MoveNext();
			}
		}
		else
		{
			__pEnum->MovePrevious();
		}
	}

	/**
	 * This is an assignment operator of the %IteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %IteratorT instance
	 * @param[in]	rhs	A reference to the %IteratorT instance on the right-hand side of the operator
	 */
	IteratorT< T >& operator=(const IteratorT< T >& rhs)
	{
		IteratorT< T > tmp(rhs);
		tmp.swap(*this);
		return *this;
	}

	/**
	 * This is the indirection operator for the %IteratorT class.
	 *
	 * @since	2.1
	 *
	 * @return		A T type reference
	 */
	T& operator*(void) const
	{
		AppAssertf(!__isPostEnd && __index >= 0, "It is out of range.");
		return const_cast< T& >(__currentObj);
	}

	/**
	 * This is a structure dereference operator for the %IteratorT class.
	 *
	 * @since	2.1
	 *
	 * @return		A T type pointer that is equivalent to the pointer address
	 */
	T* operator->(void) const
	{
		return &(operator*());
	}

	/**
	 * Moves to the next element in the collection.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %IteratorT type instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The iterator is outside the bounds of the list.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	IteratorT< T >& operator++(void)
	{
		const int PRE_BEGIN_IDX = -1;
		TryCatchResult(__index >= PRE_BEGIN_IDX, , E_OUT_OF_RANGE, "[%s] It is out of range.", GetErrorMessage(E_OUT_OF_RANGE));

		if (__index != PRE_BEGIN_IDX)
		{
			result r = __pEnum->MoveNext();
			TryCatchResult(r == E_SUCCESS, __isPostEnd = true; __currentObj = null, r, "[%s] It already reached the end.", GetErrorMessage(r));
		}

		__currentObj = static_cast< T >(__pEnum->GetCurrent());

	CATCH:
		++__index;
		return *this;
	}

	/**
	 * Moves to the next element of the collection and returns the previous state.
	 *
	 * @since	2.1
	 *
	 * @return		An %IteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The iterator is outside the bounds of the list.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	IteratorT< T > operator++(int)
	{
		IteratorT< T > tempIter = *this;
		operator++();
		return tempIter;
	}

	/**
	 * Moves to the previous element of the collection.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %IteratorT type instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The iterator is outside the bounds of the list.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	IteratorT< T >& operator--(void)
	{
		TryCatchResult(__index <= __pList->GetCount(), , E_OUT_OF_RANGE, "[%s] It is out of range.", GetErrorMessage(E_OUT_OF_RANGE));

		if (!__isPostEnd)
		{
			result r = __pEnum->MovePrevious();
			TryCatchResult(r == E_SUCCESS, __currentObj = null, r, "[%s] It already reached the front.", GetErrorMessage(r));
		}
		else
		{
			__isPostEnd = false;
		}

		__currentObj = static_cast< T >(__pEnum->GetCurrent());

CATCH:
		--__index;
		return *this;
	}

	/**
	 * Moves to the previous element of the collection and returns the previous state.
	 *
	 * @since		2.1
	 *
	 * @return		An %IteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The iterator is outside the bounds of the list.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	IteratorT< T > operator--(int)
	{
		IteratorT< T > tempIter = *this;
		operator--();
		return tempIter;
	}

	/**
	 * 	Checks the two %IteratorT instances for equality.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if every member of the specified %IteratorT instance equals the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %IteratorT instance on the right-hand side of the operator
	 */
	bool operator==(const IteratorT< T >& rhs) const
	{
		if (__pList != rhs.__pList)
		{
			return false;
		}

		if (__index != rhs.__index)
		{
			return false;
		}

		if (__isPostEnd != rhs.__isPostEnd)
		{
			return false;
		}
		else if (__isPostEnd && rhs.__isPostEnd)
		{
			// In this case, __currentObj state is invalid
			return true;
		}

		// If both this->__isPostEnd and rhs.__isPostEnd are false, then reach here. This means both iterators are in the middle of the list.
		return __currentObj == rhs.__currentObj;
	}

	/**
	 * 	Checks the two %IteratorT instances for inequality.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if any member of the specified %IteratorT instance is not equal to the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %IteratorT instance on the right-hand side of the operator
	 */
	bool operator!=(const IteratorT< T >& rhs) const
	{
		return !operator==(rhs);
	}

	/**
	 * 	Swaps values of two %IteratorT instances.
	 *
	 *	@since		2.1
	 *
	 * 	@param[in]	rhs	A reference to a %IteratorT instance to swap
	 */
	void swap(IteratorT< T >& rhs)
	{
		std::swap(__pList, rhs.__pList);
		std::swap(__isPostEnd, rhs.__isPostEnd);
		std::swap(__index, rhs.__index);
		std::swap(__pEnum, rhs.__pEnum);
		std::swap(__currentObj, rhs.__currentObj);
	}

private:
	const IList* __pList;
	bool __isPostEnd;
	int __index;
	std::unique_ptr< IBidirectionalEnumerator > __pEnum;
	T __currentObj;
}; // IteratorT

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_ITERATOR_T_H_
