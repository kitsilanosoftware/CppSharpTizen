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
 * @file			FUiCtrlEditDate.h
 * @brief	This is the header file for the %EditDate class.
 *
 * This header file contains the declarations of the %EditDate class.
 */
#ifndef _FUI_CTRL_EDITDATE_H_
#define _FUI_CTRL_EDITDATE_H_

#include <FUiControl.h>
#include <FUiIDateChangeEventListener.h>
#include <FUiIOrientationEventListener.h>

namespace Tizen { namespace Ui { namespace  Controls
{

/**
 * @class	EditDate
 * @brief    This class defines the common behavior of an %EditDate control.
 *
 * @since		2.0
 *
 * The %EditDate class displays a small, fixed-size selector that allows the user to select a date. Unlike the DatePicker, %EditDate can be placed in a container.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a>.
 *
 * The following example demonstrates how to use the %EditDate class.
 *
 * @code
// Sample code for EditDateSample.h
#include <FUi.h>

class EditDateSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IDateChangeEventListener
{
public:
	EditDateSample(void)
	: __pEditDate(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IDateChangeEventListener
	virtual void OnDateChanged(const Tizen::Ui::Control& source, int year, int month, int day);
	virtual void OnDateChangeCanceled(const Tizen::Ui::Control& source);

private:
	Tizen::Ui::Controls::EditDate* __pEditDate;
};

 *	@endcode
 *
 *	@code
// Sample code for EditDateSample.cpp
#include <FGraphics.h>

#include "EditDateSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
EditDateSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
EditDateSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of EditDate
	__pEditDate = new EditDate();
	__pEditDate->Construct(Point(100, 100));
	__pEditDate->AddDateChangeEventListener(*this);

	// Adds an instace of IDateChangeEventListener
	AddControl(*__pEditDate);

	return r;
}

// IDateChangeEventListener implementation
void
EditDateSample::OnDateChanged(const Tizen::Ui::Control& source, int year, int month, int day)
{
	// ....
}

void
EditDateSample::OnDateChangeCanceled(const Tizen::Ui::Control& source)
{
	// ....
}
 * @endcode
 */
class _OSP_EXPORT_ EditDate
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	EditDate(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~EditDate(void);

	/**
	 * Adds a data change event listener instance.
	 * Added listener is called when the date of the DatePicker is changed either through user manipulation or by calling one of its setters.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The listener to be added
	 * @see				IDateChangeEventListener::OnDateChanged()
	 * @see				IDateChangeEventListener::OnDateChangeCanceled()
	 * @see				RemoveDateChangeEventListener()
	 */
	void AddDateChangeEventListener(Tizen::Ui::IDateChangeEventListener& listener);

	/**
	 * Removes a date changed event listener instance. @n
	 * Removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener	The listener to be removed
	 * @see				IDateChangeEventListener::OnDateChanged()
	 * @see				IDateChangeEventListener::OnDateChangeCanceled()
	 * @see				AddDateChangeEventListener()
	 */
	void RemoveDateChangeEventListener(Tizen::Ui::IDateChangeEventListener& listener);

	/**
	 * Initializes this instance of %EditDate with the specified parameter.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	point	        The position of the %EditDate in the container
	 * @param[in]	title	        The title
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore, some methods may fail if used earlier.
	 */
	result Construct(const Tizen::Graphics::Point& point, const Tizen::Base::String& title = L"");

	/**
	 * Gets the current date value of the %EditDate control.
	 *
	 * @since		2.0
	 *
	 * @return		The date value
	 */
	Tizen::Base::DateTime GetDate(void) const;

	/**
	 * Gets the current day value of the %EditDate control.
	 *
	 * @since		2.0
	 *
	 * @return		The current day value as an integer, @n
	 *			else @c -1 if the %EditDate instance is not constructed
	 */
	int GetDay(void) const;

	/**
	 * Gets the current month value of the %EditDate control.
	 *
	 * @since	2.0
	 *
	 * @return   The current month value as an integer,  @n
	 *			else @c -1 if the %EditDate instance is not constructed
	 */
	int GetMonth(void) const;

	/**
	 * Gets the current year value of the %EditDate control.
	 *
	 * @since		2.0
	 *
	 * @return		The current year value, @n
	 *				else @c -1 if the %EditDate instance is not constructed
	 */
	int GetYear(void) const;

	/**
	 * Sets the designated time value of the %EditDate control.
	 *
	 * @since		 2.0
	 *
	 * @param[in]	date	The date to be set
	 */
	void SetDate(const Tizen::Base::DateTime& date);

	/**
	 * Sets the value of the %EditDate control using the current system date.
	 *
	 * @since		2.0
	 */
	void SetCurrentDate(void);

	/**
	 * Sets the year value.
	 * The year value should be between @c 1 and @c 9999.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	year	        The year to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The given year value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetYear(int year);

	/**
	 * Sets the month value of the %EditDate control.
	 * The month value should be between @c 1 and @c 12.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	month	        The month to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The given month value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result SetMonth(int month);

	/**
	 * Sets the day value of the %EditDate control.
	 * The day value should be between @c 1 and @c 31.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	day				The day to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The given day value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetDay(int day);

	/**
	 * Enables the %DatePicker control.
	 *
	 * @since				2.0
	 *
	 * @param[in]	enable		Set to @c true to enable the DatePicker control, @n
	 *							else @c false
	 */
	void SetDatePickerEnabled(bool enable);

	/**
	 * Checks whether the DatePicker control is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the DatePicker control is enabled, @n
	 *				else @c false
	 */
	bool IsDatePickerEnabled(void) const;

	/**
	 * Sets the valid year range. @n
	 * The range should be set in between @c 1 and @c 9999.
	 *
	 * @since			 2.0
	 *
	 * @return                             An error code
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
	 * @exception    E_SUCCESS		The method is successful.
	 * @exception    E_SYSTEM		A system error has occurred.
	 */
	result GetYearRange(int& minYear, int& maxYear) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	EditDate(const EditDate& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	EditDate& operator =(const EditDate& rhs);

	friend class _EditDateImpl;
}; // EditDate

}}} //Tizen::Ui::Controls

#endif      // _FUI_CTRL_EDITDATE_H_
