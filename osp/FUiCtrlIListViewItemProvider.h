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
 * @file	FUiCtrlIListViewItemProvider.h
 * @brief	This is the header file for the %IListViewItemProvider interface.
 *
 * This header file contains the declarations of the %IListViewItemProvider interface. @n
 * If the event is generated, a method of this interface is called. @n
 * So, if applications do jobs related to item events, use the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_ILIST_VIEW_ITEM_PROVIDER_H_
#define _FUI_CTRL_ILIST_VIEW_ITEM_PROVIDER_H_

#include <FUiCtrlListItemBase.h>

namespace Tizen {namespace Ui { namespace Controls
{

/**
 * @interface	IListViewItemProvider
 * @brief		This interface implements the listener for events on %ListView.
 *
 * @since		2.0
 *
 * The %IListViewItemProvider interface is the interface for handling ListView items.
 * The class that handles list items implements this interface, and the instance created using the ListView's Construct() method.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IListViewItemProvider
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
	virtual ~IListViewItemProvider(void) {}

	/**
	 * Called when the ListView is about to be drawn and returns the number of total items.
	 *
	 * @since	2.0
	 *
	 * @return  The count of all items of the list
	 * @remarks  This method must be implemented so that it returns the number of total items in the list.
	 *
	 */
	virtual int GetItemCount(void) = 0;

	/**
	 * Called when items need to be loaded.
	 *
	 * @since	2.0
	 *
	 * @return  An item of the ListView
	 * @param[in] index        The index of the item
	 * @param[in] itemWidth    The width of the item
	 * @remarks  The applications that use ListView must implement this method. @n
	 *				This method is expected to return an item which is allocated in a heap memory. @n
	 *				The returned item can be a SimpleItem or CustomItem. @n
	 *				Note that when the item becomes unnecessary, the ListView calls IListViewItemProvider::DeleteItem() and the application is in charge of
	 *				deallocating the item.
	 * @see     DeleteItem()
	 */
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth) = 0;

	/**
	 * Called when an item becomes no longer used by the %ListView.
	 *
	 * @since	2.0
	 *
	 * @return  @c true, if the item is deallocated by this method, @n
	 *          else @c false
	 * @param[in] index        The index of the item
	 * @param[in] pItem        The pointer to the item to be deleted
	 * @param[in] itemWidth    The width of the item
	 * @remarks  Applications which use ListView must implement this method. @n
	 *			In this method, the applications have the chance of deallocating the item. @n
	 *			If the application deallocates the item, this method returns @c true, notifying the %ListView not to free the item. @n
	 *			Otherwise, the item will be deallocated by %ListView.
	 * @see     CreateItem()
	 */
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth) = 0;

protected:
	//
	// Following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IListViewItemProvider_Reserved1(void) {}
	virtual void IListViewItemProvider_Reserved2(void) {}
	virtual void IListViewItemProvider_Reserved3(void) {}
}; // IListViewItemProvider

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ILIST_VIEW_ITEM_PROVIDER_H_
