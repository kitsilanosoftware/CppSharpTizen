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
 * @file	FShellAppWidgetProvider.h
 * @brief	This is the header file for the %AppWidgetProvider class.
 *
 * This header file contains the declarations of the %AppWidgetProvider class.
 */

#ifndef _FSHELL_APPWIDGET_PROVIDER_H_
#define _FSHELL_APPWIDGET_PROVIDER_H_

#include <FBaseObject.h>

namespace Tizen { namespace Shell
{

class AppWidgetFrame;

/**
 * @class		AppWidgetProvider
 * @brief		This class is the abstract base class for all AppWidget providers.
 *
 * @since	2.1
 *
 * The %AppWidgetProvider class is an abstract base class that represents an AppWidget provider.
 */
class _OSP_EXPORT_ AppWidgetProvider
	: public Tizen::Base::Object
{
protected:

	/**
	 *	This is the default constructor for this class.
	 *
	 * @since	2.1
	 */
	AppWidgetProvider(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetProvider(void);

	/**
	 * Called when the AppWidget provider is created or initialized.
	 *
	 * @since	2.1
	 *
	 * @return      @c true if the method is successful, @n
	 *              else @c false
	 * @param[in]	width		The width of the AppWidget
	 * @param[in]	height		The height of the AppWidget
	 * @param[in]	userInfo	User information that is specified when the AppWidget is added
	 * @remarks	AppWidgetFrame should be created and set here.
	 * 				If this method returns false, the AppWidget provider will be terminated.
	 * @see		SetAppWidgetFrame()
	 *
	 * The following example demonstrates how to initialize the %AppWidgetProvider instance.
	 *
	 * @code
	 * #include <FShell.h>
	 *
	 * using namespace Tizen::Shell;
	 *
	 * void MyAppWidgetProvider::OnAppWidgetProviderInitializing(int width, int height, const String& userInfo)
	 * {
	 *   AppWidgetFrame* pFrame = new MyAppWidgetProviderFrame();
	 *   pFrame->Construct(Dimension(width, height));
	 *   __pLabel = new Label();
	 *
	 *   Rectangle bounds = GetBounds();
	 *   __pLabel->Construct(bounds, L"TIZEN");
	 *   AddControl(__pLabel);
	 *   this->SetAppWidgetFrame(pFrame);
	 *   pFrame->Show();
	 *
	 *   return true;
	 * }
	 * @endcode
	 */
	virtual bool OnAppWidgetProviderInitializing(float width, float height, const Tizen::Base::String& userInfo) = 0;

	/**
	 * Called when the AppWidget provider is destroyed or terminated.
	 *
	 * @since	2.1
	 */
	virtual void OnAppWidgetProviderTerminating(void) = 0;

	/**
	 * Called when the correspondent AppWidget is removed from AppWidget viewer application. (Home or Lock screen, and so on). @n
	 * If AppWidget provider state is stored in a persistent storage such as registry or DB, it can be destroyed by implementing this pure virtual function.
	 *
	 *
	 * @since	2.1
	 *
	 * @remarks 	This method is called after the OnAppWidgetProviderTerminating() method is called.
	 */
	virtual void OnAppWidgetProviderRemoved(void) = 0;

	/**
	 * Called when AppWidget is updated. @n
	 * AppWidget provider can be updated by implementing this pure virtual function.
	 *
	 * @since	2.1
	 *
	 * @return      @c true if the method is successful, @n
	 *              else @c false
	 * @param[in]	argument		User information to update the AppWidget provider @n
	 * 								This parameter is delivered from AppWidgetProvider::RequestUpdate().
	 * @remarks		This method is called when UpdatePeriod timer is expired or AppWidgetManager::RequestUpdate() is called. @n
	 * 					If this method returns false, the AppWidget provider will be terminated.
	 */
	virtual bool OnAppWidgetProviderUpdating(const Tizen::Base::String& argument) = 0;

	/**
	 * Sets the AppWidgetFrame instance to the %AppWidgetProvider instance.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	pAppWidgetFrame		The AppWidgetFrame instance to set as the %AppWidgetProvider instance
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The pointer to AppWidgetFrame is @c null, or not constructed as yet.
	 * @exception	E_SYSTEM            The method cannot proceed due to a severe system error.
	 * @remarks
	 *			  - This method should be called only within the OnAppWidgetProviderInitializing() method.
	 *			  - The AppWidgetFrame instance ownership is transferred to the platform. After AppWidgetProvider::OnAppWidgetProviderTerminating() is called, the AppWidgetPopup instance is removed automatically. The %AppWidgetFrame instance reuse is not allowed.
	 */
	result SetAppWidgetFrame(AppWidgetFrame* pAppWidgetFrame);

	/**
	 * Gets the AppWidgetFrame instance from the %AppWidgetProvider instance.
	 *
	 * @since	2.1
	 *
	 * @return	The AppWidgetFrame instance, @n
	 *			else @c null if any %AppWidgetFrame is not set as yet
	 */
	AppWidgetFrame* GetAppWidgetFrame(void);

	/**
	 * Gets the AppWidgetFrame instance from the %AppWidgetProvider instance.
	 *
	 * @since	2.1
	 *
	 * @return	The AppWidgetFrame instance, @n
	 *			else @c null if any %AppWidgetFrame is not set as yet
	 */
	const AppWidgetFrame* GetAppWidgetFrame(void) const;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetProvider_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetProvider_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetProvider_Reserved5(void) {}

private:

	//
	// Initializes this instance of %AppWidgetProvider
	//
	// @since	2.1
	//
	result Construct(const Tizen::Base::String& instanceId);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetProvider(const AppWidgetProvider& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetProvider& operator =(const AppWidgetProvider& rhs);


private:
	class _AppWidgetProviderImpl* __pAppWidgetProviderImpl;

	friend class _AppWidgetProviderManagerImpl;
};

}} // Tizen::Shell
#endif /* _FSHELL_APPWIDGET_PROVIDER_H_ */
