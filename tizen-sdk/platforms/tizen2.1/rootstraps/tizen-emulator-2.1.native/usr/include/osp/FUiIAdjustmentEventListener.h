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
 * @file		FUiIAdjustmentEventListener.h
 * @brief		This is the header file for the %IAdjustmentEventListener interface.
 *
 * This header file contains the declarations of the %IAdjustmentEventListener interface. @n
 * If a change event is generated, a method of this interface is called. @n
 * So, for tasks related to change events, use the methods of this interface.
 *
 */
#ifndef _FUI_IADJUSTMENT_EVENT_LISTENER_H_
#define _FUI_IADJUSTMENT_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>

namespace Tizen {namespace Ui
{
class Control;

/**
 * @interface	IAdjustmentEventListener
 * @brief		This interface implements the listener for adjustment events.
 *
 * @since		2.0
 *
 * The %IAdjustmentEventListener interface is the listener interface for receiving adjustment events, which
 * are fired when the knob of a Slider moves. The class that processes an adjustment event implements this interface, and the
 * instance created with that class is registered with a UI control, using the control's AddAdjustmentEventListener() method.
 * When the adjustment event occurs, the OnAdjustmentValueChanged() method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_slider.htm">Slider</a>.

 */
class IAdjustmentEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IAdjustmentEventListener(void) {}

	/**
	 * Called when a change event occurs.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]	adjustment		The adjustment value
	 */
	virtual void OnAdjustmentValueChanged(const Tizen::Ui::Control& source, int adjustment) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// without prior notice.
	//
	// @since      2.0
	//
	virtual void IAdjustmentEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// without prior notice.
	//
	// @since      2.0
	//
	virtual void IAdjustmentEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// without prior notice.
	//
	// @since      2.0
	//
	virtual void IAdjustmentEventListener_Reserved3(void) {}

};	// IAdjustmentEventListener

}}	// Tizen::Ui

#endif // _FUI_IADJUSTMENT_EVENT_LISTENER_H_
