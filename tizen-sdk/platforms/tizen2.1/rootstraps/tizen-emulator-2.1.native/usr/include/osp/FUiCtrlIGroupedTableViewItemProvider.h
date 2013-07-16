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
* @file FUiCtrlIGroupedTableViewItemProvider.h
* @brief This is the header file for the %IGroupedTableViewItemProvider interface.
*
* This header file contains the declarations of the %IGroupedTableViewItemProvider interface.
* If the event is generated, a method of this interface is called.
* So, if applications do jobs related to item events, use the methods of this interface.
*
*/
#ifndef _FUI_CTRL_IGROUPED_TABLE_VIEW_ITEM_PROVIDER_H_
#define _FUI_CTRL_IGROUPED_TABLE_VIEW_ITEM_PROVIDER_H_

namespace Tizen { namespace Ui { namespace Controls
{
class TableViewItem;
class TableViewGroupItem;

/**
* @interface IGroupedTableViewItemProvider
* @brief  This interface implements the listener for events on GroupedTableView.
*
* @since 2.0
*
* The %IGroupedTableViewItemProvider interface implements an item provider which generates items for GroupedTableView. %GroupedTableView calls the item provider
* to request an item which is about to be displayed on a screen. Applications which use %GroupedTableView must implement the item provider.
* The class is registered with a %GroupedTableView, using the GroupedTableView::SetItemProvider() method.
*/
class _OSP_EXPORT_ IGroupedTableViewItemProvider
{
public:
	/**
	* This polymorphic destructor should be overridden if required.@n
	* This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since 2.0
	*/
	virtual ~IGroupedTableViewItemProvider(void) {}

	/**
	* Gets the total number of groups.
	*
	* @since 2.0
	*
	* @return The total number of groups
	* @remarks  This method must be implemented so that it returns the total number of groups in the GroupedTableView control.
	*/
	virtual int GetGroupCount(void) = 0;

	/**
	* Gets the total number of items in the specified group.
	*
	* @since 2.0
	*
	* @return  The total number of items in the specified group
	* @param[in] groupIndex  The index of the group
	* @remarks  This method must be implemented so that it returns the total number of items for the specified group in the GroupedTableView control.
	*/
	virtual int GetItemCount(int groupIndex) = 0;

	/**
	* Gets the group item for the specified index from the item provider.
	*
	* @since 2.0
	*
	* @return  A group item of the GroupedTableView control
	* @param[in] groupIndex           The index of the group
	* @param[in] itemWidth            The width of the item
	* @remarks
	*			- An application that uses the GroupedTableView control must implement this method. This method is expected to return a group item that is
	*			allocated on a heap memory.
	*			- Note that when the group item is not required, the %GroupedTableView control calls IGroupedTableViewItemProvider::DeleteGroupItem() and the
	*			application deallocates the item.
	 *			- The returned item should not be a null pointer.
	*/
	virtual TableViewGroupItem* CreateGroupItem(int groupIndex, int itemWidth) = 0;

	/**
	* Deletes the specified group item.
	*
	* @since 2.0
	*
	* @return  @c true if the group item is deallocated by this method,
	*          else @c false
	* @param[in] groupIndex        The index of the group
	* @param[in] pItem             The pointer to TableViewGroupItem to delete
	* @remarks
	*			- An application that uses the GroupedTableView control must implement this method.
	*			- Using this method, an application can deallocate the item.
	*			- If an application deallocates the item, this method must return @c true. This notifies the %GroupedTableView control not to release the
	*			item. Otherwise, the item is deallocated by the %GroupedTableView control.
	* @see     CreateGroupItem()
	*/
	virtual bool DeleteGroupItem(int groupIndex, TableViewGroupItem* pItem) = 0;

	/**
	* Updates the specified group item.
	*
	* @since 2.0
	*
	* @param[in] groupIndex           The group index
	* @param[in] pItem                The pointer to TableViewGroupItem to update
	* @remarks
	*			- An application that uses the GroupedTableView control must implement this method.
	*			- This method is called when the modification of a group item is requested.
	*			- The application can change @c pItem in this method, but should not keep @c pItem for later use.
	*/
	virtual void UpdateGroupItem(int groupIndex, TableViewGroupItem* pItem) = 0;

	/**
	* Creates the specified item.
	*
	* @since 2.0
	*
	* @return An item of the GroupedTableView
	* @param[in] groupIndex           The group index
	* @param[in] itemIndex            The item index
	* @param[in] itemWidth            The width of the item
	* @remarks
	*			- An application that uses the GroupedTableView control must implement this method.
	*			- This method is expected to return an item that is allocated on a heap memory.
	*			- The returned item can be a simple or custom item.
	*			- Note that when the item is not required, the %GroupedTableView control calls IGroupedTableViewItemProvider::DeleteItem()
	*			and the application deallocates the item.
	* @see     DeleteItem()
	*/
	virtual TableViewItem* CreateItem(int groupIndex, int itemIndex, int itemWidth) = 0;

	/**
	* Deletes the specified item.
	*
	* @since 2.0
	*
	* @return @c true if the item is deallocated by this method, @n
	*   else @c false
	* @param[in] groupIndex           The group index
	* @param[in] itemIndex            The item index
	* @param[in] pItem                The pointer to TableViewItem to delete
	* @remarks
	*			- An application that uses the GroupedTableView control must implement this method.
	*			- Using this method, an application can deallocate the item.
	*			- If the application deallocates the item, this method must return @c true. This notifies the %GroupedTableView control not to release the
	*			item. Otherwise, the item is deallocated by the %GroupedTableView control.
	* @see     CreateItem()
	*/
	virtual bool DeleteItem(int groupIndex, int itemIndex, TableViewItem* pItem) = 0;

	/**
	* Updates the specified item.
	*
	* @since 2.0
	*
	* @param[in] groupIndex                     The group index
	* @param[in] itemIndex            The item index
	* @param[in] pItem                            The pointer to TableViewItem to update
	* @remarks
	*			- An application that uses the GroupedTableView control must implement this method.
	*			- This method is called when the modification of an item is requested.
	*			- The application can change @c pItem in this method, but should not keep @c pItem for later use.
	*/
	virtual void UpdateItem(int groupIndex, int itemIndex, TableViewItem* pItem) = 0;

	/**
	* Gets the default height of a group item.
	*
	* @since 2.0
	*
	* @return  The default height of a group item
	* @remarks This method must be implemented so that it returns the default height of group items in the GroupedTableView control.
	*/
	virtual int GetDefaultGroupItemHeight(void) = 0;


	/**
	* Gets the default height of an item.
	*
	* @since 2.0
	*
	* @return  The default height of an item
	* @remarks This method must be implemented so that it returns the default height of items in the GroupedTableView control.
	*/
	virtual int GetDefaultItemHeight(void) = 0;

	/**
	* Checks whether the item can be reordered.
	*
	* @since 2.1
	*
	* @return	       @c true if the item can be reordered, @n
	*					else @c false
	* @param[in]	   groupIndexFrom The source group index of the item
	* @param[in]	   groupIndexTo The target group index of the item
	*/
	virtual bool IsReorderable(int groupIndexFrom, int groupIndexTo) { return false; }

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IGroupedTableViewItemProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IGroupedTableViewItemProvider_Reserved2(void) {}

}; // IGroupedTableViewItemProvider

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IGROUPED_TABLE_VIEW_ITEM_PROVIDER_H_
