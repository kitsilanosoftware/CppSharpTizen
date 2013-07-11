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

/*
 * @file	FBaseRtWaitingLoop.h
 * @brief	This is the header file for the %WaitingLoop class.
 *
 * This file contains the declarations of the %WaitingLoop class.
 */

#ifndef _FBASE_RT_WAITING_LOOP_H_
#define _FBASE_RT_WAITING_LOOP_H_

#include <FBaseObject.h>
#include <FBaseRtIWaitingLoopCondition.h>

namespace Tizen { namespace Base { namespace Runtime
{

class IWaitingLoopCondition;
/*
 * @class WaitingLoop
 * @brief This class allows developers to make the current thread wait for callback events. This class should be used only for test codes and don't use this class for commercial applications
 * @since 2.0
 *
 * @final This class is not intended for extension.
 */
class _OSP_EXPORT_ WaitingLoop
	: public Tizen::Base::Object
{
public:
	/*
	 * Gets the WaitingLoop instance.
	 *
	 * @since 2.0
	 *
	 * @return      A pointer to the WaitingLoop instance, @n
	 *				else @c null if it fails   
     	 * @remarks Once the WaitingLoop instance has been created, you must not use the instance between threads. Especially, the methods for waiting should be called on the thread you get the instance at first time.
	 */
	static WaitingLoop* GetInstance(void);

	/*
	 * Starts the waiting loop and waits until the time is expired.
	 *
	 * @since 2.0
	 *
	 * @param[in] timeout	The timeout period in milliseconds  
	 * @exception E_SUCCESS    The method is successful.
	 * @exception E_TIMEOUT    The time is expired.
	 * @exception E_INVALID_STATE    The waiting loop has already been waiting on a callback event. In order to wait again, you must quit the waiting loop.
	 * @remarks The timeout set to min(timeout, maximum), where the maximum is set using SetMaxTimeoutForWaiting().
	 * @see Notify(), SetMaxTimoutForWaiting()
	 */
	result Wait(int timeout);

	/*
	 * Starts the waiting loop and waits until the specified condition is met.
	 *
	 * @since 2.0
	 *
	 * @param[in] condition	The expiring condition  
         * @exception E_SUCCESS    The method is successful.
         * @exception E_INVALID_STATE    The waiting loop has already been waiting on a callback event. In order to wait again, you must quit the waiting loop.
         * @remarks In order to use this method correctly, you have to implement a class inheriting from %IWaitingLoopCondition. 
	 */
	result Wait(IWaitingLoopCondition& condition);

	/*
	 * Starts the waiting loop and waits until either the expiring condition occurs or the time is expired.
	 *
	 * @since 2.0
	 *
	 * @param[in] timeout	The timeout period in milliseconds  
	 * @param[in] condition	The expiring condition  
	 * @exception E_TIMEOUT    The time is expired.
	 * @exception E_INVALID_STATE    The waiting loop is waiting on a thread. In order to wait again, you must quit the waiting loop.
	 * @remarks If the timeout is over the maximum, the expired time goes together with the maximum timeout. In order to use this method correctly, you have to implement a class inheriting from %IWaitingLoopCondition interface
	 */
	result Wait(int timeout, IWaitingLoopCondition& condition);

	/*
	 * Notify the waiting thread that the related callback has completed the job.
	 *
	 * @since 2.0
	 *
	 * @remarks This method is recommended to use when the waiting condition is not explicitly specified with Wait().
	 */
	void Notify(void);

	/*
	 * Sets the maximum timeout for waiting.
	 *
	 * @since 2.0
	 *
	 * @param[in] timeout    The timeout period in milliseconds
	 *				else @c false
	 * @remarks If the timeout is considered as a small number, it will be replaced with the specified number provided by platform.
	 */
	static void SetMaxTimeoutForWaiting(int timeout);

private:
	//
	// This default constructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since 2.0
	//
	WaitingLoop(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	WaitingLoop(const WaitingLoop& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and delcared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	WaitingLoop& operator =(const WaitingLoop& rhs);

	//
	// This destructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since 2.0
	//
	virtual ~WaitingLoop(void);

	friend class _WaitingLoopImpl;
	class _WaitingLoopImpl* __pWaitingLoopImpl;
}; // WaitingLoop

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_WAITING_LOOP_H_
