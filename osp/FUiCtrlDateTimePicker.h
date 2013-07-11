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
 * @file			FUiCtrlDateTimePicker.h
 * @brief	This is the header file for the %DateTimePicker class.
 *
 * This header file contains the declarations of the %DateTimePicker class.
 */
#ifndef _FUI_CTRL_DATE_TIME_PICKER_H_
#define _FUI_CTRL_DATE_TIME_PICKER_H_

#include <FUiWindow.h>
#include <FUiIDateTimeChangeEventListener.h>

namespace Tizen { namespace Ui { namespace  Controls
{

/**
 * @class	DateTimePicker
 * @brief	This class displays a full screen %DateTimePicker on top of the screen.
 *
 * @since		2.0
 *
 * The %DateTimePicker class displays a full screen window-based selector that allows the user to select a certain date and time.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
 *
 * The following example demonstrates how to use the %DateTimePicker class.
 *
 * @code
// Sample code for DateTimePickerSample.h
#include <FUi.h>

class DateTimePickerSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IDateTimeChangeEventListener
	, public Tizen::Ui::IActionEventListener
{
public:
	DateTimePickerSample(void)
	:__pDateTimePicker(null){}

	bool Initialize(void);
	void ShowDateTimePicker(bool show);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	// IDateTimeChangeEventListener
	virtual void OnDateTimeChanged(const Tizen::Ui::Control& source, int year, int month, int day, int hour, int minute);
	virtual void OnDateTimeChangeCanceled(const Tizen::Ui::Control& source);

private:
	static const int ID_BUTTON  = 101;

	Tizen::Ui::Controls::DateTimePicker* __pDateTimePicker;
};

 *	@endcode
 *
 *	@code
// Sample code for DateTimePickerSample.cpp
#include <FGraphics.h>

#include "DateTimePickerSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
DateTimePickerSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
DateTimePickerSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Button
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 50, 300, 200), L"Show DateTimePicker");
	pButton->SetActionId(ID_BUTTON);
	pButton->AddActionEventListener(*this);

	// Adds the button to the form
	AddControl(*pButton);

	// Creates an instance of DateTimePicker
	__pDateTimePicker = new DateTimePicker();
	__pDateTimePicker->Construct();

	// Adds an instace of IDateTimeChangeEventListener
	__pDateTimePicker->AddDateTimeChangeEventListener(*this);

	// Shows the date time picker after it's owner form is shown.

	return r;
}

void
DateTimePickerSample::ShowDateTimePicker(bool show)
{
	// Changes to desired show state
	__pDateTimePicker->SetShowState(show);

	// Calls Show() of the control
	if (show)
	{
		__pDateTimePicker->Show();
	}
	// Calls Show() of the container
	else
	{
		Invalidate(true);
	}
}

result
DateTimePickerSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the date time picker
	delete __pDateTimePicker;

	return r;
}

// IActionEventListener implementation
void
DateTimePickerSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON:
		{
			ShowDateTimePicker(true);
		}
		break;
	default:
		break;
	}
}

// IDateTimeChangeEventListener implementation
void
DateTimePickerSample::OnDateTimeChanged(const Control& source, int year, int month, int day, int hour, int minute)
{
	// ....
}

void
DateTimePickerSample::OnDateTimeChangeCanceled(const Control& source)
{
	// ....
}
 * @endcode
 */

class _OSP_EXPORT_ DateTimePicker
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	DateTimePicker(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~DateTimePicker(void);

	/**
	 * Adds the IDateTimeChangeEventListener instance. @n
	 * The added listener gets notified when date or time of the %DateTimePicker instance is changed either by user manipulation or by calling one of its
	 * setters.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be added
	 * @see			IDateTimeChangeEventListener::OnDateTimeChanged()
	 * @see			IDateTimeChangeEventListener::OnDateTimeChangeCanceled()
	 * @see			RemoveDateTimeChangeEventListener()
	 */
	void AddDateTimeChangeEventListener(Tizen::Ui::IDateTimeChangeEventListener& listener);

	/**
	 * Removes the IDateTimeChangeEventListener instance. @n
	 * The removed listener is not called even when the date and time change events are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]   listener	The listener to be removed
	 * @see			IDateTimeChangeEventListener::OnDateTimeChanged()
	 * @see			IDateTimeChangeEventListener::OnDateTimeChangeCanceled()
	 * @see			AddDateTimeChangeEventListener()
	 */
	void RemoveDateTimeChangeEventListener(Tizen::Ui::IDateTimeChangeEventListener& listener);

	/**
	 * Initializes this instance of %DateTimePicker to the current date and time in the wall time mode.
	 *
	 * @since			2.0
	 *
	 * @return	    An error code
	 * @param[in]   title				The title
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Base::String& title = L"");

	/**
	 *  Sets the date and time value of the %DateTimePicker control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	dateTime	The date and time to be set
	 */
	void SetDateTime(const Tizen::Base::DateTime& dateTime);

	/**
	 * Sets the date and time value of the %DateTimePicker control with the current date and time in the Coordinated Universal Time (UTC) mode.
	 *
	 * @since		2.0
	 */
	void SetCurrentDateTime(void);

	/**
	 * Sets the year value of the %DateTimePicker control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	year			The year value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c year value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by SetYearRange().
	 * @remarks		The specified @c year should be in the range set by SetYearRange(). The default year range is from @c 1 to @c 9999.
	 * @see			SetYearRange()
	 */
	result SetYear(int year);

	/**
	 * Sets the month value. @n
	 * The month value should be between @c 1 and @c 12.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	month	The month value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c month value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetMonth(int month);

	/**
	 * Sets the day value.
	 * The day value should be between @c 1 and @c 31.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	day	 The day value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c day value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetDay(int day);

	/**
	 * Sets the hour value of the %DateTimePicker control.
	 * The hour value should be between @c 0 and @c 23.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	hour			The hour value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c hour value is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result SetHour(int hour);

	/**
	 * Sets the minute value of the %DateTimePicker control.
	 * The minute value should be between @c 0 and @c 59.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	minute		    The minute value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c minute value is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result SetMinute(int minute);

	/**
	 * Gets the current date and time value of the %DateTimePicker control.
	 *
	 * @since		 2.0
	 *
	 * @return   The current date and time
	 * @remarks     This method does not work when %DateTimePicker style is DATETIME_PICKER_STYLE_FROMTO.
	 */
	Tizen::Base::DateTime GetDateTime(void) const;

	/**
	 * Gets the current year value of %DateTimePicker. @n
	 * The year value should be between @c 1 to @c 9999.
	 *
	 * @since		2.0
	 *
	 * @return	    The current year value, @n
	 *			    else @c -1 if an error occurs
	 */
	int GetYear(void) const;

	/**
	 * Gets the current month value of %DateTimePicker. @n
	 * The month value should be between @c 1 to @c 12.
	 *
	 * @since		2.0
	 *
	 * @return	    The current month value, @n
	 *			    else @c -1 if an error occurs
	 */
	int GetMonth(void) const;

	/**
	 * Gets the current day value of %DateTimePicker. @n
	 * The day value should be between @c 1 to @c 31.
	 *
	 * @since		2.0
	 *
	 * @return	    The current day value , @n
	 *			    else @c -1 if an error occurs
	 */
	int GetDay(void) const;

	/**
	 * Gets the current hour value of the %DateTimePicker control. @n
	 * The hour value should be between @c 0 to @c 23.
	 *
	 * @since		2.0
	 *
	 * @return	    The current hour value, @n
	 *			    else @c -1 if an error occurs
	 * @remarks	    Whether the time display mode is 12-hour or 24-hour, this method always returns the hour value ranging from @c 0 to @c 23.
	 */
	int GetHour(void) const;

	/**
	 * Gets the current minute value of the %DateTimePicker control.
	 *
	 * @since		2.0
	 *
	 * @return	    The current minute value, @n
	 *			    else @c -1 if an error occurs
	 */
	int GetMinute(void) const;

	/**
	 * Sets the 12-hour or 24-hour display mode of the %DateTimePicker control.
	 *
	 * @since		2.0
	 */
	void Set24HourNotationEnabled(bool enable);

	/**
	 * Checks whether the 24-hour notation is enabled for the %DateTimePicker control. @n
	 * This can be 12-hour or 24-hour mode.
	 *
	 * @since		2.0
	 *
	 * @return	@c true if the 24-hour notation is enabled, @n
	 *			else @c false if the 12-hour notation is enabled
	 */
	bool Is24HourNotationEnabled(void) const;

	/**
	 * Sets the valid year range. @n
	 * The range should be set  between @c 1 and @c 9999.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   minYear                The minimum year for the valid range
	 * @param[in]   maxYear                The maximum year for the valid range
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG          The specified year range is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetYearRange(int minYear, int maxYear);

	/**
	 * Gets the valid year range.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  minYear                The minimum year for the valid range
	 * @param[out]  maxYear                The maximum year for the valid range
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 */
	result GetYearRange(int& minYear, int& maxYear) const;

protected:
	friend class _DateTimePickerImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	DateTimePicker(const DateTimePicker& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	DateTimePicker& operator =(const DateTimePicker& rhs);

}; // DateTimePicker

}}} // Tizen::Ui::Controls

#endif      // _FUI_CTRL_DATE_TIME_PICKER_H_
