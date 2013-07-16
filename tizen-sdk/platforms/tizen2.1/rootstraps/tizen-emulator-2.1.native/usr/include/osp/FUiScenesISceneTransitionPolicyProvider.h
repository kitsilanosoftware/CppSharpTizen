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
 * @file	FUiScenesISceneTransitionPolicyProvider.h
 * @brief	This is the header file for the %ISceneTransitionPolicyProvider interface.
 *
 * This header file contains the declarations of the %ISceneTransitionPolicyProvider interface.
 */

#ifndef _FUI_SCENES_ISCENE_TRANSITION_POLICY_PROVIDER_H_
#define _FUI_SCENES_ISCENE_TRANSITION_POLICY_PROVIDER_H_

#include <FUiScenesTypes.h>


namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @interface	ISceneTransitionPolicyProvider
 * @brief		This interface provides the scene transition policies.
 *
 * @since	2.0
 *
 * The %ISceneTransitionPolicyProvider interface is used to provide the scenario logic for scene transitions.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ ISceneTransitionPolicyProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ISceneTransitionPolicyProvider(void) {}

	/**
	 * Gets the next scene. @n
	 * Called on SceneManager#GoForward(const Tizen::Base::Collection::IList*,SceneTransitionAnimationType,SceneHistoryOption,SceneDestroyOption)
	 * to determine the next scene.
	 *
	 * @since	2.0
	 *
	 * @return		A scene ID
	 * @param[in]	currentSceneId	The scene ID of the active Scene
	 * @param[in]	pArgs			A pointer to an argument list
	 */
	virtual Tizen::Ui::Scenes::SceneId GetNextScene(const Tizen::Ui::Scenes::SceneId& currentSceneId,
												  const Tizen::Base::Collection::IList* pArgs) = 0;


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneTransitionPolicyProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneTransitionPolicyProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneTransitionPolicyProvider_Reserved3(void) {}

}; // ISceneTransitionPolicyProvider
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_ISCENE_TRANSITION_POLICY_PROVIDER_H_
