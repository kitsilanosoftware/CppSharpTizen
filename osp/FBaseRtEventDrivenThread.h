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
 * @file		FBaseRtEventDrivenThread.h
 * @brief		This is the header file for the %EventDrivenThread class.
 *
 * This header file contains the declarations of the %EventDrivenThread class.
 */
#ifndef _FBASE_RT_EVENT_DRIVEN_THREAD_H_
#define _FBASE_RT_EVENT_DRIVEN_THREAD_H_


#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseRtThread.h>

namespace Tizen { namespace Base { class String; }}

namespace Tizen { namespace Base { namespace Runtime
{

/**
 * @class   EventDrivenThread
 * @brief		This class is the fundamental class for the asynchronous execution of a thread.
 *
 * @since 2.0
 *
 * The %EventDrivenThread class is the fundamental class for the asynchronous execution of a thread.
 * A Tizen native application can execute several threads during its operation from the multi-threading view.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/thread.htm">Thread</a>.
 *
 * @see Tizen::Base::Runtime::EventDrivenThread
 *
 * The following example demonstrates how to use the %EventDrivenThread class.
 *
 * @code
 *
 *   #include <FBase.h>
 *
 *   using namespace Tizen::Base;
 *   using namespace Tizen::Base::Runtime;
 *
 *   class MyTimerThread
 *   	: public EventDrivenThread
 *   	, public ITimerEventListener
 *   {
 *   public:
 *   	MyTimerThread(void)
 *   		: __pTimer(null)
 *   		, __count(0)
 *   	{
 *   	}
 *
 *   	virtual ~MyTimerThread(void)
 *   	{
 *   		delete __pTimer;
 *   	}
 *
 *   	result Construct(void)
 *   	{
 *   		return EventDrivenThread::Construct();
 *   	}
 *
 *   	bool OnStart(void)
 *   	{
 *   		__pTimer = new Timer;
 *
 *   		__pTimer->Construct(*this);
 *
 *   		__pTimer->StartAsRepeatable(1000);
 *
 *   		return true;
 *   	}
 *
 *   	void OnStop(void)
 *   	{
 *   		__pTimer->Cancel();
 *   	}
 *
 *   	void OnTimerExpired(Timer& timer)
 *   	{
 *   		// Do repetitive tasks
 *   		AppLog("MyTimerThread: OnTimerExpired: %d", __count++);
 *   	}
 *
 *   private:
 *   	Timer* __pTimer;
 *   	int __count;
 *   };
 *
 *   void
 *   MyApplication::StartEventDrivenThreadSample(void)
 *   {
 *		__pMyTimerThread = new MyThread;
 *
 *		__pMyTimerThread->Construct();
 *
 *		__pMyTimerThread->Start();
 *
 *   }
 *
 *   void
 *   MyApplication::StopEventDrivenThreadSample(void)
 *   {
 *
 *		__pMyTimerThread->Quit();
 *
 *		__pMyTimerThread->Join();
 *
 *		delete __pMyTimerThread;
 *   }
 *
 * @endcode
 */

class _OSP_EXPORT_ EventDrivenThread
	: public Thread
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @remarks     After creating an instance of this class, one of the
	 *              Construct() methods must be called explicitly to initialize this instance.
	 */
	EventDrivenThread(void);

	/**
	 * Initializes this instance of %EventDrivenThread with the specified thread type, stack size, and priority.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result Construct(long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * Initializes this instance of %EventDrivenThread with the specified name, thread type, stack size, and priority.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   name                    The name of the thread
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result Construct(const Tizen::Base::String& name, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 *
	 */
	virtual ~EventDrivenThread(void);

	/**
	 * Sends a termination request to the thread.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS                       The method is successful.
	 * @exception   E_INVALID_STATE                 The thread is in an invalid state.
	 * @exception   E_SYSTEM                        A system error has occurred.
	 */
	virtual result Quit(void);

	/**
	 * Called when the thread is started and runs a message loop.
	 *
	 * @since 2.0
	 *
	 * @final       Although this method is virtual, it must not be overridden.
	 *              If overridden, it may not work as expected.
	 *
	 * @return      It is just ignored because there is nowhere to take the returned object
	 * @remarks     The default action of this method returns @c null.
	 */
	virtual Tizen::Base::Object* Run(void);

	/**
	 * Called before the message loop is started. @n
	 * If this method returns @c false, the thread is terminated immediately.
	 *
	 * @since 2.0
	 *
	 * @return              @c true if this thread can be run, @n
	 *                              else @c false
	 * @remarks             You can initialize the event or event listener in this method for running this thread.
	 *
	 */
	virtual bool OnStart(void);

	/**
	 * Called after the message loop is stopped.
	 *
	 * @since 2.0
	 *
	 * @remarks     You can finalize the event or event listener in this method for running this thread.
	 *
	 */
	virtual void OnStop(void);

	/**
	 * Sends a user event to the event-driven thread.
	 *
	 * @since 2.0
	 *
	 * @final        Although this method is virtual, it must not be overridden.
	 *               If overridden, it may not work as expected.
	 *
	 * @return       An error code
	 * @param[in]    requestId       The user-defined event ID
	 * @param[in]    pArgs           A pointer to a list of arguments
	 * @exception    E_SUCCESS         The method is successful.
	 * @exception    E_INVALID_STATE   The thread is in an invalid state.
	 * @exception    E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception    E_SYSTEM          A system error has occurred.
	 *
	 * @see          OnUserEventReceivedN()
	 */
	virtual result SendUserEvent(RequestId requestId, const Tizen::Base::Collection::IList* pArgs);

	/**
	 * Called when the user event is received.
	 *
	 * @since 2.0
	 *
	 * @param[in]    requestId       The user-defined event ID
	 * @param[in]    pArgs           A pointer to a list of arguments
	 *
	 * @see          SendUserEvent()
	 */
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

private:
	EventDrivenThread(const EventDrivenThread& rhs);
	EventDrivenThread& operator = (const EventDrivenThread& rhs);

private:
	class _EventDrivenThreadImpl* __pEventDrivenThreadImpl;
	friend class _EventDrivenThreadImpl;

}; // EventDrivenThread

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_EVENT_DRIVEN_THREAD_H_

