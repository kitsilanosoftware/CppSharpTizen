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
 * @file		FMediaIPlayerEventListener.h
 * @brief		This is the header file for the %IPlayerEventListener interface.
 *
 * This header file contains the declarations of the %IPlayerEventListener interface.
 */

#ifndef _FMEDIA_IPLAYER_EVENT_LISTENER_H_
#define _FMEDIA_IPLAYER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FMediaPlayerTypes.h>

namespace Tizen { namespace Media
{

/**
 * @interface	IPlayerEventListener
 * @brief			This interface provides a listener for media playing events.
 *
 * @since		2.0
 *
 * The %IPlayerEventListener interface specifies the methods used to notify the status of the media player during the media playing events.
 * The player engine works asynchronously. Therefore, it is important to implement this listener to ensure that the player flows correctly.
 * When each operation of the Player is completed, an event is generated, and a method from this class is called.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/playing_audio.htm">Playing Audio</a> and
 <a href="../org.tizen.native.appprogramming/html/guide/media/playing_video.htm">Playing Video</a>.
 */

class _OSP_EXPORT_ IPlayerEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IPlayerEventListener(void) {}

	/**
	*	Called when an audio/video content is opened asynchronously.
	*
	*   @since		2.0
	*
	*	@param[in]	 r									The cause of the error
	*	@exception	 E_SUCCESS							The method is successful.
	*	@exception	 E_SYSTEM							A system error has occurred.
	*	@exception	 E_CONNECTION_FAILED				The network connection has failed.
	*   @exception	 E_UNSUPPORTED_FORMAT				The specified format is not supported.
	*   @exception	 E_UNSUPPORTED_CODEC				The specified codec is not supported.
	*	@exception	 E_OUT_OF_MEMORY					The memory is insufficient.
	*	@see		Player::OpenFile(), Player::OpenUrl(), Player::OpenBuffer()
	*/
	virtual void OnPlayerOpened(result r) = 0;

	/**
	*	Called when the Player reaches the end of the clip.
	*
	* @since		2.0
	*/
	virtual void OnPlayerEndOfClip(void) = 0;

	/**
	*	Called when the position of the audio/video content moves asynchronously.
	*
	* @since		2.0
	*
	*	@param[in] r				  The cause of the error
	*	@exception	 E_SUCCESS		The method is successful.
	*	@exception	 E_SYSTEM		A system error has occurred.
	*	@see				 Player::SeekTo()
	*/

	virtual void OnPlayerSeekCompleted(result r){};


	/**
	*	Called when the streaming data is being buffered.
	*
	* @since		2.0
	*
	*	@param[in]	percent		The percentage of buffering is completed
	*	@see				Player::OpenUrl()
	*/
	virtual void OnPlayerBuffering(int percent) = 0;

	/**
	*	Called when an error has occurs while the Player is working.
	*
	* @since		2.0
	*
	*	@param[in]	r		A player error reason of type ::PlayerErrorReason
	*	@remarks			While playing streaming media, the player might throw an error like ::PLAYER_ERROR_CONNECTION_LOST
	*				::PLAYER_ERROR_STREAMING_TIMEOUT, ::PLAYER_ERROR_TRANSPORT or ::PLAYER_ERROR_SERVER. @n
	*				If the content includes invalid data, ::PLAYER_ERROR_INVALID_DATA may occur.
	*	@see				PlayerErrorReason
	*/
	virtual void OnPlayerErrorOccurred(Tizen::Media::PlayerErrorReason r) = 0;


	/**
	 *	Called when the Player is being interrupted by a task of higher priority than the Player.
	 *
	 * @since		2.0
	 */
	virtual void OnPlayerInterrupted(void) = 0;

	/**
	 *	Called when the interrupting Player has been released.
	 *
	 * @since		2.0
	 */
	virtual void OnPlayerReleased(void) = 0;
	/**
	*	Called when an audio playback focus is changed to another application.
	*
	*	@since		2.0
	*	@remarks	After the audio focus is being changed, the playback is paused or stopped and the state of this instance is changed to PLAYER_STATE_PAUSED or PLAYER_STATE_CLOSED.
	*	@remarks	An application can play again in the state of PLAYER_STATE_PAUSED but the interaction between device and user needs for playback again. Because there is a possibility of a race condition between applications which try to play without the interaction
	*	@remarks An application can not play again even in the state of PLAYER_STATE_PAUSED due to the application which has a higher priority.
	*/
	virtual void OnPlayerAudioFocusChanged(void) {}
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerEventListener_Reserved2(void) {}

};

}}  // Tizen::Media

#endif
