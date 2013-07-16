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
 * @file		FBaseDateTime.h
 * @brief		This is the header file for the %DateTime class.
 *
 * This header file contains the declarations of the %DateTime class.
 */
#ifndef _FBASE_DATE_TIME_H_
#define _FBASE_DATE_TIME_H_

#include <FBaseObject.h>
#include <FBaseTimeSpan.h>
#include <FBaseString.h>
#include <FBaseDouble.h>


namespace Tizen { namespace Base
{
/**
 *	@class	DateTime
 *	@brief	This class represents the date and time as per the Gregorian calendar.
 *
 *	@since 2.0
 *
 *	The %DateTime class represents dates and times with values ranging from 12:00:00.000 midnight,
 *	January 1, 1 to 11:59:59.999 P.M., December 31, 9999 in the Gregorian calendar. It
 *	provides methods for conversion between the time formats.
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/datetime_timespan.htm">DateTime and TimeSpan</a>.
 *
 *  The following example demonstrates how to use the %DateTime class.

 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	// This method sets both current local time and UTC time.
 *	void
 *	MyClass::DateTimeSample(void)
 *	{
 *		DateTime dt;
 *		int year, month, day;
 *
 *		dt.SetValue(2009, 10, 25);
 *
 *		dt.AddYears(10);
 *		dt.AddMonths(3);
 *		dt.AddDays(5);
 *
 *		// Gets values
 *		year = dt.GetYear();		//	2020
 *		month = dt.GetMonth();		//	1
 *		day = dt.GetDay();			//	30
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ DateTime
	: public Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since 2.0
	 *
	 *	@remarks	The value of the instance is the same as the value of the instance returned by the GetMinValue() method.
	 */
	DateTime(void);

