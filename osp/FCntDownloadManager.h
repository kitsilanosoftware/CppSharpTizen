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
 * @file		FCntDownloadManager.h
 * @brief		This is the header file for the %DownloadManager class.
 *
 * This header file contains the declarations of the %DownloadManager class.
 */
#ifndef _FCNT_DOWNLOAD_MANAGER_H_
#define _FCNT_DOWNLOAD_MANAGER_H_

#include <FBaseResult.h>
#include <FBaseString.h>
#include <FCntTypes.h>


namespace Tizen { namespace Content
{

class DownloadRequest;
class IDownloadListener;

/**
* @class    DownloadManager
* @brief    This class provides methods to handle HTTP downloads.
*
* @since 2.0
*
* @final	This class is not intended for extension.
*
* The %DownloadManager class provides methods to handle HTTP downloads. A download request consists of a URL and a destination path; of which the URL is mandatory for downloading content. If the destination path is not specified, the content is downloaded to a default download storage that can be obtained with the System::Environment::GetDownloadPath() method.
* This class conducts the download in the background and calls the Start() method that takes care of HTTP connections. @n
* The download operation can be:
* - Paused by calling the Pause() method
* - Resumed by calling the Resume() method
* - Cancelled by calling the Cancel() method
* Depending on how the download operation is terminated the following methods are called:
* - IDownloadListener::OnDownloadCanceled() when the download is cancelled
* - IDownloadListener::OnDownloadCompleted() when the download is completed without any errors
* - IDownloadListener::OnDownloadFailed() when the download has been stopped because of an error
*
* The following example demonstrates how to use the %DownloadManager class.
*
* @code
*
* #include <FBase.h>
* #include <FContent.h>
*
* using namespace Tizen::Base;
* using namespace Tizen::Content;
* using namespace Tizen::App;
*
* class MyAppClass
* 	: public Tizen::Content::IDownloadListener
* {
* public:
*	result Download(const String& url);
*	virtual void OnDownloadCanceled(RequestId reqId) {}
*	virtual void OnDownloadCompleted(RequestId reqId, const Tizen::Base::String& path);
*	virtual void OnDownloadFailed(RequestId reqId, result r, const Tizen::Base::String& errorCode);
*	virtual void OnDownloadPaused(RequestId reqId) {}
*	virtual void OnDownloadInProgress(RequestId reqId, unsigned long long receivedSize, unsigned long long totalSize) {}
*
* };
*
* result
* MyAppClass::Download(const String& url)
* {
*	result r = E_SUCCESS;
*	RequestId reqId = 0;
*
*	DownloadRequest request(url);
* 	DownloadManager* pManager = DownloadManager::GetInstance();
*
* 	pManager->SetDownloadListener(this);
*	pManager->Start(request, reqId);
*
*	return r;
* }
*
* void
* MyAppClass::void OnDownloadCompleted(RequestId reqId, const Tizen::Base::String& path)
* {
*	AppLog("Download is completed.");
* }
*
* void
* MyAppClass::OnDownloadFailed(RequestId reqId, result r, const Tizen::Base::String& errorCode)
* {
*	AppLog("Download failed.");
* }
*
* @endcode
*/

class _OSP_EXPORT_ DownloadManager
	: public Tizen::Base::Object
{
public:
	/**
	* Gets the download manager instance of an application.
	*
	* @since 2.0
	*
	* @return		A pointer to the %DownloadManager instance, @n
	*				else @c null if it fails
	* @exception     E_SUCCESS           The method is successful.
	* @exception     E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception     E_SYSTEM            The method cannot proceed due to a severe system error.
	* @remarks       The specific error code can be accessed using the GetLastResult() method.
	*/
	static DownloadManager* GetInstance(void);

	/**
	* Starts the download operation. @n
	* If this operation succeeds, the IDownloadListener::OnDownloadInProgress() method is called. @n
	*
	* @since 2.0
	* @privilege 	%http://tizen.org/privilege/download
	*
	* @return       An error code
	* @param[in]    request             The download request
	* @param[out]   reqId               The request ID
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		The URL of the download request is invalid.
	* @exception	E_ILLEGAL_ACCESS	Access to the path of the download request is denied due to insufficient permission.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception    E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception    E_SYSTEM            The method cannot proceed due to a severe system error.
	*/
	result Start(const DownloadRequest& request, RequestId& reqId);

	/**
	* Pauses the download operation of the specified request ID. @n
	* If this operation succeeds, the IDownloadListener::OnDownloadPaused() method is called.
	*
	* @since 2.0
	*
	* @return       An error code
	* @param[in]    reqId               The request ID returned by Start()
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		There is no download request for the specified @c reqId.
	* @exception	E_INVALID_OPERATION	The current download state prohibits the execution of this operation. @n
	*									The download state of the request ID is not downloading.
	* @exception    E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception    E_SYSTEM            The method cannot proceed due to a severe system error.
	*/
	result Pause(RequestId reqId);

	/**
	* Resumes the download operation of the specified request ID. @n
	* If this operation succeeds, the IDownloadListener::OnDownloadInProgress() method is called.
	*
	* @since 2.0
	*
	* @return       An error code
	* @param[in]    reqId               The request ID returned by Start()
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		There is no download request for the specified @c reqId.
	* @exception	E_INVALID_OPERATION	The current download state prohibits the execution of this operation. @n
	*									The download operation of the request ID is not paused.
	* @exception    E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception    E_SYSTEM            The method cannot proceed due to a severe system error.
	*/
	result Resume(RequestId reqId);

	/**
	* Cancels the download operation of the specified request ID.
	*
	* @since 2.0
	*
	* @return       An error code
	* @param[in]    reqId               The request ID returned by Start()
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		There is no download request for the specified @c reqId.
	* @exception    E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception    E_SYSTEM            The method cannot proceed due to a severe system error.
	*/
	result Cancel(RequestId reqId);

	/**
	* Gets the download request information of the specified request ID.
	*
	* @since 2.0
	*
	* @return       The download request
	* @param[in]    reqId               The request ID returned by Start()
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		There is no download request for the specified @c reqId.
	* @exception    E_OUT_OF_MEMORY     The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	DownloadRequest* GetDownloadRequestN(RequestId reqId) const;

	/**
	* Gets the download state of the given request ID. @n
	* If there is no download request for the request ID, DOWNLOAD_STATE_NONE will be returned.
	*
	* @since 2.0
	*
	* @return       The download state
	* @param[in]    reqId               The request ID returned by Start()
	*/
	DownloadState GetState(RequestId reqId) const;

	/**
	* Gets the MIME type of a download request.
	*
	* @since 2.0
	*
	* @return       An error code
	* @param[in]    reqId               The request ID returned by Start()
	* @param[out]   mimeType            The MIME type
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_ARG		There is no download request for the specified @c reqId.
	* @exception	E_INVALID_OPERATION	The current download state prohibits the execution of this operation. @n
	*									The download state of the request ID is not downloading or paused.
	* @exception    E_SYSTEM            The method cannot proceed due to a severe system error.
	*/
	result GetMimeType(RequestId reqId, Tizen::Base::String& mimeType) const;

	/**
	* Sets a download listener.
	*
	* @since 2.0
	*
	* @param[in] 	pListener           The download listener @n
	*				If this is @c null, it unsets the download listener.
	*/
	void SetDownloadListener(IDownloadListener* pListener);

private:
	/**
	* This default constructor is intentionally declared as private to implement the Singleton semantic.
	*/
	DownloadManager(void);

	/**
	* This destructor is intentionally declared as private to implement the Singleton semantic.
	*/
	virtual ~DownloadManager(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	DownloadManager(const DownloadManager& downloadManager);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	DownloadManager& operator =(const DownloadManager& downloadManager);

	friend class _DownloadManagerImpl;
	class _DownloadManagerImpl * __pDownloadManagerImpl;

}; // DownloadManager

} } // Tizen::Content

#endif //_FCNT_DOWNLOAD_MANAGER_H_

