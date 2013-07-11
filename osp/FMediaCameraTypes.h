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
 * @file			FMediaCameraTypes.h
 * @brief			This is the header file for the enumerations of the Camera class.
 *
 * This header file contains the definitions of the enumerations of the Camera class.
 */

#ifndef _FMEDIA_CAMERA_TYPES_H_
#define _FMEDIA_CAMERA_TYPES_H_

namespace Tizen { namespace Media
{

#define MAX_CAMERA_STRING_LENGTH 200

#define MIN_CAMERA_BRIGHTNESS 0
#define MAX_CAMERA_BRIGHTNESS 9
#define DEFAULT_CAMERA_BRIGHTNESS 5

#define MIN_CAMERA_CONTRAST 0
#define MAX_CAMERA_CONTRAST 9
#define DEFAULT_CAMERA_CONTRAST 5

#define MIN_CAMERA_EXPOSURE 0
#define MAX_CAMERA_EXPOSURE 9
#define DEFAULT_CAMERA_EXPOSURE 5

#define DEFAULT_CAMERA_PREVIEW_FPS 15

/**
 * @enum CameraSelection
 *
 * Defines a functional camera.
 *
 * @since		2.0
 *
 * @see		Camera::PowerOn()
 */
enum CameraSelection
{
	CAMERA_PRIMARY,          /**< The primary camera */
	CAMERA_SECONDARY,       /**< The secondary camera */
};

/**
 * @enum CameraState
 *
 * Defines the state of the camera.
 *
 * @since		2.0
 *
 * @see		Camera::GetState()
 */
enum CameraState
{
	CAMERA_STATE_INITIALIZED,       /**< The camera in the initialized state */
	CAMERA_STATE_PREVIEW,           /**< The camera in the preview state */
	CAMERA_STATE_AUTO_FOCUSING,     /**< The camera state while auto-focusing */
	CAMERA_STATE_CAPTURING,         /**< The camera state while capturing */
	CAMERA_STATE_CAPTURED,          /**< The camera state after capturing */
	CAMERA_STATE_ERROR              /**< The camera in an error state */
};

/**
 * @enum CameraWhiteBalance
 *
 * Defines the white balance levels of the camera.
 *
 * @since		2.0
 *
 * @see		Camera::SetWhiteBalance()
 * @see     Camera::GetWhiteBalance()
 */
enum CameraWhiteBalance
{
	CAMERA_WHITE_BALANCE_AUTO,                  /**< The camera's white balance level: Auto */
	CAMERA_WHITE_BALANCE_SUNNY,                 /**< The camera's white balance level: Sunny */
	CAMERA_WHITE_BALANCE_CLOUDY,                /**< The camera's white balance level: Cloudy */
	CAMERA_WHITE_BALANCE_FLUORESCENT,           /**< The camera's white balance level: Fluorescent */
	CAMERA_WHITE_BALANCE_TUNGSTEN,              /**< The camera's white balance level: Tungsten */
};

/**
 * @enum CameraEffect
 *
 * Defines the effects of the camera.
 *
 * @since		2.0
 *
 * @see		Camera::SetEffect()
 * @see     Camera::GetEffect()
 */
enum CameraEffect
{
	CAMERA_EFFECT_NONE,                 /**< The camera's effect: None */
	CAMERA_EFFECT_COLOR,                /**< The camera's effect: Color */
	CAMERA_EFFECT_BW,                   /**< The camera's effect: Black and White */
	CAMERA_EFFECT_SEPIA,                /**< The camera's effect: Sepia */
	CAMERA_EFFECT_SOLARIZE,             /**< The camera's effect: Solarize */
	CAMERA_EFFECT_NEGATIVE,             /**< The camera's effect: Negative */
	CAMERA_EFFECT_NIGHT,                /**< The camera's effect: Night */
};

/**
 * @enum CameraIsoLevel
 *
 * Defines the ISO levels of the camera.
 *
 * @since		2.0
 *
 * @see		Camera::SetIsoLevel()
 * @see     Camera::GetIsoLevel()
 */
enum CameraIsoLevel
{
	CAMERA_ISO_DEFAULT,                 /**< The device dependent default ISO level */
	CAMERA_ISO_MIN,                     /**< The minimum supported ISO level */
	CAMERA_ISO_AUTO,                    /**< The auto ISO level */
	CAMERA_ISO_50,                      /**< The ISO 50 level */
	CAMERA_ISO_100,                     /**< The ISO 100 level */
	CAMERA_ISO_200,                     /**< The ISO 200 level */
	CAMERA_ISO_400,                     /**< The ISO 400 level */
	CAMERA_ISO_800,                     /**< The ISO 800 level */
	CAMERA_ISO_1600,                    /**< The ISO 1600 level */
	CAMERA_ISO_MAX                      /**< The maximum supported ISO level */
};

/**
 * @enum CameraQuality
 *
 * Defines the capturing quality of the camera.
 *
 * @since		2.0
 *
 * @remarks The capturing quality of the camera cannot be set to CAMERA_QUALITY_MAX.
 * @see		Camera::GetQuality()
 * @see     Camera::SetQuality()
 */
enum CameraQuality
{
	CAMERA_QUALITY_NORMAL,              /**< The camera's capturing quality: Normal */
	CAMERA_QUALITY_FINE,                /**< The camera's capturing quality: Fine */
	CAMERA_QUALITY_SUPER_FINE,          /**< The camera's capturing quality: Super Fine */
	CAMERA_QUALITY_MAX,                 /**< The camera's capturing quality: Max boundary */
};

/**
 * @enum CameraErrorReason
 *
 * Defines the reason for the camera error.
 *
 * @since		2.0
 */
enum CameraErrorReason
{
	CAMERA_ERROR_NONE,                  // The undefined error
	CAMERA_ERROR_OUT_OF_MEMORY,         /**< The insufficient memory error */
	CAMERA_ERROR_DEVICE_FAILED,         /**< The camera device failed error */
	CAMERA_ERROR_DEVICE_INTERRUPTED,    /**< The camera device interrupted error  */
};


/**
 * @enum CameraDirection
 *
 * Defines the physical direction of the camera.
 *
 * @since		2.0
 */
enum CameraDirection
{
	CAMERA_DIRECTION_FRONT = 0x01,  /**< The camera's direction: Front */
	CAMERA_DIRECTION_BACK,          /**< The camera's direction: Backward */
} ;

/**
 * @enum CameraRotation
 *
 * Defines the physical rotation of the camera in degrees.
 *
 * @since		2.0
 */
enum CameraRotation
{
	CAMERA_ROTATION_NONE = 0x01,    /**< The camera's rotation: None */
	CAMERA_ROTATION_90,         /**< The camera's rotation: 90 degree rotation */
	CAMERA_ROTATION_180,            /**< The camera's rotation: 180 degree rotation  */
	CAMERA_ROTATION_270,            /**< The camera's rotation: 270 degree rotation  */
};

/**
 * @enum CameraZoomType
 *
 * Defines the zoom types of the camera.
 *
 * @since		2.0
 */
enum CameraZoomType
{
	CAMERA_ZOOM_TYPE_DIGITAL = 0x01,    /**< The camera's zoom type: Digital */
	CAMERA_ZOOM_TYPE_SMART,             /**< The camera's zoom type: Smart */
};

/**
 * @enum CameraExifOrientation
 *
 * Defines the camera's EXIF orientation flags.
 *
 * @since		2.0
 */
enum CameraExifOrientation
{
	CAMERA_EXIF_ORIENTATION_TOP_LEFT = 0x01,    /**< The row #0 is top, column #0 is left */
	CAMERA_EXIF_ORIENTATION_TOP_RIGHT,      /**< The row #0 is top, column #0 is right */
	CAMERA_EXIF_ORIENTATION_BOTTOM_RIGHT,   /**< The row #0 is bottom, column #0 is right */
	CAMERA_EXIF_ORIENTATION_BOTTOM_LEFT,    /**< The row #0 is bottom, column #0 is left */
	CAMERA_EXIF_ORIENTATION_LEFT_TOP,       /**< The row #0 is left, column #0 is top */
	CAMERA_EXIF_ORIENTATION_RIGHT_TOP,      /**< The row #0 is right, column #0 is top */
	CAMERA_EXIF_ORIENTATION_RIGHT_BOTTOM,   /**< The row #0 is right, column #0 is bottom */
	CAMERA_EXIF_ORIENTATION_LEFT_BOTTOM,    /**< The row #0 is left, column #0 is bottom */
};

/**
 * @enum CameraFlipType
 *
 * Defines the camera's flip types.
 *
 * @since		2.0
 */
enum CameraFlipType
{
	CAMERA_FLIP_NONE,               /**< The camera's flip type: None*/
	CAMERA_FLIP_HORIZONTAL,     /**< The camera's flip type: Horizontal*/
	CAMERA_FLIP_VERTICAL,           /**< The camera's flip type: Vertical*/
};

/**
 * @enum CameraFocusMode
 *
 * Defines the camera focus mode
 * @since		2.0
 */
enum CameraFocusMode
{
	CAMERA_FOCUS_MODE_NONE,	/**< The camera's  focus mode: None*/
	CAMERA_FOCUS_MODE_NORMAL,	/**< The camera's  focus mode: Normal*/
	CAMERA_FOCUS_MODE_MACRO,	/**< The camera's  focus mode: Macro*/
	CAMERA_FOCUS_MODE_CONTINUOUS_AUTO,	/**< The camera's  focus mode: Continuous auto*/
	CAMERA_FOCUS_MODE_INFINITE,	/**< The camera's  focus mode: Infinite*/
};

/**
 * @enum CameraFlashMode
 *
 * Defines the camera flash mode
 * @since		2.0
 */
enum CameraFlashMode
{
	CAMERA_FLASH_MODE_OFF,		  	/**< Flash off */
	CAMERA_FLASH_MODE_ON,			/**< Flash splashes before capturing*/
	CAMERA_FLASH_MODE_AUTO,			 		/**< Flash splashes depending on intensity of light before capturing */
	CAMERA_FLASH_MODE_RED_EYE_REDUCTION, 		/**< Flash splashes multiple times before capturing for red eye reduction. */
	CAMERA_FLASH_MODE_CONTINUOUS,				/**< Flash keeps turned on until turning off */
};

/**
* @enum CameraMeteringMode
*
* Defines the camera metering mode
* @since		2.0
*/
enum CameraMeteringMode
{
	CAMERA_METERING_MODE_NONE,			/**< No metering mode */
	CAMERA_METERING_MODE_AVERAGE,		/**< Average metering mode that uses information of entire scene */
	CAMERA_METERING_MODE_CENTER_WEIGHTED,	/**< Center weighted average metering mode that uses information of central part of the scene */
	CAMERA_METERING_MODE_SPOT,			/**< Spot metering mode that uses information of very small area of the scene */
};

}}// Tizen::Media


#endif
