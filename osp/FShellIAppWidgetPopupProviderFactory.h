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
 * @file		FShellIAppWidgetPopupProviderFactory.h
 * @brief		This is the header file for the %IAppWidgetPopupProviderFactory interface.
 *
 * This header file contains the declarations of the %IAppWidgetPopupProviderFactory interface.
 */

#ifndef _FSHELL_IAPPWIDGET_POPUP_PROVIDER_FACTORY_H_
#define _FSHELL_IAPPWIDGET_POPUP_PROVIDER_FACTORY_H_

#include <FBaseString.h>
#include <FShellAppWidgetPopupProvider.h>

namespace Tizen { namespace Shell
{

class AppWidgetPopupProvider;

/**
 *   @interface  IAppWidgetPopupProviderFactory
 *   @brief      This interface is the factory interface for creating the AppWidgetPopupProvider instance.
 *
 *   @since	2.1
 *
 * The %IAppWidgetPopupProviderFactory interface is the factory interface for creating the AppWidgetPopupProvider instance.
 * The AppWidgetManager instance calls CreateInstance() when an instance of IAppWidgetPopupProvider is required.
 *
 * @see AppWidgetManager
 */
class _OSP_EXPORT_ IAppWidgetPopupProviderFactory
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IAppWidgetPopupProviderFactory(void) {};

	/**
	 * Creates an AppWidgetPopupProvider instance. @n
	 * Called when the %AppWidgetPopupProvider creation request is received from the appwidget service. @n
	 * Applications that provide the AppWidget functionality must implement this listener.
	 *
	 * @since	2.1
	 *
	 * @param[in]   providerName		The name of the AppWidget provider
	 * @param[in]	userInfo	User information that specifies when the AppWidget is added
	 */
	virtual AppWidgetPopupProvider* CreateInstance(const Tizen::Base::String& providerName, const Tizen::Base::String& userInfo) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetPopupProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetPopupProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetPopupProvider_Reserved3(void) {}
};

}} // Tizen::Shell

#endif /* _IAPPWIDGET_POPUP_FACTORY_H_ */
