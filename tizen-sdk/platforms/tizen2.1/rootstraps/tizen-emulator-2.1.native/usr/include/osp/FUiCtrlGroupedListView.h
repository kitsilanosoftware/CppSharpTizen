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
 * @file	FUiCtrlGroupedListView.h
 * @brief	This is the header file for the %GroupedListView class.
 *
 * This header file contains the declarations of the %GroupedListView class and its helper classes.
 */

#ifndef _FUI_CTRL_GROUPED_LIST_VIEW_H_
#define _FUI_CTRL_GROUPED_LIST_VIEW_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpFloatRectangle.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlGroupedListViewTypes.h>
#include <FUiCtrlIFastScrollListener.h>
#include <FUiCtrlIGroupedListViewItemEventListener.h>
#include <FUiCtrlIGroupedListViewItemProvider.h>
#include <FUiCtrlIGroupedListViewItemProviderF.h>
#include <FUiCtrlIScrollEventListener.h>
#include <FUiCtrlIScrollEventListenerF.h>
#include <FUiCtrlListViewTypes.h>
#include <FUiCtrlScrollPanelTypes.h>
#include <FUiIUiLinkEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _GroupedListViewImpl;

/**
 * @class	GroupedListView
 * @brief   This class defines the common behavior of a %GroupedListView control.
 *
 * @since	2.0
 *
 * The %GroupedListView class displays a list of grouped items in a list. The items in a GroupedList control consist of groups and
 * items. A group represents the grouped items and is placed at the first level. Each group consists of simple or custom items.
 * Therefore, items are uniquely identified with two indexes: group index and item index.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 * The following example demonstrates how to use the %GroupedListView class.
 *
 *
 * @code
//Sample code for GroupedListViewSample.h

#include <FUi.h>

class CustomGroupedListElement;

class GroupedListViewSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IGroupedListViewItemEventListener
	, public Tizen::Ui::Controls::IGroupedListViewItemProvider
{
public:
	GroupedListViewSample(void)
	: __pGroupedListView(null)
	, __pCustomGroupedListElement(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IGroupedListViewItemEventListener
	virtual void OnGroupedListViewContextItemStateChanged(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	virtual void OnGroupedListViewItemStateChanged(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListItemStatus state);
	virtual void OnGroupedListViewItemSwept(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex,  int itemIndex, Tizen::Ui::Controls::SweepDirection direction);

	// IGroupedListViewItemProvider
	virtual int GetGroupCount(void);
	virtual int GetItemCount(int groupIndex);
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int groupIndex, int itemIndex, int itemWidth);
	virtual Tizen::Ui::Controls::GroupItem* CreateGroupItem(int groupIndex, int itemWidth);
	virtual bool DeleteItem(int groupIndex, int itemIndex, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	virtual bool DeleteGroupItem(int groupIndex, Tizen::Ui::Controls::GroupItem* pItem, int itemWidth);

private:
	static const int ID_FORMAT_STRING = 100;
	static const int ID_FORMAT_BITMAP = 101;
	static const int ID_FORMAT_CUSTOM = 102;
	static const int ID_CONTEXT_ITEM_1 = 103;
	static const int ID_CONTEXT_ITEM_2 = 104;

	Tizen::Graphics::Bitmap* __pHome;
	Tizen::Graphics::Bitmap* __pMsg;
	Tizen::Graphics::Bitmap* __pAlarm;
	Tizen::Graphics::Bitmap* __pCall;

	Tizen::Ui::Controls::GroupedListView* __pGroupedListView;
	Tizen::Ui::Controls::ListContextItem* __pItemContext;
	CustomGroupedListElement* __pCustomGroupedListElement;
};
 *	@endcode
 *
 *	@code
//Sample code for GroupedListViewSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "GroupedListViewSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

class CustomGroupedListElement
	: public ICustomElement
{
public:
	bool
	OnDraw(Canvas& canvas, const Rectangle& rect, ListItemDrawingStatus itemStatus)
	{
		Tizen::Graphics::Font font;
		font.Construct(FONT_STYLE_PLAIN, 15);
		canvas.SetFont(font);
		canvas.SetLineWidth(3);
		canvas.SetForegroundColor(Color::GetColor(COLOR_ID_GREEN));

		if (canvas.DrawRectangle(rect) != E_SUCCESS)
		{
			return false;
		}

		if (canvas.DrawText(Point(rect.x+10, rect.y+15), L"Custom") != E_SUCCESS)
		{
			return false;
		}

		return true;
	}
};

bool
GroupedListViewSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
GroupedListViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of IconListView
	__pGroupedListView = new GroupedListView();
	__pGroupedListView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), GROUPED_LIST_VIEW_STYLE_INDEXED, true, true);
	__pGroupedListView->SetItemProvider(*this);
	__pGroupedListView->AddGroupedListViewItemEventListener(*this);

	// Adds the icon list view to the form
	AddControl(__pGroupedListView);

	// Creates an instance of ListContextItem
	__pItemContext = new ListContextItem();
	__pItemContext->Construct();
	__pItemContext->AddElement(ID_CONTEXT_ITEM_1, "Test1");
	__pItemContext->AddElement(ID_CONTEXT_ITEM_2, "Test2");

	// Gets instances of Bitmap
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	__pHome = pAppResource->GetBitmapN(L"tizen.png");
	__pMsg = pAppResource->GetBitmapN(L"tizen.png");
	__pAlarm = pAppResource->GetBitmapN(L"tizen.png");
	__pCall = pAppResource->GetBitmapN(L"tizen.png");

	// Creates an instance of CustomGroupedListElement
	__pCustomGroupedListElement = new CustomGroupedListElement();

	return r;
}

result
GroupedListViewSample::OnTerminating(void)
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

void
GroupedListViewSample::OnGroupedListViewItemStateChanged(GroupedListView &listView, int groupIndex, int itemIndex, int elementId, ListItemStatus state)
{
	switch (elementId)
	{
	case ID_FORMAT_STRING:
		{
			// ....
		}
		break;
	case ID_FORMAT_BITMAP:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
GroupedListViewSample::OnGroupedListViewContextItemStateChanged(GroupedListView &listView, int groupIndex, int itemIndex, int elementId, ListContextItemStatus state)
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

// IGroupedListViewItemEventListener
void
GroupedListViewSample::OnGroupedListViewItemSwept(GroupedListView &listView, int groupIndex,  int itemIndex, SweepDirection direction)
{
	// ....
}

int
GroupedListViewSample::GetGroupCount(void)
{
	return 3;
}

int
GroupedListViewSample::GetItemCount(int groupIndex)
{
	int itemCount = 0;
	switch (groupIndex)
	{
	case 0:
		{
			itemCount = 7;
		}
		break;
	case 1:
		{
			itemCount = 5;
		}
		break;
	case 2:
		{
			itemCount = 3;
		}
		break;
	default:
		break;
	}

	return itemCount;
}

// IGroupedListViewItemProvider
GroupItem*
GroupedListViewSample::CreateGroupItem(int groupIndex, int itemWidth)
{
	String text("Group ");
	text.Append(groupIndex+1);

	GroupItem* pItem = new GroupItem();
	pItem->Construct(Dimension(itemWidth, 40));
	pItem->SetElement(text, null);

	return pItem;
}

ListItemBase*
GroupedListViewSample::CreateItem(int groupIndex, int itemIndex, int itemWidth)
{
	// Creates an instance of CustomItem
	CustomItem* pItem = new CustomItem();
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	pItem->Construct(Dimension(itemWidth, 100), style);

	switch (itemIndex % 4)
	{
	case 0:
		{
			style = LIST_ANNEX_STYLE_NORMAL;
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pHome, null, null);
			pItem->AddElement(Rectangle(150, 25, 150, 50), ID_FORMAT_STRING, L"Home", true);
		}
		break;
	case 1:
		{
			style = LIST_ANNEX_STYLE_MARK;
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pMsg, null, null);
			pItem->AddElement(Rectangle(150, 25, 150, 50), ID_FORMAT_STRING, L"Msg", true);
		}
		break;
	case 2:
		{
			style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pAlarm, null, null);
			pItem->AddElement(Rectangle(150, 25, 150, 50), ID_FORMAT_STRING, L"Alarm", true);
		}
		break;
	case 3:
		{
			style = LIST_ANNEX_STYLE_DETAILED;
			pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pCall, null, null);
			pItem->AddElement(Rectangle(150, 25, 150, 50), ID_FORMAT_STRING, L"Call", true);
		}
		break;
	default:
		break;
	}
	pItem->AddElement(Rectangle(360, 10, 180, 80), ID_FORMAT_CUSTOM, *(static_cast<ICustomElement *>(__pCustomGroupedListElement)));
	pItem->SetContextItem(__pItemContext);

	return pItem;
}

bool
GroupedListViewSample::DeleteItem(int groupIndex, int itemIndex, ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

bool
GroupedListViewSample::DeleteGroupItem(int groupIndex, GroupItem* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}
 * @endcode
 *
 */


