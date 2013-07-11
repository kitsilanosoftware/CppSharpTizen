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
 * @file		FUiInputConnection.h
 * @brief	This is the header file for the %InputConnection class.
 *
 * This header file contains the declarations of the %InputConnection class.
 */

#ifndef _FUI_INPUT_CONNECTION_H_
#define _FUI_INPUT_CONNECTION_H_

#include <FGrpRectangle.h>
#include <FUiIInputConnectionEventListener.h>
#include <FUiIInputConnectionProvider.h>
#include <FUiInputConnectionTypes.h>

namespace Tizen { namespace Ui {

class _InputConnectionImpl;
class Control;


/**
 * @class	InputConnection
 * @brief	This is the header file for the %InputConnection class.
 * This header file contains the declarations of the %InputConnection class.
 * @since 2.0
 *
 * @final This class is not intended for extension.
 *
 * Example:
 *
 * This is a simple editor that uses an %InputConnection.
 *
 *
 * @code
// Sample code for EditorSample.h
#include <FUi.h>
#include <FUiInputConnection.h>
#include <FUiIInputConnectionEventListener.h>

namespace Tizen { namespace Ui {

class EditorSample :
public Tizen::Ui::Control,
public Tizen::Ui::IInputConnectionEventListener,
public Tizen::Ui::IInputConnectionProvider
{
protected:

public:
	virtual result OnInitializing();

	result  ShowKeypad();
	result  HideKeypad();
    virtual void OnInputConnectionPanelShowStateChanged(Tizen::Ui::InputConnection& source, Tizen::Ui::InputPanelShowState showState);
    virtual void OnInputConnectionPanelLanguageChanged(Tizen::Ui::InputConnection& source, Tizen::Locales::LanguageCode language);
    virtual void OnInputConnectionPanelBoundsChanged(Tizen::Ui::InputConnection& source, const Tizen::Graphics::Rectangle& bounds);
    virtual void OnInputConnectionTextPredictionShowStateChanged(Tizen::Ui::InputConnection& source, bool isShown);
    virtual void OnInputConnectionTextPredictionBoundsChanged(Tizen::Ui::InputConnection& source, const Tizen::Graphics::Rectangle& bounds);
    virtual void OnInputConnectionTextCommitted(Tizen::Ui::InputConnection& source, const Tizen::Base::String& committedText);
    virtual void OnInputConnectionComposingTextChanged(Tizen::Ui::InputConnection& source, const Tizen::Base::String& preEditText, int cursorPosition){};
    virtual void DeleteSurroundingText(Tizen::Ui::InputConnection& source, int offset, int chars){};
    virtual void GetPreviousText(Tizen::Ui::InputConnection& source, Tizen::Base::String& text, int& cursorPosition){};

private:
    InputConnection* __pImf;
    bool    __bindStatus;
};

}}
 * @endcode
 *
 * @code
// Sample code for EditorSample.cpp
#include "EditorSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

void
EditorSample::OnInputConnectionPanelShowStateChanged(InputConnection& source, InputPanelShowState showState)
 {
    // ....
 }

void
EditorSample::OnInputConnectionPanelLanguageChanged(InputConnection& source, Tizen::Locales::LanguageCode language)
{
    // ....
}

void
EditorSample::OnInputConnectionPanelBoundsChanged(InputConnection& source, const Tizen::Graphics::Rectangle& bounds)
{
    // ....
}

void
EditorSample::OnInputConnectionTextPredictionShowStateChanged(InputConnection& source, bool isShown)
{
    // ....
}

void
EditorSample::OnInputConnectionTextPredictionBoundsChanged(InputConnection& source, const Tizen::Graphics::Rectangle& bounds)
{
    // ....
}

void
EditorSample::OnInputConnectionTextCommitted(InputConnection& source, const Tizen::Base::String& committedText)
{
    // ....
}

result
EditorSample::OnInitializing()
{
    result r = E_SUCCESS;

    __bindStatus = false;

    // Creates an instance of InputConnection
    __pImf = new (std::nothrow) InputConnection();
    __pImf->Construct(this, *this, *this);

    return r;
}

result
EditorSample::ShowKeypad()
{
    result r = E_SUCCESS;

    if(!__bindStatus)
    {
        __pImf->BindInputMethod();
        __bindStatus = true;
        __pImf->ShowInputPanel();
    }

    return r;
}

result
EditorSample::HideKeypad()
{
    result r = E_SUCCESS;

    if (__bindStatus != false)
    {
        __pImf->HideInputPanel();
        __pImf->UnbindInputMethod();
        __bindStatus = false;
    }

    return r;
}

 * @endcode
 *
 */

class _OSP_EXPORT_ InputConnection
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	InputConnection(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~InputConnection(void);

	/**
	 * Initializes this instance of the %InputConnection with the specified parameter.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @param[in]		pControl				The source object for connecting the Input Method.
	 * @param[in]		listener			An instance of the %IInputConnectionEventListener for processing the event
	 * @param[in]		provider			The %InputConnection provider
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception    	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result Construct(const Control* pControl, IInputConnectionEventListener& listener, IInputConnectionProvider& provider);

	/**
	 * Binds the %InputConnection to the current active Input Method
	 *
	 * @since 2.0
	 * @return		An error code
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
 	 * @see			UnbindInputMethod()
 	 * @remarks		This method should be called when the %Control object has the input focus.
	 */
	result BindInputMethod(void);

	/**
	 * Unbinds the %InputConnection from the current active Input Method. It will no longer be valid for the Input Method.
	 *
	 * @since 2.0
	 * @see			BindInputMethod()
	 */
	void UnbindInputMethod(void);

	/**
	 * Asks the current active Input Method to show the Input Panel which contains the keyboard.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE   	This exception is thrown when BindInputMethod is not called before calling this method.
	 * @see			HideInputPanel()
	 */
	result ShowInputPanel(void);

	/**
	 * Asks the current active Input Method to hide the active Input Panel which contains the keyboard.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE   	This exception is thrown when BindInputMethod is not called before calling this method.
	 * @see			ShowInputPanel()
	 */
	result HideInputPanel(void);

	/**
	 * Sets the style of the current active Input Panel.
	 *
	 * @since 2.0
	 * @param[in]		style				The style of the Input Panel.
	 * @remarks		This method may not work, depending on the current active Input Method.
	 */
	void SetInputPanelStyle(InputPanelStyle style);

	/**
	 * Sets the auto-capitalization mode.
	 *
	 * @since 2.0
	 * @param[in]		autoCapitalizationMode		The auto-capitalization mode.
	 * @remarks		This method may not work, depending on the current active Input Method.
	 */
	void SetAutoCapitalizationMode(AutoCapitalizationMode autoCapitalizationMode);

	/**
	 * Finishes text composition.
	 * This will typically cause the Input Method to exit the composing state.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE   	This exception is thrown when BindInputMethod is not called before calling this method.
	 */
	result FinishTextComposition(void);

	/**
	 * Sets the type of ActionKey.
	 *
	 * @since 2.0
	 * @param[in]		inputPanelAction			The InputPanel action
	 * @remarks		This method may not work, depending on the current active Input Method.
	 */
	void SetInputPanelAction(InputPanelAction inputPanelAction);

	/**
	 * Enables or disables the ActionKey.
	 *
	 * @since 2.0
 	 * @param[in]		enable				Set to @c true to enable the ActionKey, @n
	 *										else @c false
	 * @remarks		This method may not work, depending on the current active Input Method.
	 */
	void SetInputPanelActionEnabled(bool enable);

	/**
	 * Sets the language of the current active Input Panel.
	 *
	 * @since 2.0
	 * @param[in]              languageCode                         The language to set
	 * @exception             E_SUCCESS                            The method is successful.
	 * @exception             E_OUT_OF_MEMORY                    The memory is insufficient.
	 * @remarks                This method may not work, depending on the current active Input Method.
	 */
	result SetInputPanelLanguage(Tizen::Locales::LanguageCode languageCode);

	/**
	 * Sets the cursor at the specified position.
	 *
	 * @since 2.0
	 * @param[in]		position			The cursor position that is to be set
	 * @return		An error code
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception		E_INVALID_STATE   	This exception is thrown when BindInputMethod is not called before calling this method.
	 */
	result SetCursorPosition(int position);

	/**
	 * Sets the bounds of the cursor
	 *
	 * @since 2.0
	 * @param[in]		rect				the rectangle to be set
	 * @return		An error code
	 * @exception   	E_SUCCESS			The method is successful.
	 * @exception   	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception		E_INVALID_STATE   	This exception is thrown when BindInputMethod is not called before calling this method.
	 */
	result SetCursorBounds(const Tizen::Graphics::Rectangle& rect);

	/**
	 * Gets the bounds of the current active Input Panel.
	 *
	 * @since 2.0
	 * @return		An instance of the rectangle that represents the position of the top-left corner,
	 *			the width, and the height of the Input Panel.
	 * @exception    	E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE   	This exception is thrown when BindInputMethod is not called before calling this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Rectangle GetInputPanelBounds(void) const;

	/**
	 * Enables or disables text prediction.
	 *
	 * @since 2.0
	 * @param[in]		enable				Set to @c true to enable text prediction, @n
	 *										else @c false
	 * @remarks		This method may not work, depending on the current active Input Method.
	 */
	void SetTextPredictionEnabled(bool enable);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	InputConnection(const InputConnection& rhs);

	//
 	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	InputConnection& operator=(const InputConnection& rhs);

private:
	friend class _InputConnectionImpl;
	_InputConnectionImpl* __pInputConnectionImpl;

}; // InputConnection

}} // Tizen::Ui

#endif // _FUI_INPUT_CONNECTION_H_
