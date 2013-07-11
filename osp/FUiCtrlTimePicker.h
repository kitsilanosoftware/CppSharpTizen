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
 * @file			FUiCtrlTimePicker.h
 * @brief	This is the header file for the %TimePicker class.
 *
 * This header file contains the declarations of the %TimePicker class.
 */
#ifndef _FUI_CTRL_TIME_PICKER_H_
#define _FUI_CTRL_TIME_PICKER_H_

#include <FUiWindow.h>
#include <FUiITimeChangeEventListener.h>

namespace Tizen { namespace Ui { namespace  Controls
{

/**
 * @class	TimePicker
 * @brief	This class displays a %TimePicker control on top of the screen.
 *
 * @since	2.0
 *
 * The %TimePicker class displays a full screen window-based selector that allows the user to select a certain time.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimeimePicker</a>.
 *
 * The following example demonstrates how to use the %TimePicker class.
 *
 * @code
// Sample Code for TimePickerSample.h
#include <FUi.h>

class TimePickerSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ITimeChangeEventListener
	, public Tizen::Ui::IActionEventListener
{
public:
	TimePickerSample(void)
	: __pTimePicker(null){}

	bool Initialize(void);
	void ShowTimePicker(bool show);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	// ITimeChangeEventListener
	virtual void OnTimeChanged(const Tizen::Ui::Control& source, int hour, int minute);
	virtual void OnTimeChangeCanceled(const Tizen::Ui::Control& source);

private:
	static const int ID_BUTTON  = 101;

	Tizen::Ui::Controls::TimePicker* __pTimePicker;
};
 *	@endcode
 *
 *	@code
// Sample Code for TimePickerSample.cpp
#include <FGraphics.h>

#include "TimePickerSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
TimePickerSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
TimePickerSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Createa an instance of Button
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 50, 300, 200), L"Show TimePicker");
	pButton->SetActionId(ID_BUTTON);
	pButton->AddActionEventListener(*this);

	// Adda a Button to the Form
	AddControl(*pButton);

	// Creates an instanceo of TimePicker
	__pTimePicker = new TimePicker();
	__pTimePicker->Construct();

	// Adds an instanceo of ITimeChangeEventListener
	__pTimePicker->AddTimeChangeEventListener(*this);

	// Show TimePicker after it's owner Form is shown.

	return r;
}

void
TimePickerSample::ShowTimePicker(bool show)
{
	// Change to desired show state
	__pTimePicker->SetShowState(show);

	//Call Show() of the control
	if (show)
	{
		__pTimePicker->Show();
	}
	// Call Invalidate() of the container
	else
	{
		Invalidate(true);
	}
}

result
TimePickerSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the time picker
	delete __pTimePicker;

	return r;
}

// IActionEventListener implementation
void
TimePickerSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON:
		ShowTimePicker(true);
		break;

	default:
		break;
	}
}


// ITimeChangeEventListener implementation
void
TimePickerSample::OnTimeChanged(const Control& source, int hour, int minute)
{
	// Todo:
}

void
TimePickerSample::OnTimeChangeCanceled(const Control& source)
{
	// Todo:
}
 * @endcode
 */
class _OSP_EXPORT_ TimePicker
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	TimePicker(void);

	/**
	 *	This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~TimePicker(void);

	/**
	 * Adds a time changed event listener instance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be added
	 * @see			ITimeChangeEventListener::OnTimeChanged()
	 * @see			ITimeChangeEventListener::OnTimeChangeCanceled()
	 * @see			RemoveTimeChangeEventListener()
	 */
	void AddTimeChangeEventListener(Tizen::Ui::ITimeChangeEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to be removed
	 * @see			AddTimeChangeEventListener()
	 */
	void RemoveTimeChangeEventListener(Tizen::Ui::ITimeChangeEventListener& listener);

	/**
	 * Initializes this instance of %TimePicker to the current date and time in wall time mode.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	title               The title
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 */
	result Construct(const Tizen::Base::String& title = L"");

	/**
	 * Gets the current hour value of the %TimePicker control. @n
	 * The hour value is between @c 0 to @c 23.
	 *
	 * @since		2.0
	 *
	 * @return		The current hour value, @n
	 *				else @c -1 if an error occurs
	 */
	int GetHour(void) const;

	/**
	 * Gets the current minute value of the %TimePicker control. @n
	 * The minute value is between @c 0 to @c 59.
	 *
	 * @since		2.0
	 *
	 * @return		The current minute value, @n
	 *				else @c -1 if an error occurs
	 */
	int GetMinute(void) const;

	/**
	 * Gets the current time value of the %TimePicker control.
	 *
	 * @since		2.0
	 *
	 * @return		The time value
	 */
	Tizen::Base::DateTime GetTime(void) const;

	/**
	 * Sets the 12H or 24H hour display type of the %TimePicker control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable		Set to @c true to enable the 24 hour notation, @n
	 *							else @c false
	 */
	void Set24HourNotationEnabled(bool enable);

	/**
	 * Sets the hour value. @n
	 * The hour value should be between @c 0 and @c  23.
	 *
	 * @since		2.0
	 *
	 * @param[in]	hour	        The hour value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c hour value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHour(int hour);

	/**
	 * Sets the minute value. @n
	 * The minute value should be between @c 0 and @c 59.
	 *
	 * @since		2.0
	 *
	 * @param[in]	minute          The minute value
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c minute value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetMinute(int minute);

	/**
	 * Sets the current time value of the %TimePicker control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	time	The time to be set
	 */
	void SetTime(const Tizen::Base::DateTime& time);

	/**
	 * Sets the time value of the %TimePicker control with the current system time in the Coordinated Universal Time (UTC) mode.
	 *
	 * @since		2.0
	 */
	void SetCurrentTime(void);

protected:
	friend class _TimePickerImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	TimePicker(const TimePicker& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	TimePicker& operator =(const TimePicker& rhs);

}; // TimePicker

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_TIME_PICKER_H_
