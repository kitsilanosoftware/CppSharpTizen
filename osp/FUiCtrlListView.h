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
 * @file	FUiCtrlListView.h
 * @brief	This is the header file for the %ListView class.
 *
 * This header file contains the declarations of the %ListView class and its helper classes.
 */

#ifndef _FUI_CTRL_LIST_VIEW_H_
#define _FUI_CTRL_LIST_VIEW_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpRectangle.h>
#include <FUiContainer.h>
#include <FUiControl.h>
#include <FUiCtrlIFastScrollListener.h>
#include <FUiCtrlIListViewItemEventListener.h>
#include <FUiCtrlIListViewItemProvider.h>
#include <FUiCtrlIScrollEventListener.h>
#include <FUiCtrlListViewTypes.h>
#include <FUiIUiLinkEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _ListViewImpl;

/**
 * @class	ListView
 * @brief   This class defines common behavior for a %ListView control.
 *
 * @since	2.0
 *
 * The %ListView class displays a list of simple and user-configured items. A simple item has a fixed layout consisting of a bitmap
 * and a text string. A user-configured item in a %ListView instance can have a different layout and height than the other items.
 * Each user-configured item is composed of elements that can be texts and bitmaps, and is configured using the CustomItem class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 * The following example demonstrates how to use the %ListView class.
 *
 *
 * @code
//Sample code for ListViewSample.h
#include <FUi.h>

class ListViewSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IListViewItemEventListener
	, public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	ListViewSample(void)
	: __pListView(null)
	, __pItemContext(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IListViewItemEventListener
	virtual void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	virtual void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	// IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	virtual int GetItemCount(void);

private:
	static const int ID_FORMAT_STRING = 100;
	static const int ID_FORMAT_BITMAP = 101;
	static const int ID_CONTEXT_ITEM_1 = 103;
	static const int ID_CONTEXT_ITEM_2 = 104;

	Tizen::Graphics::Bitmap* __pHome;
	Tizen::Graphics::Bitmap* __pMsg;
	Tizen::Graphics::Bitmap* __pAlarm;
	Tizen::Graphics::Bitmap* __pCall;

	Tizen::Ui::Controls::ListView* __pListView;
	Tizen::Ui::Controls::ListContextItem* __pItemContext;
};
 *	@endcode
 *
 *	@code
//Sample code for ListViewSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "ListViewSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Controls;

bool
ListViewSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ListViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of ListView
	__pListView = new ListView();
	__pListView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), true, false);
	__pListView->SetItemProvider(*this);
	__pListView->AddListViewItemEventListener(*this);

	// Adds the list view to the form
	AddControl(*__pListView);

	// Creates an instance of ListContextItem
	__pItemContext = new ListContextItem();
	__pItemContext->Construct();
	__pItemContext->AddElement(ID_CONTEXT_ITEM_1, L"Test1");
	__pItemContext->AddElement(ID_CONTEXT_ITEM_2, L"Test2");

	// Gets instances of Bitmap
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	__pHome = pAppResource->GetBitmapN(L"tizen.png");
	__pMsg = pAppResource->GetBitmapN(L"tizen.png");
	__pAlarm = pAppResource->GetBitmapN(L"tizen.png");
	__pCall = pAppResource->GetBitmapN(L"tizen.png");

	return r;
}

result
ListViewSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates bitmaps
	delete __pHome;
	delete __pMsg;
	delete __pAlarm;
	delete __pCall;

	// Deallocates the item context
	delete __pItemContext;

	return r;
}

// IListViewItemEventListener implementation
void
ListViewSample::OnListViewItemStateChanged(ListView &listView, int index, int elementId, ListItemStatus status)
{
	switch (elementId)
	{
	case ID_FORMAT_BITMAP:
		{
			// ....
		}
		break;
	case ID_FORMAT_STRING:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
ListViewSample::OnListViewContextItemStateChanged(ListView &listView, int index, int elementId, ListContextItemStatus state)
{
	switch (elementId)
	{
	case ID_CONTEXT_ITEM_1:
		{
			// ....
		}
		break;
	case ID_CONTEXT_ITEM_2:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
ListViewSample::OnListViewItemSwept(ListView &listView, int index, SweepDirection direction)
{
	// ....
}

// IListViewItemProvider implementation
ListItemBase*
ListViewSample::CreateItem(int index, int itemWidth)
{
	// Creates an instance of CustomItem
	CustomItem* pItem = new CustomItem();
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

	switch (index % 4)
	{
	case 0:
		{
			style = LIST_ANNEX_STYLE_NORMAL;
			pItem->Construct(Dimension(itemWidth,112), style);
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pHome, null, null);
			pItem->AddElement(Rectangle(80, 25, 150, 50), ID_FORMAT_STRING, L"Home", true);
		}
		break;
	case 1:
		{
			style = LIST_ANNEX_STYLE_DETAILED;
			pItem->Construct(Dimension(itemWidth,112), style);
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pMsg, null, null);
			pItem->AddElement(Rectangle(80, 25, 150, 50), ID_FORMAT_STRING, L"Msg", true);
		}
		break;
	case 2:
		{
			style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
			pItem->Construct(Dimension(itemWidth,112), style);
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pAlarm, null, null);
			pItem->AddElement(Rectangle(80, 25, 150, 50), ID_FORMAT_STRING, L"Alarm", true);
		}
		break;
	case 3:
		{
			style = LIST_ANNEX_STYLE_MARK;
			pItem->Construct(Dimension(itemWidth,112), style);
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pCall, null, null);
			pItem->AddElement(Rectangle(80, 25, 150, 50), ID_FORMAT_STRING, L"Call", true);
		}
		break;
	default:
		break;
	}

	pItem->SetContextItem(__pItemContext);

	return pItem;
}

bool
ListViewSample::DeleteItem(int index, ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

int
ListViewSample::GetItemCount(void)
{
	return 15;
}
 * @endcode
 *
 */
