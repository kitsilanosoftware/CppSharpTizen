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
 * @file			FCntImageContentInfo.h
 * @brief		This is the header file for the %ImageContentInfo class.
 *
 * This header file contains the declarations of the %ImageContentInfo class.
 */

#ifndef _FCNT_IMAGE_CONTENT_INFO_H_
#define _FCNT_IMAGE_CONTENT_INFO_H_

#include <FCntContentInfo.h>

namespace Tizen { namespace Content
{

class _ImageContentInfoImpl;

/**
 * @class	ImageContentInfo
 * @brief	This class provides methods to access the image content information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ImageContentInfo class provides methods to access the image content information that is extracted from a physical file. @n
 * Before getting the image content information, ContentManager must be used to create the content.
 *
 * For more information on the different types of content information, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %ImageContentInfo class.
 *
 * @code
 * result
 * MyClass::TestImageContentInfo(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		ImageContentInfo imageContentInfo;
 *		r = imageContentInfo.Construct(null);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		Tizen::Base::String sourcePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/flower.jpg";
 *		Tizen::Base::String destPath = Tizen::System::Environment::GetMediaPath() + L"Images/flower.jpg";
 *
 *		contentId = contentManager.CreateContent(sourcePath, destPath, false, &imageContentInfo);
 *		TryReturn(Tizen::Base::UuId::GetInvalidUuId() != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ ImageContentInfo
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
	ImageContentInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~ImageContentInfo(void);

	/**
	 * Initializes this instance of %ImageContentInfo with the specified parameter.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompImageContentInfoConstructPage "here".
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
	 *                     or ContentManager::CreateContent(const Tizen::Base::String&, const Tizen::Base::String&, bool, const ContentInfo*). @n
	 *                     If the content has coordinates as metadata, they are automatically set.
	 */
	result Construct(const Tizen::Base::String* pContentPath);

	/**
	 * @if OSPCOMPAT
	 * @page	CompImageContentInfoConstructPage Compatibility for the file path.
	 * @section	CompImageContentInfoConstructPageIssueSection Issues
	 *                 The content path argument of this method in OSP compatible applications has the following issues: @n
	 *                 <UL><li> The content path should be a path that begins with an allowed path prefix.
	 *                     For example, L"/Media/Images/flower.jpg", L"/Storagecard/Media/Images/flower.jpg". </UL></li>
	 *
	 * @section	CompImageContentInfoConstructPageSolutionSection Resolutions
	 *                 This issue has been resolved in Tizen. @n
	 *                 <UL><li> The content path can be a path without a specific allowed path prefix.
	 *                 Application do not need to know the specific allowed path prefixes.
	 *                 To get the directory path, use the following methods:  </UL></li>
	 *                 - For accessing the media directory, use Tizen::System::Environment::GetMediaPath().
	 *                 - For accessing the external storage, use Tizen::System::Environment::GetExternalStoragePath().
	 *
	 * @endif
	 */

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %ImageContentInfo with the specified parameters.
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
	 *															The coordinate information may be incorrect if it is outdated or has never been updated.
	 *                                                           To update the coordinate information or to get the exact value,
	 *                                                           use Tizen::Locations::LocationProvider::RequestLocationUpdates() before calling this method.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception		E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_IO								An I/O error has occurred.
	 * @remarks		The content path must start with @c '/Media' or @c '/Storagecard/Media'. @n
	 *                       The thumbnail path must start with @c '/Home', @c '/Media', or @c '/Storagecard/Media'. @n
	 *                       The permitted format for a thumbnail image is Bitmap (bmp).
	 * @endif
	 */
	virtual result Construct(const Tizen::Base::String& contentPath, const Tizen::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	 * Gets the width of the image file.
	 *
	 * @since		2.0
	 *
	 * @return		The width of the image file
	 */
	int GetWidth(void) const;

	/**
	 * Gets the height of the image file.
	 *
	 * @since		2.0
	 *
	 * @return		The height of the image file
	 */
	int GetHeight(void) const;

	/**
	 * Gets the title of the image file.
	 *
	 * @since		2.0
	 *
	 * @return		The title of the image file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the orientation of the image file.
	 *
	 * @since		2.0
	 *
	 * @return	   The orientation of the image file
	 */
	ImageOrientationType GetOrientation(void) const;

private:
	class _ImageContentData
	{
	public:
		_ImageContentData()
			: width(0)
			, height(0)
			, orientationType(IMAGE_ORIENTATION_TYPE_UNKNOWN)
			, title(L"") {}

		int width;
		int height;
		ImageOrientationType orientationType;
		Tizen::Base::String title;
	};

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ImageContentInfo(const ImageContentInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ImageContentInfo& operator =(const ImageContentInfo& rhs);

	result SetImageContentData(const _ImageContentData* pImageContentData);

	_ImageContentData* GetImageContentData(void);

private:
	_ImageContentData* __pImageContentData;

	friend class _ContentManagerImpl;
	friend class _ContentSearchImpl;
	friend class _ContentDirectoryImpl;
	friend class _ContentUtility;
	friend class _PlayListManagerImpl;
	friend class _PlayListImpl;

	friend class _ImageContentInfoImpl;
	_ImageContentInfoImpl* __pImpl;

};  // Class ImageContentInfo

}}  // Tizen::Content

#endif  // _FCNT_IMAGE_CONTENT_INFO_H_
