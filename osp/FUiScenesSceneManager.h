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
 * @file	FUiScenesSceneManager.h
 * @brief	This is the header file for the %SceneManager class.
 *
 * This header file contains the declarations of the %SceneManager class.
 */

#ifndef _FUI_SCENES_SCENE_MANAGER_H_
#define _FUI_SCENES_SCENE_MANAGER_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FUiAnimAnimationBase.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Ui { namespace Controls
{
class Form;
class Panel;
}}}
namespace Tizen { namespace Base { namespace Collection
{
class IList;
template<class Type> class IListT;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

class Scene;
class ForwardSceneTransition;
class BackwardSceneTransition;
class IFormFactory;
class IPanelFactory;
class ISceneEventListener;
class ISceneManagerEventListener;
class ISceneAnimationProvider;
class ISceneTransitionPolicyProvider;

/**
 * @class	SceneManager
 * @brief	This class provides methods to manage scenes and scene states.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %SceneManager class provides methods to manage scenes and scene states. This class is simplified to a single method call for UI Scene transition that changes the GUI, such as
 * form to form transition or tab to tab transition. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a> and <a href="../org.tizen.native.appprogramming/html/guide/ui/transition_animation.htm">Transition Animations</a>.
 */
class _OSP_EXPORT_ SceneManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the %SceneManager instance.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the %SceneManager instance if successful, @n
	 *				else @c null if it fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static SceneManager* GetInstance(void);

	/**
	 * Registers a form factory. @n
	 * The IFormFactory::CreateFormN() method is called when a new form is required.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	formFactory			The user-defined form factory instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @see			IFormFactory
	 * @see			IFormFactory::CreateFormN()
	 */
	result RegisterFormFactory(const IFormFactory& formFactory);

	/**
	 * Registers a panel factory. @n
	 * The IPanelFactory::CreatePanelN() method is called when a new panel is required.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	panelFactory		The user-defined panel factory instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @see			IPanelFactory
	 * @see			IPanelFactory::CreatePanelN()
	 */
	result RegisterPanelFactory(const IPanelFactory& panelFactory);

	/**
	 * Registers a scene.
	 * A scene is combination of a form and a panel.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId				The scene ID
	 * @param[in]	formId				The form ID string
	 * @param[in]	panelId				The panel ID string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c sceneId already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result RegisterScene(const SceneId& sceneId, const Tizen::Base::String& formId, const Tizen::Base::String& panelId);

	/**
	 * Registers scene(s) with the specified resource ID.
	 * The %RegisterScene() method does not remove a scene that is already registered.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	resourceId			The resource ID of the scene(s)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_FILE_NOT_FOUND	The corresponding resource file is not found.
	 * @exception	E_OBJ_ALREADY_EXIST	A scene ID already exists.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A duplicated scene (scene ID) will not be registered. Also it throws the E_OBJ_ALREADY_EXIST exception.
	 * @see			UnregisterScene()
	 *
	 */
	result RegisterScene(const Tizen::Base::String& resourceId);

	/**
	 * Unregisters the specified scene.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId				The scene ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c sceneId does not exist.
	 * @see			RegisterScene()
	 */
	result UnregisterScene(const SceneId& sceneId);

	/**
	 * Adds a %SceneManager event listener.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneManagerEventListener	An instance of ISceneManagerEventListener to add
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST			The listener with the specified type is already added.
	 * @see			RemoveSceneManagerEventListener()
	 * @see			ISceneManagerEventListener
	 * @see			ISceneManagerEventListener::OnSceneTransitionCompleted()
	 * @see			ISceneManagerEventListener::OnSceneTransitionStarted()
	 */
	result AddSceneManagerEventListener(ISceneManagerEventListener& sceneManagerEventListener);

	/**
	 * Removes a %SceneManager event listener.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneManagerEventListener	An instance of ISceneManagerEventListener to remove
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OBJ_NOT_FOUND				The specified listener is not found.
	 * @see			AddSceneManagerEventListener()
	 * @see			ISceneManagerEventListener
	 */
	result RemoveSceneManagerEventListener(ISceneManagerEventListener& sceneManagerEventListener);

	/**
	 * Adds a Scene event listener.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId					The target scene ID
	 * @param[in]	sceneEventListener		An instance of ISceneEventListener to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified @c sceneId is invalid.
	 * @exception	E_OBJ_ALREADY_EXIST		The listener with the specified type is already added.
	 * @see			RemoveSceneEventListener()
	 * @see			ISceneEventListener
	 * @see							ISceneEventListener::OnSceneActivatedN()
	 * @see			ISceneEventListener::OnSceneDeactivated()
	 */
	result AddSceneEventListener(const SceneId& sceneId, ISceneEventListener& sceneEventListener);

