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
 * @file		FShellAppWidgetView.h
 * @brief	This is the header file for the %AppWidgetView class.
 *
 * This header file contains the declarations of the %AppWidgetView class.
 */

#ifndef _FSHELL_APPWIDGET_VIEW_H_
#define _FSHELL_APPWIDGET_VIEW_H_

#include <FAppTypes.h>
#include <FUiContainer.h>

namespace Tizen { namespace Base
{
class String;
}} // Tizen::Base

namespace Tizen { namespace Shell
{

class IAppWidgetViewEventListener;
class AppWidgetProviderInfo;

/**
 * @class	AppWidgetView
 * @brief	This class provides the view control for an AppWidgetViewer.
 * @since	2.1
 *
 * The %AppWidgetView class shows a drawn buffer by AppWidgetProvider.
 *
 */
class _OSP_EXPORT_ AppWidgetView
	: public Tizen::Ui::Container
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	AppWidgetView(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetView(void);

	/**
	 * Initializes this instance of %AppWidgetView with the specified parameters.
	 *
	 * @since	2.1
	 * @feature		%http://tizen.org/feature/shell.appwidget
	 * @return      An error code
	 * @param[in]	appId				The AppId of the installed application
	 * @param[in]	providerName		The name of the AppWidget provider
	 * @param[in]   rect				An instance of the Tizen::Graphics::FloatRectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner @n
	 *									of the created window along with its width and height.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception   E_OBJ_NOT_FOUND		The specified AppWidget provider is not found.
	 * @exception   E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @n
	 *									For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks		Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(const Tizen::App::AppId& appId, const Tizen::Base::String& providerName, const Tizen::Graphics::FloatRectangle& rect);

	/**
	 * Initializes this instance of %AppWidgetView with the specified parameters.
	 *
	 * @since       2.1
	 * @feature		%http://tizen.org/feature/shell.appwidget
	 * @return      An error code
	 * @param[in]   appId				The AppId of the installed application
	 * @param[in]   providerName		The name of the AppWidget provider
	 * @param[in]   rect				An instance of the Tizen::Graphics::FloatRectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner @n
	 *									of the created window along with its width and height.
	 * @param[in]   userInfo			The extra data to deliver to the AppWidget provider
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception   E_OBJ_NOT_FOUND		The specified AppWidget provider is not found.
	 * @exception   E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @n
	 *									For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks		Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(const Tizen::App::AppId& appId, const Tizen::Base::String& providerName, const Tizen::Graphics::FloatRectangle& rect, const Tizen::Base::String& userInfo);

	/**
	* Gets an AppWidgetProviderInfo of the specified AppWidget provider.
	*
	* @since		2.1
	*
	* @return		A pointer to the AppWidgetProviderInfo of the specified AppWidgetProvider@n
	* 				else @c null if an error occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_APP_NOT_INSTALLED	The application is not installed.
	* @exception	E_OBJ_NOT_FOUND		The specified AppWidget provider is not found.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AppWidgetProviderInfo* GetAppWidgetProviderInfoN(void) const;

	/**
	 * Adds an IAppWidgetViewEventListener instance. @n
	 *
	 * @since		2.1
	 * @return      An error code
	 * @param[in]	listener			The listener to add @n
	 *									The listener must be allocated at heap, not stack.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The listener has already been added.
	 * @see			RemoveAppWidgetViewEventListener()
	 */
	result AddAppWidgetViewEventListener(IAppWidgetViewEventListener& listener);

	/**
	 * Removes an IAppWidgetViewEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @since		2.1
	 * @return      An error code
	 * @param[in]	listener			The listener to remove @n
	 *									The listener should be referring to previously allocated instance which is passed as an argument to AddAppWidgetViewEventListener().
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified listener cannot be found.
	 * @see			AddAppWidgetViewEventListener()
	 */
	result RemoveAppWidgetViewEventListener(IAppWidgetViewEventListener& listener);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetView_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetView_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetView_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetView_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void AppWidgetView_Reserved5(void) {}

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	AppWidgetView(const AppWidgetView& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	AppWidgetView& operator =(const AppWidgetView& rhs);
}; // AppWidgetView

}} // Tizen::Shell

#endif // _FSHELL_APPWIDGET_VIEW_H_
