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
 * @file	FGrpFontCommon.h
 * @brief	This is the header file for the enumerations of the Font class.
 *
 * This header file contains the definitions of the enumerations of the Font class.
 */

#ifndef _FGRP_FONT_COMMON_H_
#define _FGRP_FONT_COMMON_H_

namespace Tizen { namespace Graphics
{
/**
* @enum	FontStyle
*
* Defines the style of the Font class instance.
*
* @since	2.0
*
* @remarks  Several different font styles can be combined using the "OR" operator. @n
*			(For example, int style = @c FONT_STYLE_BOLD | @c FONT_STYLE_ITALIC).
*/
enum FontStyle
{
	FONT_STYLE_PLAIN = 0x0001, /**< The plain font style */
	FONT_STYLE_BOLD = 0x0002, /**< The bold font style */
	FONT_STYLE_ITALIC = 0x0004, /**<The italic font style */
	FONT_STYLE_MAX, // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	FONT_STYLE_MIN = 0 // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

} } // Tizen::Graphics

#endif // _FGRP_FONT_COMMON_H_
