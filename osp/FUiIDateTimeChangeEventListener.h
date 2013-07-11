//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file		FUiIDateTimeChangeEventListener.h
 * @brief		This is the header file for the %IDateTimeChangeEventListener interface.
 *
 * This header file contains the declarations of the %IDateTimeChangeEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, if applications perform jobs related to change events, they use the methods of this class.
 *
 */
#ifndef _FUI_IDATETIME_CHANGE_EVENT_LISTENER_H_
#define _FUI_IDATETIME_CHANGE_EVENT_LISTENER_H_

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
 * @interface	IDateTimeChangeEventListener
 * @brief		This interface implements the listener for Date and Time change events.
 *
 * @since		2.0
 *
 * The %IDateTimeChangeEventListener interface is the listener interface for receiving date and time change events.
 * The class that processes a date and time change event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddDateTimeChangeEventListener() method. When the date and time change event
 * occurs, the OnDateTimeChanged() method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
 */
class _OSP_EXPORT_ IDateTimeChangeEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			2.0
	 */
	virtual ~IDateTimeChangeEventListener(void) {}

	/**
	 * Called when there is a change in DateTime. @n
	 * The changed values of day, month, year, hour and minute are passed as input parameters.
	 *
	 * @since			2.0
	 *
	 * @param[in]       source		    The source of the event
	 * @param[in]		year			The year value
	 * @param[in]		month			The month value
	 * @param[in]		day				The day value
	 * @param[in]		hour			The hour value
	 * @param[in]		minute			The minute value
	 *
	 */
	virtual void OnDateTimeChanged(const Tizen::Ui::Control& source, int year, int month, int day, int hour, int minute) = 0;


	/**
	* Called when the date and time change is canceled.
	*
	* @since			2.0
	*
	* @param[in]    source		The source of the event
	*/
	virtual void OnDateTimeChangeCanceled(const Tizen::Ui::Control& source) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void IDateTimeChangeEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void IDateTimeChangeEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void IDateTimeChangeEventListener_Reserved3(void) {}
}; // IDateTimeChangeEventListener

}} // Tizen::Ui

#endif // _FUI_IDATETIME_CHANGE_EVENT_LISTENER_H_
