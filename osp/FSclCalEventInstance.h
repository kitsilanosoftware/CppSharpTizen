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
 * @file	FSclCalEventInstance.h
 * @brief	This is the header file for the %CalEventInstance class.
 *
 * This header file contains the declarations of the %CalEventInstance class.
 */
#ifndef _FSCL_CAL_EVENT_INSTANCE_H_
#define _FSCL_CAL_EVENT_INSTANCE_H_

#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;
class DateTime;
}}

namespace Tizen { namespace Social
{

/**
 * @class	CalEventInstance
 * @brief	This class represents the instance of calendar book event.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %CalEventInstance class represents the instance of calendar book event.
 */
class _OSP_EXPORT_ CalEventInstance
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CalEventInstance(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalEventInstance
	 */
	CalEventInstance(const CalEventInstance& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~CalEventInstance(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %CalEventInstance instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %CalEventInstance instance, @n
	 else @c false
	 * @param[in]	rhs	The object instance to compare with the calling object
	 * @see			GetHashCode()
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the original event ID.
	 *
	 * @since	2.0
	 *
	 * @return		The original event ID
	 */
	RecordId GetOriginalEventId(void) const;

	/**
	 * Gets the calendar ID.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar ID
	 */
	RecordId GetCalendarId(void) const;

	/**
	 * Gets the start time.
	 *
	 * @since	2.0
	 *
	 * @return		The start time
	 */
	Tizen::Base::DateTime GetStartTime(void) const;

	/**
	 * Gets the end time.
	 *
	 * @since	2.0
	 *
	 * @return		The end time
	 */
	Tizen::Base::DateTime GetEndTime(void) const;

	/**
	 * Gets the subject.
	 *
	 * @since	2.0
	 *
	 * @return		The subject
	 */
	Tizen::Base::String GetSubject(void) const;

	/**
	 * Gets the description.
	 *
	 * @since	2.0
	 *
	 * @return		The description
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the location.
	 *
	 * @since	2.0
	 *
	 * @return		The location
	 */
	Tizen::Base::String GetLocation(void) const;

	/**
	 * Checks whether the original event of this instance is an all day event.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the original event of this instance is an all day event, @n
	 *				else @c false
	 */
	bool IsAllDayEvent(void) const;

	/**
	 * Gets the busy status.
	 *
	 * @since	2.0
	 *
	 * @return		The busy status
	 */
	BusyStatus GetBusyStatus(void) const;

	/**
	 * Gets the event status.
	 *
	 * @since	2.0
	 *
	 * @return		The event status
	 */
	EventStatus GetStatus(void) const;

	/**
	 * Gets the priority.
	 *
	 * @since	2.0
	 *
	 * @return		The priority
	 */
	EventPriority GetPriority(void) const;

	/**
	 * Gets the sensitivity.
	 *
	 * @since	2.0
	 *
	 * @return		The sensitivity
	 */
	RecordSensitivity GetSensitivity(void) const;

	/**
	 * Checks whether the event instance has a recurring pattern.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the event instance has a recurring pattern, @n
	 *				else @c false
	 */
	bool IsRecurring(void) const;

	/**
	 * Checks whether the event instance has reminders.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the event instance has reminders, @n
	 *				else @c false
	 */
	bool HasReminder(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalEventInstance
	 */
	CalEventInstance& operator =(const CalEventInstance& rhs);

private:
	friend class _CalEventInstanceImpl;
	class _CalEventInstanceImpl* __pCalEventInstanceImpl;
}; // CalEventInstance

}} // Tizen::Social

#endif // _FSCL_CAL_EVENT_INSTANCE_H_

