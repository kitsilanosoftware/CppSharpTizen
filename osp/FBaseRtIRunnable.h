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
 * @file		FBaseRtIRunnable.h
 * @brief		This is the header file for the %IRunnable interface.
 *
 * This header file contains the declarations of the %IRunnable interface.
 */
#ifndef _FBASE_RT_I_RUNNABLE_H_
#define _FBASE_RT_I_RUNNABLE_H_

#include <FBaseResult.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base { namespace Runtime
{
/**
 * @interface IRunnable
 * @brief	This interface is the basic unit of the task. Also, it is the execution unit of
 *          the thread. This interface must be inherited by the class whose instances will
 *		    run on the thread.
 *
 * @since 2.0
 *
 * @remarks	Classes which inherit the %IRunnable interface must implement the Run() method.
 *
 * The %IRunnable interface is the basic unit of the task. Also, it is the execution unit of
 * the thread. This interface must be inherited by the class whose instances will
 * run on the thread.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/thread_programming.htm">Thread Programming</a>.
 *
 * @see		Thread
 *
 * The following example demonstrates how to use the %IRunnable interface.
 *
 * @code
 *
 *		#include <FBase.h>
 *
 *      using namespace Tizen::Base;
 *      using namespace Tizen::Base::Runtime;
 *
 *		class MyRun
 *			: public Tizen::Base::Object
 *			, public Tizen::Base::Runtime::IRunnable
 *		{
 *		public:
 *			Object* Run(void)
 *			{
 *				for (int i = 0; i < 10000; ++i)
 *				{
 *					// ...
 *				}
 *
 *				return null;
 *			}
 *		}
 *
 * @endcode
 *
 *
 *
 */
class _OSP_EXPORT_ IRunnable
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~IRunnable(void);

	/**
	 * Runs the task. @n
	 * This method is an executable body of the task. In many cases, this method is called by the thread.
	 * Although this method can return the result of the execution, the returned value might be discarded
	 * by the executor of this task.
	 *
	 * @since 2.0
	 *
	 * @return	A pointer to the result of the task, @n
	 *			else @c null
	 */
	virtual Tizen::Base::Object* Run(void) = 0;
}; // IRunnable

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_I_RUNNABLE_H_
