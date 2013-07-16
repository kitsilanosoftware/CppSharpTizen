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
 * @file		FSclIRecordEventListener.h
 * @brief		This is the header file for the %IRecordEventListener interface.
 *
 * This header file contains the declarations of the %IRecordEventListener interface.
 */
#ifndef _FSCL_IRECORD_EVENT_LISTENER_H_
#define _FSCL_IRECORD_EVENT_LISTENER_H_

#include <FSclTypes.h>
#include <FSclRecord.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Social
{

/**
 * @if OSPDEPREC
 * @interface	IRecordEventListener
 * @brief		<i> [Deprecated] </i> This interface provides a listener that receives the events associated with the record.
 *
 * @deprecated		This interface is deprecated. Instead of using this listener, use IAddressbookEventListener or ICalendarbookEventListener.
 *
 * @since	2.0
 *
 * The %IRecordEventListener interface provides a listener that receives the events associated with the record.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/social_records.htm">Social Records</a>.
 * @endif
 */
class _OSP_EXPORT_ IRecordEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated		This method is deprecated because the %IRecordEventListener interface is deprecated. @n
	 * 							Instead of using this listener, use IAddressbookEventListener or ICalendarbookEventListener.
	 *
	 * @since	2.0
	 * @endif
	 */
	virtual ~IRecordEventListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called to notify when a record in the data storage is changed externally.
	 *
	 * @deprecated		This method is deprecated because the %IRecordEventListener interface is deprecated. @n
	 * 							Instead of using this listener, use IAddressbookEventListener or ICalendarbookEventListener.
	 *
	 * @since	2.0
	 *
	 * @param[in]	eventType				The operation type
	 * @param[in]	recordType				The record type of the changed record
	 * @param[in]	record					The Record instance that has changed @n
	 *										If the eventType is #RECORD_REMOVED, the %Record instance only has @c recordId and @c recordType but no data. @n
	 *										When multiple records have changed (#MULTI_RECORDS_ADDED, #MULTI_RECORDS_UPDATED, #MULTI_RECORDS_REMOVED),
	 *										the %Record instance is an invalid record instance with @c INVALID_RECORD_ID.
	 * @param[in]	pUpdatedProperties		This parameter is not supported, do not use it.
	 * @param[in]	pUpdatedMultiProperties This parameter is not supported, do not use it.
	 * @endif
	 */
	virtual void OnRecordChangedN(RecordEventType eventType, RecordType recordType, Record& record, Tizen::Base::Collection::IList* pUpdatedProperties, Tizen::Base::Collection::IList* pUpdatedMultiProperties) = 0;

	/**
	 */

protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IRecordEventListener_Reserved1(void) { }

};	// IRecordEventListener

}}	// Tizen::Social

#endif // _FSCL_IRECORD_EVENT_LISTENER_H_
