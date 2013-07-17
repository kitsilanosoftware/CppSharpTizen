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
 * @file			FMediaIAudioOutEventListener.h
 * @brief			This is the header file for the %IAudioOutEventListener interface.
 *
 * This header file contains the declarations of the %IAudioOutEventListener interface.
 */

#ifndef _FMEDIA_IAUDIO_OUT_EVENT_LISTENER_H_
#define _FMEDIA_IAUDIO_OUT_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Media
{
class AudioOut;
/**
 * @interface	IAudioOutEventListener
 * @brief			This interface represents a listener that receives the AudioOut related events.
 *
 * @since		2.0
 *
 * @remarks			OnAudioOutInterrupted() is called when the application is interrupted by another application and OnAudioOutReleased() event can be called at the end of interruption.
 *			OnAudioOutAudioFocusChanged() is called when the application is interrupted by another application but the end of interruption is not notified.
 *			So, the application should handle both events to work properly on various sound scenarios between applications.
 *
 *  The %IAudioOutEventListener interface represents a listener that receives the AudioOut related events. The %AudioOut class works in asynchronous mode, and when the application plays audio data with the %AudioOut class,
 *  the caller must implement this interface to receive an event from %AudioOut.
 *
 *  For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/playing_pcm_audio.htm">Playing PCM Audio</a>.
 */

class _OSP_EXPORT_ IAudioOutEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IAudioOutEventListener(void) {}

	/**
	*	Called when the device has written a buffer completely.
	*
	* @since		2.0
	*
	*	@param[in]	src	An instance of AudioOut that fires the event
	*/
	virtual void OnAudioOutBufferEndReached(Tizen::Media::AudioOut& src) = 0;

	/**
	 *	Called when the output device is interrupted by a task of higher priority than AudioOut.
	 *
	 * @since		2.0
	 *
	 *	@param[in]	src							An instance of AudioOut that fires the event
	 */
	virtual void OnAudioOutInterrupted(Tizen::Media::AudioOut& src) = 0;

	/**
	 *	Called when the interrupted output device is released.
	 *
	 * @since		2.0
	 *
	 *	@param[in]	src							An instance of AudioOut that fires the event
	 */
	virtual void OnAudioOutReleased(Tizen::Media::AudioOut& src) = 0;

	/**
	*   Called when an audio playback focus is changed to another application.
	*
	*  @since		2.0
	*
	*  @param[in]	src		An instance of AudioOut that fires the event
	*  @remarks		
	*				- After the audio focus is being changed, the playback is stopped and the state of this instance is changed to ::AUDIOOUT_STATE_STOPPED.
	*  				- User interaction with the device is required for an application in @c AUDIOOUT_STATE_STOPPED state to resume playing. 
	*				This is to avoid the occurrence of a race condition among applications that try to start without user interaction.
	*				- An application cannot start playback again even in the state of @c AUDIOOUT_STATE_STOPPED due to other applications which have a higher priority.
	*/
	virtual void OnAudioOutAudioFocusChanged(Tizen::Media::AudioOut& src) {}
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioOutEventListener_Reserved1(void){}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioOutEventListener_Reserved2(void){}

};

}} // Tizen::Media

#endif
