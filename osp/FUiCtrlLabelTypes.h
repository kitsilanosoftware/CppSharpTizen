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
* @file		FUiCtrlLabelTypes.h
* @brief	This is the header file for the LabelTextStyle enumeration.
*
* This header file contains the declarations of the LabelTextStyle enumeration.
*/
#ifndef _FUI_CTRL_LABEL_ENUM_H_
#define _FUI_CTRL_LABEL_ENUM_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
  * @enum	LabelTextStyle
  *
  * Defines the text styles of the label.
  *
  * @since		2.0
  */
enum LabelTextStyle
{
	LABEL_TEXT_STYLE_NORMAL,        /**< The plain text style */
	LABEL_TEXT_STYLE_BOLD,      /**< The bold text style */
	LABEL_TEXT_STYLE_ITALIC,        /**< The italic text style */
};

/**
  * @enum	LabelContentHint
  *
  * Defines the content update type.
  *
  * @since 2.0
  */
enum LabelContentHint
{
	LABEL_CONTENT_HINT_DYNAMIC,         /**< The contents will change */
	LABEL_CONTENT_HINT_STATIC      	/**< The contents will not change */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_LABEL_ENUM_H_
