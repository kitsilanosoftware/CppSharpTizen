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
 * @file		FUiIActionEventListener.h
 * @brief		This is the header file for the %IActionEventListener interface.
 *
 * This header file contains the declarations of the IActionEventListener interface. @n
 * If an action event is generated, a method of this interface is called. @n
 * So, for tasks related to the action event, use the methods of this interface.
 *
 */
#ifndef _FUI_IACTION_EVENT_LISTENER_H_
#define _FUI_IACTION_EVENT_LISTENER_H_

#include "FBaseRtIEventListener.h"

namespace Tizen { namespace Ui
{
class Control;
}} // Tizen::Ui

namespace Tizen {namespace Ui
{
/**
 * @interface	IActionEventListener
 * @brief		This interface implements the listener for action event.
 *
 * @since		2.0
 *
 * The %IActionEventListener interface is the listener interface for receiving action events, for example, from Buttons.
 * The class that processes an action event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's
 * AddActionEventListener() method. When the action event occurs, the OnActionPerformed() method of that instance is invoked.
 * @n
 * For more information on the class features, see in individual control topics under <a href="../org.tizen.native.appprogramming/html/guide/ui/controls.htm">UI Controls</a>.
 */
class _OSP_EXPORT_ IActionEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IActionEventListener(void) {}

	/**
	 * Called when an action event occurs.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]   actionId	The information about the action event
	 */
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId) = 0;

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
	virtual void IActionEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IActionEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IActionEventListener_Reserved3(void) {}
}; // IActionEventListener

}} // Tizen::Ui

#endif // _FUI_IACTION_EVENT_LISTENER_H_
