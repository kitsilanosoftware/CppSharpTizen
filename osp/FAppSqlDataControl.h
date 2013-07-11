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
* @file       FAppSqlDataControl.h
* @brief      This is the header file for the %SqlDataControl class.
*
* This header file contains the declarations of the %SqlDataControl class.
*/

#ifndef _FAPP_SQL_DATA_CONTROL_H_
#define _FAPP_SQL_DATA_CONTROL_H_

#include <FOspConfig.h>
#include <FBaseDataType.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base
{
class String;
namespace Collection {
class IList;
class IMap;
}
}}

namespace Tizen { namespace App
{

class _SqlDataControlImpl;
class ISqlDataControlResponseListener;

/**
 * @class   SqlDataControl
 * @brief   This class represents the SQL-type data control behavior.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %SqlDataControl class represents the data control behavior, that provides a standard mechanism
 * for accessing specific data exported by other applications.
 * Data control provider can share its own data to data control consumers.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/data_controls.htm">Data Controls</a>.
 *
 * @see	Tizen::App::AppManager
 */

class _OSP_EXPORT_ SqlDataControl
	: public Tizen::Base::Object
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~SqlDataControl(void);

	/**
	* Selects the specified columns to be queried. @n
	* The result set of the specified columns is retrieved from a table owned by an SQL-type data control provider. @n
	* The %Select() method is asynchronous.
	* For receiving the response from the data control provider, set the listener with
	* SqlDataControl::SetSqlDataControlResponseListener(). @n
	* When the requested result set has been received from the data control provider,
	* the ISqlDataControlResponseListener::OnSqlDataControlSelectResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId				A string for identifying specific data, usually a database table to query from @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	pColumnList			A list of column names to query @n
	*									The type of objects contained in the specified @c pColumnList must be
	*									Tizen::Base::String class.
	*									If the specified @c pColumnList is @c null, all columns are selected.
	* @param[in]	pWhere				A filter to select desired rows to query @n
	*									It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*									column1 = 'stringValue' AND column2 = numericValue.
	* @param[in]	pOrder				The sorting order of rows to query @n
	*									It is an SQL 'ORDER BY' clause excluding the 'ORDER BY' itself.
	* @param[out]   reqId				The request ID
	* @param[in]	pageNo				The page number of the result set @n It starts from @c 1.
	* @param[in]	countPerPage		The desired maximum count of rows on a page
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred:
	*									- The specified @c pColumnList is empty.
	*									- The specified @c pageNo parameter is less than @c 1.
	*									- The specified @c countPerPage parameter is less than @c 1.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		If the value specified in the @c pWhere is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLite SQL documents.
	*/
	result Select(const Tizen::Base::String& dataId, const Tizen::Base::Collection::IList* pColumnList,
			const Tizen::Base::String* pWhere, const Tizen::Base::String *pOrder, RequestId& reqId,
			int pageNo = 1, int countPerPage = 20);

	/**
	* Inserts new rows into a table owned by an SQL-type data control provider. @n
	* The %Insert() method is asynchronous.
	* For receiving the response from the data control provider, set the listener with
	* SqlDataControl::SetSqlDataControlResponseListener(). @n
	* When the response has been received from the data control provider,
	* the ISqlDataControlResponseListener::OnSqlDataControlInsertResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId				A string for identifying specific data, usually a database table to insert into @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	insertMap			The column-value pairs to insert @n
	*									The type of objects contained in the specified @c insertMap must be
	*									Tizen::Base::String class.
	* @param[out]   reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_INVALID_ARG		The specified @c insertMap is empty.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		If the value specified in the @c insertMap is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLite SQL documents.
	*/
	result Insert(const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& insertMap, RequestId& reqId);

	/**
	* Updates values of a table owned by an SQL-type data control provider. @n
	* The %Update() method is asynchronous.
	* For receiving the response from the data control provider, set the listener with
	* SqlDataControl::SetSqlDataControlResponseListener(). @n
	* When the response has been received from the data control provider,
	* the ISqlDataControlResponseListener::OnSqlDataControlUpdateResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId				A string for identifying specific data, usually a database table to update @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	updateMap			The column-value pairs to update @n
	*									The type of objects contained in the specified @c updateMap must be
	*									Tizen::Base::String class. @n
	* @param[in]	pWhere				A filter to select desired rows to update @n
	*									It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*									column1 = 'stringValue' AND column2 = numericValue.
	* @param[out]   reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_INVALID_ARG		The specified @c updateMap is empty.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		If the value specified in the @c pWhere or @c updateMap is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLITE SQL documents.
	*/
	result Update(const Tizen::Base::String& dataId, const Tizen::Base::Collection::IMap& updateMap,
			const Tizen::Base::String* pWhere, RequestId& reqId);

	/**
	* Deletes rows of a table owned by an SQL-type data control provider. @n
	* The %Delete() method is asynchronous.
	* For receiving the response from the data control provider, set the listener with
	* SqlDataControl::SetSqlDataControlResponseListener(). @n
	* When the response has been received from the data control provider,
	* the ISqlDataControlResponseListener::OnSqlDataControlDeleteResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId				A string for identifying specific data, usually a database table to delete from @n
	*									The string consists of one or more components, separated by a slash('/').
	* @param[in]	pWhere				A filter to select desired rows to delete @n
	*									It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*									column1 = 'stringValue' AND column2 = numericValue.
	*									If it is @c null, all rows are deleted.
	* @param[out]   reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_INVALID_ARG		A specified parameter is invalid.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		If the value specified in the @c pWhere is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLITE SQL documents.
	*/
	result Delete(const Tizen::Base::String& dataId, const Tizen::Base::String* pWhere, RequestId& reqId);

	/**
	* Sets an SQL-type data control listener to this instance.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	pListener			The data control callback listener @n
	*									Some data controls need to get the callback result by implementing
	*									the ISqlDataControlResponseListener interface.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result SetSqlDataControlResponseListener(ISqlDataControlResponseListener* pListener);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since	2.0
	*/
	SqlDataControl(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	* @remarks	This constructor is hidden.
	*/
	SqlDataControl(const SqlDataControl& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	* @remarks	This operator is hidden.
	*/
	SqlDataControl& operator =(const SqlDataControl& rhs);

	class _SqlDataControlImpl* __pSqlDataControlImpl;

	friend class _SqlDataControlImpl;

}; // SqlDataControl

}} // Tizen::App

#endif // _FAPP_SQL_DATA_CONTROL_H_

