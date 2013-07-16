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
 * @file	FIoIDbEnumerator.h
 * @brief	This is the header file for the %IDbEnumerator interface.
 *
 * This header file contains the declarations of the %IDbEnumerator interface.
 */

#ifndef _FIO_IDB_ENUMERATOR_H_
#define _FIO_IDB_ENUMERATOR_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FBaseDateTime.h>
#include <FIoDbTypes.h>

namespace Tizen { namespace Io
{

/**
 * @interface	IDbEnumerator
 * @brief		This interface provides methods for navigating the result set from the SELECT query.
 *
 * @since		2.0
 *
 * The %IDbEnumerator interface provides methods for navigating the result set from the SELECT query.
 */
class _OSP_EXPORT_ IDbEnumerator
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since	2.0
	*/
	virtual ~IDbEnumerator(void) {}

	/**
	* Moves the enumerator to the next position.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to move the cursor position of the result set that is not activated
	*									  (the query did not yield any result). @n
	* @exception	E_OUT_OF_RANGE		The enumerator has reached out of the result set returned by the SELECT query.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	virtual result MoveNext(void) = 0;

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
	* @exception	E_OUT_OF_RANGE		The enumerator has reached out of the result set returned by the SELECT query.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	virtual result MovePrevious(void) = 0;

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
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	virtual result MoveFirst(void) = 0;

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
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	virtual result MoveLast(void) = 0;

	/**
	* Resets the calling %IDbEnumerator instance back to its initial state.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	*									- This instance has not been properly constructed. @n
	*									- The method has tried to reset the enumerator of the result set that is not activated
	*									  (the query did not yield any result). @n
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		After this method is called, if MoveNext() is called the cursor goes to the first position.
	*/
	virtual result Reset(void) = 0;

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
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	virtual result GetIntAt(int columnIndex, int& value) const = 0;

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
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	virtual result GetInt64At(int columnIndex, long long& value) const = 0;

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
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	virtual result GetDoubleAt(int columnIndex, double& value) const = 0;

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
	* @exception		E_INVALID_ARG				The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH				The operation has attempted to access columns of different types.
	* @exception		E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range, or
	*												it is possible if the database file is corrupted.
	*/
	virtual result GetStringAt(int columnIndex, Tizen::Base::String& value) const = 0;

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
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception		E_OUT_OF_RANGE		The byte buffer operation has failed.
	* @exception		E_OVERFLOW			The specified @c value of the byte buffer is insufficient to save the data.
	*/
	virtual result GetBlobAt(int columnIndex, Tizen::Base::ByteBuffer& value) const = 0;

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
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range, or the specified @c size is invalid.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception		E_OVERFLOW			The specified @c buffer is insufficient to save the data.
	*/
	virtual result GetBlobAt(int columnIndex, void* buffer, int size) const = 0;

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
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception		E_INVALID_FORMAT	The date is not correctly formatted, or the method is trying to access column of type String. @n
	*										The date format should be 'mm/dd/yyyy hh:mm:ss'.
	* @exception		E_OUT_OF_RANGE		Either the year, month, day, hour, minute, or second value is out of range,
	*										or the method is trying to access a column of type String.
	*/
	virtual result GetDateTimeAt(int columnIndex, Tizen::Base::DateTime& value) const = 0;

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
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetColumnCount(void) const = 0;

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
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				Currently, DB_COLUMNTYPE_INT is returned for a 64-bit integer. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual DbColumnType GetColumnType(int columnIndex) const = 0;

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
	* @exception	E_INVALID_ARG				The specified @c columnIndex is out of range.
	* @exception	E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range, or
	*											it is possible if the database file is corrupted.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual Tizen::Base::String GetColumnName(int columnIndex) const = 0;

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
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				If the destination column is of type %String, this method returns the @c byte length excluding the @c null terminator character. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetColumnSize(int columnIndex) const = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IDbEnumerator_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IDbEnumerator_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IDbEnumerator_Reserved3(void) {}

}; // IDBEnumerator

}} // Tizen::App

#endif // _FIO_IDB_ENUMERATOR_H_

