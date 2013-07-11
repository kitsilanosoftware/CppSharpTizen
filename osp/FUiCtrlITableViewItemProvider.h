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
 * @file FUiCtrlITableViewItemProvider.h
 * @brief This is the header file for the %ITableViewItemProvider interface.
 *
 * This header file contains the declarations of the %ITableViewItemProvider interface.
 * If the event is generated, a method of this interface is called.
 * So, if applications do jobs related to item events, use the methods of this interface.
 *
 */

#ifndef _FUI_CTRL_ITABLE_VIEW_ITEM_PROVIDER_H_
#define _FUI_CTRL_ITABLE_VIEW_ITEM_PROVIDER_H_

namespace Tizen { namespace Ui { namespace Controls
{
class TableViewItem;

/**
 * @interface ITableViewItemProvider
 * @brief  This interface implements the listener for events on TableView.
 *
 * @since 2.0
 *
 * The %ITableViewItemProvider interface implements an item provider which generates items for TableView. %TableView calls the item provider
 * to request an item which is about to be displayed on a screen. Applications which use %TableView must implement the item provider.
 * The class is registered with a %TableView, using the TableView's SetSimpleStyleItemProvider() method.
 */
class _OSP_EXPORT_ ITableViewItemProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ITableViewItemProvider(void) {}

	/**
	 * Gets the total number of items in the specified group.
	 *
	 * @since 2.0
	 *
	 * @return  The total number of items
	 * @remarks This method must be implemented so that it returns the total number of items for the specified group in the TableView control.
	 */
	virtual int GetItemCount(void) = 0;

	/**
	 * Creates the specified item.
	 *
	 * @since 2.0
	 *
	 * @return An item of the TableView
	 * @param[in] itemIndex  The item index
	 * @param[in] itemWidth The width of the item
	 * @remarks  An application that uses the TableView control must implement this method.
	 *           This method is expected to return an item that is allocated on a heap memory.
	 *           The returned item can be a %TableViewItem or a class derived from TableViewItem.
	 *           Note that when the item is not required, the %TableView control calls ITableViewItemProvider::DeleteItem(), allowing the application to deallocate the item.
	 * @see           DeleteItem()
	 */
	virtual TableViewItem* CreateItem(int itemIndex, int itemWidth) = 0;

	/**
	 * Deletes the specified item.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the item is deallocated by this method, @n
	 *         else @c false
	 * @param[in] itemIndex The item index
	 * @param[in] pItem The pointer to TableViewItem that is to be deleted
	 * @remarks  An application that uses the TableView control must implement this method.
	 *           Using this method, an application can deallocate the item.
	 *           If the application deallocates the item, this method must return @c true. This notifies the %TableView not to release the
	 *           item. Otherwise, the item is deallocated by the %TableView.
	 * @see     CreateItem()
	 */
	virtual bool DeleteItem(int itemIndex, TableViewItem* pItem) = 0;

	/**
	 * Updates the specified item.
	 *
	 * @since 2.0
	 *
	 * @param[in] itemIndex  The item index
	 * @param[in] pItem The pointer to TableViewItem that is to be updated
	 * @remarks  An application that uses the TableView control must implement this method.
	 *           This method is called when the modification of an item is requested.
	 *           The application can change @c pItem in this method, but should not keep @c pItem for later use.
	 */
	virtual void UpdateItem(int itemIndex, TableViewItem* pItem) = 0;

	/**
	 * Gets the default height of an item.
	 *
	 * @since 2.0
	 *
	 * @return  The default height of an item
	 * @remarks This method must be implemented so that it returns the default height of items in the TableView control.
	 */
	virtual int GetDefaultItemHeight(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITableViewItemProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITableViewItemProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ITableViewItemProvider_Reserved3(void) {}
}; // ITableViewItemProvider

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ITABLE_VIEW_ITEM_PROVIDER_H_
