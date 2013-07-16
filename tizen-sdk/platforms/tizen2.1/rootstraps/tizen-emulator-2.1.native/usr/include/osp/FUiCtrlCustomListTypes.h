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
 * @file		FUiCtrlCustomListTypes.h
 * @brief		This is the header file for the %CustomListStyle enumeration.
 *
 * This header file contains the declarations of the %CustomListStyle enumeration.
 * This enum defines the styles for the CustomList control.
 */
#ifndef _FUI_CTRL_CUSTOM_LIST_TYPES_H_
#define _FUI_CTRL_CUSTOM_LIST_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @enum CustomListStyle
 *
 * Defines the styles of CustomList.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This enum is deprecated. Instead of using this enum, use the ListAnnexStyle enumeration for the CustomItem or SimpleItem class.
 * @since		2.0
 * @endif
 */
enum CustomListStyle
{
	CUSTOM_LIST_STYLE_NORMAL = 0,                   /**< @if OSPDEPREC No mark, radio, or On/Off check @endif */
	CUSTOM_LIST_STYLE_RADIO,                        /**< @if OSPDEPREC The radio style for single selection @endif */
	CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER,           /**< @if OSPDEPREC The radio style with divider for single selection @endif */
	CUSTOM_LIST_STYLE_MARK,                         /**< @if OSPDEPREC The mark style for multiple selection @endif */
	CUSTOM_LIST_STYLE_MARK_WITH_DIVIDER,            /**< @if OSPDEPREC The mark style with divider for multiple selection @endif */
	CUSTOM_LIST_STYLE_ONOFF,                        /**< @if OSPDEPREC The On/Off style @endif */
	CUSTOM_LIST_STYLE_ONOFF_WITH_DIVIDER            /**< @if OSPDEPREC The On/Off style with divider @endif */
};

}}}       // Tizen::Ui::Controls

#endif //_FUI_CTRL_CUSTOM_LIST_TYPES_H_
