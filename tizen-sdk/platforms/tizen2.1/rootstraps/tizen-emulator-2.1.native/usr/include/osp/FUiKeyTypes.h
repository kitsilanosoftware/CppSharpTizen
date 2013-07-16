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
* @file		FUiKeyTypes.h
* @brief	This is the header file for the key enumeration.
*
* This header file contains the declarations of the key enumeration.
*/
#ifndef _FUI_KEY_TYPES_H_
#define _FUI_KEY_TYPES_H_

namespace Tizen { namespace Ui
{

/**
 * @enum	KeyCode
 *
 * Defines the list of keys supported by the system. @n
 * Note that certain keys may not be available on all devices. @n
 * Please use the Tizen::Ui::KeyboardMap class to query the availability of a specific key on a target device.
 *
 * @since	2.0
 */
enum KeyCode
{
	KEY_INVALID		= 0x0000,		/**< The invalid key */
	KEY_SIDE_UP,		/**< The up side key */
	KEY_SIDE_DOWN,		/**< The down side key */
	KEY_OK,				/**< The OK key */
	KEY_CLEAR,			/**< The clear key */
	KEY_CAMERA,		/**< The camera key */
	KEY_SWITCH,		/**< The task switcher key */
	KEY_0,			/**< The 0 key */
	KEY_1,			/**< The 1 key */
	KEY_2,			/**< The 2 key */
	KEY_3,			/**< The 3 key */
	KEY_4,			/**< The 4 key */
	KEY_5,			/**< The 5 key */
	KEY_6,			/**< The 6 key */
	KEY_7,			/**< The 7 key */
	KEY_8,			/**< The 8 key */
	KEY_9,			/**< The 9 key */
	KEY_ASTERISK,			/**< The asterisk key */
	KEY_SHARP,			/**< The sharp key */
	KEY_LEFT,			/**< The left directional key */
	KEY_UP,			/**< The up directional key */
	KEY_DOWN,			/**< The down directional key */
	KEY_RIGHT,			/**< The right directional key */
	KEY_MAX,			/**< The Placeholder */
	KEY_A,			/**< The A key */
	KEY_B,			/**< The B key */
	KEY_C,			/**< The C key */
	KEY_D,			/**< The D key */
	KEY_E,			/**< The E key */
	KEY_F,			/**< The F key */
	KEY_G,			/**< The G key */
	KEY_H,			/**< The H key */
	KEY_I,			/**< The I key */
	KEY_J,			/**< The J key */
	KEY_K,			/**< The K key */
	KEY_L,			/**< The L key */
	KEY_M,			/**< The M key */
	KEY_N,			/**< The N key */
	KEY_O,			/**< The O key */
	KEY_P,			/**< The P key */
	KEY_Q,			/**< The Q key */
	KEY_R,			/**< The R key */
	KEY_S,			/**< The S key */
	KEY_T,			/**< The T key */
	KEY_U,			/**< The U key */
	KEY_V,			/**< The V key */
	KEY_W,			/**< The W key */
	KEY_X,			/**< The X key */
	KEY_Y,			/**< The Y key */
	KEY_Z,			/**< The Z key */
	KEY_BACKSPACE,			/**< The backspace key */
	KEY_COMMA,			/**< The comma key */
	KEY_ENTER,			/**< The enter key */
	KEY_CAPSLOCK,			/**< The Caps Lock key */
	KEY_QUESTION,			/**< The Question key */
	KEY_ALT,			/**< The Alt key */
	KEY_SYM,			/**< The Language Symbolkey */
	KEY_SETTING,			/**< The Language Setting key */
	KEY_SPACE,			/**< The Space key */
	KEY_DOT,			/**< The Dot key */
	KEY_FN,			/**< The Function key */
	KEY_CAMERA_HALF_SHUTTER,			/**< The camera half shutter key */
	KEY_CHAR_SYM_1,			/**< The Character symbol 1 key */
	KEY_CHAR_SYM_2,			/**< The Character symbol 2 key */
	KEY_CHAR_SYM_3,			/**< The Character symbol 3 key */
	KEY_CHAR_SYM_4,			/**< The Character symbol 4 key */
	KEY_CHAR_SYM_5,			/**< The Character symbol 5 key */
	KEY_CHAR_SYM_6,			/**< The Character symbol 6 key */
	KEY_CHAR_SYM_7,			/**< The Character symbol 7 key */
	KEY_CHAR_SYM_8,			/**< The Character symbol 8 key */
	KEY_CHAR_SYM_9,			/**< The Character symbol 9 key */
	KEY_CHAR_SYM_A,			/**< The Character symbol A key */
	KEY_CHAR_SYM_B,			/**< The Character symbol B key */
	KEY_CHAR_SYM_C,			/**< The Character symbol C key */
	KEY_CHAR_SYM_D,			/**< The Character symbol D key */
	KEY_CHAR_SYM_E,			/**< The Character symbol E key */
	KEY_CHAR_SYM_F,			/**< The Character symbol F key */
	KEY_FN_1,			/**< The function 1 key */
	KEY_FN_2,			/**< The function 2 key */
	KEY_FN_3,			/**< The function 3 key */
	KEY_FN_4,			/**< The function 4 key */
	KEY_FN_5,			/**< The function 5 key */
	KEY_POWER_HOLD,			/**< The power key */
	KEY_DELETE,			/**< The delete key */

