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
 * @file		FUiCtrlISplitPanelEventListener.h
 * @brief		This is the header file for the %ISplitPanelEventListener interface.
 *
 * This header file contains the declarations of the %ISplitPanelEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, if the applications perform tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_CTRL_ISPLIT_PANEL_EVENT_LISTENER_H_
#define _FUI_CTRL_ISPLIT_PANEL_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>
#include <FUiCtrlSplitPanel.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @interface	ISplitPanelEventListener
 * @brief		This interface implements the listener for all splitpanel events.
 *
 * @since 2.0
 *
 * The %ISplitPanelEventListener interface is the listener interface for receiving splitpanel events.
 * The class that processes a splitpanel event implements this interface, and the instance created with that class is registered with
 * a UI control, using the control's AddSplitPanelEventListener() method. When the splitpanel event occurs, a method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_splitpanel.htm">SplitPanel</a>.
 */
class _OSP_EXPORT_ ISplitPanelEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called
	 *
	 * @since 2.0
	 */
	virtual ~ISplitPanelEventListener(void) {}

	/**
	 * Called when the divider moves.
	 *
	 * @since 2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]   position	The position of the divider
	 */
	virtual void OnDividerPositionChanged(Tizen::Ui::Controls::SplitPanel& source, int position) = 0;

	/**
	 * Called when the divider is double pressed.
	 *
	 * @since 2.0
	 *
	 * @param[in] source		The source of the event
	 * @remark  				This method is invoked when an divider is double pressed.
	 */
	virtual void OnDividerDoublePressed(Tizen::Ui::Controls::SplitPanel& source) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISplitPanelEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISplitPanelEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISplitPanelEventListener_Reserved3(void) {}

};	// ISplitPanelEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ISPLIT_PANEL_EVENT_LISTENER_H_
