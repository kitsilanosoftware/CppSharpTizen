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
 * @file		FLclNumberSymbols.h
 * @brief		This is the header file for the %NumberSymbols class.
 *
 * This header file contains the declarations of the %NumberSymbols class.
 *
 */
#ifndef _FLCL_NUMBER_SYMBOLS_H_
#define _FLCL_NUMBER_SYMBOLS_H_

#include <FLclLocale.h>


namespace Tizen { namespace Locales
{

// Enums and Constants
/**
 * @enum	NumberSymbol
 *
 * Defines the possible formats for number symbols. @n
 *
 * This enum represents the possible symbols for NumberFormatter.
 *
 * @since		2.0
 */
enum NumberSymbol
{
	NUMBER_SYMBOL_DECIMAL_SEPARATOR,			/**< The decimal separator */
	NUMBER_SYMBOL_GROUPING_SEPARATOR,			/**< The grouping separator */
	NUMBER_SYMBOL_PATTERN_SEPARATOR,			/**< The pattern separator */
	NUMBER_SYMBOL_PERCENT,						/**< The percent symbol */
	NUMBER_SYMBOL_ZERO_DIGIT,					/**< The zero symbol*/
	NUMBER_SYMBOL_DIGIT,						/**< The character representing a digit in the pattern */
	NUMBER_SYMBOL_CURRENCY,						/**< The currency symbol */
	NUMBER_SYMBOL_INTL_CURRENCY,				/**< The international currency symbol */
	NUMBER_SYMBOL_MONETARY_SEPARATOR,			/**< The monetary separator */
	NUMBER_SYMBOL_PER_MILL,						/**< The per mil symbol */
	NUMBER_SYMBOL_EXPONENTIAL,					/**< The exponential symbol */
	NUMBER_SYMBOL_PLUS_SIGN,					/**< The plus sign */
	NUMBER_SYMBOL_MINUS_SIGN,					/**< The minus sign */
	NUMBER_SYMBOL_COUNT							/**< The number of symbol */
};


/**
 * @class		NumberSymbols
 * @brief		This class provides methods that help in providing number symbols.
 *
 * @since		2.0
 *
 * The %NumberSymbols class represents the set of symbols (such as the decimal separator and the grouping separator) needed by NumberFormatter to format numbers.
 * %NumberFormatter creates its own instance of %NumberSymbols from its locale data. %NumberSymbols can be adopted by a %NumberFormatter instance, or it can be specified when a %NumberFormatter is created. If you need to change any of these symbols, you can get the %NumberSymbols instance from your %NumberFormatter and then modify it.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/num_symbols_currencies.htm">Number Symbols and Currencies</a>.
 */
class _OSP_EXPORT_ NumberSymbols
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @see Construct()
	 */
	NumberSymbols(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~NumberSymbols(void);


	/**
	 * Initializes this instance of %NumberSymbols with the specified @c locale.
	 *
	 * @if OSPCOMPAT
	 * @brief                               <i> [Compatibility] </i> 
	 * @endif
	 * @since				2.0
	 * @if OSPCOMPAT
	 * @compatibility     This method has compatibility issues with OSP compatibile applications. @n
	*                              For more information, see @ref CompNumberSymbolsConstructPage "here".
	 * @endif
	 *
	 * @return				An error code
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_INVALID_ARG		The specified @c locale is invalid. 
	 */
	result Construct(const Locale& locale);

	/**
	 * @if OSPCOMPAT
         * @page                    CompNumberSymbolsConstructPage Compatibility for Construct()
         * @section                   CompNumberSymbolsConstructIssueSection Issues
         * Implementation of this method in OSP compatible applications has the following issue: @n
         * -# The method returns E_UNSUPPORTED_OPERATION if the @c locale is invalid.
         *
         * @section                 CompNumberSymbolsConstructSolutionSection Resolutions
         * This issue has been resolved in Tizen.
	 * @par When working in Tizen:
         * -# The method returns E_INVALID_ARG if the @c locale is invalid.
	 * @endif
         */

	/**
	 * Gets the character used for number format.
	 *
	 * @since				2.0
	 *
	 * @return				The character used for number format, @n
	 *						else an empty string if the @c symbol is invalid
	 * @param[in]			symbol						The number format symbol instance
	 * @see						SetNumberSymbol()
	 */
	Tizen::Base::String GetNumberSymbol(NumberSymbol symbol) const;


	/**
	 * Sets the character used for number format.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			symbol						A symbol to set
	 * @param[in]			str							The new string for symbol
	 * @exception			E_SUCCESS					The method is successful.
	 * @see						GetNumberSymbol()
	 */
	result SetNumberSymbol(NumberSymbol symbol, const Tizen::Base::String& str);


	/**
	 * Gets the current locale.
	 *
	 * @since				2.0
	 *
	 * @return              A pointer to the current instance of Locale, @n
	 *						else @c null if this method fails
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	const Locale* GetLocale(void) const;


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	NumberSymbols(const NumberSymbols& numberSymbols);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	NumberSymbols& operator =(const NumberSymbols& numberSymbols);


	friend class _NumberSymbolsImpl;
	class _NumberSymbolsImpl* __pNumberSymbolsImpl;

}; // NumberSymbols

}} // Tizen::Locales

#endif //_FLCL_NUMBER_SYMBOLS_H_
 
