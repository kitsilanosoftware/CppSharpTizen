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
 * @file	FUiAnimFrameAnimator.h
 * @brief	This is the header file for the %FrameAnimator class.
 *
 * This header file contains the declarations of the %FrameAnimator class.
 */

#ifndef _FUI_ANIM_FRAME_ANIMATOR_H_
#define _FUI_ANIM_FRAME_ANIMATOR_H_

#include <FUiAnimIFrameAnimatorEventListener.h>


namespace Tizen { namespace Ui {  namespace Controls
{
class Form;
class _FrameImpl;
} } }

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	FrameAnimator
 * @brief	This class defines the animation methods for Frame.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %FrameAnimator class is used to control the animations operated on a Frame.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_formstransition.htm">Animating a Form Transition</a>.
 *
 */
class _OSP_EXPORT_ FrameAnimator
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~FrameAnimator(void);


	/**
	 * Adds an IFrameAnimatorEventListener instance to the current instance of the frame. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	listener				The listener to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified @c listener is already added.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result AddFrameAnimatorEventListener(IFrameAnimatorEventListener& listener);


	/**
	 * Removes an IFrameAnimatorEventListener instance from the current instance of the frame. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	listener				The listener to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c listener is not found.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RemoveFrameAnimatorEventListener(IFrameAnimatorEventListener& listener);


	/**
	 * Gets the animation status of the frame animator.
	 *
	 * @since	2.0
	 *
	 * @return	The animation state of the frame animator
	 */
	AnimatorStatus GetStatus(void) const;


	/**
	 * Sets the specified form as the current form of the frame with an animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	form			        The form object to set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Control::Invalidate() need not be called to display the form. @n
	 *				To select the animation to be used during this method, use SetFormTransitionAnimation() before calling this method.
	 */
	result SetCurrentForm(const Tizen::Ui::Controls::Form& form);

	/**
	 * Sets a specified form as the current form of the frame with an animation.
	 *
	 * @since	2.1
	 *
	 * @return		An error code
	 * @param[in]		pForm				A pointer to Form object to set
	 * @exception	  E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_ARG                             The specified @c pForm is @c null.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	  E_SYSTEM				A system error has occurred.
	 * @remarks		Control::Invalidate() need not be called to display the form. @n
	 *				To select the animation that is used during this method, use SetFormTransitionAnimation() before calling this method.
	 */
	result SetCurrentForm(Tizen::Ui::Controls::Form* pForm);


	/**
	 * Sets the type of the form transition animation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animation			The type of form transition animation to set
	 * @param[in]	duration			The duration of animation in milliseconds @n
	 *									The maximum duration is one second.
	 * @param[in]	interpolator		The type of interpolator used for the intermediate value calculation of the animation
	 */
	void SetFormTransitionAnimation(FrameAnimatorFormTransitionAnimation animation, long duration, AnimationInterpolatorType interpolator);


	/**
	 * Gets the type of the form transition animation.
	 *
	 * @since	2.0
	 *
	 * @param[out]	animation			The type of form transition animation used
	 * @param[out]	duration			The duration of animation in milliseconds
	 * @param[out]	interpolator		The type of interpolator used for the intermediate value calculation of the animation
	 */
	void GetFormTransitionAnimation(FrameAnimatorFormTransitionAnimation& animation, long& duration, AnimationInterpolatorType& interpolator) const;


	/**
	 * Sets the control points for the Bezier interpolator. @n
	 * The %SetFormTransitionBezierControlPoints() method is supported only if the interpolator is @c ANIMATION_INTERPOLATOR_BEZIER.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	time1				The control point 1 - Time @n
	 *									The time must be within the range @c 0.0 to @c 1.0.
	 * @param[in]	value1				The control point 1 - Value @n
	 *									The value must be within the range @c 0.0 to @c 1.0.
	 * @param[in]	time2				The control point 2 - Time @n
	 *									The time must be within the range @c 0.0 to @c 1.0.
	 * @param[in]	value2				The control point 2 - Value @n
	 *									The value must be within the range @c 0.0 to @c 1.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION The interpolator of this instance is not ANIMATION_INTERPOLATOR_BEZIER.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result SetFormTransitionBezierControlPoints(float time1, float value1, float time2, float value2);


	/**
	 * Gets the control points of the Bezier interpolator. @n
	 * The %GetFormTransitionBezierControlPoints() method is supported only if the interpolator is @c ANIMATION_INTERPOLATOR_BEZIER. @n
	 * Therefore, @c 0 will be returned for other interpolators.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[out]	time1				The control point 1 - Time
	 * @param[out]	value1				The control point 1 - Value
	 * @param[out]	time2				The control point 2 - Time
	 * @param[out]	value2				The control point 2 - Value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION The interpolator of this instance is not ANIMATION_INTERPOLATOR_BEZIER.
	 */
	result GetFormTransitionBezierControlPoints(float& time1, float& value1, float& time2, float& value2) const;


	/**
	 * Stops all the animations that are being played and jumps to the final frame of the animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result StopAllAnimations(void);


protected:

	friend class _FrameAnimatorImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The variable for internal usage.
	//
	// @since	 2.0
	//
	class _FrameAnimatorImpl* _pFrameAnimatorImpl;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the constructor for this class.
	//
	// @since	2.0
	//
	FrameAnimator(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Initializes this class.
	//
	// @since	2.0
	// @return		An error code
	// @param[in]	source				An instance of the Frame class
	// @exception	E_SUCCESS			The method is successful.
	// @exception	E_SYSTEM			A system error has occurred.
	//
	result Construct(const Tizen::Ui::Controls::Frame& source);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the copy constructor for the %FrameAnimator class.
	//
	// @since	2.0
	//
	FrameAnimator(const FrameAnimator& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %FrameAnimator.
	//
	// @since	2.0
	//
	FrameAnimator& operator =(const FrameAnimator& rhs);


	friend class Tizen::Ui::Controls::_FrameImpl;
};		// FrameAnimator


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_FRAME_ANIMATOR_H_
