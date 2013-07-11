//
// Open Service Platform
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
 * @file	FSclIRecordListener.h
 * @brief	This is the header file for the %IRecordListener interface.
 *
 * This header file contains the declarations of the %IRecordListener interface.
 */
#ifndef _FSCL_IRECORD_LISTENER_H_
#define _FSCL_IRECORD_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseDataType.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Social
{

/**
 * @interface	IRecordListener
 * @brief		This interface represents a listener to asynchronously retrieve the records from the Calendarbook or Addressbook.
 *
 * @since	2.0
 *
 * The %IRecordListener interface represents a listener to asynchronously retrieve the records from the Calendarbook or Addressbook.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/social_records.htm">Social Records</a>.
 */
class _OSP_EXPORT_ IRecordListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IRecordListener(void) {}

	/**
	 * Called when the requested records are retrieved.
	 *
	 * @since	2.0
	 *
	 * @param[in]	reqId				The request ID
	 * @param[in]	pRecords			The result of a specific asynchronous method @n
	 *									A list containing all of the retrieved Record instances, @n
	 *									else an empty list if there are no retrieved records or @c null if an exception occurs
	 * @param[in]	r					The result of the request
	 * @exception	E_SUCCESS			The request is successful.
	 * @exception	E_SYSTEM			An error has occurred on the local storage side.
	 * @remarks		After using @c pRecords, the application must delete it.
	 * @see			Calendarbook::GetEventInstances()
	 */
	virtual void OnRecordsReceivedN(RequestId reqId, Tizen::Base::Collection::IList* pRecords, result r) = 0;

protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IRecordListener_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IRecordListener_Reserved2(void) { }

};	// IRecordListener

}}	// Tizen::Social

#endif // _FSCL_IRECORD_LISTENER_H_
