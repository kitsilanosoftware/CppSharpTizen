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
* @file FUiCtrlTableView.h
* @brief This is the header file for the %TableView class.
*
* This header file contains the declarations of the %TableView class and its helper classes.
*/

#ifndef _FUI_CTRL_TABLE_VIEW_H_
#define _FUI_CTRL_TABLE_VIEW_H_

#include <FGrpRectangle.h>
#include <FGrpColor.h>
#include <FUiContainer.h>
#include <FUiCtrlTableViewTypes.h>
#include <FUiCtrlScrollPanelTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
class ITableViewItemProvider;
class ITableViewItemProviderF;
class ITableViewItemEventListener;
class IFastScrollListener;
class IScrollEventListener;
class IScrollEventListenerF;

/**
 * @class TableView
 * @brief   This class defines common behavior for a %TableView control.
 *
 * @since 2.0
 *
 * The %TableView class defines common behavior for a %TableView control.
 *
 * The following example demonstrates how to use the %TableView class.
 *
 * @code
//Sample code for TableViewSample.h
#include <FUi.h>

class TableViewSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::ITableViewItemProvider
	, public Tizen::Ui::Controls::ITableViewItemEventListener
{
public:
	TableViewSample(void)
	: __pTableView(null)
	, __pContextItem(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// ITableViewItemEventListener
	virtual void OnTableViewItemStateChanged(Tizen::Ui::Controls::TableView& tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem, Tizen::Ui::Controls::TableViewItemStatus status);
	virtual void OnTableViewContextItemActivationStateChanged(Tizen::Ui::Controls::TableView& tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem* pContextItem, bool activated);
	virtual void OnTableViewItemReordered(Tizen::Ui::Controls::TableView& tableView, int itemIndexFrom, int itemIndexTo);

	// ITableViewItemProvider
	virtual int GetItemCount(void);
	virtual Tizen::Ui::Controls::TableViewItem* CreateItem(int itemIndex, int itemWidth);
	virtual bool DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	virtual void UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	virtual int GetDefaultItemHeight(void);

private:
	Tizen::Ui::Controls::TableView* __pTableView;
	Tizen::Ui::Controls::TableViewContextItem* __pContextItem;
};
 *	@endcode
 *
 *	@code
//Sample code for TableViewSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "TableViewSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Controls;

bool
TableViewSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
TableViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of TableView
	__pTableView = new TableView();
	__pTableView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), true, TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);
	__pTableView->SetItemProvider(*this);
	__pTableView->AddTableViewItemEventListener(this);

	// Adds the TableView to the form
	AddControl(__pTableView);

	// Creates an instance of TableViewContextItem
	__pContextItem = new TableViewContextItem();
	__pContextItem->Construct(Dimension(720, 100));

	Button* pButton = new Button();
	pButton->Construct(Rectangle(10, 10, 200, 80), L"Context1");

	Button* pButton2 = new Button();
	pButton2->Construct(Rectangle(250, 10, 200, 80), L"Context2");

	__pContextItem->AddControl(pButton);
	__pContextItem->AddControl(pButton2);

	return r;
}

result
TableViewSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the item context
	delete __pContextItem;
	__pContextItem = null;

	return r;
}

// ITableViewItemEventListener implementation
void
TableViewSample::OnTableViewItemStateChanged(TableView& tableView, int itemIndex, TableViewItem* pItem, TableViewItemStatus status)
{
	// ....
}

void
TableViewSample::OnTableViewContextItemActivationStateChanged(TableView& tableView, int itemIndex, TableViewContextItem* pContextItem, bool activated)
{
	// ....
}

void
TableViewSample::OnTableViewItemReordered(Tizen::Ui::Controls::TableView& tableView, int itemIndexFrom, int itemIndexTo)
{
	// ....
}

// ITableViewItemProvider implementation
int
TableViewSample::GetItemCount(void)
{
	return 50;
}

int
TableViewSample::GetDefaultItemHeight(void)
{
	return 100;
}

TableViewItem*
TableViewSample::CreateItem(int itemIndex, int itemWidth)
{
	TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
	TableViewItem* pItem = new TableViewItem();

	switch (itemIndex % 6)
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
	case 5:
		style = TABLE_VIEW_ANNEX_STYLE_ONOFF_SLIDING_WITH_DIVIDER;
		break;
	default:
		break;
	}

	pItem->Construct(Dimension(itemWidth, GetDefaultItemHeight()), style);

	String text;
	text.Format(30, L"TableViewItem %d", itemIndex);

	Label* pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, itemWidth, GetDefaultItemHeight()), text);

	pItem->AddControl(pLabel);
	pItem->SetContextItem(__pContextItem);

	return pItem;
}

bool
TableViewSample::DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
	pItem->Destroy();

	return true;
}

void
TableViewSample::UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
	// ....
}
 * @endcode
 *
 */

