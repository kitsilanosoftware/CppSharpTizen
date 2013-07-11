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
	ACCESSIBILITY_SCREEN_READER_STATUS__NONE,		/**< initial value.*/
	ACCESSIBILITY_SCREEN_READER_STATUS_ERROR,		/**<screen reader has been occurred error.*/
	ACCESSIBILITY_SCREEN_READER_STATUS_READY,		/**< screen reader is idle*/
	ACCESSIBILITY_SCREEN_READER_STATUS_PLAYING,		/**< screen reader is playing*/
	ACCESSIBILITY_SCREEN_READER_STATUS_PAUSE,		/**< screen reader is paused*/
};

}} //Tizen::Ui
#endif //_FUI_ACCESSIBILITY_TYPES_H_
