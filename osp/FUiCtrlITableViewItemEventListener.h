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
 * @file FUiCtrlITableViewItemEventListener.h
 * @brief This is the header file for the %ITableViewItemEventListener interface.
 *
 * This header file contains the declarations of the %ITableViewItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called.
 * So, if an application does some jobs related to the item event, use the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_ITABLE_VIEW_ITEM_EVENT_LISTENER_H_
#define _FUI_CTRL_ITABLE_VIEW_ITEM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiCtrlTableViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
class TableView;
class TableViewItem;
class TableViewContextItem;

/**
 * @interface ITableViewItemEventListener
 * @brief  This interface implements the listener for item event.
 *
 * @since 2.0
 *
 * The %ITableViewItemEventListener interface implements a listener for receiving item change events.
 * The class that is interested in processing an item event implements this interface,
 * and the instance created with that class is registered with a UI control, using the control's
 * AddTableViewItemEventListener() method. When the item event occurs, the OnItemStateChanged() method of that object is invoked.
 */
class _OSP_EXPORT_ ITableViewItemEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ITableViewItemEventListener(void) {}

	/**
	 * Called when the state of a TableViewItem in the TableView is changed.
	 *
	 * @since 2.0
	 *
	 * @param[in] tableView				The source of the event
	 * @param[in] itemIndex				The item index
	 * @param[in] pItem					The target item
	 * @param[in] status					The status of the item
	 * @remarks This method is called when a TableViewItem in the TableView is checked, unchecked, or selected.
	 *          The application can change @c pItem in this method, but should not keep @c pItem for later use.
	 */
	virtual void OnTableViewItemStateChanged(Tizen::Ui::Controls::TableView& tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem, Tizen::Ui::Controls::TableViewItemStatus status) = 0;

	/**
	 * Called when the TableViewContextItem is opened or closed.
	 *
	 * @since 2.0
	 *
	 * @param[in] tableView				The source of the event
	 * @param[in] itemIndex				The item index
	 * @param[in] pContextItem			The context item which is opened or closed
	 * @param[in] activated				@c true if a context item is opened,@n
	 *                                   @c false, otherwise
	 */
	virtual void OnTableViewContextItemActivationStateChanged(Tizen::Ui::Controls::TableView& tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem* pContextItem, bool activated) = 0;

	/**
	 * Called when the item is reordered.
	 *
	 * @since 2.0
	 *
	 * @param[in] tableView				The source of the event
	 * @param[in] itemIndexFrom			The start  item index of the item
	 * @param[in] itemIndexTo			The final item index of the item
	 */
	virtual void OnTableViewItemReordered(Tizen::Ui::Controls::TableView& tableView, int itemIndexFrom, int itemIndexTo) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITableViewItemEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITableViewItemEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITableViewItemEventListener_Reserved3(void) {}
}; // ITableViewItemEventListener

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_ITABLE_VIEW_ITEM_EVENT_LISTENER_H_
