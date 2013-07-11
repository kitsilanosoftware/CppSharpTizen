
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
 * @file	FSysPowerManager.h
 * @brief	This is the header file for the %PowerManager class.
 *
 * This header file contains the declarations of the %PowerManager class.
 */

#ifndef _FSYS_POWER_MANAGER_H_
#define _FSYS_POWER_MANAGER_H_

#include <FBaseObject.h>

namespace Tizen { namespace System
{

class IScreenEventListener;
class IChargingEventListener;
class IBatteryEventListener;

/**
 * @enum	BatteryLevel
 *
 * Defines the representation of the remaining charge in the battery.
 *
 * @since	2.0
 */
enum BatteryLevel
{
	BATTERY_FULL,		// This enum value is deprecated. Instead of using this enum value, use BATTERY_LEVEL_FULL.
	BATTERY_HIGH,		// This enum value is deprecated. Instead of using this enum value, use BATTERY_LEVEL_HIGH.
	BATTERY_LOW,		// This enum value is deprecated. Instead of using this enum value, use BATTERY_LEVEL_LOW.
	BATTERY_CRITICAL,	// This enum value is deprecated. Instead of using this enum value, use BATTERY_LEVEL_CRITICAL.
	BATTERY_EMPTY,		// This enum value is deprecated. Instead of using this enum value, use BATTERY_LEVEL_EMPTY.
	BATTERY_LEVEL_FULL = BATTERY_FULL,/**< The battery is fully charged */
	BATTERY_LEVEL_HIGH = BATTERY_HIGH,/**< The battery has plenty of charge */
	BATTERY_LEVEL_LOW = BATTERY_LOW,/**< The battery has little charge */
	BATTERY_LEVEL_CRITICAL = BATTERY_CRITICAL,/**< The battery charge is at a critical state @n It is strongly recommended to stop using all multimedia features because they are not guaranteed to work correctly at this level. */
	BATTERY_LEVEL_EMPTY = BATTERY_EMPTY,	/**< The battery is empty @n It is strongly recommended to prepare for the safe termination of the application because the device will start a shutdown process soon after entering this level.  */
};

/**
 * @enum	PowerMode
 *
 * Defines the representation of the charge remaining in the battery.
 *
 * @since	2.0
 */
enum PowerMode
{
	POWER_STANDBY,				// This enum value is deprecated. Instead of using this enum value, use POWER_MODE_STANDBY.
	POWER_SLEEP,				// This enum value is deprecated. Instead of using this enum value, use POWER_MODE_SLEEP.
	POWER_MODE_STANDBY = POWER_STANDBY,	/**< The battery is fully charged */
	POWER_MODE_SLEEP = POWER_SLEEP,		/**< The battery has plenty of charge */
};

/**
 * @class	PowerManager
 * @brief	This class provides methods for power management.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %PowerManager class provides methods for managing the device power state.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/screen_power_mgmt.htm">Screen Power Management</a>.

 */

class _OSP_EXPORT_ PowerManager
	: public Tizen::Base::Object
{

public:
	/**
	 * Changes the policy of the screen power management.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/power
	 *
	 * @return	An error code
	 * @param[in]	keepOn	Set to @c true if the screen remains in the 'ON' state until the application goes to the background, @n
	 *                      else @c false if the state of the screen is controlled by the default power control policy of the system
	 * @param[in]   dimming Set to @c true if the screen is dimmed when there is no user input for a certain amount of time, @n
	 *                      else @c false if the screen is not dimmed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The application should explicitly call this method again, if the screen is to be kept 'ON' after coming back from the background state.
	 */
	static result KeepScreenOnState(bool keepOn, bool dimming = true);

	/**
	 * Restores the screen brightness control.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_INVALID_STATE The brightness is never changed.
	 * @exception	E_SYSTEM The method cannot proceed due to a severe system error.
	 * @see		SetScreenBrightness()
	 */
	static result RestoreScreenBrightness(void);

	/**
	 * Sets the screen brightness level for an application.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/power
	 *
	 * @return	An error code
	 * @param[in]	brightness	The brightness level to set @n
	 *				The parameter value can range between @c 1 (minimum) and @c 10 (maximum).
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_RANGE  	The specified @c brightness is out of range.
	 * @exception	E_SYSTEM 		The method cannot proceed due to a severe system error.
	 * @remarks	This brightness level is only available when an application is running on the foreground. Even if the brightness is set to level 1, a black screen is not displayed. Level 1 is the minimum brightness level that can be set for an application.
	 * @see		RestoreScreenBrightness()
	 */

	static result SetScreenBrightness(int brightness);
	/**
	 * Gets the screen brightness level of an application.
	 *
	 * @since	2.0
	 *
	 * @return	The brightness level of the current application
	 * @exception	E_SUCCESS             The method is successful.
	 * @exception	E_SYSTEM	 A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	This method returns the screen brightness level set for an application. If the brightness level is not set, it will return the default system brightness level. @n
	 *		In case of error, this method returns @c -1. 
	 */
	static int GetScreenBrightness(void);

	/**
	 * Checks whether the screen is on.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the screen is on, @n
	 *		else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	This method returns @c true when the screen is in the dimming state, and @c false in case of an error.
	 */
	static bool IsScreenOn(void);

	/**
	 * Turns on the screen.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/power
	 * @return	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	static result TurnScreenOn(void);

	/**
	 * Turns off the screen.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/power
	 * @return	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	static result TurnScreenOff(void);

	/**
	 * Changes the policy of the CPU (Central Processing Unit) power management.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/power
	 *
	 * @return	An error code
	 * @param[in]	enable	Set to @c true to prevent the CPU from going into sleep mode, @n
	 *		else @c false to let the state of the CPU follow the system default power management policy
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	static result KeepCpuAwake(bool enable);

	/**
	 * Sets the screen event listener.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener		The screen event listener
	 * @see		IScreenEventListener
	 */
	static void SetScreenEventListener(IScreenEventListener& listener);

	/**
	 * Sets the charging event listener.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener	The charging event listener
	 */
	static void SetChargingEventListener(IChargingEventListener& listener);

	/**
	 * Sets the battery event listener.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]	pListener	The battery event listener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	If @c pListener is set to @c null, the pre-registered listener is unregistered.
	 */
	static result SetBatteryEventListener(IBatteryEventListener* pListener);

	/**
	 * Gets the current charge remaining in the battery as a percentage.
	 *
	 * @since 2.0
	 *
	 * @return	The percentage of the charge remaining in the battery.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remakrs	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	The resolution of the level is @c 1 percentage. The range of the level is minimum @c 0 to maximum @c 100. 
	 */
	static int GetCurrentBatteryLevelInPercentage(void);

	/**
	 * Gets the current charging level of the battery.
	 *
	 * @since 2.0
	 *
	 * @return	A value from the enumerator BatteryLevel indicating the current charging level
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static BatteryLevel GetCurrentBatteryLevel(void);

	/**
	 * Checks whether the battery is currently charging.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the charging cable is connected to the phone, @n
	 *		else @c false
	 * @exception	E_SUCCESS		The method is successful. 
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error. 
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static bool IsCharging(void);

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	PowerManager(void);
	/**
	 * This is the destructor for this class. This destructor overrides Tizen::Base::Object::~Object().
	 */
	virtual ~PowerManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PowerManager(const PowerManager& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PowerManager& operator = (const PowerManager& value);

private:
	friend class _PowerManagerImpl;
	class _PowerManagerImpl* __pPowerManagerImpl;
}; // PowerManager

} } // Tizen::System

#endif // _FSYS_POWER_MANAGER_H_
