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
 * @file		FLclGregorianCalendar.h
 * @brief		This is the header file for the %GregorianCalendar class.
 *
 * This header file contains the declarations of the %GregorianCalendar class.
 */
#ifndef _FLCL_GREGORIAN_CALENDAR_H_
#define _FLCL_GREGORIAN_CALENDAR_H_

#include <FBase.h>

#include <FLclCalendar.h>
#include <FLclLocale.h>
#include <FLclTimeZone.h>

namespace Tizen { namespace Locales
{

/**
 * @class		GregorianCalendar
 * @brief		This class is a concrete subclass of calendar and provides the Gregorian calendar that is the most commonly used standard calendar.
 *
 * @since		2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %GregorianCalendar class is a concrete subclass of calendar and provides the Gregorian calendar that is the most commonly used standard calendar.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/gregorian_calendar.htm">Gregorian Calendar</a>.
 *
 * @see Tizen::Locales::Locale
 * @see Tizen::Locales::TimeZone
 *
 * The following example demonstrates how to use the %GregorianCalendar class.
 * @code
 #include <FBase.h>
 #include <FLocales.h>

 using namespace Tizen::Base;
 using namespace Tizen::Locales;

 void
 MyClass::GregorianCalendarExample(void)
 {
	Calendar* pGregorianCalendar = Calendar::CreateInstanceN(CALENDAR_GREGORIAN);

	pGregorianCalendar->SetTimeField(TIME_FIELD_YEAR, 2005);
	pGregorianCalendar->SetTimeField(TIME_FIELD_MONTH, JANUARY);
	pGregorianCalendar->SetTimeField(TIME_FIELD_DAY_OF_MONTH, 3);

	int dayOfWeek = pGregorianCalendar->GetTimeField(TIME_FIELD_DAY_OF_WEEK);// It is Monday.

	pGregorianCalendar->Clear();
	pGregorianCalendar->SetTimeField(TIME_FIELD_YEAR, 1972);
	pGregorianCalendar->SetTimeField(TIME_FIELD_MONTH, OCTOBER);
	pGregorianCalendar->SetTimeField(TIME_FIELD_DAY_OF_MONTH, 26); // It is Thursday

	pGregorianCalendar->AddTimeField(TIME_FIELD_DAY_OF_MONTH, 1);
	dayOfWeek = pGregorianCalendar->GetTimeField(TIME_FIELD_DAY_OF_WEEK); // It is Friday.
}
 @endcode
 *
 */

class _OSP_EXPORT_ GregorianCalendar
	: public Calendar
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since			2.0
	 *
	 * @see				Construct()
	 */
	GregorianCalendar(void);


	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Locales::Calendar::~Calendar().
	 *
	 * @since			2.0
	 */
	virtual ~GregorianCalendar(void);


	/**
	 * Initializes this instance of %GregorianCalendar with the current GMT time zone and the system locale.
         * The time zone is used for the zone offset and the DST offset.
         * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set and weekend cease.
         * The weekdata are set as default values by the locale.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result Construct(void);


	/**
	 * Initializes this instance of %GregorianCalendar with the specified parameter.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		gc							An instance of %GregorianCalendar to copy
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result Construct(const GregorianCalendar& gc);


	/**
	 * Initializes this instance of %GregorianCalendar based on the current time in the specified time zone with the system locale. @n 
	 * The @c timeZone is used for the zone offset and the DST offset.
	 * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	 * The weekdata are set as default values by the locale. 
  	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		timeZone					An instance of TimeZone
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result Construct(const TimeZone& timeZone);


	/**
	 * Initializes this instance of %GregorianCalendar based on the current time in the GMT time zone with the specified @c locale.
	 * The time zone is used for the zone offset and the DST offset.
	 * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	 * The weekdata are set as default values by the specified @c locale.
	 *
	 * @if OSPCOMPAT 
	 * @brief <i> [Compatibility] </i>
	 * @endif 
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompGregorianCalendarConstructPage "here".   
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		locale						An instance of Locale
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception                            E_INVALID_ARG           The specified @c locale is invalid. 
	 */
	result Construct(const Locale& locale);


