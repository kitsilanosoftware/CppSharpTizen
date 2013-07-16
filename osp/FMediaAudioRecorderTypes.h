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
 * @file			FMediaAudioRecorderTypes.h
 * @brief			This is the header file for the %AudioRecordingFormat enumeration.
 *
 * This header file contains the descriptions for the %AudioRecordingFormat enumeration.
 */

#ifndef _FMEDIA_AUDIO_RECORDER_TYPES_H_
#define _FMEDIA_AUDIO_RECORDER_TYPES_H_

#include <FMediaRecorderTypes.h>

namespace Tizen { namespace Media
{

// The default audio recording time - 60 seconds
#define DEFAULT_AUDIORECORDING_TIME (60 * 1000)

// The default audio recording size - 300 kb
#define DEFAULT_AUDIORECORDING_SIZE (300 * 1024)

/**
 * @if OSPDEPREC
 * @enum AudioRecordingFormat
 *
 * Defines the formats for audio recording.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This enum is deprecated because new methods do not use it. @n
 * Instead of using this enum, use ::MediaContainerType.
 *
 * @since		2.0
 *
 * @see		AudioRecorder::SetFormat()
 * @see		AudioRecorder::GetFormat()
 * @endif
 */
enum AudioRecordingFormat
{
	AUDIORECORDING_FORMAT_DEFAULT,              /**< @if OSPDEPREC The default format @endif */
	AUDIORECORDING_FORMAT_AMR,                  /**< @if OSPDEPREC The AMR format @endif */
	AUDIORECORDING_FORMAT_WAVE,                 /**< @if OSPDEPREC The WAVE format @endif */
};

}}//Tizen::Media

#endif
