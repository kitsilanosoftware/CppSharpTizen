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
 * @file	FUiCtrlIFrameEventListener.h
 * @brief	This is the header file for the %IFrameEventListener interface.
 *
 * This header file contains the declarations of the %IFrameEventListener interface. @n
 * If a frame lifecycle event is generated, a method of this class is called. @n
 * So, if an application needs to perform tasks related to the frame event, provide the implementation of the methods declared in this interface.
 */

#ifndef _FUI_CTRL_IFRAME_EVENT_LISTENER_H_
#define _FUI_CTRL_IFRAME_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{

class Frame;

/**
 * @interface	IFrameEventListener
 * @brief		This interface implements the listener for the frame lifecycle event.
 *
 * @since		2.0
 *
 * The %IFrameEventListener interface is the listener interface for receiving %Frame lifecycle events.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_frame.htm">Frame</a>.
 *
 */
class _OSP_EXPORT_ IFrameEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual ~IFrameEventListener(void) {}

// Operations
public:
	/**
	 * Called when a Frame instance is about to be destroyed. @n
	 * This method is called just before the system destroys the %Frame instance of an application during the application termination sequence.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source		The source of the event
	 * @remarks     This method releases any resources that need to be deallocated before the destruction of the Frame instance.
	 */
	virtual void OnFrameTerminating(const Tizen::Ui::Controls::Frame& source) = 0;

	/**
	 * Called when a Frame instance is about to be activated. @n
	 * This method is called just after the system activates the %Frame instance of an application.
	 *
	 * @since 2.0
	 *
	 * @param[in] 	source		The source of the event
	  */
	virtual void OnFrameActivated(const Tizen::Ui::Controls::Frame& source) { }

	/**
	 * Called when a Frame instance is about to be deactivated. @n
	 * This method is called just after the system deactivates the %Frame instance of an application.
	 *
	 * @since 2.0
	 *
	 * @param[in] 	source		The source of the event
	 */
	virtual void OnFrameDeactivated(const Tizen::Ui::Controls::Frame& source) { }


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
	virtual void IFrameEventListener_Reserved1(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFrameEventListener_Reserved2(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFrameEventListener_Reserved3(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFrameEventListener_Reserved4(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IFrameEventListener_Reserved5(void) { }

}; // IFrameEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IFRAME_EVENT_LISTENER_H_
