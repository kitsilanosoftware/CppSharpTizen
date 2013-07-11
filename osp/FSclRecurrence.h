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
 * @file	FSclRecurrence.h
 * @brief	This is the header file for the %Recurrence class.
 *
 * This header file contains the declarations of the %Recurrence class.
 */
#ifndef _FSCL_RECURRENCE_H_
#define _FSCL_RECURRENCE_H_

#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FBaseColIListT.h>
#include <FBaseColArrayListT.h>
#include <FBaseDateTime.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Social
{

/**
 * @class	Recurrence
 * @brief	This class provides methods to access the information of a %Recurrence.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Recurrence class provides methods to access the information of a %Recurrence.
 *	A CalEvent can be made a recurring event using this class. To set or get the information of a recurrence (such as start time and recurrence
 *			pattern) use the methods of this class. The recurrence date is the start date of the CalEvent, if they do not match.
 *
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/recurrence_reminder_sensitivity.htm">Recurrence, Reminder, and Sensitivity Properties of Calendar Items</a>.
 *
 * @see		CalEvent::SetRecurrence()
 *
 * The following examples demonstrate how to use the %Recurrence class.
 *
 * 1. Repeat daily for 10 occurrences:
 *
 * @code

	void
	MyRecurrence::RepeatDayily10(void)
	{
		result r;
		Recurrence* pRecurrence = new Recurrence();
		if (IsFailed(GetLastResult()) || pRecurrence == null)
		{
			AppLogException("Create instance has failed");
		}
		pRecurrence->SetFrequency(FREQ_DAILY);
		r = pRecurrence->SetCounts(10);
		if (IsFailed(r))
		{
			AppLogException("Set counts has failed");
		}
	}

 * @endcode
 * 2. Repeat weekly until May 4, 2009:
 *
 * @code

	void
	MyRecurrence::RepeatDayilyUntil(void)
	{
		result r;
		Recurrence* pRecurrence = new Recurrence();
		if (IsFailed(GetLastResult()) || pRecurrence == null)
		{
			AppLogException("Create instance has failed");
		}
		DateTime until;
		r = until.SetValue(2009, 5, 4);
		if (IsFailed(r))
		{
			AppLogException("Set date/time has failed");
		}

		pRecurrence->SetFrequency(FREQ_WEEKLY);
		r = pRecurrence->SetUntil(&until);
		if (IsFailed(r))
		{
			AppLogException("Set until has failed");
		}
	}

 * @endcode
 *
 * 3. Repeat bi-weekly on Tuesday and Thursday until May 4, 2009:
 * @code

	void
	MyRecurrence::RepeatByWeeklyUntil(void)
	{
		result r;
		Recurrence* pRecurrence = new Recurrence();
		if (IsFailed(GetLastResult()) || pRecurrence == null)
		{
			AppLogException("Create instance has failed");
		}

		DateTime until;
		r = until.SetValue(2009, 5, 4);
		if (IsFailed(r))
		{
			AppLogException("Set date/time has failed");
		}

		pRecurrence->SetFrequency(FREQ_WEEKLY);
		r = pRecurrence->SetInterval(2);
		if (IsFailed(r))
		{
			AppLogException("Set interval has failed");
		}

		r = pRecurrence->SetDayOfWeek(CAL_TUESDAY | CAL_THURSDAY);
		if (IsFailed(r))
		{
			AppLogException("Set day of week has failed");
		}

		r = pRecurrence->SetUntil(&until);
		if (IsFailed(r))
		{
			AppLogException("Set until has failed");
		}
	}
 * @endcode
 *
 * 4. Repeat monthly on the first Thursday for 10 occurrences. The week starts on Monday:
 * @code

	void
	MyRecurrence::RepeatMonthlyUntil(void)
	{
		result r;
		Recurrence* pRecurrence = new Recurrence();
		if (IsFailed(GetLastResult()) || pRecurrence == null)
		{
			AppLogException("Create instance has failed");
		}

		pRecurrence->SetFrequency(FREQ_MONTHLY);

		r = pRecurrence->SetWeekStart(CAL_MONDAY);
		if (IsFailed(r))
		{
			AppLogException("Set week start has failed");
		}

		r = pRecurrence->SetDayOfWeek(CAL_THURSDAY);
		if (IsFailed(r))
		{
			AppLogException("Set day of the week has failed");
		}

		r = pRecurrence->SetWeekOfMonth(1);
		if (IsFailed(r))
		{
			AppLogException("Set week of month has failed");
		}

		r = pRecurrence->SetCounts(10);
		if (IsFailed(r))
		{
			AppLogException("Set counts has failed");
		}
	}

 * @endcode
 *
 */
class _OSP_EXPORT_ Recurrence
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * This constructor sets the default values. The recurrence type is daily and recurrence interval is @c 1. @n
	 * The week start day is #CAL_MONDAY. The recurrence count is @c 1.
	 *
	 * @since	2.0
	 */
	Recurrence(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Recurrence
	 */
	Recurrence(const Recurrence& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Recurrence(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %Recurrence instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %Recurrence instance, @n
	 *				else @c false
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
	 * Gets the recurrence frequency type.
	 *
	 * @since	2.0
	 *
	 * @return		A reference to one of the @c RecurFrequency enumeration values, @n
	 *				else #FREQ_DAILY if this property is not set
	 */
	RecurFrequency GetFrequency(void) const;

	/**
	 * Gets the recurrence interval. @n
	 * This represents the number of units between two recurrences. @n
	 * If the frequency is weekly and the recurrence interval is set to @c 2, the event occurs every two weeks.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value representing the recurrence interval, @n
	 *				else @c 1 if this property is not set
	 */
	int GetInterval(void) const;

	/**
	 * Gets the end date and time of recurrence.
	 *
	 * @since	2.0
	 *
	 * @return		An instance of Tizen::Base::DateTime representing the end date and time
	 * @remarks		If this method returns @c null, get the recurrence counts using the GetCounts() method.
	 *
	 */
	const Tizen::Base::DateTime* GetUntil(void) const;

	/**
	 * Gets the number of times the event recurs.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value representing the number of recurrences
	 * @remarks		If this method returns @c 0, get the recurrence end date and time using the GetUntil() method.
	 *
	 */
	int GetCounts(void) const;

	/**
	 * Gets the first day of the week. @n
	 * The default value is #CAL_MONDAY.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value representing the first day of the week
	 *
	 */
	CalDayOfWeek GetWeekStart(void) const;

	/**
	 * Gets the day of the week when the event should recur. @n
	 * The default value is @c 0.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value representing the CalDayofWeek
	 * @remarks		The Frequency property must be obtained. If the frequency is #FREQ_WEEKLY, the return value may be a combination of days,
	 * 				like #CAL_MONDAY| #CAL_THURSDAY.
	 *
	 */
	int GetDayOfWeek(void) const;

	/**
	 * Gets the day of the month. @n
	 * The default value is @c 0.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value between @c 1 ~ @c 31 representing the day of a month
	 * @remarks		The Frequency property must be obtained.
	 */
	int GetDayOfMonth(void) const;

	/**
	 * Gets the week of the month. @n
	 * The default value is @c 0.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value between @c 1 ~	@c 5 representing the week of a month
	 * @remarks		The Frequency property must be obtained.
	 *
	 */
	int GetWeekOfMonth(void) const;

	/**
	 * Gets the month of the year. @n
	 * The default value is @c 0.
	 *
	 * @since	2.0
	 *
	 * @return		An integer value between @c 1 ~ @c 12 representing the month of a year
	 * @remarks		The Frequency property must be obtained.
	 *
	 */
	int GetMonthOfYear(void) const;

	/**
	 * Sets a recurring frequency type among specific types (daily, weekly, monthly, and yearly). @n
	 * This property must be set before setting the day of recurrence. After setting the frequency, other properties are reset to default values. @n
	 * For weekly, the day of week must be set. @n
	 * For monthly, the day of the week and the week of the month must be set. @n
	 * For yearly, either the day of the month and the month of the year, or the day of the week, the week of the month, and the month of the year must be set.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type	The recurrence type
	 *
	 */
	void SetFrequency(RecurFrequency type);

	/**
	 * Sets the interval of recurrence. @n
	 * If the frequency is weekly and the recurrence interval is set to 2, the event occurs every two weeks.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
     *					For more information, see @ref CompRecurrenceSetIntervalPage "here".
     * @endif
	 *
	 * @return		An error code
	 * @param[in]	interval		The interval of recurrence
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c interval is less than @c 1.
	 */
	result SetInterval(int interval);

	/**
	 * @if OSPCOMPAT
	 * @page	CompRecurrenceSetIntervalPage Compatibility for SetInterval()
	 * @section	CompRecurrenceSetIntervalPageIssueSection Issues
	 *          Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# If the value of the interval to be set is greater than 255, E_INVALID_ARG is returned.
	 *
	 * @section	CompRecurrenceSetIntervalPageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 * 			-# There is no limit for the value of the interval.
	 * @endif
	 */

	/**
	 * Sets the end date of the recurrence. @n
	 * If you want to set the event to have no end date, set the maximum date and time using the Tizen::Base::DateTime::GetMaxValue() method.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	pUntil			The end date and time
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The @c pUntil is not in a valid range. @n
	 *					The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @remarks		Either the until or count properties may be set. @n
	 *				When the until property is set, the count property becomes @c 0. @n
	 *				When the count property is set, the until property becomes @c null.
	 */
	result SetUntil(const Tizen::Base::DateTime* pUntil);

	/**
	 * Sets the number of times the event recurs.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	count			The number of times the event recurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c count is less than @c 0.
	 * @remarks		Either the until or count properties may be set. @n
	 *				When the until property is set, the count property becomes @c 0. @n
	 *				When the count property is set, the until property becomes @c null. @n
	 */
	result SetCounts(int count);

	/**
	 * Sets the first day of the week. @n
	 * The default value is set to #CAL_MONDAY. The valid values are #CAL_SUNDAY and #CAL_MONDAY. @n
	 * This value is very important when the recurrence type is weekly and the interval is greater than @c 1. @n
	 * The weekly recurrence rule will be calculated based on the week start value.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	weekStart				The day on which the week starts
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c day is invalid.
	 */
	result SetWeekStart(CalDayOfWeek weekStart);

	/**
	 * Sets the day of the week that represents the days when the event should recur. @n
	 * The valid values range between #CAL_SUNDAY and #CAL_SATURDAY. @n
	 * Any values other than #CAL_SUNDAY ~ #CAL_SATURDAY are ignored. @n
	 * The Frequency property must be set before setting this property.
	 * This property is valid for the following #RecurFrequency enumeration types: #FREQ_WEEKLY, #FREQ_MONTHLY, and #FREQ_YEARLY.
	 * If the frequency is #FREQ_WEEKLY, the value of the day may be a combination of days, such as #CAL_MONDAY|#CAL_FRIDAY.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	day				An integer value representing the day of the week
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c day is invalid.
	 * @exception	E_TYPE_MISMATCH	The #RecurFrequency is not #FREQ_WEEKLY, #FREQ_MONTHLY, or #FREQ_YEARLY.
	 * @remarks		After this property is set, the DayOfMonth property value is reset automatically.
	 */
	result SetDayOfWeek(int day);

	/**
	 * Sets the day of the month which indicates when the event recurs. @n
	 * The Frequency property must be set before setting this property. @n
	 * This property is valid for the following #RecurFrequency enumeration types: #FREQ_MONTHLY and #FREQ_YEARLY. @n
	 * If the day of the month is 31 and the frequency is monthly, the months which have only 30 days are not included in the recurrence instance set. @c
	 * Accordingly, with the recurrence rule, 2/29 yearly, 2/29 every four years will be included in the recurrence set.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	day					An integer value between @c 1 and @c 31 indicating the day of the month
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c day is less than @c 1 or greater than @c 31.
	 * @exception	E_TYPE_MISMATCH		The #RecurFrequency is not #FREQ_MONTHLY or #FREQ_YEARLY.
	 * @remarks		After this property is set, the DayOfWeek and WeekOfMonth property value are reset automatically.
	 */
	result SetDayOfMonth(int day);

	/**
	 * Sets the week of the month. @n
	 * If the value of the week is @c 5, it is set as the last week of the month. @n
	 * This property is valid for the following #RecurFrequency enumeration types: #FREQ_MONTHLY and #FREQ_YEARLY.
	 * The Frequency property must be set before setting this property. @n
	 * When the week of the month is set, the day of the week must be set accordingly.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	week				An integer value between @c 1 and @c 5 representing the week of the month
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c week is less than @c 1 or greater than @c 5.
	 * @exception	E_TYPE_MISMATCH		The #RecurFrequency is not #FREQ_MONTHLY or #FREQ_YEARLY.
	 * @remarks		After this property is set, the DayOfMonth property value is reset automatically.
	 */
	result SetWeekOfMonth(int week);

	/**
	 * Sets the month of the year. @n
	 * This property is valid for the following #RecurFrequency enumeration type: #FREQ_YEARLY. @n
	 * The Frequency property must be set before setting this property. @n
	 * When the month of the year is set, the day of the month or both the day of the week and the week of the month must be set accordingly.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	month				An integer value between @c 1 and @c 12 representing the month of the year
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c month is less than @c 1 or greater than @c 12.
	 * @exception	E_TYPE_MISMATCH		The #RecurFrequency is not #FREQ_YEARLY.
	 */
	result SetMonthOfYear(int month);

	/**
	 * Adds an exception date to this event.
	 * The instance that its start date and time matched with the exception date will be exclude from recurrence instances.
	 * If there are any changes in this recurrence, the exception dates would be cleared.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	exceptionDate			The exception date to exclude
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c exceptionDate is invalid.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified @c exceptionDate already exists.
	 */
	result AddExceptionDate(const Tizen::Base::DateTime& exceptionDate);

	/**
	 * Gets the exception dates.
	 *
	 * @since	2.0
	 *
	 * @return		A list containing the exception dates, @n
	 *				else an empty list if there are no exception dates, or @c null if an exception occurs @n
	 *				The results are listed in the order of date and time.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetExceptionDatesN(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Recurrence
	 */
	Recurrence& operator =(const Recurrence& rhs);

private:
	friend class _RecurrenceImpl;
	class _RecurrenceImpl* __pRecurrenceImpl;
};	// Recurrence

}}	// Tizen::Social

#endif // _FSCL_RECURRENCE_H_
