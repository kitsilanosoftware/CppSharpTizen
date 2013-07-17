//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file  FUiEffectsTypes.h
 * @brief This is the header file for the effect-related types.
 *
 * This header file contains the declarations of the effect-related types.
 */
#ifndef _FUI_EFFECTS_TYPES_H_
#define _FUI_EFFECTS_TYPES_H_

namespace Tizen { namespace Ui { namespace Effects
{
/**
 * @enum EffectType
 *
 * Defines the types of effects.
 *
 * @since 2.0
 */
enum EffectType
{
	EFFECT_TYPE_TIME_BASED, /**< The effect model is not managed by user, that is, at the start of the effect @n
							  the final results and duration are known @n
							  For example, pressing the button leads to new form appearance with animation. */

	EFFECT_TYPE_INTERACTIVE /**< The effect model is managed by user, that is, at the start of the effect it is @n
							  unknown when and how it will be finished */
};


/**
 * @enum EffectResult
 *
 * Defines the result of effects.
 *
 * @since 2.0
 */
enum EffectResult
{
	EFFECT_RESULT_INTERRUPTED = 1,  /**< The effect is interrupted (stopped) with EffectsManager::StopEffect() */
	EFFECT_RESULT_FINISHED,         /**< The effect is finished normally */
	EFFECT_RESULT_ERROR             /**< There is an error during the execution of the effect */
};

}}} // Tizen::Ui::Effects

#endif // _FUI_EFFECTS_TYPES_H_

