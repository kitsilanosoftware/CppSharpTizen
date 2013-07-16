//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file		FUiCtrlIFastScrollListener.h
 * @brief	This is the header file for the %IFastScrollListener interface.
 *
 * This header file contains the declarations of the %IFastScrollListener interface. @n
 * If item event is generated, a method of this class will be called. @n
 * Applications that perform tasks related to the item event call methods of this class.
 *
 */
#ifndef _FUI_CTRL_IFAST_SCROLL_LISTENER_H_
#define _FUI_CTRL_IFAST_SCROLL_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseString.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen { namespace Ui { namespace Controls
{

// constants
/**
 * @if OSPDEPREC
 * The string constant representing the index of the magnifying icon in a fast scroll.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This object is provided only for backward compatibility and will be deleted in a future release.
 *				Instead of using this object, it is recommended to use FAST_SCROLL_SEARCH_ICON_INDEX_STRING.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String FAST_SCROLL_SEARCH_ICON_INDEX;

// constants
/**
 * The string constant representing the index of the magnifying icon in a fast scroll.
 *
 * @since 2.0
 */
_OSP_EXPORT_ extern const wchar_t* const FAST_SCROLL_SEARCH_ICON_INDEX_STRING;

/**
 * @interface	IFastScrollListener
 * @brief		This interface implements the listener for the fast scroll event.
 *
 * @since		2.0
 *
 * The %IFastScrollListener interface is the listener interface for receiving fast scroll events.
 * The class that processes a fast scroll event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddFastScrollListener() method. When the fast scroll event occurs, the
 * OnFastScrollIndexChanged() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.

 */
class _OSP_EXPORT_ IFastScrollListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IFastScrollListener(void) {}

	/**
	 * Called when an index is selected.
	 *
	 * @since				2.0
	 *
	 * @param[in]   source			The source of the event
	 * @param[in]   index			The index
	 * @remarks     When the search icon index is enabled, you can check whether the search icon index is touched by comparing @c index with the string
	 *				constant ::FAST_SCROLL_SEARCH_ICON_INDEX.
	 *
	 */
	virtual void OnFastScrollIndexSelected(Tizen::Ui::Control& source, Tizen::Base::String& index) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	//  This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IFastScrollListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	//
	virtual void IFastScrollListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IFastScrollListener_Reserved3(void) {}
}; // IFastScrollListener

};
};
};

#endif
