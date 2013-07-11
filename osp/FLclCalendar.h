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
 * @file		FLclCalendar.h
 * @brief		This is the header file for the %Calendar class.
 *
 * This header file contains the declarations of the %Calendar class.
 *
 */
#ifndef _FLCL_CALENDAR_H_
#define _FLCL_CALENDAR_H_

#include <FBase.h>
#include <FLclLocale.h>
#include <FLclTimeZone.h>

namespace Tizen { namespace Locales
{
/**
 * @class		Calendar
 * @brief		This class provides methods for displaying a calendar.
 *
 * @since		2.0
 *
 * The %Calendar class is an abstract base class for displaying a calendar. It is used to convert between the Tizen::Base::DateTime instance and a set of time fields, such as TIME_FIELD_YEAR, TIME_FIELD_MONTH, and TIME_FIELD_DAY_OF_MONTH.
 * Subclasses of %Calendar interpret %Tizen::Base::DateTime according to the rules of a specific calendar system. GregorianCalendar is commonly used.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/calendar.htm">Calendar</a>.
 *
 * @see			Tizen::Locales::TimeZone
 *
 * The following example demonstrates how to use the %Calendar class to set or add the time field.
 *
 @code
 *
 #include <FBase.h>
 #include <FLocales.h>

 using namespace Tizen::Base;
 using namespace Tizen::Locales;

 void
 MyClass::CalendarExample(void)
 {
	int offset = 60;
	String timeZoneName(L"Europe/Paris");
	TimeZone timeZone(offset, timeZoneName);

	Calendar* pCalendar = Calendar::CreateInstanceN(timeZone, CALENDAR_GREGORIAN);
	pCalendar->SetTime(2012,7,18);

	// Increase one day. The date will be 2012/7/19
	pCalendar->AddTimeField(TIME_FIELD_DAY_OF_MONTH, 1);

	// Decrease two months. The date will be 2012/5/19
	pCalendar->AddTimeField(TIME_FIELD_MONTH, -2);

	delete pCalendar;
 }
 @endcode
 */
#define GET_TIME_FIELD_MASK(X)	(static_cast<int>(1 << (X)))
/**
* @enum TimeField
*
* Defines the time fields for date and time. @n
* This enum is used in %Calendar.
*
* @since		2.0
*/
enum TimeField
{
	TIME_FIELD_ERA,							/**< Era : 0 - BC, 1 - AD */
	TIME_FIELD_YEAR,						/**< Year : 1-based */
	TIME_FIELD_MONTH,						/**< Month : 1-based (1~13)*/
	TIME_FIELD_WEEK_OF_YEAR,				/**< Week of Year : 1-based (1~53) */
	TIME_FIELD_WEEK_OF_MONTH,				/**< Week of Month : 1-based (1~5, may be specified as 0) */
	TIME_FIELD_DAY_OF_MONTH,				/**< Date : 1-based (1~31) */
	TIME_FIELD_DAY_OF_YEAR,					/**< Day of Year : 1-based (1~366) */
	TIME_FIELD_DAY_OF_WEEK,					/**< Day of Week : 1-based (1~7) */
	TIME_FIELD_DAY_OF_WEEK_IN_MONTH,		/**< Day of Week in Month : 1-based (1~5, may be specified as -1) */
	TIME_FIELD_AM_PM,						/**< AmPm : 0 - AM, 1 - PM */
	TIME_FIELD_HOUR,						/**< Hour : 0-based (0~11) */
	TIME_FIELD_HOUR_OF_DAY,					/**< Hour of Day : 0-based (0~23) */
	TIME_FIELD_MINUTE,						/**< Minute : 0-based (0~59) */
	TIME_FIELD_SECOND,						/**< Second : 0-based (0~59) */
	TIME_FIELD_MILLISECOND,					/**< Millisecond : 0-based (0~999) */
	TIME_FIELD_ZONE_OFFSET,					/**< Time Zone Offset : 0-based (-43200000~54000000 in milliseconds) */	
	TIME_FIELD_DST_OFFSET,					/**< Daylight Saving Offset : 0-based (0~3600000 in milliseconds)*/
	TIME_FIELD_FIELD_COUNT					/**< The number of time field */
};

class _OSP_EXPORT_ Calendar
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class. @n 
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~Calendar(void);

