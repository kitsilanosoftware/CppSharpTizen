//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FUiITimeChangeEventListener.h
 * @brief		This is the header file for the %ITimeChangeEventListener interface.
 *
 * This header file contains the declarations of the %ITimeChangeEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, for tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_ITIME_CHANGE_EVENT_LISTENER_H_
#define _FUI_ITIME_CHANGE_EVENT_LISTENER_H_

// Includes
#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen {namespace Ui
{

/**
 * @interface	ITimeChangeEventListener
 * @brief		This interface implements the listener for the time change events.
 *
 * @since		2.0
 *
 * The %ITimeChangeEventListener interface is the listener interface for receiving time change events.
 * The class that processes a time change event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddTimeChangeEventListener() method. When the time change event occurs, the
 *  OnTimeChanged() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a> and <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.

 */
class _OSP_EXPORT_ ITimeChangeEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			2.0
	 */
	virtual ~ITimeChangeEventListener(void) {}

	/**
	 * Called when there is a change in time. @n
	 * The changed hour and minute values are passed as input parameters.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]	hour		The hour
	 * @param[in]	minute		The minute
	 */
	virtual void OnTimeChanged(const Tizen::Ui::Control& source, int hour, int minute) = 0;

	/**
	* Called when a time change is canceled.
	*
	* @since		2.0
	*
	* @param[in]    source		The source of the event
	*/
	virtual void OnTimeChangeCanceled(const Tizen::Ui::Control& source) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The following method is reserved, and their names can be changed
	// at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void ITimeChangeEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The following method is reserved, and their names can be changed
	// at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void ITimeChangeEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The following method is reserved, and their names can be changed
	// at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void ITimeChangeEventListener_Reserved3(void) {}
}; // ITimeChangeEventListener

}} // Tizen::Ui

#endif // _FUI_ITIME_CHANGE_EVENT_LISTENER_H_
