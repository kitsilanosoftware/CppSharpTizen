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
 * @file			FCntVideoMetadata.h
 * @brief		This is the header file for the %VideoMetadata class.
 *
 * This header file contains the declarations of the %VideoMetadata class.
 */

#ifndef _FCNT_VIDEO_METADATA_H_
#define _FCNT_VIDEO_METADATA_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}}

namespace Tizen { namespace Content
{

class _VideoMetadataImpl;

/**
 * @class	VideoMetadata
 * @brief	This class provides methods to access the video metadata.
 *
 * @since	2.0
 *
 * The %VideoMetadata class provides methods to access the video metadata that contains video content-specific attributes.
 *
 * The following example demonstrates how to use the %VideoMetadata class.
 *
 * @code
 * result
 * MyClass::TestVideoMetadata(void)
 * {
 *		Tizen::Base::String contentPath = Tizen::System::Environment::GetMediaPath() + L"Videos/video.mp4";
 *		VideoMetadata* pVideoMeta = ContentManagerUtil::GetVideoMetaN(contentPath);
 *		TryReturn(pVideoMeta != null, GetLastResult(), "ContentManagerUtil::GetVideoMetaN failed.");
 *
 *		// Width
 *		pVideoMeta->GetWidth();
 *
 *		// Height
 *		pVideoMeta->GetHeight();
 *
 *		// Duration
 *		pVideoMeta->GetDuration();
 *
 *		delete pVideoMeta;
 *
 *		return E_SUCCESS;
 * }
 * @endcode
 */
class _OSP_EXPORT_ VideoMetadata
	: virtual public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	VideoMetadata(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %VideoMetadata
	 */
	VideoMetadata(const VideoMetadata& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~VideoMetadata(void);

	/**
	 * Gets the width.
	 *
	 * @since		2.0
	 *
	 * @return		The width
	 */
	int GetWidth(void) const;

	/**
	 * Gets the height.
	 *
	 * @since		2.0
	 *
	 * @return		The height
	 */
	int GetHeight(void) const;

	/**
	 * Gets the duration.
	 *
	 * @since		2.0
	 *
	 * @return		The duration in milliseconds
	 */
	long GetDuration(void) const;

	/**
	 * Gets the frame rate.
	 *
	 * @since		2.0
	 *
	 * @return		The frame rate
	 */
	int GetFramerate(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the bit rate.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because a new method has been added. @n
	 *                  Instead of using this method, use GetAudioBitrate() or GetVideoBitrate().
	 * @since		2.0
	 * @endif
	 *
	 * @return		The bit rate in bits per second (bps)
	 * @remarks	There are two kinds of bit rates in a video file: audio and video. @n
	 *					The return value is the bit rate for the audio.
	 */
	int GetBitrate(void) const;

	/**
	 * Gets the audio bit rate.
	 *
	 * @since     2.0
	 *
	 * @return    The audio bit rate in bits per second (bps)
	 */
	int GetAudioBitrate(void) const;

	/**
	 * Gets the video bit rate.
	 *
	 * @since     2.0
	 *
	 * @return    The video bit rate in bits per second (bps)
	 */
	int GetVideoBitrate(void) const;

	/**
	 * Gets the genre.
	 *
	 * @since		2.0
	 *
	 * @return		The genre
	 */
	Tizen::Base::String GetGenre(void) const;

	/**
	 * Gets a comment of a video file.
	 *
	 * @since		2.1
	 *
	 * @return		A comment of a video file
	 */
	Tizen::Base::String GetComment(void) const;

	/**
	 * Gets the description of a video file.
	 *
	 * @since		2.1
	 *
	 * @return		The description of a video file
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the album art of a video.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the album art
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_DATA_NOT_FOUND		The album art does not exist.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetAlbumArtN(void) const;

	/**
	 * Compares the equality of values between two %VideoMetadata objects by overriding the Tizen::Base::Object::Equals() method.
	 *
	 * @since          2.0
	 *
	 * @return         @c true if all the fields in the objects are equal, @n
	 *                     else @c false
	 * @param[in]    rhs     The Tizen::Base::Object with which the comparison is done
 	 * @remarks		An instance of Tizen::Graphics::Bitmap is not taken into account in the comparisons.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance by overriding the Tizen::Base::Object::GetHashCode() method.
	 *
	 * @since         2.0
	 *
	 * @return        The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since          2.0
	 *
	 * @return         A reference to this instance
	 * @param[in]    rhs An instance of %VideoMetadata
	 */
	VideoMetadata& operator =(const VideoMetadata& rhs);

private:
	friend class _VideoMetadataImpl;
	_VideoMetadataImpl* __pImpl;

};  // Class VideoMetadata

}}  // Tizen::Content

#endif  // _FCNT_VIDEO_METADATA_H_