	/**
	* Adds the specified amount to the given time field, based on the calendar rules. @n
	* It is equivalent to calling SetTimeField(field, GetTimeField(field)+amount) with two adjustments. @n
	*
	* @b Add @b Rule1: The value of the time field @c field after the call minus the value of the field
	* before the call is delta modulo any overflow that has occurred in the field.
	* Overflow occurs when a time field value exceeds its range and, as a result, the next larger field
	* is incremented or decremented and the field value is adjusted back into its range. @n
	*
	* @b Add @b Rule2: If a smaller field is expected to be invariant, but it is impossible for it to be
	* equal to its prior value because of changes in its minimum or maximum value after the time field @c field
	* is changed, then its value is adjusted to be as close as possible to its expected value. @n
	*
	* A smaller field represents a smaller unit of time. TIME_FIELD_HOUR is a smaller field than TIME_FIELD_DAY_OF_MONTH.
	* No adjustment is made to smaller fields that are not expected to be invariant.
	* The calendar system determines what fields are expected to be invariant.
	*
	* In addition, this method forces re-computation of the calendar's milliseconds and
	* all time fields immediately. @n
	*
	* For example, consider a GregorianCalendar set to Oct 31, 2004.
	* Calling AddTimeField(TIME_FIELD_MONTH, 13) sets the calendar to Nov 30, 2005. @n
	* The TIME_FIELD_MONTH field is set to NOVEMBER by @b Rule1, since adding 13 months to October gives the
	* November of the next year.
	* Since, the TIME_FIELD_DAY_OF_MONTH cannot be 31 in November in a %GregorianCalendar, the TIME_FIELD_DAY_OF_MONTH is set to 30 by @b Rule2.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompCalendarAddTimeFieldPage "here".
	* @endif
	*
	* @return			An error code
	* @param[in]		field						The time field
	* @param[in]		amount						The amount to add
	* @exception		E_SUCCESS					The method is successful.
	* @exception            E_INVALID_ARG                                  The specified @c field is invalid.  
	*/
	virtual result AddTimeField(TimeField field, int amount) = 0;

	/**
	* @if OSPCOMPAT
        * @page                    CompCalendarAddTimeFieldPage Compatibility for AddTimeField()
        * @section                   CompCalendarAddTimeFieldIssueSection Issues
        * Implementation of this method in OSP compatible applications has the following issue: @n
        * -# The method returns E_INVALID_STATE if the time field is invalid.
        *
        * @section                 CompCalendarAddTimeFieldSolutionSection Resolutions
        * This issue has been resolved in Tizen. @n
	*
	* @par When working in Tizen:
        * -# The method returns E_INVALID_ARG if the time field is invalid.
	* @endif
        */

	/**
	* Compares the current instance of %Calendar with the specified instance.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since				2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompCalendarAfterPage "here".
	* @endif
	*
	* @return				An error code
	* @param[in]		otherCalendar					The instance of %Calendar to compare
	* @param[out]		after						Set to @c true if the current instance of %Calendar is after the specified instance of %Calendar, @n
	*										else @c false
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG					The specified @c otherCalendar is invalid. 
	* @exception            E_INVALID_STATE                                 In this method, the time fields of this instance are calculated. @n 
	*										If any time field value previously set is invalid, this exception is returned. 
	* @exception		E_OUT_OF_RANGE					In this method, the time fields of this instance are calculated. @n
	*										 If the value of the time fields goes out of range, this exception is returned. 
	*/
	result After(const Calendar& otherCalendar, bool& after);

	/**
	* @if OSPCOMPAT
        * @page                    CompCalendarAfterPage Compatibility for After()
        * @section                   CompCalendarAfterIssueSection Issues
        * Implementation of this method in OSP compatible applications has the following issue: @n
        * -# The method returns E_INVALID_STATE and E_OUT_OF_RANGE if the instance of %Calendar to be compared is invalid.
        *
        * @section                 CompCalendarAfterSolutionSection Resolutions
        * This issue has been resolved in Tizen. @n
	*
	* @par When working in Tizen: 
        * -# The method returns E_INVALID_ARG if the instance of %Calendar to be compared is invalid.
        * -# The method returns E_INVALID_STATE if any time field value previously set is invalid.
        * -# The method returns E_OUT_OF_RANGE if the value of the time fields goes out of range.
	* @endif
        */                                        

