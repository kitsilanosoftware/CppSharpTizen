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
 * @file			FUiCtrlEditTypes.h
 * @brief			This is the header file for the Ui::Controls edit control enumerations.
 *
 * This header file contains the declarations of the Ui::Controls edit control enumerations.
 */
#ifndef _FUI_CTRL_EDIT_ENUM_H_
#define _FUI_CTRL_EDIT_ENUM_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @enum EditInputModeCategory
 *
 * Defines the input modes.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated We no longer provide a method to specify the list of styles which the user can set the keypad to, or the current mode to initially set the keypad to, @n
 *			   from this list. It is recommended to use the styles offered in EditFieldStyle or KeypadStyle enumerations instead.
 * @since		2.0
 * @endif
 */
enum EditInputModeCategory
{
	EDIT_INPUTMODE_ALPHA = 0x0001, /**< @if OSPDEPREC The alphabetic input mode @endif */
	EDIT_INPUTMODE_PREDICTIVE = 0x0002, /**< @if OSPDEPREC The predictive input mode @endif */
	EDIT_INPUTMODE_NUMERIC = 0x0004, /**< @if OSPDEPREC The numeric input mode @endif */
	EDIT_INPUTMODE_SYMBOL = 0x0008 /**< @if OSPDEPREC The symbolic input mode @endif */
};

/**
 * @enum EditFieldStyle
 *
 * Defines the EditField style.
 *
 * @since		2.0
 */
enum EditFieldStyle
{
	EDIT_FIELD_STYLE_NORMAL, /**< The normal style */
	EDIT_FIELD_STYLE_PASSWORD, /**< The password style '****' */
	EDIT_FIELD_STYLE_NORMAL_SMALL, /**< The small normal style */
	EDIT_FIELD_STYLE_PASSWORD_SMALL, /**< The small password style '****' */
	EDIT_FIELD_STYLE_EMAIL, /**< The email style */
	EDIT_FIELD_STYLE_URL, /**< The URL style */
	EDIT_FIELD_STYLE_EMAIL_SMALL, /**< The small email style */
	EDIT_FIELD_STYLE_URL_SMALL, /**< The small URL style */
	EDIT_FIELD_STYLE_NUMBER, /**< The number style */
	EDIT_FIELD_STYLE_NUMBER_SMALL,  /**< The small number style */
	EDIT_FIELD_STYLE_PHONE_NUMBER, /**< The phone number style */
	EDIT_FIELD_STYLE_PHONE_NUMBER_SMALL,    /**< The small phone number style */
	EDIT_FIELD_STYLE_PASSWORD_NUMBER, /**< The number password style */
	EDIT_FIELD_STYLE_PASSWORD_NUMBER_SMALL, /**< The small number password style */
	EDIT_FIELD_STYLE_IP_V4, /**< The IP V4 style */
	EDIT_FIELD_STYLE_IP_V4_SMALL, /**< The small IP V4 style */
};

/**
 * @enum CommandButtonPosition
 *
 * Defines the command button position.
 *
 * @since		2.0
 */
enum CommandButtonPosition
{
	COMMAND_BUTTON_POSITION_LEFT, /**< The position is to the left */
	COMMAND_BUTTON_POSITION_RIGHT /**< The position is to the right */
};

/**
 * @enum EditMarginType
 *
 * Defines the possible margin types of EditField and EditArea.
 *
 * @since		2.0
 */
enum EditMarginType
{
	EDIT_MARGIN_TYPE_VERTICAL, /**< The margin for top and bottom */
	EDIT_MARGIN_TYPE_HORIZONTAL /**< The margin for left and right */
};

/**
 * @enum EditTextColor
 *
 * Defines the possible Edit's text colors.
 *
 * @since		2.0
 */
enum EditTextColor
{
	EDIT_TEXT_COLOR_NORMAL,         /**< The normal text color */
	EDIT_TEXT_COLOR_DISABLED,       /**< The disabled text color */
	EDIT_TEXT_COLOR_HIGHLIGHTED,    /**< The selected text color */
	EDIT_TEXT_COLOR_LINK            /**< The highlighted text color */
};

/**
 * @enum EditStatus
 *
 * Defines the possible Edit's states.
 *
 * @since		2.0
 */
enum EditStatus
{
	EDIT_STATUS_NORMAL,         /**< The normal state */
	EDIT_STATUS_DISABLED,       /**< The disabled state */
	EDIT_STATUS_HIGHLIGHTED,    /**< The highlighted state */
	EDIT_STATUS_PRESSED         /**< The pressed state */
};

/**
 * @enum EditFieldTitleStyle
 *
 * Defines the possible styles of title.
 *
 * @since		2.0
 */
enum EditFieldTitleStyle
{
	EDIT_FIELD_TITLE_STYLE_NONE = 0,        /**< No title */
	EDIT_FIELD_TITLE_STYLE_INNER,           /**< The title appears inside of the EditField's input field */
	EDIT_FIELD_TITLE_STYLE_TOP              /**< The title appears at the top input field */
};

/**
 * @enum EllipsisPosition
 *
 * Defines the possible positions of ellipsis.
 *
 * @since		2.0
 */
enum EllipsisPosition
{
	ELLIPSIS_POSITION_START = 0,        /**< The ellipsis appears at the start of text block */
	ELLIPSIS_POSITION_MIDDLE,           /**< The ellipsis appears at the middle of text block */
	ELLIPSIS_POSITION_END,              /**< The ellipsis appears at the end of text block */
};

/**
 * @enum KeypadStyle
 *
 * Defines the initial keypad style.
 *
 * @since		2.0
 */
enum KeypadStyle
{
	KEYPAD_STYLE_NORMAL = 0, /**< The normal style */
	KEYPAD_STYLE_PASSWORD, /**< The password style '****' */
	KEYPAD_STYLE_EMAIL, /**< The email style */
	KEYPAD_STYLE_URL, /**< The URL style */
	KEYPAD_STYLE_NUMBER, /**< The number style  */
	KEYPAD_STYLE_PHONE_NUMBER, /**< The phone number style  */
	KEYPAD_STYLE_IP_V4, /**< The IP V4 style  */
};

}}} // Tizen::Ui::Controls
#endif // _FUI_CTRL_EDIT_ENUM_H_
