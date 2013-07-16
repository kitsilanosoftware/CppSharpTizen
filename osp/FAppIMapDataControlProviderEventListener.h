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
 * @file	FAppIMapDataControlProviderEventListener.h
 * @brief	This is the header file for the %IMapDataControlProviderEventListener interface.
 *
 * This header file contains the declarations of the %IMapDataControlProviderEventListener interface.
 */

#ifndef _FAPP_IMAP_DATACONTROL_REQUESTEVENT_LISTENER_H_
#define _FAPP_IMAP_DATACONTROL_REQUESTEVENT_LISTENER_H_

#include <FBaseDataType.h>
#include <FBaseString.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App
{

/**
 * @interface	IMapDataControlProviderEventListener
 * @brief		This interface defines a listener for dealing with MAP-type data control request.
 *
 * @since	2.0
 *
 * The %IMapDataControlProviderEventListener interface defines a listener for dealing with MAP-type data control request.
 *
 * The following example demonstrates how to use the %IMapDataControlProviderEventListener interface.
 * @code
#include <FBase.h>
#include <FApp.h>
#include <FIo.h>

class MyServiceApp
	: public Tizen::App::ServiceApp
	: public Tizen::App::IMapDataControlProviderEventListener
{
public:
	MyServiceApp(void);
	virtual ~MyServiceApp(void);

	virtual bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);
	virtual bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);

	virtual void OnMapDataControlGetValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key);
	virtual void OnMapDataControlAddValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& value);
	virtual void OnMapDataControlSetValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& oldValue,
			const Tizen::Base::String& newValue);
	virtual void OnMapDataControlRemoveValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& value);
};

bool
MyServiceApp::OnAppInitializing(Tizen::App::AppRegistry& appRegistry)
{
    result r = E_SUCCESS;

	DataControlProviderManager* pDcMgr = DataControlProviderManager::GetInstance();
	if (pDcMgr == null)
	{
		AppLog("Failed to get the instance of data control provider manager.");
		return false;
	}

	r = pDcMgr->SetMapDataControlProviderEventListener(this);
	if (IsFailed(r))
	{
		AppLog("Failed to set the data control provider listener.");
		return false;
	}

	return true;
}

void
MyServiceApp::OnMapDataControlGetValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
		const Tizen::Base::String& dataId, const Tizen::Base::String& key)
{
	Registry* pReg = null;
	String retValue;
	ArrayList* pResultValueList = null;
	String errorMsg;
	result r = E_SUCCESS;

	if (providerId.compareTo(L"http://tizen.org/datacontrol/provider/example") == 0)
	{
		if (dataId.compareTo(L"test") == 0)
		{
			String regPath(GetAppRootPath() + L"data/test.ini");

			pReg = new Registry();
			if (pReg == null)
			{
				errorMsg.Append(L"The memory is insufficient.");
				goto CATCH;
			}

			r = pReg->Construct(regPath, false);
			if (IsFailed(r))
			{
				errorMsg.Append(L"The data control provider failed to open the registry file.");
				goto CATCH;
			}

			r = pReg->GetValue(dataId, key, retValue);
			if (IsFailed(r))
			{
				errorMsg.Append(L"The data control provider failed to get the value.");
				goto CATCH:
			}

			pResultValueList = new ArrayList();
			pResultValueList->Add(retValue);

			delete pReg;
		}
		else
		{
			errorMsg.Append(L"The data ID is invalid.");
		}
	}
	else
	{
		errorMsg.Append(L"The provider ID is invalid.");
	}

	r = DataControlProviderManager::GetInstance()->SendMapDataControlResult(reqId, pResultValueList);
	if (IsFailed(r))
	{
		AppLog("The data control provider failed to send the result.");
	}

	if (pResultValueList)
	{
		pResultValueList->RemoveAll();
		delete pResultValueList;
	}
	return;

CATCH:
	r = DataControlProviderManager::GetInstance()->SendDataControlError(reqId, errorMsg);
	if (IsFailed(r))
	{
		AppLog("The data control provider failed to send the result.");
	}

	delete pReg;
	if (pResultValueList)
	{
		pResultValueList->RemoveAll();
		delete pResultValueList;
	}
	return;
}
* @endcode
*/
class _OSP_EXPORT_ IMapDataControlProviderEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IMapDataControlProviderEventListener(void) {}

	/**
	* Called when the request for getting the value list is received from MAP-type data control consumer. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]		reqId				The request ID
	* @param[in]		providerId			The data control provider ID
	* @param[in]		dataId				A string for identifying a specific map to get from @n
	*										The string consists of one or more components, separated by a slash('/').
	* @param[in]		key					A key of the value list to obtain
	* @remarks			For replying to the data control request, use DataControlProviderManager::SendMapDataControlResult()
	*					or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnMapDataControlGetValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key) = 0;

	/**
	* Called when the request for adding the value is received from MAP-type data control consumer. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]		reqId				The request ID
	* @param[in]		providerId			The data control provider ID
	* @param[in]		dataId				A string for identifying a specific map to add to @n
	*										The string consists of one or more components, separated by a slash('/').
	* @param[in]		key					A key of the value list to add
	* @param[in]		value				A value to add
	* @remarks			For replying to the data control request, use DataControlProviderManager::SendMapDataControlResult()
	*					or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnMapDataControlAddValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& value) = 0;

	/**
	* Called when the request for replacing the value is received from MAP-type data control consumer. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]		reqId				The request ID
	* @param[in]		providerId			The data control provider ID
	* @param[in]		dataId				A string for identifying a specific map to update @n
	*										The string consists of one or more components, separated by a slash('/').
	* @param[in]		key					A key of the value to replace
	* @param[in]		oldValue			A value to replace
	* @param[in]		newValue			A new value to replace the existing value
	* @remarks			For replying to the data control request, use DataControlProviderManager::SendMapDataControlResult()
	*					or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnMapDataControlSetValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& oldValue,
			const Tizen::Base::String& newValue) = 0;

	/**
	* Called when the request for removing the value is received from MAP-type data control consumer. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]		reqId				The request ID
	* @param[in]		providerId			The data control provider ID
	* @param[in]		dataId				A string for identifying a specific map to remove from @n
	*										The string consists of one or more components, separated by a slash('/').
	* @param[in]		key					A key of the value to remove
	* @param[in]		value				A value to remove
	* @remarks			For replying to the data control request, use DataControlProviderManager::SendMapDataControlResult()
	*					or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnMapDataControlRemoveValueRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& value) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlProviderEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlProviderEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlProviderEventListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlProviderEventListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlProviderEventListener_Reserved5(void) {}

}; // IMapDataControlProviderEventListener

}} // Tizen::App

#endif // _FAPP_IMAP_DATACONTROL_REQUESTEVENT_LISTENER_H_

