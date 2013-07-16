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
 * @file	FUiScenesTypes.h
 * @brief	This is the header file for the common data types used by the scene management.
 *
 * This header file contains the declarations of the common data types and constants used by the scene management.
 */

#ifndef _FUI_SCENES_TYPES_H_
#define _FUI_SCENES_TYPES_H_


#include <FBaseString.h>


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * The scene ID.
 *
 * @since	2.0
 */
typedef Tizen::Base::String	SceneId;

/**
 * The transition ID.
 *
 * @since	2.0
 */
typedef Tizen::Base::String	SceneTransitionId;

/**
 * @enum	SceneTransitionDirection
 *
 * Defines the scene transition directions whether forward or backward.
 *
 * @since	2.0
 */
enum SceneTransitionDirection
{
	SCENE_TRANSITION_DIRECTION_FORWARD,				/**< The transition is forward */
	SCENE_TRANSITION_DIRECTION_BACKWARD,			/**< The transition is backward */
};

/**
 * @enum	SceneHistoryOption
 *
 * Defines the scene history operation options whether to add to history or not.
 *
 * @since	2.0
 */
enum SceneHistoryOption
{
	SCENE_HISTORY_OPTION_ADD_HISTORY,				/**< The current scene would be added to history */
	SCENE_HISTORY_OPTION_NO_HISTORY,				/**< The current scene would not be added to history */
};

/**
 * @enum	SceneDestroyOption
 *
 * Defines the scene destroy options.
 *
 * @since	2.0
 */
enum SceneDestroyOption
{
	SCENE_DESTROY_OPTION_KEEP,						/**< The current scene will not be destroyed */
	SCENE_DESTROY_OPTION_DESTROY,					/**< The current scene will be destroyed after the transition is completed */
};

/**
 * @enum	SceneTransitionAnimationType
 *
 * Defines the scene transition animation types.
 *
 * @since	2.0
 *
 * @see		Tizen::Ui::Animations::FrameAnimatorFormTransitionAnimation
 */
enum SceneTransitionAnimationType
{
	SCENE_TRANSITION_ANIMATION_TYPE_NONE,          /**< No transition animation */
	SCENE_TRANSITION_ANIMATION_TYPE_CUSTOM,        /**< The custom transition animation with ISceneAnimationProvider */
	SCENE_TRANSITION_ANIMATION_TYPE_LEFT,          /**< The transition animation using translate left animation */
	SCENE_TRANSITION_ANIMATION_TYPE_RIGHT,         /**< The transition animation using translate right animation */
	SCENE_TRANSITION_ANIMATION_TYPE_FADE_IN_OUT,   /**< The transition animation using alpha animation */
	SCENE_TRANSITION_ANIMATION_TYPE_ZOOM_IN,       /**< The transition animation using scale animation */
	SCENE_TRANSITION_ANIMATION_TYPE_ZOOM_OUT,      /**< The transition animation using scale animation */
	SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN,      /**< The transition animation using scale and alpha animation */
	SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT,     /**< The transition animation using scale and alpha animation */
};
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_TYPES_H_
