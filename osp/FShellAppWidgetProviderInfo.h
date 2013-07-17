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
 * @file	FShellAppWidgetProviderInfo.h
 * @brief	This is the header file for the %AppWidgetProviderInfo class.
 *
 * This header file contains the declarations of the %AppWidgetProviderInfo class.
 */

#ifndef _FSHELL_APPWIDGET_PROVIDER_INFO_H_
#define _FSHELL_APPWIDGET_PROVIDER_INFO_H_

#include <FBaseString.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base { namespace Collection { class IList; } } }

namespace Tizen { namespace Shell
{

/**
 * @class		AppWidgetProviderInfo
 * @brief		This class contains static AppWidget information.
 *
 * @since	2.1
 *
 * The %AppWidgetProviderInfo class contains static AppWidget information.
 */
class _OSP_EXPORT_ AppWidgetProviderInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.1
	 *
	 * @param[in]	rhs 	An instance of %AppWidgetProviderInfo
	 */
	AppWidgetProviderInfo(const AppWidgetProviderInfo& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetProviderInfo(void);

	/**
	 * Gets the application ID.
	 *
	 * @since	2.1
	 *
	 * @return	The application ID
	 */
	Tizen::App::AppId GetAppId(void) const;

	/**
	 * Gets the AppWidget provider name.
	 *
	 * @since	2.1
	 *
	 * @return	The provider name
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the display name of an AppWidget. @n
	 * If the system language setting is changed, the %GetDisplayName() method returns the localized application name.
	 * The display name is displayed in applications showing AppWidget such as Launcher, and so on.
	 *
	 * @since	2.1
	 *
	 * @return	The display name of an AppWidget
	 */
	Tizen::Base::String GetDisplayName(void) const;

	/**
	 * Gets the icon path of an application.
	 *
	 * @since	2.1
	 *
	 * @return	The icon path of an application @n
	 * An empty string is returned if there is no value.
	 */
	Tizen::Base::String GetIconPath(void) const;

	/**
	 * Gets the ID of the application that exports AppContorl to configure the AppWidget.
	 *
	 * @since	2.1
	 *
	 * @return	The ID of the application that exports AppContorl to configure the AppWidget @n
	 * An empty string is returned if there is no value.
	 *
	 * The following example demonstrates how to start the application control that is exported for AppWidget configuration.
	 *
	 * @code
	 * #include <FShell.h>
	 *
	 * using namespace Tizen::Shell;
	 *
	 * AppWidgetProviderInfo* pProviderInfo = AppWidgetManager::GetInstance()->GetAppWidgetProviderInfoN(appId, providerName);
	 * if( !pProviderInfo->GetConfigurationAppControlAppId().IsEmpty )
	 * {
	 * 		AppControl* pAc = AppManager::FindAppControlN(pProviderInfo->GetConfigurationAppControlAppId(), L"http://tizen.org/appcontrol/operation/appwidget/configuration");
	 *
	 *		HashMap map();
	 *		map.Construct();
	 *		String key = L"ProviderName";
	 *		String value = pProviderInfo->GetName();
	 *		map.Add(&key, &value );
	 *
	 *		pAc->Start(null, null, &map, null);
	 *		delete pAc;
	 * }
	 * delete pProviderInfo;
	 * @endcode
	 */
	Tizen::Base::String GetConfigurationAppControlAppId(void) const;

	/**
	* Checks whether the specified AppWidget provider is the default provider or not.
	*
	* @since		2.1
	*
	* @return		@c true if the AppWidget is default, @n
	*				else @c false
	*
	* @remarks		
	*				- Default AppWidget provider providing AppWidget that represents application.
	* 				- Home application can show AppWidget instead of icon and text for applications that includes default AppWidget provider.
	*/
	bool IsDefault(void) const;

	/**
	 * Gets a list of AppWidgetSizeInfo of an AppWidget.
	 *
	 * @since	2.1
	 *
	 * @return	A pointer to the array list that contains all AppWidgetSizeInfo of the AppWidgetProvider instance, @n
	 *          else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
    Tizen::Base::Collection::IList* GetSizeInfoListN(void) const;

private:

	//
	// This is the constructor that initializes an instance of %AppWidgetProviderInfo with the specified values.
    // This constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
	// @param[in]	appId			The ID of the application that provides AppWidget
	// @param[in]	name	The name of the AppWidget provider
	//
	AppWidgetProviderInfo(const Tizen::App::AppId& appId, const Tizen::Base::String& name);

	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
    AppWidgetProviderInfo(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	//
	AppWidgetProviderInfo& operator =(const AppWidgetProviderInfo& rhs);


private:
    class _AppWidgetProviderInfoImpl* __pAppWidgetProviderInfoImpl;

friend class _AppWidgetProviderInfoImpl;
};

}} // Tizen::Shell
#endif /* _FSHELL_APPWIDGET_PROVIDER_INFO_H_ */
