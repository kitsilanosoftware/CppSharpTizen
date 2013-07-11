//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FAppUiApp.h
 * @brief	This is the header file for the %UiApp class.
 *
 * This header file contains the declarations of the %UiApp class.
 */

#ifndef _FAPP_UI_APP_H_
#define _FAPP_UI_APP_H_

#include <FAppApp.h>

namespace Tizen { namespace Base { namespace Collection { class IList; } } }
namespace Tizen { namespace Ui { namespace Controls { class Frame; } } }

namespace Tizen { namespace App
{

class UiApp;
class IAppFrame;

typedef UiApp* (*UiAppInstanceFactory)(void);

/**
 * @class	UiApp
 * @brief	This class is the base class of a %Tizen native UI application.
 *
 * @since	2.0
 *
 * The %UiApp class is the base class of a %Tizen native UI application.
 * A %Tizen native UI application must inherit from the %UiApp class. This class provides the basic features necessary to define the
 * Tizen native UI application.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/app_namespace.htm">App Guide</a> and <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/tizen_app_model/application_model.htm">Native Application Model</a>.
 *
 */
class _OSP_EXPORT_ UiApp
	: public Tizen::App::App
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~UiApp(void);

	/**
	 * Gets the first frame in the frame list of the UI application.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the IAppFrame interface of the frame, @n
	 *			else @c null if it fails
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	The frame has not been properly initialized.
	 * @exception	E_OBJ_NOT_FOUND	Frame is not found.
	 */
	IAppFrame* GetAppFrame(void) const;

	/**
	 * Adds the frame to the end of the list that is maintained by the UI application.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	frame               The frame that is added to the UI application
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE     The application is in an invalid state.
	 * @exception	E_OBJ_ALREADY_EXIST The frame to be added is already registered with the UI application.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED      The number of frames has exceeded the maximum limit.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result AddFrame(const Tizen::Ui::Controls::Frame& frame);

	/**
	 * Removes the specified @c frame from the UI application.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	frame           The frame to remove
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OBJ_NOT_FOUND The specified @c frame cannot be found.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	The removed frame is deleted from the memory.
	 */
	result RemoveFrame(const Tizen::Ui::Controls::Frame& frame);

	/**
	 * Gets the list of the frames of the UI application.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to Tizen::Base::Collection::IList that contains Tizen::Ui::Frame instances, @n
	 *			else @c null if it fails
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE     The application is in an invalid state.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetFrameList(void) const;

	/**
	 * Gets the frame with the specified @c name.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the frame having the specified @c name, @n
	 *			else @c null if it fails
	 * @param[in]	name                The name of the frame
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_OBJ_NOT_FOUND     The specified @c frame cannot be found.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Ui::Controls::Frame* GetFrame(const Tizen::Base::String& name) const;

	/**
	 * Gets the frame at the specified @c index of the list.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the frame at the specified @c index, @n
	 *			else @c null if it fails
	 * @param[in]	index               The index of the frame
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_OUT_OF_RANGE      The specified @c index is outside the bounds of the frame list.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Ui::Controls::Frame* GetFrameAt(int index) const;

/**
	 * Gets the UI state of the UI application.
	 *
	 * @since	2.0
	 *
	 * @return	The UI state of the UI application
	 * @remarks	Note that UiApp::OnBackground() is invoked when the UI state of a UI application changes
	 *          from App::APP_UI_STATE_FOREGROUND to App::APP_UI_STATE_PARTIAL_BACKGROUND or App::APP_UI_STATE_BACKGROUND.
	 * @see		AppUiState
	 */
	AppUiState GetAppUiState(void) const;

	/**
	 * Called when a UI application moves to the foreground. @n
	 * User interaction is enabled when the UI application moves to the foreground. @n
	 * A UI application moves to the foreground when:
	 *
	 * - A UI application is selected from the Task Manager.
	 * - A UI application icon in the Launcher application is pressed when it is running in the background.
	 * - A UI application is to be launched while it is running in the background.
	 * - A system pop-up, such as an incoming call, notification (for example, SMS), or a low battery warning
	 *    pop-up disappears.
	 *
	 * %OnForeground() is called when the UI application is moved to the foreground. @n
	 * When this method is invoked, the following actions are recommended:
	 *
	 * - Resume the graphic processing, such as 3D or animation, as the UI application now has the focus.
	 * - Resume the operations that stopped when the UI application is last moved to the background.
	 *
	 * @since	2.0
	 *
	 * @remarks      When the system needs to refresh a screen component, it can call this method even if the UI application is present in the foreground.
	 */
	virtual void OnForeground(void);

	/**
	 * Called when another UI application moves to the top or a system pop-up is displayed. @n
	 * User interaction is disabled when the UI application is in the background. @n
	 * A UI application moves to the background when:
	 *
	 * - A system pop-up, such as an incoming call or a low battery warning pop-up is displayed.
	 * - A device is locked.
	 * - The Home key is pressed.
	 *
	 * %OnBackground() is called when the UI application is moved to the background. @n
	 * Whenever this method is invoked, the following actions are recommended:
	 *
	 * - Stop the graphic processing, such as 3D or animation, as they will not be displayed.
	 * - Release unnecessary resources.
	 * - Stop media processing, sensor manipulations, and location updates.
	 *
	 * @since	2.0
	 *
	 * @remarks	When notification (for example, SMS) pops up, this method is not called.
	 *			When a system pop-up is displayed, a UI application becomes partially hidden
	 *			(App::APP_UI_STATE_PARTIAL_BACKGROUND).
	 *			If a UI application is partially hidden, it is recommended to hold the activated
	 *			tasks or resources instead of stopping or releasing them.
	 * @see GetAppUiState()
	 */
	virtual void OnBackground(void);

	/**
	* Gets the %UiApp instance's pointer.
	*
	* @since	2.0
	*
	* @return	A pointer to the %UiApp instance, @n
	*			else @c null if it fails
	*/
	static UiApp* GetInstance(void);

	/**
	 * Executes an application implemented by inheriting this class.
	 * The %Execute() method must be called from the entry method - OspMain(), which is generated by IDE.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pUiAppFactory         The factory method that creates this UiApp's instance
	 * @param[in]	pArguments           The launch arguments for %App
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_INIT_FAILED       The initialization failure during OnAppInitializing().
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	static result Execute(UiAppInstanceFactory pUiAppFactory, const Tizen::Base::Collection::IList* pArguments);

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	UiApp(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The following methods are reserved and the name of the methods can be changed at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void UiApp_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The following methods are reserved and the name of the methods can be changed at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void UiApp_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The following methods are reserved and the name of the methods can be changed at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void UiApp_Reserved3(void) {}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	UiApp(const UiApp& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	UiApp& operator =(const UiApp& rhs);

private:
	class _UiAppImpl* __pUiAppImpl;
}; // UiApp

typedef UiApp Application;

} } //Tizen::App

#endif // _FAPP_UI_APP_H_
