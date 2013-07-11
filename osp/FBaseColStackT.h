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
 * @file		FBaseColStackT.h
 * @brief		This is the header file for the %StackT class.
 *
 * This header file contains the declarations of the %StackT class.
 *
 */
#ifndef _FBASE_COL_STACK_T_H_
#define _FBASE_COL_STACK_T_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseColICollectionT.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class Type > class __StackEnumeratorT;

/**
 * @class	StackT
 * @brief	This class represents a template-based stack (a last-in-first-out collection of objects).
 *
 * @since 2.0
 *
 * The %StackT class represents a template-based stack (a last-in-first-out collection of objects).
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/queue_stack.htm">Stack and Queue</a>.
 *
 * The following example demonstrates how to use the %StackT class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::StackTSample(void)
 *	{
 *		StackT<String> stack;
 *		stack.Construct();
 *
 *		String str1(L"First");
 *		String str2(L"Second");
 *		String str3(L"Third");
 *
 *		stack.Push(str1);
 *		stack.Push(str2);
 *		stack.Push(str3);
 *
 *		// Reads the element at the top
 *		String temp;
 *		stack.Peek(temp);		// temp: "Third", stack.GetCount(): 3
 *
 *		// Reads and removes the element at the top
 *		stack.Pop(temp);		// temp: "Third", stack.GetCount(): 2
 *	}
 * @endcode
 */
template< class Type >
class StackT
	: public virtual ICollectionT< Type >
	, public Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	StackT(void)
		: __capacity(0)
		, __index(-1)
		, __pObjArray(null)
		, __modCount(0)
	{
	}

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~StackT(void)
	{
		__modCount++;
		RemoveAll();
	}

	/**
	 * Initializes this instance of %StackT with the specified capacity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity		The number of elements @n
	 *                              The default capacity is @c 10.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 */
	result Construct(int capacity = DEFAULT_CAPACITY)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[%s] The capacity(%d) MUST be greater than or equal to 0.", GetErrorMessage(E_INVALID_ARG), capacity);

		if (capacity > 0)
		{
			__pObjArray = new Type[capacity];
			TryReturn(__pObjArray != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
		}
		__capacity = capacity;

		return E_SUCCESS;
	}

	/**
	 * Initializes this instance of %StackT that contains the elements of the specified collection. @n
	 * The capacity of the stack is the same as the number of elements copied.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to copy elements from
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @see			StackT()
	 */
	result Construct(const ICollectionT< Type >& collection)
	{
		result r = E_SUCCESS;

		IEnumeratorT< Type >* pEnum = null;
		if (collection.GetCount() > 0)
		{
			ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
			pEnum = pCol->GetEnumeratorN();
			TryCatch(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

			while (true)
			{
				Type temp;

				r = pEnum->MoveNext();
				// enumerator is reached to the end of collection
				if (E_OUT_OF_RANGE == r)
				{
					r = E_SUCCESS;
					break;
				}
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				r = pEnum->GetCurrent(temp);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				r = Push(temp);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));
			}
		}

		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;

