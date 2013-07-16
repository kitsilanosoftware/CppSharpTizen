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
 * @file	FUiCtrlSlidableList.h
 * @brief	This is the header file for the %SlidableList class.
 *
 * This header file contains the declarations of the %SlidableList class and its helper classes.
 */

#ifndef _FUI_CTRL_SLIDABLE_LIST_H_
#define _FUI_CTRL_SLIDABLE_LIST_H_

//Includes
#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FUiCtrlIListViewItemProvider.h>
#include <FUiCtrlIListViewItemEventListener.h>
#include <FUiCtrlIFastScrollListener.h>
#include <FUiCtrlIScrollEventListener.h>
#include <FUiCtrlListTypes.h>
#include <FUiCtrlCustomList.h>
#include <FUiCtrlCustomListItem.h>
#include <FUiISlidableListEventListener.h>
#include <FUiCtrlCustomListItem.h>


namespace Tizen { namespace Base { namespace Runtime
{
class IEvent;
}}} // Tizen::Base::Runtime

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @class	SlidableList
 * @brief		<i> [Deprecated] </i> This class defines the common behavior of a %SlidableList control.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
 * @since		2.0
 *
 * The %SlidableList class represents a list which loads items on demand and
 * unloads unused items to save memory. The operation of %SlidableList is the same
 * as that of a List, except that a %SlidableList does not hold all the items in the memory.
 * Most of the item manipulations are available when they are loaded, but the check
 * state is maintained for all items whether they are loaded or not.
 * ISlidableListEventListener must be implemented so that an application can be
 * notified when items need to be loaded as the user scrolls through a list.
 * If an application wants to perform tasks when the state of a list item is changed,
 * then it must implement ICustomItemEventListener and register it to the slidable list,
 * It will then receive related events from %SlidableList.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically
 * when the %SlidableList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat
 * must be deleted by the application.
 *
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 *
 * @image html ui_controls_slidablelist.png
 *
 * This is the simple UI application which uses a %SlidableList control.
 *
 * @code
// Sample code for SlidableListSample.h
#include <FUi.h>

class SlidableListSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ICustomItemEventListener
	, public Tizen::Ui::ISlidableListEventListener
{
public:
	SlidableListSample(void)
	: __pSlidableList(null)
	, __pCustomListItemFormat(null){}

	bool Initialize(void);
	Tizen::Ui::Controls::CustomListItem* CreateListItem(Tizen::Base::String itemText,
					Tizen::Graphics::Bitmap* pBitmapNormal, Tizen::Graphics::Bitmap* pBitmapFocused);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// ICustomItemEventListener
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, Tizen::Ui::ItemStatus status);
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, int elementId, Tizen::Ui::ItemStatus status);

	// ISlidableEventListener
	virtual void OnListPropertyRequested (const Tizen::Ui::Control &source);
	virtual void OnLoadToTopRequested(const Tizen::Ui::Control &source, int index, int numItems);
	virtual void OnLoadToBottomRequested(const Tizen::Ui::Control &source, int index, int numItems);
	virtual void OnUnloadItemRequested(const Tizen::Ui::Control& source, int itemIndex);

private:
	static const int ID_LIST_TEXT  = 101;
	static const int ID_LIST_BITMAP = 102;
	static const int ITEM_COUNT = 100;
	static const int ITEM_HEIGHT = 100;

	Tizen::Ui::Controls::SlidableList* __pSlidableList;
	Tizen::Ui::Controls::CustomListItemFormat* __pCustomListItemFormat;
};
 *	@endcode
 *
 *	@code
// Sample code for SlidableListSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "SlidableListSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Controls;
using namespace Tizen::Graphics;

bool
SlidableListSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
SlidableListSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of SlidableList
	__pSlidableList = new SlidableList();
	__pSlidableList->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), CUSTOM_LIST_STYLE_NORMAL);
	__pSlidableList->AddCustomItemEventListener(*this);
	__pSlidableList->AddSlidableListEventListener(*this);

	// Creates an instance of CustomListItemFormat of the slidable list
	__pCustomListItemFormat = new CustomListItemFormat();
	__pCustomListItemFormat->Construct();
	__pCustomListItemFormat->AddElement(ID_LIST_TEXT, Rectangle(10, 25, 200, 80));
	__pCustomListItemFormat->AddElement(ID_LIST_BITMAP, Rectangle(220, 10, 70, 80));

	// Adds the slidable list to the form
	AddControl(__pSlidableList);

	return r;
}

result
SlidableListSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the item format
	delete __pCustomListItemFormat;

	return r;
}

CustomListItem*
SlidableListSample::CreateListItem(String itemText, Bitmap* pBitmapNormal, Bitmap* pBitmapFocused)
{
	CustomListItem* pItem = new CustomListItem();

	pItem->Construct(ITEM_HEIGHT);
	pItem->SetItemFormat(*__pCustomListItemFormat);
	pItem->SetElement(ID_LIST_TEXT, itemText);
	pItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

	return pItem;
}

