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
 * @file			FSclCalendarbookFilter.h
 * @brief		This is the header file for the %CalendarbookFilter class.
 *
 * This header file contains the declarations of the %CalendarbookFilter class.
 */
#ifndef _FSCL_CALENDARBOOK_FILTER_H_
#define _FSCL_CALENDARBOOK_FILTER_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;
class DateTime;
}}

namespace Tizen { namespace Social
{

/**
 * @class	CalendarbookFilter
 * @brief	This class represents the condition for searching the specific item on calendarbook.
 *
 * @since	2.0
 *
 * @final		This class is not intended for extension.
 *
 * The %CalendarbookFilter class represents the condition for searching the specific item on calendarbook.
 * The type of the filter decides which item will be searched (such as events, to-dos, calendars, all day event instances, or non-all day event instances). @n
 * The filter can consist of multiple filtering expressions and conjunctive operators.
 * A filtering expression consists of a filter property, comparison operator and value.
 * The filter property must be an element of the enumerator that corresponds with the type of the filter. @n
 * <table border=1>
 * <tr>
 * <th> Filter type </th>
 * <th> Filter Property </th>
 * <th> Search result </th>
 * </tr>
 * <tr>
 * <td> CB_FI_TYPE_EVENT </td>
 * <td> EventFilterProperty </td>
 * <td> A list of CalEvent </td>
 * </tr>
 * <tr>
 * <td> CB_FI_TYPE_TODO </td>
 * <td> TodoFilterProperty </td>
 * <td> A list of CalTodo </td>
 * </tr>
 * <tr>
 * <td> CB_FI_TYPE_CALENDAR </td>
 * <td> CalendarFilterProperty </td>
 * <td> A list of Calendar </td>
 * </tr>
 * <tr>
 * <td> CB_FI_TYPE_ALL_DAY_EVENT_INSTANCE </td>
 * <td> EventInstanceFilterProperty </td>
 * <td> A list of CalEventInstance </td>
 * </tr>
 * <tr>
 * <td> CB_FI_TYPE_NON_ALL_DAY_EVENT_INSTANCE </td>
 * <td> EventInstanceFilterProperty </td>
 * <td> A list of CalEventInstance </td>
 * </tr>
 * </table>
 *
 * The following example demonstrates how to use the %CalendarbookFilter class.
 * @code
 *
	//search condition: (calendarId=3 OR calendarId=4) AND (subject LIKE '%meeting%')
	CalendarbookFilter subFilter(CB_FILTER_TYPE_EVENT);
	subFilter.AppendInt(FI_CONJ_OP_NONE, EVENT_FI_PR_CALENDAR_ID, FI_CMP_O_EQUAL, 3);
	subFilter.AppendInt(FI_CONJ_OP_OR, EVENT_FI_PR_CALENDAR_ID, FI_CMP_OP_EQUAL, 4);

	CalendarbookFilter mainFilter(CB_FI_TYPE_EVENT);
	mainFilter.AppendFilter(FI_CONJ_OP_NONE, subFilter);
	mainFilter.AppendString(FI_CONJ_OP_AND, EVENT_FI_PR_SUBJECT, FI_STR_OP_CONTAIN, L"meeting");

	Calendarbook calendarbook;
	calendarbook.Construct();
	IList* pEventList = calendarbook.SearchN(mainFilter, EVENT_FI_PR_SUBJECT, SORT_ORDER_ASCENDING);

 * @endcode
 */
class _OSP_EXPORT_ CalendarbookFilter
	: public Tizen::Base::Object
{
public:
	/**
	 * Initializes an instance of %CalendarbookFilter with the specified @c type.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type			The type of the filter @n It decides the type of item to search.
	 */
	explicit CalendarbookFilter(CalendarbookFilterType type);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~CalendarbookFilter(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *					else @c false
	 * @param[in]	rhs			An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Appends the filtering expression for the integer value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value.
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return		The error code
	 * @param[in]	conjunctiveOperator		The conjunctive operator to append the filtering expression @n
	 * 										If there is no filtering expression or filter has been appended before, FI_CONJ_OP_NON must be used. Otherwise FI_CONJ_OP_AND or FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty		The filter property
	 * @param[in]	comparisonOperator		The comparison operator
	 * @param[in]	value		The integer value for comparison
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *						- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *						- The @c filterProperty is not for integer value. @n
	 *						- The specified @c conjunctiveOperator is invalid.
	 */
	result AppendInt(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterComparisonOperator comparisonOperator, int value);

	/**
	 * Appends the filtering expression for the double value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value.
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return		The error code
	 * @param[in]	conjunctiveOperator		The conjunctive operator to append the filtering expression @n
	 * 										If there is no filtering expression or filter has been appended before, FI_CONJ_OP_NON must be used. Otherwise FI_CONJ_OP_AND or FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty		The filter property
	 * @param[in]	comparisonOperator		The comparison operator
	 * @param[in]	value		The double value for comparison
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *						- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *						- The @c filterProperty is not for double value. @n
	 *						- The specified @c conjunctiveOperator is invalid.
	 */
	result AppendDouble(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterComparisonOperator comparisonOperator, double value);

	/**
	 * Appends the filtering expression for the bool value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value.
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return		The error code
	 * @param[in]	conjunctiveOperator		The conjunctive operator to append the filtering expression @n
	 * 										If there is no filtering expression or filter has been appended before, FI_CONJ_OP_NON must be used. Otherwise FI_CONJ_OP_AND or FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty		The filter property
	 * @param[in]	comparisonOperator		The comparison operator FILTER_COMPARISON_OPERATOR_EQUAL is only permitted
	 * @param[in]	value		The bool value for comparison
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *						- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *						- The @c filterProperty is not for bool value. @n
	 *						- The specified @c conjunctiveOperator is invalid.
	 */
	result AppendBool(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterComparisonOperator comparisonOperator, bool value);

	/**
	 * Appends the filtering expression for the Tizen::Base::DateTime value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value.
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return		The error code
	 * @param[in]	conjunctiveOperator		The conjunctive operator to append the filtering expression @n
	 * 										If there is no filtering expression or filter has been appended before, FI_CONJ_OP_NON must be used. Otherwise FI_CONJ_OP_AND or FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty		The filter property
	 * @param[in]	comparisonOperator		The comparison operator
	 * @param[in]	value		The Tizen::Base::DateTime value for comparison. @n Any value with a unit that is less than a second is ignored.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: 
	 *						- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. 
	 *						- The @c filterProperty is not for Tizen::Base::DateTime value.
	 *						- The specified @c conjunctiveOperator is invalid.
	 *						- The specified @c value is out of the valid range.
	 */
	result AppendDateTime(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterComparisonOperator comparisonOperator, const Tizen::Base::DateTime& value);

	/**
	 * Appends the filtering expression for the Tizen::Base::String value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value.
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return		The error code
	 * @param[in]	conjunctiveOperator		The conjunctive operator to append the filtering expression @n
	 * 										If there is no filtering expression or filter has been appended before, FI_CONJ_OP_NON must be used. Otherwise FI_CONJ_OP_AND or FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty		The filter property
	 * @param[in]	comparisonOperator		The comparison operator
	 * @param[in]	value		The Tizen::Base::String value for matching
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *						- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *						- The @c filterProperty is not for Tizen::Base::String value. @n
	 *						- The specified @c conjunctiveOperator is invalid.
	 */
	result AppendString(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterStringOperator comparisonOperator, const Tizen::Base::String& value);

	/**
	 * Appends the filter. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expressions of the specified filter in parentheses and appends it. @n
	 * The type of the specified @c filter must be same with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return		The error code
	 * @param[in]	conjunctiveOperator		The conjunctive operator to append the filtering expression @n
	 * 										If there is no filtering expression or filter has been appended before, FI_CONJ_OP_NON must be used. Otherwise FI_CONJ_OP_AND or FI_CONJ_OP_OR can be used.
	 * @param[in]	filter			The filter to append
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *						- The type of the specified @c filter is not same with the type of this filter. @n
	 *						- The specified @c filter is empty. @n
	 *						- The specified @c conjunctiveOperator is invalid.
	 */
	result AppendFilter(FilterConjunctiveOperator conjunctiveOperator, const CalendarbookFilter& filter);

private:
	/*
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @since	2.0
	 */
	CalendarbookFilter(void);

	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	CalendarbookFilter(const CalendarbookFilter& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	CalendarbookFilter & operator =(const CalendarbookFilter & rhs);

private:
	friend class _CalendarbookFilterImpl;
	class _CalendarbookFilterImpl* __pCalendarbookFilterImpl;
};		// CalendarbookFilter

}} // Tizen::Social

#endif // _FSCL_CALENDARBOOK_FILTER_H_
