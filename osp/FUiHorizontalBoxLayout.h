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
 * @file		FUiHorizontalBoxLayout.h
 * @brief		This is the header file for the %HorizontalBoxLayout class.
 *
 * This header file contains the declarations of the %HorizontalBoxLayout class.
 */

#ifndef _FUI_HORIZONTAL_BOX_LAYOUT_H_
#define _FUI_HORIZONTAL_BOX_LAYOUT_H_

#include <FUiLayout.h>

namespace Tizen { namespace Ui
{
class Control;

/**
 * @class	HorizontalBoxLayout
 * @brief	The horizontal box layout positions the children of a container horizontally.
 *
 * @since	2.0
 *
 * The %HorizontalBoxLayout class defines the horizontal box layout for a Container. The layout positions the children of the %Container horizontally.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/single_dimensional_layout.htm">Vertical and Horizontal Box Layouts</a>.
 *
 * @code
// Sample code for HorizontalBoxLayoutSample.h
#include <FUi.h>

class HorizontalBoxLayoutSample
	: public Tizen::Ui::Controls::Form
{
public:
	bool Initialize(void);
	virtual result OnInitializing(void);
};
 *	@endcode
 *
 *	@code
// Sample code for HorizontalBoxLayoutSample.cpp
#include <FGraphics.h>

#include "HorizontalBoxLayoutSample.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui;
using namespace Tizen::Graphics;

bool
HorizontalBoxLayoutSample::Initialize(void)
{
	//Creates an instance of VerticalBoxLayout
	VerticalBoxLayout formLayout;
	formLayout.Construct(VERTICAL_DIRECTION_DOWNWARD);

	// Applies the vertical box layout to the form
	Construct(formLayout, FORM_STYLE_NORMAL);
	return true;
}

result
HorizontalBoxLayoutSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of HorizontalBoxLayout for the top panel
	HorizontalBoxLayout topPanelLayout;
	topPanelLayout.Construct(HORIZONTAL_DIRECTION_RIGHTWARD);

	// Creates an instance of Panel and applies it to the horizontal box layout
	Panel* pTopPanel = new Panel();
	pTopPanel->Construct(topPanelLayout, Rectangle(0, 0, GetClientAreaBounds().width, 450));
	{
		// Creates instances of Label and an instance of Button
		Label* pLabel1 = new Label();
		pLabel1->Construct(Rectangle(0,0,GetClientAreaBounds().width/4,100), L"TOP");
		pLabel1->SetTextConfig(20, LABEL_TEXT_STYLE_NORMAL);
		pLabel1->SetBackgroundColor(Color(0x00, 0x10, 0x80, 0xFF));
		pTopPanel->AddControl(*pLabel1);

		Label* pLabel2 = new Label();
		pLabel2->Construct(Rectangle(0,0,GetClientAreaBounds().width/4,100), L"MIDDLE");
		pLabel2->SetTextConfig(20, LABEL_TEXT_STYLE_NORMAL);
		pLabel2->SetBackgroundColor(Color(0x00, 0x20, 0xA0, 0xFF));
		pTopPanel->AddControl(*pLabel2);

		Label* pLabel3 = new Label();
		pLabel3->Construct(Rectangle(0,0,GetClientAreaBounds().width/4,100), L"BOTTOM");
		pLabel3->SetTextConfig(20, LABEL_TEXT_STYLE_NORMAL);
		pLabel3->SetBackgroundColor(Color(0x00, 0x30, 0xC0, 0xFF));
		pTopPanel->AddControl(*pLabel3);

		Button* pButton = new Button();
		pButton->Construct(Rectangle(0,0,GetClientAreaBounds().width/4 - 10,100), L"FIT\nTO\nPARENT");
		pButton->SetTextSize(20);
		pTopPanel->AddControl(*pButton);

		// Sets relations each label and button
		topPanelLayout.SetVerticalAlignment(*pLabel1, LAYOUT_VERTICAL_ALIGN_TOP);
		topPanelLayout.SetVerticalAlignment(*pLabel2, LAYOUT_VERTICAL_ALIGN_MIDDLE);
		topPanelLayout.SetVerticalAlignment(*pLabel3, LAYOUT_VERTICAL_ALIGN_BOTTOM);
		topPanelLayout.SetSpacing(*pButton, 10);
		topPanelLayout.SetVerticalFitPolicy(*pButton, FIT_POLICY_PARENT);
	}
	// Adds the top panel to the form
	AddControl(*pTopPanel);

	// Creates an instance of HorizontalBoxLayout for bottom panel
	HorizontalBoxLayout bottomPanelLayout;
	bottomPanelLayout.Construct(HORIZONTAL_DIRECTION_RIGHTWARD);

	// Creates an instance of Panel and applies it to the horizontal box layout
	Panel* pBottomPanel = new Panel();
	pBottomPanel->Construct(bottomPanelLayout, Rectangle(0, 0, 400, 500));
	{
		// Creates instances of Label
		Label* pLabel1 = new Label();
		pLabel1->Construct(Rectangle(0,0,30,100), L"W\n1.0f");
		pLabel1->SetBackgroundColor(Color(0x00, 0x10, 0x80, 0xFF));
		pBottomPanel->AddControl(*pLabel1);

		Label* pLabel2 = new Label();
		pLabel2->Construct(Rectangle(0,0,30,100), L"W\n2.0f");
		pLabel2->SetBackgroundColor(Color(0x00, 0x20, 0xA0, 0xFF));
		pBottomPanel->AddControl(*pLabel2);

		Label* pLabel3 = new Label();
		pLabel3->Construct(Rectangle(0,0,30,100), L"W\n3.0f");
		pLabel3->SetBackgroundColor(Color(0x00, 0x30, 0xC0, 0xFF));
		pBottomPanel->AddControl(*pLabel3);

		// Sets relations each label
		bottomPanelLayout.SetVerticalFitPolicy(*pLabel1, FIT_POLICY_PARENT);
		bottomPanelLayout.SetVerticalFitPolicy(*pLabel2, FIT_POLICY_PARENT);
		bottomPanelLayout.SetVerticalFitPolicy(*pLabel3, FIT_POLICY_PARENT);
		bottomPanelLayout.SetWeight(*pLabel1, 1.0f);
		bottomPanelLayout.SetWeight(*pLabel2, 2.0f);
		bottomPanelLayout.SetWeight(*pLabel3, 3.0f);
	}

	// Adds the bottom panel to the form
	AddControl(*pBottomPanel);

	//Gets the layout of the form
	VerticalBoxLayout* pFormLayout = dynamic_cast<VerticalBoxLayout*>(this->GetLayoutN());

	// Sets relations between panels
	pFormLayout->SetHorizontalFitPolicy(*pTopPanel, FIT_POLICY_PARENT);
	pFormLayout->SetSpacing(*pBottomPanel, 30);
	pFormLayout->SetHorizontalFitPolicy(*pBottomPanel, FIT_POLICY_PARENT);

	return r;
}
 * @endcode
 *
 */

class _OSP_EXPORT_ HorizontalBoxLayout
	: public Layout
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 *
	 * @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	HorizontalBoxLayout(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~HorizontalBoxLayout(void);

	/**
	 * Initializes this instance of %HorizontalBoxLayout with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	direction		The direction in which the children are attached
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(HorizontalDirection direction);

	/**
	 * Gets the direction of %HorizontalBoxLayout.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	direction		The direction in which the children are attached
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result GetDirection(HorizontalDirection& direction) const;

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 *
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Sets the vertical alignment of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the alignment is set
	 * @param[in]	alignment		The vertical alignment
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the horizontal alignment is VERTICAL_ALIGN_TOP.
	 */
	result SetVerticalAlignment(Control& childControl, LayoutVerticalAlignment alignment);

	/**
	 * Sets the space between the specified control and its predecessor.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the space is set
	 * @param[in]	space			The space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the spacing is set to @c 0.
	 */
	result SetSpacing(Control& childControl, int space);

	/**
	 * Sets the vertical margins of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	top				The top margin
	 * @param[in]	bottom			The bottom margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetVerticalMargin(Control& childControl, int top, int bottom);

	/**
	 * Sets the width of the specified control with the fixed length.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	width		    The value of the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetWidth(Control& childControl, int width);

	/**
	 * Sets the width of the specified control with the fitting policy.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	policy			The fitting policy for the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Setting FIT_POLICY_PARENT as @c policy does not cause the width of control to change.
	 */
	result SetHorizontalFitPolicy(Control& childControl, FitPolicy policy);

	/**
	 * Sets the height of the specified control with a fixed length.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	height			The value of the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHeight(Control& childControl, int height);

	/**
	 * Sets the height of the specified control with the fitting policy.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	policy			The fitting policy for the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetVerticalFitPolicy(Control& childControl, FitPolicy policy);

	/**
	 * Sets the weight of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the weight is set
	 * @param[in]	weight			The weight that indicates how much extra space the control occupies in proportion to it, in the %HorizontalBoxLayout
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the weight is set to @c 0.0f.
	 */
	result SetWeight(Control& childControl, float weight);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	HorizontalBoxLayout(const HorizontalBoxLayout& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	HorizontalBoxLayout& operator =(const HorizontalBoxLayout& rhs);
}; // HorizontalBoxLayout

}} // Tizen::Ui

#endif // _FUI_HORIZONTAL_BOX_LAYOUT_H_
