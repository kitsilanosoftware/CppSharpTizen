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
 * @file	FUiCtrlExpandableList.h
 * @brief	This is the header file for the %ExpandableList class.
 *
 * This header file contains the declarations of the %ExpandableList class and its helper classes.
 */

#ifndef _FUI_CTRL_EXPANDABLE_LIST_H_
#define _FUI_CTRL_EXPANDABLE_LIST_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiContainer.h>
#include <FUiIExpandableItemEventListener.h>
#include <FUiCtrlCustomListTypes.h>
#include <FUiCtrlListTypes.h>
#include <FUiCtrlCustomListItem.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @class	ExpandableList
 * @brief <i> [Deprecated] </i> This class defines the common behavior of an %ExpandableList control.
 *
 * @deprecated This class is deprecated. Instead of using this class, use GroupedTableView class. @n
 * @since		2.0
 *
 * The %ExpandableList class defines the common behavior of an %ExpandableList control.
 * An expandable list is a list with a hierarchy of depth 2. List items of %ExpandableList
 * consist of main items and sub-items which are CustomListItem. Main items are inserted
 * into the first level as items are inserted into List class. Sub-items are inserted under
 * related main items. So, sub-items are uniquely identified with two indices: main item
 * index and sub-item index.
 *
 * If an application wants to perform tasks when the state of a list item is changed,
 * it must implement IExpandableItemEventListener and register it to the expandable list,
 * It will then receive related events from %ExpandableList.
 *
 * Unlike GroupedList which is also a list with the hierarch of depth 2, main items of
 * %ExpandableList can be expanded or closed.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically
 * when the %ExpandableList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat
 * must be deleted by the application.
 *
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 *
 * @image html ui_controls_expandablelist.png
 *
 * This is the simple UI application which uses an %ExpandableList control.
 *
 * @code
//Sample code for ExpandableListSample.h
#include <FUi.h>

class ExpandableListSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IExpandableItemEventListener
{
public:
	ExpandableListSample(void)
	: __pMainItemFormat(null)
	, __pSubItemFormat(null){}

	bool Initialize(void);
	result AddListMainItem(Tizen::Ui::Controls::ExpandableList& expandableList, Tizen::Base::String itemText,
			Tizen::Graphics::Bitmap* pBitmapNormal, Tizen::Graphics::Bitmap* pBitmapFocused);
	result AddListSubItem(Tizen::Ui::Controls::ExpandableList& expandableList, int itemId, Tizen::Base::String itemText);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IExpandableItemEventListener
	virtual void OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, Tizen::Ui::ItemStatus  status);
	virtual void OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, int elementId, Tizen::Ui::ItemStatus  status);



private:
	static const int ID_LIST_MAINITEM = 101;
	static const int ID_LIST_SUBITEM = 102;
	static const int ID_LIST_TEXT = 103;
	static const int ID_LIST_BITMAP = 104;

	Tizen::Ui::Controls::CustomListItemFormat* __pMainItemFormat;
	Tizen::Ui::Controls::CustomListItemFormat* __pSubItemFormat;
};
 *	@endcode
 *
 *	@code
//Sample code for ExpandableListSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "ExpandableListSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

bool
ExpandableListSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ExpandableListSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of ExpandableList
	ExpandableList* pExpandableList = new ExpandableList();
	pExpandableList->Construct(Rectangle(0, 0, 480, 500), CUSTOM_LIST_STYLE_NORMAL);
	pExpandableList->AddExpandableItemEventListener(*this);

	// Creates an instance of CustomListItemFormat of the main item
	__pMainItemFormat = new CustomListItemFormat();
	__pMainItemFormat->Construct();
	__pMainItemFormat->AddElement(ID_LIST_TEXT, Rectangle(10, 25, 200, 80));
	__pMainItemFormat->AddElement(ID_LIST_BITMAP, Rectangle(220, 10, 70, 80));

	// Creates an instance of CustomListItemFormat of the sub item
	__pSubItemFormat = new CustomListItemFormat();
	__pSubItemFormat->Construct();
	__pSubItemFormat->AddElement(ID_LIST_TEXT, Rectangle(20, 25, 450, 50));

	// Gets instances of Bitmap
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap *pBitmapNormal  = pAppResource->GetBitmapN(L"tizen.png");
	Bitmap *pBitmapFocused = pAppResource->GetBitmapN(L"tizen.png");

	// Adds the main item
	AddListMainItem(*pExpandableList, L"MainItem", pBitmapNormal, pBitmapFocused);

	// Adds the sub item
	AddListSubItem(*pExpandableList, ID_LIST_MAINITEM, L"SubItem");

	// Adds the expandable list to the form
	AddControl(*pExpandableList);

	// Deallocates bitmaps
	delete pBitmapNormal;
	delete pBitmapFocused;

	return r;
}

