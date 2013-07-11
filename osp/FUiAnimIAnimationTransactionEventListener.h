//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiAnimIAnimationTransactionEventListener.h
 * @brief	This is the header file for the %IAnimationTransactionEventListener interface.
 *
 * This header file contains the declarations of the %IAnimationTransactionEventListener interface.
 */

#ifndef _FUI_ANIM_IANIMATION_TRANSACTION_EVENT_LISTENER_H_
#define _FUI_ANIM_IANIMATION_TRANSACTION_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseRtIEventListener.h>
#include <FUiAnimTypes.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @interface	IAnimationTransactionEventListener
 * @brief		This interface implements the listener for the animation transaction events defined in the Tizen::Ui::Animations namespace.
 *
 * @since		2.0
 *
 * The %IAnimationTransactionEventListener interface is the listener interface for receiving animation transaction events.
 * The class that processes an animation transaction event implements this interface, and the instance created with that class is
 * registered with AnimationTransaction, using the AnimationTransaction::SetTransactionEventListener() method. When the animation
 * transaction event occurs, a method of that instance is invoked.
 *
 */
class _OSP_EXPORT_ IAnimationTransactionEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IAnimationTransactionEventListener(void) {}


	/**
	 * Called when the transaction starts.
	 *
	 * @since		2.0
	 *
	 * @param[in]   transactionId		The transaction ID of the transaction for which the event has occurred
	 */
	virtual void OnAnimationTransactionStarted(int transactionId) = 0;


	/**
	 * Called when the transaction stops.
	 *
	 * @since		2.0
	 *
	 * @param[in]   transactionId		The transaction ID of the transaction for which the event has occurred
	 * @remarks     This callback is called when user calls AnimationTransaction::Stop().
	 */
	virtual void OnAnimationTransactionStopped(int transactionId) = 0;


	/**
	 * Called when the transaction is finished.
	 *
	 * @since		2.0
	 *
	 * @param[in]	transactionId		The ID of the transaction for which the event has occurred
	 * @remarks     This callback is called when all the animations in a transaction are finished.
	 */
	virtual void OnAnimationTransactionFinished(int transactionId) = 0;


protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IAnimationTransactionEventListener_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IAnimationTransactionEventListener_Reserved2(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since  2.0
	//
	virtual void IAnimationTransactionEventListener_Reserved3(void) { }
};		// IAnimationTransactionEventListener


}}}		// Tizen::Ui::Animations

#endif // _FUI_ANIM_IANIMATION_TRANSACTION_EVENT_LISTENER_H_
