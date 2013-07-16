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
 * @file			FCntAudioMetadata.h
 * @brief		This is the header file for the %AudioMetadata class.
 *
 * This header file contains the declarations of the %AudioMetadata class.
 */

#ifndef _FCNT_AUDIO_METADATA_H_
#define _FCNT_AUDIO_METADATA_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}}

namespace Tizen { namespace Content
{

class _AudioMetadataImpl;

/**
 * @class	AudioMetadata
 * @brief	This class provides methods to access the audio metadata.
 *
 * @since	2.0
 *
 * The %AudioMetadata class provides methods to access the audio metadata that contains audio content-specific attributes.
 *
 * The following example demonstrates how to use the %AudioMetadata class.
 *
 * @code
 * result
 * MyClass::TestAudioMetadata(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		Tizen::Base::String contentPath = Tizen::System::Environment::GetMediaPath() + L"Sounds/hot.mp3";
 *		AudioMetadata* pAudioMeta = ContentManagerUtil::GetAudioMetaN(contentPath);
 *		TryReturn(pAudioMeta != null, GetLastResult(), "ContentManagerUtil::GetAudioMetaN failed.");
 *
 *		// Title
 *		pAudioMeta->GetTitle();
 *
 *		// Frequency
 *		pAudioMeta->GetFrequency();
 *
 *		// Artist
 *		pAudioMeta->GetArtist();
 *
 *		// Album name
 *		pAudioMeta->GetAlbumName();
 *
 *		// Duration
 *		pAudioMeta->GetDuration();
 *
 *		// Year
 *		pAudioMeta->GetYear();
 *
 *		// Thumbnail
 *		Tizen::Media::Image image;
 *		r = image.Construct();
 *		if (IsFailed(r))
 *		{
 *			delete pAudioMeta;
 *			return r;
 *		}
 *
 *		Tizen::Graphics::Bitmap* pBitmap = pAudioMeta->GetThumbnailN();
 *		if (pBitmap == null)
 *		{
 *			delete pAudioMeta;
 *			return GetLastResult();
 *		}
 *
 *		Tizen::Base::String thumbnailPath = Tizen::System::Environment::GetMediaPath() + L"Images/audio.bmp";
 *		r = image.EncodeToFile(*pBitmap, Tizen::Media::IMG_FORMAT_BMP, thumbnailPath, false);
 *		if (IsFailed(r))
 *		{
 *			delete pAudioMeta;
 *			delete pBitmap;
 *			return r;
 *		}
 *
 *		delete pAudioMeta;
 *		delete pBitmap;
 *
 *		return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ AudioMetadata
	: virtual public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	AudioMetadata(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %AudioMetadata
	 */
	AudioMetadata(const AudioMetadata& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~AudioMetadata(void);

	/**
	 * Gets the title of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The title of the audio file
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the bit rate of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The audio bit rate in bits per second (bps)
	 */
	int GetBitrate(void) const;

	/**
	 * Gets the frequency of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The frequency in hertz (Hz)
	 */
	int GetFrequency(void) const;

	/**
	 * Gets the artist information of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The artist information of the audio file
	 */
	Tizen::Base::String GetArtist(void) const;

	/**
	 * Gets the album name of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The album name of the audio file
	 */
	Tizen::Base::String GetAlbumName(void) const;

	/**
	 * Gets the comment of the audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The comment of the audio file
	 */
	Tizen::Base::String GetComment(void) const;

	/**
	 * Gets the description of an audio file.
	 *
	 * @since		2.1
	 *
	 * @return		The description of an audio file
	 */
	Tizen::Base::String GetDescription(void) const;

	/**
	 * Gets the track number of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The track number of an audio file
	 */
	int GetTrack(void) const;

	/**
	 * Gets the genre information of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The genre information of an audio file
	 */
	Tizen::Base::String GetGenre(void) const;

	/**
	 * Gets the composer information of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The composer information of an audio file
	 */
	Tizen::Base::String GetComposer(void) const;

	/**
	 * Gets the copyright information of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The copyright information of an audio file
	 */
	Tizen::Base::String GetCopyright(void) const;

	/**
	 * Gets the duration of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The duration in milliseconds
	 */
	long GetDuration(void) const;

	/**
	 * Gets the year information of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The year information of an audio file
	 */
	int GetYear(void) const;

	/**
	 * Gets the track information of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The track number/position in set
	 * @remarks	This method returns track information that is embedded in the content metadata. @n
	 *					The format returned can be like "4/9" or "4" (in case the position is not available).
	 */
	Tizen::Base::String GetTrackInfo(void) const;

	/**
	 * Gets the recording date of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The recording date of an audio file
	 */
	Tizen::Base::String GetRecordingDate(void) const;

	/**
	 * Gets the number of channels of an audio file.
	 *
	 * @since		2.0
	 *
	 * @return		The number of channels of an audio file
	 * @remarks	A monophonic stream has one channel and a stereophonic stream has two channels. @n
	 *					Valid values are either @c 1 or @c 2.
	 */
	int GetChannelCount(void) const;

	/**
	 * Gets the thumbnail of an audio file.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the thumbnail image
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_DATA_NOT_FOUND		The thumbnail image does not exist.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks
	 *				- This method returns the thumbnail image that is resized to 80x60 pixels.
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetThumbnailN(void) const;

	/**
	 * Gets the album art of an audio file.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the album art
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_DATA_NOT_FOUND		The album art does not exist.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks
	 * 				- GetThumbnailN() returns the thumbnail image that is resized to 80x60 pixels.
	 *				- GetAlbumArtN() returns the original album art that is embedded in the content metadata.
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetAlbumArtN(void) const;

	/**
	 * Compares the equality of values between two %AudioMetadata objects by overriding the Tizen::Base::Object::Equals() method.
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
	 * @param[in]    rhs An instance of %AudioMetadata
	 */
	AudioMetadata& operator =(const AudioMetadata& rhs);

private:
	friend class _AudioMetadataImpl;
	_AudioMetadataImpl* __pImpl;

};  // class AudioMetadata

}}  // Tizen::Content

#endif  // _FCNT_AUDIO_METADATA_H_
