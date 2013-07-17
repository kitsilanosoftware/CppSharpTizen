//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
* @file            FIoDataSetEnumerator.h
* @brief          This is the header file for the %DataSetEnumerator class.
*
* This header file contains the declarations of the %DataSetEnumerator class.
*/

#ifndef _FIO_DATA_SET_ENUMERATOR_H_
#define _FIO_DATA_SET_ENUMERATOR_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseDateTime.h>
#include <FIoIDbEnumerator.h>
#include <FIoDbTypes.h>

namespace Tizen { namespace Base
{
class String;
class ByteBuffer;
class DateTime;
}}

namespace Tizen { namespace Io
{

/**
* @class		DataSetEnumerator
* @brief		This class provides methods for navigating the set of data in in-memory table.
*
* @since		2.1
*
* @final		This class is not intended for extension.
*
* The %DataSetEnumerator class provides methods for navigating the set of data in in-memory table.
*
* @see Tizen::Io::DataSet
*/
class _OSP_EXPORT_ DataSetEnumerator
	: public Tizen::Base::Object
	, public Tizen::Io::IDbEnumerator
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.1
	*/
	virtual ~DataSetEnumerator(void);

	/**
	* Moves the enumerator to the next position.
	*
	* @since		2.1
	*
	* @return		An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_OUT_OF_RANGE		The enumerator has reached out of the data set.
	* @exception		E_OBJECT_LOCKED	The DataSet instance is locked.
	* @exception		E_INVALID_FORMAT	The in-memory data is malformed.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception		E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		After getting this %DataSetEnumerator instance,
	*				if this method is called first, the cursor goes to the first position.
	* @see			Tizen::Io::DataSetEnumerator::MovePrevious()
	* @see			Tizen::Io::DataSetEnumerator::MoveFirst()
	* @see			Tizen::Io::DataSetEnumerator::MoveLast()
	*/
	virtual result MoveNext(void);


	/**
	* Moves the enumerator to the previous position.
	*
	* @since		2.1
	*
	* @return		An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_OUT_OF_RANGE		The enumerator has reached out of the data set.
	* @exception		E_OBJECT_LOCKED	The DataSet instance is locked.
	* @exception		E_INVALID_FORMAT	The in-memory data is malformed.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception		E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			Tizen::Io::DataSetEnumerator::MoveNext()
	* @see			Tizen::Io::DataSetEnumerator::MoveFirst()
	* @see			Tizen::Io::DataSetEnumerator::MoveLast()
	*/
	virtual result MovePrevious(void);

	/**
	* Moves the enumerator to the first position.
	*
	* @since		2.1
	*
	* @return		An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_OBJECT_LOCKED	The DataSet instance is locked.
	* @exception		E_INVALID_FORMAT	The in-memory data is malformed.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception		E_SYSTEM 			The method cannot proceed due to a severe system error.
	* @see			Tizen:Io::DataSetEnumerator::MoveNext()
	* @see			Tizen:Io::DataSetEnumerator::MovePrevious()
	* @see			Tizen:Io::DataSetEnumerator::MoveLast()
	*/
	virtual result MoveFirst(void);

	/**
	* Moves the enumerator to the last position.
	*
	* @since          2.1
	*
	* @return		An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_OBJECT_LOCKED	The DataSet instance is locked.
	* @exception		E_INVALID_FORMAT	The in-memory data is malformed.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception		E_SYSTEM 			The method cannot proceed due to a severe system error.
	* @see			Tizen:Io::DataSetEnumerator::MoveNext()
	* @see			Tizen:Io::DataSetEnumerator::MovePrevious()
	* @see			Tizen:Io::DataSetEnumerator::MoveFirst()
	*/
	virtual result MoveLast(void);

	/**
	* Resets the calling %DataSetEnumerator instance back to its initial state.
	*
	* @since		2.1
	*
	* @return		An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_OBJECT_LOCKED	The DataSet instance is locked.
	* @exception		E_SYSTEM 			The method cannot proceed due to a severe system error.
	* @remarks		After this method is called, if MoveNext() is called the cursor goes to the first position.
	*/
	virtual result Reset(void);

