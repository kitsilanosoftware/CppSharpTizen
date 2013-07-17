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
 * @file	FUiCtrlIGroupedListViewItemProviderF.h
 * @brief	This is the header file for the %IGroupedListViewItemProviderF interface.
 *
 * This header file contains the declarations of the %IGroupedListViewItemProviderF interface. @n
 * If an event is generated, a method of this interface is called. @n
 * Therefore, if an application performs jobs related to the item events, it uses the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_IGROUPED_LIST_VIEW_ITEM_PROVIDERF_H_
#define _FUI_CTRL_IGROUPED_LIST_VIEW_ITEM_PROVIDERF_H_

#include <FUiCtrlGroupItem.h>
#include <FUiCtrlListItemBase.h>

namespace Tizen {namespace Ui { namespace Controls
{

/**
 * @interface	IGroupedListViewItemProviderF
 * @brief		This interface implements the provider for the events generated by the GroupedListView control.
 *
 * @since		2.1
 *
 * The %IGroupedListViewItemProviderF interface is the interface for handling GroupedListView items.
 * The class that handles list items implements this interface, and the instance created using the GroupedListView::Construct() method.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IGroupedListViewItemProviderF
{
// Operation
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called
	 * when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IGroupedListViewItemProviderF(void) {}

	/**
	 * Gets the total number of groups.
	 *
	 * @since	2.1
	 *
	 * @return	The total number of groups
	 * @remarks  This method must be implemented so that it returns the total number of groups in the GroupedListView control.
	 */
	virtual int GetGroupCount(void) = 0;

	/**
	 * Gets the total number of items in a specified group.
	 *
	 * @since	2.1
	 *
	 * @return  The total number of items in the specified group
	 * @param[in] groupIndex		The index of the group
	 * @remarks  This method must be implemented so that it returns the total number of items for the specified group in the GroupedListView control.
	 */
	virtual int GetItemCount(int groupIndex) = 0;

	/**
	 * Creates the group item for a specified index from the item provider.
	 *
	 * @since	2.1
	 *
	 * @return  A group item of the GroupedListView control
	 * @param[in] groupIndex        The index of the group
	 * @param[in] itemWidth         The width of the item
	 * @remarks
	 *			- An application that uses the GroupedListView control must implement this method. This method is expected to return a group item that is
	 *			allocated on a heap memory.
	 *			- Note that when the item is not required, the GroupedListView control calls IGroupedListViewItemProvider::DeleteGroupItem() and the
	 *			application deallocates the item.
	 *			- The returned item should not be a null pointer.
	 */
	virtual Tizen::Ui::Controls::GroupItem* CreateGroupItem(int groupIndex, float itemWidth) = 0;

	/**
	 * Deletes a specified group item.
	 *
	 * @since	2.1
	 *
	 * @return  @c true if the item is deallocated by this method, @n
	 *          else @c false
	 * @param[in] groupIndex        The index of the group
	 * @param[in] pItem             The pointer to GroupItem to delete
	 * @param[in] itemWidth         The width of the item
	 * @remarks
	 *			- An application that uses the GroupedListView control must implement this method.
	 *			- Using this method, an application can deallocate the item.
	 *			- If an application deallocates the item, this method must return @c true. This notifies the %GroupedListView control not to release the
	 *			item. Otherwise, the item is deallocated by the %GroupedListView control.
	 * @see     CreateItem()
	 */
	virtual bool DeleteGroupItem(int groupIndex, Tizen::Ui::Controls::GroupItem* pItem, float itemWidth) = 0;

	/**
	 * Creates a specified item.
	 *
	 * @since	2.1
	 *
	 * @return	An item of the list
	 * @param[in] groupIndex        The index of the group
	 * @param[in] itemIndex         The index of the item
	 * @param[in] itemWidth			The width of the item
	 * @remarks
	 *			- An application that uses the GroupedListView control must implement this method.
	 *			- This method is expected to return an item that is allocated on a heap memory.
	 *			- The returned item can be a simple or custom item.
	 *			- Note that when the item is not required, the %GroupedListView control calls IGroupedListViewItemProvider::DeleteItem() and the application
	 *			deallocates the item.
	 * @see     DeleteItem()
	 */
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int groupIndex, int itemIndex, float itemWidth) = 0;

	/**
	 * Deletes a specified item.
	 *
	 * @since	2.1
	 *
	 * @return	@c true if the item is deallocated by this method, @n
	 *			else @c false
	 * @param[in] groupIndex        The index of the group
	 * @param[in] itemIndex         The index of the item
	 * @param[in] pItem             The pointer to ListItemBase to delete
	 * @param[in] itemWidth         The width of the item
	 * @remarks
	 *			- An application that uses the GroupedListView control must implement this method.
	 *			- Using this method, an application can deallocate the item.
	 *			- If the application deallocates the item, this method must return @c true. This notifies the %GroupedListView control not to release the
	 *			item. Otherwise, the item is deallocated by the %GroupedListView control.
	 * @see     CreateItem()
	 */
	virtual bool DeleteItem(int groupIndex, int itemIndex, Tizen::Ui::Controls::ListItemBase* pItem, float itemWidth) = 0;

	/**
	 * Checks whether the item can be reordered.
	 *
	 * @since 2.1
	 *
	 * @return @c true if the item can be reordered, @n
	 *         else @c false
	 * @param[in] groupIndexFrom The source group index of the item
	 * @param[in] groupIndexTo The target group index of the item
	 */
	virtual bool IsReorderable(int groupIndexFrom, int groupIndexTo);

protected:
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IGroupedListViewItemProvider_Reserved1(void) {}
	virtual void IGroupedListViewItemProvider_Reserved2(void) {}
	virtual void IGroupedListViewItemProvider_Reserved3(void) {}
}; // IGroupedListViewItemProviderF

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IGROUPED_LIST_VIEW_ITEM_PROVIDERF_H_