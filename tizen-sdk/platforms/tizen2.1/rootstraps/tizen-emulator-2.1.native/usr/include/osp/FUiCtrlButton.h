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
 * @file	FUiCtrlButton.h
 * @brief	This is the header file for the %Button class.
 *
 * This header file contains the declarations of the %Button class and its helper classes.
 */

#ifndef _FUI_CTRL_BUTTON_H_
#define _FUI_CTRL_BUTTON_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpRectangle.h>
#include <FGrpColor.h>
#include <FUiIActionEventListener.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlControlsTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum ButtonStatus
 *
 * Defines the %Button control status.
 *
 * @since       2.0
 */
enum ButtonStatus
{
	BUTTON_STATUS_NORMAL,          /**< The normal status */
	BUTTON_STATUS_DISABLED,        /**< The disabled status */
	BUTTON_STATUS_PRESSED,         /**< The pressed status */
	BUTTON_STATUS_HIGHLIGHTED      /**< The highlighted status */
};

/**
 * @class	Button
 * @brief This class defines the common behavior of a %Button control.
 *
 * @since 2.0
 *
 * The %Button class displays a rectangular area that can be pressed.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_button.htm">Buttons</a>.
 *
 * The following example demonstrates how to use the %Button class.
 *
 *
 * @code
// Sample code for ButtonSample.h
#include <FUi.h>

class ButtonSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	ButtonSample(void)
	: __pButton(null)
	, __pBitmapButton(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_BUTTON  = 101;
	static const int ID_BITMAP_BUTTON = 102;

	Tizen::Ui::Controls::Button* __pButton;
	Tizen::Ui::Controls::Button* __pBitmapButton;
};
 *	@endcode
 *
 *	@code
// Sample code for ButtonSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "ButtonSample.h"

using namespace Tizen::App;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
ButtonSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ButtonSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Button
	__pButton = new Button();
	__pButton->Construct(Rectangle(50, 50, 200, 200), L"Button");
	__pButton->SetActionId(ID_BUTTON);
	__pButton->AddActionEventListener(*this);

	AddControl(__pButton);

	// Creates an instance of Button for bitmap button
	__pBitmapButton = new Button();
	__pBitmapButton->Construct(Rectangle(260, 50, 200, 200));
	__pBitmapButton->SetActionId(ID_BITMAP_BUTTON);
	__pBitmapButton->AddActionEventListener(*this);

	// Gets instances of Bitmap
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* pBitmapNormal = pAppResource->GetBitmapN(L"tizen.png");
	Bitmap* pBitmapPressed = pAppResource->GetBitmapN(L"tizen.png");

	// Sets the bitmaps to the bitmap button
	__pBitmapButton->SetNormalBackgroundBitmap(*pBitmapNormal);
	__pBitmapButton->SetPressedBackgroundBitmap(*pBitmapPressed);

	// Deallocates bitmaps
	delete pBitmapNormal;
	delete pBitmapPressed;

	// Adds the bitmap button to the form
	AddControl(__pBitmapButton);

	return r;
}

// IActionEventListener implementation
void
ButtonSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON:
		{
			// ....
		}
		break;
	case ID_BITMAP_BUTTON:
		{
			// ....
		}
		break;
	default:
		break;
	}
}
 * @endcode
 *
 */
