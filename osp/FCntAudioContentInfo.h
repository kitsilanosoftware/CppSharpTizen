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
 * @file			FCntAudioContentInfo.h
 * @brief		This is the header file for the %AudioContentInfo class.
 *
 * This header file contains the declarations of the %AudioContentInfo class.
 */

#ifndef _FCNT_AUDIO_CONTENT_INFO_H_
#define _FCNT_AUDIO_CONTENT_INFO_H_

#include <FCntContentInfo.h>

namespace Tizen { namespace Content
{

class _AudioContentInfoImpl;

/**
 * @class	AudioContentInfo
 * @brief	This class provides methods to access the audio content information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %AudioContentInfo class provides methods to access the audio content information that is extracted from a physical file. @n
 * Before getting the audio content information, ContentManager must be used to create the content.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_attributes.htm#media">Device Content Attributes</a>.
 *
 * The following example demonstrates how to use the %AudioContentInfo class.
 *
 * @code
 * result
 * MyClass::TestAudioContentInfo(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		AudioContentInfo audioContentInfo;
 *		r = audioContentInfo.Construct(null);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		Tizen::Base::String sourcePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/flower.wma";
 *		Tizen::Base::String destPath = Tizen::System::Environment::GetMediaPath() + L"Sounds/flower.wma";
 *
 *		contentId = contentManager.CreateContent(sourcePath, destPath, false, &audioContentInfo);
 *		TryReturn(Tizen::Base::UuId::GetInvalidUuId() != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ AudioContentInfo
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
	AudioContentInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~AudioContentInfo(void);

	/**
	 * Initializes this instance of %AudioContentInfo with the specified parameter.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompAudioContentInfoConstructPage "here".
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
	 * @page	CompAudioContentInfoConstructPage Compatibility for the file path.
	 * @section	CompAudioContentInfoConstructPageIssueSection Issues
	 *                 The content path argument of this method in OSP compatible applications has the following issues: @n
	 *                 -# The content path should be a path that begins with an allowed path prefix. @n
	 *                     For example, L"/Media/Images/flower.jpg", L"/Storagecard/Media/Images/flower.jpg".
	 *
	 * @section	CompAudioContentInfoConstructPageSolutionSection Resolutions
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
	 * @if OSPDEPREC
	 * Initializes this instance of %AudioContentInfo with the specified parameters.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates. @n
	 *                      Instead of using this method, use Construct(const Tizen::Base::String*). @n
	 *                      To set the coordinates in the ContentInfo instance, use ContentInfo::SetCoordinates(const Tizen::Locations::Coordinates&).
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	contentPath					The content path
	 * @param[in]	thumbnailPath				The thumbnail path
	 * @param[in]	setGps							Set to @c true to save the device's last known coordinates in the ContentInfo instance, @n
	 *												else @c false @n
	 *												The coordinate information may be incorrect if it is outdated or has never been updated. @n
	 *                                              To update the coordinate information or to get the exact value,
	 *                                              use Tizen::Locations::LocationProvider::RequestLocationUpdates() before calling this method.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_IO								An I/O error has occurred.
	 * @remarks		The content path must start with @c '/Media' or @c '/Storagecard/Media'. @n
	 *						The thumbnail path must start with @c '/Home', @c '/Media', or @c '/Storagecard/Media'. @n
	 *						The permitted format for a thumbnail image is Bitmap (bmp).
	 * @endif
	 */
	virtual result Construct(const Tizen::Base::String& contentPath, const Tizen::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	 * Gets the genre information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The genre information of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetGenre(void) const;

	/**
	 * Gets the artist information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The artist information of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetArtist(void) const;

	/**
	 * Gets the composer information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The composer information of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetComposer(void) const;

	/**
	 * Gets the album name of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The album name of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetAlbumName(void) const;

	/**
	 * Gets the release year information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The release year information of the audio file
	 */
	int GetReleaseYear(void) const;

	/**
	 * Gets the bit rate information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The bit rate in bits per second (bps)
	 */
	int GetBitrate(void) const;

	/**
	 * Gets the title of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The title of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the copyright of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The copyright of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetCopyright(void) const;

	/**
	 * Gets the track information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The track information of the audio file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetTrackInfo(void) const;

	/**
	 * Gets the duration of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The duration of the audio file in milliseconds
	 */
	long GetDuration(void) const;

private:
	class _AudioContentData
	{
	public:
		_AudioContentData()
			: bitrate(0)
			, releaseYear(0)
			, duration(0)
			, pTitle(null)
			, pAlbumName(null)
			, pArtist(null)
			, pComposer(null)
			, pGenre(null)
			, pCopyright(null)
			, pTrackInfo(null) {}

		int bitrate;
		int releaseYear;
		long duration;
		Tizen::Base::String* pTitle;
		Tizen::Base::String* pAlbumName;
		Tizen::Base::String* pArtist;
		Tizen::Base::String* pComposer;
		Tizen::Base::String* pGenre;
		Tizen::Base::String* pCopyright;
		Tizen::Base::String* pTrackInfo;
	};

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	AudioContentInfo(const AudioContentInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	AudioContentInfo& operator =(const AudioContentInfo& rhs);

	result SetAudioContentData(const _AudioContentData* pAudioContentData);

	_AudioContentData* GetAudioContentData(void);

private:
	_AudioContentData* __pAudioContentData;

	friend class _ContentManagerImpl;
	friend class _ContentSearchImpl;
	friend class _ContentDirectoryImpl;
	friend class _ContentUtility;
	friend class _PlayListManagerImpl;
	friend class _PlayListImpl;

	friend class _AudioContentInfoImpl;
	_AudioContentInfoImpl* __pImpl;

};  // Class AudioContentInfo

}}  // Tizen::Content

#endif  // _FCNT_AUDIO_CONTENT_INFO_H_
