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
 * @file		FUiIScrollPanelEventListener.h
 * @brief		This is the header file for the %IScrollPanelEventListener interface.
 *
 * This header file contains the declarations of the %IScrollPanelEventListener interface. @n
 * If a change event is generated, a method of this interface is called. @n
 * Applications that do jobs related to change events call the methods of this interface.
 *
 */
#ifndef _FUI_ISCROLL_PANEL_EVENT_LISTENER_H_
#define _FUI_ISCROLL_PANEL_EVENT_LISTENER_H_

// Includes
#include <FBaseObject.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{
class Control;
}} // Tizen::Ui

namespace Tizen {namespace Ui
{

/**
 * @interface	IScrollPanelEventListener
 * @brief		This interface implements a listener for %ScrollPanel events.
 *
 * @since		2.0
 *
 * The %IScrollPanelEventListener interface is the listener interface for receiving change events related to controls (especially an overlay keypad) within the
 * ScrollPanel. The class that processes a change event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddScrollPanelEventListener() method. When the change event occurs, a method
 * of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_panels.htm">Panels</a> and <a href="../org.tizen.native.appprogramming/html/tutorials/ui_tutorial/using_overlay_keypad_with_scroll.htm">Using EditArea or EditField Overlay Keypad with ScrollPanel</a>.

 */
class _OSP_EXPORT_ IScrollPanelEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since			2.0
	 */
	virtual ~IScrollPanelEventListener(void) {}

	/**
	 * Called when an overlay keypad is created on the ScrollPanel control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source				The source of the event
	 */
	virtual void OnOverlayControlCreated(const Tizen::Ui::Control& source) = 0;

	/**
	 * Called when an overlay keypad is opened on the ScrollPanel control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source				The source of the event
	 */
	virtual void OnOverlayControlOpened(const Tizen::Ui::Control& source) = 0;

	/**
	 * Called when an overlay keypad is closed on the ScrollPanel control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source				The source of the event
	 */
	virtual void OnOverlayControlClosed(const Tizen::Ui::Control& source) = 0;

	/**
	 * Called when a control is selected on the ScrollPanel control .
	 *
	 * @since		2.0
	 *
	 * @param[in]   source				The source of the event
	 */
	virtual void OnOtherControlSelected(const Tizen::Ui::Control& source) = 0;

	// Reserves
protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IScrollPanelEventListener_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IScrollPanelEventListener_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IScrollPanelEventListener_Reserved3(void) { }

}; // IScrollPanelEventListener


}} // Tizen::Ui

#endif // _FUI_ISCROLL_PANEL_EVENT_LISTENER_H_
