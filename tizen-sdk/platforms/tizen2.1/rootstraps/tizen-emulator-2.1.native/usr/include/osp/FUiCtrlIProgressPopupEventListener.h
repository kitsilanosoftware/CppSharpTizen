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
 * @file		FUiCtrlIProgressPopupEventListener.h
 * @brief	This is the header file for the %IProgressPopupEventListener interface.
 *
 * This header file contains the declarations of the %IProgressPopupEventListener interface. @n
 * If a ProgressPopup event is generated, a method of this interface is called. @n
 * So, for tasks related to the ProgressPopup event, use the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_IPROGRESS_POPUP_EVENT_LISTENER_H_
#define _FUI_CTRL_IPROGRESS_POPUP_EVENT_LISTENER_H_

#include "FBaseRtIEventListener.h"


namespace Tizen { namespace Ui
{
class Control;
}} // Tizen::Ui


namespace Tizen { namespace Ui
{
/**
 * @interface               IProgressPopupEventListener
 * @brief                    This interface implements the listener for ProgressPopup event.
 * @since 2.0
 *
 * The %IProgressPopupEventListener interface is the listener interface for receiving an event for closing the ProgressPopup.
 * The class that processes a ProgressPopup event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's
 * AddProgressPopupEventListener() method. When the ProgressPopup event occurs, the OnProgressPopupCanceled() method of that instance is invoked.
 *
 * For more information on the class features,
 * see in individual control topics under <a href="../org.tizen.native.appprogramming/html/guide/ui/controls.htm">UI Controls</a>.
 */
class _OSP_EXPORT_ IProgressPopupEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IProgressPopupEventListener(void) {}

	/**
	 * Called when a ProgressPopup event occurs.
	 *
	 * @since 2.0
	 */
	virtual void OnProgressPopupCanceled(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following methods are reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IProgressPopupEventListener_Reserved1(void) {}
	virtual void IProgressPopupEventListener_Reserved2(void) {}
	virtual void IProgressPopupEventListener_Reserved3(void) {}
}; // IProgressPopupEventListener

}} // Tizen::Ui

#endif // _FUI_CTRL_IPROGRESS_POPUP_EVENT_LISTENER_H_
