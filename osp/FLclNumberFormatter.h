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
 * @file		FLclNumberFormatter.h
 * @brief		This is the header file for the %NumberFormatter class.
 *
 * This header file contains the declarations of the %NumberFormatter class.
 *
 */
#ifndef _FLCL_NUMBER_FORMATTER_H_
#define _FLCL_NUMBER_FORMATTER_H_

#include <FLclLocale.h>
#include <FLclCurrency.h>

namespace Tizen { namespace Locales
{

/**
 * @class		NumberFormatter
 * @brief		This class provides methods for formatting numbers.
 *
 * @since		2.0
 *
 * The %NumberFormatter class is used to format all number formats, including decimal and real numbers, currency, and percentage for any locale. It also provides methods to determine the locales that have number formats and their names. You can write codes completely independent of the locale conventions for decimal points, thousand separators as well as of the specific decimal digits used or whether the number format is a decimal. A normal decimal number can also be displayed as a currency or as a percentage.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/num_formatter.htm">Number Formatters</a>.
 *
 * The following example demonstrates how to use the %NumberFormatter class.
 *
 * @code

#include <FBase.h>
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::Locales;

void
LocaleApp::NumberFormatterExample(void)
{
	// Construct locale
	Locale koreaLoc(LANGUAGE_KOR, COUNTRY_KR);

	// Get number formatter
	NumberFormatter* pNumberFormatter = NumberFormatter::CreateNumberFormatterN(koreaLoc);

	String formattedString;

	// Format number with number formatter
	double num = 345987.246;
	pNumberFormatter->Format(num, formattedString);

	// Get currency formatter
	NumberFormatter* pCurrencyFormatter = NumberFormatter::CreateCurrencyFormatterN(koreaLoc);

	// Format number with currency formatter
	num = 100321;
	pCurrencyFormatter->Format(num, formattedString);

	// Get percent formatter
	NumberFormatter* pPercentFormatter = NumberFormatter::CreatePercentFormatterN(koreaLoc);

	// Format number with percent formatter
	num = 0.5;
	pPercentFormatter->Format(num, formattedString);

	delete pNumberFormatter;
	delete pCurrencyFormatter;
	delete pPercentFormatter;
}
@endcode
 *
 */

class _OSP_EXPORT_ NumberFormatter
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~NumberFormatter(void);


	/**
	 * Creates a number formatter for the system locale.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to the general number formatter for the default locale, @n
	 *						else @c null if an error occurs
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_UNSUPPORTED_OPERATION		The system locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateNumberFormatterN(void);


	/**
	 * Creates a number formatter for the specified locale.
	 *
	 * @if OSPCOMPAT
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since				2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompNumberFormatterCreateNumberFormatterNPage "here".
	 * @endif
	 *
	 * @return				A pointer to a general number formatter for the specified @c locale, @n
	 *						else @c null if an error occurs
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_INVALID_ARG		The specified @c locale is invalid. 
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateNumberFormatterN(const Locale& locale);

	/**
	 * @if OSPCOMPAT
         * @page                    CompNumberFormatterCreateNumberFormatterNPage Compatibility for CreateNumberFormatterN()
         * @section                   CompNumberFormatterCreateNumberFormatterNIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
         *
         * @section                 CompNumberFormatterCreateNumberFormatterNSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen: 
         * -# The method returns E_INVALID_ARG if the @c locale is invalid.
	 * @endif
         */

	/**
	 * Creates a currency formatter for the default locale.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to a currency formatter for the default locale, @n
	 *						else @c null if an error occurs
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_UNSUPPORTED_OPERATION		The system locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateCurrencyFormatterN(void);


	/**
	 * Creates a currency formatter for the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since				2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompNumberFormatterCreateCurrencyFormatterNPage "here".
	 * @endif
	 *
	 * @return				A pointer to a currency formatter for the specified @c locale, @n
	 *						else @c null if an error occurs
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_INVALID_ARG           The specified @c locale is invalid. 
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateCurrencyFormatterN(const Locale& locale);

	/**
	 * @if OSPCOMPAT
         * @page                    CompNumberFormatterCreateCurrencyFormatterNPage Compatibility for CreateCurrencyFormatterN()
         * @section                   CompNumberFormatterCreateCurrencyFormatterNIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
         *
         * @section                 CompNumberFormatterCreateCurrencyFormatterNSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the @c locale is invalid.
	 * @endif
         */

