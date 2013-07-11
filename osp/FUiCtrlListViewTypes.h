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
 * @file	FUiCtrlListViewTypes.h
 * @brief	This is the header file for the List enumerations.
 *
 * This header file contains the declarations of the List enumerations.
 */
#ifndef _FUI_CTRL_LIST_VIEW_TYPES_H_
#define _FUI_CTRL_LIST_VIEW_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum  ListAnnexStyle
 *
 * Defines the style of annex in the items.
 *
 * @since 2.0
 */
enum ListAnnexStyle
{
	LIST_ANNEX_STYLE_NORMAL = 0,                /**< The no style annex */
	LIST_ANNEX_STYLE_MARK,                      /**< The mark style annex for multiple selection */
	LIST_ANNEX_STYLE_ONOFF_SLIDING,             /**< The slider style On/Off */
	LIST_ANNEX_STYLE_DETAILED,                  /**< Detailed style for further interaction */
	LIST_ANNEX_STYLE_RADIO                      /**< The radio style for simple look */
};

/**
 * @enum  ListItemDrawingStatus
 *
 * Defines the drawing state of the items.
 *
 * @since 2.0
 */
enum ListItemDrawingStatus
{
	LIST_ITEM_DRAWING_STATUS_NORMAL = 0,        /**< The normal drawing state */
	LIST_ITEM_DRAWING_STATUS_PRESSED,           /**< The pressed drawing state */
	LIST_ITEM_DRAWING_STATUS_HIGHLIGHTED        /**< The highlighted drawing state */
};

/**
 * @enum  ListRefreshType
 *
 * Defines the update type of the list.
 *
 * @since 2.0
 */
enum ListRefreshType
{
	LIST_REFRESH_TYPE_ITEM_ADD = 0,             /**< The add type */
	LIST_REFRESH_TYPE_ITEM_REMOVE,              /**< The remove type */
	LIST_REFRESH_TYPE_ITEM_MODIFY				/**< The modify type */
};

/**
 * @enum  ListItemStatus
 *
 * Defines the item state of the list.
 *
 * @since 2.0
 */
enum ListItemStatus
{
	LIST_ITEM_STATUS_SELECTED = 0,              /**< The selected item state */
	LIST_ITEM_STATUS_HIGHLIGHTED,               /**< The highlighted item state */
	LIST_ITEM_STATUS_CHECKED,                   /**< The check item state */
	LIST_ITEM_STATUS_UNCHECKED,                 /**< The uncheck item state */
	LIST_ITEM_STATUS_MORE                       /**< The more item state */
};

/**
 * @enum  ListContextItemStatus
 *
 * Defines the state of the context items.
 *
 * @since 2.0
 */
enum ListContextItemStatus
{
	LIST_CONTEXT_ITEM_STATUS_SELECTED = 0,      /**< The selected context item state */
	LIST_CONTEXT_ITEM_STATUS_HIGHLIGHTED        /**< The highlighted context item state */
};

/**
 * @enum  SweepDirection
 *
 * Defines the direction of the sweep interaction.
 *
 * @since 2.0
 */
enum SweepDirection
{
	SWEEP_DIRECTION_LEFT = 0,                   /**< The left direction */
	SWEEP_DIRECTION_RIGHT                       /**< The right direction */
};

/**
 * @enum ListScrollItemAlignment
 *
 * Defines the alignment information for item scroll.
 *
 * @since 2.0
 */
enum ListScrollItemAlignment
{
	LIST_SCROLL_ITEM_ALIGNMENT_TOP = 0,         /**< The item is aligned at the top of the ListView at item scroll*/
	LIST_SCROLL_ITEM_ALIGNMENT_BOTTOM           /**< The item is aligned at the bottom of the ListView at item scroll */
};

/**
 * @enum ListScrollStyle
 *
 * Defines the scroll style of the list.
 *
 * @since 2.0
 */
enum ListScrollStyle
{
	SCROLL_STYLE_FADE_OUT = 0,	/**< The fade-out scroll style */
	SCROLL_STYLE_FIXED,			/**< The fixed scroll style */
	SCROLL_STYLE_FAST_SCROLL,	/**< The fast scroll style */
	SCROLL_STYLE_JUMP_TO_TOP,   /**< The jump to top scroll style */
	SCROLL_STYLE_THUMB			/**< The thumb scroll style */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_LIST_VIEW_TYPES_H_
