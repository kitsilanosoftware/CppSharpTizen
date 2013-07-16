//
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
 * @file	FAppApp.h
 * @brief	This is the header file for the %App class.
 *
 * This header file contains the declarations of the %App class.
 */

#ifndef _FAPP_APP_H_
#define _FAPP_APP_H_

#include <FAppTypes.h>
#include <FSysBattery.h>

extern "C" {
int _OSP_EXPORT_ main(int argc, char* pArgv[]);
};

namespace Tizen { namespace Base { namespace Collection { class IList; } } }

namespace Tizen { namespace App
{

class AppRegistry;
class AppResource;

/**
 * @class	App
 * @brief	This class is the base class of a %Tizen native application.
 *
 * @since	2.0
 *
 * The %App class is the base class of a %Tizen native application.
 * A %Tizen native application must be inherited from the UiApp or ServiceApp class. These classes are inherited from the %App class. This class provides the basic features necessary to define an application.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/app_namespace.htm">App Guide</a>, <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/tizen_app_model/application_lifecycle.htm">Application Life-cycle</a>, and <a href="../org.tizen.native.appprogramming/html/guide/app/app_system_events.htm">System Events</a>.
 *
 */
class _OSP_EXPORT_ App
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~App(void);

	/**
	 * Gets an instance of AppRegistry that manages the application's states and preferences.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the AppRegistry instance, @n
	 *			else @c null if it fails
	 */
	AppRegistry* GetAppRegistry(void) const;

