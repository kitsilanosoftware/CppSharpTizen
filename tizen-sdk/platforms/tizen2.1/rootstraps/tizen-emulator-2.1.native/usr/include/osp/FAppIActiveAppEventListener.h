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
 * @file	FAppIActiveAppEventListener.h
 * @brief	This is the header file for the %IActiveAppEventListener interface.
 *
 * This header file contains the declarations of the %IActiveAppEventListener interface.
 */

#ifndef _FAPP_IACTIVE_APP_EVENT_LISTENER_H_
#define _FAPP_IACTIVE_APP_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FAppTypes.h>
#include <FBaseRtIEventListener.h>


namespace Tizen { namespace App
{

/**
 * @interface	IActiveAppEventListener
 * @brief		This interface is the listener interface for receiving the AppId of active application.
 *
 * @since	2.0
 *
 *
 * The %IActiveAppEventListener interface is the listener interface for receiving the active application change events.
 * The class that processes an active application change event implements this interface and registers using
 * the AppManager::AddActiveAppEventListener() method.
 *
 */
class _OSP_EXPORT_ IActiveAppEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 *
	 */
	virtual ~IActiveAppEventListener(void) {}

	/**
	 * Called when the active application is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	appId		The AppId of the active application
	 */
	virtual void OnActiveAppChanged(const AppId& appId) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IActiveAppEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IActiveAppEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IActiveAppEventListener_Reserved3(void) {}

}; // IActiveAppEventListener
} } // Tizen::App

#endif // _FAPP_IACTIVE_APP_EVENT_LISTENER_H_
