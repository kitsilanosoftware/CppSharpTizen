//
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FShellAppWidgetPopup.h
 * @brief	This is the header file for the %AppWidgetPopup class.
 *
 * This header file contains the declarations of the %AppWidgetPopup class.
 */

#ifndef _FSHELL_APPWIDGET_POPUP_H_
#define _FSHELL_APPWIDGET_POPUP_H_

#include <FUiWindow.h>

namespace Tizen { namespace Shell
{

/**
 * @class	AppWidgetPopup
 * @brief	This class provides the popup for an AppWidgetProvider.
 * @since	2.1
 *
 * The %AppWidgetPopup class supports detailed screen for an AppWidgetProvider.
 *
 */
class _OSP_EXPORT_ AppWidgetPopup
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	AppWidgetPopup(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetPopup(void);

	/**
	 * Initializes this instance of %AppWidgetPopup with a specified parameter.
	 *
	 * @since	2.1
	 * @feature		%http://tizen.org/feature/shell.appwidget
	 * @return      An error code
	 * @param[in]	size				The new width and height
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception   E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @n
	 *									For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks		Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see AppWidgetPopupProvider::OnAppWidgetPopupProviderInitializing()
	 */
	result Construct(const Tizen::Graphics::FloatDimension& size);

	/**
	 * Initializes this instance of %AppWidgetPopup with a specified parameter.
	 *
	 * @since	2.1
	 * @feature		%http://tizen.org/feature/shell.appwidget
	 * @return      An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	size				The new width and height
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @n
	 *									For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks		Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see AppWidgetPopupProvider::OnAppWidgetPopupProviderInitializing()
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::FloatDimension& size);

	/**
	 * Gets the bounds of the client area.
	 *
	 * @since		2.1
	 *
	 * @return		The bounds of the client area in a Tizen::Graphics::FloatRectangle instance
	 */
	Tizen::Graphics::FloatRectangle GetClientAreaBounds(void) const;

	/**
	 * Gets a graphics canvas whose bounds (position and size) are equal to the bounds of the client area of the %AppWidgetPopup instance.
	 *
	 * @since		2.1
	 *
	 * @return		The graphic canvas of the %AppWidgetPopup instance, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_RESOURCE_UNAVAILABLE		The required resource is currently unavailable.
	 * @remarks
	 *			  - This method allocates a Tizen::Graphics::Canvas whose bounds are equal to that of the client area of the %AppWidgetPopup instance. @n
	 *				It is the responsibility of the developers to deallocate the canvas after use.
	 *			  - The canvas is valid only if the properties of the parent control of the canvas remain unchanged. @n
	 *				Therefore, delete the previously allocated canvas and create a new canvas using the GetClientAreaCanvasN() method if the size or position of the
	 *				control is changed.
	 *			  - The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Canvas* GetClientAreaCanvasN(void) const;

	/**
	 * Translates a specified position to the client coordinates.
	 *
	 * @since       2.1
	 *
	 * @return      The float position in relative to the top-left corner of the client area, @n
	 *				else @c (-1.0f,-1.0f) if the instance is invalid
	 * @param[in]   controlPosition       The float position relative to the top-left corner of the %AppWidgetPopup instance
	 * @see         TranslateToControlPosition()
	 */
	Tizen::Graphics::FloatPoint TranslateToClientAreaPosition(const Tizen::Graphics::FloatPoint& controlPosition) const;

	/**
	 * Translates a specified client position to the control coordinate.
	 *
	 * @since       2.1
	 *
	 * @return      The float position in relative to the top-left corner of the Popup control, @n
	 *				else @c (-1.0f,-1.0f) if the instance is invalid
	 * @param[in]   clientPosition        The float position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPosition()
	 */
	Tizen::Graphics::FloatPoint TranslateToControlPosition(const Tizen::Graphics::FloatPoint& clientPosition) const;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetPopup_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetPopup_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetPopup_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetPopup_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetPopup_Reserved5(void) {}

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	AppWidgetPopup(const AppWidgetPopup& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	AppWidgetPopup& operator =(const AppWidgetPopup& rhs);
}; // AppWidgetPopup

}} // Tizen::Shell

#endif // _FSHELL_APPWIDGET_POPUP_H_
