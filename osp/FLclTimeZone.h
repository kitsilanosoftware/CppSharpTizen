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
 * @file		FLclTimeZone.h
 * @brief		This is the header file for the %TimeZone class.
 * @see			Tizen::Locales::Locale
 *
 * This header file contains the declarations of the %TimeZone class.
 */

#ifndef _FLCL_TIME_ZONE_H_
#define _FLCL_TIME_ZONE_H_

#include <FBaseString.h>
#include <FBaseDateTime.h>
#include <FLclTimeRule.h>

namespace Tizen { namespace Locales
{

/**
 * @class		TimeZone
 * @brief		This class represents the time zones.
 *
 * @since		2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %TimeZone class represents a time zone offset and figures out Daylight Saving Time (DST).
 *
 * The form of time zone ID is "Area/Location". However, the specialized time zone IDs have the different form.@n
 *
 * The IDs are defined in <a href="http://www.iana.org/time-zones" target="_blank">Time Zone Database</a>. @n
 * 
 * The supported time zone list depends on the device. Therefore, it must be checked by using LocaleManager::GetAvailableTimeZonesN().
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/time_zone.htm">Time Zones</a>.
 *
 * The following example demonstrates how to use the %TimeZone class.
 *
@code

#include <FLocales.h>

using namespace Tizen::Locales;

void
MyClass::MyTimeZone(void)
{
	// Gets the system time zone.
	LocaleManager localeManager;
	localeManager.Construct();

	TimeZone timeZone = localeManager.GetSystemTimeZone();

	String timeZoneId = timeZone.GetId();
	int rawOffset = timeZone.GetRawOffset();
	int dstSavings = timeZone.GetDstSavings();

	// Gets the special time zone.
	TimeZone timeZone2;
	Tizen::Locales::TimeZone::GetTimeZone(L"Europe/Zurich", timeZone2);
}
@endcode
 *
 */

class _OSP_EXPORT_ TimeZone
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	TimeZone(void);


	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~TimeZone(void);


	/**
	 * This is the copy constructor for the %TimeZone class. @n
	 * It initializes an instance of %TimeZone with the values of the specified instance of %TimeZone.
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since			2.0
	 *
	 * @param[in]		otherTimeZone					An instance of %TimeZone
	 */
	TimeZone(const TimeZone& otherTimeZone);

	/**
	 * Assigns the value of the specified instance to the current instance of %TimeZone. @n
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since			2.0
	 *
	 * @return			A reference value of the current instance
	 * @param[in]		otherTimeZone					An instance of %TimeZone
	 *
	 */
	TimeZone& operator =(const TimeZone& otherTimeZone);

	/**
	 * Initializes this instance of %TimeZone with the specified raw GMT offset and the ID of the time zone without including DST.
	 *
	 * @since			2.0
	 *
	 * @param[in]		rawOffset						The base time zone offset to GMT in minutes
	 * @param[in]		id								The time zone ID
	 * @remarks                     The form of time zone @c id is "Area/Location". @n For more information on IDs, refer <a href="http://www.iana.org/time-zones">here</a>. @n
	 *                                      However, the supported time zone list depends on the device. Therefore, it must be checked before using this method.
	 * @see                         LocaleManager::GetAvailableTimeZonesN()
	 */
	TimeZone(int rawOffset, const Tizen::Base::String& id);

	/**
	 * Initializes this instance of %TimeZone with the specified raw GMT offset,
	 * the ID of the time zone, the rules for starting/ending DST, and the DST offset.
	 *
	 * @since			2.0
	 *
	 * @param[in]		rawOffset						The base time zone offset to GMT in minutes
	 * @param[in]		id								The time zone ID
	 * @param[in]		startRule						The DST starting rule
	 * @param[in]		endRule							The DST end rule
	 * @param[in]		dstOffset						The amount of time in minutes saved during DST
	 * @remarks                     The form of time zone @c id is "Area/Location". @n For more information on IDs, refer <a href="http://www.iana.org/time-zones">here</a>. @n
	 *                                      However, the supported time zone list depends on the device. Therefore, it must be checked before using this method.
	 * @see                         LocaleManager::GetAvailableTimeZonesN()
	 */
	TimeZone(int rawOffset, const Tizen::Base::String& id,
		const TimeRule& startRule, const TimeRule& endRule, int dstOffset);

