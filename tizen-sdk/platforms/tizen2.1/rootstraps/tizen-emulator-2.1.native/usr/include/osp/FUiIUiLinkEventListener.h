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
 * @file		FUiIUiLinkEventListener.h
 * @brief		This is the header file for the %IUiLinkEventListener interface.
 *
 * This header file contains the declarations of the %IUiLinkEventListener interface.
 */
#ifndef _FUI_IUI_LINK_EVENT_LISTENER_H_
#define _FUI_IUI_LINK_EVENT_LISTENER_H_

// Includes
#include <FBaseUtilTypes.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base
{
class String;
}} // Tizen::Base

// Namespace declaration
namespace Tizen { namespace Ui
{

class Control;

/**
 * @interface    IUiLinkEventListener
 * @brief        This interface implements the listener for link events.
 *
 * @since        2.0
 *
 * The %IUiLinkEventListener interface is the listener interface for receiving link click events, for example, from EditFields.
 * The class that processes a link click event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddUiLinkEventListener() method. When the link click event occurs, the OnLinkClicked()
 * method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>, <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_textbox.htm">TextBox</a>, and <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.

 */
class _OSP_EXPORT_ IUiLinkEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IUiLinkEventListener(void) {}

	// Operation
public:
	/**
	 * Called when a link is clicked.
	 *
	 * @since		  2.0
	 *
	 * @param[in]     source   	The source of the event
	 * @param[in]     text     	The text
	 * @param[in]     linkType 	The link type
	 * @param[in]     link     	The optional link text
	 * @remarks       If the clicked link does not contain an optional link text, then the value of @c text and @c link will be the same.
	 */
	virtual void OnLinkClicked(Tizen::Ui::Control& source, const Tizen::Base::String& text, Tizen::Base::Utility::LinkType linkType, const Tizen::Base::String& link) = 0;

// Reserves
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IUiLinkEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IUiLinkEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IUiLinkEventListener_Reserved3(void) {}
}; // IUiLinkEventListener

} } // Tizen::Ui

#endif  // _FUI_IUI_LINK_EVENT_LISTENER_H_
