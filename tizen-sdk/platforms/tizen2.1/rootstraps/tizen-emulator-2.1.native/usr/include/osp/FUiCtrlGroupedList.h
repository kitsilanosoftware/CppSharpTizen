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
 * @file	FUiCtrlGroupedList.h
 * @brief	This is the header file for the %GroupedList class.
 *
 * This header file contains the declarations of the %GroupedList class and its helper classes.
 */

#ifndef _FUI_CTRL_GROUPED_LIST_H_
#define _FUI_CTRL_GROUPED_LIST_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlCustomList.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiIFastScrollEventListener.h>
#include <FUiIGroupedItemEventListener.h>
#include <FUiCtrlListTypes.h>

namespace Tizen { namespace Ui { namespace Controls {

/**
 * @if OSPDEPREC
 * @class		GroupedList
 * @brief       <i> [Deprecated] </i> This class defines the common behavior of a %GroupedList control.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
 * @since		2.0
 *
 * The %GroupedList class represents grouped items in a list. List items of
 * %GroupedList consist of groups and items. A group represents grouped items and is
 * inserted into the first level as items are inserted into List. Items which are
 * CustomListItem are inserted under related groups. So, items are uniquely identified
 * with two indices: group index and item index.
 *
 * If an application wants to perform tasks when the state of a list item is changed,
 * it must implement IGroupedItemEventListener and register it to the grouped list,
 * It will then receive related events from %GroupedList.
 *
 * Unlike ExpandableList which is also a list with a hierarchy of depth 2, group
 * item itself does not have many functions.
 *
 * A typical use case of %GroupedList would be a list which groups all items alphabetically.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically
 * when the %GroupedList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat
 * must be deleted by the application.
 *
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 *
 * @image html ui_controls_groupedlist.png
 *
 * This is the simple UI application that uses a %GroupedList control.
 *
 * @code
// Sample code for GroupedListSample.h
#include <FApp.h>
#include <FUi.h>

class GroupedListSample
	:public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ICustomItemEventListener
{
public:
	GroupedListSample(void)
	: __pGroupedList(null)
	, __pCustomListItemFormat(null){}

	bool Initialize(void);
	result AddListItem(Tizen::Ui::Controls::GroupedList& groupedList, int groupId, Tizen::Base::String itemText,
			Tizen::Graphics::Bitmap* pBitmapNormal, Tizen::Graphics::Bitmap* pBitmapFocused);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// ICustomItemEventListener
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, Tizen::Ui::ItemStatus status);
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, int elementId, Tizen::Ui::ItemStatus status);

private:
	static const int ID_LIST_	   = 101;
	static const int ID_LIST_TEXT   = 102;
	static const int ID_LIST_BITMAP = 103;

	Tizen::Ui::Controls::GroupedList* __pGroupedList;
	Tizen::Ui::Controls::CustomListItemFormat* __pCustomListItemFormat;
};
 *	@endcode
 *
 *	@code
// Sample code for CutomListSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "GroupedListSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
GroupedListSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
GroupedListSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of GroupedList
	__pGroupedList = new GroupedList();
	__pGroupedList->Construct(Rectangle(0,0,GetClientAreaBounds().width,GetClientAreaBounds().height), CUSTOM_LIST_STYLE_NORMAL);

	// Creates an instance of CustomListItemFormat of the grouped list
	__pCustomListItemFormat = new CustomListItemFormat();
	__pCustomListItemFormat->Construct();
	__pCustomListItemFormat->AddElement(ID_LIST_TEXT, Rectangle(10, 25, 200, 80));
	__pCustomListItemFormat->AddElement(ID_LIST_BITMAP, Rectangle(220, 10, 70, 80));

	// Adds the groups to the grouped list
	__pGroupedList->AddGroup(L"Group_1", null);
	__pGroupedList->AddGroup(L"Group_2", null);
	__pGroupedList->AddGroup(L"Group_3", null);

	// Gets instances of Bitmap
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap *pBitmapNormal  = pAppResource->GetBitmapN(L"tizen.png");
	Bitmap *pBitmapFocused = pAppResource->GetBitmapN(L"tizen.png");

	// Adds the items to the grouped list
	for (int i = 0; i < __pGroupedList->GetGroupCount(); i++ )
	{
		AddListItem(*__pGroupedList, i, L"SubItem1", pBitmapNormal, pBitmapFocused);
		AddListItem(*__pGroupedList, i, L"SubItem2", pBitmapNormal, pBitmapFocused);
		AddListItem(*__pGroupedList, i, L"SubItem3", pBitmapNormal, pBitmapFocused);
		AddListItem(*__pGroupedList, i, L"SubItem4", pBitmapNormal, pBitmapFocused);
	}

	// Adds the grouped list to the form
	AddControl(__pGroupedList);

	// Deallocates bitmaps
	delete pBitmapNormal;
	delete pBitmapFocused;

	return r;
}

result
GroupedListSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the item format
	delete __pCustomListItemFormat;

	return r;
}

result
GroupedListSample::AddListItem(GroupedList& groupedList, int groupId, String itemText, Bitmap* pBitmapNormal, Bitmap* pBitmapFocused)
{
	result r = E_SUCCESS;

	// Creates an instance of CustomListItem of the grouped list
	CustomListItem* pItem = new CustomListItem();
	pItem->Construct(100);
	pItem->SetItemFormat(*__pCustomListItemFormat);
	pItem->SetElement(ID_LIST_TEXT, itemText);
	pItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

	// Adds the item to the grouped list
	groupedList.AddItem(groupId, *pItem, ID_LIST_);

	return r;
}

// ICustomItemEventListener implementation
void
GroupedListSample::OnItemStateChanged(const Control& source, int index, int itemId, ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
GroupedListSample::OnItemStateChanged(const Control& source, int index, int itemId, int elementId, ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_:
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
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ GroupedList
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the GroupedList::Construct() method must be called right after calling this constructor.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 * @endif
	 */
	GroupedList(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~GroupedList(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %GroupedList with the specified parameters.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Graphics::Rectangle class @n
	 *					This instance represents the X, Y coordinates of the top-left corner of the created %GroupedList along with the width and
	 *								height.
	 * @param[in]	style			The style of the %GroupedList control
	 * @param[in]	itemDivider		Set to @c true to display an item divider, @n
	 *								else @c false
	 * @param[in]	fastScroll		Set to @c true if to use a fast scroll, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- The size of the control must be within the range as defined by the minimum and maximum size.
	 *			- The minimum size of this control is 274 x 148 on a WVGA screen, 180 x 96 on a HVGA screen and 137 x 74 on a WQVGA screen.
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true, bool fastScroll = false);

	/**
	 * @if OSPDEPREC
	 * Adds the group to the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text				The string of the group to append
	 * @param[in]	pBackgroundBitmap	The background bitmap of the group
	 * @param[in]	groupId				The ID of the group
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @endif
	 */
	result AddGroup(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBackgroundBitmap, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Inserts the group of the %GroupedList control at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex			The group index
	 * @param[in]   text				The name of the group item
	 * @param[in]   pBackgroundBitmap	The background bitmap of the group item
	 * @param[in]   groupId				The ID of the group item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The @c groupIndex is out of bounds.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result InsertGroupAt(int groupIndex, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBackgroundBitmap, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Sets the contents of the group of the %GroupedList control at the index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex		    The group index
	 * @param[in]   text			    The string of the group to append
	 * @param[in]   pBackgroundBitmap	The bitmap of the group
	 * @param[in]   groupId				The ID of the group
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @endif
	 */
	result SetGroupAt(int groupIndex, const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBackgroundBitmap, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Removes the group of the %GroupedList control at the index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- When the specified group is removed, all the items in the group are also removed.
	 *			- The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveGroupAt(int groupIndex);

	/**
	 * @if OSPDEPREC
	 * Removes all the groups of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- When the specified group is removed, all the items in the group are also removed.
	 *			- The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllGroups(void);

	/**
	 * @if OSPDEPREC
	 * Counts all the groups of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The count of all the groups
	 * @endif
	 */
	int GetGroupCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Adds the item to the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	item			The custom list item object to add
	 * @param[in]	itemId			The specified item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemId is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- The added item is deleted automatically when the list is destroyed.
	 *			- Do not add, insert, or set an item that already belongs to a %GroupedList control.
	 * @endif
	 */
	result AddItem(int groupIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
 	 * @if OSPDEPREC
	 * Inserts the item to the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex		The group index
	 * @param[in]   itemIndex		The item index in the specified group
	 * @param[in]	item	        The custom list item to insert
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemId is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 *			- The inserted item is deleted automatically when the list is destroyed.
	 *			- Do not add, insert, or set an item that already belongs to a %GroupedList control.
	 * @endif
	 */
	result InsertItemAt(int groupIndex, int itemIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Sets the contents of the item in the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex		The group index
	 * @param[in]   itemIndex		The item index in the specified group
	 * @param[in]	item			The custom list item to set
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemId is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Do not add, insert, or set an item that already belongs to a %GroupedList control.
	 * @endif
	 */
	result SetItemAt(int groupIndex, int itemIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
 	 * @if OSPDEPREC
	 * Sets the checked status for the specified item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since			2.0
	 *
	 * @return						An error code
	 * @param[in]   groupIndex		The group index of the item
	 * @param[in]   itemIndex		The item index
	 * @param[in]   check			Set to @c true to check the item, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetItemChecked(int groupIndex, int itemIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Enables or disables the item at the specified index of the %GroupedList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index of the item
	 * @param[in]   itemIndex		The item index
	 * @param[in]	enable			Set to @c true to enable the item, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetItemEnabled(int groupIndex, int itemIndex, bool enable);

	/**
	 * @if OSPDEPREC
	 * Sets the background color of this control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since       2.0
	 *
	 * @param[in]	color	The background color
	 * @endif
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the text that is displayed when %GroupedList is empty.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	text	The empty list test
 	 * @endif
	 */
	void SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
 	 * @if OSPDEPREC
	 * Sets the color of the text that is displayed when %GroupedList is empty.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since     2.0
	 *
	 * @param[in]	color	The color of the text to display
	 * @endif
	 */
	void SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Gets the color of the text that is displayed when %GroupedList is empty.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since	2.0
	 *
	 * @return	The color of the text to be displayed
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the item at the specified index of this grouped list is checked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		@c true if the item is checked, @n
	 *              else @c false
	 * @param[in]	groupIndex		The group index of the item
	 * @param[in]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	bool IsItemChecked(int groupIndex, int itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]   groupIndex		The group index of the item
	 * @param[in]   itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	bool IsItemEnabled(int groupIndex, int itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Removes an item in the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex		The group index
	 * @param[in]   itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The removed list item is deleted from the memory.
	 * @endif
	 */
	result RemoveItemAt(int groupIndex, int itemIndex);

	/**
	 * @if OSPDEPREC
	 * Removes all the items in the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllItemsAt(int groupIndex);

	/**
	 * @if OSPDEPREC
	 * Removes all the checked items in the specified group.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllCheckedItemsAt(int groupIndex);

	/**
	 * @if OSPDEPREC
	 * Counts all items of the %GroupedList instance.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The item count of the specified group
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	int GetItemCountAt(int groupIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item ID of the item at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The item ID
	 * @param[in]   groupIndex		The group index
	 * @param[in]   itemIndex		The item index in the specified group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	int GetItemIdAt(int groupIndex, int itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item index by the specified item ID.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		itemId			The item ID
	 * @param[out]      groupIndex		The group index
	 * @param[out]      itemIndex		The item index in the specified group
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetItemIndexFromItemId(int itemId, int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the group ID at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The group ID
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	int GetGroupIdAt(int groupIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the group index from the specified group ID.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		The group index
	 * @param[in]	groupId		    The ID of the group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	int GetGroupIndexFromGroupId(int groupId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the last item checked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  groupIndex		The group index
	 * @param[out]  itemIndex		The item index in the specified group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetLastCheckedItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the next checked item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in,out]   groupIndex		The group index
	 * @param[in,out]   itemIndex		The item index in the specified group
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetNextCheckedItemIndexAfter(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   x				The x position of the point
	 * @param[in]   y				The y position of the point
	 * @param[out]	groupIndex		The index of the group which the item belongs to
	 * @param[out]	itemIndex		The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred. @n
	 *								There is no item at the specified position.
	 * @endif
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified item position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   position        The position of the point
	 * @param[out]	groupIndex      The index of the group which the item belongs to
	 * @param[out]	itemIndex       The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred. @n
	 *								There is no item at the specified position.
	 * @endif
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the current top drawn list item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  groupIndex	    The group index of the item
	 * @param[out]  itemIndex		The item index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetTopDrawnItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Removes all the items of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Removes all the checked items of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllCheckedItems(void);

	/**
	 * @if OSPDEPREC
	 * Gets the specified item of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		A custom list item
	 * @param[in]   groupIndex			The index of the group which the item belongs to
	 * @param[in]   itemIndex		    The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	const CustomListItem* GetItemAt(int groupIndex, int itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Scrolls to the bottom of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since	2.0
	 * @endif
	 */
	void ScrollToBottom(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the top of the %GroupedList.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since	2.0
	 * @endif
	 */
	void ScrollToTop(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result ScrollToTop(int groupIndex, int itemIndex);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the group at the specified index. @n
	 * The specified group is drawn at the top of the %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result ScrollToTop(int groupIndex);

	/**
	 * @if OSPDEPREC
	 * Sets the first index list of scroll by text.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
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
	 * Adds the fast scroll event listener.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to add
	 * @endif
	 */
	void AddFastScrollEventListener(Tizen::Ui::IFastScrollEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes the fast scroll event listener.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 * @endif
	 */
	void RemoveFastScrollEventListener(Tizen::Ui::IFastScrollEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Adds the grouped list item event listener.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to add
	 * @endif
	 */
	void AddGroupedItemEventListener(Tizen::Ui::IGroupedItemEventListener& listener);

	/**
 	 * @if OSPDEPREC
	 * Removes the grouped list item event listener.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 * @endif
	 */
	void RemoveGroupedItemEventListener(Tizen::Ui::IGroupedItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the first checked list item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  groupIndex	    The group index of the item
	 * @param[out]  itemIndex		The item index of the item
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetFirstCheckedItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Sets the checked status of all the items of the specified group with the given value.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   groupIndex	    The group index of the item
	 * @param[in]   check			Set to @c true to check all the items, @n
	 *							    else @c false
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetAllItemsChecked(int groupIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the current bottom drawn list item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  groupIndex	    The group index of the item
	 * @param[out]  itemIndex		The item index of the item
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result GetBottomDrawnItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * @if OSPDEPREC
	 * Draws and shows the item of %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_INVALID_OPERATION	The item has never been drawn before calling this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result RefreshItem(int groupIndex, int itemIndex);

	/**
	 * @if OSPDEPREC
	 * Draws and shows the group of %GroupedList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RefreshGroup(int groupIndex);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	GroupedList(const GroupedList& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	GroupedList& operator =(const GroupedList& rhs);

	friend class _GroupedListImpl;
}; //GroupedList
}}} // Tizen::Ui::Controls
#endif // _FUI_CTRL_GROUPED_LIST_H_