	/**
	 * Initializes this instance of %GregorianCalendar based on the current time in the specified time zone with the specified system locale. @n
	 * The @c timeZone is used for the zone offset and the DST offset.
	 * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	 * The weekdata are set as default values by the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompGregorianCalendarConstructPage "here".   
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		timeZone					An instance of TimeZone
	 * @param[in]		locale						An instance of Locale
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception                            E_INVALID_ARG           The specified @c locale is invalid. 
	 */
	result Construct(const TimeZone& timeZone, const Locale& locale);

	/**
	 * @if OSPCOMPAT
	 * @page                    CompGregorianCalendarConstructPage Compatibility for Construct()
	 * @section                   CompGregorianCalendarConstructIssueSection Issues
	 * Implementation of this method in OSP compatible applications has the following issue: @n
	 * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
	 *
	 * @section                 CompGregorianCalendarConstructSolutionSection Resolutions
	 * This issue has been resolved in Tizen.
	 * @par When working in Tizen:
	 * -# The method returns E_INVALID_ARG if the @c locale is invalid.
	 * @endif
	*/

	/**
	 * Initializes this instance of %GregorianCalendar based on the specified @c year, @c month, @c day, @c hour, @c minute, and @c second
	 * in the GMT time zone with the system locale. @n
	 * The time zone is used for the zone offset and the DST offset.
	 * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	 * The weekdata are set as default values by the locale.
	 * The Gregorian calendar is lenient: time fields are normalized when the user calls the Calendar::GetTimeField() method.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		year						An integer value used to set the year time field
	 * @param[in]		month						An integer value used to set the month time field @n
	 *												The indexing is 1-based. Therefore, 1 means January.
	 * @param[in]		day							An integer value used to set the date time field
	 * @param[in]		hour						An integer value used to set the hour time field
	 * @param[in]		minute						An integer value used to set the minute time field
	 * @param[in]		second						An integer value used to set the second time field
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception           E_INVALID_ARG           An argument is invalid.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception		E_OUT_OF_RANGE				In this method, time fields of this instance are calculated. @n
	 *                                                If the value of the time fields goes out of range, this exception is returned.
	 */
	result Construct(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);


	/**
	 * Initializes this instance of %GregorianCalendar based on the specified date and time in the GMT time zone with the system locale. @n
	 * The time zone is used for the zone offset and the DST offset.
	 * An instance has weekdata which are the first of week, minimal days in the first week, weekend on set, and weekend cease.
	 * The weekdata are set as default values by the locale.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		dateTime					An instance of Tizen::Base::DateTime
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception           E_INVALID_ARG  		The specified @c dateTime is invalid.
	 * @exception		E_OUT_OF_RANGE				In this method, time fields of this instance are calculated. @n
	 *                                                If the value of the time fields goes out of range, this exception is returned.
	 */
	result Construct(const Tizen::Base::DateTime& dateTime);


