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
 * @file	FUiCtrlRadioGroup.h
 * @brief	This is the header file for the %RadioGroup class.
 *
 * This header file contains the declarations of the %RadioGroup class and its helper classes.
 */

#ifndef _FUI_CTRL_RADIO_GROUP_H_
#define _FUI_CTRL_RADIO_GROUP_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlCheckButton.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @class	RadioGroup
 * @brief	This class is an implementation of a %RadioGroup control.
 *
 * @since	2.0
 *
 * The %RadioGroup class displays a set of CheckButtons with radio style together in a group, allowing the user to select only
 * one of the predefined set of buttons.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_button.htm">Buttons</a>.
 *
 * The following example demonstrates how to use the %RadioGroup class.
 *
 * @code
// Sample code for RadioGroupSample.h
#include <FUi.h>

class RadioGroupSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	RadioGroupSample(void)
	: __pRadioGroup(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_BUTTON1_CHECKED = 101;
	static const int ID_BUTTON1_UNCHECKED = 102;
	static const int ID_BUTTON2_CHECKED = 103;
	static const int ID_BUTTON2_UNCHECKED = 104;

	Tizen::Ui::Controls::RadioGroup* __pRadioGroup;
};
 *	@endcode
 *
 *	@code
// Sample code for RadioGroupSample.cpp
#include <FGraphics.h>

#include "RadioGroupSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
RadioGroupSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
RadioGroupSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates instances of CheckButton
	CheckButton *pCheckButton1 = new CheckButton();
	pCheckButton1->Construct(Rectangle(50, 50, GetClientAreaBounds().width - 100, 100),
			CHECK_BUTTON_STYLE_RADIO, BACKGROUND_STYLE_DEFAULT, false, L"Radio1");
	pCheckButton1->SetActionId(ID_BUTTON1_CHECKED, ID_BUTTON1_UNCHECKED);
	pCheckButton1->AddActionEventListener(*this);

	CheckButton *pCheckButton2 = new CheckButton();
	pCheckButton2->Construct(Rectangle(50, 160, GetClientAreaBounds().width - 100, 100),
			CHECK_BUTTON_STYLE_RADIO,BACKGROUND_STYLE_DEFAULT, false, L"Radio2");
	pCheckButton2->SetActionId(ID_BUTTON2_CHECKED, ID_BUTTON2_UNCHECKED);
	pCheckButton2->AddActionEventListener(*this);

	// Adds check buttons to the form
	AddControl(*pCheckButton1);
	AddControl(*pCheckButton2);

	// Creates an instance of RadioGroup
	__pRadioGroup = new RadioGroup();
	__pRadioGroup->Construct();

	// Adds the check buttons to the radio group
	__pRadioGroup->Add(*pCheckButton1);
	__pRadioGroup->Add(*pCheckButton2);

	return r;
}

result
RadioGroupSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the __pRadioGroup
	delete __pRadioGroup;

	return r;
}

// IActionEventListener implementation
void
RadioGroupSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON1_CHECKED:
		{
			// ....
		}
		break;
	case ID_BUTTON1_UNCHECKED:
		{
			// ....
		}
		break;
	case ID_BUTTON2_CHECKED:
		{
			// ....
		}
		break;
	case ID_BUTTON2_UNCHECKED:
		{
			// ....
		}
		break;
	default:
		break;
	}
}
 * @endcode
 *
 */
class _OSP_EXPORT_ RadioGroup
	: public Tizen::Ui::Control
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	RadioGroup(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~RadioGroup(void);


	/**
	 * Initializes this instance of %RadioGroup.
	 *
	 * @since			2.0
	 *
	 * @return      An error code
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result Construct(void);

public:
	/**
	 * Adds the check button to the radio group.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	checkButton		The %CheckButton instance to be added
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Only CheckButtons whose style is CHECK_BUTTON_STYLE_RADIO or CHECK_BUTTON_STYLE_RADIO_WITH_DIVIDER can be added to %RadioGroup.
	 */
	result Add(const CheckButton& checkButton);

	/**
	 * Removes the check button from the radio group.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	checkButton			The %CheckButton instance to be removed
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The object is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Before removing %CheckButton from its parent container, it must be removed from %RadioGroup.
	 */
	result Remove(const CheckButton& checkButton);

public:
	/**
	 * Gets the number of check buttons in the radio group.
	 *
	 * @since	2.0
	 *
	 * @return	The number of check buttons in the radio group
	 */
	int GetItemCount(void) const;

	/**
	 * Selects the specified check button in the radio group.
	 *
	 * @since			2.0
	 *
	 * @param[in]		checkButton		The check button to be selected
	 */
	void SetSelectedItem(const CheckButton& checkButton);

	/**
	 * Gets the selected check button in the radio group.
	 *
	 * @since			2.0
	 *
	 * @return	The pointer to the selected check button, @n
	 *			else  @c null if an error occurs or no check button in the radio group is selected
	 *
	 */
	const CheckButton* GetSelectedItem(void) const;

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is prohibited. If this method is used
	// in an application, the application can get rejected during the certification
	// process.
	//
	// (Blocked) Draws the control.
	//
	// @since		2.0
	//
	// @return		An error code
	// @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	//
	virtual result Draw(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is prohibited. If this method is used
	// in an application, the application can get rejected during the certification
	// process.
	//
	// (Blocked) Shows this control.
	//
	// @since		2.0
	//
	// @return		An error code
	// @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	//
	virtual result Show(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is prohibited. If this method is used
	// in an application, the application can get rejected during the certification
	// process.
	//
	// (Blocked) Gives the input focus to the control. @n
	// One must call this method if the control needs to listen to the user input events such as key pressed.
	//
	// @since		2.0
	//
	// @return		An error code
	// @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	//
	virtual result SetFocus(void);

protected:
	friend class _RadioGroupImpl;

private:
	//
	// This is the copy constructor for the %RadioGroup class.
	//
	RadioGroup(const RadioGroup& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %RadioGroup.
	//
	RadioGroup& operator =(const RadioGroup& rhs);

}; // RadioGroup

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_RADIO_GROUP_H_
