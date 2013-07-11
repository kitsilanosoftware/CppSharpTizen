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
 * @file	FUiCtrlSlider.h
 * @brief	This is the header file for the %Slider class.
 *
 * This header file contains the declarations of the %Slider class and its helper classes.
 */

#ifndef _FUI_CTRL_SLIDER_H_
#define _FUI_CTRL_SLIDER_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseColArrayListT.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiIAdjustmentEventListener.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlGroupTypes.h>
#include <FUiCtrlSliderTypes.h>
#include <FUiCtrlISliderEventListener.h>


namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	Slider
 * @brief	This class is an implementation of a %Slider control.
 *
 * @since	2.0
 *
 * The %Slider class displays a slider that represents changing progress or setting information. The difference between %Slider
 * and Progress is that the former accepts user input by the touch of the slider icon.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_slider.htm">Slider</a>.
 *
 * The following example demonstrates how to use the %Slider class.
 *
 * @code
// Sample code for SliderSample.h
#include <FUi.h>

class SliderSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IAdjustmentEventListener
{
public:
	SliderSample(void)
	: __pSlider(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual void OnAdjustmentValueChanged(const Tizen::Ui::Control& source, int adjustment);

private:
	Tizen::Ui::Controls::Slider* __pSlider;
};
 *	@endcode
 *
 *	@code
// Sample code for SliderSample.cpp
#include <FGraphics.h>

#include "SliderSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
SliderSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
SliderSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Slider
	__pSlider = new Slider();
	__pSlider->Construct(Rectangle(0, 200, GetClientAreaBounds().width, 200), BACKGROUND_STYLE_DEFAULT, false, 0, 100);
	__pSlider->SetValue(50);
	__pSlider->AddAdjustmentEventListener(*this);

	// Adds the slider to the form
	AddControl(*__pSlider);

	return r;
}

// IAdjustmentEventListener implementation
void
SliderSample::OnAdjustmentValueChanged(const Control& source, int adjustment)
{
	// ....
}
 * @endcode
 *
 */
