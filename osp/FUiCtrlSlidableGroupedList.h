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
 * @file	FUiCtrlSlidableGroupedList.h
 * @brief	This is the header file for the %SlidableGroupedList class.
 *
 * This header file contains the declarations of the %SlidableGroupedList class and its helper classes.
 */
#ifndef _FUI_CTRL_SLIDABLE_GROUPED_LIST_H_
#define _FUI_CTRL_SLIDABLE_GROUPED_LIST_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlGroupedList.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiISlidableGroupedListEventListener.h>
#include <FUiCtrlCustomListItem.h>

namespace Tizen { namespace Base { namespace Runtime
{
class IEvent;
} } }

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @class		SlidableGroupedList
 * @brief       <i> [Deprecated] </i> This class defines the common behavior of the %SlidableGroupedList control.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
 * @since		2.0
 *
 * The %SlidableGroupedList class represents a list which loads grouped
 * items on demand and unloads unused grouped items to save memory. Like GroupedList,
 * the list items of GroupedList consist of groups and items. A group represents grouped
 * items and is inserted into the first level just as items are inserted into List. Items
 * which are from CustomListItems are inserted under related groups. So, items are uniquely
 * identified with two indices: group index and item index.
 *
 * The operation of %SlidableGroupedList is the same as that of a GroupedList, except
 * that a %SlidableGroupedList does not hold all items in the memory. Most of the item manipulations
 * are available when they are loaded, but the check state is maintained for all items
 * whether they are loaded or not.
 * ISlidableGroupedListEventListener must be implemented so that an application can
 * be notified when the items need to be loaded as the user scrolls through a list.
 * If an application wants to perform tasks when the state of a list item is changed,
 * it must implement IGroupedItemEventListener and register it to the slidable
 * grouped list. It will then receive related events from %SlidableGroupedList.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically
 * when the %SlidableGroupedList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat
 * must be deleted by the application.
 *
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 *
 * @image html ui_controls_slidablegroupedlist.png
 *
 * This is the simple UI application which uses a %SlidableGroupedList control.
 *
 * @code
// Sample code for SlidableGroupedListSample.h
#include <FUi.h>

class SlidableGroupedListSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IGroupedItemEventListener
	, public Tizen::Ui::ISlidableGroupedListEventListener
{
public:
	SlidableGroupedListSample(void)
	: __pSlidableGroupedList(null)
	, __pCustomListItemFormat(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	Tizen::Ui::Controls::CustomListItem* LoadListItem(int itemId);
	virtual void OnItemStateChanged(const Tizen::Ui::Control &source, int groupIndex, int itemIndex, int itemId, int elementId, Tizen::Ui::ItemStatus status);
	virtual void OnItemStateChanged(const Tizen::Ui::Control &source, int groupIndex, int itemIndex, int itemId, Tizen::Ui::ItemStatus status);
	virtual void OnListPropertyRequested(const Tizen::Ui::Control &source);
	virtual void OnLoadToTopRequested(const Tizen::Ui::Control &source, int groupIndex, int itemIndex, int numItems);
	virtual void OnLoadToBottomRequested(const Tizen::Ui::Control &source, int groupIndex, int itemIndex, int numItems);
	virtual void OnUnloadItemRequested(const Tizen::Ui::Control& source, int groupIndex, int itemIndex);

private:
	static const int ID_LIST_TEXT  = 101;
	static const int ID_LIST_BITMAP = 102;
	static const int ITEM_HEIGHT = 103;
	static const int ITEM_COUNT = 104;
	static const int ITEM_COUNT_GROUP1 = 10;
	static const int ITEM_COUNT_GROUP2 = 20;
	static const int ITEM_COUNT_GROUP3 = 30;
	static const int ITEM_ID_LIMITS = 30;

	Tizen::Ui::Controls::SlidableGroupedList* __pSlidableGroupedList;
	Tizen::Ui::Controls::CustomListItemFormat* __pCustomListItemFormat;
};
 *	@endcode
 *
 *	@code
// Sample code for SlidableGroupedListSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "SlidableGroupedListSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


bool
SlidableGroupedListSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
SlidableGroupedListSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of SlidableGroupedList
	__pSlidableGroupedList = new SlidableGroupedList();
	__pSlidableGroupedList->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), CUSTOM_LIST_STYLE_NORMAL);
	__pSlidableGroupedList->AddGroupedItemEventListener(*this);
	__pSlidableGroupedList->AddSlidableGroupedListEventListener(*this);

	// Creates an instance of CustomListItemFormat
	__pCustomListItemFormat = new CustomListItemFormat();
	__pCustomListItemFormat->Construct();
	__pCustomListItemFormat->AddElement(ID_LIST_TEXT, Rectangle(10, 25, 240, 80));
	__pCustomListItemFormat->AddElement(ID_LIST_BITMAP, Rectangle(250, 10, 70, 80));

	// Adds the groups to the slidable grouped list
	__pSlidableGroupedList->AddGroup(L"Group1", null, ITEM_COUNT_GROUP1, ITEM_COUNT_GROUP1 * ITEM_HEIGHT);
	__pSlidableGroupedList->AddGroup(L"Group2", null, ITEM_COUNT_GROUP2, ITEM_COUNT_GROUP2 * ITEM_HEIGHT);
	__pSlidableGroupedList->AddGroup(L"Group3", null, ITEM_COUNT_GROUP3, ITEM_COUNT_GROUP3 * ITEM_HEIGHT);

	// Adds the slidable grouped list to the form
	AddControl(*__pSlidableGroupedList);

	return r;
}

