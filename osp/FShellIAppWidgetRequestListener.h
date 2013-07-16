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
 * @file		FShellIAppWidgetRequestListener.h
 * @brief		This is the header file for the %IAppWidgetRequestListener interface.
 *
 * This header file contains the declarations of the %IAppWidgetRequestListener interface.
 */

#ifndef _FSHELL_IAPPWIDGET_ADD_REQUEST_LISTENER_H_
#define _FSHELL_IAPPWIDGET_ADD_REQUEST_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseString.h>
#include <FAppTypes.h>

namespace Tizen { namespace Shell
{

/**
 * @interface	IAppWidgetRequestListener
 * @brief		This interface defines a listener for an AppWidget viewer (for example, Home screen, Lock screen) that receives request to add AppWidget.
 *
 * @since	2.1
 *
 * The %IAppWidgetRequestListener interface defines a listener for an AppWidget viewer (for example, Home screen, Lock screen) that receives request to add AppWidget.
 */
class _OSP_EXPORT_ IAppWidgetRequestListener
 : virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IAppWidgetRequestListener(void) {}

	/**
	 * Called when requested to add an AppWidget. @n
	 * The AppWidget viewer application such as the Home screen can get callback request to add an AppWidget by implementing this listener.
	 *
	 * @since	2.1
	 *
	 * @param[in]	appId	The application ID of the application providing AppWidget
	 * @param[in]	providerName	The name of the AppWidget provider to add
	 * @param[in]	text			Alternative text for the AppWidget
	 * @param[in]	userInfo		User information for the AppWidget provider
	 * @remarks	This method is invoked only in the main thread.
	 * @see		AppWidgetProviderManager::AddAppWidget()
	 */
	virtual void OnAppWidgetAddRequested(const Tizen::App::AppId& appId, const Tizen::Base::String& providerName, const Tizen::Base::String& text, const Tizen::Base::String& userInfo) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetAddReqeustListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetAddReqeustListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IAppWidgetAddReqeustListener_Reserved3(void) {}

};

}} // Tizen::Shell

#endif /* _FSHELL_IAPPWIDGET_ADD_REQUEST_LISTENER_H_ */
