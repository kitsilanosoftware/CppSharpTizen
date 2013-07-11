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
 * @file	FUiScenesForwardSceneTransition.h
 * @brief	This is the header file for the %ForwardSceneTransition class.
 *
 * This header file contains the declarations of the %ForwardSceneTransition class.
 */

#ifndef _FUI_SCENES_FORWARD_SCENE_TRANSITION_H_
#define _FUI_SCENES_FORWARD_SCENE_TRANSITION_H_

#include <FUiScenesSceneTransition.h>


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @class	ForwardSceneTransition
 * @brief	This class is the %ForwardSceneTransition class of a Tizen native application.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ForwardSceneTransition class contains transition information, such as transition direction, transition destination,
 * animation type, history option, and destroy option. By default, the transition direction is set as SCENE_TRANSITION_DIRECTION_FORWARD. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ ForwardSceneTransition
	: public Tizen::Ui::Scenes::SceneTransition
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @remarks		Use this constructor for transition through the policy provider with default options
	 * 				(SCENE_TRANSITION_ANIMATION_TYPE_NONE, SCENE_HISTORY_OPTION_ADD_HISTORY, SCENE_DESTROY_OPTION_KEEP).
	 */
	ForwardSceneTransition(void);

	/**
	 * Initializes this instance of %ForwardSceneTransition with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	destinationSceneId	The scene ID of transition destination
	 * @param[in]	animationType		The transition animation type
	 * @param[in]	historyOption		The history option whether to add the current scene to the history or not
	 * @param[in]	destroyOption		The destroy option whether to destroy the current scene or not
	 * @remarks		Use this constructor for transition to the specified @c destinationSceneId with options.
	 */
	ForwardSceneTransition(const SceneId& destinationSceneId,
						   SceneTransitionAnimationType animationType = SCENE_TRANSITION_ANIMATION_TYPE_NONE,
						   SceneHistoryOption historyOption = SCENE_HISTORY_OPTION_ADD_HISTORY,
						   SceneDestroyOption destroyOption = SCENE_DESTROY_OPTION_KEEP);

	/**
	 * Initializes this instance of %ForwardSceneTransition with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animationType		The transition animation type
	 * @param[in]	historyOption		The history option whether to add the current scene to the history or not
	 * @param[in]	destroyOption		The destroy option whether to destroy the current scene or not
	 * @remarks		Use this constructor for transition through the policy provider.
	 */
	ForwardSceneTransition(SceneTransitionAnimationType animationType,
						   SceneHistoryOption historyOption = SCENE_HISTORY_OPTION_ADD_HISTORY,
						   SceneDestroyOption destroyOption = SCENE_DESTROY_OPTION_KEEP);

	/**
	 * This destructor overrides Tizen::Ui::Scenes::SceneTransition::~SceneTransition().
	 *
	 * @since	2.0
	 */
	virtual ~ForwardSceneTransition(void);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ForwardSceneTransition_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ForwardSceneTransition_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ForwardSceneTransition_Reserved3(void) {}

}; // ForwardSceneTransition
} } } // Tizen::Ui::Scenes

#endif // _FUI_SCENES_FORWARD_SCENE_TRANSITION_H_