	/**
	 * Checks whether the specified instance of %TimeZone equals the value of the current instance.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the two instances are equal, @n
	 *					else @c false
	 * @param[in]		otherTimeZone					An instance of %TimeZone
	 */
	bool operator ==(const TimeZone& otherTimeZone) const;

	/**
	 * Checks whether the %TimeZone instance is equal to the current instance.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the two instances are not equal, @n
	 *					else @c false
	 * @param[in]		otherTimeZone					An instance of %TimeZone 
	 */
	bool operator !=(const TimeZone& otherTimeZone) const;

	/**
	* Compares the value of the specified instance to that of the current instance.
	*
	* @since			2.0
	*
	* @return			@c true if the value of the specified instance is equal to that of the current instance, @n
	*					  else @c false
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

	/**
	* Sets the DST time.
	*
	* @since			2.0
	*
	* @param[in]		dstSavings						The amount of time in minutes @n
	*													The time is advanced with respect to the standard time when the DST rules are in effect.
	*/
	void SetDstSavings(int dstSavings);

	/**
	 * Sets the DST starting and end rule.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		startRule						The DST starting rule
	 * @param[in]		endRule							The DST end rule
	 * @param[in]		dstSavings						The DST offset in minutes
	 * @exception		E_SUCCESS						The method is successful.
	 * @exception		E_OUT_OF_RANGE					The specified @c dstSavings is less than 24 hours.
	 */
	result SetDstRules(const TimeRule& startRule, const TimeRule& endRule, int dstSavings = 60);

	/**
	 * Sets the DST end rule.
	 *
	 * @since			2.0
	 *
	 * @param[in]		endRule							The DST end rule
	 */
	void SetDstEndingRule(const TimeRule& endRule);

	/**
	 * Sets the DST starting rule.
	 *
	 * @since			2.0
	 *
	 * @param[in]		startRule						The DST starting rule
	 */
	void SetDstStartingRule(const TimeRule& startRule);

	/**
	 * Sets the difference in minutes between the local standard time and GMT,
	 * without including DST (that is, raw offset).
	 *
	 * @since			2.0
	 *
	 * @param[in]		rawOffset						The difference in minutes between the local standard time and GMT, without including DST
	 */
	void SetRawOffset(int rawOffset);

	/**
	 * Sets the DST starting year.
	 *
	 * @since			2.0
	 *
	 * @param[in]		year							The DST starting year
	 */
	void SetDstStartingYear(int year);

	/**
	 * Sets the ID of the time zone.
	 *
	 * @since			2.0
	 *
	 * @param[in]		id								The ID of the time zone
	 */
	void SetId(const Tizen::Base::String& id);

	/**
	 * Converts the Coordinated Universal Time (UTC) time to the standard time.
	 *
	 * @since				2.0
	 *
	 * @return			The standard time
	 * @param[in]		utcTime							The UTC time
	 */
	Tizen::Base::DateTime UtcTimeToStandardTime(const Tizen::Base::DateTime& utcTime);

	/**
	 * Converts the UTC time to the wall time.
	 *
	 * @since			2.0
	 *
	 * @return			The wall time
	 * @param[in]		utcTime							The UTC time
	 */
	Tizen::Base::DateTime UtcTimeToWallTime(const Tizen::Base::DateTime& utcTime);

	/**
	 * Converts the standard time to the UTC time.
	 *
	 * @since			2.0
	 *
	 * @return			The UTC time
	 * @param[in]		standardTime					The standard time
	 */
	Tizen::Base::DateTime StandardTimeToUtcTime(const Tizen::Base::DateTime& standardTime);

