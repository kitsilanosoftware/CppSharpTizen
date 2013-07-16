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
 * @file	FUiCtrlListContextItem.h
 * @brief	This is the header file for the %ListContextItem class.
 *
 * This header file contains the declarations of the %ListContextItem class and its helper classes.
 */

#ifndef _FUI_CTRL_LIST_CONTEXT_ITEM_H_
#define _FUI_CTRL_LIST_CONTEXT_ITEM_H_

#include <FGrpBitmap.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _ListContextItemImpl;

/**
 * @class	ListContextItem
 * @brief    This class defines common behavior for %ListContextItem.
 *
 * @since	2.0
 *
 * The %ListContextItem class displays the context item for a ListView or GroupedListView.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */

class _OSP_EXPORT_ ListContextItem
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is
	 * called. @n For full construction, the ListContextItem::Construct() method must be
	 * called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	ListContextItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ListContextItem(void);

	/**
	 * Initializes this instance of %ListContextItem with the specified parameter.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Adds the text element to the context item.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] elementId         The ID of the element
	 * @param[in] text              The text to display
	 * @param[in] enable            Set to @c true, to enable this element @n
	 *                              else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result AddElement(int elementId, const Tizen::Base::String& text, bool enable = true);

	/**
	 * Adds the bitmap element to the context item.
	 *
	 * @since	2.0
	 * @return  An error code
	 * @param[in] elementId           The ID of the element
	 * @param[in] normalBitmap        The bitmap displayed when the item is in normal status
	 * @param[in] pressedBitmap       The bitmap displayed when the item is pressed
	 * @param[in] pHighlightedBitmap  The bitmap displayed when the item is highlighted
	 * @param[in] enable              Set to @c true, to enable this element, @n
	 *                                else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result AddElement(int elementId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap& pressedBitmap, const Tizen::Graphics::Bitmap* pHighlightedBitmap = null, bool enable = true);

	/**
	 * Adds the text and the bitmap element to the context item.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] elementId           The ID of the element
	 * @param[in] text				  The text to display
	 * @param[in] normalBitmap        The bitmap displayed when the item is in normal status
	 * @param[in] pressedBitmap       The bitmap displayed when the item is pressed
	 * @param[in] pHighlightedBitmap  The bitmap displayed when the item is highlighted
	 * @param[in] enable              Set to @c true, to enable this element, @n
	 *                                else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result AddElement(int elementId, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap& pressedBitmap, const Tizen::Graphics::Bitmap* pHighlightedBitmap = null, bool enable = true);

	/**
	 * Sets the background image of a context item.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] pBitmap           The background bitmap image
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks
	 *			- The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only
	 *			the bitmap is displayed. @n
 	 *			- When @c pBitmap is set as @c null, the background color of the context item is drawn.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the background color of a context item.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] color             The background color
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks  The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only
	 *			the bitmap is displayed.
	 */
	result SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of a context item.
	 *
	 * @since   2.0
	 *
	 * @return  The background color of a context item
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the background color of the context item element.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[in] elementId			The ID of the element
	 * @param[in] status			The status of the context item element
	 * @param[in] color				The background color of the context item element
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_INVALID_ARG			The specified @c elementId is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks	If the specified @c backgroundColor is not set, the default color set by configuration is used.
	 * @see		GetElementBackgroundColor()
	 */
	result SetElementBackgroundColor(int elementId, ListContextItemElementStatus status, const Tizen::Graphics::Color& backgroundColor);

	/**
	 * Gets the background color of the context item element.
	 *
	 * @since   2.1
	 *
	 * @return	The background color of the element
	 * @param[in] elementId			The ID of the element
	 * @param[in] status			The status of the context item element
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_INVALID_ARG			The specified @c elementId is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @see		SetElementBackgroundColor()
	 */
	Tizen::Graphics::Color GetElementBackgroundColor(int elementId, ListContextItemElementStatus status) const;

	/**
	 * Sets the text color of the context item element.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[in] elementId			The ID of the element
	 * @param[in] status			The status of the context item element
	 * @param[in] color				The text color of the context item element
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_INVALID_ARG			The specified @c elementId is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks	If the element text color is not set by the application, the default color is set by theme.
	 * @see		GetElementTextColor()
	 */
	result SetElementTextColor(int elementId, ListContextItemElementStatus status, const Tizen::Graphics::Color& textColor);

	/**
	 * Gets the text color of the context item element.
	 *
	 * @since   2.1
	 *
	 * @return	The text color of the element
	 * @param[in] elementId			The ID of the element
	 * @param[in] status			The status of the context item element
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_INVALID_ARG			The specified @c elementId is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @see		SetElementTextColor()
	 */
	Tizen::Graphics::Color GetElementTextColor(int elementId, ListContextItemElementStatus status) const;

protected:
	friend class _ListContextItemImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ListContextItem(const ListContextItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ListContextItem& operator =(const ListContextItem& rhs);

private:
	_ListContextItemImpl* __pImpl;
}; // ListContextItem

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_LIST_CONTEXT_ITEM_H_
