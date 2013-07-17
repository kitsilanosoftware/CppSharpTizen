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
 * @file	FBaseRtTimer.h
 * @brief	This is the header file for the %Timer class.
 *
 * This header file contains the declarations of the %Timer class.
 */

#ifndef _FBASE_RT_TIMER_H_
#define _FBASE_RT_TIMER_H_

#include <FBaseString.h>
#include <FBaseResult.h>
#include <FBaseRtTypes.h>
#include <FBaseRtITimerEventListener.h>

namespace Tizen { namespace Base { namespace Runtime
{
/**
 * @class	Timer
 * @brief	This class provides the timer service.
 *
 * @since 2.0
 *
 * The %Timer class can activate the timer and notify the listeners.
 * Once the target goes into sleep mode, Timer does not work properly because the main loop gets stopped.
 * You can use Alarm on behalf of Timer for sleep mode.
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/timer.htm">Timer</a>.
 * The following example demonstrates how to use the %Timer class.
 *
 * @code
 *
 *  #include <FBase.h>
 *
 *  using namespace Tizen::Base;
 *  using namespace Tizen::Base::Runtime;
 *
 *  class MyTimerApp
 *  	: public ITimerEventListener
 *  	, public Object
 *  {
 *  public:
 *      MyTimerApp();
 *      ~MyTimerApp();
 *
 *     	void OnTimerExpired(Timer& timer);
 *     	bool IsTimerExpired() const;
 *     	int GetCount() {return __count;};
 *     	void StartApp();
 *
 *   private:
 *       	bool __bTimerExpired;
 *       	int __count;
 *       	Timer __timer;
 *   };
 *
 *   MyTimerApp::MyTimerApp()
 *   	: __bTimerExpired(false)
 *   	, __count(10)
 *   {
 *   	 __timer.Construct(*this);
 *   }
 *
 *   MyTimerApp::~MyTimerApp()
 *   {
 *   }
 *
 *   void
 *   MyTimerApp::OnTimerExpired(Timer& timer)
 *   {
 *       __count--;
 *       if (__count == 0)
 *       {
 *       	__bTimerExpired = true;
 *       }
 *       else
 *       {
 *       	timer.Start(100);
 *       }
 *
 *       AppLog("TimerApp: Current count: %d\n", __count);
 *   }
 *
 *   bool
 *   MyTimerApp::IsTimerExpired() const
 *   {
 *       return __bTimerExpired;
 *   }
 *
 *   void
 *   MyTimerApp::StartApp()
 *   {
 *       __timer.Start(10);
 *   }
 *
 * @endcode
 *
 * @see	ITimerEventListener
 * @see Tizen::System::Alarm
 */

class _OSP_EXPORT_ Timer
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	Timer(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~Timer(void);

	/**
	 * Initializes this instance of %Timer with the specified listener.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	listener		The event listener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result Construct(ITimerEventListener& listener);

	/**
	 * Starts the timer.
	 *
	 *
	 * @since 2.0
	 *
	 *
	 * @return		An error code
	 * @param[in]	timeout	        A timeout interval in milliseconds
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		Once it has been started, it cannot be started again until it expires. @n
	 *              You must cancel it if you want to re-start the timer.
	 * @see				Cancel()
	 */
	result Start(int timeout);

	/**
	* @page                    CompTimerStartPage Compatibility for Start(int timeout)
	* @section                 CompTimerStartPageIssueSection Issues
	* Implementation of this method in Tizen API versions prior to 2.1 has the following issue: @n
	* -# The method returns E_INVALID_ARG if timeout is equal to zero.
	*
	* @section                 CompTimerStartPageSolutionSection Resolutions
	* The issue mentioned above is resolved in Tizen API version 2.1, and it is recommended to use Tizen API version 2.1 or above.
	* -# In case of zero, Timer sets timeout to the best-effort minimum interval without returning E_INVALID_ARG.
	*/

	/**
	 * Starts the timer. @n
	 * The timer is expired repeatedly until it is canceled.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	interval	A timeout interval in milliseconds
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks             To stop timer expiration or restart a timer, the timer must be canceled.
	 * @see                Cancel()
	 */
	result StartAsRepeatable(int interval);

	/**
	 * Cancels the timer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		The timer cannot be canceled if it is not started.
	 */
	result Cancel(void);

private:
	Timer(const Timer& rhs);

	Timer& operator =(const Timer& rhs);

private:
	friend class _TimerImpl;
	class _TimerImpl * __pTimerImpl;

}; // Timer

} } } // Tizen::Runtime

#endif // _FBASE_RT_TIMER_H_
