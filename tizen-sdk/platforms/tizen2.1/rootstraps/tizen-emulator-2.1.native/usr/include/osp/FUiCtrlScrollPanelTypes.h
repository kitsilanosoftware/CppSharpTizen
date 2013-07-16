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
 * @file		FUiCtrlScrollPanelTypes.h
 * @brief		This is the header file for the enumerations of the ScrollPanel class.
 *
 * This header file defines the data types for the ScrollPanel class.
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

/**
* @enum ScrollInputMode
*
* Defines the scroll interaction mode.
*
* @since 2.0
*/
enum ScrollInputMode
{
	SCROLL_INPUT_MODE_ALLOW_ANY_DIRECTION = 0,                               /**< Content can be scrolled in any direction */
	SCROLL_INPUT_MODE_RESTRICT_TO_INITIAL_DIRECTION                          /**< Content can be scrolled only in the first direction */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_SCROLL_PANEL_TYPES_H_