	/**
	* Gets an instance of AppResource that manages the application's resources.
	*
	* @since	2.0
	*
	* @return	A pointer to the AppResource instance, @n
	*		    else @c null if it fails
	*/
	AppResource* GetAppResource(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the list of the launch arguments. @n
	 * For more information on the launch arguments, see <a href="../org.tizen.native.appprogramming/html/guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use IAppControlProviderEventListener
	 * 			to acquire delivered arguments list.
	 * @since	2.0
	 *
	 * @return	A pointer to the list that contains the Tizen::Base::String instances of the launch arguments
	 * @see AppManager::LaunchApplication()
	 * @see AppManager::RegisterAppLaunch()
	 * @see AppManager::StartAppControl()
	 * @see AppControl::Start()
	 * @endif
	 */
	Tizen::Base::Collection::IList* GetAppArgumentListN(void) const;

	/**
	 * Gets the current state of the application.
	 *
	 * @since	2.0
	 *
	 * @return	The current state of the application
	 */
	AppState GetAppState(void) const;

	/**
	 * Gets the locale-independent name of the application.
	 *
	 * @since	2.0
	 * @return	The name of the application
	 */
	Tizen::Base::String GetAppName(void) const;

	/**
	 * @page	CompGetAppNamePage Compatibility for GetAppName()
	 * @section	CompGetAppNamePageIssue Issues
	 * Implementation of this method in %Tizen API versions prior to 2.1 has the following issue: @n
	 *
	 * -# GetAppName() returns the localized name of the application while the meaning of the application name is ambiguous.
	 *  There are different use cases for locale-dependent name and localized name and the platform does not provide
	 *  a method for obtaining language-neutral name.
	 *
	 * @section	CompGetAppNamePageResolution Resolutions
	 * The issue mentioned above is resolved in %Tizen API version 2.1 as follows: @n
	 *
	 * -# GetAppDisplayName() is introduced to acquire localized name and GetAppName() returns locale-independent application name.
	 */

	/**
	 * Gets the display name of the application. @n
	 * If the system language setting is changed, the %GetAppDisplayName() method returns the localized application name.
	 * The display name is displayed in applications like Launcher, Setting, Task Manager, and so on.
	 *
	 * @since	2.0
	 *
	 * @return	The display name of the application
	 */
	Tizen::Base::String GetAppDisplayName(void) const;

	/**
	 * Gets the version of the application.
	 *
	 * @since	2.0
	 *
	 * @return	The version of the application
	 */
	Tizen::Base::String GetAppVersion(void) const;

	/**
	 * Gets the application ID.
	 *
	 * @since	2.0
	 *
	 * @return	The application ID
	 */
	AppId GetAppId(void) const;

	/**
	* Gets the path of the application's root directory where the application is installed.
	*
	* @since	2.0
	*
	* @return	The application's root directory path
	*/
	Tizen::Base::String GetAppRootPath(void) const;

	/**
	* Gets the path of the application's data directory used to store its own private data.
	*
	* @since	2.0
	*
	* @return	The application's data directory path
	*/
	Tizen::Base::String GetAppDataPath(void) const;

	/**
	* Gets the path of the application's resource directory that ships resource files delivered with the application
	* package.
	*
	* @since	2.0
	*
	* @return	The application's resource directory path
	*/
	Tizen::Base::String GetAppResourcePath(void) const;

	/**
	* Gets the path of the application's shared directory to export data to other applications.
	*
	* @since	2.1
	*
	* @return	The application's shared directory path
	*/
	Tizen::Base::String GetAppSharedPath(void) const;

	/**
	 * Terminates the application while it is running. @n
	 * The OnAppTerminating() method is called after the %Terminate() method is executed successfully.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE     This instance is in an invalid state.
	 */
	result Terminate(void);

	/**
	 * Called when the application's state changes to App::INITIALIZING. @n
	 * In general, most of the activities involved in initializing the application,
	 * including restoring the application's states, must be done in the %OnAppInitializing() method.
	 * If this method fails, the application's state changes to App::TERMINATED.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the method is successful, @n
	 *		else @c false
	 * @param[in]	appRegistry        The instance of AppRegistry that manages the application's states
	 * @remarks	Introducing the modal dialogs (for example, MessageBox) in this method is not allowed,
	 * because it blocks the initialization procedure.
	 */
	virtual bool OnAppInitializing(AppRegistry& appRegistry) = 0;

	/**
	 * Called when the application's initialization is finished. @n
	 * After the %OnAppInitialized() method succeeds, the application's state changes to App::RUNNING.
	 * If this method fails, the application's state changes to App::TERMINATING and the App::OnAppTerminating() method is called.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the method is successful, @n
	 *			else @c false
	 */
	virtual bool OnAppInitialized(void);

	/**
	 * Called when the application is requested to terminate. @n
	 * The %OnAppWillTerminate() method returns @c false to prevent the application from getting terminated.
	 * If this method returns @c true, the application's state changes to App::TERMINATING and the App::OnAppTerminating() method is called.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the method is successful, @n
	 *			else @c false
	 */
	virtual bool OnAppWillTerminate(void);

	/**
	 * Called when the application's state changes to App::TERMINATING. @n
	 * All the activities involved in terminating the application, including saving the application's states, must be done in the %OnAppTerminating() method.
	 * After this method, the application code cannot be executed. The application is destroyed subsequently. @n
	 *
	 * An application can be terminated by either system, such as power-off and OOM, or others, such as self and other applications. @n
	 * When the termination by system, called an “urgent termination”, occurs, the method, %OnAppTerminating(), cannot be executed properly.
	 * For more details, while power-off, even if %OnAppTerminating() is called, it has a short time for executing. If the application is killed by OOM, %OnAppTerminating() is not called. @n
	 * Because %OnAppTerminating() is not likely to be called due to urgent termination, the application should save the critical data as they can do.
	 * For example, the application can set the check point or use the callback for low memory. @n
	 * When the termination by self or other applications, called a “normal termination”, occurs, the method, %OnAppTerminating(), can be executed properly.
	 * It provides more time for executing than urgent termination, but limits to the time to 3 or 5 seconds. @n
	 * The main loop is already quitted when %OnAppTerminating() is called.
	 * Thus, the application should not use a kind of asynchronous API of which the callback is triggered by the main loop.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the method is successful, @n
	 *			else @c false
	 * @param[in]	appRegistry         The instance that manages the application's states
	 * @param[in]	urgentTermination   Set to @c true if the application is terminated by the system, @n
	 *									else @c false
	 */
	virtual bool OnAppTerminating(AppRegistry& appRegistry, bool urgentTermination = false) = 0;

	/**
	 * Called when the system detects that the system wide memory or application heap memory is insufficient to run the application any further. @n
	 * Resources that are not in use currently can be released using the %OnLowMemory() method.
	 *
	 * @since	2.0
	 */
	virtual void OnLowMemory(void);

	/**
	 * Called when the battery level changes. @n
	 * It is recommended that the application consuming more battery power must be terminated if the battery level is Tizen::System::BATTERY_LEVEL_CRITICAL.
	 *
	 * @since	2.0
	 *
	 * @param[in]	batteryLevel    The device's current battery level
	 */
	virtual void OnBatteryLevelChanged(Tizen::System::BatteryLevel batteryLevel);

	/**
	* Sends the user event to the application itself and not to another application.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	requestId   The user defined event ID
	* @param[in]	pArgs       A pointer to an argument list of type Tizen::Base::String
	* @exception	E_SUCCESS   The method is successful.
	* @see			OnUserEventReceivedN()
	*/
	result SendUserEvent(RequestId requestId, const Tizen::Base::Collection::IList* pArgs);

	/**
	* Called asynchronously when the user event is sent by the SendUserEvent() method. @n
	* The request ID and argument format for the user event can be defined as per the requirement.
	*
	* @since	2.0
	*
	* @param[in]	requestId   The user defined event ID
	* @param[in]	pArgs       A pointer to an argument list of type Tizen::Base::String
	*/
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

	/**
	* Gets the %App instance's pointer.
	*
	* @since	2.0
	*
	* @return	A pointer to the %App instance, @n
	*			else @c null if it fails
	*/
	static App* GetInstance(void);

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	App(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void App_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void App_Reserved2(void) {}

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	App(const App& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	App& operator =(const App& rhs);

private:
	class _AppImpl* __pAppImpl;
}; // App

}} // Tizen::App

#endif // _FAPP_APP_H_
