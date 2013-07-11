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
 * @file	FUiScenesSceneTransition.h
 * @brief	This is the header file for the %SceneTransition class.
 *
 * This header file contains the declarations of the %SceneTransition class.
 */

#ifndef _FUI_SCENES_SCENE_TRANSITION_H_
#define _FUI_SCENES_SCENE_TRANSITION_H_

#include <FBaseString.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @class	SceneTransition
 * @brief	This class is the %SceneTransition class of a Tizen native application.
 *
 * @since	2.0
 *
 * The %SceneTransition class contains transition information, such as transition direction, transition destination,
 * animation type, history option, and destroy option. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ SceneTransition
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	SceneTransition(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %SceneTransition
	 */
	SceneTransition(const SceneTransition& rhs);

	/**
	 * Initializes this instance of %SceneTransition with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @param[in]	direction			The transition direction
	 * @param[in]	destinationSceneId	The scene ID of transition destination
	 * @param[in]	animationType		The transition animation type
	 * @param[in]	historyOption		The history option whether to add the current scene to the history or not
	 * @param[in]	destroyOption		The destroy option whether to destroy the current scene or not
	 */
	SceneTransition(SceneTransitionDirection direction, const SceneId& destinationSceneId,
					SceneTransitionAnimationType animationType,
					SceneHistoryOption historyOption, SceneDestroyOption destroyOption);

	/**
	 * Assigns the value of the specified instance to the current instance of %SceneTransition.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %SceneTransition
	 */
	SceneTransition& operator =(const SceneTransition& rhs);

	/**
	 * Checks whether the specified instance of %SceneTransition equals the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %SceneTransition
	 * @remarks		The method returns @c false if the specified object is not Scene.
	 */
	virtual bool Equals(const Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~SceneTransition(void);


//	result SetTransitionId(TransitionId& transitionId);

	/**
	 * Sets the scene transition direction.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	direction		The transition direction
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 */
	result SetDirection(SceneTransitionDirection direction);

	/**
	 * Gets the scene transition direction.
	 *
	 * @since	2.0
	 *
	 * @return		The direction of scene transition
	 *
	 */
	SceneTransitionDirection GetDirection(void) const;

	/**
	 * Sets the scene transition destination scene.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId			The scene ID of transition destination
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 */
	result SetDestinationSceneId(const SceneId& sceneId);

	/**
	 * Gets the scene transition destination scene.
	 *
	 * @since	2.0
	 *
	 * @return		The scene ID of transition destination
	 *
	 */
	SceneId GetDestinationSceneId(void) const;

	/**
	 * Sets the scene transition animation type.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	animationType	The transition animation type
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 */
	result SetAnimationType(SceneTransitionAnimationType animationType);

	/**
	 * Gets the scene transition animation type.
	 *
	 * @since	2.0
	 *
	 * @return		The transition animation type
	 *
	 */
	SceneTransitionAnimationType GetAnimationType(void) const;

	/**
	 * Sets the scene transition history option.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	historyOption	The history option whether to add the current scene to the history or not
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 */
	result SetHistoryOption(SceneHistoryOption historyOption);

	/**
	 * Gets the scene transition history option.
	 *
	 * @since	2.0
	 *
	 * @return		The history option
	 *
	 */
	SceneHistoryOption GetHistoryOption(void) const;

	/**
	 * Sets the scene transition destroy option.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	destroyOption	The destroy option whether to destroy the current scene or not
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 */
	result SetDestroyOption(SceneDestroyOption destroyOption);

	/**
	 * Gets the scene transition destroy option.
	 *
	 * @since	2.0
	 *
	 * @return		The destroy option
	 *
	 */
	SceneDestroyOption GetDestroyOption(void) const;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void SceneTransition_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void SceneTransition_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void SceneTransition_Reserved3(void) {}

private:
	friend class _SceneTransitionImpl;
	class _SceneTransitionImpl* __pSceneTransitionImpl;

}; // SceneTransition
} } } // Tizen::Ui::Scenes

#endif // _FUI_SCENES_SCENE_TRANSITION_H_
