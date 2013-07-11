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
 * @file	FUiAnimIVisualElementAnimationValueInterpolator.h
 * @brief	This is the header file for the %IVisualElementAnimationValueInterpolator interface.
 *
 * This header file contains the declarations of the %IVisualElementAnimationValueInterpolator interface.
 */

#ifndef _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_VALUE_INTERPOLATOR_H_
#define _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_VALUE_INTERPOLATOR_H_

#include <FBaseObject.h>
#include <FUiVariant.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @interface	IVisualElementAnimationValueInterpolator
 * @brief		This interface implements the interpolator for the VisualElementAnimation defined in the Tizen::Ui::Animations namespace.
 *
 * @since		2.0
 *
 * The %IVisualElementAnimationValueInterpolator interface is the interpolator interface for interpolating on animation progress.
 * The class that interpolates start value and end value implements this interface,
 * and the instance created with that class is registered with an animation,
 * using the VisualElementAnimation::SetValueInterpolator() method or the AnimationTransaction::SetVisualElementAnimationValueInterpolator() method.
 * When tick of the animation occurs, a method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/interpolating_visualelement.htm">Interpolation</a>.
 *
 */
class _OSP_EXPORT_ IVisualElementAnimationValueInterpolator
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	2.0
	 */
	IVisualElementAnimationValueInterpolator(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~IVisualElementAnimationValueInterpolator(void);


	/**
	 * Calculates the interpolated value based on the time. @n
	 * The %Interpolate() method will be called on every frame of an animation to calculate the current value of the specified @c progress.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	progress	The progress value from @c startValue to @c endValue @n
	 *                          The range of @c progress is decided by the IVisualElementAnimationTimingFunction interface.
	 * @param[in]	startValue	The start value
	 * @param[in]	endValue	The end value
	 * @param[out]	value		The interpolated value based on the time
	 * @exception	E_SUCCESS	The method is successful.
	 * @remarks		If result is not E_SUCCESS, use @c startValue for the animation.
	 */
	virtual result Interpolate(float progress, const Tizen::Ui::Variant& startValue, const Tizen::Ui::Variant& endValue, Tizen::Ui::Variant& value) const = 0;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the assignment operator for this class.
	//
	// @since  2.0
	//
	IVisualElementAnimationValueInterpolator(const IVisualElementAnimationValueInterpolator& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %IVisualElementAnimationValueInterpolator.
	//
	// @since  2.0
	//
	IVisualElementAnimationValueInterpolator& operator =(const IVisualElementAnimationValueInterpolator& rhs);
};		// IVisualElementAnimationValueInterpolator


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_VALUE_INTERPOLATOR_H_
