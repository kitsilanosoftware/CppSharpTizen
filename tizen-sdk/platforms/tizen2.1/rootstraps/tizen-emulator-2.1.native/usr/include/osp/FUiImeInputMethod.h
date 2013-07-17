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
 * @file FUiImeInputMethod.h
 * @brief This is the header file for the %InputMethod class.
 *
 * This header file contains the declarations of the %InputMethod class.
 */

#ifndef _FUI_IME_INPUT_METHOD_H_
#define _FUI_IME_INPUT_METHOD_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FGrpFloatRectangle.h>
#include <FOspConfig.h>
#include <FUiIKeyEventListener.h>
#include <FUiImeIInputMethodListener.h>
#include <FUiImeIInputMethodProvider.h>
#include <FUiImeIInputMethodProviderF.h>

namespace Tizen { namespace Ui { namespace Ime {

class _InputMethodImpl;

/**
 * @class InputMethod
 * @brief This class provides a standard implementation of the %InputMethod class.
 * @since	2.1
 *
 * @final This class is not intended for extension.
 * @remarks	The IME application developers can use the %InputMethod class to communicate with the associated text input UI control. First, set the provider which
 * provides attributes of the soft input panel. Next, set the listener which lets the IME application receive asynchronous callbacks from the input service. These
 * allow the IME application to interact with the associated text input UI control properly. After that, request the %InputMethod class to send a text or a key event
 * which is to be displayed in the associated text input UI control.
 *
 * The %InputMethod class provides a standard implementation of the %InputMethod class.
 *
 * The following example demonstrates how to use the %InputMethod class.
 * @code
 * #include <new>
 * #include <FUi.h>
 *
 * using namespace Tizen::Ui::Ime;
 *
 * class MyProvider
 * 	: public IInputMethodProvider
 * {
 * 		//...
 * };
 *
 * class MyListener
 * 	: public IInputMethodListener
 * {
 * 		//...
 * };
 *
 * class MyImeApp
 * {
 * public:
 * 		//...
 * 	void Construct();
 * };
 *
 * void
 * MyImeApp::Construct()
 * {
 * 	// Gets an instance of InputMethod
 * 	InputMethod* pInputMethod = InputMethod::GetInstance();
 *
 * 	// Creates an instance of MyProvider and sets it as a provider
 * 	MyProvider* pMyProvider = new(std::nothrow) MyProvider();
 * 	pInputMethod->SetInputMethodProvider(pMyProvider);
 *
 * 	// Creates an instance of MyListener and adds it to the input method
 * 	MyListener* pMyListener = new(std::nothrow) MyListener();
 * 	pInputMethod->SetInputMethodListener(pMyListener);
 * }
 * @endcode
 *
 */

class _OSP_EXPORT_ InputMethod
	: public Tizen::Base::Object
{
public:
	/**
	* Gets an instance of %InputMethod.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An instance of %InputMethod
	* @exception E_SUCCESS The method is successful.
	* @exception E_CONNECTION_FAILED The connection to the input service fails.
	* @exception E_SYSTEM A failure occurs from the underlying system.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	* @remarks 
	* - The specific error code can be accessed using the GetLastResult() method.
	* - There is a high probability for an occurrence of an out-of-memory exception. @n If possible, check whether the exception is @c E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	*/
	static InputMethod* GetInstance(void);

	/**
	* Sets an instance of IInputMethodProvider. @n
	* The %InputMethod instance accepts only one provider. So users must unregister the provider by setting @c pProvider as @c null before deallocating
	* an instance of the provider.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] pProvider An instance of IInputMethodProvider
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	* @remarks 
	* - The specific error code can be accessed using the GetLastResult() method.
	* - The platform will call only the provider set by the SetInputMethodProviderF() method, if both IInputMethodProvider and IInputMethodProviderF are set.
	*/
	void SetInputMethodProvider(IInputMethodProvider* pProvider);

	/**
	* Sets an instance of IInputMethodProviderF. @n
	* The %InputMethod instance accepts only one provider. So users must unregister the provider by setting @c pProvider as @c null before deallocating
	* an instance of the provider.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] pProvider An instance of IInputMethodProviderF
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	* @remarks 
	* - The specific error code can be accessed using the GetLastResult() method.
	* - The platform will call only the provider set by the SetInputMethodProviderF() method, if both IInputMethodProvider and IInputMethodProviderF are set.
	*/
	void SetInputMethodProviderF(IInputMethodProviderF* pProvider);

	/**
	* Sets an instance of IInputMethodListener. @n
	* The %InputMethod instance accepts only one listener. So users must unregister the listener by setting @c pListener as @c null before deallocating an
	* instance of the listener.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] pListener An instance of IInputMethodListener
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	void SetInputMethodListener(IInputMethodListener* pListener);

	/**
	* Deletes a text at the position of the cursor.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @param[in] cursorOffset The offset value from the cursor position
	* @param[in] length The length of the text to delete
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_ARG The @c length is less than or equal to @c 0.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result DeleteText(int cursorOffset, int length);

	/**
	* Notifies the position and the size of the input panel at both the portrait and the landscape orientation.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @param[in] portraitBounds The position and size of the input panel at the portrait orientation
	* @param[in] landscapeBounds The position and size of the input panel at the landscape orientation
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result NotifyInputPanelBounds(const Tizen::Graphics::FloatRectangle& portraitBounds, const Tizen::Graphics::FloatRectangle& landscapeBounds);

	/**
	* Notifies the state of the input panel to the associated text input UI control when the state of an input panel changes.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @param[in] state The state of the input panel
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result NotifyInputPanelState(Tizen::Ui::InputPanelShowState state);

	/**
	* Notifies a point of time when the language of the input method changes.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result NotifyLanguageChanged(void);

	/**
	 * Requests the surrounding text from the position of the cursor. @n
	 * The requested surrounding text can be received using the Tizen::Ui::Ime::IInputMethodListener::OnSurroundingTextReceived() method.
	 *
	 * @since 2.1
	 * @privlevel partner
	 * @privilege %http://tizen.org/privilege/ime
	 *
	 * @return An error code
	 * @param[in] lengthBeforeCursor The length of the surrounding text before the cursor
	 * @param[in] lengthAfterCursor The length of the surrounding text after the cursor
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_INVALID_ARG The arguments are less than @c 0.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 */
	result RequestSurroundingText(int lengthBeforeCursor, int lengthAfterCursor);

	/**
	* Sends a composite text that is being modified to the associated text input UI control.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @param[in] text The composite text to send
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result SendCompositeText(const Tizen::Base::String& text);

	/**
	* Sends a key event directly to the associated text input UI control.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @param[in] code The key code
	* @param[in] state The key state
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result SendKeyEvent(Tizen::Ui::KeyCode code, Tizen::Ui::KeyState state);

	/**
	* Sends a text to the associated text input UI control.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return An error code
	* @param[in] text The text to send
	* @exception E_SUCCESS The method is successful.
	* @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	*/
	result SendText(const Tizen::Base::String& text);

private:
	//
	// This Construct() is intentionally declared as private so that only the platform can create an instance.
	//
	// @since 2.1
	//
	// @return An error code
	// @exception E_SUCCESS The method is successful.
	// @exception E_CONNECTION_FAILED The connection to the input service fails.
	// @exception E_SYSTEM A failure occurs from the underlying system.
	// @remarks OOM might be thrown by this method.
	//
	result Construct(void);

	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since 2.1
	//
	InputMethod(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since 2.1
	//
	virtual ~InputMethod(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.1
	//
	InputMethod(const InputMethod& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.1
	//
	InputMethod& operator=(const InputMethod& rhs);

private:
	friend class _InputMethodImpl;

	_InputMethodImpl* __pInputMethodImpl;
};

}}} // Tizen::Ui::Ime

#endif // _FUI_IME_INPUT_METHOD_H_
