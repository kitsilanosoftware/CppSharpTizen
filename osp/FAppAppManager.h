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
 * @file	FAppAppManager.h
 * @brief	This is the header file for the %AppManager class.
 *
 * This header file contains the declarations of the %AppManager class.
 */

#ifndef _FAPP_APP_MANAGER_H_
#define _FAPP_APP_MANAGER_H_

#include <FBaseObject.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base {
class ByteBuffer;
namespace Collection {
class IList;
class IMap;
}
}}

namespace Tizen { namespace App
{

class IAppControlEventListener;
class IAppControlListener;
class IAppControlResponseListener;
class IAppCheckpointEventListener;
class IAppLaunchConditionEventListener;
class IActiveAppEventListener;
class AppControl;
class SqlDataControl;
class MapDataControl;

/**
 * @class		AppManager
 * @brief		This class manages all the applications.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %AppManager class manages all the applications.
 * The application manager supports normal and conditional application launch, and application control search and launch.
 * It looks up the specific application control from the application control registry and creates an application control instance.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>, <a href="../org.tizen.native.appprogramming/html/guide/app/registering_launch_condition.htm">Registering a Launch Condition</a>, and <a href="../org.tizen.native.appprogramming/html/guide/app/app_controls.htm">Application Controls</a>.
 */
class _OSP_EXPORT_ AppManager
	: public Tizen::Base::Object
{
public:
	/**
	 * @enum LaunchOption
	 *
	 * Defines the launch options.
	 *
	 * @since	2.0
	 */
	enum LaunchOption
	{
		LAUNCH_OPTION_DEFAULT   /**< The launch option: default */
	};

	/**
	 * Finds the application control that the caller wants to start. @n
	 * It resolves the matched application control with the delivered application ID and operation ID.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the newly created AppControl instance if a matched %AppControl is found, @n
	 *			else @c null
	 * @param[in]	appId			The application ID
	 * @param[in]	operationId		The operation ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The application control is not found.
	 * @exception	E_SYSTEM		A system error has occurred. @n
	 * 								Either the file operation or the DB operation has failed.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	%Tizen platform defines platform-defined alias for application ID and this aliased application ID
	 * 			can be used to find the AppControl. For more information, see
	 * 			<a href="../org.tizen.native.appprogramming/html/guide/app/app_controls.htm">here</a>.
	 *
	 * The following example demonstrates how to use the %FindAppControlN() method to find the application control.
	 *
	 * @code
	 * ArrayList dataList(SingleObjectDeleter);
	 * dataList.Construct();
	 * dataList.Add(new String(L"tel:1234567900"));
	 * dataList.Add(new String(L"type:voice"));
	 *
	 * AppControl* pAc = AppManager::FindAppControlN(L"tizen.phone", L"http://tizen.org/appcontrol/operation/call");
	 * pAc->Start(&dataList, null);
	 * @endcode
	 */
	static AppControl* FindAppControlN(const AppId& appId, const Tizen::Base::String& operationId);

	/**
	 * Finds a list of AppControl instances that matches the specified operation ID, category,
	 * data type, and URI pattern.
	 *
	 * @since		2.0
	 *
	 * @return	A pointer to the list of the AppControl instances that matches the specified operation ID, category, URI, and data type, @n
	 *          else @c null if it fails
	 * @param[in]	pOperationId	The operation ID
	 * @param[in]	pCategory			The application category
	 * @param[in]	pDataType	The MIME type (RFC 2046) or file extension @n
	 *                          The '.' prefix must be used when specifying the file extension.
	 * @param[in]	pUriPattern			The URI pattern
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		At least one of the specified @c pOperationId, @c pCategory, @c pDataType, or @c pUriScheme must not be @c null.
	 * @exception	E_INVALID_FORMAT	The specified URI scheme is invalid (RFC 2396).
	 * @exception	E_UNSUPPORTED_FORMAT	The specified file extension for @c pDataType is not supported.
	 * @exception	E_OBJ_NOT_FOUND		The application control is not found.
	 * @exception	E_SYSTEM		A system error has occurred. @n
	 * 								Either the file operation or the DB operation has failed.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	For the delivered launch arguments, see App::GetAppArgumentListN().
	 */
	static Tizen::Base::Collection::IList* FindAppControlsN(const Tizen::Base::String* pOperationId, const Tizen::Base::String* pCategory, const Tizen::Base::String* pDataType, const Tizen::Base::String* pUriPattern);

	/**
         * @if OSPDEPREC
	 * Starts the application control if there is only one application control that matches the specified URI, operation ID, and data type. @n
	 * If there are more than one application controls, the one that the user selects is started.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because IAppControlListener is deprecated and replaced by IAppControlResponselistener.
	 * 				Instead of using this method, use AppControl::FindAndStart().
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return	An error code
	 * @param[in]	uriData			The URI that has a maximum size of @c 1024 bytes
	 * @param[in]	pOperationId	The operation ID
	 * @param[in]	pDataType	The MIME type (RFC 2046) or file extension @n
	 *                          The '.' prefix must be used for the @c dataType when specifying the file extension.
	 * @param[in]	pListener	A listener that gets notified when the resolved application control has started
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_MAX_EXCEEDED		The size of @c uri has exceeded the maximum limit.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified file extension for @c pDataType is not supported.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The application control is not found.
	 * @exception	E_IN_PROGRESS		The target application control is in progress.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 *
	 * @see	App::GetAppArgumentListN()
	 * @see	FindAppControlN()
	 * @see	FindAppControlsN()
	 * @see	AppControl::Start()
	 *
	 * The following example demonstrates how to use the %StartAppControl() method.
	 * @code
	 * String operationId = L"http://tizen.org/appcontrol/operation/call";
	 * StartAppControl(L"tel:1234567890", &operationId, null, null);
	 * @endcode
         * @endif
	 */
	static result StartAppControl(const Tizen::Base::String& uriData, const Tizen::Base::String* pOperationId, const Tizen::Base::String* pDataType, IAppControlListener* pListener);

	/**
	 * @if OSPDEPREC
	 * Starts the application control if there is only one application control that matches the specified operation ID, category, URI, and data type. @n
	 * If there are more than one application controls, the one that the user selects is started.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because IAppControlListener is deprecated and replaced by IAppControlResponselistener.
	 * 				Instead of using this method, use AppControl::FindAndStart().
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return	An error code
	 * @param[in]	pOperationId	The operation ID
	 * @param[in]	pCategory			The application control category
	 * @param[in]	pDataType	The MIME type (RFC 2046) or file extension @n
	 *                          The '.' prefix must be used when specifying the file extension.
	 * @param[in]	pUriPattern			A URI pattern which is used for application control resolution and delivered as the argument
	 * @param[in]	pDataList	The data list that is delivered to the resolved application control @n
	 *                       It has a maximum size of @c 1024 bytes.
	 * @param[in]	pListener	A listener that gets notified when the resolved application control has started
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		At least one of the specified @c pOperationId, @c pCategory, @c pDataType, or @c pUri must not be @c null.
	 * @exception	E_MAX_EXCEEDED		The size of @c pDataList has exceeded the maximum limit.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified file extension for @c pDataType is not supported.
	 * @exception	E_OBJ_NOT_FOUND		The application control is not found.
	 * @exception	E_IN_PROGRESS		The target application control is in progress.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		For delivered launch arguments, see App::GetAppArgumentListN().
	 * @see	App::GetAppArgumentListN()
	 * @see	FindAppControlsN()
	 * @see	AppControl::Start()
	 * @endif
	 */
	static result StartAppControl(const Tizen::Base::String* pOperationId, const Tizen::Base::String* pCategory, const Tizen::Base::String* pDataType, const Tizen::Base::String* pUriPattern, const Tizen::Base::Collection::IList* pDataList, IAppControlListener* pListener);

	/**
	 * Gets the SQL-type data control that the caller wants to use. @n
	 * It resolves the matching data control with the specified data control provider ID.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the SqlDataControl instance if a matching data control is found, @n
	 *				else @c null
	 * @param[in]	providerId			The provider ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The data control specified with the @c providerId is not found.
	 * @exception	E_ILLEGAL_ACCESS	The access is denied due to insufficient permission.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static SqlDataControl* GetSqlDataControlN(const Tizen::Base::String& providerId);

	/**
	 * Gets the MAP-type data control that the caller wants to use. @n
	 * It resolves the matching data control with the specified data control provider ID.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the MapDataControl instance if a matching data control is found, @n
	 *				else @c null
	 * @param[in]	providerId			The provider ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The data control specified with the @c providerId is not found.
	 * @exception	E_ILLEGAL_ACCESS	The access is denied due to insufficient permission.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static MapDataControl* GetMapDataControlN(const Tizen::Base::String& providerId);

	/**
	* Gets the path of the read-only shared directory exported by an other application specified with an application ID.
	*
	* @since	2.0
	*
	* @return		The other application's shared directory path, @n
	*				else an empty string if an exception occurs
	* @param[in]	appId				The application ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_APP_NOT_INSTALLED	The expected shared directory cannot be found
	*									because the application specified with @c appId cannot be installed.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static Tizen::Base::String GetAppSharedPath(const AppId& appId);

	/**
	 * Gets the application manager instance.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the %AppManager instance, @n
	 *			else @c null if it fails
	 */
	static AppManager* GetInstance(void);

	/**
	 * @if OSPDEPREC
	 * Launches the default application with given @c appId. @n
	 * The launch arguments are given as App::OnUserEventReceivedN() or can be obtained by
	 * invoking App::GetAppArgumentListN(), especially within App::OnAppInitializing().
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because sending argument with %LaunchApplication() is not recommended. @n
	 * 				Instead of using this method, use %LaunchApplication() without launch arguments or AppControl::Start().
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return	An error code
	 * @param[in]	appId				The application's ID to execute
	 * @param[in]	pArguments			A pointer to the list of string arguments that has a maximum size of @c 1024 bytes
	 * @param[in]	option				The launch option (currently only AppManager::LAUNCH_OPTION_DEFAULT is available)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_INVALID_ARG		The specified @c appId is empty.
	 * @exception	E_OBJ_NOT_FOUND		The target application is not installed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED		The size of @c appId or @c pArguments has exceeded the maximum limit.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result LaunchApplication(const AppId& appId, const Tizen::Base::Collection::IList* pArguments, LaunchOption option = LAUNCH_OPTION_DEFAULT);

	/**
	 * Launches the default application with given @c appId.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return	An error code
	 * @param[in]	appId				The application's ID to execute
	 * @param[in]	option				The launch option (currently only AppManager::LAUNCH_OPTION_DEFAULT is available)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_APP_NOT_INSTALLED	The target application is not installed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result LaunchApplication(const AppId& appId, LaunchOption option = LAUNCH_OPTION_DEFAULT);

	/**
	 * Checks whether an application is running.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the application is running, @n
	 *           else @c false
	 * @param[in]	appId               The installed application ID
	 */
	bool IsRunning(const AppId& appId) const;

	/**
	 * Gets a list of running applications at the time of invocation.
	 *
	 * @since      2.0
	 *
	 * @return	A pointer to the running state application list (AppId), @n
	 *                   else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetRunningAppListN(void) const;

	/**
	 * Registers an application with a specific condition and launches it if the condition is met. @n
	 * If the requested application is already running, the application is notified through IAppLaunchConditionEventListener::OnAppLaunchConditionMetN().
	 * The launch arguments are given as input parameters to %IAppLaunchConditionEventListener::OnAppLaunchConditionMetN().
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return		An error code
	 * @param[in]	condition	  The launch condition for the application @n
	 *							  The condition has L"Key='value'" format and is case sensitive. To use single or double quotes in the condition values, prefix them with a slash (\' or \"). @n
	 *							  For more information on the condition formats, see <a href="../org.tizen.native.appprogramming/html/guide/app/registering_launch_condition.htm">Registering a Launch Condition</a>.
	 *                            <table><tr><th>Condition Format</th><th>Meaning</th></tr>
	                              <tr><td>L"DateTime='mm/dd/yyyy hh:mm:ss'"</td>
	                              <td>The specified condition is the local due time.</td></tr>
	                              <tr><td>L"DueTime='mm/dd/yyyy hh:mm:ss' LaunchPeriod='mm'"</td>
	                              <td>The specific condition is the time period after due time.</td></tr>
	                              <tr><td>L"Serial='command'"</td><td>The specified condition is a serial
	                              communication input command.</td></tr>
	                              <tr><td>L"NFC='command'"</td><td>The specified condition is a Near Field Communication (NFC) tag that has the NFC Data Exchange Format (NDEF) data.
	                              </td></tr></table> @n

	 *
	 * @param[in]	pArguments	  A list of string arguments that has a maximum size of @c 1024 bytes @n
	 *							  The parameter can also contain @c null. @n
	 *						      For more information on the arguments, see <a href="../org.tizen.native.appprogramming/html/guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>.
	 * @param[in]	option         The launch option (currently only AppManager::LAUNCH_OPTION_DEFAULT is available)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The launch condition is empty or too long (Maximum 400 bytes).
	 * @exception	E_INVALID_FORMAT		The specified condition format is invalid.
	 * @exception	E_INVALID_CONDITION  The specified condition format is valid but the condition has at least one or more invalid values.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c condition is already registered by a different application.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED		The size of @c pArguments has exceeded the maximum limit.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		When the registered application is about to be launched, the registered launch condition and arguments are given as parameters to IAppLaunchConditionEventListener::OnAppLaunchConditionMetN().
	 * @remarks		The newly introduced launch condition does not work on the previous SDK version and the E_INVALID_CONDITION exception is returned.
	 * @remarks		Registering the same launch condition overwrites the previous launch argument without throwing an exception.
	 * @remarks		The launch period requires more consideration because an inappropriate short period value may lead
	 *				to an adverse effect on the device battery.
	 * @remarks		For the NFC launch condition, the detected NDEF message can be acquired using the @c pExtraData parameter of %IAppLaunchConditionEventListener::OnAppLaunchConditionMetN() method.
	 * @see			UnregisterAppLaunch()
	 * @see			IsAppLaunchRegistered()
	 * @see			LaunchApplication()
	 * @see			Tizen::Base::DateTime::ToString()
	 * @see			Tizen::Io::SerialPort
	 *
	 * The following example demonstrates how to use the %RegisterAppLaunch() method.
	 *
	 * @code
	 *
	 *  DateTime time;
	 *  SystemTime::GetCurrentTime(TIME_MODE_WALL, time);
	 *  time.AddMinutes(1);
	 *
	 *  String cond;
	 *  cond.Format(70, L"DueTime='%S' LaunchPeriod='60'", time.ToString().GetPointer());
	 *
	 *  // Registers a periodic condition that fires every 60 minutes starting after one minute
	 *  AppManager::GetInstance()->RegisterAppLaunch(cond, null, AppManager::LAUNCH_OPTION_DEFAULT)
	 *
	 * @endcode
	 */
	result RegisterAppLaunch(const Tizen::Base::String& condition, const Tizen::Base::Collection::IList* pArguments, LaunchOption option);

	/**
	 * Unregisters the previously registered launch condition.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		E_SUCCESS			An error occurs when there is no registered launch condition.
	 * @see			RegisterAppLaunch()
	 * @see			IsAppLaunchRegistered()
	 */
	result UnregisterAppLaunch(void);

	/**
	 * Unregisters the specified launch condition.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return		An error code
	 * @param[in]	condition			The launch condition for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified launch condition is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see			RegisterAppLaunch()
	 * @see			IsAppLaunchRegistered()
	 */
	result UnregisterAppLaunch(const Tizen::Base::String& condition);

	/**
	 * Checks whether a launch condition is registered for the application.
	 *
	 * @since	2.0
	 *
	 * @return     @c true if a condition is already registered to the application invoking this method, @n
	 *             else @c false
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_SYSTEM				A system error has occurred.
	 *
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         RegisterAppLaunch()
	 * @see         UnregisterAppLaunch()
	 */
	bool IsAppLaunchRegistered(void) const;

	/**
	 * Sets a checkpoint event listener. @n
	 * The listener gets notified when a checkpoint event is fired.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener		The listener to receive the checkpoint event
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_OBJ_ALREADY_EXIST	The listener is already set.
	 * @exception  E_SYSTEM		A system error has occurred.
	 * @see		IAppCheckpointEventListener
	 *
	 */
	result SetCheckpointEventListener(IAppCheckpointEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Sends the result list for the application control request. @n
	 * The client can get the result list by implementing IAppControlEventListener::OnAppControlCompleted().
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because a new method has been added. @n
	 *			Instead of using this method, use AppControlProviderManager::SendAppControlResult().
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	appControlRequestId	The application control request ID @n
	 *                          The application control request ID is given as an argument for
	 *                          App::GetAppArgumentListN() or App::OnUserEventReceivedN().
	 * @param[in]	pResultList	The list of the result strings of the application control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The application control request is not found.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @see	IAppControlEventListener
	 * @endif
	 */
	static result SendAppControlResult(const Tizen::Base::String& appControlRequestId, const Tizen::Base::Collection::IList* pResultList);

	/**
     * Sets an IAppLaunchConditionEventListener to the %AppManager. @n
     * The listener gets notified when the application is launched by the registered condition.
     *
     * @since	2.0
	 *
     * @param[in]  pListener      The event listener @n
     *                            To unset the listener, pass a @c null value to the listener parameter.
     * @remarks    If the application is newly launched by the condition, then %SetAppLaunchConditionEventListener() must
     *             be set within App::OnAppInitializing().
     *             If the application does not set the listener using %SetAppLaunchConditionEventListener(),
     *             then the application is launched without invoking any listener for the condition.
     * @see RegisterAppLaunch()
     */
	void SetAppLaunchConditionEventListener(IAppLaunchConditionEventListener* pListener);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	AppManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppManager(const AppManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppManager& operator =(const AppManager& rhs);

	/**
	 * Constructs the instance of this class.
	 *
	 * @since	2.0
	 *
	 * @return	    An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * This destructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~AppManager(void);

private:
	class _AppManagerImpl* __pAppManagerImpl;

	friend class _AppManagerImpl;
}; // AppManager

}} // Tizen::App

#endif // _FAPP_APP_MANAGER_H_

