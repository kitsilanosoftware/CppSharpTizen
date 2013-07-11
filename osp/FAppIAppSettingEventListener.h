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
 * @file	FAppIAppSettingEventListener.h
 * @brief	This is the header file for the %IAppSettingEventListener interface.
 *
 * This header file contains the declarations of the %IAppSettingEventListener interface.
 */

#ifndef _FAPP_IAPP_SETTING_EVENT_LISTENER_H_
#define _FAPP_IAPP_SETTING_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseRtIEventListener.h>


namespace Tizen { namespace App
{

/**
 * @interface	IAppSettingEventListener
 * @brief		This interface is the listener interface for receiving the setting change events.
 *
 * @since	2.0
 *
 * The %IAppSettingEventListener interface is the listener interface for receiving the setting change events.
 * The class that processes a setting change event implements this interface and registers using
 * the AppSetting::SetAppSettingEventListener() method.
 *
 */
class _OSP_EXPORT_ IAppSettingEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAppSettingEventListener(void) {}

	/**
	 * Called when the application setting is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	id		The ID of the application setting whose value is changed
	 */
	virtual void OnAppSettingChanged(const Tizen::Base::String& id) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppSettingEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppSettingEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppSettingEventListener_Reserved3(void) {}

}; // IAppSettingEventListener
} } // Tizen::App

#endif // _FAPP_IAPP_SETTING_EVENT_LISTENER_H_
