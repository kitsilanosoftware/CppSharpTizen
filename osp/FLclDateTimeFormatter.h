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
 * @file		FLclDateTimeFormatter.h
 * @brief		This is the header file for the %DateTimeFormatter class.
 *
 * This header file contains the declarations of the %DateTimeFormatter class.
 *
 */
#ifndef _FLCL_DATE_TIME_FORMATTER_H_
#define _FLCL_DATE_TIME_FORMATTER_H_

// Includes
#include <FBaseString.h>
#include <FLclCalendar.h>
#include <FLclDateTimeSymbols.h>


namespace Tizen { namespace Locales
{

// forward declaration
class NumberFormatter;
class _FieldPosition;
class _DateTimeFormatterImpl;


/**
 * @enum DateTimeStyle
 *
 * Defines the style for date and time.
 *
 * @since		2.0
 */
enum DateTimeStyle
{
	DATE_TIME_STYLE_NONE = -1,	/**< The date time style: None */
	DATE_TIME_STYLE_FULL = 0,	/**< The date time style: FULL is pretty completely specified, such as Tuesday, April 12, 1952 AD or 3:30:42PM PST */
	DATE_TIME_STYLE_LONG = 1,	/**< The date time style: LONG is longer, such as July 18, 2012 or 3:30:32PM */
	DATE_TIME_STYLE_MEDIUM = 2,	/**< The date time style: MEDIUM is a little longer, such as Jan 12, 1952 */
	DATE_TIME_STYLE_SHORT = 3,	/**< The date time style: SHORT is completely numeric, such as 12/13/52 or 3:30PM */
	DATE_TIME_STYLE_DEFAULT = DATE_TIME_STYLE_MEDIUM			/**< The default date time style: Medium */
};

/**
 * @class		DateTimeFormatter
 * @brief		This class provides methods for formatting the date and time formats.
 *
 * @since		2.0
 *
 * The %DateTimeFormatter class is used to format the date and time formats in a language-independent manner.
 * The date and time are represented as a Tizen::Base::DateTime instance.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/datetime_formatter.htm">Date and Time Formatter</a>.
 *
 * @see		Tizen::Base::DateTime
 * @see		DateTimeSymbols
 *
 * The following example demonstrates how to use the %DateTimeFormatter class.
 *
 * @code
#include <FBase.h>
#include <FLocales.h>
#include <FSystem.h>

using namespace Tizen::Base;
using namespace Tizen::Locales;
using namespace Tizen::System;

void
LocaleApp::DateTimeFormatterExample(void)
{
	// Construct locale
	Locale locale(LANGUAGE_ENG, COUNTRY_US);

	// Get today
	DateTime today;
	SystemTime::GetCurrentTime(TIME_MODE_UTC, today);

	// Get date formatter
	DateTimeFormatter* pDateFormatter = DateTimeFormatter::CreateDateFormatterN(locale, DATE_TIME_STYLE_DEFAULT);

	String formattedString;

	// Format today with date formatter
	pDateFormatter->Format(today, formattedString);

	// Get time formatter
	DateTimeFormatter* pTimeFormatter = DateTimeFormatter::CreateTimeFormatterN(locale, DATE_TIME_STYLE_DEFAULT);

	// Format today with time formatter
	pTimeFormatter->Format(today, formattedString);

	// Customized pattern
	String cutomizedPattern = L"EEE d MMM yy";
	pDateFormatter->ApplyPattern(cutomizedPattern);

	// Format today with date formatter
	pDateFormatter->Format(today, formattedString);

	delete pDateFormatter;
	delete pTimeFormatter;
}
@endcode
 *
 */
class _OSP_EXPORT_ DateTimeFormatter
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~DateTimeFormatter(void);

	/**
	 * Creates the date formatter with the specified formatting style for the system locale.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the system locale date formatter, @n
	 *					else @c null if an error occurs
	 * @param[in]		style						The formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception		E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @exception           E_INVALID_ARG           The specified @c style is an invalid value.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateFormatterN(DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);


	/**
	 * Creates the date formatter with the specified formatting style for the specified locale.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompDateTimeFormatterCreateDateFormatterNPage "here".   
	 * @endif
	 *
	 * @return			A pointer to the specified locale date formatter, @n
	 *					else @c null if an error occurs
	 * @param[in]		locale						The locale
	 * @param[in]		style						The formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception           E_INVALID_ARG           The specified @c locale or @c style is invalid. 
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateFormatterN(const Locale& locale, DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);
	
	/**
	 * @if OSPCOMPAT
         * @page                    CompDateTimeFormatterCreateDateFormatterNPage Compatibility for CreateDateFormatterN()
         * @section                   CompDateTimeFormatterCreateDateFormatterNIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
         *
         * @section                 CompDateTimeFormatterCreateDateFormatterNtSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the @c locale or @c style is invalid.
	 * @endif
         */


