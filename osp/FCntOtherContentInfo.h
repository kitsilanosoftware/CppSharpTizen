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
 * @file			FCntOtherContentInfo.h
 * @brief		This is the header file for the %OtherContentInfo class.
 *
 * This header file contains the declarations of the %OtherContentInfo class.
 */

#ifndef _FCNT_OTHER_CONTENT_INFO_H_
#define _FCNT_OTHER_CONTENT_INFO_H_

#include <FCntContentInfo.h>

namespace Tizen { namespace Content
{

class _OtherContentInfoImpl;

/**
 * @class	OtherContentInfo
 * @brief	This class provides methods to access the other content information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %OtherContentInfo class provides methods to access the other content information. @n
 * Before getting the other content information, the ContentManager class must be used to create the content. @n
 * If the E_UNSUPPORTED_FORMAT exception is received from the ContentManagerUtil::CheckContentType() method, the file can only be created as %OtherContentInfo.
 *
 * For more information on the different types of content information, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %OtherContentInfo class.
 *
 * @code
 * result
 * MyClass::TestOtherContentInfo(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		OtherContentInfo otherContentInfo;
 *		r = otherContentInfo.Construct(null);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		Tizen::Base::String sourcePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/flower.doc";
 *		Tizen::Base::String destPath = Tizen::System::Environment::GetMediaPath() + L"Others/flower.doc";
 *
 *		contentId = contentManager.CreateContent(sourcePath, destPath, false, &otherContentInfo);
 *		TryReturn(Tizen::Base::UuId::GetInvalidUuId() != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ OtherContentInfo
	: public Tizen::Content::ContentInfo
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	OtherContentInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~OtherContentInfo(void);

	/**
	 * Initializes this instance of %OtherContentInfo with the specified parameter.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompOtherContentInfoConstructPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]	pContentPath					The content path
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_IO								An I/O error has occurred.
	 * @exception	E_SYSTEM						An internal error has occurred.
	 * @remarks		The @c pContentPath should start with directory path returned by either Tizen::System::Environment::GetMediaPath() or Tizen::System::Environment::GetExternalStoragePath(). @n
	 *                     If @c pContentPath is @c null, use ContentManager::CreateContent(const Tizen::Base::ByteBuffer&, const Tizen::Base::String&, const ContentInfo*)
	 *                     or ContentManager::CreateContent(const Tizen::Base::String&, const Tizen::Base::String&, bool, const ContentInfo*).
	 */
	result Construct(const Tizen::Base::String* pContentPath);

	/**
	 * @if OSPCOMPAT
	 * @page	CompOtherContentInfoConstructPage Compatibility for the file path.
	 * @section	CompOtherContentInfoConstructPageIssueSection Issues
	 *                 The content path argument of this method in OSP compatible applications has the following issues: @n
	 *                 -# The content path should be a path that begins with an allowed path prefix. @n
	 *                     For example, L"/Media/Images/flower.jpg", L"/Storagecard/Media/Images/flower.jpg".
	 *
	 * @section	CompOtherContentInfoConstructPageSolutionSection Resolutions
	 *                 This issue has been resolved in Tizen. @n
	 *                 -# The content path can be a path without a specific allowed path prefix. @n
	 *                 Application do not need to know the specific allowed path prefixes. @n
	 *                 To get the directory path, use the following methods: @n
	 *                 - For accessing the media directory, use Tizen::System::Environment::GetMediaPath().
	 *                 - For accessing the external storage, use Tizen::System::Environment::GetExternalStoragePath().
	 * @endif
	 */

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %OtherContentInfo with the specified parameters.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated   This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates. @n
	 *                       Instead of using this method, use Construct(const Tizen::Base::String*). @n
	 *                       To set the coordinates in the ContentInfo instance, use ContentInfo::SetCoordinates(const Tizen::Locations::Coordinates&).
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		contentPath					The content path
	 * @param[in]		thumbnailPath				The thumbnail path
	 * @param[in]		setGps							Set to @c true to save the device's last known coordinates in the ContentInfo instance, @n
	 *                                                           else @c false @n
	 *															The coordinate information may be incorrect if it is outdated or has never been updated. @n
	 *                                                           To update the coordinate information or to get the exact value,
	 *                                                           use Tizen::Locations::LocationProvider::RequestLocationUpdates() before calling this method.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception		E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_IO								An I/O error has occurred.
	 * @remarks		The content path must start with @c '/Media' or @c '/Storagecard/Media'. @n
	 *                       The thumbnail path must start with @c '/Home', @c '/Media', or @c '/Storagecard/Media'. @n
	 *                       The permitted format for a thumbnail image is bitmap (bmp).
	 * @endif
	 */
	virtual result Construct(const Tizen::Base::String& contentPath, const Tizen::Base::String& thumbnailPath = L"", bool setGps = false);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	OtherContentInfo(const OtherContentInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	OtherContentInfo& operator =(const OtherContentInfo& rhs);

private:
	bool __isCreated;

	friend class _OtherContentInfoImpl;
	_OtherContentInfoImpl* __pImpl;

};  // class OtherContentInfo

}}  // Tizen::Content

#endif  // _FCNT_OTHER_CONTENT_INFO_H_
