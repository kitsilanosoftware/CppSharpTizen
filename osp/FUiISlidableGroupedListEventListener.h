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
 * @file	FUiISlidableGroupedListEventListener.h
 * @brief	This is the header file for the %ISlidableGroupedListEventListener interface.
 *
 * This header file contains the declarations of the %ISlidableGroupedListEventListener interface. @n
 * If an event is generated, a method of this interface is called. @n
 * So, if an application performs tasks related to item events, it uses the methods of this interface.
 *
 */
#ifndef _FUI_ISLIDABLE_GROUPED_LIST_EVENT_LISTENER_H_
#define _FUI_ISLIDABLE_GROUPED_LIST_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen {namespace Ui
{

/**
* @if OSPDEPREC
 * @interface	ISlidableGroupedListEventListener
 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableGroupedList.
 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedListViewItemEventListener interface.
 * @since		2.0
 *
 * The %ISlidableGroupedListEventListener interface implements a listener for receiving scroll events on SlidableGroupedList. @n
 * The role of this interface is similar to ISlidableListEventListener.
 * This interface is registered with a %SlidableGroupedList, using the SlidableGroupedList::AddSlidableGroupedListEventListener() method.
 * @endif
 */
class _OSP_EXPORT_ ISlidableGroupedListEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
         * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableGroupedList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedListViewItemEventListener interface.
	 * @since		2.0
         * @endif
	 */
	virtual ~ISlidableGroupedListEventListener(void) {}

	/**
         * @if OSPDEPREC
	 * Called when the SlidableGroupedList is about to be drawn and requests the listener to set the properties of the list such as the total height and the
	 * number of items in each group.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableGroupedList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedListViewItemEventListener interface.
	 * @since		2.0
	 * @param[in]   source		The source of the event
         * @endif
	 */
	virtual void OnListPropertyRequested(const Tizen::Ui::Control& source) = 0;

	/**
         * @if OSPDEPREC
	 * Called when the items need to be loaded to the top.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableGroupedList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedListViewItemEventListener interface.
	 * @since		2.0
	 * @param[in]	source		  The source of the event
	 * @param[in]   groupIndex	  The index of the list group
	 * @param[in]   itemIndex	  The index of the list item in the specified group
	 * @param[in]   numItems	  The number of items
         * @endif
	 */
	virtual void OnLoadToTopRequested(const Tizen::Ui::Control& source, int groupIndex, int itemIndex, int numItems) = 0;

	/**
         * @if OSPDEPREC
	 * Called when the items need to be loaded to the bottom.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableGroupedList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedListViewItemEventListener interface.
	 * @since		2.0
	 * @param[in]   source        The source of the event
	 * @param[in]   groupIndex	  The index of the list group
	 * @param[in]   itemIndex     The index of the list item in the specified group
	 * @param[in]   numItems      The number of items
         * @endif
	 */
	virtual void OnLoadToBottomRequested(const Tizen::Ui::Control& source, int groupIndex, int itemIndex, int numItems) = 0;

	/**
         * @if OSPDEPREC
	 * Called when an item is about to be unloaded from memory. @n
	 * The user-allocated resources associated with the item to be unloaded need to be freed when OnUnloadItemRequested() is called.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableGroupedList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IGroupedListViewItemEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]   source	        The source of the event
	 * @param[in]   groupIndex	    The index of the list group
	 * @param[in]   itemIndex       The index of the list item in the specified group
         * @endif
	 */
	virtual void OnUnloadItemRequested(const Tizen::Ui::Control& source, int groupIndex, int itemIndex) = 0;

}; //ISlidableGroupedListEventListener

}} //Tizen::Ui

#endif // _FUI_ISLIDABLE_GROUPED_LIST_EVENT_LISTENER_H_
