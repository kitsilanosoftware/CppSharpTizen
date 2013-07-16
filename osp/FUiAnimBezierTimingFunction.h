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
 * @file	FUiAnimBezierTimingFunction.h
 * @brief	This is the header file for the %BezierTimingFunction class.
 *
 * This header file contains the declarations of the %BezierTimingFunction class.
 */

#ifndef _FUI_ANIM_BEZIER_TIMING_FUNCTION_H_
#define _FUI_ANIM_BEZIER_TIMING_FUNCTION_H_

#include <FUiAnimIVisualElementAnimationTimingFunction.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	BezierTimingFunction
 * @brief	This class stores the information of a bezier curve timing function.
 *
 * @since	2.0
 *
 * @remarks	This class needs 2 control points of cubic bezier curve.
 *
 * The %BezierTimingFunction class provides bezier curve timing function related information.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/timing_function.htm">Timing Function</a>.
 *
 */
class _OSP_EXPORT_ BezierTimingFunction
	: public Tizen::Base::Object
	, public IVisualElementAnimationTimingFunction
{
public:

	/**
	 * This is the constructor for this class.
	 *
	 * @since	2.0
	 */
	BezierTimingFunction(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~BezierTimingFunction(void);


	/**
	 * Calculates the progress(pace) of an animation regarding the time elapsed.
	 *
	 * @since	2.0
	 *
	 * @return	The progress(pace) value calculated by bezier equation with control points @n
	 *			@c 0 and @c 1 are the start and end values of an animation, respectively.
	 * @param[in]	timeProgress	The time progress value @n
	 *								This must be in the range @c 0.0 to @c 1.0.
	 */
	virtual float CalculateProgress(float timeProgress) const;


	/**
	 * Sets the control points.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in]	timeProgress1		The time progress of control point 1 @n
	 *									This must be in the range @c 0.0 to @c 1.0.
	 * @param[in]	progress1			The progress of control point 1 @n
	 *									This must be in the range @c 0.0 to @c 1.0.
	 * @param[in]	timeProgress2		The time progress of control point 2 @n
	 *									This must be in the range @c 0.0 to @c 1.0.
	 * @param[in]	progress2			The progress of control point 2 @n
	 *									This must be in the range @c 0.0 to @c 1.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is less than @c 0 or greater than @c 1.
	 * @see		GetControlPoints()
	 */
	result SetControlPoints(float timeProgress1, float progress1, float timeProgress2, float progress2);


	/**
	 * Gets the control points.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	timeProgress1		The time progress of control point 1 @n
	 *									The default value is @c 0.33f.
	 * @param[out]	progress1			The progress of control point 1 @n
	 *									The default value is @c 0.8f.
	 * @param[out]	timeProgress2		The time progress of control point 2 @n
	 *									The default value is @c 0.66f.
	 * @param[out]	progress2			The progress of control point 2 @n
	 *									The default value is @c 0.2f.
	 * @exception	E_SUCCESS			The method is successful.
	 * @see		SetControlPoints()
	 */
	result GetControlPoints(float& timeProgress1, float& progress1, float& timeProgress2, float& progress2) const;


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the assignment operator for this class.
	//
	// @since  2.0
	//
	BezierTimingFunction(const BezierTimingFunction& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %BezierTimingFunction.
	//
	// @since  2.0
	//
	BezierTimingFunction& operator =(const BezierTimingFunction& rhs);


private:

	/**
	 * The time progress of control point 1.
	 *
	 * @since	2.0
	 */
	float __timeProgress1;


	/**
	 * The progress of control point 1.
	 *
	 * @since	2.0
	 */
	float __progress1;


	/**
	 * The time progress of control point 2.
	 *
	 * @since	2.0
	 */
	float __timeProgress2;


	/**
	 * The progress of control point 2.
	 *
	 * @since	2.0
	 */
	float __progress2;


	/**
	 * The coefficient A for calculating bezier curve.
	 *
	 * @since	2.0
	 */
	float __coefficientA;


	/**
	 * The coefficient B for calculating bezier curve.
	 *
	 * @since	2.0
	 */
	float __coefficientB;


	/**
	 * The coefficient C for calculating bezier curve.
	 *
	 * @since	2.0
	 */
	float __coefficientC;
};		// BezierTimingFunction


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_BEZIER_TIMING_FUNCTION_H_
