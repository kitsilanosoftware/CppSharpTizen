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
 * @file     FUiSystemUtil.h
 * @brief    This is the header file for the SystemUtil
 *
 * This header file contains the declarations of the SystemUtil class.
 *
 */

#ifndef _FUI_SYSTEM_UTIL_H_
#define _FUI_SYSTEM_UTIL_H_

#include <FUiIKeyEventListener.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
class Point;
}}

namespace Tizen { namespace Ui
{

/**
 * @enum         KeyEventType
 *
 * Defines key event types.
 *
 * @since 2.0
 */
enum KeyEventType
{
	KEY_EVENT_TYPE_PRESSED,           /**< Key pressed event type */
	KEY_EVENT_TYPE_RELEASED,          /**< Key released event type */
};

/**
 * @enum         TouchEventType
 *
 * Defines touch event types.
 *
 * @since 2.0
 */
enum TouchEventType
{
	TOUCH_EVENT_TYPE_PRESSED,           /**< Touch pressed event type */
	TOUCH_EVENT_TYPE_RELEASED,          /**< Touch released event type */
	TOUCH_EVENT_TYPE_MOVED             /**< Touch moved event type */
};


}} //Tizen::Ui
#endif

