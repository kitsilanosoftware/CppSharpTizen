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
 * @file     FShellAppWidgetManager.h
 * @brief    This is the header file for the %AppWidgetManager class.
 *
 * This header file contains the declarations of the %AppWidgetManager class.
 */

#ifndef _FSHELL_APPWIDGET_MANAGER_H_
#define _FSHELL_APPWIDGET_MANAGER_H_

#include <unique_ptr.h>
#include <FBaseString.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base { namespace Collection { class IList; } } }
namespace Tizen { namespace Shell
{

class AppWidgetProviderInfo;
class IAppWidgetRequestListener;

/**
 * @class		AppWidgetManager
 * @brief		This class manages static information of all the AppWidgets and provides APIs for AppWidget viewer (such as the Home screen).
 *
 * @since	2.1
 *
 * @final		This class is not intended for extension.
 *
 * The %AppWidgetManager class manages static information of all the AppWidgets and deliveries request to add AppWidget.
 */
class _OSP_EXPORT_ AppWidgetManager
	: public Tizen::Base::Object
{
public:

	/**
	 * Gets the AppWidget manager instance.
	 *
	 * @since	2.1
	 *
	 * @feature        %http://tizen.org/feature/shell.appwidget
	 * @return				A pointer to the %AppWidgetManager instance, @n
	 *						else @c null if it fails
	 * @exception      E_SUCCESS       The method is successful.
	 * @exception      E_SYSTEM        The method cannot proceed due to a severe system error.
	 * @exception      E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @n
	 *                 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks      
	 *					- The specific error code can be accessed using the GetLastResult() method.
	 *					- Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	static AppWidgetManager* GetInstance(void);

	/**
	 * Gets a list of installed AppWidgetProviderInfo.
	 *
	 * @since	2.1
	 *
	 * @return	A pointer to the array list that contains all AppWidgetProviderInfo of installed AppWidgetProvider, @n
	 *          else @c null if an error occurs
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAppWidgetProviderInfoListN(void) const;

	/**
	 * Gets an AppWidgetProviderInfo of the specified AppWidget provider.
	 *
	 * @since	2.1
	 *
	 * @return	A pointer to the AppWidgetProviderInfo instance of the specified AppWidgetProvider, @n
	 * 			else @c null if an error occurs
	 * @param[in]	appId			The ID of the application that provides AppWidget
	 * @param[in]	providerName	The name of the AppWidget provider
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_OBJ_NOT_FOUND		The specified AppWidget provider is not found.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	AppWidgetProviderInfo* GetAppWidgetProviderInfoN(const Tizen::App::AppId& appId, const Tizen::Base::String& providerName) const;

	/**
	 * Gets an AppWidgetProviderInfo of the default AppWidget provider in the package.
	 *
	 * @since	2.1
	 *
	 * @return	A pointer to the AppWidgetProviderInfo instance of the default AppWidgetProvider, @n
	 * 			else @c null if there is no default AppWidget provider or if an error occurs
	 * @param[in]	packageId			The ID of the package that contains the AppWidget provider
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	AppWidgetProviderInfo* GetDefaultAppWidgetProviderInfoN(const Tizen::App::PackageId& packageId) const;

	/**
	 * Sets an AppWidget request listener. @n
	 * The listener gets notified when the request is received. @n
	 * To unset the listener, pass a @c null value to the @c pListener parameter.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	pListener		The pointer to the listener to receive request to add AppWidget
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks	Platform does not have the ownership of this pointer, so caller should manage the listener object properly.
	 * @see		IAppWidgetRequestListener
	 */
	result SetAppWidgetRequestListener(IAppWidgetRequestListener* pListener);

private:
	//
	// This default constructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	AppWidgetManager(void);

	//
	// This destructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	virtual ~AppWidgetManager(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetManager(const AppWidgetManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetManager& operator =(const AppWidgetManager& rhs);

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
	
	static AppWidgetManager* __pTheInstance;
	class _AppWidgetManagerImpl* __pAppWidgetManagerImpl;
	friend struct std::default_delete< AppWidgetManager >;
};

}} // Tizen::Shell
#endif /* _FSHELL_APPWIDGET_MANAGER_H_ */
