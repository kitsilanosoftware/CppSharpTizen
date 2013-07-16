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
 * @file	FUiAnimAnimationBase.h
 * @brief	This is the header file for the %AnimationBase class.
 *
 * This header file contains the declarations of the %AnimationBase class and the enumerators related to it.
 */

#ifndef _FUI_ANIM_ANIMATION_BASE_H_
#define _FUI_ANIM_ANIMATION_BASE_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FUiAnimTypes.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	AnimationBase
 * @brief	This class is the base class for all the Animation classes. @n
 *			It is an abstract base class.
 *
 * @since	2.0
 *
 * The %AnimationBase class defines the basic animation properties, such as the interpolator to be used, the duration of the animation in milliseconds, the delay before the animation is started in milliseconds, and the repeat count.
 *
 */
class _OSP_EXPORT_ AnimationBase
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~AnimationBase(void);


	/**
	 * Sets the duration of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	milliseconds		The duration of the animation in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       The value of the specified parameter is negative.
	 */
	result SetDuration(long milliseconds);


	/**
	 * Sets the offset value of the animation. @n
	 * Additionally, the %SetOffset() method alters the start value and duration for which an animation is played.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	milliseconds		The offset of the animation in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       The value of the specified parameter is negative or greater than the duration of the animation.
	 * @remarks		If the start value of the animation is @c 0.0, the end value is @c 1.0, the duration is @c 100 ms and the offset value is @c 20 ms,
	 *              the actual animation starts at @c 0th ms and plays for @c 80 ms with a start value of @c 0.2. @n
	 *				If @c autoReverseset is set to @c true, the Backward animation plays for 100ms, from @c 1.0 to @c 0.0.
	 */
	result SetOffset(long milliseconds);


	/**
	 * Sets the delay for the animation. @n
	 * The animation starts after the duration of delay has passed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	milliseconds		The delay for the animation to start in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       The value of the specified parameter is negative.
	 * @remarks		This method does not alter the start, end, and duration values of the animation.
	 */
	result SetDelay(long milliseconds);


	/**
	 * Sets the repeat count for the animation. @n
	 * Repeats an animation for the specified number of times.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	count				The number of times the animation has to repeat
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       The value of the specified parameter is negative.
	 * @remarks		A delay and offset is applied to an animation only when the animation is played for the first time.
	 */
	result SetRepeatCount(long count);


	/**
	 * Sets the AutoReverse property of the animation. @n
	 * If enabled, the forward and backward animation can also be played.
	 *
	 * @since		2.0
	 *
	 * @param[in]	autoReverse			Set to @c true to enable the AutoReverse property of the animation, @n
	 *									else @c false
	 * @remarks		If @c autoReverseset is set to @c true, the duration of the animation is doubled.
	 *				If the repeat count is more than 1, @n
	 *				@c autoReverse is applied to each iteration.
	 *              Note that if @c autoReverse is set to @c true, one forward animation play and one backward animation play is one
	 *				iteration.
	 */
	void SetAutoReverseEnabled(bool autoReverse);


	/**
	 * Sets the scale ratio of the animation. @n
	 * The %SetScaleRatio() method multiplies the duration, offset, and delay using the scale ratio.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	scaleRatio			The scale ratio property of the animation
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       The value of the specified parameter is negative.
	 */
	result SetScaleRatio(float scaleRatio);


	/**
	 * Sets the hold end value of the animation. @n
	 * The %SetHoldEndEnabled() method retains the end values of an animation or goes to the start value of an animation.
	 *
	 * @since		2.0
	 *
	 * @param[in]	holdEnd		Set to @c true to hold the end values of the animation, @n
	 *							else @c false
	 */
	void SetHoldEndEnabled(bool holdEnd);


	/**
	 * Gets the duration of the animation in milliseconds.
	 *
	 * @since		2.0
	 *
	 * @return      The duration value of the animation
	 */
	long GetDuration(void) const;


	/**
	 * Gets the offset value in milliseconds after the animation starts.
	 *
	 * @since		2.0
	 *
	 * @return      The offset value of the animation in milliseconds @n
	 *				The default value of the offset is @c 0.
	 */
	long GetOffset(void) const;


	/**
	 * Gets the delay value in milliseconds before the animation starts.
	 *
	 * @since		2.0
	 *
	 * @return		The delay value in milliseconds @n
	 *				The default value of the delay is @c 0.
	 */
	long GetDelay(void) const;


	/**
	 * Gets the repeat count value of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The repeat count value of the animation @n
	 *				The default value of the repeat count is @c 1.
	 */
	long GetRepeatCount(void) const;


	/**
	 * Checks whether the auto reverse is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the auto reverse is enabled, @n
	 *				else @c false @n
	 *				The default auto reverse value is @c false.
	 */
	bool IsAutoReverseEnabled(void) const;


	/**
	 * Gets the scale ratio value of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The scale ratio value of the animation @n
	 *				The default value of scale ratio is @c 1.0f.
	 */
	float GetScaleRatio(void) const;


	/**
	 * Checks whether the hold end value of the animation is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the hold end value is enabled, @n
	 *				else @c false @n
	 *				The default hold end value is @c true.
	 */
	bool IsHoldEndEnabled(void) const;


	/**
	 * Sets the interpolator type.
	 *
	 * @since		2.0
	 *
	 * @param[in]	interpolatorType	The interpolator type used for the animation
	 */
	void SetInterpolatorType(AnimationInterpolatorType interpolatorType);


	/**
	 * Gets the interpolator type.
	 *
	 * @since		2.0
	 *
	 * @return      The interpolator type of an animation @n
	 *				The default interpolator type is @c ANIMATION_INTERPOLATOR_LINEAR.
	 */
	AnimationInterpolatorType GetInterpolatorType(void) const;


	/**
	 * Sets the control points for Bezier interpolator. @n
	 * The %SetBezierControlPoints() method is supported only if the interpolator is ANIMATION_INTERPOLATOR_BEZIER.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	time1				The control point 1 - Time @n
	 *									The time must be in the range @c 0.0 to @c 1.0. The time value is scaled relative to the duration of the animation.
	 * @param[in]	value1				The control point 1 - Value @n
	 *									The value must be in the range @c 0.0 to @c 1.0. The value is scaled relative to the start and end value of the animation.
	 * @param[in]	time2				The control point 2 - Time @n
	 *									The time must be in the range @c 0.0 to @c 1.0. The time value is scaled relative to the duration of the animation.
	 * @param[in]	value2				The control point 2 - Value @n
	 *									The value must be in the range @c 0.0 to @c 1.0. The value is scaled relative to the start and end value of the animation.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION This method is not supported for the interpolator set of this instance.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @remarks		@c time1 can be greater than @c time2 and vice versa.
	 */
	result SetBezierControlPoints(float time1, float value1, float time2, float value2);


	/**
	 * Gets the control points of the Bezier interpolator. @n
	 * The %GetBezierControlPoints() method is supported only if the interpolator is @c ANIMATION_INTERPOLATOR_BEZIER. @c 0 is returned for the other interpolators.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	time1				The control point 1 - Time @n
	 *									The default value of control point 1 is @c 0.0.
	 * @param[out]	value1				The control point 1 - Value @n
	 *									The default value of control point 1 is @c 0.0.
	 * @param[out]	time2				The control point 2 - Time @n
	 *									The default value of control point 2 is @c 0.0.
	 * @param[out]	value2				The control point 2 - Value @n
	 *									The default value of control point 2 is @c 0.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION This method is not supported for the interpolator set of this instance.
	 *
	 */
	result GetBezierControlPoints(float& time1, float& value1, float& time2, float& value2) const;


	/**
	 * Gets the count of key frames added to this animation.
	 *
	 * @since		2.0
	 *
	 * @return		The key frame count
	 */
	int GetKeyFrameCount(void) const;


	/**
	 * Sets the name of the animation.
	 *
	 * @since		2.0
	 *
	 * @param[in]	name	The name of the animation
	 */
	void SetName(const Tizen::Base::String& name);


	/**
	 * Gets the name of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The name of the animation @n
	 *				The default value of the name is an empty string.
	 */
	Tizen::Base::String GetName(void) const;


	/**
	 * Gets the type information of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The type information of this instance
	 */
	virtual AnimationType GetType(void) const = 0;


protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since   2.0
	//
	AnimationBase(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the copy constructor for the %AnimationBase class.
	//
	// @since	 2.0
	//
	// @param[in]	animationBase		An instance of AnimationBase
	// @remarks		The animation name of the copied %AnimationBase object will be same as the %AnimationBase object passed.
	//              User must change the name using the SetName() method of this class in order to make animation name unique.
	//
	AnimationBase(const AnimationBase& animationBase);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the constructor for this class.
	//
	// @since	2.0
	//
	// @param[in]	duration			The duration of animation in milliseconds
	// @param[in]	interpolator		The type of Interpolation used for animation's intermediate value calculation
	//
	AnimationBase(long duration, AnimationInterpolatorType interpolator);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//  Assigns the value of the specified instance to the current instance of %AnimationBase.
	//
	// @since   2.0
	//
	// @param[in]   value   An instance of %AnimationBase
	// @remarks	   The animation name of the returned %AnimationBase object will be same as the %AnimationBase object passed.
	//			   User must change the name using SetName() method of this class in order to make animation name unique.
	//
	AnimationBase& operator =(const AnimationBase& value);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since	2.0
	//
	virtual void AnimationBase_Reserved1(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since	2.0
	//
	virtual void AnimationBase_Reserved2(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since	2.0
	//
	virtual void AnimationBase_Reserved3(void);


	friend class _AnimationBaseImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This variable is for internal usage.
	//
	// @since  2.0
	//
	class _AnimationBaseImpl* _pAnimationBaseImpl;
};		// AnimationBase


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_ANIMATION_BASE_H_
