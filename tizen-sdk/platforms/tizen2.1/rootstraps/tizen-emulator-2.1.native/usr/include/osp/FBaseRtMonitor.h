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
 * @file		FBaseRtMonitor.h
 * @brief		This is the header file for the %Monitor class.
 *
 * This header file contains the declarations of the %Monitor class.
 */

#ifndef _FBASE_RT_MONITOR_H_
#define _FBASE_RT_MONITOR_H_

#include <FBaseResult.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Runtime
{

class _MonitorImpl;

/**
 * @class   Monitor
 * @brief	This represents a monitor; a type of synchronization mechanism that provides acquire/release semantics by Enter() / Exit() as well as wait/notify semantics by Wait() / Notify() / NotifyAll().
 *
 * @since 2.0
 *
 * @final This class is not intended for extension.
 *
 * The %Monitor class represents a monitor. %Monitor is a synchronization mechanism that provides acquire/release semantics by Enter() / Exit() as well as wait/notify semantics by Wait() / Notify() / NotifyAll().
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/monitor.htm">Monitor</a>.
 *
 * The following examples demonstrates how to use the %Monitor class. In the examples, 2 classes, Consumer and Producer, share a space.
 * Producer writes some data to this space, and Consumer reads it. Consumer and Producer run simultaneously.
 * Consumer must not miss the data which Producer writes. In this case, Consumer and Producer share the monitor.
 * Producer notifies Consumer that its writing action is done. Consumer waits for this notification, and reads the data after receiving it.
 *
 * @code
 *
 *  #include <FBase.h>
 *
 *  using namespace Tizen::Base;
 *  using namespace Tizen::Base::Runtime;
 *
 *  class Producer
 *		: public Thread
 *  {
 *  public:
 *
 *		// This methods creates a new instance of the Producer thread
 *     	Producer(int* pShared, Monitor* pMonitor);
 *     	virtual ~Producer(void);
 *
 *     	// This methods waits for a starting Consumer and sets a value to the shared position
 *     	//	Finally it notifies the Consumer thread
 *     	virtual Object* Run(void);
 *
 *	private:
 *			int* __pShared;
 *     	Monitor* __pMonitor;
 *  };
 *
 *  Producer::Producer(int* pShared, Monitor* pMonitor)
 *     	: __pShared(pShared)
 *     	, __pMonitor(pMonitor)
 *  {
 *  }
 *
 *  Producer::~Producer(void)
 *  {
 *  }
 *
 *  Object*
 *  Producer::Run(void)
 *  {
 *    	if (__pShared && __pMonitor)
 *    	{
 *    		// Begins a critical region
 *    		result r = __pMonitor->Enter();
 *    		if (IsFailed(r))
 *    		{
 *    			goto CATCH2;
 *    		}
 *
 *    		// Waits for a starting Consumer
 *    		r = __pMonitor->Wait();
 *    		if (IsFailed(r))
 *    		{
 *    			goto CATCH1;
 *    		}
 *
 *    		// Produces a number value 6 times
 *    		for (int i = 0; i < 6; i++)
 *    		{
 *    			*__pShared = i;
 *
 *    			// Notifies the consumer thread
 *    			r = __pMonitor->Notify();
 *    			if (IsFailed(r))
 *    			{
 *    				goto CATCH1;
 *    			}
 *
 *    			AppLog("Producer::Run [%d]: Value at shared resource: %d\n", i, *__pShared);
 *    			if (*__pShared == 5)
 *    			{
 *    				break;
 *    			}
 *
 *    			// Waits until the consumer thread reads the value
 *    			r = __pMonitor->Wait();
 *    		}
 *
 *		CATCH1:
 *    		__pMonitor->Exit();
 *		}
 *
 *  CATCH2:
 *    	return null;
 *  }
 *
 *  class Consumer
 *		: public Thread
 *  {
 *  public:
 *
 *  	// This methods creates a new instance of the Consumer thread
 *    	Consumer(int* pShared, Monitor* pMonitor);
 *    	virtual ~Consumer(void);
 *
 *    	// This methods waits for a notification from the Producer thread and reads a value From the shared position
 *    	virtual Tizen::Base::Object* Run(void);
 *
 *  private:
 *    	int* __pShared;
 *    	Monitor* __pMonitor;
 *
 *  };
 *
 *  Consumer::Consumer(int* pShared, Monitor* pMonitor)
 *    	: __pShared(pShared)
 *    	, __pMonitor(pMonitor)
 *  {
 *  }
 *
 *  Consumer::~Consumer(void)
 *  {
 *  }
 *
 *  Object*
 *  Consumer::Run(void)
 *  {
 *    	if (__pShared &&__pMonitor)
 *    	{
 *    		// Begins a critical region
 *    		result r = __pMonitor->Enter();
 *    		if (IsFailed(r))
 *    		{
 *    			goto CATCH2;
 *    		}
 *
 *    		// Notifies the producer thread
 *    		r = __pMonitor->Notify();
 *    		if (IsFailed(r))
 *    		{
 *    			goto CATCH1;
 *    		}
 *
 *    		// Waits for a notification
 *    		r = __pMonitor->Wait();
 *    		while (!IsFailed(r))
 *    		{
 *    			// Notifies the producer thread
 *    			r = __pMonitor->Notify();
 *    			if (IsFailed(r))
 *    			{
 *    				goto CATCH1;
 *    			}
 *
 *    			AppLog("Consumer::Run: Value at shared resource: %d\n", *__pShared);
 *    			if (*__pShared == 5)
 *    			{
 *    				break;
 *    			}
 *
 *    			// Waits for a notification
 *    			r = __pMonitor->Wait();
 *    			if (IsFailed(r))
 *    			{
 *    				goto CATCH1;
 *    			}
 *    		}
 *
 *  	CATCH1:
 *    		// Exits the monitor
 *    		r = __pMonitor->Exit();
 *   	}
 *
 *  CATCH2:
 *    	return null;
 *  }
 *
 *  void
 *  MyApp::TestProducerConsumer(void)
 *  {
 *    	result r = E_SUCCESS;
 *    	Monitor* pMonitor = null;
 *    	int* pShared = null;
 *
 *    	pMonitor = new Monitor;
 *    	if (pMonitor)
 *    	{
 *    		r = pMonitor->Construct();
 *    		if (IsFailed(r))
 *    		{
 *    			AppLog("Failed at Monitor Construct\n");
 *    			goto CATCH;
 *    		}
 *
 *    		pShared = new int;
 *    		if (pShared)
 *    		{
 *    			Producer producer(pShared, pMonitor);
 *    			Consumer consumer(pShared, pMonitor);
 *
 *    			producer.Construct();
 *    			consumer.Construct();
 *
 *    			producer.Start();
 *    			consumer.Start();
 *
 *    			producer.Join();
 *    			consumer.Join();
 *    		}
 *    	}
 *
 *  CATCH:
 *    	delete pShared;
 *    	delete pMonitor;
 *  }
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ Monitor
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @remarks	After creating an instance of this class, one of the
	 *			Construct() methods must be called explicitly to initialize this instance.
	 */
	Monitor(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~Monitor(void);


	/**
	 * Initializes this instance of %Monitor.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Acquires a lock for a monitor. @n
	 * Semantically, this method declares the beginning of the critical region for the monitor. This region
	 * ends with the Exit() method.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful in acquiring the lock.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		This method will block if called on already locked monitor object until monitor becomes availalbe.
	 * @see			Exit()
	 */
	result Enter(void);


	/**
	 * Releases a lock for a monitor. @n
	 * Semantically, it declares the ending of the critical region for the monitor that begins with
	 * the Enter() method.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful in releasing the lock.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		This method should be called only after acquiring lock by Enter() call
	 * @see			Enter()
	 */
	result Exit(void);

	/**
	 * Releases the lock for the monitor and waits for the notification from the other thread. @n
	 * After receiving the notification, it tries to acquire the lock.
	 * Semantically, it waits until the other thread notifies it.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		This method should be called only after acquiring lock by Enter() call
	 * @see			Notify()
	 * @see			NotifyAll()
	 */
	result Wait(void);

	/**
	 * Notifies one of the waiting threads. @n
	 * The selection of the notified thread is determined by the Linux scheduling policy.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @see			NotifyAll()
	 * @see			Wait()
	 */
	result Notify(void);


	/**
	 * Notifies all waiting threads.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @see			Notify()
	 * @see			Wait()
	 */
	result NotifyAll(void);

private:
	Monitor(const Monitor& rhs);
	Monitor& operator =(const Monitor& rhs);

private:
	friend class _MonitorImpl;
	class _MonitorImpl * __pMonitorImpl;
}; // Monitor

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_MONITOR_H_