	/**
	* Compares the current instance of %Calendar with the specified instance.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since				2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompCalendarBeforePage "here".
	* @endif
	*
	* @return				An error code
	* @param[in]			otherCalendar				The instance of %Calendar to compare
	* @param[out]			before					Set to @c true if the current instance of %Calendar is before the specified instance of %Calendar, @n
	*										else @c false
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG				The specified @c otherCalendar is invalid. 
	* @exception            E_INVALID_STATE                         In this method, the time fields of this instance are calculated. @n
	*									 If any time field value previously set is invalid, this exception is returned. 
	* @exception		E_OUT_OF_RANGE				In this method, the time fields of this instance are calculated. @n
	*									 If the value of the time fields goes out of range, this exception is returned. 
	*/
	result Before(const Calendar& otherCalendar, bool& before);

	/**
	* @if OSPCOMPAT
        * @page                    CompCalendarBeforePage Compatibility for Before()
        * @section                   CompCalendarBeforeIssueSection Issues
        * Implementation of this method in OSP compatible applications has the following issue: @n
        * -# The method returns E_INVALID_STATE and E_OUT_OF_RANGE if the instance of %Calendar to be compared is invalid.
        *
        * @section                 CompCalendarBeforeSolutionSection Resolutions
        * This issue has been resolved in Tizen. @n
	*
	* @par When working in Tizen: 
        * -# The method returns E_INVALID_ARG if the instance of %Calendar to be compared is invalid.
        * -# The method returns E_INVALID_STATE if any time field value previously set is invalid.
        * -# The method returns E_OUT_OF_RANGE if the value of the time fields goes out of range.
        * @endif
        */

	/**
	* Clears all the time fields and sets it to @c 0. @n
	* Zero is not the default value for each field. It means the field is cleared.
	*
	* @since				2.0
	*
	* @return				An error code
	* @exception			E_SUCCESS					The method is successful.
	*/
	result Clear(void);

	/**
	* Clears the specified time field and sets it to @c 0. @n
	* Zero is not the default value for each field. It means the field is cleared.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			field						The time field to clear
	* @exception			E_SUCCESS					The method is successful.
	*/
	result Clear(TimeField field);

	/**
	* Checks whether the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Calendar.
	*
	* @since			2.0
	*
	* @return			@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Calendar, @n
	*					else @c false
	* @param[in]		obj An instance of Tizen::Base::Object to compare
	*/
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since			2.0
	*
	* @return			The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Rolls up or down as per the specified @c amount in the specified time field without changing the larger fields (for example, TIME_FIELD_YEAR field cannot be changed when the input field is TIME_FIELD_MONTH). @n
	* If the specified @c amount is negative, the amount value is deducted from the specified time field value.
	* In this method, the time field of this instance is operated upon. If the value of the specified @c field goes out of range, E_OUT_OF_RANGE is returned.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since				2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompCalendarRollPage "here".
	* @endif
	*
	* @return				An error code
	* @param[in]			field							The time field to roll
	* @param[in]			amount							The amount to add to the time field
	* @exception			E_SUCCESS						The method is successful.
	* @exception                    E_INVALID_ARG                                   The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET). 
	* @exception            E_OUT_OF_RANGE                          In this method, the time fields of this instance are calculated. @n
	*                                                                        If the value of the time fields goes out of range, this exception is returned.
	*/
	virtual result Roll(TimeField field, int amount);

	/**
	* @if OSPCOMPAT
        * @page                    CompCalendarRollPage Compatibility for Roll()
        * @section                   CompCalendarRollIssueSection Issues
        * Implementation of this method in OSP compatible applications has the following issue: @n
        * -# The method returns E_INVALID_STATE if the time field is invalid.
        *
        * @section                 CompCalendarRollSolutionSection Resolutions
        * This issue has been resolved in Tizen. @n
	*
	* @par When working in Tizen: 
        * -# The method returns E_INVALID_ARG if the time field is invalid.
	* @endif
        */

	/**
	* Sets the specified time field with the specified @c value. @n
	* This sets an internal member variable to indicate that the field has been changed.
	* Although the time field is changed, the milliseconds of %Calendar are not recomputed
	* until GetTimeField(), GetTime(), or GetTimeInMillisec() is called.
	* Thus, even if you call this method several times, unnecessary multiple computations are not triggered. @n
	*
	* As a result of changing a field using SetTimeField(), other fields may also change
	* depending on the field, the field value, and the calendar system. @n
	*
	* For example, consider a GregorianCalendar set to Oct. 31, 2004.
	* Calling SetTimeField(TIME_FIELD_MONTH, NOVEMBER) sets the calendar to Nov 31, 2004. @n
	* But, if you call GetTime(), then Dec 1, 2004 is returned because Nov 31, 2004 does not exist.
	* However, a call to SetTimeField(TIME_FIELD_MONTH, SEPTEMBER) before a call to GetTime() sets the calendar
	* to Sep 30, 2004, since no re-computation has occurred after the first call to SetTimeField().
	*
	* The value of field is not affected by it being local time or UTC time.
	* The value is only overwritten.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			field					The time field to set
	* @param[in]			value					The value to set
	* @exception			E_SUCCESS				The method is successful.
	* @exception			E_OUT_OF_RANGE			The value is out of range in lenient mode.
	* @exception			E_INVALID_ARG			The specified @c field is invalid.
	*/
	result SetTimeField(TimeField field, int value);

