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
 * @file		FUiITextEventListener.h
 * @brief		This is the header file for the %ITextEventListener interface.
 *
 * This header file contains the declarations of the %ITextEventListener interface. @n
 * If a change event is generated, a method of this interface is called. @n
 * So, if the applications perform tasks related to change events, use the methods of this interface.
 *
 */
#ifndef _FUI_ITEXT_EVENT_LISTENER_H_
#define _FUI_ITEXT_EVENT_LISTENER_H_

// Includes
#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>

namespace Tizen { namespace Ui
{
class Control;
}} // Tizen::Ui

namespace Tizen {namespace Ui
{

/**
 * @interface	ITextEventListener
 * @brief		This interface implements the listener for text events.
 *
 * @since		2.0
 *
 * The %ITextEventListener interface is the listener interface for receiving text events, for example, from EditFields.
 * The class that processes a text event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control's AddTextEventListener() method. When the text event occurs, the OnTextValueChanged() method of
 * that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>, <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>, <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_textbox.htm">TextBox</a>, and <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_searchbar.htm">SearchBar</a>.

 */
class ITextEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			2.0
	 */
	virtual ~ITextEventListener(void) {}

	/**
	 * Called when a text is changed.
	 *
	 * @since			2.0
	 *
	 * @param[in]       source		The source of the event
	 * @remarks			For EditField or EditArea with INPUT_STYLE_FULLSCREEN input style, this listener method is invoked when the user presses "Done"
	 *					soft-key. Whereas, for %EditField or %EditArea with INPUT_STYLE_OVERLAY input style, this method is called whenever the user presses a
	 *					key.
	 * @remarks         Note that when a non-character key is pressed, OnTextValueChanged() callback is invoked.
	 */
	virtual void OnTextValueChanged(const Tizen::Ui::Control& source) = 0;

	/**
	 * Called when a change made to the text is canceled.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @remarks     This listener method is called when the user presses "Cancel" soft-key for EditField or EditArea with INPUT_STYLE_FULLSCREEN input
	 *				style.
	 */
	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source) = 0;

// Reserves
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextEventListener_Reserved3(void) {}
}; // ITextEventListener

}} // Tizen::Ui

#endif // _FUI_ITEXT_EVENT_LISTENER_H_
