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
 * @file	FUiIExpandableItemEventListener.h
 * @brief	This is the header file for the %IExpandableItemEventListener interface.
 *
 * This header file contains the declarations of the %IExpandableItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called.
 *
 */
#ifndef _FUI_IEXPANDABLE_ITEM_EVENT_LISTENER_H_
#define _FUI_IEXPANDABLE_ITEM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiIItemEventListener.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen {namespace Ui
{

/**
 * @if OSPDEPREC
 * @interface	IExpandableItemEventListener
 * @brief      <i> [Deprecated] </i>  This interface implements a listener for the item events.
 *
 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedTableViewItemEventListener interface.
 * @since		2.0
 *
 * The %IExpandableItemEventListener interface implements a listener for the item events.
 * A class that needs to process an item event
 * must implement this interface. The object created with that class is registered with a UI Control using the controls.
 * ExpandableList::AddExpandableItemEventListener() method. When the item event occurs, that instance's OnItemStateChanged() method is invoked.
 * @endif
 */
class _OSP_EXPORT_ IExpandableItemEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
         * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This interface is deprecated. Instead of using this interface, use the IGroupedTableViewEventListener interface.
	 * @since			2.0
	 * @endif
	 */
	virtual ~IExpandableItemEventListener(void) {}

	/**
         * @if OSPDEPREC
	 * Called when the state of CustomListItem in the ExpandableList is changed. @n
	 * If a main item is selected, the index of the sub-item is @c -1.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated	This interface is deprecated. Instead of using this interface, use the IGroupedTableViewEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]  source		The source control from which the event is fired
	 * @param[in]  mainIndex	The main index of the item
	 * @param[in]  subIndex     The sub index of the item
	 * @param[in]  itemId       The item ID
	 * @param[in]  status       The state of the item
	 * @remarks Implement this method in a class that derives %IExpandableItemEventListener to handle the user interaction at the CustomListItem of the
	 *			ExpandableList.
         * @endif
	 */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int mainIndex, int subIndex, int itemId, Tizen::Ui::ItemStatus status) = 0;


	/**
          * @if OSPDEPREC
	  * Called when the state of an element in CustomListItem in ExpandableList is changed. @n
	  * If a main item is selected, the index of the sub-item is @c -1.
	  * @brief       <i> [Deprecated] </i>
	  * @deprecated	This interface is deprecated. Instead of using this interface, use the IGroupedTableViewEventListener interface.
	  * @since		2.0
	  *
	  * @param[in]	source			The source control from which the event is fired
	  * @param[in]	mainIndex		The main index of the item
	  * @param[in]	subIndex		The sub index of the item
	  * @param[in]  itemId			The item ID
	  * @param[in]  elementId		The element ID
	  * @param[in]  status          The state of the element
	  * @remarks Implement this method in a class that derives %IExpandableItemEventListener to handle the user interaction at the element in
	  *			CustomListItem of ExpandableList.
	  * @endif
	  */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int mainIndex, int subIndex, int itemId, int elementId, Tizen::Ui::ItemStatus status) = 0;

}; //IExpandableItemEventListener

}} // Tizen::Ui

#endif // _FUI_IEXPANDABLE_ITEM_EVENT_LISTENER_H_
