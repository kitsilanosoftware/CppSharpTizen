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
 * @file		FSclIAddressbookEventListener.h
 * @brief		This is the header file for the %IAddressbookEventListener interface.
 *
 * This header file contains the declarations of the %IAddressbookEventListener interface.
 */
#ifndef _FSCL_IADDRESSBOOK_EVENT_LISTENER_H_
#define _FSCL_IADDRESSBOOK_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base { namespace Collection {
class IList;
} } }

namespace Tizen { namespace Social
{

/**
 * @interface	IAddressbookEventListener
 * @brief	This interface provides a listener that receives the events associated with contact and category changes.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This interface is deprecated. Instead of using this listener, use IAddressbookChangeEventListener.
 * @since	2.0
 *
 * The %IAddressbookEventListener interface provides a listener that receives the events associated with contact and category changes.
 *
 */
class _OSP_EXPORT_ IAddressbookEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAddressbookEventListener(void) {}

	/**
	 * Called to notify when contacts are changed. @n
	 * A list of ContactChangeInfo instances is passed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	contactChangeInfoList	The list of contact change information (@ref ContactChangeInfo list)
	 * @remarks This listener method is called when the following changes have occurred: @n
	 *	- Contacts are added, updated, or removed
	 *	- Contacts are added/removed to/from categories
	 *
	 * The following example demonstrates how to use the %OnContactsChanged() method.
	 * @code
	 * void
	 * MyApplication::OnContactsChangedN(const IList& contactChangeInfoList)
	 * {
	 *    IEnumerator* pEnum = contactChangeInfoList.GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      ContactChangeInfo* pInfo = (ContactChangeInfo*) pEnum->GetCurrent();
	 *
	 *      AppLog("Contact changed: type(%d), id(%d), version(%d)", pInfo->GetChangeType(), pInfo->GetContctId(), pInfo->GetVersion());
	 *    }
	 *    delete pEnum;
	 * }
	 * @endcode
	 *
	 */
	virtual void OnContactsChanged(const Tizen::Base::Collection::IList& contactChangeInfoList) = 0;

	/**
	 * Called to notify when categories are changed. @n
     * A list of CategoryChangeInfo instances is passed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	categoryChangeInfoList	The list of category change information (@ref CategoryChangeInfo list)
	 * @remarks This listener method is called when the following changes have occurred: @n
	 *	- Categories are added, updated, or removed
	 *	- Contacts are added/removed to/from categories
	 *
	 * The following example demonstrates how to use the %OnCategoriesChanged() method.
	 * @code
	 * void
	 * MyApplication::OnCategoriesChangedN(const IList& categoryChangeInfoList)
	 * {
	 *    IEnumerator* pEnum = categoryChangeInfoList.GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      CategoryChangeInfo* pInfo = (CategoryChangeInfo*) pEnum->GetCurrent();
	 *
	 *      AppLog("Category changed: type(%d), id(%d), version(%d)", pInfo->GetChangeType(), pInfo->GetCategoryId(), pInfo->GetVersion());
	 *    }
	 *    delete pEnum;
	 * }
	 * @endcode
	 *
	 */
	virtual void OnCategoriesChanged(const Tizen::Base::Collection::IList& categoryChangeInfoList) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAddressbookEventListener_Reserved1(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAddressbookEventListener_Reserved2(void){ }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IAddressbookEventListener_Reserved3(void){ }

};	// IAddressbookEventListener

}}	// Tizen::Social

#endif // _FSCL_IADDRESSBOOK_EVENT_LISTENER_H_
