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
 * @file	FSysAlarm.h
 * @brief	This is the header file for the %Alarm class.
 *
 * This header file contains the declarations of the %Alarm class.
 */

#ifndef _FSYS_ALARM_H_
#define _FSYS_ALARM_H_

#include <FBaseDateTime.h>
#include <FSysIAlarmEventListener.h>

namespace Tizen { namespace System
{

/**
 * @class	Alarm
 * @brief	This class provides methods for creating, deleting, and updating an alarm.
 *
 * @since 2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Alarm class provides methods to create a one-time or repeating alarm.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/system_namespace.htm">System Guide</a>.
 */

class _OSP_EXPORT_ Alarm
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @remarks The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor. 
	 */
	Alarm(void);

	/**
	 * This is the destructor for this class. @n
	 * It unregisters the current instance of %Alarm from the system.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	~Alarm(void);

	/**
	 * Initializes an instance of %Alarm with the specified @c listener.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener		A reference to IAlarmEventListener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 */
	result Construct(IAlarmEventListener& listener);

	/**
	 * Sets a one-time alarm.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/alarm
	 *
	 * @return	An error code
	 * @param[in]	duetime			The time for the alarm to ring. @n Any value with a unit that is less than a second is ignored.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c duetime is invalid.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     If this %Alarm instance is already registered by this method, existing alarm is cancelled automatically.
	 */
	result Set(const Tizen::Base::DateTime& duetime);

	/**
	 * Sets a repeating alarm.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/alarm
	 *
	 * @return	An error code
	 * @param[in]	start			The time for the alarm to ring first. @n Any value with a unit that is less than a second is ignored.
	 * @param[in]	period			The interval in minutes between consecutive alarm rings.
	 * @param[in]	pEnd			The time for the alarm ring to end. @n Any value with a unit that is less than a second is ignored.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     If this %Alarm instance is already registered by this method, existing alarm is cancelled automatically. @n If @c pEnd is @c null, the alarm repeats forever.
	 */
	result Set(const Tizen::Base::DateTime& start, int period, const Tizen::Base::DateTime* pEnd = null);

	/**
	 * Cancels the alarm.
	 *
	 * @since	2.0
	 *
	 * @privilege	%http://tizen.org/privilege/alarm
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM		A system error has occurred.
	 */
	result Cancel(void);

	/**
	 * Gets the start time for the current instance of %Alarm.
	 *
	 * @since	2.0
	 *
	 * @return	An instance of Tizen::Base::DateTime indicating the start time for the alarm
	 * @remarks     If this %Alarm instance is not registered by the Set() method, return value is default value of the Tizen::Base::DateTime class.
	 */
	const Tizen::Base::DateTime GetStartTime(void) const;

	/**
	 * Gets the period of the current instance of %Alarm in minutes.
	 *
	 * @since	2.0
	 *
	 * @return	The period of the current instance of %Alarm in minutes
	 * @remarks     If this %Alarm instance is not registered by the Set() method, return value is @c 0.
	 */
	int GetPeriod(void) const;

	/**
	 * Gets the end time for the current instance of %Alarm.
	 *
	 * @since	2.0
	 *
	 * @return	 A pointer to Tizen::Base::DateTime indicating the end time for the alarm, @n
	 *			else @c null if the end time has not been set
	 */
	const Tizen::Base::DateTime* GetEndTime(void) const;

private:
	/**
	 * This is the default copy constructor for this class. The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	Alarm(const Alarm& alarml);

	/**
	 * This is the assignment operator for this class. The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	Alarm& operator =(const Alarm& alarml);

private:
	friend class _AlarmImpl;

	class _AlarmImpl* __pAlarmImpl;

}; // Alarm

} } // Tizen::System

#endif // _FSYS_ALARM_H_
