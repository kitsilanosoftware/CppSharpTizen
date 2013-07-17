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
// distributed under the License is distributed on an ¡±AS IS¡± BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FUiCtrlIconListViewTypes.h
 * @brief		This is the header file for the enumerations of the IconListView class.
 *
 * This header file contains the declarations of the enumerations of the IconListView class.
 * These enumerations define the various properties of the %IconListView control.
 */

#ifndef _FUI_CTRL_ICON_LIST_VIEW_TYPES_H_
#define _FUI_CTRL_ICON_LIST_VIEW_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum IconListViewStyle
 *
 * Defines the styles of the IconListView control.
 *
 * @since 2.0
 */
enum IconListViewStyle
{
	ICON_LIST_VIEW_STYLE_NORMAL = 0,                    /**< The No mark or radio check */
	ICON_LIST_VIEW_STYLE_RADIO,                         /**< The radio style for a single selection */
	ICON_LIST_VIEW_STYLE_MARK                           /**< The mark style for multiple selections */
};

/**
 * @enum IconListViewItemBorderStyle
 *
 * Defines the constants used to identify the border style of the item.
 *
 * @since 2.0
 */
enum IconListViewItemBorderStyle
{
	ICON_LIST_VIEW_ITEM_BORDER_STYLE_NONE = 0,    /**< The item that has no border */
	ICON_LIST_VIEW_ITEM_BORDER_STYLE_OUTLINE,     /**< The item that has a line border */
	ICON_LIST_VIEW_ITEM_BORDER_STYLE_SHADOW       /**< The item that has a bitmap border with the drop shadow effect */
};

/**
 * @enum IconListViewScrollDirection
 *
 * Defines the scroll direction of the IconListView control.
 *
 * @since 2.0
 */
enum IconListViewScrollDirection
{
	ICON_LIST_VIEW_SCROLL_DIRECTION_VERTICAL,           /**< The vertical direction */
	ICON_LIST_VIEW_SCROLL_DIRECTION_HORIZONTAL          /**< The horizontal direction */
};

/**
 * @enum IconListViewItemTextVerticalAlignment
 *
 * Defines the vertical alignment of the item text.
 *
 * @since 2.0
 */
enum IconListViewItemTextVerticalAlignment
{
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_TOP,     /**< The text is top-aligned inside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_MIDDLE,  /**< The text is middle-aligned inside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_BOTTOM,  /**< The text is bottom-aligned inside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_OUTSIDE_TOP,    /**< The text is top-aligned outside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_OUTSIDE_BOTTOM  /**< The text is bottom-aligned outside the item */
};

/**
 * @enum IconListViewItemStatus
 *
 * Defines the constants used to identify the item state.
 *
 * @since 2.0
 */
enum IconListViewItemStatus
{
	ICON_LIST_VIEW_ITEM_CHECKED = 0,                    /**< The item has been checked (toggle of the check area) */
	ICON_LIST_VIEW_ITEM_UNCHECKED,                      /**< The item has been unchecked (toggle of the check area) */
	ICON_LIST_VIEW_ITEM_SELECTED,                       /**< The item has been selected (non-check area of the item) */
	ICON_LIST_VIEW_ITEM_HIGHLIGHTED                     /**< The item has been highlighted (non-check area of the item) */
};

/**
 * @enum  IconListViewItemDrawingStatus
 *
 * Defines the drawing state of the IconListView control items.
 *
 * @since 2.0
 */
enum IconListViewItemDrawingStatus
{
	ICON_LIST_VIEW_ITEM_DRAWING_STATUS_NORMAL = 0,      /**< The drawing status for normal items */
	ICON_LIST_VIEW_ITEM_DRAWING_STATUS_PRESSED,         /**< The drawing status for pressed items */
	ICON_LIST_VIEW_ITEM_DRAWING_STATUS_HIGHLIGHTED      /**< The drawing status for highlighted items */
};

/**
 * @enum IconListViewCheckBoxPosition
 *
 * Defines the checkbox position.
 *
 * @since 2.0
 */
enum IconListViewCheckBoxPosition
{
	ICON_LIST_VIEW_CHECK_BOX_POSITION_TOP_LEFT,         /**< The position of the checkbox is top-left */
	ICON_LIST_VIEW_CHECK_BOX_POSITION_TOP_RIGHT,        /**< The position of the checkbox is top-right */
	ICON_LIST_VIEW_CHECK_BOX_POSITION_BOTTOM_LEFT,      /**< The position of the checkbox is bottom-left */
	ICON_LIST_VIEW_CHECK_BOX_POSITION_BOTTOM_RIGHT      /**< The position of the checkbox is bottom-right */
};

/**
 * @enum IconListViewScrollStyle
 *
 * Defines the scroll style of the IconListView control.
 *
 * @since 2.0
 */
enum IconListViewScrollStyle
{
	ICON_LIST_SCROLL_STYLE_FADE_OUT = 0,	/**< The fade-out scroll style */
	ICON_LIST_SCROLL_STYLE_FIXED,			/**< The fixed scroll style */
	ICON_LIST_SCROLL_STYLE_JUMP_TO_TOP,		/**< The jump to top scroll style */
	ICON_LIST_SCROLL_STYLE_THUMB			/**< The thumb scroll style */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ICON_LIST_VIEW_TYPES_H_
