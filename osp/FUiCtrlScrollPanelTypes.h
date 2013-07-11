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
 * @file		FUiCtrlScrollPanelTypes.h
 * @brief		This is the header file for the ScrollPanel enumeration.
 *
 * The ScrollPanel enumeration defines the data types for the ScrollPanel.
 */
#ifndef _FUI_CTRL_SCROLL_PANEL_TYPES_H_
#define _FUI_CTRL_SCROLL_PANEL_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum ScrollPanelScrollDirection
 *
 * Defines the scroll direction type of the ScrollPanel control.
 *
 * @since 2.0
 */
enum ScrollPanelScrollDirection
{
	SCROLL_PANEL_SCROLL_DIRECTION_VERTICAL = 0,	/**< Vertical scroll mode */
	SCROLL_PANEL_SCROLL_DIRECTION_HORIZONTAL	/**< Horizontal scroll mode */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_SCROLL_PANEL_TYPES_H_
