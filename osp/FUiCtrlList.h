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
 * @file	FUiCtrlList.h
 * @brief	This is the header file for the %List class.
 *
 * This header file contains the declarations of the %List class and its helper classes.
 */

#ifndef _FUI_CTRL_LIST_H_
#define _FUI_CTRL_LIST_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlListTypes.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiIItemEventListener.h>


namespace Tizen { namespace Base { namespace Runtime
{
class IEvent;
}}} // Tizen::Base::Runtime

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @class	List
 * @brief		<i> [Deprecated] </i> This class defines the common behavior of the %List control.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
 * @since		2.0
 *
 * The %List class defines the common behavior of the %List control.
 * A list displays the user selection in the form of a list of items. When an item
 * on the list is selected or deselected, an item event occurs. It is passed on to
 * any item event listeners that have registered an interest in item events generated
 * by this list.
 *
 * If an application wants to perform something based on a list being selected and
 * deselected, it must realize IItemEventListener and register the listener to
 * receive events from this list, by calling the list's AddItemEventListener() method.
 *
 * There are several styles supported with differences in the number of columns, rows and
 * types of data that can be set. The Construct has a parameter for the size of
 * all 4 aspects of a list item. If the item has less than 2 rows or 2 columns, you
 * only need to specify the width and height information relevant to the style selected.
 * Also, the check style causes some space to be taken up on the right side of the list
 * item. The framework will try to make room for the check from the right-most column,
 * so the actual width of each column may be different from what you have set.
 *
 * @image html ui_controls_list_construct.png
 *
 * If the application directly allocates resources, the resources must be deleted
 * (for example, text or bitmap).
 *
 * Example:
 *
 * @image html ui_controls_list.png
 *
 *
 * This is a simple UI application which uses a list control.
 *
 *
 * @code
//Sample code for ListSample.h
#include <FUi.h>

class ListSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IItemEventListener
{
public:
	ListSample(void)
	: __pList(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual void OnItemStateChanged(const Tizen::Ui::Control &source, int index, int itemId, Tizen::Ui::ItemStatus status);

private:
	static const int ID_LIST_FIRSTITEM = 101;
	static const int ID_LIST_SECONDITEM = 102;

	Tizen::Ui::Controls::List* __pList;
};
 *	@endcode
 *
 *	@code
//Sample code for ListSample.cpp
#include <FGraphics.h>

#include "ListSample.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
ListSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ListSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of List
	__pList = new List();
	__pList->Construct(Rectangle(0, 0, GetClientAreaBounds().width, 500),
			LIST_STYLE_NORMAL, LIST_ITEM_SINGLE_TEXT, 100, 0, GetClientAreaBounds().width, 0);
	__pList->AddItemEventListener(*this);

	// Sets Strings
	String itemText1(L"List Item 1");
	String itemText2(L"List Item 2");

	// Adds the items to the list
	__pList->AddItem(&itemText1, null, null, null, ID_LIST_FIRSTITEM);
	__pList->AddItem(&itemText2, null, null, null, ID_LIST_SECONDITEM);

	// Adds the list to the form
	AddControl(*__pList);

	return r;
}

