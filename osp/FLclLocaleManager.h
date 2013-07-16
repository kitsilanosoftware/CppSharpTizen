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
 * @file		FLclLocaleManager.h
 * @brief		This is the header file for the %LocaleManager class.
 *
 * This header file contains the declarations of the %LocaleManager class.
 *
 */
#ifndef _FLCL_LOCALE_MANAGER_H_
#define _FLCL_LOCALE_MANAGER_H_

#include <FBaseString.h>
#include <FBaseColIList.h>
#include <FLclTimeZone.h>
#include <FLclLocale.h>

namespace Tizen { namespace Locales
{

/**
 * @class		LocaleManager
 * @brief		This class is used for the %LocaleManager identification.
 *
 * @since		2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %LocaleManager class helps application programmers handle the system locale information of the device. Each device system has at least one installed locale and often has many locales from which the user can choose.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/lang_country_codes.htm">Retrieving Language and Country Codes</a>.

 * @see Locale
 * @see NumberFormatter
 * @see DateTimeFormatter
 *
 * The following example demonstrates how to use the %LocaleManager class to get and set system locale information.
 *
 * @code

#include <FBase.h>
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::Locales;

void
LocaleApp::LocaleExample1(void)
{
    LocaleManager localeManager;
    localeManager.Construct();

    // Gets the system locale information.
    Locale	systemLocale = localeManager.GetSystemLocale();

    String countryCodeString = systemLocale.GetCountryCodeString();
    String languageCodeString = systemLocale.GetLanguageCodeString();
    String variantCodString = systemLocale.GetVariantCodeString();

    // Gets the formatted number that is localized.
    NumberFormatter* pNumberFormatter = NumberFormatter::CreateNumberFormatterN(systemLocale);

    String formattedString;
    long inputNumber = 123456;
    pNumberFormatter->Format((long) inputNumber, formattedString);

    // Gets the formatted date/time that is localized.
    DateTimeFormatter* pDateTimeFormatter = DateTimeFormatter::CreateDateTimeFormatterN(systemLocale);
    DateTime dateTime;
    dateTime.SetValue(2009, 2, 24, 15, 22, 00);
    pDateTimeFormatter->Format(dateTime, formattedString);

    // Gets the currency symbol that is localized.
    NumberFormatter* pCurrencyFormatter = NumberFormatter::CreateCurrencyFormatterN(systemLocale);
    inputNumber = 4000;
    pCurrencyFormatter->Format(inputNumber, formattedString);


    delete pNumberFormatter;
    delete pDateTimeFormatter;
    delete pCurrencyFormatter;
}

@endcode
 *
 * The following example demonstrates how to use the %LocaleManager class to get a list of all the available locales from the system.
 *
 * @code

#include <FBase.h>
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::Locales;

void
LocaleApp::LocaleExample2(void)
{
	LocaleManager localeManager;
	localeManager.Construct();

	IList* pAvailableLocales = localeManager.GetAvailableLocalesN();
	if (pAvailableLocales)
	{
		for (int i = 0; i < pAvailableLocales->GetCount(); i++)
		{
			Locale* pLocale = (Locale*) (pAvailableLocales->GetAt(i));

			String languageCodeString = pLocale->GetLanguageCodeString();
			String countryCodeString = pLocale->GetCountryCodeString();
			String variantCodString = pLocale->GetVariantCodeString();

			// ...
		}
	}
}

@endcode

 *
 */
class _OSP_EXPORT_ LocaleManager
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @see				Construct()
	 *
	 */
	LocaleManager(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~LocaleManager(void);

	/**
	 * Initializes this instance of %LocaleManager.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result Construct(void);


	/**
	 * Gets the system locale of the device.
	 *
	 * @since				2.0
	 *
	 * @return				An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception                   E_SYSTEM                                        A system error has occurred.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 *						The resulting Locale instance is Locale (LANGUAGE_INVALID, COUNTRY_INVALID).
	 */
	Locale GetSystemLocale(void) const;


	/**
	 * Gets a list of all the available locales.
	 *
	 * @since				2.0
	 *
	 * @return				A list of Locale instances, @n
	 *						else @c null if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @remarks				The IList returned contains the list of all the locales installed on the system.
	 *						The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAvailableLocalesN(void) const;


	/**
	 * Gets the currently selected language of the device by a user from the user setting menu.
	 *
	 * @since				2.0
	 *
	 * @return				An instance of Tizen::Base::String (ISO 639-2 code format), @n
	 *						else empty string if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetSelectedLanguage(void) const;


	/**
	 * Gets a list of all the available languages supported by the device, which can be different according to the target country/region of the device.
	 *
	 * @since				2.0
	 *
	 * @return				A list of Tizen::Base::String instances (ISO 639-2 code format), @n
	 *						else @c null if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAvailableLanguagesN(void) const;


	/**
	 * Gets a list of all the available time zone IDs.
	 *
	 * @since				2.0
	 *
	 * @return				A list of Tizen::Base::String instances, @n
	 *						else @c null if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAvailableTimeZonesN(void) const;


	/**
	 * Gets a list of all the available time zone IDs with the specified Greenwich Mean Time (GMT) offset for this time zone.
	 *
	 * @since				2.0
	 *
	 * @return				A list of Tizen::Base::String instances, @n
	 *						else @c null if the method fails
	 * @param[in]			rawOffset					The specified GMT offset for this time zone (Daylight Saving Time (DST) is not considered) @n
	 *													The value of @c rawOffset is in minutes.
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 *						If there are no time zones for the specified GMT offset, an empty list is returned.
	 */
	Tizen::Base::Collection::IList* GetAvailableTimeZonesN(int rawOffset) const;


	/**
	 * Gets the default system time zone.
	 *
	 * @since				2.0
	 *
	 * @return				The default system time zone, @n
	 *						else the time zone name is an empty string and the offset is @c -1 if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	TimeZone GetSystemTimeZone(void) const;


	/**
	 * Checks whether the specified instance of Locale is supported.
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[in]			locale						An instance of Locale
	 * @param[out]			isSupportedLocale			The flag for checking the supported locale
	 * @exception			E_SUCCESS					The method is successful.
	 */
	result IsSupportedLocale(const Locale& locale, bool& isSupportedLocale);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to
	 * prohibit copying of objects.
	 */
	LocaleManager(const LocaleManager& localeManager);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private
	 * to prohibit copying of objects.
	 */
	LocaleManager& operator =(const LocaleManager& localeManager);

	friend class _LocaleManagerImpl;
	class _LocaleManagerImpl* __pLocaleManagerImpl;
}; // Locale

}} // Tizen::Locales

#endif //_FLCL_LOCALE_MANAGER_H_
