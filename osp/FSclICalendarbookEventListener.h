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
 * @file		FSclICalendarbookEventListener.h
 * @brief		This is the header file for the %ICalendarbookEventListener interface.
 *
 * This header file contains the declarations of the %ICalendarbookEventListener interface.
 */
#ifndef _FSCL_ICALENDARBOOK_EVENT_LISTENER_H_
#define _FSCL_ICALENDARBOOK_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Social
{

/**
 * @interface	ICalendarbookEventListener
 * @brief		This interface provides a listener that receives the events associated with the calendarbook.
 *
 * @since	2.0
 *
 * The %ICalendarbookEventListener interface provides a listener that receives the events associated with the calendarbook.
 */
class _OSP_EXPORT_ ICalendarbookEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ICalendarbookEventListener(void) {}

	/**
	 * Called to notify when the calendar events are changed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	eventChangeInfoList		The list of changed event information represented by CalEventChangeInfo
	 */
	virtual void OnCalendarEventsChanged(const Tizen::Base::Collection::IList& eventChangeInfoList) = 0;

	/**
	 * Called to notify when the calendar to-dos are changed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	todoChangeInfoList		The list of changed to-do information represented by CalTodoChangeInfo
	 */
	virtual void OnCalendarTodosChanged(const Tizen::Base::Collection::IList& todoChangeInfoList) = 0;
	
protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ICalendarbookEventListener_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ICalendarbookEventListener_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ICalendarbookEventListener_Reserved3(void) { }

};	// ICalendarbookEventListener

}}	// Tizen::Social

#endif // _FSCL_ICALENDARBOOK_EVENT_LISTENER_H_
