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
 * @file		FBaseRtSemaphore.h
 * @brief		This is the header file for the %Semaphore class.
 *
 * This header file contains the declarations of the %Semaphore class.
 */

#ifndef _FBASE_RT_SEMAPHORE_H_
#define _FBASE_RT_SEMAPHORE_H_

#include <FBaseResult.h>
#include <FBaseString.h>

namespace Tizen { namespace Base { namespace Runtime
{
/**
 *  @class  Semaphore
 *  @brief  This class represents semaphore, a type of synchronization mechanisms. It can provide the acquiring semantics. @n
 *
 *  @since 2.0
 *
 *  @final This class is not intended for extension.
 *
 * The %Semaphore class represents a semaphore; a type of synchronization mechanism.
 * It can provide the acquiring semantics. The semaphore allows the N threads to acquire the semaphore simultaneously.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/mutex_and_semaphore.htm">Mutex and Semaphore</a>.
 *
 * The following example demonstrates how to use the %Semaphore class.
 *
 *	@code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base::Runtime;
 *
 *	class MySemaphoreApp
 *	{
 *	public:
 *		MySemaphoreApp(int count);
 *		~MySemaphoreApp();
 *
 *		void* AccessCriticalResource();
 *
 *	private:
 *		Semaphore __sem;
 *		int __resourceCount;
 *	};
 *
 *	MySemaphoreApp::MySemaphoreApp(int count)
 *		: __resourceCount(count)
 *	{
 *		__sem.Create(count);
 *	}
 *
 *	MySemaphoreApp::~MySemaphoreApp()
 *	{
 *	}
 *
 *	void
 *	MySemaphoreApp::AccessCriticalResource()
 *	{
 *		__sem.Acquire();
 *		// Code to access critical resource, at max,
 *		// The number of '__resourceCount' users can enter this section at same time,
 *		__sem.Release();
 *	}
 *
 *	@endcode
 * 
 */
class _OSP_EXPORT_ Semaphore
	: Tizen::Base::Object
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
	Semaphore(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since 2.0
	 */
	virtual ~Semaphore(void);


	/**
	 *	Creates an unnamed semaphore.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	count			The number of threads that can acquire the semaphore simultaneously @n
	 *								If the count is @c 1, then it is the same as a mutex.
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_INVALID_ARG	The specified @c count is less than @c 0.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Create(int count = 1);


	/**
	 *	Creates a named semaphore. @n
	 *	If a semaphore with the specified name already exists, this creates a semaphore which references that particular semaphore.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	name			The name of the semaphore
	 *	@param[in]	count			The number of threads that can acquire the semaphore simultaneously
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_INVALID_ARG	The specified @c count is less than @c 0.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Create(const Tizen::Base::String& name, int count = 1);

	/**
	 *	Acquires the semaphore if it is not acquired. @n
	 *	If the semaphore is already acquired, the current thread is blocked until the semaphore is released.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	timeout			The period during which the thread tries to acquire the semaphore
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_TIMEOUT		The operation cannot be completed within the specified time period. @n
	 *								The method has failed to acquire the semaphore because the given time has elapsed.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Acquire(long timeout = INFINITE);

	/**
	 *	Tries to acquire the semaphore. @n
	 *	If the semaphore is already acquired by another thread, E_OBJECT_LOCKED is returned.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_OBJECT_LOCKED 	The semaphore is already locked.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result TryToAcquire(void);

	/**
	 *	Releases the semaphore.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		A system error has occurred.
	 */
	result Release(void);

private:
	Semaphore(const Semaphore& rhs);
	Semaphore& operator =(const Semaphore& rhs);

private:
	friend class _SemaphoreImpl;
	class _SemaphoreImpl * __pSemaphoreImpl;
}; // Semaphore

} } } // Tizen::Base::Runtime


#endif // _FBASE_RT_SEMAPHORE_H_
