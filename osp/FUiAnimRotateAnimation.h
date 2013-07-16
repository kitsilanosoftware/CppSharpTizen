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
 * @file	FUiAnimRotateAnimation.h
 * @brief	This is the header file for the %RotateAnimation class.
 *
 * This header file contains the declarations of the %RotateAnimation class.
 */

#ifndef _FUI_ANIM_ROTATE_ANIMATION_H_
#define _FUI_ANIM_ROTATE_ANIMATION_H_

#include <FUiAnimFloatAnimation.h>


namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	RotateAnimation
 * @brief	This class animates between two angle values.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %RotateAnimation class animates an object from an angle value (float) to another angle value (float)
 * based on the specified interpolator type. When associated with a Control, the animation is applied on the z-axis of the %Control.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_uicontrols.htm">Animating UI Controls</a>.
 */
class _OSP_EXPORT_ RotateAnimation
	: public FloatAnimation
{
public:

	/**
	 * Initializes this instance of %RotateAnimation with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @param[in]	startValue			The start value for the rotate animation @n
	 *									If the value is positive, the control is rotated in the clockwise direction and if the value is negative, the control
	 *									is rotated in the anti-clockwise direction.
	 * @param[in]	endValue			The end value for the rotate animation @n
	 *                                  The value must be @c 0 or @c 360, else ControlAnimator::ControlAnimator() returns an @c E_INVALID_ARG exception.
	 * @param[in]	duration			The duration of animation in milliseconds
	 * @param[in]	interpolator		The type of interpolator @n
	 *                                  This is used for the intermediate value calculation of the animation.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The value of the specified parameter is negative or the interpolator is of an invalid type.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	RotateAnimation(float startValue, float endValue, long duration, AnimationInterpolatorType interpolator);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~RotateAnimation(void);


	/**
	 * This is the copy constructor for the %RotateAnimation class.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rotateAnimation		An instance of %RotateAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	RotateAnimation(const RotateAnimation& rotateAnimation);


	/**
	 * Assigns the value of the specified instance to the current instance of %RotateAnimation.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs		An instance of %RotateAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	RotateAnimation& operator =(const RotateAnimation& rhs);


	/**
	 * Checks whether the specified instance and the current instance of %RotateAnimation have equal animation values.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the animation of the two instances of %RotateAnimation have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %RotateAnimation
	 */
	bool operator ==(const RotateAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and the current instance of %RotateAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %RotateAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %RotateAnimation
	 */
	bool operator !=(const RotateAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %RotateAnimation is equal to the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %RotateAnimation
	 * @remarks     The %RotateAnimation class has a semantic value. This means that this method checks whether the two instances have the same animation.
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
	 * @param[in]	anchorX			The x value of the anchor @n
	 *								The control's animation is performed at this point. The range of the anchor point is @c 0.0 to @c 1.0.
	 * @param[in]	anchorY			The y value of the anchor @n
	 *                              The control's animation is performed at this point. The range of the anchor point is @c 0.0 to @c 1.0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @remarks     The default anchor point value is (0.5, 0.5). The range of an anchor point is @c 0.0 to @c 1.0. @n
	 *              If the anchor point value is (0.5, 0.5), the object is rotated and the center of the object remains fixed. @n
	 *              If the anchor point value is (0.0, 0.0), the object is rotated and the top-left corner of the object remains fixed. @n
	 *              If the anchor point value is (1.0, 1.0), the object is rotated and the right-bottom corner of the object remains fixed.
	 */
	result SetAnchor(float anchorX, float anchorY);


	/**
	 * Gets the anchor point associated with the animation. @n
	 * The default anchor point is (0.5, 0.5).
	 *
	 * @since	2.0
	 *
	 * @param[out]	anchorX		The x value of the anchor @n
	 *                          The control's animation is performed at this point.
	 * @param[out]	anchorY		The y value of the anchor @n
	 *                          The control's animation is performed at this point.
	 */
	void GetAnchor(float& anchorX, float& anchorY) const;


	/**
	 * Gets the type information of this instance.
	 *
	 * @since	2.0
	 *
	 * @return  The type information of this instance
	 */
	virtual AnimationType GetType(void) const;


protected:

	friend class _RotateAnimationImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This variable is for internal usage.
	//
	// @since        2.0
	//
	class _RotateAnimationImpl* _pRotateAnimationImpl;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since        2.0
	//
	RotateAnimation(void);
};		// RotateAnimation


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_ROTATE_ANIMATION_H_
