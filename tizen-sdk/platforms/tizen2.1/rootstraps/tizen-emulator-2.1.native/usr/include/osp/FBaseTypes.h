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
 * @file		FBaseTypes.h
 * @brief		This is the header file for the built-in data types.
 *
 * This header file contains the declarations of the commonly used built-in data types.
 *
 */
#ifndef _FBASE_TYPES_H_
#define _FBASE_TYPES_H_

#include <FBaseLog.h>
#include <FBaseDataType.h>


namespace Tizen { namespace Base
{

/**
 *	@enum	SortOrder
 *
 *	Defines the order of sorting.
 *
 *	@since 2.0
 */
enum SortOrder
{
	SORT_ORDER_ASCENDING = 0,   /**< A constant for sorting the results in ascending order */
	SORT_ORDER_DESCENDING,      /**< A constant for sorting the results in descending order */
	SORT_ORDER_NONE             /**< A constant for indicating the results are not sorted */
};


/**
 *	@enum	StringMatchCriteria
 *
 *	Defines the matching criteria for strings.
 *
 *	@since 2.0
 */
enum StringMatchCriteria
{
	STRING_MATCH_CRITERIA_EXACT = 0,    /**< A constant for matching the strings exactly */
	STRING_MATCH_CRITERIA_START_WITH,   /**< A constant for matching the strings starting with the specified characters */
	STRING_MATCH_CRITERIA_CONTAIN,      /**< A constant for matching the strings partially */
	STRING_MATCH_CRITERIA_WILDCARD      /**< A constant for matching the strings supporting the wildcard characters */
};


/**
 * @enum ComparisonOperator
 *
 * Defines a set of comparison operators whose semantics follow the SQL standards by default,
 * but can be overridden by each API that uses this type, depending on the semantics and intention of the API.
 *
 * @since 2.0
 */
enum ComparisonOperator
{
	COMPARISON_OP_EQUAL = 0,                /**< A comparison operator that checks the value equality */
	COMPARISON_OP_NOT_EQUAL,                /**< A comparison operator that checks the value inequality */
	COMPARISON_OP_GREATER_THAN,             /**< A comparison operator that checks whether a value is greater than the other */
	COMPARISON_OP_LESS_THAN,                /**< A comparison operator that checks whether a value is less than the other */
	COMPARISON_OP_GREATER_THAN_EQUAL_TO,    /**< A comparison operator that checks whether a value is greater than or equal to the other */
	COMPARISON_OP_LESS_THAN_EQUAL_TO,       /**< A comparison operator that checks whether a value is less than or equal to the other */
	COMPARISON_OP_LIKE,                     /**< A comparison operator that checks whether a value is like the other, where the exact matching condition may vary depending on the definition of each specific API */
	COMPARISON_OP_IS_NULL,                  /**< A comparison operator that returns @c true when a value does not exist for the given operand */
	COMPARISON_OP_IS_NOT_NULL               /**< A comparison operator that returns @c true when a value exists for the given operand */
};

}} // Tizen::Base

#endif // _FBASE_TYPES_H_