// ICustomItemEventListener implementation
void
SlidableListSample::OnItemStateChanged(const Control& source, int index, int itemId, ItemStatus status)
{
	switch (itemId)
	{
	case 1:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
SlidableListSample::OnItemStateChanged(const Control& source, int index, int itemId, int elementId, ItemStatus status)
{
	switch (itemId)
	{
	case 1:
		{
			switch (elementId)
			{
			case ID_LIST_TEXT:
				{
					// ....
				}
				break;
			case ID_LIST_BITMAP:
				{
					// ....
				}
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
}

// ISlidableEventListener implementation
void
SlidableListSample::OnListPropertyRequested (const Control &source)
{
	// Sets the total count and the height of items
	__pSlidableList->SetItemCountAndHeight(ITEM_COUNT, ITEM_COUNT * ITEM_HEIGHT);
}

void
SlidableListSample::OnLoadToTopRequested(const Control &source, int index, int numItems)
{
	// Gets instances of Bitmap
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap *pBitmapNormal  = pAppResource->GetBitmapN(L"tizen.png");
	Bitmap *pBitmapFocused = pAppResource->GetBitmapN(L"tizen.png");

	// Creates items of the slidable list
	for(int i = index; i > index - numItems; i--)
	{
		String itemText = "ITEM_";
		itemText.Append(i);
		__pSlidableList->LoadItemToTop(*CreateListItem(itemText, pBitmapNormal, pBitmapFocused), i+1);
	}

	// Deallocates bitmaps
	delete pBitmapNormal;
	delete pBitmapFocused;
}

void
SlidableListSample::OnLoadToBottomRequested (const Control &source, int index, int numItems)
{
	// Gets instances of Bitmap
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap *pBitmapNormal  = pAppResource->GetBitmapN(L"tizen.png");
	Bitmap *pBitmapFocused = pAppResource->GetBitmapN(L"tizen.png");

	// Creates items of the slidable list
	for(int i = index; i < index + numItems; i++)
	{
		String itemText = L"ITEM_";
		itemText.Append(i);
		__pSlidableList->LoadItemToBottom(*CreateListItem(itemText, pBitmapNormal, pBitmapFocused), i+1);
	}

	// Deallocates bitmaps
	delete pBitmapNormal;
	delete pBitmapFocused;
}

void
SlidableListSample::OnUnloadItemRequested(const Control& source, int itemIndex)
{
	// Releases resources of the specified item
	// ....
}
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ SlidableList
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the SlidableList::Construct() method must be called right after calling this constructor.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 * @endif
	 */
	SlidableList(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 * @endif
	 */
	virtual ~SlidableList(void);

// Operation

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %SlidableList with the specified parameters.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			This instance represents the X and Y coordinates of the top-left corner of the created %SlidableList along with the width and height
	 * @param[in]	style			The style set of %CustomList
	 * @param[in]	itemDivider		Set to @c true to display an item divider, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid. @n
	 *                              Either the @c rect.width or the @c rect.height is @c 0 or negative.
	 * @exception	E_SYSTEM		The method has failed.
	 * @remarks	The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks	The minimum size of this control is 92 x 72 on a WVGA screen, 60 x 48 on a HVGA screen and 46 x 36 on a WQVGA screen.
	 *
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true);

	/**
	 * @if OSPDEPREC
	 * Adds a listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @endif
	 */
	void AddSlidableListEventListener(Tizen::Ui::ISlidableListEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes a listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 * @endif
	 */
	void RemoveSlidableListEventListener(Tizen::Ui::ISlidableListEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Adds a listener instance. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @endif
	 */
	void AddCustomItemEventListener(Tizen::Ui::ICustomItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Adds the specified item to the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	item			The CustomListItem to add
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The added item is deleted automatically when the list is destroyed. @n
	 *				Do not add, insert, or set an item which already belongs to %SlidableList.
	 * @endif
	 */
	result AddItem(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the bottom drawn item from the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An integer value representing the index of the bottom drawn item
	 * @endif
	 */
	int GetBottomDrawnItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the first item of all the checked items in the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the first selected item
	 * @remarks   This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	int GetFirstCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the count of the number of items in the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The number of items in the %SlidableList control
	 * @endif
	 */
	int GetItemCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the last item of all the checked items in the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the last selected item
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	int GetLastCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the radio checked item of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return			The next item index
	 * @param[in]   index	The item index
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	int GetNextCheckedItemIndexAfter(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the top drawn item of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the top drawn item
	 * @endif
	 */
	int GetTopDrawnItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Inserts the specified item in the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index           The item index at which to insert the item
	 * @param[in]	item            The CustomListItem instance to insert
	 * @param[in]	itemId		    The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to %SlidableList.
	 * @endif
	 */
	result InsertItemAt(int index, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Removes all the items of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks    The removed list items are deleted from the memory.
	 * @remarks		After items have been removed, the ISlidableListEventListener::OnListPropertyRequested() method is called.
	 * @see				ISlidableListEventListener
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 * @endif
	 */
	void RemoveCustomItemEventListener(Tizen::Ui::ICustomItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the bottom of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 * @endif
	 */
	void ScrollToBottom(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the top of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 * @endif
	 */
	void ScrollToTop(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @endif
	 */
	result ScrollToTop(int index);

	/**
	 * @if OSPDEPREC
	 * Sets the check status for all items of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	check		Set to @c true to check all the items, @n
	 *							else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result SetAllItemsChecked(bool check);

	/**
	 * @if OSPDEPREC
	 * Sets the check status of the item at the specified index of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return			An error code
	 * @param[in]   index		The item index
	 * @param[in]   check		The check status
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *
	 * @remarks      This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * @if OSPDEPREC
	 * Enables or disables the status of the item at the specified index of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return			An error code
	 * @param[in]   index		The item index
	 * @param[in]   enable	    Set to @c true to enable, @n
	 *						    else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *
	 * @endif
	 */
	result SetLoadedItemEnabled(int index, bool enable);

	/**
	 * @if OSPDEPREC
	 * Sets the background color of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since               2.0
	 *
	 * @param[in]     color    The background color
	 * @endif
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the text to display in the absence of a %SlidableList item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @param[in] text		The text message
	 * @endif
	 */
	void SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * @if OSPDEPREC
	 * Sets a color of the text to display in the absence of a %SlidableList item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since     2.0
	 *
	 * @param[in]	color	The color of the text to display
	 * @endif
	 */
	void SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Gets a color of the text to display in the absence of a %SlidableList item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since  2.0
	 *
	 * @return	The color of the text to be displayed
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the loaded item at the specified index of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		A CustomListItem
	 * @param[in] index		The item index
	 * @endif
	 */
	const CustomListItem* GetLoadedItemAt(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the loaded item at the specified item ID.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The item ID
	 * @param[in] index		The item index
	 * @endif
	 */
	int GetLoadedItemIdAt(int index) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in] index		The item index
	 * @endif
	 */
	bool IsItemChecked(int index) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the loaded item at the specified index is enabled.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in] index		The item index
	 * @endif
	 */
	bool IsLoadedItemEnabled(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the loaded item at the specified item ID.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since					2.0
	 *
	 * @return				The index of the item
	 * @param[in]     itemId		The item ID
	 * @endif
	 */
	int GetLoadedItemIndexFromItemId(int itemId) const;

	/**
	 * @if OSPDEPREC
	 * Loads the item to the top of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	item			The CustomListItem instance to load
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result LoadItemToTop(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Loads the item to the end of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	item			The CustomListItem instance to load
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result LoadItemToBottom(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Unloads all loaded items of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result UnloadAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Sets the contents of the item at the specified index of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] index               The item index
	 * @param[in]	item				The CustomListItem instance to set
	 * @param[in]	itemId				The item ID for this item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c index is less than @c 0 or greater than or equal to the item count.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Do not add, insert, or set an item which already belongs to %SlidableList.
	 * @endif
	 */
	result SetItemAt(int index, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Removes the item at the specified index of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] index		The item index to delete
	 * @param[in] itemHeight	The height of the item to delete
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks   The removed list item is deleted from the memory.
	 * @endif
	 */
	result RemoveItemAt(int index, int itemHeight);

	/**
	 * @if OSPDEPREC
	 * Removes all the checked items of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] itemHeight		The height of the item to delete
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   The removed list items are deleted from the memory.
	 * @remarks	This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result RemoveAllCheckedItems(int itemHeight);

	/**
	 * @if OSPDEPREC
	 * Sets the number of items and the combined height of all the items of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @param[in]   count		The count of list items
	 * @param[in]   listHeight	The height of the list
	 * @endif
	 */
	void SetItemCountAndHeight(int count, int listHeight);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specific item is loaded.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return		@c true if the item is loaded, @n
	 *				else @c false
	 * @param[in]   index	The item index
	 * @endif
	 */
	bool IsItemLoaded(int index) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the first loaded item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the first loaded item
	 * @endif
	 */
	int GetFirstLoadedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the last loaded item.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		The index of the last loaded item
	 * @endif
	 */
	int GetLastLoadedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return      The index of the item, @n
	 *				else @c -1 if there is no list item with the specified position
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
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since				2.0
	 *
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item with the specified position
	 * @param[in]   position    The position of the point
	 * @endif
	 */
	int GetItemIndexFromPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * @if OSPDEPREC
	 * Draws and shows the item of the %SlidableList control.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The index of the %SlidableList item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_INVALID_OPERATION The item has never been drawn before calling this method.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @endif
	 */
	result RefreshItem(int index);

protected:

	friend class _SlidableListImpl;
private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	SlidableList(const SlidableList& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	SlidableList& operator =(const SlidableList& rhs);
}; //SlidableList
}}} // Tizen::Ui::Controls
#endif // _FUI_CTRL_SLIDABLE_LIST_H_
