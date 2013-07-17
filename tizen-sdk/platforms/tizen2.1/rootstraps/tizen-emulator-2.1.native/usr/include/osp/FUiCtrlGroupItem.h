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
 * @file	FUiCtrlGroupItem.h
 * @brief	This is the header file for the %GroupItem class.
 *
 * This header file contains the declarations of the %GroupItem class and its helper classes.
 */

#ifndef _FUI_CTRL_GROUP_ITEM_H_
#define _FUI_CTRL_GROUP_ITEM_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpBitmap.h>
#include <FGrpFloatRectangle.h>
#include <FGrpRectangle.h>
#include <FUiCtrlListItemBase.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _GroupItemImpl;

/**
 * @class	GroupItem
 * @brief    This class defines common behavior of %GroupItem.
 *
 * @since	2.0
 *
 * The %GroupItem class displays a group item. The basic layout of the %GroupItem instance is text and a bitmap arranged horizontally in one line.
 * The bitmap can be omitted while text must be given.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */

class _OSP_EXPORT_ GroupItem
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is
	 * called. @n For full construction, the %Construct() method must be
	 * called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	GroupItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~GroupItem(void);

	/**
	 * Initializes this instance of %GroupItem with the specified parameter.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	itemSize            The size of the item
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Dimension& itemSize);

	/**
	 * Initializes this instance of %GroupItem with the specified parameter.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	itemSize            The size of the item
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::FloatDimension& itemSize);

	/**
	 * Sets the background image of the item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pBitmap           The background bitmap image
	 * @exception	E_SUCCESS         The method is successful.
	 * @exception	E_SYSTEM          A system error has occurred.
	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and background color are
	 *			specified, only the bitmap is displayed.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the background color of the item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	color				The background color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- The background bitmap has priority over the background color. When both the background bitmap and the
	 *			background color are specified, only the bitmap is displayed.
	 *			- The background color of the item is not applied when the item is inserted into the GroupedListView of section style.
	 */
	result SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of the item.
	 *
	 * @since	2.0
	 *
	 * @return	The background color of the item, @n
	 *			else RGBA(0, 0, 0, 0) if an error occurs
	 * @see     SetBackgroundColor()
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the color of the text.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in]   color               The text color
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see			GetTextColor()
	 */
	result SetTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the text.
	 *
	 * @since	2.0
	 *
	 * @return	The text color, @n
	 *			else RGBA(0, 0, 0, 0) if an error occurs
	 * @see		SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(void) const;

	/**
	 * Sets the size of the text.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	size                The size of the text
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see     GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	 * Sets the size of a text.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	size                The size of the text to set
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see     GetTextSize()
	 */
	result SetTextSize(float size);

	/**
	 * Gets the size of the text.
	 *
	 * @since	2.0
	 *
	 * @return  The size of the text,
	 *			else @c -1 if an error occurs
	 *
	 * @see     SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the size of a text.
	 *
	 * @since	2.1
	 *
	 * @return  The size of a text,
	 *			else @c -1.0f if an error occurs
	 *
	 * @see     SetTextSize()
	 */
	float GetTextSizeF(void) const;

	/**
	 * Sets the text and bitmap of the element for %GroupItem.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	text				The text string to add
	 * @param[in]	pBitmap             The bitmap to display
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- The behavior of %GroupItem is different according to the style of GroupedListView.
	 *			- When the style is ::GROUPED_LIST_VIEW_INDEXED, the text and bitmap of %GroupItem are displayed,
	 *			if they are given. However, when the style is ::GROUPED_LIST_VIEW_STYLE_SECTION, the bitmap is not displayed in any
	 *			case and setting an empty text to %GroupItem does not show %GroupItem.
	 */
	result SetElement(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBitmap = null);

protected:
	friend class _GroupItemImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	GroupItem(const GroupItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	GroupItem& operator =(const GroupItem& rhs);

protected:
	_GroupItemImpl* _pImpl;
}; // GroupItem

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_GROUP_ITEM_H_
