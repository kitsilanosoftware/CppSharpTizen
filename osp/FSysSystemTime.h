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
 * @file	FSysSystemTime.h
 * @brief	This is the header file for the %SystemTime class.
 *
 * This header file contains the declarations of the %SystemTime class.
 */

#ifndef _FSYS_SYSTEM_TIME_H_
#define _FSYS_SYSTEM_TIME_H_

#include <FBaseObject.h>
#include <FBaseTimeSpan.h>
#include <FBaseDateTime.h>

namespace Tizen { namespace System
{

/**
 * @class	SystemTime
 * @brief	This class provides methods to get the system time.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %SystemTime class provides methods to get the current system time, ticks, and uptime.
 * It also supports the UTC, standard, and wall time modes.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/systime.htm">System Time</a>.
 */

/**
 * @enum	TimeMode
 *
 * Defines the three types of time modes.
 *
 * @since 2.0
 */
enum TimeMode
{
	UTC_TIME,	// This enum value is deprecated. Instead of using this enum value, use UTC_TIME.
	STANDARD_TIME,	// This enum value is deprecated. Instead of using this enum value, use STANDARD_TIME.
	WALL_TIME,	// This enum value is deprecated. Instead of using this enum value, use TIME_MODE_WALL.
	TIME_MODE_UTC = UTC_TIME,		/**< The UTC Time */
	TIME_MODE_STANDARD = STANDARD_TIME,	/**< The Standard Time */
	TIME_MODE_WALL = WALL_TIME,		/**< The Wall Time */
};

class _OSP_EXPORT_ SystemTime
{

public:
	/**
	 * Gets the uptime in milliseconds since the system is booted.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]  uptime		The uptime in milliseconds
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result GetUptime(Tizen::Base::TimeSpan& uptime);

	/**
	 * Gets the current system time.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]  currentTime	The current system time in UTC
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result GetCurrentTime(Tizen::Base::DateTime& currentTime);

	/**
	 * Gets the current system time.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	timeMode	The time mode @c TIME_MODE_UTC, TIME_MODE_STANDARD, or @c TIME_MODE_WALL
	 * @param[out]  currentTime	The current system time
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result GetCurrentTime(TimeMode timeMode, Tizen::Base::DateTime& currentTime);

	/**
	 * Gets the current system time in milliseconds since 1/1/1970 UTC.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]	ticks		The system time in milliseconds
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result GetTicks(long long& ticks);

	/**
	 * This is the default constructor for this class. This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	SystemTime(void);

	/**
	 * This is the destructor for this class. This destructor overrides Tizen::Base::Object::~Object().
	 */
	virtual ~SystemTime(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	SystemTime(const SystemTime& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	SystemTime& operator =(const SystemTime& value);

private:
	friend class _SystemTimeImpl;
	class _SystemTimeImpl* __pSystemTimeImpl;

}; // SystemTime

} } // Tizen::System

#endif // _FSYS_SYSTEM_TIME_H_
