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
 * @file	FUiCtrlIconList.h
 * @brief	This is the header file for the %IconList class.
 *
 * This header file contains the declarations of the %IconList class and its helper classes.
 */

#ifndef _FUI_CTRL_ICON_LIST_H_
#define _FUI_CTRL_ICON_LIST_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiContainer.h>
#include <FUiCtrlIconListTypes.h>
#include <FUiCtrlListTypes.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiIItemEventListener.h>

// forward declarations
namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @class	IconList
 * @brief  <i> [Deprecated] </i>  This class defines the common behavior of an %IconList control.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
 * @since		2.0
 *
 * @remarks	%IconList can display a maximum of 64 items on the screen at once (for example, 8 x 8 grid).
 * %IconList is not drawn properly when it is resized.
 *
 * The %IconList class can be used to display a list of bitmap images and icons. When
 * a list item (or icon) is pressed by the user, an item event is generated and the
 * item event listeners are called to notify the change in the
 * item's state (ITEM_CHECKED, ITEM_UNCHECKED and ITEM_SELECTED).
 *
 * When %IconList's style is set as ICON_LIST_STYLE_RADIO, only one item
 * can be "selected" at a time. Whereas, if ICON_LIST_STYLE_MARK is set as
 * the %IconList's style, multiple items can be "checked" at the same time.
 * However, no item can be selected or checked when %IconList's style is set as
 * ICON_LIST_STYLE_NORMAL.
 *
 * When a list item is selected by the user, the "focused" bitmap image is displayed
 * instead of item's "normal" bitmap image.
 *
 * Please note that any image resources (bitmaps) that are allocated by application
 * must be freed after they are passed to Additem()/InsertItem()/SetItem() to
 * minimize memory usage. @n
 *
 * Example:
 *
 * @image html ui_controls_iconlist.png
 *
 *@n
 * This is a simple UI application which uses a icon list control.
 *
 *
 * @code
//Sample code for IconListSample.h
#include <FUi.h>

class IconListSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IItemEventListener
{
public:
	IconListSample(void)
	: __pIconList(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IItemEventListener
	virtual void OnItemStateChanged(const Tizen::Ui::Control &source, int index, int itemId, Tizen::Ui::ItemStatus status);

private:
	static const int ID_LIST_FIRSTITEM = 101;
	static const int ID_LIST_SECONDITEM = 102;

	Tizen::Ui::Controls::IconList *__pIconList;
};
 *	@endcode
 *
 *	@code
//Sample code for IconListSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "IconListSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

bool
IconListSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
IconListSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of IconList
	__pIconList = new IconList();
	__pIconList->Construct(Rectangle(0, 100, GetClientAreaBounds().width, GetClientAreaBounds().height), ICON_LIST_STYLE_NORMAL, 96, 96);
	__pIconList->AddItemEventListener(*this);

	// Creates instances of String
	String itemText1(L"Item1");
	String itemText2(L"Item2");

	// Gets instances of Bitmap
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap *pBitmapNormal1  = pAppResource->GetBitmapN(L"call.png");
	Bitmap *pBitmapFocused1 = pAppResource->GetBitmapN(L"call_focused.png");
	Bitmap *pBitmapNormal2  = pAppResource->GetBitmapN(L"home.png");
	Bitmap *pBitmapFocused2 = pAppResource->GetBitmapN(L"home_focused.png");

	// Adds the items to the icon list
	__pIconList->AddItem(&itemText1, pBitmapNormal1, pBitmapFocused1, ID_LIST_FIRSTITEM);
	__pIconList->AddItem(&itemText2, pBitmapNormal2, pBitmapFocused2, ID_LIST_SECONDITEM);

	// Adds the icon list to the form
	AddControl(__pIconList);

	// Deallocates bitmaps
	delete pBitmapNormal1;
	delete pBitmapFocused1;
	delete pBitmapNormal2;
	delete pBitmapFocused2;

	return r;
}

// IItemEventListener implementation
void
IconListSample::OnItemStateChanged (const Control &source, int index, int itemId, ItemStatus status)
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
class _OSP_EXPORT_ IconList
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. @n
	* For full construction, the IconList::Construct() method must be called right after calling this constructor.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
 	 * @since	2.0
	 * @endif
	 */
	IconList(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since	2.0
	 * @endif
	 */
	virtual ~IconList(void);

public:
	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %IconList with the specified parameters.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	rect	        An instance of the Graphics::Rectangle class @n
	 *						        This instance represents the X and Y coordinates of the top-left corner of the created %IconList along with
	 *						        the width and height. @n
	 * @param[in]	style			The style set of %IconList
	 * @param[in]   itemWidth		The width of the items in the %IconList
	 * @param[in]	itemHeight		The height of the items in the %IconList
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *				- A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *				- The %IconList cannot display more than 64 items on screen at once.
	 *				- The size of the control must be within the range defined by the minimum and maximum size.
	 * 				- The minimum size of this control is 0 x 0.
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, IconListStyle style, int itemWidth, int itemHeight);


