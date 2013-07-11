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
 * @file			FUiCtrlEditTime.h
 * @brief		This is the header file for the %EditTime class.
 *
 * This header file contains the declarations of the %EditTime class.
 */
#ifndef _FUI_CTRL_EDIT_TIME_H_
#define _FUI_CTRL_EDIT_TIME_H_

#include <FUiControl.h>
#include <FUiITimeChangeEventListener.h>
#include <FUiIOrientationEventListener.h>

namespace Tizen { namespace Ui { namespace  Controls
{

/**
 * @class	EditTime
 * @brief    This class defines the common behavior of an %EditTime control.
 *
 * @since	2.0
 *
 * The %EditTime class displays a small, fixed-size selector that allows the user to select a time.
 * Unlike TimePicker, %EditTime can be placed in a container.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a>.
 *
 * The following example demonstrates how to use the %EditTime class.
 *
 * @code
// Sample code for EditTimeSample.h
#include <FUi.h>

class EditTimeSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ITimeChangeEventListener
{
public:
	EditTimeSample(void)
	: __pEditTime(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// ITimeChangeEventListener
	virtual void OnTimeChanged(const Tizen::Ui::Control& source, int hour, int minute);
	virtual void OnTimeChangeCanceled(const Tizen::Ui::Control& source);

private:
	Tizen::Ui::Controls::EditTime* __pEditTime;
};
 *	@endcode
 *
 *	@code
// Sample code for EditTimeSample.cpp
#include <FGraphics.h>

#include "EditTimeSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
EditTimeSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
EditTimeSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of EditTime
	__pEditTime = new EditTime();
	__pEditTime->Construct(Point(100, 100));
	__pEditTime->AddTimeChangeEventListener(*this);

	//Adds the edit time to the form
	AddControl(*__pEditTime);

	return r;
}

// ITimeChangeEventListener implementation
void
EditTimeSample::OnTimeChanged(const Control& source, int hour, int minute)
{
	// ....
}

void
EditTimeSample::OnTimeChangeCanceled(const Control& source)
{
	// ....
}
 * @endcode
 */
class _OSP_EXPORT_ EditTime
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	EditTime(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~EditTime(void);

	/**
	 * Adds a time changed event listener instance.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The listener to be added
	 * @see				ITimeChangeEventListener::OnTimeChanged()
	 * @see				ITimeChangeEventListener::OnTimeChangeCanceled()
	 * @see				RemoveTimeChangeEventListener()
	 */
	void AddTimeChangeEventListener(Tizen::Ui::ITimeChangeEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The listener to be removed
	 * @see				AddTimeChangeEventListener()
	 */
	void RemoveTimeChangeEventListener(Tizen::Ui::ITimeChangeEventListener& listener);

	/**
	 * Initializes this instance of %EditTime with the specified parameters.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	point				The position of %EditTime in container
	 * @param[in]	title			The title
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Point& point, const Tizen::Base::String& title = L"");

	/**
	 * Gets the current hour value of the %EditTime control.
	 *
	 * @since		2.0
	 *
	 * @return	The current hour value, @n
	 *			else @c -1 if the %EditTime instance is not constructed @n
	 *			The hour value is between @c 0 to @c 23.
	 */
	int GetHour(void) const;

	/**
	 * Gets the current minute value of the %EditTime control.
	 *
	 * @since	2.0
	 *
	 * @return	The current minute value, @n
	 *			else @c -1 if this %EditTime instance is not constructed
	 */
	int GetMinute(void) const;

	/**
	 * Gets the current time value of the %EditTime control.
	 *
	 * @since			2.0
	 *
	 * @return		The time value
	 */
	Tizen::Base::DateTime GetTime(void) const;

	/**
	 * Sets the 12-hour or 24-hour display type of the %EditTime. @n
	 * This can be 12-hour or 24-hour type.
	 *
	 * @since			2.0
	 *
	 * @param[in]	enable	Set to @c true to set the 24-hour notation, @n
	 *						else @c false to set the 12-hour notation
	 */
	void Set24HourNotationEnabled(bool enable);

	/**
	 * Sets the hour value of the %EditTime control. @n
	 * The hour value should be between @c 0 and @c 23.
	 *
	 * @since			2.0
	 *
	 * @param[in]	hour			The hour value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified hour value is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 *
	 */
	result SetHour(int hour);

	/**
	 * Sets the minute value of the %EditTime control. @n
	 * The minute value should be between @c 0 and @c 59.
	 *
	 * @since			2.0
	 *
	 * @param[in]	minute			The minute value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified minute value is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 *
	 */
	result SetMinute(int minute);

	/**
	 * Sets the designated time value of the %EditTime control.
	 *
	 * @since			2.0
	 *
	 * @param[in]	time	The time to be set
	 */
	void SetTime(const Tizen::Base::DateTime& time);

	/**
	 * Sets the value of the %EditTime control using the current system time.
	 *
	 * @since		2.0
	 */
	void SetCurrentTime(void);

	/**
	 * Enables TimePicker.
	 *
	 * @since				2.0
	 *
	 * @param[in]	enable		Set to @c true to enable %TimePicker, @n
	 *							else @c false
	 */
	void SetTimePickerEnabled(bool enable);

	/**
	 * Checks whether TimePicker is enabled.
	 *
	 * @since		2.0
	 *
	 * @return	@c true if TimePicker is enabled, @n
	 *			else @c false
	 */
	bool IsTimePickerEnabled(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	EditTime(const EditTime& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	EditTime& operator =(const EditTime& rhs);

	friend class _EditTimeImpl;
}; // EditTime

}}} //Tizen::Ui::Controls

#endif      // _FUI_CTRL_EDIT_TIME_H_
