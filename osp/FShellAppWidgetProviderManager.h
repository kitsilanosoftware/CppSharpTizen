//
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file     FShellAppWidgetProviderManager.h
 * @brief    This is the header file for the %AppWidgetProviderManager class.
 *
 * This header file contains the declarations of the %AppWidgetProviderManager class.
 */

#ifndef _FSHELL_APPWIDGET_PROVIDER_MANAGER_H_
#define _FSHELL_APPWIDGET_PROVIDER_MANAGER_H_

#include <unique_ptr.h>
#include <FBaseString.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base { namespace Collection { class IList; } } }
namespace Tizen { namespace Shell
{

class IAppWidgetProviderFactory;
class IAppWidgetPopupProviderFactory;

/**
 * @class		AppWidgetProviderManager
 * @brief		This class manages all the AppWidget providers.
 *
 * @since	2.1
 *
 * @final		This class is not intended for extension.
 *
 * The %AppWidgetProviderManager class manages all the AppWidget providers.
 * The AppWidget manager manages static and run time AppWidget information.
 */
class _OSP_EXPORT_ AppWidgetProviderManager
	: public Tizen::Base::Object
{
public:

	/**
	 * Gets the AppWidget manager instance.
	 *
	 * @since	2.1
	 *
	 * @feature        %http://tizen.org/feature/shell.appwidget
	 *
	 * @return         A pointer to the %AppWidgetProviderManager instance, @n
	 *				   else @c null if it fails
	 * @exception      E_SUCCESS       The method is successful.
	 * @exception      E_SYSTEM        The method cannot proceed due to a severe system error.
	 * @exception      E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature.
	 *                 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 *
	 * @remarks      
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *			- Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	static AppWidgetProviderManager* GetInstance(void);

	/**
	 * Requests AppWidget service to trigger the specified AppWidget update.
	 *
	 * @since	2.1
	 *
	 * @param[in]	appId			The appId that provides AppWidget
	 * @param[in]	providerName	The name of the AppWidget provider
	 * @param[in]	argument		User information for the AppWidget provider @n
	 * 								This parameter will be delivered as parameter of AppWidgetProvider::OnAppWidgetProviderUpdating().
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_OBJ_NOT_FOUND		The specified AppWidget provider is not found.
	 * @exception	E_CERTIFICATE_VERIFICATION_FAILED	The application is not permitted to request to update AppWidget of other application package. @n
	 * 									To get permission, the target application is signed with the same certificate.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 *
	 * @see			AppWidgetProvider::OnAppWidgetProviderUpdating()
	 */
	result RequestUpdate(const Tizen::App::AppId& appId, const Tizen::Base::String& providerName, const Tizen::Base::String& argument = L"");

	/**
	 * Requests an AppWidget viewer (for example, Home screen, Lock screen) to add the specified AppWidget.
	 *
	 * @since	2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/appwidgetprovider.install
	 *
	 * @param[in]	providerAppId	The ID of the application providing AppWidget
	 * @param[in]	providerName	The name of the AppWidget provider to add
	 * @param[in]	alternateText	Alternate text displayed in the AppWidgetView instance while the AppWidgetProvider instance is initializing or is unavailable
	 * @param[in]	userInfo		User information for the AppWidget provider
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_OBJ_NOT_FOUND	The specified AppWidget provider is not found.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_CERTIFICATE_VERIFICATION_FAILED	The application is not permitted to request to add AppWidget of other application package. @n
	 * 									To get permission, the target application is signed with the same certificate.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified AppWidget provider does not support this operation. @n
	 * 										To request an AppWidget viewer to add an AppWidget, AppWidget provider should support 1x1 size AppWidget, but the specified AppWidget provider does not support 1x1 size.
	 * @exception 	E_CONNECTION_FAILED	The viewer application does not set a listener to receive this request.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks 	Only the AppWidget provider that is packaged with the caller application can be added by this method.
	 * @see		AppWidgetManager::SetAppWidgetRequestListener()
	 */
	result AddAppWidget(const Tizen::App::AppId& providerAppId, const Tizen::Base::String& providerName, const Tizen::Base::String& alternateText, const Tizen::Base::String& userInfo);

	/**
	 * Sets an AppWidgetProvider factory. @n
	 * The factory is called when AppWidgetProvider needs to be created.
	 * The %SetAppWidgetProviderFactory() method should be called in App::OnAppInitializing(), to receive the event correctly.
	 * Implementing AppWidgetProviderFactory is mandatory to provide AppWidget functionality.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	factory		The factory to create concrete AppWidgetProvider
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_OPERATION	The application's attribute does not meet the condition to provide AppWidget.
	 * @exception  E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @see		IAppWidgetProviderFactory
	 */
	result SetAppWidgetProviderFactory(IAppWidgetProviderFactory& factory);

	/**
	 * Sets an AppWidgetPopupProvider factory. @n
	 * The factory is called when AppWidgetPopupProvider needs to be created.
	 * The %SetAppWidgetPopupProviderFactory() method should be called in App::OnAppInitializing(), to receive the event correctly.
	 * Implementing AppWidgetPopupProviderFactory is mandatory to provide AppWidgetPopup functionality.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	factory		The factory to create concrete AppWidgetPopupProvider
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_OPERATION	The application's attribute does not meet the condition to provide AppWidget popup.
	 * @exception  E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @see		IAppWidgetPopupProviderFactory
	 */
	result SetAppWidgetPopupProviderFactory(IAppWidgetPopupProviderFactory& factory);


private:
	//
	// This default constructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	AppWidgetProviderManager(void);

	//
	// This destructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	virtual ~AppWidgetProviderManager(void);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetProviderManager& operator =(const AppWidgetProviderManager& rhs);

	//
	// Constructs the instance of this class.
	//
	// @since	2.1
	//
	// @return	    An error code
	// @exception	E_SUCCESS	The method is successful.
	// @exception	E_SYSTEM	A system error has occurred.
	//
	result Construct(void);


	static void InitSingleton(void);
	static void DestroySingleton(void);

private:
	static AppWidgetProviderManager* __pTheInstance;
	class _AppWidgetProviderManagerImpl* __pAppWidgetProviderManagerImpl;
	friend struct std::default_delete< AppWidgetProviderManager >;
}; // AppWidgetProviderManager

}} // Tizen::Shell

#endif /* _FSHELL_APPWIDGET_PROVIDER_MANAGER_H_ */
