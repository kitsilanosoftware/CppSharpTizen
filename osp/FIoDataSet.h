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
* @file            FIoDataSet.h
* @brief          This is the header file for the %DataSet class.
*
* This header file contains the declarations of the %DataSet class.
*/

#ifndef _FIO_DATA_SET_H_
#define _FIO_DATA_SET_H_

#include <FBaseObject.h>
#include <FBaseColIList.h>
#include <FIoDataRow.h>
#include <FIoDataSetEnumerator.h>

namespace Tizen { namespace Io
{

/**
* @class		DataSet
* @brief		This class provides methods to manipulate in-memory table.
*
* @since		2.1
*
* @final		This class is not intended for extension.
*
* The %DataSet class provides methods to manipulate in-memory table.
*/
class _OSP_EXPORT_ DataSet
           : public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction,
	* the Construct() method must be called right after calling this constructor.
	*
	* @since		2.1
	*/
	DataSet(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.1
	*/
	virtual ~DataSet(void);

	/**
	* Creates in-memory table.
	*
	* @since		2.1
	*
	* @return		An error code
	* @param[in]		columnNames		The list of column names to create @n
	*								The object type in the specified list should be String.
	* @exception		E_SUCCESS		The method is successful.
	* @exception		E_INVALID_ARG	The specified @c columnNames has no element.
	*/
	result Construct(const Tizen::Base::Collection::IList& columnNames);

	/**
	* Creates a row in the table.
	*
	* @since		2.1
	*
	* @return	A pointer to the DataRow instance, @n
	*			else @c null if the memory is insufficient
	* @remarks	The column type is decided by the type of each element inserted in first row.
	*			If a specific column element on the first row is not inserted, then the column's type is @c DB_COLUMNTYPE_NULL
	*				In that case, when a new column element is added later,
	*				then the column's type will be changed according to the new element.
	*/
	DataRow* CreateDataRowN(void);

	/**
	* Gets a table enumerator.
	*
	* @since		2.1
	*
	* @return	A pointer to the DataSetEnumerator instance, @n
	*			else @c null if the memory is insufficient
	*/
	DataSetEnumerator* GetDataSetEnumeratorN(void);


	/**
	* Gets a copy of this instance.
	*
	* @since		2.1
	*
	* @return	A pointer to the copy of the %DataSet instance, @n
	*			else @c null if the memory is insufficient
	*/
	DataSet* CloneN(void) const;

	/**
	* Checks whether the value of a specified instance of Tizen::Base::Object is equal to the value of a current instance of
	* %DataSet.
	*
	* @since		2.1
	*
	* @return	@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current
	*			instance of %DataSet, @n
	*			else @c false
	* @param[in]	obj		An instance of Tizen::Base::Object to compare
	* @remarks	This method returns @c false if the specified @c obj is not a %DataSet instance.
	*/
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Gets the hash value of a current instance.
	*
	* @since		2.1
	*
	* @return	The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//

	DataSet(const DataSet& value);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	DataSet& operator =(const DataSet& rhs);

	class _DataSetImpl* __pDataSetImpl;
	friend class _DataSetImpl;

}; // DataSet

}} // Tizen::Io

#endif // _FIO_DATA_SET_H_
