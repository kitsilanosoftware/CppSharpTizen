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
 * @file			FMediaIVideoRecorderEventListener.h
 * @brief			This is the header file for the %IVideoRecorderEventListener interface.
 *
 * This header file contains the declarations of the %IVideoRecorderEventListener interface.
 */

#ifndef _FMEDIA_IVIDEO_RECORDER_EVENT_LISTENER_H_
#define _FMEDIA_IVIDEO_RECORDER_EVENT_LISTENER_H_

#include <FBase.h>
#include <FMediaRecorderTypes.h>

namespace Tizen { namespace Media
{

/**
 * @interface	IVideoRecorderEventListener
 * @brief			This interface represents a listener that receives events associated with the VideoRecorder class.
 * @since		2.0
 *
 * The %IVideoRecorderEventListener interface specifies the methods used to notify the status of the video recorder.
 * The video recorder engine works asynchronously. Therefore, it is important to implement this listener to ensure that the recorder flows correctly.
 * When an operation of each method is completed, an event is generated and a method of this interface is called.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/recording_video.htm">Recording Video</a>.
 */
class _OSP_EXPORT_ IVideoRecorderEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This is the destructor for this class.
	*
	* @since		2.0
	*/
	virtual ~IVideoRecorderEventListener(void) {}

	/**
	*	Called when the VideoRecorder::Stop() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnVideoRecorderStopped(result r) = 0;

	/**
	*	Called when the VideoRecorder::Cancel() method is completed.
	*
	* @since		2.0
	*
	* @param[in]   r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*/
	virtual void OnVideoRecorderCanceled(result r) = 0;

	/**
	*	Called when the VideoRecorder::Pause() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnVideoRecorderPaused(result r) = 0;

	/**
	*	Called when the VideoRecorder::Record() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnVideoRecorderStarted(result r) = 0;

	/**
	 *	Called when VideoRecorder reaches the end of the pre-defined time.
	 *
	 * @since		2.0
	 *
	 * @param[in]	endCondition	The end condition of the recording
	 * @see				VideoRecorder::SetMaxRecordingTime()
	 *
	 */
	virtual void OnVideoRecorderEndReached(RecordingEndCondition endCondition) = 0;

	/**
	*	Called when the VideoRecorder::Close() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*
	*/
	virtual void OnVideoRecorderClosed(result r) = 0;

	/**
	*	Called when an error occurred in VideoRecorder.
	*
	* @since		2.0
	*
	*	@param[in]	r		A video recorder error reason of type ::RecorderErrorReason
	*	@remarks			
	*				- ::RECORDER_ERROR_OUT_OF_STORAGE occurs when the recording size exceeds the maximum available capacity.
	*				- While recording to an external memory like MMC card, ::RECORDER_ERROR_STORAGE_FAILED can occur.
	*				- ::RECORDER_ERROR_DEVICE_FAILED occurs when the recording device has a problem like damaged shape or h/w failure.
	*/
	virtual void OnVideoRecorderErrorOccurred(RecorderErrorReason r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IVideoRecorderEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IVideoRecorderEventListener_Reserved2(void) {}

};

}}// Tizen::Media

#endif
