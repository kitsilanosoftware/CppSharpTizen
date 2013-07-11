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
 * @file	FUiScenesISceneManagerEventListener.h
 * @brief	This is the header file for the %ISceneManagerEventListener interface.
 *
 * This header file contains the declarations of the %ISceneManagerEventListener interface.
 */

#ifndef _FUI_SCENES_ISCENE_MANAGER_EVENT_LISTENER_H_
#define _FUI_SCENES_ISCENE_MANAGER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @interface	ISceneManagerEventListener
 * @brief		This interface provides listeners for managing scenes and scene states.
 *
 * @since	2.0
 *
 * The %ISceneManagerEventListener interface provides listeners for managing scenes and scene states.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ ISceneManagerEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ISceneManagerEventListener(void) {}

	/**
	 * Called when the scene transition is started.
	 *
	 * @since	2.0
	 *
	 * @param[in]	currentSceneId		The scene ID of the scene being deactivated
	 * @param[in]	nextSceneId			The scene ID of the next active scene
	 *
	 */
	virtual void OnSceneTransitionStarted(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										  const Tizen::Ui::Scenes::SceneId& nextSceneId) = 0;

	/**
	 * Called after the scene transition is completed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	previousSceneId		The scene ID of the deactivated scene
	 * @param[in]	currentSceneId		The scene ID of the newly activated scene
	 * @remarks		This method is called after the scene is activated using the ISceneEventListener::OnSceneActivatedN() callback method.
	 */
	virtual void OnSceneTransitionCompleted(const Tizen::Ui::Scenes::SceneId& previousSceneId,
											const Tizen::Ui::Scenes::SceneId& currentSceneId) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneManagerEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneManagerEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneManagerEventListener_Reserved3(void) {}

}; // ISceneManagerEventListener
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_ISCENE_MANAGER_EVENT_LISTENER_H_
