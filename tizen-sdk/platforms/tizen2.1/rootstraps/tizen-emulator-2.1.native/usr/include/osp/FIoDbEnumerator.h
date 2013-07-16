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
 * @file	FIoDbEnumerator.h
 * @brief	This is the header file for the %DbEnumerator class.
 *
 * This header file contains the declarations of the %DbEnumerator class.
 */

#ifndef _FIO_DB_ENUMERATOR_H_
#define _FIO_DB_ENUMERATOR_H_

#include <FBaseObject.h>
#include <FBaseRtMutex.h>
#include <FIoDbTypes.h>
#include <FIoIDbEnumerator.h>

namespace Tizen { namespace Base
{
class String;
class ByteBuffer;
class DateTime;
}}

namespace Tizen { namespace Io
{

/**
 * @class   DbEnumerator
 * @brief	This class provides methods for navigating the result set from the SELECT query.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %DbEnumerator class provides methods for navigating the result set from the SELECT query.
 * All the members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/io/database_operations.htm">Database Operations</a>.
 *
 * @see Tizen::Io::Database
 */
class _OSP_EXPORT_ DbEnumerator
	: public Tizen::Base::Object
	, public Tizen::Io::IDbEnumerator
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~DbEnumerator(void);

	/**
	* Moves the enumerator to the next position.
	*
	* @since			2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to move the cursor position of the result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_OUT_OF_RANGE		The enumerator has reached out of the result set returned by the SELECT query.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred:  @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see		Tizen::Io::Database::ExecuteStatementN()
	* @see	       Tizen::Io::Database::QueryN()
	* @see		Tizen::Io::DbEnumerator::MovePrevious()
	* @see	       Tizen::Io::DbEnumerator::MoveFirst()
	* @see	       Tizen::Io::DbEnumerator::MoveLast()
	*/
	virtual result MoveNext(void);

	/**
	* Moves the enumerator to the previous position.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to move the cursor position of the result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_OUT_OF_RANGE		The enumerator has reached out of the result set returned by the SELECT query.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see		Tizen::Io::Database::ExecuteStatementN()
	* @see	       Tizen::Io::Database::QueryN()
	* @see		Tizen::Io::DbEnumerator::MoveNext()
	* @see	       Tizen::Io::DbEnumerator::MoveFirst()
	* @see	       Tizen::Io::DbEnumerator::MoveLast()
	*/
	virtual result MovePrevious(void);

	/**
	* Moves the enumerator to the first position.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to move the cursor position of the result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see		Tizen::Io::Database::ExecuteStatementN()
	* @see		Tizen::Io::Database::QueryN()
	* @see		Tizen::Io::DbEnumerator::MoveNext()
	* @see		Tizen::Io::DbEnumerator::MovePrevious()
	* @see		Tizen::Io::DbEnumerator::MoveLast()
	*/
	virtual result MoveFirst(void);

	/**
	* Moves the enumerator to the last position.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to move the cursor position of the result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see		Tizen::Io::Database::ExecuteStatementN()
	* @see		Tizen::Io::Database::QueryN()
	* @see		Tizen::Io::DbEnumerator::MoveNext()
	* @see		Tizen::Io::DbEnumerator::MovePrevious()
	* @see		Tizen::Io::DbEnumerator::MoveFirst()
	*/
	virtual result MoveLast(void);

	/**
	* Resets the calling %DbEnumerator instance back to its initial state.
	*
	* @since			2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to reset the enumerator of the result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		After this method is called, if MoveNext() is called the cursor goes to the first position.
	*/
	virtual result Reset(void);

	/**
	* Gets an @c int value from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The integer value obtained from the column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		Either of the following conditions has occurred: @n
	*										- This instance has not been properly constructed. @n
	*										- The method has tried to fetch the column data of a result set that is not activated
	*										  (the query did not yield any result). @n
	*										- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	virtual result GetIntAt(int columnIndex, int& value) const;

	/**
	* Gets a @c long @c long value from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The 64-bit integer value obtained from the column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		Either of the following conditions has occurred: @n
	*										- This instance has not been properly constructed. @n
	*										- The method has tried to fetch the column data of a result set that is not activated
	*										  (the query did not yield any result). @n
	*										- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	virtual result GetInt64At(int columnIndex, long long& value) const;

	/**
	* Gets a @c double value from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The value obtained from the column as a double
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		Either of the following conditions has occurred: @n
	*										- This instance has not been properly constructed. @n
	*										- The method has tried to fetch the column data of a result set that is not activated
	*										  (the query did not yield any result). @n
	*										- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	virtual result GetDoubleAt(int columnIndex, double& value) const;

	/**
	* Gets a @c String value from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex					The index of the column whose value is required
	* @param[in,out]	value						The value obtained from the column as a String
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				Either of the following conditions has occurred: @n
	*												- This instance has not been properly constructed. @n
	*												- The method has tried to fetch the column data of a result set that is not activated
	*												  (the query did not yield any result). @n
	*												- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG				The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH				The operation has attempted to access columns of different types.
	* @exception		E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range, or
	*												it is possible if the database file is corrupted.
	*/
	virtual result GetStringAt(int columnIndex, Tizen::Base::String& value) const;

