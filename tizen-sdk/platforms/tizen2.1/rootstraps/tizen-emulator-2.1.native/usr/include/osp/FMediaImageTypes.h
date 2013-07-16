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
 * @file		FMediaImageTypes.h
 * @brief		This is the header file for the common types of the Image class.
 *
 * This header file contains the declarations of the enumerations of the Image class.
 */

#ifndef _FMEDIA_IMAGE_TYPES_H_
#define _FMEDIA_IMAGE_TYPES_H_

namespace Tizen { namespace Media
{

/**
 * @enum	ImageFormat
 *
 * Defines the image formats.
 *
 * @since	2.0
 */
enum ImageFormat
{
	IMG_FORMAT_NONE = -1,       /**< No image format type */
	IMG_FORMAT_JPG = 0,         /**< The JPEG image format type*/
	IMG_FORMAT_PNG,             /**< The PNG image format type*/
	IMG_FORMAT_GIF,             /**< The GIF image format type*/
	IMG_FORMAT_BMP,             /**< The BMP image format type*/
	IMG_FORMAT_TIFF,            /**< The TIFF image format type*/
	IMG_FORMAT_WBMP,            /**< The WBMP image format type*/
};

/**
 * @enum ImageRotationType
 *
 * Defines the types of rotation.
 *
 * @since	2.0
 */
enum ImageRotationType
{
	IMAGE_ROTATION_0 = 0x00,    /**< The no-rotation */
	IMAGE_ROTATION_90,          /**< The 90 degree rotation in clockwise direction */
	IMAGE_ROTATION_180,         /**< The 180 degree rotation in clockwise direction */
	IMAGE_ROTATION_270,         /**< The 270 degree rotation in clockwise direction */
};

/**
 * @enum ImageFlipType
 *
 * Defines the types of flip.
 *
 * @since	2.0
 */
enum ImageFlipType
{
	IMAGE_FLIP_NONE = 0x00,     /**< The no-flip type */
	IMAGE_FLIP_HORIZONTAL,      /**< The horizontal flip */
	IMAGE_FLIP_VERTICAL,        /**< The vertical flip */
};

/**
 * @enum	MediaPixelFormat
 *
 * Defines the pixel formats of the media data.
 *
 * @since	2.0
 */
enum MediaPixelFormat
{
	MEDIA_PIXEL_FORMAT_NONE = 0x0000,     // The undefined pixel format
	MEDIA_PIXEL_FORMAT_RGB565LE = 0x0001, /**< The RGB565 little-endian format */
	MEDIA_PIXEL_FORMAT_RGB565BE,          /**< The RGB565 big-endian format */
	MEDIA_PIXEL_FORMAT_RGB888 = 0x0100,   /**< The RGB888 format */
	MEDIA_PIXEL_FORMAT_BGR888,            /**< The BGR888 format */
	MEDIA_PIXEL_FORMAT_RGBA8888,          /**< The RGBA8888 format */
	MEDIA_PIXEL_FORMAT_BGRA8888,          /**< The BGRA8888 format */
	MEDIA_PIXEL_FORMAT_YUV420P = 0x0200,  /**< The YUV420 Planar format */
	MEDIA_PIXEL_FORMAT_NV12,              /**< The NV12 format */
	MEDIA_PIXEL_FORMAT_NV12_TILE,         /**< The NV12 tiled format */
	MEDIA_PIXEL_FORMAT_NV21,              /**< The NV21 format @b Since: @b 2.0 */
	MEDIA_PIXEL_FORMAT_YUV444P,           /**< The YUV444 Planar format @b Since: @b 2.0 */
	MEDIA_PIXEL_FORMAT_YUYV422,           /**< The YUYV422 format @b Since: @b 2.0 */
	MEDIA_PIXEL_FORMAT_UYVY422,           /**< The UYVY422 format @b Since: @b 2.0 */
	MEDIA_PIXEL_FORMAT_GRAY,              /**< The gray pixel format @b Since: @b 2.0 */
};

/**
 * @enum ImageScalingMethod
 *
 * Defines the image scaling method.
 *
 * @since  2.1
 */
enum ImageScalingMethod
{
	IMAGE_SCALING_METHOD_FAST_BILINEAR,   /**< Fast bilinear interpolation method */
	IMAGE_SCALING_METHOD_BILINEAR,        /**< Bilinear interpolation method */
	IMAGE_SCALING_METHOD_BICUBIC,         /**< Bicubic interpolation method */
};

/**
 * @enum ExifOrientation
 *
 * Defines the image's EXIF orientation flags.
 *
 * @since       2.1
 */
enum ExifOrientation
{
	EXIF_ORIENTATION_TOP_LEFT = 0x01,     /**< The row #0 is top, column #0 is left     */
	EXIF_ORIENTATION_TOP_RIGHT,           /**< The row #0 is top, column #0 is right    */
	EXIF_ORIENTATION_BOTTOM_RIGHT,        /**< The row #0 is bottom, column #0 is right */
	EXIF_ORIENTATION_BOTTOM_LEFT,         /**< The row #0 is bottom, column #0 is left  */
	EXIF_ORIENTATION_LEFT_TOP,            /**< The row #0 is left, column #0 is top     */
	EXIF_ORIENTATION_RIGHT_TOP,           /**< The row #0 is right, column #0 is top    */
	EXIF_ORIENTATION_RIGHT_BOTTOM,        /**< The row #0 is right, column #0 is bottom */
	EXIF_ORIENTATION_LEFT_BOTTOM,         /**< The row #0 is left, column #0 is bottom  */
};

};
};   // Tizen::Media


#endif
