//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FShellIShortcutRequestListener.h
 * @brief		This is the header file for the %IShortcutRequestListener interface.
 *
 * This header file contains the declarations of the %IShortcutRequestListener interface.
 */

#ifndef _FSHELL_ISHORTCUT_REQUEST_LISTENER_H_
#define _FSHELL_ISHORTCUT_REQUEST_LISTENER_H_

#include <FBaseString.h>
#include <FAppTypes.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Shell
{

/**
 * @interface	IShortcutRequestListener
 * @brief		This interface defines a listener for the Home application that receives request to add a shortcut.
 *
 * @since	2.1
 *
 * The %IShortcutRequestListener interface defines a listener for the Home application that receives request to add a shortcut.

 * The following example demonstrates how to start the application when the added shortcut is selected by the user.
 * @code
#include <FShell.h>
#include <FApp.h>

using namespace Tizen::Shell;
using namespace Tizen::App;

		if( uriData.IsEmpty() )
		{
			AppManager::GetInstance()->LaunchApplication(appId, null);
		}
		else
		{
	 		AppControlpAc = AppManager::FindAppControlN(App::GetInstance()->GetAppId(), L"http://tizen.org/appcontrol/operation/view");
			if( pAc )
			{
				pAc->Start(*uriData, null, null, null);
				delete pAc;
			}
		}
@endcode
 */
class _OSP_EXPORT_ IShortcutRequestListener
 : virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IShortcutRequestListener(void) {}

	/**
	 * Called when requested to add a shortcut.
	 *
	 * @since	2.1
	 *
	 * @param[in]	appId		The application ID
	 * @param[in]	displayName	The display name of shortcut
	 * @param[in]	iconFilePath	The icon file path
	 * @param[in]	uriData			Uri that will be delivered by IAppControlProviderEventListener::OnAppControlRequestReceived(), when the application is started using a shortcut.
	 *
	 * @remarks		If @c uriData is specified, application should be started by AppControl with %http://tizen.org/appcontrol/operation/view operation, when it is launched from the Home application using a shortcut.
	 *				Or else application should be started by AppControl with default operation (%http://tizen.org/appcontrol/operation/main).
	 *				For more information on the AppControl class, see <a href="../org.tizen.native.appprogramming/html/guide/app/app_controls.htm">Application Controls</a>, and <a href="../org.tizen.native.appprogramming/html/guide/app/delivering_launch_arguments.htm">Delivering Launch Arguments</a>.
	 * @see		ShortcutManager::AddShortcut()
	 */
	virtual void OnShortcutAddRequested(const Tizen::App::AppId& appId, const Tizen::Base::String& displayName, const Tizen::Base::String& iconFilePath, const Tizen::Base::String& uriData) = 0;

	/**
	 * Called when requested to remove a shortcut.
	 *
	 * @since	2.1
	 *
	 * @param[in]	appId		The application ID
	 * @param[in]	displayName	The display name of shortcut
	 * @remarks       If there are more than one shortcuts with duplicated @c appId and @c displayName, all of them should be removed.
	 * @see		ShortcutManager::RemoveShortcut()
	 */
	virtual void OnShortcutRemoveRequested(const Tizen::App::AppId& appId, const Tizen::Base::String& displayName) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IShortcutReqeustListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IShortcutReqeustListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IShortcutReqeustListener_Reserved3(void) {}
};

}} // Tizen::Shell

#endif /* _FSHELL_ISHORTCUT_REQUEST_LISTENER_H_ */
