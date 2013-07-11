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
 * @file			FAppIAppControlEventListener.h
 * @brief			This is the header file for the %IAppControlEventListener interface.
 *
 * This header file contains the declarations of the %IAppControlEventListener interface.
 */

#ifndef _FAPP_IAPP_CONTROL_EVENT_LISTENER_H_
#define _FAPP_IAPP_CONTROL_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base { class String; } }
namespace Tizen { namespace Base { namespace Collection { class IList; } } }

namespace Tizen { namespace App
{

/**
* @if OSPDEPREC
* @interface	IAppControlEventListener
* @brief		<i>[Deprecated]</i> This interface defines a listener for the AppControl result events.
*
* @deprecated	This class is deprecated. Instead of using this interface, use the IAppControlResponseListener interface.
* @since	2.0
*
* The %IAppControlEventListener interface defines a listener for the AppControl result events.
* @endif
*/
class _OSP_EXPORT_ IAppControlEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief	<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this interface, use the IAppControlResponseListener interface.
	 * @since	2.0
	 * @endif
	 */
	virtual ~IAppControlEventListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called when the application control is completed. @n
	 * The client can get callback result for some application controls by implementing this listener. @n
	 * %OnAppControlCompleted() is called after AppControl::Start() with listener for some application controls.
	 *
	 * @brief	<i> [Deprecated] </i>
	 *
	 * @deprecated	This class is deprecated. Instead of using this interface, use the IAppControlResponseListener interface.
	 * @since	2.0
	 *
	 * @param[in]	providerId	The provider ID
	 * @param[in]	operationId		The operation ID used in application control invocation
	 * @param[in]	pResultList		The list of callback strings of application control
	 *
	 * @remarks	The specified @c pResultList provides the result code for the first array element.
	 * @remarks	When the invoked application control is terminated without sending a result,
	 *           then this method is invoked with @c pResultList and it contains App::APPCONTROL_RESULT_TERMINATED.
	 * @remarks	Switching forms using Tizen::Ui::Controls::Frame::SetCurrentForm() in this listener disables the upcoming form
	 *           (UiApp::OnForeground()). If %UiApp::OnForeground() is being used in the application logic,
	 *			it is recommended to avoid switching forms in this listener.
	 * @see		Tizen::App::AppControl
	 * @endif
	 */
	virtual void OnAppControlCompleted(const Tizen::Base::String& providerId, const Tizen::Base::String& operationId, const Tizen::Base::Collection::IList* pResultList) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAppControlEventListener_Reserved3(void) {}
}; // IAppControlEventListener

} } // Tizen::App

#endif // _FAPP_IAPP_CONTROL_EVENT_LISTENER_H_
