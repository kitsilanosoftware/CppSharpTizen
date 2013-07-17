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
 * @file	FTelITelephonyNetworkEventListener.h
 * @brief	This is the header file for the %ITelephonyNetworkEventListener interface.
 *
 * This header file contains the declarations of the %ITelephonyNetworkEventListener interface.
 */
#ifndef _FTEL_ITELEPHONY_NETWORK_EVENT_LISTENER_H_
#define _FTEL_ITELEPHONY_NETWORK_EVENT_LISTENER_H_


#include <FBase.h>
#include <FTelNetworkStatus.h>


namespace Tizen { namespace Telephony
{
/**
 * @interface   ITelephonyNetworkEventListener
 * @brief       This interface provides methods to listen to the change in status of the telephony network.
 *
 * @since       2.0
 *
 * The %ITelephonyNetworkEventListener interface checks for status changes in the telephony network.
 *
 */
class _OSP_EXPORT_ ITelephonyNetworkEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
     * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since   2.0
     */
	virtual ~ITelephonyNetworkEventListener(void) {}

	/**
     * Called when the status of the telephony network is changed.
     *
     * @since   2.0
	 *
     * @param[in]   networkStatus	The new network status
     */
	virtual void OnTelephonyNetworkStatusChanged(const NetworkStatus& networkStatus) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITelephonyNetworkEventListener_Reserved1(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITelephonyNetworkEventListener_Reserved2(void) {};
}; // ITelephonyNetworkEventListener

}} // Tizen::Telephony
#endif // _FTEL_ITELEPHONY_NETWORK_EVENT_LISTENER_H_