	/**
	 * Converts the wall time to the UTC time.
	 *
	 * @since				2.0
	 *
	 * @return			The UTC time
	 * @param[in]		wallTime						The wall time
	 */
	Tizen::Base::DateTime WallTimeToUtcTime(const Tizen::Base::DateTime& wallTime);

	/**
	 * Gets the amount of time in minutes to be added to the local standard time to get the local wall time.
	 *
	 * @since			2.0
	 *
	 * @return			The amount of time in minutes
	 *
	 */
	int GetDstSavings(void) const;

	/**
	 * Gets the starting year of the DST.
	 *
	 * @since			2.0
	 *
	 * @return			The starting year of the DST set by the SetDstStartingYear() method, @n
	 *					else @c 0 if the starting year of the DST is undefined
	 * @see				SetDstStartingYear()
	 */
	int GetDstStartingYear(void) const;

	/**
	 * Gets the raw and GMT offset for the specified instance of Tizen::Base::DateTime in the current time zone.
	 *
	 * @if OSPCOMPAT  
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompTimeZoneGetOffsetPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		date						An instance of Tizen::Base::DateTime
	 * @param[in]		local						Set to @c true if the date is in local wall time @n
	 *												else @c false if it is in GMT time
	 * @param[out]		rawOffset					The time zone's raw offset in minutes
	 * @param[out]		dstOffset					The offset to add to @c rawOffset to obtain the total offset between the local and GMT time @n
	 *												If DST is not in effect, it is zero.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception           E_INVALID_ARG           			The specified @c date is invalid. 
	 * @remarks			Local millisecond = GMT milliseconds + rawOffset(in milliseconds) + dstOffset(in milliseconds).
	 *					All computations are performed in Gregorian calendar.
	 */
	result GetOffset(const Tizen::Base::DateTime& date, bool local, int& rawOffset, int& dstOffset) const;

	/**
	 * Gets the difference in minutes between the local standard time and GMT, taking into consideration both the raw offset and the effect of DST.
	 *
	 * @if OSPCOMPAT
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompTimeZoneGetOffsetPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		ticks						The time ticks value @n
	 *												The value can be either GMT time or local wall time.
	 * @param[out]		offset						The offset between the local standard time and GMT, taking into consideration DST
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception           E_INVALID_ARG                                   The specified @c ticks is invalid. 
	 */
	result GetOffset(long long ticks, int& offset) const;

        /** 
	 * @if OSPCOMPAT
         * @page                    CompTimeZoneGetOffsetPage Compatibility for GetOffset()
         * @section                   CompTimeZoneGetOffsetIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_OUT_OF_RANGE if an argument is invalid.
         *
         * @section                 CompTimeZoneGetOffsetSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:  
         * -# The method returns E_INVALID_ARG if an argument is invalid.
	 * @endif
        */

	/**
	 * Gets the difference in minutes between the local standard time and GMT, without including DST (that is, raw offset).
	 *
	 * @since			2.0
	 *
	 * @return			The raw offset
	 *
	 */
	int GetRawOffset(void) const;

	/**
	 * Gets the ID of the time zone.
	 *
	 * @since			2.0
	 *
	 * @return			The ID of the time zone
	 */
	Tizen::Base::String GetId(void) const;

	/**
	 * Gets the DST starting rule.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the DST start rule, @n
	 *					else a @c null pointer if the DST start rule is undefined
	 */
	const TimeRule* GetDstStartingRule(void) const;

	/**
	 * Gets the DST end rule.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the DST end rule, @n
	 *					else a @c null pointer if the DST end rule is undefined
	 */
	const TimeRule* GetDstEndingRule(void) const;

	/**
	 * Checks whether the current instance of %TimeZone uses DST.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the current instance uses DST, @n
	 *					else @c false
	 */
	bool IsDstUsed(void) const;

	/**
	 * Gets the GMT time zone. @n
	 * The GMT time zone has a raw offset of @c 0 and does not use DST.
	 *
	 * @since		2.0
	 *
	 * @return		The GMT time zone
	 */
	static TimeZone GetGmtTimeZone(void);

