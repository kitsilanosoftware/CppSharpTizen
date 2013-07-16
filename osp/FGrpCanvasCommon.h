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

/**
 * @enum		LineCapStyle
 *
 * Defines the line cap style.
 *
 * @since	2.1
 */
enum LineCapStyle
{
	LINE_CAP_STYLE_ROUND, /**< A rounded end */
	LINE_CAP_STYLE_BUTT, /**< A flat end */
	LINE_CAP_STYLE_SQUARE /**< A square end */
};

/**
 * @enum		LineJoinStyle
 *
 * Defines the line join style.
 *
 * @since	2.1
 */
enum LineJoinStyle
{
	LINE_JOIN_STYLE_ROUND, /**< A rounded corner */
	LINE_JOIN_STYLE_MITER, /**< A sharp corner */
	LINE_JOIN_STYLE_BEVEL /**< A beveled corner */
};

/**
* @enum        CompositeMode
*
* Defines the composite mode.
*
* @since         2.1
*
* @remarks       The area affected by Canvas::CompositeMode can be either bounded or unbounded.
*                In some cases, the area in which composition is performed can be bounded by the source region, or unbounded and the composition affects all of the Canvas pixels.
*/
enum CompositeMode
{
           COMPOSITE_MODE_CLEAR, /**< Clearing destination that is bounded */
           COMPOSITE_MODE_SRC, /**< Replacing source that is bounded */
           COMPOSITE_MODE_DST, /**< Ignoring the destination */
           COMPOSITE_MODE_SRC_OVER, /**< Drawing source on top of a destination */
           COMPOSITE_MODE_DST_OVER, /**< Drawing destination on top of a source */
           COMPOSITE_MODE_SRC_IN, /**< Drawing source only on the area that is overlapped by source and destination and it is unbounded */
           COMPOSITE_MODE_DST_IN, /**< Drawing destination only on the area that is overlapped by source and destination and it is unbounded */
           COMPOSITE_MODE_SRC_OUT, /**< Drawing source only on the area that is not overlapped by source and destination and it is unbounded */
           COMPOSITE_MODE_DST_OUT, /**< Drawing destination only on the area that is not overlapped by source and destination */
           COMPOSITE_MODE_SRC_ATOP, /**< Replacing source only on the area that is overlapped by source and destination */
           COMPOSITE_MODE_DST_ATOP, /**< Replacing destination only on the area that is overlapped by source and destination and it is unbounded */
           COMPOSITE_MODE_DST_XOR, /**< Drawing source and destination on the area that is other than the area overlapped by source and destination */
           COMPOSITE_MODE_ADD, /**< Adding source and destination */
           COMPOSITE_MODE_SATURATE, /**< Compositing like @c COMPOSITE_MODE_SRC_OVER as long as source and destination are disjoint geometries */
           COMPOSITE_MODE_MULTIPLY, /**< Multiplying source and destination */
           COMPOSITE_MODE_SCREEN, /**< Complementing and multiplying source and destination */
           COMPOSITE_MODE_OVERLAY, /**< Multiplying and screening destination based on the area that is overlapped by source and destination and destination color */
           COMPOSITE_MODE_DARKEN, /**< Darkening the destination based on the area that is overlapped by source and destination and destination color */
           COMPOSITE_MODE_LIGHTEN /**< Lightening destination based on the area that is overlapped by source and destination and destination color */
};

} } // Tizen::Graphics

#endif // _FGRP_CANVAS_COMMON_H_
