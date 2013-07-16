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
 * @file	FUiCtrlPopup.h
 * @brief	This is the header file for the %Popup class.
 *
 * This header file contains the declarations of the %Popup class.
 */

#ifndef _FUI_CTRL_POPUP_H_
#define _FUI_CTRL_POPUP_H_

#include <FUiWindow.h>

namespace Tizen { namespace Ui
{
class DataBindingContext;
}}	// Tizen::Ui


namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	Popup
 * @brief	This class displays a popup on the top of the screen.
 *
 * @since	2.0
 *
 * The %Popup class displays messages to alert the user of important changes, to request confirmation for a significant task, or to
 * serve as a warning. It is an implementation of the Window class.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_popup_messagebox.htm">Popup and MessageBox</a>.
 *
 * @see Tizen::Ui::Window
 *
 * The following example demonstrates how to use the %Popup class.
 *
 * @code
// Sample code for PopupSample.h
#include <FUi.h>

class PopupSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	PopupSample(void)
	: __pPopup(null){}

	bool Initialize(void);
	void ShowPopup(void);
	void HidePopup(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_BUTTON_OPEN_POPUP = 501;
	static const int ID_BUTTON_CLOSE_POPUP = 502;

	Tizen::Ui::Controls::Popup* __pPopup;
};
 *	@endcode
 *
 *	@code
// Sample code for PopupSample.cpp
#include <FGraphics.h>

#include "PopupSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
PopupSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
PopupSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Popup
	__pPopup = new Popup();
	__pPopup->Construct(true, Dimension(600,800));
	__pPopup->SetTitleText(L"Popup Sample");

	// Creates an instance of Button to close the popup.
	Button* pCloseButton = new Button();
	pCloseButton->Construct(Rectangle(10, 10, 250, 80), L"Close Popup");
	pCloseButton->SetActionId(ID_BUTTON_CLOSE_POPUP);
	pCloseButton->AddActionEventListener(*this);

	// Adds the button to the popup
	__pPopup->AddControl(pCloseButton);

	// Creates an instance of Button to open the popup.
	Button* pOpenButton = new Button();
	pOpenButton->Construct(Rectangle(10, 10, 250, 60), L"Open Popup");
	pOpenButton->SetActionId(ID_BUTTON_OPEN_POPUP);
	pOpenButton->AddActionEventListener(*this);

	// Adds the button to the form
	AddControl(pOpenButton);

	return r;
}

void
PopupSample::ShowPopup(void)
{
	__pPopup->SetShowState(true);
	__pPopup->Show();
}

void
PopupSample::HidePopup(void)
{
	__pPopup->SetShowState(false);
	Invalidate(true);
}

result
PopupSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the __pPopup
	__pPopup->Destroy();

	return r;
}

void
PopupSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON_OPEN_POPUP:
		{
			ShowPopup();
		}
		break;
	case ID_BUTTON_CLOSE_POPUP:
		{
			HidePopup();
		}
		break;
	default:
		break;
	}
}
* @endcode
*/

