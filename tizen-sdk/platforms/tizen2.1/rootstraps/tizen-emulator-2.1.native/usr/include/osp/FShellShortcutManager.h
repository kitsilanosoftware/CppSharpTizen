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
 * @file     FShellShortcutManager.h
 * @brief    This is the header file for the %ShortcutManager class.
 *
 * This header file contains the declarations of the %ShortcutManager class.
 */

#ifndef _FSHELL_SHORTCUT_MANAGER_H_
#define _FSHELL_SHORTCUT_MANAGER_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FAppTypes.h>


namespace Tizen { namespace Shell
{

class IShortcutRequestListener;

/**
 * @class		ShortcutManager
 * @brief		This class helps an application to add its shortcut to the Home app.
 *
 * @since	2.1
 *
 * @final		This class is not intended for extension.
 *
 * The %ShortcutManager class helps an application to add its shortcut to the Home app.
 */
class _OSP_EXPORT_ ShortcutManager
	: public Tizen::Base::Object
{
public:

	/**
	 * Gets the %ShortcutManager instance.
	 *
	 * @since	2.1
	 *
	 * @return	A pointer to the %ShortcutManager instance, @n
	 *			else @c null if it fails
	 * @exception      E_SUCCESS       The method is successful.
	 * @exception      E_OUT_OF_MEMORY                    The memory is insufficient.
	 * @exception      E_SYSTEM                                   The method cannot proceed due to a severe system error.
	 * @remarks        The specific error code can be accessed using the GetLastResult() method.
	 */
	static ShortcutManager* GetInstance(void);

	/**
	 * Adds a shortcut to Home app.
	 *
	 * @since	2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/shortcut.install
	 *
	 * @return	An error code
	 * @param[in]	appId	The application ID
	 * @param[in]	displayName	The display name of shortcut
	 * @param[in]	iconPath	The icon file path
	 * @param[in]	uriData				Uri that will be delivered by Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived(), when the application is started using a shortcut.
	 * @param[in]	allowDuplication	Flag to allow duplicate shortcut
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 *
	 * @remarks		
	 *				- Icon file should be placed in sub directory of 'shared/res' to be used by the Home app.
	 *				For more information on shared directory, see <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/io_overview.htm">I/O Overview</a> 
	 *				and see <a href="../org.tizen.native.appprogramming/html/app_dev_process/manifest_general.htm">General Information</a> for icon file.
	 *				- If @c uriData is specified, application will be started by AppControl with %http://tizen.org/appcontrol/operation/view operation, when it is launched from the Home app using a shortcut.
	 *				Or else application will be started by AppControl with default operation(%http://tizen.org/appcontrol/operation/main).
	 *
	 * @see			Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived()
	 * @see			IShortcutRequestListener::OnShortcutAddRequested()
	 *
	 * The following example demonstrates how to add shortcut.
	 *
	 * @code
	 * #include <FApp.h>
	 * #include <FShell.h>
	 *
	 * using namespace Tizen::App;
	 * using namespace Tizen::Shell;
	 *
	 * String displayName = L"Shortcut to my app";
	 * String iconPath = App::GetInstance()->GetAppSharedPath() + L"res/screen-density-xhigh/mainmenu.png";
	 * String uriData = L"myapp://mydata/myitem";
	 * ShortcutManager::GetInstance()->AddShortcut(App::GetInstance()->GetAppId(), displayName, iconPath , uriData);
	 * @endcode
	 */
	result AddShortcut(const Tizen::App::AppId& appId, const Tizen::Base::String& displayName, const Tizen::Base::String& iconPath, const Tizen::Base::String& uriData, bool allowDuplication = true );

	/**
	 * Removes a shortcut from Home app.
	 *
	 * @since	2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/shortcut
	 *
	 * @return	An error code
	 * @param[in]	appId	The application ID
	 * @param[in]	displayName	The display name of shortcut
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks     If there are more than one shortcuts with duplicated @c appId and @c displayName in the Home app, all of them will be removed.
	 *
	 * @see			IShortcutRequestListener::OnShortcutRemoveRequested()
	 */
	result RemoveShortcut(const Tizen::App::AppId& appId, const Tizen::Base::String& displayName);

	/**
	 * Adds an IShortcutRequestListener to the %ShortcutManager. @n
	 * The listener gets notified when requested to add a shortcut.
	 *
	 * @since	2.1
	 *
	 * @return		An error code
	 * @param[in]	listener				The event listener to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST		The listener is already added.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddShortcutRequestListener(IShortcutRequestListener& listener);

	/**
	 * Removes an IShortcutRequestListener from the %ShortcutManager.
	 *
	 * @since	2.1
	 *
	 * @return		An error code
	 * @param[in]	listener			The event listener to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The listener is not found.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result RemoveShortcutRequestListener(IShortcutRequestListener& listener);

private:
	//
	// This default constructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	ShortcutManager(void);

	//
	// This destructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	virtual ~ShortcutManager(void);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	ShortcutManager& operator =(const ShortcutManager& rhs);

	//
	// Constructs the instance of this class.
	//
	// @since	2.1
	//
	// @return	    An error code
	// @exception	E_SUCCESS	The method is successful.
	// @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	//
	result Construct(void);

	static void InitSingleton(void);
	static void DestroySingleton(void);

private:
	static ShortcutManager* __pTheInstance;
	friend struct std::default_delete< ShortcutManager >;
	class _ShortcutManagerImpl* __pShortcutManagerImpl;
};

}} // Tizen::Shell
#endif /* _FSHELL_SHORTCUT_MANAGER_H_ */
