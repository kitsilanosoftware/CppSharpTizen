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
 * @file	FUiAnimIVisualElementAnimationStatusEventListener.h
 * @brief	This is the header file for the %IVisualElementAnimationStatusEventListener interface.
 *
 * This header file contains the declarations of the %IVisualElementAnimationStatusEventListener interface.
 */

#ifndef _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_STATUS_EVENT_LISTENER_H_
#define _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_STATUS_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base {
class String;
}} // Tizen::Base

namespace Tizen { namespace Ui { namespace Animations
{

class VisualElement;
class VisualElementAnimation;

/**
 * @interface	IVisualElementAnimationStatusEventListener
 * @brief		This interface implements the listener for the VisualElementAnimation status events defined in the Tizen::Ui::Animations namespace.
 *
 * @since		2.0
 *
 * The %IVisualElementAnimationStatusEventListener interface is the listener interface for receiving animation status events.
 * The class that processes an animation status event implements this interface, and the instance created with that class is
 * registered with an animation, using the VisualElementAnimation::SetVisualElementAnimationStatusEventListener() method or
 * the AnimationTransaction::SetVisualElementAnimationStatusEventListener() method.
 * When the animation status is changing, a method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animation_event_handling.htm">Event Handling</a>.
 *
 */
class _OSP_EXPORT_ IVisualElementAnimationStatusEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~IVisualElementAnimationStatusEventListener(void);


	/**
	 * Called when the animation is started.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animation		The animation that is started
	 * @param[in]	keyName			The key name of the animation
	 * @param[in]	target			An instance of VisualElement to which the animation is applied
	 * @remarks		If the key name of the animation is not set, @c keyName is empty string.
	 */
	virtual void OnVisualElementAnimationStarted(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target) = 0;


	/**
	 * Called when the animation is repeated.
	 *
	 * @since       2.0
	 *
	 * @param[in]	animation		The animation that is repeated
	 * @param[in]	keyName			The key name of the animation
	 * @param[in]	target			An instance of VisualElement to which the animation is applied
	 * @param[in]	currentRepeatCount	The current repeat count
	 * @remarks		If the key name of the animation is not set, @c keyName is empty string.
	 */
	virtual void OnVisualElementAnimationRepeated(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, long currentRepeatCount) = 0;


	/**
	 * Called when the animation is finished.
	 *
	 * @since       2.0
	 *
	 * @param[in]	animation		The animation that is finished
	 * @param[in]	keyName			The key name of the animation
	 * @param[in]	target			An instance of VisualElement to which the animation is applied
	 * @param[in]	completedNormally 	@c true if the animation is completed normally, @n
	 * 									else @c false
	 * @remarks		If the key name of the animation is not set, @c keyName is empty string.
	 */
	virtual void OnVisualElementAnimationFinished(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, bool completedNormally) = 0;


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
	virtual void IVisualElementAnimationStatusEventListener_Reserved1(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationStatusEventListener_Reserved2(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationStatusEventListener_Reserved3(void) {}
};		// IVisualElementAnimationStatusEventListener


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_STATUS_EVENT_LISTENER_H_
