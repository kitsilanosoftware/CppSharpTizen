//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file	FTelISimStateManagerGetPinLockSettingResultListener.h
 * @brief	This is the header file for the %ISimStateManagerGetPinLockSettingResultListener interface.
 *
 * This header file contains the declarations of the %ISimStateManagerGetPinLockSettingResultListener interface.
 *
 */
#ifndef _FTEL_ISIM_STATE_MANAGER_GET_PIN_LOCK_SETTING_RESULT_LISTENER_H_
#define _FTEL_ISIM_STATE_MANAGER_GET_PIN_LOCK_SETTING_RESULT_LISTENER_H_

#include <FBaseRtIEventListener.h>


namespace Tizen { namespace Telephony
{
/**
 * @interface   ISimStateManagerGetPinLockSettingResultListener
 * @brief		This interface provides methods to receive the result of the SimStateManager::GetPinLockSetting() asynchronous method.
 *
 * @since		2.1
 *
 * The %ISimStateManagerGetPinLockSettingResultListener interface provides methods to receive the result of the SimStateManager::GetPinLockSetting() asynchronous method.
 *
 */
class _OSP_EXPORT_ ISimStateManagerGetPinLockSettingResultListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~ISimStateManagerGetPinLockSettingResultListener(void) {}

public:
	/**
	 * Called when a response to the PIN lock setting query is received.
	 *
	 * @since		2.1
	 *
	 * @param[in]	isEnabled		The PIN lock setting value
	 * @param[in]	r				The result of the request @n The following exceptions may be given through this parameter.
	 *
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE		The SIM is in an invalid state.
	 */
	virtual void OnSimStateManagerGetPinLockSettingResultReceived(bool isEnabled, result r) = 0;

}; // ISimStateManagerGetPinLockSettingResultListener

} } // Tizen::Telephony

#endif // _FTEL_ISIM_STATE_MANAGER_GET_PIN_LOCK_SETTING_RESULT_LISTENER_H_
