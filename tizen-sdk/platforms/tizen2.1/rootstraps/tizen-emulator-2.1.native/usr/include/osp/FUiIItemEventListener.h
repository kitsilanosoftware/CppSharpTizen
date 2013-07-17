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
 * @file	FUiIItemEventListener.h
 * @brief	This is the header file for the %IItemEventListener interface.
 *
 * This header file contains the declarations of the %IItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called. @n
 * So, if an application performs tasks related to the item event, use the methods of this interface.
 *
 */
#ifndef _FUI_IITEM_EVENT_LISTENER_H_
#define _FUI_IITEM_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen {namespace Ui
{
/**
 * @if OSPDEPREC
 * @enum		ItemStatus
 *
 * Defines the constants used to identify the item state.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enum is deprecated. Instead of using this enum, use the ListItemStatus enumeration.
 * @since	2.0
 * @endif
 */
enum ItemStatus
{
	ITEM_CHECKED = 0,           /**< @if OSPDEPREC The item has been checked (toggle of the check area) @endif */
	ITEM_UNCHECKED,             /**< @if OSPDEPREC The item has been unchecked (toggle of the check area) @endif */
	ITEM_SELECTED,              /**< @if OSPDEPREC The item has been selected (non-check area of the item) @endif */
	ITEM_HIGHLIGHTED            /**< @if OSPDEPREC The item has been highlighted (non-check area of the item) @b Since: @b 1.1 @endif */
};

/**
 * @if OSPDEPREC
 * @interface		IItemEventListener
 * @brief			<i> [Deprecated] </i> This interface implements the listener for the item event.
 * @deprecated      This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
 * @since			2.0
 *
 * The %IItemEventListener interface is the listener interface for receiving item events. The class that processes an item event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's
 * AddItemEventListener() method. When the item event occurs, the OnItemStateChanged() method of that instance is invoked.
 * @endif
 */
class _OSP_EXPORT_ IItemEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
         * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
         * @endif
	 */
	virtual ~IItemEventListener(void) {}

	/**
         * @if OSPDEPREC
	 * Called when an item event occurs.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This interface is deprecated. Instead of using this interface, use the IListViewItemEventListener interface.
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]   index		The index of the item
	 * @param[in]   itemId		The item ID
	 * @param[in]   status		The item status
         * @endif
	 */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, Tizen::Ui::ItemStatus status) = 0;
}; //IItemEventListener

}} // Tizen::Ui

#endif // _FUI_IITEM_EVENT_LISTENER_H_
