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
 * @file	FShellIAppWidgetViewEventListener.h
 * @brief	This is the header file for the %IAppWidgetViewEventListener interface.
 *
 * This header file contains the declarations of the %IAppWidgetViewEventListener interface.
 */

#ifndef _FSHELL_IAPP_WIDGET_VIEW_EVENT_LISTENER_H_
#define _FSHELL_IAPP_WIDGET_VIEW_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Shell
{

class AppWidgetView;

/**
 * @interface	IAppWidgetViewEventListener
 * @brief		This interface defines a listener for the AppWidgetView that receives AppWidgetProvider removed event.
 *
 * @since	2.1
 *
 * The %IAppWidgetViewEventListener interface defines a listener for the AppWidgetView that receives AppWidgetProvider removed event.
 */
class _OSP_EXPORT_ IAppWidgetViewEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IAppWidgetViewEventListener(void) {}

	/**
	 * Called when a AppWidgetProvider instance is about to be removed. @n
	 *
	 * @since 2.1
	 *
	 * @param[in]  appWidgetView	The source of the event
	 */
	virtual void OnAppWidgetProviderRemoved(AppWidgetView& appWidgetView) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IAppWidgetViewEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IAppWidgetViewEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IAppWidgetViewEventListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IAppWidgetViewEventListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IAppWidgetViewEventListener_Reserved5(void) {}
};

}} // Tizen::Shell

#endif /* _FSHELL_IAPP_WIDGET_VIEW_EVENT_LISTENER_H_ */
