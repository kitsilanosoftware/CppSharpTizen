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
 * @file			FCntIContentTransferListener.h
 * @brief		This is the header file for the %IContentTransferListener interface.
 *
 * This header file contains the declarations of the %IContentTransferListener interface.
 */

#ifndef _FCNT_ICONTENT_TRANSFER_LISTENER_H_
#define _FCNT_ICONTENT_TRANSFER_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FCntTypes.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
}}

namespace Tizen { namespace Content
{
/**
 * @if OSPDEPREC
 * @interface IContentTransferListener
 * @brief	<i> [Deprecated] </i> This interface provides event handlers that receive the events associated with ContentTransfer.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
 * @since	2.0
 *
 * The %IContentTransferListener interface handles the content download events.
 * @endif
 */
class _OSP_EXPORT_ IContentTransferListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since	2.0
	 */
	virtual ~IContentTransferListener(void) {}

	/**
	 * Called when the content transfer is in progress.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since			2.0
	 *
	 * @param[in]	reqId			The request ID
	 * @param[in]	totalTransferedSize		The total size of the data to transfer in bytes
	 */
	virtual void OnContentTransferInProgress(RequestId reqId, int totalTransferedSize) = 0;

	/**
	 * Called when a download operation is completed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since			2.0
	 *
	 * @param[in]	reqId		The request ID
	 * @param[in]	contentId	The registered content ID
	 * @param[in]	r			The result of the download
	 * @param[in]	errorCode	The error code from the server
	 * @param[in]	errorMessage	The error message from the server
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SERVER		An error has occurred on the server side.
	 * @exception	E_CONNECTION_FAILED The server connection has failed.
	 * @exception	E_ILLEGAL_ACCESS	The request to access a server is illegal.
	 * @exception	E_STORAGE_FULL		The storage is full.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual void OnContentDownloadCompleted(RequestId reqId, ContentId contentId, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage) = 0;

	/**
	 * Called when a download to buffer operation is completed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since			2.0
	 *
	 * @param[in]	reqId		The request ID
	 * @param[in]	pBuffer		The binary buffer that has been downloaded
	 * @param[in]	r			The result of the download
	 * @param[in]	errorCode	The error code from the server
	 * @param[in]	errorMessage	The error message from the server
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SERVER		An error has occurred on the server side.
	 * @exception	E_FILE_ALREADY_EXIST The specified file already exists.
	 * @exception	E_STORAGE_FULL		The storage is full.
	 * @exception	E_CONNECTION_FAILED The server connection has failed.
	 * @exception	E_ILLEGAL_ACCESS	The request to access a server is illegal.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual void OnContentDownloadToBufferCompleted(RequestId reqId, Tizen::Base::ByteBuffer* pBuffer, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage) = 0;

	/**
	* Called when a transfer operation is cancelled.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since			2.0
	 *
	 * @param[in]	reqId		The request ID
	 * @param[in]	r			The result of the transfer
	 * @param[in]	errorCode	The error code from the server
	 * @param[in]	errorMessage	The error message from the server
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SERVER		An error has occurred on the server side.
	 */
	virtual void OnContentTransferCanceled(RequestId reqId, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage) = 0;

protected:

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IContentTransferListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IContentTransferListener_Reserved2(void) {}

};  // class IContentTransferListener

}} // Tizen::Content

#endif // _FCNT_ICONTENT_TRANSFER_LISTENER_H_
