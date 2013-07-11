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
 * @file	FUiCtrlListTypes.h
 * @brief	This is the header file for the List enumerations.
 *
 * This header file contains the declarations of the List enumerations.
 */
#ifndef _FUI_CTRL_LIST_TYPES_H_
#define _FUI_CTRL_LIST_TYPES_H_

namespace Tizen { namespace Ui { namespace Controls
{

//
//This integer is for internal use only. Using this integer can cause behavioral, security-related,
//and consistency-related issues in the application.
//
static const int LIST_ITEM_NOTFOUND = 0;

/**
 * The integer value that represents the unspecified item ID
 *
 * @since 2.0
 */
static const int LIST_ITEM_UNSPECIFIED_ID = -1;

/**
 * @if OSPDEPREC
 * @enum ListStyle
 *
 * Defines the list style.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated  This enumeration is deprecated. Instead of using this enumeration, use ListAnnexStyle enumeration for CustomItem or SimpleItem class. @n
 * @since 2.0
 * @endif
 */
enum ListStyle
{
	LIST_STYLE_NORMAL = 0,                          /**< @if OSPDEPREC The normal style @endif */
	LIST_STYLE_NUMBER,                              /**< @if OSPDEPREC The numbered style @endif */
	LIST_STYLE_RADIO,                               /**< @if OSPDEPREC The radio style for single selection @endif */
	LIST_STYLE_RADIO_WITH_DIVIDER,                  /**< @if OSPDEPREC The radio style with divider for single selection @endif */
	LIST_STYLE_MARK,                                /**< @if OSPDEPREC The mark style for multiple selection @endif */
	LIST_STYLE_MARK_WITH_DIVIDER,                   /**< @if OSPDEPREC The mark style with divider for multiple selection @endif */
	LIST_STYLE_ONOFF,                               /**< @if OSPDEPREC The On/Off style @endif */
	LIST_STYLE_ONOFF_WITH_DIVIDER                   /**< @if OSPDEPREC The On/Off style with divider @endif */
};

/**
 * @if OSPDEPREC
 * @enum ListItemFormat
 *
 * Defines the list item format.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enumeration is deprecated. There is no need to use this enumeration. @n
 * @since 2.0
 * @endif
 */
enum ListItemFormat
{
	LIST_ITEM_SINGLE_IMAGE = 0,                     /**< @if OSPDEPREC The single line of image @endif */
	LIST_ITEM_SINGLE_TEXT,                          /**< @if OSPDEPREC The single line of text @endif */
	LIST_ITEM_SINGLE_IMAGE_TEXT,                    /**< @if OSPDEPREC The single line of image, and text @endif */
	LIST_ITEM_SINGLE_TEXT_IMAGE,                    /**< @if OSPDEPREC The single line of text, and image @endif */
	LIST_ITEM_SINGLE_IMAGE_TEXT_IMAGE,              /**< @if OSPDEPREC The single line of image, text, and image @endif */
	LIST_ITEM_DOUBLE_IMAGE_TEXT_FULLTEXT,           /**< @if OSPDEPREC The 1st line of image and text, 2nd line of text @endif */
	LIST_ITEM_DOUBLE_FULLTEXT_IMAGE_TEXT,           /**< @if OSPDEPREC The 1st line of text, 2nd line of image, and text @endif */
	LIST_ITEM_DOUBLE_TEXT_IMAGE_FULLTEXT,           /**< @if OSPDEPREC The 1st line of text and image, 2nd line of text @endif */
	LIST_ITEM_DOUBLE_FULLTEXT_TEXT_IMAGE,           /**< @if OSPDEPREC The 1st line of text, 2nd line of text, and image @endif */
	LIST_ITEM_DOUBLE_IMAGE_TEXT_TEXT,               /**< @if OSPDEPREC A big image followed by two lines of text @endif */
	LIST_ITEM_DOUBLE_TEXT_TEXT_IMAGE                /**< @if OSPDEPREC The two lines of text followed by a big image @endif */
};

/**
 * @if OSPDEPREC
 * @enum ListItemText
 *
 * Defines the option of text slide.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enumeration is deprecated. There is no need to use this enumeration. @n
 * @since 2.0
 * @endif
 */
enum ListItemText
{
	LIST_ITEM_TEXT1,                                /**< @if OSPDEPREC The sliding of 1st text is switched on @endif */
	LIST_ITEM_TEXT2                                 /**< @if OSPDEPREC The sliding of 2nd text is switched on @endif */
};

/**
 * @if OSPDEPREC
 * @enum FastScrollIndexDigit
 *
 * Defines the number of digits or characters of the fast scroll index.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enumeration is deprecated. There is no need to use this enumeration. @n
 * @since 2.0
 * @endif
 */
enum FastScrollIndexDigit
{
	SCROLL_INDEX_DIGIT_NUM_1,                       /**< @if OSPDEPREC The number of digits or characters of the index is 1 @endif */
	SCROLL_INDEX_DIGIT_NUM_2                        /**< @if OSPDEPREC The number of digits or characters of the index is 2 @endif */
};

}}} // Tizen::Ui::Controls

#endif //_FUI_CTRL_LIST_TYPES_H_
