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
 * @file		FBaseRtITimerEventListener.h
 * @brief		This is the header file for the %ITimerEventListener interface.
 *
 */
#ifndef _FBASE_RT_I_TIMER_EVENT_LISTENER_H_
#define _FBASE_RT_I_TIMER_EVENT_LISTENER_H_


#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>


namespace Tizen { namespace Base { namespace Runtime
{
class Timer;

/**
 * @interface ITimerEventListener
 * @brief     This interface is the listener of the timer event.
 *
 * @since 2.0
 *
 * The %ITimerEventListener interface is the listener of the timer event.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/timer.htm">Timer</a>.
 *
 * @see		    Timer()
 */
class _OSP_EXPORT_ ITimerEventListener
	: virtual public IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~ITimerEventListener(void) {}

	/**
	 *	Called when the timer has expired.
	 *
	 *  @since 2.0
	 *
	 *	@param[in]	timer	The timer that has expired
	 */
	virtual void OnTimerExpired(Timer& timer) = 0;

}; // ITimerEventListener

} } } // Tizen::Runtime


#endif // _FBASE_RT_I_TIMER_EVENT_LISTENER_H_