	/**
	 * Adds the specified amount to the specified time field, based on the calendar rules. @n
	 * It is equivalent to calling Set(field, GetTimeField(field)+amount) with two adjustments. @n
	 *
	 * @b Add @b Rule1: The value of @c field after the call minus the value of @c field before the call is delta, modulo any overflow that has occurred in @c field.
	 * Overflow occurs when the @c field value exceeds its range and, as a result, the next larger field is incremented or decremented and the @c field value is adjusted back into its range. @n
	 *
	 * @b Add @b Rule2: If a smaller field is expected to be invariant, but it is impossible for it to be equal to its prior value because of
	 * changes in its minimum or maximum value after the @c field value is changed, then its value is adjusted to the closest possible value. @n
	 *
	 * A smaller field represents a smaller unit of time. The TIME_FIELD_HOUR field is smaller than the TIME_FIELD_DAY_OF_MONTH field.
	 * No adjustment is made to smaller fields that are not expected to be invariant.
	 * The calendar system determines what fields are expected to be invariant. @n
	 *
	 * In addition, this method forces re-computation of the calendar's milliseconds and all time fields immediately.
	 * @n
	 * For example, consider a %GregorianCalendar set to Oct. 31. 2004. Calling AddTimeField(TIME_FIELD_MONTH, 13) sets the calendar to Nov. 30. 2005.
	 * The TIME_FIELD_MONTH field is set to TIME_FIELD_NOVEMBER by @b Rule1, since adding 13 months to October gives November of the next year. Since
	 * the TIME_FIELD_DAY_OF_MONTH cannot be 31 in November in a %GregorianCalendar, TIME_FIELD_DAY_OF_MONTH is set to 30 by @b Rule2.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		field						The time field
	 * @param[in]		amount						The amount to add
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				The specified @c field is invalid.
	 * @exception           E_OUT_OF_RANGE          In this method, time fields of this instance are calculated. @n
	 *                                                                              If the value of the time fields goes out of range, this exception is returned. 
  	 * @remarks			The TIME_FIELD_EXTENDED_YEAR and TIME_FIELD_YEAR_WOY fields cannot be added.
	 */
	virtual result AddTimeField(TimeField field, int amount);


	/**
	 * Gets the actual minimum value that the specified time field can have, given the current date. @n
	 * For the Gregorian calendar, this is the same as Calendar::GetMinTimeField() and Calendar::GetGreatestMinTimeField().
	 *
	 * @since			2.0
	 *
	 * @return			An integer value indicating the actual minimum value
	 * @param[in]                           field           The time field
	 * @exception                           E_SUCCESS                       The method is successful.
	 * @exception                           E_INVALID_ARG                   The specified time field is invalid.
	 * @remarks                                     The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetActualMinTimeField(TimeField field) const;


	/**
	 * Gets the actual maximum value that the specified time field can have, given the current date. @n
	 * For example, if the current date is "Feb. 3. 2004", then the maximum value of the DATE field is 29.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value indicating the actual maximum value
	 * @param[in]                           field           The time field
	 * @exception                           E_SUCCESS                       The method is successful.
	 * @exception                           E_INVALID_ARG                   The specified time field is invalid.

	 * @remarks                                     The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetActualMaxTimeField(TimeField field) const;


	/*
	 * Gets the Gregorian Calendar change date. @n
	 * This is the point when the switch from Julian dates to Gregorian dates occurred.
	 * Default is 00:00:00 local time, October 15, 1582. Previous to this the time and date are Julian dates.
	 *
	 * @since			2.0
	 *
	 * @return			The milliseconds which is the Gregorian cutover time for this calendar
	 */
	long long GetGregorianChange(void) const;


	/**
	 * Gets the calendar type of the current instance.
	 *
	 * @since			2.0
	 *
	 * @return			An instance of CalendarType representing the calendar type of the current instance of Calendar @n
	 *					In this case, CALENDAR_GREGORIAN.
	 */
	virtual CalendarType GetType(void) const;

	/**
	 * Checks whether the current date for the current instance is in Daylight Saving Time (DST).
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[out]		isInDst						Set to @c true if the current date is in DST, @n
	 *												else @c false
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_RANGE		In this method, time fields of this instance are calculated. @n
	 * 										If the value of the time fields goes out of range, this exception is returned.
	 * @exception           E_INVALID_STATE         In this method, time fields of this instance are calculated. @n 
	 *                     If any time field value previously set is invalid, this exception is returned.
	 */
	virtual result IsInDst(bool& isInDst) const;


	/**
	 * Checks whether the specified year is a leap year.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the specified year is a leap year, @n
	 *					else @c false
	 * @param[in]		year						The year to check
	 */
	bool IsLeapYear(int year) const;


