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
* @file		FIoDataRow.h
* @brief		This is the header file for the %DataRow class.
*
* This header file contains the declarations of the %DataRow class.
*/

#ifndef _FIO_DATA_ROW_H_
#define _FIO_DATA_ROW_H_

#include <FBaseObject.h>
#include <FBaseByteBuffer.h>
#include <FBaseDateTime.h>

namespace Tizen { namespace Io
{

/**
* @class		DataRow

* @brief		This class provides methods to create a row in in-memory table.
*
* @since		2.1
*
* @final		This class is not intended for extension.
*
* The %DataRow class provides methods to create a row in in-memory table.
*
* @see Tizen::Io::DataSet
*/
class _OSP_EXPORT_ DataRow
           : public Tizen::Base::Object
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.1
	*/
	virtual ~DataRow(void);

	/**
	* Sets a Tizen::Base::ByteBuffer value to the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex		The index of the column whose value is set @n
	*								The column index starts from 0.
	* @param[in]		pValue			The value to set @n
	*								The specified @c pValue is a pointer to user-provided Tizen::Base::ByteBuffer type buffer.
	* @exception		E_SUCCESS		The method is successful.
	* @exception		E_INVALID_ARG	Either of the following conditions has occurred: @n
	*									- The specified @c columnIndex is out of range.
	*									- The specified @c pValue is @c null.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	* @remarks		This method performs a shallow copy. It copies only the pointer; not the element itself. @n
	*				The platform will take the ownership of @c pValue after calling this method.
	*/
	result SetBlobAt(int columnIndex, Tizen::Base::ByteBuffer* pValue);


	/**
	* Sets a Tizen::Base::DateTime value to the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex		The index of the column whose value is set @n
	*								The column index starts from 0.
	* @param[in]		value			The value to set
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	result SetDateTimeAt(int columnIndex, const Tizen::Base::DateTime& value);


	/**
	* Sets a @c double value to the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex		The index of the column whose value is set @n
	*								The column index starts from 0.
	* @param[in]		value			The value to set
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	result SetDoubleAt(int columnIndex, double value);

	/**
	* Sets an @c int value to the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex		The index of the column whose value is set @n
	*								The column index starts from 0.
	* @param[in]		value			The value to set
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	result SetIntAt(int columnIndex, int value);

	/**
	* Sets a @c long @c long value to the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex		The index of the column whose value is set @n
	*								The column index starts from 0.
	* @param[in]		value			The value to set
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	result SetInt64At(int columnIndex, long long value);

	/**
	* Sets a Tizen::Base::String value to the column whose index is specified.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnIndex		The index of the column whose value is set @n
	*								The column index starts from 0.
	* @param[in]		value			The value to set
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception		E_TYPE_MISMATCH	The operation has attempted to access columns of different types.
	*/
	result SetStringAt(int columnIndex, const Tizen::Base::String& value);

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
	DataRow(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	DataRow(const DataRow& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	DataRow& operator =(const DataRow& rhs);

	class _DataRowImpl* __pDataRowImpl;
	friend class _DataRowImpl;

}; // DataRow

}} // Tizen::Io

#endif // _FIO_DATA_ROW_H_
