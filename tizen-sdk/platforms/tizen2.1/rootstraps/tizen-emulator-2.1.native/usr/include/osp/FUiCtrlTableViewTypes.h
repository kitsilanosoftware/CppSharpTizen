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
* @file FUiCtrlTableViewTypes.h
* @brief This is the header file for the TableView enumerations.
*
* This header file contains the declarations of the TableView enumerations.
*/
#ifndef _FUI_CTRL_TABLE_VIEW_TYPES_H_
#define _FUI_CTRL_TABLE_VIEW_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
* @enum  TableViewAnnexStyle
*
* Defines the style of annex in the items.
*
* @since 2.0
*/
enum TableViewAnnexStyle
{
	TABLE_VIEW_ANNEX_STYLE_NORMAL = 0,					/**< No annex */
	TABLE_VIEW_ANNEX_STYLE_MARK,						/**< Mark style check for multiple selection */
	TABLE_VIEW_ANNEX_STYLE_ONOFF_SLIDING,				/**< On/Off slider style  */
	TABLE_VIEW_ANNEX_STYLE_DETAILED,					/**< Detailed style for further interaction */
	TABLE_VIEW_ANNEX_STYLE_RADIO,						/**< Radio style check for simple look */
	TABLE_VIEW_ANNEX_STYLE_ONOFF_SLIDING_WITH_DIVIDER	/**< The slider style On/Off with divider @b Since: @b 2.1 */
};

/**
* @enum  TableViewItemDrawingStatus
*
* Defines the drawing state of the items.
*
* @since 2.0
*/
enum TableViewItemDrawingStatus
{
	TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL = 0,		/**< The normal drawing state */
	TABLE_VIEW_ITEM_DRAWING_STATUS_PRESSED,			/**< The pressed drawing state */
	TABLE_VIEW_ITEM_DRAWING_STATUS_HIGHLIGHTED		/**< The highlighted drawing state */
};

/**
* @enum  TableViewRefreshType
*
* Defines the update type of the TableView item.
*
* @since 2.0
*/
enum TableViewRefreshType
{
	TABLE_VIEW_REFRESH_TYPE_ITEM_ADD = 0,			/**< Refresh request of adding an item */
	TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE,			/**< Refresh request of removing an item */
	TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY				/**< Refresh request of modifying an item */
};

/**
* @enum  TableViewItemStatus
*
* Defines the item state of the TableView.
*
* @since 2.0
*/
enum TableViewItemStatus
{
	TABLE_VIEW_ITEM_STATUS_SELECTED = 0,			/**< The selected item state */
	TABLE_VIEW_ITEM_STATUS_HIGHLIGHTED,				/**< The highlighted item state */
	TABLE_VIEW_ITEM_STATUS_CHECKED,					/**< The checked item state */
	TABLE_VIEW_ITEM_STATUS_UNCHECKED,				/**< The unchecked item state */
	TABLE_VIEW_ITEM_STATUS_MORE						/**< The more item state */
};

/**
* @enum  TableViewSweepDirection
*
* Defines the direction of the sweep interaction.
*
* @since 2.0
*/
enum TableViewSweepDirection
{
	TABLE_VIEW_SWEEP_DIRECTION_LEFT = 0,			/**< The left direction */
	TABLE_VIEW_SWEEP_DIRECTION_RIGHT				/**< The right direction */
};

/**
* @enum TableViewScrollItemAlignment
*
* Defines the alignment information for item scroll.
*
* @since 2.0
*/
enum  TableViewScrollItemAlignment
{
	TABLE_VIEW_SCROLL_ITEM_ALIGNMENT_TOP = 0,		/**< The item is aligned at the top of the TableView at item scroll*/
	TABLE_VIEW_SCROLL_ITEM_ALIGNMENT_BOTTOM			/**< The item is aligned at the bottom of the TableView at item scroll */
};

/**
* @enum TableViewScrollBarStyle
*
* Defines the scroll bar style of the list.
*
* @since 2.0
*/
enum TableViewScrollBarStyle
{
	TABLE_VIEW_SCROLL_BAR_STYLE_NONE = 0,							/**< No scroll bar */
	TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT,						 /**< The fade-out scroll bar style */
	TABLE_VIEW_SCROLL_BAR_STYLE_FIXED,									 /**< The fixed scroll bar style */
	TABLE_VIEW_SCROLL_BAR_STYLE_JUMP_TO_TOP, 						 /**< The jump to top scroll bar style */
	TABLE_VIEW_SCROLL_BAR_STYLE_THUMB,								   /**< The thumb scroll bar style */
	TABLE_VIEW_SCROLL_BAR_STYLE_FAST_SCROLL							 /**< The fast scroll bar style */

};


}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_TABLE_VIEW_TYPES_H_
