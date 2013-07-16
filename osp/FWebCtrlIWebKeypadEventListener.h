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
 * @file		FWebCtrlIWebKeypadEventListener.h
 * @brief		This is the header file for the %IWebKeypadEventListener interface.
 *
 * This header file contains the declarations of the %IWebKeypadEventListener interface.
 */
#ifndef _FWEB_CTRL_IWEB_KEYPAD_EVENT_LISTENER_H_
#define _FWEB_CTRL_IWEB_KEYPAD_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Web { namespace Controls
{
class Web;
}}} // Tizen::Web::Controls

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @interface	IWebKeypadEventListener
 * @brief		This interface provides a listener for keypad events invoked by the <textarea> or <input> tag, which has "text" or "password" value as its attribute.
 *
 * @since		2.0
 *
 * The %IWebKeypadEventListener interface provides a listener for keypad events invoked by the <textarea> or <input> tag, which has "text" or "password" value as its attribute.
 * It also enables the implementer class to receive the overlay keypad related events.
 */
class _OSP_EXPORT_ IWebKeypadEventListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~IWebKeypadEventListener(void) {}

	/**
	 * Called when the keypad is about to be shown on the screen.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The source of the event
	 * @remarks		When the overlay keypad appears on the screen, the current Form's
	 *			area is adjusted to account for the space that is taken up by the overlay keypad.
	 * @see	Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadWillOpen(Tizen::Web::Controls::Web& source) = 0;

	/**
	 * Called when the keypad is shown on the screen.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The source of the event
	 * @remarks		When the overlay keypad appears on the screen, the current Form's
	 *			area is adjusted to account for the space that is taken up by the overlay keypad.
	 * @see	Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadOpened(Tizen::Web::Controls::Web& source) = 0;

	/**
	 * Called when the keypad is hidden from the screen.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The source of the event
	 * @see	Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadClosed(Tizen::Web::Controls::Web& source) = 0;

	/**
	 * Called when the keypad bounds are changed, for instance when the predictive text window which is located in the upper side of the keypad is shown.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The source of the event
	 * @see	Tizen::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadBoundsChanged(Tizen::Web::Controls::Web& source) {};

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebKeypadEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebKeypadEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since		2.0
	//
	virtual void IWebKeypadEventListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebKeypadEventListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IWebKeypadEventListener_Reserved5(void) {}
}; // IWebKeypadEventListener

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_IWEB_KEYPAD_EVENT_LISTENER_H_
