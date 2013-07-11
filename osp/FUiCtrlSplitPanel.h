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
 * @file		FUiCtrlSplitPanel.h
 * @brief	This is the header file for the %SplitPanel class.
 *
 * This header file contains the declarations of the %SplitPanel class.
 */
#ifndef _FUI_CTRL_SPLIT_PANEL_H_
#define _FUI_CTRL_SPLIT_PANEL_H_

#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiCtrlSplitPanelTypes.h>


namespace Tizen { namespace Ui { namespace Controls
{

class ISplitPanelEventListener;

/**
 * @class	SplitPanel
 * @brief	This class is an implementation of a %SplitPanel control.
 *
 * @since 2.0
 * @final	This class is not intended for extension.
 *
 * The %SplitPanel class provides the functionality of a %SplitPanel which is a control that contains two panes.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_splitpanel.htm">SplitPanel</a>.
 *
 * The following example demonstrates how to use the %SplitPanel class.
 *
 * @code
// Sample code for SplitPanel.h
#include <FUi.h>

class SplitPanelSample
	: public Tizen::Ui::Controls::Form
{
public:
	virtual result OnInitializing(void);
};
 * @endcode
 *
 * @code
// Sample code for SplitPanelSample.cpp
#include "SplitPanelSample.h"

using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

result
SplitPanelSample::OnInitializing(void)
{
	// Creates an instance of SplitPanel
	SplitPanel* pSplitPanel = new (std::nothrow) SplitPanel();
	pSplitPanel->Construct(Rectangle(0, 0, 800, 400),
			SPLIT_PANEL_DIVIDER_STYLE_MOVABLE, SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL);

	// Creates instances of Panel
	Panel* pFirstPanel = new (std::nothrow) Panel();
	pFirstPanel->Construct(Rectangle(0, 0, 400, 480));

	Panel* pSecondPanel = new (std::nothrow) Panel();
	pSecondPanel->Construct(Rectangle(0, 0, 400, 480));

	//Sets the divider position to the slit panel
	pSplitPanel->SetDividerPosition(400);

	//Sets panes to the split panel
	pSplitPanel->SetPane(pFirstPanel, SPLIT_PANEL_PANE_ORDER_FIRST);
	pSplitPanel->SetPane(pSecondPanel, SPLIT_PANEL_PANE_ORDER_SECOND);

	// Adds the split panel to the form
	AddControl(*pSplitPanel);

	return E_SUCCESS;
}
 * @endcode
 *
 */

class _OSP_EXPORT_ SplitPanel
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	SplitPanel(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~SplitPanel(void);

	/**
	 * Initializes this instance of %SplitPanel with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	rect						The location and size of the %SplitPanel control as a Rectangle instance.
	 * @param[in]	splitPanelDividerStyle		The divider style of the %SplitPanel control
	 * @param[in]	splitPanelDividerDirection	The divider direction of the %SplitPanel control @n
	 * 											The specified divider direction determines the divider is vertical or horizontal.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, SplitPanelDividerStyle splitPanelDividerStyle, SplitPanelDividerDirection splitPanelDividerDirection);

	/**
	 * Adds a ISplitPanelEventListener instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since 2.0
	 *
	 * @param[in] 	listener    			The event listener to be added
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST		The event listener already exists.
	 */
	result AddSplitPanelEventListener(ISplitPanelEventListener& listener);

	/**
	 * Removes a ISplitPanelEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @param[in] 	listener    		The event listener to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OBJ_NOT_FOUND		The event listener is not found.
	 */
	result RemoveSplitPanelEventListener(ISplitPanelEventListener& listener);

	/**
	 * Sets the pane to the %SplitPanel control.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pControl       		The control to be set.
	 * @param[in]	paneOrder       	The order of pane. SPLIT_PANEL_PANE_FIRST is displayed on the left side @n
	 *									and SPLIT_PANEL_PANE_SECOND is displayed on the right side of the %SplitPanel when its direction is SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @remarks		The %SplitPanel control must contain exactly two panes and the user can change their relative sizes.
	 */
	result SetPane(Control* pControl, SplitPanelPaneOrder paneOrder);

	/**
	 * Gets the control at the specified pane order of the %SplitPanel.
	 *
	 * @since 2.0
	 *
	 * @return		The control at the specified pane order of the %SplitPanel @n
	 *              @c null, if there is no panel.
	 * @param[in]	paneOrder			The order of pane. SPLIT_PANEL_PANE_FIRST is displayed on the left side @n
	 *									and SPLIT_PANEL_PANE_SECOND is displayed on the right side of the %SplitPanel when its direction is SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL.
 	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_INVALID_ARG  		A specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Control* GetPane(SplitPanelPaneOrder paneOrder) const;

	/**
	 * Sets the divider position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @see				GetDividerPosition()
	 * @see				SetMaximumDividerPosition(), GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition(), GetMinimumDividerPosition()
	 */
	result SetDividerPosition(int position);

	/**
	 * Gets the current divider position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			The current divider position
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetDividerPosition()
	 * @see				SetMaximumDividerPosition(), GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition(), GetMinimumDividerPosition()
	 */
	int GetDividerPosition(void) const;

	/**
	 * Sets the divider maximum position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider.
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition(), GetMinimumDividerPosition()
	 */
	result SetMaximumDividerPosition(int position);

	/**
	 * Gets the maximum divider position.
	 *
	 * @since 2.0
	 *
	 * @return			The maximum divider position of the control.
	 * @see				SetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition(), GetMinimumDividerPosition()
	 */
	int GetMaximumDividerPosition(void) const;

	/**
	 * Sets the divider minimum position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider.
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @see				GetMinimumDividerPosition()
	 * @see				SetMaximumDividerPosition(), GetMaximumDividerPosition()
	 */
	result SetMinimumDividerPosition(int position);

	/**
	 * Gets the minimum divider position.
	 *
	 * @since 2.0
	 *
	 * @return			The minimum divider position of the control.
 	 * @see				SetMinimumDividerPosition()
	 * @see				SetMaximumDividerPosition(), GetMaximumDividerPosition()
	 */
	int GetMinimumDividerPosition(void) const;

	/**
	 * Maximizes the specified pane.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		paneOrder				The order of pane.
	 * @see		 		IsPaneMaximized()
	 */
	result MaximizePane(SplitPanelPaneOrder paneOrder);

	/**
	 * Checks whether the specified pane is maximized.
	 *
	 * @since 2.0
	 * @return      	@c true if the pane is maximized, @n
	 *              	else @c false
	 */
	bool IsPaneMaximized(SplitPanelPaneOrder paneOrder) const;

	/**
	 * Restores the previous pane size if the specified pane is maximized.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @see		 		MaximizePane()
	 */
	result RestorePane(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	SplitPanel(const SplitPanel& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	SplitPanel& operator =(const SplitPanel& rhs);

	friend class _SplitPanelImpl;

}; // SplitPanel

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_SPLIT_PANEL_H_
