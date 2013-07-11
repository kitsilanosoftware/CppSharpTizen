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
 * @file	FUiFocusManager.h
 * @brief	This is the header file for the %FocusManager class.
 *
 * This header file contains the declarations of the %FocusManager class.
 */

#ifndef _FUI_FOCUS_MANAGER_H_
#define _FUI_FOCUS_MANAGER_H_

#include <FBaseObject.h>

namespace Tizen { namespace Ui
{

class Control;
class Window;


/**
 * @class	FocusManager
 * @brief	This class manages the current focus of the application owned by the UI control and its ancestor Window.
 *
 * @since	2.0
 *
 * The %FocusManager class is used to query the application's current focus owner.
 */
class _OSP_EXPORT_ FocusManager
	: public Tizen::Base::Object
{
public:
	/**
     * Gets the pointer to the current focus manager.
	 *
	 * @since	 2.0
	 *
	 * @return The current focus manager instance
	 */
	static FocusManager* GetInstance(void);

	/**
	 * Gets the current focus owner.
	 *
	 * @since		2.0
	 *
	 * @return  The current focus owner
	 * @remarks The method returns the current focus owner of this application.
	 */
	Control* GetCurrentFocusOwner(void) const;

	/**
     * Gets the current focused Window.
     *
     * @since	2.0
     *
	 * @return  The current focused Window
     * @remarks The method returns the application's current focus owner's ancestor Window or the %Window that is currently focused.
	 */
	Window* GetCurrentFocusedWindow(void) const;

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	FocusManager(void);

	//
	// This destructor is intentionally declared as private so that only the platform can delete an instance.
	//
	virtual ~FocusManager(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	FocusManager(const FocusManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	FocusManager& operator=(const FocusManager& rhs);
}; // FocusManager

}} // Tizen::Ui

#endif // _FUI_FOCUS_MANAGER_H_
