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
 * @file			FUiCtrlDatePicker.h
 * @brief		This is the header file for the %DatePicker class.
 *
 * This header file contains the declarations of the %DatePicker class.
 */
#ifndef _FUI_CTRL_DATE_PICKER_H_
#define _FUI_CTRL_DATE_PICKER_H_

#include <FUiWindow.h>
#include <FUiIDateChangeEventListener.h>

namespace Tizen { namespace Ui { namespace  Controls
{

/**
 * @class	DatePicker
 * @brief	This class displays a full screen %DatePicker on top of the screen.
 *
 * @since		2.0
 *
 * @remarks   One cannot change the size and the position of the %DatePicker.
 *
 * The %DatePicker class displays a full screen window-based selector that allows the user to select a certain date.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
 *
 * The following example demonstrates how to use the %DatePicker class.
 *
 * @code
// Sample code for DatePickerSample.h
#include <FUi.h>

class DatePickerSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IDateChangeEventListener
	, public Tizen::Ui::IActionEventListener
{
public:
	DatePickerSample(void)
	:__pDatePicker(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	void ShowDatePicker(bool show);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	// IDateChangeEventListener
	virtual void OnDateChanged(const Tizen::Ui::Control& source, int year, int month, int day);
	virtual void OnDateChangeCanceled(const Tizen::Ui::Control& source);

private:
	static const int ID_BUTTON  = 101;

	Tizen::Ui::Controls::DatePicker* __pDatePicker;
};

 *	@endcode
 *
 *	@code
// Sample code for DatePickerSample.cpp
#include "DatePickerSample.h"
#include <FGraphics.h>

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
DatePickerSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
DatePickerSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Button
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 50, 300, 200), L"Show DatePicker");
	pButton->SetActionId(ID_BUTTON);
	pButton->AddActionEventListener(*this);

	// Adds the button to the form
	AddControl(*pButton);

	// Creates an instance of DatePicker
	__pDatePicker = new DatePicker();
	__pDatePicker->Construct();

	// Adds an instace of IDateChangeEventListener
	__pDatePicker->AddDateChangeEventListener(*this);

	// Shows the date picker after it's owner form is shown.

	return r;
}

void
DatePickerSample::ShowDatePicker(bool show)
{
	// Changes to desired show state
	__pDatePicker->SetShowState(show);

	// Calls Show() of the control
	if (show)
	{
		__pDatePicker->Show();
	}
	// Calls Show() of the container
	else
	{
		Invalidate(true);
	}
}

result
DatePickerSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the date picker
	delete __pDatePicker;

	return r;
}

// IActionEventListener implementation
void
DatePickerSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON:
		{
			ShowDatePicker(true);
		}
		break;
	default:
		break;
	}
}

// IDateChangeEventListener implementation
void
DatePickerSample::OnDateChanged(const Control& source, int year, int month, int day)
{
	// ....
}

void
DatePickerSample::OnDateChangeCanceled(const Control& source)
{
	// ....
}
 * @endcode
 */
class _OSP_EXPORT_ DatePicker
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	DatePicker(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~DatePicker(void);

	/**
	 * Adds a data change event listener instance. @n
	 * The added listener is called when the date of the %DatePicker is changed either through user manipulation or by calling one of its setters.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be added
	 * @see			IDateChangeEventListener::OnDateChanged()
	 * @see			IDateChangeEventListener::OnDateChangeCanceled()
	 * @see			RemoveDateChangeEventListener()
	 */
	void AddDateChangeEventListener(Tizen::Ui::IDateChangeEventListener& listener);

	/**
	 * Removes a date changed event listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be removed
	 * @see			IDateChangeEventListener::OnDateChanged()
	 * @see			IDateChangeEventListener::OnDateChangeCanceled()
	 * @see			AddDateChangeEventListener()
	 */
	void RemoveDateChangeEventListener(Tizen::Ui::IDateChangeEventListener& listener);

	/**
	 * Initializes this instance of %DatePicker with the specified parameter.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	title               The title
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 */
	result Construct(const Tizen::Base::String& title = L"");

	/**
	 * Gets the current date value of the %DatePicker control.
	 *
	 * @since	2.0
	 *
	 * @return   A %DateTime instance
	 */
	Tizen::Base::DateTime GetDate(void) const;

	/**
	 * Gets the current day value of the %DatePicker control. @n
	 * The day value is between @c 1 to @c 31.
	 *
	 * @since	2.0
	 *
	 * @return	The current day value, @n
	 *           else @c -1 if an error occurs
	 */
	int GetDay(void) const;

	/**
	 * Gets the current month value of the %DatePicker control. @n
	 * The month value is between @c 1 to @c 12.
	 *
	 * @since	2.0
	 *
	 * @return	The current month value, @n
	 *           else @c -1 if an error occurs
	 */
	int GetMonth(void) const;

	/**
	 * Gets the current year value of the %DatePicker control.
	 * The year value is between @c 1 to @c 9999.
	 *
	 * @since	2.0
	 *
	 * @return	The current year value, @n
	 *           else @c -1 if an error occurs
	 *
	 */
	int GetYear(void) const;

	/**
	 * Sets the date value of the %DatePicker control.
	 *
	 * @since		2.0
	 *
	 * @param[in]    date	The date to be set
	 */
	void SetDate(const Tizen::Base::DateTime& date);

	/**
	 * Sets the date value of the %DatePicker control with the current date.
	 *
	 * @since		2.0
	 */
	void SetCurrentDate(void);

	/**
	 * Sets the year value. @n
	 * The year value should be between @c 1 and @c 9999.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	year	The year value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified year value is invalid.
	 */
	result SetYear(int year);

	/**
	 * Sets the month value. @n
	 * The month value should be between @c 1 and @c 12.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	month	        The month value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified month value is invalid.
	 */
	result SetMonth(int month);

	/**
	 * Sets the day value. @n
	 * The day value should be between @c 1 and @c 31.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	day	            The day value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c day is invalid.
	 */
	result SetDay(int day);

	/**
	 * Sets the valid year range.
	 * The range should be set in between @c 1 and @c 9999.
	 *
	 * @since			 2.0
	 *
	 * @return                              An error code
	 * @param[in]   minYear                The minimum year for the valid range
	 * @param[in]   maxYear                The maximum year for the valid range
	 * @exception    E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG          The given year range is invalid.
	 * @exception    E_SYSTEM			A system error has occurred.
	 */
	result SetYearRange(int minYear, int maxYear);

	/**
	 * Gets the valid year range.
	 *
	 * @since			 2.0
	 *
	 * @return                             An error code
	 * @param[out]  minYear                The minimum year for the valid range
	 * @param[out]  maxYear                The maximum year for the valid range
	 * @exception    E_SUCCESS			The method is successful.
	 * @exception    E_SYSTEM			A system error has occurred.
	 */
	result GetYearRange(int& minYear, int& maxYear) const;

protected:
	friend class _DatePickerImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	DatePicker(const DatePicker& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	DatePicker& operator =(const DatePicker& rhs);

}; // DatePicker

}}} // Tizen::Ui::Controls

#endif      // _FUI_CTRL_DATE_PICKER_H_
