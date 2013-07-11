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
 * @file	FUiCtrlLabel.h
 * @brief	This is the header file for the %Label class.
 *
 * This header file contains the declarations of the %Label class and its helper classes.
 */

#ifndef _FUI_CTRL_LABEL_H_
#define _FUI_CTRL_LABEL_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseResult.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpColor.h>
#include <FGrpPoint.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlLabelTypes.h>
#include <FUiCtrlControlsTypes.h>
#include <FUi.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @class	Label
 * @brief   This class defines the common behavior of a %Label control.
 *
 * @since	2.0
 *
 * The %Label class displays a non-editable text field and does not accept any input from the user.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_label.htm">Label</a>.
 *
 * The following example demonstrates how to use the %Label class.
 *
 * @code
// Sample code for LabelSample.h
#include <FUi.h>

class LabelSample
	: public Tizen::Ui::Controls::Form
{
public:
	LabelSample(void)
	: __pLabel(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

private:
	Tizen::Ui::Controls::Label *__pLabel;
};
 *	@endcode
 *
 *	@code
// Sample code for LabelSample.cpp
#include <FGraphics.h>

#include "LabelSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
LabelSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
LabelSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Label
	__pLabel = new Label();
	__pLabel->Construct(Rectangle(100, 100, 200, 50), L"Label Text");
	__pLabel->SetTextConfig(30, LABEL_TEXT_STYLE_BOLD);
	__pLabel->SetBackgroundColor(Color::GetColor(COLOR_ID_BLUE));

	// Adds the label to the form
	AddControl(*__pLabel);

	return r;
}
 * @endcode
 *
 */
class _OSP_EXPORT_ Label
	: public Tizen::Ui::Control
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Label(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Label(void);

	/**
	 * Initializes this instance of %Label with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the window.
	 * @param[in]   text				The text for this label instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *				To display text in multi-lines or to denote the end of line use '\\n'. @n
	 *				The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, const Tizen::Base::String& text);

public:
	/**
	 * Sets the specified text for the %Label control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   text		The string to set
	 * @remarks		To display text in multi-lines or to denote the end of line use '\\n'.
	 */
	void SetText(const Tizen::Base::String& text);

	/**
	 * Gets the text of the %Label control.
	 *
	 * @since	2.0
	 *
	 * @return	The text of the %Label control, @n
	 *			else an empty string if an error occurs
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Sets the background bitmap of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	bitmap	 The background bitmap
	 */
	void SetBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the horizontal alignment of the text of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	alignment	The horizontal text alignment
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Gets the horizontal alignment of the text of the %Label control.
	 *
	 * @since	2.0
	 *
	 * @return	The horizontal text alignment, @n
	 *			else @c ALIGNMENT_LEFT if the instance is invalid
	 */
	HorizontalAlignment GetTextHorizontalAlignment(void) const;

	/**
	 * Sets the vertical alignment of the text of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   alignment	The vertical text alignment
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

	/**
	 * Gets the vertical alignment of the text of the %Label control.
	 *
	 * @since	2.0
	 *
	 * @return	The vertical text alignment, @n
	 *			else @c ALIGNMENT_TOP if the instance is invalid
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;

	/**
	 * Sets the background color of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	color		The normal background color
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @return		The background color
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the text color of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	color		The color to be set
	 */
	virtual void SetTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %Label control.
	 *
	 * @since		2.0
	 *
	 * @return		The text color
	 */
	virtual Tizen::Graphics::Color GetTextColor(void) const;

	/**
	 * Sets the text attributes of the %Label control.
	 *
	 * @since			2.0
	 *
	 * @param[in]	size			The size of the text
	 * @param[in]	style			The style of the text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *				If @c size is less than the minimum size, this method fails. The minimum font size is 6 on devices of high screen density.
	 */
	void SetTextConfig(int size, LabelTextStyle style);

	/**
	 * Gets the text size of the %Label control.
	 *
	 * @since	2.0
	 *
	 * @return	The size of the text, @n
	 *			else @c -1 if an error occurs
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the text style of the %Label control.
	 *
	 * @since	2.0
	 *
	 * @return  The style of the text, @n
	 *			else @c LABEL_TEXT_STYLE_NORMAL if the instance is invalid
	 */
	LabelTextStyle GetTextStyle(void) const;

	/**
	 * Sets the top and left margins.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]   topMargin         The top margin.
	 * @param[in]   leftMargin        The left margin.
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     The specified input parameter is invalid. @n
	 *                                The specified @c size must be greater than @c 0.

	 * @see                           GetTopMargin(), GetLeftMargin()
	 */
	result SetMargin(int topMargin, int leftMargin);

	/**
	 * Gets the top margin.
	 *
	 * @since	2.0
	 *
	 * @return      The size of the top margin, @n
	 *              else @c -1 if an error occurs
	 * @see         SetMargin()
	 */
	int GetTopMargin(void) const;

    /**
     * Gets the left margin.
     *
     * @since	2.0
     *
     * @return      The size of the left margin, @n
     *              else @c -1 if an error occurs.
     * @see         SetMargin()
     */
	int GetLeftMargin(void) const;

protected:
	friend class _LabelImpl;

private:
	//
	// This is the copy constructor for this class.
	//
	Label(const Label& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %Label.
	//
	Label& operator =(const Label& rhs);

}; // Label

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_LABEL_H_