class _OSP_EXPORT_ Button
	: public Tizen::Ui::Control
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	Button(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~Button(void);

	/**
	 * Initializes this instance of %Button with the specified parameters.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Tizen::Graphics::Rectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner
	 *                              of the created window along with its width and height.@n
	 *								The optimal size of the control is defined in
	 *								<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   text			The text to display on the button
	 *								To display the text in multi-lines or to denote the end of line, use '\\n'.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- A control is fully functional only after it has been added to a container. Therefore, some methods may fail if they are used before
	 *				adding the control to the container.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, const Tizen::Base::String& text = L"");

	/**
	 * Initializes this instance of %Button with the specified parameters.
	 *
	 * @since			2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Tizen::Graphics::FloatRectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner
	 *                              of the created window along with its width and height.@n
	 *								The optimal size of the control is defined in
	 *								<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   text			The text to display on the button
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- A control is fully functional only after it has been added to a container. Therefore, some methods may fail if they are used before
	 *				adding the control to the container.
	 *				- To display the text in multi-lines or to denote the end of line, use '\\n'.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, const Tizen::Base::String& text = L"");

	/**
	 * Adds a listener instance. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to add
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Sets the action ID of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	actionId		The action ID
	 */
	void SetActionId(int actionId);

	/**
	  * Gets the action ID of the button.
	  *
	  * @since		2.0
	  *
	  * @return		An integer value representing the action ID
	  */
	int GetActionId(void) const;

public:
	/**
	 * Sets the text that the button displays.
	 *
	 * @since		2.0
	 *
	 * @param[in]   text	The text of the button
	 * @remarks		To display text in multi-lines or to denote the end of line, use '\\n'.
	 */
	void SetText(const Tizen::Base::String& text);

	/**
	 * Sets the horizontal alignment of the text of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	alignment	The horizontal text alignment
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Sets the vertical alignment of the text of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]   alignment	The vertical text alignment
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

public:
	/**
	 * Gets the text displayed by the button.
	 *
	 * @since	2.0
	 *
	 * @return	The text of the button
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets the horizontal alignment of the text of the button.
	 *
	 * @since	2.0
	 *
	 * @return	The horizontal text alignment
	 */
	HorizontalAlignment GetTextHorizontalAlignment(void) const;

	/**
	 * Gets the vertical alignment of the text of the button.
	 *
	 * @since	2.0
	 *
	 * @return	The vertical text alignment
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;

	//Normal color
	/**
	 * Sets the color of the text to be displayed on the button.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color	The text color to set
	 */
	virtual void SetTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the text to be displayed on the button.
	 *
	 * @since			2.0
	 *
	 * @return      The text color
	 */
	virtual Tizen::Graphics::Color GetTextColor(void) const;

	//Pressed color
	/**
	 * Sets the text color of the button for the pressed state.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color	The color to set
	 */
	void SetPressedTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the button for the pressed state.
	 *
	 * @since			2.0
	 *
	 * @return      The text color when the button is pressed
	 */
	Tizen::Graphics::Color GetPressedTextColor(void) const;

	//Disabled color
	/**
	 * Sets the text color of the button for the disabled state.
	 *
	 * @since			2.0
	 *
	 * @param[in]	color	The color to set
	 */
	void SetDisabledTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the button for the disabled state.
	 *
	 * @since			2.0
	 *
	 * @return	        The disabled text color
	 */
	Tizen::Graphics::Color GetDisabledTextColor(void) const;

	/**
	 * Sets the text color of the button for the highlighted state.
	 *
	 * @since           2.0
	 *
	 * @param[in]	color	The color to set
	 * @remarks     While navigating the user interface using the directional keys, the focused UI control is highlighted.
	 */
	void SetHighlightedTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the button for the highlighted state.
	 *
	 * @since           2.0
	 *
	 * @return    The highlighted text color
	 * @remarks    While navigating the user interface using the directional keys, the selected UI control is highlighted and takes the focus.
	 */
	Tizen::Graphics::Color GetHighlightedTextColor(void) const;

	/**
	 * Sets a bitmap that is to be displayed when the button is not pressed.
	 *
	 * @since	    2.0
	 *
	 * @param[in]	position	The location of a bitmap where it is to display on the button
	 * @param[in]	bitmap		The bitmap to set
	 */
	void SetNormalBitmap(const Tizen::Graphics::Point& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets a bitmap that is to be displayed when the button is not pressed.
	 *
	 * @since	    2.1
	 *
	 * @param[in]	position	The location of a bitmap where it is to display on the button
	 * @param[in]	bitmap		The bitmap to set
	 */
	void SetNormalBitmap(const Tizen::Graphics::FloatPoint& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the disabled bitmap of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	position	The location of disabled bitmap
	 * @param[in]	bitmap		The disabled bitmap of the button
	 */
	void SetDisabledBitmap(const Tizen::Graphics::Point& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the disabled bitmap of the button.
	 *
	 * @since		2.1
	 *
	 * @param[in]	position	The location of disabled bitmap
	 * @param[in]	bitmap		The disabled bitmap of the button
	 */
	void SetDisabledBitmap(const Tizen::Graphics::FloatPoint& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the bitmap that is to be displayed on the button when it is pressed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	position	The location of a bitmap where it is to display on the Button control
	 * @param[in]	bitmap		The bitmap to set
	 */
	void SetPressedBitmap(const Tizen::Graphics::Point& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the bitmap that is to be displayed on the button when it is pressed.
	 *
	 * @since		2.1
	 *
	 * @param[in]	position	The location of a bitmap where it is to display on the Button control
	 * @param[in]	bitmap		The bitmap to set
	 */
	void SetPressedBitmap(const Tizen::Graphics::FloatPoint& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the highlighted bitmap of the button.
	 *
	 * @since       2.1
	 *
	 * @param[in]   position     The location of highlighted bitmap
	 * @param[in]   bitmap       The highlighted bitmap of the button
	 */
	void SetHighlightedBitmap(const Tizen::Graphics::Point& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the highlighted bitmap of the button.
	 *
	 * @since       2.1
	 *
	 * @param[in]   position     The location of highlighted bitmap
	 * @param[in]   bitmap       The highlighted bitmap of the button
	 */
	void SetHighlightedBitmap(const Tizen::Graphics::FloatPoint& position, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the normal background bitmap of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	bitmap			The normal background image
	 */
	void SetNormalBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the disabled background bitmap of the button.
	 *
	 * @since       2.1
	 *
	 * @param[in]   bitmap          The disabled background image
	 */
	void SetDisabledBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the pressed background bitmap of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	bitmap			The pressed background bitmap
	 */
	void SetPressedBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the highlighted background bitmap of the button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	bitmap    The highlighted background bitmap
	 * @remarks		When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 */
	void SetHighlightedBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Gets the color of the button for the specified status.
	 *
	 * @since       2.0
	 *
	 * @return      The color, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @param[in]   status               The status
	 * @exception   E_SUCCESS            The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(ButtonStatus status) const;

	/**
	 * Sets the color of the button for the specified status.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   status               The status
	 * @param[in]   color                The button color
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_SYSTEM             A system error has occurred.
	 */
	result SetColor(ButtonStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Gets the text size.
	 *
	 * @since       2.0
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS                 The method is successful.
	 * @exception   E_SYSTEM                  A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the text size.
	 *
	 * @since       2.1
	 *
	 * @return      The size of the text, @n
	 *              else @c -1.0f if an error occurs
	 * @exception   E_SUCCESS                 The method is successful.
	 * @exception   E_SYSTEM                  A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	float GetTextSizeF(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   size              The text size
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     The specified input parameter is invalid. @n
	 *                                The specified @c size must be greater than @c 0.
	 * @exception   E_SYSTEM          A system error has occurred.
	 * @see                           GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	* Sets the text size.
    *
	* @since       2.1
	*
	* @return      An error code
	* @param[in]   size              The text size
	* @exception   E_SUCCESS         The method is successful.
	* @exception   E_INVALID_ARG     The specified input parameter is invalid. @n
	*                                The specified @c size must be greater than @c 0.
	* @exception   E_SYSTEM          A system error has occurred.
	* @see                           GetTextSize()
	*/
	result SetTextSize(float size);

protected:
	friend class _ButtonImpl;

private:
	//
	// This is the copy constructor for this class.
	//
	Button(const Button& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %Button.
	//
	Button& operator =(const Button& rhs);

}; // Button

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_BUTTON_H_
