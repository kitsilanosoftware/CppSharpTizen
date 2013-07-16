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
 * @file		FBaseRtMutex.h
 * @brief		This is the header file for the %Mutex class.
 *
 * This header file contains the declarations of the %Mutex class.
 */

#ifndef _FBASE_RT_MUTEX_H_
#define _FBASE_RT_MUTEX_H_

#include <FBaseResult.h>
#include <FBaseString.h>



namespace Tizen { namespace Base { namespace Runtime
{
/**
 * @struct	NonRecursiveMutexTag
 *
 * This struct is used only for providing the non-recursive type of mutex.
 * A non-recursive mutex is a mutex that can not be acquired multiple times by the locking thread. It returns an exception if the locking thread tries to lock the same mutex.
 *
 * @since 2.1
 *
 * @see		Mutex
 */
 struct NonRecursiveMutexTag
 {
 };

/**
 * This is a constant instance of NonRecursiveMutexTag.
 *
 * @code
 * Mutex m;
 * result r = m.Create(NonRecursiveMutex); 
 * @endcode
 */
 static const NonRecursiveMutexTag NonRecursiveMutex = {};

/**
 *  @class Mutex
 *	@brief	This class represents a mutex; a type of synchronization mechanism.
 *
 *	@since 2.0
 *
 * @final This class is not intended for extension.
 *  The %Mutex class represents a mutex; a type of synchronization mechanism.
 *	It is a binary semaphore. Only one thread can acquire the %Mutex.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/mutex_and_semaphore.htm">Mutex and Semaphore</a>.
 *
 *	@see Semaphore
 * 	@see Thread
 *
 * The following example demonstrates how to use the %Mutex class.
 *
 *	@code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base::Runtime;
 *
 *	class MyMutexApp
 *	{
 *	public:
 *		MyMutexApp();
 *		~MyMutexApp();
 *
 *		void UpdateCriticalResource();
 *
 *	private:
 *		Mutex __mutex;
 *		int __count;
 *	};
 *
 *	MyMutexApp::MyMutexApp()
 *		: __count(0)
 *	{
 *		__mutex.Create();
 *	}
 *
 *	MyMutexApp::~MyMutexApp()
 *	{
 *	}
 *
 *	void
 *	MyMutexApp::UpdateCriticalResource()
 *	{
 *		__mutex.Acquire();
 *		__count++;
 *		__mutex.Release();
 *	}
 *
 *	@endcode
 *
 */

class _OSP_EXPORT_ Mutex
	: public Tizen::Base::Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since 2.0
	 *
	 *	@remarks	After creating an instance of this class, one of
	 *				the Create() methods must be called explicitly to initialize this instance.
	 */
	Mutex(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since 2.0
	 */
	virtual ~Mutex(void);

	/**
	 *	Creates an unnamed mutex which is a recursive mutex that can be acquired multiple times by the locking thread. 
	 *     It keeps the number of getting locked and you must unlock it the same number of times.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Create(void);

	/**
	 *	Creates a non-recursive mutex.
	 *
	 *	@since 2.1
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Create(NonRecursiveMutexTag);

	/**
	 *	Creates a named mutex which is a recursive mutex that can be acquired multiple times by the locking thread. 
	 *     It keeps the number of getting locked and you must unlock it the same number of times. @n
	 *	If a mutex with the specified name already exists, this creates a mutex which references that particular mutex.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	name			The name of the mutex
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Create(const Tizen::Base::String& name);

	/**
	 *	Releases the mutex.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM	A system error has occurred.
	 *	@remarks	This method should be called only after acquiring lock by Acquire()/ TryToAcquire() call
	 */
	result Release(void);

	/**
	 *	Acquires the mutex if it is not acquired. @n
	 *	If the mutex is already acquired by another thread,
	 *	the current thread is blocked until the mutex is released.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 *	@remarks	This method will block if called on already locked monitor object until mutex becomes availalbe.
	 */
	result Acquire(void);

	/**
	 *	Tries to acquire the mutex if it is not acquired. @n
	 *	If the mutex is already acquired by another thread, E_OBJECT_LOCKED is returned.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_OBJECT_LOCKED		The mutex is already locked.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 * 	@remarks	This method will block if called on already locked monitor object until mutex becomes availalbe.
	 */
	result TryToAcquire(void);

private:
	Mutex(const Mutex& value);
	Mutex& operator =(const Mutex& value);

private:
	friend class _MutexImpl;
	class _MutexImpl * __pMutexImpl;
}; // Mutex

} } } // Tizen::Base::Runtime


#endif // _FBASE_RT_MUTEX_H_
