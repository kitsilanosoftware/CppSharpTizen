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
 * @file		FUiCtrlSplitPanelTypes.h
 * @brief		This is the header file for the enumerations of the SplitPanel class.
 *
 * This header file contains the declarations of the enumerations of the SplitPanel class.
 *
 */
#ifndef _FUI_CTRL_SPLIT_PANEL_TYPES_H_
#define _FUI_CTRL_SPLIT_PANEL_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum SplitPanelDividerStyle
 *
 * Defines the divider style of the SplitPanel control.
 *
 * @since 2.0
 */
enum SplitPanelDividerStyle
{
	SPLIT_PANEL_DIVIDER_STYLE_FIXED,		/**< The fixed divider style */
	SPLIT_PANEL_DIVIDER_STYLE_MOVABLE		/**< The movable divider style */
};

/**
 * @enum SplitPanelDividerDirection
 *
 * Defines the divider direction of the SplitPanel control.
 *
 * @since 2.0
 */
enum SplitPanelDividerDirection
{
	SPLIT_PANEL_DIVIDER_DIRECTION_VERTICAL, 			/**< Set to vertical divider */
	SPLIT_PANEL_DIVIDER_DIRECTION_HORIZONTAL        	/**< Set to horizontal divider */
};

/**
 * @enum	SplitPanelPaneOrder
 *
 * Defines the pane order of the SplitPanel control.
 *
 * @since 2.0
 */
enum SplitPanelPaneOrder
{
	SPLIT_PANEL_PANE_ORDER_FIRST, /**< The panel located on the left side or upper side */
	SPLIT_PANEL_PANE_ORDER_SECOND /**< The panel located on the right side or down side */
};

}}}	// Tizen::Ui::Controls

#endif  //_FUI_CTRL_SPLIT_PANEL_TYPES_H_

