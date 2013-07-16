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
 * @file		FBaseColQueueT.h
 * @brief		This is the header file for the %QueueT class.
 *
 * This header file contains the declarations of the %QueueT class.
 *
 */
#ifndef _FBASE_COL_QUEUE_T_H_
#define _FBASE_COL_QUEUE_T_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseColICollectionT.h>


namespace Tizen { namespace Base { namespace Collection
{

template< class Type > class __QueueEnumeratorT;

/**
 * @class	QueueT
 * @brief	This represents a template-based queue (a first-in-first-out collection of objects).
 *
 * @since 2.0
 *
 * The %QueueT class represents a template-based queue (a first-in-first-out collection of objects).
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/queue_stack.htm">Stack and Queue</a>.
 *
 * The following example demonstrates how to use the %QueueT class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::QueueTSample(void)
 *	{
 *		QueueT< String > queue;
 *		queue.Construct();
 *
 *		String str1(L"First");
 *		String str2(L"Second");
 *		String str3(L"Third");
 *
 *		queue.Enqueue(str1);
 *		queue.Enqueue(str2);
 *		queue.Enqueue(str3);
 *
 *		// Reads the element at the beginning
 *		String temp;
 *		queue.Peek(temp);		// temp: "First", queue.GetCount(): 3
 *
 *		// Reads and removes the element at the beginning
 *		queue.Dequeue(temp);	// temp: "First", queue.GetCount(): 2
 *	}
 * @endcode
 */
template< class Type >
class QueueT
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
	QueueT(void)
		: __capacity(0)
		, __head(0)
		, __tail(0)
		, __pObjArray(null)
		, __modCount(0)
	{
	}

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~QueueT(void)
	{
		__modCount++;
		RemoveAll();
	}

	/**
	 * Initializes this instance of %QueueT with the specified capacity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	capacity			The number of elements in the queue @n
	 *                                  The default capacity is @c 10.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
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
	 * Initializes this instance of %QueueT that contains the elements of the specified @c collection. @n
	 * The capacity of the queue is the same as the number of elements copied.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection The collection to copy the elements from
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @see			QueueT()
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

				if (E_OUT_OF_RANGE == r)
				{
					r = E_SUCCESS;
					break;
				}
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				r = pEnum->GetCurrent(temp);
				TryCatch(r == E_SUCCESS, , "[%s] Propagating.", GetErrorMessage(r));

				r = Enqueue(temp);
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
	 * Reads and removes the element at the beginning of this queue.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The element at the beginning of this queue
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this queue is empty.
	 * @see			Enqueue()
	 */
	virtual result Dequeue(Type& obj)
	{
		if (__head <= __tail)
			return E_UNDERFLOW;

		__modCount++;
		int index = (__tail) % __capacity;
		obj = __pObjArray[index];

		__tail++;

		return E_SUCCESS;
	}

	/**
	 * Inserts an object at the end of this queue.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	obj The object to add to this queue
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see			Dequeue()
	 */
	virtual result Enqueue(const Type& obj)
	{
		if (null == __pObjArray)
		{
			__pObjArray = new Type[DEFAULT_CAPACITY];
			TryReturn(__pObjArray != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
			__capacity = DEFAULT_CAPACITY;
		}
		else if ((__head - __tail) >= __capacity)
		{
			Type* pArrayTemp = new Type[__capacity + DEFAULT_CAPACITY];
			TryReturn(pArrayTemp != null, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

			for (int i = 0, j = __tail; i < __capacity; i++, j++)
			{
				pArrayTemp[i] = __pObjArray[j % __capacity];
			}

			delete[] __pObjArray;
			__pObjArray = pArrayTemp;
			__tail = 0;
			__head = __capacity;
			__capacity += DEFAULT_CAPACITY;
		}

		__modCount++;
		__pObjArray[__head % __capacity] = obj;
		__head++;

		return E_SUCCESS;
	}

	/**
	 * Removes all the elements in this queue.
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
		__head = 0;
		__tail = 0;
	}

	/**
	 * Gets an enumerator of this queue.
	 *
	 * @since 2.0
	 *
	 * @return		An enumerator (an instance of the IEnumeratorT derived class) of this queue, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Base::Collection::IEnumeratorT
	 */
	virtual IEnumeratorT< Type >* GetEnumeratorN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		__QueueEnumeratorT< Type >* pEnum = new __QueueEnumeratorT< Type >(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));

		return pEnum;

CATCH:
		SetLastResult(r);
		return null;
	}

	/**
	 * Reads the element at the beginning of this queue without removing it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The element at the beginning of this queue
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this queue is empty.
	 */
	virtual result Peek(Type& obj) const
	{
		if (__head <= __tail)
		{
			return E_UNDERFLOW;
		}

		obj = __pObjArray[__tail % __capacity];

		return E_SUCCESS;
	}

