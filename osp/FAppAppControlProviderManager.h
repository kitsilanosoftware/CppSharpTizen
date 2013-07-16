//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	 FAppAppControlProviderManager.h
 * @brief	This is the header file for the %AppControlProviderManager class.
 *
 * This header file contains the declarations of the %AppControlProviderManager class.
 */

#ifndef _FAPP_APPCONTROL_PROVIDER_MANAGER_H_
#define _FAPP_APPCONTROL_PROVIDER_MANAGER_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FAppTypes.h>


namespace Tizen { namespace Base { namespace Collection {
class IList;
class IMap;
}}}

namespace Tizen { namespace App
{

class IAppControlProviderEventListener;

/**
 * @class	AppControlProviderManager
 * @brief	This class manages the AppControl provider.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %AppControlProviderManager class manages the AppControl provider. @n
 * The %AppControl provider registers or unregisters the IAppControlProviderEventListener listener
 * for providing the %AppControl functionality, looks up for the delivered %AppControl request information,
 * and sends the %AppControl result back to the calling application. @n
 *
 * The request ID is used to identify each %AppControl request and can be acquired using
 * IAppControlProviderEventListener::OnAppControlRequestReceived().
 *
 */
class _OSP_EXPORT_ AppControlProviderManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the application control provider manager instance.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the %AppControlProviderManager instance if it succeeds, @n
	 * 			else @c null
	 */
	static AppControlProviderManager* GetInstance(void);

	/**
	 * Sets the application control provider listener to the application control provider manager. @n
	 * The listener gets notified when the application control request is received from other applications.
	 * To unset the listener, pass a @c null value to the listener parameter. @n
	 *
	 * If the application does not set the listener using %SetAppControlProviderEventListener(),
	 * then the application is launched or moves to the foreground without invoking any listener
	 * for the application request from another application.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pListener	The application control provider listener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been properly constructed.
	 * @exception	E_INVALID_OPERATION	The listener must be set for the valid %App class.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	If the application is newly launched with the AppControl request, then %SetAppControlProviderEventListener() must
	 * 			be set before invoking IAppControlProviderEventListener::OnAppControlRequestReceived().
	 * 			For valid %AppControl request handling, %SetAppControlProviderEventListener() must be called within
	 * 			App::OnAppInitializing().
	 */
	result SetAppControlProviderEventListener(IAppControlProviderEventListener* pListener);

	/**
	 * Gets the application ID for the application control request.
	 *
	 * @since	2.0
	 *
	 * @return	The application ID @n
	 * 			If an error occurs, an empty string is returned.
	 * @param[in]	reqId	The requestID
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The application control request is not found.
	 * @exception	E_INVALID_STATE	This instance has not been properly constructed.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	AppId GetClientAppId(RequestId reqId) const;

	/**
	 * Sends the result list for the application control request. @n
	 * The client receives the result by implementing IAppControlResponseListener::OnAppControlCompleteResponseReceived().
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	reqId	The application control request ID
	 * @param[in]	appControlResult	The application control result
	 * @param[in]	pExtraData	A pointer to an extra argument map of key and value pair where the key is of type Tizen::Base::String and the value is of type %Tizen::Base::String or type Tizen::Base::Collection::ArrayList of %Tizen::Base::String
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The application control request is not found.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	result SendAppControlResult(RequestId reqId, AppCtrlResult appControlResult, const Tizen::Base::Collection::IMap* pExtraData);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	AppControlProviderManager(void);

	/**
	 * This destructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~AppControlProviderManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppControlProviderManager(const AppControlProviderManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppControlProviderManager& operator=(const AppControlProviderManager& rhs);


private:
	class _AppControlProviderManagerImpl*	__pAppControlProviderManagerImpl;

	friend class _AppControlProviderManagerImpl;
};

};
};	// Tizen::App

#endif //_FAPP_APPCONTROL_PROVIDER_MANAGER_H_

