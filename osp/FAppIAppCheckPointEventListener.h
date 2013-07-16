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
 * @file			FAppIAppCheckPointEventListener.h
 * @brief			This is the header file for the %IAppCheckpointEventListener interface.
 *
 * This header file contains the declarations of the %IAppCheckpointEventListener interface. @n
 * If a checkpoint event is generated, a method of this interface is called.
 */

#ifndef _FAPP_IAPP_CHECK_POINT_EVENT_LISTENER_H_
#define _FAPP_IAPP_CHECK_POINT_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App
{

class AppRegistry;

/**
 * @interface IAppCheckpointEventListener
 * @brief	This interface defines the listener for the checkpoint event.
 *
 * @since	2.0
 *
 * The %IAppCheckpointEventListener interface is used for receiving the checkpoint event.
 * The event is fired when the system is about to terminate an application due to, for example, low memory or when another application
 *  is being launched.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/tizen_app_model/multitasking_in_tizen.htm">Multitasking in Tizen</a>.
 *
 */
class _OSP_EXPORT_ IAppCheckpointEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAppCheckpointEventListener(void) {}

	/**
	 * Called when a checkpoint event occurs.
	 *
	 * @since			2.0
	 * @param[in]	appRegistry	 The application registry
	 */
	virtual void OnAppCheckpointing(AppRegistry& appRegistry) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since           2.0
	//
	virtual void IAppCheckpointEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since           2.0
	//
	virtual void IAppCheckpointEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since           2.0
	//
	virtual void IAppCheckpointEventListener_Reserved3(void) {}

}; // IAppCheckpointEventListener

} } // Tizen::App

#endif  //_FAPP_IAPP_CHECK_POINT_EVENT_LISTENER_H_