	/**
	* Gets a byte array value from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The user-provided buffer used to receive the blob data as a stream of type ByteBuffer @n
	*										The buffer will be filled from the current position and data copy will be continued
	*										until buffer limitation is reached or no more blob data remains. @n
	*										The maximum size available is limited to 100 MByte.
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		Either of the following conditions has occurred: @n
	*										- This instance has not been properly constructed. @n
	*										- The method has tried to fetch the column data of a result set that is not activated
	*										  (the query did not yield any result). @n
	*										- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception		E_OUT_OF_RANGE		The byte buffer operation has failed.
	* @exception		E_OVERFLOW			The specified @c value of the byte buffer is insufficient to save the data.
	*/
	virtual result GetBlobAt(int columnIndex, Tizen::Base::ByteBuffer& value) const;

	/**
	* Gets a blob data from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	buffer				The user-provided buffer used to receive the blob data @n
	*										The maximum size available is limited to 100 MByte.
	* @param[out]		size				The maximum buffer length in bytes
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		Either of the following conditions has occurred: @n
	*										- This instance has not been properly constructed. @n
	*										- The method has tried to fetch the column data of a result set that is not activated
	*										  (the query did not yield any result). @n
	*										- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range, or the specified @c size is invalid.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception		E_OVERFLOW			The specified @c buffer is insufficient to save the data.
	*/
	virtual result GetBlobAt(int columnIndex, void* buffer, int size) const;

	/**
	* Gets a @c DateTime value from the column whose index is specified.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The value obtained from the column as a DateTime instance
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		Either of the following conditions has occurred: @n
	*										- This instance has not been properly constructed. @n
	*										- The method has tried to fetch the column data of a result set that is not activated
	*										  (the query did not yield any result). @n
	*										- The Database or DbStatement instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception		E_INVALID_FORMAT	The date is not correctly formatted, or the method is trying to access column of type String. @n
	*										The date format should be 'mm/dd/yyyy hh:mm:ss'.
	* @exception		E_OUT_OF_RANGE		Either the year, month, day, hour, minute, or second value is out of range,
	*										or the method is trying to access a column of type String.
	*/
	virtual result GetDateTimeAt(int columnIndex, Tizen::Base::DateTime& value) const;

	/**
	* Gets the number of columns for this enumerator.
	*
	* @since		2.0
	*
	* @return		The number of columns in the calling enumerator, @n
	*				else @c -1 if an exception occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to fetch the column data of a result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @remarks		The method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetColumnCount(void) const;

	/**
	* Gets the type of the column indicated by the specified index.
	*
	* @since		2.0
	*
	* @return		The type of column, @n
	*				else DB_COLUMNTYPE_UNDEFINED if an exception occurs
	* @param[in]	columnIndex			The index of the destination column
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to fetch the column data of a result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				Currently, DB_COLUMNTYPE_INT is returned for a 64-bit integer. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual DbColumnType GetColumnType(int columnIndex) const;

	/**
	* Gets the name of the column indicated by the specified index.
	*
	* @since		2.0
	*
	* @return		The name of the column, @n
	*				else an empty string if an exception occurs
	* @param[in]	columnIndex					The index of the destination column
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				Either of the following conditions has occurred: @n
	*											- This instance has not been properly constructed. @n
	*											- The method has tried to fetch the column data of a result set that is not activated
	*											  (the query did not yield any result). @n
	*											- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_INVALID_ARG				The specified @c columnIndex is out of range.
	* @exception	E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range, or
	*											it is possible if the database file is corrupted.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual Tizen::Base::String GetColumnName(int columnIndex) const;

	/**
	* Gets the size of data in bytes.
	*
	* @since		2.0
	*
	* @return		The size of the data in bytes, @n
	*				else @c -1 if an exception occurs
	* @param[in]	columnIndex			The index of the destination column
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to fetch the column data of a result set that is not activated
	*									  (the query did not yield any result). @n
	*									- The Database or DbStatement instance associated with this instance is deleted.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				If the destination column is of type String, this method returns the @c byte length excluding the @c null terminator character. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetColumnSize(int columnIndex) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since 2.0
	*/
	DbEnumerator(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	DbEnumerator(const DbEnumerator& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	* @since 2.0
	*/
	DbEnumerator& operator =(const DbEnumerator& rhs);

	class _DbEnumeratorImpl* __pDbEnumeratorImpl;

	friend class _DbEnumeratorImpl;

}; // DbEnumerator

}} // Tizen::Io

#endif // _FIO_DB_ENUMERATOR_H_

