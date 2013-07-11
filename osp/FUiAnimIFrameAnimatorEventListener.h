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
 * @file	FUiAnimIFrameAnimatorEventListener.h
 * @brief	This is the header file for the %IFrameAnimatorEventListener interface.
 *
 * This header file contains the declarations of the %IFrameAnimatorEventListener interface.
 */

#ifndef _FUI_CTRL_IFRAME_ANIMATOR_EVENT_LISTENER_H_
#define _FUI_CTRL_IFRAME_ANIMATOR_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FBaseRtIEventListener.h>
#include <FUiAnimTypes.h>
#include <FUiAnimAnimationBase.h>


namespace Tizen { namespace Ui { namespace Controls
{
class Form;
} } }
namespace Tizen { namespace Ui { namespace Controls
{
class Frame;
} } }
namespace Tizen { namespace Ui { namespace Animations
{
class FrameAnimator;
} } }

namespace Tizen { namespace Ui { namespace Animations
{



/**
 * @interface	IFrameAnimatorEventListener
 * @brief		This interface implements the listener for animation events.
 *
 * @since		2.0
 *
 * The %IFrameAnimatorEventListener interface is the listener interface for receiving frame animator events.
 * The class that processes a frame animator event implements this interface, and the instance created with that class is
 * registered with a Frame, using the FrameAnimator::AddFrameAnimatorEventListener() method. When the frame animator event occurs, a
 * method of that instance is invoked.
 */
class _OSP_EXPORT_ IFrameAnimatorEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IFrameAnimatorEventListener(void) {}


	/**
	 * Called when the animation of a form transition starts.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   frame			The frame @n
	 *                              The frame that starts the animation of a form transition.
	 * @param[in]   form1			The form @n
	 *                              The animation starts on this form.
	 * @param[in]   form2			The form @n
	 *                              The animation starts on this form.
	 */
	virtual void OnFormTransitionAnimationStarted(Tizen::Ui::Animations::FrameAnimator& source, Tizen::Ui::Controls::Frame& frame, Tizen::Ui::Controls::Form& form1, Tizen::Ui::Controls::Form& form2) = 0;


	/**
	 * Called when the animation of a form transition stops.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   frame			The frame @n
	 *                              The frame that stops the animation of a form transition.
	 * @param[in]   form1			The form @n
	 *                              The animation stops on this form.
	 * @param[in]   form2			The form @n
	 *                              The animation stops on this form.
	 */
	virtual void OnFormTransitionAnimationStopped(Tizen::Ui::Animations::FrameAnimator& source, Tizen::Ui::Controls::Frame& frame, Tizen::Ui::Controls::Form& form1, Tizen::Ui::Controls::Form& form2) = 0;


	/**
	 * Called when the animation of a form transition finishes.
	 *
	 * @since	2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   frame			The frame @n
	 *                              The frame that finishes the animation of a form transition.
	 * @param[in]   form1			The form @n
	 *                              The animation finishes on this form.
	 * @param[in]   form2			The form @n
	 *                              The animation finishes on this form.
	 */
	virtual void OnFormTransitionAnimationFinished(Tizen::Ui::Animations::FrameAnimator& source, Tizen::Ui::Controls::Frame& frame, Tizen::Ui::Controls::Form& form1, Tizen::Ui::Controls::Form& form2) = 0;


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
	virtual void IFrameAnimatorEventListener_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IFrameAnimatorEventListener_Reserved2(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IFrameAnimatorEventListener_Reserved3(void) { }
};		// IFrameAnimatorEventListener


}}}		// Tizen::Ui::Animations

#endif // _FUI_ANIM_IFRAME_ANIMATOR_EVENT_LISTENER_H_