	/**
	* Gets an @c int value from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The integer value obtained from the specified column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	virtual result GetIntAt(int columnIndex, int& value) const;

	/**
	* Gets a @c long @c long value from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The 64-bit integer value obtained from the specified column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	virtual result GetInt64At(int columnIndex, long long& value) const;

	/**
	* Gets a @c double value from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The double value obtained from the specified column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	virtual result GetDoubleAt(int columnIndex, double& value) const;

	/**
	* Gets a Tizen::Base::String value from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The Tizen::Base::String value obtained from the specified column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	* @exception		E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range.
	*/
	virtual result GetStringAt(int columnIndex, Tizen::Base::String& value) const;

	/**
	* Gets a Tizen::Base::ByteBuffer value from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The Tizen::Base::ByteBuffer value obtained from the specified column @n
	*									The %Tizen::Base::ByteBuffer will be filled from the current position and data copy
	*										will be continued until %Tizen::Base::ByteBuffer limitation is reached or no more
	*										blob data remains.
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	* @exception		E_OVERFLOW			The specified Tizen::Base::ByteBuffer @c value is insufficient to save the data.
	* @see			Tizen::Base::ByteBuffer
	*/
	virtual result GetBlobAt(int columnIndex, Tizen::Base::ByteBuffer& value) const;

	/**
	* Gets a blob data from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	buffer				The user-provided buffer used to receive the blob data
	* @param[in]		size					The maximum buffer length in bytes
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		Either the specified @c columnIndex is out of range or the specified @c size is invalid.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	* @exception		E_OVERFLOW			The specified @c buffer is insufficient to save the data.
	*/
	virtual result GetBlobAt(int columnIndex, void* buffer, int size) const;

	/**
	* Gets a Tizen::Base::DateTime value from the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex			The index of the column whose value is required
	* @param[in,out]	value				The Tizen::Base::DateTime value obtained from the specified column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	* @exception		E_INVALID_FORMAT	The date is not correctly formatted, or the method is trying to access column of type String. @n
	*									The date format should be 'mm/dd/yyyy hh:mm:ss'.
	* @exception		E_OUT_OF_RANGE		Either the year, month, day, hour, minute, or second value is out of range,
	*										or the method is trying to access a column of type String.
	*/
	virtual result GetDateTimeAt(int columnIndex, Tizen::Base::DateTime& value) const;

	/**
	* Gets the number of columns for this enumerator.
	*
	* @since		2.1
	*
	* @return		The number of columns in the calling enumerator, @n
	*				else @c -1 if an exception occurs
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetColumnCount(void) const;

	/**
	* Gets the type of the column indicated by a specified index.
	*
	* @since		2.1
	*
	* @return		The type of column, @n
	*				else @c DB_COLUMNTYPE_UNDEFINED if an exception occurs
	* @param[in]		columnIndex			The index of the destination column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				Currently, @c DB_COLUMNTYPE_INT is returned for a 64-bit integer. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual DbColumnType GetColumnType(int columnIndex) const;

	/**
	* Gets the name of the column indicated by a specified index.
	*
	* @since		2.1
	*
	* @return		The name of the column, @n
	*				else an empty string if an exception occurs
	* @param[in]		columnIndex			The index of the destination column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual Tizen::Base::String GetColumnName(int columnIndex) const;

	/**
	* Gets the size of data in bytes.
	*
	* @since		2.1
	*
	* @return		The size of the data in bytes, @n
	*				else @c -1 if an exception occurs
	* @param[in]		columnIndex			The index of the destination column
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The DataSet instance associated with this instance is deleted.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		This method must be called after MoveNext(), MoveFirst(), or MoveLast(). @n
	*				If the destination column is of type String, this method returns the @c byte length excluding
	*					the @c null terminator character. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual int GetColumnSize(int columnIndex) const;

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
	DataSetEnumerator(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	DataSetEnumerator(const DataSetEnumerator& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	// @since	2.1
	//
	DataSetEnumerator& operator =(const DataSetEnumerator& rhs);

	class _DataSetEnumeratorImpl* __pDataSetEnumeratorImpl;
	friend class _DataSetEnumeratorImpl;

}; // DataSetEnumerator

}} // Tizen::Io

#endif // _FIO_DATA_SET_ENUMERATOR_H_
