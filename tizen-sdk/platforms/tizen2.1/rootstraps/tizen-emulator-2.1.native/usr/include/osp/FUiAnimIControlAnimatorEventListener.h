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
 * @file	FUiAnimIControlAnimatorEventListener.h
 * @brief	This is the header file for the %IControlAnimatorEventListener interface.
 *
 * This header file contains the declarations of the %IControlAnimatorEventListener interface.
 */

#ifndef _FUI_ANIM_ICONTROL_ANIMATOR_EVENT_LISTENER_H_
#define _FUI_ANIM_ICONTROL_ANIMATOR_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FBaseRtIEventListener.h>

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
 * @interface	IControlAnimatorEventListener
 * @brief		This interface implements the listener for animation events.
 *
 * @since		2.0
 *
 * The %IControlAnimatorEventListener interface is the listener interface for receiving control animator events.
 * The class that processes a control animator event implements this interface, and the instance created with that class is
 * registered with a UI control, using the ControlAnimator::AddControlAnimatorEventListener() method. When the control animator event
 * occurs, a method of that instance is invoked.
 */
class _OSP_EXPORT_ IControlAnimatorEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IControlAnimatorEventListener(void) {}


	/**
	 * Called when an animation starts on the specified control.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control on which an animation starts
	 */
	virtual void OnControlAnimationStarted(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control) = 0;


	/**
	 * Called when all the animations currently associated with a control have finished.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control on which all the animations have finished
	 */
	virtual void OnControlAnimationFinished(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control) = 0;


	/**
	 * Called when all the animations currently associated with a control have stopped.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   control			The control on which all the animations have stopped
	 */
	virtual void OnControlAnimationStopped(Tizen::Ui::Animations::ControlAnimator& source, Tizen::Ui::Control& control) = 0;


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
	virtual void IControlAnimatorEventListener_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IControlAnimatorEventListener_Reserved2(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IControlAnimatorEventListener_Reserved3(void) { }
};		// IControlAnimatorEventListener


}}}		// Tizen::Ui::Animations

#endif // _FUI_ANIM_ICONTROL_ANIMATOR_EVENT_LISTENER_H_
