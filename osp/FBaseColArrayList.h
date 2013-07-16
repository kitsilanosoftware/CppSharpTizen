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
 * @file		FBaseColArrayList.h
 * @brief		This is the header file for the %ArrayList class.
 *
 * This header file contains the declarations of the %ArrayList class.
 */
#ifndef _FBASE_COL_ARRAY_LIST_H_
#define _FBASE_COL_ARRAY_LIST_H_

#include <FBaseObject.h>
#include <FBaseColIComparer.h>
#include <FBaseColIList.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @class ArrayList
 * @brief This class represents a collection of objects that can be individually accessed by an index.
 *
 * @since 2.0
 *
 *
 * The %ArrayList class represents a collection of objects that can be individually accessed by an index.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/arraylist_linkedlist.htm">ArrayList and LinkedList</a>.
 *
 * The following example demonstrates how to use the %ArrayList class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *
 *	void
 *	MyClass::ArrayListSample(void)
 *	{
 *		ArrayList	list(SingleObjectDeleter);
 *
 *		list.Construct();
 *
 *		list.Add(new Integer(1));	// 1
 *		list.Add(new Integer(2));	// 1,2
 *		list.Add(new Integer(3));	// 1,2,3
 *
 *		Integer*	pInt = static_cast< Integer* > (list.GetAt(0));
 *
 *		if (pInt->Equals(Integer(1)))
 *		{
 *			// Must be here
 *		}
 *
 *		list.InsertAt(new Integer(4), 1);	// 1,4,2,3
 *
 *		list.Remove(Integer(3));		// 1,4,2
 *
 *		list.RemoveAt(0);				// 4,2
 *
 *		list.Sort(IntegerComparer());	// 2,4
 *
 *		// Uses an enumerator to access elements in the list
 *		IEnumerator*	pEnum = list.GetEnumeratorN();
 *		Object*		pObj = null;
 *		while (pEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pObj = pEnum->GetCurrent();
 *		}
 *
 *		delete pEnum;
 *
 *
 *		// Deallocates all objects
 *		// Because the destructor calls RemoveAll() internally, you do not need to call RemoveAll() to destroy all elements at the end.
 *		// list.RemoveAll();
 *	}
 * @endcode
 */
