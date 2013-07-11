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
* @file			FMediaAudioManagerTypes.h
* @brief		This is the header file for the types of audio manager classes.
*
* This header files contains all the common things required for audio manager classes and associated classes
*
*/
#ifndef _FMEDIA_AUDIO_MANAGER_TYPES_H_
#define _FMEDIA_AUDIO_MANAGER_TYPES_H_

namespace Tizen { namespace Media
{




/**
 * @enum AudioStreamType
 *
 * Defines the audio stream types.
 *
 * @since		2.0
 */
enum AudioStreamType
{
	AUDIO_STREAM_TYPE_NO_SOUND,			/**< System is not playing any sound */
	AUDIO_STREAM_TYPE_SYSTEM,					/**< System audio */
	AUDIO_STREAM_TYPE_NOTIFICATION,			/**< Notification audio */
	AUDIO_STREAM_TYPE_ALARM,					/**< Alarm type audio */
	AUDIO_STREAM_TYPE_RINGTONE,				/**< Ringtone type audio */
	AUDIO_STREAM_TYPE_MEDIA,						/**< Media type audio */
	AUDIO_STREAM_TYPE_CALL						/**< Call type audio */
};


}}	//Tizen::Media
#endif
