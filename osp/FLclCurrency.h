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
 * @file		FLclCurrency.h
 * @brief		This is the header file for the %Currency class.
 *
 * This header file contains the declarations of the %Currency class.
 *
 */
#ifndef _FLCL_CURRENCY_H_
#define _FLCL_CURRENCY_H_

#include <FBaseString.h>
#include <FBaseColIList.h>

namespace Tizen {namespace Locales
{

// Forward declaration
class Locale;

/**
 * @class		Currency
 * @brief		This class represents currencies.
 *
 * @since		2.0
 *
 * The %Currency class represents currencies, and is used when the localized currency symbol is retrieved.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/num_symbols_currencies.htm">Number Symbols and Currencies</a>.
 * @see Locale
 * @see LanguageCode
 * @see CountryCode
 *
 */
class _OSP_EXPORT_ Currency
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @see 			Construct()
	 */
	Currency(void);


	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~Currency(void);


	/**
	 * Initializes this instance of %Currency with the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	 *                              For more information, see @ref CompCurrencyConstructPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		locale						The specified @c locale to get the currency symbol
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c locale is not supported.
	 */
	result Construct(const Locale& locale);


	/**
	 * Initializes this instance of %Currency with the specified currency code. @n
	 * Currencies are enumerated as defined by ISO 4217. For example, if the locale is Korean (language) and Korea (country), the currency code is "KRW".
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
         *                              For more information, see @ref CompCurrencyConstructPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param[in]		currencyCode				The specified currency code to get the currency symbol
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c currencyCode is not supported.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result Construct(const Tizen::Base::String& currencyCode);
	/**
	 * @if OSPCOMPAT
         * @page                    CompCurrencyConstructPage Compatibility for Construct()
         * @section                   CompCurrencyConstructIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the argument is invalid.
         *
         * @section                 CompCurrencyConstructSolutionSection Resolutions
         * This issue has been resolved in Tizen. @n
	 * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the argument is invalid.
	 * @endif
         */


	/**
	 * Gets the ISO 4217 currency code for the specified currency.
	 *
	 * @since			2.0
	 *
	 * @return			The currency code that is already set
	 * @see				GetSymbol()
	 */
	Tizen::Base::String GetCurrencyCode(void) const;


	/**
	 * Gets the symbol of this currency. @n
	 * The symbol will be localized for the locale of the currency.
	 * For example, if the locale of this currency is kor_KR and the system locale is eng_US,
	 * the symbol will be the Korean won sign "₩ "; if the locale of this currency is eng_US and the system locale is kor_KR,
	 * the symbol will be "$".
	 *
	 * @since			2.0
	 *
	 * @return			symbol						The currency symbol string
	 */
	Tizen::Base::String GetSymbol(void) const;

	/**
	 * Compares the value of the specified instance to that of the current instance.
	 *
	 * @since			2.0
	 *
	 * @return			@c true if the value of the specified instance is equal to that of the current instance, @n
	 *					else @c false
	 * @param[in]		obj The object to compare with the current instance
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since			2.0
	*
	* @return			The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	 * Gets a list of all available currencies.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to an array of %Currency objects, @n
	 *					else a @c null pointer is returned if there is no currency available or there is some failure @n
	 *					The array is a list of all the available currencies.
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 * @remarks                                     The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::Collection::IList* GetAvailableCurrenciesN(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	Currency(const Currency& currency);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	Currency& operator =(const Currency& currency);

	Tizen::Base::String __currencyCodeSymbol;

	friend class _CurrencyImpl;
	class _CurrencyImpl* __pCurrencyImpl;
}; // Currency

}} // Tizen::Locales

#endif //_FLCL_CURRENCY_H_