	/**
	 * Removes a Scene event listener.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId				The target scene ID
	 * @param[in]	sceneEventListener	An instance of ISceneEventListener to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c sceneId is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c sceneId is not found.
	 * @see			AddSceneEventListener()
	 * @see			ISceneEventListener
	 */
	result RemoveSceneEventListener(const SceneId& sceneId, ISceneEventListener& sceneEventListener);

	/**
	 * Sets a Scene animation provider.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId					The target scene ID
	 * @param[in]	pSceneAnimationProvider	An instance of ISceneAnimationProvider to set, @n else @c null to clear previous one
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c sceneId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified scene is not found.
	 * @see			ISceneAnimationProvider
	 */
	result SetSceneAnimationProvider(const SceneId& sceneId, ISceneAnimationProvider* pSceneAnimationProvider);

	/**
	 * Sets a Scene transition policy provider.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	pSceneTransitionPolicyProvider	An instance of ISceneTransitionPolicyProvider to set, @n
	 * 												else @c null to clear previous one
	 * @exception	E_SUCCESS			The method is successful.
	 * @see			ISceneTransitionPolicyProvider
	 * @see			ISceneTransitionPolicyProvider::GetNextScene()
	 * @see			GoForward()
	 */
	result SetSceneTransitionPolicyProvider(ISceneTransitionPolicyProvider* pSceneTransitionPolicyProvider);

	/**
	 * Sets the default values for the individual animation types.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	animationType		The target animation type
	 * @param[in]	duration			The duration of the animation in milliseconds @n The maximum duration is one second.
	 * @param[in]	interpolatorType	The type of interpolator used for the intermediate value calculation of the animation
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @remarks		It throws an E_INVALID_ARG exception if the animationType is SCENE_TRANSITION_ANIMATION_TYPE_NONE
	 * 				or SCENE_TRANSITION_ANIMATION_TYPE_CUSTOM.
	 * @see			GoForward()
	 * @see			GoBackward()
	 */
	result SetFormTransitionAnimationDefaultValues(SceneTransitionAnimationType animationType, long duration,
												   Tizen::Ui::Animations::AnimationInterpolatorType interpolatorType);

	/**
	 * Requests forward scene transition with the specified scene transition.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneTransition		The scene transition that describes the destination and options
	 * @param[in]	pArgs				A pointer to Tizen::Base::Collection::IList that contains the scene transition parameters
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_IN_PROGRESS		A previous transition is in progress.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The destination scene ID is not found in the registered scenes.
	 * @exception	E_INVALID_STATE		The factory instance ( @ref IFormFactory, @ref IPanelFactory ) or
	 * 									ISceneTransitionPolicyProvider is not set.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 * 									(Internal logic or failed to create control from a factory).
	 * @remarks		To use the policy provider operation, SceneTransition's destinationSceneId must be of length 0,
	 * 				also you must register the user-defined ISceneTransitionPolicyProvider and implement the
	 * 				ISceneTransitionPolicyProvider::GetNextScene() callback method.
 	 **/
	result GoForward(const ForwardSceneTransition& sceneTransition, const Tizen::Base::Collection::IList* pArgs = null);

	/**
	 * Requests forward scene transition with the specified transition ID.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	transitionId		The transition ID that describes the destination and options
	 * @param[in]	pArgs				A pointer to Tizen::Base::Collection::IList that contains the scene transition parameters
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_IN_PROGRESS		A previous transition is in progress.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The destination scene ID is not found in the registered scenes.
	 * @exception	E_INVALID_STATE		The factory instance ( @ref IFormFactory, @ref IPanelFactory ) or
	 * 									ISceneTransitionPolicyProvider is not set.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 * 									(Internal logic or failed to create control from a factory).
	 * @remarks		To use the policy provider operation, SceneTransition's destinationSceneId must be of length 0,
	 * 				also you must register the user-defined ISceneTransitionPolicyProvider and implement the
	 * 				ISceneTransitionPolicyProvider::GetNextScene() callback method.
	 **/
	result GoForward(const SceneTransitionId& transitionId, const Tizen::Base::Collection::IList* pArgs = null);