	/**
	 *	Copying of objects using this copy constructor is allowed.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]  value		The %DateTime instance to copy
	 */
	DateTime(const DateTime& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~DateTime(void);

	/**
	 *	Sets the current instance of %DateTime to the value of the specified instance of TimeSpan since the minimum date (GetMinValue()).
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value	An instance of TimeSpan
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result SetValue(const TimeSpan& value);

	/**
	 *	Sets the current instance of %DateTime to the value of the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@param[in]	value	An instance of %DateTime
	 */
	void SetValue(const DateTime& value);

	/**
	 *	Sets the current instance of %DateTime to the specified @c year, @c month, @c day, @c hour, @c minute, and @c second.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	year				The year to set
	 *	@param[in]	month				The month to set
	 *	@param[in]	day					The day to set
	 *	@param[in]	hour				The hour to set
	 *	@param[in]	minute				The minute set
	 *	@param[in]	second				The second to set
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									 Either the arguments are greater than the value returned by GetMaxValue() or
	 *									are less than the value returned by GetMinValue(), or
	 *									 the arguments contain invalid values.
	 *									For example, day is 31 when month is 2.
	 */
	result SetValue(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);

	/**
	 *	Sets the current instance of %DateTime to the specified @c year, @c month, @c day, @c hour, @c minute, @c second, and @c millisecond.
	 *
	 *	@since 2.1
	 *
	 *	@return			An error code
	 *	@param[in]	year				The year to set
	 *	@param[in]	month				The month to set
	 *	@param[in]	day					The day to set
	 *	@param[in]	hour				The hour to set
	 *	@param[in]	minute				The minute set
	 *	@param[in]	second				The second to set
	 *	@param[in]	millisecond			The millisecond to set
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									Either the arguments are greater than the value returned by GetMaxValue() or
	 *									are less than the value returned by GetMinValue(), or
	 *									the arguments contain invalid values.
	 *									For example, day is 31 when month is 2.
	 */
	result SetValue(int year, int month, int day, int hour, int minute, int second, int millisecond);

	/**
	 *	Sets the current instance of %DateTime with the specified number of %ticks.
	 *	The tick value of type @c long @c long represents dates and times ranging from January 1, 1 A.D. 00:00:00.000 am.
	 *
	 *	@since	2.1
	 *
	 *	@return			An error code
	 *	@param[in]	ticks	The number of ticks
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 *									Either the arguments are greater than the value returned by GetMaxValue() or
	 *									are less than the value returned by GetMinValue(), or
	 *									the arguments contain invalid values.
	 *									For example, day is 31 when month is 2.
	 */
	result SetValue(long long ticks);

	/**
	 *	Copying of objects using this copy assignment operator is allowed.
	 *
	 *	@since 2.0
	 *
	 *	@return			A reference to the current object
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	DateTime& operator =(const DateTime& rhs);

	/**
	 *	Checks whether the current instance of %DateTime is equivalent to the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the current instance is equivalent to the specified instance, @n
	 *               else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator ==(const DateTime& rhs) const;

	/**
	 *	Checks whether the current instance of %DateTime is not equivalent to the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the current instance is not equivalent to the specified instance, @n
	 *           else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator !=(const DateTime& rhs) const;

	/**
	 *	Checks whether the value of the current instance of %DateTime is less than the value of the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the value of the current instance is less than the value of the specified instance, @n
	 *                   else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator <(const DateTime& rhs) const;

	/**
	 *	Checks whether the value of the current instance of %DateTime is greater than the value of the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the value of the current instance is greater than the value of the specified instance, @n
	 *                   else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator >(const DateTime& rhs) const;

	/**
	 *	Checks whether the value of the current instance of %DateTime is less than or equal to the value of the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the value of the current instance is less than or equal to the value of the specified instance, @n
	 *                   else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator <=(const DateTime& rhs) const;

	/**
	 *	Checks whether the value of the current instance of %DateTime is greater than or equal to the value of the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			@c true if the value of the current instance is greater than or equal to the value of the specified instance, @n
	 *                   else @c false
	 *	@param[in]	rhs	An instance of %DateTime
	 */
	bool operator >=(const DateTime& rhs) const;

	/**
	 *	Adds the specified time span to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	t					The time span to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result Add(const TimeSpan& t);

	/**
	 *	Adds the specified number of days to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	days				The number of days to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddDays(int days);

	/**
	 *	Adds the specified number of hours to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	hours				The number of hours to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddHours(int hours);

	/**
	 *	Adds the specified number of minutes to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	minutes				The number of minutes to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddMinutes(int minutes);

	/**
	 *	Adds the specified number of months to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	months				The number of months to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddMonths(int months);

	/**
	 *	Adds the specified number of seconds to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	seconds				The number of seconds to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddSeconds(int seconds);

	/**
	 *	Adds a specified number of milliseconds to the instance of %DateTime.
	 *
	 *	@since 2.1
	 *
	 *	@return	An error code
	 *	@param[in]	milliseconds		The number of milliseconds to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddMilliseconds(long long milliseconds);

	/**
	 *	Adds a specified number of ticks to the instance of %DateTime.
	 *
	 *	@since 2.1
	 *
	 *	@return	An error code
	 *	@param[in]	ticks				The number of ticks to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddTicks(long long ticks);

	/**
	 *	Adds the specified number of years to the instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	An error code
	 *	@param[in]	years				The number of years to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result AddYears(int years);

	/**
	 *	Compares two specified instances of %DateTime. @n
	 *	The two instances must be in the same time zone to make a meaningful comparison.
	 *
	 *	@since 2.0
	 *
	 *  @return			A 32-bit @c signed integer value
	 *	@code
	 *	<  0  if the value of @c dt1 is less than the value of @c dt2
	 *	== 0  if the value of @c dt1 is equal to the value of @c dt2
	 *	>  0  if the value of @c dt1 is greater than the value of @c dt2
	 *	@endcode
	 *	@param[in]	dt1	An instance of %DateTime
	 *	@param[in]	dt2	An instance of %DateTime
	 */
	static int Compare(const DateTime& dt1, const DateTime& dt2);

	/**
	 *	Compares the value of the current instance of %DateTime with the value of the specified instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *  @return			A 32-bit @c signed integer value
	 *	@code
	 *	<  0  if the value of the current instance is less than value of the specified instance
	 *	== 0  if the value of the current instance is equal to value of the specified instance
	 *	>  0  if the value of the current instance is greater than value of the specified instance
	 *	@endcode
	 *	@param[in]		value	An instance of %DateTime
	 */
	int CompareTo(const DateTime& value) const;

	/**
	 *	Checks whether the specified instance of Object is equivalent to the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the specified instance of Object is equivalent to the current instance of %DateTime, @n
	 *               else @c false
	 *	@param[in]	obj The object to compare with the current instance of %DateTime
	 *	@see			Tizen::Base::Object::GetHashCode()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance of %DateTime. @n
	 *	The hash value is calculated as (GetTime() ^ (GetTime() >> 16)).
	 *
	 *	@since 2.0
	 *
	 *	@return		The hash value of the current instance of %DateTime
	 *	@see		Tizen::Base::Object::Equals()
	 */
	virtual int GetHashCode(void) const;

	/**
	 *	Gets the time span since the midnight of the date represented by the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		An instance of TimeSpan
	 */
	TimeSpan GetTimeOfDay(void) const;

	/**
	 *	Gets the number of @c days in the specified @c month of the specified @c year.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	year				The year
	 *	@param[in]	month				The month
	 *	@param[out]	days				The number of days
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									 @c year must be a value between @c 1 and @c 9999 and @c month must be a value between @c 1 and @c 12.
	 */
	static result GetDaysInMonth(int year, int month, int& days);

	/**
	 *	Subtracts the specified time span from the value of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return			An error code
	 *	@param[in]	t					The time span to deduct
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue() or @n
	 *									is less than the value returned by GetMinValue().
	 */
	result Subtract(const TimeSpan& t);

	/**
	 *	Represents the current instance of %DateTime as a string.
	 *
	 *	@since 2.0
	 *
	 *	@return		A string containing Unicode representation of the value of the current instance of %DateTime
	 *	@remarks	The format of the String representation is "mm/dd/yyyy hh:mm:ss".
	 *	@remarks	Use the Tizen::Locale namespace for a string of the locale-specific representation.
	 *
	 */
	String ToString(void) const;

	/**
	 * Parses the specified String representation of the date and time value.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str		A String representation of a date and time value
	 * @param[out]	dt		The result of the method
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_FORMAT		The specified string is in an invalid format.
	 * @exception	E_OUT_OF_RANGE			The specified string contains an invalid value. @n
	 *									     1) The resulting value of %DateTime is greater than the value returned by GetMaxValue()
	 *									    or is less than the value returned by GetMinValue(). @n
	 *									     2) The specified string contains an invalid value.
	 *									    For example, day is 31 when the month is 2.
	 * @remarks
	 *				- The format of the string is "mm/dd/yyyy hh:mm:ss".
	 *				- This method guarantees that the original value of out-parameter is not changed when the method returns error.
	 */
	static result Parse(const String& str, DateTime& dt);

	/**
	 *	Gets the year of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return	 An integer value indicating the year of the current instance of %DateTime
	 */
	int GetYear(void) const;

	/**
	 *	Gets the month of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the month of the current instance of %DateTime
	 */
	int GetMonth(void) const;

	/**
	 *	Gets the day of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the day of the current instance of %DateTime
	 */
	int GetDay(void) const;

	/**
	 *	Gets the hour of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the hour of the current instance of %DateTime
	 */
	int GetHour(void) const;

	/**
	 *	Gets the minute of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the minute of the current instance of %DateTime
	 */
	int GetMinute(void) const;

	/**
	 *	Gets the second of the current instance of %DateTime.
	 *
	 *	@since 2.0
	 *
	 *	@return		An integer value indicating the second of the current instance of %DateTime
	 */
	int GetSecond(void) const;

	/**
	 *	Gets the millisecond of the current instance of %DateTime.
	 *
	 *	@since	2.1
	 *
	 *	@return		An integer value indicating the millisecond of the current instance of %DateTime
	 */
	int GetMillisecond(void) const;

	/**
	 *	Gets the number of ticks in 1 second.
	 *
	 *	@since	2.1
	 *
	 *	@return		The number of ticks in 1 second.
	 */
	static int GetTicksPerSecond(void);

	/**
	 *	Gets the tick of the current instance of %DateTime.
	 *	The tick value of type @c long @c long represents dates and times ranging from January 1, 1 A.D. 00:00:00.000 am.
	 *
	 *	@since	2.1
	 *
	 *	@return		A @c long @c long value indicating the tick of the current instance of %DateTime
	 */
	long long GetTicks(void) const;

	/**
	 *	Gets the number of milliseconds (in TimeSpan) since the minimum date (GetMinValue()).
	 *
	 *	@since 2.0
	 *
	 *	@return		An instance of TimeSpan
	 *	@remarks	The returned instance is the time since the value returned by GetMinValue().
	 */
	TimeSpan GetTime(void) const;

	/**
	 *	Gets the maximum allowable value of %DateTime (that is, "December 31 9999 23:59:59.999").
	 *
	 *	@since 2.0
	 *
	 *	@return		An instance of %DateTime
	 */
	static const DateTime& GetMaxValue(void);

	/**
	 *	Gets the minimum allowable value of %DateTime (that is, "January 1 1 00:00:00.000").
	 *
	 *	@since 2.0
	 *
	 *	@return		An instance of %DateTime
	 */
	static const DateTime& GetMinValue(void);

	/**
	 *	Checks whether the year represented by the current instance of %DateTime is a leap year.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the year represented by the current instance of %DateTime is a leap year, @n
	 *               else @c false
	 */
	bool IsLeapYear(void) const;

	/**
	 *	Checks whether the specified @c year is a leap year.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the specified year is a leap year, @n
	 *               else @c false
	 *	@param[in]	year	The year
	 */
	static bool IsLeapYear(int year);

private:
	DateTime(int year, int month, int day, int hour, int minute, int second, int tick);

	int CountLeapYear(int year) const
	{
		return static_cast< int >((year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400);

	}

	int CountDays(int year) const
	{
		return static_cast< int >((year - 1) * 365 + CountLeapYear(year));
	}

	int CountYears(int day) const
	{
		double year = (day - CountLeapYear(day / 365)) / 365.0;
		Double year1(year);
		Double year2(0.0);

		if (year1.Equals(year2))
		{
			return 1;
		}
		else
		{
			year = (year != static_cast< int >(year) ? 1 + static_cast< int >(year) : static_cast< int >(year));
			int tempDays = day - CountDays(year);

			// Check the boundary of days
			if (IsLeapYear(year))
			{
				if (tempDays > 366)
				{
					year += 1;
				}
			}
			else
			{
				if (tempDays > 365)
				{
					year += 1;
				}
			}

			return year;
		}
	}

	typedef struct
	{
		int year;       /**<The year (1-9999)*/
		int month;      /**<The month (1-12)*/
		int day;        /**<The day (1-31)*/
		int hour;       /**<The hour (0-23)*/
		int minute;     /**<The minute (0-59)*/
		int second;     /**<The first 16 bits store tick (0-999) and the last 16 bits store second (0-59)*/
	} TmDateTime;

	result ConvertTicksToDate(long long ticks, TmDateTime* pDateTime);
	long long ConvertDateToTicks(const TmDateTime* pDateTime) const;

	result ConvertSecondsToDate(long long seconds, TmDateTime* pDateTime);
	long long ConvertDateToSeconds(const TmDateTime* pDateTime) const;

	TmDateTime __dateTime;

	friend class _DateTimeImpl;
	class _DateTimeImpl * __pDateTimeImpl;

}; // DateTime

}}  // Tizen::Base

#endif // _FBASE_DATE_TIME_H_

