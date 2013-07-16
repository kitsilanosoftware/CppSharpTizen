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
 * @file	FUiUiConfigurationTypes.h
 * @brief	This is the header file for the common data types used by the UI configuration.
 *
 * This header file contains the descriptions of the common data types used by the UI configuration.
 */

#ifndef _FUI_UI_CONFIGURATION_TYPES_H_
#define _FUI_UI_CONFIGURATION_TYPES_H_

#include <FOspConfig.h>

namespace Tizen { namespace Ui {

struct _OSP_EXPORT_ ColorKey
{
	struct _OSP_EXPORT_ Button
	{
		/**
		* The property key to get the normal background color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the disabled background color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_DISABLED;

		/**
		* The property key to get the pressed background color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_PRESSED;

		/**
		* The property key to get the highlighted background color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_HIGHLIGHTED;
	};

	struct CheckButton
	{
		/**
		* The property key to get the normal background color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the disabled background color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_DISABLED;

		/**
		* The property key to get the pressed background color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_PRESSED;

		/**
		* The property key to get the highlighted background color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_SELECTED;

		/**
		* The property key to get the normal text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_SELECTED;

		/**
		* The property key to get the normal title text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		* The property key to get the disabled title text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_DISABLED;

		/**
		* The property key to get the pressed title text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_PRESSED;

		/**
		* The property key to get the highlighted title text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected title text color of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_SELECTED;

		/**
		* The property key to get the normal background color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_BG_SELECTED;

		/**
		* The property key to get the normal text color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the detailed icon of check button.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DETAILED_ICON_TEXT_SELECTED;

		/**
		* The property key to get the color of the left divider line of check button.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_LEFT_NORMAL;

		/**
		* The property key to get the color of the right divider line of check button.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_RIGHT_NORMAL;
	};
	struct _OSP_EXPORT_ ColorPicker
	{
		/**
		* The property key to get the color of top half part of divider of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_TOP_HALF;

		/**
		* The property key to get the color of bottom half part of divider of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_BOTTOM_HALF;

		/**
		* The property key to get the normal background color of the arrow button of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BUTTON_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the arrow button of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BUTTON_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the arrow button of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BUTTON_BG_DISABLED;

		/**
		* The property key to get the normal color of the arrow button of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BUTTON_NORMAL;

		/**
		* The property key to get the pressed color of the arrow button of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BUTTON_PRESSED;

		/**
		* The property key to get the disabled color of the arrow button of color picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BUTTON_DISABLED;
	};

	struct _OSP_EXPORT_ ContextMenu
	{
		/**
		* The property key to get the normal background color of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the color of list type divider 01 of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int LIST_ITEM_DIVIDER_01_NORMAL;

		/**
		* The property key to get the color of list type divider 02 of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int LIST_ITEM_DIVIDER_02_NORMAL;

		/**
		* The property key to get the normal background color of the item of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the item of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the item of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the color of grid type divider 01 of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GRID_ITEM_DIVIDER_01_NORMAL;

		/**
		* The property key to get the color of grid type divider 02 of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GRID_ITEM_DIVIDER_02_NORMAL;

		/**
		* The property key to get the normal text color of the item of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of the item of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the item of context menu.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_HIGHLIGHTED;
	};

	struct _OSP_EXPORT_ DateTimeBar
	{
		/**
		* The property key to get the background color of date time bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the normal text color of date time bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of date time bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;
	};
	struct _OSP_EXPORT_ DateTimePicker
	{
		/**
		* The property key to get the background color of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the normal background color of button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_BG_NORMAL;

		/**
		* The property key to get the pressed background color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_BG_HIGHLIGHTED;

		/**
		* The property key to get the disabled background color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_BG_DISABLED;

		/**
		* The property key to get the normal text color of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_HIGHLIGHTED;

		/**
		* The property key to get the disabled text color of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the normal text color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the disabled text color of AM/PM button of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int AM_PM_TEXT_DISABLED;

		/**
		* The property key to get the color of the left half of the divider of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LEFT_HALF;

		/**
		* The property key to get the color of the right half of the divider of date time picker.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_RIGHT_HALF;

		/**
		* The property key to get the normal background color of the picker button of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the picker button of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the picker button of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_DISABLED;

		/**
		* The property key to get the highlighted background color of the picker button of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the display area background color of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DISPLAY_BG_NORMAL;

		/**
		* The property key to get the normal title color of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_NORMAL;

		/**
		* The property key to get the disabled title color of date time picker
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_DISABLED;
	};
	struct _OSP_EXPORT_ Edit
	{
		/**
		* The property key to get the normal background color of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the pressed background color of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_PRESSED;

		/**
		* The property key to get the highlighted background color of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_HIGHLIGHTED;

		/**
		* The property key to get the disabled background color of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_DISABLED;

		/**
		* The property key to get the normal text color of the title text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		* The property key to get the pressed color of the title text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_PRESSED;

		/**
		* The property key to get the highlighted color of the title text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the disabled color of the title text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_DISABLED;

		/**
		* The property key to get the normal color of the text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed color of the text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the highlighted color of the text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_HIGHLIGHTED;

		/**
		* The property key to get the disabled color of the text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the color of the guide text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GUIDE_TEXT_NORMAL;

		/**
		* The property key to get the normal color of the clear icon of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CLEAR_ICON_NORMAL;

		/**
		* The property key to get the pressed color of the clear icon of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CLEAR_ICON_PRESSED;

		/**
		* The property key to get the color of the cut link text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CUT_LINK_TEXT_NORMAL;

		/**
		* The property key to get the background color of the cut link text of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CUT_LINK_BG_NORMAL;

		/**
		* The property key to get the color of the cursor of edit.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CURSOR_NORMAL;
	};

	struct _OSP_EXPORT_ EditDate
	{
		/**
		* The property key to get the normal color of the text of edit date.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed color of the text of edit date.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the disabled color of the text of edit date.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the normal color of the title text of edit date.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		* The property key to get the disabled color of the title text of edit date.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_DISABLED;

		/**
		* The property key to get the normal background color of the picker button of edit date
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the picker button of edit date
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the picker button of edit date
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_DISABLED;

		/**
		* The property key to get the highlighted background color of the picker button of edit date
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_HIGHLIGHTED;
	};

	struct _OSP_EXPORT_ EditTime
	{
		/**
		* The property key to get the normal background color of the button of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the button of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the button of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_DISABLED;

		/**
		* The property key to get the normal text color of the button of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of the button of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_PRESSED;

		/**
		* The property key to get the disabled text color of the button of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_DISABLED;

		/**
		* The property key to get the normal text color of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the disabled text color of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the normal title text color of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		* The property key to get the disabled title text color of edit time.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_DISABLED;

		/**
		* The property key to get the highlighted text color of the button of edit time
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the picker button of edit time
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the picker button of edit time
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the picker button of edit time
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_DISABLED;

		/**
		* The property key to get the highlighted background color of the picker button of edit time
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_BG_HIGHLIGHTED;
	};

	struct _OSP_EXPORT_ FastScroll
	{
		/**
		* The property key to get the normal background color of fast scroll index.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INDEX_BG_NORMAL;

		/**
		* The property key to get the pressed background color of fast scroll index.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INDEX_BG_PRESSED;

		/**
		* The property key to get the color of the line of fast scroll index.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INDEX_LINE_PRESSED;

		/**
		* The property key to get the normal text color of fast scroll index.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INDEX_TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of fast scroll index.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INDEX_TEXT_PRESSED;

		/**
		* The property key to get the color of the divider of fast scroll index.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INDEX_DIVIDER_NORMAL;

		/**
		* The property key to get the background color of the popup of fast scroll.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int POPUP_BG_NORMAL;

		/**
		* The property key to get the text color of the popup of fast scroll.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int POPUP_TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ Footer
	{
		/**
		* The property key to get the background color of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the background color of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the normal background color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the translucent style button of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_SELECTED;

		/**
		* The property key to get the normal background color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_SELECTED;

		/**
		* The property key to get the normal text color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the segmented item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_SELECTED;

		/**
		* The property key to get the normal text color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the segmented item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_SELECTED;

		/**
		* The property key to get the normal background color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_SELECTED;

		/**
		* The property key to get the normal background color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_SELECTED;

		/**
		* The property key to get the normal text color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the tab item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_SELECTED;

		/**
		* The property key to get the normal text color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the tab item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_SELECTED;

		/**
		* The property key to get the normal background color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button item of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button item of the translucent style of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal color of the back icon of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BACK_ICON_NORMAL;

		/**
		* The property key to get the disabled color of the back icon of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BACK_ICON_DISABLED;

		/**
		* The property key to get the pressed color of the back icon of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BACK_ICON_PRESSED;

		/**
		* The property key to get the highlighted color of the back icon of footer.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BACK_ICON_HIGHLIGHTED;

		/**
		* The property key to get the color of the left divider line of footer.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_LEFT_NORMAL;

		/**
		* The property key to get the color of the right divider line of footer.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_RIGHT_NORMAL;

		/**
		* The property key to get the color of the left divider line of the translucent style of footer.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_LEFT_TRANSLUCENT_NORMAL;

		/**
		* The property key to get the color of the right divider line of the translucent style of footer.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_RIGHT_TRANSLUCENT_NORMAL;
	};

	struct _OSP_EXPORT_ Form
	{
		/**
		* The property key to get the background color of form.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;
	};

	struct _OSP_EXPORT_ Gallery
	{
		/**
		* The property key to get the empty text color of gallery.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EMPTY_TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ Header
	{
		/**
		* The property key to get the background of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the background of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the color of the title text of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		* The property key to get the color of the title text of translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TRANSLUCENT_TITLE_TEXT_NORMAL;

		/**
		* The property key to get the color of the description text of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DESCRIPTION_TEXT_NORMAL;

		/**
		* The property key to get the color of the description text of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TRANSLUCENT_DESCRIPTION_TEXT_NORMAL;

		/**
		* The property key to get the normal background color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_BG_SELECTED;

		/**
		* The property key to get the normal background color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_BG_SELECTED;

		/**
		* The property key to get the normal text color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the segmented item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TEXT_SELECTED;

		/**
		* The property key to get the normal text color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the segmented item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SEGMENTED_ITEM_TRANSLUCENT_TEXT_SELECTED;

		/**
		* The property key to get the normal background color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_BG_SELECTED;

		/**
		* The property key to get the normal background color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the selected background color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_BG_SELECTED;

		/**
		* The property key to get the normal text color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the tab item of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TEXT_SELECTED;

		/**
		* The property key to get the normal text color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the selected text color of the tab item of the translucent style of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TAB_ITEM_TRANSLUCENT_TEXT_SELECTED;

		/**
		* The property key to get the normal background color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_BG_NORMAL;

		/**
		* The property key to get the disabled background color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_BG_DISABLED;

		/**
		* The property key to get the pressed background color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of badge icon of header.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BADGE_ICON_TEXT_HIGHLIGHTED;

				/**
		* The property key to get the color of the left divider line of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_LEFT_NORMAL;

		/**
		* The property key to get the color of the right divider line of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_RIGHT_NORMAL;

		/**
		* The property key to get the color of the left divider line of the translucent style of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_LEFT_TRANSLUCENT_NORMAL;

		/**
		* The property key to get the color of the right divider line of the translucent style of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_LINE_RIGHT_TRANSLUCENT_NORMAL;

		/**
		* The property key to get the normal background color of the button item of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button item of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button item of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button item of header.
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_DISABLED;

		/**
		* The property key to get the pressed background color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button item of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button item of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button item of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button item of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_DISABLED;

		/**
		* The property key to get the pressed text color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of the button item of the translucent style of header
		*
		* @since  2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_ITEM_TRANSLUCENT_TEXT_HIGHLIGHTED;
	};

	struct _OSP_EXPORT_ IconList
	{
		/**
		* The property key to get the empty text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EMPTY_TEXT_NORMAL;

		/**
		* The property key to get the normal text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_HIGHLIGHTED;

		/**
		* The property key to get the inner normal text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INNER_TEXT_NORMAL;

		/**
		* The property key to get the inner pressed text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INNER_TEXT_PRESSED;

		/**
		* The property key to get the inner highlighted text color of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INNER_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the background color of inner text area of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int INNER_TEXT_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the item of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_PRESSED;

		/**
		* The property key to get the normal border color of the item of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BORDER_NORMAL;

		/**
		* The property key to get the pressed border color of the item of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BORDER_PRESSED;

		/**
		* The property key to get the highlighted border color of the item of icon list.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BORDER_HIGHLIGHTED;
	};

	struct _OSP_EXPORT_ InputPad
	{
		/**
		* The property key to get the normal text color of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_PRESSED;

		/**
		* The property key to get the highlighted text color of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_HIGHLIGHTED;

		/**
		* The property key to get the disabled text color of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_DISABLED;

		/**
		* The property key to get the guide text color of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GUIDE_TEXT_NORMAL;

		/**
		* The property key to get the normal background color of the button of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the button of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_PRESSED;

		/**
		* The property key to get the highlighted background color of the button of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_HIGHLIGHTED;

		/**
		* The property key to get the disabled background color of the button of input pad.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_DISABLED;
	};

	struct _OSP_EXPORT_ Label
	{
		/**
		* The property key to get the text color of label.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ MessageBox
	{
		/**
		* The property key to get the background color of messagebox.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the color of the title text of messagebox.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		* The property key to get the color of the text of messagebox.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ Panel
	{
		/**
		* The property key to get the background color of grouped style of panel.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUPED_STYLE_BG_NORMAL;
	};

	struct _OSP_EXPORT_ Popup
	{
		/**
		* The property key to get the background color of popup.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		* The property key to get the color of the title text of popup.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ Progress
	{
		/**
		* The property key to get the background color of the bar of progress.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BAR_BG_NORMAL;

		/**
		* The property key to get the background color of progress.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BAR_NORMAL;
	};

	struct _OSP_EXPORT_ Scroll
	{
		/**
		* The property key to get the background color of thumb of scroll.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int THUMB_BG_NORMAL;

		/**
		* The property key to get the normal color of the jump-to-top button of scroll.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int JUMP_TO_TOP_NORMAL;

		/**
		* The property key to get the pressed color of the jump-to-top button of scroll.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int JUMP_TO_TOP_PRESSED;

		/**
		* The property key to get the normal background color of the button of scroll
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the button of scroll.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_PRESSED;
	};

	struct _OSP_EXPORT_ SearchBar
	{
		/**
		* The property key to get the normal background color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_DISABLED;

		/**
		* The property key to get the highlighted background color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_NORMAL;

		/**
		* The property key to get the pressed text color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_PRESSED;

		/**
		* The property key to get the disabled text color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_DISABLED;

		/**
		* The property key to get the highlighted text color of the button of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BUTTON_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the edit of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EDIT_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the edit of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EDIT_BG_DISABLED;

		/**
		* The property key to get the normal text color of the edit of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EDIT_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the edit of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EDIT_TEXT_DISABLED;

		/**
		* The property key to get the highlighted text color of the edit of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EDIT_TEXT_HIGHLIGHTED;

		/**
		* The property key to get the normal background color of the icon of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ICON_BG_NORMAL;

		/**
		* The property key to get the disabled background color of the icon of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ICON_BG_DISABLED;

		/**
		* The property key to get the background color of the content area of search bar.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTENT_AREA_BG_NORMAL;
	};

	struct _OSP_EXPORT_ Slider
	{
		/**
		* The property key to get the background color of the others style of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_OTHERS_NORMAL;

		/**
		* The property key to get the background color of the default style of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_DEFAULT_NORMAL;

		/**
		* The property key to get the background color of the bar of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BAR_BG_NORMAL;

		/**
		* The property key to get the color of the bar of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BAR_NORMAL;

		/**
		* The property key to get the normal background color of the handle of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int HANDLE_BG_NORMAL;

		/**
		* The property key to get the pressed background color of the handle of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int HANDLE_BG_PRESSED;

		/**
		* The property key to get the disabled background color of the handle of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int HANDLE_BG_DISABLED;

		/**
		* The property key to get the highlighted background color of the handle of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int HANDLE_BG_HIGHLIGHTED;

		/**
		* The property key to get the normal text color of the handle of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int HANDLE_NUMBER_TEXT_NORMAL;

		/**
		* The property key to get the disabled text color of the handle of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int HANDLE_NUMBER_TEXT_DISABLED;

		/**
		* The property key to get the color of the title text of slider.
		*
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TITLE_TEXT_NORMAL;

		/**
		 * The property key to get the background color of the overlay of slider.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int OVERLAY_BG_NORMAL;

		/**
		 * The property key to get the text color of the overlay of slider.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int OVERLAY_TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ SplitPanel
	{
		/**
		 * The property key to get the normal color of the divider of split panel.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_BG_NORMAL;

		/**
		 * The property key to get the pressed color of the divider of split panel.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int DIVIDER_BG_PRESSED;
	};

	struct _OSP_EXPORT_ TabBar
	{
		/**
		 * The property key to get the background color of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		 * The property key to get the normal background color of the item of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_NORMAL;

		/**
		 * The property key to get the pressed background color of the item of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_PRESSED;

		/**
		 * The property key to get the selected background color of the item of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_SELECTED;

		/**
		 * The property key to get the normal text color of the item of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_NORMAL;

		/**
		 * The property key to get the pressed text color of the item of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_PRESSED;

		/**
		 * The property key to get the selected text color of the item of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_SELECTED;

		/**
		 * The property key to get the background color of the arrow of tab bar.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ARROW_BG_NORMAL;
	};

	struct _OSP_EXPORT_ Tab
	{
		/**
		 * The property key to get the normal background color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_NORMAL;

		/**
		 * The property key to get the pressed background color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_PRESSED;

		/**
		 * The property key to get the selected background color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_SELECTED;

		/**
		 * The property key to get the highlighted background color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_HIGHLIGHTED;

		/**
		 * The property key to get the disabled background color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_DISABLED;

		/**
		 * The property key to get the normal text color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_NORMAL;

		/**
		 * The property key to get the pressed text color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_PRESSED;

		/**
		 * The property key to get the selected text color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_SELECTED;

		/**
		 * The property key to get the highlighted text color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_HIGHLIGHTED;

		/**
		 * The property key to get the disabled text color of the item of tab.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_DISABLED;
	};

	struct _OSP_EXPORT_ TableView
	{
		/**
		 * The property key to get the background color of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		 * The property key to get the color of top divider of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_DIVIDER_TOP_BG_NORMAL;

		/**
		 * The property key to get the color of bottom divider of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_DIVIDER_BOTTOM_BG_NORMAL;

		/**
		 * The property key to get the normal background color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_NORMAL;

		/**
		 * The property key to get the pressed background color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_PRESSED;

		/**
		 * The property key to get the highlighted background color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_HIGHLIGHTED;

		/**
		 * The property key to get the disabled background color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_BG_DISABLED;

		/**
		 * The property key to get the normal text color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_NORMAL;

		/**
		 * The property key to get the pressed text color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_PRESSED;

		/**
		 * The property key to get the highlighted text color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_HIGHLIGHTED;

		/**
		 * The property key to get the disabled text color of the item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_TEXT_DISABLED;

		/**
		 * The property key to get the color of the description text of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_DESCRIPTION_TEXT_NORMAL;

		/**
		 * The property key to get the normal color of the annex of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_ANNEX_DETAIL_NORMAL;

		/**
		 * The property key to get the pressed color of the annex of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_ANNEX_DETAIL_PRESSED;

		/**
		 * The property key to get the highlighted color of the annex of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_ANNEX_DETAIL_HIGHLIGHTED;

		/**
		 * The property key to get the normal background color of the annex of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_ANNEX_DETAIL_BG_NORMAL;

		/**
		 * The property key to get the pressed background color of the annex of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_ANNEX_DETAIL_BG_PRESSED;

		/**
		 * The property key to get the highlighted background color of the annex of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int ITEM_ANNEX_DETAIL_BG_HIGHLIGHTED;

		/**
		 * The property key to get the background color of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_BG_NORMAL;

		/**
		 * The property key to get the normal text color of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_TEXT_NORMAL;

		/**
		 * The property key to get the pressed text color of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_TEXT_PRESSED;

		/**
		 * The property key to get the highlighted text color of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_TEXT_HIGHLIGHTED;

		/**
		 * The property key to get the normal color of the index bar of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_INDEX_BAR_NORMAL;

		/**
		 * The property key to get the pressed color of the index bar of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_INDEX_BAR_PRESSED;

		/**
		 * The property key to get the highlighted color of the index bar of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_INDEX_BAR_HIGHLIGHTED;

		/**
		 * The property key to get the normal color of the bar of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_BAR_NORMAL;

		/**
		 * The property key to get the pressed color of the bar of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_BAR_PRESSED;

		/**
		 * The property key to get the highlighted color of the bar of the group item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int GROUP_ITEM_BAR_HIGHLIGHTED;

		/**
		 * The property key to get the background color of the section item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int SECTION_ITEM_BG_NORMAL;

		/**
		 * The property key to get the background color of the context item of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int CONTEXT_ITEM_BG_NORMAL;

		/**
		 * The property key to get the empty text color of table view.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int EMPTY_TEXT_NORMAL;
	};

	struct _OSP_EXPORT_ TokenEdit
	{
		/**
		 * The property key to get the normal background color of token edit.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_NORMAL;

		/**
		 * The property key to get the selected background color of token edit.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int BG_SELECTED;

		/**
		 * The property key to get the normal text color of token edit.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_NORMAL;

		/**
		 * The property key to get the selected text color of token edit.
		 *
		* @since		2.1
		*/
		_OSP_EXPORT_ static const int TEXT_SELECTED;
	};
};
}} //Tizen::Ui
#endif // _FUI_UI_CONFIGURATION_TYPES_H_
