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
 * @file		FCntContentTransferInfo.h
 * @brief		This is the header file for the %ContentTransferInfo class.
 *
 * This header file contains the declarations of the %ContentTransferInfo class.
 */

#ifndef _FCNT_CONTENT_TRANSFER_INFO_H_
#define _FCNT_CONTENT_TRANSFER_INFO_H_

#include <FBaseUtilUri.h>

namespace Tizen { namespace Content
{

class _ContentTransferInfoImpl;
class IContentTransferListener;

/**
 * @if OSPDEPREC
 * @enum ContentTransferStatus
 *
 * Defines the content transfer status.
 *
 * @since	2.0
 * #endif
 */
enum  ContentTransferStatus
{
	CONTENT_TRANSFER_STATUS_NONE,									/**< None */
	CONTENT_TRANSFER_STATUS_DOWNLOADING,					/**< The Downloading status */
	CONTENT_TRANSFER_STATUS_DOWNLOAD_COMPLETED,	/**<  The Download completed status */
	CONTENT_TRANSFER_STATUS_DOWNLOAD_READY,				/**<  The Download ready status */
};

/**
 * @if OSPDEPREC
 * @class	ContentTransferInfo
 * @brief	<i> [Deprecated] </i> This class contains methods that provide information about the content transfer.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
 * @since	2.0
 *
 * The %ContentTransferInfo class provides information about the transfer of content between the device and servers.
 * @endif
 */
class _OSP_EXPORT_ ContentTransferInfo
	: virtual public Tizen::Base::Object
{
public:
	/**
	 * This is the constructor for this class.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 */
	ContentTransferInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 */
	virtual ~ContentTransferInfo(void);

	/**
	 * Gets the requested Uniform Resource Identifier (URI).
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		The requested URI
	 */
	Tizen::Base::Utility::Uri GetUri(void) const;

	/**
	 * Gets the request ID.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		The request ID
	 *
	 */
	RequestId GetRequestId(void) const;

	/**
	 * Gets the destination file path.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		The destination file path
	 *
	 */
	Tizen::Base::String GetDestPath(void) const;

	/**
	 * Gets the content transfer's status.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		The content transfer's status
	 */
	ContentTransferStatus GetContentTransferStatus(void) const;

private:
	void SetAllInfo(RequestId reqId, const Tizen::Base::Utility::Uri& uri, const Tizen::Base::String& destPath, const Tizen::Base::String& sourcePath, int sourceFileSize, ContentTransferStatus status);

	void SetRestRequestId(RequestId reqId);

	RequestId GetRestRequestId(void) const;

	int GetSourceFileSize(void) const;

	void SetSlotId(int slot);

	int GetSlotId(void) const;

	void SetTimeout(int sec);

	int GetTimeout(void) const;

	void SetListener(IContentTransferListener* pListener);

	ContentTransferInfo* CopyN(void);

	void SetIsBuffer(bool isBuffer);

	bool GetIsBuffer(void) const;

	void SetProgressInterval(int intervalValue);

	int GetProgressInterval(void) const;

	void SetDownloadStatus(ContentTransferStatus status);

private:
	RequestId __requestId;
	RequestId __restRequestId;
	ContentTransferStatus __status;
	Tizen::Base::String __destPath;
	Tizen::Base::Utility::Uri __uri;
	Tizen::Base::String __sourcePath;
	int __sourceFileSize;
	int __slotId;
	IContentTransferListener* __pListener;
	int __timeout;
	bool __isBuffer;
	int __intervalValue;
	_ContentTransferInfoImpl* __pImpl; // pubonly - for ABC
	friend class _ContentTransferInfoImpl;
	friend class _ContentTransferImpl;
	friend class _ContentDownloadListener;

};  // class ContentTransferInfo

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_TRANSFER_INFO_H_