	/**
	* Sets the first day of the week.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			dayOfWeek				The value to set as the first day of the week
	* @exception			E_SUCCESS				The method is successful.
	* @exception			E_INVALID_ARG			The specified @c dayOfWeek is invalid.
	*/
	result SetFirstDayOfWeek(DayOfWeek dayOfWeek);

	/**
	* Sets the leniency of date and time interpretations.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			lenient					Set to @c true if the date and time interpretation is set to lenient, @n
	*												else @c false
	* @exception			E_SUCCESS				The method is successful.
	*/
	result SetLenient(bool lenient);

	/**
	* Sets the minimal days required in the first week.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			value					The minimal days required in the first week
	* @exception			E_SUCCESS				The method is successful.
	*/
	result SetMinDaysInFirstWeek(short value);

	/**
	* Sets the value of year, month, day, hour, minute, and seconds. @n
	* The date and time are local time.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			year					The value to set for year
	* @param[in]			month					The value to set for month @n
	*												The indexing is 1-based. Therefore, 1 means January.
	* @param[in]			day						The value to set for day
	* @param[in]			hour					The value to set for hour
	* @param[in]			minute					The value to set for minute
	* @param[in]			second					The value to set for second
	* @exception			E_SUCCESS				The method is successful.
	* @exception			E_OUT_OF_RANGE			 A time field or its value is out of range in lenient mode.
	*/
	result SetTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);

	/**
	* Sets the calendar's current time with the specified Tizen::Base::DateTime.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			dateTime				The Tizen::Base::DateTime instance to set
	* @exception			E_SUCCESS				The method is successful.
	* @remarks				The time specified is the local time.
	*/
	result SetTime(const Tizen::Base::DateTime& dateTime);

	/**
	* Sets the current time of this %Calendar instance with the specified value.
	*
	* @since				2.0
	*
	* @return				An error code
	* @param[in]			millisec				The new time in milliseconds from the starting day (Jan 1, 1.)
	* @exception			E_SUCCESS				The method is successful.
	* @exception			E_OUT_OF_RANGE			A time field or its value is out of range.
	*/
	result SetTimeInMillisec(long long millisec);

	/**
	* Sets the time zone of the calendar to the specified time zone.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		timeZone				The time zone to set
	* @exception		E_SUCCESS				The method is successful.
	*/
	result SetTimeZone(const TimeZone& timeZone);

	/**
	 * Gets the actual maximum value that the specified field can have, given the current date. @n
	 * For example, if the current date is "Feb 10, 2004" and the time field specified is TIME_FIELD_DAY_OF_MONTH, then the actual
	 * maximum value for this time field is 29.
	 *
	 * @since					2.0
	 *
	 * @return					An integer value indicating the actual maximum value
	 * @param[in]				field		The time field
	 * @exception				E_SUCCESS			The method is successful.
	 * @exception				E_INVALID_ARG			The specified @c field is invalid.
	 * @remarks					The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetActualMaxTimeField(TimeField field) const;

	/**
	 * Gets the actual minimum value that the specified time field can have, given the current date. @n
	 * For the Gregorian calendar, this is the same as GetMinTimeField() and
	 * GetGreatestMinTimeField().
	 *
	 * @since					2.0
	 *
	 * @return					An integer value indicating the actual minimum value 
	 * @param[in]				field		The time field
	 * @exception				E_SUCCESS			The method is successful.
	 * @exception				E_INVALID_ARG			The specified @c field is invalid.
	 * @exception				E_SYSTEM			A system error has occurred.
	 * @remarks					The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetActualMinTimeField(TimeField field) const;

	/**
	* Gets the value of the first day of the week. @n
	* For example, in USA, the first day of the week is SUNDAY. But, it is MONDAY in France.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the first day of the week, @n
	*						else @c -1 if the method fails
	*/
	int GetFirstDayOfWeek(void) const;

	/**
	* Gets the greatest minimum value that the specified time field can have.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the greatest minimum value for the specified time field
	* @param[in]				field		The time field
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_INVALID_ARG			The specified @c field is invalid.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetGreatestMinTimeField(TimeField field) const;

	/**
	* Gets the least maximum value that the specified time field can have.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the least maximum value for the specified time field
	* @param[in]				field		The time field
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_INVALID_ARG			The specified @c field is invalid.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetLeastMaxTimeField(TimeField field) const;

	/**
	* Gets the maximum value that the specified time field can have.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the maximum value for the specified time field
	* @param[in]				field		The time field
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_INVALID_ARG			The specified @c field is invalid.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetMaxTimeField(TimeField field) const;

	/**
	* Gets the minimum value that the specified time field can have.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the minimum value for the specified time field
	* @param[in]				field		The time field
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_INVALID_ARG			The specified @c field is invalid.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetMinTimeField(TimeField field) const;

	/**
	* Gets the minimum number of days required in the first week of the year. @n
	* For example, if the first week is defined as the one that contains the first day of
	* the first month of a year, this method returns @c 1.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the minimum number of days required in the first week
	*/
	int GetMinDaysInFirstWeek(void) const;

	/**
	* Gets the date and time of the current instance of %Calendar.
	*
	* @since					2.0
	*
	* @return					An instance of Tizen::Base::DateTime with the current time in local time
	* @remarks					The time specified is local time.
	*/
	Tizen::Base::DateTime GetTime(void) const;

	/**
	* Gets the value of the specified time field.
	*
	* @since					2.0
	*
	* @return					An integer value indicating the value of the specified time field
	*							
	* @param[in]				field		The given time field
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_INVALID_ARG			The specified @c field is invalid.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					This method is semantically const, but may alter the instance in memory.
	*						All fields are re-computed if any field is invalid.
	* 						The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetTimeField(TimeField field) const;

	/**
	* Gets the current time of the instance in the @c long format.
	*
	* @since					2.0
	*
	* @return					An error code
	* @param[out]				millisec						The current time in milliseconds from starting day (Jan 1, 1.)
	* @exception				E_SUCCESS						The method is successful.
	* @exception				E_INVALID_STATE					In this method, the time fields of this instance are calculated. @n
	*												 If any time field value previously set is invalid, this exception is returned.
	* @exception				E_OUT_OF_RANGE					The value of the argument is out of the valid range defined by the method.
	*/
	result GetTimeInMillisec(long long& millisec) const;

	/**
	* Gets a reference to the time zone owned by this instance of %Calendar.
	*
	* @since					2.0
	*
	* @return					The TimeZone instance associated with the current instance of %Calendar
	* @remarks					The returned reference is valid only until the SetTimeZone() method is called or this instance of %Calendar is destroyed.
	* @see						SetTimeZone()
	*/
	TimeZone GetTimeZone(void) const;

	/**
	* Gets the calendar type of the current instance of %Calendar.
	*
	* @since					2.0
	*
	* @return					An instance of CalendarType representing the calendar type of the current instance of %Calendar @n
	*							For example, CALENDAR_GREGORIAN.
	*/
	virtual CalendarType GetType(void) const = 0;

	/**
	* Checks whether the current date for the instance of %Calendar is in Daylight Saving Time (DST).
	*
	* @since					2.0
	*
	* @return					An error code
	* @param[out]				isInDst			Set to @c true if the current date is in DST, @n
	*											else @c false
	* @exception				E_SUCCESS						The method is successful.
	* @exception			        E_INVALID_STATE         In this method, the time fields of this instance are calculated. @n 
	*									If any time field value previously set is invalid, this exception is returned.
	* @exception				E_OUT_OF_RANGE					A time field or its value is out of range. @n
	* 					In this method, the time fields of this instance are calculated. If the value of the time fields goes out of range, this exception is returned.
	*/
	virtual result IsInDst(bool& isInDst) const = 0;

	/**
	* Checks whether the date and time interpretation is lenient.
	*
	* @since					2.0
	*
	* @return					@c true if the date and time interpretation is set to lenient, @n
	*							else @c false
	*/
	bool IsLenient(void) const;

	/**
	* Checks whether the specified time field has a value.
	*
	* @since					2.0
	*
	* @return					@c true if the specified time field has a value, @n
	*							else @c false
	* @param[in]				field		The time field
	*/
	bool IsSet(TimeField field) const;

	/**
	* Creates an instance of %Calendar of the specified type with the GMT time zone and the system locale. @n
	* The time zone is used for the zone offset and the DST offset.
	* An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	* The weekdata are set as default values by the locale.
	*
	* @since					2.0
	*
	* @return					A pointer to the created %Calendar instance, @n
	*							else @c null if the method fails
	* @param[in]				calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(CalendarType calendarType = CALENDAR_GREGORIAN);

	/**
	* Creates an instance of %Calendar of the specified type with the specified time zone and the system locale. @n
	* The @c timeZone is used for the zone offset and the DST offset.
	* An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	* The weekdata are set as default values by the locale.
	*
	* @since					2.0
	*
	* @return					A pointer to the created %Calendar instance, @n
	*							else @c null if the method fails
	* @param[in]				timeZone			An instance of TimeZone
	* @param[in]				calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception				E_SYSTEM			A system error has occurred.
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(const TimeZone& timeZone, CalendarType calendarType = CALENDAR_GREGORIAN);

	/**
	* Creates an instance of %Calendar of the specified type with the specified @c locale and the GMT time zone. @n
	* The time zone is used for the zone offset and the DST offset.
	* An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	* The weekdata are set as default values by the specified @c locale.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since					2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompCalendarCreateInstanceNPage "here".
	* @endif
	*
	* @return					A pointer to the created %Calendar instance, @n
	*							else @c null if the method fails
	* @param[in]				locale				The locale for whose country the %Calendar instance is needed
	* @param[in]				calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_SYSTEM			A system error has occurred.
	* @exception				E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception                            E_INVALID_ARG           The specified @c locale is invalid. 
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(const Locale& locale, CalendarType calendarType = CALENDAR_GREGORIAN);

	/**
	* Creates an instance of %Calendar of the specified type with the specified time zone and @c locale. @n
	* The @c timeZone is used for the zone offset and the DST offset.
	* An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	* The weekdata are set as default values by the specified @c locale.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since					2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompCalendarCreateInstanceNPage "here".
	* @endif	
	*
	* @return					A pointer to the created %Calendar instance, @n
	*							else @c null if the method fails
	* @param[in]				timeZone			An instance of TimeZone
	* @param[in]				locale				The locale for whose country the %Calendar instance is needed
	* @param[in]				calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception				E_SUCCESS			The method is successful.
	* @exception				E_SYSTEM			A system error has occurred.
	* @exception				E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception                            E_INVALID_ARG           The specified @c locale is invalid. 
	* @remarks					The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(const TimeZone& timeZone, const Locale& locale, CalendarType calendarType = CALENDAR_GREGORIAN);

	/**
	* @if OSPCOMPAT
        * @page                    CompCalendarCreateInstanceNPage Compatibility for CreateInstanceN()
        * @section                   CompCalendarCreateInstanceNIssueSection Issues
        * Implementation of this method in OSP compatible applications has the following issue: @n
        * -# The method returns E_UNSUPPORTED_OPERATION if the locale is invalid.
        *
        * @section                 CompCalendarCreateInstanceNSolutionSection Resolutions
        * This issue has been resolved in Tizen. @n
	* @par When working in Tizen: 
        * -# The method returns E_INVALID_ARG if the locale is invalid.
	* @endif
        */

