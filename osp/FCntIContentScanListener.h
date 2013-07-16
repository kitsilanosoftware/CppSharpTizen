//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FCntIContentScanListener.h
 * @brief		This is the header file for the %IContentScanListener interface.
 *
 * This header file contains the declarations of the %IContentScanListener interface.
 */

#ifndef _FCNT_ICONTENT_SCAN_LISTENER_H_
#define _FCNT_ICONTENT_SCAN_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Content
{
/**
 * @interface	IContentScanListener
 * @brief		This interface is used for receiving the scan operation event.
 *
 * @since 2.1
 *
 * The %IContentScanListener interface is used for receiving the scan operation event.
 */
class _OSP_EXPORT_ IContentScanListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IContentScanListener(void) {}

	/**
	 * Called when a scan operation is completed.
	 *
	 * @since			2.1
	 *
	 * @param[in]		reqId				The request ID returned by ContentManager::ScanDirectory()
	 * @param[in]		scanPath			The scan path
	 * @param[in]		r					The error of scan operation @n
	 *										The following exceptions are given through this parameter.
	 * @exception		E_SUCCESS			The method is successful
	 * @exception		E_SERVICE_BUSY	    The database is busy.
	 * @exception		E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	virtual void OnContentScanCompleted(RequestId reqId, const Tizen::Base::String& scanPath, result r) = 0;

protected:

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentScanListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentScanListener_Reserved2(void) {}


};  // class IContentScanListener

}} // Tizen::Content

#endif // _FCNT_ICONTENT_SCAN_LISTENER_H_
