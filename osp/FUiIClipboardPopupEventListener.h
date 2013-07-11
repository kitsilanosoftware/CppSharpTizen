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
 * @file		FUiIClipboardPopupEventListener.h
 * @brief		This is the header file for the %IClipboardPopupEventListener interface.
 *
 * This header file contains the declarations of the %IClipboardPopupEventListener interface. @n
 * If the item event is generated, a method of this interface will be called. @n
 * The applications that perform tasks related to the item event, must call methods of this interface.
 */

#ifndef _FUI_ICLIPBOARD_POPUP_EVENT_LISTENER_H_
#define _FUI_ICLIPBOARD_POPUP_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{
class ClipboardItem;

/**
 * @interface	IClipboardPopupEventListener
 * @brief		This interface defines the listener for clipboard pop-up events.
 *
 * @since		2.0
 *
 * The %IClipboardPopupEventListener interface is the listener interface for receiving clipboard pop-up events.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/clipboard.htm">Clipboard</a>.
 */
class _OSP_EXPORT_ IClipboardPopupEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since     2.0
	 */
	virtual ~IClipboardPopupEventListener(void) {}

	/**
	 * Called when the clipboard popup is closed by user interaction.
	 *
	 * @since       2.0
	 *
	 * @param[in]   pClipboardItem	The pointer to ClipboardItem that
	 *                                  is selected, @n
	 *                                  else @c null if no item is selected
	 * @remarks     @c pClipboardItem is deleted by the system after this method call.
	 */
	virtual void OnClipboardPopupClosed(const ClipboardItem* pClipboardItem) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IClipboardPopupEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IClipboardPopupEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IClipboardPopupEventListener_Reserved3(void) {}
}; // IClipboardPopupEventListener

}} // Tizen::Ui

#endif //_FUI_ICLIPBOARD_POPUP_EVENT_LISTENER_H_
