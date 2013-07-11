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
 * @file		FUiCtrlProgressPopup.h
 * @brief		This is the header file for the %ProgressPopup class.
 *
 * This header file contains the declarations of the %ProgressPopup class.
 */

#ifndef _FUI_CTRL_PROGRESS_POPUP_H_
#define _FUI_CTRL_PROGRESS_POPUP_H_

#include <FUiCtrlPopup.h>

namespace Tizen { namespace Ui
{
class IProgressPopupEventListener;
}}	// Tizen::Ui


namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	ProgressPopup
 * @brief	This class defines the common behavior of a %ProgressPopup control.
 *
 * @since 2.0
 *
 * The %ProgressPopup class displays processing animation to show processing status.
 * It can contain a title, body text and cancel button.
 *
 * @see Tizen::Ui::Window
 *
 * The following example demonstrates how to use the %ProgressPopup class.
 *
 * @code
// Sample code for ProgressPopupSample.h
#include <FUi.h>

class ProgressPopupSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IProgressPopupEventListener
{
public:
	ProgressPopupSample(void);
	virtual ~ProgressPopupSample(void);

	virtual bool Initialize(void);
	void ShowProgressPopup(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	//IProgressPopupEventListener
	virtual void OnProgressPopupCanceled(void);

private:
	static const int ID_BUTTON_PROGRESSPOPUP = 501;
	static const int ID_BUTTON_CLOSE_PROGRESSPOPUP = 502;

	Tizen::Ui::Controls::ProgressPopup* __pProgressPopup;
};
 * @endcode
 *
 * @code
// Sample code for ProgressPopupSample.cpp
#include "ProgressPopupSample.h"

using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

ProgressPopupSample::ProgressPopupSample(void)
	: __pProgressPopup(null)
{
}

ProgressPopupSample::~ProgressPopupSample(void)
{
}

bool
ProgressPopupSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ProgressPopupSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of ProgressPopup
	__pProgressPopup = new (std::nothrow) ProgressPopup();
	__pProgressPopup->Construct(true,false);
	__pProgressPopup->SetTitleText(L"ProgressPopup Test");
	__pProgressPopup->SetText(L"Hello World!!");
	__pProgressPopup->AddProgressPopupEventListener(*this);

	// Creates an instance of Button to open the ProgressPopup
	Button* pButtonProgressPopup = new Button();
	pButtonProgressPopup->Construct(Rectangle(10, 10, 250, 60), L"Open ProgressPopup");
	pButtonProgressPopup->SetActionId(ID_BUTTON_PROGRESSPOPUP);
	pButtonProgressPopup->AddActionEventListener(*this);

	return r;
}

result
ProgressPopupSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the __pProgressPopup
	delete __pProgressPopup;

	return r;
}

void
ProgressPopupSample::ShowProgressPopup(void)
{
	__pProgressPopup->SetShowState(true);
	__pProgressPopup->Show();
}

void
ProgressPopupSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON_PROGRESSPOPUP:
		ShowProgressPopup();
		break;
	default:
		break;
	}
}

void
ProgressPopupSample::OnProgressPopupCanceled(void)
{
	__pProgressPopup->SetShowState(false);
	Invalidate(true);
}

 * @endcode
 */
class _OSP_EXPORT_ ProgressPopup
	: public Popup
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	ProgressPopup(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ProgressPopup(void);

	/**
	 * Initializes this instance of %ProgressPopup with the specified parameters.
	 *
	 * @since 2.0
	 * @return        An error code
	 * @param[in]    cancelButton                Set to @c true if the %ProgressPopup window has a cancel button, @n
	 *                                                   else @c false
	 * @param[in]    translucent   Set to @c true if the %ProgressPopup window is translucent, @n
	 *                                                   else @c false
	 * @exception    E_SUCCESS                   The method is successful.
	 * @exception    E_SYSTEM                    A system error has occurred. @n
     *                                                        This error occurs when the internal resource is not loaded.
	 * @remarks                                      To show a %ProgressPopup window, call Show() or DoModal() after calling the Construct() method. @n
	 *                                                   By default, the title area and the body text are not shown. @n
	 *                                                   Use SetTitleText() and SetText() to show the title area and the body text.
	 * @remarks                                      If cancelButton is set to true and ProgressPopup is closed by pressing a Cancel Button,
	 *                                                    out parameter of DoModal(), modalResult, is -1.
	 */
	result Construct(bool cancelButton, bool translucent);

	/**
	 * Sets the text of the %ProgressPopup window.
	 *
	 * @since 2.0
	 * @return                                        An error code
	 * @param[in]    text                           The text to be set
	 * @exception    E_SUCCESS                   The method is successful.
	 * @exception    E_OUT_OF_MEMORY       The memory is insufficient.
	 */
	result SetText(const Tizen::Base::String& text);

	/**
	 * Gets the text of the %ProgressPopup window.
	 *
	 * @since 2.0
	 *
	 * @return				The text of the %ProgressPopup window, @n
	 *                          		else an empty string if an error occurs
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Adds a listener instance @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 * @return                                        An error code
	 * @param[in]     listener                      The event listener to be added. Listener should be allocated at heap, not stack.
	 * @exception     E_SUCCESS                  This method was successful.
	 * @exception     E_OBJ_ALREADY_EXIST    The listener was already exist.
	 */
	result AddProgressPopupEventListener(Tizen::Ui::IProgressPopupEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 * @return                                        An error code
	 * @param[in]     listener                      The event listener to be removed. @n
	 *                                                   Listener should be referring to previously allocated instance which is passed as an argument to AddProgressPopupEventListener.
	 * @exception     E_SUCCESS                  This method was successful.
	 * @exception     E_OBJ_NOT_FOUND       The listener was not found.
	 */
	result RemoveProgressPopupEventListener(Tizen::Ui::IProgressPopupEventListener& listener);

	/**
	 * Sets the text color of the %ProgressPopup window.
	 *
	 * @since 2.0
	 * @param[in]                color     The text color
	 */
	void SetTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the %ProgressPopup window.
	 *
	 * @since 2.0
	 * @return                  The color, @n
	 *                              else RGBA(0, 0, 0, 0) if an error occurs
	 */
	Tizen::Graphics::Color GetTextColor(void) const;

protected:
	friend class _ProgressPopupImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ProgressPopup(const ProgressPopup& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ProgressPopup& operator =(const ProgressPopup& rhs);

};  // ProgressPopup


}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_PROGRESS_POPUP_H_
