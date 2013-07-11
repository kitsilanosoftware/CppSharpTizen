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
 * @file	FUiAnimExpOutTimingFunction.h
 * @brief	This is the header file for the %ExpOutTimingFunction class.
 *
 * This header file contains the declarations of the %ExpOutTimingFunction class.
 */

#ifndef _FUI_ANIM_EXP_OUT_TIMING_FUNCTION_H_
#define _FUI_ANIM_EXP_OUT_TIMING_FUNCTION_H_

#include <FUiAnimIVisualElementAnimationTimingFunction.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	ExpOutTimingFunction
 * @brief	This class stores the information of an exp-out timing function.
 *
 * @since	2.0
 *
 * The %ExpOutTimingFunction class provides exp-out timing function related information.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/timing_function.htm">Timing Function</a>.
 *
 */
class _OSP_EXPORT_ ExpOutTimingFunction
	: public Tizen::Base::Object
	, public IVisualElementAnimationTimingFunction
{
public:

	/**
	 * This is the constructor for this class.
	 *
	 * @since	2.0
	 */
	ExpOutTimingFunction(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ExpOutTimingFunction(void);


	/**
	 * Calculates the progress(pace) of an animation regarding the time elapsed.
	 *
	 * @since	2.0
	 *
	 * @return	The progress(pace) value calculated by exp-in equation with scale value @n
	 *			@c 0 and @c 1 are the start and end values of an animation, respectively.
	 * @param[in]	timeProgress	The time progress value @n
	 *								This must be in the range @c 0.0 to @c 1.0.
	 */
	virtual float CalculateProgress(float timeProgress) const;


	/**
	 * Sets the scale value.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	scale				The scale value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is @c 0.0 or negative.
	 * @see		GetScaleValue()
	 */
	result SetScaleValue(float scale);


	/**
	 * Gets the scale value.
	 *
	 * @since	2.0
	 *
	 * @return  The scale value
	 * @see		SetScaleValue()
	 */
	float GetScaleValue(void) const;

private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the assignment operator for this class.
	//
	// @since  2.0
	//
	ExpOutTimingFunction(const ExpOutTimingFunction& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %ExpOutTimingFunction.
	//
	// @since  2.0
	//
	ExpOutTimingFunction& operator =(const ExpOutTimingFunction& rhs);


private:

	/**
	 * The scale value.
	 *
	 * @since	2.0
	 */
	float __scale;

	/**
	 * The divisor for exponential timing function.
	 *
	 * @since	2.0
	 */
	float __divisor;
};		// ExpOutTimingFunction


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_EXP_OUT_TIMING_FUNCTION_H_