class _OSP_EXPORT_ ArrayList
	: public IList
	, public Object
{
public:
	using IList::Add;
	using IList::InsertAt;
	using IList::Remove;
	using IList::RemoveAt;
	using IList::RemoveItems;
	using IList::RemoveAll;
	using IList::SetAt;
	using IList::ContainsAll;
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	The function pointer to type of the element deleter
	 * @remarks		To create an owing collection, set the element deleter value as @c SingleObjectDeleter. This gives the collection the ownership of elements and the collection will destroy elements. @n
	 *				On the other hand, to create a non-owning collection, you do not need to set the element deleter value, as @c NoOpDeleter is the default element deleter.
	 *				It means that you do not transfer the ownership of elements to the collection.
	 * @remarks		After creating an instance of the %ArrayList class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see			NoOpDeleter()
	 * @see			SingleObjectDeleter()
	 * @see			ArrayDeleter()
	 */
	explicit ArrayList(DeleterFunctionType deleter = NoOpDeleter);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ArrayList(void);

	/**
	 * Initializes this instance of %ArrayList with the specified parameter and sets its initial capacity to the
	 * indicated value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity	The number of elements @n
	 *  						The default capacity is @c 10.
	 * @exception	E_SUCCESS		  The method is successful.
	 * @exception	E_INVALID_ARG	  A specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 * @remarks		If the number of elements added to the list reaches the current capacity,
	 *				the capacity is automatically increased by memory reallocation.
	 *				Therefore, if the size of the list can be estimated,
	 *				specifying the initial capacity eliminates the need to perform a number of
	 *				resizing operations while adding elements to the list.
	 * @see			ArrayList()
	 */
	result Construct(int capacity = DEFAULT_CAPACITY);


	/**
	 * Initializes this instance of %ArrayList by copying the elements of the specified
	 * @c collection. @n
	 * The capacity of the list is the same as the number of elements copied.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			ArrayList()
	 */
	result Construct(const ICollection& collection);

	/**
	 * Adds the specified object to the end of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		An pointer to object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			Remove()
	 */
	virtual result Add(Object* pObj);


	/**
	 * Adds the elements of the specified @c collection to the end of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollection& collection);


	/**
	 * Gets an enumerator (an instance of the IEnumerator-derived class) of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of the IEnumerator-derived class, @n
	 * 				else @c null if some exception occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;

	/**
	 * Gets a bidirectional enumerator (an instance of the IBidirectionalEnumerator derived class) of this list.
	 *
	 * @since 2.0
	 *
	 * @return        An instance of the IBidirectionalEnumerator derived class, @n
	 *                              else @c null if some exception occurs
	 * @remarks      Use this method to obtain a bidirectional enumerator (an instance of the IBidirectionalEnumerator derived class)
	 *                              to iterate over a collection (an instance of the IList derived class).
	 *                   The specific error code can be accessed using GetLastResult() method.
	 * @see           Tizen::Base::Collection::IBidirectionalEnumerator
	 */
	virtual IBidirectionalEnumerator* GetBidirectionalEnumeratorN(void) const;

	/**
	 * Gets the object at the specified @c index of this list.
	 *
	 * @since 2.0
	 *
	 * @return		The object at the specified @c index of this list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index	The index of the object in the calling list to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual const Object* GetAt(int index) const;


	/**
	 * Gets the object at the specified @c index of this list.
	 *
	 * @since 2.0
	 *
	 * @return		The object at the specified @c index of this list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index	The index of the object to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual Object* GetAt(int index);

	/**
	 * Gets the IList within the specified range of this list.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to IList, @n
	 *				else @c null if some exception occurs
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *											or less than @c 0.
	 * @remarks		The IList stores just the pointers to the elements in the list, not the elements themselves.
	 *              The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IList* GetItemsN(int startIndex, int count) const;

	/**
	 * Searches for an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int& index) const;

	/**
	 * Searches for an object starting from the specified index. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[in]	startIndex	The starting index for the search @n
	 *							It must be less than the number of elements.
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *											the specified @c startIndex is either equal to or greater than the number of elements or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int startIndex, int& index) const;

	/**
	 * Searches for an object within the specified range. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *											or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int startIndex, int count, int& index) const;

	/**
	 * Searches for the last occurrence of an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj         The object to locate
	 * @param[out]	index		The index of the last occurrence of the specified object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf(const Object& obj, int& index) const;

	/**
	 * Inserts the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj        The pointer to object to insert
	 * @param[in]	index	The index at which the object must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c index is greater than the number of elements or less than @c 0.
	 * @remarks		The elements that follow the insertion point move down to accommodate the new element.
	 *				If the @c index equals to the number of elements, then the new element
	 *				is added at the end of this list.
	 *				This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result InsertAt(Object* pObj, int index);

	/**
	 * Inserts the elements of the collection at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to insert
	 * @param[in]	startIndex	The starting index at which the collection must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c startIndex is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the @c collection is modified during the operation of this method.
	 * @remarks		The elements that follow the insertion point move down to accommodate the new element.
	 *				If the @c startIndex equals to the number of elements then the new elements
	 *				are added at the end of this list.
	 *				This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			RemoveItems()
	 * @see			AddItems()
	 */
	virtual result InsertItemsFrom(const ICollection& collection, int startIndex);

	/**
	 * Removes the first occurrence of the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj     An object to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			Add()
	 * @see			RemoveAt()
	 * @see			RemoveAll()
	 */
	virtual result Remove(const Object& obj);

	/**
	 * Removes the object at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index	The index at which the object must be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The elements that follow the deletion point move up to occupy the vacated spot.
	 * @see			InsertAt()
	 * @see			Remove()
	 */
	virtual result RemoveAt(int index);

	/**
	 * Removes all the elements within the specified range.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @remarks		The elements that follow the deletion point move up to occupy the vacated spot.
	 * @see			AddItems()
	 */
	virtual result RemoveItems(int startIndex, int count);

	/**
	 * Removes all of the elements that are in the intersection of the specified @c collection
	 * and this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to remove from this list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @see			Remove()
	 * @see			RemoveAt()
	 */
	virtual result RemoveItems(const ICollection& collection);

	/**
	 * Removes all of the object pointers in the collection and also removes all of the objects depending on the specified element deleter.
	 * The %RemoveAll() can be called before the collection is deleted.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void);

	/**
	 * Replaces the object at the specified @c index with the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		An pointer to object to set
	 * @param[in]	index	The index at which the object must be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(Object* pObj, int index);

	/**
	 * Sets the capacity of this list to the specified value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	newCapacity	The new capacity of this list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG 	The specified input parameter is invalid, or
	 *								  the @c newCapacity is negative.
	 * @remarks		When the new capacity is less than the current capacity, the elements
	 *				within the truncated memory are not destroyed.
	 * @see			Construct()
	 * @see			Trim()
	 * @see			GetCapacity()
	 */
	virtual result SetCapacity(int newCapacity);

	/**
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	comparer	The IComparer implementation to use when comparing elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	virtual result Sort(const IComparer& comparer);

	/**
	 * Sets the capacity to the actual number of elements in this list.
	 *
	 * @since 2.0
	 */
	virtual void Trim(void);

	/**
	 * Gets the current capacity of this list.
	 *
	 * @since 2.0
	 *
	 * @return	The current capacity of this list
	 * @see			SetCapacity()
	 */
	virtual int GetCapacity(void) const;

	/**
	 * Gets the number of objects currently stored in this list.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in this list
	 */
	virtual int GetCount(void) const;

	/**
	 * Checks whether a list contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the object is present in the list, @n
	 *				else @c false
	 * @param[in]	obj The object to locate
	 * @see			ContainsAll()
	 */
	virtual bool Contains(const Object& obj) const;

	/**
	 * Checks whether the list contains all the elements of the specified @c collection.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the list contains all the elements of the specified @c collection, @n
	 *					else @c false
	 * @param[in]	collection	The collection to check for in the list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If the given @c collection is empty, this method will return @c true.
 	 * @see			Contains()
	 */
	virtual bool ContainsAll(const ICollection& collection) const;

	/**
	 * Compares the specified Object instance with the calling %ArrayList instance.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the given object matches the calling List, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the calling list
	 * @remarks		This method returns @c true only if the specified object @c obj is also an instance of %ArrayList class,
	 *				both lists have the same size, and all the corresponding pairs of the elements in the two lists are equal.
	 *				In other words, the two lists are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return 	The hash value of the current instance
	 * @remarks	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 * 			the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Distinguish between %ArrayList and LinkedList.
	 *
	 * @since 2.0
	 * @return	@c true if it is an %ArrayList, @n
	 *			else @c false if it is a LinkedList
	 */
	virtual bool IsRandomAccessible(void) const
	{
		return true;
	}

	/**
	 * Gets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @return	A function pointer to the existing element deleter
	 */
	virtual DeleterFunctionType GetDeleter(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list	The instance of the %ArrayList class to copy from
	 */
	ArrayList(const ArrayList& list);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list	An instance of %ArrayList
	 */
	ArrayList& operator =(const ArrayList& list);

	/**
	 * Sorts the specified sub-list.
	 *
	 * @return		An error code
	 * @param[in]	startIndex The starting point of the sub-list to sort
	 * @param[in]	endIndex The end point of the sub-list to sort
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the elements.
	 */
	result QuickSort(int startIndex, int endIndex);

	/**
	 * Sets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	A function pointer to the element deleter to set
	 */
	virtual void SetDeleter(DeleterFunctionType deleter);

	int __capacity;
	int __count;
	Object** __pObjArray;
	int __modCount;
	IComparer* __pComparer;
	static const int DEFAULT_CAPACITY = 10;
	DeleterFunctionType __deleter;

	friend class _ArrayListEnumerator;
	friend class _ArrayListImpl;
	class _ArrayListImpl* __pArrayListImpl;

}; // ArrayList

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_ARRAY_LIST_H_
