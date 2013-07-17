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
 * @file		FBaseColRandomIteratorT.h
 * @brief		This is the header file for the %RandomIteratorT class.
 *
 * This header file contains the declarations of the %RandomIteratorT class.
 */

#ifndef _FBASE_COL_RANDOM_ITERATOR_T_H_
#define _FBASE_COL_RANDOM_ITERATOR_T_H_

#include <algorithm>	// std::swap (Before C++11)
#include <iterator>
#include <FBaseColIList.h>
#include <FBaseLog.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base { namespace Collection
{
/**
 * @class 	RandomIteratorT
 * @brief	This class provides a random iterator that is used to convert IList to STL containers. @n
 *			StlConverter provides static methods to get this random iterator from %IList.
 *
 * @since	2.1
 *
 * @remarks	The %RandomIteratorT class satisfies only requirements of C++ standard library InputIterator concept due to limitations of %Tizen collection.
 * 			So, this class can be used with C++ standard library algorithms which requires only InputIterator concept for their arguments.
 *
 * The %RandomIteratorT class provides a random iterator that is used to convert IList to STL containers.
 * StlConverter provides static methods to get this random iterator from IList.
 */

template < typename T >
class RandomIteratorT
	: public std::iterator< std::input_iterator_tag, T >
{
public:
	/**
	 * Initializes this instance of %RandomIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	list		A reference to the IList instance to convert
	 * @param[in]	index	A start index
	 * @remarks			%RandomIteratorT only supports random accessible collection for performance.
	 * @see				Tizen::Base::Collection::IList::IsRandomAccessible()
	 */
	explicit RandomIteratorT(const IList& list, int index = 0)
		: __pList(&list)
		, __index(index)
		, __currentObj(static_cast< T >(const_cast< Object* >(__pList->GetAt(__index))))
	{
		AppAssertf(list.IsRandomAccessible(), "The list is not randomly accessible. RandomIteratorT only supports random accessible collection.");
	}

	/**
	 * This is the copy constructor of the %RandomIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs	A reference to the %RandomIteratorT instance
	 */
	RandomIteratorT(const RandomIteratorT< T >& rhs)
		: __pList(rhs.__pList)
		, __index(rhs.__index)
		, __currentObj(rhs.__currentObj)
	{
	}

	/**
	 * This is the assignment operator of the %RandomIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %RandomIteratorT instance
	 * @param[in]	rhs	A reference to the %RandomIteratorT instance on the right-hand side of the operator
	 */
	RandomIteratorT< T >& operator=(const RandomIteratorT< T >& rhs)
	{
		RandomIteratorT< T > tmp(rhs);
		tmp.swap(*this);
		return *this;
	}

	/**
	 * This is the indirection operator for the %RandomIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A T type reference
	 */
	T& operator*(void) const
	{
		AppAssertf(__index >= 0 && __index < __pList->GetCount(), "It is out of range.");
		return const_cast< T& >(__currentObj);
	}

	/**
	 * This is the structure dereference operator for the %RandomIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A T type pointer equivalent to the pointer address
	 */
	T* operator->(void) const
	{
		return &(operator*());
	}

	/**
	 * Increases __index by 1.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %RandomIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	RandomIteratorT< T >& operator++(void)
	{
		++__index;

		// GetAt() will return null if __index is out of range.
		__currentObj = static_cast< T >(const_cast< Object* >(__pList->GetAt(__index)));
		TryReturnResult(__currentObj != null, *this, GetLastResult(), "[%s] It is out of range.", GetErrorMessage(GetLastResult()));
		return *this;
	}

	/**
	 * Increases __index by 1 and returns the previous state.
	 *
	 * @since		2.1
	 *
	 * @return		A %RandomIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	RandomIteratorT< T > operator++(int)
	{
		RandomIteratorT< T > tempIter = *this;
		operator++();
		return tempIter;
	}

	/**
	 * Decrease __index by 1.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %RandomIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	RandomIteratorT< T >& operator--(void)
	{
		--__index;

		// GetAt() will return null if __index is out of range.
		__currentObj = static_cast< T >(const_cast< Object* >(__pList->GetAt(__index)));
		TryReturnResult(__currentObj != null, *this, GetLastResult(), "[%s] It is out of range.", GetErrorMessage(GetLastResult()));
		return *this;
	}

	/**
	 * Decrease __index by 1 and returns the previous state.
	 *
	 * @since		2.1
	 *
	 * @return		A %RandomIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	RandomIteratorT< T > operator--(int)
	{
		RandomIteratorT< T > tempIter = *this;
		operator--();
		return tempIter;
	}

	/**
	 * 	Checks two %RandomIteratorT instances for equality.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if every member of the specified %RandomIteratorT instance equals the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %RandomIteratorT instance on the right-hand side of the operator
	 */
	bool operator==(const RandomIteratorT< T >& rhs) const
	{
		return ((__pList == rhs.__pList) && (__index == rhs.__index) && (__currentObj == rhs.__currentObj));
	}

	/**
	 * 	Checks two %RandomIteratorT instances for inequality.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if any member of the specified %RandomIteratorT instance is not equal to the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %RandomIteratorT instance on the right-hand side of the operator
	 */
	bool operator!=(const RandomIteratorT< T >& rhs) const
	{
		return !operator==(rhs);
	}

	/**
	 * 	Checks l-value is less than r-value.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if l-value of the specified %RandomIteratorT instance is less than the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %RandomIteratorT instance on the right-hand side of the operator
	 */
	bool operator<(const RandomIteratorT< T >& rhs) const
	{
		return __index < rhs.__index;
	}

	/**
	 * 	Checks whether l-value is greater than r-value.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if l-value of the specified %RandomIteratorT instance is greater than the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %RandomIteratorT instance on the right-hand side of the operator
	 */
	bool operator>(const RandomIteratorT< T >& rhs) const
	{
		return __index > rhs.__index;
	}

	/**
	 * Increases __index as specified by the diff parameter.
	 *
	 * @since		2.1
	 *
	 * @return		A %RandomIteratorT instance
	 * @param[in]	diff		The length to move forward
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	RandomIteratorT< T > operator+(int diff)
	{
		RandomIteratorT< T > tempIter = *this;
		tempIter.__index += diff;

		// GetAt() will return null if __index is out of range.
		tempIter.__currentObj = static_cast< T >(const_cast< Object* >(tempIter.__pList->GetAt(tempIter.__index)));
		TryReturnResult(tempIter.__currentObj != null, tempIter, GetLastResult(), "[%s] It is out of range.", GetErrorMessage(GetLastResult()));
		return tempIter;
	}

	/**
	 * Decrease __index as specified by the diff parameter.
	 *
	 * @since		2.1
	 *
	 * @return		A %RandomIteratorT instance
	 * @param[in]	diff		The length to move backward
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	RandomIteratorT< T > operator-(int diff)
	{
		RandomIteratorT< T > tempIter = *this;
		tempIter.__index -= diff;

		// GetAt() will return null if __index is out of range.
		tempIter.__currentObj = static_cast< T >(const_cast< Object* >(tempIter.__pList->GetAt(tempIter.__index)));
		TryReturnResult(tempIter.__currentObj != null, tempIter, GetLastResult(), "[%s] It is out of range.", GetErrorMessage(GetLastResult()));
		return tempIter;
	}

	int operator-(const RandomIteratorT< T >& rhs)
	{
		return __index - rhs.__index;
	}

	/**
	 * This is the index operator for the %RandomIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the T type instance
	 * @param[in]	index	An index to reach
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure,
	 * 									or the specified index is either equal to or greater than the number of elements in the list or less than 0.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	T& operator[](int index) const
	{
		// GetAt() will return null if __index is out of range.
		const T& tempObj = static_cast< T >(const_cast< Object* >(__pList->GetAt(index)));
		TryReturnResult(tempObj != null, const_cast< T& >(tempObj), GetLastResult(), "[%s] It is out of range.", GetErrorMessage(GetLastResult()));
		return const_cast< T& >(tempObj);
	}

	/**
	 * 	Swaps values of the two %RandomIteratorT instances.
	 *
	 *	@since		2.1
	 *
	 * 	@param[in]	rhs	A reference to the %RandomIteratorT instance to swap
	 */
	void swap(RandomIteratorT< T >& rhs)
	{
		std::swap(__pList, rhs.__pList);
		std::swap(__index, rhs.__index);
		std::swap(__currentObj, rhs.__currentObj);
	}

private:
	const IList* __pList;
	int __index;
	T __currentObj;
}; // RandomIteratorT

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_RANDOM_ITERATOR_T_H_
