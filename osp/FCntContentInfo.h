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
 * @file			FCntContentInfo.h
 * @brief		This is the header file for the %ContentInfo class.
 *
 * This header file contains the declarations of the %ContentInfo class.
 */

#ifndef _FCNT_CONTENT_INFO_H_
#define _FCNT_CONTENT_INFO_H_

#include <FBaseUuId.h>
#include <FBaseDateTime.h>
#include <FCntTypes.h>
#include <FLocCoordinates.h>

namespace Tizen { namespace Locations
{
class Coordinates;
}}

namespace Tizen { namespace Graphics
{
class Bitmap;
}}

namespace Tizen { namespace Content
{

class _ContentInfoImpl;

/**
 * @class	ContentInfo
 * @brief	This class provides methods to manage the content information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ContentInfo class is an abstract base class. @n
 * ImageContentInfo, AudioContentInfo, VideoContentInfo, and OtherContentInfo are derived from the %ContentInfo class.
 *
 * When a user creates content, its content information is created as a new pair. @n
 * When a user deletes content, its content information is deleted from the content database. @n
 * This class provides methods to get or to set the specific content information. @n
 * The physical file is not updated even if the set methods are called.
 *
 * For more information on the different types of content information, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %ContentInfo class.
 *
 * @code
 * result
 * MyClass::TestContentInfo(void)
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
class _OSP_EXPORT_ ContentInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~ContentInfo(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %ContentInfo with the specified parameters.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates.
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	contentPath           The content path
	 * @param[in]	thumbnailPath       The thumbnail path
	 * @param[in]	setGps                 Set to @c true to save the device's last known coordinates in the %ContentInfo instance, @n
	 *                                                else @c false
	 * @endif
	 */
	virtual result Construct(const Tizen::Base::String& contentPath, const Tizen::Base::String& thumbnailPath = L"", bool setGps = false) = 0;

	/**
	 * Gets the content ID.
	 *
	 * @since		2.0
	 *
	 * @return		The content ID
	 */
	ContentId GetContentId(void) const;

	/**
	 * Gets the content type.
	 *
	 * @since		2.0
	 *
	 * @return		The content type
	 */
	ContentType GetContentType(void) const;

	/**
	 * Gets the mime type.
	 *
	 * @since		2.0
	 *
	 * @return		The mime type
	 */
	Tizen::Base::String GetMimeType(void) const;

	/**
	 * Gets the date and time of the created content.
	 *
	 * @since		2.0
	 *
	 * @return		The content's creation time (GMT)
	 */
	Tizen::Base::DateTime GetDateTime(void) const;

	/**
	 * Gets the file size of the content.
	 *
	 * @since		2.0
	 *
	 * @return		The file size of the content
	 */
	unsigned long GetContentSize(void) const;

	/**
	 * Gets the content name.
	 *
	 * @since		2.0
	 *
	 * @return		The content name
	 */
	Tizen::Base::String GetContentName(void) const;

	/**
	 * Gets the file path of the content.
	 *
	 * @since		2.0
	 *
	 * @return		The file path of the content
	 */
	Tizen::Base::String GetContentPath(void) const;

	/**
	 * Gets the coordinates of the location.
	 *
	 * @since		2.0
	 *
	 * @return		A reference to the coordinates
	 */
	const Tizen::Locations::Coordinates& GetCoordinates(void) const;

	/**
	 * Sets the coordinates of the location.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	coordinates			The user-defined coordinates
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetCoordinates(const Tizen::Locations::Coordinates& coordinates);

	/**
	 * Sets the location tag.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	locationTag			The new location tag
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetLocationTag(const Tizen::Base::String& locationTag);

	/**
	 * Gets the location tag.
	 *
	 * @since		2.0
	 *
	 * @return		The location tag
	 */
	Tizen::Base::String GetLocationTag(void) const;

	/**
	 * Sets the rating.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	rating				The new rating
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetRating(const Tizen::Base::String& rating);

	/**
	 * Gets the rating.
	 *
	 * @since		2.0
	 *
	 * @return		The rating
	 */
	Tizen::Base::String GetRating(void) const;

	/**
	 * Sets the category.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	category				The new category
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetCategory(const Tizen::Base::String& category);

	/**
	 * Gets the category.
	 *
	 * @since		2.0
	 *
	 * @return		The category
	 */
	Tizen::Base::String GetCategory(void) const;

