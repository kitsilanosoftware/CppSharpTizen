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
 * @file	FSysIAlarmEventListener.h
 * @brief	This is the header file for the %IAlarmEventListener interface.
 *
 * This header file contains the declarations of the %IAlarmEventListener interface.
 */

#ifndef _FSYS_IALARM_EVENT_LISTENER_H_
#define _FSYS_IALARM_EVENT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace System
{

class AlarmEvent;
class Alarm;

/**
 * @interface	IAlarmEventListener
 * @brief	This interface is the listener of the alarm event.
 *
 * @since	2.0
 *
 * The %IAlarmEventListener interface must be registered and implemented by an application to receive alarm events from the system.
 *
 */
class _OSP_EXPORT_ IAlarmEventListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class. This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAlarmEventListener(void) {}

	/**
	 * Called when the alarm expires.
	 *
	 * @since	2.0
	 *
	 * @param[in]	alarm	The alarm that expires
	 */
	virtual void OnAlarmExpired(Alarm& alarm) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void OnIAlarmEventListener_Reserved1(void) {};

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	virtual void OnIAlarmEventListener_Reserved2(void) {};

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	virtual void OnIAlarmEventListener_Reserved3(void) {};

}; // IAlarmEventListener

} } // Tizen::System

#endif // _FSYS_IALARM_EVENT_LISTENER_H_
