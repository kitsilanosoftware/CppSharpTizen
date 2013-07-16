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
 * @file		FUiCtrlIFormBackEventListener.h
 * @brief		This is the header file for the %IFormBackEventListener interface.
 *
 * This header file contains the declarations of the %IFormBackEventListener interface.
 */
#ifndef _FUI_CTRL_IFORM_BACK_EVENT_LISTENER_H_
#define _FUI_CTRL_IFORM_BACK_EVENT_LISTENER_H_

// includes
#include <FBaseRtIEventListener.h>

// namespace declaration
namespace Tizen { namespace Ui { namespace Controls
{

class Form;

/**
 * @interface	IFormBackEventListener
 * @brief		This interface implements the listener for Form-related events.
 *
 * @since		2.0
 *
 * The %IFormBackEventListener interface is the listener interface for receiving Form-related back button events.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_form.htm">Form</a>.
 */
class IFormBackEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IFormBackEventListener(void) {}

// Operation
public:
	/**
	 * Called when the current Form control needs to be closed to revert back to the previous %Form control.
	 *
	 * @since	2.0
	 *
	 * @param[in]	source		The source of the event
	 * @remarks		This event is fired when the user clicks on the software 'back' button on the Footer control, or the hardware back button on the
	 *				device.
	 */
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source) = 0;

// Reserves
protected:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFormBackEventListener_Reserved1(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFormBackEventListener_Reserved2(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFormBackEventListener_Reserved3(void) { }
}; // IFormBackEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IFORM_BACK_EVENT_LISTENER_H_
