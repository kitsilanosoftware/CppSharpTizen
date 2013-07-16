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
 * @file	FIoSqlStatementBuilder.h
 * @brief	This is the header file for the %SqlStatementBuilder class.
 *
 * This header file contains the declarations of the %SqlStatementBuilder class.
 */

#ifndef _FIO_SQL_STATEMENT_BUILDER_H_
#define _FIO_SQL_STATEMENT_BUILDER_H_

#include <FOspConfig.h>

namespace Tizen { namespace Base
{
class String;
namespace Collection
{
class IList;
class IMap;
}
}}

namespace Tizen { namespace Io
{

/**
 * @class	SqlStatementBuilder
 * @brief	This class provides methods for building SQL statement.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %SqlStatementBuilder class provides methods for building SQL statement.
 */
class _OSP_EXPORT_ SqlStatementBuilder
	: public Tizen::Base::Object
{

public:
	/**
	* Creates SQL SELECT statement.
	*
	* @since		2.0
	*
	* @return		A created SQL SELECT statement, @n
	*				else an empty string in case of failure
	* @param[in]	table				A table name to query from
	* @param[in]	pColumnList			A list of column names to query @n
	*									The type of objects contained in the specified @c pColumnList must be
	*									Tizen::Base::String class.
	*									If it is @c null, all columns are returned in result set.
	* @param[in]	pWhere				A filter to select desired rows to query @n
	*									It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*									column1 = 'stringValue' AND column2 = numericValue.
	* @param[in]	pOrder				Sorting order of rows to query @n
	*									It is an SQL 'ORDER BY' clause excluding the 'ORDER BY' itself.
	* @param[in]	pLimit				Limitation of the number of rows to query @n
	*									It is the SQL 'LIMIT' clause excluding the 'LIMIT' itself.
	* @param[in]	pGroup				A filter to select a column grouping rows to query @n
	*									It is the SQL 'GROUP BY' clause excluding the 'GROUP BY' itself.
	* @param[in]	pHaving				A filter for the group @n
	*									It is the SQL 'HAVING' clause excluding the 'HAVING' itself.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred:
	*									- The specified @c pColumnList is empty.
	*									- The specified @c pOrder is @c null and @c pLimit is not @c null.
	*									- The specified @c pGroup is @c null and @c pHaving is not @c null.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @remarks		If the value specified in the @c pWhere is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLite SQL documents.
	*/
	static Tizen::Base::String CreateSelectStatement(const Tizen::Base::String& table, const Tizen::Base::Collection::IList* pColumnList,
			const Tizen::Base::String* pWhere, const Tizen::Base::String* pOrder = null, const Tizen::Base::String* pLimit = null,
			const Tizen::Base::String* pGroup = null, const Tizen::Base::String* pHaving = null);

	/**
	* Creates SQL INSERT statement.
	*
	* @since		2.0
	*
	* @return		A created SQL INSERT statement, @n
	*				else an empty string in case of failure @n
	* @param[in]	table				A table name to insert
	* @param[in]	insertMap			Column-value pairs to insert @n
	*									The type of objects contained in the specified @c insertMap must be
	*									Tizen::Base::String class.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c insertMap is empty.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @remarks		If the value specified in the @c insertMap is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLite SQL documents.
	*/
	static Tizen::Base::String CreateInsertStatement(const Tizen::Base::String& table, const Tizen::Base::Collection::IMap& insertMap);

	/**
	* Creates SQL UPDATE statement.
	*
	* @since		2.0
	*
	* @return		A created SQL UPDATE statement, @n
	*				else an empty string in case of failure @n
	* @param[in]	table				A table name to update
	* @param[in]	updateMap			Column-value pairs to update @n
	*									The type of objects contained in the specified @c updateMap must be
	*									Tizen::Base::String class.
	* @param[in]	pWhere				A filter to select desired rows to update @n
	*									It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*									column1 = 'stringValue' AND column2 = numericValue.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c updateMap is empty.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @remarks		If the value specified in the @c pWhere or @c updateMap is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLITE SQL documents.
	*/
	static Tizen::Base::String CreateUpdateStatement(const Tizen::Base::String& table, const Tizen::Base::Collection::IMap& updateMap,
			const Tizen::Base::String* pWhere);

	/**
	* Creates SQL DELETE statement.
	*
	* @since		2.0
	*
	* @return		A created SQL DELETE statement, @n
	*				else an empty string in case of failure @n
	* @param[in]	table				A table name to query
	* @param[in]	pWhere				A filter to select desired rows to delete @n
	*									It is an SQL 'WHERE' clause excluding the 'WHERE' itself such as
	*									column1 = 'stringValue' AND column2 = numericValue.
	*									If it is @c null, all rows are deleted.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified parameter is invalid.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @remarks		If the value specified in the @c pWhere is string, the value must be wrapped in
	*				single quotes. Otherwise it is not needed to wrap the numeric value in single quotes.
	*				For more information on the SQL statement, see SQLITE SQL documents.
	*/
	static Tizen::Base::String CreateDeleteStatement(const Tizen::Base::String& table, const Tizen::Base::String* pWhere);

private:
	/**
	* This default constructor is intentionally declared as private because this class cannot be constructed.
	*
	* @since	2.0
	*/
	SqlStatementBuilder(void);

	/**
	* This destructor is intentionally declared as private because this class cannot be constructed.
	*
	* @since	2.0
	*/
	virtual ~SqlStatementBuilder(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	* @remarks	This constructor is hidden.
	*/
	SqlStatementBuilder(const SqlStatementBuilder& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	* @remarks	This operator is hidden.
	*/
	SqlStatementBuilder& operator =(const SqlStatementBuilder& rhs);

	class _SqlStatementBuilderImpl* __pSqlStatementBuilderImpl;

}; // SqlStatementBuilder

}} // Tizen::Io

#endif // _FIO_SQL_STATEMENT_BUILDER_H_

