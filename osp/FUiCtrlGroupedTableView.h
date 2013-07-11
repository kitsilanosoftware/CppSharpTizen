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
 * @file FUiCtrlGroupedTableView.h
 * @brief This is the header file for the %GroupedTableView class.
 *
 * This header file contains the declarations of the %GroupedTableView class and its helper classes.
 */

#ifndef _FUI_CTRL_GROUPED_TABLE_VIEW_H_
#define _FUI_CTRL_GROUPED_TABLE_VIEW_H_

#include <FGrpRectangle.h>
#include <FGrpColor.h>
#include <FUiContainer.h>
#include <FUiCtrlTableViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
class IGroupedTableViewItemProvider;
class IGroupedTableViewItemEventListener;
class IFastScrollListener;
class IScrollEventListener;

/**
 * @class GroupedTableView
 * @brief   This class defines common behavior for a %GroupedTableView control.
 *
 * @since 2.0
 *
 * The %GroupedTableView class defines common behavior for a %GroupedTableView control.
 * @code
//Sample code for GroupedTableViewSample.h
#include <FUi.h>

class GroupedTableViewSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IGroupedTableViewItemProvider
	, public Tizen::Ui::Controls::IGroupedTableViewItemEventListener
	, public Tizen::Ui::Controls::IFastScrollListener
{
public:
	GroupedTableViewSample(void)
	: __pGroupedTableView(null)
	, __pContextItem(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IGroupedTableViewItemEventListener
	virtual void OnGroupedTableViewGroupItemStateChanged(Tizen::Ui::Controls::GroupedTableView& tableView, int groupIndex, Tizen::Ui::Controls::TableViewGroupItem* pItem, Tizen::Ui::Controls::TableViewItemStatus status);
	virtual void OnGroupedTableViewItemStateChanged(Tizen::Ui::Controls::GroupedTableView& tableView, int groupIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem, Tizen::Ui::Controls::TableViewItemStatus status);
	virtual void OnGroupedTableViewContextItemActivationStateChanged(Tizen::Ui::Controls::GroupedTableView& tableView, int groupIndex, int itemIndex, Tizen::Ui::Controls::TableViewContextItem* pContextItem, bool activated);

	// IGroupedTableViewItemProvider
	virtual int GetGroupCount(void);
	virtual int GetItemCount(int groupIndex);
	virtual Tizen::Ui::Controls::TableViewGroupItem* CreateGroupItem(int groupIndex, int itemWidth);
	virtual bool DeleteGroupItem(int groupIndex, Tizen::Ui::Controls::TableViewGroupItem* pItem);
	virtual void UpdateGroupItem(int groupIndex, Tizen::Ui::Controls::TableViewGroupItem* pItem);
	virtual Tizen::Ui::Controls::TableViewItem* CreateItem(int groupIndex, int itemIndex, int itemWidth);
	virtual bool DeleteItem(int groupIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	virtual void UpdateItem(int groupIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	virtual int GetDefaultItemHeight(void);
	virtual int GetDefaultGroupItemHeight(void);

	// IFastScrollListener
	virtual void OnFastScrollIndexSelected(Tizen::Ui::Control& source, Tizen::Base::String& index);

private:
	Tizen::Ui::Controls::GroupedTableView* __pGroupedTableView;
	Tizen::Ui::Controls::TableViewContextItem* __pContextItem;
};
 *  @endcode
 *
 *  @code

//Sample code for GroupedTableViewSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "GroupedTableViewSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Controls;

bool
GroupedTableViewSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
GroupedTableViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of TableView
	__pGroupedTableView = new GroupedTableView();
	__pGroupedTableView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), true, TABLE_VIEW_SCROLL_BAR_STYLE_FAST_SCROLL);
	__pGroupedTableView->SetItemProvider(*this);
	__pGroupedTableView->AddTableViewItemEventListener(*this);

	__pGroupedTableView->AddFastScrollListener(*this);
	__pGroupedTableView->SetFastScrollIndex(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", true);

	// Adds the TableView to the form
	AddControl(*__pGroupedTableView);

	// Creates an instance of TableViewContextItem
	__pContextItem = new TableViewContextItem();
	__pContextItem->Construct(Dimension(720, 100));

	Button* pButton = new Button();
	pButton->Construct(Rectangle(10, 10, 200, 80), L"Context1");

	Button* pButton2 = new Button();
	pButton2->Construct(Rectangle(250, 10, 200, 80), L"Context2");

	__pContextItem->AddControl(*pButton);
	__pContextItem->AddControl(*pButton2);

	return r;
}

result
GroupedTableViewSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the item context
	delete __pItemContext;
	__pItemContext = null;

	return r;
}

// IGroupedTableViewItemEventListener implementation
void
GroupedTableViewSample::OnGroupedTableViewGroupItemStateChanged(GroupedTableView& tableView, int groupIndex, TableViewGroupItem* pItem, TableViewItemStatus status)
{
	if (tableView.IsGroupExpanded(groupIndex))
	{
		tableView.CollapseGroup(groupIndex);
	}
	else
	{
		tableView.ExpandGroup(groupIndex);
	}
}

void
GroupedTableViewSample::OnGroupedTableViewItemStateChanged(GroupedTableView& tableView, int groupIndex, int itemIndex, TableViewItem* pItem, TableViewItemStatus status)
{
	// ....
}

void
GroupedTableViewSample::OnGroupedTableViewContextItemActivationStateChanged(GroupedTableView& tableView, int groupIndex, int itemIndex, TableViewContextItem* pContextItem, bool activated)
{
	// ....
}

// IFastScrollListener implementation
void
GroupedTableViewSample::OnFastScrollIndexSelected(Tizen::Ui::Control& source, Tizen::Base::String& index)
{
	// ....
}

// IGroupedTableViewItemProvider implementation
int
GroupedTableViewSample::GetGroupCount(void)
{
	return 26;
}

int
GroupedTableViewSample::GetItemCount(int groupIndex)
{
	return 10;
}

int
GroupedTableViewSample::GetDefaultItemHeight(void)
{
	return 100;
}

int
GroupedTableViewSample::GetDefaultGroupItemHeight(void)
{
	return 80;
}

TableViewGroupItem*
GroupedTableViewSample::CreateGroupItem(int groupIndex, int itemWidth)
{
	TableViewGroupItem* pItem = new TableViewGroupItem();
	pItem->Construct(Dimension(itemWidth, GetDefaultGroupItemHeight()));

	String text;
	text.Format(30, L"Group title %d", itemIndex);

	Label* pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, itemWidth, GetDefaultGroupItemHeight(), text);

	pItem->AddControl(*pLable);

	return pItem;
}

bool
GroupedTableViewSample::DeleteGroupItem(int groupIndex, TableViewGroupItem* pItem)
{
	delete pItem;

	return true;
}

void
GroupedTableViewSample::UpdateGroupItem(int groupIndex, TableViewGroupItem* pItem)
{
	// ....
}

TableViewItem*
GroupedTableViewSample::CreateItem(int groupIndex, int itemIndex, int itemWidth)
{
	TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
	TableViewItem* pItem = new TableViewItem();

	switch (itemIndex % 5)
	{
	case 0:
		style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
		break;
	case 1:
		style = TABLE_VIEW_ANNEX_STYLE_MARK;
		break;
	case 2:
		style = TABLE_VIEW_ANNEX_STYLE_ONOFF_SLIDING;
		break;
	case 3:
		style = TABLE_VIEW_ANNEX_STYLE_DETAILED;
		break;
	case 4:
		style = TABLE_VIEW_ANNEX_STYLE_RADIO;
		break;
	default:
		break;
	}

	pItem->Construct(Dimension(itemWidth, GetDefaultItemHeight()), style);

	String text;
	text.Format(30, L"TableViewItem %d", itemIndex);

	Label* pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, itemWidth, GetDefaultItemHeight(), text);

	pItem->AddControl(*pLabel);
	pItem->SetContextItem(__pContextItem);

	return pItem;
}

bool
GroupedTableViewSample::DeleteItem(int groupIndex, int itemIndex, Controls::TableViewItem* pItem)
{
	delete pItem;

	return true;
}

void
GroupedTableViewSample::UpdateItem(int groupIndex, int itemIndex, Controls::TableViewItem* pItem)
{
	// ....
}
 * @endcode
 *
 */

