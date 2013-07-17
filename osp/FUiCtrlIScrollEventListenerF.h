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
 * @file		FUiCtrlIScrollEventListenerF.h
 * @brief	This is the header file for the %IScrollEventListenerF interface.
 *
 * This header file contains the declarations of the %IScrollEventListenerF interface. @n
 * If a change event is generated, a method of this interface is called. @n
 * The applications that perform tasks related to the change events, call the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_ISCROLL_EVENT_LISTENER_F_H_
#define _FUI_CTRL_ISCROLL_EVENT_LISTENER_F_H_

#include <FBaseRtIEventListener.h>
#include <FUiCtrlScrollEventTypes.h>

namespace Tizen { namespace Ui
{
class Control;
}}	// Tizen::Ui

namespace Tizen {namespace Ui { namespace Controls
{

/**
 * @interface	IScrollEventListenerF
 * @brief	This interface implements a listener for scroll events.
 *
 * @since	2.1
 *
 * The %IScrollEventListenerF interface is the listener interface for receiving scroll events.
 * The class that processes a scroll event implements this interface, and the instance created with that class is registered with
 * a UI control, using the control(GroupedListView, GroupedTableView, IconListView,  ListView, ScrollPanel, SectionTableView, TableView)'s AddScrollEventListener() method.
 * When the scroll event occurs, the OnScrollEndReached() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_panels.htm">Panels</a>
 * and <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IScrollEventListenerF
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.1
	 *
	 */
	virtual ~IScrollEventListenerF(void) {}

	/**
	 * Called when the scroll reaches the top, bottom, left, or right end.
	 *
	 * @since           2.1
	 *
	 * @param[in]		source        The source of the event
	 * @param[in]		type          The type of scroll end event
	 */
	virtual void OnScrollEndReached(Tizen::Ui::Control& source, Tizen::Ui::Controls::ScrollEndEvent type) = 0;

	/**
	 * Called continuously when the control is being scrolled.
	 *
	 * @since 2.1
	 *
	 *@param[in]               source        The control being scrolled
	 *@param[in]               scrollPosition     The scrolled position
	 */
	virtual void OnScrollPositionChanged(Tizen::Ui::Control& source, float scrollPosition) = 0;

	/**
	 * Called when the control's scroll movement has come to a stop.
	 *
	 * @since 2.1
	 *
	 * @param[in]               source        The control being scrolled
	 */
	virtual void OnScrollStopped(Tizen::Ui::Control& source) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ScrollEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ScrollEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ScrollEventListener_Reserved3(void) {}

}; // IScrollEventListenerF

}}}	// Tizen::Ui::Controls

#endif // _FUI_CTRL_ISCROLL_EVENT_LISTENER_F_H_