class _OSP_EXPORT_ Slider
	: public Tizen::Ui::Control
{
// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	Slider(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~Slider(void);

	/**
	 * Initializes this instance of %Slider with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the control.
	 * @param[in]	backgroundStyle		The background style set of the slider
	 * @param[in]   showTitle			Set to @c true to enable the show title, @n
	 *									else @c false
	 * @param[in]	minValue			The minimum slider value
	 * @param[in]	maxValue			The maximum slider value
	 * @param[in]   groupStyle			The table view style of the slider
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  The background style of BACKGROUND_STYLE_NONE does not work with group styles except GROUP_STYLE_NONE.
	 * @exception	E_OUT_OF_RANGE		The specified values are less than @c -99 or greater than @c 999.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container. Therefore, some methods may fail if used earlier. @n
	 *				If the given size is less than the minimum, it returns E_INVALID_ARG.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, BackgroundStyle backgroundStyle = BACKGROUND_STYLE_DEFAULT, bool showTitle = false, int minValue = 0, int maxValue = 100, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Adds a IAdjustmentEventListener instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 */
	void AddAdjustmentEventListener(Tizen::Ui::IAdjustmentEventListener& listener);

	/**
	 * Removes a IAdjustmentEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveAdjustmentEventListener(Tizen::Ui::IAdjustmentEventListener& listener);

// Operation
public:
	/**
	 * Sets the range of the %Slider control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	minValue		The minimum value of the %Slider control
	 * @param[in]	maxValue		The maximum value of the %Slider control
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified values are greater than @c -99 or less than @c 999.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRange(int minValue, int maxValue);

	/**
	 * Gets the minimum value and the maximum value of the slider.
	 *
	 * @since		2.0
	 *
	 * @param[out]	minValue		The minimum value of the slider
	 * @param[out]	maxValue		The maximum value of the slider
	 */
	void GetRange(int& minValue, int& maxValue) const;

	/**
	 * Sets the value of the current thumb position. @n
	 * If the specified @c value is greater than @c maxValue, the value is set to @c maxValue, and
	 * if the specified @c value is less than @c minValue, the value is set to @c minValue.
	 *
	 * @since		2.0
	 *
	 * @param[in]   value  The value of the position
	 */
	void SetValue(int value);

	/**
	 * Gets the value of the current thumb position.
	 *
	 * @since		2.0
	 *
	 * @return		The current thumb position
	 */
	int GetValue(void) const;

	/**
	 * Sets the icon of the slider.
	 *
	 * @since		2.0
	 *
	 * @param[in]   position	The position of the icon (ICON_POSITION_LEFT/ICON_POSITION_RIGHT)
	 * @param[in]   icon        The bitmap image of the icon
	 * @remarks     If the size of the bitmap is greater than the default size, the bitmap image is scaled down.
	 */
	void SetIcon(IconPosition position, const Tizen::Graphics::Bitmap& icon);

	/**
 	 * Sets the title of the slider.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]    title		        The title to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM	        A system error has occurred.
	 */
	result SetTitleText(const Tizen::Base::String& title);

	/**
	 * Gets the title of the slider.
	 *
	 * @since		2.0
	 *
	 * @return		The title text of the entered string, @n
	 *			    else an empty string if the %Slider instance is not constructed
	 */
	Tizen::Base::String GetTitleText(void) const;

	/**
	 * Sets the title text color of the %Slider control.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color   The title text color to be set
	 */
	void SetTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of the %Slider control.
	 *
	 * @since		2.0
	 *
	 * @return		The title text color
	 */
	Tizen::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * Initializes this instance of %Slider with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Graphics::Rectangle class @n
	 *								    This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *                                  its width and height.
	 * @param[in]	sliderStyle         The style of the slider @n
	 *                                  Multiple link types can be combined using bitwise OR operator. See Tizen::Ui::Controls::SliderStyle.
	 * @param[in]	minValue            The minimum slider value
	 * @param[in]	maxValue            The maximum slider value
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_OUT_OF_RANGE      The specified minimum and maximum values are less than @c -99, or greater than @c 999.
	 * @exception	E_INVALID_ARG       A specified input parameter is invalid, or the specified @c minValue is greater than @c maxVaue.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks		A control is fully functional only after it has been added to a container. Therefore, some methods may fail if they are used before
	 *				adding the control to the container. @n
	 *				If the specified size is less than the minimum size, the %Slider control is constructed with the minimum size.
	 * @remarks		The width and the height of the control must be greater than @c 0.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, unsigned long sliderStyle, int minValue = 0, int maxValue = 100);

	/**
	 * Adds a ISliderEventListener instance. @n
	 * The added listener can listen to the slider-related events.
	 *
	 * @since     2.0
	 *
	 * @param[in] listener    The event listener to be added
	 */
	void AddSliderEventListener(ISliderEventListener& listener);

	/**
	 * Removes a ISliderEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since     2.0
	 *
	 * @param[in] listener    The event listener to be removed
	 */
	void RemoveSliderEventListener(ISliderEventListener& listener);

	/**
	 * Sets the color of the bar.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] color             The color to be set
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
	 * Sets the color of the slider.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] color                     The color to be set
	 * @exception E_SUCCESS                 The method is successful.
	 * @exception E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The operation is not supported if the background style of the %Slider control is BACKGROUND_STYLE_NONE.
	 * @exception E_SYSTEM                  A system error has occurred.
	 * @remarks   If a device supports only the 16-bit color space, this method considers the color as opaque by ignoring the alpha value of @c color.
	 */
	result SetColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the slider.
	 *
	 * @since		2.0
	 *
	 * @return		The color , @n
	 *				else RGBA(0, 0, 0, 0) if an instance is invalid or the background style is BACKGROUND_STYLE_NONE
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The background style is not proper.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(void) const;

	/**
	 * Sets the bitmap image to the %Slider control Thumb.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param[in] status                    The state of the slider thumb
	 * @param[in] bitmap                    The Thumb bitmap image
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_MEMORY       The memory is insufficient.
	 */
	result SetThumbBitmap(SliderThumbStatus status, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the text color of the %Slider control Thumb.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param[in] status					The state of the slider thumb
	 * @param[in] color					The color should be set for the thumb text
	 */
	void SetThumbTextColor(SliderThumbStatus status, const Tizen::Graphics::Color& color);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Slider(const Slider&);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Slider& operator =(const Slider&);

	friend class _SliderImpl;

};	// Slider

}}}	// Tizen::Ui::Controls

#endif // _FUI_CTRL_SLIDER_H_