class _OSP_EXPORT_ GroupedTableView
	: public Tizen::Ui::Container
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. Hence, the Construct() method must be called after calling this constructor.
	 *
	 * @since 2.0
	 */
	GroupedTableView(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~GroupedTableView(void);

	/**
	 * Initializes this instance of %GroupedTableView with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] rect    An instance of the Graphics::Rectangle class
	 *                              This instance represents the x and y coordinates of the left top corner of the created %GroupedTableView along with the width and height.
	 * @param[in] itemDivider       Set to @c true to display an item divider, @n
	 *                              else @c false
	 * @param[in] scrollStyle       The style of %GroupedTableView scroll bar style
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid, or either the rect.width or rect.height parameter has a negative value.
	 *
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool itemDivider, TableViewScrollBarStyle scrollStyle);

	/**
	 * Sets the item provider that creates and deletes items for the grouped style table view.
	 *
	 * @since 2.0
	 *
	 * @param[in] pProvider                                 The item provider to create and delete items
	 * @remarks If an item provider is not set for the table view, the table view does not work. The specified provider should be allocated in heap memory.
	 *          To reset the item provider, pass @c null to @c pProvider.
	 */
	void SetItemProvider(IGroupedTableViewItemProvider* pProvider);

	/**
	 * Expands the group's items.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] groupIndex The index of the group
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	 */
	result ExpandGroup(int groupIndex);

	/**
	 * Collapses the group's items.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] groupIndex The index of the group
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE           A specified input parameter is invalid.
	 */
	result CollapseGroup(int groupIndex);

	/**
	 * Expands all groups of table view.
	 *
	 * @since 2.0
	 *
	 */
	void ExpandAllGroup(void);

	/**
	 * Collapses all groups of table view.
	 *
	 * @since 2.0
	 *
	 */
	void CollapseAllGroup(void);

	/**
	 * Returns whether the group is expanded or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the group is expanded, else @c false
	 * @param[in] groupIndex The index of the group
	 * @exception E_SUCCESS  The method is successful.
	 * @exception E_OUT_OF_RANGE           A specified input parameter is invalid.
	 */
	bool IsGroupExpanded(int groupIndex) const;

	/**
	 * Sets the grouped look is enabled.
	 *
	 * @since 2.0
	 *
	 * @param[in] enable   The enabled/disabled status
	 */
	void SetGroupedLookEnabled(bool enable);

	/**
	 * Returns whether the grouped look is enabled or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the grouped look is enabled, else @c false
	 */
	bool IsGroupedLookEnabled(void) const;

	/**
	 * Adds a listener instance that listens to state changes of table view items. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener      The event listener to add
	 * @exception E_SUCCESS                                          The method is successful.
	 * @exception E_OBJ_ALREADY_EXIST      The listener is already added.
	 * @remarks   The specified listener should be allocated in heap memory.
	 */
	result AddGroupedTableViewItemEventListener(IGroupedTableViewItemEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of table view items. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to remove
	 * @exception   E_SUCCESS                             The method is successful.
	 * @exception   E_OBJ_NOT_FOUND                  The listener is not found.
	 */
	result RemoveGroupedTableViewItemEventListener(IGroupedTableViewItemEventListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a fast scroll. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to add
	 * @exception   E_SUCCESS                             The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_OBJ_ALREADY_EXIST   The listener is already added.
	 * @remarks   The specified listener should be allocated in heap memory.
	 */
	result AddFastScrollListener(IFastScrollListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a fast scroll. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to remove
	 * @exception   E_SUCCESS                             The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_OBJ_NOT_FOUND                  The listener is not found.
	 */
	result RemoveFastScrollListener(IFastScrollListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a scroll event. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener          The event listener to add
	 * @see     IScrollEventListener::OnScrollEndReached()
	 * @see     RemoveScrollEventListener()
	 * @exception   E_SUCCESS                             The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_OBJ_ALREADY_EXIST   The listener is already added.
	 * @remarks   The specified listener should be allocated in heap memory.
	 */
	result AddScrollEventListener(IScrollEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to remove
	 * @see  IScrollEventListener::OnScrollEndReached()
	 * @see     AddScrollEventListener()
	 * @exception   E_SUCCESS                             The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_OBJ_NOT_FOUND                  The listener is not found.
	 */
	result RemoveScrollEventListener(IScrollEventListener& listener);

	/**
	 * Enables or disables the collapse by pinch gesture.
	 *
	 * @since 2.0
	 *
	 * @param[in] enable   Set to @c true to enable the collapse by pinch gesture, else @c false
	 */
	void SetCollapseByPinchGestureEnabled(bool enable);

	/**
	 * Returns whether the collapse by pinch gesture is enabled or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the collapse by pinch gesture is enabled, else @c false
	 */
	bool IsCollapseByPinchGestureEnabled(void) const;

	/**
	 * Sets the text index of the fast scroll.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] text                    The text of the index
	 * @param[in] useSearchIcon           Set to @c true to show the magnifying icon, @n
	 *                                    else @c false
	 * @exception E_SUCCESS               The method is successful.
	 * @exception E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation.
	 */
	result SetFastScrollIndex(const Tizen::Base::String& text, bool useSearchIcon);

	/**
	 * Gets the group and item indexes of the top item.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 * @param[out]  groupIndex                 The group index
	 * @param[out]  itemIndex                  The item index
	 * @exception   E_SUCCESS                  The method is successful.
	 * @exception   E_OBJ_NOT_FOUND            Top drawn item is not found.
	 */
	result GetTopDrawnItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the group and item indexes of the bottom item.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 * @param[out]  groupIndex                 The group index
	 * @param[out]  itemIndex                  The item index
	 * @exception   E_SUCCESS                  The method is successful.
	 * @exception   E_OBJ_NOT_FOUND            Bottom drawn item is not found.
	 */
	result GetBottomDrawnItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * Scrolls to the item at the specified index.
	 * The specified item is drawn at the position specified by the item alignment.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] groupIndex            The group index
	 * @param[in] itemIndex             The item index
	 * @param[in] itemAlignment         The item alignment
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	 * @remarks If the specified item. itemIndex is -1, then the method is applied to the group item with the given index.
	 */
	result ScrollToItem(int groupIndex, int itemIndex, TableViewScrollItemAlignment itemAlignment = TABLE_VIEW_SCROLL_ITEM_ALIGNMENT_TOP);

	/**
	 * Checks or unchecks the item at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] groupIndex            The group index
	 * @param[in] itemIndex             The item index
	 * @param[in] check    Set to @c true to select the item, @n
	 *         else @c false
	 * @exception E_SUCCESS   The method is successful.
	 * @exception E_OUT_OF_RANGE           A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION     The item is disabled.
	 * @remarks This method works only when the annex style of the item allows selection.
	 */
	result SetItemChecked(int groupIndex, int itemIndex, bool check);

	/**
	 * Returns whether the item at the specified index is selected or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the item is selected, @n
	 *   else @c false
	 * @param[in] groupIndex            The group index
	 * @param[in] itemIndex             The item index
	 * @exception E_SUCCESS                               The method is successful.
	 * @exception E_OUT_OF_RANGE A specified input parameter is invalid.
	 * @remarks This method returns @c false, if the annex style of the item does not allow selection.
	*/
	bool IsItemChecked(int groupIndex, int itemIndex) const;

	/**
	 * Enables or disables the item at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] groupIndex            The group index
	 * @param[in] itemIndex             The item index
	 * @param[in] enable    Set to @c true to enable the specified item, @n
	 *         else @c false
	 * @exception E_SUCCESS   The method is successful.
	 * @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	 */
	result SetItemEnabled(int groupIndex, int itemIndex, bool enable);

	/**
	 * Returns whether the item at the specified index is enabled or disabled.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the item is enabled, @n
	 *   else @c false
	 * @param[in] groupIndex            The group index
 	 * @param[in] itemIndex             The item index
	 * @exception E_SUCCESS                               The method is successful.
	 * @exception E_OUT_OF_RANGE A specified input parameter is invalid.
	 */
	bool IsItemEnabled(int groupIndex, int itemIndex) const;

	/**
	 * Counts the total number of groups.
	 *
	 * @since 2.0
	 *
	 * @return The total number of groups
	 */
	int GetGroupCount(void) const;

	/**
 	 * Counts all the items of the specified group.
	 *
	 * @since 2.0
	 *
	 * @return The total number of items in the specified group
	 * @param[in] groupIndex   The group index
	 * @exception E_SUCCESS                               The method is successful.
	 * @exception E_OUT_OF_RANGE A specified input parameter is invalid.
	 */
	int GetItemCountAt(int groupIndex) const;

	/**
	 * Updates the specified item. @n
	 * For instance, TABLE_VIEW_REFRESH_TYPE_ITEM_ADD is used when a new item needs to be added and TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE is used when an item is deleted from the
	 * table view. Moreover, TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY is used when the content of an existing item has changed and it needs to be updated.
	 * Note that calling this method with TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY invokes item provider's UpdateItem() for the given index in sequence.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] groupIndex                    The group index
	 * @param[in] itemIndex           The item index
	 * @param[in] type                             The item to be added, removed, or modified
	 * @exception E_SUCCESS   The method is successful.
	 * @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	 * @remarks If the specified item. itemIndex is -1, then the method is applied to the group item with the given index.
	 *   Note that if TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE option is used to a group item, all the items in the group (including the group item itself) are
	 *   removed from the table view.
	 */
	result RefreshItem(int groupIndex, int itemIndex, TableViewRefreshType type);

	/**
	 * Updates all the items of a table view.
	 *
	 * @since 2.0
	 *
	 * @remarks This method clears all the items in the table view and invokes the methods of the item provider again to update the table view.
	 */
	void UpdateTableView(void);

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since 2.0
	 *
	 * @param[in] position    The position of the item
	 * @param[out] groupIndex The group index of the item on specified position
	 * @param[out] itemIndex  The item index of the item on specified position
	 * @remarks This method sets both of groupIndex and itemIndex to -1 if no item is found at the given position.
	 */
	void GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& groupIndex, int& itemIndex) const;

	/**
	 * Sets the color of a division line between items.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] color    The division line color
	 */
	void SetItemDividerColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of a division line between items.
	 *
	 * @since 2.0
	 *
	 * @return  The color of a division line
	 */
	Tizen::Graphics::Color GetItemDividerColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since 2.0
	 *
	 * @param[in] color       The background color
	 * @remarks The background bitmap has priority over the background color. When both the background bitmap and the background color are specified,
	 *   only the bitmap image is displayed.
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the scroll input handling mode.
	 *
	 * @since 2.0
	 *
	 * @param[in] mode  The scroll input handling mode
	 * @see         GetScrollInputMode()
	 */
	void SetScrollInputMode(ScrollInputMode mode);

	/**
	 * Gets the scroll input handling mode.
	 *
	 * @since 2.0
	 *
	 * @return     The scroll input handling mode
	 * @see         SetScrollInputMode()
	 */
	ScrollInputMode GetScrollInputMode(void) const;

	/**
	 * Gets the background color of this control.
	 *
	 * @since 2.0
	 *
	 * @return The background color
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/*
	 * Scrolls the list contents with the amount of pixels.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in]   pixel					 The amount of pixels to scroll
	 * @exception   E_SUCCESS			 The method is successful.
	 * @exception   E_OUT_OF_RANGE	 The specified @c pixel is out of range.
	 * @remarks If you call ScrollByPixel() with negative @c pixel when position of scroll is already top of contents then it will return E_OUT_OF_RANGE.
	 *			   Likewise, in case of positive @c pixel on the bottom position of scroll it will also return E_OUT_OF_RANGE.
	 */
	result ScrollByPixel(int pixel);

	/*
	 * Gets the current scroll position
	 *
	 * @since 2.0
	 */
	int GetCurrentScrollPosition(void) const;

	/*
	 * Enables or disables the scroll of GroupedTableView items.
	 *
	 * @since 2.0
	 */
	void SetScrollEnabled(bool enable);

	/*
	 * Checks whether the scroll is enabled or disabled.
	 *
	 * @since 2.0
	 */
	bool IsScrollEnabled(void) const;

private:
	friend class _TableViewImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	GroupedTableView(const GroupedTableView& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	GroupedTableView& operator =(const GroupedTableView& rhs);
}; // GroupedTableView

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_GROUPED_TABLE_VIEW_H_
