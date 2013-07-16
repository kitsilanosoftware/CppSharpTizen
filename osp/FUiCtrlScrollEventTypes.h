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
 * @file	FUiCtrlScrollEventTypes.h
 * @brief	This is the header file for the List enumerations.
 *
 * @since 2.0
 *
 * This header file contains the declarations of the scroll event enumerations.
 */

#ifndef _FUI_CTRL_SCROLL_EVENT_ENUM_H_
#define _FUI_CTRL_SCROLL_EVENT_ENUM_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum ScrollEndEvent
 *
 * Defines constants that represent the type of scroll end event.
 *
 * @since 2.0
 */
enum ScrollEndEvent
{
	SCROLL_END_EVENT_END_TOP = 0,                 /**< The scroll reaches top end */
	SCROLL_END_EVENT_END_BOTTOM,                  /**< The scroll reaches bottom end */
	SCROLL_END_EVENT_END_LEFT,                    /**< The scroll reaches left end */
	SCROLL_END_EVENT_END_RIGHT                   /**< The scroll reaches right end */
};

}}}	// Tizen::Ui::Controls

#endif
