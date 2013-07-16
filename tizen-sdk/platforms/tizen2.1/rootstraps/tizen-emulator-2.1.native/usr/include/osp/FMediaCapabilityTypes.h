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
 * @file			FMediaCapabilityTypes.h
 * @brief			This is the header file for the common data of the MediaCapability class.
 *
 * This header file contains the declarations of common data of the MediaCapability class.
 */

#ifndef _FMEDIA_CAPABILITY_TYPES_H_
#define _FMEDIA_CAPABILITY_TYPES_H_

#include <FBase.h>

namespace Tizen { namespace Media
{

/**
* The property key to check the list of the supported sample rates of AudioIn.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const AUDIOIN_SAMPLE_RATE;

/**
* The property key to check the list of the supported sample types of AudioIn.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const AUDIOIN_SAMPLE_TYPE;

/**
* The property key to check the maximum instance count that AudioOut can construct.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const AUDIOOUT_COUNT_MAX;

/**
* The property key to check the list of the supported sample rates of AudioOut.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const AUDIOOUT_SAMPLE_RATE;

/**
* The property key to check the list of the supported sample types of AudioOut.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const AUDIOOUT_SAMPLE_TYPE;

/**
* The property key to check the list of audio formats that the audio recorder supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const AUDIORECORDER_FORMAT;

/**
* The property key to check the count of cameras that are supported.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_COUNT;

/**
* The property key to check the list of capture formats that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_CAPTURE_FORMAT;

/**
* The property key to check the list of capture resolutions that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_CAPTURE_RESOLUTION;

/**
* The property key to check the physical direction of the primary camera.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_DIRECTION;

/**
* The property key to check the list of effects that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_EFFECT;

/**
* The property key to check the list of ISO levels that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_ISO_LEVEL;

/**
* The property key to check the list of preview formats that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_PREVIEW_FORMAT;

/**
* The property key to check the list of preview frame rates that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_PREVIEW_FRAMERATE;

/**
* The property key to check the list of preview resolutions that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_PREVIEW_RESOLUTION;

/**
* The property key to check the list of recording resolutions that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_RECORDING_RESOLUTION;

/**
* The property key to check the physical rotation of the primary camera in the portrait mode.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_ROTATION;

/**
* The property key to check the ability of the primary camera to support brightness APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_BRIGHTNESS;

/**
* The property key to check the ability of the primary camera to support capture APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_CAPTURE;

/**
* The property key to check the ability of the primary camera to support contrast APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_CONTRAST;

/**
* The property key to check the ability of the primary camera to support exposure APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_EXPOSURE;

/**
* The property key to check the ability of the primary camera to support flash APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_FLASH;

/**
* The property key to check the ability of the primary camera to support focus APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_FOCUS;

/**
* The property key to check the ability of the primary camera to support preview APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_PREVIEW;

/**
* The property key to check the ability of the primary camera to be used with the video recorder.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_RECORDING;

/**
* The property key to check the ability of the primary camera to support zoom APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_ZOOM;

/**
* The property key to check the ability of the primary camera to support zero-shutter-lag feature.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SUPPORT_ZERO_SHUTTER_LAG;

/**
* The property key to check the list of white balances that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_WHITE_BALANCE;

/**
* The property key to check the list of zoom types that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_ZOOM_TYPE;

/**
* The property key to check the list of flip types that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_FLIP;

/**
* The property key to check the list of preview rotations that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_PREVIEW_ROTATION;

/**
* The property key to check the list of focus mode that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_FOCUS_MODE;

/**
* The property key to check the list of flash mode that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_FLASH_MODE;

/**
* The property key to check the default preview format of the primary camera.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_DEFAULT_PREVIEW_FORMAT;

/**
* The property key to check the list of metering mode that the primary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_METERING_MODE;

/**
* The property key to check the list of scene mode that the primary camera supports.
*
* @since		2.1
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_PRIMARY_SCENE_MODE;


/**
* The property key to check the list of capture formats that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_CAPTURE_FORMAT;

/**
* The property key to check the list of capture resolutions that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_CAPTURE_RESOLUTION;

/**
* The property key to check the physical direction of the secondary camera.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_DIRECTION;

/**
* The property key to check the list of effects that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_EFFECT;

/**
* The property key to check the list of ISO levels that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_ISO_LEVEL;

/**
* The property key to check the list of preview formats that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_PREVIEW_FORMAT;

/**
* The property key to check the list of preview frame rates that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_PREVIEW_FRAMERATE;

/**
* The property key to check the list of preview resolutions that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_PREVIEW_RESOLUTION;

/**
* The property key to check the list of recording resolutions that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_RECORDING_RESOLUTION;

/**
* The property key to check the physical rotation of the secondary camera in the portrait mode.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_ROTATION;

/**
* The property key to check the ability of the secondary camera to support brightness APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_BRIGHTNESS;

/**
* The property key to check the ability of the secondary camera to support capture APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_CAPTURE;

/**
* The property key to check the ability of the secondary camera to support contrast APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_CONTRAST;

/**
* The property key to check the ability of the secondary camera to support exposure APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_EXPOSURE;

/**
* The property key to check the ability of the secondary camera to support flash APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_FLASH;

/**
* The property key to check the ability of the secondary camera to support focus APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_FOCUS;

/**
* The property key to check the ability of the secondary camera to support preview APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_PREVIEW;

/**
* The property key to check the ability of the secondary camera to be used with the video recorder.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_RECORDING;

/**
* The property key to check the ability of the secondary camera to support zoom APIs.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_ZOOM;

/**
* The property key to check the ability of the secondary camera to support zero-shutter-lag feature.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SUPPORT_ZERO_SHUTTER_LAG;

/**
* The property key to check the list of white balances that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_WHITE_BALANCE;

/**
* The property key to check the list of zoom types that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_ZOOM_TYPE;

/**
* The property key to check the list of flip types that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_FLIP;

/**
* The property key to check the list of preview rotations that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_PREVIEW_ROTATION;

/**
* The property key to check the list of focus mode that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_FOCUS_MODE;

/**
* The property key to check the list of flash mode that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_FLASH_MODE;

/**
* The property key to check the default preview format of the secondary camera.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_DEFAULT_PREVIEW_FORMAT;

/**
* The property key to check the list of metering mode that the secondary camera supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_METERING_MODE;

/**
* The property key to check the list of scene mode that the secondary camera supports.
*
* @since		2.1
*/
_OSP_EXPORT_ extern const wchar_t* const CAMERA_SECONDARY_SCENE_MODE;

/**
* The property key to check the list of audio codecs that the player supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const PLAYER_AUDIO_CODEC;

/**
* The property key to check the maximum count of instances that the player can construct.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const PLAYER_COUNT_MAX;

/**
* The property key to check the list of streaming protocols that the player supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const PLAYER_PROTOCOL;

/**
* The property key to check the list of video codecs that the player supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const PLAYER_VIDEO_CODEC;

/**
* The property key to check the maximum height of the video that the player supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const PLAYER_VIDEO_HEIGHT;

/**
* The property key to check the maximum width of the video that the player supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const PLAYER_VIDEO_WIDTH;

/**
* The property key to check the list of audio codecs that the video recorder supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const VIDEORECORDER_AUDIO_CODEC;

/**
* The property key to check the list of container formats that the video recorder supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const VIDEORECORDER_FORMAT;

/**
* The property key to check the list of video codecs that the video recorder supports.
*
* @since		2.0
*/
_OSP_EXPORT_ extern const wchar_t* const VIDEORECORDER_VIDEO_CODEC;

}}// Tizen::Media

#endif
