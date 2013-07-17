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
 * @file	FUiAnimFloatAnimation.h
 * @brief	This is the header file for the %FloatAnimation class.
 *
 * This header file contains the declaration of the %FloatAnimation class.
 */

#ifndef _FUI_ANIM_FLOAT_ANIMATION_H_
#define _FUI_ANIM_FLOAT_ANIMATION_H_

#include <FBaseFloat.h>
#include <FUiAnimAnimationBase.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	FloatAnimation
 * @brief	This class animates an object from a float value to another float value.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %FloatAnimation class animates an object from a float value to another float value based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_uicontrols.htm">Animating UI Controls</a>.
 *
 */
class _OSP_EXPORT_ FloatAnimation
	: public AnimationBase
{
public:
	/**
	 * Initializes this instance of %FloatAnimation with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	startValue			The start value for float animation
	 * @param[in]	endValue			The end value for float animation
	 * @param[in]	duration			The duration of animation in milliseconds
	 * @param[in]	interpolator		The type of interpolation used for the intermediate value calculation of the animation
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The value of the specified parameter is negative or the interpolator is of an invalid type.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	FloatAnimation(float startValue, float endValue, long duration, AnimationInterpolatorType interpolator);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~FloatAnimation(void);


	/**
	 * Assigns the value of the specified instance to the current instance of %FloatAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	floatAnimation	An instance of %FloatAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	FloatAnimation(const FloatAnimation& floatAnimation);


	/**
	 * Assigns the value of the specified instance to the current instance of %FloatAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %FloatAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	FloatAnimation& operator =(const FloatAnimation& rhs);


	/**
	 * Checks whether the specified instance and current instance of %FloatAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %FloatAnimation are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %FloatAnimation
	 */
	bool operator ==(const FloatAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and current instance of %FloatAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %FloatAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %FloatAnimation
	 */
	bool operator !=(const FloatAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %FloatAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %FloatAnimation
	 * @remarks     The %FloatAnimation class has a semantic value. @n
	 *				This means that this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks     The two equal instances must return the same hash value. For better performance, the used hash function must generate a random distribution
	 *				for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Gets the animated value for the current time.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]   currentTime		The current time value of the animation play @n
	 *                              The value must be between @c 0 and the duration of the animation.
	 * @param[out]  animatedValue	The animated value for the @c currentTime passed as input
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetAnimatedValue(long currentTime, float& animatedValue) const;


	/**
	 * Adds a key frame to the animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	time				The time stamp
	 * @param[in]	value				The value at the specified @c time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		If @c time is greater than the duration, it becomes the new @c duration and value becomes the new @c endValue.
	 *              Also the old @c duration and @c endValue are added as a new key frame entry in the list.
	 * @remarks		If a key-value pair with the current key already exists, the old value is overwritten with the new value.
	 * @remarks		An exception is returned if the @c time is equal to @c 0 or the duration of the animation.
	 */
	result AddKeyFrame(long time, float value);


	/**
	 * Gets the keyframe at a particular index in this animation.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                                  This value is sorted in an increasing order of time.
	 * @param[out]	time				The time stamp at the specified @c index
	 * @param[out]	value				The value at the specified @c index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_RANGE		The specified index is out of range.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks		The @c time and @c value returned, are the one present at the index of the sorted map list (sorted with respect to key).
	 *              For example, if the user adds keyframe in the order (10,value1), (20,value2), (5,value3), and
	 *              the GetKeyFrameAt (0,time,value) is called, the pair returned is (5,value3).
	 */
	result GetKeyFrameAt(int index, long& time, float& value) const;


	/**
	 * Removes the passed keyframe object from the keyframe list.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	time				The key frame time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c time is invalid.
	 * @exception   E_OBJ_NOT_FOUND		The specified @c time is not found in the KeyFrame List.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveKeyFrame(long time);


	/**
	 * Removes the keyframe present at the specified @c index from the keyframe list.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                                  This value is sorted in an increasing order of time.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveKeyFrameAt(int index);


	/**
	 * Removes all the keyframes from the animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveAllKeyFrames(void);


	/**
	 * Sets the start value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	startValue			The start value of the animation to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetStartValue(float startValue);


	/**
	 * Sets the end value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]	endValue			The end value of the animation to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetEndValue(float endValue);


	/**
	 * Gets the start value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return	The start value
	 */
	float GetStartValue(void) const;


	/**
	 * Gets the end value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return		The end value
	 */
	float GetEndValue(void) const;


	/**
	 * Gets the type information of this instance.
	 *
	 * @since	2.0
	 *
	 * @return  The type information of this instance
	 */
	virtual AnimationType GetType(void) const;


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since	2.0
	//
	FloatAnimation(void);


	friend class _FloatAnimationImpl;


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The variable for internal usage.
	//
	// @since  2.0
	//
	class _FloatAnimationImpl* _pFloatAnimationImpl;
};      // FloatAnimation


}}}     // Tizen::Ui::Animations

#endif  // _FUI_ANIM_FLOAT_ANIMATION_H_
