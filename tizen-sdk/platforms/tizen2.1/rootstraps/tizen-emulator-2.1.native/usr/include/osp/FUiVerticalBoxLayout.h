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
 * @file		FUiVerticalBoxLayout.h
 * @brief		This is the header file for the %VerticalBoxLayout class.
 *
 * This header file contains the declarations of the %VerticalBoxLayout class.
 */
#ifndef _FUI_VERTICAL_BOX_LAYOUT_H_
#define _FUI_VERTICAL_BOX_LAYOUT_H_

#include <FUiLayout.h>

namespace Tizen { namespace Ui
{
class Control;

/**
 * @class	VerticalBoxLayout
 * @brief	The vertical box layout positions the children of a container vertically.
 *
 * @since	2.0
 *
 * The %VerticalBoxLayout class defines the vertical box layout for a Container. The layout positions the children of the %Container vertically.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/single_dimensional_layout.htm">Vertical and Horizontal Box Layouts</a>.
 *
 * The following examples demonstrate how to use the %VerticalBoxLayout class.
 * @code
// Sample code for VerticalBoxLayoutSample.h
#include <FUi.h>

class VerticalBoxLayoutSample
	: public Tizen::Ui::Controls::Form
{
public:
	bool Initialize(void);
	virtual result OnInitializing(void);
};
 *	@endcode
 *
 *	@code
// Sample code for VerticalBoxLayoutSample.cpp
#include <FGraphics.h>

#include "VerticalBoxLayoutSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
VerticalBoxLayoutSample::Initialize(void)
{
	//Creates an instance of VerticalBoxLayout
	VerticalBoxLayout formLayout;
	formLayout.Construct(VERTICAL_DIRECTION_DOWNWARD);

	// Applies the vertical box layout to the form
	Construct(formLayout, FORM_STYLE_NORMAL);
	return true;
}

result
VerticalBoxLayoutSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of VerticalBoxLayout for the top panel
	VerticalBoxLayout topPanelLayout;
	topPanelLayout.Construct(VERTICAL_DIRECTION_DOWNWARD);

	// Creates an instance of Panel and applies it to the vertical box layout
	Panel* pTopPanel = new Panel();
	pTopPanel->Construct(topPanelLayout, Rectangle(0, 0, GetClientAreaBounds().width, 350));
	{
		// Creates instances of Label and a instance of Button
		Label* pLabel1 = new Label();
		pLabel1->Construct(Rectangle(0,0,150,80), L"RIGHT");
		pLabel1->SetBackgroundColor(Color(0x00, 0x10, 0x80, 0xFF));
		pTopPanel->AddControl(pLabel1);

		Label* pLabel2 = new Label();
		pLabel2->Construct(Rectangle(0,0,200,80), L"CENTER");
		pLabel2->SetBackgroundColor(Color(0x00, 0x20, 0xA0, 0xFF));
		pTopPanel->AddControl(pLabel2);

		Label* pLabel3 = new Label();
		pLabel3->Construct(Rectangle(0,0,150,80), L"LEFT");
		pLabel3->SetBackgroundColor(Color(0x00, 0x30, 0xC0, 0xFF));
		pTopPanel->AddControl(pLabel3);

		Button* pButton = new Button();
		pButton->Construct(Rectangle(0,0,150,80), "FIT TO PARENT");
		pTopPanel->AddControl(pButton);

		// Sets relations each label and button
		topPanelLayout.SetHorizontalAlignment(*pLabel1, LAYOUT_HORIZONTAL_ALIGN_RIGHT);
		topPanelLayout.SetHorizontalAlignment(*pLabel2, LAYOUT_HORIZONTAL_ALIGN_CENTER);
		topPanelLayout.SetHorizontalAlignment(*pLabel3, LAYOUT_HORIZONTAL_ALIGN_LEFT);
		topPanelLayout.SetSpacing(*pButton, 10);
		topPanelLayout.SetHorizontalFitPolicy(*pButton, FIT_POLICY_PARENT);
	}

	// Adds the top panel to the form
	AddControl(pTopPanel);

	// Creates an instance of VerticalBoxLayout for the bottom panel
	VerticalBoxLayout bottomPanelLayout;
	bottomPanelLayout.Construct(VERTICAL_DIRECTION_DOWNWARD);

	// Creates an instance of Panel and applies it to the vertical box layout
	Panel* pBottomPanel = new Panel();
	pBottomPanel->Construct(bottomPanelLayout, Rectangle(0, 0, GetClientAreaBounds().width, 450));
	{
		// Creates instances of Label
		Label* pLabel1 = new Label();
		pLabel1->Construct(Rectangle(0,0,100,50), L"WEIGHT = 1.0f");
		pLabel1->SetBackgroundColor(Color(0x00, 0x10, 0x80, 0xFF));
		pBottomPanel->AddControl(pLabel1);

		Label* pLabel2 = new Label();
		pLabel2->Construct(Rectangle(0,0,100,50), L"WEIGHT = 2.0f");
		pLabel2->SetBackgroundColor(Color(0x00, 0x20, 0xA0, 0xFF));
		pBottomPanel->AddControl(pLabel2);

		Label* pLabel3 = new Label();
		pLabel3->Construct(Rectangle(0,0,100,50), L"WEIGHT = 3.0f");
		pLabel3->SetBackgroundColor(Color(0x00, 0x30, 0xC0, 0xFF));
		pBottomPanel->AddControl(pLabel3);

		// Sets relations each label
		bottomPanelLayout.SetHorizontalFitPolicy(*pLabel1, FIT_POLICY_PARENT);
		bottomPanelLayout.SetHorizontalFitPolicy(*pLabel2, FIT_POLICY_PARENT);
		bottomPanelLayout.SetHorizontalFitPolicy(*pLabel3, FIT_POLICY_PARENT);
		bottomPanelLayout.SetWeight(*pLabel1, 1.0f);
		bottomPanelLayout.SetWeight(*pLabel2, 2.0f);
		bottomPanelLayout.SetWeight(*pLabel3, 3.0f);
	}

	// Adds the bottom panel to the form
	AddControl(pBottomPanel);

	//Gets the layout of the form
	VerticalBoxLayout* pFormLayout = dynamic_cast<VerticalBoxLayout*>(this->GetLayoutN());

	// Sets relations between panels
	pFormLayout->SetHorizontalFitPolicy(*pTopPanel, FIT_POLICY_PARENT);
	pFormLayout->SetSpacing(*pBottomPanel, 50);
	pFormLayout->SetHorizontalFitPolicy(*pBottomPanel, FIT_POLICY_PARENT);

	return r;
}
 * @endcode
 *
 */
class _OSP_EXPORT_ VerticalBoxLayout
	: public Layout
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	VerticalBoxLayout(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~VerticalBoxLayout(void);

	/**
	 * Initializes this instance of %VerticalBoxLayout with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	direction			The direction in which the children are attached
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(VerticalDirection direction);

	/**
	 * Gets the direction of %VerticalBoxLayout.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	direction		The direction in which the children are attached
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result GetDirection(VerticalDirection& direction) const;

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 *
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Sets the horizontal alignment of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl		The control for which the alignment is set
	 * @param[in]	alignment			The horizontal alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		By default, the horizontal alignment is HORIZONTAL_ALIGNLEFT.
	 */
	result SetHorizontalAlignment(Control& childControl, LayoutHorizontalAlignment alignment);

	/**
	 * Sets the space between the specified control and its predecessor.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the space is set
	 * @param[in]	space		    The space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the spacing is set to @c 0.
	 */
	result SetSpacing(Control& childControl, int space);

	/**
	 * Sets the space between a specified control and its predecessor.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the space is set
	 * @param[in]	space		    The space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the spacing is set to @c 0.
	 */
	result SetSpacing(Control& childControl, float space);

	/**
	 * Sets the horizontal margins of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetHorizontalMargin(Control& childControl, int left, int right);

	/**
	 * Sets the horizontal margins of a specified control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetHorizontalMargin(Control& childControl, float left, float right);

	/**
	 * Sets the width of the specified control with the fixed length.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	width			The value of the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetWidth(Control& childControl, int width);

	/**
	 * Sets the width of a specified control with the fixed length.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	width			The value of the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetWidth(Control& childControl, float width);

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
	 * Sets the height of a specified control with a fixed length.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	height			The value of the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHeight(Control& childControl, float height);

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
	 * @remarks		Setting FIT_POLICY_PARENT as @c policy does not cause the height of the control to change.
	 */
	result SetVerticalFitPolicy(Control& childControl, FitPolicy policy);

	/**
	 * Sets the weight of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the weight is set
	 * @param[in]	weight			The weight that indicates how much extra space the control occupies in proportion to it, in the %VerticalBoxLayout.
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
	VerticalBoxLayout(const VerticalBoxLayout& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	VerticalBoxLayout& operator =(const VerticalBoxLayout& rhs);
}; // VerticalBoxLayout

}} // Tizen::Ui

#endif // _FUI_VERTICAL_BOX_LAYOUT_H_
