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
 * @file	FUiScenesBackwardSceneTransition.h
 * @brief	This is the header file for the %BackwardSceneTransition class.
 *
 * This header file contains the declarations of the %BackwardSceneTransition class.
 */

#ifndef _FUI_SCENES_BACKWARD_SCENE_TRANSITION_H_
#define _FUI_SCENES_BACKWARD_SCENE_TRANSITION_H_

#include <FUiScenesSceneTransition.h>


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @class	BackwardSceneTransition
 * @brief	This class is the %BackwardSceneTransition class of a Tizen native application.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %BackwardSceneTransition class contains transition information, such as transition direction, transition destination,
 * animation type, history option, and destroy option. By default, the transition direction is set as SCENE_TRANSITION_DIRECTION_BACKWARD
 * and the history option is set as SCENE_HISTORY_OPTION_NO_HISTORY. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ BackwardSceneTransition
	: public Tizen::Ui::Scenes::SceneTransition
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @remarks		Use this constructor for adjacent backward transition with default options
	 * 				(SCENE_TRANSITION_ANIMATION_TYPE_NONE, SCENE_DESTROY_OPTION_DESTROY).
	 */
	BackwardSceneTransition(void);

	/**
	 * Initializes this instance of %BackwardSceneTransition with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animationType		The transition animation type
	 * @param[in]	destroyOption		The destroy option whether to destroy the current scene or not
	 * @remarks		Use this constructor for adjacent backward transition.
	 */
	BackwardSceneTransition(SceneTransitionAnimationType animationType,
							SceneDestroyOption destroyOption = SCENE_DESTROY_OPTION_DESTROY);

	/**
	 * Initializes this instance of %BackwardSceneTransition with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	destinationSceneId	The scene ID of transition destination
	 * @param[in]	animationType		The transition animation type
	 * @param[in]	destroyOption		The destroy option whether to destroy the current scene or not
	 * @remarks		Use this constructor for non-adjacent backward transition.
	 */
	BackwardSceneTransition(const SceneId& destinationSceneId,
							SceneTransitionAnimationType animationType = SCENE_TRANSITION_ANIMATION_TYPE_NONE,
							SceneDestroyOption destroyOption = SCENE_DESTROY_OPTION_DESTROY);

	/**
	 * This destructor overrides Tizen::Ui::Scenes::SceneTransition::~SceneTransition().
	 *
	 * @since	2.0
	 */
	virtual ~BackwardSceneTransition(void);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void BackwardSceneTransition_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void BackwardSceneTransition_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void BackwardSceneTransition_Reserved3(void) {}

}; // BackwardSceneTransition
} } } // Tizen::Ui::Scenes

#endif // _FUI_SCENES_BACKWARD_SCENE_TRANSITION_H_
