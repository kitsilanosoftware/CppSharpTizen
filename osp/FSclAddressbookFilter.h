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
 * @file		FSclAddressbookFilter.h
 * @brief		This is the header file for the %AddressbookFilter class.
 *
 * This header file contains the declarations of the %AddressbookFilter class.
 */
#ifndef _FSCL_ADDRESSBOOK_FILTER_H_
#define _FSCL_ADDRESSBOOK_FILTER_H_

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
 * @class          AddressbookFilter
 * @brief          This class represents the condition for searching the specific item on addressbook.
 * 
 * @since	2.0
 *
 * @final          This class is not intended for extension.
 *
 * The %AddressbookFilter class represents the condition for searching the specific item on addressbook.
 * The type of the filter decides which item will be searched. (such as addressbook, contacts, persons, categories) @n
 * The filter can consist of multiple filtering expressions and conjunctive operators.
 * A filtering expression consists of a filter property, comparison operator and value.
 * The filter property must be an element of the enumerator that corresponds with the type of the filter. @n
 * <table border=1>
 * <tr>
 *  <th> Filter type </th>
 *  <th> Filter Property </th>
 *  <th> Search result </th>
 * </tr>
 * <tr>
 *  <td> AB_FI_TYPE_ADDRESSBOOK </td>
 *  <td> AddressbookFilterProperty </td>
 *  <td> A list of Addressbook </td>
 * </tr>
 * <tr>
 *  <td> AB_FI_TYPE_PERSON </td>
 *  <td> PersonFilterProperty </td>
 *  <td> A list of Person </td>
 * </tr>
 * <tr>
 *  <td> AB_FI_TYPE_CONTACT </td>
 *  <td> ContactFilterProperty </td>
 *  <td> A list of Contact </td>
 * </tr>
 * <tr>
 *  <td> AB_FI_TYPE_CATEGORY </td>
 *  <td> CategoryFilterProperty </td>
 *  <td> A list of Category </td>
 * </tr>
 * <tr>
 *  <td> AB_FI_TYPE_PHONE_CONTACT </td>
 *  <td> PhoneContactFilterProperty </td>
 *  <td> A list of PhoneNumberContact </td>
 * </tr>
 * <tr>
 *  <td> AB_FI_TYPE_EMAIL_CONTACT </td>
 *  <td> EmailContactFilterProperty </td>
 *  <td> A list of EmailContact </td>
 * </tr>
 * </table>
 *
 * The following example demonstrates how to use the %AddressbookFilter class.
 * @code
  // Search condition: (addressbookId=0 OR addressbookId=1) AND (display name LIKE '%John%')
  AddressbookFilter subFilter(AB_FI_TYPE_CONTACT);
  subFilter.AppendInt(FI_CONJ_OP_NONE, CONTACT_FI_PR_ADDRESSBOOK_ID, FI_CMP_OP_EQUAL, 0);
  subFilter.AppendInt(FI_CONJ_OP_OR, CONTACT_FI_PR_ADDRESSBOOK_ID, FI_CMP_OP_EQUAL, 1);
 
  AddressbookFilter mainFilter(AB_FI_TYPE_CONTACT);
  mainFilter.Append(FI_CONJ_OP_NONE, subFilter);
  mainFilter.Append(FI_CONJ_OP_AND, CONTACT_FI_PR_DISPLAY_NAME, FI_STR_OP_CONTAIN, L"John");
 
  AddressbookManager* pAddressbookManager = AddressbookManager::GetInstance();
 
  IList* pEventList = pAddressbookManager->SearchN(mainFilter, CONTACT_FI_PR_DISPLAY_NAME, SORT_ORDER_ASCENDING);

 * @endcode
 */
