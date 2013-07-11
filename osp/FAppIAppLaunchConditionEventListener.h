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
 * @file			FAppIAppLaunchConditionEventListener.h
 * @brief			This is the header file for the %IAppLaunchConditionEventListener interface.
 *
 * This header file contains the declarations of the %IAppLaunchConditionEventListener interface.
 */

#ifndef _FAPP_IAPP_LAUNCH_CONDITION_EVENT_LISTENER_H_
#define _FAPP_IAPP_LAUNCH_CONDITION_EVENT_LISTENER_H_

#include <FOspConfig.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base { class String; } }

namespace Tizen { namespace App
{

/**
* @interface	IAppLaunchConditionEventListener
* @brief		This interface defines a listener for the AppLaunchCondition events.
*
* @since	2.0
*
* The %IAppLaunchConditionEventListener interface defines a listener for the AppLaunchCondition events.
* @n
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>, <a href="../org.tizen.native.appprogramming/html/guide/app/registering_launch_condition.htm">Registering a Launch Condition</a>.
*/
class _OSP_EXPORT_ IAppLaunchConditionEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAppLaunchConditionEventListener(void) {}

	/**
	* Called when the registered launch condition is met.
	*
	* @since	2.0
	*
	* @param[in] condition        The registered condition for the application launch
	* @param[in] pArguments       A list of string arguments specified when the condition is registered
	* @param[in] pExtraData       A pointer to the instance of object that system delivered, @n
	*                             else @c null if there is no extra data
	*
	* @remarks     If extra data is required to be delivered, @c pExtraData contains the data,
	*              and this must be freed by the launched application after use.
	*               ( Currently, only NFC condition uses this to deliver to Tizen::Net::Nfc::NdefMessage. )
	* @see         Tizen::App::AppManager::RegisterAppLaunch()
	* @see         Tizen::App::AppManager::SetAppLaunchConditionEventListener()
	*
	*  The following example demonstrates how to use the %OnAppLaunchConditionMetN() method to get Tizen::Net::Nfc::NdefMessage instance, when an application is launched by NFC condition.
	*  @code
	*  NdefMessage* pMessage = dynamic_cast<NdefMessage*>(pExtraData);
	*  @endcode
	*/
	virtual void OnAppLaunchConditionMetN(const Tizen::Base::String& condition, Tizen::Base::Object* pExtraData, Tizen::Base::Collection::IList* pArguments) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppLaunchConditionEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppLaunchConditionEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppLaunchConditionEventListener_Reserved3(void) {}
}; // IAppLaunchConditionEventListener

} } // Tizen::App

#endif // _FAPP_IAPP_LAUNCH_CONDITION_EVENT_LISTENER_H_

