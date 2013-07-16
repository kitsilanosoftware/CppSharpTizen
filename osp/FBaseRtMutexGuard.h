//
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
* @file		FBaseRtMutexGuard.h
* @brief	This is the header file for the %MutexGuard class.
*
* This header file contains the declarations of the %MutexGuard class.
*/

#ifndef _FBASE_RT_MUTEX_GUARD_H_
#define _FBASE_RT_MUTEX_GUARD_H_

#include <FBaseRtMutex.h>
#include <FBaseRtTypes.h>

namespace Tizen { namespace Base { namespace Runtime
{

/**
* @class	MutexGuard
* @brief	This class is the RAII style class for %Mutex class.
*
* @since 2.0
*
* The following example demonstrates how to use this %MutexGuard class
*
* @code
*
* #include <FBase.h>
* #include <FBaseRt.h>
*
* using namespace std;
* using namespace Tizen::Base::Runtime;
*
* class SynchronizedCounter
* {
* public:
*     explicit SynchronizedCounter(long long initialValue = 0)
*         : __m()
*         , __count(initialValue)
*     {
*         __m.Create();
*     }
*
*     SynchronizedCounter(const SynchronizedCounter& rhs)
*         : __m()
*         , __count(rhs.__count)
*     {
*         __m.Create();
*     }
*
*     SynchronizedCounter& operator =(SynchronizedCounter rhs)
*     {
*         __count = rhs.__count;
*         return *this;
*     }
*
*     SynchronizedCounter& operator ++()
*     {
*         IncrementImpl(1);
*         return *this;
*     }
*
*     SynchronizedCounter& operator --()
*     {
*         IncrementImpl(-1);
*         return *this;
*     }
*
*     bool TryToIncrement(void)
*     {
*         return TryToIncrementImpl(1);
*     }
*
*     bool TryToDecrement(void)
*     {
*         return TryToIncrementImpl(-1);
*     }
*
*     long long GetCount() const
*     {
*         return __count;
*     }
*
* private:
*     void IncrementImpl(int amount)
*     {
*         MutexGuard lock(__m);
*         __count += amount;
*     }	// The acquired lock will be released when going out of scope
*
*     bool TryToIncrementImpl(int amount)
*     {
*         MutexGuard lock(__m, Try);	// Uses predefined Try const object for non-blocking mode locking
*         TryReturn(lock.IsLocked(), false, “Failed to lock mutex”);
*         __count += amount;
*         return true;
*     }
*
*     Mutex __m;
*     long long __count;
* };
*
* class MyThread
*     : public Thread
* {
* public:
*     static SynchronizedCounter counter;
*     static const long long LOOP_COUNT = 10000000;
*
*     virtual Object* Run(void)
*     {
*         for (long long i = 0; i < LOOP_COUNT; ++i)
*         {
*             ++counter;
*         }
*
*         return null;
*     }
* };
*
* SynchronizedCounter MyThread::counter;
*
* void
* ButtonPanel::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
* {
*     switch (actionId)
*     {
*     case ID_BUTTON:
*         {
*             static const int NUM_THREADS = 10;
*             MyThread thrs[NUM_THREADS];
*
*             __pLabel->SetText(L"Button is clicked!");
*             AppLog("Button is pressed!");
*
*             for (int i = 0; i < NUM_THREADS; ++i)
*             {
*                 thrs[i].Construct();
*                 thrs[i].Start();
*             }
*
*             for (int i = 0; i < NUM_THREADS; ++i)
*             {
*                 thrs[i].Join();
*             }
*
*             AppLog("Total Count = [%lld]", MyThread::counter.GetCount());
*             AppAssertf(MyThread::counter.GetCount() == NUM_THREADS * MyThread::LOOP_COUNT,
*                        "[Assert] Count is wrong");
*         }
*         break;
*     }
*     Invalidate(true);
* }
*
* @endcode
*/

class MutexGuard
{
public:
	/**
	* This constructor acquires the lock in a blocking way.
	*
	* @since 2.0
	*
	* @param[in]	m	The %Mutex instance to be manipulated
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			Mutex::Acquire() for detailed exceptions
	*/
	MutexGuard(Mutex& m)
		: __m(m)
		, __locked(false)
	{
		SetLastResult(Lock());
	}

	/**
	* This constructor acquires the lock in a non-blocking way.
	*
	* @since 2.0
	*
	* @param[in]	m	The %Mutex instance to be manipulated
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			Mutex::TryToAcquire() for detailed exceptions
	*/
	MutexGuard(Mutex& m, TryTag)
		: __m(m)
		, __locked(false)
	{
		SetLastResult(TryToLock());
	}

	/**
	* This destructor releases the lock if acquired when going out of a scope
	*
	* @since 2.0
	*
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @see		Mutex::Release() for detailed exceptions
	*/
	~MutexGuard(void)
	{
		SetLastResult(Unlock());
	}

	/**
	* Returns whether this instance owns the lock on the given mutex at constructor.
	*
	* @since 2.0
	*
	* @return	true if the lock is owned, @n
	*			false otherwise.
	*/
	bool IsLocked(void) const
	{
		return __locked;
	}

	/**
	* Returns whether this instance owns the lock on the given mutex at constructor. @n
	* Have same effects to calling IsLocked().
	*
	* @since 2.0
	*/
	operator bool() const
	{
		return IsLocked();
	}

	/**
	* Acquires the lock manually on the given mutex at constructor in a blocking way
	*
	* @since 2.0
	*
	* @return	An error code.
	* @see		Mutex::Acquire() for detailed exceptions
	*/
	result Lock(void)
	{
		return SetLockedAndReturn(__m.Acquire());
	}

	/**
	* Acquires the lock manually on the given mutex at constructor in a non-blocking way
	*
	* @since 2.0
	*
	* @return	An error code.
	* @see		Mutex::TryToAcquire() for detailed exceptions
	*/
	result TryToLock(void)
	{
		return SetLockedAndReturn(__m.TryToAcquire());
	}

	/**
	* Releases the lock manually
	*
	* @since 2.0
	*
	* @return	An error code.
	* @see		Mutex::Release() for detailed exceptions
	*/
	result Unlock(void)
	{
		result r = E_SUCCESS;
		if (__locked)
		{
			r = __m.Release();
			__locked = false;
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
	MutexGuard(const MutexGuard& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private
	* to prohibit copying of objects.
	*
	* @since 2.0
	*/
	MutexGuard& operator =(const MutexGuard& rhs);

	// helper function
	result SetLockedAndReturn(result r)
	{
		__locked = (r == E_SUCCESS);
		return r;
	}

private:
	Mutex& __m;
	bool __locked;
}; // MutexGuard

}}} // Tizen::Base::Runtime

#endif // _FBASE_RT_MUTEX_GUARD_H_