class _OSP_EXPORT_ GroupedListView
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is
	 * called. @n For full construction, the %Construct() method must be
	 * called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	GroupedListView(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~GroupedListView(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %GroupedListView with the specified parameters.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated.
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in]   rect				An instance of the Graphics::Rectangle class
	 *                                  This instance represents the x and y coordinates of the top-left corner of the created
	 *									%GroupedListView control along with the width and height.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   style				The style of the %GroupedListView control
	 * @param[in]   itemDivider			Set to @c true to display an item divider, @n
	 *									else @c false
	 * @param[in]   fastScroll			Set to @c true to use the fast scroll, @n
	 *									else @c false
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *  								Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, GroupedListViewStyle style, bool itemDivider = true, bool fastScroll = false);

	/**
	 * Initializes this instance of %GroupedListView with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in]   rect				An instance of the Graphics::Rectangle class
	 *                                  This instance represents the x and y coordinates of the top-left corner of the created
	 *									%GroupedListView control along with the width and height.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   style				The style of the %GroupedListView control
	 * @param[in]   itemDivider			Set to @c true to display an item divider, @n
	 *									else @c false
	 * @param[in]   scrollStyle			Set to scroll style
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *  								Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, GroupedListViewStyle style, bool itemDivider, ListScrollStyle scrollStyle);

	/**
	 * Initializes this instance of %GroupedListView with the specified parameters.
	 *
	 * @since 2.1
	 *
	 * @return  An error code
	 * @param[in]   rect				An instance of the Graphics::Rectangle class
	 *                                  This instance represents the x and y coordinates of the top-left corner of the created
	 *									%GroupedListView control along with the width and height.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   style				The style of the %GroupedListView control
	 * @param[in]   itemDivider			Set to @c true to display an item divider, @n
	 *									else @c false
	 * @param[in]   scrollStyle			Set to scroll style
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *  								Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, GroupedListViewStyle style, bool itemDivider, ListScrollStyle scrollStyle);

	/**
	 * Sets the item provider that creates and deletes items from the list.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	provider			The item provider to create and delete items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- If an item provider is not set for the list, the list does not work.
	 *			- A provider should be allocated on a heap memory.
	 */
	result SetItemProvider(IGroupedListViewItemProvider& provider);

	/**
	 * Sets the item provider that creates and deletes items from the list.
	 *
	 * @since	2.1
	 *
	 * @return		An error code
	 * @param[in]	provider			The item provider to create and delete items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	If an item provider is not set for the list, the list does not work. @n
	 *			A provider should be allocated on a heap memory.
	 */
	result SetItemProvider(IGroupedListViewItemProviderF& provider);

	/**
	 * Adds an IGroupedListViewItemEventListener instance that listens to the state changes of the list view items. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to add
	 */
	void AddGroupedListViewItemEventListener(IGroupedListViewItemEventListener& listener);

	/**
	 * Removes an IGroupedListViewItemEventListener instance that listens to the state changes of the list view items. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to remove
	 */
	void RemoveGroupedListViewItemEventListener(IGroupedListViewItemEventListener& listener);

	/**
	 * Adds an IFastScrollListener instance that listens to the state changes of a fast scroll. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to add
	 */
	void AddFastScrollListener(IFastScrollListener& listener);

	/**
	 * Removes an IFastScrollListener instance that listens to the state changes of a fast scroll. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to remove
	 */
	void RemoveFastScrollListener(IFastScrollListener& listener);

	/**
	 * Adds an IScrollEventListener instance that listens to the state changes of a scroll event. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to add
	 * @see       IScrollEventListener::OnScrollEndReached()
	 * @see       RemoveScrollEventListener()
	 */
	void AddScrollEventListener(IScrollEventListener& listener);

	/**
	 * Adds an IScrollEventListener instance that listens to the state changes of a scroll event. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.1
	 *
	 * @param[in]	listener			The event listener to add
	 * @see       IScrollEventListener::OnScrollEndReached()
	 * @see       RemoveScrollEventListener()
	 */
	void AddScrollEventListener(IScrollEventListenerF& listener);

	/**
	 * Removes an IScrollEventListener instance that listens to the state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to remove
	 * @see     IScrollEventListener::OnScrollEndReached()
	 * @see     AddScrollEventListener()
	 */
	void RemoveScrollEventListener(IScrollEventListener& listener);

	/**
	 * Removes an IScrollEventListener instance that listens to the state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.1
	 *
	 * @param[in]	listener			The event listener to remove
	 * @see     IScrollEventListener::OnScrollEndReached()
	 * @see     AddScrollEventListener()
	 */
	void RemoveScrollEventListener(IScrollEventListenerF& listener);

	/**
	 * Adds a link event listener.
	 *
	 * @since   2.0
	 *
	 * @param[in]	listener			The event listener to add
	 * @remarks	The added listener is notified when a link is selected by the user.
	 *
	 * @see     RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since	2.0
	 *
	 * @param[in]	listener			The event listener to remove
	 * @see		AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(Tizen::Ui::IUiLinkEventListener& listener);

	/**
	 * Enables or disables the sweep event.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	enable              Set to @c true to enable the item sweep, @n
	 *									else @c false
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result SetSweepEnabled(bool enable);

	/**
	 * Sets the index list of the fast scroll.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	text				The text of the index
	 * @param[in]	useSearchIcon		Set to @c true to display the magnifying icon, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetFastScrollIndex(const Tizen::Base::String& text, bool useSearchIcon);

	/**
	 * Gets the group and item indexes of the top item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]	groupIndex          The group index
	 * @param[out]	itemIndex           The item index
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result GetTopDrawnItemIndex(int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the group and item indexes of the bottom item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]	groupIndex          The group index
	 * @param[out]	itemIndex           The item index
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result GetBottomDrawnItemIndex(int& groupIndex, int& itemIndex) const;


	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %GroupedListView control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] groupIndex            The group index
	 * @param[in] itemIndex             The item index
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	 * @exception E_SYSTEM              A system error has occurred.
	 * @remarks This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result ScrollToItem(int groupIndex, int itemIndex);

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the position specified by the item alignment.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] groupIndex            The group index
	 * @param[in] itemIndex             The item index
	 * @param[in] itemAlignment			The item alignment
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	 * @exception E_SYSTEM              A system error has occurred.
	 * @remarks This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result ScrollToItem(int groupIndex, int itemIndex, ListScrollItemAlignment itemAlignment);

	/**
	 * Checks or unchecks the item at the specified index.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in]	groupIndex			The group index of the item to check
	 * @param[in]	itemIndex			The index of the item to check
	 * @param[in]	check				Set to @c true to select the item, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION	The item is disabled.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- This method works only when the annex style of the item allows selection.
	 *			- This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result SetItemChecked(int groupIndex, int itemIndex, bool check);

	/**
	 * Checks whether the item at the specified index is selected.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the item is selected, @n
	 *			else @c false
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @remarks
	 *			- This method returns @c false, if the annex style of the item does not allow selection.
	 *			- This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	bool IsItemChecked(int groupIndex, int itemIndex) const;

	/**
	 * Enables or disables the item at the specified index.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @param[in]	enable				Set to @c true to enable the specified item, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- This method can only be used when the annex style of the list allows selection.
	 *			- This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result SetItemEnabled(int groupIndex, int itemIndex, bool enable);

	/**
	 * Checks whether the item at the specified index is enabled or disabled.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the item is enabled, @n
	 *			else @c false
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @remarks This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	bool IsItemEnabled(int groupIndex, int itemIndex) const;

	/**
	 * Counts the total number of groups.
	 *
	 * @since	2.0
	 *
	 * @return	The total number of groups
	 */
	int GetGroupCount(void) const;

	/**
	 * Counts all the items of the specified group.
	 *
	 * @since	2.0
	 *
	 * @return	The total number of items in the specified group
	 * @param[in]	groupIndex			The group index
	 * @remarks This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	int GetItemCountAt(int groupIndex) const;

	/**
	 * Shows the description text of the specified item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	groupIndex			The group index of the item
	 * @param[in]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- If no description text is set for the item at the specified index, it is not displayed.
	 *			- This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 *
	 */
	result ShowItemDescriptionText(int groupIndex, int itemIndex);

	/**
	 * Hides the description text of the specified item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	groupIndex			The group index of the item
	 * @param[in]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks This method should be called only after list items are created. @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result HideItemDescriptionText(int groupIndex, int itemIndex);

	/**
	 * Updates the specified item. @n
	 * For instance, @c LIST_REFRESH_TYPE_ITEM_ADD is used when a new item needs to be added and @c LIST_REFRESH_TYPE_ITEM_REMOVE
	 * is used when an item is deleted from the list. Moreover, @c LIST_REFRESH_TYPE_ITEM_MODIFY is used when the content of an existing item
	 * has changed and it needs to be updated. @n Note that calling this method with @c LIST_REFRESH_TYPE_ITEM_MODIFY invokes item provider's
	 * DeleteItem() and CreateItem() for the given index in sequence.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @param[in]	type                The item to add, remove, or modify
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks
	 *			- If the specified itemIndex is @c -1, then the method is applied to the group item with the given index.
	 *			- Note that if @c LIST_REFRESH_TYPE_ITEM_REMOVE option is used to a group item, all the items in the group
	 *			(including the group item itself) are removed from the list.
	 *			- This method internally calls Invalidate(), so you do not need to call them to update the screen.
	 */
	result RefreshList(int groupIndex, int itemIndex, ListRefreshType type);

	/**
	 * Refreshes the specified item's element.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @param[in]	elementId			The item element ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks  This method internally calls Invalidate(), so you do not need to call them to update the screen.
	 */
	result RefreshList(int groupIndex, int itemIndex, int elementId);

	/**
	 * Updates all the items of a list.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	This method clears all the items in the list and invokes the methods of the item provider again to update the list.
	 */
	result UpdateList(void);

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	x					The X position of the item
	 * @param[in]	y					The Y position of the item
	 * @param[out]	groupIndex			The index of the group that the item belongs to
	 * @param[out]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred, or @n
	 *									there is no item at the specified position.
	 * @remarks This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	x					The X position of the item
	 * @param[in]	y					The Y position of the item
	 * @param[out]	groupIndex			The index of the group that the item belongs to
	 * @param[out]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred, or @n
	 *									there is no item at the specified position.
	 * @remarks This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(float x, float y, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	position			The position of the item
	 * @param[out]	groupIndex			The index of the group that the item belongs to
	 * @param[out]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred, or @n
	 *									there is no item at the specified position.
	 * @remarks This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	position			The position of the item
	 * @param[out]	groupIndex			The index of the group that the item belongs to
	 * @param[out]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred, or @n
	 *									there is no item at the specified position.
	 * @remarks This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::FloatPoint& position, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in]  x                    The X position of the item
	 * @param[in]  y                    The Y position of the item
	 * @param[out] groupIndex           The index of the group that the item belongs to
	 * @param[out] itemIndex            The index of the item
	 * @param[out] elementId            The ID of the element
	 * @exception  E_SUCCESS            The method is successful.
	 * @exception  E_SYSTEM             A system error has occurred, or
	 *								    there is no item at the specified position.
	 * @remarks
	 *			- @c groupIndex and @c itemIndex are @c -1 when there is no list item at the specified position.
	 *			- @c elementId is @c -1 when there is no element at the specified position
	 * 			- This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).

	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex, int& elementId) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since	2.1
	 *
	 * @return  An error code
	 * @param[in]  x                    The X position of the item
	 * @param[in]  y                    The Y position of the item
	 * @param[out] groupIndex           The index of the group that the item belongs to
	 * @param[out] itemIndex            The index of the item
	 * @param[out] elementId            The ID of the element
	 * @exception  E_SUCCESS            The method is successful.
	 * @exception  E_SYSTEM             A system error has occurred, or
	 *								    there is no item at the specified position.
	 * @remarks
	 *			- @c groupIndex and @c itemIndex are @c -1 when there is no list item at the specified position.
	 *			- @c elementId is @c -1 when there is no element at the specified position
	 * 			- This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(float x, float y, int& groupIndex, int& itemIndex, int& elementId) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in]  position             The position of the point
	 * @param[out] groupIndex           The index of the group that the item belongs to
	 * @param[out] itemIndex            The index of the item
	 * @param[out] elementId            The ID of the element
	 * @exception  E_SUCCESS            The method is successful.
	 * @exception  E_SYSTEM             A system error has occurred, or
	 *								    there is no item at the specified position.
	 * @remarks
	 *			- @c groupIndex and @c itemIndex are @c -1 when there is no list item at the specified position.
	 *			- @c elementId is @c -1 when there is no element at the specified position
	 *			- This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& groupIndex, int& itemIndex, int& elementId) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since	2.1
	 *
	 * @return  An error code
	 * @param[in]  position             The position of the point
	 * @param[out] groupIndex           The index of the group that the item belongs to
	 * @param[out] itemIndex            The index of the item
	 * @param[out] elementId            The ID of the element
	 * @exception  E_SUCCESS            The method is successful.
	 * @exception  E_SYSTEM             A system error has occurred, or
	 *								    there is no item at the specified position.
	 * @remarks
	 *			- @c groupIndex and @c itemIndex are @c -1 when there is no list item at the specified position.
	 *			- @c elementId is @c -1 when there is no element at the specified position
	 *			- This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::FloatPoint& position, int& groupIndex, int& itemIndex, int& elementId) const;

	/**
	 * Sets the color of a section.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	color				The section color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation
	 *									(this control cannot be displayed).
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *			- This method works only when the style of the %GroupedListView control is ::GROUPED_LIST_VIEW_STYLE_SECTION.
	 *			- If the device does not support the 32-bit color space, the method sets the alpha value of the specified color to @c 255.
	 */
	result SetSectionColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of a section.
	 *
	 * @since	2.0
	 *
	 * @return	The section color, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Tizen::Graphics::Color GetSectionColor(void) const;

	/**
	 * Sets the color of a division line between items.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	color				The division line color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetItemDividerColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of a division line between items.
	 *
	 * @since	2.0
	 *
	 * @return  The color of a division line, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Tizen::Graphics::Color GetItemDividerColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in]	color               The background color
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks
	 *			- If the device does not support the 32-bit color space, the method sets the alpha value of the specified color to @c 255.
	 *			- The background bitmap has priority over the background color. When both the background bitmap and the background color
	 *			are specified, only the bitmap image is displayed.
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
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pBitmap				The bitmap for the empty list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetBitmapOfEmptyList(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the text of the empty list.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	text				The text for the empty list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * Gets the text to display when there is no item in a list.
	 *
	 * @since	2.0
	 *
	 * @return	The text to be displayed, @n
	 *			else an empty string when the instance is invalid
	 */
	Tizen::Base::String GetTextOfEmptyList(void) const;

	/**
	 * Sets the color of the text to be displayed when there is no item in a list.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	color				The color of the text to display
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the text to be displayed when there is no item in a list.
	 *
	 * @since	2.0
	 *
	 * @return  The color of the text to be displayed, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * Expands the group's items.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] groupIndex The index of the group
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_OUT_OF_RANGE        A specified input parameter is invalid.
	 * @exception E_SYSTEM              A system error has occurred.
	 * @remarks	This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
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
	 * @exception E_OUT_OF_RANGE    A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks	This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	result CollapseGroup(int groupIndex);

	/**
	 * Checks whether the group is expanded.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the group is expanded, @n
	 *			@c else false
	 *
	 * @param[in] groupIndex The index of the group
	 * @remarks	This method should be called only after list items are created.  @n
	 *			If this method needs to be called early in the lifecycle of the ListView,
	 *			then UpdateList() method should be called explicitly (for example, during Tizen::Ui::Control::OnInitializing()).
	 */
	bool IsGroupExpanded(int groupIndex) const;

	/**
	 * Expands all groups of list.
	 *
	 * @since 2.1
	 *
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_OPERATION   The feature of expanding all groups is only supported when %GroupedListView% is constructed with
	 *								::GROUPED_LIST_VIEW_STYLE_INDEXED style.
	 * @see    GroupedListView::Construct()
	 */
	result ExpandAllGroups(void);

	/**
	 * Collapses all groups of list.
	 *
	 * @since 2.1
	 *
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_OPERATION   The feature of collapsing all groups is only supported when %GroupedListView% is constructed with
	 *								::GROUPED_LIST_VIEW_STYLE_INDEXED style.
	 * @see    GroupedListView::Construct()
	 */
	result CollapseAllGroups(void);

	/**
	 * Begins the reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_INVALID_OPERATION	The reordering mode is only supported when %GroupedListView% is constructed with
	 *								::GROUPED_LIST_VIEW_STYLE_INDEXED style.
	 * @see		GroupedListView::Construct()
	 * @see		IGroupedListViewItemEventListener::OnGroupedListViewItemReordered()
	 */
	result BeginReorderingMode(void);

	/**
	 * Ends the reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_INVALID_OPERATION	The reordering mode is only supported when %GroupedListView% is constructed with
	 *								::GROUPED_LIST_VIEW_STYLE_INDEXED style.
	 * @see		GroupedListView::Construct()
	 * @see		IGroupedListViewItemEventListener::OnGroupedListViewItemReordered()
	 */
	result EndReorderingMode(void);

	/**
	 * Checks whether the %GroupedListView control is in reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the %GroupedListView is in reordering mode,
	 * 			else @c false
	 */
	bool IsInReorderingMode(void) const;

	/**
	 * Sets the scroll input handling mode.
	 *
	 * @since 2.1
	 *
	 * @param[in] mode  The scroll input handling mode
	 * @see         GetScrollInputMode()
	 */
	void SetScrollInputMode(ScrollInputMode mode);

	/**
	 * Gets the scroll input handling mode.
	 *
	 * @since 2.1
	 *
	 * @return     The scroll input handling mode
	 * @see         SetScrollInputMode()
	 */
	ScrollInputMode GetScrollInputMode(void) const;

	/**
	 * Opens the context item at a specified index.
	 *
	 * @since 2.1
	 *
	 * @return	An error code
	 * @param[in] groupIndex	The group index
	 * @param[in] itemIndex		The item index
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 */
	result OpenContextItem(int groupIndex, int itemIndex);

	/**
	 * Closes the context item at a specified index.
	 *
	 * @since 2.1
	 *
	 * @return	An error code
	 * @param[in] groupIndex	The group index
	 * @param[in] itemIndex		The item index
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 */
	result CloseContextItem(int groupIndex, int itemIndex);

	/**
	 * Returns whether the context item at a specified index has been opened or not.
	 *
	 * @since 2.1
	 *
	 * @return	@c true if the context item has been opened, @n
	 *          else @c false
	 * @param[in] groupIndex	The group index
	 * @param[in] itemIndex		The item index
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_OUT_OF_RANGE	A specified input parameter is invalid.
	 */
	bool IsContextItemOpened(int groupIndex, int itemIndex) const;

protected:
	friend class _GroupedListViewImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	GroupedListView(const GroupedListView& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	GroupedListView& operator =(const GroupedListView& rhs);

}; // GroupedListView

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_GROUPED_LIST_VIEW_H_