	/**
	 * Creates a percentage formatter for the system locale.
	 *
	 * @since				2.0
	 *
	 * @return				A pointer to a percentage formatter for the default locale, @n
	 *						else @c null if an error occurs
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_UNSUPPORTED_OPERATION		The system locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreatePercentFormatterN(void);


	/**
	 * Creates a percentage formatter for the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since				2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompNumberFormatterCreatePercentFormatterNPage "here".
	 * @endif
	 *
	 * @return				A pointer to a percentage formatter for the specified @c locale, @n
	 *						else @c null if an error occurs
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_INVALID_ARG           The specified @c locale is invalid. 
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreatePercentFormatterN(const Locale& locale);

        /**
	 * @if OSPCOMPAT
         * @page                    CompNumberFormatterCreatePercentFormatterNPage Compatibility for CreatePercentFormatterN()
         * @section                   CompNumberFormatterCreatePercentFormatterNIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
         *
         * @section                 CompNumberFormatterCreatePercentFormatterNSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the @c locale is invalid.
	 * @endif
         */



	/**
	 * Formats a number of type Tizen::Base::Long to type Tizen::Base::String and appends the resulting string to a buffer.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			number						The number of type Tizen::Base::Long to format
	 * @param[out]			str							The string to append to the resultant string
	 * @exception			E_SUCCESS					The method is successful.
	 */
	virtual result Format(long number, Tizen::Base::String& str) const;


	/**
	 * Formats a number of type Tizen::Base::Double to type Tizen::Base::String and appends the resulting string to a buffer.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			number						The number of type Tizen::Base::Double to format
	 * @param[out]			str							The string to append to the resultant string
	 * @exception			E_SUCCESS					The method is successful.
	 */
	virtual result Format(double number, Tizen::Base::String& str) const;


	/**
	 * Gets the currency used by the current number format when formatting currency values.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to an instance of Currency
	 * @remarks			The initial value is derived in a locale dependent way. @n
	 *					The returned value may be @c null if no valid currency is determined
	 *					or no currency has been set using the SetCurrency() method.
	 * @see				SetCurrency()
	 */
	virtual const Currency* GetCurrency(void) const;


	/**
	 * Sets the currency used by the current number format when formatting currency values.
	 *
	 * @since				2.0
	 *
	 * @param[in]		currency			The new currency to use by the current number format
	 * @remarks			This does not update the minimum or maximum number of fractional digits used by the number format.
	 * @see					GetCurrency()
	 */
	virtual void SetCurrency(const Currency& currency);


	/**
	 * Gets the maximum number of digits allowed in the integer portion of a number.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value representing the maximum number of digits allowed in the integer portion of a number
	 * @see				SetMaxIntegerDigits()
	 */
	virtual int GetMaxIntegerDigits(void) const;


	/**
	 * Sets the maximum number of digits allowed in the integer portion of a number.
	 *
	 * @since			2.0
	 *
	 * @param[in]		newValue				The maximum number of integer digits allowed in the integer portion of a number, @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The maximum integer digits must be greater than or equal to the minimum integer digits.
	 *					If the new value for the maximum integer digits is less than the current value of the minimum integer digits,
	 *					the minimum integer digits are also set to the new value.
	 * @see				GetMaxIntegerDigits()
	 */
	virtual void SetMaxIntegerDigits(int newValue);


	/**
	 * Gets the minimum number of digits allowed in the integer portion of a number.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value representing the minimum number of digits allowed in the integer portion of a number
	 * @see				SetMinIntegerDigits()
	 */
	virtual int GetMinIntegerDigits(void) const;


	/**
	 * Sets the minimum number of digits allowed in the integer portion of a number.
	 *
	 * @since			2.0
	 *
	 * @param[in]		newValue				The minimum number of integer digits allowed in the integer portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The minimum integer digits must be less than or equal to the maximum integer digits.
	 *					If the new value for the minimum integer digits exceeds the current value of the maximum integer digits,
	 *					the maximum integer digits are also set to the new value.
	 * @see				GetMinIntegerDigits()
	 */
	virtual void SetMinIntegerDigits(int newValue);


