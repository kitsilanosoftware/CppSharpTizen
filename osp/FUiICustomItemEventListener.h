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
 * @file		FUiICustomItemEventListener.h
 * @brief		This is the header file for the %ICustomItemEventListener interface.
 *
 * This header file contains the declarations of the ICustomItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called. @n
 * Application doing tasks related to the item event use the methods of this interface.
 *
 */
#ifndef _FUI_ICUSTOM_ITEM_EVENT_LISTENER_H_
#define _FUI_ICUSTOM_ITEM_EVENT_LISTENER_H_

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
 * @interface	ICustomItemEventListener
 * @brief		<i> [Deprecated] </i> This interface implements the listener for the item event.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use IListViewItemEventListener class.
 * @since		2.0
 *
 * The %ICustomItemEventListener interface is the listener interface for receiving item events. The class that processes an item event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's
 * AddCustomItemEventListener() method. When the item event occurs, the OnItemStateChanged() method of that object is invoked.
 * @endif
 */
class _OSP_EXPORT_ ICustomItemEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use IListViewItemEventListener class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~ICustomItemEventListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called when the state of CustomListItem is changed.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use IListViewItemEventListener class.
	 * @since		2.0
	 *
	 * @param[in]   source		The source control from which the event is fired
	 * @param[in]   index       The index of the item
	 * @param[in]   itemId      The item ID
	 * @param[in]   status      The state of the item
	 * @remarks     Implement this method in a class which derives %ICustomItemEventListener to handle the user interaction at the CustomListItem.
	 * @remarks		If CustomList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is called when the radio button is selected.
	 * @endif
	 */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, Tizen::Ui::ItemStatus status) = 0;


	/**
	 * @if OSPDEPREC
	 * Called when the state of an element in the CustomListItem is changed.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use IListViewItemEventListener class.
	 * @since			2.0
	 *
	 * @param[in]       source		The source control from which the event is fired
	 * @param[in]       index		The index of the item
	 * @param[in]       itemId		The item ID
	 * @param[in]       elementId	The element ID
	 * @param[in]       status		The state of the element
	 * @remarks         Implement this method in a class which derives %ICustomItemEventListener to handle the user interaction at the element in
	 *					CustomListItem.
	 * @remarks         If CustomList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is not called when the radio button is selected.
	 *					Instead, OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, Tizen::Ui::ItemStatus status) is called.
	 * @endif
	 */
	virtual void OnItemStateChanged(const Tizen::Ui::Control& source, int index, int itemId, int elementId, Tizen::Ui::ItemStatus status) = 0;


}; //ICustomItemEventListener

}} // Tizen::Ui

#endif // _FUI_ICUSTOM_ITEM_EVENT_LISTENER_H_
