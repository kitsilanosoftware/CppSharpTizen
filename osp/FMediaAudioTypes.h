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
* @file			FMediaAudioTypes.h
* @brief		This is the header file for the common types of AudioIn and AudioOut.
*
* This header file contains the declarations of the enumerations of the Audio In/Out classes.
*/
#ifndef _FMEDIA_AUDIO_TYPES_H_
#define _FMEDIA_AUDIO_TYPES_H_

namespace Tizen { namespace Media
{

#define MIN_AUDIOOUT_VOLUME 0
#define MAX_AUDIOOUT_VOLUME 100
#define DEFAULT_AUDIOOUT_VOLUME 50

/**
 * @enum AudioInputDevice
 *
 * Defines the audio input device.
 *
 * @since		2.0
 *
 * @see	AudioIn::Prepare()
 */
enum AudioInputDevice
{
	AUDIO_INPUT_DEVICE_MIC,     /**< The audio input device is a microphone */
};

/**
 * @enum AudioChannelType
 *
 * Defines the audio channel type.
 *
 * @since		2.0
 *
 * @see	AudioIn::Prepare(), AudioOut::Prepare()
 */
enum AudioChannelType
{
	AUDIO_CHANNEL_TYPE_NONE,    /**< The audio channel type is none */
	AUDIO_CHANNEL_TYPE_MONO,    /**< The audio channel type is mono */
	AUDIO_CHANNEL_TYPE_STEREO,  /**< The audio channel type is stereo */
};

/**
 * @enum AudioSampleType
 *
 * Defines the audio sample type with bit depth.
 *
 * @since		2.0
 *
 * @see	AudioIn::Prepare(), AudioOut::Prepare()
 */
enum AudioSampleType
{
	AUDIO_TYPE_NONE,        /**< The audio encoding type is none */
	AUDIO_TYPE_PCM_U8,      /**< The 8-bit samples are unsigned */
	AUDIO_TYPE_PCM_S8,      /**< The 8-bit samples are signed */
	AUDIO_TYPE_PCM_U16_LE,  /**< The 16-bit little-endian samples are unsigned */
	AUDIO_TYPE_PCM_U16_BE,  /**< The 16-bit big-endian samples are unsigned */
	AUDIO_TYPE_PCM_S16_LE,  /**< The 16-bit little-endian samples are signed */
	AUDIO_TYPE_PCM_S16_BE   /**< The 16-bit big-endian samples are signed */
};

/**
 * @enum AudioInState
 *
 * Defines the audio input state.
 *
 * @since		2.0
 *
 * @see	AudioIn::GetState()
 */
enum AudioInState
{
	AUDIOIN_STATE_INITIALIZED,      /**< The device is initialized */
	AUDIOIN_STATE_PREPARED,         /**< The device is prepared */
	AUDIOIN_STATE_RECORDING,        /**< The device is recording */
	AUDIOIN_STATE_STOPPED,          /**< The device is stopped */
	AUDIOIN_STATE_UNPREPARED,       /**< The device is uninitialized */
	AUDIOIN_STATE_ERROR,            /**< An error has occurred */
};

/**
 * @enum AudioOutState
 *
 * Defines the audio output state.
 *
 * @since		2.0
 *
 * @see	AudioOut::GetState()
 */
enum AudioOutState
{
	AUDIOOUT_STATE_INITIALIZED,     /**< The device is initialized */
	AUDIOOUT_STATE_PREPARED,        /**< The device is prepared */
	AUDIOOUT_STATE_PLAYING,         /**< The device is playing data */
	AUDIOOUT_STATE_STOPPED,         /**< The device is stopped */
	AUDIOOUT_STATE_UNPREPARED,      /**< The device is uninitialized */
	AUDIOOUT_STATE_ERROR,           /**< An error has occurred */
};

}} // Tizen::Media


#endif
