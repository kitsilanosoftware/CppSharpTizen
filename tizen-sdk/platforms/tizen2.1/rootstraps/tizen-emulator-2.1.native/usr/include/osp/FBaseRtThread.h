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
 * @file		FBaseRtThread.h
 * @brief		This is the header file for the %Thread class.
 *
 * This header file contains the declarations of the %Thread class.
 */
#ifndef _FBASE_RT_THREAD_H_
#define _FBASE_RT_THREAD_H_


#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseColIList.h>
#include <FBaseColMultiHashMap.h>
#include <FBaseColArrayList.h>

#include <FBaseRtMutex.h>
#include <FBaseRtSemaphore.h>
#include <FBaseRtMonitor.h>
#include <FBaseRtIRunnable.h>


#if defined(Yield)  // For preventing compile errors
#undef Yield
#endif

namespace Tizen { namespace Base { class String; }}

namespace Tizen { namespace Base { namespace Runtime
{


/**
 * @if OSPDEPREC
 * @enum ThreadType
 *
 * Defines the type of thread.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated This enum is deprecated.
 *
 * @since 2.0
 *
 * @endif
 */
enum ThreadType
{
	THREAD_TYPE_WORKER = 0, /**< @if OSPDEPREC The worker thread mode @endif */
	THREAD_TYPE_EVENT_DRIVEN, /**< @if OSPDEPREC The event-driven thread mode @endif */
	THREAD_TYPE_MAIN			// This enum value is for internal use only. Using this enum value can cause behavioral,
								// security-related, and consistency-related issues in the application.
								// The main thread mode
};

/**
 * @enum ThreadPriority
 *
 * Defines the priority of the thread.
 *
 * @since 2.0
 *
 */
enum ThreadPriority
{
	THREAD_PRIORITY_HIGH, /**< The high priority*/
	THREAD_PRIORITY_MID, /**< The mid priority*/
	THREAD_PRIORITY_LOW, /**< The low priority*/
};

/**
 * @class   Thread
 * @brief	This class is the fundamental class for the asynchronous execution of a thread.
 *
 * @since 2.0
 *
 * @remarks This class supports only worker threads. For event-driven threads, use the EventDrivenThread class.
 *
 * The %Thread class is the fundamental class for the asynchronous execution of a thread.
 * A Tizen native application can execute several threads during its operation from the multi-threading view.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/thread.htm">Thread</a>.
 *
 * @see Tizen::Base::Runtime::EventDrivenThread
 *
 * The following example demonstrates how to use the %Thread class.
 *
 * @code
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Runtime;
 *
 * class MyThread
 *  : public Thread
 * {
 *   public:
 *		MyThread(void)
 *		{
 *		}
 *
 *		virtual ~MyThread(void)
 *		{
 *		}
 *
 *		result Construct(void)
 *		{
 *				return Thread::Construct();
 *		}
 *
 *		Object* Run(void)
 *		{
 *				// Do some task...
 *				return null;
 *		}
 * };
 *
 * void
 * MyApplication::ThreadSample(void)
 * {
 *		MyThread* pMyThread = new MyThread;
 *
 *		pMyThread->Construct();
 *
 *		pMyThread->Start();
 *
 *		pMyThread->Join(); // Waits until the thread finished the task
 *
 *		delete pMyThread;
 * }
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ Thread
	: public Object
	, public Tizen::Base::Runtime::IRunnable

{
public:
	/**
	* Default stack size of the thread.
	*
	* @since 2.0
	*
	*/
	const static unsigned long DEFAULT_STACK_SIZE = 64 * 1024;

public:
	/**
	 * Suspends the execution of the current thread for the specified interval.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   milliSeconds    The time, in milliseconds, for which to suspend the execution @n
	 *                              A value of zero causes the thread to relinquish the remainder of its time
	 *                              slice to any other thread that is ready to run. The time cannot be negative.
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   A negative time value is passed.
	 */
	static result Sleep(long milliSeconds);

	/**
	 * Causes the current thread context to be temporarily paused and allows other threads to execute.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS      The method is successful.
	 * @exception   E_SYSTEM       A system error has occurred.
	 */
	static result Yield(void);

	/**
	 * Ends a thread.
	 * After this method is called, the thread's execution is stopped.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   exitCode        The exit code for the thread @n
	 * @exception   E_SUCCESS       The method is successful.
	 * @remarks      Use GetExitCode() for getting the exit code set by this method.  
	 */
	static result Exit(int exitCode = 0x00);

