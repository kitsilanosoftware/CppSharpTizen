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
 * @file	FUiIGroupedItemEventListener.h
 * @brief	This is the header file for the %IGroupedItemEventListener interface.
 *
 * This header file contains the declarations of the %IGroupedItemEventListener interface.
 */

#ifndef _FUI_IGROUPED_ITEM_EVENT_LISTENER_H_
#define _FUI_IGROUPED_ITEM_EVENT_LISTENER_H_

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
 * @interface		IGroupedItemEventListener
 * @brief			<i> [Deprecated] </i> This interface implements the listener for the events on the items of GroupedList.
 *
 * @deprecated     This class is deprecated. Instead of using this class, use IGroupedListViewItemEventListener class.
 * @since			2.0
 *
 *
 * The %IGroupedItemEventListener interface implements a listener for detecting state changes on the item of the grouped list.
 * The interface is registered with a GroupedList, using the control's AddGroupedItemEventListener() method.
 * @endif
 */
class _OSP_EXPORT_ IGroupedItemEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * @if OSPDEPREC
	 * This is the default constructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use IGroupedListViewItemEventListener class.
	 * @since		2.0
	 * @endif
	 */
	IGroupedItemEventListener(void) {};

	/**
	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use IGroupedListViewItemEventListener class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~IGroupedItemEventListener(void) {};

	/**
	 * @if OSPDEPREC
	 * Called when the state of an element in the CustomListItem instance in the GroupedList instance is changed. @n
	 * For example, this method is called when an element of %CustomListItem in %GroupedList is checked, unchecked, or selected.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use IGroupedListViewItemEventListener class.
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   groupIndex      The index of the list group
	 * @param[in]   itemIndex       The index of the list item in the specified group
	 * @param[in]   itemId          The item ID
	 * @param[in]   elementId       The element ID
	 * @param[in]   status          The state of the element
	 * @remarks     If GroupedList or SlidableGroupedList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is not called when the
	 *				radio button is selected. Instead, OnItemStateChanged(const Tizen::Ui::Control &source, int groupIndex, int itemIndex, int itemId,
	 *				Tizen::Ui::ItemStatus status) is called.
	 * @endif
	 */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int groupIndex, int itemIndex, int itemId, int elementId, Tizen::Ui::ItemStatus status) = 0;

	/**
	 * @if OSPDEPREC
	 * Called when the state of an item in the grouped list is changed. @n
	 * For example, this method is called when an item of the GroupedList control is checked, unchecked, or selected.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. Instead of using this class, use IGroupedListViewItemEventListener class.
	 * @since		2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   groupIndex      The index of the list group
	 * @param[in]   itemIndex       The index of the list item in the specified group
	 * @param[in]   itemId          The item ID
	 * @param[in]   status          The state of the item
	 * @remarks		If GroupedList or SlidableGroupedList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is called when the radio
	 *				button is selected.
	 * @endif
	 */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int groupIndex, int itemIndex, int itemId, Tizen::Ui::ItemStatus status) = 0;
}; //IGroupedItemEventListener

}} // Tizen::Ui

#endif //_FUI_IGROUPED_ITEM_EVENT_LISTENER_H_
