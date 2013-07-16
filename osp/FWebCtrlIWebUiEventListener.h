//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FWebCtrlIWebUiEventListener.h
 * @brief		This is the header file for the %IWebUiEventListener interface.
 *
 * This header file contains the declarations of the %IWebUiEventListener interface.
 */
#ifndef _FWEB_CTRL_IWEB_UI_EVENT_LISTENER_H_
#define _FWEB_CTRL_IWEB_UI_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FWebCtrlWeb.h>
#include <FGrpPoint.h>

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @interface	IWebUiEventListener
 * @brief		This interface is used for receiving user interface (UI) related events caused by the layout changes of a control.
 *
 * @since		2.0
 *
 * The %IWebUiEventListener interface is used for receiving user interface (UI) related events caused by the layout changes of a control.
 * The browser engine requests a screen update through this interface when the layout of a page is changed.
 */
class _OSP_EXPORT_ IWebUiEventListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IWebUiEventListener(void) {}

	/**
	 * Called when the layout of a page is updated. @n
	 * The application must call Tizen::Ui::Control::Show() if the screen needs to be updated.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 */
	virtual void OnWebPageShowRequested(Tizen::Web::Controls::Web& source) = 0;


	/**
	 * Called when a request for creating a new window is received. @n
	 * The returned %Web control instance must be constructed by using a child window's Construct() method.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the new WebWindow instance
	 */
	virtual Tizen::Web::Controls::Web* OnWebWindowCreateRequested(void) = 0;


	/**
	 * Called when a request for closing the window is received. @n
	 * This event is called from the parent window's listener that invoked the child window. @n
	 * The application must free the resource allocated for the Web Control.
	 *
	 * @since		 2.0
	 *
	 * @param[in]	source		The source of the closing event
	 */
	virtual void OnWebWindowCloseRequested(Tizen::Web::Controls::Web& source) = 0;

	/**
	 * Called when the selected block of a page is updated.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @param[in]	startPoint		The starting point of the selected block
	 * @param[in]	endPoint		The ending point of the selected block
	 */
	virtual void OnWebPageBlockSelected(Tizen::Web::Controls::Web& source, Tizen::Graphics::Point& startPoint, Tizen::Graphics::Point& endPoint) = 0;

	/**
	 * Called just after the touch move event to determine whether the preventDefault() method is triggered or not. @n
	 * The application that wants to support W3C preventDefault() feature is recommended to use this callback and delay to handle the touch move event until this callback is received.
	 *
	 * @since		2.1
	 *
	 * @param[in]	source		The source of the event
	 * @param[in]	trigger		Set to @c true if the preventDefault() method is triggered, @n
	 *						else @c false
	 * @remarks				This callback is always called just after the touch move event and returns @c true when preventDefault() is triggered on the touch start or touch move event.
	 */
	virtual void OnWebPreventDefaultTriggered(Tizen::Web::Controls::Web& source, bool trigger) {};

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebUiEventListener_Reserved1(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebUiEventListener_Reserved2(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebUiEventListener_Reserved3(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebUiEventListener_Reserved4(void) {};
}; // IWebUiEventListener

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_IWEB_UI_EVENT_LISTENER_H_
