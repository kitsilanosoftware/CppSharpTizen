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
 * @file		FUiCtrlMessageBox.h
 * @brief	This is the header file for the %MessageBox class.
 *
 * This header file contains the declarations of the %MessageBox class.
 */

#ifndef _FUI_CTRL_MESSAGE_BOX_H_
#define _FUI_CTRL_MESSAGE_BOX_H_

#include <FUiWindow.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum	MessageBoxStyle
 *
 * Defines the %MessageBox style.
 *
 * @since 	2.0
 */
enum MessageBoxStyle
{
	MSGBOX_STYLE_NONE,                      /**< The message box does not contain push buttons: NONE */
	MSGBOX_STYLE_OK,                        /**< The message box contains one push button: OK */
	MSGBOX_STYLE_CANCEL,                    /**< The message box contains one push button: CANCEL */
	MSGBOX_STYLE_OKCANCEL,                  /**< The message box contains two push buttons: OK and CANCEL */
	MSGBOX_STYLE_YESNO,                     /**< The message box contains two push buttons: YES and NO */
	MSGBOX_STYLE_YESNOCANCEL,               /**< The message box contains three push buttons: YES, NO and CANCEL */
	MSGBOX_STYLE_ABORTRETRYIGNORE,          /**< The message box contains three push buttons: ABORT, RETRY, and IGNORE */
	MSGBOX_STYLE_CANCELTRYCONTINUE,         /**< The message box contains three push buttons: CANCEL, TRY, and CONTINUE */
	MSGBOX_STYLE_RETRYCANCEL                /**< The message box contains two push buttons: RETRY and CANCEL */
};


/**
 * @enum	MessageBoxModalResult
 *
 * Defines the %MessageBox notifications.
 *
 * @since	2.0
 */
enum MessageBoxModalResult
{

	MSGBOX_RESULT_CLOSE,                /**< The message box is closed */
	MSGBOX_RESULT_OK,                   /**< The OK button is selected */
	MSGBOX_RESULT_CANCEL,               /**< The cancel button is selected */
	MSGBOX_RESULT_YES,                  /**< The Yes button is selected */
	MSGBOX_RESULT_NO,                   /**< The No button is selected */
	MSGBOX_RESULT_ABORT,                /**< The Abort button is selected */
	MSGBOX_RESULT_TRY,                  /**< The Try button is selected */
	MSGBOX_RESULT_RETRY,                /**< The Retry button is selected */
	MSGBOX_RESULT_IGNORE,               /**< The Ignore button is selected */
	MSGBOX_RESULT_CONTINUE,             /**< The Continue button is selected */
};


/**
 * @class	MessageBox
 * @brief	This class implements a message box.
 *
 * @since	2.0
 *
 * The %MessageBox class displays a confirmation message when the user is asked to confirm an action, or a warning message when the
 * user wants to continue a potentially dangerous action. It can also display information, question, alarm, and lock messages, or
 * the user selections.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_popup_messagebox.htm">Popup and MessageBox</a>.
 *
 * The following example demonstrates how to use the %MessageBox class.
 *
 * @code
// Sample code for MessageBoxSample.h
#include <FUi.h>

class MessageBoxSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	bool Initialize(void);
	void OpenMessageBox(void);
	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

protected:
	static const int ID_BTN_DO_SOMETHING = 101;
};
 *	@endcode
 *
 *	@code
// Sample code for MessageBoxSample.cpp
#include <FGraphics.h>

#include "MessageBoxSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
MessageBoxSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
MessageBoxSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Button
	Button* pButton = new Button();
	pButton->Construct(Rectangle(10, 10, 350, 60), L"MessageBox Test");
	pButton->SetActionId(ID_BTN_DO_SOMETHING);
	pButton->AddActionEventListener(*this);

	// Adds the button to the form
	AddControl(*pButton);

	return r;
}

void
MessageBoxSample::OpenMessageBox(void)
{
	// Creates an instance of MessageBox
	MessageBox messageBox;
	messageBox.Construct(L"MessageBox Title", L"MessageBox Sample Code.", MSGBOX_STYLE_OK, 3000);

	int modalResult = 0;

	// Calls ShowAndWait() : Draws and Shows itself and processes events
	messageBox.ShowAndWait(modalResult);

	switch (modalResult)
	{
	case MSGBOX_RESULT_OK:
		{
			// ....
		}
		break;
	default:
		break;
	}
}

void
MessageBoxSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BTN_DO_SOMETHING:
		{
			OpenMessageBox();
		}
		break;
	default:
		break;
	}
}
 * @endcode
 */

