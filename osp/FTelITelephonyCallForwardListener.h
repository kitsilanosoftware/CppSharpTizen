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
 * @file    FTelITelephonyCallForwardListener.h
 * @brief   This is the header file for the %ITelephonyCallForwardListener interface.
 *
 * This header file contains the declarations of the %ITelephonyCallForwardListener interface.
 */
#ifndef _FTEL_ITELEPHONY_CALL_FORWARD_LISTENER_H_
#define _FTEL_ITELEPHONY_CALL_FORWARD_LISTENER_H_


#include <FBase.h>


namespace Tizen { namespace Telephony
{
/**
 * @interface   ITelephonyCallForwardListener
 * @brief       This interface provides methods to listen to the results of the call forwarding request.
 *
 * @since       2.0
 *
 * The %ITelephonyCallForwardListener interface provides methods to listen to the results of the call forwarding request.
 */
class _OSP_EXPORT_ ITelephonyCallForwardListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
     * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since   2.0
     */
	virtual ~ITelephonyCallForwardListener(void) {}

	/**
     * Called when a response of the call forwarding request is received.
     *
     * @since   2.0
     *
     * @param[in]    phoneNumber         The phone number
     * @param[in]    r                   The result of the call forwarding request
     * @exception    E_SUCCESS           The method is successful.
     * @exception    E_NOT_RESPONDING    The server on the telephony network is not responding.
     * @exception    E_SYSTEM            A system error has occurred.
     */
	virtual void OnTelephonyCallForwardResponseReceived(const Tizen::Base::String& phoneNumber, result r) = 0;

	/**
     * Called when a response of the call forwarding stop request is received.
     *
     * @since   2.0
	 *
     * @param[in]    phoneNumber         The phone number
     * @param[in]    r                   The result of the call forwarding request
     * @exception    E_SUCCESS           The method is successful.
     * @exception    E_NOT_RESPONDING    The server on the telephony network is not responding.
     * @exception    E_SYSTEM            A system error has occurred.
	 */
	virtual void OnTelephonyCallForwardStopped(const Tizen::Base::String& phoneNumber, result r) = 0;

	/**
     * Called when a query for the call forwarding number is completed.
     *
     * @since   2.0
	 *
     * @param[in]    phoneNumber             The phone number
     * @param[in]    r                       The result of the query request
     * @exception    E_SUCCESS               The method is successful.
     * @exception    E_NOT_RESPONDING        The server on the telephony network is not responding.
     * @exception    E_SERVICE_DEACTIVATED   The call forwarding service is not enabled.
     * @exception    E_SYSTEM                A system error has occurred.
     */
	virtual void OnTelephonyCallForwardNumberReceived(const Tizen::Base::String& phoneNumber, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITelephonyCallForwardListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITelephonyCallForwardListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since    2.0
	//
	virtual void ITelephonyCallForwardListener_Reserved3(void) {}
}; // ITelephonyCallForwardListener

}} // Tizen::Telephony
#endif // _FTEL_ITELEPHONY_CALL_FORWARD_LISTENER_H_
