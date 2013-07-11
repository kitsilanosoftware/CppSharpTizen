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
 * @file		FUiCtrlGroupTypes.h
 * @brief		This is the header file for the table view style enumeration.
 *
 * This header file contains the declarations of the table view style enumeration.
 */
#ifndef _FUI_CTRL_GROUP_TYPES_H_
#define _FUI_CTRL_GROUP_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

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

}}}	// Tizen::Ui::Controls

#endif	// _FUI_CTRL_GROUP_TYPES_H_
