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
 * @file		FLclDateTimeSymbols.h
 * @brief		This is the header file for the %DateTimeSymbols class.
 *
 * This header file contains the declarations of the %DateTimeSymbols class.
 *
 */
#ifndef _FLCL_DATE_TIME_SYMBOLS_H_
#define _FLCL_DATE_TIME_SYMBOLS_H_

#include <FBaseColArrayList.h>
#include <FLclLocale.h>
#include <FLclCalendar.h>

namespace Tizen { namespace Locales
{

/**
 * @class		DateTimeSymbols
 * @brief		This class provides methods that help in providing date and time symbols.
 *
 * @since		2.0
 *
 * The %DateTimeSymbols class is used for encapsulating localizable date-time formatting data, such as the names of the months, the days of the week, and the time zone data.
 * It is also used by DateTimeFormatter.
 * %DateTimeSymbols specifies the exact character strings to use for various parts of a date or time. For example, the names of the months and days of the week, the strings for AM and PM, and the day of the week considered to be the first day of the week.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/datetime_formatter.htm">Date and Time Formatter</a>.
 *
 * @see			Tizen::Locales::DateTimeFormatter
 *
 */
class _OSP_EXPORT_ DateTimeSymbols
	: public Tizen::Base::Object
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
	DateTimeSymbols(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~DateTimeSymbols(void);


	/**
	 * Initializes this instance of %DateTimeSymbols with the specified @c locale and @c calendarType.	
	 *
	 * @if OSPCOMPAT 
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since				2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompDateTimeSymbolsConstructPage "here".   
	 * @endif
	 *
	 * @return				An error code
	 * @param[in]			locale							The locale
	 * @param[in]			calendarType					The calendar type
	 * @exception			E_SUCCESS						The method is successful.
	 * @exception			E_OUT_OF_MEMORY					The memory is insufficient.
	 * @exception                   E_INVALID_ARG                   The specified @c locale or @c calendarType is invalid. 
	 */
	result Construct(const Locale& locale, CalendarType calendarType = CALENDAR_GREGORIAN);


	/**
	 * Initializes this instance of %DateTimeSymbols with the specified parameter. @n
	 * This method loads the format data from the resources for the default locale into the default calendar.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since				2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompDateTimeSymbolsConstructPage "here".   
	 * @endif
	 *
	 * @return				An error code
	 * @param[in]			calendarType					The calendar type
	 * @exception			E_SUCCESS						The method is successful.
	 * @exception			E_OUT_OF_MEMORY					The memory is insufficient.
	 * @exception                   E_INVALID_ARG                   The specified @c calendarType is invalid. 
	 */
	result Construct(CalendarType calendarType);
	
	/**
	 * @if OSPCOMPAT
         * @page                    CompDateTimeSymbolsConstructPage Compatibility for Construct()
         * @section                   CompDateTimeSymbolsConstructIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c calendarType is invalid.
         *
         * @section                 CompDateTimeSymbolsConstructSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:   
         * -# The method returns E_INVALID_ARG if the @c calendarType is invalid.
	 * @endif
         */


	/**
	 * Initializes this instance of %DateTimeSymbols with the specified parameter.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			other							An instance of %DateTimeSymbols
	 * @exception			E_SUCCESS						The method is successful.
	 * @exception			E_OUT_OF_MEMORY					The memory is insufficient.
	 */
	result Construct(const DateTimeSymbols& other);


	/**
	 * Gets the list of the era strings. @n
	 * For example: "AD" and "BC".
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the list of era strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see					SetEras()
	 */
	const Tizen::Base::Collection::IList* GetEras(void) const;


	/**
	 * Sets the era strings. @n
	 * Multiple strings can be concatenated by '|'. For example: "AD|BC".
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			eras						The era strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c eras contains an invalid value.
	 * @see					GetEras()
	 */
	result SetEras(const Tizen::Base::String& eras);


	/**
	 * Gets the list of the month name strings. @n
	 * For example: "January", "February", etc.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the list of month name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see					SetMonths()
	 */
	const Tizen::Base::Collection::IList* GetMonths(void) const;


	/**
	 * Sets the month name strings concatenated by '|'. @n
	 * For example: "January|February|March|April|May|June|July|August|September|October|November|December".
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			months						The new month strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c months contains an invalid value.
	 * @see						GetMonths()
	 */
	result SetMonths(const Tizen::Base::String& months);


	/**
	 * Gets the list of the short month name strings. @n
	 * For example: "Jan", "Feb", etc.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the list of short month name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see					SetShortMonths()
	 */
	const Tizen::Base::Collection::IList* GetShortMonths(void) const;


	/**
	 * Sets the short month name strings concatenated by '|'. @n
	 * For example: "Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec".
	 *
	 * @since					2.0
	 * @return				An error code
	 * @param[in]			shortMonths				The new short month name strings concatenated by '|'
	 * @exception			E_SUCCESS				The method is successful.
	 * @exception			E_INVALID_ARG			The specified @c shortMonths contains an invalid value. @n See the valid string in the description of the method.
	 * @see						GetShortMonths()
	 */
	result SetShortMonths(const Tizen::Base::String& shortMonths);


	/**
	 * Gets the list of the weekday name strings. @n
	 * For example: "Sunday", "Monday", etc.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the list of weekday name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see					SetWeekdays()
	 */
	const Tizen::Base::Collection::IList* GetWeekdays(void) const;


	/**
	 * Sets the weekday name strings concatenated by '|'. @n
	 * For example: "Sunday|Monday|Tuesday|Wednesday|Thursday|Friday|Saturday".
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			weekdays					The new weekday name strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c weekdays contains an invalid value.
	 * @see					GetWeekdays()
	 */
	result SetWeekdays(const Tizen::Base::String& weekdays);


	/**
	 * Gets the list of the short weekday name strings. @n
	 * For example: "Sun", "Mon", etc.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the list of short weekday name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see					SetShortWeekdays()
	 */
	const Tizen::Base::Collection::IList* GetShortWeekdays(void) const;


	/**
	 * Sets the weekday name strings concatenated by '|'. @n
	 * For example: "Sun|Mon|Tue|Wed|Thu|Fri|Sat".
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			shortWeekdays				The new short weekday strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c shortWeekdays contains an invalid value.
	 * @see					GetShortWeekdays()
	 */
	result SetShortWeekdays(const Tizen::Base::String& shortWeekdays);


	/**
	 * Gets the list of the AM/PM strings. @n
	 * For example: "AM" and "PM".
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the list of AM/PM strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see					SetAmPm()
	 */
	const Tizen::Base::Collection::IList* GetAmPm(void) const;


	/**
	 * Sets the AM/PM strings concatenated by '|'. @n
	 * For example: "AM|PM".
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			amPm						The new AM/PM strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c amPm contains an invalid value.
	 * @see					GetAmPm()
	 */
	result SetAmPm(const Tizen::Base::String& amPm);


	/**
	 * Gets the name of the time zone. @n
	 * For example: "Eastern European Time (EET)", "Eastern European Summer Time (EEST)".
	 *
	 * @since				2.0
	 *
	 * @return				The time zone name, @n
	 *						else an empty string if @c timeZoneId is not found @n
	 *						or the time zone name of @c timeZoneStyle is not found.
	 * @param[in]	timeZoneId		The time zone ID
	 * @param[in]	timeZoneStyle	The parameter may contain one of the following time zone styles:
	 *								@li The normal time zone (0)
	 *								@li The abbreviated time zone (1)
	 *								@li The normal summer time zone (2)
	 *								@li The abbreviated summer time zone (3)
	 * @see							SetTimeZoneName()
	 * @see							AddTimeZoneName()
	 */
	Tizen::Base::String GetTimeZoneName(Tizen::Base::String& timeZoneId, int timeZoneStyle = 0) const;


	/**
	 * Sets the time zone name string related to the specified time zone ID.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			timeZoneId							The time zone ID @n
	 *															For example: "Europe/Helsinki".
	 * @param[in]			concatenatedTimeZoneName			The new concatenated time zone name @n
	 *															For example, "Eastern European Time|EET|Eastern European Summer Time|EEST".
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_INVALID_ARG		The specified @c timeZoneId or @c concatenatedTimeZoneName contains an invalid value.
	 * @exception			E_OBJ_NOT_FOUND		The specified @c timeZoneId is not found.
	 * @see						GetTimeZoneName()
	 * @see						AddTimeZoneName()
	 */
	result SetTimeZoneName(const Tizen::Base::String& timeZoneId, const Tizen::Base::String& concatenatedTimeZoneName);


	/**
	 * Adds a new time zone name string that is related to time zone ID.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			timeZoneId							The time zone ID @n
	 *															For example: "Europe/Helsinki".
	 * @param[in]			concatenatedTimeZoneName			The concatenated time zone name @n
	 *															For example, "Eastern European Time|EET|Eastern European Summer Time|EEST".
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception			E_OBJ_ALREADY_EXIST	The specified @c timeZoneId already exists.
	 * @see					GetTimeZoneName()
	 * @see					SetTimeZoneName()
	 */
	result AddTimeZoneName(const Tizen::Base::String& timeZoneId, const Tizen::Base::String& concatenatedTimeZoneName);


	/*
	 * Gets the non-localized date-time pattern characters.
	 *
	 * @since				2.0
	 *
	 * @return				The non-localized date-time pattern characters
	 */
	static Tizen::Base::WcharBuffer* GetNonLocalizedDateTimePatternN(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	DateTimeSymbols(const DateTimeSymbols& dateTimeSymbols);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	DateTimeSymbols& operator =(const DateTimeSymbols& dateTimeSymbols);

	friend class _DateTimeSymbolsImpl;
	class _DateTimeSymbolsImpl* __pDateTimeSymbolsImpl;

}; // DateTimeSymbols

}} // Tizen::Locales

#endif //_FLCL_DATE_TIME_SYMBOLS_H_
 