result
SlidableGroupedListSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the item format
	delete __pCustomListItemFormat;

	return r;
}

CustomListItem*
SlidableGroupedListSample::LoadListItem(int itemId)
{
	// Gets instances of Bitmap
	AppResource* pAppResource = Application::App::GetInstance()->GetAppResource();
	Bitmap *pBitmapNormal  = pAppResource->GetBitmapN(L"tizen.png");
	Bitmap *pBitmapFocused = pAppResource->GetBitmapN(L"tizen.png");

	// Creates an instance of String to set an item element
	String itemText;
	int groupIndex = itemId / ITEM_ID_LIMITS;
	int itemIndex  = itemId % ITEM_ID_LIMITS;
	itemText.Format(128, L"ITEM %d-%d", groupIndex+1, itemIndex+1);

	// Creates an instance of CustomListItem
	CustomListItem* pItem = new CustomListItem();
	pItem->Construct(ITEM_HEIGHT);
	pItem->SetItemFormat(*__pCustomListItemFormat);
	pItem->SetElement(ID_LIST_TEXT, itemText);
	pItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

	// Deallocates bitmaps
	delete pBitmapNormal;
	delete pBitmapFocused;

	return pItem;
}

// IGroupedItemEventListener implementation
void
SlidableGroupedListSample::OnItemStateChanged(const Control &source, int groupIndex, int itemIndex, int itemId, ItemStatus status)
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
SlidableGroupedListSample::OnItemStateChanged(const Control &source, int groupIndex, int itemIndex, int itemId, int elementId, ItemStatus status)
{
	switch (itemId)
	{
	case 1:
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
		}
		break;
	default:
		break;
	}
}

// IFastScrollEventListener implementation
void
SlidableGroupedListSample::OnListPropertyRequested(const Control &source)
{
	// ....
}

void
SlidableGroupedListSample::OnLoadToTopRequested(const Control &source, int groupIndex, int itemIndex, int numItems)
{
	for(int i=0; i < numItems; ++i)
	{
		// Loads items upwards
		int itemId = ITEM_ID_LIMITS * groupIndex + itemIndex;

		CustomListItem* pItem = LoadListItem(itemId);
		__pSlidableGroupedList->LoadItemToTop(*pItem, itemId);
	}
}

void
SlidableGroupedListSample::OnLoadToBottomRequested (const Control &source, int groupIndex, int itemIndex, int numItems)
{
	for(int i=0; i< numItems; ++i)
	{
		// Loads items downwards
		int itemId = ITEM_ID_LIMITS * groupIndex + itemIndex + i;

		CustomListItem* pItem = LoadListItem(itemId);
		__pSlidableGroupedList->LoadItemToBottom(*pItem, itemId);
	}
}

