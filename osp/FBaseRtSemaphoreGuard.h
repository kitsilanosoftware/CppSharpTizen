//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
* @file		FBaseRtSemaphoreGuard.h
* @brief	This is the header file for the %SemaphoreGuard class.
*
* This header file contains the declarations of the %SemaphoreGuard class.
*/

#ifndef _FBASE_RT_SEMAPHORE_GUARD_H_
#define _FBASE_RT_SEMAPHORE_GUARD_H_

#include <FBaseRtSemaphore.h>
#include <FBaseRtTypes.h>

namespace Tizen { namespace Base { namespace Runtime
{

/**
* @class	SemaphoreGuard
* @brief	This class is the RAII style class for %Semaphore class.
*
* @since 2.0
*/
class SemaphoreGuard
{
public:
	/**
	* This constructor acquires a semaphore count in a blocking way.
	*
	* @since 2.0
	*
	* @param[in]	s	The %Semaphore instance to be manipulated
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			Semaphore::Acquire() for detailed exceptions
	*/
	SemaphoreGuard(Semaphore& s)
		: __s(s)
		, __acquired(false)
	{
		SetLastResult(Acquire());
	}

	/**
	* This constructor acquires a semaphore count in a non-blocking way.
	*
	* @since 2.0
	*
	* @param[in]	s	The %Semaphore instance to be manipulated
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			Semaphore::TryToAcquire() for detailed exceptions
	*/
	SemaphoreGuard(Semaphore& s, TryTag)
		: __s(s)
		, __acquired(false)
	{
		SetLastResult(TryToAcquire());
	}

	/**
	* This destructor releases the acquired semaphore count when going out of a scope
	*
	* @since 2.0
	*
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @see		Semaphore::Release() for detailed exceptions
	*/
	~SemaphoreGuard(void)
	{
		SetLastResult(Release());
	}

	/**
	* Returns whether this instance owns a semaphore count on the given semaphore at constructor.
	*
	* @since 2.0
	*
	* @return	true if a semaphore is owned, @n
	*			false otherwise.
	*/
	bool IsAcquired(void) const
	{
		return __acquired;
	}

	/**
	* Returns whether this instance owns a semaphore count on the given semaphore at constructor. @n
	* Have same effects to calling IsAcquired().
	*
	* @since 2.0
	*/
	operator bool() const
	{
		return IsAcquired();
	}

	/**
	* Acquires a semaphore count manually on the given semaphore at constructor in a blocking way
	*
	* @since 2.0
	*
	* @return	An error code.
	* @see		Semaphore::Acquire() for detailed exceptions
	*/
	result Acquire(void)
	{
		return SetAcquiredAndReturn(__s.Acquire());
	}

	/**
	* Acquires a semaphore count manually on the given semaphore at constructor in a non-blocking way
	*
	* @since 2.0
	*
	* @return	An error code.
	* @see		Semaphore::TryToAcquire() for detailed exceptions
	*/
	result TryToAcquire(void)
	{
		return SetAcquiredAndReturn(__s.TryToAcquire());
	}

	/**
	* Releases the acquired semaphore count manually
	*
	* @since 2.0
	*
	* @return	An error code.
	* @see		Semaphore::Release() for detailed exceptions
	*/
	result Release(void)
	{
		result r = E_SUCCESS;
		if (__acquired)
		{
			r = __s.Release();
			__acquired = false;
		}
		return r;
	}

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private 
	* to prohibit copying of objects.
	*
	* @since 2.0
	*/
	SemaphoreGuard(const SemaphoreGuard& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private
	* to prohibit copying of objects.
	*
	* @since 2.0
	*/
	SemaphoreGuard& operator =(const SemaphoreGuard& rhs);

	// helper function
	result SetAcquiredAndReturn(result r)
	{
		__acquired = (r == E_SUCCESS);
		return r;
	}

private:
	Semaphore& __s;
	bool __acquired;
}; // SemaphoreGuard

}}} // Tizen::Base::Runtime

#endif // _FBASE_RT_SEMAPHORE_GUARD_H_
