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
 * @file		FUiITextBlockEventListener.h
 * @brief		This is the header file for the %ITextBlockEventListener interface.
 *
 * This header file contains the declarations of the %ITextBlockEventListener interface.
 */
#ifndef _FUI_ITEXT_BLOCK_EVENT_LISTENER_H_
#define _FUI_ITEXT_BLOCK_EVENT_LISTENER_H_

// Includes
#include <FBaseRtIEventListener.h>

// Forward declaration
namespace Tizen { namespace Ui
{
class Control;
}} // Tizen::Ui

// Namespace declaration
namespace Tizen { namespace Ui
{
/**
 * @interface	ITextBlockEventListener
 * @brief	    This interface implements the listener for the text block events.
 *
 * @since	    2.0
 *
 * The %ITextBlockEventListener interface is the listener interface for receiving text block selection events, for example, from EditFields.
 * The class that processes a text block selection event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddTextBlockEventListener() method. When the text block selection event
 * occurs, the OnTextBlockSelected() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>.

 */
class _OSP_EXPORT_ ITextBlockEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~ITextBlockEventListener(void) {}


// Operation
public:
	/**
	 * Called when a text block is selected.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source  The source of the event
	 * @param[in]   start   The start index of the selected text block
	 * @param[in]   end     The end index of the selected text block
	 */
	virtual void OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end) = 0;


// Reserves
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextBlockEventListener_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextBlockEventListener_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextBlockEventListener_Reserved3(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextBlockEventListener_Reserved4(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ITextBlockEventListener_Reserved5(void) { }
}; // ITextBlockEventListener

}} //Tizen::Ui

#endif // _FUI_ITEXT_BLOCK_EVENT_LISTENER_H_
