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
 * @file	FUiAnimIVisualElementAnimationTimingFunction.h
 * @brief	This is the header file for the %IVisualElementAnimationTimingFunction interface.
 *
 * This header file contains the declarations of the %IVisualElementAnimationTimingFunction interface.
 */

#ifndef _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_TIMING_FUNCTION_H_
#define _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_TIMING_FUNCTION_H_

#include <FBaseObject.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @interface	IVisualElementAnimationTimingFunction
 * @brief		This interface implements the timing function for the VisualElementAnimation defined in the Tizen::Ui::Animations namespace.
 *
 * @since	 	2.0
 *
 * The %IVisualElementAnimationTimingFunction interface is the timing function interface for the pacing of an animation.
 * The class that defines the pacing of an animation as a timing curve implements this interface,
 * and the instance created with that class is registered with an animation,
 * using the VisualElementAnimation::SetTimingFunction() method or the AnimationTransaction::SetVisualElementAnimationTimingFunction() method.
 * When tick of the animation occurs, a method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/timing_function.htm">Timing Function</a>.
 *
 */
class _OSP_EXPORT_ IVisualElementAnimationTimingFunction
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	2.0
	 */
	IVisualElementAnimationTimingFunction(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~IVisualElementAnimationTimingFunction(void);


	/**
	 * Calculates the progress(pace) of an animation regarding the time elapsed.
	 *
	 * @since	2.0
	 *
	 * @return	The progress(pace) value calculated by the time progress value and the timing function type @n
	 *			@c 0 and @c 1 are the start and end values of an animation, respectively.
	 * @param[in]	timeProgress	The time progress value @n
	 *                               This must be in the range @c 0.0 to @c 1.0.
	 */
	virtual float CalculateProgress(float timeProgress) const = 0;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the assignment operator for this class.
	//
	// @since  2.0
	//
	IVisualElementAnimationTimingFunction(const IVisualElementAnimationTimingFunction& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %IVisualElementAnimationTimingFunction.
	//
	// @since  2.0
	//
	IVisualElementAnimationTimingFunction& operator =(const IVisualElementAnimationTimingFunction& rhs);
};		// IVisualElementAnimationTimingFunction


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_TIMING_FUNCTION_H_
