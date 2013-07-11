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
 * @file	FUiAnimDimensionAnimation.h
 * @brief	This is the header file for the %DimensionAnimation class.
 *
 * This header file contains the declarations of the %DimensionAnimation class.
 */

#ifndef _FUI_ANIM_DIMENSION_ANIMATION_H_
#define _FUI_ANIM_DIMENSION_ANIMATION_H_

#include <FGrpDimension.h>
#include <FGrpPoint.h>

#include <FUiAnimAnimationBase.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	DimensionAnimation
 * @brief	This class animates the Tizen::Graphics::Dimension object.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %DimensionAnimation class animates an object from a Tizen::Graphics::Dimension value to another %Tizen::Graphics::Dimension value
 * based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_uicontrols.htm">Animating UI Controls</a>.
 */
class _OSP_EXPORT_ DimensionAnimation
	: public AnimationBase
{
public:
	/**
	 * Initializes this instance of %DimensionAnimation with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @param[in]	startValue			The start value for the dimension animation
	 * @param[in]	endValue			The end value for the dimension animation
	 * @param[in]	duration			The duration of animation in milliseconds
	 * @param[in]	interpolator		The type of interpolator used for the animation's intermediate value calculation
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The value of the specified parameter is negative or the interpolator is of an invalid type.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	DimensionAnimation(const Tizen::Graphics::Dimension& startValue, const Tizen::Graphics::Dimension& endValue, long duration, AnimationInterpolatorType interpolator);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~DimensionAnimation(void);

	/**
	 * This is the copy constructor for the %DimensionAnimation class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	dimensionAnimation	An instance of %DimensionAnimation
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	DimensionAnimation(const DimensionAnimation& dimensionAnimation);


	/**
	 * Assigns the value of the specified instance to the current instance of %DimensionAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %DimensionAnimation
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	DimensionAnimation& operator =(const DimensionAnimation& rhs);


	/**
	 * Checks whether the specified instance and current instance of %DimensionAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %DimensionAnimation are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %DimensionAnimation
	 */
	bool operator ==(const DimensionAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and current instance of %DimensionAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %DimensionAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %DimensionAnimation
	 */
	bool operator !=(const DimensionAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %DimensionAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
	 *              else @c false
	 * @param[in]	obj		An instance of %DimensionAnimation
	 * @remarks     The %DimensionAnimation class has a semantic value that means this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks     The two equal instances must return the same hash value. For better performance, the used hash function must generate a random
	 *				distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Sets the anchor points for the animation.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]   anchorX				The X value of the anchor at which the control's animation is performed
	 * @param[in]   anchorY				The Y value of the anchor at which the control's animation is performed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @remarks     A default anchor point value is (0.0, 0.0). The range of an anchor point is @c 0.0 to @c 1.0. @n
	 *              When the anchor point value is (0.0, 0.0), the object is scaled and the top-left corner of the object remains fixed. @n
	 *              For all the other anchor point values, the position property is changed.
	 *              If the anchor point value is (0.5, 0.5), the object is scaled with respect to the center.
	 *              If the anchor point value is (1.0, 1.0), the object is scaled and the bottom-right corner of the object remains fixed.
	 */
	result SetAnchor(float anchorX, float anchorY);


	/**
	 * Gets the anchor point associated with the animation. @n
	 * The default anchor point is (0.0, 0.0).
	 *
	 * @since		2.0
	 *
	 * @param[out]  anchorX		The X value of the anchor at which the control's animation is performed
	 * @param[out]  anchorY		The Y value of the anchor at which the control's animation is performed
	 */
	void GetAnchor(float& anchorX, float& anchorY) const;


	/**
	 * Gets the animated value for the current time.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   currentTime			The current time value of the animation play @n
	 *									The value must be between @c 0 and the duration of the animation.
	 * @param[out]  animatedValue		The animated value for the current time passed as the input parameter
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 */
	result GetAnimatedValue(long currentTime, Tizen::Graphics::Dimension& animatedValue) const;


	/**
	 * Adds a keyframe to the animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	time				The time stamp
	 * @param[in]	value				The value at the specified @c time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		If @c time is greater than the duration, it will become the new duration and @c value becomes the new @c endValue. @n
	 *              Also, the old duration and @c endValue will be added as a new key frame entry in the list. @n
	 *              If a key-value pair with the current key already exists, the old value will be overwritten with the new one. @n
	 *              An exception will be returned if @c time is equal to @c 0 or the duration of the animation.
	 */
	result AddKeyFrame(long time, const Tizen::Graphics::Dimension& value);


	/**
	 * Gets the keyframe at a particular index in this animation.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]	index				The index value in the keyframe list that is sorted in an increasing order of time
	 * @param[out]	time				The time stamp at the specified @c index
	 * @param[out]	value				The value at the specified @c index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks		The @c time and @c value returned is the one present at the index of the sorted map list(sorted with respect to key). @n
	 *              For example, if the user adds key-frame in the order (10,value1), (20,value2), (5,value3) and then GetKeyFrameAt(0,time,value) is called, the
	 *				pair returned is (5,value3).
	 */
	result GetKeyFrameAt(int index, long& time, Tizen::Graphics::Dimension& value) const;


	/**
	 * Removes the passed keyframe object from the keyframe list.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	time				The key frame time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The keyframe @c time value is invalid.
	 * @exception   E_OBJ_NOT_FOUND		The keyframe @c time value is not found in the keyframe List.
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
	 * @exception   E_OUT_OF_RANGE		The specified @c index parameter is out of range.
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
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetStartValue(const Tizen::Graphics::Dimension& startValue);


	/**
	 * Sets the end value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]	endValue			The end value of the animation to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetEndValue(const Tizen::Graphics::Dimension& endValue);


	/**
	 * Gets the start value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return	The start value
	 */
	Tizen::Graphics::Dimension GetStartValue(void) const;


	/**
	 * Gets the end value of the animation.
	 *
	 * @since	2.0
	 *
	 * @return	The end value
	 */
	Tizen::Graphics::Dimension GetEndValue(void) const;


	/**
	 * Gets the animation type information of this instance.
	 *
	 * @since	2.0
	 *
	 * @return  The animation type information of this instance
	 */
	virtual AnimationType GetType(void) const;


protected:
	friend class _DimensionAnimationImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The variable for internal usage.
	//
	// @since  2.0
	//
	class _DimensionAnimationImpl* _pDimensionAnimationImpl;


private:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since	2.0
	//
	DimensionAnimation(void);
};      // DimensionAnimation


}}}     // Tizen::Ui::Animations

#endif  // _FUI_ANIM_DIMENSION_ANIMATION_H_
