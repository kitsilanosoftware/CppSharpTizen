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
 * @file		FUiCtrlPanel.h
 * @brief		This is the header file for the %Panel class.
 *
 * This header file contains the declarations of the %Panel class.
 */

#ifndef _FUI_CTRL_PANEL_H_
#define _FUI_CTRL_PANEL_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FUiContainer.h>
#include <FUiCtrlGroupTypes.h>

namespace Tizen {namespace Base
{
class String;
}} //Tizen::Base

namespace Tizen { namespace Ui
{
class DataBindingContext;
}} //Tizen::Ui

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	Panel
 * @brief	This class provides a %Panel, that is the simplest container.
 *
 * @since	2.0
 *
 * The %Panel class displays a space where other UI elements can be placed. It is a concrete implementation of the Container class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_panels.htm">Panels</a>.
 *
 * The following example demonstrates how to use the %Panel class.
 *
 * @code
// Sample code for PanelSample.h
#include <FUi.h>

class PanelSample
	: public Tizen::Ui::Controls::Form
{
public:
	PanelSample(void)
	: __pPanel(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

private:
	Tizen::Ui::Controls::Panel* __pPanel;
};
 *	@endcode
 *
 *	@code
// Sample code for PanelSample.cpp
#include <FGraphics.h>

#include "PanelSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
PanelSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
PanelSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Panel
	__pPanel = new Panel();
	__pPanel->Construct(Rectangle(100, 200, 300, 300));
	__pPanel->SetBackgroundColor(Color(0x50, 0xFF, 0x38));

	//Adds the panel to the form
	AddControl(*__pPanel);

	return r;
}
 * @endcode
 */
class _OSP_EXPORT_ Panel
	: public Tizen::Ui::Container
{
// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 *
	 */
	Panel(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 *
	 */
	virtual ~Panel(void);

	/**
	 * Initializes this instance of %Panel with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the %Panel control as an instance of Rectangle
	 * @param[in]	groupStyle		The group style of the %Panel control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The specified group style determines the border look of the %Panel control.
	 * @see         Tizen::Ui::Container, Tizen::Ui::GroupStyle
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, GroupStyle groupStyle = GROUP_STYLE_NONE);


	/**
	 * Initializes this instance of %Panel and child controls with the specified resource ID @n
	 *
	 * This method first attempts to find the resource file in the folder that corresponds to the current screen resolution. @n
	 * If it fails to find the resource file, it searches in other folders in the following order when CoordinateSystem is Logical in the application manifest file @n
	 * the density folder that corresponds to the current screen size category  "res/screen-size-normal/" folder.
	 *
	 * @since 2.0
	 *
	 * @return           An error code
	 * @param[in]  resourceId              The resource ID describing the %Panel control
	 * @exception  E_SUCCESS               The method is successful.
	 * @exception  E_FILE_NOT_FOUND        The specified file cannot be found.
	 * @exception  E_INVALID_FORMAT        The specified XML format is invalid.
	 * @exception  E_OPERATION_FAILED      The operation has failed.
	 */
	result Construct(const Tizen::Base::String& resourceId);

	/**
	 * Initializes this instance of %Panel with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape modes
	 * @param[in]	rect				The location and size of the %Panel control as an instance of Rectangle
	 * @param[in]	groupStyle			The table view style of the %Panel control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified layout is already bound to another container.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specified group style determines the border look of the %Panel control.
	 * @see         Tizen::Ui::Container, Tizen::Ui::GroupStyle
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Rectangle& rect, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Initializes this instance of %Panel with the specified layouts, rectangular region, and group style.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of the %Panel control as an instance of Rectangle
	 * @param[in]	groupStyle			The table view style of the %Panel control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified layout is already bound to another container.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specified group style determines the border look of the %Panel control.
	 * @see         Tizen::Ui::Container, Tizen::Ui::GroupStyle
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Rectangle& rect, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Gets the background color of the %Panel control.
	 *
	 * @since		2.0
	 *
	 * @return		The background color
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	color   The background color
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Enables the %Panel control to be composited to the screen buffer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because changing composition mode is not allowed any more.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	composite		Set to @c true to make the %Panel control composited to the screen buffer, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks     In case a %Panel is transparent and nothing is drawn on the canvas of the %Panel control, the graphic performance can be improved if the
	 *				compositing of the %Panel control to the screen buffer is disabled. @n
	 * 				By default, compositing is enabled. For example, if a Form control has a %Panel that has a List, by disabling the compositing of the
	 *				%Panel, the scroll performance of the %List will improve.
	 * @endif
	 */
	result SetCompositeEnabled(bool composite);

	/**
	 * @if OSPDEPREC
	 * Checks whether the %Panel control is composite to the screen buffer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because changing composition mode is not allowed any more.
	 * @since	2.0
	 *
	 * @return	@c true if the %Panel control is composite to the screen buffer, @n
	 *			else @c false
	 * @endif
	 */
	bool IsCompositeEnabled(void) const;

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

	friend class _PanelImpl;

	// Reserved virtual methods for later extension

	// The following methods are reserved and may change its name at any time without prior notice.
	virtual void Panel_Reserved1(void) {}

	virtual void Panel_Reserved2(void) {}

	virtual void Panel_Reserved3(void) {}

private:
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	Panel(const Panel& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	Panel& operator =(const Panel& rhs);

}; // Panel

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_PANEL_H_

