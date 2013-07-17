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
 * @file		FShellIBadgeEventListener.h
 * @brief		This is the header file for the %IBadgeEventListener interface.
 *
 * This header file contains the declarations of the %IBadgeEventListener interface.
 */

#ifndef _FSHELL_IBADGE_EVENT_LISTENER_H_
#define _FSHELL_IBADGE_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FAppTypes.h>

namespace Tizen { namespace Shell
{

/**
 * @interface	IBadgeEventListener
 * @brief		This interface defines a listener for the Home screen that receives badge updated event.
 *
 * @since	2.1
 *
 * The %IBadgeEventListener interface defines a listener for the Home screen that receives badge updated event.
 */
class _OSP_EXPORT_ IBadgeEventListener
 : virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IBadgeEventListener(void) {}

	/**
	 * Called when a badge number has been updated.
	 *
	 * @since	2.1
	 *
	 * @param[in]	appId	The application ID that updates the badge number 
	 * @param[in]	badgeNumber		The updated badge number
	 * @remarks	This method is invoked only in the main thread
	 * @see		NotificationManager::Notify()
	 */
	virtual void OnBadgeUpdated(const Tizen::App::AppId& appId, int badgeNumber) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IBadgeEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IBadgeEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void IBadgeEventListener_Reserved3(void) {}
};

}} // Tizen::Shell

#endif /* _FSHELL_IBADGE_EVENT_LISTENER_H_ */
