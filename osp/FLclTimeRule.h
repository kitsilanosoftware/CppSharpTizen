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
 * @file		FLclTimeRule.h
 * @brief		This is the header file for the %TimeRule class.
 *
 * This header file contains declarations of the %TimeRule class.
 */
#ifndef _FLCL_TIME_RULE_H_
#define _FLCL_TIME_RULE_H_

#include <FBaseObject.h>
#include <FSysSystemTime.h>

namespace Tizen { namespace Locales
{

/**
 * @class		TimeRule
 * @brief		This class is for setting and getting the time rule.
 *
 * @since		2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %TimeRule class defines the time rule and provides methods for setting and getting it.
 * This class does not execute any operation with its value and is mainly used when periodically repeated time rules are defined.
 * For example, the daylight saving time rule.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/time_rules.htm">Time Rules</a>.
 *
 * @see		Tizen::Locales::TimeZone
 */

/**
* @enum Month
*
* Defines the months. @n
* The indexing is 1-based.
*
* @since		2.0
*/
enum Month
{
	JANUARY = 1,    /**< January	*/
	FEBRUARY,       /**< February	*/
	MARCH,          /**< March		*/
	APRIL,          /**< April		*/
	MAY,            /**< May		*/
	JUNE,           /**< June		*/
	JULY,           /**< July		*/
	AUGUST,         /**< August		*/
	SEPTEMBER,      /**< September	*/
	OCTOBER,        /**< October	*/
	NOVEMBER,       /**< November   */
	DECEMBER,       /**< December   */
	MONTH_UNDEFINED = -1    // Undefined
};


/**
* @enum DayOfWeek
*
* Defines the days of the week. @n
* The indexing is 1-based.
*
* @since		2.0
*/
enum DayOfWeek
{
	SUNDAY = 1,                 /**< Sunday */
	MONDAY,                     /**< Monday */
	TUESDAY,                    /**< Tuesday */
	WEDNESDAY,                  /**< Wednesday */
	THURSDAY,                   /**< Thursday */
	FRIDAY,                     /**< Friday */
	SATURDAY,                   /**< Saturday */
	DAY_OF_WEEK_UNDEFINED = -1  //*< Undefined */
};

/**
 * @enum Week
 *
 * Defines the week.
 *
 * @since		2.0
 */
enum Week
{
	FIRST_WEEK = 1,             /**< The first week */
	SECOND_WEEK = 2,            /**< The second week */
	THIRD_WEEK = 3,             /**< The third week */
	FOURTH_WEEK = 4,            /**< The fourth week */
	FIFTH_WEEK = 5,             /**< The fifth week */
	SIXTH_WEEK = 6,             /**< The sixth week */
	LAST_WEEK = -2,             /**< The last week */
	WEEK_UNDEFINED = -1         //*< Undefined */
};

class _OSP_EXPORT_ TimeRule
	: public Tizen::Base::Object
{
public:
	/**
	 * Initializes the current instance of %TimeRule with the values of the specified %TimeRule instance. @n
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since			2.0
	 *
	 * @param[in]		timeRule			An instance of %TimeRule
	 */
	TimeRule(const TimeRule& timeRule);

	/**
	 * Assigns the value of the specified instance to the current instance of %TimeRule. @n
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since			2.0
	 *
	 * @param[in]		timeRule			An instance of %TimeRule
	 */
	TimeRule& operator =(const TimeRule& timeRule);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~TimeRule(void);

	/**
	 * Initializes the current instance of %TimeRule with the specified @c month, @c day, @c hour,
	 * @c minute, and @c timeMode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		month				The month
	 * @param[in]		day					The day
	 * @param[in]		hour				The hour
	 * @param[in]		minute				The minute
	 * @param[in]		timeMode			The time mode - TIME_MODE_UTC, TIME_MODE_STANDARD, or TIME_MODE_WALL
	 */
	TimeRule(Month month, int day, int hour = 0, int minute = 0, Tizen::System::TimeMode timeMode = Tizen::System::TIME_MODE_WALL);

	/**
	 * Initializes the current instance of %TimeRule with the specified @c month, @c week,
	 * @c dayOfWeek, @c hour, @c minute, and @c timeMode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		month				The month
	 * @param[in]		week				The week
	 * @param[in]		dayOfWeek			The day of the week
	 * @param[in]		hour				The hour
	 * @param[in]		minute				The minute
	 * @param[in]		timeMode			The time mode - TIME_MODE_UTC, TIME_MODE_STANDARD, or TIME_MODE_WALL
	 */
	TimeRule(Month month, Week week, DayOfWeek dayOfWeek,
		int hour = 0, int minute = 0, Tizen::System::TimeMode timeMode = Tizen::System::TIME_MODE_WALL);

	/**
	 * Initializes the current instance of %TimeRule with the specified @c month, @c day,
	 * @c dayOfWeek, @c onOrAfterDay setting, @c hour, @c minute, and @c timeMode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		month				The month
	 * @param[in]		day					The day
	 * @param[in]		dayOfWeek			The day of the week
	 * @param[in]		onOrAfterDay		Set to @c true to select the first @c dayOfWeek
	 *                                        @b on @b or @b after @c day, @n
	 *                                        else @c false to select the last @c dayOfWeek
	 *                                        @b on @b or @b before @c day
	 * @param[in]		hour				The hour
	 * @param[in]		minute				The minute
	 * @param[in]		timeMode			The time mode - TIME_MODE_UTC, TIME_MODE_STANDARD, or TIME_MODE_WALL
	 */
	TimeRule(Month month, int day, DayOfWeek dayOfWeek,
		bool onOrAfterDay, int hour = 0, int minute = 0, Tizen::System::TimeMode timeMode = Tizen::System::TIME_MODE_WALL);

	/**
	 * Gets the month.
	 *
	 * @since			2.0
	 *
	 * @return			The month
	 */
	Month GetMonth(void) const;

	/**
	 * Gets the day.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value indicating the day, @n
	 * 					  else @c -1 if the value of day is undefined
	 */
	int GetDay(void) const;

	/**
	 * Gets the week.
	 *
	 * @since			2.0
	 *
	 * @return			The week, @n
	 * 					  else @c -1 if the value of week is undefined
	 */
	Week GetWeek(void) const;

	/**
	 * Gets the day of the week.
	 *
	 * @since			2.0
	 *
	 * @return			The day of the week, @n
	 * 					  else @c -1 if the value of day of the week is undefined
	 */
	DayOfWeek GetDayOfWeek(void) const;

	/**
	 * Gets the hour.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value indicating the hour
	 */
	int GetHour(void) const;

	/**
	 * Gets the minute.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value indicating the minute
	 */
	int GetMinute(void) const;

	/**
	 * Gets the time mode.
	 *
	 * @since			2.0
	 *
	 * @return			An instance of Tizen::System::TimeMode
	 */
	Tizen::System::TimeMode GetTimeMode(void) const;

	/**
	 * Gets the value of the @c onOrAfterDay field.
	 *
	 * @since			2.0
	 *
	 * @return			A @c boolean value of the @c onOrAfterDay field
	 */
	bool IsOnOrAfterDay(void) const;

	/**
	 * Checks whether the value of the specified instance is equal to that of the current instance.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the value of the specified instance is equal to that of the current instance, @n
	 * 					  else @c false
	 * @param[in]		obj The object to compare with the current instance
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

private:
	/**
	 * Initializes a %TimeRule instance with given values.
	 *
	 * @return			An error code
	 * @param[in]		month					The month
	 * @param[in]		day						The day
	 * @param[in]		week					The week
	 * @param[in]		dayOfWeek				The day of week
	 * @param[in]		beforeAfter				If @c after is ON_OR_AFTER_DAY, this rule selects the first @c dayOfWeek
	 *											@b on @b or @b after @c day.
	 *											If @c after is ON_OR_BEFORE_DAY, this rule selects the last @c dayOfWeek
	 *											@b on @b or @b before @c day.
	 * @param[in]		hour					The hour
	 * @param[in]		minute					The minute
	 * @param[in]		timeMode				The time mode - TIME_MODE_UTC, TIME_MODE_STANDARD, TIME_MODE_WALL
	 */
	void SetValue(Month month, int day, Week week,
		DayOfWeek dayOfWeek, bool onOrAfterDay, int hour,
		int minute, Tizen::System::TimeMode timeMode);

	int GetRuleMode(void) const;

	static const int DAY_UNDEFINED = -1;

	Month __month;
	int __day;
	Week __week;
	DayOfWeek __dayOfWeek;
	int __hour;
	int __minute;
	Tizen::System::TimeMode __timeMode;
	bool __onOrAfterDay;


	friend class _TimeRuleImpl;
	class _TimeRuleImpl* __pTimeRuleImpl;

	friend class _TimeZoneImpl;
	friend class _LocaleData;
}; // TimeRule

}} // Tizen::Locales
#endif  // _FLCL_TIME_RULE_H_
