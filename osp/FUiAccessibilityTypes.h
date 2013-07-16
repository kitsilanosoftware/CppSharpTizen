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
 * @file        FUiAccessibilityTypes.h
 * @brief       This is the header file for declarations of the accessibility enumeration .
 *
 * This header file contains the declarations of the accessibility enumeration .
 *
 */

#ifndef _FUI_ACCESSIBILITY_TYPES_H_
#define _FUI_ACCESSIBILITY_TYPES_H_

namespace Tizen { namespace Ui
{
/**
 * @enum AccessibilityScreenReaderStatus
 *
 * Defines the status of the accessibility screen reader.
 *
 * @since 2.0
 */
enum AccessibilityScreenReaderStatus
{
	ACCESSIBILITY_SCREEN_READER_STATUS__NONE,  /**< Initial value to which the screen reader is set */
	ACCESSIBILITY_SCREEN_READER_STATUS_ERROR,  /**< An error has occurred. */
	ACCESSIBILITY_SCREEN_READER_STATUS_READY, /**< Screen reader is idle. */
	ACCESSIBILITY_SCREEN_READER_STATUS_PLAYING, /**< Screen reader is in use. */
	ACCESSIBILITY_SCREEN_READER_STATUS_PAUSE, /**< Screen reader has been paused. */
};

}} //Tizen::Ui
#endif //_FUI_ACCESSIBILITY_TYPES_H_
