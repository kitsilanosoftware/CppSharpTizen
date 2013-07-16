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
 * @file		FUiCtrlControlsTypes.h
 * @brief		This is the header file for the enumerations.
 *
 * This header file contains the declarations of the enumerations.
 */
#ifndef _FUI_CTRL_CONTROLS_TYPES_H_
#define _FUI_CTRL_CONTROLS_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum MarginType
 *
 * Defines different margin types for a control.
 *
 * @since 2.0
 */
enum MarginType
{
	MARGIN_TYPE_LEFT,                                   /**< The left side of the margin */
	MARGIN_TYPE_RIGHT,                                  /**< The right side of the margin */
	MARGIN_TYPE_TOP,                                    /**< The top side of the margin */
	MARGIN_TYPE_BOTTOM                                  /**< The bottom side of the margin */
};

/**
 * @enum BackgroundStyle
 *
 * Defines the background style.
 *
 * @since		2.0
 */
enum BackgroundStyle
{
	BACKGROUND_STYLE_NONE = 0,                              /**< The image with no background */
	BACKGROUND_STYLE_DEFAULT,                               /**< The default background image */
};

/**
 * @enum  IconPosition
 *
 * Defines position of the text.
 *
 * @since	2.0
 */
enum IconPosition
{
	ICON_POSITION_LEFT,                 /**< The position of the icon is to the left of the object */
	ICON_POSITION_RIGHT                 /**< The position of the icon is to the right of the object */
};

/**
 * @enum HorizontalAlignment
 *
 * Defines horizontal alignment of the text.
 *
 * @since		2.0
 */
enum HorizontalAlignment
{
	ALIGNMENT_LEFT,                 /**< The text is left-aligned */
	ALIGNMENT_CENTER,               /**< The text is center-aligned horizontally */
	ALIGNMENT_RIGHT             /**< The text is right-aligned */
};

/**
 * @enum VerticalAlignment
 *
 * Defines vertical alignment of the text.
 *
 * @since		2.0
 */
enum VerticalAlignment
{
	ALIGNMENT_TOP,                  /**< The text is top-aligned */
	ALIGNMENT_MIDDLE,               /**< The text is center-aligned vertically */
	ALIGNMENT_BOTTOM                /**< The text is bottom-aligned */
};

/**
 * @enum GroupStyle
 *
 * Defines the table view style of a control's border.
 *
 * @since	2.0
 */
enum GroupStyle
{
	GROUP_STYLE_NONE,                   /**< A rectangle with no outline */
	GROUP_STYLE_SINGLE,                 /**< A rectangle with all corners rounded */
	GROUP_STYLE_TOP,                    /**< A rectangle with the two top corners rounded */
	GROUP_STYLE_MIDDLE,                 /**< A rectangle positioned at the center of a group */
	GROUP_STYLE_BOTTOM                  /**< A rectangle with the two bottom corners rounded */
};

}}}// Tizen::Ui::Controls

#endif //_FUI_CTRL_CONTROLS_TYPES_H_
