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
 * @file		FMediaITonePlayerEventListener.h
 * @brief		This is the header file for the %ITonePlayerEventListener interface.
 *
 * This header file contains the declarations of the %ITonePlayerEventListener interface.
 */

#ifndef _FMEDIA_ITONE_PLAYER_EVENT_LISTENER_H_
#define _FMEDIA_ITONE_PLAYER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FMediaTonePlayer.h>

namespace Tizen { namespace Media
{
class TonePlayer;
/**
 * @interface	ITonePlayerEventListener
 * @brief		This interface provides a listener for the tone player events.
 *
 * @since		2.0
 *
 * @remarks			OnTonePlayerInterrupted() is called when the application is interrupted by another application and OnTonePlayerReleased() event can be called at the end of interruption.
 *			OnTonePlayerAudioFocusChanged() is called when the application is interrupted by another application but the end of interruption is not notified.
 *			So, the application should handle both events to work properly on various sound scenarios between applications.
 *
 * The %ITonePlayerEventListener interface specifies the methods used to notify the status of the tone player.
 */

class _OSP_EXPORT_ ITonePlayerEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~ITonePlayerEventListener(void) {}

	/**
	*	Called when the tone player reaches the end of the tone or the end of the list of tones.
	*
	*     @since		2.0
	*
	*	@param[in]	src		An instance of TonePlayer that fires the event
	*
	*/
	virtual void OnTonePlayerEndOfTone(Tizen::Media::TonePlayer& src) = 0;

	/**
	*	Called when the tone player is interrupted by a task of higher priority than the tone player.
	*
	*     @since		2.0
	*
	*	@param[in]	src		An instance of TonePlayer that fires the event
	*
	*/
	virtual void OnTonePlayerInterrupted(Tizen::Media::TonePlayer& src) = 0;

	/**
	*	Called when the interrupted tone player is released.
	*
	*     @since		2.0
	*
	*	@param[in]	src		An instance of TonePlayer that fires the event
	*
	*/
	virtual void OnTonePlayerReleased(Tizen::Media::TonePlayer& src) = 0;

	/**
	*	Called to notify an application that an error has occurred while the tone is played.
	*
	*   @since		2.0
	*
	*	@param[in]	src									An instance of TonePlayer that fires the event
	*	@param[in]	r									The cause of the error
	*	@exception	E_SYSTEM							A system error has occurred.
	*/
	virtual void OnTonePlayerErrorOccurred(Tizen::Media::TonePlayer& src, result r) = 0;

	/**
	*	Called when an audio playback focus is changed to another application.
	*
	*	@since		2.0
	*
	*	@param[in]		src		An instance of TonePlayer that fires the event
	*	@remarks		
	*					- After the audio focus is being changed, the playback is paused and the state of this instance is changed to ::TONE_PLAYER_STATE_PAUSED.
	*					- User interaction with the device is required for an application in @c TONE_PLAYER_STATE_PAUSED state to resume playing. 
	*					This is to avoid the occurrence of a race condition among applications that try to play without user interaction.
	*					- An application cannot start playback again even in the state of @c TONE_PLAYER_STATE_PAUSED due to other applications which have a higher priority.
	*/
	virtual void OnTonePlayerAudioFocusChanged(Tizen::Media::TonePlayer& src) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void ITonePlayerEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void ITonePlayerEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void ITonePlayerEventListener_Reserved3(void) {}

};

}}// Tizen::Media

#endif
