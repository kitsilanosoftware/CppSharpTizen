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
 * @file			FAppIAppControlResponseListener.h
 * @brief			This is the header file for the %IAppControlResponseListener interface.
 *
 * This header file contains the declarations of the %IAppControlResponseListener interface.
 */

#ifndef _FAPP_IAPP_CONTROL_RESPONSE_LISTENER_H_
#define _FAPP_IAPP_CONTROL_RESPONSE_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base {
class String;
namespace Collection {
class IMap;
}
}}

namespace Tizen { namespace App
{

/**
* @interface	IAppControlResponseListener
* @brief		This interface defines a listener for the AppControl response events.
*
* @since	2.0
*
* The %IAppControlResponseListener interface defines a listener for the AppControl response events.
*/
class _OSP_EXPORT_ IAppControlResponseListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAppControlResponseListener(void) {}

	/**
	 * Called when the response for application control completion is received.
	 *
	 * @since	2.0
	 *
	 * @param[in]	appId			The ID of the requested application
	 * @param[in]	operationId		The operation ID used in application control invocation
	 * @param[in]	appControlResult	The application control result
	 * @param[in]	pExtraData		The Tizen::Base::String key and %Tizen::Base::String value pair map of application result data
	 * @remarks	The application control completion result is received when the requested application control
	 * 			sends the result using AppControlProviderManager::SendAppControlResult().
	 * @see		AppControl
	 * @see		AppControlProviderManager::SendAppControlResult()
	 */
	virtual void OnAppControlCompleteResponseReceived(const AppId& appId, const Tizen::Base::String& operationId, AppCtrlResult appControlResult, const Tizen::Base::Collection::IMap* pExtraData) = 0;

	/**
	 * Called when the application control is about to start or to be canceled by the user resolution. @n
	 * The calling application can get the result of the resolution by implementing this empty body method.
	 *
	 * @since	2.0
	 *
	 * @param[in]	appId			The ID of the requested application
	 * @param[in]	operationId		The operation ID used in application control invocation
	 * @param[in]	r				The result of the application control start response @n
	 * 								The exception code may be given through this parameter.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OPERATION_CANCELED	The application control resolve request is canceled by a user operation.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method invoked only for the implicit AppControl resolution.
	 * @see	AppControl
	 * @see	AppControl::FindAndStart()
	 */
	virtual void OnAppControlStartResponseReceived(const AppId& appId, const Tizen::Base::String& operationId, result r) {}

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlResponseListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlResponseListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlResponseListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlResponseListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlResponseListener_Reserved5(void) {}
}; // IAppControlResponseListener

} } // Tizen::App

#endif // _FAPP_IAPP_CONTROL_RESPONSE_LISTENER_H_
