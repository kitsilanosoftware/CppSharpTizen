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
 * @file		FCntDownloadRequest.h
 * @brief		This is the header file for the %DownloadRequest class.
 *
 * This header file contains the declarations of the %DownloadRequest class.
 */
#ifndef _FCNT_DOWNLOAD_REQUEST_H_
#define _FCNT_DOWNLOAD_REQUEST_H_

#include <FBaseResult.h>
#include <FBaseString.h>
#include <FBaseColIMap.h>
#include <FCntTypes.h>

namespace Tizen { namespace Content
{

/**
* @class    DownloadRequest
* @brief    This class provides information of a download request.
*
* @since 2.0
*
* @final	This class is not intended for extension.
*
* The %DownloadRequest class provides information of a download request. It provides the URL of a download request, which is mandatory information. It also provides the destination directory path and the file name. The destination directory path and file name can be set by the SetDirectoryPath() and SetFileName() methods. @n
* If the download path is not specified, the data will be downloaded to the default download directory returned by Tizen::System::Environment::GetDefaultDownloadPath().
*
*/

class _OSP_EXPORT_ DownloadRequest
	: public Tizen::Base::Object
{
public:
	/**
	* Initializes this instance of %DownloadRequest with the specified URL. @n
	* The downloaded path is set to a default download directory returned by Tizen::System::Environment::GetDefaultDownloadPath().
	*
	* @since 2.0
	*
	* @param[in]  url		The URL of the download request
	*/
	DownloadRequest(const Tizen::Base::String& url);

	/**
	* Initializes this instance of %DownloadRequest with the specified URL and directory path.
	*
	* @since 2.0
	*
	* @param[in]  url		The URL of the download request
	* @param[in]  dirPath	The directory path of the data that will be downloaded
	*/
	DownloadRequest(const Tizen::Base::String& url, const Tizen::Base::String& dirPath);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since 2.0
	*
	* @param[in]  rhs		An instance of %DownloadRequest to copy
	*/
	DownloadRequest(const DownloadRequest& rhs);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~DownloadRequest(void);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @return		A reference to this instance
	* @param[in]	rhs		An instance of %DownloadRequest
	*/
	DownloadRequest& operator =(const DownloadRequest& rhs);

	/**
	 *	Checks whether the specified instance of Tizen::Base::Object is equivalent to the current instance of %DownloadRequest.
	 *
	 *	@since 2.0
	 *
	 *	@return		@c true if the specified instance of Tizen::Base::Object is equivalent to the current instance of %DownloadRequest, @n
	 *              else @c false
	 *	@param[in]	obj The object to compare with the current instance of %DownloadRequest
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 *	Gets the hash value of the current instance.
	 *
	 *	@since 2.0
	 *
	 *	@return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	* Sets the directory path of the data that will be downloaded.
	*
	* @since 2.0
	*
	* @param[in]  dirPath	The directory path
	*/
	void SetDirectoryPath(const Tizen::Base::String& dirPath); 

	/**
	* Sets the file name of the data to be downloaded.
	*
	* @since 2.0
	*
	* @param[in]  fileName	The file name
	*/
	void SetFileName(const Tizen::Base::String& fileName); 

	/**
	* Gets the URL of a download request.
	*
	* @since 2.0
	*
	* @return		The URL of this download request
	*/
	Tizen::Base::String GetUrl(void) const;

	/**
	* Gets the directory path of the data that will be downloaded.
	*
	* @since 2.0
	*
	* @return		The directory path
	*/
	Tizen::Base::String GetDirectoryPath(void) const;

	/**
	* Gets the file name of the data to be downloaded.
	*
	* @since 2.0
	*
	* @return		The file name
	*/
	Tizen::Base::String GetFileName(void) const;

	/**
	* Determines whether the system should show the download notification or not. @n
	* If @c true, the system posts notifications about this download request through the Tizen::Shell::NotificationManager. @n
	* By default, this value sets to @c true.
	*
	* @since 2.1
	*
	* @param[in] enable Set to @c true if the system shows a notification for this download request, @n
	*					else @c false
	* @see Tizen::Shell::NotificationManager
	*/
	void SetNotification(bool enable);

	/**
	* Sets extra data that is delivered to the application when the notification message is selected. @n
	* The extra data will be passed to the application through the
	* Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived() method.
	*
	* @since 2.1
	*
	* @return An error code
	* @param[in] pExtraData A pointer to an argument map of the Tizen::Base::String key and the Tizen::Base::String value pair
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_ARG Either of the following conditions has occurred:
	* - The argument is @c null.
	* - The argument is not a map of the Tizen::Base::String key and the Tizen::Base::String value pair.
	* @see Tizen::Shell::NotificationManager
	* @see Tizen::App::IAppControlProviderEventListener::OnAppControlRequestReceived()
	*/
	result SetNotificationExtraData(const Tizen::Base::Collection::IMap *pExtraData);

	/**
	* Sets to an allowed network type. @n
	* By default, all network types are allowed.
	*
	* @since 2.1
	*
	* @param[in] type The download network type
	*/
	void SetNetworkType(DownloadNetworkType type);

	/**
	* Checks whether the system should show a notification for this download request.
	*
	* @since 2.1
	*
	* @return @c true if the system should show a notification for this download request, @n
	* else @c false
	*/
	bool IsNotificationEnabled(void) const;

	/**
	* Gets extra data that is delivered to the application when the notification message is selected.
	*
	* @since 2.1
	*
	* @return The extra data map that consists of the Tizen::Base::String key and the Tizen::Base::String value pair
	*/
	const Tizen::Base::Collection::IMap* GetNotificationExtraData(void) const;

	/**
	* Gets an allowed network type.
	*
	* @since 2.1
	*
	* @return The network type
	*/
	DownloadNetworkType GetNetworkType(void) const;

	/**
	* Adds an HTTP header field.
	*
	* @since 2.1
	*
	* @return An error code
	* @param[in] field The HTTP header field
	* @param[in] value The value of the header field
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_ARG Either the field is empty or it already exists.
	*/
	result AddRequestHeader(const Tizen::Base::String& field, const Tizen::Base::String& value);

	/**
	* Sets an HTTP header field.
	*
	* @since 2.1
	*
	* @return An error code
	* @param[in] field The HTTP header field
	* @param[in] value The value of the header field
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_ARG Either the field is empty or it does not exist.
	*/
	result SetRequestHeader(const Tizen::Base::String& field, const Tizen::Base::String& value);

	/**
	* Removes an HTTP header field.
	*
	* @since 2.1
	*
	* @return An error code
	* @param[in] field The HTTP header field
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_ARG Either the field is empty or it does not exist.
	*/
	result RemoveRequestHeader(const Tizen::Base::String& field);

	/**
	* Gets the value of an HTTP header field.
	*
	* @since 2.1
	*
	* @return The value of the HTTP header field if successful, @n
	* else @c null if there is no HTTP header field
	* @param[in] field The HTTP header field
	*/
	Tizen::Base::String* GetRequestHeaderN(const Tizen::Base::String& field);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	DownloadRequest(void);

	friend class _DownloadRequestImpl;
	class _DownloadRequestImpl * __pDownloadRequestImpl;

}; // DownloadRequest

} } // Tizen::Content

#endif //_FCNT_DOWNLOAD_MANAGER_H_

