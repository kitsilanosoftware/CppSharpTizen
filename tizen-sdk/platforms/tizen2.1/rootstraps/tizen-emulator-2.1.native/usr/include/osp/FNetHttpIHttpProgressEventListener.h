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
 * @file		FNetHttpIHttpProgressEventListener.h
 * @brief		This is the header file for the %IHttpProgressEventListener interface.
 *
 * This header file contains the declarations of the %IHttpProgressEventListener interface.
 */

#ifndef _FNET_HTTP_IHTTP_PROGRESS_EVENT_LISTENER_H_
#define _FNET_HTTP_IHTTP_PROGRESS_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpSession;
class HttpTransaction;
/**
 * @interface	IHttpProgressEventListener
 * @brief		This interface provides the listeners for the HTTP progress events.
 *
 * @since       2.0
 *
 *  The %IHttpProgressEventListener interface is the listener for the HTTP progress events, when the HTTP message is uploaded or downloaded. In order to use this listener,
 *	the listener must be set to the HttpTransaction instance using the HttpTransaction::SetHttpProgressListener() method.
 */

class _OSP_EXPORT_ IHttpProgressEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since 2.0
	*/
	virtual ~IHttpProgressEventListener(void) {}

public:
	/**
	 * Called to notify when the content body of the request message is being uploaded.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession				The session information of the %Http transaction event
	 * @param[in]	httpTransaction			The transaction information of the %Http transaction event
	 * @param[in]	currentLength			The current length of the uploaded data (in bytes)
	 * @param[in]	totalLength				The total length of the data (in bytes) to upload
	 * @remarks		If the content length of the request message is not set, the value of @c totalLength is -1.
	 */
	virtual void OnHttpUploadInProgress(HttpSession& httpSession, HttpTransaction& httpTransaction, long long currentLength, long long totalLength) = 0;

	/**
	 * Called to notify when the content body of the response message is being downloaded.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession				The session information of the %Http transaction event
	 * @param[in]	httpTransaction			The transaction information of the %Http transaction event
	 * @param[in]	currentLength			The current length of the downloaded data (in bytes)
	 * @param[in]	totalLength				The total length of the data (in bytes) to download
	 * @remarks		If the content length of the response message is not set, the value of @c totalLength is -1.
	 */
	virtual void OnHttpDownloadInProgress(HttpSession& httpSession, HttpTransaction& httpTransaction, long long currentLength, long long totalLength) = 0;

protected:
	// Reserved virtual methods for later extension.

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpProgressEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpProgressEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpProgressEventListener_Reserved3(void) {}
};

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_IHTTP_PROGRESS_EVENT_LISTENER_H_
