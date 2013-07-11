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
 * @file	FUiScenesISceneAnimationProvider.h
 * @brief	This is the header file for the %ISceneAnimationProvider interface.
 *
 * This header file contains the declarations of the %ISceneAnimationProvider interface.
 */

#ifndef _FUI_SCENES_ISCENE_ANIMATION_PROVIDER_H_
#define _FUI_SCENES_ISCENE_ANIMATION_PROVIDER_H_

#include <FUiScenesTypes.h>


namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @interface	ISceneAnimationProvider
 * @brief		This interface is the interface for providing custom animation operation on scene transition.
 *
 * @since	2.0
 *
 * The %ISceneAnimationProvider interface is the interface for providing custom animation operation on scene transition.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/transition_animation.htm">Transition Animations</a>.
 */
class _OSP_EXPORT_ ISceneAnimationProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ISceneAnimationProvider(void) {}

	/**
	 * Called on scene transition exactly before current Form (form to form transition) is changed or show state
	 * (panel to panel transition) is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	sceneId			The scene ID that requires the animator settings
	 * @param[in]	pArgs			A pointer to an argument list
	 * @param[in]	type			The animation type
	 * @param[in]	formTransition	Set to @c true if the transition is form to form transition, @n
	 * 								else @c false if the transition is panel to panel transition (Based on same Form)
	 * @remarks		To show custom scene transition animation, add animator modification code in this callback. @n
	 * 				Animation is initiated by SceneManager after this method is called.
	 * 				The form to form transition animation is triggered by Tizen::Ui::Animations::FrameAnimator::SetCurrentForm(),
	 * 				and the panel to panel transition animation is triggered by Tizen::Ui::Animations::ControlAnimator::SetShowState().
	 *
	 */
	virtual void PrepareAnimation(const Tizen::Ui::Scenes::SceneId& sceneId, Tizen::Base::Collection::IList* pArgs,
								  Tizen::Ui::Scenes::SceneTransitionAnimationType type, bool formTransition) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneAnimationProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneAnimationProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void ISceneAnimationProvider_Reserved3(void) {}

}; // ISceneAnimationProvider
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_ISCENE_ANIMATION_PROVIDER_H_
