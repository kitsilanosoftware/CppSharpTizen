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
 * @file	FIoDbTypes.h
 * @brief	This is the header file for the %DbColumnType enumerator.
 *
 * This header file contains the declarations of the %DbColumnType enumerator.
 */

#ifndef _FIO_DB_TYPES_H_
#define _FIO_DB_TYPES_H_

namespace Tizen { namespace Io
{

#define DB_OPEN_READ_ONLY   (0x00000001L)
#define DB_OPEN_READ_WRITE  (0x00000002L)
#define DB_OPEN_CREATE      (0x00000004L)

/**
 * @enum	DbColumnType
 *
 * Defines the column types.
 *
 * @since	2.0
 */
enum DbColumnType
{
	DB_COLUMNTYPE_INT = 0,  /**< The column type is 4bytes integer */
	DB_COLUMNTYPE_INT64,    /**< The column type is 8bytes integer */
	DB_COLUMNTYPE_DOUBLE,   /**< The column type is double */
	DB_COLUMNTYPE_TEXT,     /**< The column type is text */
	DB_COLUMNTYPE_BLOB,     /**< The column type is blob */
	DB_COLUMNTYPE_NULL,     /**< The column type is @c null */
	DB_COLUMNTYPE_UNDEFINED
};

}} // Tizen::Io

#endif //_FIO_DB_TYPES_H_

