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
* @file		FAppISqlDataControlResponseListener.h
* @brief	This is the header file for the %ISqlDataControlResponseListener interface.
*
* This header file contains the declarations of the %ISqlDataControlResponseListener interface.
*/

#ifndef _FAPP_ISQL_DATACONTROL_RESPONSE_LISTENER_H_
#define _FAPP_ISQL_DATACONTROL_RESPONSE_LISTENER_H_

#include <FBaseDataType.h>
#include <FBaseString.h>
#include <FBaseRtIEventListener.h>
#include <FIoIDbEnumerator.h>

namespace Tizen { namespace App
{

/**
*   @interface	ISqlDataControlResponseListener
*   @brief		This interface defines a listener for the SQL-type data control response.
*
*   @since	2.0
*
*   The %ISqlDataControlResponseListener interface defines a listener for the SQL-type data control response.
*/
class _OSP_EXPORT_ ISqlDataControlResponseListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ISqlDataControlResponseListener(void) {}

	/**
	* Called when the result set is received from SQL-type data control provider. @n
	* The application requesting the data control can get the query result by implementing this listener. @n
	* This listener must be registered by SqlDataControl::SetSqlDataControlResponseListener() for receiving the result set.
	* It is called after SqlDataControl::Select().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific table to query from @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	resultSetEnumerator	Navigates the result of data control select request
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the query request, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnSqlDataControlSelectResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, Tizen::Io::IDbEnumerator& resultSetEnumerator, bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

	/**
	* Called when the response is received from SQL-type data control provider. @n
	* The application requesting the data control can get insert result by implementing this listener. @n
	* This listener must be registered by SqlDataControl::SetSqlDataControlResponseListener() for receiving the result response.
	* It is called after SqlDataControl::Insert().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific table to insert into @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	insertRowId			The inserted row ID set by the data control provider if the specified @c providerResult is @c true, @n
	*									else @c -1
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the insert request, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnSqlDataControlInsertResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, long long insertRowId, bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

	/**
	* Called when the response is received from SQL-type data control provider. @n
	* The application requesting the data control can get update result implementing this listener. @n
	* This listener must be registered by SqlDataControl::SetSqlDataControlResponseListener() for receiving the result response.
	* It is called after SqlDataControl::Update().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId 			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific table to update @n
	*						 			The string consists of one or more components, separated by a slash('/').
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the update request, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnSqlDataControlUpdateResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, bool providerResult, const Tizen::Base::String* pErrorMsg) = 0;

	/**
	* Called when the response is received from SQL-type data control provider. @n
	* The application requesting the data control can get delete result by implementing this listener. @n
	* This listener must be registered by SqlDataControl::SetSqlDataControlResponseListener() for receiving the result response.
	* It is called after SqlDataControl::Delete().
	*
	* @since	2.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	providerId			The data control provider ID
	* @param[in]	dataId				A string for identifying a specific table to delete from @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	providerResult		Set to @c true if the data control provider successfully processed the delete request, @n
	*									else @c false
	* @param[in]	pErrorMsg			The error message from the data control provider
	*/
	virtual void OnSqlDataControlDeleteResponseReceived(RequestId reqId, const Tizen::Base::String& providerId,
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
	virtual void ISqlDataControlResponseListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlResponseListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlResponseListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlResponseListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlResponseListener_Reserved5(void) {}

}; // ISqlDataControlResponseListener

}} // Tizen::App

#endif // _FAPP_ISQL_DATACONTROL_RESPONSE_LISTENER_H_

