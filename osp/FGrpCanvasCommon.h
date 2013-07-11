//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpCanvasCommon.h
 * @brief	This is the header file for the enumerations of the Canvas class.
 *
 * This header file contains the definitions of the enumerations of the Canvas class.
 */

#ifndef _FGRP_CANVAS_COMMON_H_
#define _FGRP_CANVAS_COMMON_H_

namespace Tizen { namespace Graphics
{
/**
 * @enum	LineStyle
 *
 * Defines the line style.
 *
 * @since	2.0
 */
enum LineStyle
{
	LINE_STYLE_SOLID = 1, /**< The solid line style */
	LINE_STYLE_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	LINE_STYLE_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum	ArcStyle
 *
 * Defines the arc style.
 *
 * @since	2.0
 */
enum ArcStyle
{
	ARC_STYLE_ONLY = 1, /**< An arc line is drawn */
	ARC_STYLE_PIE, /**< A pie (arc and chords) is drawn */
	ARC_STYLE_CHORD, /**< A chord is drawn */
	ARC_STYLE_FILLED_PIE, /**< A filled pie is drawn */
	ARC_STYLE_FILLED_CHORD, /**< A filled chord is drawn */
	ARC_STYLE_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	ARC_STYLE_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum	FlipDirection
 *
 * Defines the flip direction.
 *
 * @since	2.0
 */
enum FlipDirection
{
	FLIP_DIRECTION_HORIZONTAL = 1, /**< The horizontal type */
	FLIP_DIRECTION_VERTICAL, /**< The vertical type */
	FLIP_DIRECTION_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	FLIP_DIRECTION_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

} } // Tizen::Graphics

#endif // _FGRP_CANVAS_COMMON_H_