	/**
	 * Gets the pointer of the currently running %Thread instance.
	 *
	 * @since 2.0
	 *
	 * @return      A pointer to the currently running thread
	 */
	static Thread* GetCurrentThread(void);

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @remarks		After creating an instance of this class, one of the
	 *              Construct() methods must be called explicitly to initialize this instance.
	 */
	Thread(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %Thread with the specified thread type, stack size, and priority.
	 *
 	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated because the %Thread class does not support event-driven thread any more. Instead, use the EventDrivenThread class instead.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   threadType      The thread type
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 * @endif
	 */
	result Construct(ThreadType threadType, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %Thread with the specified name, thread type, stack size, and priority.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated because the %Thread class does not support event-driven thread any more. Instead, use the EventDrivenThread class instead.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   name            The name of the thread
	 * @param[in]   threadType      The thread type
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 * @endif
	 */
	result Construct(const Tizen::Base::String& name, ThreadType threadType,
			long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * Initializes this instance of %Thread with the specified stack size, and priority.
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
	 * Initializes this instance of %Thread with the specified name, stack size, and priority.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   name            The name of the thread
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result Construct(const Tizen::Base::String& name,
		long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * Initializes this instance of %Thread with the specified IRunnable instance, stack size, and priority.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   target          An instance of %IRunnable
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result Construct(IRunnable& target, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * Initializes this instance of %Thread with the specified name, IRunnable instance, stack size, and priority.
	 *
	 * @since 2.0
	 *
	 * @return              An error code
	 * @param[in]   name                    The name of the thread
	 * @param[in]   target          An instance of IRunnable
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   An invalid argument is passed.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result Construct(const Tizen::Base::String& name, IRunnable& target,
					 long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 *
	 */
	virtual ~Thread(void);

	/**
	 * Waits until the thread execution is terminated.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS             The method is successful.
	 * @exception   E_INVALID_OPERATION   An other thread is calling this method.
	 * @exception   E_SYSTEM              A system error has occurred.
	 */
	result Join(void);

	/**
	 * Starts the thread. @n
	 * The Run() method is called when the thread starts.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_SYSTEM               A system error has occurred.
	 */
	result Start(void);

	/**
	 * @if OSPDEPREC
	 * Forces the thread to stop executing.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS                       The method is successful.
	 * @exception   E_SYSTEM                        A system error has occurred.
	 * @remarks     This is only available for event-driven threads.
	 * @endif
	 */
	result Stop(void);

	/**
	 * Called when the thread is started without the IRunnable instance. @n
	 * The body for thread execution is specified by inheriting the %Thread class and implementing this method.
	 *
	 * @since 2.0
	 *
	 * @return      It is just ignored because there is nowhere to take the returned object
	 * @remarks     The default action of this method returns @c null.
	 */
	virtual Tizen::Base::Object* Run(void);

	/**
	 * Gets an exit code of the thread which is given by calling the Exit() method.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[out]  exitCode               The exit code for the thread
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_INVALID_STATE        The thread is in an invalid state.
	 * @exception   E_SYSTEM               A system error has occurred.
	 */
	result GetExitCode(int& exitCode) const;

	/**
	 * Gets the name of the thread.
	 *
	 * @since 2.0
	 *
	 * @return      The name of the thread
	 * @exception   E_SUCCESS                       The method is successful.
	 */
	const Tizen::Base::String& GetName(void) const;


	/**
	 * @if OSPDEPREC
	 * Called before the Run() method is executed. @n
	 * The Run() method is executed if this method returns @c true, and @n
	 * if this method returns @c false, the thread is terminated immediately.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated because the %Thread class does not support event-driven threads.
	 *
	 * @since 2.0
	 *
	 * @return              @c true if this thread can be run, @n
	 *                              else @c false
	 * @remarks             You can initialize the event or event listener in this method for running this
	 *                      thread in an event-driven mode.
	 * @endif
	 */
	virtual bool OnStart(void);

	/**
	 * @if OSPDEPREC
	 * Called after the Run() method is executed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated because the %Thread class does not support event-driven threads.
	 * @since 2.0
	 *
	 * @remarks     You can finalize the event or event listener in this method for running this
	 *              thread in an event-driven mode.
	 *
	 * @endif
	 */
	virtual void OnStop(void);

	/**
	 * @if OSPDEPREC
	 * Sends a user event to the event-driven thread.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated because the %Thread class does not support event-driven threads.
	 *
	 * @since 2.0
	 *
	 * @return       An error code
	 * @param[in]    requestId            The user-defined event Id
	 * @param[in]    pArgs                A pointer to a list of arguments
	 * @exception    E_SUCCESS            The method is successful.
	 * @exception    E_INVALID_OPERATION  The thread is not an event-driven thread.
	 *
	 * @remarks     This is only available for event-driven threads.
	 * @see         OnUserEventReceivedN()
	 * @endif
	 */
	virtual result SendUserEvent(RequestId requestId, const Tizen::Base::Collection::IList* pArgs);

	/**
	 * @if OSPDEPREC
	 * Called when the user event is received.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated because the %Thread class does not support event-driven threads.
	 *
	 * @since 2.0
	 *
	 * @param[in]    requestId       The user-defined event Id
	 * @param[in]    pArgs           A pointer to a list of arguments
	 * @see          SendUserEvent()
	 * @endif
	 */
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

private:
	Thread(const Thread& rhs);
	Thread& operator =(const Thread& rhs);

private:
	friend class _ThreadImpl;
	class _ThreadImpl* __pThreadImpl;
}; // Thread

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_THREAD_H_

