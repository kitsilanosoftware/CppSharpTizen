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
 * @file		FUiRelativeLayout.h
 * @brief		This is the header file for the %RelativeLayout class.
 *
 * This header file contains the declarations of the %RelativeLayout class.
 */

#ifndef _FUI_RELATIVE_LAYOUT_H_
#define _FUI_RELATIVE_LAYOUT_H_

#include <FUiLayout.h>

namespace Tizen { namespace Ui
{
class Control;
}}

namespace Tizen { namespace Ui
{

/**
 * @class	RelativeLayout
 * @brief	The relative layout positions the children of a container in a manner that is relative to other children or its parent container.
 *
 * @since	2.0
 *
 * The %RelativeLayout class defines the relative layout for a Container. The layout positions the children of the %Container relative to the
 * Container or its other children. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/relative_layout.htm">Relative Layout</a>.
 *
 * @code
// Sample code for RelativeLayoutSample.h
#include <FUi.h>

class RelativeLayoutSample
	: public Tizen::Ui::Controls::Form
{
public:
	bool Initialize(void);
	virtual result OnInitializing(void);
};
 *	@endcode
 *
 *	@code
// Sample code for RelativeLayoutSample.cpp
#include <FGraphics.h>

#include "RelativeLayoutSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
RelativeLayoutSample::Initialize(void)
{
	// Creates an instance of RelativeLayout
	RelativeLayout relativeFormLayout;
	relativeFormLayout.Construct();

	// Applies the relative layout to the form
	Construct(relativeFormLayout, FORM_STYLE_NORMAL);
	return true;
}

result
RelativeLayoutSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of RelativeLayout for the top panel
	RelativeLayout topPanelLayout;
	topPanelLayout.Construct();

	// Creates an instance of Panel and applies it to the relative layout
	Panel* pTopRelativePanel = new Panel();
	pTopRelativePanel->Construct(topPanelLayout, Rectangle(0, 0, 300, 300));
	{
		// Creates instances of Button
		Button* pUpButton = new Button();
		pUpButton->Construct(Rectangle(0,0,200,100), "UP");
		pTopRelativePanel->AddControl(*pUpButton);

		Button* pMiddleButton = new Button();
		pMiddleButton->Construct(Rectangle(0,0,200,100), "CENTER");
		pTopRelativePanel->AddControl(*pMiddleButton);

		Button* pDownButton = new Button();
		pDownButton->Construct(Rectangle(0,0,200,100), "DOWN");
		pTopRelativePanel->AddControl(*pDownButton);

		// Sets relations between the pUpButton and pMiddleButton
		topPanelLayout.SetRelation(*pUpButton, *pMiddleButton, RECT_EDGE_RELATION_LEFT_TO_LEFT);
		topPanelLayout.SetRelation(*pUpButton, *pMiddleButton, RECT_EDGE_RELATION_BOTTOM_TO_TOP);
		topPanelLayout.SetMargin(*pUpButton, 0, 0, 0, 10);

		// Sets the middle button
		topPanelLayout.SetCenterAligned(*pMiddleButton, CENTER_ALIGN_HORIZONTAL);
		topPanelLayout.SetCenterAligned(*pMiddleButton, CENTER_ALIGN_VERTICAL);
		topPanelLayout.SetMargin(*pMiddleButton, 10, 10, 10, 10);

		// Sets relations between the pDownButton and the pMiddleButton
		topPanelLayout.SetRelation(*pDownButton, *pMiddleButton, RECT_EDGE_RELATION_RIGHT_TO_RIGHT);
		topPanelLayout.SetRelation(*pDownButton, *pMiddleButton, RECT_EDGE_RELATION_TOP_TO_BOTTOM);
		topPanelLayout.SetMargin(*pDownButton, 0, 0, 10, 0);
	}

	// Adds the top panel to the form
	AddControl(*pTopRelativePanel);

	// Creates an instance of RelativeLayout for the bottom panel
	RelativeLayout bottomPanelLayout;
	bottomPanelLayout.Construct();

	// Creates an instance of Panel and applies it to the relative layout
	Panel* pBottomRelativePanel = new Panel();
	pBottomRelativePanel->Construct(bottomPanelLayout, Rectangle(0, 0, 300, 300));
	{
		// Creates instances of Label
		Label* pFixedLabel = new Label();
		pFixedLabel->Construct(Rectangle(0, 0, 150, 80), L"FIXED");
		pFixedLabel->SetBackgroundColor(Color::GetColor(COLOR_ID_YELLOW));
		pFixedLabel->SetTextColor(Color::GetColor(COLOR_ID_BLACK));
		pBottomRelativePanel->AddControl(*pFixedLabel);

		Label* pScalableLabel = new Label();
		pScalableLabel->Construct(Rectangle(0, 0, 150, 80), L"SCALABLE <=>");
		pScalableLabel->SetBackgroundColor(Color::GetColor(COLOR_ID_BLUE));
		pScalableLabel->SetTextColor(Color::GetColor(COLOR_ID_BLACK));
		pBottomRelativePanel->AddControl(*pScalableLabel);

		// Sets relations between the fixed label and the panel
		bottomPanelLayout.SetCenterAligned(*pFixedLabel, CENTER_ALIGN_VERTICAL);
		bottomPanelLayout.SetRelation(*pFixedLabel, *pBottomRelativePanel, RECT_EDGE_RELATION_LEFT_TO_LEFT);
		bottomPanelLayout.SetRelation(*pFixedLabel, *pBottomRelativePanel, RECT_EDGE_RELATION_TOP_TO_TOP);
		bottomPanelLayout.SetMargin(*pFixedLabel, 30, 30, 30, 30);

		// Sets relations between the scalable label and the panel
		bottomPanelLayout.SetCenterAligned(*pScalableLabel, CENTER_ALIGN_VERTICAL);
		bottomPanelLayout.SetRelation(*pScalableLabel, *pFixedLabel, RECT_EDGE_RELATION_LEFT_TO_RIGHT);
		bottomPanelLayout.SetRelation(*pScalableLabel, *pFixedLabel, RECT_EDGE_RELATION_LEFT_TO_RIGHT);
		bottomPanelLayout.SetRelation(*pScalableLabel, *pBottomRelativePanel, RECT_EDGE_RELATION_RIGHT_TO_RIGHT);
		bottomPanelLayout.SetRelation(*pScalableLabel, *pBottomRelativePanel, RECT_EDGE_RELATION_TOP_TO_TOP);
		bottomPanelLayout.SetMargin(*pScalableLabel, 30, 30, 30, 30);
	}

	// Adds the bottom panel to the form
	AddControl(*pBottomRelativePanel);

	//Gets the layout of the form
	RelativeLayout* pFormLayout = dynamic_cast<RelativeLayout*>(this->GetLayoutN());

	// Sets relations of the top relative panel
	pFormLayout->SetRelation(*pTopRelativePanel, *this, RECT_EDGE_RELATION_LEFT_TO_LEFT);
	pFormLayout->SetRelation(*pTopRelativePanel, *this, RECT_EDGE_RELATION_RIGHT_TO_RIGHT);
	pFormLayout->SetRelation(*pTopRelativePanel, *this, RECT_EDGE_RELATION_TOP_TO_TOP);

	// Sets relations of the bottom relative panel
	pFormLayout->SetRelation(*pBottomRelativePanel, *this, RECT_EDGE_RELATION_LEFT_TO_LEFT);
	pFormLayout->SetRelation(*pBottomRelativePanel, *this, RECT_EDGE_RELATION_RIGHT_TO_RIGHT);
	pFormLayout->SetRelation(*pBottomRelativePanel, *this, RECT_EDGE_RELATION_BOTTOM_TO_BOTTOM);

	// Sets relations between the top relative panel and the bottom relative panel
	pFormLayout->SetHorizontalFitPolicy(*pTopRelativePanel, FIT_POLICY_PARENT);
	pFormLayout->SetHorizontalFitPolicy(*pBottomRelativePanel, FIT_POLICY_PARENT);
	pFormLayout->SetVerticalFitPolicy(*pBottomRelativePanel, FIT_POLICY_FIXED);
	pFormLayout->SetRelation(*pTopRelativePanel, *pBottomRelativePanel, RECT_EDGE_RELATION_BOTTOM_TO_TOP);

	return r;
}
 * @endcode
 *
 */
class _OSP_EXPORT_ RelativeLayout
	: public Layout
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	RelativeLayout(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~RelativeLayout(void);

	/**
	 * Initializes this instance of %RelativeLayout.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Gets the type of the layout.
	 *
	 * @since		2.0
	 *
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Sets the relation of the specified child control for the edge with other control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the relation is set
	 * @param[in]	targetControl	The target control @n
	 *								It must be a parent or sibling.
	 * @param[in]	edgeRelation	The edge of the specified control to be aligned with the edge of the target control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								Either the specified @c childControl or the specified @c targetControl is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRelation(Control& childControl, const Control& targetControl, RectangleEdgeRelation edgeRelation);

	/**
	 * Resets the relation of the specified control for the vertical edge.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the relation is reset
	 * @param[in]	edgeType		The edge type of the specified control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result ResetRelation(Control& childControl, RectangleEdgeType edgeType);

	/**
	 * Sets the specified control at the center of the parent control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control to be center aligned
	 * @param[in]	alignment		The center alignment for a control either vertically or horizontally
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The relation value that is set to a child control is ignored when the center-alignment is applied to the control.
	 */
	result SetCenterAligned(Control& childControl, CenterAlignmentType alignment);

	/**
	 * Resets the center position of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control to be center aligned
	 * @param[in]	alignment		The center alignment for a control either vertically or horizontally
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result ResetCenterAligned(Control& childControl, CenterAlignmentType alignment);

	/**
	 * Sets the margins of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @param[in]	top				The top margin
	 * @param[in]	bottom			The bottom margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetMargin(Control& childControl, int left, int right, int top, int bottom);

	/**
	 * Sets the width of the specified control to the fixed size.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	width			The value of the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetWidth(Control& childControl, int width);

	/**
	 * Sets the width of the specified control as per the fitting policy.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	policy			The fitting policy for the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHorizontalFitPolicy(Control& childControl, FitPolicy policy);

	/**
	 * Sets the height of the specified control to the fixed size.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	height			The value of the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHeight(Control& childControl, int height);

	/**
	 * Sets the height of the specified control as per the fitting policy.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	policy			The fitting policy for the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetVerticalFitPolicy(Control& childControl, FitPolicy policy);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	RelativeLayout(const RelativeLayout& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	RelativeLayout& operator =(const RelativeLayout& rhs);

}; // RelativeLayout

}} // Tizen::Ui

#endif // _FUI_RELATIVE_LAYOUT_H_
