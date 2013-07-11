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
 * @file    FTelITelephonyCallEventListener.h
 * @brief   This is the header file for the %ITelephonyCallEventListener interface.
 *
 * This header file contains the declarations of the %ITelephonyCallEventListener interface.
 *
 */
#ifndef _FTEL_ITELEPHONY_CALL_EVENT_LISTENER_H_
#define _FTEL_ITELEPHONY_CALL_EVENT_LISTENER_H_


#include <FBase.h>
#include <FTelTypes.h>
#include <FTelCallInfo.h>


namespace Tizen { namespace Telephony
{
/**
 * @interface   ITelephonyCallEventListener
 * @brief       This interface provides methods to listen to the change in status of a call.
 *
 * @since       2.0
 *
 * The %ITelephonyCallEventListener interface checks for the change in status of a call.
 *
 */
class _OSP_EXPORT_ ITelephonyCallEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
    /**
     * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since   2.0
     */
	virtual ~ITelephonyCallEventListener(void) {}

	/**
    * Called when the status of a call is changed.
    *
    * @since    2.0
	*
    * @param[in]    callStatus The new status of a call
    * @param[in]    pCallInfo  The detailed information of a call
    * @see  Tizen::Telephony::CallStatus
    */
	virtual void OnTelephonyCallStatusChangedN(CallStatus callStatus, CallInfo* pCallInfo) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITelephonyCallEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITelephonyCallEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITelephonyCallEventListener_Reserved3(void) {}
}; // ITelephonyCallEventListener

}} // Tizen::Telephony
#endif // _FTEL_ITELEPHONY_CALL_EVENT_LISTENER_H_
