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
 * @file	FGrpBitmapCommon.h
 * @brief	This is the header file for the %Bitmap class.
 *
 * This header file contains the definitions of the enumerations of the %Bitmap class.
 */

#ifndef _FGRP_BITMAP_COMMON_H_
#define _FGRP_BITMAP_COMMON_H_

namespace Tizen { namespace Graphics
{

/**
 * @enum	BitmapPixelFormat
 *
 * Defines the bitmap pixel format.
 *
 * @since	2.0
 */
enum BitmapPixelFormat
{
	BITMAP_PIXEL_FORMAT_RGB565 = 1, /**< The RGB565 pixel format */
	BITMAP_PIXEL_FORMAT_ARGB8888, /**< The ARGB8888 pixel format */
	BITMAP_PIXEL_FORMAT_R8G8B8A8, /**< The R8G8B8A8 pixel format, the order of the color component is guaranteed by the byte unit */
	BITMAP_PIXEL_FORMAT_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	BITMAP_PIXEL_FORMAT_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum	BufferScaling
 *
 * Defines the bitmap buffer scaling type.
 *
 * @since	2.0
 *
 */
enum BufferScaling
{
	BUFFER_SCALING_NONE = 1, /**< The bitmap buffer is created without scaling */
	BUFFER_SCALING_AUTO, /**< The bitmap buffer is created according to the auto scaling rule */
	BUFFER_SCALING_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	BUFFER_SCALING_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum	BitmapScalingQuality
 *
 * Defines the bitmap scaling quality.
 *
 * @since 2.0
 *
 * @remarks Bitmap::Scale() function performs the operation according to the given BitmapScalingQuality value. \n
 *          Bitmap scaling with BITMAP_SCALING_QUALITY_HIGH provides better results than others, but it takes longer.
 *          On the other hand, bitmap scaling with BITMAP_SCALING_QUALITY_LOW runs faster than others, but the results are poorer.
 *          When you scale bitmaps with a masking color then you have to select BITMAP_SCALING_QUALITY_LOW,
 *          because that algorithm does not harm the masking color (by sampling the pixels instead of interpolating).
 */
enum BitmapScalingQuality
{
	BITMAP_SCALING_QUALITY_LOW, /**< Low-quality but high-performance */
	BITMAP_SCALING_QUALITY_MID, /**< Mid-quality */
	BITMAP_SCALING_QUALITY_HIGH /**< High-quality but low-performance */
};

} } // Tizen::Graphics

#endif
