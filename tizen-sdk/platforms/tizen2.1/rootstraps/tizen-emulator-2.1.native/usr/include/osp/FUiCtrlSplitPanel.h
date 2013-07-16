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
class ISplitPanelEventListenerF;

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
	, public Tizen::Ui::Controls::ISplitPanelEventListener
{
public:
	SplitPanelSample(void)
	: __pSplitPanel(null)
	, __pFirstPanel(null)
	, __pSecondPanel(null){}

    bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

private:
	Tizen::Ui::Controls::SplitPanel* __pSplitPanel;
	Tizen::Ui::Controls::Panel* __pFirstPanel;
	Tizen::Ui::Controls::Panel* __pSecondPanel;
};
 * @endcode
 *
 * @code
// Sample code for SplitPanelSample.cpp
#include <FGraphics.h>

#include "SplitPanelSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
SplitPanelSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
SplitPanelSample::OnInitializing(void)
{
	// Creates an instance of SplitPanel
	__pSplitPanel = new (std::nothrow) SplitPanel();
	__pSplitPanel->Construct(Rectangle(0, 0, 800, 400),
			SPLIT_PANEL_DIVIDER_STYLE_MOVABLE, SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL);

	// Creates instances of Panel
	__pFirstPanel = new (std::nothrow) Panel();
	__pFirstPanel->Construct(Rectangle(0, 0, 400, 480));

	__pSecondPanel = new (std::nothrow) Panel();
	__pSecondPanel->Construct(Rectangle(0, 0, 400, 480));

	//Sets the divider position to the slit panel
	__pSplitPanel->SetDividerPosition(400);

	//Sets panes to the split panel
	__pSplitPanel->SetPane(__pFirstPanel, SPLIT_PANEL_PANE_ORDER_FIRST);
	__pSplitPanel->SetPane(__pSecondPanel, SPLIT_PANEL_PANE_ORDER_SECOND);

	// Adds the split panel to the form
	AddControl(__pSplitPanel);

	return E_SUCCESS;
}

 result
 SplitPanelSample::OnTerminating(void)
 {
	// Sets null panes to the split panel
	 __pSplitPanel->SetPane(null, SPLIT_PANEL_PANE_ORDER_FIRST);
	 __pSplitPanel->SetPane(null, SPLIT_PANEL_PANE_ORDER_SECOND);

	//Deallocates the control
	 __pFirstPanel->Destroy();
	 __pSecondPanel->Destroy();

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
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	SplitPanel(void);

	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
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
	 * @param[in]	rect						The location and size of the %SplitPanel control as a Tizen::Graphics::Rectangle instance.
	 * @param[in]	splitPanelDividerStyle		The divider style of the %SplitPanel control
	 * @param[in]	splitPanelDividerDirection	The divider direction of the %SplitPanel control @n
	 * 											The specified divider direction determines the divider is vertical or horizontal.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, SplitPanelDividerStyle splitPanelDividerStyle, SplitPanelDividerDirection splitPanelDividerDirection);

	/**
	 * Initializes this instance of %SplitPanel with the specified parameters.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	rect						The location and size of the %SplitPanel control as a Tizen::Graphics::FloatRectangle instance.
	 * @param[in]	splitPanelDividerStyle		The divider style of the %SplitPanel control
	 * @param[in]	splitPanelDividerDirection	The divider direction of the %SplitPanel control @n
	 * 											The specified divider direction determines the divider is vertical or horizontal.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, SplitPanelDividerStyle splitPanelDividerStyle, SplitPanelDividerDirection splitPanelDividerDirection);


	/**
	 * Adds a ISplitPanelEventListener instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since 2.0
	 *
	 * @param[in] 	listener    			The event listener to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST		The event listener already exists.
	 */
	result AddSplitPanelEventListener(ISplitPanelEventListener& listener);

	/**
	 * Adds a ISplitPanelEventListenerF instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	listener    			The event listener to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST		The event listener already exists.
	 */
	result AddSplitPanelEventListener(ISplitPanelEventListenerF& listener);

	/**
	 * Removes a ISplitPanelEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @param[in] 	listener    		The event listener to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OBJ_NOT_FOUND		The event listener is not found.
	 */
	result RemoveSplitPanelEventListener(ISplitPanelEventListener& listener);

	/**
	 * Removes a ISplitPanelEventListenerF instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	listener    		The event listener to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OBJ_NOT_FOUND		The event listener is not found.
	 */
	result RemoveSplitPanelEventListener(ISplitPanelEventListenerF& listener);

	/**
	 * Sets the pane to the %SplitPanel control.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pControl       		The control to set
	 * @param[in]	paneOrder       	The order of pane. @c SPLIT_PANEL_PANE_FIRST is displayed on the left side @n
	 *							and @c SPLIT_PANEL_PANE_SECOND is displayed on the right side of the %SplitPanel when its direction is
	 *							@c SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL.
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
	 * @param[in]	paneOrder			The order of pane. @c SPLIT_PANEL_PANE_FIRST is displayed on the left side @n
	 *								and @c SPLIT_PANEL_PANE_SECOND is displayed on the right side of the %SplitPanel when
	 *								its direction is @c SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL.
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
	 * @remarks			This Api sets the value to current orientation. The divider position must be reset when the orientation of the form is changed.
	 * @see				GetDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	result SetDividerPosition(int position);

	/**
	 * Sets the divider position of the control.
	 *
	 * @since 2.1
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @remarks			This Api sets the value to current orientation. The divider position must be reset when the orientation of the form is changed.
	 * @see				GetDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	result SetDividerPosition(float position);

	/**
	 * Gets the current divider position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			The current divider position
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	int GetDividerPosition(void) const;

	/**
	 * Gets the current divider position of the control.
	 *
	 * @since 2.1
	 *
	 * @return			The current divider position
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	float GetDividerPositionF(void) const;

	/**
	 * Sets the divider maximum position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider.
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @remarks			This Api sets the value to current orientation. The maximum divider position must be reset when the orientation of the form is changed.
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	result SetMaximumDividerPosition(int position);

	/**
	 * Sets the divider maximum position of the control.
	 *
	 * @since 2.1
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider.
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @remarks			This Api sets the value to current orientation. The maximum divider position must be reset when the orientation of the form is changed.
	 * @see				GetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	result SetMaximumDividerPosition(float position);

	/**
	 * Gets the maximum divider position.
	 *
	 * @since 2.0
	 *
	 * @return			The maximum divider position of the control.
	 * @see				SetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	int GetMaximumDividerPosition(void) const;

	/**
	 * Gets the maximum divider position.
	 *
	 * @since 2.1
	 *
	 * @return			The maximum divider position of the control.
	 * @see				SetMaximumDividerPosition()
	 * @see				SetMinimumDividerPosition()
	 * @see				GetMinimumDividerPosition()
	 */
	float GetMaximumDividerPositionF(void) const;

	/**
	 * Sets the divider minimum position of the control.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider.
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @remarks			This Api sets the value to current orientation. The minimum divider position must be reset when the orientation of the form is changed.
	 * @see				GetMinimumDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 */
	result SetMinimumDividerPosition(int position);

	/**
	 * Sets the divider minimum position of the control.
	 *
	 * @since 2.1
	 *
	 * @return			An error code
	 * @param[in]		position				The position of divider.
	 * @exception   	E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @remarks			This Api sets the value to current orientation. The minimum divider position must be reset when the orientation of the form is changed.
 	 * @see				GetMinimumDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 */
	result SetMinimumDividerPosition(float position);

	/**
	 * Gets the minimum divider position.
	 *
	 * @since 2.0
	 *
	 * @return			The minimum divider position of the control.
 	 * @see				SetMinimumDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 */
	int GetMinimumDividerPosition(void) const;

	/**
	 * Gets the minimum divider position.
	 *
	 * @since 2.1
	 *
	 * @return			The minimum divider position of the control.
	 * @see				SetMinimumDividerPosition()
	 * @see				SetMaximumDividerPosition()
	 * @see				GetMaximumDividerPosition()
	 */
	float GetMinimumDividerPositionF(void) const;

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
