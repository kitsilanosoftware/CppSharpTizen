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
 * @file	FUiAnimEaseOutInTimingFunction.h
 * @brief	This is the header file for the %EaseOutInTimingFunction class.
 *
 * This header file contains the declarations of the %EaseOutInTimingFunction class.
 */

#ifndef _FUI_ANIM_EASE_OUT_IN_TIMING_FUNCTION_H_
#define _FUI_ANIM_EASE_OUT_IN_TIMING_FUNCTION_H_

#include <FUiAnimIVisualElementAnimationTimingFunction.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	EaseOutInTimingFunction
 * @brief	This class stores the information of a ease-outin timing function.
 *
 * @since	2.0
 *
 * The %EaseOutInTimingFunction class provides ease-outin timing function related information.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/timing_function.htm">Timing Function</a>.
 *
 */
class _OSP_EXPORT_ EaseOutInTimingFunction
	: public Tizen::Base::Object
	, public IVisualElementAnimationTimingFunction
{
public:

	/**
	 * This is the constructor for this class.
	 *
	 * @since	2.0
	 */
	EaseOutInTimingFunction(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~EaseOutInTimingFunction(void);


	/**
	 * Calculates the progress(pace) of an animation regarding the time elapsed.
	 *
	 * @since	2.0
	 *
	 * @return	The progress(pace) value calculated by ease-outin equation @n
	 *			@c 0 and @c 1 are the start and end values of an animation, respectively.
	 * @param[in]	timeProgress	The time progress value @n
	 *								This must be in the range @c 0.0 to @c 1.0.
	 */
	virtual float CalculateProgress(float timeProgress) const;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the assignment operator for this class.
	//
	// @since  2.0
	//
	EaseOutInTimingFunction(const EaseOutInTimingFunction& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %EaseOutInTimingFunction.
	//
	// @since  2.0
	//
	EaseOutInTimingFunction& operator =(const EaseOutInTimingFunction& rhs);
};		// EaseOutInTimingFunction


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_EASE_OUT_IN_TIMING_FUNCTION_H_