	/**
	 * Gets the time zone instance from the given ID.
	 *
	 * @if OSPCOMPAT  
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif 
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompTimeZoneGetTimeZonePage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		id				The time zone ID
	 * @param[out]		timeZone		The time zone for the given ID
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG 		The specified @c id is invalid. 
	 * @remarks			The %TimeZone instance for the specified @c id does not contain the DST information.
	 *					The supported time zone list depends on the device. Therefore, it should be checked before using this method.
	 * @see				LocaleManager::GetAvailableTimeZonesN()
	 */
	static result GetTimeZone(const Tizen::Base::String& id, Tizen::Locales::TimeZone& timeZone);

	/**
	 * Gets the %TimeZone instance from the specified ID and UTC time.
	 *
	 * @if OSPCOMPAT 
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompTimeZoneGetTimeZonePage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		id				The time zone ID
	 * @param[in]		utcTime			The UTC time
	 * @param[out]		timeZone		The time zone for the specified ID and UTC time
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception           E_INVALID_ARG           The specified @c id is invalid. 
	 * @remarks			The %TimeZone instance for the specified ID and UTC time contains the DST information.
	 *					The supported time zone list depends on the device. Therefore, it should be checked before using this method.
	 * @see				LocaleManager::GetAvailableTimeZonesN()
	 */
	static result GetTimeZone(const Tizen::Base::String& id, const Tizen::Base::DateTime& utcTime, Tizen::Locales::TimeZone& timeZone);

        /** 
	 * @if OSPCOMPAT
         * @page                    CompTimeZoneGetTimeZonePage Compatibility for GetTimeZone()
         * @section                   CompTimeZoneGetTimeZoneIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the time zone ID is invalid.
         *
         * @section                 CompTimeZoneGetTimeZoneSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the time zone ID is invalid.
	 * @endif
	*/

	/**
	 * Converts the UTC time to the standard time.
	 *
	 * @since		2.0
	 *
	 * @return      The standard time
	 * @param[in]   utcTime			The UTC time
	 * @param[in]   rawOffset		The time zone's raw offset in minutes
	 */
	static Tizen::Base::DateTime UtcTimeToStandardTime(const Tizen::Base::DateTime& utcTime, int rawOffset);

	/**
	 * Converts the standard time to the UTC time.
	 *
	 * @since		2.0
	 *
	 * @return      The UTC time
	 * @param[in]   standardTime		The standard time
	 * @param[in]   rawOffset		The time zone's raw offset in minutes
	 */
	static Tizen::Base::DateTime StandardTimeToUtcTime(const Tizen::Base::DateTime& standardTime, int rawOffset);

	/**
	 * Converts the UTC time to the wall time.
	 *
	 * @since		2.0
	 *
	 * @return      The wall time
	 * @param[in]   utcTime             The UTC time
	 * @param[in]   rawOffset		The time zone's raw offset in minutes
	 * @param[in]   dstOffset		The amount of time in minutes saved during DST
	 */
	static Tizen::Base::DateTime UtcTimeToWallTime(const Tizen::Base::DateTime& utcTime, int rawOffset, int dstOffset);

	/**
	 * Converts the wall time to the UTC time.
	 *
	 * @since		2.0
	 *
	 * @return      The UTC time
	 * @param[in]   wallTime			The wall time
	 * @param[in]   rawOffset		The time zone's raw offset in minutes
	 * @param[in]   dstOffset		The amount of time in minutes saved during DST
	 */
	static Tizen::Base::DateTime WallTimeToUtcTime(const Tizen::Base::DateTime& wallTime, int rawOffset, int dstOffset);

private:

	friend class _TimeZoneImpl;
	class _TimeZoneImpl* __pTimeZoneImpl;

	friend class _LocaleData;
}; // TimeZone

}} // Tizen::Locales
#endif // _FLCL_TIME_ZONE_H_
