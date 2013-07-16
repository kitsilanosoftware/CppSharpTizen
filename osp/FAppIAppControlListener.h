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
 * @file			FAppIAppControlListener.h
 * @brief			This is the header file for the %IAppControlListener interface.
 *
 * This header file contains the declarations of the %IAppControlListener interface.
 */

#ifndef _FAPP_IAPP_CONTROL_LISTENER_H_
#define _FAPP_IAPP_CONTROL_LISTENER_H_

#include <FAppIAppControlEventListener.h>

namespace Tizen { namespace App { class AppControl; } }
namespace Tizen { namespace Base { class String; } }
namespace Tizen { namespace Base { namespace Collection { class IList; } } }

namespace Tizen { namespace App
{

/**
 * @if OSPDEPREC
 * @interface	IAppControlListener
 * @brief		<i>[Deprecated]</i> This interface defines a listener for the AppControl start and result events.
 *
 * @deprecated	This interface is deprecated. Instead of using this interface, use the IAppControlResponseListener interface.
 * @since		2.0
 *
 * The %IAppControlListener interface defines a listener for the AppControl start and result events.
 * @endif
 */
class _OSP_EXPORT_ IAppControlListener
	: public IAppControlEventListener
	, virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
     * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief		<i>[Deprecated]</i>
	 *
	 * @deprecated	This interface is deprecated. Instead of using this interface, use the IAppControlResponseListener interface.
	 * @since	2.0
	 * @endif
	 */
	virtual ~IAppControlListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called when the application control is about to start. @n
	 * The client can get the callback result for some application controls by implementing this listener.
	 *
	 * @brief		<i>[Deprecated]</i>
	 *
	 * @deprecated	This interface is deprecated. Instead of using this interface, use the IAppControlResponseListener interface.
	 * @since			2.0
	 *
	 * @param[in]	pAppControl			A pointer to the AppControl instance that is started
	 * @param[in]	r					The error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_IN_PROGRESS		The target AppControl is in progress.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see		AppControl::Start()
	 * @see		AppManager::StartAppControl()
	 * @endif
	 */
	virtual void OnAppControlStarted(const AppControl* pAppControl, result r) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppControlListener_Reserved1() {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since	2.0
	//
	virtual void IAppControlListener_Reserved2() {}
}; // IAppControlListener

} } // Tizen::App

#endif // _FAPP_IAPP_CONTROL_LISTENER_H_
