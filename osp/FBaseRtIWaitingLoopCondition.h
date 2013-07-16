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

/*
 * @file	FBaseRtIWaitingLoopCondition.h
 * @brief	This is the header file for the %IWaitingLoopCondition interface.
 *
 */
#ifndef _FBASE_RT_WAITING_LOOP_CONDITION_H_
#define _FBASE_RT_WAITING_LOOP_CONDITION_H_


namespace Tizen { namespace Base { namespace Runtime
{
/*
 * @interface IWaitingLoopCondition
 * @brief     This interface provides the method to check whether the WaitingLoopCondition is met.
 *
 * @since 2.0
 */
class _OSP_EXPORT_ IWaitingLoopCondition
{
public:
	/*
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IWaitingLoopCondition(void) {}

	/*
	 * Check whether the waiting loop condition is met
	 *
	 * @since 2.0
	 *
	 */
	virtual bool IsMet(void) = 0;

}; // IWaitingLoopCondition

} } } // Tizen::Runtime

#endif // _FBASE_RT_I_WAITING_LOOP_CONDITION_H_
