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
 * @file	FUiISlidableListEventListener.h
 * @brief	This is the header file for the %ISlidableListEventListener interface.
 *
 * This header file contains the declarations of the %ISlidableListEventListener interface. @n
 * If the event is generated, a method of this interface is called. @n
 * So, if applications do jobs related to item events, use the methods of this interface.
 *
 */
#ifndef _FUI_ISLIDABLE_LIST_EVENT_LISTENER_H_
#define _FUI_ISLIDABLE_LIST_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen {namespace Ui
{

/**
 * @if OSPDEPREC
 * @interface	ISlidableListEventListener
 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableList.
 * @deprecated  This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
 * @since		2.0
 *
 *
 * The %ISlidableListEventListener interface implements a listener for receiving scroll events on SlidableList. This listener is implemented
 * to allow the application to load the items as needed, as the user scrolls through the list.
 * The class is registered with a SlidableList, using the control's AddSlidableListEventListener() method.
 * @endif
 */
class _OSP_EXPORT_ ISlidableListEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
  	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
         * @endif
	 */
	virtual ~ISlidableListEventListener(void) {}

	/**
  	 * @if OSPDEPREC
	 * Called when the slidable list is about to be drawn and requests to set the properties of the list such as the total height.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
         * @endif
	 */
	virtual void OnListPropertyRequested(const Tizen::Ui::Control& source) = 0;

	/**
  	 * @if OSPDEPREC
	 * Called when the items need to be loaded to the top.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @param[in]	index		The index of the item
	 * @param[in]	numItems	The number of items
         * @endif
	 */
	virtual void OnLoadToTopRequested(const Tizen::Ui::Control& source, int index, int numItems) = 0;

	/**
  	 * @if OSPDEPREC
	 * Called when the items need to be loaded to the bottom.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]   index		The index of the item
	 * @param[in]	numItems	The number of items
         * @endif
	 */
	virtual void OnLoadToBottomRequested(const Tizen::Ui::Control& source, int index, int numItems) = 0;

	/**
  	 * @if OSPDEPREC
	 * Called when an item is about to be unloaded from memory. @n
	 * The user-allocated resources associated with the item must be freed before unloading, when OnUnloadItemRequested() is called.
	 *
	 * @brief		<i> [Deprecated] </i> This interface implements the listener for events on SlidableList.
	 * @deprecated  This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]	source		The source of the event
	 * @param[in]	index		The index of the item
         * @endif
	 */
	virtual void OnUnloadItemRequested(const Tizen::Ui::Control& source, int index) = 0;

}; //ISlidableListEventListener

}} //Tizen::Ui

#endif // _FUI_ISLIDABLE_LIST_EVENT_LISTENER_H_
