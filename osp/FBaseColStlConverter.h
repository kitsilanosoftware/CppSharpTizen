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
 * @file		FBaseColStlConverter.h
 * @brief		This is the header file for the %StlConverter class.
 *
 * This header file contains the declarations of the %StlConverter class.
 */

#ifndef _FBASE_COL_STL_CONVERTER_H_
#define _FBASE_COL_STL_CONVERTER_H_

#include <utility>
#include <unique_ptr.h>
#include <FBaseColArrayList.h>
#include <FBaseColLinkedList.h>
#include <FBaseColHashMap.h>
#include <FBaseColMultiHashMap.h>
#include <FBaseColIteratorT.h>
#include <FBaseColPairIteratorT.h>
#include <FBaseColRandomIteratorT.h>
#include <FBaseColTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
class IMap;
class IMultiMap;

/**
 * 	@class	StlConverter
 * 	@brief	This class provides static methods to convert %Tizen Collection to STL Container and vice versa.
 *
 * 	@since	2.1
 *
 *	The %StlConverter class provides static methods to convert %Tizen Collection to STL Container and vice versa.
 * 	The following example demonstrates how to use the %StlConverter class.
 *
 * 	@code
 *	#include <vector>
 *	#include <FBase.h>
 *	#include <FBaseCol.h>
 *
 *	using namespace std;
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::StlConverterSample
 *	{
 *		// The case of Collection to STL Container
 *		IList* pList1 = someNativeObject.GetSomeIntegerListN();
 *
 *		// vector can be created through IteratorT
 *		vector< Integer* > vec1(
 *			StlConverter::GetBeginIterator< Integer* >(pList1),
 *			StlConverter::GetEndIterator< Integer* >(pList1));
 *
 *		// vec1 can be used here.
 *
 *		// The case of STL Container to Collection
 *		vector< Integer* > vec2;
 *
 *		vec2.push_back(new Integer(1));
 *		vec2.push_back(new Integer(2));
 *		vec2.push_back(new Integer(3));
 *
 *		unique_ptr< ArrayList > pList2(StlConverter::GetArrayListN(vec2.begin(), vec2.end(), SingleObjectDeleter));
 *
 *		// call SomeNativeAPI(pList2.get());
 *	}
 * 	@endcode
 */

class StlConverter
{
public:
	/**
	 * Gets the STL compatible iterator referring to the first element in the IList instance.
	 *
	 * @since		2.1
	 *
	 * @return		An IteratorT instance
	 * @param[in]	pList			A pointer to the IList instance to convert
	 */
	template < typename T >
	static IteratorT< T > GetBeginIterator(const IList* pList)
	{
		return IteratorT< T >(*pList);
	}

	/**
	 * Gets the STL compatible iterator referring to the post-end element in the IList instance.
	 *
	 * @since		2.1
	 *
	 * @return		An IteratorT instance
	 * @param[in]	pList			A pointer to the IList instance to convert
	 */
	template < typename T >
	static IteratorT< T > GetEndIterator(const IList* pList)
	{
		return IteratorT< T >(*pList, true);
	}

	/**
	 * Gets the STL compatible random iterator referring to the first element in the IList instance.
	 *
	 * @since		2.1
	 *
	 * @return		A RandomIteratorT instance
	 * @param[in]	pList			A pointer to the IList instance to convert
	 */
	template < typename T >
	static RandomIteratorT< T > GetBeginRandomIterator(const IList* pList)
	{
		return RandomIteratorT< T >(*pList, 0);
	}

	/**
	 * Gets the STL compatible random iterator referring to the post-end element in the IList instance.
	 *
	 * @since		2.1
	 *
	 * @return		A RandomIteratorT instance
	 * @param[in]	pList			A pointer to the IList instance to convert
	 */
	template < typename T >
	static RandomIteratorT< T > GetEndRandomIterator(const IList* pList)
	{
		return RandomIteratorT< T >(*pList, pList->GetCount());
	}

	/**
	 * Gets the STL compatible iterator referring to the first element in the IMap instance. @n
	 * This iterator can be used in algorithms that require paired iterators.
	 *
	 * @since		2.1
	 *
	 * @return		A PairIteratorT instance
	 * @param[in]	pMap		A pointer to the IMap instance to convert
	 */
	template < typename K, typename V >
	static PairIteratorT< K, V > GetBeginPairIterator(const IMap* pMap)
	{
		return PairIteratorT< K, V >(*pMap);
	}

	/**
	 * Gets the STL compatible iterator referring to the post-end element in the IMap instance. @n
	 * This iterator can be used in algorithms that require paired iterators.
	 *
	 * @since		2.1
	 *
	 * @return		A PairIteratorT instance
	 * @param[in]	pMap		A pointer to the IMap instance to convert
	 */
	template < typename K, typename V >
	static PairIteratorT< K, V > GetEndPairIterator(const IMap* pMap)
	{
		return PairIteratorT< K, V >(*pMap, true);
	}