class _OSP_EXPORT_ MessageBox
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	MessageBox(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~MessageBox(void);

	/**
	 * Initializes this instance of %MessageBox with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	title				The title string to be set
	 * @param[in]	text				The text string to be set
	 * @param[in]	style				The style of the %MessageBox control
	 * @param[in]	timeout				The duration of the timeout in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c text is too long.
	 * @remarks		To create a %MessageBox control, call ShowAndWait() after the Construct() method is called. @n
	 *				The message box text cannot contain over @c 399 characters. @n
	 *				To display the text in multi-lines or to denote the end of line use '\\n'.
	 * @see			ShowAndWait()
	 */
	result Construct(const Tizen::Base::String& title, const Tizen::Base::String& text, MessageBoxStyle style, unsigned long timeout = 0);

public:
	/**
	 * Runs the modal window. @n
	 * This method should be called only after calling the Construct() method.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out] 	modalResult		The %MessageBox notification
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 */
	virtual result ShowAndWait(int& modalResult);

	/**
	 * Gets the text of the %MessageBox control.
	 *
	 * @since		2.0
	 *
	 * @return		The text of this %MessageBox instance, @n
	 *				else an empty string if the instance is invalid
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets the title of the %MessageBox control.
	 *
	 * @since		2.0
	 *
	 * @return		The title of this %MessageBox instance, @n
	 *				else an empty string if the instance is invalid
	 */
	Tizen::Base::String GetTitleText(void) const;

	/**
	 * Gets the style of the current %MessageBox.
	 *
	 * @since		2.0
	 *
	 * @return		The style of the current %MessageBox, @n
	 *				else @c MSGBOX_STYLE_NONE if the instance is invalid
	 */
	MessageBoxStyle GetMessageBoxStyle(void) const;

	/**
	 * Gets the timeout value of %MessageBox.
	 *
	 * @since		2.0
	 *
	 * @return		The timeout value in milliseconds, @n
	 *				else @c 0 if the instance is invalid
	 */
	virtual unsigned long GetTimeout(void) const;

	/**
	 * Sets the color of the %MessageBox control.
	 *
	 * @since 2.0
	 *
	 * @param[in]   color		The color to be set
	 */
	void SetColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the %MessageBox control.
	 *
	 * @since 2.0
	 *
	 * @return      The color to be set
	 */
	Tizen::Graphics::Color GetColor(void) const;

	/**
	 * Sets the title text color of the %MessageBox control.
	 *
	 * @since 2.0
	 *
	 * @param[in]   color		The title text color to be set
	 */
	void SetTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of the %MessageBox control.
	 *
	 * @since 2.0
	 *
	 * @return		The title text color
	 */
	Tizen::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * Sets the text color of the %MessageBox control.
	 *
	 * @since 2.0
	 *
	 * @param[in]   color		The text color to be set
	 */
	void SetTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %MessageBox control.
	 *
	 * @since 2.0
	 *
	 * @return		The text color
	 */
	Tizen::Graphics::Color GetTextColor(void) const;

protected:
	friend class _MessageBoxImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	MessageBox(const MessageBox& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	MessageBox& operator =(const MessageBox& rhs);

};  // MessageBox


}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_MESSAGE_BOX_H_