// Operation
	/**
	 * @if OSPDEPREC
	 * Adds a listener instance. @n
	 * The added listener can listen to item events when they are fired. Only an item event with the ITEM_SELECTED state is fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to add
	 * @endif
	 */
	void AddItemEventListener(Tizen::Ui::IItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener    The listener to remove
	 * @endif
	 */
	void RemoveItemEventListener(Tizen::Ui::IItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Sets the background bitmap of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	bitmap		The background bitmap
	 * @endif
	 */
	void SetBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the top and left margins of the items for %IconList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	topMargin			The top margin of the background bitmap
	 * @param[in]	leftMargin			The left margin of the background bitmap
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The %IconList cannot display more than 64 items on screen at once.
	 * @endif
	 */
	result SetMargin(int topMargin, int leftMargin);


	/**
	 * @if OSPDEPREC
	 * Gets the top margin of the items for the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The top margin of the background bitmap
	 * @endif
	 */
	int GetTopMargin(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the left margin of the items for the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The left margin of the background bitmap
	 * @endif
	 */
	int GetLeftMargin(void) const;

	/**
	 * @if OSPDEPREC
	 * Adds a list item with the specified text and bitmap images to the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   pText			The item text
	 * @param[in]   pNormalBitmap   The default bitmap image
	 * @param[in]   pFocusedBitmap  The displayed bitmap image when an item is selected
	 * @param[in]	itemId		    The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *				- The contents of the specified texts and bitmaps are copied and kept by %List.
	 *				- To display text in multi-lines or to denote the end of line, use '\\n'.
	 * @endif
	 */
	result AddItem(const Tizen::Base::String* pText, const Tizen::Graphics::Bitmap* pNormalBitmap, const Tizen::Graphics::Bitmap* pFocusedBitmap, int itemId = LIST_ITEM_UNSPECIFIED_ID);


	/**
	 * @if OSPDEPREC
	 * Inserts the specified text and bitmap item in the specified index of the specified %IconList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The item text
	 * @param[in]	pText			The text item to add
	 * @param[in]	pNormalBitmap	The default bitmap image
	 * @param[in]	pFocusedBitmap	The displayed bitmap image when an item is selected
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *				- The contents of the specified texts and bitmaps are copied and kept by %IconList.
	 *				- To display text in multi-lines or to denote the end of line, use '\\n'.
	 * @endif
	 */
	result InsertItemAt(int index, const Tizen::Base::String* pText, const Tizen::Graphics::Bitmap* pNormalBitmap, const Tizen::Graphics::Bitmap* pFocusedBitmap, int itemId = LIST_ITEM_UNSPECIFIED_ID);


	/**
	 * @if OSPDEPREC
	 * Sets the specified text and bitmap item in the specified index of the specified %IconList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the List item
	 * @param[in]	pText			The item text
	 * @param[in]	pNormalBitmap	The default bitmap image
	 * @param[in]	pFocusedBitmap	The displayed bitmap image when an item is selected
	 * @param[in]	itemId		    The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *				- The contents of the specified texts and bitmaps are copied and kept by %IconList.
	 *			    Call RefreshItem() to update item images.
	 *				- To display text in multi-lines or to denote the end of line, use '\\n'.
	 * @endif
	 */
	result SetItemAt(int index, const Tizen::Base::String* pText, const Tizen::Graphics::Bitmap* pNormalBitmap, const Tizen::Graphics::Bitmap* pFocusedBitmap, int itemId = LIST_ITEM_UNSPECIFIED_ID);


	/**
	 * @if OSPDEPREC
	 * Removes the item at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the %IconList item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RemoveItemAt(int index);

	/**
	 * @if OSPDEPREC
	 * Removes all items of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Gets the column count of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The count of all the items of the %IconList control
	 * @endif
	 */
	int GetColumnCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item count of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The count of all the items of the %IconList control
	 * @endif
	 */
	int GetItemCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the checked status of the specified item of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the %IconList item
	 * @param[in]	check			Set to @c true to check the specified item, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks	This method can only be used when the style of the list allows selection (ICON_LIST_STYLE_MARK).
	 * @remarks	The method only changes the state of the list item. %IconList needs to be redrawn to reflect the change on the screen.
	 * @endif
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified item of the %IconList control is checked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		@c true if the specified item is checked, @n
	 *				else @c false
	 * @param[in]	index	The index of the list item
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	bool IsItemChecked(int index) const;

	/**
	 * @if OSPDEPREC
	 * Sets the checked status of all the items of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	check			Set to @c true to check all the items, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections (ICON_LIST_STYLE_MARK).
	 * @remarks		The method only changes the states of the list items. %IconList needs to be redrawn to reflect the changes on the screen.
	 * @endif
	 */
	result SetAllItemsChecked(bool check);

	/**
	 * @if OSPDEPREC
	 * Removes all checked items of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result RemoveAllCheckedItems(void);

	/**
	 * @if OSPDEPREC
	 * Gets the first checked items of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The index of the %IconList item
	 * @endif
	 */
	int GetFirstCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the last checked items of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The index of the %IconList item
	 * @endif
	 */
	int GetLastCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the next checked items at the specified index of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The index of the list item
	 * @param[in]   index	The index of the %IconList item
	 * @endif
	 */
	int GetNextCheckedItemIndexAfter(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]   x       The x position of the point
	 * @param[in]   y       The y position of the point
	 * @endif
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]	position	The position of the point
	 * @endif
	 */
	int GetItemIndexFromPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * @if OSPDEPREC
	 * Sets a horizontal alignment of the text in the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	alignment	The horizontal alignment of the text
	 * @endif
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * @if OSPDEPREC
	 * Sets a vertical alignment of the text of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]   alignment	The vertical alignment of the icon and text
	 * @endif
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

	/**
	 * @if OSPDEPREC
	 * Gets the horizontal alignment of the text of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The horizontal alignment of the %IconList control
	 * @endif
	 */
	HorizontalAlignment GetTextHorizontalAlignment(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the vertical alignment of the text of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The vertical alignment of the %IconList control
	 * @endif
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the background color of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since        2.0
	 *
	 * @param[in]	color	The background color
	 * @endif
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the text to display when the %IconList control contains no item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	text	The text
	 * @endif
	 */
	void SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * @if OSPDEPREC
	 * Sets the color of the text that is displayed when the %IconList control contains no item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	color	The color of the text
	 * @endif
	 */
	void SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);


	/**
	 * @if OSPDEPREC
	 * Gets the color of the text that is displayed when the %IconList control contains no item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The color of the text, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;


	/**
	 * @if OSPDEPREC
	 * Sets the text color of the item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	textColor	The color of the text
	 * @endif
	 */
	void SetItemTextColor(const Tizen::Graphics::Color& textColor);

	/**
	 * @if OSPDEPREC
	 * Gets the text color of the item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The color of the text, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @endif
	 */
	Tizen::Graphics::Color GetItemTextColor(void) const;


	/**
	 * @if OSPDEPREC
	 * Sets the size of the text of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	size			The size of the text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If @c size is less than the minimum size, this method fails. The minimum font size is 6 on devices of high screen density.
	 * @endif
	 */
	void SetTextSize(int size);


	/**
	 * @if OSPDEPREC
	 * Gets the size of the text of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since	2.0
	 *
	 * @return  The size of the text of the current %IconList control
	 * @endif
	 */
	int GetTextSize(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item with the specified item ID.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item with the specified item ID
	 * @param[in]	itemId		The item ID of the list item
	 * @endif
	 */
	int GetItemIndexFromItemId(int itemId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item ID of the item at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The item ID of the item, @n
	 *				else @c -1 if there is no list item at the specified index
	 * @param[in]	index		The index of the list item
	 * @endif
	 */
	int GetItemIdAt(int index) const;

	/**
	 * @if OSPDEPREC
	 * Sets the position of the checkbox of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	position	The position of the checkbox of the current %IconList control
	 * @remarks		This method changes the position of the checkbox image displayed for the "selected" item(s), when the style of %IconList is either
	 *				ICON_LIST_STYLE_RADIO or ICON_LIST_STYLE_MARK.
	 * @endif
	 */
	void SetCheckBoxPosition(IconListCheckBoxPosition position);

	/**
	 * @if OSPDEPREC
	 * Gets the position of the checkbox of the current %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		The position of the checkbox of the current %IconList control
	 * @endif
	 */
	IconListCheckBoxPosition GetCheckBoxPosition(void) const;

	/**
	 * @if OSPDEPREC
	 * Enables or disables focus animation.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable focus animation, @n
	 *                      else @c false
	 * @remarks		If a separate Focused Bitmap is to be used, the animation effect must be disabled.
	 * @endif
	 */
	void SetFocusAnimationEnabled(bool enable);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the bottom of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since	2.0
	 * @endif
	 */
	void ScrollToBottom(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the top of the %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since	2.0
	 * @endif
	 */
	void ScrollToTop(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls the specified item to the top of %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	itemIndex		The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @endif
	 */
	result ScrollToTop(int itemIndex);

	/**
	 * @if OSPDEPREC
	 * Draws and shows the item of %IconList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the %IconList item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @endif
	 */
	result RefreshItem(int index);

public:
	friend class _IconListImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	IconList(const IconList& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	IconList& operator =(const IconList& rhs);
}; //IconList

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ICON_LIST_H_
