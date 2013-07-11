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
 * @file	FUiScenesISceneEventListener.h
 * @brief	This is the header file for the %ISceneEventListener interface.
 *
 * This header file contains the declarations of the %ISceneEventListener interface.
 */

#ifndef _FUI_SCENES_ISCENE_EVENT_LISTENER_H_
#define _FUI_SCENES_ISCENE_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseRtIEventListener.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @interface	ISceneEventListener
 * @brief		This interface is the listener interface for receiving the scene transition events.
 *
 * @since	2.0
 *
 * The %ISceneEventListener interface is the listener interface for receiving the scene transition events.
 * The class that processes a scene transition event implements this interface and registers using
 * the SceneManager::AddSceneEventListener() method.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ ISceneEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ISceneEventListener(void) {}

	/**
	 * Called after setting as current scene. @n
	 * The UI element (Tizen::Ui::Controls::Form or Tizen::Ui::Controls::Panel)
	 * has been added to a container (Frame or Form) and is ready to update.
	 *
	 * @since	2.0
	 *
	 * @param[in]	previousSceneId		The scene ID of the deactivated scene
	 * @param[in]	currentSceneId		The scene ID of the newly activated scene
	 * @param[in]	pArgs				A pointer to an argument list that is user-specified
	 * @remarks		The argument list must be cleaned up to free memory.
	 */
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs) = 0;

	/**
	 * Called when the current scene is deactivated.
	 *
	 * @since	2.0
	 *
	 * @param[in]	currentSceneId		The scene ID of the scene being deactivated
	 * @param[in]	nextSceneId			The scene ID of the next active scene
	 *
	 */
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId) = 0;


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneEventListener_Reserved3(void) {}

}; // ISceneEventListener
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_ISCENE_EVENT_LISTENER_H_
