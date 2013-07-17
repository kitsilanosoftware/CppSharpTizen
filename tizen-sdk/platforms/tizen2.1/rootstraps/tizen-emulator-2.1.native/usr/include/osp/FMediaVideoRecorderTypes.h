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
 * @file			FMediaVideoRecorderTypes.h
 * @brief			This is the header file for the video recording enumerations.
 *
 * This header file contains the declarations of the video recording enumerations.
 */

#ifndef _FMEDIA_VIDEO_RECORDER_TYPES_H_
#define _FMEDIA_VIDEO_RECORDER_TYPES_H_

#include "FMediaRecorderTypes.h"

namespace Tizen { namespace Media
{

// 60 sec
#define DEFAULT_VIDEORECORDING_TIME 60000

// 1 Megabytes
#define DEFAULT_VIDEORECORDING_SIZE 1024 * 1024

/**
 * @if OSPDEPREC
 * @enum VideoRecordingFormat
 *
 * Defines the format of a video recorder.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This enum is deprecated because new methods do not use this enum. Instead of this enum, use
 *				::MediaContainerType.
 * @since		2.0
 *
 * @see		VideoRecorder::SetFormat()
 * @see		VideoRecorder::GetFormat()
 * @endif
 */
enum VideoRecordingFormat
{
	VIDEORECORDING_FORMAT_DEFAULT,                  /**< @if OSPDEPREC The default format @endif */
	VIDEORECORDING_FORMAT_MP4,                      /**< @if OSPDEPREC The MP4 format @endif */
	VIDEORECORDING_FORMAT_3GP,                      /**< @if OSPDEPREC The 3GP format @endif */
};

/**
 * @if OSPDEPREC
 * @enum VideoRecorderMode
 *
 * Defines the mode of a video recorder.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This enum is deprecated because new methods do not use this enum. For video only recording, instead of using this enum, use
 *				::CODEC_NONE.
 * @since		2.0
 *
 * @see		VideoRecorder::SetMode()
 * @see		VideoRecorder::GetMode()
 * @endif
 */
enum VideoRecorderMode
{
	VIDEORECORDER_MODE_VIDEO_WITH_AUDIO,                /**< @if OSPDEPREC The video with audio mode @endif */
	VIDEORECORDER_MODE_VIDEO_ONLY,                      /**< @if OSPDEPREC The video only mode @endif */
};

}}

#endif
