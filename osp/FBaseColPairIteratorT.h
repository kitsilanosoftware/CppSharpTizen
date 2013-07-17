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
 * @file		FBaseColPairIteratorT.h
 * @brief		This is the header file for the %PairIteratorT class.
 *
 * This header file contains the declarations of the %PairIteratorT class.
 */

#ifndef _FBASE_COL_PAIR_ITERATOR_T_H_
#define _FBASE_COL_PAIR_ITERATOR_T_H_

#include <algorithm>	// std::swap (Before C++11)
#include <iterator>
#include <utility>
#include <unique_ptr.h>
#include <FBaseLog.h>
#include <FBaseColIMap.h>
#include <FBaseColIMultiMap.h>
#include <FBaseColIMapEnumerator.h>

namespace Tizen { namespace Base { namespace Collection
{
/**
 * @class	PairIteratorT
 * @brief	This class provides an iterator that is used to convert IMap or IMultiMap to STL containers. @n
 *			StlConverter provides static methods to get this iterator from %IMap or %IMultiMap.
 *
 * @since	2.1
 *
 * @remarks	The %PairIteratorT class satisfies only requirements of C++ standard library InputIterator concept due to limitations of %Tizen Collection.
 * 			So, this class can be used with C++ standard library algorithms which requires only InputIterator concept for their arguments.
 *
 * The %PairIteratorT class provides an iterator that is used to convert IMap or IMultiMap to STL containers.
 * StlConverter provides static methods to get this iterator from IMap or IMultiMap.
 */

template < typename K, typename V >
class PairIteratorT
	: public std::iterator< std::input_iterator_tag, std::pair< K, V > >
{
public:
	/**
	 * Initializes this instance of %PairIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	map			A reference to the IMap instance to convert
	 * @param[in]	isPostEnd	A boolean value to check the end
	 */
	explicit PairIteratorT(const IMap& map, bool isPostEnd = false)
		: __pMap(&map)
		, __pMultiMap(null)
		, __isPostEnd(isPostEnd)
		, __index(0)
		, __pEnum(__pMap->GetMapEnumeratorN())
		, __currentObj()
	{
		if (__pMap->GetCount() != 0)
		{
			if (!__isPostEnd)
			{
				__pEnum->MoveNext();
				__currentObj.first = static_cast< K >(__pEnum->GetKey());
				__currentObj.second = static_cast< V >(__pEnum->GetValue());
			}
			else
			{
				__index = __pMap->GetCount();
			}
		}
		else
		{
			// Control reaches here intentionally because begin() should be equal to end()
			__isPostEnd = true;
		}
	}

	/**
	 * Initializes this instance of %PairIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	multiMap	A reference to the IMultiMap instance to convert
	 * @param[in]	isPostEnd	A boolean value to check the end
	 */
	PairIteratorT(const IMultiMap& multiMap, bool isPostEnd = false)
		: __pMap(null)
		, __pMultiMap(&multiMap)
		, __isPostEnd(isPostEnd)
		, __index(0)
		, __pEnum(__pMultiMap->GetMapEnumeratorN())
		, __currentObj()
	{
		if (__pMultiMap->GetCount() != 0)
		{
			if (!__isPostEnd)
			{
				__pEnum->MoveNext();
				__currentObj.first = static_cast< K >(__pEnum->GetKey());
				__currentObj.second = static_cast< V >(__pEnum->GetValue());
			}
			else
			{
				__index = __pMultiMap->GetCount();
			}
		}
		else
		{
			// Control reaches here intentionally because begin() should be equal to end()
			__isPostEnd = true;
		}
	}

	/**
	 * This is the copy constructor of the %PairIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs					A reference to the %PairIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Both @c __pMap and @c __pMultiMap are @c null.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	PairIteratorT(const PairIteratorT< K, V >& rhs)
		: __pMap(rhs.__pMap)
		, __pMultiMap(rhs.__pMultiMap)
		, __isPostEnd(rhs.__isPostEnd)
		, __index(rhs.__index)
		, __currentObj(rhs.__currentObj)
	{
		TryReturnVoidResult(__pMap != null || __pMultiMap != null, E_INVALID_ARG, "[%s] __pMap or __pMultiMap should not be null.", GetErrorMessage(E_INVALID_ARG));

		if (__pMap != null)
		{
			__pEnum.reset(__pMap->GetMapEnumeratorN());
		}
		else if (__pMultiMap != null)
		{
			__pEnum.reset(__pMultiMap->GetMapEnumeratorN());
		}

		if (!__isPostEnd)
		{
			for (int i = 0; i <= __index; ++i)
			{
				__pEnum->MoveNext();
			}
		}
	}

	/**
	 * This is assignment operator of the %PairIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %PairIteratorT instance
	 * @param[in]	rhs					A reference to the %PairIteratorT instance on the right-hand side of the operator
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Both @c __pMap and @c __pMultiMap are @c null.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	PairIteratorT< K, V >& operator=(const PairIteratorT< K, V >& rhs)
	{
		PairIteratorT< K, V > tmp(rhs);
		tmp.swap(*this);
		return *this;
	}

	/**
	 * This is the indirection operator for the %PairIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A std::pair type reference with K and V type
	 */
	std::pair< K, V >& operator*(void) const
	{
		AppAssertf(!__isPostEnd, "It is out of range.");
		return const_cast< std::pair< K, V >& >(__currentObj);
	}

	/**
	 * This is the const version structure dereference operator for the %PairIteratorT class.
	 *
	 * @since		2.1
	 *
	 * @return		A std::pair type pointer equivalent to the pointer address
	 */
	std::pair< K, V >* operator->(void) const
	{
		return &(operator*());
	}

	/**
	 * Moves to the next element of the collection.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to the %PairIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the collection.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	PairIteratorT< K, V >& operator++(void)
	{
		TryReturnResult(!__isPostEnd, *this, E_OUT_OF_RANGE, "[%s] It already reached the end.", GetErrorMessage(E_OUT_OF_RANGE));

		result r = __pEnum->MoveNext();
		TryCatchResult(r == E_SUCCESS, __isPostEnd = true; __currentObj.first = null; __currentObj.second = null,
			r, "[%s] It already reached the end.", GetErrorMessage(r));

		__currentObj.first = static_cast< K >(__pEnum->GetKey());
		__currentObj.second = static_cast< V >(__pEnum->GetValue());

CATCH:
		++__index;
		return *this;
	}

	/**
	 * Moves to the next element of the collection and returns the previous state.
	 *
	 * @since	2.1
	 *
	 * @return		A %PairIteratorT instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the collection.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *				 					the collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 */
	PairIteratorT< K, V > operator++(int)
	{
		PairIteratorT< K, V > tempIter = *this;
		operator++();
		return tempIter;
	}

	/**
	 * 	Checks the two %PairIteratorT instances for equality.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if every member of the specified %PairIteratorT instance equals the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %PairIteratorT instance on the right-hand side of the operator
	 */
	bool operator==(const PairIteratorT< K, V >& rhs) const
	{
		if (__pMap != rhs.__pMap)
		{
			return false;
		}

		if (__pMultiMap != rhs.__pMultiMap)
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
	 * 	Checks the two %PairIteratorT instances for inequality.
	 *
	 *	@since		2.1
	 *
	 * 	@return		@c true if any member of the specified %PairIteratorT instance is not equal to the calling instance's members, @n
	 * 				else @c false
	 * 	@param[in]	rhs 	A reference to the %PairIteratorT instance on the right-hand side of the operator
	 */
	bool operator!=(const PairIteratorT< K, V >& rhs) const
	{
		return !operator==(rhs);
	}

	/**
	 * 	Swaps values of the two %PairIteratorT instances.
	 *
	 *	@since		2.1
	 *
	 * 	@param[in]	rhs	A reference to the %PairIteratorT instance to swap
	 */
	void swap(PairIteratorT< K, V >& rhs)
	{
		std::swap(__pMap, rhs.__pMap);
		std::swap(__pMultiMap, rhs.__pMultiMap);
		std::swap(__isPostEnd, rhs.__isPostEnd);
		std::swap(__index, rhs.__index);
		std::swap(__pEnum, rhs.__pEnum);
		std::swap(__currentObj, rhs.__currentObj);
	}

private:
	const IMap* __pMap;
	const IMultiMap* __pMultiMap;
	bool __isPostEnd;
	int __index;
	std::unique_ptr< IMapEnumerator > __pEnum;
	std::pair< K, V > __currentObj;
};	// PairIteratorT

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_PAIR_ITERATOR_T_H_
