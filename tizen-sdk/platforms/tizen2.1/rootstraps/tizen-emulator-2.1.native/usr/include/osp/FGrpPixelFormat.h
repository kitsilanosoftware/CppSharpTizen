//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpPixelFormat.h
 * @brief	This is the header file for the PixelFormat enumeration that defines the pixel information.
 *
 * This header file contains the definitions of the PixelFormat enumeration that defines the pixel information.
 */

#ifndef _FGRP_PIXEL_FORMAT_H_
#define _FGRP_PIXEL_FORMAT_H_

namespace Tizen { namespace Graphics
{
/**
 * @enum	PixelFormat
 *
 * Defines the bits per pixel and the bits per component.
 *
 * @since	2.0
 */
enum PixelFormat
{
	PIXEL_FORMAT_RGB565 = 1, /**< The RGB565 pixel format */
	PIXEL_FORMAT_ARGB8888, /**<The ARGB8888 pixel format */
	PIXEL_FORMAT_R8G8B8A8, /**<The R8G8B8A8 pixel format @n
			                    The order of color component is guaranteed by the byte unit. */
	PIXEL_FORMAT_YCbCr420_PLANAR, /**<The 8-bit Y-plane followed by 8-bit 2x2 sub sampled U-plane and V-plane */
	PIXEL_FORMAT_JPEG, /**<The encoded formats */
	PIXEL_FORMAT_NV12, /**<The NV12 pixel formats */
	PIXEL_FORMAT_UYVY, /**<The UYVY pixel format */
	PIXEL_FORMAT_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	PIXEL_FORMAT_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

} } // Tizen::Graphics

#endif
