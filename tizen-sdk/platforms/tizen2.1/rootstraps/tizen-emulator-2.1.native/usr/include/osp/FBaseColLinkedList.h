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
 * @file		FBaseColLinkedList.h
 * @brief		This is the header file for the %LinkedList class.
 *
 * This header file contains the declarations of the %LinkedList class.
 */
#ifndef _FBASE_COL_LINKED_LIST_H_
#define _FBASE_COL_LINKED_LIST_H_

#include <FBaseColIComparer.h>
#include <FBaseColIList.h>


namespace Tizen { namespace Base { namespace Collection
{

class _ListNode;

/**
 * @class LinkedList
 * @brief This class represents a collection of objects that can be individually accessed by index.
 *
 * @since 2.0
 *
 * The %LinkedList class represents a collection of objects that can be individually accessed by index.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/arraylist_linkedlist.htm">ArrayList and LinkedList</a>.
 *
 * The following example demonstrates how to use the %LinkedList class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::LinkedListSample(void)
 *	{
 *		LinkedList list(SingleObjectDeleter);
 *
 *		list.Add(new Integer(1));	// 1
 *		list.Add(new Integer(2));	// 1,2
 *		list.Add(new Integer(3));	// 1,2,3
 *
 *		Integer*	pInt = static_cast< Integer* > (list.GetAt(0));
 *
 *		if (pValue->Equals(Integer(1))
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
 *		Object* pObj = null;
 *		while (pEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pObj = pEnum->GetCurrent();
 *		}
 *
 *		delete pEnum;
 *
 *		// Deallocates all objects
 *		// Because the destructor calls RemoveAll() internally, you do not need to call RemoveAll() to destroy all elements at the end.
 *		// list.RemoveAll();
 *	}
 * @endcode
 */
class _OSP_EXPORT_ LinkedList
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
	 * @remarks	To create an owing collection, set the element deleter value as @c SingleObjectDeleter. This gives the collection the ownership of elements and the collection will destroy elements. @n
	 *			On the other hand, to create a non-owning collection, you do not need to set the element deleter value, as @c NoOpDeleter is the default element deleter.
	 *			It means that you do not transfer the ownership of elements to the collection.
	 * @see		NoOpDeleter()
	 * @see		SingleObjectDeleter()
	 * @see		ArrayDeleter()
	 */
	explicit LinkedList(DeleterFunctionType deleter = NoOpDeleter);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~LinkedList(void);

	/**
	 * Adds the given object to the end of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		An pointer to object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see Remove()
	 */
	virtual result Add(Object* pObj);

	/**
	 * Adds the elements of the given collection to the end of this list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollection& collection);

	/**
	 * Gets an enumerator (an instance of the IEnumerator derived class) to the list.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator of the calling list object, @n
	 *				else @c null if an exception occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumerator
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
	 * Gets the object at the specified index of the calling list.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the object at the specified index of the list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index The index of the object to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual const Object* GetAt(int index) const;

	/**
	 * Gets the object at the specified index of the calling list.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the object at the specified index of the list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index The index of the object to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual Object* GetAt(int index);

	/**
	 * Gets an IList with the specified range from the calling list object.
	 *
	 * @since 2.0
	 *
	 * @return		An IList pointer if successful, @n
	 *				else @c null if an exception occurs
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @remarks		The IList stores just the pointers to the elements in the list, not the elements themselves.
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IList* GetItemsN(int startIndex, int count) const;

	/**
	 * Searches for an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj			The object to locate
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 */
	virtual result IndexOf(const Object& obj, int& index) const;

	/**
	 * Searches for an object starting from the specified index. @n
	 * Gets the index of the object if found.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[in]	startIndex	The starting index for the search @n
	 *							It must be less than the number of elements.
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
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
	 * @param[in]	obj 		The object to locate
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
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
	 * @param[in]	obj 		The object to locate
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
	 * @param[in]	pObj		The pointer to object to insert
	 * @param[in]	index	The index at which the object must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is greater than the number of elements or less than @c 0.
	 * @remarks		If the @c index equals to the number of elements, then the new element
	 *				is added at the end of this list.
	 *			This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see		Add()
	 * @see		RemoveAt()
	 */
	virtual result InsertAt(Object* pObj, int index);

	/**
	 * Inserts the elements of the collection at the specified location.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to insert elements from
	 * @param[in]	startIndex	The starting index at which the elements must be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the @c collection is modified during the operation of this method.
	 * @remarks		If the @c startIndex equals to the number of elements then the new elements
	 *				are added at the end of this list.
	 *      		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			RemoveItems()
	 * @see			AddItems()
	 */
	virtual result InsertItemsFrom(const ICollection& collection, int startIndex);

