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
 * @file		FUiIDateChangeEventListener.h
 * @brief		This is the header file for the %IDateChangeEventListener interface.
 *
 * This header file contains the declarations of the %IDateChangeEventListener interface.
 * If a change event is generated, a method of this interface is called.
 * So, for tasks related to the change events, use the methods of this interface.
 *
 */
#ifndef _FUI_IDATE_CHANGE_EVENT_LISTENER_H_
#define _FUI_IDATE_CHANGE_EVENT_LISTENER_H_

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
 * @interface	IDateChangeEventListener
 * @brief		This interface implements the listener for Date change events.
 *
 * @since		2.0
 *
 * The %IDateChangeEventListener interface is the listener interface for receiving date change events.
 * The class that processes a date change event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddDateChangeEventListener() method. When the date change event occurs, the
 * OnDateChanged() method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a> and <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
 */
class _OSP_EXPORT_ IDateChangeEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			2.0
	 */
	virtual ~IDateChangeEventListener(void) {}

	/**
	 * Called when there is a change in the date. @n
	 * The changed values of the year, month, and day are passed as input parameters.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]	year		The year
	 * @param[in]	month		The month
	 * @param[in]	day			The day
	 */
	virtual void OnDateChanged(const Tizen::Ui::Control& source, int year, int month, int day) = 0;


	/**
	* Called when the change in date is canceled.
	*
	* @since		2.0
	*
	* @param[in]    source		The source of the event
	*/
	virtual void OnDateChangeCanceled(const Tizen::Ui::Control& source) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void IDateChangeEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void IDateChangeEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void IDateChangeEventListener_Reserved3(void) {}

}; // IDateChangeEventListener

}}  // Tizen::Ui

#endif // _FUI_IDATE_CHANGE_EVENT_LISTENER_H_
