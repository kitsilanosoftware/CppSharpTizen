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
 * @file	FTelITelephonySimEventListener.h
 * @brief	This is the header file for the %ITelephonySimEventListener interface.
 *
 * This header file contains the declarations of the %ITelephonySimEventListener interface.
 */
#ifndef _FTEL_ITELEPHONY_SIM_EVENT_LISTENER_H_
#define _FTEL_ITELEPHONY_SIM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FTelTypes.h>


namespace Tizen { namespace Telephony
{

/**
 * @interface   ITelephonySimEventListener
 * @brief       This interface provides methods to listen to the change in state of the SIM card.
 *
 * @since       2.1
 *
 * The %ITelephonySimEventListener interface checks for the change in state of the SIM card.
 *
 */
class _OSP_EXPORT_ ITelephonySimEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
     * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since   2.1
     */
	virtual ~ITelephonySimEventListener(void) {}

	/**
     * Called when the state of SIM is changed.
     *
     * @since   2.1
	 *
     * @param[in]   state	The new SIM state
     */
	virtual void OnTelephonySimStateChanged(SimState state) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void ITelephonySimEventListener_Reserved1(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void ITelephonySimEventListener_Reserved2(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void ITelephonySimEventListener_Reserved3(void) {};

}; // ITelephonySimEventListener

}} // Tizen::Telephony
#endif // _FTEL_ITELEPHONY_SIM_EVENT_LISTENER_H_