	KEY_APOSTROPHE,	/**< The apostrophe key */
	KEY_BACKSLASH,		/**< The backslash key */
	KEY_CONTEXT_MENU,	/**< The menu key */
	KEY_EQUAL,			/**< The equal key */
	KEY_ESC,			/**< The esc key */
	KEY_FN_6,			/**< The function 6 key */
	KEY_FN_7,			/**< The function 7 key */
	KEY_FN_8,			/**< The function 8 key */
	KEY_FN_9,			/**< The function 9 key */
	KEY_FN_10,			/**< The function 10 key */
	KEY_FN_11,			/**< The function 11 key */
	KEY_FN_12,			/**< The function 12 key */
	KEY_GRAVE,			/**< The grave key */
	KEY_INSERT,			/**< The insert key */
	KEY_LANGUAGE_SWITCH,	/**< The language switch key */
	KEY_LEFT_ALT,		/**< The left alt key */
	KEY_LEFT_BRACKET,	/**< The left bracket key */
	KEY_LEFT_CTRL,		/**< The left control key */
	KEY_LEFT_SHIFT,		/**< The left shift key */
	KEY_LEFT_WIN,		/**< The left window key */
	KEY_MINUS,			/**< The minus key */
	KEY_MOVE_END,			/**< The end key */
	KEY_MOVE_HOME,		/**< The home key */
	KEY_NUM_LOCK,		/**< The number lock key */
	KEY_NUMPAD_0,		/**< The Numpad 0 key */
	KEY_NUMPAD_1,		/**< The Numpad 1 key */
	KEY_NUMPAD_2,		/**< The Numpad 2 key */
	KEY_NUMPAD_3,		/**< The Numpad 3 key */
	KEY_NUMPAD_4,		/**< The Numpad 4 key */
	KEY_NUMPAD_5,		/**< The Numpad 5 key */
	KEY_NUMPAD_6,		/**< The Numpad 6 key */
	KEY_NUMPAD_7,		/**< The Numpad 7 key */
	KEY_NUMPAD_8,		/**< The Numpad 8 key */
	KEY_NUMPAD_9,		/**< The Numpad 9 key */
	KEY_NUMPAD_ADD,		/**< The Numpad add key */
	KEY_NUMPAD_DIVIDE,	/**< The Numpad divide key */
	KEY_NUMPAD_DOT,		/**< The Numpad dot key */
	KEY_NUMPAD_ENTER,	/**< The Numpad enter key */
	KEY_NUMPAD_MULTIPLY,	/**< The Numpad multiply key */
	KEY_NUMPAD_SUBTRACT,	/**< The Numpad subtract key */
	KEY_PAGE_DOWN,		/**< The page down key */
	KEY_PAGE_UP,		/**< The page up key */
	KEY_PAUSE_BREAK,	/**< The pause key */
	KEY_PRINT,			/**< The print key */
	KEY_RIGHT_ALT,		/**< The right alt key */
	KEY_RIGHT_BRACKET,	/**< The right bracket key */
	KEY_RIGHT_CTRL,		/**< The right control key */
	KEY_RIGHT_SHIFT,		/**< The right shift key */
	KEY_RIGHT_WIN,		/**< The right window key */
	KEY_SCROLL_LOCK,	/**< The scroll lock key */
	KEY_SEMICOLON,		/**< The semicolon key */
	KEY_SLASH,			/**< The slash key */
	KEY_TAB,			/**< The tab key */
	KEY_OEM_1,			/**< The OEM 1 key */
	KEY_OEM_2,			/**< The OEM 2 key */
	KEY_OEM_3,			/**< The OEM 3 key */
	KEY_OEM_4,			/**< The OEM 4 key */
	KEY_OEM_5,			/**< The OEM 5 key */
	KEY_OEM_6,			/**< The OEM 6 key */
	KEY_OEM_7,			/**< The OEM 7 key */
	KEY_OEM_8,			/**< The OEM 8 key */
	KEY_OEM_9,			/**< The OEM 9 key */
	KEY_OEM_10,			/**< The OEM 10 key */
	KEY_OEM_11,			/**< The OEM 11 key */
	KEY_OEM_12,			/**< The OEM 12 key */
	KEY_OEM_13,			/**< The OEM 13 key */
	KEY_OEM_14,			/**< The OEM 14 key */
	KEY_OEM_15,			/**< The OEM 15 key */
	KEY_OEM_16,			/**< The OEM 16 key */
	KEY_OEM_17,			/**< The OEM 17 key */
	KEY_OEM_18,			/**< The OEM 18 key */
	KEY_OEM_19,			/**< The OEM 19 key */
	KEY_OEM_20,			/**< The OEM 20 key */
	KEY_HARDWARE_MAX	/**< The placeholder key */
};

/**
 * @enum 	KeyState
 *
 *	Defines the state of a key.
 *
 * @since	2.0
 */
enum KeyState
{
	KEY_PRESSED = 0x0001,       /**< The key is pressed */
	KEY_RELEASED = 0x0002,      /**< The key is released */
	KEY_LONGPRESSED = 0x0003    /**< The key pressed and held down over a predefined duration */
};

/**
 * @enum 	KeyModifier
 *
 *	Defines constants used to identify key modifiers.
 *
 * @since	2.1
 */
enum KeyModifier
{
	KEY_MODIFIER_NONE = 0,      /**< No active modifiers */
	KEY_MODIFIER_SHIFT = 1 << 0, /**< "Shift" is being pressed */
	KEY_MODIFIER_CTRL = 1 << 1, /**< "Control" is being pressed */
	KEY_MODIFIER_ALT = 1 << 2, /**< "Alt" is being pressed */
	KEY_MODIFIER_WIN = 1 << 3, /**< "Win" (between "Ctrl" and "Alt") is being pressed */
	KEY_MODIFIER_SCROLL_LOCK = 1 << 4, /**< "Scroll" is locked */
	KEY_MODIFIER_NUM_LOCK = 1 << 5, /**< "Num Lock" on the keyboard is locked */
	KEY_MODIFIER_CAPS_LOCK = 1 << 6, /**< "Caps" is locked */
};

}} // Tizen::Ui

#endif // _FUI_KEY_TYPES_H_

