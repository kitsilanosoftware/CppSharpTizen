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
 * @file	FUiScenesScene.h
 * @brief	This is the header file for the %Scene class.
 *
 * This header file contains the declarations of the %Scene class.
 */

#ifndef _FUI_SCENES_SCENE_H_
#define _FUI_SCENES_SCENE_H_

#include <FBaseString.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Ui { namespace Controls
{
class Form;
class Panel;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

class ISceneEventListener;

/**
 * @class	Scene
 * @brief	This class is the %Scene class of a Tizen native applications.
 *
 * @since	2.0
 *
 * The %Scene is the basic unit of UI switching. @n
 * The %Scene class is the item class for scene management. It represents individual UI scene.
 * A scene is combination of form and panel, panel can be omitted.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ Scene
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Scene(void);

	/**
	 * Checks whether the specified instance of %Scene equals the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Scene
	 * @remarks		The method returns @c false if the specified object is not %Scene.
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
	 * Gets the string ID of %Scene.
	 *
	 * @since	2.0
	 *
	 * @return		The name of %Scene
	 * @see			SetSceneId()
	 */
	SceneId GetSceneId(void) const;

	/**
	 * Gets the string ID of Form.
	 *
	 * @since	2.0
	 *
	 * @return		The name of Form
	 */
	Tizen::Base::String GetFormId(void) const;

	/**
	 * Gets the string ID of Panel.
	 *
	 * @since	2.0
	 *
	 * @return		The name of Panel, @n
	 * 				else an empty string if the Panel is not specified
	 */
	Tizen::Base::String GetPanelId(void) const;

	/**
	 * Gets the associated Form instance pointer.
	 *
	 * @since	2.0
	 *
	 * @return		The Form instance pointer
	 * @see			SetForm()
	 */
	Tizen::Ui::Controls::Form* GetForm(void) const;

	/**
	 * Gets the associated Panel instance pointer.
	 *
	 * @since	2.0
	 *
	 * @return		The Panel instance pointer, @n
	 * 				else a @c null pointer if the %Panel is not specified
	 * @remarks		The Panel is optional component of %Scene so it may not be always valid.
	 * @see			SetPanel()
	 */
	Tizen::Ui::Controls::Panel* GetPanel(void) const;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void Scene_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void Scene_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void Scene_Reserved3(void) {}

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @since	2.0
	 */
	Scene(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	Scene(const Scene& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	Scene& operator =(const Scene& rhs);

private:
	friend class _SceneImpl;
	class _SceneImpl* __pSceneImpl;

}; // Scene
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_SCENE_H_