	/**
	 * Requests backward scene transition with the specified scene transition.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneTransition		The scene transition that describes the destination and options
	 * @param[in]	pArgs				A pointer to Tizen::Base::Collection::IList that contains the scene transition parameters
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_IN_PROGRESS		A previous transition is in progress.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The scene ID of the previous scene in the internal history is not found in
	 * 									the current registered scenes.
	 * @exception	E_INVALID_STATE		The factory instance ( @ref IFormFactory, @ref IPanelFactory ) or
	 * 									ISceneTransitionPolicyProvider is not set.
	 * @exception	E_UNDERFLOW			The scene history is empty.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  (Internal logic or failed to create control from a factory).
	 * @remarks		An item removed from the internal history except the E_SYSTEM exception case. @n
	 * 				For non-adjacent backward transition, the current scene and the scenes between the current scene and
	 * 				the requested scene would be destroyed if SCENE_DESTROY_OPTION_KEEP is not specified as destroyOption. @n
	 * 				If the destroy option is selected then the sibling panel scenes (sharing same base form) are also destroyed.
	 */
	result GoBackward(const BackwardSceneTransition& sceneTransition, const Tizen::Base::Collection::IList* pArgs = null);

	/**
	 * Requests backward scene transition with the specified transition ID.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	transitionId		The transition ID that describes the destination and options
	 * @param[in]	pArgs				A pointer to Tizen::Base::Collection::IList that contains the scene transition parameters
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_IN_PROGRESS		A previous transition is in progress.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The scene ID of the previous scene in the internal history is not found in
	 * 									the current registered scenes.
	 * @exception	E_INVALID_STATE		The factory instance ( @ref IFormFactory, @ref IPanelFactory ) or
	 * 									ISceneTransitionPolicyProvider is not set.
	 * @exception	E_UNDERFLOW			The scene history is empty.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 *                                  (Internal logic or failed to create control from a factory).
	 * @remarks		An item removed from the internal history except the E_SYSTEM exception case. @n
	 * 				For non-adjacent backward transition, the current scene and the scenes between the current scene and
	 * 				the requested scene would be destroyed if SCENE_DESTROY_OPTION_KEEP is not specified as destroyOption. @n
	 * 				If the destroy option is selected then the sibling panel scenes (sharing same base form) are also destroyed.
	 */
	result GoBackward(const SceneTransitionId& transitionId, const Tizen::Base::Collection::IList* pArgs = null);

	/**
	 * Gets a pointer to the current Scene instance.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the current Scene instance
	 * @see			GetCurrentSceneId()
	 */
	Scene* GetCurrentScene(void) const;

	/**
	 * Gets the current scene ID string.
	 *
	 * @since	2.0
	 *
	 * @return		The scene ID
	 * @see			GetCurrentScene()
	 */
	SceneId GetCurrentSceneId(void) const;

	/**
	 * Checks whether the Scene instance with the specified sceneId has been destroyed or not.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the scene instance has not been destroyed, @n
	 *              else @c false
	 * @param[in]	sceneId				The scene ID
	 * @remarks		This method is useful to check state of the scene, because the scene lifetime is determined
	 * 				by scene transition option and user can destroy the scene in real time.
	 */
	bool IsSceneAlive(const SceneId& sceneId) const;

	/**
	 * Destroys the specified scene.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId				The scene ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The current scene cannot be destroyed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c sceneId does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result DestroyScene(const SceneId& sceneId);

	/**
	 * Brings the current scene to the topmost to get back the control of scene management.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The current scene is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		If a user sets a form as a current form on a frame by calling Tizen::Ui::Controls::Frame::SetCurrentForm(),
	 * 				they will no longer be under the control of %SceneManager. In this case,
	 * 				they can get back the control of scene management easily by calling this method.
	 * @see			Tizen::Ui::Controls::Frame::SetCurrentForm()
	 */
	result BringCurrentSceneToTop(void);

	/**
	 * Clears the scene history.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @see			AddToSceneHistory()
	 */
	result ClearSceneHistory(void);

	/**
	 * Adds the scene to the scene history.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	sceneId				The scene ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c sceneId is not found in the registered scenes.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			ClearSceneHistory()
	 */
	result AddToSceneHistory(const SceneId& sceneId);

	/**
	 * Gets the scene history list.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the list that contains the scene history
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IListT<SceneId>* GetSceneHistoryN(void) const;

private:
	/**
	 * This default constructor is intentionally declared as private to implement the Singleton semantic.
	 *
	 * @since	2.0
	 */
	SceneManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	SceneManager(const SceneManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	SceneManager& operator =(const SceneManager& rhs);

	/**
	 * This destructor is intentionally declared as private to implement the Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~SceneManager(void);

	/**
	 * Initializes the instance of the this class.
	 *
	 * @since	2.0
	 *
	 * @return		An error code.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 *
	 */
	result Construct(void);

	static void InitSingleton(void);
	static void DestroySingleton(void);

private:
	friend class _SceneManagerImpl;
	class _SceneManagerImpl* __pSceneManagerImpl;
	static SceneManager* __pSceneManagerInstance;

}; // SceneManager
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_SCENE_MANAGER_H_
