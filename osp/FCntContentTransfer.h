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
 * @file		FCntContentTransfer.h
 * @brief		This is the header file for the %ContentTransfer class.
 *
 * This header file contains the declarations of the %ContentTransfer class.
 */

#ifndef _FCNT_CONTENT_TRANSFER_H_
#define _FCNT_CONTENT_TRANSFER_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Base { namespace Utility
{
class Uri;
}}}

namespace Tizen { namespace Content
{

class _ContentTransferImpl;
class IContentTransferListener;

/**
 * @if OSPDEPREC
 * @class	ContentTransfer
 * @brief	<i> [Deprecated] </i> This class provides methods to download the content.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
 * @since	2.0
 *
 * The %ContentTransfer class provides the following features:
 * - Downloading the content from the servers that support HTTP access.
 * - Cancelling a download operation.
 *
 * HTTP download (ContentTransfer::Download()) is a standard HTTP transaction using the HTTP GET request and response methods.
 *
 * The following example demonstrates how to use the %ContentTransfer class.
 *
 *	@code
 *	class  MyClass
 *		:public Tizen::Content::IContentTransferListener
 *	{
 *	public:
 *		MyClass(void);
 *		virtual ~MyClass(void);
 *
 *	public:
 *		void OnContentTransferInProgress(RequestId requestID, int totalReceivedSize);
 *		void OnContentDownloadCompleted(RequestId requestID, ContentId contentID, result res, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage);
 *		void OnContentDownloadToBufferCompleted(RequestId reqId, Tizen::Base::ByteBuffer* pBuffer, result r, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage);
 *		void OnContentTransferCanceled(RequestId reqId, result res, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage);
 *	};
 *
 *	// Implementation for the listener function and Implementation of other listener function is
 *	void MyClass::OnContentDownloadCompleted(RequestId requestID, ContentId contentID, result res, const Tizen::Base::String& errorCode, const Tizen::Base::String& errorMessage)
 *	{
 *		result r = E_SUCCESS;
 *		ContentManager contentManager;
 *		ContentInfo* pContentInfo = null;
 *
 *		// Error check
 *		TryCatch(!IsFailed(res), r, "Download Error [%s]", GetErrorMessage(res));
 *
 *		// Do something
 *		r = contentManager.Construct();
 *		TryCatch(!IsFailed(r), r, "Construct failed.");
 *
 *		// Get ContentInfo
 *		pContentInfo = contentManager.GetContentInfoN(contentID);
 *	CATCH:
 *		if (pContentInfo)
 *			delete pContentInfo;
 *	}
 *
 *	result
 *	MyClass::RequestDownload(void)
 *	{
 *		ContentTransfer contentTransfer;
 *		RequestId requestId;
 *		Tizen::Base::Utility::Uri contentUri;
 *		int contentSize;
 *		Tizen::Base::String downloadPath;
 *
 *		result r = contentTransfer.Construct(*this);
 *		TryReturn(!IsFailed(r), r, ("Construct is failed.\n"));
 *
 *		// TODO: set uri and download path
 *
 *		r = contentTransfer.Download(contentUri, downloadPath, requestId, false);
 *		TryReturn(!IsFailed(r), r, ("Download Request is failed.\n"));
 *	}
 *	@endcode
 *	@endif
 */
class _OSP_EXPORT_ ContentTransfer
	: virtual public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct(IContentTransferListener&) method must be called right after calling this constructor.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	ContentTransfer(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 *
	 * @since		2.0
	 */
	virtual ~ContentTransfer(void);

	/**
	 * Initializes this instance of %ContentTransfer with the specified parameter. @n
	 * This method should be called after every instance of %ContentTransfer is constructed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	listener		A reference to IContentTransferListener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(IContentTransferListener& listener);

	/**
	* Downloads a content file from the content provider's server. @n
	* The @c filesize parameter is used to check the limitation of the local volume. If this parameter is set to @c 0, this method will not check the volume. @n
	* An application should set the full destination path for the downloaded contents. When the content is downloaded to one of the following paths, this method internally registers the content using ContentManager.
	* - /Media/
	* - /Storagecard/Media/ @n
	*
	* When the download is completed, the application is notified using the IContentTransferListener::OnContentDownloadCompleted() method. @n
	* When the data is being downloaded, the application is notified of the progress using the IContentTransferListener::OnContentTransferInProgress() method.
	*
	* @brief	<i> [Deprecated] </i>
	* @deprecated This method is deprecated due to the operation policy of the Tizen Server.
	* When downloading the contents from a third party server, it is recommended to use the Download(const Tizen::Base::Utility::Uri&, const Tizen::Base::String&, RequestId&, bool, int, int) method.
	* @since				 2.0
	* @privilege 	%http://tizen.org/privilege/download
	*
	* @return	An error code
	* @param[in]	uri					The content URL
	* @param[in]	fileSize			The content file size in bytes @n
	*									If set to @c 0, the method does not check the storage limitation.
	* @param[in]	destFilePath		The full destination path
	* @param[in]	replace				The replace option of the destination file @n
	*									Set to @c true to replace the file, @n
	*									else @c false.
	* @param[out]	reqId				The request ID
	* @param[in]	pListener			A pointer to the IContentTransferListener instance
	* @param[in]	sec					The timeout period in seconds
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception 	E_IN_PROGRESS			A previous request is in progress.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @see	IContentTransferListener::OnContentDownloadCompleted()
	* @see	IContentTransferListener::OnContentTransferInProgress()
	*/
	result Download(const Tizen::Base::Utility::Uri& uri, int fileSize, const Tizen::Base::String& destFilePath, bool replace, RequestId& reqId, IContentTransferListener* pListener = null, int sec = 0);

	/**
	 * Downloads a content file from the content provider's server. @n
	 * An application should set the destination path for the downloaded contents.
	 * The path of the downloaded file should use Tizen::System::Environment::GetMediaPath() or Tizen::System::Environment::GetExternalStoragePath().
	 *
	 * When the content is downloaded to the path using Tizen::System::Environment::GetMediaPath() or Tizen::System::Environment::GetExternalStoragePath(), this method internally registers the content in the content database. @n
	 * When the download is completed, the application is notified using the IContentTransferListener::OnContentDownloadCompleted() method. @n
	 * When the data is being downloaded, the application is notified of the progress using the IContentTransferListener::OnContentTransferInProgress() method.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompContentTransferDownloadPage3 "here".
	 * @endif
	 * @privilege		%http://tizen.org/privilege/download
	 *
	 * @return			An error code
	 * @param[in]	uri						The content URL
	 * @param[in]	filePath				The destination file path @n
	 *                                      		Use Tizen::System::Environment::GetMediaPath(), Tizen::System::Environment::GetExternalStoragePath() and Tizen::App::App::GetInstance()->GetAppRootPath().
	 * @param[out]	reqId                   The request ID
	 * @param[in]	replace                 The replace option of the destination file @n
	 *                                       Set to @c true to replace the file, @n
	 *										else @c false.
	 * @param[in]	timeout                 The timeout period in seconds
	 * @param[in]	progressInterval        The progress period interval as a percentage value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	 * @exception	E_IN_PROGRESS			A previous request is in progress.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The @c progressInterval is the interval of the progress for each download request. If the value of the @c progressInterval is @c 0, the @c progressInterval uses the value set by the ContentTransfer::SetProgressIntervalByPercent(int). The @c progressInterval is a percentage value between @c 0 and @c 100.
	 *				The @c timeout is the value of the response timeout for each download request. If the value of the @c timeout is @c 0, the value for the @c timeout uses the value set by the ContentTransfer::SetDefaultTimeout(int).
	 * @see  IContentTransferListener::OnContentDownloadCompleted()
	 * @see  IContentTransferListener::OnContentTransferInProgress()
	 */
	result Download(const Tizen::Base::Utility::Uri& uri, const Tizen::Base::String& filePath, RequestId& reqId, bool replace = false, int timeout = 0, int progressInterval = 0);

	/**
	 * @if OSPCOMPAT
	 * @page		CompContentTransferDownloadPage3 Compatibility for the file path.
	 * @section	CompContentTransferDownloadPageIssueSection Issues
	 *                 The content path argument of this method in OSP compatible applications has the following issues: @n
	 *                 -# The content path should be a path that begins with an allowed path prefix. @n
	 *                    For example, L"/Media/Images/flower.jpg", "/Storagecard/Media/Images/flower.jpg".
	 *
	 * @section	CompImageContentInfoConstructPageSolutionSection Resolutions
	 *                 This issue has been resolved in Tizen. @n
	 *                 -# The content path can be a path without a specific allowed path prefix. @n
	 *                 Application do not need to know the specific allowed path prefixes. @n
	 *                 To get the directory path, use the following methods: @n
	 *                 - For accessing the media directory, use Tizen::System::Environment::GetMediaPath().
	 *                 - For accessing the external storage, use Tizen::System::Environment::GetExternalStoragePath().
	 *
	 * @endif
	 */

	/**
	* Downloads a content file to a buffer from the content provider's servers. @n
	* This method does not register the content. @n
	* When the download is completed, the application is notified using the IContentTransferListener::OnContentDownloadToBufferCompleted() method. @n
	* When the data is being downloaded, the application is notified of the progress using the IContentTransferListener::OnContentTransferInProgress() method.
	*
	* @brief	<i> [Deprecated] </i>
	* @deprecated This method is deprecated due to the operation policy of the Tizen Server.
	* When downloading the contents to a buffer from a third party server, it is recommended to use the DownloadToBuffer(const Tizen::Base::Utility::Uri&, RequestId&, int, int) method.
	* @since				 2.0
	* @privilege 	%http://tizen.org/privilege/download
	*
	* @return	An error code
	* @param[in]	uri					The content URL
	* @param[in]	fileSize			The content file size in bytes @n
	*									If set to @c 0, the method does not check the storage limitation.
	* @param[out]	reqId				The request ID
	* @param[in]	pListener			A pointer to the IContentTransferListener instance
	* @param[in]	sec					The timeout period in seconds
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see	IContentTransferListener::OnContentDownloadToBufferCompleted()
	* @see	IContentTransferListener::OnContentTransferInProgress()
	*/
	result DownloadToBuffer(const Tizen::Base::Utility::Uri& uri, int fileSize, RequestId& reqId, IContentTransferListener* pListener = null, int sec = 0);

	/**
	 * Downloads a content file to a buffer from the content provider's servers. @n
	 * This method does not register the content. @n
	 * When the download is completed, the application is notified using the IContentTransferListener::OnContentDownloadToBufferCompleted() method. @n
	 * When the data is being downloaded, the application is notified of the progress using the IContentTransferListener::OnContentTransferInProgress() method.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since			2.0
	 * @privilege		%http://tizen.org/privilege/download
	 *
	 * @return			An error code
	 * @param[in]	uri						The content URL
	 * @param[out]	reqId					The request ID
	 * @param[in]	timeout					The timeout period in seconds
	 * @param[in]	progressInterval        The progress period interval as a percentage value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_IN_PROGRESS			A previous request is in progress.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The @c progressInterval is the interval of the progress for each download request. If the value of the @c progressInterval is @c 0, the @c progressInterval uses the value set by the ContentTransfer::SetProgressIntervalByPercent(int). The @c progressInterval is a percentage value between @c 0 and @c 100.
	 *				The @c timeout is the value of the response timeout for each download request. If the value of the @c timeout is @c 0, the value for the @c timeout uses the value set by the ContentTransfer::SetDefaultTimeout(int).
	 * @see  IContentTransferListener::OnContentDownloadToBufferCompleted()
	 * @see  IContentTransferListener::OnContentTransferInProgress()
	 */
	result DownloadToBuffer(const Tizen::Base::Utility::Uri& uri, RequestId& reqId, int timeout = 0, int progressInterval = 0);

	/**
	 * Sets the default timeout period. @n
	 * If the server does not respond during the timeout period, the network connection is closed.
	 * @c 0 or minus second means unlimited period.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @param[in]	sec			The default timeout period in seconds @n
	 *                          The default value is @c 0.
	 */
	void SetDefaultTimeout(int sec);

	/**
	 * Gets the default timeout period.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		The default timeout period
	 */
	int GetDefaultTimeout(void) const;

	/**
	 * Removes a transfer operation. @n
	 * This operation removes a request for multiple downloads.
	 * A download operation in progress is not removed by this operation.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	reqId The request ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c reqId is not found.
	 * @exception	E_INVALID_STATE	This method is invalid for the current state of this instance.
	 * @remarks     To stop an on-going transfer, use the Cancel() method.
	 */
	result Remove(RequestId reqId);

	/**
	 * Removes all the transfer operations. @n
	 * This operation removes all the requests for multiple downloads.
	 * The download operations in progress are not removed by this operation.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE	This method is invalid for the current state of this instance.
	 * @remarks     To stop an on-going transfer, use the Cancel() method.
	 */
	result RemoveAll(void);

	/**
	 * Cancels a transfer operation. @n
	 * The downloaded file is deleted from the file system. @n
	 * When a transfer download operation is canceled, the application is notified via the IContentTransferListener::OnContentTransferCanceled() method.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	reqId			The request ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND 	The specified @c reqId is not found.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE	This method is invalid for the current state of this instance.
	 * @see IContentTransferListener::OnContentTransferCanceled()
	 */
	result Cancel(RequestId reqId);

	/**
	 * Cancels all the operations in progress.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE	This method is invalid for the current state of this instance.
	 */
	result CancelAll(void);

	/**
	 * Gets the content transfer information list.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		A pointer to a list containing the ContentTransferInfo instances, @n
	 *				else an empty list if there is no result and no error
	 */
	Tizen::Base::Collection::IList* GetContentTransferInfoListN(void) const;

	/**
	 * Gets the list of transfers that are in progress.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @return		A pointer to a list containing the ContentTransferInfo instances, @n
	 *				else an empty list if there is no result and no error
	 */
	Tizen::Base::Collection::IList* GetContentTransferInfoListInProgressN(void) const;

	/**
	 * Sets the interval of the progress. @n
	 * The input is a percentage value between @c 0 and @c 100. The default value is @c 0.
	 * @c 0 means the application would not receive progress events.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use DownloadManager class.
	 * @since		2.0
	 *
	 * @param[in]	percent		The progress period interval as a percentage value
	 * @remarks     If a server does not provide the information about the content size, then the content module cannot verify the information. @n
	 *              In that case, progress event will occur randomly.
	 */
	void SetProgressIntervalByPercent(int percent);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentTransfer(const ContentTransfer& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentTransfer& operator =(const ContentTransfer& rhs);

private:
	friend class _ContentTransferImpl;
	_ContentTransferImpl* __pImpl;

};  // class ContentTransfer

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_TRANSFER_H_
