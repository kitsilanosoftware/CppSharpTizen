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
 * @file		FUiInputConnectionTypes.h
 * @brief	This is the header file for the data types.
 *
 * This header file contains the declarations of the commonly used data types.
 *
 */


#ifndef _FUI_INPUT_CONNECTION_TYPES_H_
#define _FUI_INPUT_CONNECTION_TYPES_H_

namespace Tizen { namespace Ui {


/**
 *	@enum	InputPanelStyle
 *	Defines the style of the input panel.
 *
 *	@since 2.0
 */
enum InputPanelStyle
{
	INPUT_PANEL_STYLE_NORMAL,				/**< Default style */
	INPUT_PANEL_STYLE_EMAIL,				/**< Email style */
	INPUT_PANEL_STYLE_URL,					/**< URL	style */
	INPUT_PANEL_STYLE_NUMBER,				/**< Number style */
	INPUT_PANEL_STYLE_NUMBER_ONLY,			/**< Number Only style */
	INPUT_PANEL_STYLE_PHONE_NUMBER,			/**< Phone Number  style */
	INPUT_PANEL_STYLE_IP					/**< IP style */
};

/**
 *	@enum	InputPanelShowState
 *	Defines the state of the input panel.
 *
 *	@since 2.0
 */
enum InputPanelShowState
{
	INPUT_PANEL_SHOW_STATE_SHOW,    				/**< Show State */
	INPUT_PANEL_SHOW_STATE_HIDE    				/**< Hide State */
};

/**
 *	@enum	AutoCapitalizationMode
 *	Defines the type of auto-capitalization mode.
 *
 *	@since 2.0
 */
enum AutoCapitalizationMode
{
	AUTO_CAPITALIZATION_MODE_NONE,					/**< Auto-capitalization mode is set to None */
	AUTO_CAPITALIZATION_MODE_WORD,					/**< Auto-capitalization mode is Word */
	AUTO_CAPITALIZATION_MODE_SENTENCE,				/**< Auto-capitalization mode is Sentence */
	AUTO_CAPITALIZATION_MODE_ALL						/**< Auto-capitalization mode is set to All */
};

/**
 * @enum 		InputPanelAction
 *
 * Defines the possible keypad action types.
 * @since 2.0
 */
enum InputPanelAction
{
	INPUT_PANEL_ACTION_ENTER,				/**< The Enter key */
	INPUT_PANEL_ACTION_GO,					/**< The Go key */
	INPUT_PANEL_ACTION_NEXT,	    		/**< The Next key */
	INPUT_PANEL_ACTION_SEND,	    			/**< The Send key */
	INPUT_PANEL_ACTION_SEARCH,   			/**< The Search key */
	INPUT_PANEL_ACTION_LOGIN,    			/**< The Login key */
	INPUT_PANEL_ACTION_SIGN_IN,  			/**< The Sign-In key */
	INPUT_PANEL_ACTION_JOIN,	    		/**< The Join key */
	INPUT_PANEL_ACTION_DONE		    		/**< The Done key */
};

}} // Tizen::Ui

#endif // _FUI_INPUT_CONNECTION_TYPES_H_