	/**
	 * Sets the Gregorian Calendar change date. @n
	 * This is the point when the switch from Julian dates to Gregorian dates occurred.
	 * Default is 00:00:00 local time, Oct 15, 1582. Previous to this, dates are in the Julian calendar.
	 *
	 * To obtain a pure Julian calendar, set the change @c change to MAX_MILLISECOND.
	 * To obtain a pure Gregorian calendar, set the change @c change to MIN_MILLISECOND.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		change						The given Gregorian cutover date
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result SetGregorianChange(long long change);

	/**
	 * Rolls up or down as per the specified amount in the specified field. @n
	 * This method overrides Calendar(). @n
	 * For more details, refer to Tizen::Locales::Calendar::Roll(TimeField, int).
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		field						The time field
	 * @param[in]		amount						The amount to roll up/down
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				In this method, time fields of this instance are calculated. @n
	 *									If any time field value previously set is invalid, this exception is returned.
	 * @exception		E_INVALID_ARG				The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET).
	 * @exception		E_OUT_OF_RANGE		        In this method, time fields of this instance are calculated. @n
	 *                                               If the value of the time fields goes out of range, this exception is returned.
	 */
	virtual result Roll(TimeField field, int amount);


	/*
	 * Gets the millisecond which is midnight, local time at or before the Gregorian cutover.
	 *
	 * @since			2.0
	 *
	 * @return			The millisecond which is midnight, local time at or before the Gregorian cutover
	 *					If this method fails, @c -1 is returned.
	 *					The specific error code can be accessed using the GetLastResult() method.
	 */
	long long GetNormalizedGregorianCutover(void) const;

	/*
	 * Gets the year of the Gregorian cutover, with @c 0 representing 1 BC, @c -1 representing 2 BC, and so on.
	 *
	 * @since			2.0
	 *
	 * @return			The year of the Gregorian cutover
	 *					If this method fails, @c -1 is returned.
	 *					The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetGregorianCutoverYear(void) const;

	/*
	 * Gets the Julian day number of the Gregorian cutover.
	 *
	 * @since			2.0
	 *
	 * @return			The Julian day number of the Gregorian cutover
	 */
	int GetCutoverJulianDay(void) const;


	/**
	 * Checks whether the current calendar is a Gregorian calendar or not.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the current calendar is a Gregorian calendar, @n
	 *					else @c false
	 */
	bool IsGregorian() const;


	/**
	 * Gets the current time of the instance in milliseconds from epoch.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[out]		millisec					The current time in milliseconds from the epoch
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				If any time field value previously set is invalid, this exception is returned.
	 * @exception		E_OUT_OF_RANGE				A time field or its value is out of range.
	 */
	result GetTimeInMillisecFromEpoch(long long& millisec) const;


	/**
	 * Sets the current time of the instance with the specified milliseconds value.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		millisec					The new time in milliseconds from the epoch
	 * @exception		E_OUT_OF_RANGE				A time field or its value is out of range.
	 */
	result SetTimeInMillisecFromEpoch(long long millisec);


	/**
	 * Converts the 1970-epoch day number to the Gregorian year, month, date, day of week, and day of year.
	 *
	 * @since			2.0
	 *
	 * @param[in]		day							The 1970-epoch day number
	 * @param[out]		year						The year to convert
	 * @param[out]		month						The month to convert
	 * @param[out]		dayOfMonth					The date to convert
	 * @param[out]		dayOfWeek					The day of week to convert
	 * @param[out]		dayOfYear					The day of year to convert
	 */
	static void DayToFields(int day, int& year, int& month, int& dayOfMonth, int& dayOfWeek, int& dayOfYear);

private:
	/**
	 * @enum		GregorianCalendarEras
	 *
	 * Defines Era for Gregorian calendar. The indexing is 0-based.
	 */
	enum GregorianCalendarEras
	{
		GREGORIAN_CALENDAR_BC = 0,      // BC
		GREGORIAN_CALENDAR_AD = 1,      // AD

		GREGORIAN_CALENDAR_BCE = 0,     // BCE
		GREGORIAN_CALENDAR_CE = 1,      // CE
	};

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	GregorianCalendar(const GregorianCalendar& gregorianCalendar);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	GregorianCalendar& operator =(const GregorianCalendar& gregorianCalendar);