	/**
	 * Gets the maximum number of digits allowed in the fractional portion of a number.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value representing the maximum number of digits allowed in the fractional portion of a number
	 * @see				SetMaxFractionDigits()
	 */
	virtual int GetMaxFractionDigits(void) const;


	/**
	 * Sets the maximum number of digits allowed in the fractional portion of a number.
	 *
	 * @since			2.0
	 *
	 * @param[in]		newValue				The maximum number of fractional digits allowed in the fractional portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The maximum fractional digits must be greater than or equal to the minimum fractional digits.
	 *					If the new value for the maximum fractional digits is less than the current value of the minimum fractional digits,
	 *					the minimum fractional digits are also set to the new value.
	 * @see				GetMaxFractionDigits()
	 */
	virtual void SetMaxFractionDigits(int newValue);


	/**
	 * Gets the minimum number of digits allowed in the fractional portion of a number.
	 *
	 * @since			2.0
	 *
	 * @return			An integer value representing the minimum number of digits allowed in the fractional portion of a number
	 * @see				SetMinFractionDigits()
	 */
	virtual int GetMinFractionDigits(void) const;


	/**
	 * Sets the minimum number of digits allowed in the fractional portion of a number.
	 *
	 * @since			2.0
	 *
	 * @param[in]		newValue				The minimum number of fractional digits allowed in the fractional portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The minimum fractional digits must be less than or equal to the maximum fractional digits.
	 *					If the new value for the minimum fractional digits exceeds the current value of the maximum fraction digits,
	 *					the maximum fraction digits are also set to the new value.
	 * @see				GetMinFractionDigits()
	 */
	virtual void SetMinFractionDigits(int newValue);


	/**
	 * Checks whether the grouping is used in the current instance of %NumberFormatter.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if grouping is used in the current instance of %NumberFormatter, @n
	 *					else @c false
	 * @remarks			For example, in the English locale, with grouping on, the number 1234567
	 *					might be formatted as "1,234,567".
	 *					The grouping separator as well as the size of each group is locale dependent
	 *					and is determined by subclasses of %NumberFormatter.
	 * @see				SetGroupingUsed()
	 */
	virtual bool IsGroupingUsed(void) const;


	/**
	 * Sets the current instance of %NumberFormatter to use or not to use grouping.
	 *
	 * @since			2.0
	 *
	 * @param[in]		newValue				Set to @c true if grouping is used in the current formatter, @n
	 *											else @c false
	 * @see				IsGroupingUsed()
	 */
	virtual void SetGroupingUsed(bool newValue);


	/**
	* Applies the specified pattern to the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		pattern						The new pattern
	* @param[in]		localized					The localization On/Off flag @n
	*												Set to @c true if the pattern is applied with the localized symbols, @n
	*												else @c false.
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c pattern is invalid or its length is @c 0.
	*/
	result ApplyPattern(const Tizen::Base::String& pattern, bool localized);


	/**
	* Gets the positive prefix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @return			The positive prefix of the current %NumberFormatter instance
	* @remarks			For example: +123, $123, sFr123.
	* @see				SetPositivePrefix()
	*/
	Tizen::Base::String GetPositivePrefix(void) const;


	/**
	* Sets a new value for the positive prefix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @param[in]		newValue				The new positive prefix
	* @see				GetPositivePrefix()
	*/
	void SetPositivePrefix(const Tizen::Base::String& newValue);


	/**
	* Gets the negative prefix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @return			The negative prefix of the current %NumberFormatter instance
	* @remarks			For example: -123, $123 (with negative prefix), sFr-123
	* @see				SetNegativePrefix()
	*/
	Tizen::Base::String GetNegativePrefix(void) const;


	/**
	* Sets a new value for the negative prefix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @param[in]		newValue					The new negative prefix
	* @see				GetNegativePrefix()
	*/
	void SetNegativePrefix(const Tizen::Base::String& newValue);


	/**
	* Gets the positive suffix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @return			The positive suffix of the current %NumberFormatter instance
	* @remarks			For example: 123%
	* @see				SetPositiveSuffix()
	*/
	Tizen::Base::String GetPositiveSuffix(void) const;


