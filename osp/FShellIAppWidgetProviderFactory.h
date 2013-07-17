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
 * @file		FShellIAppWidgetProviderFactory.h
 * @brief		This is the header file for the %IAppWidgetProviderFactory interface.
 *
 * This header file contains the declarations of the %IAppWidgetProviderFactory interface.
 */

#ifndef _FSHELL_IAPPWIDGET_PROVIDER_FACTORY_H_
#define _FSHELL_IAPPWIDGET_PROVIDER_FACTORY_H_

#include <FBaseString.h>

namespace Tizen { namespace Shell
{

class AppWidgetProvider;

/**
 *   @interface  IAppWidgetProviderFactory
 *   @brief      This interface defines the factory for the AppWidgetProvider creation.
 *
 *   @since	2.1
 *
 * The %IAppWidgetProviderFactory interface defines a factory for the AppWidgetProvider creation.
 * The AppWidgetManager instance calls CreateInstance() when an instance of %AppWidgetProvider is required.
 * Applications that provide the %AppWidgetProvider functionality must implement this interface.
 *
 * @see AppWidgetManager
 */
class _OSP_EXPORT_ IAppWidgetProviderFactory
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IAppWidgetProviderFactory(void) {};

	/**
	 * Called when the AppWidgetProvider creation request is received from the appwidget service. @n
	 * Applications that provide the %AppWidgetProvider functionality must implement this listener.
	 *
	 * @since	2.1
	 *
	 * @param[in]	providerName		The name of the AppWidget provider
	 * @param[in]	width		The width of the AppWidget
	 * @param[in]	height 		The height of the AppWidget
	 * @param[in]	userInfo	User information that specifies when the AppWidget is added
	 */
	virtual AppWidgetProvider* CreateInstance(const Tizen::Base::String& providerName, float width, float height, const Tizen::Base::String& userInfo) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetProviderFactory_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetProviderFactory_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetProviderFactory_Reserved3(void) {}
};

}} // Tizen::Shell

#endif /* _FSHELL_IAPPWIDGET_PROVIDER_FACTORY_H_ */
