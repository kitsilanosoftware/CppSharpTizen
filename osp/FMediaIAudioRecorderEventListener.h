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
 * @file			FMediaIAudioRecorderEventListener.h
 * @brief			This is the header file for the %IAudioRecorderEventListener interface.
 *
 * This header file contains the declarations of the %IAudioRecorderEventListener interface.
 */

#ifndef _FMEDIA_IAUDIO_RECORDER_EVENT_LISTENER_H_
#define _FMEDIA_IAUDIO_RECORDER_EVENT_LISTENER_H_

#include <FBase.h>
#include <FMediaRecorderTypes.h>

namespace Tizen { namespace Media
{

/**
 * @interface	IAudioRecorderEventListener
 * @brief		This interface represents a listener that receives events associated with the AudioRecorder class.
 *
 * @since		2.0
 *
 * The %IAudioRecorderEventListener interface represents a listener that receives events associated with the AudioRecorder class.
 * %IAudioRecorderEventListener specifies the methods used to notify the status of the audio recorder.
 * The audio recorder engine works asynchronously. Therefore, it is important to implement this listener to ensure that the recorder flows correctly.
 * When an operation of each method is completed, an event is generated and a method of this class is called.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/recording_audio.htm">Recording Audio</a>.
 */
class _OSP_EXPORT_ IAudioRecorderEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IAudioRecorderEventListener(void) {}

	/**
	*	Called when the AudioRecorder::Stop() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	r	The cause of the error
	*	@exception	  E_SUCCESS	The method is successful.
	*	@exception	  E_SYSTEM	A system error has occurred.
	*/
	virtual void OnAudioRecorderStopped(result r) = 0;

	/**
	*	Called when the AudioRecorder::Cancel() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*/
	virtual void OnAudioRecorderCanceled(result r) = 0;

	/**
	*	Called when the AudioRecorder::Pause() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnAudioRecorderPaused(result r) = 0;

	/**
	*	Called when the AudioRecorder::Record() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnAudioRecorderStarted(result r) = 0;

	/**
	*	Called when AudioRecorder reaches the end of the pre-defined time.
	*
	* @since		2.0
	*
	*	@param[in]	endCondition	The end condition of the recording
	* @see				AudioRecorder::SetMaxRecordingTime()
	*
	*/
	virtual void OnAudioRecorderEndReached(RecordingEndCondition endCondition) = 0;

	/**
	*	Called when the AudioRecorder::Close() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnAudioRecorderClosed(result r) = 0;

	/**
	*	Called when an error has occurred in AudioRecorder.
	*
	* @since		2.0
	*
	*	@param[in]	r		An audio recorder error reason of type ::RecorderErrorReason
	*	@remarks		
	*				- ::RECORDER_ERROR_OUT_OF_STORAGE occurs when the recording size exceeds the maximum available capacity.
	*				- While recording especially to the external memory like MMC card, ::RECORDER_ERROR_STORAGE_FAILED can occur.
	*				::RECORDER_ERROR_DEVICE_FAILED occurs when the recording device has a problem like damaged shape or hardware malfunction.
	*/
	virtual void OnAudioRecorderErrorOccurred(RecorderErrorReason r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioRecorderEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioRecorderEventListener_Reserved2(void) {}

};

}}// Tizen::Media

#endif
