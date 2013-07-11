//
// Open Service Platform
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
* @file		FAppIMapDataControlResponseListener.h
* @brief	This is the header file for the %IMapDataControlResponseListener interface.
*
* This header file contains the declarations of the %IMapDataControlResponseListener interface.
*/

#ifndef _FAPP_IMAP_DATA_CONTROL_RESPONSE_LISTENER_H_
#define _FAPP_IMAP_DATA_CONTROL_RESPONSE_LISTENER_H_

#include <FBaseDataType.h>
#include <FBaseString.h>
#include <FBaseColIList.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App
{

/**
* @interface	IMapDataControlResponseListener
* @brief		This interface defines a listener for the MAP-type data control response.
*
* @since	2.0
*
* The %IMapDataControlResponseListener interface defines a listener for the MAP-type data control response.
*/
class _OSP_EXPORT_ IMapDataControlResponseListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IMapDataControlResponseListener(void) {}

	/**
	* Called when the result value list is received from MAP-type data control provider. @n
	* The application requesting the data control can get the result value list by implementing this listener. @n
	* This listener must be registered by MapDataControl::SetMapDataControlResponseListener() for receiving the result value set.
	* It is called after MapDataControl::GetValue().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific map to get from @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	resultValueList		The result value list of data control request getting matching values @n
	*									The type of objects contained in the specified @c resultValueList is
	*									Tizen::Base::String class.
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the request getting the values, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnMapDataControlGetValueResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, Tizen::Base::Collection::IList& resultValueList,
			bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

	/**
	* Called when the response is received from MAP-type data control provider. @n
	* The application requesting the data control can get the result by implementing this listener. @n
	* This listener must be registered by MapDataControl::SetMapDataControlResponseListener() for receiving the result response.
	* It is called after MapDataControl::AddValue().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific map to add to @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the request adding a value, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnMapDataControlAddValueResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

	/**
	* Called when the response is received from MAP-type data control provider. @n
	* The application requesting the data control can get the result for some data controls by implementing this listener. @n
	* This listener must be registered by MapDataControl::SetMapDataControlResponseListener() for receiving the result response.
	* It is called after MapDataControl::SetValue().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific map to update @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the request replacing a value, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnMapDataControlSetValueResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

	/**
	* Called when the response is received from MAP-type data control provider. @n
	* The application requesting the data control can get the result for some data controls by implementing this listener. @n
	* This listener must be registered by MapDataControl::SetMapDataControlResponseListener() for receiving the result response.
	* It is called after MapDataControl::RemoveValue().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific map to remove from @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the request removing a value, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnMapDataControlRemoveValueResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlResponseListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlResponseListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlResponseListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlResponseListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IMapDataControlResponseListener_Reserved5(void) {}

}; // IMapDataControlResponseListener

}} // Tizen::App

#endif // _FAPP_IMAP_DATA_CONTROL_RESPONSE_LISTENER_H_

