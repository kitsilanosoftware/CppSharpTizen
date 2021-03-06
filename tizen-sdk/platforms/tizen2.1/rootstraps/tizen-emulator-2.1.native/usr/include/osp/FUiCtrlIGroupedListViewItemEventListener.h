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
 * @file	FUiCtrlIGroupedListViewItemEventListener.h
 * @brief	This is the header file for the %IGroupedListViewItemEventListener interface.
 *
 * This header file contains the declarations of the %IGroupedListViewItemEventListener interface.
 */

#ifndef _FUI_CTRL_IGROUPED_LIST_VIEW_ITEM_EVENT_LISTENER_H_
#define _FUI_CTRL_IGROUPED_LIST_VIEW_ITEM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class GroupedListView;

/**
 * @interface	IGroupedListViewItemEventListener
 * @brief		This interface implements the listener for the events generated by the items of the GroupedListView control.
 *
 * @since		2.0
 *
 * The %IGroupedListViewItemEventListener interface is the listener interface for receiving GroupedListView item events.
 * The class that processes a list item event implements this interface, and the instance created with that class is registered
 *  with a UI control, using the control's AddGroupedListViewItemEventListener() method. When the list item event occurs, a
 *  method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IGroupedListViewItemEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called
	 * when the destructor of this interface is called.
	 *
	 * @since   2.0
	 */
	virtual ~IGroupedListViewItemEventListener(void) {};

	/**
	 * Called when the state of an element of a GroupedListView item is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in] listView			The source of the event
	 * @param[in] groupIndex		The index of the group item
	 * @param[in] itemIndex			The index of the item in the group
	 * @param[in] elementId			The element ID
	 * @param[in] status			The status of the element
	 *
	 * @remarks
	 *			- This method is called when an element of the %CustomItem control in the %GroupedListView control is checked, unchecked,
	 *			or selected.
	 *			- If the method is called to notify the state change of an item's annex or the item itself, the specified elementId is set to @c -1.
	 */
	virtual void OnGroupedListViewItemStateChanged(Tizen::Ui::Controls::GroupedListView& listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListItemStatus status) = 0;

	/**
	 * Called when ListItem is swept.
	 *
	 * @since	2.0
	 * @param[in] listView			The source of the event
	 * @param[in] groupIndex		The index of the group item
	 * @param[in] itemIndex			The index of the item in the group
	 * @param[in] direction			The sweep direction
	 */
	virtual void OnGroupedListViewItemSwept(Tizen::Ui::Controls::GroupedListView& listView, int groupIndex, int itemIndex, Tizen::Ui::Controls::SweepDirection direction) = 0;

	/**
	 * Called when the state of an element in the ListContextItem control is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in] listView  		The source of the event
	 * @param[in] groupIndex		The index of the group item
	 * @param[in] itemIndex 		The index of the item in the group
	 * @param[in] elementId 		The element ID
	 * @param[in] status			The status of the element
	 */
	virtual void OnGroupedListViewContextItemStateChanged(Tizen::Ui::Controls::GroupedListView& listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListContextItemStatus status) = 0;

	/**
	 * Called when the item or the element is long pressed.
	 *
	 * @since   2.0
	 *
	 * @param[in] listView  		The source of the event
	 * @param[in] groupIndex		The index of the group
	 * @param[in] itemIndex 		The index of the item in the group
	 * @param[in] elementId 		The element ID
	 * @param[in,out] invokeListViewItemCallback	Indicates whether to invoke %GroupedListView item callback after this method returns
	 * @remarks
	 *			- This method is invoked when an item or an element is long pressed. @n
	 *			When the event comes from the annex or the whole item, @c elementId is always -1.
	 *			- Setting @c invokeListViewItemCallback to @c true invokes GroupedListView item callbacks after this method returns.
	 *			- Set @c invokeListViewItemCallback to @c false to not invoke %GroupedListView item callbacks. The default value of
	 *			@c invokeListViewItemCallback is @c true.
	 *			- Note that other %GroupedListView item callbacks are not called even though @c invokeListViewItemCallback is @c true, if
	 *			%GroupedListView loses focus, for example, due to invoking a Popup or a ContextMenu in this method.
	 */
	virtual void OnGroupedListViewItemLongPressed(Tizen::Ui::Controls::GroupedListView& listView, int groupIndex, int itemIndex, int elementId, bool& invokeListViewItemCallback);

	/**
	 * Called when GroupItem is selected.
	 *
	 * @since 2.0
	 *
	 * @param[in] listView  		The source of the event
	 * @param[in] groupIndex		The index of the group item
	 */
	virtual void OnGroupedListViewGroupItemSelected(Tizen::Ui::Controls::GroupedListView& listView, int groupIndex);

	/**
	 * Called when the item is reordered.
	 *
	 * @since 2.0
	 *
	 * @param[in] listView   The source of the event
	 * @param[in] groupIndexFrom The source group index of the item
	 * @param[in] itemIndexFrom The source item index of the item
	 * @param[in] groupIndexTo The target group index of the item
	 * @param[in] itemIndexTo The target item index of the item
	 */
	virtual void OnGroupedListViewItemReordered(Tizen::Ui::Controls::GroupedListView& listView, int groupIndexFrom, int itemIndexFrom, int groupIndexTo, int itemIndexTo);

protected:
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IGroupedListViewItemEventListener_Reserved1(void) {}
	virtual void IGroupedListViewItemEventListener_Reserved2(void) {}
	virtual void IGroupedListViewItemEventListener_Reserved3(void) {}
}; // IGroupedListViewItemEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IGROUPED_LIST_VIEW_ITEM_EVENT_LISTENER_H_
