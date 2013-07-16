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
 * @file	FUiAnimEaseOutTimingFunction.h
 * @brief	This is the header file for the %EaseOutTimingFunction class.
 *
 * This header file contains the declarations of the %EaseOutTimingFunction class.
 */

#ifndef _FUI_ANIM_EASE_OUT_TIMING_FUNCTION_H_
#define _FUI_ANIM_EASE_OUT_TIMING_FUNCTION_H_

#include <FUiAnimIVisualElementAnimationTimingFunction.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	EaseOutTimingFunction
 * @brief	This class stores the information of an ease-out timing function.
 *
 * @since	2.0
 *
 * The %EaseOutTimingFunction class provides ease-out timing function related information.
 */
class _OSP_EXPORT_ EaseOutTimingFunction
	: public Tizen::Base::Object
	, public IVisualElementAnimationTimingFunction
{
public:

	/**
	 * This is the constructor for this class.
	 *
	 * @since	2.0
	 */
	EaseOutTimingFunction(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~EaseOutTimingFunction(void);


	/**
	 * Calculates the progress(pace) of an animation regarding the time elapsed.
	 *
	 * @since	2.0
	 *
	 * @return	The progress(pace) value calculated by ease-out equation @n
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
	EaseOutTimingFunction(const EaseOutTimingFunction& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %EaseOutTimingFunction.
	//
	// @since  2.0
	//
	EaseOutTimingFunction& operator =(const EaseOutTimingFunction& rhs);
};		// EaseOutTimingFunction


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_EASE_OUT_TIMING_FUNCTION_H_