	/**
	 * Gets the number of objects currently stored in this queue.
	 *
	 * @since 2.0
	 *
	 * @return		The number of objects currently stored in this queue
	 */
	virtual int GetCount(void) const
	{
		return __head - __tail;
	}

	/**
	 * Checks whether this queue contains the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if this queue contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj  The object to locate
	 */
	virtual bool Contains(const Type& obj) const
	{
		bool out = false;
		for (int i = 0; i < GetCount(); i++)
		{
			if (__pObjArray[(__tail + i) % __capacity] == obj)
			{
				out = true;
				break;
			}
		}

		return out;
	}

	/**
	 * Checks whether this queue contains all of the elements in the specified collection.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	collection	The collection to locate
	 * @param[out]	out  Set to @c true if this queue contains all of the elements in the specified collection, @n
	 *					 else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
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
	 * Compares the specified instance to the current instance for equality.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the specified object is also an instance of %QueueT class,
	 *				both queues have the same size, and all corresponding pairs of elements in the two queues are equal.
	 *				In other words, two queues are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const
	{
		bool out = true;

		const QueueT< Type >* other = dynamic_cast< const QueueT< Type >* >(&obj);
		if (null == other)
		{
			out = false;
		}
		else if (other == this)
		{
			out = true;
		}
		else if (GetCount() != other->GetCount())
		{
			out = false;
		}
		else
		{
			for (int i = 0; i < GetCount(); i++)
			{
				if (!(__pObjArray[(__tail + i) % __capacity] == other->__pObjArray[(other->__tail + i) % other->__capacity]))
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
		int count = GetCount();
		for (int i = 0; i < count; i++)
		{
			if (&(__pObjArray[(__tail + i) % __capacity]) != null)
			{
				hash += reinterpret_cast< int >(&(__pObjArray[(__tail + i) % __capacity]));
			}
		}
		return hash;
	}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	queue The specified instance of %QueueT to initialize the current instance
	 */
	QueueT(const QueueT< Type >& queue);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	queue An instance of %QueueT
	 */
	QueueT< Type >& operator =(const QueueT< Type >& queue);

	int __capacity;
	int __head;
	int __tail;
	Type* __pObjArray;
	int __modCount;
	static const int DEFAULT_CAPACITY = 10;

	friend class __QueueEnumeratorT< Type >;

}; // QueueT

//
// @class	__QueueEnumeratorT
// @brief	This class is an implementation of IEnumeratorT for %QueueT.
// @since 2.0
//
template< class Type >
class __QueueEnumeratorT
	: public IEnumeratorT< Type >
	, public Object
{
public:
	/**
	 * Initializes this instance of __QueueEnumeratorT with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	queue		A queue to enumerate
	 * @param[in]	modeCount	The modification count to detect the change in the queue
	 */
	__QueueEnumeratorT(const QueueT< Type >& queue, int modeCount)
		: __queue(queue)
		, __modCount(modeCount)
		, __position(-1)
	{
	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~__QueueEnumeratorT(void)
	{
	}

	/**
	 * Gets the current object in the queue.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	obj The current object
	 * @exception	E_INVALID_OPERATION	  Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- This enumerator is currently positioned before the first element or
	 *									past the last element. @n
	 *									- The queue is modified after this enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetCurrent(Type& obj) const
	{
		TryReturn((__modCount == __queue.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));
		TryReturn((__position >= __queue.__tail) && (__position < __queue.__head), E_INVALID_OPERATION,
			"[%s] Current position is before the first element or past the last element.", GetErrorMessage(E_INVALID_OPERATION));

		obj = __queue.__pObjArray[__position % __queue.__capacity];

		return E_SUCCESS;
	}

	/**
	 * Moves this enumerator to the next element of the queue. @n
	 * When this enumerator is first created or after the call to Reset(),
	 * the first call to MoveNext() positions this enumerator to the first element in the queue.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the queue is modified after this enumerator is created.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the queue.
	 * @see			Reset()
	 */
	result MoveNext(void)
	{
		TryReturn((__modCount == __queue.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		if ((__position + 1) >= __queue.__head)
		{
			return E_OUT_OF_RANGE;
		}
		else
		{
			if (__position == -1)
			{
				__position = __queue.__tail;
			}
			else
			{
				__position++;
			}
		}

		return E_SUCCESS;
	}

	/**
	 * Positions this enumerator before the first element in the queue.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the queue is modified after this enumerator is created.
	 */
	result Reset(void)
	{
		TryReturn((__modCount == __queue.__modCount), E_INVALID_OPERATION,
			"[%s] The source collection is modified after the creation of this enumerator.", GetErrorMessage(E_INVALID_OPERATION));

		__position = -1;

		return E_SUCCESS;
	}

private:
	const QueueT< Type >& __queue;
	int __modCount;
	int __position;

}; // __QueueEnumeratorT

}}} // Tizen::Base::Collection

#endif //_FBASE_COL_QUEUE_T_H_