	/**
	 * Creates the time formatter with the specified formatting style for the system locale.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the system locale time formatter, @n
	 *					else @c null if an error occurs
	 * @param[in]		style						The formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception		E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @exception           E_INVALID_ARG           The specified  @c style is invalid. 
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateTimeFormatterN(DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);


	/**
	 * Creates the time formatter with the specified formatting style for the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif   
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompDateTimeFormatterCreateTimeFormatterNPage "here".   
	 * @endif
	 *
	 * @return			A pointer to the specified locale time formatter, @n
	 *					else @c null if an error occurs
	 * @param[in]		locale						The locale
	 * @param[in]		style						The formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception           E_INVALID_ARG           The specified @c locale or @c style is invalid. 
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateTimeFormatterN(const Locale& locale, DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);

	/**
	 * @if OSPCOMPAT
         * @page                    CompDateTimeFormatterCreateTimeFormatterNPage Compatibility for CreateTimeFormatterN()
         * @section                   CompDateTimeFormatterCreateTimeFormatterNIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
         *
         * @section                 CompGrDateTimeFormatterCreateTimeFormatterNSolutionSection Resolutions
         * This issue has been resolved in Tizen.
         * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the @c locale or @c style is invalid.
	 * @endif
         */

	/**
	 * Creates the date/time formatter with the specified formatting style for the system locale.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the system locale date/time formatter, @n
	 *					else @c null if an error occurs
	 * @param[in]		dateStyle					The date formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @param[in]		timeStyle					The time formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception		E_UNSUPPORTED_OPERATION		The current locale is not supported.
 	 * @exception           E_INVALID_ARG           The specified @c dateStyle or @c timeStyle is invalid. 	 
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateTimeFormatterN(DateTimeStyle dateStyle = DATE_TIME_STYLE_DEFAULT, DateTimeStyle timeStyle = DATE_TIME_STYLE_DEFAULT);


	/**
	 * Creates the date/time formatter with the specified formatting style for the specified @c locale.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the specified locale date/time formatter, @n
	 *					else @c null if an error occurs
	 * @param[in]		locale						The locale
	 * @param[in]		dateStyle					The date formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @param[in]		timeStyle					The time formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception		E_INVALID_ARG		The specified @c locale is not supported, or the @c dateStyle or the @c timeStyle is invalid.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateTimeFormatterN(const Locale& locale, DateTimeStyle dateStyle = DATE_TIME_STYLE_DEFAULT, DateTimeStyle timeStyle = DATE_TIME_STYLE_DEFAULT);

	/**
	 * Formats a Tizen::Base::DateTime object into a date/time string and appends the resulting string to the specified string buffer.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		date				The Tizen::Base::DateTime object to format
	 * @param[out]		str					The string to append to the resultant string
	 * @exception		E_SUCCESS			The method is successful.
	 * @remarks			This method does not handle the time zone information, so "z" pattern always returns "GMT+00:00".
	 * @see				Tizen::Base::DateTime
	 */
	virtual result Format(const Tizen::Base::DateTime& date, Tizen::Base::String& str) const;


	/**
	 * Formats a Calendar object into a date/time string and appends the resulting string to the specified string buffer.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		calendar				The Calendar object to format
	 * @param[out]		str						The string to append to the resultant string
	 * @exception		E_SUCCESS				The method is successful.
	 * @see					Tizen::Base::DateTime
	 */
	virtual result Format(const Calendar& calendar, Tizen::Base::String& str) const;


	/**
	* Applies the specified pattern string to the date format.
	*
	* @since				2.0
	*
	* @param[in]			pattern					The new date and time pattern for the date format
	* @exception			E_SUCCESS				The method is successful.
	* @exception			E_INVALID_ARG			The length of the specified @c pattern is @c 0.
	*/
	result ApplyPattern(const Tizen::Base::String& pattern);


	/**
	* Gets a pattern string describing the date format.
	*
	* @since				2.0
	*
	* @return				A string describing the date format
	*/
	Tizen::Base::String GetPattern(void) const;


	/**
	* Gets the date and time format symbols of the formatter.
	*
	* @since				2.0
	*
	* @return				A pointer to DateTimeSymbols for the formatter instance
	* @see					SetDateTimeSymbols()
	*/
	const DateTimeSymbols* GetDateTimeSymbols(void) const;


	/**
	* Sets the date and time format symbols of the date format.
	*
	* @since				2.0
	*
	* @param[in]			newSymbols			The new date and time format symbols
	* @see					GetDateTimeSymbols()
	*/
	void SetDateTimeSymbols(const DateTimeSymbols& newSymbols);

private:
	NumberFormatter* __pNumberFormat;
	Calendar* __pCalendar;

	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	DateTimeFormatter(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	DateTimeFormatter(const DateTimeFormatter& dateTimeFormatter);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	DateTimeFormatter& operator =(const DateTimeFormatter& dateTimeFormatter);

	friend class _DateTimeFormatterImpl;
	class _DateTimeFormatterImpl* __pDateTimeFormatterImpl;
}; // DateTimeFormatter

}} // Tizen::Locales

#endif //_FLCL_DATE_TIME_FORMATTER_H_
 
