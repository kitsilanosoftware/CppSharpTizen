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
 * @file		FUiClipboardTypes.h
 * @brief		This is the header file for the enumerations of the Clipboard class.
 *
 * The %ClipboardDataType enumeration defines the data types for the system clipboard.
 */

#ifndef _FUI_CLIPBOARD_ENUM_H_
#define _FUI_CLIPBOARD_ENUM_H_

namespace Tizen { namespace Ui
{
/**
 * @enum ClipboardDataType
 *
 * Defines the data types supported by %Clipboard.
 *
 * @since 2.0
 */
enum ClipboardDataType
{
	CLIPBOARD_DATA_TYPE_TEXT = 0x0001, /**< The text data type */
	CLIPBOARD_DATA_TYPE_HTML = 0x0002, /**< The HTML data type */
	CLIPBOARD_DATA_TYPE_IMAGE = 0x0004, /**< The image data type */
	CLIPBOARD_DATA_TYPE_VIDEO = 0x0008, /**< The video data type */
	CLIPBOARD_DATA_TYPE_AUDIO = 0x0010, /**< The audio data type */
	CLIPBOARD_DATA_TYPE_MAX = 0x7fff, // The data type max
	CLIPBOARD_DATA_TYPE_NONE = 0x0000 // No data type
};

}} // Tizen::Ui

#endif // _FUI_CLIPBOARD_ENUM_H_
