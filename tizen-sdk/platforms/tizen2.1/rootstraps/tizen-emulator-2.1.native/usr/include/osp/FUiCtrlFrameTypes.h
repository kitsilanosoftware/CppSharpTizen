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
 * @file		FUiCtrlFrameTypes.h
 * @brief		This is the header file for the Frame type.
 *
 * This header file contains the declarations of the Frame type.
 *
 */
#ifndef _FUI_CTRL_FRAME_TYPES_H_
#define _FUI_CTRL_FRAME_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum FrameShowMode
 *
 * Defines the mode to show the Frame control.
 *
 * @since 2.0
 */
enum FrameShowMode
{
	FRAME_SHOW_MODE_FULL_SCREEN,                 /**< The frame occupies the whole screen */
	FRAME_SHOW_MODE_PARTIAL_SCREEN,              /**< The frame occupies the partial screen */
	FRAME_SHOW_MODE_PARTIAL_SCREEN_FLOATING,     /**< The frame is always on top of other frames, occupying the partial screen */
	FRAME_SHOW_MODE_MINIMIZED,                   /**< The frame is minimized @b Since: @b 2.1 */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_FRAME_TYPES_H_