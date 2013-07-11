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
 * @file			FUiCtrlColorPicker.h
 * @brief	This is the header file for the %ColorPicker class.
 *
 * This header file contains the declarations of the %ColorPicker class.
 */
#ifndef _FUI_CTRL_COLOR_PICKER_H_
#define _FUI_CTRL_COLOR_PICKER_H_

#include <FUiControl.h>
#include <FUiIColorChangeEventListener.h>
#include <FUiIOrientationEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	ColorPicker
 * @brief This class defines the common behavior of a %ColorPicker control.
 *
 * @since 2.0
 *
 * The %ColorPicker class displays a set of 3 sliders (hue, saturation, and luminance) with which the user can define a color.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_colorpicker.htm">ColorPicker</a>.
 *
 * The following example demonstrates how to use the %ColorPicker class.
 *
 * @code
// Sample code for ColorPickerSample.h
#include <FUi.h>
#include <FGraphics.h>

class ColorPickerSample
	: public Tizen::Ui::Controls::Form
    , public Tizen::Ui::IColorChangeEventListener
{
public:
	ColorPickerSample(void)
	: __pColorPicker(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IColorChangeEventListener
	virtual void OnColorChanged(const Tizen::Ui::Control& source, const Tizen::Graphics::Color& color);

private:
	Tizen::Ui::Controls::ColorPicker* __pColorPicker;
};

 *	@endcode
 *
 *	@code

// Sample code for ColorPickerSample.cpp
#include "ColorPickerSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
ColorPickerSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ColorPickerSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of ColorPicker
	__pColorPicker = new ColorPicker();
	__pColorPicker->Construct(Point(10,50));
	__pColorPicker->AddColorChangeEventListener(*this);

	// Adds the color picker to the form
	AddControl(*__pColorPicker);

	return r;
}

// IColorChangeEventListener implementation
void
ColorPickerSample::OnColorChanged(const Control& source, const Color& color)
{
	// ....
}
 * @endcode
 */

class _OSP_EXPORT_ ColorPicker
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	ColorPicker(void);

	/**
	 *	This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ColorPicker(void);

	/**
	 * Initializes this instance of %ColorPicker with the specified parameter.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	point	        The position of this %ColorPicker in the container
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container. Therefore, some methods may fail if the control is used earlier.
	 */
	result Construct(const Tizen::Graphics::Point& point);

	/**
	 * Gets the current color value of %ColorPicker.
	 *
	 * @since		2.0
	 *
	 * @return		The current color value
	 */
	Tizen::Graphics::Color GetColor(void) const;

	/**
	 * Gets the current hue value of %ColorPicker.
	 *
	 * @since		2.0
	 *
	 * @return		The current hue value
	 * @remarks		The return value is between @c 0 to @c 100.
	 */
	int GetHue(void) const;

	/**
	 * Gets the current saturation value of %ColorPicker.
	 *
	 * @since		2.0
	 *
	 * @return		The current saturation value
	 * @remarks		The return value is between @c 0 to @c 100.
	 */
	int GetSaturation(void) const;

	/**
	 * Gets the current luminance value of %ColorPicker.
	 *
	 * @since		2.0
	 *
	 * @return		The current luminance value
	 * @remarks		The return value is between @c 0 to @c 100.
	 */
	int GetLuminance(void) const;

	/**
	 * Sets the color value of %ColorPicker.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color	The color value
	 */
	void SetColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the hue value of %ColorPicker.
	 *
	 * @since			2.0
	 *
	 * @param[in]	hue	The hue value of this object
	 * @remarks			The value should be between @c 0 to @c 100.
	 *
	 */
	void SetHue(int hue);

	/**
	 * Sets the saturation value of %ColorPicker.
	 *
	 * @since			2.0
	 *
	 * @param[in]	saturation	The saturation value of this object
	 * @remarks			The value should be between @c 0 to @c 100.
	 *
	 */
	void SetSaturation(int saturation);

	/**
	 * Sets the luminance value of %ColorPicker.
	 *
	 * @since			2.0
	 *
	 * @param[in]	luminance	The luminance value of this object
	 * @remarks			The value should be between @c 0 to @c 100.
	 *
	 */
	void SetLuminance(int luminance);

	/**
	 * Adds a listener instance.
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The event listener to be added
	 * @see				RemoveColorChangeEventListener()
	 */
	void AddColorChangeEventListener(Tizen::Ui::IColorChangeEventListener& listener);

	/**
	 * Removes a listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The event listener to be removed
	 * @see				AddColorChangeEventListener()
	 */
	void RemoveColorChangeEventListener(Tizen::Ui::IColorChangeEventListener& listener);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ColorPicker(const ColorPicker& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ColorPicker& operator =(const ColorPicker& rhs);

	friend class _ColorPickerImpl;
};	// ColorPicker

}}}	// Tizen::Ui::Controls

#endif // _FUI_CTRL_COLOR_PICKER_H_
