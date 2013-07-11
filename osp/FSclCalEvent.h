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
 * @file	FSclCalEvent.h
 * @brief	This is the header file for the %CalEvent class.
 *
 * This header file contains the declarations of the %CalEvent class.
 */
#ifndef _FSCL_CAL_EVENT_H_
#define _FSCL_CAL_EVENT_H_

#include <FBaseDataType.h>
#include <FBaseColIList.h>
#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FBaseDateTime.h>
#include <FLclCalendar.h>
#include <FSclTypes.h>
#include <FSclRecord.h>
#include <FSclRecurrence.h>
#include <FSclReminder.h>
#include <FSclAttendee.h>

namespace Tizen { namespace Locales
{
class TimeZone;
}}

namespace Tizen { namespace Social
{

/**
 *	@class	CalEvent
 *	@brief	This class provides methods to manage the information of a calendar book event.
 *
 * @since	2.0
 *
 *	@final	This class is not intended for extension.
 *
 *	The %CalEvent class describes an occasion planned in a particular situation. @n
 *	An event is a subset of vEvent. A %CalEvent instance includes the category, subject, description, start time, end time, location, and sensitivity.
 *	%CalEvent also includes the recurring and reminder data. For more information, see the Recurrence, and Reminder classes.
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/calevent.htm">Calendar Events</a>.
 *
 *	The following example demonstrates how to use the %CalEvent class.

 *	@code
 *
	#include <FSocial.h>
	#include <FLocales.h>

	using namespace Tizen::Base;
	using namespace Tizen::Social;
	using namespace Tizen::Locales;

	void
	CreateCalEventWithTimeZone(void)
	{
		DateTime startWallTime;
		DateTime endWallTime;
		DateTime startUtcTime;
		DateTime endUtcTime;

		// Suppose a user set 2010/2/17 12:00:00 ~ 2010/2/17 14:00:00 in wall time for start/end time
		startWallTime.SetValue(2010, 2, 17, 12, 0, 0);
		endWallTime.SetValue(2010, 2, 17, 14, 0, 0);

		// Gets the system time zone
		LocaleManager localeManager;
		localeManager.Construct();

		TimeZone timeZone = localeManager.GetSystemTimeZone();

		// Converts the wall time to UTC time before set start and end time of the event
		startUtcTime = timeZone.WallTimeToUtcTime(startWallTime);
		endUtcTime = timeZone.WallTimeToUtcTime(endWallTime);

		// Creates an event
		CalEvent event;

		// Sets the values
		event.SetTimeZone(timeZone);
		event.SetStartAndEndTime(startUtcTime, endUtcTime);
	}
 *
 * @endcode
 *
 */
class _OSP_EXPORT_ CalEvent
	: public Record
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CalEvent(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalEvent
	 */
	CalEvent(const CalEvent& rhs);

	/**
	 * This destructor overrides Tizen::Social::Record::~Record().
	 *
	 * @since	2.0
	 */
	virtual ~CalEvent(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %CalEvent instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %CalEvent instance, @n
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
	 * @if OSPDEPREC
	 * Checks whether this instance is a %CalEvent instance. @n
	 * A one-time calendar event has only one instance and a recurring calendar event has more than one instance. @n
	 * Each instance of %CalEvent has its own recurrence ID.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because %CalEvent class is not used for event instance any more. @n
	 * Instead of using the %CalEvent class, it is recommended to use the CalEventInstance class for event instance.
	 * @since	2.0
	 *
	 * @return		@c true if this instance is a %CalEvent instance, @n
	 *				else @c false
	 * @endif
	 */
	bool IsInstance(void) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the calendar event has a recurring pattern.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because %CalEvent class is not used for event instance any more. @n
	 * Instead of using the %CalEvent class, it is recommended to use the CalEventInstance class for event instance.
	 * @since	2.0
	 *
	 * @return		@c true if the calendar event has a recurring pattern, @n
	 *				else @c false
	 * @endif
	 */
	bool IsRecurring(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the original calendar event ID. @n
	 * The %CalEvent instance has an original @c CalEventId, that is a record ID of its entry.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because %CalEvent class is not used for event instance any more. @n
	 * Instead of using the %CalEvent class, it is recommended to use the CalEventInstance class for event instance.
	 * @since	2.0
	 *
	 * @return	The original calendar event ID, @n
	 *			else #INVALID_RECORD_ID if the record ID is invalid
	 * @endif
	 */
	RecordId GetOriginalCalEventId(void) const;

	/**
	 * Checks whether the calendar event is an all day event.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if calendar event is an all day event, @n
	 *				else @c false
	 */
	bool IsAllDayEvent(void) const;

	/**
	 * Sets the calendar event as an all day event.
	 *
	 * @since	2.0
	 *
	 * @param[in]	isAllDayEvent	Set to @c true to make the calendar event an all day event, @n
	 *								else @c false
	 */
	void SetAllDayEvent(bool isAllDayEvent);

	/**
	 * @if OSPDEPREC
	 * Gets the globally unique ID. @n
	 * UID: globally Unique Identifier (vCalendar 1.0)
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because string value can’t be handled. @n
	 * Instead of using this method, it is recommended to use GetUid().
	 * @since	2.0
	 *
	 * @return		The globally unique ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Tizen::Base::ByteBuffer* GetUIDN(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the globally unique ID. @n
	 * UID: globally Unique Identifier (vCalendar 1.0)
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because string value can’t be handled. @n
	 * Instead of using this method, it is recommended to use SetUid().
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	pUid					The globally unique ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @endif
	 */
	result SetUID(const Tizen::Base::ByteBuffer* pUid);

	/**
	 * Gets the globally unique ID. @n
	 * UID: globally Unique Identifier (vCalendar 1.0)
	 *
	 * @since	2.0
	 *
	 * @return		The globally unique ID
	 */
	Tizen::Base::String GetUid(void) const;

	/**
	 * Sets the globally unique ID. @n
	 * UID: globally Unique Identifier (vCalendar 1.0)
	 *
	 * @since	2.0
	 *
	 * @param[in]	uid					The globally unique ID
	 */
	void SetUid(const Tizen::Base::String& uid);

	/**
	 * Gets the calendar event status. @n
	 * The default status is #EVENT_STATUS_NONE.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar event status
	 * @see			EventStatus
	 */
	EventStatus GetStatus(void) const;

	/**
	 * Sets the calendar event status.
	 *
	 * @since	2.0
	 *
	 * @param[in]	status		The status
	 * @see			EventStatus
	 */
	void SetStatus(EventStatus status);

	/**
	 * Gets the busy status. @n
	 * The default busy status is #BUSY_STATUS_BUSY.
	 *
	 * @since	2.0
	 *
	 * @return		The busy status
	 * @see			BusyStatus
	 */
	BusyStatus GetBusyStatus(void) const;

	/**
	 * Sets the busy status.
	 *
	 * @since	2.0
	 *
	 * @param[in]	busyStatus		The busy status
	 * @see			BusyStatus
	 */
	void SetBusyStatus(BusyStatus busyStatus);

	/**
	 * Gets the priority level of the calendar event. @n
	 * The default priority level is #EVENT_PRIORITY_LOW.
	 *
	 * @since	2.0
	 *
	 * @return		The priority level
	 *
	 */
	EventPriority GetPriority(void) const;

	/**
	 * Sets the priority level of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @param[in]	priority	The priority level to set
	 *
	 */
	void SetPriority(EventPriority priority);

	/**
	 * Adds an attendee.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	attendee			The attendee to add @n
	 *									The specified @c attendee must have an email address.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	An attendee with the same email address already exists.
	 * @remarks		The attendee values may be lost if an anniversary event including the attendee is modified in the base application.
	 */
	result AddAttendee(const Attendee& attendee);

	/**
	 * Removes an attendee.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	attendee			The attendee to remove @n
	 *									The specified @c attendee must have an email address.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		An attendee that has the same email address is not found.
	 */
	result RemoveAttendee(const Attendee& attendee);

	/**
	 * Gets a list of all the attendees.
	 *
	 * @since	2.0
	 *
	 * @return		A list of the attendees
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Attendee
	 */
	Tizen::Base::Collection::IList* GetAllAttendeesN(void) const;

	/**
	 * Gets the time zone.
	 *
	 * @since	2.0
	 *
	 * @return		The time zone
	 * @see			Tizen::Locales::TimeZone
	 */
	Tizen::Locales::TimeZone GetTimeZone(void) const;

	/**
	 * Sets the time zone. @n
	 * Recurrence is calculated based on the time zone, thus the time zone must be set before setting a recurrence.
	 * If the time zone is not set, it will be considered as Greenwich Mean Time (GMT) 0.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	timeZone			The time zone to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @remarks		As anniversaries and all day events are not affected by a time zone, it is recommended not to set the time zone.
	 * @see			Tizen::Locales::TimeZone
	 */
	result SetTimeZone(const Tizen::Locales::TimeZone& timeZone);

	/**
	 * @if OSPDEPREC
	 * Gets the recurrence ID. @n
	 * This method works only for the %CalEvent instances.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because %CalEvent class is not used for event instance any more. @n
	 * Instead of using the %CalEvent class, it is recommended to use the CalEventInstance class for event instance.
	 * @since	2.0
	 *
	 * @return		The recurrence ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance is a %CalEvent instance that does not have a recurrence ID.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	RecurrenceId GetRecurrenceId(void) const;

	/**
	 * Gets the subject of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		The subject, @n
	 *				else @c null if there is no subject value
	 */
	Tizen::Base::String GetSubject(void) const;

	/**
	 * Gets the description of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		The description
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the start date and time of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		An instance of Tizen::Base::DateTime representing the start date and time
	 */
	Tizen::Base::DateTime GetStartTime(void) const;

	/**
	 * Gets the end date and time of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		An instance of Tizen::Base::DateTime representing the end date and time
	 */
	Tizen::Base::DateTime GetEndTime(void) const;

	/**
	 * Gets the location of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		The location
	 */
	Tizen::Base::String GetLocation(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the category of the calendar event.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because the category of event is not used any more.
	 * @since	2.0
	 *
	 * @return		The category of the calendar event
	 * @endif
	 */
	EventCategory GetCategory(void) const;

	/**
	 * Gets the sensitivity of the calendar event. @n
	 * The default value is #SENSITIVITY_PUBLIC.
	 *
	 * @since	2.0
	 *
	 * @return		The sensitivity of the calendar event
	 */
	RecordSensitivity GetSensitivity(void) const;


	/**
	 * @if OSPDEPREC
	 * Gets the reminder for the calendar event.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated		This method is deprecated. Instead of using this method, it is recommended to use GetAllReminders().
	 * @since	2.0
	 *
	 * @return		A pointer to an instance of Reminder, @n
	 *				else @c null if the reminder is not set
	 * @endif
	 */
	const Reminder* GetReminder(void) const;

	/**
	 * Gets the recurrence of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to an instance of Recurrence, @n
	 *				else @c null if the event is not a recurring event
	 */
	const Recurrence* GetRecurrence(void) const;

	/**
	 * Gets the last updated date and time of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		The last updated date and time
	 */
	Tizen::Base::DateTime GetLastRevisedTime(void) const;

	/**
	 * Sets the subject of the calendar event.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompCalEventSetSubjectPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	subject				The subject of the calendar event
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetSubject(const Tizen::Base::String& subject);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalEventSetSubjectPage Compatibility for SetSubject()
	 * @section	CompCalEventSetSubjectPageIssueSection Issues
	 *          Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# If the length of the subject to be set is greater than 100 characters, E_INVALID_ARG is returned.
	 *
	 * @section	CompCalEventSetSubjectPageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 * 			-# There is no limit for the length of the subject.
	 * @endif
	 */

	/**
	 * Sets the description of the current calendar event.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompCalEventSetDescriptionPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	description			The description of the event
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetDescription(const Tizen::Base::String& description);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalEventSetDescriptionPage Compatibility for SetDescription()
	 * @section	CompCalEventSetDescriptionPageIssueSection Issues
	 *          Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# If the length of the description to be set is greater than 1000 characters, E_INVALID_ARG is returned.
	 *
	 * @section	CompCalEventSetDescriptionPageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 * 			-# There is no limit for the length of the description.
	 * @endif
	 */

	/**
	 * Sets the start and end date and time of the calendar event. @n
	 * If the start date and time is not fixed, the default date and time are set. @n
	 * The default start date and time is the current date and time. @n
	 * The start date and time must be earlier than or equal to the end date and time. @n
	 * If the recurrence date is already set, this method returns an exception.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	startDateTime				The start date and time
	 * @param[in]	endDateTime					The end date and time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c endDateTime value is earlier than the specified @c startDateTime value.
	 *										- The @c startDateTime or @c endDateTime is not in a valid range. @n
	 *										The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_INVALID_CONDITION	The recurrence date is already set.
	 * @remarks		The start and end time of all day events created from the base applications is the local time of the location where
	 *				they are added.
	 *				All the other events are Coordinated Universal Time (UTC).
	 *				In order to integrate it with the base applications, set the start and end time properly according to the above guidelines.
	 *				If the seconds value of the start time is set, the alarm will not be fired.
	 *				There is no automatic time conversion based on the time zone property of the calendar event.
	 */
	result SetStartAndEndTime(const Tizen::Base::DateTime& startDateTime, const Tizen::Base::DateTime& endDateTime);

	/**
	 * Sets the location of the current calendar event.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompCalEventSetLocationPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	location			The location of the event
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetLocation(const Tizen::Base::String& location);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalEventSetLocationPage Compatibility for SetLocation()
	 * @section	CompCalEventSetLocationPageIssueSection Issues
	 *          Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# If the length of the location to be set is greater than 100 characters, E_INVALID_ARG is returned.
	 *
	 * @section	CompCalEventSetLocationPageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 * 			-# There is no limit for the length of the location.
	 * @endif
	 */

	/**
	 * @if OSPDEPREC
	 * @{
	 * Sets the category of the calendar event. @n
	 * If the category is not set, the default category (#EVENT_CATEGORY_APPOINTMENT) is set.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Deprecated] [Compatibility] </i>
	 * @endif
	 * @deprecated	This method is deprecated because the category of event is not used any more.
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 * 					For more information, see @ref CompCalEventSetCategoryPage "here".
	 * @endif
	 *
	 * @param[in]	category			The category of the event
	 * @remarks		The start and end time of the anniversary and all day events created from the base applications, is the local time of the location where
	 *				they are added.
	 *				All the other events are Coordinated Universal Time (UTC).
	 *				In order to integrate it with the base applications, set the start and end time properly according to the above guidelines.
	 * @}
	 * @endif
	 */
	void SetCategory(EventCategory category);

	/**
	 * @if OSPCOMPAT
	 * @page		CompCalEventSetCategoryPage		Compatibility for SetCategory()
	 * @section		CompCalEventSetCategoryPageIssueSection Issues
	 * 				Implementing this method in OSP compatible applications has the following issues:   @n
	 *
	 *	-# When the anniversary category is set to the event, it's handled as all day event even though the all day event property is not set.
	 *
	 * @section		CompCalEventSetCategoryPageSolutionSection Resolutions
	 *
	 * This issue has been resolved in Tizen.  @n
	 *  -# The category property is deprecated and it's not used any more.
	 *  In Tizen, the all day event property will be set simultaneously when the anniversary category is set to the event.
	 *  If an application tries to change the all day event property of the anniversary event to @c false, it will not be changed.
	 * @endif
	 */

	/**
	 * Sets the sensitivity of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @param[in]	sensitivity		The sensitivity of the calendar event
	 */
	void SetSensitivity(RecordSensitivity sensitivity);

	/**
	 * Sets the coordinates.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	latitude		The latitude in the range @n The valid range is [-90.0, 90.0].
	 * @param[in]	longitude		The longitude in the range @n The valid range is [-180.0, 180.0].
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The @c latitude or @c longitude is out of the valid range.
	 */
	result SetCoordinates(double latitude, double longitude);

	/**
	 * Gets the coordinates.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[out]	latitude		The latitude
	 * @param[out]	longitude		The longitude
	 */
	void GetCoordinates(double& latitude, double& longitude) const;

	/**
	 * @if OSPDEPREC
	 * Sets the reminder of the calendar event.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated		This method is deprecated. Instead of using this method, it is recommended to use AddReminder() and RemoveReminderAt().
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	pReminder				The reminder to set, @n
	 *										else @c null to remove the previous reminder
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @endif
	 */
	result SetReminder(const Reminder* pReminder);

	/**
	 * Sets the recurrence of the calendar event. @n
	 * The recurrence rule date must be equal to the start date of the event. @n
	 * If the event start date is different than the recurrence rule date, the event start date is set to match the recurrence rule date. @n
	 * For example, if an event start date is 17/02/2010, that is Wednesday and the recurrence rule date is Thursday of every week,
	 * the event start date changes to 18/02/2010, after this method is called. @n
	 * Note that the start/end date and the time zone must be set before setting a recurrence.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                For more information, see @ref CompCalEventSetRecurrencePage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	pRecurrence				The recurrence to set, @n
	 *										else @c null to remove the previous recurrence
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The current event is a %CalEvent instance that has a recurrence ID.
	 * @exception	E_INVALID_CONDITION		Either of the following conditions has occurred: @n
	 *										- The recurrence rule date is earlier than the start date and time of the event. @n
	 *										- The recurrence rule is invalid. @n
	 *										- The duration of the event is too long. @n
	 *										It must be shorter than the (interval x frequency) days set for the recurrence rule.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- When the frequency is #FREQ_WEEKLY, DayOfWeek is not set. @n
	 *										- When the frequency is #FREQ_MONTHLY, neither DayOfMonth nor DayOfWeek and WeekOfMonth are not set. @n
	 *										- When the frequency is #FREQ_YEARLY, neither DayOfMonth and MonthOfYear nor DayOfWeek,
	 *										WeekOfMonth and MonthOfYear are not set. @n
	 *										- When the frequency is #FREQ_YEARLY and MonthOfYear is 2, DayOfMonth is greater than 29 ( > 29 ). @n
	 *										- When the frequency is #FREQ_YEARLY and MonthOfYear is 4 or 6 or 9 or 11,
	 *										DayOfMonth is greater than 30 ( > 30 ).
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		If the until property of the recurrence is set with too distant future from the event's start date, @n
	 * 				too many recurring events are generated. It is the same when the value of recurrence count is big. @n
	 * 				The system limits the count of the recurring events that are generated by recurrence rule of an event. @n
	 * 				In this case, some recurring events that exceed the system limitation cannot be retrieved.
	 *
	 * The following example demonstrates how to use the %SetRecurrence() method.
	 * @code
		MyClass::SetEventRecurrence(void)
		{
			result r = E_SUCCESS;
			Recurrence* pRecurrence = new Recurrence();

			pRecurrence->SetFrequency(FREQ_WEEKLY);
			pRecurrence->SetDayOfWeek(CAL_MONDAY);

			r = __pCalEvent->SetRecurrence(pRecurrence);

			delete pRecurrence;
		}
	 * @endcode
	 */
	result SetRecurrence(const Recurrence* pRecurrence);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalEventSetRecurrencePage Compatibility for SetRecurrence()
	 * @section	CompCalEventSetRecurrencePageIssueSection Issues
	 *           Implementing this method in OSP compatible applications has the following issues:   @n
	 *			- If the category is anniversary and the frequency of recurrence is not yearly, E_TYPE_MISMATCH exception is occurred. @n
	 *			Yearly frequency is only accepted for anniversary category.
	 *
	 * @section	CompCalEventSetRecurrencePageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 *			-# All recurrence frequency will be accepted because the category of event is not used any more.
	 * @endif
	 */

	/**
	 * Adds a reminder.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	reminder			The reminder to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result AddReminder(const Reminder& reminder);

	/**
	 * Removes a reminder at the index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The index of reminder to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The index is either equal to or greater than the number of reminders or less than @c 0.
	 */
	result RemoveReminderAt(int index);

	/**
	 * Gets a list of all the reminders.
	 *
	 * @since	2.0
	 *
	 * @return		A list containing the Reminder instances, @n
	 *				else an empty list if there are no reminders
	 */
	const Tizen::Base::Collection::IList& GetAllReminders(void) const;

	/**
	 * Gets the ID of the calendar to which this event belongs.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar Id
	 */
	RecordId GetCalendarId(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalEvent
	 */
	CalEvent& operator =(const CalEvent& rhs);

private:
	friend class _CalEventImpl;
	class _CalEventImpl* __pCalEventImpl;
};	// CalEvent

}}	// Tizen::Social

#endif // _FSCL_CAL_EVENT_H_
