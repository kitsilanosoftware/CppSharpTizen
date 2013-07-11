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
* @file		FBaseRtMonitorGuard.h
* @brief	This is the header file for the %MonitorGuard class.
*
* This header file contains the declarations of the %MonitorGuard class.
*/

#ifndef _FBASE_RT_MONITOR_GUARD_H_
#define _FBASE_RT_MONITOR_GUARD_H_

#include <FBaseRtMonitor.h>

namespace Tizen { namespace Base { namespace Runtime
{

/**
* @class	MonitorGuard
* @brief	This class is the RAII style class for %Monitor class.
*
* @since 2.0
*/
class MonitorGuard
{
public:
	/**
	* This constructor enters the monitored block in a blocking way.
	*
	* @since 2.0
	*
	* @param[in]	m	The %Monitor instance to be manipulated
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			Monitor::Enter() for detailed exceptions
	*/
	MonitorGuard(Monitor& m)
	: __m(m)
	, __entered(false)
	{
		SetLastResult(SetEnteredAndReturn(__m.Enter()));
	}

	/**
	* This destructor exits the monitored block when going out of a scope
	*
	* @since 2.0
	*
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @see		Monitor::Exit() for detailed exceptions
	*/
	~MonitorGuard(void)
	{
		result r = E_SUCCESS;
		if (__entered)
		{
			r = __m.Exit();
			__entered = false;
		}
		SetLastResult(r);
	}

	/**
	* Returns whether this instance owns the lock on the given monitor at constructor.
	*
	* @since 2.0
	*
	* @return	true if the lock is owned, @n
	*			false otherwise.
	*/
	bool IsEntered(void) const
	{
		return __entered;
	}

	/**
	* Returns whether this instance owns the lock on the given monitor at constructor. @n
	* Have same effects to calling IsEntered().
	*
	* @since 2.0
	*/
	operator bool() const
	{
		return IsEntered();
	}

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private 
	* to prohibit copying of objects.
	*
	* @since 2.0
	*/
	MonitorGuard(const MonitorGuard& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private
	* to prohibit copying of objects.
	*
	* @since 2.0
	*/
	MonitorGuard& operator =(const MonitorGuard& rhs);

	// helper function
	result SetEnteredAndReturn(result r)
	{
		__entered = (r == E_SUCCESS);
		return r;
	}

private:
	Monitor& __m;
	bool __entered;
}; // MonitorGuard

}}} // Tizen::Base::Runtime

#endif // _FBASE_RT_MONITOR_GUARD_H_
