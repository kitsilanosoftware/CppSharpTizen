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
 * @if OSPCOMPAT
 * @file	FSysBattery.h
 * @brief	This is the header file for the %Battery class.
 *
 * This header file contains the declarations of the %Battery class.
 * @endif
 */

#ifndef _FSYS_BATTERY_H_
#define _FSYS_BATTERY_H_

#include <FBaseObject.h>
#include <FSysPowerManager.h>

namespace Tizen { namespace System
{

/**
 * @if OSPCOMPAT
 * @if OSPDEPREC
 * @class	Battery
 * @brief	<i>[Deprecated]</i> This class provides methods to get information related to the battery charge.
 *
 * @since	2.0
 *
 * @deprecated	This class is deprecated. Instead of using this class, use the PowerManager class.
 * @final	This class is not intended for extension.
 *
 * The %Battery class provides methods to get the status related to battery levels and
 * determine whether the battery is currently being charged.
 * You cannot create an instance of this class directly.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/battery_status.htm">Battery Status</a>.
 * @endif
 * @endif
 */
class _OSP_EXPORT_ Battery
	: public Tizen::Base::Object
{

public:
	/**
	 * Gets the current charge remaining in the battery as a percentage.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, use the PowerManager::GetCurrentBatteryLevelInPercentage() method.
	 * @since       2.0
	 *
	 * @return	An error code
	 * @param[out]  level	The percentage of the charge remaining in the battery
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	The battery service is not available.
	 * @exception   E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks The resolution of the level is 1% since 2.0. The range of the level is 0(Minimum) to 100(Maximum).
	 */
	static result GetCurrentLevelInPercentage(int& level);

	/**
	 * Gets the current charging level of the battery.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, use the PowerManager::GetCurrentBatteryLevel() method.
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]  level           A value from the enumerator BatteryLevel indicating the current charging level
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	The battery service is not available.
	 * @exception   E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetCurrentLevel(BatteryLevel& level);

	/**
	 * Checks whether the battery is currently charging.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, use the PowerManager::IsCharging() method.
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]	charging	Set to @c true if the charging cable is connected to the phone, @n
	 *				else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	The battery service is not available.
	 * @exception   E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result IsCharging(bool& charging);

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	Battery(void);

	/**
	 * This is the destructor for this class. 
	 * This destructor overrides Tizen::Base::Object::~Object(). @n
	 */
	virtual ~Battery(void);

 	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	Battery(const Battery& value);

 	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	Battery& operator =(const Battery& value);

private:
	friend class _BatteryImpl;
}; // Battery

} } // Tizen::System

#endif // _FSYS_BATTERY_H_
