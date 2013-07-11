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
 * @file		FUiCtrlSliderTypes.h
 * @brief		This is the header file for the SliderStyle enumerations.
 *
 * This header files contains the declarations of the SliderStyle enumeration.
 *
 */
#ifndef _FUI_CTRL_SLIDER_TYPES_H_
#define _FUI_CTRL_SLIDER_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum	SliderStyle
 *
 * Defines the slider styles.
 *
 * @since	2.0
 */
enum SliderStyle
{
	SLIDER_STYLE_NONE = 0x0000,                     /**< The no bubble, no title slider */
	SLIDER_STYLE_BUBBLE = 0x0001,                   /**< The bubble style slider */
	SLIDER_STYLE_TITLE = 0x0002,                    /**< The title style slider */
};

/**
 * @enum     SliderThumbStatus
 *
 * Defines the possible states of the slider thumb.
 *
 * @since 2.0
 */

enum SliderThumbStatus
{
	SLIDER_THUMB_STATUS_NORMAL,               /**< The normal state */
	SLIDER_THUMB_STATUS_PRESSED,              /**< The pressed state */
	SLIDER_THUMB_STATUS_DISABLED,             /**< The disabled state */
	SLIDER_THUMB_STATUS_HIGHLIGHTED,          /**< The focus-highlighted state */
};

}}}	// Tizen::Ui::Controls

#endif  //_FUI_CTRL_SLIDER_TYPES_H_
