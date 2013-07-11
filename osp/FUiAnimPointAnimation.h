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
 * @file	FUiAnimPointAnimation.h
 * @brief	This is the header file for the %PointAnimation class.
 *
 * This header file contains the declarations of the %PointAnimation class.
 */

#ifndef _FUI_ANIM_POINT_ANIMATION_H_
#define _FUI_ANIM_POINT_ANIMATION_H_

#include <FGrpPoint.h>
#include <FUiAnimAnimationBase.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	PointAnimation
 * @brief	This class animates the Tizen::Graphics::Point object.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %PointAnimation class animates an object from a Tizen::Graphics::Point value to another %Tizen::Graphics::Point value
 * based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_uicontrols.htm">Animating UI Controls</a>.
 */
class _OSP_EXPORT_ PointAnimation
	: public AnimationBase
{
public:

	/**
	 * Initializes this instance of %PointAnimation with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	startValue			The start value for %PointAnimation
	 * @param[in]	endValue			The end value for %PointAnimation
	 * @param[in]	duration			The duration of animation in milliseconds
	 * @param[in]	interpolator		The type of interpolator used for the intermediate value calculation of the animation
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The value of the specified parameter is negative or the interpolator is of an invalid type.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	PointAnimation(const Tizen::Graphics::Point& startValue, const Tizen::Graphics::Point& endValue, long duration, AnimationInterpolatorType interpolator);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~PointAnimation(void);


	/**
	 * This is the copy constructor for the %PointAnimation class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	pointAnimation	An instance of %PointAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	PointAnimation(const PointAnimation& pointAnimation);


	/**
	 * Assigns the value of the specified instance to the current instance of %PointAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	pointAnimation		An instance of %PointAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	PointAnimation& operator =(const PointAnimation& pointAnimation);


	/**
	 * Checks whether the specified instance and the current instance of %PointAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %PointAnimation are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %PointAnimation
	 */
	bool operator ==(const PointAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and the current instance of %PointAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %PointAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %PointAnimation
	 */
	bool operator !=(const PointAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %PointAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %PointAnimation
	 * @remarks     The %PointAnimation class has a semantic value. @n
	 *				This means that this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	The two equal instances must return the same hash value. For better performance, the used hash function must generate a random
	 *			distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Gets the animated value for the current time.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]   currentTime		The current time value of the animation @n
	 *								The value must be between @c 0 and the duration of the animation.
	 * @param[out]  animatedValue	The animated value for the current time passed as the input parameter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result GetAnimatedValue(long currentTime, Tizen::Graphics::Point& animatedValue) const;


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
	 * @remarks		If @c time is greater than the duration, it becomes the new duration and @c value becomes the new @c endValue. @n
	 *              The old duration and @c endValue are added as a new key frame entry in the list. @n
	 *              If a key-value pair with the current key already exists, then the old value will be overwritten with the new one. @n
	 *              An exception will be returned if time is equal to @c 0 or duration of the animation.
	 */
	result AddKeyFrame(long time, const Tizen::Graphics::Point& value);


	/**
	 * Gets the keyframe at a particular index in this animation.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                                  The value is sorted in an increasing order of time.
	 * @param[out]	time				The time stamp at the specified @c index
	 * @param[out]	value				The value at the specified @c index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks		The @c time and @c value returned are present at the index of the sorted map list that is sorted with respect to the key.
	 *              For example, if the user adds key-frame in the order (10,value1), (20,value2), (5,value3) and then
	 *              GetKeyFrameAt(0,time,value) is called, the pair returned is (5,value3).
	 */
	result GetKeyFrameAt(int index, long& time, Tizen::Graphics::Point& value) const;


	/**
	 * Removes the passed keyframe object from the keyframe list.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	time				The key frame time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c time value is invalid.
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
	 *                                  The value is sorted in an increasing order of time.
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
	result SetStartValue(const Tizen::Graphics::Point& startValue);


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
	result SetEndValue(const Tizen::Graphics::Point& endValue);


	/**
	 * Gets the start value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return	The start value
	 */
	Tizen::Graphics::Point GetStartValue(void) const;


	/**
	 * Gets the end value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return	The end value
	 */
	Tizen::Graphics::Point GetEndValue(void) const;


	/**
	 * Gets the type information of this instance.
	 *
	 * @since	2.0
	 *
	 * @return  The type information of this instance
	 */
	virtual AnimationType GetType(void) const;


protected:

	friend class _PointAnimationImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This variable is for internal usage.
	//
	// @since        2.0
	//
	class _PointAnimationImpl* _pPointAnimationImpl;

private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since        2.0
	//
	PointAnimation(void);
};		// PointAnimation


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_POINT_ANIMATION_H_
