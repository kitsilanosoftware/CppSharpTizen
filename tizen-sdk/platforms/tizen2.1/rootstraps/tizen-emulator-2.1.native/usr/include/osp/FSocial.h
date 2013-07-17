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
 * @file	FSocial.h
 * @brief	This is the header file for the %Social namespace.
 *
 * This header file contains the declarations and descriptions of the %Social namespace.
 */

#ifndef _FSOCIAL_H_
#define _FSOCIAL_H_

// Includes
#include <FSclAddress.h>
#include <FSclAddressbook.h>
#include <FSclAddressbookManager.h>
#include <FSclAttendee.h>
#include <FSclCalendar.h>
#include <FSclCalendarbook.h>
#include <FSclCalendarbookFilter.h>
#include <FSclCalEvent.h>
#include <FSclCalEventChangeInfo.h>
#include <FSclCalEventInstance.h>
#include <FSclCalTodo.h>
#include <FSclCalTodoChangeInfo.h>
#include <FSclCategory.h>
#include <FSclCategoryChangeInfo.h>
#include <FSclContact.h>
#include <FSclContactChangeInfo.h>
#include <FSclEmail.h>
#include <FSclEmailContact.h>
#include <FSclIAddressbookEventListener.h>
#include <FSclIAddressbookChangeEventListener.h>
#include <FSclICalendarbookEventListener.h>
#include <FSclIRecordEventListener.h>
#include <FSclIRecordListener.h>
#include <FSclImAddress.h>
#include <FSclPhoneNumber.h>
#include <FSclPhoneNumberContact.h>
#include <FSclRecord.h>
#include <FSclRecurrence.h>
#include <FSclReminder.h>
#include <FSclUrl.h>
#include <FSclContactEvent.h>
#include <FSclOrganization.h>
#include <FSclRelationship.h>
#include <FSclPerson.h>
#include <FSclAddressbookFilter.h>
#include <FSclAccount.h>
#include <FSclAccountAccessor.h>
#include <FSclAccountManager.h>
#include <FSclAccountProvider.h>
#include <FSclIAccountEventListener.h>
#include <FSclTypes.h>
#include <FSclUserProfile.h>

/**
 * @namespace	Tizen::Social
 * @brief		This namespace contains the classes and interfaces for managing the social information of the user.
 * @since		2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FSocial.h> @n
 *				@b Library : @b osp-social
 *
 *
 * The %Social namespace provides various classes to manage the personal data, address book, and calendar of the user.
 *
 * For more information on the %Social namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/social/social_namespace.htm">Social Guide</a>.
 *
 * The following diagrams illustrate the relationships between the classes belonging to the Social namespace.
 *
 * [Account]
 * @image html social_account_classdiagram.png
 *
 * [Addressbook]
 * @image html social_addressbook_classdiagram.png
 *
 * [Calendarbook]
 * @image html social_calendarbook_using_the_apis_classdiagram.png
 *
 */
namespace Tizen { namespace Social
{
}}  // Tizen::Social

#endif // _FSOCIAL_H_
