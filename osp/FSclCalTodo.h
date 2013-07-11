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
 * @file		FSclCalTodo.h
 * @brief		This is the header file for the %CalTodo class.
 *
 * This header file contains the declarations of the %CalTodo class.
 */
#ifndef _FSCL_CAL_TODO_H_
#define _FSCL_CAL_TODO_H_

#include <FBaseDataType.h>
#include <FSclTypes.h>
#include <FSclRecord.h>
#include <FSclRecurrence.h>

namespace Tizen { namespace Base
{
class String;
class DateTime;

namespace Collection
{
class IList;
}
}}

namespace Tizen { namespace Social
{

class Reminder;

/**
 *	@class	CalTodo
 *	@brief	This class represents the calendar book to-do information.
 *
 * @since	2.0
 *
 *	@final	This class is not intended for extension.
 *
 * The %CalTodo class is a subset of vTodo. An instance of %CalTodo includes the subject, description, start date, due date, location, sensitivity,
 *			priority, and status.
 * This class represents the information of a calendar book to-do.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/caltodo.htm">Calendar Tasks</a>.
 *
 */
class _OSP_EXPORT_ CalTodo
	: public Record
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CalTodo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalTodo
	 */
	CalTodo(const CalTodo& rhs);

	/**
	 * This destructor overrides Tizen::Social::Record::~Record().
	 *
	 * @since	2.0
	 */
	virtual ~CalTodo(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %CalTodo instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %CalTodo instance, @n
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
	 * Gets the subject of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @return		The subject
	 */
	Tizen::Base::String GetSubject(void) const;

	/**
	 * Gets the description of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @return	 The description
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the start date of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @return		The start date, @n
	 * 				the minimum value of Tizen::Base::DateTime, if the start date has been not set
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_DATA_NOT_FOUND		The start date has been not set.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The minimum value can be acquired using Tizen::Base::DateTime::GetMinValue().
	 */
	Tizen::Base::DateTime GetStartDate(void) const;

	/**
	 * Gets the due date of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @return		The due date, @n
	 * 				the minimum value of Tizen::Base::DateTime, if the due date has been not set
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_DATA_NOT_FOUND		The due date has been not set.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The minimum value can be acquired using Tizen::Base::DateTime::GetMinValue().
	 */
	Tizen::Base::DateTime GetDueDate(void) const;

	/**
	 * Gets the priority level of the current instance of %CalTodo. @n
	 * The default priority level is #TODO_PRIORITY_LOW.
	 *
	 * @since	2.0
	 *
	 * @return		The priority level
	 */
	TodoPriority GetPriority(void) const;

	/**
	 * Gets the status of the current instance of %CalTodo. @n
	 * The default status is #TODO_STATUS_NONE.
	 *
	 * @since	2.0
	 *
	 * @return		The to-do status
	 */
	TodoStatus GetStatus(void) const;

	/**
	 * Gets the sensitivity of the current instance of %CalTodo. @n
	 * The default value is #SENSITIVITY_PUBLIC.
	 *
	 * @since	2.0
	 *
	 * @return		The to-do sensitivity
	 */
	RecordSensitivity GetSensitivity(void) const;

	/**
	 * Gets the last updated date and time of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @return		The last updated date and time
	 */
	Tizen::Base::DateTime GetLastRevisedTime(void) const;

	/**
	 * Sets the subject of the current instance of %CalTodo.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompCalTodoSetSubjectPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	subject				The to-do subject
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetSubject(const Tizen::Base::String& subject);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalTodoSetSubjectPage Compatibility for SetSubject()
	 * @section	CompCalTodoSetSubjectPageIssueSection Issues
	 *			Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# If the length of the subject to be set is greater than 100 characters, E_INVALID_ARG is returned.
	 *
	 * @section	CompCalTodoSetSubjectPageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 * 			-# There is no limit for the length of the subject.
	 * @endif
	 */

	/**
	 * Sets the description of the current instance of %CalTodo.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompCalTodoSetDescriptionPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	description		The to-do description, @n
	 *								else @c null to remove the existing value
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetDescription(const Tizen::Base::String& description);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalTodoSetDescriptionPage Compatibility for SetDescription()
	 * @section	CompCalTodoSetDescriptionPageIssueSection Issues
	 *			Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# If the length of the description to be set is greater than 1000 characters, E_INVALID_ARG is returned.
	 *
	 * @section	CompCalTodoSetDescriptionPageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 * 			-# There is no limit for the length of the description.
	 * @endif
	 */

	/**
	 * @if OSPDEPREC
	 * @{
	 * Sets the start date and due date for the current instance of %CalTodo. @n
	 * The due date must be later than or equal to the start date.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Deprecated] [Compatibility] </i>
	 * @endif
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use SetStartDate() and SetDueDate().
	 * @since	2.0
	 * @if OSPCOMPAT
 	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 * 				For more information, see @ref CompCalTodoSetStartAndDueDatePage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	startDate			The start date
	 * @param[in]	dueDate			The due date
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c dueDate is earlier than the specified @c startDate.
	 *									- The @c startDate or @c dueDate is not a valid range. @n
	 *									The valid range of the date can be referenced from GetMaxDateTime() and GetMinDateTime().
	 * @}
	 * @endif
	 */
	result SetStartAndDueDate(const Tizen::Base::DateTime& startDate, const Tizen::Base::DateTime& dueDate);

	/**
	 * @if OSPCOMPAT
	 * @page	CompCalTodoSetStartAndDueDatePage Compatibility for SetStartAndDueDate()
	 * @section	CompCalTodoSetStartAndDueDatePageIssueSection Issues
	 * 		Implementing this method in OSP compatible applications has the following issues:   @n
	 *			-# The start and due date cannot be unset. And if the SetStartAndDueDate() is not called, the default start and due date @n
	 *			are set to the system time when the to-do is constructed.
	 *
	 * @section	CompCalTodoSetStartAndDueDatePageSolutionSection Resolutions
	 * 			This issue has been resolved in Tizen.  @n
	 *			-# The default start and due date of the to-do is unset.
	 * @endif
	 */

	/**
	 * Sets the start date for the current instance of %CalTodo. @n
	 * If the @c startDate is minimum value of Tizen::Base::DateTime, the start date is changed to unset. @n
	 * And if the start date is later than due date, the due date will be changed to unset.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	startDate			The start date
	 * @exception	E_SUCCESS		The method is successful. @n
	 *								Either @c startDate is between Calendarbook::GetMaxDateTime() and Calendarbook::GetMinDateTime(), or
	 *								@c startDate is the minimum value of Tizen::Base::DateTime to unset the start date.
	 * @exception	E_INVALID_ARG	The specified @c start date is invalid.
	 * @remarks		The minimum value can be acquired using Tizen::Base::DateTime::GetMinValue().
	 */
	result SetStartDate(const Tizen::Base::DateTime& startDate);

	/**
	 * Sets the end date for the current instance of %CalTodo. @n
	 * If the @c dueDate is minimum value of Tizen::Base::DateTime, the due date is changed to unset. @n
	 * And if the due date is earlier than start date, the start date will be changed to unset.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	dueDate			The due date
	 * @exception	E_SUCCESS		The method is successful. @n
	 *								Either @c dueDate is between Calendarbook::GetMaxDateTime() and Calendarbook::GetMinDateTime(), or
	 *								@c dueDate is the minimum value of Tizen::Base::DateTime to unset the due date.
	 * @exception	E_INVALID_ARG	The specified @c due date is invalid.
	 * @remarks		The minimum value can be acquired using Tizen::Base::DateTime::GetMinValue().
	 */
	result SetDueDate(const Tizen::Base::DateTime& dueDate);


	/**
	 * Sets the priority level of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @param[in]	priority		The priority level to set
	 */
	void SetPriority(TodoPriority priority);

	/**
	 * Sets the status of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @param[in]	status			The status to set
	 */
	void SetStatus(TodoStatus status);

	/**
	 * Sets the sensitivity of the current instance of %CalTodo.
	 *
	 * @since	2.0
	 *
	 * @param[in]	sensitivity		The sensitivity to set
	 */
	void SetSensitivity(RecordSensitivity sensitivity);

	/**
	 * Sets the location of the current calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	location			The location of the event
	 */
	void SetLocation(const Tizen::Base::String& location);

	/**
	 * Gets the location of the calendar event.
	 *
	 * @since	2.0
	 *
	 * @return		The location
	 */
	Tizen::Base::String GetLocation(void) const;

	/**
	 * Sets the coordinates.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	latitude		The latitude in the range @n The valid range is [-90.0, 90.0].
	 * @param[in]	longitude		The longitude in the range @n The valid range is [-180.0, 180.0].
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The @c latitude or @c longitude is out of the valid range.
	 */
	result SetCoordinates(double latitude, double longitude);

	/**
	 * Gets the coordinates.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[out]	latitude		The latitude
	 * @param[out]	longitude		The longitude
	 */

	void GetCoordinates(double& latitude, double& longitude) const;

	/**
	 * Adds a reminder.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	reminder			The reminder to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result AddReminder(const Reminder& reminder);

	/**
	 * Removes a reminder at the index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The index of reminder to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The index is either equal to or greater than the number of reminders or less than @c 0.
	 */
	result RemoveReminderAt(int index);

	/**
	 * Gets a list of all the reminders.
	 *
	 * @since	2.0
	 *
	 * @return		A list containing the Reminder instances, @n
	 *				else an empty list if there are no reminders
	 */
	const Tizen::Base::Collection::IList& GetAllReminders(void) const;

	/**
	 * Gets the ID of the calendar to which this to-do belongs.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar ID
	 */
	RecordId GetCalendarId(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalTodo
	 */
	CalTodo& operator =(const CalTodo& rhs);

private:
	friend class _CalTodoImpl;
	class _CalTodoImpl* __pCalTodoImpl;
};	// CalTodo

}}	// Tizen::Social

#endif // _FSCL_CAL_TODO_H_
