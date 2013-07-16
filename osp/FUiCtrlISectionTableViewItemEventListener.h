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
* @file FUiCtrlISectionTableViewItemEventListener.h
* @brief This is the header file for the %ISectionTableViewItemEventListener interface.
*
* This header file contains the declarations of the %ISectionTableViewItemEventListener interface. @n
* If an item event is generated, a method of this interface is called.
* So, if an application does some jobs related to the item event, use the methods of this interface.
*
*/
#ifndef _FUI_CTRL_ISECTION_TABLE_VIEW_ITEM_EVENT_LISTENER_H_
#define _FUI_CTRL_ISECTION_TABLE_VIEW_ITEM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{
class SectionTableView;
class TableViewItem;
class TableViewContextItem;


/**
* @interface ISectionTableViewItemEventListener
* @brief  This interface implements the listener for item event.
*
* @since 2.0
*
* The %ISectionTableViewItemEventListener interface implements a listener for receiving item change events.
* The class that is interested in processing an item event implements this interface,
* and the instance created with that class is registered with a UI control, using the control's
* AddSectionTableViewItemEventListener() method. When the item event occurs, the OnItemStateChanged() method of that object is invoked.
*/
class _OSP_EXPORT_ ISectionTableViewItemEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required.@n
	* This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since 2.0
	*/

	virtual ~ISectionTableViewItemEventListener(void) {}
	/**
	* Called when the state of a TableViewItem in the SectionTableView is changed.
	*
	* @since 2.0
	*
	* @param[in] tableView				The source of the event
	* @param[in] sectionIndex			The section index
	* @param[in] itemIndex				The item index
	* @param[in] pItem					The target item
	* @param[in] status					The status of the item
	* @remarks  This method is called when the TableViewItem in the SectionTableView is checked, unchecked, or selected.
	*/
	virtual void OnSectionTableViewItemStateChanged(Tizen::Ui::Controls::SectionTableView& tableView, int sectionIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem, Tizen::Ui::Controls::TableViewItemStatus status) = 0;

	/**
	* Called when the TableViewContextItem is opened or closed.
	*
	* @since 2.0
	*
	* @param[in] tableView				The source of the event
	* @param[in] sectionIndex			The section index
	* @param[in] itemIndex				The item index
	* @param[in] pContextItem			The context item which is opened or closed
	* @param[in] activated				@c true if a context item is opened, @n
	*                                  else @c false
	*/
	virtual void OnSectionTableViewContextItemActivationStateChanged(Tizen::Ui::Controls::SectionTableView& tableView, int sectionIndex, int itemIndex, Tizen::Ui::Controls::TableViewContextItem* pContextItem, bool activated) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISectionTableViewItemEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISectionTableViewItemEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISectionTableViewItemEventListener_Reserved3(void) {}
}; // ISectionTableViewItemEventListener

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_ISECTION_TABLE_VIEW_ITEM_EVENT_LISTENER_H_
