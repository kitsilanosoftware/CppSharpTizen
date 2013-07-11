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
 * @file	FUiAnimVisualElementValueAnimation.h
 * @brief	This is the header file for the %VisualElementValueAnimation class.
 *
 * This header file contains the declarations of the %VisualElementValueAnimation class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_VALUE_ANIMATION_H_
#define _FUI_ANIM_VISUAL_ELEMENT_VALUE_ANIMATION_H_

#include <FUiVariant.h>
#include <FUiAnimVisualElementAnimation.h>

namespace Tizen { namespace Ui { namespace Animations
{


class IVisualElementAnimationTickEventListener;
class _VisualElementValueAnimationImpl;

/**
 * @class 	VisualElementValueAnimation
 * @brief 	This class is for value animation.
 *
 * @since 	2.0
 *
 * The %VisualElementValueAnimation class defines the basic value animation.
 */
class _OSP_EXPORT_ VisualElementValueAnimation
	: public VisualElementAnimation
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	2.0
	 *
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementValueAnimation(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~VisualElementValueAnimation(void);


	/**
	 * This is the copy constructor for the %VisualElementValueAnimation class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animation	An instance of %VisualElementValueAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementValueAnimation(const VisualElementValueAnimation& animation);


	/**
	 * Assigns the value of the specified instance to the current instance of %VisualElementValueAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %VisualElementValueAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementValueAnimation& operator =(const VisualElementValueAnimation& rhs);


	/**
	 * Checks whether the specified instance and current instance of %VisualElementValueAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the animation of the two instances of %VisualElementValueAnimation are equal, @n
	 *		else @c false
	 * @param[in]	rhs		An instance of %VisualElementValueAnimation
	 */
	bool operator ==(const VisualElementValueAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and current instance of %VisualElementValueAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the values of the animations of the two instances of %VisualElementValueAnimation are not equal, @n
	 *		else @c false
	 * @param[in]	rhs		An instance of %VisualElementValueAnimation
	 */
	bool operator !=(const VisualElementValueAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %VisualElementValueAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the current instance equals the value of the specified instance, @n
	 *               else @c false
	 * @param[in]	obj		An instance of %VisualElementValueAnimation
	 * @remarks     The %VisualElementValueAnimation class has a semantic value which means that this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks 	The two equal instances must return the same hash value.
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
	 * Sets an IVisualElementAnimationTickEventListener listener instance to listen to the events of a particular animation. @n
	 * The set listener, %IVisualElementAnimationTickEventListener, can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	pListener		The listener to set
	 */
	void SetVisualElementAnimationTickEventListener(IVisualElementAnimationTickEventListener* pListener);


	/**
	 * Gets the IVisualElementAnimationTickEventListener listener.
	 *
	 * @since		 2.0
	 *
	 * @return				   A pointer to the IVisualElementAnimationTickEventListener instance @n
	 *										 If listener has not been set, @c null is returned.
	 * @see SetVisualElementAnimationTickEventListener()
	 */
	IVisualElementAnimationTickEventListener* GetVisualElementAnimationTickEventListener(void) const;


	/**
	 * Sets the start value of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in]	startValue		The start value of the animation to set
	 * @exception	E_SUCCESS	 	The method is successful.
	 * @exception	E_INVALID_ARG		The type of Variant is empty.
	 * @see		GetStartValue()
	 */
	result SetStartValue(const Tizen::Ui::Variant& startValue);


	/**
	 * Gets the start value of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	The start value of animation
	 * @see		SetStartValue()
	 */
	Tizen::Ui::Variant GetStartValue(void) const;


	/**
	 * Sets the end value of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in]	endValue		The end value of the animation to set
	 * @exception	E_SUCCESS	 	The method is successful.
	 * @exception	E_INVALID_ARG		The type of Variant is empty.
	 * @see		GetEndValue()
	 */
	result SetEndValue(const Tizen::Ui::Variant& endValue);


	/**
	 * Gets the end value of the animation.
	 *
	 * @since 	2.0
	 *
	 * @return	The end value of animation
	 * @see		SetEndValue()
	 */
	Tizen::Ui::Variant GetEndValue(void) const;


	/**
	 * Sets the flag to apply the end value of the animation when the animation is finished.
	 *
	 * @since 	2.0
	 *
	 * @param[in]	apply	Set to @c true to apply the end values of the animation, @n
	 *						else @c false
	 * @remarks		There is no difference in behavior with this method in value animation. @n
	 * 				So you must set the end value by seeing this value.
	 * @see		IsEndValueApplied()
	 */
	void SetEndValueApplied(bool apply);


	/**
	 * Checks whether the end value of the animation is applied when the animation is finished.
	 *
	 * @since 	2.0
	 *
	 * @return	@c true if the end value is applied, @n
	 *			else @c false @n
	 *			The default value is @c true.
	 * @see		SetEndValueApplied()
	 */
	bool IsEndValueApplied(void) const;


	/**
	 * Adds the key frame information for the animation.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	timeProgress		The specified time progress value @n
 	 *                       			This must be in the range @c 0.0 to @c 1.0 and cannot be @c 0.0 and @c 1.0.
	 * @param[in]	value				The value at the specified time
	 * @param[in]	pTimingFunction		The timing function instance that is used in keyframe segment
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The specified @c value parameter is invalid.
	 * @exception 	E_OUT_OF_RANGE 		The specified @c timeProgress is not within the range @c 0 to @c 1 (exclusive).
	 * @remarks		If a key-value pair with the current key already exists, the old value is overwritten with the new one.
	 *        		If timing function is @c null, the default timing function is applied.
	 *      		The timing function is applied to current pace from previous pace.
	 * @see 	RemoveKeyFrame()
	 * @see 	RemoveAllKeyFrames()
	 */
	result AddKeyFrame(float timeProgress, const Tizen::Ui::Variant& value, const IVisualElementAnimationTimingFunction* pTimingFunction = null);


	/**
	 * Removes the key frame information for the animation.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	timeProgress		The time progress for the key frame to remove
 	 *                  	     		This must be in the range @c 0.0 to @c 1.0 and cannot be @c 0.0 and @c 1.0.
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception 	E_OUT_OF_RANGE		The value of the specified parameter is not within the range @c 0 to @c 1 (exclusive).
	 * @exception	E_OBJ_NOT_FOUND		The key frame with @c timeProgress does not exist.
	 * @see 	AddKeyFrame()
	 * @see 	RemoveAllKeyFrames()
	 */
	result RemoveKeyFrame(float timeProgress);


	/**
	 * Removes all the key frame information for the animation.
	 *
	 * @since	2.0
	 *
	 * @see 	AddKeyFrame()
	 * @see 	RemoveKeyFrame()
	 */
	void RemoveAllKeyFrames(void);


protected:

	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the constructor for derived classes.
	//
	// @since  2.0
	//
	VisualElementValueAnimation(_VisualElementValueAnimationImpl* pImpl);


	friend class _VisualElementValueAnimationImpl;
};		// VisualElementValueAnimation


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_VISUAL_ELEMENT_VALUE_ANIMATION_H_