result
ExpandableListSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates item formats
	delete __pMainItemFormat;
	delete __pSubItemFormat;

	return r;
}

result
ExpandableListSample::AddListMainItem(ExpandableList& expandableList, String itemText, Bitmap* pBitmapNormal, Bitmap* pBitmapFocused)
{
	result r = E_SUCCESS;

	// Creates a main instance of CustomListItem of the expandable list
	CustomListItem* pMainItem = new CustomListItem();
	pMainItem->Construct(100);
	pMainItem->SetItemFormat(*__pMainItemFormat);
	pMainItem->SetElement(ID_LIST_TEXT, itemText);
	pMainItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

	// Adds the item to the expandable list
	expandableList.AddItem(*pMainItem, ID_LIST_MAINITEM);

	return r;
}

result
ExpandableListSample::AddListSubItem(ExpandableList& expandableList, int itemId, String itemText)
{
	result r = E_SUCCESS;

	// Creates a sub instance of CustomListItem of the expandable list
	CustomListItem* pSubItem = new CustomListItem();
	pSubItem->Construct(100);
	pSubItem->SetItemFormat(*__pSubItemFormat);
	pSubItem->SetElement(ID_LIST_TEXT, itemText);

	// Adds the item to the expandable list
	expandableList.AddSubItem(expandableList.GetItemIndexFromItemId(ID_LIST_MAINITEM), *pSubItem, ID_LIST_SUBITEM);

	return r;
}

// IExpandableItemEventListener implementation
void
ExpandableListSample::OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_MAINITEM:
		{
			// ....
		}
		break;
	case ID_LIST_SUBITEM:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
