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
 * @file			FMediaPlayer.h
 * @brief			This is the header file for the %Player class.
 *
 * This header file contains the declarations of the %Player class.
 */

#ifndef _FMEDIA_PLAYER_H_
#define _FMEDIA_PLAYER_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseUtilUri.h>
#include <FBaseByteBuffer.h>
#include <FBaseObject.h>
#include <FBaseColIMap.h>
#include <FGrpBufferInfo.h>
#include <FGrpVideoTexture.h>
#include <FMediaPlayerTypes.h>
#include <FMediaAudioTypes.h>
#include <FMediaMediaStreamInfo.h>
#include <FMediaAudioManagerTypes.h>
#include <FMediaIPlayerEventListener.h>
#include <FMediaIPlayerVideoEventListener.h>
#include <FMediaIPlayerProgressiveDownloadListener.h>

namespace Tizen { namespace Media
{

/**
 * @class	Player
 * @brief	This class provides methods to play audio and video.
 *
 * @since		2.0
 *
 * The %Player class provides methods to play audio and video, including:
 * - Playing the audio or video content stored in the local storage (internal and external memory).
 * - Playing the audio or video content stream from the content server over RTSP or HTTP.
 * - Operating general controls for the audio or video content, such as play, pause, resume, and stop.
 * - Moving the audio or video content on the basis of time.
 * - Controlling the volume of the audio or video content.
 * - Looping the audio or video content.
 * - Getting the duration of an audio or the video content.
 * - Playing back multiple audio streams.
 *
 * The maximum count of the %Player instance is limited by Media::MediaCapability class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/playing_audio.htm">Playing Audio</a> and <a href="../org.tizen.native.appprogramming/html/guide/media/playing_video.htm">Playing Video</a>.
 *
 * The following example demonstrates how to use the %Player class to play an audio or video file.
 *
 * @code
 * #include <FBase.h>
 * #include <FGraphics.h>
 * #include <FUi.h>
 * #include <FApp.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Ui;
 * using namespace Tizen::Ui::Controls;
 * using namespace Tizen::Media;
 *
 * class PlayerSample
 *     : public Tizen::Ui::Controls::Form
 *     , public Tizen::Media::IPlayerEventListener
 *     , public Tizen::Media::IPlayerVideoEventListener
 * {
 * public:
 *     result StartVideo(void);
 *     result StartAudio(void);
 *     result StartVideoWithVideoEventListener(void);
 *     void Stop(void);
 *
 * protected:
 *     // IPlayerEventListener
 *     virtual void OnPlayerOpened(result r) {}
 *     virtual void OnPlayerEndOfClip(void) {}
 *     virtual void OnPlayerBuffering(int percent) {}
 *     virtual void OnPlayerErrorOccurred(PlayerErrorReason r) {}
 *     virtual void OnPlayerInterrupted(void) {}
 *     virtual void OnPlayerReleased(void) {}
 *     virtual void OnPlayerSeekCompleted(result r) {}
 *     virtual void OnPlayerAudioFocusChanged (void) {}
 *
 *     // IPlayerVideoEventListener
 *     virtual void OnVideoFrameDecoded(Player &src, BitmapPixelFormat bitmapPixelFormat, const Dimension &dim,
 *                                      const byte *pBuffer, int sizeOfBuffer, result r);
 *
 * private:
 *     Player __player;
 *     OverlayRegion *__pOverlay;
 * };
 *
 * PlayerSample::PlayerSample(void)
 * {
 *     __pOverlay = null;
 * }
 *
 * result
 * PlayerSample::StartVideo(void)
 * {
 *     result r = E_SUCCESS;
 *     Rectangle rect(0, 0, 320, 240);
 *     BufferInfo bufferInfo;
 *     String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp4";
 *
 *     // Gets OverlayRegion from this Form
 *     __pOverlay = GetOverlayRegionN(rect, OVERLAY_REGION_TYPE_NORMAL);
 *     if (__pOverlay == null)
 *     {
 *         return GetLastResult();
 *     }
 *
 *     __pOverlay->GetBackgroundBufferInfo(bufferInfo);
 *
 *     r = __player.Construct(*this, &bufferInfo);
 *     if (IsFailed(r))
 *     {
 *         goto CATCH;
 *     }
 *
 *     // Opens file synchronously
 *     r = __player.OpenFile(filePath, false);
 *     if (IsFailed(r))
 *     {
 *         goto CATCH;
 *     }
 *
 *     __player.SetLooping(true);
 *     __player.SetVolume(80);
 *
 *     r = __player.Play();
 *     if (IsFailed(r))
 *     {
 *         goto CATCH;
 *     }
 *
 *     return E_SUCCESS;
 *
 * CATCH:
 *     delete __pOverlay;
 *     __pOverlay = null;
 *     return r;
 * }
 *
 * result
 * PlayerSample::StartAudio(void)
 * {
 *     result r = E_SUCCESS;
 *     String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp3";
 *
 *     r = __player.Construct(*this);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     // Opens file synchronously
 *     r = __player.OpenFile(filePath, false);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     __player.SetVolume(80);
 *
 *     r = __player.Play();
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     return E_SUCCESS;
 * }
 *
 * void
 * PlayerSample::Stop(void)
 * {
 *     __player.Stop();
 *     __player.Close();
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 * }
 *
 *
 * result
 * PlayerSample::StartVideoWithVideoEventListener(void)
 * {
 *     result r = E_SUCCESS;
 *     Rectangle rect(0, 0, 320, 240);
 *     String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp4";
 *
 *     r = __player.Construct(*this, *this);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     r = __player.OpenFile(filePath);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     // Gets OverlayRegion from this Form
 *     __pOverlay = GetOverlayRegionN(rect, OVERLAY_REGION_TYPE_NORMAL);
 *     if (__pOverlay == null)
 *     {
 *         return GetLastResult();
 *     }
 *
 *     r = __player.Play();
 *     if (IsFailed(r))
 *     {
 *         goto CATCH;
 *     }
 *
 *     return E_SUCCESS;
 *
 * CATCH:
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 *     return r;
 *  }
 *
 * void
 * PlayerSample::OnVideoFrameDecoded(Player &src, BitmapPixelFormat bitmapPixelFormat, const Dimension &dim,
 *                                   const byte *pBuffer, int sizeOfBuffer, result r)
 * {
 *     ByteBuffer buf;
 *     OverlayRegionBufferPixelFormat overlayPixelFormat;
 *
 *     if (IsFailed(r))
 *     {
 *         return;
 *     }
 *
 *     if (__pOverlay == null)
 *     {
 *         return;
 *     }
 *
 *     if (bitmapPixelFormat == BITMAP_PIXEL_FORMAT_ARGB8888)
 *     {
 *         overlayPixelFormat = OVERLAY_REGION_BUFFER_PIXEL_FORMAT_ARGB8888;
 *     }
 *     else if (bitmapPixelFormat == BITMAP_PIXEL_FORMAT_RGB565)
 *     {
 *         overlayPixelFormat = OVERLAY_REGION_BUFFER_PIXEL_FORMAT_RGB565;
 *     }
 *     else // Unsupported pixel format
 *     {
 *         return;
 *     }
 *
 *     buf.Construct(pBuffer, 0, sizeOfBuffer, sizeOfBuffer);
 *     __pOverlay->SetInputBuffer(buf, dim, overlayPixelFormat);
 * }
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ Player
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to
	*           initialize this instance.
	* @see		Construct()
	*/
	Player(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	* This method deallocates the resources. This method must be called in the same thread as the Construct()
	* method.
	*
	* @since		2.0
	*
	* @see		Construct()
	*/
	virtual ~Player(void);

public:
	/**
	* Initializes this instance of %Player with the specified parameters.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener					An instance of IPlayerEventListener
	* @param[in]	pBufferInfo					The buffer information to display the video  @n
	*											This information is essential to play a video but not required for an audio content.
	* @exception	E_SUCCESS										The method is successful.
	* @exception	E_SYSTEM											A system error has occurred.
	* @exception 	E_OUT_OF_MEMORY    				The memory is insufficient. 
	* @exception	E_RESOURCE_UNAVAILABLE		The player's resources are unavailable.
	* @remarks      Multiple instances of %Player can be constructed.
	*/
	result Construct(IPlayerEventListener& listener, const Tizen::Graphics::BufferInfo* pBufferInfo = null);

	/**
	* Opens an audio or video file to be played. @n
	* This method works synchronously, but when the second parameter, @c isAsync is set to @c true, this method works asynchronously.
	* Note that a method that works asynchronously must implement a listener.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since		2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return			An error code
	* @param[in]		mediaLocalPath			The local file path of the media source
	* @param[in]		isAsync					Set to @c true for the asynchronous mode, @n
	*											else @c false for the synchronous mode
	* @exception		E_SUCCESS							The method is successful.
	* @exception		E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception		E_SYSTEM								A system error has occurred.
	* @exception		E_FILE_NOT_FOUND			The specified file cannot be found or accessed.
	* @exception   E_INVALID_DATA    	The specified file contains invalid data.
	* @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	* @see				Close()
	*/
	result OpenFile(const Tizen::Base::String& mediaLocalPath, bool isAsync = false);

	/**
	* Opens an audio or video streaming content to play through the specified URL. @n
	* This method works synchronously, but when the second parameter @c isAsync is set to @c true,
	* this method works asynchronously. Note that a method that works asynchronously must implement a listener.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	mediaUri				The URL of the media source
	* @param[in]	isAsync					Set to @c true for the asynchronous mode, @n
	*										else @c false for the synchronous mode
	* @exception	E_SUCCESS									The method is successful.
	* @exception	E_INVALID_STATE	      This instance is in an invalid state for this method.
	* @exception	E_CONNECTION_FAILED			The network connection has failed.
	* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	* @exception	E_SYSTEM										A system error has occurred.
	* @remarks	This method is not thread-safe when @c isAsync is @c false.
	* @remarks	Input URL should be encoded if there are non-alphanumeric characters in URL.
	* @see			Close()
	*/
	result OpenUrl(const Tizen::Base::Utility::Uri& mediaUri, bool isAsync = false);

	/**
	* Opens an audio or video content to play on the memory. @n
	* This method works synchronously, but when the second parameter @c isAsync is set to @c true, this method works asynchronously.
	* Note that a method that works asynchronously must implement a listener.
	*
	* @since		2.0
	*
	* @return			An error code
	* @param[in]		mediaBuffer				A pointer to the media source in the external memory
	* @param[in]		isAsync					Set to @c true for asynchronous mode, @n
	*											else @c false for synchronous mode
	* @exception		E_SUCCESS								The method is successful.
	* @exception		E_INVALID_STATE	    	This instance is in an invalid state for this method.
	* @exception		E_SYSTEM									A system error has occurred.
	* @exception		E_OBJ_NOT_FOUND				The specified media buffer cannot be found.
	* @exception   E_INVALID_DATA  		   The specified buffer contains invalid data.
	* @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	* @see				Close()
	*/
	result OpenBuffer(const Tizen::Base::ByteBuffer& mediaBuffer, bool isAsync = false);

	/**
	* Closes the audio or video content. @n
	* This method works synchronously.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS							The method is successful.
	* @exception	E_INVALID_STATE   	This instance is in an invalid state for this method.
	* @exception	E_SYSTEM								A system error has occurred.
	* @see			OpenFile(), OpenBuffer(), OpenUrl()
	*/
	result Close(void);

	/**
	* Plays the audio or video content. @n
	* The playback starts from the current position. In case of the ::PLAYER_STATE_ENDOFCLIP player state, the audio or video content
	* is played again.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS								The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY						The device cannot be approached because of other applications which have a higher priority.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_SYSTEM									A system error has occurred. @n
	*									If playback has been paused, it resumes from the last position. @n
	*									E_SYSTEM is returned when unsupported format or codec media data are received during streaming. @n
	*                                    E_SYSTEM is returned when the unsupport resolution is set for rendering .
	* @remarks		When this method is called after the %Player instance is created with the Construct() method that accepts the IPlayVideoEventListener
	* interface as a parameter, it delivers every video frame of a video content continuously until the state is changed to PLAYER_STATE_ENDOFCLIP,
	* or the Stop() or Pause() method is called .
	* @see			Stop(), Pause(), IPlayerVideoEventListener
	*/
	result Play(void);

	/**
	* Stops the playback of the audio or video content. This method works synchronously.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS							The method is successful.
	* @exception	E_INVALID_STATE    	This instance is in an invalid state for this method.
	* @exception	E_SYSTEM								A system error has occurred.
	* @remarks		In the Real Time Streaming Protocol (RTSP), this method stops the media stream and requests the termination of the network session.
	* @see			Play(), Pause()
	*/
	result Stop(void);

	/**
	* Pauses the playback of the audio or video content. @n
	* To resume the playback, the Play() method must be called. This method works synchronously.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS							The method is successful.
	* @exception	E_INVALID_STATE    	This instance is in an invalid state for this method.
	* @exception	E_SYSTEM								A system error has occurred.
	* @see			Play(), Stop()
	*/
	result Pause(void);

	/**
	* Gets the state of an audio or video player.
	*
	* @since		2.0
	*
	* @return		The current state of the player
	* @see			Close(), Play(), Stop(), Pause(), PlayerState
	*/
	PlayerState GetState(void) const;

	/**
	* Gets the time for the current playback position of the audio or video content. @n
	* Accuracy of the retrieved time is determined by the subsystem (for example, the time slice of the OS scheduler,
	* time resolution of the audio or video codec, or implementation of the audio or video player).
	* Note that it must not be assumed that this method can reach the exact position mentioned by GetDuration().
	*
	* @since		2.0
	*
	* @return		The current position of the player in milliseconds
	* @exception	E_SUCCESS							The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SeekTo()
	*/
	long GetPosition(void) const;

	/**
	* Seeks the current playback position of the audio or video content to the specified time. @n
	* This method works asynchronously. @n
	* Note that a method that works asynchronously must implement a listener. @n
	* This method only works for the PLAYER_STATE_PLAYING, PLAYER_STATE_PAUSED and PLAYER_STATE_OPENED(local file/buffer playback only) states of the player. @n
	* This method changes the playback position as well as the time value. @n
	* In video, it may not change position accurately.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	msTime				The time in milliseconds to move to the current playback position @n
	*									@c 0 indicates the starting position.
	* @exception	E_SUCCESS							The method is successful.
	* @exception	E_INVALID_STATE    	This instance is in an invalid state for this method. @n
	*					                While playing live streaming, this operation returns E_INVALID_STATE. @n
	*							        This method returns E_INVALID_STATE, if this method is called again before
	*									IPlayerEventListener::OnPlayerSeekCompleted() is called.
	* @exception	E_OUT_OF_RANGE				The specified time is out of range.
	* @exception	E_INVALID_DATA     	The media data is inappropriate for seeking.
	* @exception	E_SYSTEM								A system error has occurred.
	* @remarks		For video, this method delivers one video frame on the specified position through the video
	*				event. Before calling this method, the %Player instance must be created with the Construct()
	*				method has a parameter of the IPlayVideoEventListener interface .
	* @see			GetPosition(),  IPlayerVideoEventListener
	*/
	result SeekTo(long msTime);

	/**
	* Gets the total running time of the media source.
	*
	* @since		2.0
	*
	* @return			The running time of the media source in milliseconds
	* @exception		E_SUCCESS						The method is successful.
	* @exception		E_INVALID_STATE		This instance is in an invalid state for this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				While playing live streaming, this operation returns @c 0.
	* @remarks           This method is valid in the playing and paused state of this instance.
	* @see			GetPosition()
	*/
	long GetDuration(void) const;

	/**
	* Sets the specified value for the volume of an audio or video player.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	volume			The new value of volume @n
	*								The range of this parameter is @c 0 to @c 100 and it is proportional to the current media sound volume level in setting.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified volume is out of range.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state for this method.
	* @see			GetVolume(), IsMuted(), SetMute()
	*/
	result SetVolume(int volume);

	/**
	* Gets the current volume of an audio or video player.
	*
	* @since		2.0
	*
	* @return		The current volume level @n
	*				The range of this return value is @c 0 to @c 100.
	* @see			SetVolume(), IsMuted(), SetMute()
	*/
	int GetVolume(void) const;

	/**
	* Sets the mute status of an audio or video player.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	mute				Set to @c true to mute the audio or video player, @n
	*									else @c false
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @see          GetVolume(), SetVolume(), IsMuted()
	*/
	result SetMute(bool mute);

	/**
	* Checks the mute status of an audio or video player.
	*
	* @since		2.0
	*
	* @return		@c true if the audio or video player is muted, @n
	*				else @c false
	* @see          GetVolume(), SetVolume(), SetMute()
	*/
	bool IsMuted(void) const;

	/**
	* Sets an audio or video player to be in a loop. @n
	* Set the looping to @c true to continuously play the audio or video content.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	looping	            Set to @c true to play the audio or video content in a loop, @n
	*									else @c false
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @remarks		In streaming, this method throws E_INVALID_STATE for the cost of network.
	* @see          IsLooping()
	*/
	result SetLooping(bool looping);

	/**
	* Checks whether the audio or video player is in a loop.
	*
	* @since		2.0
	*
	* @return		@c true if the audio or video player is in a loop, @n
	*				else @c false
	* @see          SetLooping()
	*/
	bool IsLooping(void) const;

	/**
	* Gets the current media stream information.
	*
	* @since		2.0
	*
	* @return       A pointer to the MediaStreamInfo instance containing metadata for the current media stream
	* @exception    E_SUCCESS								The method is successful.
	* @exception    E_INVALID_STATE     This instance is in an invalid state for this method.
	* @exception    E_INVALID_CONTENT   The content is inappropriate to compose media stream information.
	* @exception    E_SYSTEM            A system error has occurred.
	* @remarks       This method returns a stream information of the media, which is currently being played.
	*               The specific error code can be accessed using the GetLastResult() method.
	*               This method must be called after Play() to get the correct data.
	* @see          MediaStreamInfo
	*/
	MediaStreamInfo* GetCurrentMediaStreamInfoN(void) const;

	/**
	* Sets the rendering buffer for the video playback.
	*
	* @since		2.0
	*
	* @return       An error code
	* @param[in]	bufferInfo			The buffer information to display the video
	* @exception 	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_SYSTEM							A system error has occurred. @n
	*                                   E_SYSTEM is returned when the unsupport resolution is set for rendering .
	* @remarks      This method works for the PLAYER_STATE_OPENED, PLAYER_STATE_ENDOFCLIP, PLAYER_STATE_STOPPED, PLAYER_STATE_PAUSED, and PLAYER_STATE_PLAYING states of the player.
	* @remarks		This method throws E_INVALID_STATE after the player instance is constructed with IPlayerVideoEventListener.
	*/
	result SetRenderingBuffer(const Tizen::Graphics::BufferInfo& bufferInfo);

	/**
	* Initializes this instance of %Player with the specified parameters.
	*
	* @since		2.0
	*
	* @return       An error code
	* @param[in]    listener                    An IPlayerEventListener instance
	* @param[in]    videoListener               An IPlayerVideoEventListener instance
	* @exception    E_SUCCESS                   The method is successful.
	* @exception    E_SYSTEM                    A system error has occurred.
	* @exception    E_RESOURCE_UNAVAILABLE      The player's resources are unavailable.
	* @exception    E_OUT_OF_MEMORY             The memory is insufficient. 
	* @remarks      This method constructs the %Player instance to render the video content into the buffer of the video event listener.
	* @see          IPlayerVideoEventListener
	*/
	result Construct(IPlayerEventListener& listener, IPlayerVideoEventListener& videoListener);

	/**
	* Captures the video frame. @n
	* This method delivers one video frame of a video content by using the IPlayVideoEventListener interface only once in the %Player instance. @n
	* This method works only for the PLAYER_STATE_OPENED state of the %Player instance, and the state of the %Player instance is changed to PLAYER_STATE_PAUSED from PLAYER_STATE_OPENED after calling this method.
	*
	* @since		2.0
	*
	* @return       An error code
	* @exception    E_SUCCESS									The method is successful.
	* @exception    E_INVALID_STATE					This instance is in an invalid state for this method. @n
	*										This method throws E_INVALID_STATE if the %Player instance is
	*										constructed without IPlayerVideoEventListener.
	* @exception    E_INVALID_OPERATION		This method is invalid for the current media content.
	* @exception    E_SYSTEM									A system error has occurred.
	* @remarks      In the Real Time Streaming Protocol (RTSP), this method does not work properly.
	* @see          IPlayerVideoEventListener
	*/
	result CaptureVideo(void);

	/**
	* Sets audio stream type
	*
	* @since		2.0
	*
	* @return       	  An error code
	* @param[in]    type                    			An audio stream type
	* @exception    E_SUCCESS					The method is successful.
	* @exception    E_INVALID_ARG				A specified input parameter is invalid.
	*/
	result SetAudioStreamType(AudioStreamType type);

	/**
	* Opens an audio or video streaming content to play through the specified URL with the HTTP header.@n
	* This method works asynchronously, thus application can call further APIs of %Player after IPlayerEventListener::OnPlayerOpened() is called.
	*
	* @since		2.0
	*
	* @return								An error code
	* @param[in]	url						The URL of the media source
	* @param[in]	pHeader					The list of field and value pairs that will be added in HTTP request header. @n
	The types of field and value are described in the Programming Guide. If @c null, then default values will be set
	*
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	* @exception	E_INVALID_ARG			The specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks	See Programming Guide for the detail information of supported HTTP header fields.
	* @remarks	Input URL should be encoded if there are non-alphanumeric characters in URL.
	* @see			Close()
	*/
	result OpenUrlAsync(const Tizen::Base::String& url, const Tizen::Base::Collection::IMap* pHeader = null);

	/**
	* Opens an audio or video streaming content to play through the specified HTTP URL with the HTTP header for the progressive download playback. @n
	* This method works asynchronously, thus application can call further APIs of %Player after IPlayerEventListener::OnPlayerOpened() is called.
	* The content information of the media source should be located at the beginning of the file for the progressive download playback. Otherwise, it does not guarantee to play and download media stream properly.
	*
	* @since		2.0
	*
	* @return								An error code
	* @param[in]	url						The URL of the media source
	* @param[in]	filePath				The file path on local file system that the downloaded content will be saved.
	* @param[in]	listener				The download listener
	* @param[in]	pHeader					The list of field and value pairs that will be added in HTTP request header. @n
	The types of field and value are described in the Programming Guide.
											If @c null, then default values will be set..
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	* @exception	E_INVALID_ARG			The specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks	Download will start when Play() is called.
	* @remarks	If the specified file name already exists, then the old file will be overwritten with the new one.
	* @remarks	See Programming Guide for the detail information of supported HTTP header fields.
	* @remarks	Input URL should be encoded if there are non-alphanumeric characters in URL.
	* @see			Close(), Play()
	*/
	result OpenUrlAsync(const Tizen::Base::String& url, const Tizen::Base::String& filePath, IPlayerProgressiveDownloadListener& listener, const Tizen::Base::Collection::IMap* pHeader = null);


	/**
	* Sets the interval of calling the progress event
	*
	* @since		2.0
	*
	* @param[in]	percent					The progress period interval as a percentage value.
	* @remark		If the server does not provide the information about the content size, progress event will occur randomly.
	* @remarks		If the percentage value is not set, @c 10 will be set as a default value.
	* @see			OnPlayerProgressiveDownloadInProgress(), IPlayerProgressiveDownloadListener
	*/
	void SetProgressiveDownloadIntervalByPercent(int percent);

	/**
	* Initializes this instance of %Player with the specified parameters.
	*
	* @since		2.0
	*
	* @return        An error code
	* @param[in]   listener                        An IPlayerEventListener instance
	* @param[in]   videoTexture                  An VideoTexture instance
	* @exception    E_SUCCESS                The method is successful.
	* @exception    E_INVALID_ARG      A specified input parameter is invalid.
	* @exception    E_RESOURCE_UNAVAILABLE  The player's resources are unavailable.
	* @remarks      This method constructs the %Player instance to render the video content into the video texture area.
	*/
	result Construct(IPlayerEventListener& listener, Tizen::Graphics::Opengl::VideoTexture& videoTexture);
private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 *  @since		2.0
	 */
	Player(const Player& rhs);

	/**
	 *The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 */
	Player& operator =(const Player& rhs);

	friend class _PlayerImpl;
	class _PlayerImpl* __pPlayerImpl;
};


}} // Tizen::Media

#endif
