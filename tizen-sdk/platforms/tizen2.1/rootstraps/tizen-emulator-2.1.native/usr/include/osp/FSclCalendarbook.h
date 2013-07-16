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
 * @file		FSclCalendarbook.h
 * @brief		This is the header file for the %Calendarbook class.
 *
 * This header file contains the declarations of the %Calendarbook class.
 */
#ifndef _FSCL_CALENDARBOOK_H_
#define _FSCL_CALENDARBOOK_H_

#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FSclTypes.h>
#include <FSclCalEvent.h>
#include <FSclCalTodo.h>
#include <FSclIRecordEventListener.h>
#include <FSclIRecordListener.h>

namespace Tizen { namespace Base
{
class String;
class DateTime;
namespace Collection
{
class IList;
}
}}

namespace Tizen { namespace Locales
{
class TimeZone;
}}


namespace Tizen { namespace Social
{

class ICalendarbookEventListener;
class Calendar;
class CalEventInstance;
class CalendarbookFilter;

/**
 * @class	Calendarbook
 * @brief	This class manages the calendar data such as events, to-dos, and calendars.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Calendarbook class manages the calendar data such as events, to-dos, and calendars.
 * The calendar book is a centralized database that is used by multiple applications to store events and to-do information.
 * A calendar book represents the methods to read, add, remove, and update the events, to-do lists, and calendars stored in the device.
 * The users must be notified of changes in the calendar book as multiple applications can share, change, or remove the data.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/calendarbook_namespace.htm">Calendar book</a>.
 *
 * The following example demonstrates how to use the %Calendarbook class to add calendarbook event.
 * @code

	#include <FSocial.h>
	#include <FLocales.h>

	using namespace Tizen::Social;
	using namespace Tizen::Base;
	using namespace Tizen::Locales;

	void
	MyCalendarbook::AddEventExample(void)
	{
		result r = E_SUCCESS;

		DateTime startWallTime;
		DateTime endWallTime;
		DateTime startUtcTime;
		DateTime endUtcTime;

		// Suppose a user set 2012/7/17 12:00:00 ~ 2012/7/17 14:00:00 in wall time for start/end time
		startWallTime.SetValue(2012, 7, 17, 12, 0, 0);
		endWallTime.SetValue(2012, 7, 17, 14, 0, 0);

		// Gets the system time zone
		LocaleManager localeManager;
		localeManager.Construct();

		TimeZone timeZone = localeManager.GetSystemTimeZone();

		// Converts the wall time to UTC time before set start and end time of the event
		startUtcTime = timeZone.WallTimeToUtcTime(startWallTime);
		endUtcTime = timeZone.WallTimeToUtcTime(endWallTime);

		// Creates a CalEvent instance
		CalEvent newEvent;
		newEvent.SetSubject(L"Daily event");
		newEvent.SetStartAndEndTime(startUtcTime, endUtcTime);

		Recurrence dailyRecurrence;
		dailyRecurrence.SetFrequency(FREQ_DAILY);
		dailyRecurrence.SetCounts(10);

		newEvent.SetRecurrence(&dailyRecurrence);

		// Creates a Calendarbook instance
		Calendarbook* pCalendarbook = new Calendarbook();
		r = pCalendarbook->Construct();
		if (IsFailed(r))
		{
			AppLogException("initializing the calendar book has failed");
			delete pCalendarbook;
			return;
		}

		// Adds the event
		r = pCalendarbook->AddEvent(newEvent);
		if (IsFailed(r))
		{
			AppLogException("AddEvent() has failed");
			delete pCalendarbook;
			return;
		}

		delete pCalendarbook;
	}

 * @endcode
 *
 * The following example demonstrates how to use the %Calendarbook class to update calendarbook event.
 * @code

	#include <FSocial.h>
	#include <FLocales.h>

	using namespace Tizen::Social;
	using namespace Tizen::Base;
	using namespace Tizen::Locales;

	void
	MyCalendarbook::UpdateEventExample(void)
	{
		result r = E_SUCCESS;

		// This specificEventId should have been set as already added event record ID.
		RecordId specificEventId = 0;

		DateTime changedStartWallTime;
		DateTime changedEndWallTime;
		DateTime changedStartUtcTime;
		DateTime changedEndUtcTime;

		// Suppose a user set 2012/7/18 12:00:00 ~ 2012/7/18 14:00:00 in wall time for start/end time.
		changedStartWallTime.SetValue(2012, 7, 18, 12, 0, 0);
		changedEndWallTime.SetValue(2012, 7, 18, 14, 0, 0);

		// Gets the system time zone.
		LocaleManager localeManager;
		localeManager.Construct();

		TimeZone timeZone = localeManager.GetSystemTimeZone();

		// Converts the wall time to UTC time before set start and end time of the event.
		changedStartUtcTime = timeZone.WallTimeToUtcTime(changedStartWallTime);
		changedEndUtcTime = timeZone.WallTimeToUtcTime(changedEndWallTime);

		// Creates Calendarbook instance.
		Calendarbook* pCalendarbook = new Calendarbook();
		r = pCalendarbook->Construct();
		if (IsFailed(r))
		{
			AppLogException("initializing the calendar book has failed");
			delete pCalendarbook;
			return;
		}

		// Retrieves CalEvent instance.
		CalEvent* pEvent = pCalendarbook->GetEventN(specificEventId);
		if (pEvent == null)
		{
			AppLogException("Getting the event has failed");
			delete pCalendarbook;
			return;
		}

		Recurrence recurrence(*pEvent->GetRecurrence());
		pEvent->SetRecurrence(null);
		pEvent->SetStartAndEndTime(changedStartUtcTime, changedEndUtcTime);
		pEvent->SetRecurrence(&recurrence);

		// Updates the event.
		r = pCalendarbook->UpdateEvent(*pEvent);
		if (IsFailed(r))
		{
			AppLogException("UpdateEvent() has failed");
			delete pEvent;
			delete pCalendarbook;
			return;
		}

		delete pEvent;
		delete pCalendarbook;
	}

 * @endcode
 *
 * The following example demonstrates how to use the %Calendarbook class to retrieve event instance list.
 * @code

	#include <FSocial.h>
	#include <FLocales.h>

	using namespace Tizen::Social;
	using namespace Tizen::Base;
	using namespace Tizen::Locales;
	using namespace Tizen::Base::Collection;

	void
	MyCalendarbook::RetrieveEventInstanceExample(void)
	{
		result r = E_SUCCESS;

		DateTime startRange;
		DateTime endRange;
		IList* pEventInstanceList = null;

		DateTime startRangeWallTime;
		DateTime endRangeWallTime;
		DateTime startRangeUtcTime;
		DateTime endRangeUtcTime;

		// Suppose a user set 2012/7/1 00:00:00 ~ 2012/7/31 23:59:59 in wall time for start/end time.
		startRangeWallTime.SetValue(2012, 7, 1, 0, 0, 0);
		endRangeWallTime.SetValue(2012, 7, 31, 23, 59, 59);

		// Gets the system time zone.
		LocaleManager localeManager;
		localeManager.Construct();

		TimeZone timeZone = localeManager.GetSystemTimeZone();

		// Converts the wall time to UTC time before set start and end time of the event.
		startRangeUtcTime = timeZone.WallTimeToUtcTime(startRangeWallTime);
		endRangeUtcTime = timeZone.WallTimeToUtcTime(endRangeWallTime);

		// Creates Calendarbook instance.
		Calendarbook* pCalendarbook = new Calendarbook();
		r = pCalendarbook->Construct();
		if (IsFailed(r))
		{
			AppLogException("initializing the calendar book has failed");
			delete pCalendarbook;
			return;
		}

		// Gets the event instances.
		CalendarbookFilter filter(CB_FI_TYPE_NON_ALL_DAY_EVENT_INSTANCE);
		filter.AppendDateTime(FI_CONJ_OP_NONE, EVENT_INST_FI_PR_END_TIME, FI_CMP_OP_GREATER_THAN, startRangeUtcTime);
		filter.AppendDateTime(FI_CONJ_OP_AND, EVENT_INST_FI_PR_START_TIME, FI_CMP_OP_LESS_THAN, endRangeUtcTime);

		pEventInstanceList = pCalendarbook->SearchN(filter, EVENT_INST_FI_PR_START_TIME, SORT_ORDER_ASCENDING);
		if (pEventInstanceList == null)
		{
			AppLogException("SearchN() is failed");
			delete pCalendarbook;
			return;
		}

		IEnumerator* pEnum = pEventInstanceList->GetEnumeratorN();
		while (pEnum->MoveNext() == E_SUCCESS)
		{
			CalEventInstance* pEventInstance = static_cast<CalEventInstance*>(pEnum->GetCurrent());

			// Reads the properties of pEventInstance.
			// ...
		}
		delete pEnum;

		// Removes the first event instance of the list.
		CalEventInstance* pExcludingEventInstance = static_cast<CalEventInstance*>(pEventInstanceList->GetAt(0));
		r = pCalendarbook->RemoveEventInstance(*pExcludingEventInstance);
		if (IsFailed(r))
		{
			AppLogException("RemoveEventInstance() has failed");
			pEventInstanceList->RemoveAll(true);
			delete pEventInstanceList;
			delete pCalendarbook;
			return;
		}

		pEventInstanceList->RemoveAll(true);
		delete pEventInstanceList;
		delete pCalendarbook;
	}

 * @endcode
 */

class _OSP_EXPORT_ Calendarbook
	: public Tizen::Base::Object
{
public:

	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	Calendarbook(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Calendarbook(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %Calendarbook with the specified event listener.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use Construct(ICalendarbookEventListener*).
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	pListener				The event listener to register, @n
	 *										else @c null if an event listener need not be registered
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @endif
	 */
	result Construct(IRecordEventListener* pListener);

	/**
	 * Initializes this instance of %Calendarbook.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %Calendarbook with the specified event listener.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	listener				The event listener to register
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result Construct(ICalendarbookEventListener& listener);

	/**
	 * Adds an event of the default calendar to the calendar book. @n
	 * After adding the event successfully, the event has a valid record ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in,out]	event					The event to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c event is invalid.
	 * @exception	E_STORAGE_FULL			The storage is insufficient.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddEvent(CalEvent& event);

	/**
	 * Adds an event of the specific calendar to the calendar book. @n
	 * After adding the event successfully, the event has a valid record ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in,out]	event					The event to add
	 * @param[in]	calendarId				The calendar ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c event is invalid. @n
	 *										- The specified @c calendarId is invalid. @n
	 *										- The specified calendar is created for CALENDAR_ITEM_TYPE_TODO.
	 * @exception	E_OBJ_NOT_FOUND			The specified calendar is not found.
	 * @exception	E_STORAGE_FULL			The storage is insufficient.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddEvent(CalEvent& event, RecordId calendarId);

	/**
	 * Adds a to-do of the default calendar to the calendar book. @n
	 * After adding the to-do item successfully, the item has a valid record ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in,out]	todo					The to-do to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c todo is invalid.
	 * @exception	E_STORAGE_FULL			The storage is insufficient.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddTodo(CalTodo& todo);

	/**
	 * Adds a to-do of the specific calendar to the calendar book. @n
	 * After adding the to-do item successfully, the item has a valid record ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in,out]	todo					The to-do to add
	 * @param[in]	calendarId				The calendar ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 										- The specified @c todo is invalid. @n
	 * 										- The specified @c calendarId is invalid. @n
	 * 										- The specified calendar is created for CALENDAR_ITEM_TYPE_EVENT.
	 * @exception	E_OBJ_NOT_FOUND			The specified calendar is not found.
	 * @exception	E_STORAGE_FULL			The storage is insufficient.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddTodo(CalTodo& todo, RecordId calendarId);

	/**
	 * Removes the specified calendar event from this calendar book. @n
	 * After removing the event successfully, the event has #INVALID_RECORD_ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	event				The calendar event to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c recordId is #INVALID_RECORD_ID.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception   E_INVALID_OPERATION		This method cannot be used for the recurrence exception of the recurring event. @n
	 * 										RemoveEventInstance() should be used instead of this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result RemoveEvent(CalEvent& event);

	/**
	 * Removes the specified calendar event from this calendar book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	eventId					The calendar event ID to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c eventId is #INVALID_RECORD_ID.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception   E_INVALID_OPERATION		This method cannot be used for the recurrence exception of the recurring event. @n
	 * 										RemoveEventInstance() should be used instead of this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result RemoveEvent(RecordId eventId);

	/**
	 * Removes the specified CalTodo instance from the calendar book. @n
	 * After removing the to-do item successfully, the item has #INVALID_RECORD_ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	todo					The CalTodo ID to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c recordId is #INVALID_RECORD_ID.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result RemoveTodo(CalTodo& todo);

	/**
	 * Removes the specified CalTodo instance from the calendar book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	todoId					The CalTodo ID to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result RemoveTodo(RecordId todoId);

	/**
	 * Updates the specified calendar event to the internal data storage.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	event				The CalEvent instance to update
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c recordId is #INVALID_RECORD_ID. @n
	 *										- The specified @c event is not #RECORD_TYPE_EVENT. @n
	 *										- The specified @c event is not an entry type instance. @n
	 *										- The date of the event is invalid. @n
	 *										The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception   E_INVALID_OPERATION		This method cannot be used for the recurrence exception of the recurring event. @n
	 * 										UpdateEventInstance() should be used instead of this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result UpdateEvent(const CalEvent& event);

	/**
	 * Updates the specified CalTodo instance on the internal data storage.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	todo					The CalTodo instance to update
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c recordId is #INVALID_RECORD_ID, or the date of the to-do item is invalid. @n
	 *										The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result UpdateTodo(const CalTodo& todo);

	/**
	 * Gets the specified event ID that is matched with the RecordId.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		The matched event
	 * @param[in]	eventId					The event ID to find
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c eventId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	CalEvent* GetEventN(RecordId eventId) const;

	/**
	 * Gets the specified to-do after matching it with the specified record ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		The matched to-do
	 * @param[in]	todoId					The ID of the to-do to find
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c todoId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	CalTodo* GetTodoN(RecordId todoId) const;

	/**
	 * Gets all the to-do items in the specified time range. @n
	 * To-do items, whose due date is within the retrieving range, is retrieved.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list of all the matched CalTodo instances, @n
	 *				else an empty list if there is no matched to-do item @n
	 *				The items are sorted by due date.
	 * @param[in]	start					The start of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	end						The end of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	pageNo					The page number of the result list @n
	 *										It starts from @c 1.
	 * @param[in]	countPerPage			The desired maximum count of the result items per page
	 * @param[in]	status					The to-do status @n
	 *										If a specific status is set, the to-dos that have the specified status are returned. @n
	 *										The default status value is #TODO_STATUS_ALL, which means all the statuses are returned.
	 * @param[in]	priority				The to-do priority @n
	 *										If a specific priority is set, the to-dos that have the specified priority are returned. @n
	 *										The default priority value is #TODO_PRIORITY_ALL that means all the priorities are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *										- The start time is later than the end date. @n
	 *										- The start or end time is out of the valid range. @n
	 *										 The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetTodosN(const Tizen::Base::DateTime& start, const Tizen::Base::DateTime& end, int pageNo, int countPerPage, unsigned long status = TODO_STATUS_ALL,
							unsigned long priority = TODO_PRIORITY_ALL) const;

	/**
	 */

	/**
	 * Gets the total number of to-do items in the specified time range. @n
	 * To-do items, whose due date is within the retrieving range, is counted.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		The total number of to-dos, @n
	 *										else @c -1 if an exception occurs
	 * @param[in]	start					The start of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	end						The end of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	status					The to-do status @n
	 *										If a specific status is set, the to-dos that have the specified status are returned. @n
	 *										The default status value is #TODO_STATUS_ALL, which means all the statuses are returned.
	 * @param[in]	priority				The to-do priority @n
	 *										If a specific priority is set, the to-dos that have the specified priority are returned. @n
	 *										The default priority value is #TODO_PRIORITY_ALL that means all the priorities are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 										- The start time is later than the end date. @n
	 *										- The start or end time is out of the valid range. @n
	 *										The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTodoCount(const Tizen::Base::DateTime& start, const Tizen::Base::DateTime& end, unsigned long status = TODO_STATUS_ALL, unsigned long priority = TODO_PRIORITY_ALL) const;

	/**
	 */

	/**
	 * @if OSPDEPREC
	 * Gets the CalEvent instances that are within the specified time range. @n
	 * The all day events are retrieved by their start and end dates in the local time zone, while all other events are retrieved by their
	 * start and end times in Coordinated Universal Time (UTC).
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use GetInstancesOfAllDayEventsN() or GetInstancesOfNonAllDayEventsN().
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list containing all of the matched CalEvent instances, @n
	 *				else an empty list if there are no matched instances, or @c null if an exception occurs @n
	 *				The results are listed in the following order: all day events, and other events. @n
	 *				The results with the same property of all day event are ordered by their start time.
	 * @param[in]	start				The start of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	end					The end of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	timeZone			The time zone of the specified start and end times
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items per page
	 * @param[in]	category			The event category @n
	 *									If a specific category is set, the events that have the specified category are returned. @n
	 *									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *									- The specified @c category is invalid. @n
	 *									- The start time is later than the end date. @n
	 *									- The start or end time is out of the valid range. @n
	 *									The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Tizen::Base::Collection::IList*	GetEventInstancesN(const Tizen::Base::DateTime& start, const Tizen::Base::DateTime& end,
									 const Tizen::Locales::TimeZone& timeZone, int pageNo, int countPerPage,
									 unsigned long category = EVENT_CATEGORY_ALL) const;

	/**
	 * @if OSPDEPREC
	 * Gets the CalEvent instances that are within the specified time range. @n
	 * The all day events are retrieved by their start and end dates in the local time zone, while all other events are retrieved by their
	 * start and end times in Coordinated Universal Time (UTC).
	 *
	 * Although GetEventInstancesN() retrieves the data synchronously, this method returns data asynchronously using
	 * RecordListener::OnEventInstancesReceivedN(). @n
	 * It is highly recommended to use the asynchronous method because getting the event instances may take a long time.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use GetInstancesOfAllDayEventsN() or GetInstancesOfNonAllDayEventsN().
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		An error code
	 * @param[in]	start					The start of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	end					The end of the time range. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	timeZone				The time zone of the specified start and end times
	 * @param[in]	pageNo					The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage			The desired maximum count of the result items per page
	 * @param[in]	category				The event category @n
	 *									If a specific category is set, the events that have the specified @c category are returned. @n
	 *									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @param[out]	reqId				The ID of the request
	 * @param[in]	listener				The listener for receiving the responses of the request
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *									- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *									- The specified @c category is invalid. @n
	 *									- The start time is later than the end date. @n
	 *									- The start or end time is out of the valid range. @n
	 *									The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		IRecordListener::OnRecordsReceivedN(), Calendarbook::GetEventInstancesN()
	 * @endif
	 */
	result GetEventInstances(const Tizen::Base::DateTime& start, const Tizen::Base::DateTime& end,
									const Tizen::Locales::TimeZone& timeZone, int pageNo, int countPerPage, unsigned long category,
									RequestId& reqId,
									const IRecordListener& listener) const;

	/**
	 * Gets all events.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list containing all the CalEvent instances, @n
	 *				else an empty list if there are no events, or @c null if an exception occurs @n
	 *				The results are listed in the order of their event ID.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetAllEventsN(void) const;

	/**
	 * Gets all to-dos.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list containing all the CalTodo instances, @n
	 *				else an empty list if there are no to-dos, or @c null if an exception occurs @n
	 *				The results are listed in the order of their to-do ID.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetAllTodosN(void) const;

	/**
	 * Gets all calendars.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list containing all the Calendar instances, @n
	 *				else an empty list if there are no calendars, or @c null if an exception occurs @n
	 *				The results are listed in the order of their calendar ID.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetAllCalendarsN(void) const;

	/**
	 * Gets information of all the changed events since the version.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list containing the CalEventChangeInfo instances, @n
	 *				else an empty list if there are no events, or @c null if an exception occurs @n
	 *				The results are listed in the order of their version.
	 * @param[in]	version					The version
	 * @param[out]	latestVersion			The latest change version among the changed events
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c version is invalid.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetChangedEventsAfterN(int version, int& latestVersion) const;

	/**
	 * Gets information of all the changed to-dos since the version.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list containing the CalTodoChangeInfo instances, @n
	 *				else an empty list if there are no to-dos, or @c null if an exception occurs @n
	 *				The results are listed in the order of their version.
	 * @param[in]	version					The version
	 * @param[out]	latestVersion			The latest change version among the changed to-dos
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c version is invalid.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetChangedTodosAfterN(int version, int& latestVersion) const;

	/**
	 * Adds a calendar. @n
	 * After adding the calendar to the database successfully, the calendar has a valid calendar ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in,out]	calendar				The calendar to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The record ID of the calendar is not #INVALID_RECORD_ID.
	 * @exception	E_STORAGE_FULL			The storage is insufficient.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddCalendar(Calendar& calendar);

	/**
	 * Adds a calendar that is associated with the specified account. @n
	 * After adding the calendar to the database successfully, the calendar has a valid calendar ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in,out]	calendar			The calendar to add
	 * @param[in]	accountId				The account Id
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 										- The record ID of the calendar is not #INVALID_RECORD_ID. @n
	 *										- The specified @c accountId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified account is not found.
	 * @exception	E_STORAGE_FULL			The storage is insufficient.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddCalendar(Calendar& calendar, AccountId accountId);

	/**
	 * Removes the specified calendar.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	calendarId				The calendar ID to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The specified @c calendarId is invalid, or
	 *											the calendar represents default calendar.
	 * @exception	E_OBJ_NOT_FOUND			The specified calendar is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result RemoveCalendar(RecordId calendarId);

	/**
	 * Updates the specified calendar.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	calendar				The Calendar instance to update
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The calendar's recordId is #INVALID_RECORD_ID, or
	 * 										the calendar represents default calendar.
	 * @exception	E_OBJ_NOT_FOUND			The specified calendar is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result UpdateCalendar(const Calendar& calendar);

	/**
	 * Gets the calendar with the specified calendar ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		The matched calendar, @n 
	 *              else @c null if an exception occurs
	 * @param[in]	calendarId				The calendar ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG					The specified @c calendarId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified calendar is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	Calendar* GetCalendarN(RecordId calendarId) const;

	/**
	 * Removes an instance of the recurring event. @n
	 * If the event instance has been removed successfully, its start date is added as an exception date to the recurrence of its original event.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	eventInstance			The event instance to remove @n
	 * 										The @c eventInstance must be an instance of the recurring event.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG			The instance is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The original event of the @c eventInstance is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The instance's start time is added to the recurrence of original event as exception date.
	 */
	result RemoveEventInstance(const CalEventInstance& eventInstance);

	/**
	 * Update the specified recurring event instance(@ref CalEventInstance). This method can be used for defining exception of the recurring event. @n
	 * In order to update an event instance, you should use copy of its original event(@ref CalEventInstance::GetOriginalEventId()). @n
	 * You can modify the properties of copy of the original event and use it as the second parameter of this method. @n
	 * (The start/end time of the original event should be set with the start/end time of the event instance.) @n
	 * This method adds the modified copy of the original event as a new event. Therefore the new event ID will be assigned to it through @c event's record ID @n
	 * and its existing event ID inside the modified copy of the original event will become the base event ID of the new event. @n
	 * However this method only updates the properties of the event, does not add a new event that is already added.
	 *
	 * @since	2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.write
	 *
	 * @return		An error code
	 * @param[in]	eventInstance			The event instance to update @n
	 * 										The @c eventInstance must be an instance of the recurring event.
	 * @param[in,out]	event				The modified copy of the original event @n
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 										- The instance is invalid. @n
	 * 										- @c event is not referring to the original event.
	 * @exception	E_OBJ_NOT_FOUND			The original event of the @c eventInstance is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 *
	 * @code

		void UpdateRecurringEventInstance(const CalEventInstance& eventInstance)
		{
			CalEvent* pEvent = pCalendarbook->GetEventN(eventInstance.GetOriginalEventId());
			if (pEvent == null)
			{
				AppLogException("GetEventN() has failed");
				return;
			}

			// Sets the start time and end time
			pEvent->SetRecurrence(null);
			pEvent->SetStartAndEndTime(eventInstance.GetStartTime(), eventInstance.GetEndTime());

			// Modifies the properties
			pEvent->SetLocation(L"Meeting room on 11th floor");

			// Updates the instance
			result r = pCalendarbook->UpdateEventInstance(eventInstance, *pEvent);
			if (IsFailed(r))
			{
				AppLogException("UpdateEventInstance() has failed");
				delete pEvent;
				return;
			}

			delete pEvent;
		}

	 * @endcode
	 */
	result UpdateEventInstance(const CalEventInstance& eventInstance, CalEvent& event);

	/**
	 * Gets the latest version of calendarbook.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		The latest version
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLatestVersion(void) const;

	/**
	 * Searches items of the calendarbook with the filter. @n
	 * The filter specifies the item type and condition for searching.
	 * The searched results are ordered by the @c propertySortedBy and @c sortOrder.
	 * If the @c offset is M and the @c maxCount are N, then the first M items are omitted from the result set returned by the searching operation and the next N items are returned.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		A list of searched results (the list of CalEvent, CalTodo, Calendar, or CalEventInstance), @n
	 *						else an empty list if there is no searched result, or @c null if an exception occurs
	 * @param[in]	filter		The filter that specifies the search condition @n If the filter is empty, all items that are specified by the type of this filter will be searched.
	 * @param[in]	propertySortedBy		The property for sorting @n The searched results are ordered by the values of this property.
	 * @param[in]	sortOrder		The order for sorting
	 * @param[in]	offset			The offset of the searched results @n If this value is @c 0, it will be ignored.
	 * @param[in]	maxCount		The maximum count of the searched results @n If this value is @c 0, it will be ignored.
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG				The specified @c offset or @c maxCount is less than 0, or the @c propertySortedBy is not an element of the enumerator that corresponds with the type of the specified @c filter.
	 * @exception	E_SYSTEM					The method cannot proceed due to a severe system error.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	  * @see EventFilterProperty
	  * @see TodoFilterProperty
	  * @see CalendarFilterProperty
	  * @see EventInstanceFilterProperty
	 */
	Tizen::Base::Collection::IList* SearchN(const CalendarbookFilter& filter, unsigned long propertySortedBy = 0, Tizen::Base::SortOrder sortOrder = Tizen::Base::SORT_ORDER_NONE,
			int offset = 0, int maxCount = 0) const;

	/**
	 * Gets the matched item count of the search results with the filter. @n
	 * The filter specifies the item type and condition for searching.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/calendar.read
	 *
	 * @return		The count of the searched results
	 * @param[in]	filter 	The filter that specifies the search condition @n If the filter is empty, all items that are specified by the type of this filter will be searched.
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM						The method cannot proceed due to a severe system error.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetMatchedItemCount(const CalendarbookFilter& filter) const;

	/**
	 * Parses the events from specific vCalendar file. @n
	 * The %ParseEventsFromVcalendarN() method supports to parse for vCalendar version 1.0 and 2.0 (iCalendar).
	 *
	 * @since	2.0
	 *
	 * @return		A list containing the CalEvent instances, @n
	 *				else an empty list if there are no events, or @c null if an exception occurs
	 * @param[in]	vCalFilePath			The path of the vCalendar file
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c vCalFilePath is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_FILE_NOT_FOUND		The specified vCalendar file is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	static Tizen::Base::Collection::IList* ParseEventsFromVcalendarN(const Tizen::Base::String& vCalFilePath);

	/**
	 * Parses the to-dos from specific vCalendar file. @n
	 * The %ParseTodosFromVcalendarN() method supports to parse for vCalendar version 1.0 and 2.0 (iCalendar).
	 *
	 * @since	2.0
	 *
	 * @return		A list containing the CalTodo instances, @n
	 *				else an empty list if there are no to-dos, or @c null if an exception occurs
	 * @param[in]	vCalFilePath			The path of the vCalendar file
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c vCalFilePath is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_FILE_NOT_FOUND		The specified vCalendar file is not found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is
	 *					E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer
	 *					<a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	static Tizen::Base::Collection::IList* ParseTodosFromVcalendarN(const Tizen::Base::String& vCalFilePath);

	/**
	 * Exports the events to vCalendar 2.0 (iCalendar) file.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	eventList				The event list to export @n The list should contain CalEvent instances.
	 * @param[in]	vCalFilePath			The vCalendar file path
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c eventList is invalid or
	 * 										the specified @c vCalFilePath is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access of vCalFilePath is denied due to insufficient permission.
	 * @exception	E_FILE_ALREADY_EXIST	The vCalendar file already exists.
	 * @exception	E_STORAGE_FULL			The disk space is full.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	static result ExportEventsToVcalendar(const Tizen::Base::Collection::IList& eventList, const Tizen::Base::String& vCalFilePath);

	/**
	 * Exports the to-dos to vCalendar 2.0 (iCalendar) file.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	todoList				The to-do list to export @n The list should contain CalTodo instances.
	 * @param[in]	vCalFilePath			The vCalendar file path
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c todoList is invalid or
	 * 										the specified @c vCalFilePath is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access of vCalFilePath is denied due to insufficient permission.
	 * @exception	E_FILE_ALREADY_EXIST	The vCalendar file already exists.
	 * @exception	E_STORAGE_FULL			The disk space is full.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	static result ExportTodosToVcalendar(const Tizen::Base::Collection::IList& todoList, const Tizen::Base::String& vCalFilePath);

	/**
	 * Gets the maximum allowable date and time in the calendarbook (that is, "December 31 2100 23:59:59").
	 *
	 * @since	2.0
	 *
	 * @return		An instance of Tizen::Base::DateTime
	 */
	static Tizen::Base::DateTime GetMaxDateTime(void);

	/**
	 * Gets the minimum allowable date and time in the calendarbook (that is, "January 1 1900 00:00:00").
	 *
	 * @since	2.0
	 *
	 * @return		An instance of Tizen::Base::DateTime
	 */
	static Tizen::Base::DateTime GetMinDateTime(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private @n
	 * to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	Calendarbook(const Calendarbook& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private @n
	 * to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	Calendarbook& operator =(const Calendarbook& rhs);

private:
	friend class _CalendarbookImpl;
	class _CalendarbookImpl* __pCalendarbookImpl;
};	// Calendarbook

}}	// Tizen::Social


#endif // _FSCL_CALENDARBOOK_H_
