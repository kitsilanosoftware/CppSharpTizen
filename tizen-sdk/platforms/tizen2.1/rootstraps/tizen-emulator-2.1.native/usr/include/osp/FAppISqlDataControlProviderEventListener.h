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
 * @file    FAppISqlDataControlProviderEventListener.h
 * @brief   This is the header file for the %ISqlDataControlProviderEventListener interface.
 *
 * This header file contains the declarations of the %ISqlDataControlProviderEventListener interface.
 */

#ifndef _FAPP_ISQL_DATACONTROL_REQUESTEVENT_LISTENER_H_
#define _FAPP_ISQL_DATACONTROL_REQUESTEVENT_LISTENER_H_

#include <FBaseDataType.h>
#include <FBaseString.h>
#include <FBaseColIMapT.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace App
{

/**
 * @interface	ISqlDataControlProviderEventListener
 * @brief		This interface defines a listener for dealing with SQL-type data control request.
 *
 * @since	2.0
 *
 * The %ISqlDataControlProviderEventListener interface defines a listener for dealing with SQL-type data control request.
 *
 * The following example demonstrates how to use the %ISqlDataControlProviderEventListener interface.
 *
 * @code
#include <FBase.h>
#include <FApp.h>
#include <FIo.h>

class MyServiceApp
    : public Tizen::App::ServiceApp
	: public Tizen::App::ISqlDataControlProviderEventListener
{
public:
	MyServiceApp(void);
	virtual ~MyServiceApp(void);

	virtual bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);
	virtual bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);

	virtual void OnSqlDataControlSelectRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::Collection::IList* pColumnList,
			const Tizen::Base::String* pWhere, const Tizen::Base::String* pOrder);
	virtual void OnSqlDataControlInsertRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& insertMap);
	virtual void OnSqlDataControlUpdateRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& updateMap,
			const Tizen::Base::String* pWhere);
	virtual void OnSqlDataControlDeleteRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String* pWhere);
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

	r = pDcMgr->SetSqlDataControlProviderEventListener(this);
	if (IsFailed(r))
	{
		AppLog("Failed to set the data control provider listener.");
		return false;
	}

	return true;
}

void
MyServiceApp::OnSqlDataControlSelectRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
		const Tizen::Base::String& dataId, const Tizen::Base::Collection::IList* pColumnList,
		const Tizen::Base::String* pWhere, const Tizen::Base::String* pOrder)
{
	Database* pDb = null;
	DbEnumerator* pDbEnum = null;
	String errorMsg;
	result r = E_SUCCESS;

	if (providerId == L"http://tizen.org/datacontrol/provider/example")
	{
		if (dataId == L"test")
		{
			String sql = SqlStatementBuilder::CreateSelectStatement(dataId, pColumnList, pWhere, pOrder,
					null, null, null);

			String dbPath(App::GetInstance()->GetAppDataPath() + L"test.db");

			pDb = new Database();
			if (pDb == null)
			{
				errorMsg.Append(L"The memory is insufficient.");
				goto CATCH;
			}

			r = pDb->Construct(dbPath, "r");
			if (IsFailed(r))
			{
				errorMsg.Append(L"The data control provider failed to open the database file.");
				goto CATCH;
			}

			pDbEnum = pDb->QueryN(sql);
			r = GetLastResult();
			if (IsFailed(r))
			{
				errorMsg.Append(L"The data control provider failed to execute SQL statement.");
				goto CATCH;
			}
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

	r = DataControlProviderManager::GetInstance()->SendSqlDataControlSelectResult(reqId, pDbEnum);
	if (IsFailed(r))
	{
		AppLog("The data control provider failed to send the result.");
	}

	delete pDbEnum;
	delete pDb;
	return;

CATCH:
	r = DataControlProviderManager::Getinstance()->SendDataControlError(reqId, errorMsg);
	if (IsFailed(r))
	{
		AppLog("The data control provider failed to send the result.");
	}

	delete pDbEnum;
	delete pDb;
	return;
}

void
MyServiceApp::OnSqlDataControlInsertRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
		const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& insertMap)
{
	Database* pDb = null;
	String errorMsg;
	long long insertRowId = -1;
	result r = E_SUCCESS;

	if (providerId == L"http://tizen.org/datacontrol/provider/example")
	{
		if (dataId == L"test")
		{
			String sql = SqlStatementBuilder::CreateInsertStatement(dataId, insertMap);

			String dbPath(App::GetInstance()->GetAppDataPath() + L"test.db");

			pDb = new Database();
			if (pDb == null)
			{
				errorMsg.Append(L"The memory is insufficient.");
				goto CATCH;
			}

			r = pDb->Construct(dbPath, "a+");
			if (IsFailed(r))
			{
				errorMsg.Append(L"The data control provider failed to open the database file.");
				goto CATCH;
			}

			r = pDb->ExcuteSql(sql, true);
			if (IsFailed(r))
			{
				errorMsg.Append(L"The data control provider failed to execute SQL statement.");
				goto CATCH;
			}

			insertRowId = pDb->GetLastInsertRowId();
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

	r = DataControlProviderManager::GetInstance()->SendSqlDataControlInsertResult(reqId, insertRowId);
	if (IsFailed(r))
	{
		AppLog("The data control provider failed to send the result.");
	}

	delete pDb;
	return;

CATCH:
	r = DataControlProviderManager::Getinstance()->SendDataControlError(reqId, errorMsg);
	if (IsFailed(r))
	{
		AppLog("The data control provider failed to send the result.");
	}

	delete pDb;
	return;
}
* @endcode
*/
class _OSP_EXPORT_ ISqlDataControlProviderEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ISqlDataControlProviderEventListener(void) {}

	/**
	* Called when a select request is received from an application using SQL-type data control. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]	reqId			The request ID
	* @param[in]	providerId		The provider ID for identifying the data control
	* @param[in]	dataId			A string for identifying a specific table to query from @n
	*								The string consists of one or more components, separated by a slash('/').
	*								If the specified @c pColumnList is @c null, all columns are selected.
	* @param[in]	pColumnList		A list of column names to query @n
	*								The type of objects contained in the specified @c pColumnList is
	*								Tizen::Base::String class.
	* @param[in]	pWhere			A filter to select desired rows to query @n
	*								It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*								column1 = 'stringValue' AND column2 = numericValue.
	* @param[in]	pOrder			The sorting order of rows to query @n
	*								It is an SQL 'ORDER BY' clause excluding the 'ORDER BY' itself.
	* @remarks		For replying to the data control request, use DataControlProviderManager::SendSqlDataControlSelectResult()
	*				or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnSqlDataControlSelectRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::Collection::IList* pColumnList,
			const Tizen::Base::String* pWhere, const Tizen::Base::String* pOrder) = 0;

	/**
	* Called when an insert request is received from an application using SQL-type data control. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]	reqId			The request ID
	* @param[in]	providerId		The provider ID for identifying the data control
	* @param[in]	dataId			A string for identifying a specific table to insert into @n
	*								The string consists of one or more components, separated by a slash('/').
	* @param[in]	insertMap		The column-value pairs to insert @n
	*								The type of objects contained in the specified @c insertMap is
	*								Tizen::Base::String class.
	* @remarks		For replying to the data control request, use DataControlProviderManager::SendSqlDataControlInsertResult()
	*				or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnSqlDataControlInsertRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& insertMap) = 0;

	/**
	* Called when an update request is received from an application using SQL-type data control. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]	reqId			The request ID
	* @param[in]	providerId		The provider ID for identifying the data control
	* @param[in]	dataId			A string for identifying a specific table to update @n
	*								The string consists of one or more components, separated by a slash('/').
	* @param[in]	updateMap		The column-value pairs to update @n
	*								The type of objects contained in the specified @c updateMap is
	*								Tizen::Base::String class.
	* @param[in]	pWhere			A filter to select desired rows to update @n
	*								It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*								column1 = 'stringValue' AND column2 = numericValue.
	* @remarks		For replying to the data control request, use DataControlProviderManager::SendSqlDataControlUpdateDeleteResult()
	*				or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnSqlDataControlUpdateRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& updateMap,
			const Tizen::Base::String* pWhere) = 0;

	/**
	* Called when a delete request is received from an application using SQL-type data control. @n
	* The provider must implement this listener for providing its own data.
	*
	* @since	2.0
	*
	* @param[in]	reqId			The request ID
	* @param[in]	providerId		The provider ID for identifying the data control
	* @param[in]	dataId			A string for identifying a specific table to delete from @n
	*								The string consists of one or more components, separated by a slash('/').
	* @param[in]	pWhere			A filter to select desired rows to delete @n
	*								It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*								column1 = 'stringValue' AND column2 = numericValue.
	* @remarks		For replying to the data control request, use DataControlProviderManager::SendSqlDataControlUpdateDeleteResult()
	*				or DataControlProviderManager::SendDataControlError().
	*/
	virtual void OnSqlDataControlDeleteRequestReceived(RequestId reqId, const Tizen::Base::String& providerId,
			const Tizen::Base::String& dataId, const Tizen::Base::String* pWhere) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlProviderEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlProviderEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlProviderEventListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlProviderEventListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISqlDataControlProviderEventListener_Reserved5(void) {}

}; // ISqlDataControlProviderEventListener

}} // Tizen::App

#endif // _FAPP_ISQL_DATACONTROL_REQUESTEVENT_LISTENER_H_

