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
 * @file		FBaseColStack.h
 * @brief		This is the header file for the %Stack class.
 *
 * This header file contains the declarations of the %Stack class.
 *
 */
#ifndef _FBASE_COL_STACK_H_
#define _FBASE_COL_STACK_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseColICollection.h>


namespace Tizen { namespace Base { namespace Collection
{

/**
 * @class	Stack
 * @brief	This class represents a simple last-in-first-out collection of objects, that is, a stack.
 *
 * @since 2.0
 *
 * The %Stack class represents a simple last-in-first-out collection of objects, that is, a stack.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/queue_stack.htm">Stack and Queue</a>.
 *
 * The following example demonstrates how to use the %Stack class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::StackSample(void)
 *	{
 *		Stack stack;
 *		stack.Construct(3);			// capacity = 3
 *
 *		stack.Push(new String(L"First"));
 *		stack.Push(new String(L"Second"));
 *		stack.Push(new String(L"Third"));
 *
 *		// Reads the element at the top
 *		const Object* pObj = stack.Peek();				// pObj: "Third", stack.GetCount(): 3
 *
 *		// Reads and removes the element at the top
 *		String* pStr = static_cast<String*> (stack.Pop());	// pStr: "Third", stack.GetCount(): 2
 *
 *		delete pStr;	// Because the stack does not have the ownership of this pStr after popping
 *
 *		// Deallocates all objects
 *		stack.RemoveAll(true);
 *	}
 * @endcode
 */
class _OSP_EXPORT_ Stack
	: public virtual ICollection
	, public Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	Stack(void);


	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Stack(void);


	/**
	 * Initializes this instance of %Stack with the specified capacity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		 The number of elements @n
	 *                               The default capacity is @c 10.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 * @remarks		If the number of elements added to the stack reaches the current capacity,
	 *				the capacity is automatically increased by memory reallocation. @n
	 *				Therefore, if the size of the stack can be estimated,
	 *				specifying the initial capacity eliminates the need to perform a number of
	 *				resizing operations while adding elements to the stack.
	 * @see			Stack()
	 */
	result Construct(int capacity = DEFAULT_CAPACITY);

	/**
	 * Initializes this instance of %Stack by copying the elements of the specified collection. @n
	 * The capacity of the stack is the same as the number of elements copied.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection  The collection to copy elements from
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			Stack()
	 */
	result Construct(const ICollection& collection);

	/**
	 * Gets an enumerator of this stack.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumerator derived class) of this stack, @n
	 *				else @c null if an exception occurs
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				IEnumerator
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;

	/**
	 * Gets the element at the top of this stack without removing it.
	 *
	 * @since 2.0
	 *
	 * @return		The element at the top of this stack, @n
	 *				else @c null if this stack is empty
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this stack is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual const Object* Peek(void) const;

	/**
	 * Pops the element from the top of this stack.
	 *
	 * @since 2.0
	 *
	 * @return		The element at the top of this stack, @n
	 *				else @c null if this stack is empty
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this stack is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				Push()
	 */
	virtual Object* Pop(void);

	/**
	 * @if OSPDEPREC
	 * Pushes an object to the top of this stack.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it has a problem of const reference argument.
	 *				Instead of using this method, use Push(Object* pObj).
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj  The object to add to this stack
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see				Pop()
	 * @endif
	 */
	result Push(const Object& obj)
	{
		return Push(const_cast< Object* >(&obj));
	}

	/**
	 * Pushes an object to the top of this stack.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pObj		The pointer to object to add to this stack
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @remarks		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see				Pop()
	 */
	virtual result Push(Object* pObj);

	/**
	 * Removes all objects and their pointers in collection, when the @c deallocate parameter is set to @c true. @n
	 * This method can be called before deleting the objects in a collection.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deallocate		Set to @c true to deallocate all objects, @n
	 * 								else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);

	/**
	 * Gets the number of objects currently stored in this stack.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in this stack
	 */
	virtual int GetCount(void) const;

	/**
	 * Checks whether this stack contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if this stack contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj  The object to locate
	 */
	virtual bool Contains(const Object& obj) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether this stack contains all of the elements in the specified collection.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because it transfers a result of comparison in out-parameter form.
	 *				The return type will be changed into boolean type and this method will return the result.
	 *				Instead of using this method, use bool Contains(const ICollection& collection).
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to locate
	 * @param[out]	out  Set to @c true if this stack contains all the elements in the specified collection, @n
	 *					 else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @endif
	 */
	result ContainsAll(const ICollection& collection, bool& out) const
	{
		out = ContainsAll(collection);
		result r = GetLastResult();
		return r;
	}

	/**
	 * Checks whether this stack contains all of the elements in the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if this stack contains all the elements in the specified collection, @n
	 *					else @c false
	 * @param[in]	collection	The collection to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool ContainsAll(const ICollection& collection) const;

	/**
	 * Checks whether the specified instance equals the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true only if the specified object is also an instance of %Stack class,
	 *				both stacks have the same size, and all corresponding pairs of elements in the two stacks are equal.
	 *				In other words, two stacks are equal if they contain the same elements in the same order.
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

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	stack The other instance of Stack
	 */
	Stack(const Stack& stack);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since 2.0
	 *
	 * @param[in]	stack An instance of %Stack
	 */
	Stack& operator =(const Stack& stack);

	int __capacity;
	int __index;
	Object** __pObjArray;
	int __modCount;
	static const int DEFAULT_CAPACITY = 10;

	friend class _StackEnumerator;
	class _StackImpl* __pStackImpl;
	friend class _StackImpl;

}; // Stack

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_STACK_H_
