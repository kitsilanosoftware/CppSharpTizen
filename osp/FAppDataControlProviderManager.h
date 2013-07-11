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
 * @file	FAppDataControlProviderManager.h
 * @brief	This is the header file for the %DataControlProviderManager class.
 *
 * This header file contains the declarations of the %DataControlProviderManager class.
 */

#ifndef _FAPP_DATA_CONTROL_PROVIDER_MANAGER_H_
#define _FAPP_DATA_CONTROL_PROVIDER_MANAGER_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FBaseColIList.h>
#include <FIoIDbEnumerator.h>

namespace Tizen { namespace Base
{
class String;
class ByteBuffer;
}}
namespace Tizen { namespace Io
{
class DbEnumerator;
class DataControlResultSet;
}}

namespace Tizen { namespace App
{

class ISqlDataControlProviderEventListener;
class IMapDataControlProviderEventListener;

/**
 * @class	DataControlProviderManager
 * @brief	This class manages the data control provider.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %DataControlProviderManager class manages the data control provider.
 */
class _OSP_EXPORT_ DataControlProviderManager
	: public Tizen::Base::Object
{

public:
	/**
	* Sets a SQL-type data control provider listener to the data control provider manager. @n
	* The listener gets notified when a data control request is received from the other applications.
	* To unset the listener, pass a @c null value to the listener parameter.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	pListener			The SQL-type data control provider listener @n
	*									The listener must implement the ISqlDataControlProviderEventListener interface.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_INVALID_OPERATION	The listener must be set for a service application.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		This method must be called in App::OnAppInitializing() for setting the data control provider listener
	*				before receiving the data control request.
	*/
	result SetSqlDataControlProviderEventListener(ISqlDataControlProviderEventListener* pListener);

	/**
	* Sets a MAP-type data control provider listener to the data control provider manager. @n
	* The listener gets notified when a data control request is received from the other applications.
	* To unset the listener, pass a @c null value to the listener parameter.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	pListener			The MAP-type data control provider listener @n
	*									The listener must implement the IMapDataControlProviderEventListener interface.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_INVALID_OPERATION	The listener must be set for a service application.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		This method must be called in App::OnAppInitializing() for setting the data control provider listener
	*				before receiving the data control request.
	*/
	result SetMapDataControlProviderEventListener(IMapDataControlProviderEventListener* pListener);

	/**
	* Sends the success result and the result set of SELECT request to the application requesting the SQL-type
	* data control. @n
	* The data control provider must call the %SendSqlDataControlSelectResult() method to notify success to the requesting application.
	* The application requesting the data control can get the success result and the result set
	* by implementing Tizen::App::ISqlDataControlResponseListener.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	reqId				The request ID
	* @param[in]	pDbEnum				The Tizen::Io::DbEnumerator instance to obtain the result set
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred:
	*									- This method cannot send result for the specified @c reqId of INSERT, UPDATE, or DELETE requests.
	*									- Tizen::Io::Database or Tizen::Io::DbStatement instance associated with the specified @c pDbEnum is deleted.
	* @exception	E_OBJ_NOT_FOUND		The data control request specified with the @c reqId did not exist.
	* @exception	E_OBJECT_LOCKED		The database instance associated to the specified @c pDbEnum is locked.
	* @exception	E_INVALID_FORMAT	The database file associated to the specified @c pDbEnum is malformed.
	* @exception	E_IO				Either of the following conditions has occurred:
	*									- An unexpected device failure has occurred as the media ejected suddenly.
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlInsertResult()
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlUpdateDeleteResult()
	* @see			Tizen::App::DataControlProviderManager::SendDataControlError()
	* @see			Tizen::App::ISqlDataControlProviderEventListener
	*/
	result SendSqlDataControlSelectResult(RequestId reqId, Tizen::Io::IDbEnumerator* pDbEnum);

	/**
	* Sends the success result of INSERT request and the last inserted row ID to the application requesting
	* the SQL-type data control. @n
	* The data control provider must call the %SendSqlDataControlInsertResult() method to notify success to the requesting application.
	* The application requesting the data control can get the success result and the last inserted row ID
	* by implementing Tizen::App::ISqlDataControlResponseListener.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	reqId				The request ID
	* @param[in]	insertRowId			The row ID of database changed by INSERT request
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		This method cannot send result for the specified @c reqId of SELECT, UPDATE, or DELETE request.
	* @exception	E_OBJ_NOT_FOUND		The data control request specified with the @c reqId did not exist.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlSelectResult()
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlUpdateDeleteResult()
	* @see			Tizen::App::DataControlProviderManager::SendDataControlError()
	* @see			Tizen::App::ISqlDataControlProviderEventListener
	* @see			Tizen::Io::Database::GetLastInsertRowId()
	*/
	result SendSqlDataControlInsertResult(RequestId reqId, long long insertRowId);

	/**
	* Sends the success result of UPDATE / DELETE request to the application requesting the SQL-type data control. @n
	* The data control provider must call the %SendSqlDataControlUpdateDeleteResult() method to notify success to the requesting application.
	* The application requesting the data control can get the success result by implementing Tizen::App::ISqlDataControlResponseListener.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		This method cannot send result for the specified @c reqId of SELECT or INSERT request.
	* @exception	E_OBJ_NOT_FOUND		The data control request specified with the @c reqId did not exist.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlSelectResult()
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlInsertResult()
	* @see			Tizen::App::DataControlProviderManager::SendDataControlError()
	* @see			Tizen::App::ISqlDataControlProviderEventListener
	*/
	result SendSqlDataControlUpdateDeleteResult(RequestId reqId);

	/**
	* Sends the success result and the result list of the provider to the application requesting the MAP-type
	* data control. @n
	* The data control provider must call the %SendMapDataControlResult() method to notify success to the requesting application.
	* The application requesting the data control can get the success result and the result set
	* by implementing Tizen::App::IMapDataControlResponseListener.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	reqId				The request ID
	* @param[in]	pResultValueList	The result list to request @n
	*									The type of objects contained in the specified @c pResultValueList must be
	*									Tizen::Base::String class.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred:
	*									- The specified @c pResultValueList must be @c null if the request is one of
	*									  AddValue, SetValue, RemoveValue queries.
	*									- The specified @c pResultValueList must not be @c null if the request is
	*									  GetValue() query.
	* @exception	E_OBJ_NOT_FOUND		The data control request specified with the @c reqId does not exist.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			Tizen::App::DataControlProviderManager::SendDataControlError()
	* @see			Tizen::App::IMapDataControlProviderEventListener
	*/
	result SendMapDataControlResult(RequestId reqId, Tizen::Base::Collection::IList* pResultValueList = null);

	/**
	* Sends the provider error message to the application requesting the data control. @n
	* The data control provider must call the %SendDataControlError() method to notify failure to the requesting application.
	* The application requesting the data control can get the failure result and the error message
	* by implementing Tizen::App::ISqlDataControlResponseListener.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	reqId				The request ID
	* @param[in]	errorMsg			The provider-defined error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_NOT_FOUND		The data control request specified with the @c reqId did not exist.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlSelectResult()
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlInsertResult()
	* @see			Tizen::App::DataControlProviderManager::SendSqlDataControlUpdateDeleteResult()
	* @see			Tizen::App::DataControlProviderManager::SendMapDataControlResult()
	* @see			Tizen::App::ISqlDataControlProviderEventListener
	* @see			Tizen::App::IMapDataControlProviderEventListener
	*/
	result SendDataControlError(RequestId reqId, const Tizen::Base::String& errorMsg);

	/**
	* Gets the data control provider manager instance.
	*
	* @since	2.0
	*
	* @return	A pointer to the %DataControlProviderManager instance if it succeeds, @n
	*			else @c null
	*/
	static DataControlProviderManager* GetInstance(void);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	DataControlProviderManager(void);

	/**
	 * This destructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~DataControlProviderManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	DataControlProviderManager(const DataControlProviderManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	DataControlProviderManager& operator =(const DataControlProviderManager& rhs);

private:
	class _DataControlProviderManagerImpl* __pDataControlProviderManagerImpl;

	friend class _DataControlProviderManagerImpl;

}; // DataControlProviderManager

}} // Tizen::App

#endif // _FAPP_DATA_CONTROL_PROVIDER_MANAGER_H_

