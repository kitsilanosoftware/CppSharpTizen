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
 * @file	FIoDbStatement.h
 * @brief	This is the header file for the %DbStatement class.
 *
 * This header file contains the declarations of the %DbStatement class.
 */

#ifndef _FIO_DB_STATEMENT_H_
#define _FIO_DB_STATEMENT_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FBaseDateTime.h>
#include <FBaseRtMutex.h>
#include <FIoDbTypes.h>

namespace Tizen { namespace Io
{

/**
 * @class   DbStatement
 * @brief	This class provides a method for evaluating pre-compiled statements.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %DbStatement class provides a method for evaluating pre-compiled statements.
 * All members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/io/database_operations.htm">Database Operations</a>.
 */
class _OSP_EXPORT_ DbStatement
	: public Tizen::Base::Object
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~DbStatement(void);

	/**
	* Binds an integer value to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex			The index of the column whose value is bound
	* @param[out]	value				The integer value to bind
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindInt(int columnIndex, int value);

	/**
	* Binds a @c long @c long value to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex			The index of the column whose value is bound
	* @param[out]	value				The 64-bit integer value to bind
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindInt64(int columnIndex, long long value);

	/**
	* Binds a @c double value to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex			The index of the column whose value is bound
	* @param[out]	value				The @c double value to bind
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindDouble(int columnIndex, double value);

	/**
	* Binds a String value to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex			The index of the column whose value is bound
	* @param[out]	value				The string value to bind
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c value exceeds size limit.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindString(int columnIndex, const Tizen::Base::String& value);

	/**
	* Binds a value of type ByteBuffer to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex		    The index of the column whose value is bound
	* @param[out]	value		        The blob value to bind @n
	*							        The maximum available size is limited to 100 MBytes.
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE	     The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	* 									- The specified @c columnIndex is invalid. @n
	* 									- The size of byte buffer is less than @c 0 or has @c null data. @n
	* 									- The specified @c value exceeds size limit.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	* @remarks		The bound @c byte array size is from the current position of byte buffer to the limit.
	*/
	result BindBlob(int columnIndex, const Tizen::Base::ByteBuffer& value);

	/**
	* Binds the raw blob data to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex	        The index of the column whose value is bound
	* @param[in]	buffer				A pointer to the buffer where blob data is located @n
	*									The maximum available size is limited to 100 MBytes.
	* @param[in]	size				The blob data length in bytes
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	* 									- The specified @c columnIndex is invalid. @n
	* 									- The specified @c size is less than @c 0. @n
	* 									- The pointer to the buffer is @c null. @n
	* 									- The specified @c buffer exceeds size limit.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindBlob(int columnIndex, const void* buffer, int size);

	/**
	* Binds a DateTime value to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex			The index of the column whose value is bound
	* @param[out]	value				The date value to bind
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid, or
	*									the value is less than @c or a @c null pointer.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindDateTime(int columnIndex, const Tizen::Base::DateTime& value);

	/**
	* Binds a @c null value to the statement parameter.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompDatabaseExceptionPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	columnIndex			The index of the column whose value is bound
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
	*									or the instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_INVALID_OPERATION	This method has failed to bind the parameter because the database state has not been reset
	*									after executing the SELECT query by using Database::ExecuteStatementN() or DbEnumerator::MoveNext().
	*									In this case DbEnumerator::Reset() should be invoked before calling this method.
	*/
	result BindNull(int columnIndex);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since 2.0
	*/
	DbStatement(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	DbStatement(const DbStatement& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	DbStatement& operator =(const DbStatement& rhs);

	class _DbStatementImpl* __pDbStatementImpl;

	friend class _DbStatementImpl;

}; // DbStatement

}} // Tizen::Io

#endif  //_FIO_DB_STATEMENT_H_

