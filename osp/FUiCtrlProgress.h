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
 * @file	FUiCtrlProgress.h
 * @brief	This is the header file for the %Progress class.
 *
 * This header file contains the declarations of the %Progress class and its helper classes.
 */

#ifndef _FUI_CTRL_PROGRESS_H_
#define _FUI_CTRL_PROGRESS_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlControlsTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	Progress
 * @brief	This class is an implementation of a %Progress control.
 *
 * @since	2.0
 *
 * The %Progress class displays the progress of a lengthy operation in a progress bar.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_progress.htm">Progress</a>.
 *
 * The following example demonstrates how to use the %Progress class.
 *
 * @code
// Sample code for ProgressSample.h
#include <FUi.h>

class ProgressSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	ProgressSample(void)
	: __pProgress(null)
	, __pValue(0){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control&, int);

private:
	static const int ID_BUTTON_CHECKED = 100;

	Tizen::Ui::Controls::Progress* __pProgress;
	int __pValue;
};
 *	@endcode
 *
 *	@code
// Sample code for ProgressSample.cpp
#include <FGraphics.h>

#include "ProgressSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
ProgressSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ProgressSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Progress
	__pProgress = new Progress();
	__pProgress->Construct(Rectangle(50, 50, GetClientAreaBounds().width - 100, 100), 0, 100);
	__pProgress->SetValue(__pValue);

	// Creates an instance of pButton to control progress value
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 200, 150, 100), L"Here");
	pButton->SetActionId(ID_BUTTON_CHECKED);
	pButton->AddActionEventListener(*this);

	// Adds the __pProgress and the pButton to the form
	AddControl(__pProgress);
	AddControl(pButton);

	return r;
}

void
ProgressSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON_CHECKED :
		{
			if (__pValue >= 100)
			{
				__pValue = 0;
			}
			else
			{
				__pValue += 10;
			}
			__pProgress->SetValue(__pValue);
			__pProgress->Invalidate(true);
		}
		break;
	default:
		break;
	}
}
 * @endcode
 *
 */
class _OSP_EXPORT_ Progress
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called.  @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	Progress(void);


	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~Progress(void);


	/**
	 * Initializes this instance of %Progress with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Tizen::Graphics::Rectangle class @n
	 *						            This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *                                  its width and height. @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   minValue			The minimum value of the current instance of %Progress
	 * @param[in]   maxValue			The maximum value of the current instance of %Progress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of an argument is outside the valid range defined by the method. @n
	 *									The specified values should be positive and @c minValue should be less than @c maxValue.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *				- The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, int minValue, int maxValue);

	/**
	 * Initializes this instance of %Progress with the specified parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Tizen::Graphics::FloatRectangle class @n
	 *						            This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *                                  its width and height. @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   minValue			The minimum value of the current instance of %Progress
	 * @param[in]   maxValue			The maximum value of the current instance of %Progress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of an argument is outside the valid range defined by the method. @n
	 *									The specified values should be positive and @c minValue should be less than @c maxValue.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *				- The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, int minValue, int maxValue);

public:
	/**
	 * Sets the current value of the %Progress control. @n
	 * If the given value is greater than the @c maxValue with which %Progress is constructed, it will be set to %maxValue. The same applies for @c minValue.
	 *
	 * @since		2.0
	 *
	 * @param[in]   value	The current progress value
	 */
	void SetValue(int value);


	/**
	 * Sets the minimum and maximum value of the %Progress control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	minValue			The minimum value of the current instance of %Progress
	 * @param[in]	maxValue			The maximum value of the current instance of %Progress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of an argument is outside the valid range defined by the method. @n
	 *									The specified values should be positive.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetRange(int minValue, int maxValue);


	/**
	 * Gets the current value of the %Progress control.
	 *
	 * @since	2.0
	 *
	 * @return	An integer value representing the current value of progress, @n
	 *			else @c -1 if an error occurs
	 */
	int GetValue(void) const;


	/**
	 * Gets the minimum value and the maximum value of the %Progress control.
	 *
	 * @since		2.0
	 *
	 * @param[out]  minValue	The minimum value
	 * @param[out]  maxValue	The maximum value
	*/
	void GetRange(int& minValue, int& maxValue) const;


	/**
	 * Gets the percent value of the %Progress control.
	 *
	 * @since	2.0
	 *
	 * @return	The progress as a percentage, @n
	 *			else @c -1 if an error occurs
	 */
	int GetPercentComplete(void) const;


	/**
	 * Sets the color of the bar.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] color             The color to set
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks   The method ignores the alpha value of the @c color parameter and sets the alpha value to @c 255.
	 */
	result SetBarColor(const Tizen::Graphics::Color& color);


	/**
	 * Gets the color of the bar.
	 *
	 * @since     2.0
	 *
	 * @return    The color of the bar, @n
	 *			  else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception E_SUCCESS         The method is successful.
	 * @remarks   The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetBarColor(void) const;


	/**
	 * Sets the background color of the bar.
	 *
	 * @since     2.1
	 *
	 * @param[in] barBackgroundColor             The color to set
	 * @remarks   The method ignores the alpha value of the @c color parameter and sets the alpha value to @c 255.
	 * @see GetBarBackgroundColor()
	 */
	void SetBarBackgroundColor(const Tizen::Graphics::Color& barBackgroundColor);

	/**
	 * Gets the background color of the bar.
	 *
	 * @since     2.1
	 *
	 * @return    The background color of the bar, @n
	 *			  else RGBA(0, 0, 0, 0) if an error occurs
	 * @remarks   The specific error code can be accessed using the GetLastResult() method.
	 * @see SetBarBackgroundColor()
	 */
	Tizen::Graphics::Color GetBarBackgroundColor(void) const;


private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Progress(const Progress& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Progress& operator =(const Progress& rhs);

	friend class _ProgressImpl;

};  // Progress

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_PROGRESS_H_
