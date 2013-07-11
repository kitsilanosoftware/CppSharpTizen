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
 * @file		FUiIWindowEventListener.h
 * @brief		This is the header file for the %IWindowEventListener interface.
 *
 * This header file contains the declarations of the %IWindowEventListener interface. @n
 * If a window event is generated, a method of this interface is called. @n
 * So, if an application does some jobs related to the window event, use the methods of this interface.
 *
 */

#ifndef _FUI_IWINDOW_EVENT_LISTENER_H_
#define _FUI_IWINDOW_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseTypes.h>

namespace Tizen {namespace Ui
{

class Window;

/**
 * @interface	IWindowEventListener
 * @brief		This interface implements the listener for the window event.
 *
 * @since			2.0
 *
 * The %IWindowEventListener interface for receiving window events. The class that processes a window event
 * implements this interface, and the instance created with that class is registered with a Window using Window's
 * AddWindowEventListener() method. When the window event occurs, the OnWindowActivated(), or OnWindowDeactivated() method of that instance is invoked.
 */
class _OSP_EXPORT_ IWindowEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since				2.0
	 *
	 */
	virtual ~IWindowEventListener(void) {}

	/**
	 * Called when a window becomes the topmost window.
	 *
	 * @since				2.0
	 *
	 * @param[in]   source		The source of the event
	 *
	 */
	virtual void OnWindowActivated(const Tizen::Ui::Window& source) = 0;

	/**
	 * Called when the window is no longer the topmost window.
	 *
	 * @since				2.0
	 *
	 * @param[in]   source		The source of the event
	 *
	 */
	virtual void OnWindowDeactivated(const Tizen::Ui::Window& source) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IWindowEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IWindowEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IWindowEventListener_Reserved3(void) {}
};

}}; // Tizen::Ui

#endif // _FUI_IWINDOW_EVENT_LISTENER_H_
