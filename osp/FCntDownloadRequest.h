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
 * @file		FCntDownloadRequest.h
 * @brief		This is the header file for the %DownloadRequest class.
 *
 * This header file contains the declarations of the %DownloadRequest class.
 */
#ifndef _FCNT_DOWNLOAD_REQUEST_H_
#define _FCNT_DOWNLOAD_REQUEST_H_

#include <FBaseResult.h>
#include <FBaseString.h>

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

