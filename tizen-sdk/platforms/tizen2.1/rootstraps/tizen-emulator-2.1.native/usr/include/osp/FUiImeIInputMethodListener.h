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
 * @file FUiImeIInputMethodListener.h
 * @brief This is the header file for the %IInputMethodListener interface.
 *
 * This header file contains the declarations of the %IInputMethodListener interface.
 */

#ifndef _FUI_IME_IINPUT_METHOD_LISTENER_H_
#define _FUI_IME_IINPUT_METHOD_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseString.h>
#include <FGrpRectangle.h>
#include <FOspConfig.h>
#include <FUiInputConnectionTypes.h>

namespace Tizen { namespace Ui { namespace Ime {

/**
 * @interface	IInputMethodListener
 * @brief	This interface provides a listener for the InputMethod class to receive asynchronous callbacks from the input service.
 * @since	2.1
 *
 * @remarks The IME application developers can implement a class that is derived from %IInputMethodListener and use it to receive asynchronous callbacks
 * from the input service.
 *
 * The %IInputMethodListener interface provides a listener for the InputMethod class to receive asynchronous callbacks from the input service.
 *
 * The following example demonstrates how to use the %IInputMethodListener interface.
 * @code
 * #include <FUi.h>
 *
 * class MyListener
 * 	: public IInputMethodListener
 * {
 * 	//...
 * 	virtual void OnCursorPositionChanged(int position); 
 *	virtual void OnOpaqueCommandReceived(const Tizen::Base::String& command); 
 *	virtual void OnSurroundingTextReceived(const Tizen::Base::String& text, int cursorPosition);
 * 	//...
 * };
 * @endcode
 *
 */
class _OSP_EXPORT_ IInputMethodListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. @n This way, the destructors of the derived classes are called when the destructor of this
	* interface is called.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*/
	virtual ~IInputMethodListener(void) {}

	/**
	* Called when the position of the cursor in an associated text input UI control changes.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in]	position The position of the cursor
	*/
	virtual void OnCursorPositionChanged(int position) {}

	/**
	* Called when a client of the input method sends the opaque command. @n
	* The opaque command is the engaged command between the certain input method and their clients which know opaque commands. @n
	* It is for additional options that the input method does not provide.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] command The opaque command that is a string format like "org.tizen.MyApp.OpaqueCommand=True"
	*/
	virtual void OnOpaqueCommandReceived(const Tizen::Base::String& command) {}

	/**
	* Called when an associated text input UI control responds to a request with the surrounding text. @n
	* The surrounding text can be requested by the Tizen::Ui::Ime::InputMethod::RequestSurroundingText() method.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] text The surrounding text @n
	*				The length of the surrounding text can be less than that requested by the user.
	* @param[in] cursorPosition The position of the cursor
	*/
	virtual void OnSurroundingTextReceived(const Tizen::Base::String& text, int cursorPosition) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodListener_Reserved4(void) {}
};

}}} // Tizen::Ui::Ime

#endif // _FUI_IME_IINPUT_METHOD_LISTENER_H_
