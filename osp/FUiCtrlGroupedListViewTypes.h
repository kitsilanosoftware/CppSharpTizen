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
 * @file	FUiCtrlGroupedListViewTypes.h
 * @brief	This is the header file for the GroupedListView enumerations.
 *
 * This header file contains the declarations of the GroupedListView enumerations.
 */
#ifndef _FUI_CTRL_GROUPED_LIST_VIEW_TYPES_H_
#define _FUI_CTRL_GROUPED_LIST_VIEW_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum	GroupedListViewStyle
 *
 * Defines the style of %GroupedListView.
 *
 * @since 2.0
 */
enum GroupedListViewStyle
{
	GROUPED_LIST_VIEW_STYLE_INDEXED = 0,                /**< The group and the item are displayed in a rectangular area */
	GROUPED_LIST_VIEW_STYLE_SECTION                     /**< All the items in the group are displayed in a rounded rectangle */
}; // GroupedListViewStyle

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_GROUPED_LIST_VIEW_TYPES_H_