class _OSP_EXPORT_ ListView
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is
	 * called. For full construction, the Construct() method must be
	 * called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	ListView(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ListView(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %ListView with the specified parameters.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated.
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] rect				An instance of the Graphics::Rectangle class @n
	 *								This instance represents the x and y coordinates of the left top corner of the created %ListView along with the width
	 *								and height.
	 * @param[in] itemDivider       Set to @c true to display an item divider, @n
	 *								else @c false
	 * @param[in] fastScroll        Set to @c true to use fast scroll, @n
	 *                              else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid. @n
	 *  							Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool itemDivider = true, bool fastScroll = false);

	/**
	 * Initializes this instance of %ListView with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] rect              An instance of the Graphics::Rectangle class @n
	 *								This instance represents the x and y coordinates of the left top corner of the created %ListView along with the width
	 *								and height.
	 * @param[in] itemDivider       Set to @c true to display an item divider, @n
	 *								else @c false
	 * @param[in] scrollStyle       Set to scroll style
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid. @n
	 *  							Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool itemDivider, ListScrollStyle scrollStyle);

	/**
	 * Sets the item provider that creates and deletes items for the list.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] provider          The item provider to create and delete items
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks  If an item provider is not set for the list, the list does not work. @n
	 *			The specified @c provider should be allocated in heap memory.
	 */
	result SetItemProvider(IListViewItemProvider& provider);


	/**
	 * Adds a listener instance that listens to state changes of list view items. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener		    The event listener to add
	 */
	void AddListViewItemEventListener(IListViewItemEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of list view items. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener			The event listener to remove
	 */
	void RemoveListViewItemEventListener(IListViewItemEventListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a fast scroll. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener			The event listener to add
	 */
	void AddFastScrollListener(IFastScrollListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a fast scroll. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener			The event listener to remove
	 */
	void RemoveFastScrollListener(IFastScrollListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a scroll event. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener          The event listener to add
	 * @see     IScrollEventListener::OnScrollEndReached()
	 * @see     RemoveScrollEventListener()
	 */
	void AddScrollEventListener(IScrollEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener			The event listener to remove
	 * @see		IScrollEventListener::OnScrollEndReached()
	 * @see     AddScrollEventListener()
	 */
	void RemoveScrollEventListener(IScrollEventListener& listener);

	/**
	 * Adds a link event listener.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener          The event listener to add
	 * @remarks  The added listener is notified when a link is selected by the user.
	 * @see     RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in] listener          The event listener to remove
	 * @see     AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Sets the sweep event to enable.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] enable			Set to @c true to enable the sweep, @n
	 *								else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetSweepEnabled(bool enable);

	/**
	 * Sets the index list of the scroll by texts.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] text              The text of the index
	 * @param[in] useSearchIcon		Set to @c true to show the magnifying icon, @n
	 *                              else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetFastScrollIndex(const Tizen::Base::String& text, bool useSearchIcon);

	/**
	 * Gets the index of the top drawn item of the %ListView control.
	 *
	 * @since	2.0
	 *
	 * @return  The index of the top drawn item
	 */
	int GetTopDrawnItemIndex(void) const;

	/**
	 * Gets the index of the bottom drawn item of the %ListView control.
	 *
	 * @since	2.0
	 *
	 * @return  The index of the bottom drawn item
	 */
	int GetBottomDrawnItemIndex(void) const;

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %ListView control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] index				The item index
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    The specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result ScrollToItem(int index);

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the position specified by the item alignment.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] index             The item index
	 * @param[in] itemAlignment		The item alignment
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result ScrollToItem(int index, ListScrollItemAlignment itemAlignment);

	/**
	 * Sets the check status of the item at the specified index.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] index             The item index
	 * @param[in] check				The check status
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION   The item is disabled.
	 * @exception E_SYSTEM              A system error has occurred.
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * Checks whether the item at the specified index is checked.
	 *
	 * @since	2.0
	 *
	 * @return  @c true if the item is checked, @n
	 *          else @c false
	 * @param[in] index				The item index
	 */
	bool IsItemChecked(int index) const;

	/**
	 * Sets the enabled/disabled status of the item at the specified index.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in] index             The item index
	 * @param[in] enable			The enabled/disabled status
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 *
	 */
	result SetItemEnabled(int index, bool enable);

	/**
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @since	2.0
	 *
	 * @return  @c true if the item is enabled, @n
	 *          else @c false
	 * @param[in] index				The item index
	 */
	bool IsItemEnabled(int index) const;

	/**
	 * Counts the number of items.
	 *
	 * @since	2.0
	 *
	 * @return  The total number of items
	 */
	int GetItemCount(void) const;

	/**
	 * Shows the description text of the given item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in] index				The index of the item
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    The specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks  If no description text is set to the item of the specified index, this method does not show the description text.
	 *
	 */
	result ShowItemDescriptionText(int index);

	/**
	 * Hides the description text of the given item.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] index				The index of the item
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    The specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result HideItemDescriptionText(int index);

	/**
	 * Refreshes the specified item.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] index             The item index
	 * @param[in] type              The item to be added, removed, or modified
	 * @exception E_SUCCESS            The method is successful.
	 * @exception E_OUT_OF_RANGE       A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception E_SYSTEM             A system error has occurred.
	 * @remarks	3 refresh types are supported: LIST_REFRESH_TYPE_ITEM_ADD, LIST_REFRESH_TYPE_ITEM_REMOVE, and LIST_REFRESH_TYPE_ITEM_MODIFY.
	 * 			- LIST_REFRESH_TYPE_ITEM_ADD is used when new data is added to the data model. @n
	 *			- LIST_REFRESH_TYPE_ITEM_REMOVE is used when a data is deleted from the data model. @n
	 *			- LIST_REFRESH_TYPE_ITEM_MODIFY is used when an existing data has changes and needs to be updated. @n
	 *			   Calling this method with LIST_REFRESH_TYPE_ITEM_MODIFY invokes the item provider to call DeleteItem() and CreateItem() for the given index in
	 *			   sequence.
	 * @remarks  This method internally calls Invalidate(), so you do not need to call them to update the screen.
	 */
	result RefreshList(int index, ListRefreshType type);

	/**
	 * Refreshes the specified item's element.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] index             The item index
	 * @param[in] elementId         The item element ID
	 * @exception E_SUCCESS            The method is successful.
	 * @exception E_OUT_OF_RANGE       A specified input parameter is invalid.
	 * @exception E_SYSTEM             A system error has occurred.
	 * @remarks  This method internally calls Invalidate(), so you do not need to call them to update the screen.
	 */
	result RefreshList(int index, int elementId);

	/**
	 * Updates the whole items of a list.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks	This method clears the items in the list and re-invokes the methods of the item provider to fill the list.
	 */
	result UpdateList(void);

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return  The index of the item, @n
	 *			else @c -1 if there is no list item at the specified position
	 * @param[in] x					The X position of the point
	 * @param[in] y                 The Y position of the point
	 * @remarks	The method returns -1 when there is no list item at the specified position.
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return  The index of the item
	 * @param[in] position		The position of the point, @n
	 *							else @c -1 if there is no list item at the specified position
	 */
	int GetItemIndexFromPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] x                 The X position of the item
	 * @param[in] y                 The Y position of the item
	 * @param[out] itemIndex		The index of the item
	 * @param[out] elementId        The ID of the element
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred, or @n
	 *								there is no item at the specified position.
	 * @remarks	The specified @c itemIndex is -1 when there is no list item at the specified position.
	 * @remarks  The specified @c elementId is -1 when there is no element at the specified position.
	 */
	result GetItemIndexFromPosition(int x, int y, int& itemIndex, int& elementId) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] position          The position of the point
	 * @param[out] itemIndex        The index of the item
	 * @param[out] elementId		The ID of the element
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred, or @n
	 *								there is no item at the specified position.
	 * @remarks	The specified @c itemIndex is -1 when there is no list item at the specified position.
	 * @remarks The specified @c elementId is -1 when there is no element at the specified position.
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& itemIndex, int& elementId) const;

	/**
	 * Sets the color of a division line between items.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] color				The division line color
	 * @exception E_SUCCESS         The method is successful.
	 */
	result SetItemDividerColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of a division line between items.
	 *
	 * @since	2.0
	 *
	 * @return  The color of a section, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Tizen::Graphics::Color GetItemDividerColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] color				The background color
	 * @exception E_SUCCESS			The method is successful.
	 * @remarks  The method sets the alpha value of the specified @c color to @c 255, when a device does not support 32bit color space. @n
	 *          The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only
	 *			the bitmap image is displayed.
	 */
	result SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of this control.
	 *
	 * @since	2.0
	 *
	 * @return	The background color, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the bitmap of this control.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] pBitmap        	The bitmap for the list
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the bitmap of the empty list.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] pBitmap           The bitmap for the empty list
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetBitmapOfEmptyList(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the text of the empty list.
	 *
	 * @since    2.0
	 *
	 * @return   An error code
	 * @param[in] text              The text for the empty list
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * Gets the text to display when there is no item in a list.
	 *
	 * @since	2.0
	 *
	 * @return	The text to display, @n
	 *			else an empty string if the instance is invalid
	 */
	Tizen::Base::String GetTextOfEmptyList(void) const;

	/**
	 * Sets a color of the text to display when there is no item in a list.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] color             The color of the text to display
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * Gets a color of the text to display when there is no item in a list.
	 *
	 * @since	2.0
	 *
	 * @return  The color of the text to display
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * Begins the reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @see    IListViewItemEventListener::OnListViewItemReordered()
	 */
	result BeginReorderingMode(void);

	/**
	 * Ends the reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @see    IListViewItemEventListener::OnListViewItemReordered()
	 */
	result EndReorderingMode(void);

	/**
	 * Checks whether the %ListView control is in reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the %ListView is in reordering mode, @n
	 *  		else @c false
	 */
	bool IsInReorderingMode(void) const;

protected:
	friend class _ListViewImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ListView(const ListView& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ListView& operator =(const ListView& rhs);
}; // ListView

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_LIST_VIEW_H_