	/**
	* Sets a new value for the positive suffix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @param[in]		newValue					The new positive suffix
	* @see				GetPositiveSuffix()
	*/
	void SetPositiveSuffix(const Tizen::Base::String& newValue);


	/**
	* Gets the negative suffix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @return			The negative suffix of the current %NumberFormatter instance
	* @remarks			For example: -123%, $123 (with negative suffix)
	* @see				SetNegativeSuffix()
	*/
	Tizen::Base::String GetNegativeSuffix(void) const;


	/**
	* Sets a new value for the negative suffix of the current instance of %NumberFormatter.
	*
	* @since			2.0
	*
	* @param[in]		newValue					The new negative suffix
	* @see				GetNegativeSuffix()
	*/
	void SetNegativeSuffix(const Tizen::Base::String& newValue);


	/**
	* Gets the multiplier for use in percent, per mill, and so on.
	*
	* @since			2.0
	*
	* @return			An integer value representing the multiplier
	* @remarks			For example: with 100, 1.23 -> "123", and "123" -> 1.23
	* @see				SetMultiplier()
	*/
	int GetMultiplier(void) const;


	/**
	* Sets a new value for the multiplier for use in percent, per mill, and so on.
	*
	* @since			2.0
	*
	* @param[in]		newValue					The new value for the multiplier
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified input parameter is invalid.
	* @remarks			For example, in percentage, set the suffixes to have "%" and the multiplier to be 100.
	* @see				GetMultiplier()
	*/
	result SetMultiplier(int newValue);


	/**
	* Gets the grouping size.
	*
	* @since			2.0
	*
	* @return			An integer value representing the grouping size
	* @remarks			Grouping size is the number of digits between grouping separators in the integer portion of a number. @n
	*					For example, in the number "123,456.78", the grouping size is 3.
	* @see				SetGroupingSize()
	* @see				IsGroupingUsed()
	*/
	int GetGroupingSize(void) const;


	/**
	* Sets a new value for the grouping size.
	*
	* @since			2.0
	*
	* @param[in]		newValue					The new value for the grouping size
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified input parameter is invalid.
	* @see				GetGroupingSize()
	* @see				SetGroupingUsed()
	*/
	result SetGroupingSize(int newValue);


	/**
	* Checks whether the decimal separator is always shown.
	*
	* @since			2.0
	*
	* @return			@c true if the decimal separator is always shown, @n
	*					else @c false
	* @remarks			For example: ON: 12345 -> 12345.; OFF: 12345 -> 12345
	* @see				SetDecimalSeparatorAlwaysShown()
	*/
	bool IsDecimalSeparatorAlwaysShown(void) const;


	/**
	* Sets the behavior of the decimal separator. @n
	* The decimal separator can be set to always appear using this method.
	*
	* @since			2.0
	*
	* @param[in]		newValue				Set to @c true if the decimal separator is always shown, @n
	*											else @c false
	* @see				IsDecimalSeparatorAlwaysShown()
	*/
	void SetDecimalSeparatorAlwaysShown(bool newValue);


	/**
	* Checks whether the positive sign is always shown.
	*
	* @since			2.0
	*
	* @return			@c true if the positive sign is always shown, @n
	*					else @c false
	* @remarks			For example: ON: 12345 -> +12345.; OFF: 12345 -> 12345.
	* @see				SetPositiveSignAlwaysShown()
	*/
	bool IsPositiveSignAlwaysShown(void) const;


	/**
	* Sets the behavior of the plus sign. @n
	* The plus sign can be set to always appear using this method.
	*
	* @since			2.0
	*
	* @param[in]		newValue				Set to @c true if the plus sign is always shown, @n
	*											else @c false
	* @see				IsPositiveSignAlwaysShown()
	*/
	void SetPositiveSignAlwaysShown(bool newValue);


private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	NumberFormatter(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	NumberFormatter(const NumberFormatter& numberFormatter);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	NumberFormatter& operator =(const NumberFormatter& numberFormatter);

	friend class _NumberFormatterImpl;
	class _NumberFormatterImpl* __pNumberFormatterImpl;

}; // NumberFormatter

}} // Tizen::Locales

#endif //_FLCL_NUMBER_FORMATTER_H_
 
