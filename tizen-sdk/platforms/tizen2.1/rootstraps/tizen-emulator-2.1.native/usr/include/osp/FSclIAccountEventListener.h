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
 * @file		FSclIAccountEventListener.h
 * @brief		This is the header file for the %IAccountEventListener interface.
 *
 * This header file contains the declarations of the %IAccountEventListener interface.
 */
#ifndef _FSCL_IACCOUNT_EVENT_LISTENER_H_
#define _FSCL_IACCOUNT_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base { namespace Collection {
class IList;
} } }

namespace Tizen { namespace Social
{

/**
 * @interface	IAccountEventListener
 * @brief		This interface provides a listener that receives the events associated with account changes.
 *
 * @since		2.1
 *
 * The %IAccountEventListener interface provides a listener that receives the events associated with account changes.
 *
 */
class _OSP_EXPORT_ IAccountEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IAccountEventListener(void) {}

	/**
	 * Called to notify when an account is added.
	 *
	 * @since	2.1
	 *
	 * @param[in]	accountId	The account ID of the added account
	 */
	virtual void OnAccountAdded(AccountId accountId) = 0;

	/**
	 * Called to notify when an account is updated.
	 *
	 * @since	2.1
	 *
	 * @param[in]	accountId	The account ID of the updated account
	 */
	virtual void OnAccountUpdated(AccountId accountId) = 0;

	/**
	 * Called to notify when an account is removed.
	 *
	 * @since	2.1
	 *
	 * @param[in]	accountId	The account ID of the removed account
	 */
	virtual void OnAccountRemoved(AccountId accountId) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.1
	//
	virtual void IAccountEventListener_Reserved1(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.1
	//
	virtual void IAccountEventListener_Reserved2(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.1
	//
	virtual void IAccountEventListener_Reserved3(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.1
	//
	virtual void IAccountEventListener_Reserved4(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.1
	//
	virtual void IAccountEventListener_Reserved5(void){ }

};	// IAccountEventListener

}}	// Tizen::Social

#endif // _FSCL_IACCOUNT_EVENT_LISTENER_H_
