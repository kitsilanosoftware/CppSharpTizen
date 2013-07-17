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
// distributed under the License is distributed on an ¡±AS IS¡± BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiCtrlIIconListViewItemProvider.h
 * @brief	This is the header file for the %IIconListViewItemProvider interface.
 *
 * This header file contains the declarations of the %IIconListViewItemProvider interface. @n
 * If an event is generated, a method of this interface is called. @n
 * Applications that perform tasks related to the list events call methods of this interface.
 */

#ifndef _FUI_CTRL_IICON_LIST_VIEW_ITEM_PROVIDER_H_
#define _FUI_CTRL_IICON_LIST_VIEW_ITEM_PROVIDER_H_

#include <FUiCtrlIconListViewItem.h>

namespace Tizen { namespace Ui { namespace Controls
{

class IconListView;

/**
 * @interface	IIconListViewItemProvider
 * @brief		This interface implements the provider for events on IconListView.
 *
 * @since		2.0
 *
 * The %IIconListViewItemProvider interface is the interface for handling IconListView items.
 * The class that handles list items implements this interface, and the instance created using the IconListView::Construct(const Tizen::Graphics::Rectangle&, const Tizen::Graphics::Dimension&, IconListViewStyle, IconListViewScrollDirection, IconListViewScrollStyle) method.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IIconListViewItemProvider
{
// Operation
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since   2.0
	 */
	virtual ~IIconListViewItemProvider(void) {}

	/**
	 * Called when the IconListView is about to be drawn and requests the listener to set the number of total items.
	 *
	 * @since   2.0
	 *
	 * @return	The item count of the IconListView
	 * @remarks	Applications that use IconListView must implement this method. This method is expected to return the number of total items in the
	 *			%IconListView.
	 */
	virtual int GetItemCount(void) = 0;

	/**
	 * Called when items need to be loaded.
	 *
	 * @since   2.0
	 *
	 * @return	The item of the IconListView
	 * @param[in] index			The index of the item
	 * @remarks  Applications that use IconListView must implement this method. This method is expected to return an item that is allocated in a heap
	 *			memory. The returned item can be IconListViewItem. Note that, when the item becomes unnecessary, the %IconListView calls
	 *			DeleteItem() and applications are in charge of deallocating the item. @n
	 *			The returned item should not be a null pointer.
	 *
	 */
	virtual Tizen::Ui::Controls::IconListViewItem* CreateItem(int index) = 0;

	/**
	 * Called when an item is no longer used by the IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	@c true if the item is deallocated by this method, @n
	 *          else @c false
	 *
	 * @param[in] index			The index of the item
	 * @param[in] pItem			The pointer to the item to delete
	 *
	 * @remarks	Applications that use IconListView must implement this method. In this method, the applications have the chance of deallocating the
	 *			item. If the application deallocates the item, this method must return @c true, notifying the %IconListView not to free the item.
	 *			Otherwise, the item will be deallocated by the %IconListView.
	 *
	 * @see		CreateItem()
	 */
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::IconListViewItem* pItem) = 0;

protected:
	// The following methods are reserved and may change its name at any time without prior notice.
	virtual void IconListViewItemProvider_Reserved1(void) {}
	virtual void IconListViewItemProvider_Reserved2(void) {}
	virtual void IconListViewItemProvider_Reserved3(void) {}
}; // IIconListViewItemProvider

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IICON_LIST_VIEW_ITEM_PROVIDER_H_
