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
* @file FUiCtrlISectionTableViewItemProviderF.h
* @brief This is the header file for the %ISectionTableViewItemProviderF interface.
*
* This header file contains the declarations of the %ISectionTableViewItemProviderF interface.
* If the event is generated, a method of this interface is called.
* So, when applications do jobs related to item events, use the methods of this interface.
*
*/
#ifndef _FUI_CTRL_ISECTION_TABLE_VIEW_ITEM_PROVIDER_F_H_
#define _FUI_CTRL_ISECTION_TABLE_VIEW_ITEM_PROVIDER_F_H_

namespace Tizen { namespace Ui { namespace Controls
{
class TableViewItem;

/**
* @interface ISectionTableViewItemProviderF
* @brief  This interface implements the listener for events on SectionTableView.
*
* @since 2.1
*
* The %ISectionTableViewItemProviderF interface implements an item provider which generates items for SectionTableView. %SectionTableView calls the item provider
* to request an item which is about to be displayed on a screen. Applications which use %SectionTableView must implement the item provider.
* The class is registered with a %SectionTableView, using the SectionTableView::SetItemProviderF() method.
*/
class _OSP_EXPORT_ ISectionTableViewItemProviderF
{
public:
	/**
	* This polymorphic destructor should be overridden if required.@n
	* This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since 2.1
	*/
	virtual ~ISectionTableViewItemProviderF(void) {}

	/**
	* Gets the total number of groups in the SectionTableView control.
	*
	* @since 2.1
	*
	* @return The total number of groups
	* @remarks  This method must be implemented so that it returns the total number of groups in the SectionTableView control.
	*/
	virtual int GetSectionCount(void) = 0;

	/**
	* Gets the total number of items in a specified group.
	*
	* @since 2.1
	*
	* @return  The total number of items in the specified group
	* @param[in] sectionIndex  The index of the section
	* @remarks  This method must be implemented so that it returns the total number of items for the specified section in the SectionTableView control.
	*/
	virtual int GetItemCount(int sectionIndex) = 0;

	/**
	* Creates a specified item.
	*
	* @since 2.1
	*
	* @return An item of the SectionTableView
	* @param[in] sectionIndex         The section index
	* @param[in] itemIndex            The item index
	* @param[in] itemWidth            The width of the item
	* @remarks
	*			- An application that uses the SectionTableView control must implement this method.
	*			- This method is expected to return an item that is allocated on a heap memory.
	*			- The returned item can be a simple or custom item.
	*			- The returned item should not be a null pointer.
	*			- Note that when the item is not required, the %SectionTableView control calls ISectionTableViewItemProviderF::DeleteItem() and the application
	*			deallocates the item.
	* @see     DeleteItem()
	*/
	virtual TableViewItem* CreateItem(int sectionIndex, int itemIndex, float itemWidth) = 0;

	/**
	* Deletes a specified item.
	*
	* @since 2.1
	*
	* @return @c true if the item is deallocated by this method, @n
	*         else @c false
	* @param[in] sectionIndex         The section index
	* @param[in] itemIndex            The item index
	* @param[in] pItem                The pointer to TableViewItem to delete
	* @remarks
	*			- An application that uses the SectionTableView control must implement this method.
	*			- Using this method, an application can deallocate the item.
	*			- If the application deallocates the item, this method must return @c true. This notifies the %SectionTableView control not to release the
	*			item. Otherwise, the item is deallocated by the %SectionTableView control.
	* @see     CreateItem()
	*/
	virtual bool DeleteItem(int sectionIndex, int itemIndex, TableViewItem* pItem) = 0;

	/**
	* Updates a specified item.
	*
	* @since 2.1
	*
	* @param[in] sectionIndex         The section index
	* @param[in] itemIndex            The item index
	* @param[in] pItem                The pointer to TableViewItem to update
	* @remarks
	*			- An application that uses the SectionTableView control must implement this method.
	*			- This method is called when the modification of an item is requested.
	*			- The application can change @c pItem using this method, so the user should consider this when using @c pItem in future.
	*/
	virtual void UpdateItem(int sectionIndex, int itemIndex, TableViewItem* pItem) = 0;

	/**
	* Gets the header text of a specified section.
	*
	* @since 2.1
	*
	* @return The header text of the specified section
	* @param[in] sectionIndex  The index of the group
	* @remarks
	*			- An application that uses the SectionTableView control must implement this method.
	*			- The header text will be left aligned.
	*/
	virtual Tizen::Base::String GetSectionHeader(int sectionIndex) = 0;

	/**
	* Checks whether the group has a section header or not.
	*
	* @since 2.1
	*
	* @return @c true if the section has the header, @n
	*         else @c false
	* @param[in] sectionIndex  The index of the section
	* @remarks An application that uses the SectionTableView control must implement this method.
	*/
	virtual bool HasSectionHeader(int sectionIndex) = 0;

	/**
	* Gets the footer text of a specified section.
	*
	* @since 2.1
	*
	* @return The footer text of the specified section
	* @param[in] sectionIndex  The index of the section
	* @remarks
	*			- An application that uses the SectionTableView control must implement this method.
	*			- The footer text will be right aligned.
	*/
	virtual Tizen::Base::String GetSectionFooter(int sectionIndex) = 0;

	/**
	* Checks whether the section has a footer or not.
	*
	* @since 2.1
	*
	* @return @c true if the section has the footer, @n
	*         else @c false
	* @param[in] sectionIndex  The index of the section
	* @remarks An application that uses the SectionTableView control must implement this method.
	*/
	virtual bool HasSectionFooter(int sectionIndex) = 0;

	/**
	* Gets the default height of an item.
	*
	* @since 2.1
	*
	* @return  The default height of an item
	* @remarks This method must be implemented so that it returns the default height of items in the SectionTableView control.
	*/
	virtual float GetDefaultItemHeight(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void ISectionTableViewItemProviderF_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void ISectionTableViewItemProviderF_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void ISectionTableViewItemProviderF_Reserved3(void) {}
}; // ISectionTableViewItemProviderF

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ISECTION_TABLE_VIEW_ITEM_PROVIDER_F_H_