	/**
	 * Sets the description.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	description				The new description
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 140 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetDescription(const Tizen::Base::String& description);

	/**
	 * Gets the description.
	 *
	 * @since		2.0
	 *
	 * @return		The description
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the thumbnail image.
	 *
	 * @if OSPCOMPAT
	 * @brief	<i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *					 For more information, see @ref CompContentInfoGetThumbnailNPage "here".
	 * @endif
	 *
	 * @return			A pointer to the thumbnail image
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_DATA_NOT_FOUND		The thumbnail image does not exist.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetThumbnailN(void) const;

	/**
	 * @if OSPCOMPAT
	 * @page		CompContentInfoGetThumbnailNPage Compatibility for GetThumbnailN().
	 * @section	CompContentInfoGetThumbnailNPageIssueSection Issue
	 *				The thumbnail size of this method in OSP compatible applications has the following issues: @n
	 *				<DIV> The size is changed from 80x60 pixels to the size of image which is returned from the platform since %Tizen</DIV>
	 *
	 * @endif
	 */

	/**
	 * Checks whether the content is DRM protected.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if this content has DRM, @n
	 *					else @c false
	 */
	bool IsDrmProtected(void) const;

	/**
	 * Gets the keyword.
	 *
	 * @since		2.0
	 *
	 * @return		The keyword
	 */
	Tizen::Base::String GetKeyword(void) const;

	/**
	 * Sets the content name.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	contentName			The new content name
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetContentName(const Tizen::Base::String& contentName);

	/**
	 * Sets the keyword.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	keyword					The new keyword
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetKeyword(const Tizen::Base::String& keyword);

	/**
	 * Sets the author.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	author					The new author
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetAuthor(const Tizen::Base::String& author);

	/**
	 * Gets the author.
	 *
	 * @since		2.0
	 *
	 * @return		The author
	 */
	Tizen::Base::String GetAuthor(void) const;

	/**
	 * Sets the provider.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	provider					The new content provider
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetProvider(const Tizen::Base::String& provider);

	/**
	 * Gets the provider.
	 *
	 * @since		2.0
	 *
	 * @return		The content provider
	 */
	Tizen::Base::String GetProvider(void) const;

	/**
	 * Gets the media format.
	 *
	 * @since		2.0
	 *
	 * @return		The media format
	 */
	Tizen::Base::String GetMediaFormat(void) const;

protected:
	//
	// This class is for internal use only.
	// Using this class can cause behavioral, security-related, and consistency-related issues in the application.
	//
	class _ContentData
	{
	public:
		_ContentData()
			: contentId(Tizen::Base::UuId::GetInvalidUuId())
			, storageType(0)
			, contentType(CONTENT_TYPE_UNKNOWN)
			, contentSize(0)
			, latitude(-200.0)
			, longitude(-200.0)
			, altitude(-200.0)
			, isDrm(false)
			, pThumbnailPath(null)
			, pAuthor(null)
			, pCategory(null)
			, pContentName(null)
			, pDescription(null)
			, pKeyword(null)
			, pLocationTag(null)
			, pProvider(null)
			, pRating(null) {}

		ContentId contentId;
		int storageType;
		ContentType contentType;
		unsigned long contentSize;
		Tizen::Base::DateTime dateTime;
		double latitude;
		double longitude;
		double altitude;
		bool isDrm;
		Tizen::Base::String contentPath;
		Tizen::Base::String mimeType;
		Tizen::Base::String* pThumbnailPath;
		Tizen::Base::String* pAuthor;
		Tizen::Base::String* pCategory;
		Tizen::Base::String* pContentName;
		Tizen::Base::String* pDescription;
		Tizen::Base::String* pKeyword;
		Tizen::Base::String* pLocationTag;
		Tizen::Base::String* pProvider;
		Tizen::Base::String* pRating;
	};

	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	ContentInfo(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Sets the content data.
	//
	// @since           2.0
	//
	// @return			An error code
	// @param[in]	pContentData				The content data
	// @exception	E_SUCCESS               The method is successful.
	// @exception	E_INVALID_ARG			The specified input parameter is invalid.
	// @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	//
	result SetContentData(const _ContentData* pContentData);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentInfo(const ContentInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentInfo& operator =(const ContentInfo& rhs);

	_ContentData* GetContentData(void);

private:
	_ContentData* __pContentData;
	mutable Tizen::Locations::Coordinates coordinates;

	friend class _ContentManagerImpl;
	friend class _ContentSearchImpl;
	friend class _ContentDirectoryImpl;
	friend class _ContentUtility;
	friend class _PlayListManagerImpl;
	friend class _PlayListImpl;

	friend class _ContentInfoImpl;
	_ContentInfoImpl* __pImpl;

};  // class ContentInfo

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_INFO_H_
