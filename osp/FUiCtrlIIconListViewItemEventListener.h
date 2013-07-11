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
 * @file	FUiCtrlIIconListViewItemEventListener.h
 * @brief	This is the header file for the %IIconListViewItemEventListener interface.
 *
 * This header file contains the declarations of the %IIconListViewItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called. @n
 * So, if an application does some jobs related to the item event, use the methods of this interface.
 */

#ifndef _FUI_CTRL_IICON_LIST_VIEW_ITEM_EVENT_LISTENER_H_
#define _FUI_CTRL_IICON_LIST_VIEW_ITEM_EVENT_LISTENER_H_

// Includes
#include <FBaseRtIEventListener.h>
#include <FOspConfig.h>

namespace Tizen { namespace Ui { namespace Controls
{

class IconListView;

/**
 * @interface	IIconListViewItemEventListener
 * @brief		This interface implements the listener for the item event.
 *
 * @since		2.0
 *
 * The %IIconListViewItemEventListener interface is the listener interface for receiving IconListView item events.
 * The class that processes a list item event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddIIconListViewItemEventListener() method. When the list item event occurs, the
 * OnIconListViewItemStateChanged() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IIconListViewItemEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IIconListViewItemEventListener(void) {}

	/**
	 * Called when an item event occurs.
	 *
	 * @since   2.0
	 *
	 * @param[in] iconListView	The source of the event
	 * @param[in] index			The index of the item
	 * @param[in] status		The item status
	 */
	virtual void OnIconListViewItemStateChanged(Tizen::Ui::Controls::IconListView& iconListView, int index, Tizen::Ui::Controls::IconListViewItemStatus status) = 0;

	/**
	 * Called when the overlay bitmap is selected.
	 *
	 * @since 2.0
	 *
	 * @param[in] iconListView    	The source of the event
	 * @param[in] index           	The index of the item
	 * @param[in] overlayBitmapId   The overlay bitmap ID
	 */
	virtual void OnIconListViewOverlayBitmapSelected(Tizen::Ui::Controls::IconListView& iconListView, int index, int overlayBitmapId) {}

	/**
	 * Called when the item is reordered.
	 *
	 * @since 2.0
	 *
	 * @param[in] iconListView	The source of the event
	 * @param[in] indexFrom  	The start index of the item
	 * @param[in] indexTo 		The final index of the item
	 */
	virtual void OnIconListViewItemReordered(Tizen::Ui::Controls::IconListView&  iconListView, int indexFrom, int indexTo) {}

protected:
	// Following methods are reserved and may change its name at any time without prior notice.
	virtual void IconListViewItemEventListener_Reserved1(void) {}
	virtual void IconListViewItemEventListener_Reserved2(void) {}
	virtual void IconListViewItemEventListener_Reserved3(void) {}
}; // IIconListViewItemEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IICON_LIST_VIEW_ITEM_EVENT_LISTENER_H_
