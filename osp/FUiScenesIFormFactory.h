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
 * @file	FUiScenesIFormFactory.h
 * @brief	This is the header file for the %IFormFactory interface.
 *
 * This header file contains the declarations of the %IFormFactory interface.
 */

#ifndef _FUI_SCENES_IFORM_FACTORY_H_
#define _FUI_SCENES_IFORM_FACTORY_H_

#include <FBaseString.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Ui { namespace Controls
{
class Form;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @interface	IFormFactory
 * @brief		This interface is the factory interface for creating the Form control instance.
 *
 * @since	2.0
 *
 * The %IFormFactory interface is the factory interface for creating the Form control instance.
 * The SceneManager calls CreateFormN() with form ID string when an instance of %Form control is required.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ IFormFactory
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IFormFactory(void) {}

	/**
	 * Creates a Form instance.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to a new Form instance
	 * @param[in]	formId		The form ID string that specifies the ID of the Form to create
	 * @param[in]	sceneId		The scene ID corresponding to the Form
	 * @remarks		The new instance managed by the SceneManager class must not be deleted manually.
	 */
	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IFormFactory_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IFormFactory_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IFormFactory_Reserved3(void) {}

}; // IFormFactory
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_IFORM_FACTORY_H_