ExpandableListSample::OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, int elementId, ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_MAINITEM:
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
	case ID_LIST_SUBITEM:
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
class _OSP_EXPORT_ ExpandableList
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 * @endif
	 */
	ExpandableList(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~ExpandableList(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %ExpandableList with the specified parameters.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]	rect				The x, y position of the top-left corner of the %ExpandableList along with the width and the height of the control
	 * @param[in]   style				The style set
	 * @param[in]	itemDivider			Set to @c true to display the divider, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The size of the control must be within the range defined by the minimum size and the maximum size.
	 *		The minimum size of this control is 92 x 72 on a WVGA screen, 60 x 48 on a HVGA screen and 46 x 36 on a WQVGA screen.
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true);

	/**
	 * @if OSPDEPREC
	 * Adds the ExpandableItemEventListener instance. @n
	 * The added listener gets notified when the state of an item is changed.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @endif
	 */
	void AddExpandableItemEventListener(Tizen::Ui::IExpandableItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes the ExpandableItemEventListener instance. @n
	 * The removed listener is not notified even when the expandable item events are fired.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @endif
	 */
	void RemoveExpandableItemEventListener(Tizen::Ui::IExpandableItemEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Adds the specified item to the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	item			The CustomListItem to be added
	 * @param[in]	itemId			The item ID for the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The item ID can be used to identify the specific %CustomListItem instance or to associate the user-allocated resources. @n
	 *				Note that %ExpandableList does not throw an exception, if the same item ID is given to multiple items. @n
	 *              	The added item is deleted automatically when the list is destroyed. @n
	 *				Do not add, insert, or set an item which already belongs to the %ExpandableList.
	 * @endif
	 */
	result AddItem(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Inserts the specified item to the %ExpandableList control at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index at which to insert the item
	 * @param[in]	item            	The CustomListItem to be inserted
	 * @param[in]	itemId         		The item ID for the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to the %ExpandableList control.
	 * @endif
	 */
	result InsertItemAt(int mainIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Changes the contents of the item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index at which to set the contents of the item
	 * @param[in]	item            	The CustomListItem to be set
	 * @param[in]	itemId          	The item ID for the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		Do not add, insert, or set an item that already belongs to the %ExpandableList control.
	 * @endif
	 */
	result SetItemAt(int mainIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Removes the item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex			The index of the item to be deleted
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The removed list item is deleted from the memory.
	 * @endif
	 */
	result RemoveItemAt(int mainIndex);

	/**
	 * @if OSPDEPREC
	 * Removes all the items from the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks   The removed list items are deleted from the memory.
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Gets the item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		A CustomListItem instance, @n
	 *				else @c null if the specified index is out of range
	 * @param[in]	mainIndex		The index of the item
	 * @endif
	 */
	const CustomListItem* GetItemAt(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Adds the specified sub-item to the main item in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item to which the sub-item is added
	 * @param[in]	item            	The CustomListItem instance to be added
	 * @param[in]	itemId          	The item ID for the sub-item
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_INVALID_ARG		The specified index is less than @c 0, or greater than the item count.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result AddSubItem(int mainIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Inserts the specified sub-item at the specified index to the main item in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item to which the sub-item is added
	 * @param[in]   subIndex        	The index of the sub-item at which to insert the item
	 * @param[in]	item            	The CustomListItem instance to be inserted
	 * @param[in]	itemId          	The item ID
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_INVALID_ARG   	The specified index is less than @c 0, or greater than the item count.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result InsertSubItemAt(int mainIndex, int subIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Changes the contents of the sub-item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The main index of the sub-item at which to set the contents of the item
	 * @param[in]   subIndex        	The sub-index of the sub-item at which to set the contents of the item
	 * @param[in]   item            	The CustomListItem instance to be set
	 * @param[in]   itemId          	The item ID
	 * @exception   E_SUCCESS       	The method is successful.
	 * @exception   E_INVALID_ARG   	The specified index is less than @c 0, or greater than the item count.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result SetSubItemAt(int mainIndex, int subIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @if OSPDEPREC
	 * Removes the sub-item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex        	The index of the sub-item to be deleted in the main item
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified index is less than @c 0, or greater than the item count.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result RemoveSubItemAt(int mainIndex, int subIndex);

	/**
	 * @if OSPDEPREC
	 * Removes all sub-items of the specified main item in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex			The index of the main item of the %ExpandableList control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified index is less than @c 0, or greater than or equal to the item count.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result RemoveAllSubItemsAt(int mainIndex);

	/**
	 * @if OSPDEPREC
	 * Gets the number of items in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		The number of items in %ExpandableList, @n
	 *				else @c -1 if an error occurs
	 * @endif
	 */
	int GetItemCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the number of sub-items in the main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		The number of sub-items in the main item, @n
	 *              else @c -1 if an error occurs
	 * @param[in] mainIndex The index of the main item
	 * @endif
	 */
	int GetSubItemCount(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the sub-item at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		A pointer to the CustomListItem instance at the specified index,  @n
	 *				else @c null if the specified index does not exist in the %ExpandableList control
	 * @param[in]   mainIndex   The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex    The index of the sub-item to get in the main index
	 * @endif
	 */
	const CustomListItem* GetSubItemAt(int mainIndex, int subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the first item of all the checked main items in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      The index of the first checked item,  @n
	 *              else @c -1 if no main item is checked
	 * @endif
	 */
	int GetFirstCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item ID of the specified main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since	   2.0
	 *
	 * @return      The item ID of the main item, @n
	 *              else @c -1 if the specified @c mainIndex is less than @c 0 or greater than the main item count
	 * @param[in]   mainIndex  The index of the main item
	 * @endif
	 */
	int GetItemIdAt(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the specified main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      The index of the main item, @n
	 *              else @c -1 if no main item has the specified item ID
	 * @param[in]	itemId		The item ID
	 * @remarks A main item can have the same item ID and this method returns the first main item among such items.
	 * @endif
	 */
	int GetItemIndexFromItemId(int itemId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the item ID of the specified sub-item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since	    2.0
	 *
	 * @return       The item ID of the specified sub-item, @n
	 *               else @c -1 if the specified sub-item does not exist
	 * @param[in]	mainIndex	The index of the main item, which the sub-item belongs to
	 * @param[in]    subIndex      The index of the sub-item
	 * @endif
	 */
	int GetSubItemIdAt(int mainIndex, int subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Expands or shrinks the specified main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item
	 * @param[in]   expand				Set to @c true to expand the specified main item, @n
	 *						        	else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified @c mainIndex is less than @c 0, or greater than the main item count.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result SetItemExpanded(int mainIndex, bool expand);

	/**
	 * @if OSPDEPREC
	 * Checks whether the main item is expanded.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      @c true if the main item is expanded, @n
	 *				else @c false
	 * @param[in]   mainIndex   The index of the main item
	 * @endif
	 */
	bool IsItemExpanded(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Enables or disables the status of the main item at the specified index of the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   mainIndex       	The index of the main item, for which the status is to be set
	 * @param[in]   enable          	Set to @c true to enable the main item, @n
	 *									else @c false
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified @c mainIndex is less than @c 0, or no less than the main item count.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result SetItemEnabled(int mainIndex, bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the main item at the specified index in the %ExpandableList control is enabled.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      @c true if the main item is enabled, @n
	 *              else @c false
	 * @param[in]	mainIndex	The index of the main item to be checked
	 * @endif
	 */
	bool IsItemEnabled(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Sets the enabled status of the specific sub-item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex        	The index of the sub-item in the main item
	 * @param[in]   enable				Set to @c true to enable the sub-item, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The sub-item at the specified index does not exist.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result SetSubItemEnabled(int mainIndex, int subIndex, bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified sub-item is enabled.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      @c true if the specified sub-item is enabled, @n
	 *				else @c false
	 * @param[in]   mainIndex         The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex          The index of the sub-item in the main item
	 * @endif
	 */
	bool IsSubItemEnabled(int mainIndex, int subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Sets the check status of the main item at the specified index.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex	    	The index of the main item
	 * @param[in]   check		    	Set to @c true to check the main item, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	The specified @c mainIndex is less than @c 0, or no less than the main item count.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	result SetItemChecked(int mainIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Checks whether the status of the main item at the specified index is checked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      @c true if the main item is checked, @n
	 *				else @c false
	 * @param[in]	mainIndex	The index of the main item
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	bool IsItemChecked(int mainIndex) const;


	/**
	 * @if OSPDEPREC
	 * Sets the check status of the specified sub-item of the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return	    An error code
	 * @param[in]   mainIndex       	The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex        	The index of the sub-item in the main index
	 * @param[in]	check				Set to @c true to check the sub-item, @n
	 *									else @c false
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception   E_INVALID_ARG   	The sub-item at the specified index does not exist.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	result SetSubItemChecked(int mainIndex, int subIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Checks whether the specified sub-item is checked.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		@c true if the sub-item is checked, @n
	 *				else @c false
	 * @param[in]   mainIndex  The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex  The index of the sub-item in the main item
	 * @remarks		This method can only be used when the style of the list allows selection.
	 * @endif
	 */
	bool IsSubItemChecked(int mainIndex, int subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Sets the check status of all sub-items of the specified main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item
	 * @param[in]	check				Set to @c true to check the items, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	The specified @c mainIndex is less than @c 0, or greater than the main item count.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result SetAllSubItemsChecked(int mainIndex, bool check);

	/**
	 * @if OSPDEPREC
	 * Removes all the checked sub-items of the specified main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG   	The specified @c mainIndex is less than @c 0, or not less than the main item count.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 * @endif
	 */
	result RemoveAllCheckedSubItemsAt(int mainIndex);

	/**
	 * @if OSPDEPREC
	 * Gets the first sub-item of all the checked sub-items in the main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return      The index of the first checked sub-item, @n
	 *              else @c -1 if no sub-item is checked, or the specified main item does not exist
	 * @endif
	 */
	int GetFirstCheckedSubItemIndex(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the last item of all the checked main items in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return       The index of the last checked item, @n
	 *               else @c -1 if no main item is checked
	 * @endif
	 */
	int GetLastCheckedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the last sub-item of all the checked sub-items in the main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
 	 * @since		2.0
	 *
	 * @return       The index of the last checked sub-item, @n
	 *               else @c -1 if no sub-item is checked or the specified main item does not exist
	 * @endif
	 */
	int GetLastCheckedSubItemIndex(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the next checked main item from the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return       The index of the next checked main item, @n
	 *               else @c -1 if no more main item after the specified index is checked, or the specified main item does not exist
	 * @param[in]    mainIndex  The index of the main item
	 * @endif
	 */
	int GetNextCheckedItemIndexAfter(int mainIndex) const;

	/**
	 * Gets the next checked sub-item from the specified index in the main item.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return       The index of the next checked sub-item, @n
	 *               else @c -1 if no more sub-item after the specified index is checked, or the specified sub-item does not exist
	 * @param[in]	mainIndex	The index of the main item, that the sub-item belongs to
	 * @param[in]    subIndex  The index of the sub-item in the main item
	 * @endif
	 */
	int GetNextCheckedSubItemIndexAfter(int mainIndex, int subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the sub-item with the specified @c itemId.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   itemId				The item ID
	 * @param[out]  mainIndex       	The index of the main item which the sub-item belongs to
	 * @param[out]  subIndex			The index of the sub-item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified item is not found.
	 * @remarks     Note that one or more sub-items can have the same item ID. This method returns the first sub-item among such sub-items.
	 * @endif
	 */
	result GetSubItemIndexFromItemId(int itemId, int& mainIndex, int& subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   x               	The x position of the point
	 * @param[in]   y               	The y position of the point
	 * @param[out]  mainIndex       	The index of the main item which the sub-item belongs to
	 * @param[out]  subIndex        	The index of the sub-item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result GetItemIndexFromPosition(int x, int y, int& mainIndex, int& subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified position.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   position        	The position of the point
	 * @param[out]  mainIndex       	The index of the main item which the sub-item belongs to
	 * @param[out]  subIndex        	The index of the sub-item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @endif
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& mainIndex, int& subIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the first item of the visible items in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  mainIndex   		The main index of the top drawn item
	 * @param[out]	subIndex			The sub-index of the top drawn item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     @c mainIndex is @c -1 if no item is visible. @n
	 *				@c subIndex is @c -1 if the top item drawn is a main item.
	 * @endif
	 */
	result GetTopDrawnItemIndex(int& mainIndex, int& subIndex) const;


	/**
	 * @if OSPDEPREC
	 * Gets the index of the last of the visible items in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]  mainIndex   		The main index of the bottom drawn item
	 * @param[out]	subIndex			The sub-index of the bottom drawn item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     @c mainIndex is @c -1 if no item is visible. @n
	 *				@c subIndex is @c -1 if the bottom item drawn is a main item.
	 * @endif
	 */
	result GetBottomDrawnItemIndex(int& mainIndex, int& subIndex) const;


	/**
	 * @if OSPDEPREC
	 * Sets the background color of this control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since        2.0
	 *
	 * @param[in]    color    The background color
	 * @endif
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the text to display when there is no item in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @param[in]	text	The text message to be displayed
	 * @endif
	 */
	void SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * @if OSPDEPREC
	 * Sets the color of the text to be displayed when there is no item in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since       2.0
	 *
	 * @param[in]	color	The color of the text to be displayed
	 * @endif
	 */
	void SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Gets the color of the text to be displayed when there is no item in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since       2.0
	 *
	 * @return		The color of the text to be displayed
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;


	/**
	 * @if OSPDEPREC
	 * Scrolls to the bottom of the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 * @endif
	 */
	void ScrollToBottom(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the top of the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 * @endif
	 */
	void ScrollToTop(void);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item
	 * @param[in]   subIndex        	The index of the sub-item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @exception   E_INVALID_ARG   	The specified item does not exist.
	 * @endif
	 */
	result ScrollToTop(int mainIndex, int subIndex);

	/**
	 * @if OSPDEPREC
	 * Scrolls to the main item at the specified index. @n
	 * The specified main item is drawn at the top of the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM       		A system error has occurred.
	 * @exception   E_INVALID_ARG   	The specified @c mainIndex is less than @c 0, or not less than the main item count.
	 * @endif
	 */
	result ScrollToTop(int mainIndex);

	/**
	 * @if OSPDEPREC
	 * Draws and shows the item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex       	The index of the main item
	 * @param[in]   subIndex        	The index of the sub-item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @exception   E_INVALID_OPERATION The item has never been drawn before calling this method.
	 * @exception   E_INVALID_ARG   	The specified item does not exist.
	 * @endif
	 */
	result RefreshSubItem(int mainIndex, int subIndex);

	/**
	 * @if OSPDEPREC
	 * Draws and shows the main item at the specified index in the %ExpandableList control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use GroupedTableView class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mainIndex      		The index of the main item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception   E_INVALID_OPERATION The item has never been drawn before calling this method.
	 * @exception   E_INVALID_ARG   	The specified @c mainIndex is invalid.
	 * @endif
	 */
	result RefreshItem(int mainIndex);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ExpandableList(const ExpandableList& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ExpandableList& operator =(const ExpandableList& rhs);

	friend class _ExpandableListImpl;
}; //ExpandableList

}}} // Tizen::Ui::Controls
#endif // _FUI_CTRL_EXPANDABLE_LIST_H_
