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
 * @file			FCntVideoContentInfo.h
 * @brief		This is the header file for the %VideoContentInfo class.
 *
 * This header file contains the declarations of the %VideoContentInfo class.
 */

#ifndef _FCNT_VIDEO_CONTENT_INFO_H_
#define _FCNT_VIDEO_CONTENT_INFO_H_

#include <FCntContentInfo.h>

namespace Tizen { namespace Content
{

class _VideoContentInfoImpl;

/**
 * @class	VideoContentInfo
 * @brief	This class provides methods to access the video content information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %VideoContentInfo class provides methods to access the video content information that is extracted from a physical file. @n
 * Before getting the video content information, the ContentManager class must be used to create the content.
 *
 * For more information on the different types of content information, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %VideoContentInfo class.
 *
 * @code
 * result
 * MyClass::TestVideoContentInfo(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		VideoContentInfo videoContentInfo;
 *		r = videoContentInfo.Construct(null);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		Tizen::Base::String sourcePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/flower.wmv";
 *		Tizen::Base::String destPath = Tizen::System::Environment::GetMediaPath() + L"Videos/flower.wmv";
 *
 *		contentId = contentManager.CreateContent(sourcePath, destPath, false, &videoContentInfo);
 *		TryReturn(Tizen::Base::UuId::GetInvalidUuId() != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ VideoContentInfo
	: public Tizen::Content::ContentInfo
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	VideoContentInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~VideoContentInfo(void);

	/**
	 * Initializes this instance of %VideoContentInfo with the specified parameter.
	 *
	 * @since			2.0
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
	 *                     If @c pContentPath is @c null, use ContentManager::CreateContent(const Tizen::Base::ByteBuffer&, const Tizen::Base::String&, const ContentInfo*) @n
	 *                     or ContentManager::CreateContent(const Tizen::Base::String&, const Tizen::Base::String&, bool, const ContentInfo*).
	 */
	result Construct(const Tizen::Base::String* pContentPath);

	/**
	 */

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %VideoContentInfo with the specified parameters.
	 *
	 * @brief <i> [Deprecated] </i>
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
	 * @remarks
	 * 					- The content path must start with @c '/Media' or @c '/Storagecard/Media'.
	 *					- The thumbnail path must start with @c '/Home', @c '/Media', or @c '/Storagecard/Media'. @n
	 *						The permitted format for a thumbnail image is bitmap (bmp).
	 * @endif
	 */
	virtual result Construct(const Tizen::Base::String& contentPath, const Tizen::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	 * Gets the genre of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The genre of the video file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetGenre(void) const;

	/**
	 * Gets the artist of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The artist of the video file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetArtist(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the bit rate of the video file.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because a new method has been added. @n
	 *                  Instead of using this method, use GetAudioBitrate() or GetVideoBitrate().
	 * @since		2.0
	 *
	 * @return		The bit rate in bits per second (bps)
	 * @remarks	There are two kinds of bit rates in a video file: audio and video. @n
	 *					The return value is the bit rate for the audio.
	 * @endif
	 */
	int GetBitrate(void) const;

	/**
	 * Gets the audio bit rate of the video file.
	 *
	 * @since     2.0
	 *
	 * @return    The audio bit rate in bits per second (bps)
	 */
	int GetAudioBitrate(void) const;

	/**
	 * Gets the video bit rate of the video file.
	 *
	 * @since     2.0
	 *
	 * @return    The video bit rate in bits per second (bps)
	 */
	int GetVideoBitrate(void) const;

	/**
	 * Gets the frame rate of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The frame rate of the video file
	 */
	int GetFramerate(void) const;

	/**
	 * Gets the width of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The width of the video file
	 */
	int GetWidth(void) const;

	/**
	 * Gets the height of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The height of the video file
	 */
	int GetHeight(void) const;

	/**
	 * Gets the title of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The title of the video file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the album name of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The album name of the video file, @n
	 *              else @c Unknown if the value is empty
	 */
	Tizen::Base::String GetAlbumName(void) const;

	/**
	 * Gets the duration of the video file.
	 *
	 * @since		2.0
	 *
	 * @return		The duration of the video file in milliseconds
	 */
	long GetDuration(void) const;

private:
	class _VideoContentData
	{
	public:
		_VideoContentData()
			: width(0)
			, height(0)
			, framerate(0)
			, audioBitrate(0)
			, videoBitrate(0)
			, duration(0)
			, pArtist(null)
			, pGenre(null)
			, pTitle(null)
			, pAlbumName(null) {}

		int width;
		int height;
		int framerate;
		int audioBitrate;
		int videoBitrate;
		long duration;
		Tizen::Base::String* pArtist;
		Tizen::Base::String* pGenre;
		Tizen::Base::String* pTitle;
		Tizen::Base::String* pAlbumName;
	};

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	VideoContentInfo(const VideoContentInfo& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	VideoContentInfo& operator =(const VideoContentInfo& rhs);

	result SetVideoContentData(const _VideoContentData* pVideoContentData);

	_VideoContentData* GetVideoContentData(void);

	result GetVideoMetadata(void) const;

private:
	_VideoContentData* __pVideoContentData;

	friend class _ContentManagerImpl;
	friend class _ContentSearchImpl;
	friend class _ContentDirectoryImpl;
	friend class _ContentUtility;
	friend class _PlayListManagerImpl;
	friend class _PlayListImpl;

	friend class _VideoContentInfoImpl;
	_VideoContentInfoImpl* __pImpl;

};  // Class VideoContentInfo

}}  // Tizen::Content

#endif  // _FCNT_VIDEO_CONTENT_INFO_H_
