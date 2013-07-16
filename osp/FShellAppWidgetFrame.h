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
 * @file	FShellAppWidgetFrame.h
 * @brief	This is the header file for the %AppWidgetFrame class.
 *
 * This header file contains the declarations of the %AppWidgetFrame class.
 */

#ifndef _FSHELL_APPWIDGET_FRAME_H_
#define _FSHELL_APPWIDGET_FRAME_H_

#include <FUiWindow.h>

namespace Tizen { namespace Shell
{

/**
 * @class	AppWidgetFrame
 * @brief	This class provides the main frame window for an AppWidgetProvider.
 * @since	2.1
 *
 * The %AppWidgetFrame class is the root parent of all AppWidget controls that are created by an AppWidgetProvider.
 *
 */
class _OSP_EXPORT_ AppWidgetFrame
	: public Tizen::Ui::Window
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	AppWidgetFrame(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetFrame(void);

	/**
	 * Initializes this instance of %AppWidgetFrame with a specified parameter.
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
	 * @see AppWidgetProvider::OnAppWidgetProviderInitializing()
	 */
	result Construct(const Tizen::Graphics::FloatDimension& size);

	/**
	 * Initializes this instance of %AppWidgetFrame with a specified parameter.
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
	 * @see AppWidgetProvider::OnAppWidgetProviderInitializing()
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::FloatDimension& size);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetFrame_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetFrame_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetFrame_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetFrame_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetFrame_Reserved5(void) {}

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	AppWidgetFrame(const AppWidgetFrame& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	AppWidgetFrame& operator =(const AppWidgetFrame& rhs);
}; // AppWidgetFrame

}} // Tizen::Shell

#endif // _FSHELL_APPWIDGET_FRAME_H_
