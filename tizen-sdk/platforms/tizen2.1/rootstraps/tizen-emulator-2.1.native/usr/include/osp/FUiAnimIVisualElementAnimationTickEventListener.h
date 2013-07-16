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
 * @file	FUiAnimIVisualElementAnimationTickEventListener.h
 * @brief	This is the header file for the %IVisualElementAnimationTickEventListener interface.
 *
 * This header file contains the declarations of the %IVisualElementAnimationTickEventListener interface.
 */

#ifndef _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_TICK_EVENT_LISTENER_H_
#define _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_TICK_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

#include <FUiAnimVisualElement.h>
#include <FUiAnimVisualElementAnimation.h>


namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @interface	IVisualElementAnimationTickEventListener
 * @brief		This interface implements the listener for the VisualElementAnimation tick events defined in the Tizen::Ui::Animations namespace.
 *
 * @since		2.0
 *
 * The %IVisualElementAnimationTickEventListener interface is the listener interface for receiving animation tick events.
 * The class that processes an animation tick event implements this interface, and the instance created with that class is registered with an animation,
 * using the VisualElementValueAnimation::SetVisualElementAnimationTickEventListener() method.
 * When the animation tick event occurs, a method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animation_event_handling.htm">Event Handling</a>.
 *
 */
class _OSP_EXPORT_ IVisualElementAnimationTickEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~IVisualElementAnimationTickEventListener(void);


	/**
	 * Called when a tick event has occurred. @n
	 * The %OnTickOccurred() callback method will be called with every tick of the animation, using the current value by the UI framework.
	 *
	 * @since       2.0
	 *
	 * @param[in]	animation	The animation that is running
	 * @param[in]	keyName 	The key name of the animation
	 * @param[in]	target     	The VisualElement object to which the animation is applied
	 * @param[in]	currentValue	The current value
	 */
	virtual void OnTickOccurred(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, const Tizen::Ui::Variant& currentValue) = 0;


protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationTickEventListener_Reserved1(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationTickEventListener_Reserved2(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationTickEventListener_Reserved3(void) {}
};		// IVisualElementAnimationTickEventListener


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_TICK_EVENT_LISTENER_H_