	// added for backward compatibility
	virtual result RollWithSingleUnit(TimeField field, bool up);
	virtual result ComputeTimeFields(void);
	virtual result ComputeTime(void);
	virtual int GetMonthLength(int extendedYear, int month) const;
	virtual int HandleGetLimit(TimeField field, CalendarLimitType limitType) const;
	virtual Calendar* CloneN(void) const;

public:
	/**
	 * Defines the length of months.
	 *
	 * @since 2.0
	 */
	static const int MONTH_LENGTH[24];

	/**
	 * Defines the days of a year.
	 *
	 * @since 2.0
	 */
	static const int NUM_DAYS[24];

	/**
	 * The Gregorian cutover number for Julian day.
	 *
	 * @since 2.0
	 */
	static const int CUTOVER_JULIAN_DAY = 2299161;      // Oct 15, 1582

	/**
	 * The epoch year.
	 *
	 * @since 2.0
	 */
	static const int EPOCH_YEAR = 1970;

	/**
	 * The epoch start for Julian day.
	 *
	 * @since 2.0
	 */
	static const int EPOCH_START_AS_JULIAN_DAY = 2440588; // Jan 1, 1970(Gregorian)

	/**
	 * Jan 1, 1 epoch start for Julian day.
	 *
	 * @since 2.0
	 */
	static const int JAN_1_1_JULIAN_DAY = 1721426;  // Jan 1, 1 CE Gregorian

	/**
	 * Temporary value for the Gregorian cutover.
	 *
	 * @since 2.0
	 */
	static const long long PAPAL_CUTOVER =
		((long long) (GregorianCalendar::CUTOVER_JULIAN_DAY -
					  GregorianCalendar::EPOCH_START_AS_JULIAN_DAY) * (long long) ONE_DAY_IN_MILLISEC);

	/**
	 * Maximum value for longlong.
	 *
	 * @since 2.0
	 */
	static const long long MAX_LONGLONG = (2 ^ 63) - 1;

	/**
	 * Minimum value for longlong.
	 *
	 * @since 2.0
	 */
	static const long long MIN_LONGLONG = -1 * (2 ^ 63);

	/**
	 * Maximum value for Julian day.
	 *
	 * @since 2.0
	 */
	static const int MAX_JULIAN = 0x7F000000;

	/**
	 * Minimum value for Julian day.
	 *
	 * @since 2.0
	 */
	static const int MIN_JULIAN = -0x7F000000;

	/**
	 * Maximum millisecond value for Julian day.
	 *
	 * @since 2.0
	 */
	static const long long MAX_MILLISEC = ((GregorianCalendar::MAX_JULIAN - GregorianCalendar::EPOCH_START_AS_JULIAN_DAY) * (long long) ONE_DAY_IN_MILLISEC);

	/**
	 * Minimum millisecond value for Julian day.
	 *
	 * @since 2.0
	 */
	static const long long MIN_MILLISEC = ((GregorianCalendar::MIN_JULIAN - GregorianCalendar::EPOCH_START_AS_JULIAN_DAY) * (long long) ONE_DAY_IN_MILLISEC);

	/**
	 * Epoch offset in millisecond value.
	 *
	 * @since 2.0
	 */
	static const long long EPOCH_OFFSET_IN_MILLISEC = 62135596800000LL; // Jan 1, 1970

	/**
	 * Default Gregorian cutover.
	 *
	 * @since 2.0
	 */
	static const long long DEFAULT_GREGORIAN_CUTOVER = -12219292800000LL;

private:
	long long __normalizedGregorianCutover; // = __gregorianCutover;
	int __gregorianCutoverYear; // 1582
	int __cutoverJulianDay;

	friend class _GregorianCalendarImpl;
	class _GregorianCalendarImpl* __pGregorianCalendarImpl;

}; // GregorianCalendar

}} // Tizen::Locales

#endif //_FLCL_GREGORIAN_CALENDAR_H_
