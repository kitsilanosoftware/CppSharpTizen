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
 * @file	FUiAnimVisualElementAnimation.h
 * @brief	This is the header file for the %VisualElementAnimation class.
 *
 * This header file contains the declarations of the %VisualElementAnimation class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_H_
#define _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_H_

#include <FBaseObject.h>

namespace Tizen { namespace Ui { namespace Animations
{


class IVisualElementAnimationStatusEventListener;
class IVisualElementAnimationTimingFunction;
class IVisualElementAnimationValueInterpolator;
class _VisualElementAnimationImpl;

/**
 * @class 	VisualElementAnimation
 * @brief 	This class is the base class for all the %VisualElementAnimation classes.
 *
 * @since 	2.0
 *
 * The %VisualElementAnimation class defines the basic animation properties, such as the interpolator to be used,
 * the duration of the animation in milliseconds, the delay before the animation is started in milliseconds, and the repeat count.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/visual_element_animations.htm">Visual Element Animations</a>.
 *
 */
class _OSP_EXPORT_ VisualElementAnimation
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementAnimation(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~VisualElementAnimation(void);


	/**
	 * This is the copy constructor for the %VisualElementAnimation class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animation	An instance of %VisualElementAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementAnimation(const VisualElementAnimation& animation);


	/**
	 * Assigns the value of the specified instance to the current instance of %VisualElementAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %VisualElementAnimation
	 */
	VisualElementAnimation& operator =(const VisualElementAnimation& rhs);


	/**
	 * Checks whether the specified instance and current instance of %VisualElementAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the animation of the two instances of %VisualElementAnimation are equal, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of %VisualElementAnimation
	 */
	bool operator ==(const VisualElementAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and current instance of %VisualElementAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the values of the animations of the two instances of %VisualElementAnimation are not equal, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of %VisualElementAnimation
	 */
	bool operator !=(const VisualElementAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %VisualElementAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the current instance equals the value of the specified instance, @n
	 * 			else @c false
	 * @param[in]	obj		An instance of %VisualElementAnimation
	 * @remarks     The %VisualElementAnimation class has a semantic value which means that this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks     The two equal instances must return the same hash value.
	 *				For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Gets the copied instance of the class.
	 *
	 * @since   2.0
	 *
	 * @return 	An instance of %VisualElementAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual VisualElementAnimation* CloneN(void) const;


	/**
	 * Sets an IVisualElementAnimationStatusEventListener listener instance to listen to the events of a particular animation. @n
	 * The added listener, %IVisualElementAnimationStatusEventListener, can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	pListener		The listener instance to set
	 */
	void SetVisualElementAnimationStatusEventListener(IVisualElementAnimationStatusEventListener* pListener);


	/**
	 * Gets the IVisualElementAnimationStatusEventListener listener.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the IVisualElementAnimationStatusEventListener instance @n
	 *				If listener has not been set, @c null is returned.
	 * @see 		SetVisualElementAnimationStatusEventListener()
	 */
	IVisualElementAnimationStatusEventListener* GetVisualElementAnimationStatusEventListener(void) const;


	/**
	 * Sets the timing function to calculate the animation pace.
	 *
	 * @since 	2.0
	 *
	 * @param[in] 	pTimingFunction		The timing function instance to set
	 * @remarks 	If @c pTimingFunction is @c null, the default timing function is used which is pre-defined by the UI framework.
	 * @see			GetTimingFunction()
	 */
	void SetTimingFunction(const IVisualElementAnimationTimingFunction* pTimingFunction);


	/**
	 * Gets the timing function.
	 *
	 * @since   2.0
	 *
	 * @return		A pointer to the timing function instance
	 *				If timing function has not been set, the default timing function is returned.
	 * @see 		SetTimingFunction()
	 */
	const IVisualElementAnimationTimingFunction* GetTimingFunction(void) const;


	/**
	 * Sets the interpolator to calculate the current value for the specific time during the animation.
	 *
	 * @since 	2.0
	 *
	 * @param[in] 	pInterpolator	The interpolator instance to set
	 * @remarks 	If @c pInterpolator is @c null, the default interpolator is used which is pre-defined by the UI framework.
	 * @see 		GetValueInterpolator()
	 */
	void SetValueInterpolator(const IVisualElementAnimationValueInterpolator* pInterpolator);


	/**
	 * Gets the value interpolator.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the interpolator instance
	 *				If interpolator has not been set, the default interpolator is returned.
	 * @see 		SetValueInterpolator()
	 */
	const IVisualElementAnimationValueInterpolator* GetValueInterpolator(void) const;


	/**
	 * Sets the duration of the animation.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	milliseconds	The duration of the animation in milliseconds
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The value of the specified parameter is negative or lesser than the offset of the animation.
	 * @see		GetDuration()
	 */
	result SetDuration(long milliseconds);


	/**
	 * Gets the duration of the animation in milliseconds.
	 *
	 * @since 	2.0
	 *
	 * @return 	The duration value of the animation
	 * @see 	SetDuration()
	 */
	long GetDuration(void) const;


	/**
	 * Sets the offset value of the animation. @n
	 * Additionally, the %SetOffset() alters the start value and duration for which an animation is played.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	milliseconds		The offset of the animation in milliseconds
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The value of the specified parameter is negative or greater than the duration of the animation.
	 * @remarks 	If the start value of the animation is @c 0.0, the end value is @c 1.0, the duration is @c 100 ms and the offset value is @c 20 ms,
	 *              the actual animation starts at @c 0th ms and plays for @c 80 ms with a start value of @c 0.2. @n
	 *		If @c autoReverse is set to @c true, the backward animation plays for @c 100ms, from @c 1.0 to @c 0.0.
	 * @see 	GetOffset()
	 */
	result SetOffset(long milliseconds);


	/**
	 * Gets the offset value in milliseconds after the animation starts.
	 *
	 * @since 	2.0
	 *
	 * @return	The offset value of the animation in milliseconds @n
	 *			The default value of the offset is @c 0.
	 * @see 	SetOffset()
	 */
	long GetOffset(void) const;


	/**
	 * Sets the delay for the animation. @n
	 * The animation starts after the duration of delay has passed.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	milliseconds		The delay for the animation to start in milliseconds
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The value of the specified parameter is negative.
	 * @remarks 	This method does not alter the start, end, and duration values of the animation.
	 * @see 	GetDelay()
	 */
	result SetDelay(long milliseconds);


	/**
	 * Gets the delay value in milliseconds before the animation starts.
	 *
	 * @since 	2.0
	 *
	 * @return	The delay value in milliseconds @n
	 *			The default value of the delay is @c 0.
	 * @see 	SetDelay()
	 */
	long GetDelay(void) const;


	/**
	 * Sets the repeat count for the animation. @n
	 * Repeats an animation for the specified number of times.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	count			The number of times the animation is repeated
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The value of the specified parameter is negative.
	 * @remarks 	A delay and offset is applied to an animation only when the animation is played for the first time.
	 *          	If @c count is set to @c 0, the animation is repeated indefinitely.
	 * @see 	GetRepeatCount()
	 */
	result SetRepeatCount(long count);


	/**
	 * Gets the repeat count value of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	The repeat count value of the animation @n
	 *			The default value of the repeat count is @c 1.
	 * @see 	SetRepeatCount()
	 */
	long GetRepeatCount(void) const;


	/**
	 * Sets the @c autoReverse property of the animation. @n
	 * If enabled, the forward and backward animation can also be played.
	 *
	 * @since 	2.0
	 *
	 * @param[in] 	autoReverse		Set to @c true to enable the @c autoReverse property of the animation, @n
	 *								else @c false
	 * @remarks		If @c autoReverse is set to @c true, the duration of the animation is doubled.
	 *				If the repeat count is more than @c 1, @c autoReverse is applied to each iteration. @n
	 *              Note that if @c autoReverse is set to @c true, one forward animation play and
	 * 				one backward animation play is one iteration.
	 * @see 	IsAutoReverseEnabled()
	 */
	void SetAutoReverseEnabled(bool autoReverse);


	/**
	 * Checks whether auto reverse is enabled.
	 *
	 * @since 	2.0
	 *
	 * @return	@c true if auto reverse is enabled, @n
	 *			else @c false @n
	 *			The default auto reverse value is @c false.
	 * @see 	SetAutoReverseEnabled()
	 */
	bool IsAutoReverseEnabled(void) const;


	/**
	 * Sets the scale ratio of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	scaleRatio		The scale ratio value of the animation
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The value of the specified parameter is below @c 0.
	 * @remarks		If @c scaleRatio is @c 0.5, then the animation speed is 2 times faster.
	 * @see 	GetScaleRatio()
	 */
	result SetScaleRatio(float scaleRatio);


	/**
	 * Gets the scale ratio value of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	The scale ratio value of the animation @n
	 *			The default value of scale ratio is @c 1.0f.
	 * @see 	SetScaleRatio()
	 */
	float GetScaleRatio(void) const;


	/**
	 * Sets the custom data of the animation.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pUserData			The user data associated with this instance
	 * @see 	GetUserData()
	 */
	void SetUserData(void* pUserData);


	/**
	 * Gets the custom data of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The user data associated with this instance
	 * @see 	SetUserData()
	 */
	void* GetUserData(void) const;


	/**
	 * Gets the predefined timing function by name.
	 *
	 * @since	2.0
	 *
	 * @return	The specified timing function
	 * @param[in]	name			The timing function name
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG 		The specified input parameter is invalid.
	 * @remarks		The parameter @c name must be "Linear", "EaseIn", "EaseOut", "EaseInOut", "EaseOutIn", "Discrete", "Bezier", "ExpIn", "ExpOut", "EaseElasticIn", or "EaseElasticOut".
	 * 				The specific error code can be accessed using the GetLastResult() method.
	 */
	static const IVisualElementAnimationTimingFunction* GetTimingFunctionByName(const Tizen::Base::String& name);


protected:

	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the constructor for derived classes.
	//
	// @since  2.0
	//
	VisualElementAnimation(_VisualElementAnimationImpl* pImpl);


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// @since  2.0
	//
	_VisualElementAnimationImpl* _pAnimationImpl;

	friend class _VisualElementAnimationImpl;
};		// VisualElementAnimation


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_H_
