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
 * @file		FUiLayoutTypes.h
 * @brief		This is the header file for the layout enumerations.
 *
 * This header file contains the declarations of the layout enumerations.
 */
#ifndef _FUI_LAYOUT_ENUM_H_
#define _FUI_LAYOUT_ENUM_H_

namespace Tizen { namespace Ui
{

/**
 *	@enum	LayoutType
 *
 *	Defines the layout type.
 *
 *  @since	2.0
 */
enum LayoutType
{
	LAYOUT_RELATIVE,       /**< The relative layout */
	LAYOUT_VERTICAL_BOX,   /**< The vertical box layout */
	LAYOUT_HORIZONTAL_BOX, /**< The horizontal box layout */
	LAYOUT_GRID,            /**< The grid layout */
	LAYOUT_CARD 			/**< The card layout */
};

/**
 *	@enum	RectangleEdgeRelation
 *
 *	Defines the relative relation between the source control and the target control.
 *
 *  @since	2.0
 */
enum RectangleEdgeRelation
{
	RECT_EDGE_RELATION_LEFT_TO_LEFT,     /**< The left edge of the source control is aligned with the left edge of the target control */
	RECT_EDGE_RELATION_LEFT_TO_RIGHT,    /**< The left edge of the source control is aligned with the right edge of the target control */
	RECT_EDGE_RELATION_RIGHT_TO_RIGHT,   /**< The right edge of the source control is aligned with the right edge of the target control */
	RECT_EDGE_RELATION_RIGHT_TO_LEFT,    /**< The right edge of the source control is aligned with the left edge of the target control */
	RECT_EDGE_RELATION_TOP_TO_TOP,       /**< The top edge of the source control is aligned with the top edge of the target control */
	RECT_EDGE_RELATION_TOP_TO_BOTTOM,    /**< The top edge of the source control is aligned with the bottom edge of the target control */
	RECT_EDGE_RELATION_BOTTOM_TO_BOTTOM, /**< The bottom edge of the source control is aligned with the bottom edge of the target control */
	RECT_EDGE_RELATION_BOTTOM_TO_TOP     /**< The bottom edge of the source control is aligned with the top edge of the target control */
};

/**
 *	@enum	RectangleEdgeType
 *
 *	Defines the edges of a rectangle.
 *
 *  @since	2.0
 */
enum RectangleEdgeType
{
	RECT_EDGE_LEFT,   /**< The left edge of a rectangle */
	RECT_EDGE_RIGHT,  /**< The right edge of a rectangle */
	RECT_EDGE_TOP,    /**< The top edge of a rectangle */
	RECT_EDGE_BOTTOM  /**< The bottom edge of a rectangle */
};

/**
 *	@enum	CenterAlignmentType
 *
 *	Defines the center alignment for a control.
 *
 *  @since	2.0
 */
enum CenterAlignmentType
{
	CENTER_ALIGN_HORIZONTAL, /**< Centers the child control horizontally with respect to the left and right side of its parent control */
	CENTER_ALIGN_VERTICAL    /**< Centers the child control vertically with respect to the top and bottom side of its parent control */
};

/**
 *	@enum	FitPolicy
 *
 *	Defines the fitting policy for a control.
 *
 *  @since	2.0
 */
enum FitPolicy
{
	FIT_POLICY_FIXED,   /**< The fixed size of a control */
	FIT_POLICY_CONTENT, /**< The size of the control that is large enough to fit its internal content */
	FIT_POLICY_PARENT   /**< The size of the control that is as large as its parent control */
};

/**
 *	@enum	VerticalDirection
 *
 *	Defines the direction for the vertical box layout.
 *
 *  @since	2.0
 */
enum VerticalDirection
{
	VERTICAL_DIRECTION_DOWNWARD, /**< The direction that runs from top to bottom */
	VERTICAL_DIRECTION_UPWARD    /**< The direction that runs from bottom to top */
};

/**
 *	@enum	HorizontalDirection
 *
 *	Defines the direction for the horizontal box layout.
 *
 *  @since	2.0
 */
enum HorizontalDirection
{
	HORIZONTAL_DIRECTION_RIGHTWARD, /**< The direction that runs from left to right */
	HORIZONTAL_DIRECTION_LEFTWARD   /**< The direction that runs from right to left */
};

/**
 *	@enum	LayoutHorizontalAlignment
 *
 *	Defines the horizontal alignment for the grid layout.
 *
 *  @since	2.0
 */
enum LayoutHorizontalAlignment
{
	LAYOUT_HORIZONTAL_ALIGN_LEFT,   /**< The horizontal left alignment of the control */
	LAYOUT_HORIZONTAL_ALIGN_CENTER, /**< The horizontal center alignment of the control */
	LAYOUT_HORIZONTAL_ALIGN_RIGHT   /**< The horizontal right alignment of the control */
};

/**
 *	@enum	LayoutVerticalAlignment
 *
 *	Defines the vertical alignment for the grid layout.
 *
 *  @since	2.0
 */
enum LayoutVerticalAlignment
{
	LAYOUT_VERTICAL_ALIGN_TOP,    /**< The vertical top alignment of the control */
	LAYOUT_VERTICAL_ALIGN_MIDDLE, /**< The vertical middle alignment of the control */
	LAYOUT_VERTICAL_ALIGN_BOTTOM  /**< The vertical bottom alignment of the control */
};

}} // Tizen::Ui

#endif // _FUI_LAYOUT_ENUM_H_