	/**
	 * Gets the STL compatible iterator referring to the first element in the IMultiMap instance. @n
	 * This iterator can be used in algorithms that require paired iterators.
	 *
	 * @since		2.1
	 *
	 * @return		A PairIteratorT instance
	 * @param[in]	pMultiMap	A pointer to the IMultiMap instance to convert
	 */
	template < typename K, typename V >
	static PairIteratorT< K, V > GetBeginPairIterator(const IMultiMap* pMultiMap)
	{
		return PairIteratorT< K, V >(*pMultiMap);
	}

	/**
	 * Gets the STL compatible iterator referring to the post-end element in the IMultiMap instance. @n
	 * This iterator can be used in algorithms that require paired iterators.
	 *
	 * @since		2.1
	 *
	 * @return		A PairIteratorT instance
	 * @param[in]	pMultiMap	A pointer to the IMultiMap instance to convert
	 */
	template < typename K, typename V >
	static PairIteratorT< K, V > GetEndPairIterator(const IMultiMap* pMultiMap)
	{
		return PairIteratorT< K, V >(*pMultiMap, true);
	}

	/**
	 * Gets an ArrayList instance from the begin and end iterators of STL container.
	 *
	 * @since		2.1
	 *
	 * @return		A std::unique_ptr to the ArrayList instance, @n
	 *				else @c std::unique_ptr< ArrayList >() if error occurs
	 * @param[in]	begin		begin() of STL container
	 * @param[in]	end			end() of STL container
	 * @param[in]	deleter		The function pointer to type of the element deleter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks		To create an owning collection, set the element deleter value as @c SingleObjectDeleter.
	 * 				This gives the collection the ownership of elements and the collection can destroy elements. @n
	 *				On the other hand, to create a non-owning collection, you don't need to set the element deleter value,
	 *				as @c NoOpDeleter is the default element deleter.
	 *				That implies transfer of the ownership of elements to the collection is not required.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 * @see			NoOpDeleter()
	 * @see			SingleObjectDeleter()
	 * @see			ArrayDeleter()
	 */
	template < typename FwdIter >
	static std::unique_ptr< ArrayList > GetArrayListN(FwdIter begin, FwdIter end, DeleterFunctionType deleter = NoOpDeleter)
	{
		std::unique_ptr< ArrayList > pArrayList(new (std::nothrow) ArrayList(deleter));
		TryReturnResult(pArrayList, std::unique_ptr< ArrayList >(), E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		result r = pArrayList->Construct();
		TryReturnResult(r == E_SUCCESS, std::unique_ptr< ArrayList >(), r, "[%s] Propagating.", GetErrorMessage(r));

		for (FwdIter iter = begin; iter != end; ++iter)
		{
			r = pArrayList->Add(*iter);
			if (IsFailed(r))
			{
				pArrayList->RemoveAll(false);
				TryReturnResult(false, std::unique_ptr< ArrayList >(), r, "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		return std::move(pArrayList);
	}

	/**
	 * Gets a LinkedList instance from the begin and end iterators of STL container.
	 *
	 * @since		2.1
	 *
	 * @return		A std::unique_ptr to the LinkedList instance @n
	 *				else @c std::unique_ptr< LinkedList >() if error occurs
	 * @param[in]	begin		begin() of STL container
	 * @param[in]	end			end() of STL container
	 * @param[in]	deleter		The function pointer to type of the element deleter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks		To create an owning collection, set the element deleter value as @c SingleObjectDeleter.
	 * 				This gives the collection the ownership of elements and the collection will destroy elements. @n
	 *				On the other hand, to create a non-owning collection, you don't need to set the element deleter value,
	 *				as @c NoOpDeleter is the default element deleter.
	 *				That implies transfer of the ownership of elements to the collection is not required.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 * @see			NoOpDeleter()
	 * @see			SingleObjectDeleter()
	 * @see			ArrayDeleter()
	 */
	template < typename FwdIter >
	static std::unique_ptr< LinkedList > GetLinkedListN(FwdIter begin, FwdIter end, DeleterFunctionType deleter = NoOpDeleter)
	{
		std::unique_ptr< LinkedList > pLinkedList(new (std::nothrow) LinkedList(deleter));
		TryReturnResult(pLinkedList, std::unique_ptr< LinkedList >(), E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		for (FwdIter iter = begin; iter != end; ++iter)
		{
			result r = pLinkedList->Add(*iter);
			if (IsFailed(r))
			{
				pLinkedList->RemoveAll(false);
				TryReturnResult(false, std::unique_ptr< LinkedList >(), r, "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		return std::move(pLinkedList);
	}

	/**
	 * Gets a HashMap instance from the begin and end iterators of STL container.
	 *
	 * @since		2.1
	 *
	 * @return		A std::unique_ptr to the HashMap instance @n
	 *				else @c std::unique_ptr< HashMap >() if error occurs
	 * @param[in]	begin		begin() of STL container
	 * @param[in]	end			end() of STL container
	 * @param[in]	deleter		The function pointer to type of the element deleter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks		To create an owning collection, set the element deleter value as @c SingleObjectDeleter.
	 * 				This gives the collection the ownership of elements and the collection will destroy elements. @n
	 *				On the other hand, to create a non-owning collection, you don't need to set the element deleter value,
	 *				as @c NoOpDeleter is the default element deleter.
	 *				That implies transfer of the ownership of elements to the collection is not required.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 * @see			NoOpDeleter()
	 * @see			SingleObjectDeleter()
	 * @see			ArrayDeleter()
	 */
	template < typename PairedFwdIter >
	static std::unique_ptr< HashMap > GetHashMapN(PairedFwdIter begin, PairedFwdIter end, DeleterFunctionType deleter = NoOpDeleter)
	{
		std::unique_ptr< HashMap > pMap(new (std::nothrow) HashMap(deleter));
		TryReturnResult(pMap, std::unique_ptr< HashMap >(), E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		result r = pMap->Construct();
		TryReturnResult(r == E_SUCCESS, std::unique_ptr< HashMap >(), r, "[%s] Propagating.", GetErrorMessage(r));

		for (PairedFwdIter pairIter = begin; pairIter != end; ++pairIter)
		{
			r = pMap->Add(pairIter->first, pairIter->second);
			if (IsFailed(r))
			{
				pMap->RemoveAll(false);
				TryReturnResult(false, std::unique_ptr< HashMap >(), r, "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		return std::move(pMap);
	}

	/**
	 * Gets a MultiHashMap instance from the begin and end iterators of STL container.
	 *
	 * @since		2.1
	 *
	 * @return		A std::unique_ptr to the MultiHashMap instance @n
	 *				else @c std::unique_ptr< MultiHashMap >() if error occurs
	 * @param[in]	begin		begin() of STL container
	 * @param[in]	end			end() of STL container
	 * @param[in]	deleter		The function pointer to type of the element deleter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks		To create an owning collection, set the element deleter value as @c SingleObjectDeleter.
	 * 				This gives the collection the ownership of elements and the collection will destroy elements. @n
	 *				On the other hand, to create a non-owning collection, you don't need to set the element deleter value,
	 *				as @c NoOpDeleter is the default element deleter.
	 *				That implies transfer of the ownership of elements to the collection is not required.
	 * @remarks		The specific error code can be accessed using GetLastResult() method.
	 * @see			NoOpDeleter()
	 * @see			SingleObjectDeleter()
	 * @see			ArrayDeleter()
	 */
	template < typename PairedFwdIter >
	static std::unique_ptr< MultiHashMap > GetMultiHashMapN(PairedFwdIter begin, PairedFwdIter end, DeleterFunctionType deleter = NoOpDeleter)
	{
		std::unique_ptr< MultiHashMap > pMultiMap(new (std::nothrow) MultiHashMap(deleter));
		TryReturnResult(pMultiMap, std::unique_ptr< MultiHashMap >(), E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		result r = pMultiMap->Construct();
		TryReturnResult(r == E_SUCCESS, std::unique_ptr< MultiHashMap >(), r, "[%s] Propagating.", GetErrorMessage(r));

		for (PairedFwdIter pairIter = begin; pairIter != end; ++pairIter)
		{
			r = pMultiMap->Add(pairIter->first, pairIter->second);
			if (IsFailed(r))
			{
				pMultiMap->RemoveAll(false);
				TryReturnResult(false, std::unique_ptr< MultiHashMap >(), r, "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		return std::move(pMultiMap);
	}

private:
	//
	// This default constructor is intentionally declared as private because this class is not constructible.
	//
	// @since		2.1
	//
	StlConverter(void);

	//
	// This destructor is intentionally declared as private because this class is not constructible.
	//
	// @since		2.1
	//
	virtual ~StlConverter(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		2.1
	//
	// @param[in]	rhs		A reference to the %StlConverter instance
	//
	StlConverter(const StlConverter& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		2.1
	//
	// @return		A reference to the %StlConverter instance
	// @param[in]	rhs		A reference to the %StlConverter instance
	//
	StlConverter& operator=(const StlConverter& rhs);
};

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_STL_CONVERTER_H_
