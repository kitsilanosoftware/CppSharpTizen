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
 * @file	FUiCtrlIListViewItemEventListener.h
 * @brief	This is the header file for the %IListViewItemEventListener interface.
 *
 * This header file contains the declarations of the %IListViewItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called. @n
 * So, if an application does some jobs related to the item event, use the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_ILIST_VIEW_ITEM_EVENT_LISTENER_H_
#define _FUI_CTRL_ILIST_VIEW_ITEM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class ListView;

/**
 * @interface	IListViewItemEventListener
 * @brief		This interface implements the listener for item event.
 *
 * @since		2.0
 *
 * The %IListViewItemEventListener interface is the listener interface for receiving ListView item events.
 * The class that processes a list item event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddListViewItemEventListener() method. When the list item event occurs, a method of that
 * instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IListViewItemEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called
	 * when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IListViewItemEventListener(void) {}

	/**
	 * Called when the state of an element in the ListViewItem in the ListView or GroupedListView is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in] listView      The source of the event
	 * @param[in] index         The index of the list
	 * @param[in] elementId     The element ID
	 * @param[in] status        The status of the element
	 *
	 * @remarks  This method is called when an element of the ListViewItem in the ListView is checked, unchecked, or selected. @n
	 *   		When the event comes from the annex or the whole item, @c elementId is always @c -1.
	 */
	virtual void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView& listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status) = 0;

	/**
	 * Called when the ListItem is swept.
	 *
	 * @since	2.0
	 *
	 * @param[in] listView      The source of the event
	 * @param[in] index         The index of the list
	 * @param[in] direction     The sweep direction
	 */
	virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView& listView, int index, Tizen::Ui::Controls::SweepDirection direction) = 0;

	/**
	 * Called when the state of an element in the %ListContextItem is changed.
	 *
	 * @since	2.0
	 *
	 * @param[in] listView		The source of the event
	 * @param[in] index			The index of the list
	 * @param[in] elementId		The element ID
	 * @param[in] status        The status of the element
	 */
	virtual void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView& listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus status) = 0;

	/**
	 * Called when the item or the element is long pressed.
	 *
	 * @since	2.0
	 *
	 * @param[in] listView		The source of the event
	 * @param[in] index			The index of the list
	 * @param[in] elementId		The element ID
	 * @param[in,out] invokeListViewItemCallback	Indicates whether to invoke ListView item callback after this method returns
	 * @remarks  This method is invoked when an item or an element is long pressed. @n
	 *			When the event comes from the annex or the whole item, @c elementId is always @c -1.
	 *			Setting @c invokeListViewItemCallback to @c true invokes %ListView item callbacks after this method returns.
	 *			Set @c invokeListViewItemCallback to @c false to not invoke %ListView item callbacks. The default value of
	 *			@c invokeListViewItemCallback is @c true.
	 *			Note that other %ListView item callbacks are not called even though @c invokeListViewItemCallback is @c true, in case that ListView
	 *			loses the focus, for example, due to invoking a Popup or a ContextMenu in this method.
	 */
	virtual void OnListViewItemLongPressed(Tizen::Ui::Controls::ListView& listView, int index, int elementId, bool& invokeListViewItemCallback);

	/**
	 * Called when the item is reordered.
	 *
	 * @since 2.0
	 *
	 * @param[in] listView   The source of the event
	 * @param[in] indexFrom The start index of the item
	 * @param[in] indexTo The final index of the item
	 */
	virtual void OnListViewItemReordered(Tizen::Ui::Controls::ListView& listView, int indexFrom, int indexTo);

protected:
	//
	// Following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IListViewItemEventListener_Reserved1(void) {}
	virtual void IListViewItemEventListener_Reserved2(void) {}
	virtual void IListViewItemEventListener_Reserved3(void) {}
}; // IListViewItemEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ILIST_VIEW_ITEM_EVENT_LISTENER_H_
