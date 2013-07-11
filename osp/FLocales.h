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
 * @file		FLocales.h
 * @brief		This is the header file for the %Locales namespace.
 *
 * This header file contains the declarations of the %Locales namespace.
 */

#ifndef _FLOCALES_H_
#define _FLOCALES_H_

#include <FLclLocale.h>
#include <FLclLocaleManager.h>
#include <FLclNumberFormatter.h>
#include <FLclDateTimeFormatter.h>
#include <FLclNumberSymbols.h>
#include <FLclDateTimeSymbols.h>
#include <FLclCalendar.h>
#include <FLclGregorianCalendar.h>
#include <FLclTimeZone.h>
#include <FLclCurrency.h>


/**
 * @namespace	Tizen::Locales
 * @brief		This namespace contains classes that define culture-related information.
 *
 * @since		2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FLocales.h> @n
 *				@b Library: @b osp-appfw
 *
 *
 * The %Locales namespace contains classes representing a specific cultural region (locale) and the classes for manipulating and formatting locale-sensitive information, such as dates, times, numbers, and time zones.
 *
 * For more information on the %Locales namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/locales_namespace.htm">Locales Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Locales namespace.
 *
 * @image html locales_using_the_apis_classdiagram.png
 */

namespace Tizen { namespace Locales
{

}} // Tizen::Locales

#endif //_FLOCALES_H_
