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
 * @file			FMediaMediaStreamInfo.h
 * @brief			This is the header file for the %MediaStreamInfo class.
 *
 * This header file contains the declarations of the %MediaStreamInfo class.
 */

#ifndef _FMEDIA_MEDIA_STREAM_INFO_H_
#define _FMEDIA_MEDIA_STREAM_INFO_H_

#include <FBaseObject.h>
#include <FBaseColIList.h>
#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FMediaAudioStreamInfo.h>
#include <FMediaVideoStreamInfo.h>

namespace Tizen { namespace Media
{
/**
 * @class	 MediaStreamInfo
 * @brief	 This class provides methods to get media stream information.
 *
 * @since		2.0
 *
 * The %MediaStreamInfo class provides methods to get media stream information, including:
 * - Content metadata, such as the title, artist, album title, genre, year, and album art.
 * - Audio and video stream information.
 *
 * This class supports multiple stream content that consists of several audio or video tracks.
 * This class provides a list of AudioStreamInfo and VideoStreamInfo that has the stream information of each audio or video track.
 *
 * For more detailed information, see %AudioStreamInfo and %VideoStreamInfo classes.
 *
 * The following example demonstrates how to use the %MediaStreamInfo class.
 * @code
 * #include <FBase.h>
 * #include <FApp.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Collection;
 * using namespace Tizen::Media;
 *
 * class MediaStreamInfoSample
 *	 : public Tizen::Media::IPlayerEventListener
 * {
 * public:
 *	 result Test(void);
 *
 * protected:
 *	 virtual void OnPlayerOpened(result r) {}
 *	 virtual void OnPlayerEndOfClip(void) {}
 *	 virtual void OnPlayerBuffering(int percent) {}
 *	 virtual void OnPlayerErrorOccurred(PlayerErrorReason r) {}
 *	 virtual void OnPlayerInterrupted() {}
 *	 virtual void OnPlayerReleased() {}
 *	 virtual void OnPlayerSeekCompleted(result r) {}
 *  virtual void OnPlayerAudioFocusChanged (void) {}
 *
 * private:
 *	 Player __player;
 * };
 *
 * result
 * MediaStreamInfoSample::Test(void)
 * {
 *	 MediaStreamInfo*  pStreamInfo = null;
 *	 const IList* pInfoList = null;
 *	 const AudioStreamInfo* pInfo = null;
 *	 String path = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.aac";
 *
 *	 __player.Construct(*this);
 *	 __player.OpenFile(path);
 *	 __player.Play();
 *
 *	 // Checks the Player's state
 *	 if (__player.GetState() != PLAYER_STATE_PLAYING)
 *	 {
 *		 return E_INVALID_STATE;
 *	 }
 *
 *	 // Gets the stream information from Player
 *	 pStreamInfo = __player.GetCurrentMediaStreamInfoN();
 *	 if (pStreamInfo == null)
 *	 {
 *		 return GetLastResult();
 *	 }
 *
 *	 pInfoList = pStreamInfo->GetAudioStreamInfoList();
 *	 if (pInfoList == null)
 *	 {
 *		 goto CATCH;
 *	 }
 *
 *	 pInfo = (const AudioStreamInfo*)pInfoList->GetAt(0);
 *	 if (pInfo == null)
 *	 {
 *		 goto CATCH;
 *	 }
 *
 *	 AppLog("AudioStreamInfo: codec:0x%x, bitRate:%d, channel:%d, sampleRate:%d",
 *			pInfo->GetCodecType(), pInfo->GetBitRate(),
 *			pInfo->GetChannelType(), pInfo->GetSampleRate());
 *
 *	 __player.Stop();
 *	 __player.Close();
 *	 return E_SUCCESS;
 *
 * CATCH:
 *	 delete pStreamInfo;
 *	 return E_SUCCESS;
 * }
 *
 * @endcode
 */
class _OSP_EXPORT_ MediaStreamInfo
	: public Tizen::Base::Object
{
public:
	/**
	*	This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~MediaStreamInfo(void);

public:
	/**
	*	Gets the title.
	*
	*	@since		2.0
	*
	*	@return		  The value of the title, @n
	*				  else an empty string if the content has no title
	*/
	Tizen::Base::String GetTitle(void) const;

	/**
	*	Gets the name of the artist from the content.
	*
	*	@since		2.0
	*
	*	@return					 The artist, @n
	*							 else an empty string if the content has no artist name
	*/
	Tizen::Base::String GetArtist(void) const;

	/**
	*	Gets the album title.
	*
	*	@since		2.0
	*
	*	@return		  The title of the album, @n
	*				  else an empty string if the content has no album
	*/
	Tizen::Base::String GetAlbumTitle(void) const;

	/**
	*	Gets the genre.
	*
	*	@since		2.0
	*
	*	@return		  The genre, @n
	*				  else an empty string if the content has no genre
	*/
	Tizen::Base::String GetGenre(void) const;

	/**
	*	Gets the year.
	*
	*	@since		2.0
	*
	*	@return		The year, @n
	*				else @c 0 if the content has no year
	*/
	int GetYear(void) const;

	/**
	*	Gets the album art.
	*
	*	@since		2.0
	*
	*	@return		The album art in the content, @n
	*				else @c null if the content has no album art
	*/
	Tizen::Base::ByteBuffer* GetAlbumArtN(void) const;

	/**
	*	Gets a list of the audio stream information.
	*
	*   @since		2.0
	*
	*	@return									A pointer to the list containing the audio stream information @n
	*											The value belongs to the AudioStreamInfo class.
	*	@exception	  E_SUCCESS				The method is successful.
	*	@exception	  E_INVALID_DATA			The stream cannot be parsed successfully.
	*	@exception	  E_SYSTEM				 A system error has occurred.
	*	@remarks				The specific error code can be accessed using the GetLastResult() method.
	*/
	const Tizen::Base::Collection::IList* GetAudioStreamInfoList(void) const;

	/**
	*	Gets a list of the video stream information.
	*
	*   @since		2.0
	*
	*	@return		 A pointer to a list containing the video stream information @n
	*								The value belongs to the VideoStreamInfo class.
	*	@exception	  E_SUCCESS				The method is successful.
	*	@exception	  E_INVALID_DATA			The stream cannot be parsed successfully.
	*	@exception	  E_SYSTEM				 A system error has occurred.
	*	@remarks				The specific error code can be accessed using the GetLastResult() method.
	*/
	const Tizen::Base::Collection::IList* GetVideoStreamInfoList(void) const;

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @return		The copy of this instance
	* @param[in]	rhs	An instance of %MediaStreamInfo
	*/
	MediaStreamInfo(const MediaStreamInfo & rhs);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since		2.0
	*
	* @return The reference of this instance
	* @param[in] rhs An instance of %MediaStreamInfo
	*/
	MediaStreamInfo & operator =(const MediaStreamInfo & rhs);

	/**
	* Compares the specified instance of Tizen::Base::Object with the calling instance of %MediaStreamInfo.
	*
	* @since		2.0
	*
	* @return	 @c true if the value of the specified instance equals the value of the current instance, @n
	*			  else @c false
	* @param[in]  rhs   The object to compare with the current instance
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return						  The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

private:
	/**
	*	This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	*	@param[in]		title					The value of the title @n
	*	@param[in]		artist					The value of the artist @n
	*	@param[in]		albumTitle				The value of the title of the album @n
	*	@param[in]		genre					The value of the genre @n
	*	@param[in]		year					The value of the year @n
	*	@param[in]		albumArt				The value of the album art @n
	*	@param[in]		pAudioStream			A pointer to an audio stream list @n
	*	@param[in]		pVideoStream			A pointer to a video stream list @n
	*	@param[in]		titleException			An exception generated due to the title of audio or video @n
	*	@param[in]		audioStreamException	The exception generated during audio streaming @n
	*	@param[in]		videoStreamException	The exception generated during video streaming @n
	*/
	MediaStreamInfo(const Tizen::Base::String& title, const Tizen::Base::String& artist, const Tizen::Base::String& albumTitle, const Tizen::Base::String& genre, int year, Tizen::Base::ByteBuffer* pAlbumArt, Tizen::Base::Collection::IList* pAudioStream, Tizen::Base::Collection::IList* pVideoStream, result audioStreamException, result videoStreamException);

private:
	class _MediaStreamInfoImpl *__pMediaStreamInfoImpl;
	friend class _PlayerImpl;
};

}}//Tizen::Media

#endif