class _OSP_EXPORT_ AddressbookFilter
           : public Tizen::Base::Object
{
public:
	/**
	 * Initializes an instance of %AddressbookFilter with the specified type.
	 *
	 * @since	2.0
	 *
	 * @param[in]    type                The type of the filter @n It decides the type of item to search.
	 */
	AddressbookFilter(AddressbookFilterType type);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~AddressbookFilter(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return        @c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *                             else @c false
	 * @param[in]    rhs                 An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return        The hash value of the current instance
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
	 * @return    The error code
	 * @param[in]	conjunctiveOperator  	The conjunctive operator to append the filtering expression @n 
	 *                                      If there is no filtering expression or filter has been appended before, #FI_CONJ_OP_NONE must be used. Otherwise #FI_CONJ_OP_AND or #FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty  	The filter property
	 * @param[in]	comparisonOperator  	The comparison operator
	 * @param[in]	value   		The integer value for comparison 
	 * @exception   E_SUCCESS        	The method is successful.
	 * @exception   E_INVALID_ARG        Either of the following conditions has occurred: @n
	 *                                     		- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *                                     		- The type of the @c filterProperty is not @c int. @n
	 *                                     		- The specified @c conjuctiveOperator is invalid.
	 */
	result AppendInt(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterComparisonOperator comparisonOperator, int value);

	/**
	 * Appends the filtering expression for the @c bool value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value. 
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return      The error code
	 * @param[in]	conjunctiveOperator  	The conjunctive operator to append the filtering expression @n
	 *                                     If there is no filtering expression or filter has been appended before, #FI_CONJ_OP_NONE must be used. Otherwise #FI_CONJ_OP_AND or #FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty  	The filter property
	 * @param[in]	comparisonOperator  	The comparison operator #FI_CMP_OP_EQUAL is only permitted
	 * @param[in]	value   		The @c bool value for comparison 
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG        	Either of the following conditions has occurred: @n
	 *                                     		- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *                                     		- The type of the @c filterProperty is not @c bool. @n
	 *						- The @c comparisonOperator is no #FI_CMP_OP_EQUAL. @n
	 *                                     		- The specified @c conjuctiveOperator is invalid.
	 * @remarks  If the filtering expression is appended firstly, the @c conjunctiveOperator is ignored.
	 */
	result AppendBool(FilterConjunctiveOperator conjunctiveOperator, unsigned long filterProperty, FilterComparisonOperator comparisonOperator, bool value);

	/**
	 * Appends the filtering expression for the Tizen::Base::String value. @n
	 * Firstly, this method appends the conjunctive operator.
	 * Then, this method puts the filtering expression in parentheses and appends it. @n
	 * The filtering expression consists of the filter property, comparison operator, and value. 
	 * The specified @c filterProperty must be an element of the enumerator that corresponds with the type of this filter.
	 *
	 * @since	2.0
	 *
	 * @return      The error code
	 * @param[in]	conjunctiveOperator  	The conjunctive operator to append the filtering expression @n
	 *                                     If there is no filtering expression or filter has been appended before, #FI_CONJ_OP_NONE must be used. Otherwise #FI_CONJ_OP_AND or #FI_CONJ_OP_OR can be used.
	 * @param[in]	filterProperty  	The filter property
	 * @param[in]	comparisonOperator  	The comparison operator
	 * @param[in]	value   		The Tizen::Base::String value for matching 
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG        	Either of the following conditions has occurred: @n
	 *                                     		- The @c filterProperty is not an element of the enumerator that corresponds with the type of this filter. @n
	 *                                     		- The type of the @c filterProperty is not Tizen::Base::String. @n
	 *                                     		- The specified @c conjuctiveOperator is invalid.
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
	 * @return      The error code
	 * @param[in]	conjunctiveOperator  	The conjunctive operator to append the filtering expression @n 
	 *                                     If there is no filtering expression or filter has been appended before, #FI_CONJ_OP_NONE must be used. Otherwise #FI_CONJ_OP_AND or #FI_CONJ_OP_OR can be used.
	 * @param[in]	filter  		The filter to append
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG        	Either of the following conditions has occurred: @n
	 *                                             - The type of the specified @c filter is not same with the type of this filter. @n
	 *                                             - The specified @c filter is empty. @n
	 *                                             - The specified @c conjuctiveOperator is invalid.
	 */
	result AppendFilter(FilterConjunctiveOperator conjunctiveOperator, const AddressbookFilter& filter);

private:
	/*
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @since	2.0
	 */
	AddressbookFilter(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AddressbookFilter(const AddressbookFilter& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AddressbookFilter & operator =(const AddressbookFilter & rhs);

private:
           friend class _AddressbookFilterImpl;
           class _AddressbookFilterImpl* __pAddressbookFilterImpl;
};         // AddressbookFilter

}} // Tizen::Social

#endif // _FSCL_ADDRESSBOOK_FILTER_H_
