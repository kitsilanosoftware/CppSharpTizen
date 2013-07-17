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
 * @file	FShellAppWidgetPopupProvider.h
 * @brief	This is the header file for the %AppWidgetPopupProvider class.
 *
 * This header file contains the declarations of the %AppWidgetPopupProvider class.
 */

#ifndef _FSHELL_APPWIDGET_POPUP_PROVIDER_H_
#define _FSHELL_APPWIDGET_POPUP_PROVIDER_H_

#include <FBaseObject.h>

namespace Tizen { namespace Shell
{

class AppWidgetPopup;

/**
 * @class		AppWidgetPopupProvider
 * @brief		This class is the abstract base class of all the AppWidget popup providers.
 *
 * @since	2.1
 *
 * The %AppWidgetPopupProvider class is a base class that represents an AppWidget popup provider.
 */
class _OSP_EXPORT_ AppWidgetPopupProvider
	: public Tizen::Base::Object
{
public:
	/**
	 * Requests AppWidget service to trigger specified AppWidget update
	 *
	 * @since	2.1
	 *
	 * @return      An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result RequestUpdateToAppWidget(void);

protected:
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since	2.1
	 */
	AppWidgetPopupProvider(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetPopupProvider(void);

	/**
	 * Called when the AppWidget popup provider is required to be created.
	 *
	 * @since	2.1
	 *
	 * @return      @c true if the method is successful, @n
	 *				else @c false
	 * @param[in]	userInfo	User information that specifies when the AppWidget is added
	 * @remarks	AppWidgetPopup should be created and set here.
	 * @see		SetAppWidgetPopup()
	 */
	virtual bool OnAppWidgetPopupProviderInitializing(const Tizen::Base::String& userInfo) = 0;

	/**
	 * Called when the AppWidget popup provider is required to be destroyed.
	 *
	 * @since	2.1
	 */
	virtual void OnAppWidgetPopupProviderTerminating(void) = 0;

	/**
	 * Sets the AppWidget popup to the AppWidget popup provider.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	pAppWidgetPopup		The pointer to the AppWidgetPopup instance that is set to AppWidget
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The pointer to AppWidgetFrame is @c null, or not constructed as yet.
	 * @exception	E_SYSTEM            The method cannot proceed due to a severe system error.
	 * @remarks
	 *			  - This method should be called only in OnAppWidgetPopupProviderInitializing().
	 *			  - The AppWidgetPopup instance ownership is transferred to platform. After AppWidgetPopupProvider::OnAppWidgetPopupProviderTerminating() is called, the %AppWidgetPopup instance is removed automatically. The %AppWidgetPopup instance reuse is not allowed.
	 */
	result SetAppWidgetPopup(Tizen::Shell::AppWidgetPopup* pAppWidgetPopup);

	/**
	 * Gets the AppWidget popup.
	 *
	 * @since	2.1
	 *
	 * @return	The AppWidgetPopup instance, @n
	 *			else @c null if any %AppWidgetPopup is not set as yet
	 */
	Tizen::Shell::AppWidgetPopup* GetAppWidgetPopup(void);

	/**
	 * Gets the AppWidget popup from the AppWidget.
	 *
	 * @since	2.1
	 *
	 * @return	The AppWidgetPopup instance, @n
	 *			else @c null if any %AppWidgetPopup is not set as yet
	 */
	const Tizen::Shell::AppWidgetPopup* GetAppWidgetPopup(void) const;


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetPopupProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetPopupProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since	2.1
	//
	virtual void AppWidgetPopupProvider_Reserved3(void) {}

private:
	//
	// Initializes this instance of %AppWidgetPopupProvider
	//
	// @since	2.1
	//
	result Construct(const Tizen::Base::String& instanceId, double x, double y);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetPopupProvider(const AppWidgetPopupProvider& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetPopupProvider& operator =(const AppWidgetPopupProvider& rhs);

private:
	class _AppWidgetPopupProviderImpl* __pAppWidgetPopupProviderImpl;

	friend class _AppWidgetProviderManagerImpl;

}; // AppWidgetPopupProvider

}} // Tizen::Shell

#endif /* _FSHELL_APPWIDGET_POPUP_PROVIDER_H_ */
