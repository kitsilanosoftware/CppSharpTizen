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
 * @file	FUiScenesIPanelFactory.h
 * @brief	This is the header file for the %IPanelFactory interface.
 *
 * This header file contains the declarations of the %IPanelFactory interface.
 */

#ifndef _FUI_SCENES_IPANEL_FACTORY_H_
#define _FUI_SCENES_IPANEL_FACTORY_H_

#include <FBaseString.h>
#include <FUiScenesTypes.h>


namespace Tizen { namespace Ui { namespace Controls
{
class Panel;
}}}


namespace Tizen { namespace Ui { namespace Scenes
{

/**
 * @interface	IPanelFactory
 * @brief		This interface is the factory interface for creating the Panel control instance.
 *
 * @since	2.0
 *
 * The %IPanelFactory interface is the factory interface for creating the Panel control instance.
 * The SceneManager class calls CreatePanelN() with panel ID string when an instance of %Panel control is required.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/scene_management.htm">Scene Management</a>.
 */
class _OSP_EXPORT_ IPanelFactory
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IPanelFactory(void) {}

	/**
	 * Creates a Panel instance.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to a new Panel instance
	 * @param[in]	panelId		The panel ID string that specifies the ID of the Panel to create
	 * @param[in]	sceneId		The scene ID corresponding to the Panel
	 * @remarks		The new instance managed by the SceneManager class must not be deleted manually.
	 */
	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IPanelFactory_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IPanelFactory_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IPanelFactory_Reserved3(void) {}

}; // IPanelFactory
} } } // Tizen::Ui::Scenes

#endif  //_FUI_SCENES_IPANEL_FACTORY_H_
