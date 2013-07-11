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
 * @file		FCntIDownloadListener.h
 * @brief		This is the header file for the %IDownloadListener interface.
 *
 * This header file contains the declarations of the %IDownloadListener interface.
 */

#ifndef _FCNT_IDOWNLOAD_LISTENER_H_
#define _FCNT_IDOWNLOAD_LISTENER_H_

#include <FBaseString.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Content
{

/**
* @interface IDownloadListener
* @brief    This interface is used for receiving the download operation events.
*
* @since 2.0
*
* The %IDownloadListener interface is used for receiving the download operation events.
*/
class _OSP_EXPORT_ IDownloadListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IDownloadListener(void) {}

	/**
	 * Called when a download operation is canceled.
	 *
	 * @since 2.0
	 *
	 * @param[in] reqId           The request ID returned by DownloadManager::Start()
	 */
	virtual void OnDownloadCanceled(RequestId reqId) = 0;

	/**
	 * Called when a download operation is completed.
	 *
	 * @since 2.0
	 *
	 * @param[in] reqId           The request ID returned by DownloadManager::Start()
	 * @param[in] path            The path of the downloaded file
	 */
	virtual void OnDownloadCompleted(RequestId reqId, const Tizen::Base::String& path) = 0;

	/**
	 * Called when a download operation fails.
	 *
	 * @since 2.0
	 *
	 * @param[in] reqId           The request ID returned by DownloadManager::Start()
	 * @param[in] r               The error of a download operation @n The following error codes may be given through this argument.
	 * @param[in] errorCode         The http error code from the server
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_INVALID_URL		The specified URL is invalid.
	 * @exception E_CONNECTION_FAILED	The server connection fails.
	 * @exception E_TIMEOUT			The connection has timed out.
	 * @exception E_MAX_EXCEEDED	The request has exceeded the limit.
	 * @exception E_STORAGE_FULL	The storage is full.
	 * @exception E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	virtual void OnDownloadFailed(RequestId reqId, result r, const Tizen::Base::String& errorCode) = 0;

	/**
	 * Called when a download operation pauses.
	 *
	 * @since 2.0
	 *
	 * @param[in] reqId           The request ID returned by DownloadManager::Start()
	 */
	virtual void OnDownloadPaused(RequestId reqId) = 0;

	/**
	 * Called when the progress of download operation is changed.
	 *
	 * @since 2.0
	 *
	 * @param[in] reqId           The request ID
	 * @param[in] receivedSize    The size of received data in bytes
	 * @param[in] totalSize       The total size of data to receive in bytes
	 */
	virtual void OnDownloadInProgress(RequestId reqId, unsigned long long receivedSize, unsigned long long totalSize) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IDownloadListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IDownloadListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IDownloadListener_Reserved3(void) {}
}; // IDownloadListener

} } // Tizen::Content

#endif // _FCNT_IDOWNLOAD_LISTENER_H_