protected:
	/**
	* @enum AmPm
	*
	* Defines the AM/PM mode. @n
	* This is a.m./p.m. The indexing is 0-based.
	*
	* @since					2.0
	*/
	enum AmPm
	{
		AM, /**< The time is in A.M */
		PM  /**< The time is in P.M */
	};

	/**
	* @enum	CalendarLimitType
	*
	* Defines the calendar limitations.
	*
	* @since					2.0
	*/
	enum CalendarLimitType
	{
		CALENDAR_LIMIT_MINIMUM = 0,             /**< The minimum limit */
		CALENDAR_LIMIT_GREATEST_MINIMUM,        /**< The greatest minimum limit */
		CALENDAR_LIMIT_LEAST_MAXIMUM,           /**< The least maximum limit */
		CALENDAR_LIMIT_MAXIMUM,                 /**< The maximum limit */
		CALENDAR_LIMIT_COUNT                    /**< The number of limit type */
	};

	/**
	* @enum	StampValue
	*
	* Defines the stamp value.
	*
	* @since					2.0
	*/
	enum StampValue
	{
		UNSET = 0,              /**< Unset */
		COMPUTED,               /**< Computed */
		MINIMUM_USER_STAMP      /**< Minimum user stamp */
	};

	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since					2.0
	 *
	 * @see						Construct()
	 */
	Calendar(void);

	/**
	 * Initializes this instance of %Calendar.
	 *
	 * @since					2.0
	 *
	 * @return					An error code
	 * @exception				E_SUCCESS					The method is successful.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %Calendar with the specified parameter.
	 *
	 * @since					2.0
	 *
	 * @return					An error code
	 * @param[in]				calendar					The %Calendar instance to copy
	 * @exception				E_SUCCESS					The method is successful.
	 * @exception				E_SYSTEM					A system error has occurred.
	 *
	 */
	result Construct(const Calendar& calendar);

	/**
	 * Initializes this instance of %Calendar with the specified time zone and @c locale. @n
	 * The @c timeZone is used for the zone offset and the DST offset.
	 * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	 * The weekdata are set as default values by the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since					2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompCalendarConstructPage "here".       
	 * @endif
	 *
	 * @return					An error code
	 * @param[in]				timeZone					An instance of TimeZone
	 * @param[in]				locale						An instance of Locale
	 * @exception				E_SUCCESS					The method is successful.
	 * @exception                            E_INVALID_ARG           The specified @c locale is invalid. 
	 */
	result Construct(const Tizen::Locales::TimeZone& timeZone, const Locale& locale);

	/**
	 * @if OSPCOMPAT
         * @page                    CompCalendarConstructPage Compatibility for Construct()
         * @section                   CompCalendarConstructIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the locale is invalid.
         *
         * @section                 CompCalendarConstructSolutionSection Resolutions
         * This issue has been resolved in Tizen. @n
	 * @par When working in Tizen: 
         * -# The method returns E_INVALID_ARG if the locale is invalid.
	 * @endif	 
         */

	/**
	* Rolls up or down with a single unit of time on a given time field without changing larger fields. @n
	* When rolling on the MONTH field, other fields such as DATE field might conflict
	* and needs to be changed.
	*
	* @since					2.0
	*
	* @return					An error code
	* @param[in]				field							The time field to change
	* @param[in]				up								Set to @c true if the time field must be rolled upwards, @n
	*															else @c false
	* @exception				E_SUCCESS						The method is successful.
	* @exception				E_INVALID_STATE					In this method, the time fields of this instance are calculated. @n 
	*												If any time field value previously set is invalid, this exception is returned.
	* @exception				E_INVALID_ARG					The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET).
	* @exception				E_OUT_OF_RANGE		 A time field or its value is out of range. @n
	*							In this method, the time fields of this instance are calculated.
	*							If the value of the time fields goes out of range, this exception is returned.
	*/
	virtual result RollWithSingleUnit(TimeField field, bool up) = 0;

	/**
	 * Checks whether the current instance of %Calendar is equivalent to the specified instance of %Calendar.
	 *
	 * @since					2.0
	 *
	 * @return					@c true if the current instance of %Calendar is equivalent to the specified %Calendar instance, @n
	 *							else @c false
	 * @param[in]				calendar		The instance of %Calendar to compare with
	 * @remarks					If the specified %Calendar instance is equivalent to the current instance, the two instances behave
	 *							exactly the same, but they may be set to different times.
	 */
	virtual bool IsEquivalentTo(const Calendar& calendar) const;

	/**
	* Computes the time field value. @n
	* Converts the current millisecond time value to TimeField. @n
	* This allows synching up the time field values with a new time that is set for the calendar.
	*
	* @since						2.0
	*
	* @return						An error code
	* @exception					E_SUCCESS					The method is successful.
	* @exception					E_OUT_OF_RANGE	The time fields contain an invalid value. @n
	*								In this method, the time fields of this instance are calculated. If the value of the time fields goes out of range, this exception is returned.
	*/
	virtual result ComputeTimeFields(void) = 0;

	/**
	* Computes the time value. @n
	* Converts the current values of time field to the millisecond time value.
	*
	* @since						2.0
	*
	* @return						An error code
	* @exception					E_SUCCESS					The method is successful.
	* @exception					E_INVALID_STATE				A value of the internal time field is invalid.
	*/
	virtual result ComputeTime(void) = 0;

	/**
	* Gets the length of the specified month.
	*
	* @since						2.0
	*
	* @return						An integer value indicating the number of days in the specified month
	* @param[in]					extendedYear				An extended year
	* @param[in]					month						A month
	*/
	virtual int GetMonthLength(int extendedYear, int month) const = 0;

	/**
	* Handles the limits of different types. @n
	* Derived classes must implement this method for the following fields:
	* TIME_FIELD_ERA, TIME_FIELD_YEAR, TIME_FIELD_MONTH, TIME_FIELD_WEEK_OF_YEAR, TIME_FIELD_WEEK_OF_MONTH,
	* TIME_FIELD_DAY_OF_MONTH, TIME_FIELD_DAY_OF_YEAR, TIME_FIELD_DAY_OF_WEEK_IN_MONTH, TIME_FIELD_YEAR_WOY,
	* TIME_FIELD_EXTENDED_YEAR.
	*
	* @since						2.0
	*
	* @return						The limit of the specified field
	* @param[in]					field						The time field
	* @param[in]					limitType					The type of limit
	*/
	virtual int HandleGetLimit(TimeField field, CalendarLimitType limitType) const = 0;

	/*
	* Creates and returns a polymorphic copy of this calendar.
	*
	* @since						2.0
	*
	* @return    					A polymorphic copy of this calendar
	*/
	virtual Tizen::Locales::Calendar* CloneN(void) const = 0;

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Calendar_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Calendar_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Calendar_Reserved3(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Calendar_Reserved4(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void Calendar_Reserved5(void) { }

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects. Use CloneN() to get an exact copy of the instance.
	 */
	Calendar(const Calendar& calendar);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects. Use CloneN() to get an exact copy of the instance.
	 */
	Calendar& operator =(const Calendar& calendar);

public:
	/**
	 * Millisecond constants for one day.
	 *
	 * @since	2.0
	 */
	static const int ONE_DAY_IN_MILLISEC = 86400000;

	/**
	 * Millisecond constants for one hour.
	 *
	 * @since	2.0
	 */
	static const int ONE_HOUR_IN_MILLISEC = 60 * 60 * 1000;

	/**
	 * Millisecond constants for one minute.
	 *
	 * @since	2.0
	 */
	static const int ONE_MINUTE_IN_MILLISEC = 60000;

	/**
	 * Millisecond constants for one second.
	 *
	 * @since	2.0
	 */
	static const int ONE_SECOND_IN_MILLISEC = 1000;

	/**
	 * Millisecond constants for one week.
	 *
	 * @since	2.0
	 */
	static const long long ONE_WEEK_IN_MILLISEC = 7 * ONE_DAY_IN_MILLISEC;

protected:
	/**
	 * The field values for the currently set time for this calendar.
	 */
	int _timeFields[TIME_FIELD_FIELD_COUNT];

	/**
	 * Pseudo-time-stamps which specify when each field is set.
	 * There are two special values - UNSET and INTERNALLY_SET.
	 */
	int _stamp[TIME_FIELD_FIELD_COUNT];

	/**
	 * The flags which tell if a specified time field for the calendar is set.
	 */
	bool _isSet[TIME_FIELD_FIELD_COUNT];

	long long _time; // UTC time
	Tizen::Locales::TimeZone _timeZone;

	bool _isTimeSet;
	bool _areFieldsSet;
	bool _areAllFieldsSet;
	int _nextStamp;
	bool _isLenient;
	bool _isConstructed;

	// Mask values for calendar fields
	static const int ERA_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_ERA);
	static const int YEAR_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_YEAR);
	static const int MONTH_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_MONTH);
	static const int WEEK_OF_YEAR_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_WEEK_OF_YEAR);
	static const int WEEK_OF_MONTH_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_WEEK_OF_MONTH);
	static const int DAY_OF_MONTH_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_DAY_OF_MONTH);
	static const int DAY_OF_YEAR_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_DAY_OF_YEAR);
	static const int DAY_OF_WEEK_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_DAY_OF_WEEK);
	static const int DAY_OF_WEEK_IN_MONTH_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_DAY_OF_WEEK_IN_MONTH);
	static const int AM_PM_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_AM_PM);
	static const int HOUR_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_HOUR);
	static const int HOUR_OF_DAY_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_HOUR_OF_DAY);
	static const int MINUTE_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_MINUTE);
	static const int SECOND_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_SECOND);
	static const int MILLISECOND_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_MILLISECOND);
	static const int ZONE_OFFSET_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_ZONE_OFFSET);
	static const int DST_OFFSET_MASK = GET_TIME_FIELD_MASK(TIME_FIELD_DST_OFFSET);
	static const int ALL_FIELDS = GET_TIME_FIELD_MASK(TIME_FIELD_FIELD_COUNT) - 1;

//private:
	friend class _CalendarImpl;
	class _CalendarImpl* _pCalendarImpl;

}; // Calendar

}} // Tizen::Locales

#endif //_FLCL_CALENDAR_H_
