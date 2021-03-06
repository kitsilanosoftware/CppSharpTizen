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
 * @file		FUiIAnimationEventListener.h
 * @brief		This is the header file for the %IAnimationEventListener interface.
 *
 * This header file contains the declarations of the %IAnimationEventListener interface.
 * If a change event is generated, a method of this interface is called.
 * So, for tasks related to change events, use the methods of this interface.
 *
 */
#ifndef _FUI_IANIMATION_EVENT_LISTENER_H_
#define _FUI_IANIMATION_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>

namespace Tizen { namespace Ui
{

class Control;

/**
 * @interface	IAnimationEventListener
 * @brief		This interface implements the listener for animation events.
 *
 * @since		2.0
 *
 * The %IAnimationEventListener interface is the listener interface for receiving animation events.
 * The class that processes an animation event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's @ref Tizen::Ui::Controls::Animation::AddAnimationEventListener() method. When the animation event occurs, the
 * @ref OnAnimationStopped() method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_animation.htm">Animation</a>.
 *
 *
 */
class IAnimationEventListener
	: public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~IAnimationEventListener(void) {}

	/**
	 * Called when the animation is stopped.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 */
	virtual void OnAnimationStopped(const Tizen::Ui::Control& source) = 0;

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
	virtual void IAnimationEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// without prior notice.
	//
	// @since      2.0
	//
	virtual void IAnimationEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// without prior notice.
	//
	// @since      2.0
	//
	virtual void IAnimationEventListener_Reserved3(void) {}

}; // IAnimationEventListener

}} // Tizen::Ui

#endif // _FUI_IANIMATION_EVENT_LISTENER_H_
