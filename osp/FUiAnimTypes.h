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
 * @file    FUiAnimTypes.h
 * @brief   This is the header file for the common data types used by UI animations.
 *
 * This header file contains the declarations of the common data types and constants used by UI animations.
 */

#ifndef _FUI_ANIM_TYPES_H_
#define _FUI_ANIM_TYPES_H_


namespace Tizen { namespace Ui { namespace Animations
{


/** @enum HitTestResult
 *
 * Defines the hit test result.
 *
 * @since		2.0
 * @see IVisualElementContentProvider::HitTest()
 * @see VisualElement::OnHitTest()
 */
enum HitTestResult {
	HIT_TEST_NOWHERE = 0,                   /**< VisualElement does not contain the specified point */
	HIT_TEST_MATCH = 1                      /**< VisualElement contains the specified point */
};




/**
 * @enum	AnimationType
 *
 * Defines the information of the animation type.
 *
 * @since	2.0
 */
enum AnimationType
{
	ANIMATION_TYPE_FLOAT_ANIMATION = 0,     /**< The float animation */
	ANIMATION_TYPE_INTEGER_ANIMATION,       /**< The integer animation */
	ANIMATION_TYPE_DIMENSION_ANIMATION,     /**< The dimension animation */
	ANIMATION_TYPE_RECTANGLE_ANIMATION,     /**< The rectangle animation */
	ANIMATION_TYPE_POINT_ANIMATION,         /**< The point animation */
	ANIMATION_TYPE_ROTATE_ANIMATION,        /**< The rotate animation */
};


/**
 * @enum	AnimationInterpolatorType
 *
 * Defines the interpolator type used in animations.
 *
 * @since	2.0
 */
enum AnimationInterpolatorType
{
	ANIMATION_INTERPOLATOR_LINEAR = 0,      /**< The linear interpolator */
	ANIMATION_INTERPOLATOR_DISCRETE,        /**< The discrete interpolator*/
	ANIMATION_INTERPOLATOR_EASE_IN,         /**< The easeIn interpolator*/
	ANIMATION_INTERPOLATOR_EASE_OUT,        /**< The easeOut interpolator*/
	ANIMATION_INTERPOLATOR_EASE_IN_OUT,     /**< The easeInOut interpolator*/
	ANIMATION_INTERPOLATOR_BEZIER,          /**< The bezier interpolator @n
				                                 Sets the control points for this interpolator using AnimationBase::SetBezierControlPoints(). */
};


/**
 * @enum	AnimationTargetType
 *
 * Defines the object property for which the animations are to be applied.
 *
 * @since	2.0
 */
enum AnimationTargetType
{
	ANIMATION_TARGET_NONE = -1,     /**< An invalid %Animation */
	ANIMATION_TARGET_SIZE,          /**< An animation for the size property */
	ANIMATION_TARGET_POSITION,      /**< An animation for the position property */
	ANIMATION_TARGET_ALPHA,         /**< An animation for alpha property @n The value range for playing the alpha animation must be between @c 0.0 to @c 1.0. */
	ANIMATION_TARGET_ROTATION,      /**< An animation for rotate property @n The control will be rotated in the xy-plane along the z-axis. */
	ANIMATION_TARGET_MAX            // This enum value is for internal use only.
									// Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};


/**
 * @enum	AnimatorStatus
 *
 * Defines the status of the animations attached to a control.
 *
 * @since	2.0
 */
enum AnimatorStatus
{
	ANIMATOR_STATUS_PLAYING,        /**< The animation being played */
	ANIMATOR_STATUS_STOPPED,        /**< The animation stopped */
};


/**
* @enum      AnimationGroupType
*
* Defines the animation group type information.
*
* @since 2.0
*/
enum AnimationGroupType
{
	ANIMATION_GROUP_TYPE_SEQUENTIAL = 0,         /** The sequential animation group */
	ANIMATION_GROUP_TYPE_PARALLEL,               /** The parallel animation group */
};


/**
 * @enum	AnimationTransactionStatus
 *
 * Defines the transaction status of the animation.
 * @since	2.0
 */
enum AnimationTransactionStatus
{
	ANIMATION_TRANSACTION_STATUS_PLAYING,       /**< A transaction being played */
	ANIMATION_TRANSACTION_STATUS_STOPPED,       /**< A transaction stopped */
};


/**
 * @enum	ControlAnimatorTriggerType
 *
 * Defines the trigger for animations attached to a control.
 *
 * @since	2.0
 */
enum ControlAnimatorTriggerType
{
	ANIMATION_TRIGGER_USER = 0,             /**< The animation attached to a control is explicitly triggered by the user */
	ANIMATION_TRIGGER_POSITION_CHANGE,      /**< The animation attached to a control is implicitly triggered by changing the position of the control */
	ANIMATION_TRIGGER_SIZE_CHANGE,          /**< The animation attached to a control is implicitly triggered by changing the size of the control */
	ANIMATION_TRIGGER_SHOW_STATE_CHANGE,    /**< The animation attached to a control is implicitly triggered by changing the showstate of the control */
};



/**
 * @enum	FrameAnimatorFormTransitionAnimation
 *
 * Defines the platform predefined animation set for the animation events.
 *
 * @since	2.0
 */
enum FrameAnimatorFormTransitionAnimation
{
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_LEFT = 0,    /**< The transition animation using translate left animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_RIGHT,       /**< The transition animation using translate right animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_FADE_IN_OUT,           /**< The transition animation using alpha animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_ZOOM_IN,               /**< The transition animation using scale animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_ZOOM_OUT,              /**< The transition animation using scale animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_DEPTH_IN,              /**< The transition animation using scale and alpha animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_DEPTH_OUT,             /**< The transition animation using scale and alpha animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_MAX			// This enum value is for internal use only. Using this enum value can cause behavioral, security-related,
																// and consistency-related issues in the application.
};


}}} // Tizen::Ui::Animations

#endif // _FUI_ANIMATIONS_TYPES_H_