// IItemEventListener implementation
void
ListSample::OnItemStateChanged (const Tizen::Ui::Control &source, int index, int itemId, Tizen::Ui::ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_FIRSTITEM:
		{
			// ....
		}
		break;
	case ID_LIST_SECONDITEM:
		{
			// ....
		}
		break;
	default:
		break;
	}
}
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ List
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 * @endif
	 */
	List(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~List(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %List with the specified parameters.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	rect	            An instance of the Graphics::Rectangle class @n
	 *						            This instance represents the x and y coordinates of the top-left corner of the created list along with
	 *						            the width and height of the list.
	 * @param[in]	style			    The style set of the list
	 * @param[in]	itemFormat		    The layout of the list items
	 * @param[in]	row1Height		    The height of the first row
	 * @param[in]	row2Height		    The height of the second row
	 * @param[in]	column1Width		The width of the first column
	 * @param[in]	column2Width		The width of the second column
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remarks	A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier. @n
	 *		If the given size is less than the minimum size, %List is constructed with the minimum size. @n
	 *		When, %List is constructed with LIST_STYLE_NUMBER style, the maximum number of items supported is @c 99.
	 * @remarks	The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks     The minimum size of this control is 92 x 72 on a WVGA screen, 60 x 48 on a HVGA screen and 46 x 36 on a WQVGA screen.
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, ListStyle style, ListItemFormat itemFormat, int row1Height, int row2Height, int column1Width, int column2Width);

	/**
	 * @if OSPDEPREC
	 * Adds the specified listener instance. @n
	 * The added listener can listen to the item events when they are fired. Only an item event with the ITEM_SELECTED state is fired.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @endif
	 */
	void AddItemEventListener(Tizen::Ui::IItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @endif
	 */
	void RemoveItemEventListener(Tizen::Ui::IItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Adds the item to the current %List instance.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	pText1		    A pointer to the first string
	 * @param[in]	pText2		    A pointer to the second string
	 * @param[in]	pBitmap1	    A pointer to the first normal bitmap
	 * @param[in]	pBitmap2	    A pointer to the second normal bitmap
	 * @param[in]	itemId		    The itemId for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The contents of the specified texts and bitmaps are copied and kept by the list.
	 *			If the size of the text exceeds the displayable area, the text will slide automatically when the list item is selected.
	 * @endif
	 */
	result AddItem(const Tizen::Base::String* pText1, const Tizen::Base::String* pText2, const Tizen::Graphics::Bitmap* pBitmap1, const Tizen::Graphics::Bitmap* pBitmap2, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Inserts the specified item to list, at the specified index.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]   index			The index at which the item is to be inserted
	 * @param[in]	pText1		    A pointer to the first string
	 * @param[in]	pText2		    A pointer to the second string
	 * @param[in]	pBitmap1	    A pointer to the first normal bitmap
	 * @param[in]	pBitmap2	    A pointer to the second normal bitmap
	 * @param[in]	itemId		    The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The contents of the specified texts and bitmaps are copied and kept by the list.
	 *			If the size of the text exceeds the displayable area, the text will slide automatically when a list item is selected.
	 * @endif
	 */
	result InsertItemAt(int index, const Tizen::Base::String* pText1, const Tizen::Base::String* pText2, const Tizen::Graphics::Bitmap* pBitmap1, const Tizen::Graphics::Bitmap* pBitmap2, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Sets the contents of the specified item to list at the specified index.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]   index		        The index at which the contents of the item is to be set
	 * @param[in]	pText1		        A pointer to the first string
	 * @param[in]	pText2		        A pointer to the second string
	 * @param[in]	pBitmap1	        A pointer to the first normal bitmap
	 * @param[in]	pBitmap2	        A pointer to the second normal bitmap
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than or equal to the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The contents of the specified texts and bitmaps are copied and kept in the list.
	 *			If the size of the text exceeds the displayable area, the text will slide automatically when a list item is selected.
	 * @endif
	 */
	result SetItemAt(int index, const Tizen::Base::String* pText1, const Tizen::Base::String* pText2, const Tizen::Graphics::Bitmap* pBitmap1, const Tizen::Graphics::Bitmap* pBitmap2, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Removes the item at the specified index of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]   index			The index at which the item is to be deleted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than or equal to the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RemoveItemAt(int index);

	/**
	 * @if OSPDEPREC
	 * Removes all the items of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Gets the item count of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The number of items in the list
	 * @endif
	 */
	int GetItemCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the enabled status of the specified item of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index		The index of the list item for which status is to be set
	 * @param[in]	enable	    Set to @c true to enable the item, @n
	 *							else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @endif
	 */
	result SetItemEnabled(int index, bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified item is enabled.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]	index		The index of the list item
	 * @endif
	 */
	bool IsItemEnabled(int index) const;

	/**
	 * @if OSPDEPREC
	 * Sets the background bitmap image of the focused item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	bitmap		The background bitmap of the focused item
	 * @endif
	 */
	void SetFocusedItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the highlighted background image on the rectangle of each list item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since               2.0
	 *
	 * @param[in]     bitmap            The background image
	 * @remarks		When a user navigates a user interface with directional keys, the selected UI control is highlighted and takes the focus.
	 * @endif
	 */
	void SetHighlightedItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the background image on the rectangle of each list item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	bitmap		The background image
	 * @endif
	 */
	void SetNormalItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the top-drawn item of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the top-drawn item
	 * @endif
	 */
	int GetTopDrawnItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the bottom-drawn item of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the bottom-drawn item
	 * @endif
	 */
	int GetBottomDrawnItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the text to be displayed when the list is empty.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	text	The text message to be displayed
	 * @endif
	 */
	void SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * @if OSPDEPREC
	 * Sets the color of the text that is displayed when the list is empty.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @param[in]       color	The color of the text for an empty List
	 * @endif
	 */
	void SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Gets the color of the empty text that is displayed when the list is empty.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The empty text color, @n
	 *				else RGBA(0, 0, 0, 0) if the instance is invalid
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the background color of this control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since                 2.0
	 *
	 * @param[in]     color    The background color
	 * @endif
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the item text color.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @param[in]   textIndex The index of the text
	 * @param[in]   textColor The color of the text
	 * @endif
	 */
	void SetItemTextColor(ListItemText textIndex, const Tizen::Graphics::Color& textColor);

	/**
	 * @if OSPDEPREC
	 * Gets the text color of item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return      The item text color
	 * @param[in]   textIndex The index of the text, @n
	 *				else RGBA(0, 0, 0, 0) if the instance is invalid
	 * @endif
	 */
	Tizen::Graphics::Color GetItemTextColor(ListItemText textIndex) const;

	/**
	 * @if OSPDEPREC
	 * Enables the text slide.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in] textIndex	 The text index of the list item format to slide
	 * @remarks		If text slide is enabled, the texts which are too long to fit in the given list item slide show the remnant contents when a user touches
	 *				the item for a long time.
	 * @endif
	 */
	void EnableTextSlide(ListItemText textIndex);

	/**
	 * @if OSPDEPREC
	 * Disables the text sliding.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 * @endif
	 */
	void DisableTextSlide(void);

	/**
	 * @if OSPDEPREC
	 * Gets the height of the list item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The height of the item
	 * @endif
	 */
	int GetItemHeight(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the row1 height of the current list
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The row1 height of the item
	 * @endif
	 */
	int GetRow1Height(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the row2 height of the current list
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The row2 height of the item
	 * @endif
	 */
	int GetRow2Height(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the column1 width of the current list
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The column1 width of the item
	 * @endif
	 */
	int GetColumn1Width(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the column2 width of the current list
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The column2 width of the item
	 * @endif
	 */
	int GetColumn2Width(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the row1 height of the current List
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]   row1Height		The row1 height of the list item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		In logical pixels, the minimum height of the rows is 48.
	 * @endif
	 */
	result SetRow1Height(int row1Height);

	/**
	 * @if OSPDEPREC
	 * Sets the row2 height of the current list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	row2Height      The row2 height of the list item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		In logical pixels, the minimum height of the rows is 48.
	 * @endif
	 */
	result SetRow2Height(int row2Height);

	/**
	 * @if OSPDEPREC
	 * Sets the column1 width of the current %List
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]   column1Width		The column1 width of the list item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result SetColumn1Width(int column1Width);

	/**
	 * @if OSPDEPREC
	 * Sets the column2 width of the current %List
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]   column2Width	The column2 width of the list item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetColumn2Width(int column2Width);

	/**
	 * @if OSPDEPREC
	 * Sets the check status of the specified item of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return			An error code
	 * @param[in]   index       The index of the list
	 * @param[in]   check       The check status
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred.
	 *
	 * @remarks     This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified item of the list is checked.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		@c true if the item is checked, @n
	 *				else @c false
	 * @param[in]	index		The index of the list item
	 *
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	bool IsItemChecked(int index) const;

	/**
	 * @if OSPDEPREC
	 * Sets the checked status of all the items of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	check			Set to @c true to check all the items, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result SetAllItemsChecked(bool check);

	/**
	 * @if OSPDEPREC
	 * Removes all the checked items of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since						2.0
	 *
	 * @return      An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result RemoveAllCheckedItems(void);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the first checked item from the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the first checked item
	 * @remarks         This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	int GetFirstCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the last checked item from the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the last checked item
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	int GetLastCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the next checked item after the specified index from the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the next checked item
	 * @param[in]	index		The index of the item
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	int GetNextCheckedItemIndexAfter(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item with the specified item ID.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the item
	 * @param[in]	itemId		The item ID of the list
	 * @remarks		The method returns -1 when there is no list item with the specified item ID.
	 * @endif
	 */
	int GetItemIndexFromItemId(int itemId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]   x   The x position of the point
	 * @param[in]   y   The y position of the point
	 * @endif
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]   position    The position of the point
	 * @endif
	 */
	int GetItemIndexFromPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item ID of the item at the specified index.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 *
	 * @return      The ID of the item, @n
	 *				else @c -1 if there is no list item at the specified index
	 * @param[in]   index		The index of the list item
	 * @endif
	 */
	int GetItemIdAt(int index) const;

	/**
	 * @if OSPDEPREC
	 * Scrolls to the bottom of the List.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 * @endif
	 */
	void ScrollToBottom(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the top of the List.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since		2.0
	 * @endif
	 */
	void ScrollToTop(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the list item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @endif
	 */
	result ScrollToTop(int index);

	/**
	 * @if OSPDEPREC
	 * Draws and shows the item of the list.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the list item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @endif
	 */
	result RefreshItem(int index);


private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	List(const List& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	List& operator =(const List& rhs);

	friend class _ListImpl;
}; //List

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_LIST_H_
