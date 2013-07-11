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
 * @file	FSclReminder.h
 * @brief	This is the header file for the %Reminder class.
 *
 * This header file contains the declarations of the %Reminder class.
 */
#ifndef _FSCL_REMINDER_H_
#define _FSCL_REMINDER_H_

#include <FBaseString.h>
#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 *	@class	Reminder
 *	@brief	This class represents the information of a reminder.
 *
 * @since	2.0
 *
 *	@final	This class is not intended for extension.
 *
 *	The %Reminder class represents the information of a reminder. An application uses this class to get or set the information of a reminder,
 *	such as the reminder time or the media file to be played for the reminder.
 *
 *	For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/recurrence_reminder_sensitivity.htm">Recurrence, Reminder, and Sensitivity Properties of Calendar Items</a>.
 *
 */
class _OSP_EXPORT_ Reminder
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * The default values are set. @n
	 * The time offset of @c 0 minutes for a reminder is set. @n
	 * The sound file name is @c null.
	 *
	 * @since	2.0
	 */
	Reminder(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Reminder
	 */
	Reminder(const Reminder& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Reminder(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %Reminder instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %Reminder instance, @n
	 *				else @c false
	 * @param[in]	rhs	The object instance to compare with the calling object
	 * @see			GetHashCode()
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the time offset of the reminder prior to an event time. @n
	 * For an event, the time offset is calculated as the number of minutes before the start DateTime. @n
	 * The default time offset is @c 0.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated		This method is deprecated. Instead of using this method, it is recommended to use GetTimeUnit() and GetTimeOffset().
	 *
	 * @since	2.0
	 *
	 * @return	The number of minutes
	 * @endif
	 */
	int GetMinutesBefore(void) const;

	/**
	 * Gets the sound file for the reminder. @n
	 * There is no default file name.
	 *
	 * @since	2.0
	 *
	 * @return		The file path and name
	 */
	Tizen::Base::String GetSoundFile(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the time offset of the reminder prior to an event time. @n
	 * For an event, the time offset is calculated as the number of minutes before the start DateTime.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated		This method is deprecated. Instead of using this method, it is recommended to use SetTimeOffset().
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	minutes			The time offset in minutes
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified time offset is less than @c 0 or greater than @c 40320.
	 * @remarks		The maximum value of the time offset is @c 40320.
	 * @endif
	 */
	result SetMinutesBefore(int minutes);

	/**
	 * Sets the sound file for the reminder.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompIoPathPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	filePath		The path and name of the new sound file, @n
	 *								else @c null to remove the previously set sound file
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The file path is invalid or the file does not exist.
	 */
	result SetSoundFile(const Tizen::Base::String& filePath);

	/**
	 * Sets the reminder time unit and offset.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	timeUnit			The reminder time unit
	 * @param[in]	timeOffset			The reminder time offset
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c timeOffset is less than @c 0.
	 */
	result SetTimeOffset(ReminderTimeUnit timeUnit, int timeOffset);

	/**
	 * Gets the reminder time unit.
	 *
	 * @since	2.0
	 *
	 * @return		The reminder time unit
	 */
	ReminderTimeUnit GetTimeUnit(void) const;

	/**
	 * Gets the reminder time offset in the time unit currently set to this instance.
	 *
	 * @since	2.0
	 *
	 * @return		The reminder time offset
	 */
	int GetTimeOffset(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Reminder
	 */
	Reminder& operator =(const Reminder& rhs);

private:
	Tizen::Base::String __soundFilePath;
	ReminderTimeUnit __timeUnit;
	int __timeOffset;

	friend class _ReminderImpl;
	class _ReminderImpl* __pReminderImpl;
};	// Reminder

}}	// Tizen::Social

#endif // _FSCL_REMINDER_H_
