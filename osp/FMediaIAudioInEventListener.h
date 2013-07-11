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
 * @file			FMediaIAudioInEventListener.h
 * @brief			This is the header file for the %IAudioInEventListener interface.
 *
 * This header file contains the declarations of the %IAudioInEventListener interface.
 */

#ifndef _FMEDIA_IAUDIO_IN_EVENT_LISTENER_H_
#define _FMEDIA_IAUDIO_IN_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseByteBuffer.h>

namespace Tizen { namespace Media
{

/**
 * @interface	IAudioInEventListener
 * @brief			This interface represents a listener that receives the %AudioIn related events.
 *
 * @since		2.0
 *
 * The %IAudioInEventListener interface provides various methods that are called during the operations of %AudioIn.
 * %AudioIn captures audio data from the device in asynchronous mode,
 * and calls the listener's methods to pass the captured audio data.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/recording_pcm_audio.htm">Recording PCM Audio</a>.
 *
 */

class _OSP_EXPORT_ IAudioInEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IAudioInEventListener(void) {}

	/**
	*	Called when the device has filled up a buffer with PCM data completely.
	*
	* @since		2.0
	*
	*	@param[in]  pData	A pointer to the buffer containing the filled data @n
	*							The data address is same as the address added by AudioIn::AddBuffer().
	*/
	virtual void OnAudioInBufferIsFilled(Tizen::Base::ByteBuffer* pData) = 0;

	/**
	 *	Called when an input device is interrupted by a task of higher priority than AudioIn.
	 *
	 * @since		2.0
	 */
	virtual void OnAudioInInterrupted(void) = 0;

	/**
	 *	Called when an interrupted input device is released.
	 *
	 * @since		2.0
	 */
	virtual void OnAudioInReleased(void) = 0;

	/**
	*   Called when an audio recording focus is changed to another application.
	*
	*  @since		2.0
	*  @remarks		After the audio focus is being changed, the recording is stopped and the state of this instance is changed to AUDIOIN_STATE_STOPPED.
	*  @remarks		An application can start recording in the state of AUDIOIN_STATE_STOPPED but the interaction between device and user needs to record again.  Because there is a possibility of a race condition between applications which try to resume without the interaction.
	*		@remarks		An application cannot start recording again even in the state of AUDIOIN_STATE_STOPPED due to other applications which have a higher priority.
	*/

	virtual void OnAudioInAudioFocusChanged(void) {}
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioInEventListener_Reserved1(void){}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioInEventListener_Reserved2(void){}
};

}} // Tizen::Media

#endif