void
SlidableGroupedListSample::OnUnloadItemRequested(const Control& source, int groupIndex, int itemIndex)
{
	// Releases resources of the specified item
	// ....
}
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ SlidableGroupedList
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since	2.0
	 * @endif
	 */
	SlidableGroupedList(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since	2.0
	 * @endif
	 */
	virtual ~SlidableGroupedList(void);

// Operation
	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %SlidableGroupedList with the specified parameters.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] rect           An instance of the Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created %SlidableGroupedList along with
	 *									the width and height.
	 * @param[in] style          The style of the CustomListItem instances
	 * @param[in]	itemDivider			Set to @c true to display an item divider, @n
	 *									else @c false
	 * @param[in]	fastScroll			Set to @c true to use fast scroll, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The size of the control must be within the range defined by the minimum size and the maximum size. @n
	 * @remarks	The minimum size of this control is 274 x 148 on a WVGA screen, 180 x 96 on a HVGA screen and 137 x 74 on a WQVGA screen.
	 *
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true, bool fastScroll = false);

	/**
	 * @if OSPDEPREC
	 * Adds the specified listener instance.
	 * The added listener can listen to the events on the context of the given event dispatcher when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @endif
	 */
	void AddSlidableGroupedListEventListener(Tizen::Ui::ISlidableGroupedListEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes the specified listener instance.
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @endif
	 */
	void RemoveSlidableGroupedListEventListener(Tizen::Ui::ISlidableGroupedListEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Loads the item to the top of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	item	        The %CustomListItem instance
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result LoadItemToTop(const Tizen::Ui::Controls::CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Loads the item to the end of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	item	        The %CustomListItem object
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result LoadItemToBottom(const Tizen::Ui::Controls::CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Unloads all the loaded items of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
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
	 * Removes all the items in the specified group. @n
	 * The group is not removed.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllItemsAt(int groupIndex);

	/**
	 * @if OSPDEPREC
	 * Removes all the items in the list.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The removed list items are deleted from the memory.
	 * @remarks		After the items have been removed, the ISlidableGroupedListEventListener::OnListPropertyRequested() method is called.
	 * @see				ISlidableGroupedListEventListener
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener		The event listener to be removed
	 * @endif
	 */
	void RemoveFastScrollEventListener(Tizen::Ui::IFastScrollEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @param[in]	listener        The event listener to be removed
	 * @endif
	 */
	void RemoveGroupedItemEventListener(Tizen::Ui::IGroupedItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the bottom of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 * @endif
	 */
	void ScrollToBottom(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the top of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 * @endif
	 */
	void ScrollToTop(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @endif
	 */
	result ScrollToTop(int groupIndex, int itemIndex);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the group at the specified index. @n
	 * The specified group is drawn at the top of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @endif
	 */
	result ScrollToTop(int groupIndex);


	/**
	 * @if OSPDEPREC
	 * Sets all the items at the specified group index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since					2.0
	 *
	 * @param[in]       groupIndex	The group index
	 * @param[in]		check		Set to @c true to check the item, @n
	 *								else @c false to uncheck
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @endif
	 */
	result SetAllItemsChecked(int groupIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Sets the contents of the group of the %SlidableGroupedList control at the specified group index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in] 	text				The string of the group to be appended
	 * @param[in] 	pBackgroundBitmap	The bitmap of the group
	 * @param[in] 	groupId				The group ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result SetGroupAt(int groupIndex, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBackgroundBitmap, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Sets the specified item as checked or unchecked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since					2.0
	 *
	 * @return				An error code
	 * @param[in]   groupIndex		The group index of the item to be checked
	 * @param[in]   itemIndex		The index of the item to be checked
	 * @param[in]   check			Set to @c true to check the item, @n
	 *                              else @c false to uncheck it
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetItemChecked(int groupIndex, int itemIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Enables or disables the item at the specified index of the %SlidableGroupedList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index of the item to be checked
	 * @param[in]	itemIndex		The index of the item to be checked
	 * @param[in]	enable			Set to @c true to enable the item, @n
	 *                              else @c false to disable it
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetLoadedItemEnabled(int groupIndex, int itemIndex, bool enable);

	/**
	 * @if OSPDEPREC
	 * Removes all the checked items from the group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	height			The estimated/real height of the items of the group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RemoveAllCheckedItemsAt(int groupIndex, int height);

	/**
	 * @if OSPDEPREC
	 * Removes the specified item from the group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	itemIndex			The item index
	 * @param[in] 	height			The estimated/real height of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   The removed list item is deleted from the memory.
	 * @endif
	 */
	result RemoveItemAt(int groupIndex, int itemIndex, int height);


	/**
	 * @if OSPDEPREC
	 * Removes the group of the %SlidableGroupedList control at the group index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When the specified group is removed, all the items in the group are also removed.
	 * @remarks   The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveGroupAt(int groupIndex);


	/**
	 * @if OSPDEPREC
	 * Gets the item at the specified indexes if the item is currently loaded.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		A pointer to the loaded item, @n
	 *				else @c null if the specified item is not currently loaded
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @endif
	 */
	const Tizen::Ui::Controls::CustomListItem* GetLoadedItemAt(int groupIndex, int itemIndex) const;


	/**
	 * @if OSPDEPREC
	 * Gets the item ID at the specified index if the item is currently loaded.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		The item ID, @n
	 *				else LIST_ITEM_UNSPECIFIED_ID if the specified item is not currently loaded
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @endif
	 */
	int GetLoadedItemIdAt(int groupIndex, int itemIndex) const;


	/**
	 * @if OSPDEPREC
	 * Gets the item index from the specified item ID.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code, @n
	 *				else @c -1 if the specified item is not currently loaded
	 * @param[in]	itemId			The item ID
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetLoadedItemIndexFromItemId(int itemId, int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Removes all the checked items of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] 	height			The height of the item to be deleted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   The removed list items are deleted from the memory.
	 * @remarks	    This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result RemoveAllCheckedItems(int height);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the first loaded item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetFirstLoadedItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the last loaded item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetLastLoadedItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Sets the first index list of the scroll by text.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[in]   text			The text of the first index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetFastScrollMainIndex(const Tizen::Base::String& text);


	/**
	 * @if OSPDEPREC
	 * Sets the second index list of the scroll by text.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in] 	text			The text of the second index @n
	 *                              Each second index of the first index has to be separated by ','
	 * @param[in] 	indexDigit		The index digit count
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The sub-index of fast scroll does not support SCROLL_INDEX_DIGIT_NUM_2. Therefore, when SCROLL_INDEX_DIGIT_NUM_2 is passed to
	 *				@c indexDigit, this method returns E_SYSTEM.
	 * @endif
	 */
	result SetFastScrollSubIndex(const Tizen::Base::String& text, FastScrollIndexDigit indexDigit = SCROLL_INDEX_DIGIT_NUM_1);

	/**
	 * @if OSPDEPREC
	 * Sets the background color of this control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since       2.0
	 *
	 * @param[in]   color    The background color
	 * @endif
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the text of the empty list.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]   text	The text of the empty list
	 * @endif
	 */
	void SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * @if OSPDEPREC
	 * Sets the color of the text to be displayed in the absence of a %SlidableGroupedList item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since     	2.0
	 *
	 * @param[in]	color	The color of the text to be displayed
	 * @endif
	 */
	void SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Gets the color of the text to be displayed in the absence of a %SlidableGroupedList item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since   2.0
	 *
	 * @return	The color of the text to be displayed
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the contents of the item in the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in]	itemIndex	    The %CustomListItem object
	 * @param[in]	item	        The item
	 * @param[in]	itemId		    The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Do not add, insert, or set an item, that already belongs to %SlidableGroupedList.
	 * @endif
	 */
	result SetItemAt(int groupIndex, int itemIndex, const Tizen::Ui::Controls::CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Adds the specified listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @endif
	 */
	void AddFastScrollEventListener(Tizen::Ui::IFastScrollEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Adds the specified group to the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   text					The string of the group to be appended
	 * @param[in]   pBackgroundBitmap		The background bitmap of the group
	 * @param[in]   itemCount				The number of items of the group
	 * @param[in]   groupHeight				The total height of the items of the group
	 * @param[in]   groupId					The group ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @endif
	 */
	result AddGroup(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBackgroundBitmap, int itemCount, int groupHeight, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Adds the specified listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @endif
	 */
	void AddGroupedItemEventListener(Tizen::Ui::IGroupedItemEventListener& listener);


	/**
	 * @if OSPDEPREC
	 * Adds the item to the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	item			The CustomListItem object
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   The added item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to %SlidableGroupedList.
	 * @endif
	 */
	result AddItem(int groupIndex, const Tizen::Ui::Controls::CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the current bottom drawn item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			 2.0
	 *
	 * @return		An error code
	 * @param[out] 	groupIndex		The group index
	 * @param[out] 	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetBottomDrawnItemIndex(int& groupIndex, int& itemIndex) const;


	/**
	 * @if OSPDEPREC
	 * Gets the index of the first checked list item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			 2.0
	 *
	 * @return		An error code
	 * @param[out] 	groupIndex		The group index
	 * @param[out] 	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetFirstCheckedItemIndex(int& groupIndex, int& itemIndex) const;


	/**
	 * @if OSPDEPREC
	 * Gets the group ID from the specified group index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		The group ID
	 * @param[in]	groupIndex	The group index
	 * @endif
	 */
	int GetGroupIdAt(int groupIndex) const;


	/**
	 * @if OSPDEPREC
	 * Gets the group index from the specified group ID.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		The group index
	 * @param[in]	groupId		The group ID
	 * @endif
	 */
	int GetGroupIndexFromGroupId(int groupId) const;


	/**
	 * @if OSPDEPREC
	 * Gets the index of the last checked item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			 2.0
	 *
	 * @return		An error code
	 * @param[out] 	groupIndex		The group index
	 * @param[out] 	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetLastCheckedItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the next checked item after the specified item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since					2.0
	 *
	 * @return			An error code
	 * @param[in,out]	groupIndex		The group index
	 * @param[in,out]	itemIndex		The item index
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception	    E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetNextCheckedItemIndexAfter(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the current top drawn item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[out]  groupIndex		The group index
	 * @param[out]  itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @endif
	 */
	result GetTopDrawnItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[in]   	x           The x position of the point
	 * @param[in]   	y           The y position of the point
	 * @param[out]	groupIndex		The index of the group, that the item belongs to
	 * @param[out]	itemIndex   	The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred. @n
	 *								There is no item at the specified position.
	 * @endif
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[in]   position    	The position of the point
	 * @param[out]	groupIndex      The index of the group, that the item belongs to
	 * @param[out]	itemIndex   	The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred. @n
	 *								There is no item at the specified position.
	 * @endif
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Inserts the group at the specified group index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since				2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]   text				The string of the group to be appended
	 * @param[in]   pBackgroundBitmap	The background bitmap of the group
	 * @param[in]   itemCount			The count of all the items in the group
	 * @param[in]   groupHeight			The total height of all the items in the group
	 * @param[in]   groupId				The group ID
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_ARG	    A specified input parameter is invalid.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @endif
	 */
	result InsertGroupAt(int groupIndex, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBackgroundBitmap, int itemCount, int groupHeight, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Checks whether the item at the specified index is checked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		@c true if the item is checked, @n
	 *	            else @c false
	 * @param[in] 	groupIndex			The group index
	 * @param[in] 	itemIndex			The item index
	 *
	 * @remarks     This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	bool IsItemChecked(int groupIndex, int itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return      @c true if the item is enabled, @n
	 *              else @c false
	 * @param[in] 	groupIndex			The group index
	 * @param[in] 	itemIndex			The item index
	 * @endif
	 */
	bool IsLoadedItemEnabled(int groupIndex, int itemIndex) const;


	/**
	 * @if OSPDEPREC
	 * Checks whether the item at the specified index is currently loaded to the slidable list.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return      @c true if the item is loaded, @n
	 *				else @c false
	 * @param[in] 	groupIndex			The group index
	 * @param[in] 	itemIndex			The item index
	 * @endif
	 */
	bool IsItemLoaded(int groupIndex, int itemIndex) const;


	/**
	 * @if OSPDEPREC
	 * Removes all the groups of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When the specified group is removed, all the items in the group are also removed.
	 * @remarks   	The removed list items are deleted from the memory.
	 * @remarks		After the items have been removed, the ISlidableGroupedListEventListener::OnListPropertyRequested() method is called.
	 * @endif
	 */
	result RemoveAllGroups(void);

	/**
	 * @if OSPDEPREC
	 * Gets the count of all the groups of the %SlidableGroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The count of all the groups
	 * @endif
	 */
	int GetGroupCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Inserts the item to the specified group and item indices.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	itemIndex		The item index
	 * @param[in]	item	        The CustomListItem object
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item, that already belongs to %SlidableGroupedList.
	 * @endif
	 */
	result InsertItemAt(int groupIndex, int itemIndex, const Tizen::Ui::Controls::CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);


	/**
	 * @if OSPDEPREC
	 * Gets the count of all the items in the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The count of all the items in the specified group
	 * @param[in]	groupIndex		The group index
	 * @endif
	 */
	int GetItemCountAt(int groupIndex) const;

	/**
	 * @if OSPDEPREC
	 * Draws and shows the specified item of %SlidableGroupedList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception   E_INVALID_OPERATION The item has never been drawn before calling this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @endif
	 */
	result RefreshItem(int groupIndex, int itemIndex);

	/**
	 * @if OSPDEPREC
	 * Draws and shows the specified group of %SlidableGroupedList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the %GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result RefreshGroup(int groupIndex);

protected:

	friend class _SlidableGroupedListImpl;
private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	SlidableGroupedList(const SlidableGroupedList& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	SlidableGroupedList& operator =(const SlidableGroupedList& rhs);

}; //SlidableGroupedList

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_SLIDABLE_GROUPED_LIST_H_
