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
 * @file	FUiAnimIControlAnimatorDetailedEventListener.h
 * @brief	This is the header file for the %IControlAnimatorDetailedEventListener interface.
 *
 * This header file contains the declarations of the %IControlAnimatorDetailedEventListener interface.
 */

#ifndef _FUI_ANIM_ICONTROL_ANIMATOR_DETAILED_EVENT_LISTENER_H_
#define _FUI_ANIM_ICONTROL_ANIMATOR_DETAILED_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FBaseRtIEventListener.h>

#include <FUiAnimTypes.h>
#include <FUiAnimAnimationBase.h>

namespace Tizen { namespace Ui
{
class Control;
} }
namespace Tizen { namespace Ui { namespace Animations
{
class ControlAnimator;
} } }
namespace Tizen { namespace Ui { namespace Animations
{



/**
 * @interface	IControlAnimatorDetailedEventListener
 * @brief		This interface implements a detailed listener for animation events.
 *
 * @since		2.0
 *
 * The %IControlAnimatorDetailedEventListener interface is the listener interface for receiving detailed control animator events.
 * The class that processes a detailed control animator event implements this interface, and the instance created with that class
 * is registered with a UI control, using the ControlAnimator::AddControlAnimatorDetailedEventListener() method. When the detailed
 * control animator event occurs, a method of that instance is invoked.
 */
class _OSP_EXPORT_ IControlAnimatorDetailedEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IControlAnimatorDetailedEventListener(void) {}


	/**
	 * Called when an animation starts.
	 *
	 * @since	2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control @n
	 *                              The animation starts on this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations,
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the
	 *								application), @c pAnimation is @c null.
	 */
	virtual void OnControlAnimationStarted(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control, Tizen::Ui::Animations::ControlAnimatorTriggerType animTrigger, Tizen::Ui::Animations::AnimationTargetType animTarget, Tizen::Ui::Animations::AnimationBase* pAnimation) = 0;


	/**
	 * Called when an animation is repeated. @n
	 * This event occurs only when a user calls StartUserAnimation().
	 *
	 * @since	2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control @n
	 *                              The animation is repeated on this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations,
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the
	 *								application), @c pAnimation is @c null.
	 * @param[in]   repeatCount		The current repeat count of the animation
	 */
	virtual void OnControlAnimationRepeated(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control, Tizen::Ui::Animations::ControlAnimatorTriggerType animTrigger, Tizen::Ui::Animations::AnimationTargetType animTarget, Tizen::Ui::Animations::AnimationBase* pAnimation, int repeatCount) = 0;


	/**
	 * Called when an animation finishes.
	 *
	 * @since	2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control @n
	 *                              The animation with the specified trigger type has finished for this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations,
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the
	 *								application), @c pAnimation is @c null.
	 */
	virtual void OnControlAnimationFinished(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control, Tizen::Ui::Animations::ControlAnimatorTriggerType animTrigger, Tizen::Ui::Animations::AnimationTargetType animTarget, Tizen::Ui::Animations::AnimationBase* pAnimation) = 0;


	/**
	 * Called when an animation stops.
	 *
	 * @since	2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control @n
	 *                              The animation with the specified trigger type has stopped for this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations,
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the
	 *								application), @c pAnimation is @c null.
	 */
	virtual void OnControlAnimationStopped(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control, Tizen::Ui::Animations::ControlAnimatorTriggerType animTrigger, Tizen::Ui::Animations::AnimationTargetType animTarget, Tizen::Ui::Animations::AnimationBase* pAnimation) = 0;


protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IControlAnimatorDetailedEventListener_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IControlAnimatorDetailedEventListener_Reserved2(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IControlAnimatorDetailedEventListener_Reserved3(void) { }
};		// IControlAnimatorDetailedEventListener


}}}		// Tizen::Ui::Animations

#endif // _FUI_ANIM_ICONTROL_ANIMATOR_DETAILED_EVENT_LISTENER_H_
