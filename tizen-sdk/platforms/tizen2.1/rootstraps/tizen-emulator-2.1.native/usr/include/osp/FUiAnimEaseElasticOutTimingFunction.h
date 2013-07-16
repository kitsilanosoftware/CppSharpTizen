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
 * @file	FUiAnimEaseElasticOutTimingFunction.h
 * @brief	This is the header file for the %EaseElasticOutTimingFunction class.
 *
 * This header file contains the declarations of the %EaseElasticOutTimingFunction class.
 */

#ifndef _FUI_ANIM_EASE_ELASTIC_OUT_TIMING_FUNCTION_H_
#define _FUI_ANIM_EASE_ELASTIC_OUT_TIMING_FUNCTION_H_

#include <FUiAnimIVisualElementAnimationTimingFunction.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	EaseElasticOutTimingFunction
 * @brief	This class stores the information of an ease-elastic-out timing function.
 *
 * @since	2.0
 *
 * The %EaseElasticOutTimingFunction class provides ease-elastic-out timing function related information.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/timing_function.htm">Timing Function</a>.
 *
 */
class _OSP_EXPORT_ EaseElasticOutTimingFunction
	: public Tizen::Base::Object
	, public IVisualElementAnimationTimingFunction
{
public:

	/**
	 * This is the constructor for this class.
	 *
	 * @since	2.0
	 */
	EaseElasticOutTimingFunction(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~EaseElasticOutTimingFunction(void);


	/**
	 * Calculates the progress(pace) of an animation regarding the time elapsed.
	 *
	 * @since	2.0
	 *
	 * @return	The progress(pace) value calculated by ease-elastic-out equation with period @n
	 *			@c 0 and @c 1 are the start and end values of an animation, respectively.
	 * @param[in]	timeProgress	The time progress value @n
	 *								This must be in the range @c 0.0 to @c 1.0.
	 */
	virtual float CalculateProgress(float timeProgress) const;


	/**
	 * Sets the period value as period of sine curve.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	period				The period value @n
	 *									This must be in the range @c 0.0 to @c 1.0 and cannot be @c 0.0 and @c 1.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is @c 0.0 or negative.
	 * @see		GetPeriod()
	 */
	result SetPeriod(float period);


	/**
	 * Gets the period value.
	 *
	 * @since	2.0
	 *
	 * @return  The period value
	 * @see		SetPeriod()
	 */
	float GetPeriod(void) const;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the assignment operator for this class.
	//
	// @since  2.0
	//
	EaseElasticOutTimingFunction(const EaseElasticOutTimingFunction& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the copy constructor for the %EaseElasticOutTimingFunction class.
	//
	// @since  2.0
	//
	EaseElasticOutTimingFunction& operator= (const EaseElasticOutTimingFunction& rhs);


private:

	/**
	 * The period value
	 *
	 * @since	2.0
	 */
	float __period;
};		// EaseElasticOutTimingFunction


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_EASE_ELASTIC_OUT_TIMING_FUNCTION_H_