	/**
	 * Removes the first occurrence of the specified object from the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj	An object to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			Add()
	 * @see			RemoveAt()
	 */
	virtual result Remove(const Object& obj);

	/**
	 * Removes the object at the specified location in the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	index The index at which the object must be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									The specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see		InsertAt()
	 */
	virtual result RemoveAt(int index);

	/**
	 * Removes all elements within the specified range from the list.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of element to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The specified index is outside the bounds of the data structure. @n
	 *									- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *									- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @see			AddItems()
	 * @see			InsertItemsFrom()
	 */
	virtual result RemoveItems(int startIndex, int count);

	/**
	 * Removes all the elements that are common in the specified @c collection
	 * and the list.
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
	 * This method can be called before deleting the objects in a collection.
	 *
	 * @since 2.0
	 *
	 */
	virtual void RemoveAll(void);

	/**
	 * Replaces the object at the specified index with the given object.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to set
	 * @param[in]	index	The index at which the object must be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(Object* pObj, int index);

	/**
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	comparer The IComparer implementation to use when comparing elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the @c comparer is not valid.
	 */
	virtual result Sort(const IComparer& comparer);

	/**
	 * Gets the number of objects currently stored in this list.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in this list
	 */
	virtual int GetCount(void) const;

	/**
	 * Checks whether the list contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the list contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj 	The object to locate
	 * @see			ContainsAll()
	 */
	virtual bool Contains(const Object& obj) const;

	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if this list contains all of the elements in the specified collection, @n
	 *					else @c false
	 * @param[in]	collection	The collection to check for containment in this list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If the given @c collection is empty, this method will return @c true.
	 * @see			Contains()
	 */
	virtual bool ContainsAll(const ICollection& collection) const;

	/**
	 * Compares the given object with the calling %LinkedList object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the calling object
	 * @remarks		This method returns @c true only if the specified object is also an instance of the %LinkedList class,
	 *				both lists have the same size, and all corresponding pairs of elements in the two lists are equal.
	 *				In other words, two lists are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 * 			the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

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
	 * @param[in]	list The %LinkedList object to initialize the new object
	 */
	LinkedList(const LinkedList& list);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	list An instance of %LinkedList
	 */
	LinkedList& operator =(const LinkedList& list);

	/**
	 * Allocates and adds a memory block.
	 *
	 * @return		An error code
	 * @param[in]	blockSize	The size of block to allocate
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result AddBlock(int blockSize = DEFAULT_CAPACITY);

	/**
	 * Frees memory blocks of the list.
	 *
	 */
	void DeleteBlock(void);

	/**
	 * Inserts an object to the beginning of the %LinkedList.
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertFirst(Object* pObj);

	/**
	 * Inserts an object to the end of the %LinkedList.
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to insert
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertLast(Object* pObj);

	/**
	 * Inserts an object after the specified node.
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to insert
	 * @param[in]	pPrevNode The node after which the object must inserted
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertNext(Object* pObj, _ListNode* pPrevNode);

	/**
	 * Gets a node from Available node list.
	 *
	 * @return		A pointer to a new List Node if successful, @n
	 *				else @c null if no node is available
	 */
	_ListNode* GetNewNode(void);

	/**
	 * Gets the node at the specified index.
	 *
	 * @return		A node at the specified index
	 * @param[in]	index The index of the node to read
	 */
	_ListNode* GetNode(int index) const;

	/**
	 * Removes the specified node.
	 *
	 * @param[in]	pNode The pointer of the node to remove
	 */
	void RemoveNode(_ListNode* pNode);

	/**
	 * Sets the element deleter of the collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deleter	A function pointer to the element deleter to set
	 */
	virtual void SetDeleter(DeleterFunctionType deleter);

	_ListNode* __pListHead;
	_ListNode* __pListTail;
	_ListNode* __pAvailableHead;
	_ListNode* __pAvailableTail;
	_ListNode* __pBlocks;
	int __count;
	int __capacity;
	int __modCount;
	static const int DEFAULT_CAPACITY = 10;
	DeleterFunctionType __deleter;

	friend class _LinkedListEnumerator;
	friend class _LinkedListImpl;
	class _LinkedListImpl* __pLinkedListImpl;

}; // LinkedList

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_LINKED_LIST_H_
