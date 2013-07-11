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
 * @file		FUiCtrlIconListTypes.h
 * @brief		This is the header file for the %IconList enumerations.
 *
 * This header file contains the declarations of the %IconList enumerations.
 *
 * These enumerations define the various properties of the %IconList control.
 */

#ifndef _FUI_CTRL_ICON_LIST_TYPES_H_
#define _FUI_CTRL_ICON_LIST_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @enum    IconListStyle
 *
 * Defines the styles of %IconList.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the IconListViewStyle enumeration.
 * @since		2.0
 * @endif
 */
enum IconListStyle
{
	ICON_LIST_STYLE_NORMAL = 0,                         /**< @if OSPDEPREC The No mark or radio check @endif */
	ICON_LIST_STYLE_RADIO,                              /**< @if OSPDEPREC The radio style for single selection @endif */
	ICON_LIST_STYLE_MARK,                               /**< @if OSPDEPREC The mark style for multiple selection @endif */
};

/**
 * @if OSPDEPREC
 * @enum IconListCheckBoxPosition
 *
 * Defines the check-box position.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the IconListViewCheckBoxPosition enumeration.
 * @since	2.0
 * @endif
 */
enum IconListCheckBoxPosition
{
	ICON_LIST_CHECK_BOX_POSITION_TOP_LEFT,              /**< @if OSPDEPREC The position of checkbox is top-left @endif */
	ICON_LIST_CHECK_BOX_POSITION_TOP_RIGHT,             /**< @if OSPDEPREC The position of checkbox is top-right @endif */
	ICON_LIST_CHECK_BOX_POSITION_BOTTOM_LEFT,           /**< @if OSPDEPREC The position of checkbox is bottom-left @endif */
	ICON_LIST_CHECK_BOX_POSITION_BOTTOM_RIGHT           /**< @if OSPDEPREC The position of checkbox is bottom-right @endif */
};

}}} // Tizen::Ui::Controls

#endif //_FUI_CTRL_ICON_LIST_TYPES_H_