class _OSP_EXPORT_ TableView
	: public Tizen::Ui::Container
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the %Construct() method must be called right after calling this constructor.
	*
	* @since 2.0
	*/
	TableView(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~TableView(void);

	/**
	* Initializes this instance of %TableView with the specified parameters.
	*
	* @since 2.0
	*
	* @return  An error code
	* @param[in] rect    An instance of the Graphics::Rectangle class
	*                              This instance represents the x and y coordinates of the left top corner of the created %TableView along with the width and height.
	* @param[in] itemDivider       Set to @c true to display an item divider, @n
	*                              else @c false
	* @param[in] scrollStyle       The style of %TableView scroll bar style
	* @exception E_SUCCESS         The method is successful.
	* @exception E_INVALID_ARG     A specified input parameter is invalid, or either the rect.width or rect.height parameter has a negative value.
	*
	*/
	result Construct(const Tizen::Graphics::Rectangle& rect, bool itemDivider, TableViewScrollBarStyle scrollStyle);

	/**
	* Initializes this instance of %TableView with the specified parameters.
	*
	* @since 2.1
	*
	* @return  An error code
	* @param[in] rect    An instance of the Tizen::Graphics::FloatRectangle class @n
	*                              This instance represents the x and y coordinates of the left top corner of the created %TableView along with the width and height.
	* @param[in] itemDivider       Set to @c true to display an item divider, @n
	*                              else @c false
	* @param[in] scrollStyle       The style of %TableView scroll bar style
	* @exception E_SUCCESS         The method is successful.
	* @exception E_INVALID_ARG     A specified input parameter is invalid, or either the @c rect.width or @c rect.height parameter has a negative value.
	*
	*/
	result Construct(const Tizen::Graphics::FloatRectangle& rect, bool itemDivider, TableViewScrollBarStyle scrollStyle);

	/**
	* Sets the item provider that creates and deletes items for the simple style table view.
	*
	* @since 2.0
	*
	* @param[in] pProvider		The item provider to create and delete items
	* @remarks
	*				- If an item provider is not set for the table view, the table view does not work.
	*				- The specified provider should be allocated in heap memory.
	*				- To reset the item provider, pass @c null to @c pProvider.
	*/
	void SetItemProvider(ITableViewItemProvider* pProvider);

	/**
	* Sets the item provider that creates and deletes items for the simple style table view.
	*
	* @since 2.1
	*
	* @param[in] pProvider		The item provider to create and delete items
	* @remarks
	*				- If an item provider is not set for the table view, the table view does not work.
	*				- The specified provider should be allocated in heap memory.
	*				- To reset the item provider, pass @c null to @c pProvider.
	*/
	void SetItemProviderF(ITableViewItemProviderF* pProvider);

	/**
	* Begins the reordering mode.
	*
	* @since 2.0
	*
	* @see    ITableViewViewItemEventListener::OnTableViewItemReordered()
	*/
	void BeginReorderingMode(void);

	/**
	* Ends the reordering mode.
	*
	* @since 2.0
	*
	* @see    ITableViewViewItemEventListener::OnTableViewItemReordered()
	*/
	void EndReorderingMode(void);

	/**
	* Returns whether the %TableView control is in reordering mode or not.
	*
	* @since 2.0
	*
	* @return        @c true if the %TableView is in reordering mode, @n
	*                   else @c false
	*/
	bool IsInReorderingMode(void) const;

	/**
	* Adds a listener instance that listens to state changes of table view items. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] listener               The event listener to add
	* @exception E_SUCCESS                                The method is successful.
	* @exception E_OBJ_ALREADY_EXIST       The listener is already added.
	* @remarks   The specified listener should be allocated in heap memory.
	*/
	result AddTableViewItemEventListener(ITableViewItemEventListener& listener);

	/**
	* Removes a listener instance that listens to state changes of table view items. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] listener     The event listener to remove
	* @exception    E_SUCCESS                             The method is successful.
	* @exception    E_OBJ_NOT_FOUND        The listener is not found.
	*/
	result RemoveTableViewItemEventListener(ITableViewItemEventListener& listener);

	/**
	* Adds a listener instance that listens to state changes of a fast scroll. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] listener     The event listener to add
	* @exception    E_SUCCESS                             The method is successful.
	* @exception    E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @exception    E_OBJ_ALREADY_EXIST The listener is already added.
	* @remarks   The specified listener should be allocated in heap memory.
	*/
	result AddFastScrollListener(IFastScrollListener& listener);

	/**
	* Removes a listener instance that listens to state changes of a fast scroll. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] listener     The event listener to remove
	* @exception    E_SUCCESS                             The method is successful.
	* @exception    E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @exception    E_OBJ_NOT_FOUND        The listener is not found.
	*/
	result RemoveFastScrollListener(IFastScrollListener& listener);

	/**
	* Adds a listener instance that listens to state changes of a scroll event. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] listener                          The event listener to add
	* @exception	E_SUCCESS                             The method is successful.
	* @exception	E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @exception	E_OBJ_ALREADY_EXIST The listener is already added.
	* @remarks   The specified listener should be allocated in heap memory.
	* @see			IScrollEventListener::OnScrollEndReached()
	* @see			RemoveScrollEventListener()
	*/
	result AddScrollEventListener(IScrollEventListener& listener);

	/**
	* Removes a listener instance that listens to state changes of a scroll event. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] listener     The event listener to remove
	* @exception    E_SUCCESS                             The method is successful.
	* @exception    E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @exception    E_OBJ_NOT_FOUND        The listener is not found.
	* @see  IScrollEventListener::OnScrollEndReached()
	* @see           AddScrollEventListener()
	*/
	result RemoveScrollEventListener(IScrollEventListener& listener);

	/**
	* Adds a listener instance that listens to state changes of a scroll event. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since 2.1
	*
	* @return        An error code
	* @param[in] listener                          The event listener to add
	* @exception	E_SUCCESS                             The method is successful.
	* @exception	E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @exception	E_OBJ_ALREADY_EXIST The listener is already added.
	* @remarks   The specified listener should be allocated in heap memory.
	* @see			IScrollEventListenerF::OnScrollEndReached()
	* @see			RemoveScrollEventListenerF()
	*/
	result AddScrollEventListener(IScrollEventListenerF& listener);

	/**
	* Removes a listener instance that listens to state changes of a scroll event. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since 2.1
	*
	* @return        An error code
	* @param[in] listener     The event listener to remove
	* @exception    E_SUCCESS                             The method is successful.
	* @exception    E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @exception    E_OBJ_NOT_FOUND        The listener is not found.
	* @see  IScrollEventListenerF::OnScrollEndReached()
	* @see           AddScrollEventListenerF()
	*/
	result RemoveScrollEventListener(IScrollEventListenerF& listener);

	/**
	* Sets the index table view of the scroll by texts.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in] text                                         The text of the index
	* @param[in] useSearchIcon  Set to @c true to show the magnifying icon, @n
	*                                                                                   else @c false
	* @exception E_SUCCESS                     The method is successful.
	* @exception E_INVALID_ARG     A specified input parameter is invalid.
	* @exception E_INVALID_OPERATION      The current state of the instance prohibits the execution of the specified operation.
	*/
	result SetFastScrollIndex(const Tizen::Base::String& text, bool useSearchIcon);

	/**
	* Gets the group and item indexes of the top item.
	*
	* @since 2.0
	*
	* @return        The item index
	* @exception    E_SUCCESS                   The method is successful.
	* @exception    E_OBJ_NOT_FOUND             Top drawn item is not found.
	*/
	int GetTopDrawnItemIndex(void) const;

	/**
	* Gets the group and item indexes of the bottom item.
	*
	* @since 2.0
	*
	* @return        The item index
	* @exception    E_SUCCESS                   The method is successful.
	* @exception    E_OBJ_NOT_FOUND             Bottom drawn item is not found.
	*/
	int GetBottomDrawnItemIndex(void) const;

	/**
	* Scrolls to the item at the specified index.
	* The specified item is drawn at the position specified by the item alignment.
	*
	* @since 2.0
	*
	* @return  An error code
	* @param[in] itemIndex             The targeted item index
	* @param[in] itemAlignment         The item alignment
	* @exception E_SUCCESS             The method is successful.
	* @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	* @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @b Since: @b 2.1
	* @remarks
	*			- This method does not work inside the ITableViewItemProvider callback.
	*			- This method should be called only after %TableView items are created. If this method needs to be called early in the lifecycle of
	*			the %TableView, then UpdateTableView() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	result ScrollToItem(int itemIndex, TableViewScrollItemAlignment itemAlignment = TABLE_VIEW_SCROLL_ITEM_ALIGNMENT_TOP);

	/**
	* Checks or unchecks the item at the specified index.
	*
	* @since 2.0
	*
	* @return  An error code
	* @param[in] itemIndex  The item index to check
	* @param[in] check    Set to @c true to select the item, @n
	*         else @c false
	* @exception E_SUCCESS   The method is successful.
	* @exception E_OUT_OF_RANGE            A specified input parameter is invalid.
	* @exception E_INVALID_OPERATION      The item is disabled or the current state of the instance prohibits the execution of the specified operation.
	* @remarks
	*			- This method works only when the annex style of the item allows selection.
	* 			- This method does not work during the ITableViewItemProvider call-back procedure.
	*			- This method should be called only after %TableView items are created. If this method needs to be called early in the lifecycle of
	*			the %TableView, then UpdateTableView() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	result SetItemChecked(int itemIndex, bool check);

	/**
	* Returns whether the item at the specified index is selected or not.
	*
	* @since 2.0
	*
	* @return @c true if the item is selected, @n
	*   else @c false
	* @param[in] itemIndex  The item itemIndex
	* @exception E_SUCCESS                                The method is successful.
	* @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	* @remarks
	*			- This method returns @c false, if the annex style of the item does not allow selection.
	*			- This method should be called only after %TableView items are created. If this method needs to be called early in the lifecycle of
	*			the %TableView, then UpdateTableView() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	bool IsItemChecked(int itemIndex) const;

	/**
	* Enables or disables the item at the specified index.
	*
	* @since 2.0
	*
	* @return An error code
	* @param[in] itemIndex  The item index
	* @param[in] enable    Set to @c true to enable the specified item, @n
	*         else @c false
	* @exception E_SUCCESS   The method is successful.
	* @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	* @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @b Since: @b 2.1
	* @remarks
	*			- This method does not work during the ITableViewItemProvider call-back procedure.
	*			- This method should be called only after %TableView items are created. If this method needs to be called early in the lifecycle of
	*			the %TableView, then UpdateTableView() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	result SetItemEnabled(int itemIndex, bool enable);

	/**
	* Returns whether the item at the specified index is enabled or disabled.
	*
	* @since 2.0
	*
	* @return @c true if the item is enabled, @n
	*   else @c false
	* @param[in] itemIndex  The item index
	* @exception E_SUCCESS                                The method is successful.
	* @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	* @remarks
	*				- This method should be called only after %TableView items are created.
	*				- If this method needs to be called early in the lifecycle of the
	*				%TableView, then UpdateTableView() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	bool IsItemEnabled(int itemIndex) const;

	/**
	* Counts all the items of the specified group.
	*
	* @since 2.0
	*
	* @return The total number of items
	*/
	int GetItemCount(void) const;

	/**
	* Updates the specified item. @n
	* For instance, @c TABLE_VIEW_REFRESH_TYPE_ITEM_ADD is used when a new item needs to be added and
	* @c TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE is used when an item is deleted from the
	* table view. Moreover, @c TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY is used when the content of an existing item has changed and it
	* needs to be updated. @n
	* Note that calling the %RefreshAllItems() method with @c TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY invokes
	* ITableViewItemProvider::UpdateItem() or ITableViewItemProviderF::UpdateItem() for the given index in sequence.
	*
	* @since 2.0
	*
	* @return An error code
	* @param[in] itemIndex  The item index
	* @param[in] type                The item to add, remove, or modify
	* @exception E_SUCCESS   The method is successful.
	* @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	* @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @b Since: @b 2.1
	* @remarks 	This method does not work during the ITableViewItemProvider call-back procedure.
	*/
	result RefreshItem(int itemIndex, TableViewRefreshType type);

	/**
	* Updates all items of the table view. @n
	* Note that calling the %RefreshAllItems() method invokes ITableViewItemProvider::UpdateItem() or ITableViewItemProviderF::UpdateItem() for all loaded items.
	*
	* @since 2.1
	*
	* @return An error code
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_OPERATION The %TableView item provider is processing the other request.
	*/
	result RefreshAllItems(void);

	/**
	* Updates all the items of a table view. @n
	* This method deletes all the items in the table view and invokes the methods of the item provider again to update the table view.
	*
	* @since 2.0
	*
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @b Since: @b 2.1
	* @remarks
	*			- This method will delete all the items and recreate them, so it should not be called from the inside of
	*			OnTableViewItemStateChanged() call-back as this leads to self deletion. If you need to update an Item, you should use RefreshItem() method.
	*			- This method should not be called from ITableViewItemProvider implementation because of recursion.
	*			- The specific error code can be accessed using the GetLastResult() method.
	*/
	void UpdateTableView(void);

	/**
	* Gets the index of the item at the specified position.
	*
	* @since 2.0
	*
	* @return  The item index of the item on specified position
	* @param[in] position   The position of the item
	* @remarks
	*				- This method returns @c -1 if no item is found at the given position.
	*				- This method should be called only after %TableView items are created.
	*				- If this method needs to be called early in the lifecycle of the %TableView,
	*				then UpdateTableView() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	int GetItemIndexFromPosition(const Tizen::Graphics::Point& position) const;

	/**
	* Gets the index of the item at the specified position.
	*
	* @since 2.1
	*
	* @return  The item index of the item on specified position
	* @param[in] position   The position of the item
	* @remarks
	*				- This method returns @c -1 if no item is found at the given position.
	*				- This method should be called only after %TableView items are created.
	**				- If this method needs to be called early in the lifecycle of the %TableView, then UpdateTableView() method should be called
	*				explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	*/
	int GetItemIndexFromPosition(const Tizen::Graphics::FloatPoint& position) const;

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
	* @return        The color of a division line
	*/
	Tizen::Graphics::Color GetItemDividerColor(void) const;

	/**
	* Sets the background color of this control.
	*
	* @since 2.0
	*
	* @param[in] color          The background color
	* @remarks The background bitmap has priority over the background color. When both the background bitmap and the background color are specified,
	*        only the bitmap image is displayed.
	*/
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	* Gets the background color of this control.
	*
	* @since 2.0
	*
	* @return The background color
	*/
	Tizen::Graphics::Color GetBackgroundColor(void) const;

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
	* Scrolls the list contents by a specified number of pixels. @n When it is negative, it scrolls to opposite direction in current scroll style.
	*
	* @since 2.1
	*
	* @return  An error code
	* @param[in]   pixel						The amount of pixels to scroll
	* @exception   E_SUCCESS				The method is successful.
	* @exception   E_OUT_OF_RANGE		The specified @c pixel is out of range.
	* @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @remarks
	*				- If you call this method with negative @c pixel when position of scroll is already top of contents then
	*				it will return @c E_OUT_OF_RANGE. @n
	*				Likewise, in case of positive @c pixel on the bottom position of scroll it will also return @c E_OUT_OF_RANGE.
	*				- This method does not work during the ITableViewItemProvider call-back procedure.
	*/
	result ScrollByPixel(int pixel);

	/**
	* Scrolls the list contents by a specified number of pixels. @n When it is negative, it scrolls to opposite direction in current scroll style.
	*
	* @since 2.1
	*
	* @return  An error code
	* @param[in]   pixel						The amount of pixels to scroll
	* @exception   E_SUCCESS				The method is successful.
	* @exception   E_OUT_OF_RANGE		The specified @c pixel is out of range.
	* @exception E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	* @remarks
	*				- If you call this method with negative @c pixel when position of scroll is already top of contents then it will
	*				return @c E_OUT_OF_RANGE. @n
	*				Likewise, in case of positive @c pixel on the bottom position of scroll it will also return @c E_OUT_OF_RANGE.
	*				- This method does not work during the ITableViewItemProvider call-back procedure.
	*/
	result ScrollByPixel(float pixel);

	/**
	* Gets the current scroll position.
	*
	* @since 2.1
	*/
	int GetCurrentScrollPosition(void) const;

	/**
	* Gets the current scroll position.
	*
	* @since 2.1
	*/
	float GetCurrentScrollPositionF(void) const;

	/*
	* Enables or disables the scroll of %TableView items.
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

	/**
	* Opens the context item at a specified index.
	*
	* @since 2.1
	*
	* @return  An error code
	* @param[in] itemIndex	The item index
	* @exception E_SUCCESS	 The method is successful.
	* @exception E_OUT_OF_RANGE 		   The specified input parameter is invalid.
	* @exception E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	*/
	result OpenContextItem(int itemIndex);

	/**
	* Closes the context item at a specified index.
	*
	* @since 2.1
	*
	* @return  An error code
	* @param[in] itemIndex	The item index
	* @exception E_SUCCESS	 The method is successful.
	* @exception E_OUT_OF_RANGE 		   The specified input parameter is invalid.
	* @exception E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	*/
	result CloseContextItem(int itemIndex);

	/**
	* Checks whether the context item at a specified index is opened.
	*
	* @since 2.1
	*
	* @return @c true if the context item is opened, @n
	*         else @c false
	* @param[in] itemIndex	The item index
	* @exception E_SUCCESS		 The method is successful.
	* @exception E_OUT_OF_RANGE  The specified input parameter is invalid.
	*/
	bool IsContextItemOpened(int itemIndex) const;

private:
	friend class _TableViewImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableView(const TableView& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableView& operator =(const TableView& rhs);
}; // TableView

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_TABLE_VIEW_H_