class _OSP_EXPORT_ Popup
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called.  @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	Popup(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Popup(void);

	/**
	 * Initializes this instance of %Popup with the specified dimensions.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	hasTitle			Set to @c true if the %Popup control has a title, @n
	 *									else @c false
	 * @param[in]	dim			    	The size of the %Popup control @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(bool hasTitle, const Tizen::Graphics::Dimension& dim);

	/**
	 * Initializes this instance of %Popup with the specified dimensions.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	hasTitle			Set to @c true if the %Popup control has a title, @n
	 *									else @c false
	 * @param[in]	dim			    	The size of the %Popup control @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(bool hasTitle, const Tizen::Graphics::FloatDimension& dim);

	/**
	 * Initializes this instance of %Popup and child controls with the specified resource ID @n
	 * This method first attempts to find the resource file in the folder that corresponds to the current screen resolution. @n
	 * If it fails to find the resource file, it searches in other folders in the following order when CoordinateSystem is Logical in the application manifest file
	 * the density folder that corresponds to the current screen size category  "res/screen-size-normal/" folder.
	 *
	 * @since	  2.0
	 *
	 * @return     An error code
	 * @param[in]  resourceId              The resource ID describing the %Popup control
	 * @exception  E_SUCCESS               The method is successful.
	 * @exception  E_FILE_NOT_FOUND        The specified file cannot be found.
	 * @exception  E_INVALID_FORMAT        The specified XML format is invalid.
	 * @exception  E_OPERATION_FAILED      The operation has failed.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 * @remarks	If SetBounds(), SetSize(), SetPosition() methods are called before Show(), then the new value is applied to both orientations 
	 *			because the current orientation is not known. After Show() is called, then the values are applied only to the current orientation.
	 */
	result Construct(const Tizen::Base::String& resourceId);

	/**
	 * Initializes this instance of %Popup with the specified layout and dimensions.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	hasTitle	    	Set to @c true if the %Popup control should have a title, @n
	 *							    	else @c false
	 * @param[in]	dim			    	The size of the %Popup control @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(const Tizen::Ui::Layout& layout, bool hasTitle, const Tizen::Graphics::Dimension& dim);

	/**
	 * Initializes this instance of %Popup with the specified layout and dimensions.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	hasTitle	    	Set to @c true if the %Popup control should have a title, @n
	 *							    	else @c false
	 * @param[in]	dim			    	The size of the %Popup control @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(const Tizen::Ui::Layout& layout, bool hasTitle, const Tizen::Graphics::FloatDimension& dim);

	/**
	 * Initializes this instance of %Popup with the specified layouts and dimensions.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	hasTitle			Set to @c true if this %Popup control should have a title, @n
	 * 									else @c false
	 * @param[in]	dim			    	The size of the %Popup control @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, bool hasTitle, const Tizen::Graphics::Dimension& dim);

	/**
	 * Initializes this instance of %Popup with the specified layouts and dimensions.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	hasTitle			Set to @c true if this %Popup control should have a title, @n
	 * 									else @c false
	 * @param[in]	dim			    	The size of the %Popup control @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		The default owner will be the current Form (or Frame). It is possible that this control may not be visible
	 * due to this ownership relationship. @n In this case, use the SetOwner() method to change the ownership to the top-most window.
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, bool hasTitle, const Tizen::Graphics::FloatDimension& dim);

	/**
	 * Shows the modal window. @n
	 *
	 * @since 2.0
	 * @return                   An error code
	 * @param[out]   modalResult           The %Popup's notification. @n
	 *                                              This value is the 'modalResult' parameter of the EndModal() method
	 * @exception     E_SUCCESS            The method is successful.
	 * @exception     E_INVALID_STATE    The %Popup is not visible. The visible state of the %Popup should be set @c true.
	 * @remarks
	 *				- Do not call this method from Tizen::App::App::OnAppInitializing().
	 *				- To show a %Popup properly from Tizen::Ui::Controls::Form::OnInitializing(), theForm must
	 *				have been successfully drawn before the DoModal() method.
	 */
	result DoModal(int& modalResult);

	/**
	 * Closes the modal window. @n
	 *
	 * @since 2.0
	 * @return                  An error code
	 * @param[in]     modalResult                           The result value of the modal window. @n
	 *										The value which needs to be returned as the output parameter of DoModal() method
	 *										should be passed as the input argument
	 * @exception     E_SUCCESS                            The method is successful.
	 * @exception     E_INVALID_STATE                    The method is not supported because this popup isn't running as a modal window.
	 */
	result EndModal(int modalResult);

	/**
	 * Sets the title of the %Popup control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	title		The title to set
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	virtual result SetTitleText(const Tizen::Base::String& title);

	/**
	 * Gets the title of the %Popup control.
	 *
	 * @since		2.0
	 *
	 * @return		The title of the %Popup control
	 */
	Tizen::Base::String GetTitleText(void) const;

	/**
	 * Gets the bounds of the client area.
	 *
	 * @since		2.0
	 *
	 * @return		The bounds of the client area in a Tizen::Graphics::Rectangle instance
	 */
	Tizen::Graphics::Rectangle GetClientAreaBounds(void) const;

	/**
	 * Gets the bounds of the client area.
	 *
	 * @since		2.1
	 *
	 * @return		The bounds of the client area in a Tizen::Graphics::FloatRectangle instance
	 */
	Tizen::Graphics::FloatRectangle GetClientAreaBoundsF(void) const;

	/**
	 * Creates and returns a graphics canvas whose bounds (position and size) are equal to the bounds of the client area of the %Popup control.
	 *
	 * @since		2.0
	 *
	 * @return		The graphic canvas of the %Popup control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_RESOURCE_UNAVAILABLE		The required resource is currently unavailable.
	 * @remarks
	 *				- The method allocates a Tizen::Graphics::Canvas whose bounds are equal to that of the client area of the %Popup control.
	 *				- It is the responsibility of the developers to deallocate the canvas after use.
	 *				- The canvas is valid only if the properties of the parent control of the canvas remain unchanged. @n
	 *				Therefore, delete the previously allocated canvas and create a new canvas using this method if the size or position of the
	 *				control is changed.
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Canvas* GetClientAreaCanvasN(void) const;

	/**
	 * Translates the specified position to the client coordinates.
	 *
	 * @since       2.0
	 *
	 * @return      The position in relative to the top-left corner of the client-area, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   position	The position relative to the top-left corner of the %Popup control
	 * @see         TranslateFromClientAreaPosition()
	 */
	Tizen::Graphics::Point TranslateToClientAreaPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * Translates the specified position to the client coordinates.
	 *
	 * @since       2.1
	 *
	 * @return      The position in relative to the top-left corner of the client-area, @n
	 *				else @c (-1.0f,-1.0f) if the instance is invalid
	 * @param[in]   position	The position relative to the top-left corner of the %Popup control
	 * @see         TranslateFromClientAreaPositionF()
	 */
	Tizen::Graphics::FloatPoint TranslateToClientAreaPosition(const Tizen::Graphics::FloatPoint& position) const;

	/**
	 * Translates the specified client position to the control coordinate.
	 *
	 * @since       2.0
	 *
	 * @return      The position in relative to the top-left corner of the %Popup control, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   clientPosition		The position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPosition()
	 */
	Tizen::Graphics::Point TranslateFromClientAreaPosition(const Tizen::Graphics::Point& clientPosition) const;

	/**
	 * Translates the specified client position to the control coordinate.
	 *
	 * @since       2.1
	 *
	 * @return      The position in relative to the top-left corner of the %Popup control, @n
	 *				else @c (-1.0f,-1.0f) if the instance is invalid
	 * @param[in]   clientPosition		The position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPositionF()
	 */
	Tizen::Graphics::FloatPoint TranslateFromClientAreaPosition(const Tizen::Graphics::FloatPoint& clientPosition) const;

	/**
	 * Gets the color of the %Popup control.
	 *
	 * @since       2.0
	 *
	 * @return      The color, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception   E_SUCCESS            The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(void) const;

	/**
	 * Sets the color of the %Popup control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   color               The color to set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 */
	result SetColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the title text color of the %Popup control.
	 *
	 * @since		2.0
	 *
	 * @return		The color, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * Sets the title text color of the %Popup control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   color                The title text color
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_SYSTEM             A system error has occurred.
	 */
	result SetTitleTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the data binding context.
	 *
	 * @since 2.0
	 *
	 * @return       The data binding context
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_SYSTEM         A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	DataBindingContext* GetDataBindingContextN(void) const;

protected:
	friend class _PopupImpl;

	/**
	 * The following methods are reserved and may change its name at any time without
	 * prior notice.
	 */
	virtual void Popup_Reserved1(void) { }
	virtual void Popup_Reserved2(void) { }
	virtual void Popup_Reserved3(void) { }

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Popup(const Popup& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Popup& operator =(const Popup& rhs);

}; // Popup


}}} // Tizen::Ui::Controls

#endif  //_FUI_CTRL_POPUP_H_