CATCH:
		RemoveAll();

		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;
	}

	/**
	 * Gets an enumerator of this stack.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumeratorT derived class) of this stack, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				Tizen::Base::Collection::IEnumeratorT
	 */
	virtual IEnumeratorT< Type >* GetEnumeratorN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		__StackEnumeratorT< Type >* pEnum = new __StackEnumeratorT< Type >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Reads the element at the beginning of this stack without removing it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The element at the beginning of this stack
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this stack is empty.
	 */
	virtual result Peek(Type& obj) const
	{
		if (__index < 0)
		{
			return E_UNDERFLOW;
		}

		obj = __pObjArray[__index];

		return E_SUCCESS;
	}

	/**
	 * Pops the element from the beginning of this stack.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The element at the beginning of this stack
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this stack is empty.
	 * @see			Push()
	 */
	virtual result Pop(Type& obj)
	{
		if (__index < 0)
		{
			return E_UNDERFLOW;
		}

		__modCount++;

		obj = __pObjArray[__index];

		__index--;

		return E_SUCCESS;
	}

	/**
	 * Pushes an object at the top of this stack.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj The object to add to this stack
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see				Pop()
	 */
	virtual result Push(const Type& obj)
	{
		// Ensure capacity
		if (null == __pObjArray)
		{
			__pObjArray = new Type[DEFAULT_CAPACITY];
			TryReturn(__pObjArray != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

			__capacity = DEFAULT_CAPACITY;
		}
		else if ((__index + 1) >= __capacity)
		{
			Type* pArrayTemp = new Type[__capacity + DEFAULT_CAPACITY];
			TryReturn(pArrayTemp != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

			for (int i = 0; i <= __index; i++)
			{
				pArrayTemp[i] = __pObjArray[i];
			}

			delete[] __pObjArray;

			__pObjArray = pArrayTemp;
			__capacity += DEFAULT_CAPACITY;
		}

		__modCount++;

		// Add element
		__pObjArray[++__index] = obj;

		return E_SUCCESS;
	}

	/**
	 * Removes all elements in this stack.
	 *
	 * @since 2.0
	 */
	virtual void RemoveAll(void)
	{
		if (__pObjArray != null)
		{
			delete[] __pObjArray;
		}

		__pObjArray = null;

		__modCount++;
		__capacity = 0;
		__index = -1;
	}

	/**
	 * Gets the number of objects currently stored in this stack.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in this stack
	 */
	virtual int GetCount(void) const
	{
		return __index + 1;
	}

	/**
	 * Checks whether this stack contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if this stack contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj  The object to locate
	 */
	virtual bool Contains(const Type& obj) const
	{
		bool out = false;

		if (__index > -1)
		{
			for (int i = 0; i <= __index; i++)
			{
				if (__pObjArray[i] == obj)
				{
					out = true;
					break;
				}
			}
		}

		return out;
	}

	/**
	 * Checks whether this stack contains all of the elements in the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to locate
	 * @param[out]	out   Set to @c true if this stack contains all of the elements in the specified collection, @n
	 *					 else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 */
	virtual result ContainsAll(const ICollectionT< Type >& collection, bool& out) const
	{
		result r = E_SUCCESS;

		ICollectionT< Type >* pCol = const_cast< ICollectionT< Type >* >(&collection);
		IEnumeratorT< Type >* pEnum = pCol->GetEnumeratorN();
		TryCatch(pEnum != null, r = GetLastResult(), "[%s] Propagating.", GetErrorMessage(GetLastResult()));

		while (true)
		{
			Type temp;

			r = pEnum->MoveNext();
			// enumerator has reached the end of collection
			if (E_OUT_OF_RANGE == r)
			{
				r = E_SUCCESS;
				out = true;
				break;
			}
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			r = pEnum->GetCurrent(temp);
			TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

			if (false == Contains(temp))
			{
				out = false;
				break;
			}
		}

		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;

CATCH:
		if (null != pEnum)
		{
			delete pEnum;
		}
		return r;
	}

	/**
	 * Checks whether the specified instance equals the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true only if the specified object is also an instance of the Stack class,
	 *				both stacks have the same size, and all the corresponding pairs of elements in the two stacks are equal.
	 *				In other words, two stacks are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const
	{
		bool out = true;

		const StackT< Type >* other = dynamic_cast< const StackT< Type >* >(&obj);
		if (null == other) // obj is not a StackT<Type> instance
		{
			out = false;
		}
		else if (other == this)
		{
			out = true;
		}
		else if (__index != other->__index)
		{
			out = false;
		}
		else
		{
			for (int i = 0; i <= __index; i++)
			{
				if (!(__pObjArray[i] == other->__pObjArray[i]))
				{
					out = false;
					break;
				}
			}
		}

		return out;
	}


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return 	The hash value of the current instance
	 * @remarks	The two Tizen::Base::Object::Equals() instances must return the same hash value. For better performance, @n
	 * 			the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const
	{
		int hash = 0;
		for (int i = 0; i <= __index; i++)
		{
			if (&__pObjArray[i] != null)
			{
				hash += reinterpret_cast< int >(&__pObjArray[i]);
			}
		}

		return hash;
	}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	stack The other instance of StackT
	 */
	StackT(const StackT< Type >& stack);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	stack An instance of %StackT
	 */
	StackT< Type >& operator =(const StackT< Type >& stack);

	int __capacity;
	int __index;
	Type* __pObjArray;
	int __modCount;
	static const int DEFAULT_CAPACITY = 10;

	friend class __StackEnumeratorT< Type >;

}; // StackT

//
// @class	__StackEnumeratorT
// @brief	This class is an implementation of IEnumeratorT for %StackT.
// @since 2.0
//
template< class Type >
class __StackEnumeratorT
	: public IEnumeratorT< Type >
	, public Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	stack		A stack to enumerate
	 * @param[in]	modCount	The modification count to detect the change in the stack
	 */
	__StackEnumeratorT(const StackT< Type >& stack, int modCount)
		: __stack(stack)
		, __modCount(modCount)
		, __position(-1)
	{
	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__StackEnumeratorT(void)
	{
	}

	/**
	 * Gets the current object in the stack.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The current object
	 * @exception	E_INVALID_OPERATION	   Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									 - This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	 *									- The stack is modified after this enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetCurrent(Type& obj) const
	{
		TryReturn(__modCount == __stack.__modCount, E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn(((__position >= 0) && (__position <= __stack.__index)), E_INVALID_OPERATION,
			"[%s] Current position is before the first element or past the last element.", GetErrorMessage(E_INVALID_OPERATION));

		obj = __stack.__pObjArray[__position];

		return E_SUCCESS;
	}

	/**
	 * Moves this enumerator to the next element of the stack. @n
	 * When this enumerator is first created or after a call to Reset(),
	 * the first call to MoveNext() positions this enumerator to the first element in the stack.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the stack is modified after this enumerator is created.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the stack.
	 * @see				Reset()
	 */
	result MoveNext(void)
	{
		TryReturn((__modCount == __stack.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		result r = E_SUCCESS;
		if (__position >= __stack.__index)
		{
			// Do not log the E_OUT_OF_RANGE, because it is normal or trivial in most cases.
			r = E_OUT_OF_RANGE;
		}
		else
		{
			__position++;
		}

		return r;
	}

	/**
	 * Positions this enumerator before the first element in the stack.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the stack is modified after this enumerator is created.
	 */
	result Reset(void)
	{
		TryReturn((__modCount == __stack.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__position = -1;

		return E_SUCCESS;
	}

private:
	const StackT< Type >& __stack;
	int __modCount;
	int __position;

}; // __StackEnumeratorT

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_STACK_T_H_
