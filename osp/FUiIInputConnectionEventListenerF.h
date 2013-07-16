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
 * @file		FUiIInputConnectionEventListenerF.h
 * @brief	This is the header file for the %IInputConnectionEventListenerF interface.
 *
 * This header file contains the declarations of the %IInputConnectionEventListenerF interface.
 *
 *
 */

#ifndef _FUI_IINPUT_CONNECTION_EVENT_LISTENER_F_H_
#define _FUI_IINPUT_CONNECTION_EVENT_LISTENER_F_H_

#include <FBaseRtIEventListener.h>
#include <FLclLocale.h>
#include <FUiInputConnectionTypes.h>

namespace Tizen { namespace Base {
	class String;
}} // Tizen::Base

namespace Tizen { namespace Graphics {
	class FloatRectangle;
}} // Tizen::Graphics


namespace Tizen { namespace Ui {

class InputConnection;

/**
 * @interface	IInputConnectionEventListenerF
 * @brief	This interface defines methods for processing between the InputConnection and the input method.
 *
 * @since 2.1
 *
 * The %IInputConnectionEventListener interface defines methods for processing between the InputConnection and the input method. It is possible to not work the callback depending on the current InputMethod.
 */
class _OSP_EXPORT_ IInputConnectionEventListenerF
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.1
	 */
	virtual ~IInputConnectionEventListenerF(void) {}

	/**
	 * Called when the show state of the InputPanel is changed.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	showState	The state
	 */
	virtual void OnInputConnectionPanelShowStateChanged(Tizen::Ui::InputConnection& source, Tizen::Ui::InputPanelShowState showState) = 0;

	/**
	 * Called when the language of the InputPanel is changed.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	language	The language code
	 */
	virtual void OnInputConnectionPanelLanguageChanged(Tizen::Ui::InputConnection& source, Tizen::Locales::LanguageCode language) = 0;

	/**
	 * Called when the size of the InputPanel is changed.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	bounds		The size
	 */
	virtual void OnInputConnectionPanelBoundsChanged(Tizen::Ui::InputConnection& source, const Tizen::Graphics::FloatRectangle& bounds) = 0;

	/**
	 * Called when the show state of the Text-Prediction is changed.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	isShown		The state
	 */
	virtual void OnInputConnectionTextPredictionShowStateChanged(Tizen::Ui::InputConnection& source, bool isShown) = 0;

	/**
	 * Called when the size of the Text-Prediction is changed.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	bounds		The size
	 */
	virtual void OnInputConnectionTextPredictionBoundsChanged(Tizen::Ui::InputConnection& source, const Tizen::Graphics::FloatRectangle& bounds) = 0;

	/**
	 * Called when the key of the InputPanel is selected.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	committedText		The committed text
	 */
	virtual void OnInputConnectionTextCommitted(Tizen::Ui::InputConnection& source, const Tizen::Base::String& committedText) = 0;

	/**
	 * Called when the key of the InputPanel is selected during the composing.
	 *
	 * @since 2.1
	 *
	 * @param[in] 	source		The source of the event
	 * @param[in] 	composingText		The composing text
	 * @param[in] 	cursorPosition	The current cursor position
	 */
	virtual void OnInputConnectionComposingTextChanged(Tizen::Ui::InputConnection& source, const Tizen::Base::String& composingText, int cursorPosition) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionEventListenerF_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionEventListenerF_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionEventListenerF_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionEventListenerF_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionEventListenerF_Reserved5(void) {}
}; // IInputConnectionEventListenerF

}} // Tizen::Ui
#endif // _FUI_IINPUT_CONNECTION_EVENT_LISTENER_F_H_

