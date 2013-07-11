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
 * @file			FMediaRecorderTypes.h
 * @brief			This is the header file for the enumerations of the AudioRecorder and VideoRecorder classes.
 *
 * This header file contains the definitions of the enumerations of the AudioRecorder and VideoRecorder classes.
 */

#ifndef _FMEDIA_RECORDER_TYPES_H_
#define _FMEDIA_RECORDER_TYPES_H_

namespace Tizen { namespace Media
{

/**
 * @enum RecorderState
 *
 * Defines the state of the recorder.
 *
 * @since		2.0
 *
 * @see		AudioRecorder::GetState()
 * @see		VideoRecorder::GetState()
 */
enum RecorderState
{
	RECORDER_STATE_INITIALIZED,	 /**< The recorder is initialized */
	RECORDER_STATE_OPENED,		  /**< The file to write into is opened */
	RECORDER_STATE_ENDOF_FILE,	  /**< The recorder has reached the end of size or time */
	RECORDER_STATE_STOPPING,		/**< The recorder stops recording */
	RECORDER_STATE_STOPPED,		 /**< The recorder is stopped and has no current record-time @n
										 However, the media content is opened and initialized. */
	RECORDER_STATE_PAUSING,		 /**< The recorder is paused at a specific position */
	RECORDER_STATE_PAUSED,		  /**< The recorder is paused */
	RECORDER_STATE_STARTING,		/**< The recording operation is starting */
	RECORDER_STATE_RECORDING,	   /**< The recording state of the recorder */
	RECORDER_STATE_CLOSING,		 /**< The recorder process is closing */
	RECORDER_STATE_CLOSED,		  /**< The file is closed */
	RECORDER_STATE_ERROR,		   /**< An error has occurred in the recorder */
};

/**
 * @enum RecordingQuality
 *
 * Defines the quality of the recorder.
 *
 * @since		2.0
 *
 * @see	AudioRecorder::SetQuality()
 * @see	AudioRecorder::GetQuality()
 * @see	VideoRecorder::SetQuality()
 * @see	VideoRecorder::GetQuality()

 */
enum RecordingQuality
{
	RECORDING_QUALITY_LOW,				  /**< The low quality */
	RECORDING_QUALITY_MEDIUM,			   /**< The medium quality */
	RECORDING_QUALITY_HIGH,				 /**< The high quality */
};

/**
 * @enum RecordingEndCondition
 *
 * Defines the record ending by reaching the limit.
 *
 * @since		2.0
 *
 * @see	AudioRecorder::SetMaxRecordingTime()
 * @see	VideoRecorder::SetMaxRecordingTime()
 *
 */
enum RecordingEndCondition
{
	RECORDING_ENDOF_MAX_SIZE,		   /**< The end of file size */
	RECORDING_ENDOF_MAX_TIME,		   /**< The end of time */
};

/**
 * @enum RecorderErrorReason
 *
 * Defines the error reasons of the recorder.
 *
 * @since		2.0
 */
enum RecorderErrorReason
{
	RECORDER_ERROR_NONE,						// Undefined error
	RECORDER_ERROR_OUT_OF_STORAGE,		  /**< The storage is insufficient */
	RECORDER_ERROR_STORAGE_FAILED,		  /**< The device storage access has failed */
	RECORDER_ERROR_DEVICE_FAILED,		   /**< The recording device has failed */
};

/**
 * @enum RecordingRotation
 *
 * Defines the recording rotation of the recorder.
 *
 * @since		2.0
 */
enum RecordingRotation
{
	RECORDING_ROTATION_NONE,		/**< The recording rotation: None */
	RECORDING_ROTATION_90,			/**< The recording rotation: 90 degree rotation */
	RECORDING_ROTATION_180,			/**< The recording rotation: 180 degree rotation */
	RECORDING_ROTATION_270,			/**< The recording rotation: 270 degree rotation */
};

}}

#endif
