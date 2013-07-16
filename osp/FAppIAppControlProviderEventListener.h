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
 * @file    FAppIAppControlProviderEventListener.h
 * @brief   This is the header file for the %IAppControlProviderEventListener interface.
 *
 * This header file contains the declarations of the %IAppControlProviderEventListener interface.
 */

#ifndef _FAPP_IAPPCONTROL_PROVIDER_EVENT_LISTENER_H_
#define _FAPP_IAPPCONTROL_PROVIDER_EVENT_LISTENER_H_

#include <FBaseObject.h>
#include <FBaseRtIEventListener.h>
#include <FAppTypes.h>


namespace Tizen { namespace Base { namespace Collection {
class IList;
class IMap;
}}}

namespace Tizen { namespace App
{

/**
*   @interface  IAppControlProviderEventListener
*   @brief      This interface defines the provider listener for the AppControl request.
*
*   @since	2.0
*
* The %IAppControlProviderEventListener interface defines a listener for the AppControl request events.
* Applications that provide the %AppControl functionality must implement this interface.
*
* @see AppControlProviderManager
*/
class _OSP_EXPORT_ IAppControlProviderEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAppControlProviderEventListener(void) {}

	/**
	 * Called when the application control request is received from the caller application. @n
	 * The application control provider must implement this listener for exporting its own functionality.
	 *
	 * @since	2.0
	 *
	 * @param[in]   reqId  The application control request ID
	 * @param[in]	operationId	The application control operation ID
	 * @param[in]	pUriData	A pointer to the URI data
	 * @param[in]	pMimeType	A pointer to the MIME type (RFC 2046) data
	 * @param[in]	pExtraData	A pointer to an argument map of key and value pair where the key is of type String and the value is of type Tizen::Base::String or of type Tizen::Base::Collection::ArrayList of %Tizen::Base::String
	 * @remarks	To reply to the application control request, use AppControlProviderManager::SendAppControlResult() with the given request ID.
	 * @remarks	When the application receives the AppControl request on the background,
	 * 			%OnAppControlRequestReceived() is invoked before UiApp::OnForeground().
	 * @remarks	When the application control is resolved with the file extension with AppControl::FindAndStart(),
	 * 			the delivered file extension is converted to the corresponding MIME type in the @c pMimeType parameter.
	 * @see AppControlProviderManager::SendAppControlResult()
	 */
	virtual void OnAppControlRequestReceived(RequestId reqId, const Tizen::Base::String& operationId, const Tizen::Base::String* pUriData, const Tizen::Base::String* pMimeType, const Tizen::Base::Collection::IMap* pExtraData) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppControlProviderEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppControlProviderEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppControlProviderEventListener_Reserved3(void) {}

}; // IAppControlProviderEventListener

}} // Tizen::App

#endif // _FAPP_IAPPCONTROL_PROVIDER_EVENT_LISTENER_H_
