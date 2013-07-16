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
 * @file	FUiCtrlICustomListElement.h
 * @brief	This is the header file for the %ICustomListElement interface.
 *
 * This header files contains the declarations of %ICustomListElement interface.
 *
 */

#ifndef _FUI_CTRL_ICUSTOM_LIST_ELEMENT_H_
#define _FUI_CTRL_ICUSTOM_LIST_ELEMENT_H_

//includes
#include <FGrpCanvas.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @enum	CustomListItemStatus
 *
 * Defines the value of status of the CustomList item.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enum is deprecated. Instead of using this enum, use the ListItemStatus enumeration.
 * @since   2.0
 * @endif
 */
enum CustomListItemStatus
{
	CUSTOM_LIST_ITEM_STATUS_NORMAL = 0,     /**< @if OSPDEPREC The status of the item is normal @endif */
	CUSTOM_LIST_ITEM_STATUS_SELECTED,       /**< @if OSPDEPREC The status of the item is selected @endif */
	CUSTOM_LIST_ITEM_STATUS_FOCUSED         /**< @if OSPDEPREC The status of the item is focused @endif */
};

/**
 * @if OSPDEPREC
 * @interface	ICustomListElement
 * @brief       <i> [Deprecated] </i> This interface represents the common behaviors for a CustomList element.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use the ICustomElement class.
 * @since		2.0
 *
 *
 * The %ICustomListElement interface provides interfaces used for custom drawing
 * in a custom list item.
 *
 * If an application wants to draw its own contents in a custom list item, it must
 * implement %ICustomListElement and add elements by calling SetElement(int elementId,
 * const %ICustomListElement &element). When the custom list item needs to be redrawn,
 * DrawElement() is called by the framework.
 * @endif
 */
class _OSP_EXPORT_ ICustomListElement
	: public Tizen::Base::Object
{
public:
	/**
	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ICustomElement class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~ICustomListElement(void) {}

// Operation
public:
	/**
	 * @if OSPDEPREC
	 * Draws a custom element of the item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ICustomElement class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	canvas		The graphic canvas of the list control
	 * @param[in] rect        The location and size of the CustomList element
	 * @param[in]	itemStatus	The status of the item
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @endif
	 */
	virtual result DrawElement(const Tizen::Graphics::Canvas& canvas, const Tizen::Graphics::Rectangle& rect, CustomListItemStatus itemStatus) = 0;
}; //ICustomListElement
}}} //Tizen::Ui::Controls
#endif // _FUI_CTRL_ICUSTOM_LIST_ELEMENT_H_
