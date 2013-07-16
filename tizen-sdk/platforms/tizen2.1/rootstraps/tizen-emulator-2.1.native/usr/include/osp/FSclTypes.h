//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
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
 * @file	FSclTypes.h
 * @brief	This is the header file for the types in the Social namespace.
 *
 * This header file contains the declarations of the types in the Social namespace.
 */
#ifndef _FSCL_TYPES_H_
#define _FSCL_TYPES_H_

namespace Tizen { namespace Base
{
class DateTime;
}}

namespace Tizen { namespace Social
{

/**
 * A unique ID. This ID is unique within a local storage only. @n
 * @c RecordId is assigned by the local storage (for example, Addressbook and Calendarbook) when a record is saved to the storage. @n
 * A newly constructed record instance has @c INVALID_RECORD_ID.
 *
 * @since	2.0
 */
typedef int RecordId;

/**
 * An invalid record ID. @n
 * The record has not been properly recorded to Addressbook.
 *
 * @since	2.0
 */
const RecordId INVALID_RECORD_ID = -1;

/**
 * A unique ID for an account. @n
 * If an account is added successfully, an @c AccountId is automatically assigned to the account.
 *
 * @since	2.1
 */
typedef int AccountId;

/**
 * An invalid account ID.
 *
 * @since	2.1
 */
const AccountId INVALID_ACCOUNT_ID = -1;

/**
 * @typedef	RecurrenceId
 * Defines the recurrence ID that is used to identify a specific instance of a recurring calendar component (CalEvent). @n
 * The value type is @c Tizen::Base::DateTime. The property value is the effective value of the start time ("DTSTART" property) of the Recurrence instance.
 *
 * @since	2.0
 */
typedef Tizen::Base::DateTime RecurrenceId;

/**
 * @if OSPDEPREC
 * The maximum length of the name property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_ATTENDEE_NAME_LENGTH = 100;

/**
 * @if OSPDEPREC
 * The maximum length of the email property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_ATTENDEE_EMAIL_LENGTH = 320;

/**
 * @if OSPDEPREC
 * The maximum length of the subject field.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_EVENT_SUBJECT_LENGTH = 100;

/**
 * @if OSPDEPREC
 * The maximum length of the description field.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_EVENT_DESCRIPTION_LENGTH = 1000;

/**
 * @if OSPDEPREC
 * The maximum length of the location field.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_EVENT_LOCATION_LENGTH = 100;

/**
 * @if OSPDEPREC
 * The maximum length of the subject field.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_TODO_SUBJECT_LENGTH = 100;

/**
 * @if OSPDEPREC
 * The maximum length of the description field.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_TODO_DESCRIPTION_LENGTH = 1000;

/**
 * @if OSPDEPREC
 * The maximum recurrence interval value.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_RECURRENCE_INTERVAL_VALUE = 255;

/**
 * @if OSPDEPREC
 * The maximum value of the reminder offset (in minutes).
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated.
 * @since	2.0
 * @endif
 */
static const int MAX_REMINDER_OFFSET_VALUE = 40320;

/**
 * @if OSPDEPREC
 * The maximum length of the name properties (first, last, nickname, and formatted names).
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_CONTACT_NAME_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the job title property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_CONTACT_JOB_TITLE_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the company property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_CONTACT_COMPANY_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the note property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_CONTACT_NOTE_LENGTH = 100;

/**
 * @if OSPDEPREC
 * The maximum length of the category name.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because the maximum length of the category name has been changed.
 * @since	2.0
 * @endif
 */
static const int MAX_CATEGORY_NAME_LENGTH = 20;

/**
 * @if OSPDEPREC
 * The minimum length of the query string for searching the contacts by name.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This value is deprecated.
 * @since	2.0
 *
 * @see	 Addressbook::SearchContactsByNameN()
 * @endif
 */
static const int MIN_NAME_QUERY_LENGTH = 1;

/**
 * @if OSPDEPREC
 * The minimum length of the query string for searching the contacts by phone number.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This value is deprecated.
 * @since	2.0
 *
 * @see	 Addressbook::SearchContactsByPhoneNumberN()
 * @endif
 */
static const int MIN_PHONENUMBER_QUERY_LENGTH = 4;

/**
 * @if OSPDEPREC
 * The minimum length of the query string for searching the contacts by email.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This value is deprecated.
 * @since	2.0
 *
 * @see	 Addressbook::SearchContactsByEmailN()
 * @endif
 */
static const int MIN_EMAIL_QUERY_LENGTH = 1;

/**
 * @if OSPDEPREC
 * The maximum length of the email property.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_EMAIL_LENGTH = 100;

/**
 * @enum	ContactPropertyId
 *
 * Defines the IDs for accessing the single value type properties of Contact.
 * @since	2.0
 */
enum ContactPropertyId
{
	CONTACT_PROPERTY_ID_FIRST_NAME = 1,			/**< The first name property ID (String type) */
	CONTACT_PROPERTY_ID_LAST_NAME,				/**< The last name property ID (String type) */
	CONTACT_PROPERTY_ID_DISPLAY_NAME,			/**< The formatted name property ID (String type) */
	CONTACT_PROPERTY_ID_NICK_NAME,				/**< @if OSPDEPREC The nick name property ID (String type)
									@deprecated This enum value is deprecated because there can be multiple nicknames
									in a contact. Instead of using this, use ContactMultiPropertyId::CONTACT_MPROPERTY_ID_NICKNAMES. @endif */
	CONTACT_PROPERTY_ID_THUMBNAIL,				/**< @if OSPDEPREC The thumbnail property ID (Bitmap type)
								@deprecated This enumeration value is deprecated because it is not used any longer. @endif */
	CONTACT_PROPERTY_ID_BIRTHDAY,				/**< @if OSPDEPREC The birthday property ID (DateTime type)
                                                                	@deprecated This enum value is deprecated because there can be multiple birthday events.
									Instead of using this, use ContactMultiPropertyId::CONTACT_MPROPERTY_ID_EVENTS. @endif */
	CONTACT_PROPERTY_ID_JOB_TITLE,				/**< @if OSPDEPREC The job title property ID (String type)
                                                                	@deprecated This enum value is deprecated because there can be multiple organizational information.
									Instead of using this, use ContactMultiPropertyId::CONTACT_MPROPERTY_ID_ORGANIZATIONS. @endif */
	CONTACT_PROPERTY_ID_COMPANY,				/**< @if OSPDEPREC The company property ID (String type)
									@deprecated This enum value is deprecated because there can be multiple organizational information.
									Instead of using this, use ContactMultiPropertyId::CONTACT_MPROPERTY_ID_ORGANIZATIONS.@endif */
	CONTACT_PROPERTY_ID_NOTE,				/**< @if OSPDEPREC The note property ID (String type)
									@deprecated This enum value is deprecated because there can be multiple notes
									in a contact. Instead of using this, use ContactMultiPropertyId::CONTACT_MPROPERTY_ID_NOTES.@endif */
	CONTACT_PROPERTY_ID_ANNIVERSARY,			/**< @if OSPDEPREC The anniversary property ID (DateTime type)
									@deprecated This enum value is deprecated because there can be multiple anniversary events.
									Instead of using this, use ContactMultiPropertyId::CONTACT_MPROPERTY_ID_EVENTS.@endif */
	CONTACT_PROPERTY_ID_RINGTONE,				/**< The ringtone property ID (String type) */
	CONTACT_PROPERTY_ID_MIDDLE_NAME,			/**< The middle name property ID (String type) */
	CONTACT_PROPERTY_ID_LAST_REVISION,			/**< An ID for the calendar date and time for the last update in Coordinated Universal Time (UTC) @n	Read-only (DateTime type). */
	CONTACT_PROPERTY_ID_NAME_PREFIX,			/**< The name honorific prefix property ID (String type) */
	CONTACT_PROPERTY_ID_NAME_SUFFIX,			/**< The name honorific suffix property ID (String type) */
	CONTACT_PROPERTY_ID_PHONETIC_FIRST_NAME,	/**< The phonetic first name property ID (String type) @b Since: @b 2.1 */
	CONTACT_PROPERTY_ID_PHONETIC_LAST_NAME,		/**< The phonetic last name property ID (String type) @b Since: @b 2.1 */
	CONTACT_PROPERTY_ID_PHONETIC_MIDDLE_NAME,	/**< The phonetic middle name property ID (String type) @b Since: @b 2.1 */
	CONTACT_PROPERTY_ID_UID,			/**< The globally unique ID (String type) @b Since: @b 2.1 */
};

/**
 * @enum	ContactMultiPropertyId
 *
 * Defines the IDs for accessing the multi-value type properties of Contact. @n
 * The properties have several values and they are called multi-type properties.
 * @since	2.0
 */
enum ContactMultiPropertyId
{
	CONTACT_MPROPERTY_ID_PHONE_NUMBERS,		/**< The phone number property ID (PhoneNumber class) */
	CONTACT_MPROPERTY_ID_EMAILS,			/**< The email property ID (Email class) */
	CONTACT_MPROPERTY_ID_URLS,			/**< The URL property ID (Url class) */
	CONTACT_MPROPERTY_ID_ADDRESSES,			/**< The address property ID (Address class) */
	CONTACT_MPROPERTY_ID_IMADDRESSES,		/**< The Instant Message property ID (ImAddress class) */
	CONTACT_MPROPERTY_ID_EVENTS,			/**< The contact event property ID (ContactEvent type) */
	CONTACT_MPROPERTY_ID_ORGANIZATIONS,		/**< The organization property ID (Organization type) */
	CONTACT_MPROPERTY_ID_NOTES,			/**< The note property ID (String type) */
	CONTACT_MPROPERTY_ID_NICKNAMES,			/**< The nickname property ID (String type) */
	CONTACT_MPROPERTY_ID_RELATIONSHIPS,		/**< The relationship property ID (Relationship type) */
};

/**
 * @if OSPDEPREC
 * The number of #ContactPropertyId factors.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because it is not used any more.
 * @since	2.0
 * @endif
 */
static const int CONTACT_PROPERTY_ID_NUM = 14;

/**
 * @if OSPDEPREC
 * The number of #ContactMultiPropertyId factors.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because it is not used any more.
 * @since	2.0
 * @endif
 */
static const int CONTACT_MPROPERTY_ID_NUM = 5;

/**
 * @enum	RecordSensitivity
 * Defines the sensitivity type of the calendar book record. @n
 * This value represents the access classification property of @c vCalendar and @c iCalendar.
 *
 * @since	2.0
 */
enum RecordSensitivity
{
	SENSITIVITY_PUBLIC,			/**< The public sensitivity */
	SENSITIVITY_PRIVATE,			/**< The private sensitivity */
	SENSITIVITY_CONFIDENTIAL		/**< The confidential sensitivity */
};

/**
 * @enum	AttendeeRole
 * Defines the role of the attendee.
 * @since	2.0
 */
enum AttendeeRole
{
	ATTENDEE_ROLE_ATTENDEE,			 /**< The attendee	*/
	ATTENDEE_ROLE_REQUIRED_ATTENDEE,	/**< The required attendee	*/
	ATTENDEE_ROLE_ORGANIZER			 /**< The organizer	*/
};

/**
 * @enum	AttendeeStatus
 * Defines the possible status of the attendee.
 * @since	2.0
 */
enum AttendeeStatus
{
	ATTENDEE_STATUS_NONE,			/**< The none status */
	ATTENDEE_STATUS_NOT_RESPONDED,	/**< The not-responded status */
	ATTENDEE_STATUS_ACCEPTED,		/**< The accepted status */
	ATTENDEE_STATUS_DECLINED,		/**< The declined status*/
	ATTENDEE_STATUS_TENTATIVE,		/**< The tentative status*/
};

/**
 * @if OSPDEPREC
 * @enum		EventCategory
 * @brief	 <i> [Deprecated] </i> Defines the categories to classify the event.
 *
 * @deprecated	This enum type is deprecated because the category of event is not used any more.
 * @since	2.0
 * @endif
 */
enum EventCategory
{
	EVENT_CATEGORY_APPOINTMENT = 0x00000001,		/**< @if OSPDEPREC The appointment category @endif */
	EVENT_CATEGORY_ANNIVERSARY = 0x00000002,		/**< @if OSPDEPREC The anniversary category @endif */
};

/**
 * @if OSPDEPREC
 * All the event categories.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because the category of event is not used any more.
 * @since	2.0
 * @endif
 */
static const unsigned long EVENT_CATEGORY_ALL = EVENT_CATEGORY_APPOINTMENT | EVENT_CATEGORY_ANNIVERSARY;

/**
 * @enum		EventPriority
 * Defines the possible priority levels of the event.
 *
 * @since	2.0
 */
enum EventPriority
{
	EVENT_PRIORITY_LOW,		 /**< The low priority */
	EVENT_PRIORITY_NORMAL,		/**< The normal priority */
	EVENT_PRIORITY_HIGH		 /**< The high priority */
};

/**
 * @enum		EventStatus
 * Defines the possible statuses of the event.
 *
 * @since	2.0
 */
enum EventStatus
{
	EVENT_STATUS_NONE,		/**< The none status	*/
	EVENT_STATUS_CONFIRMED, /**< The confirmed status	*/
	EVENT_STATUS_CANCELLED, /**< The canceled status	*/
	EVENT_STATUS_TENTATIVE	/**< The tentative status	*/
};

/**
 * @enum		BusyStatus
 * Defines the busy statuses of the event.
 *
 * @since	2.0
 */
enum BusyStatus
{
	BUSY_STATUS_FREE,		/**< The free status	*/
	BUSY_STATUS_BUSY,		/**< The busy status	*/
	BUSY_STATUS_UNAVAILABLE,	/**< The unavailable status	*/
	BUSY_STATUS_TENTATIVE	/**< The tentative status	*/
};

/**
 * @enum	TodoStatus
 * Defines the possible to-do status types.
 *
 * @since	2.0
 */
enum TodoStatus
{
	TODO_STATUS_NONE = 0x00000001,				/**< The none status			*/
	TODO_STATUS_NEEDS_ACTION = 0x00000002,		/**< The needs action status	*/
	TODO_STATUS_COMPLETED = 0x00000004,			/**< The completed status		*/
	TODO_STATUS_IN_PROCESS = 0x00000008,		/**< The in process status		*/
	TODO_STATUS_CANCELLED = 0x00000010,			/**< The canceled status		*/
};

/** All the to-do statuses.
 *
 * @since	2.0
 */
static const unsigned long TODO_STATUS_ALL = TODO_STATUS_NONE | TODO_STATUS_NEEDS_ACTION | TODO_STATUS_COMPLETED |
											 TODO_STATUS_IN_PROCESS | TODO_STATUS_CANCELLED;

/**
 * @enum	TodoPriority
 * Defines the possible to-do priority levels.
 *
 * @since	2.0
 */
enum TodoPriority
{
	TODO_PRIORITY_LOW = 0x00000001,				/**< The low priority		*/
	TODO_PRIORITY_NORMAL = 0x00000002,			/**< The normal priority	*/
	TODO_PRIORITY_HIGH = 0x00000004,			/**< The high priority		*/
};

/** All the to-do priorities.
 *
 * @since	2.0
 */
static const unsigned long TODO_PRIORITY_ALL = TODO_PRIORITY_LOW | TODO_PRIORITY_NORMAL | TODO_PRIORITY_HIGH;

/**
 * @if OSPDEPREC
 * @enum RecordEventType
 * Defines the record event types.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This enum is deprecated because IRecordEventListener interface is deprecated.
 *
 * @since	2.0
 * @endif
 */
enum RecordEventType
{
	RECORD_ADDED,			/**< @if OSPDEPREC The adding of a new record @endif */
	RECORD_UPDATED,			/**< @if OSPDEPREC The updating of a record @endif */
	RECORD_REMOVED,			/**< @if OSPDEPREC The removal of a record @endif */
	ALL_RECORDS_REMOVED,		/**<
				 	 * @if OSPDEPREC
					 * The removal of all records @n
					 * @deprecated   This enum value is deprecated because it is not used any more.
					 * @endif
					 */
	MULTI_RECORDS_ADDED,		/**< @if OSPDEPREC The adding of multiple records @endif */
	MULTI_RECORDS_UPDATED,		/**< @if OSPDEPREC The adding, updating, and/or removal of multiple records @endif */
	MULTI_RECORDS_REMOVED		/**< @if OSPDEPREC The removal of multiple records @endif */
};

/**
 * @enum	RecurFrequency
 * Defines the recurrence frequency type.
 *
 * @since	2.0
 */
enum RecurFrequency
{
	FREQ_DAILY,		 /**< The daily recurrence	*/
	FREQ_WEEKLY,		/**< The weekly recurrence	*/
	FREQ_MONTHLY,		/**< The monthly recurrence	*/
	FREQ_YEARLY		 /**< The yearly recurrence	*/
};

/**
 * @enum	CalDayOfWeek
 * Defines the day of week type.
 *
 * @since	2.0
 */
enum CalDayOfWeek
{
	CAL_SUNDAY = 0x0001,		/**< The day of the week is Sunday	*/
	CAL_MONDAY = 0x0002,		/**< The day of the week is Monday	*/
	CAL_TUESDAY = 0x0004,		/**< The day of the week is Tuesday	*/
	CAL_WEDNESDAY = 0x0008,	 /**< The day of the week is Wednesday */
	CAL_THURSDAY = 0x0010,		/**< The day of the week is Thursday */
	CAL_FRIDAY = 0x0020,		/**< The day of the week is Friday	*/
	CAL_SATURDAY = 0x0040		/**< The day of the week is Saturday */
};

/**
 * @enum	RecordChangeType
 * Defines the change type of Record.
 *
 * @since	2.0
 */
enum RecordChangeType
{
	RECORD_CHANGE_TYPE_ADDED,		/**< A record is added */
	RECORD_CHANGE_TYPE_REMOVED,		/**< A record is removed */
	RECORD_CHANGE_TYPE_UPDATED,		/**< A record is updated */
};

/**
 * @enum		CalendarItemType
 * Defines item types to specify which kind of item the calendar can contain.
 *
 * @since	2.0
 */
enum CalendarItemType
{
	CALENDAR_ITEM_TYPE_EVENT_ONLY = 0x1,			/**< The item type for event */
	CALENDAR_ITEM_TYPE_TODO_ONLY = 0x2,			/**< The item type for to-do item */
	CALENDAR_ITEM_TYPE_EVENT_AND_TODO = 0x3		/**< The item type for event and to-do item */
};

/**
 * @enum PhoneNumberType
 *
 * Defines the types of phone number.
 * @since	2.0
 */
enum PhoneNumberType
{
	PHONENUMBER_TYPE_HOME,		/**< The phone number type for home telephone*/
	PHONENUMBER_TYPE_WORK,		/**< The phone number type for work telephone*/
	PHONENUMBER_TYPE_MOBILE,	/**< The phone number type for mobile */
	PHONENUMBER_TYPE_HOME_FAX,	/**< The phone number type for home fax */
	PHONENUMBER_TYPE_WORK_FAX,	/**< The phone number type for work fax */
	PHONENUMBER_TYPE_PAGER,	 	/**< The phone number type for pager */
	PHONENUMBER_TYPE_OTHER,		/**< The phone number type for other */
	PHONENUMBER_TYPE_CUSTOM,	/**< The custom type @n The actual type can be set in the label. */
	PHONENUMBER_TYPE_ASSISTANT	/**< The phone number type for assistant. @b Since: @b 2.1 */
};

/**
 * @enum	ReminderTimeUnit
 * Defines the reminder time unit.
 *
 * @since	2.0
 */
enum ReminderTimeUnit
{
	REMINDER_TIME_UNIT_MINUTE,		/**< The unit of time offset is minute */
	REMINDER_TIME_UNIT_HOUR,			/**< The unit of time offset is hour */
	REMINDER_TIME_UNIT_DAY,			/**< The unit of time offset is day */
	REMINDER_TIME_UNIT_WEEK,			/**< The unit of time offset is week */
	REMINDER_TIME_UNIT_NONE,			/**< The unit of time offset is none @b Since @b 2.1 */
};

/**
 * @enum EmailType
 *
 * Defines the types of email.
 *
* @since	2.0
 */
enum EmailType
{
	EMAIL_TYPE_PERSONAL,	/**< The email type for personal*/
	EMAIL_TYPE_WORK,	/**< The email type for work */
	EMAIL_TYPE_OTHER,	/**< The email type for other */
	EMAIL_TYPE_CUSTOM,	/**< The custom type @n The actual type can be set in the label. */
	EMAIL_TYPE_MOBILE	/**< The email type for mobile. @b Since: @b 2.1 */
};

/**
 * Defines the types of address.
 *
 * @since	2.0
 */
enum AddressType
{
	ADDRESS_TYPE_HOME,	/**< The address type for home address */
	ADDRESS_TYPE_WORK,	/**< The address type for work address */
	ADDRESS_TYPE_OTHER,	/**< The address type for other */
	ADDRESS_TYPE_CUSTOM	/**< The custom type @n The actual type can be set in the label. */
};

/**
 * @enum ContactEventType
 *
 * Defines the types of event.
 *
 * @since	2.0
 */
enum ContactEventType
{
	CONTACT_EVENT_TYPE_BIRTHDAY,	/**< The event type for birthday */
	CONTACT_EVENT_TYPE_ANNIVERSARY,	/**< The event type for anniversary */
	CONTACT_EVENT_TYPE_OTHER,	/**< The event type for other */
	CONTACT_EVENT_TYPE_CUSTOM	/**< The custom event @n The actual type can be set in the label. */
};

/**
 * @enum UrlType
 *
 * Defines the types of URL.
 *
 * @since	2.0
 */
enum UrlType
{
	URL_TYPE_PERSONAL,	/**< The URL type is personal */
	URL_TYPE_WORK,		/**< The URL type is work */
	URL_TYPE_OTHER,		/**< The URL type is other */
	URL_TYPE_CUSTOM         /**< The custom type @n The actual type can be set in the label. */
};

/**
 * @enum RelationshipType
 *
 * Defines the types of relationship.
 *
 * @since	2.0
 */
enum RelationshipType
{
	CONTACT_RELATIONSHIP_TYPE_ASSISTANT,		/**< The relation type for assistant */
	CONTACT_RELATIONSHIP_TYPE_BROTHER,		/**< The relation type for brother */
	CONTACT_RELATIONSHIP_TYPE_CHILD,		/**< The relation type for child */
	CONTACT_RELATIONSHIP_TYPE_DOMESTIC_PARTNER, 	/**< The relation type for domestic partner */
	CONTACT_RELATIONSHIP_TYPE_FATHER,		/**< The relation type for father */
	CONTACT_RELATIONSHIP_TYPE_FRIEND,		/**< The relation type for friend */
	CONTACT_RELATIONSHIP_TYPE_MANAGER,		/**< The relation type for manager */
	CONTACT_RELATIONSHIP_TYPE_MOTHER,		/**< The relation type for mother */
	CONTACT_RELATIONSHIP_TYPE_PARENT, 		/**< The relation type for parent */
	CONTACT_RELATIONSHIP_TYPE_PARTNER,		/**< The relation type for partner */
	CONTACT_RELATIONSHIP_TYPE_REFERRED_BY,		/**< The relation type for referred-by */
	CONTACT_RELATIONSHIP_TYPE_RELATIVE,		/**< The relation type for relative */
	CONTACT_RELATIONSHIP_TYPE_SISTER,		/**< The relation type for sister */
	CONTACT_RELATIONSHIP_TYPE_SPOUSE,		/**< The relation type for spouse */
	CONTACT_RELATIONSHIP_TYPE_CUSTOM		/**< The custom event @n The actual type can be set in the label. */
};

/**
 * @enum OrganizationType
 *
 * Defines the types of organization.
 *
 * @since 2.1
 */

enum OrganizationType
{
	ORGANIZATION_TYPE_WORK,		/**< The organization type for work */
	ORGANIZATION_TYPE_OTHER,	/**< The organization type for other */
	ORGANIZATION_TYPE_CUSTOM	/**< The custom type @n The actual type can be set in the label */
};

/**
 * @if OSPDEPREC
 * The maximum length of the phone number property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_PHONE_NUMBER_LENGTH = 50;

//This value is for internal use only. Using this value can cause behavioral,
//security-related, and consistency-related issues in the application.
typedef int AccountId;

/**
 * The person ID.
 *
 * @since	2.0
 */
typedef int PersonId;


/**
 * The addressbook ID.
 *
 * @since	2.0
 */
typedef int AddressbookId;

/**
* An invalid address book ID indicates that the address book has not been properly stored to the address book database.
*
* @since	2.0
*/
static const AddressbookId INVALID_ADDRESSBOOK_ID = -2;

/**
* The default addressbook ID.
*
* @since	2.0
*/
static const AddressbookId DEFAULT_ADDRESSBOOK_ID = 0;

/**
 * @enum FilterConjunctiveOperator
 * Defines the conjunctive operators to compound the filtering expressions.
 *
 * @since	2.0
 */
enum FilterConjunctiveOperator
{
	FI_CONJ_OP_NONE,  	/**< None */
	FI_CONJ_OP_AND,  	/**< AND operator */
	FI_CONJ_OP_OR,  	/**< OR operator */
};

/**
 * @enum FilterComparisonOperator
 * Defines the comparison operators.
 *
 * @since	2.0
 */
enum FilterComparisonOperator
{
	FI_CMP_OP_EQUAL, 			/**< = operator */
	FI_CMP_OP_LESS_THAN, 			/**< < operator */
	FI_CMP_OP_LESS_THAN_OR_EQUAL, 		/**< <= operator */
	FI_CMP_OP_GREATER_THAN, 		/**< > operator*/
	FI_CMP_OP_GREATER_THAN_OR_EQUAL, 	/**< >= operator */
	FI_CMP_OP_IS_NULL, 			/**< IS NULL operator */
};

/**
 * @enum FilterStringOperator
 * Defines the matching criteria for Strings.
 *
 * @since	2.0
 */
enum FilterStringOperator
{
	FI_STR_OP_EQUAL, 		/**< The operator for matching the string exactly */
	FI_STR_OP_FULL_STRING, 		/**< The operator for matching the full-string without case sensitive */
	FI_STR_OP_START_WITH, 		/**< The operator for matching the string starting with the specified keyword */
	FI_STR_OP_END_WITH, 		/**< The operator for matching the string ending with the specified keyword */
	FI_STR_OP_CONTAIN, 		/**< The operator for matching the string containing the specified keyword */
	FI_STR_OP_IS_NOT_NULL,        	/**< The operator for matching any string(except NULL) @n The specified is ignored. */
};

/**
 * @enum AddressbookFilterType
 * Defines the type of the filter for Addressbook.
 *
 * @since	2.0
 */
enum AddressbookFilterType
{
	AB_FI_TYPE_ADDRESSBOOK,  	/**< The filter for the addressbooks @n AddressbookFilterProperty is only used in this type filter.
						The search result with this filter is a list of Addressbook. */
	AB_FI_TYPE_PERSON,  		/**< The filter for the persons @n PersonFilterProperty is only used in this type filter.
						The search result with this filter is a list of Person. */
	AB_FI_TYPE_CONTACT, 		/**< The filter for the contacts @n ContactFilterProperty is only used in this type filter.
						The search result with this filter is a list of Contact. */
	AB_FI_TYPE_CATEGORY,  		/**< The filter for the categories @n CategoryFilterProperty is only used in this type filter.
						The search result with this filter is a list of Category. */
	AB_FI_TYPE_PHONE_CONTACT,  	/**< The filter for the contacts with phone number @n PhoneContactFilterProperty is only used in this type filter.
						The search result with this filter is a list of PhoneNumberContact. */
	AB_FI_TYPE_EMAIL_CONTACT, 	/**< The filter for the contacts with email @n EmailContactFilterProperty is only used in this type filter.
						The search result with this filter is a list of EmailContact. */
};

/**
 * @enum AddressbookFilterProperty
 * Defines the property for filtering the addressbooks. @n
 * These properties can be used to create an AddressbookFilter of #AB_FI_TYPE_ADDRESSBOOK type.
 *
 * @since	2.0
 */
enum AddressbookFilterProperty
{
	AB_FI_PR_ADDRESSBOOK_ID = 1, 		/**< The addressbook ID: int (AddressbookId) */
	AB_FI_PR_ACCOUNT_ID, 			/**< The account ID: int (AccountId) */
	AB_FI_PR_NAME, 				/**< The addressbook name: String */
};

/**
 * @enum PersonFilterProperty
 * Defines the property for filtering the persons. @n
 * These properties can be used to create an AddressbookFilter of #AB_FI_TYPE_PERSON type.
 *
 * @since	2.0
 */
enum PersonFilterProperty
{
	PERSON_FI_PR_PERSON_ID = 100, 		/**< The person ID: int (RecordId) */
	PERSON_FI_PR_DISPLAY_NAME, 		/**< The display name: String */
	PERSON_FI_PR_HAS_PHONE, 		/**< Whether the person has phone numbers or not: bool */
	PERSON_FI_PR_HAS_EMAIL, 		/**< Whether the person has emails or not: bool */
	PERSON_FI_PR_IS_FAVORITE, 		/**< Whether the person is favorite or not: bool */
	PERSON_FI_PR_CATEGORY_ID, 		/**< The category ID: int (RecordId) */
	PERSON_FI_PR_ADDRESSBOOK_ID, 		/**< The addressbook ID: int (AddressbookId) */
};

/**
 * @enum ContactFilterProperty
 * Defines the property for filtering the contacts. @n
 * These properties can be used to create an AddressbookFilter of #AB_FI_TYPE_CONTACT type.
 *
 * @since	2.0
 */
enum ContactFilterProperty
{
	CONTACT_FI_PR_CONTACT_ID = 200, 	/**< The contact ID: int (RecordId) */
	CONTACT_FI_PR_ADDRESSBOOK_ID, 		/**< The addressbook ID: int (AddressbookId) */
	CONTACT_FI_PR_PERSON_ID, 		/**< The person ID: int (PersonId) */
	CONTACT_FI_PR_DISPLAY_NAME, 		/**< The display name: String */
	CONTACT_FI_PR_HAS_PHONE, 		/**< Whether the contact has phone numbers or not: bool */
	CONTACT_FI_PR_HAS_EMAIL, 		/**< Whether the contact has emails or not: bool */
};

/**
 * @enum CategoryFilterProperty
 * Defines the property for filtering the categories.
 * These properties can be used to create an AddressbookFilter of #AB_FI_TYPE_CATEGORY type.
 *
 * @since	2.0
 */
enum CategoryFilterProperty
{
	CATEGORY_FI_PR_CATEGORY_ID = 300, 	/**< The category ID: int (RecordId) */
	CATEGORY_FI_PR_ADDRESSBOOK_ID, 		/**< The addressbook ID: int (AddressbookId) */
	CATEGORY_FI_PR_NAME, 			/**< The category name: String */
};

/**
 * @enum PhoneContactFilterProperty
 * Defines the property for filtering the contacts with phone number.
 * These properties can be used to create an AddressbookFilter of #AB_FI_TYPE_PHONE_CONTACT type.
 *
 * @since	2.0
 */
enum PhoneContactFilterProperty
{
	PHONE_CONTACT_FI_PR_CONTACT_ID = 400,       /**< The contact ID: int (RecordId) */
	PHONE_CONTACT_FI_PR_ADDRESSBOOK_ID,         /**< The addressbook ID: int (AddressbookId) */
	PHONE_CONTACT_FI_PR_PERSON_ID,              /**< The person ID: int (PersonId) */
	PHONE_CONTACT_FI_PR_DISPLAY_NAME,           /**< The display name: String */
	PHONE_CONTACT_FI_PR_PHONE,           	    /**< The phone number: String */
};

/**
 * @enum EmailContactFilterProperty
 * Defines the property for filtering the contacts with email.
 * These properties can be used to create an AddressbookFilter of #AB_FI_TYPE_EMAIL_CONTACT type.
 *
 * @since	2.0
 */
enum EmailContactFilterProperty
{
	EMAIL_CONTACT_FI_PR_CONTACT_ID = 500,              /**< The contact ID: int (RecordId) */
	EMAIL_CONTACT_FI_PR_ADDRESSBOOK_ID,                /**< The addressbook ID: int (AddressbookId) */
	EMAIL_CONTACT_FI_PR_PERSON_ID,                     /**< The person ID: int (PersonId) */
	EMAIL_CONTACT_FI_PR_DISPLAY_NAME,                  /**< The display name: String */
	EMAIL_CONTACT_FI_PR_EMAIL,                         /**< The email: String */
};

/**
 * @enum        UserProfilePropertyId
 *
 * Defines the IDs for accessing the single value type properties of UserProfile.
 * @since       2.1
 */
enum UserProfilePropertyId
{
	USER_PROFILE_PROPERTY_ID_FIRST_NAME = 1,                  /**< The first name property ID (String type) */
	USER_PROFILE_PROPERTY_ID_LAST_NAME,                        /**< The last name property ID (String type) */
	USER_PROFILE_PROPERTY_ID_MIDDLE_NAME,                      /**< The middle name property ID (String type) */
	USER_PROFILE_PROPERTY_ID_NAME_PREFIX,                      /**< The name honorific prefix property ID (String type) */
	USER_PROFILE_PROPERTY_ID_NAME_SUFFIX,                      /**< The name honorific suffix property ID (String type) */
	USER_PROFILE_PROPERTY_ID_DISPLAY_NAME,                     /**< The formatted name property ID (String type) */
	USER_PROFILE_PROPERTY_ID_PHONETIC_FIRST_NAME,           /**< The phonetic first name property ID (String type) */
	USER_PROFILE_PROPERTY_ID_PHONETIC_LAST_NAME,            /**< The phonetic last name property ID (String type) */
	USER_PROFILE_PROPERTY_ID_PHONETIC_MIDDLE_NAME,          /**< The phonetic middle name property ID (String type) */
};

/**
 * @enum        UserProfileMultiPropertyId
 *
 * Defines the IDs for accessing the multi-value type properties of UserProfile. @n
 * The properties have several values and they are called multi-type properties.
 * @since       2.1
 */
enum UserProfileMultiPropertyId
{
	USER_PROFILE_MPROPERTY_ID_PHONE_NUMBERS,           /**< The phone number property ID (PhoneNumber class) */
	USER_PROFILE_MPROPERTY_ID_EMAILS,                  /**< The email property ID (Email class) */
	USER_PROFILE_MPROPERTY_ID_URLS,                    /**< The URL property ID (Url class) */
	USER_PROFILE_MPROPERTY_ID_ADDRESSES,               /**< The address property ID (Address class) */
	USER_PROFILE_MPROPERTY_ID_IMADDRESSES,             /**< The instant message property ID (ImAddress class) */
	USER_PROFILE_MPROPERTY_ID_EVENTS,                  /**< The contact event property ID (ContactEvent class) */
	USER_PROFILE_MPROPERTY_ID_ORGANIZATIONS,           /**< The organization property ID (Organization class) */
	USER_PROFILE_MPROPERTY_ID_NOTES,                   /**< The note property ID (String type) */
	USER_PROFILE_MPROPERTY_ID_NICKNAMES,               /**< The nickname property ID (String type) */
	USER_PROFILE_MPROPERTY_ID_RELATIONSHIPS,           /**< The relationship property ID (Relationship type) */
};

/**
 * @enum CalendarbookFilterType
 * Defines the type of the filter for Calendarbook.
 *
 * @since	2.0
 */
enum CalendarbookFilterType
{
	CB_FI_TYPE_EVENT,		/**< The filter for the event of Calendarbook @n EventFilterProperty is only used in this type filter. The search result with this filter is a list of CalEvent. */
	CB_FI_TYPE_TODO,		/**< The filter for the to-do of Calendarbook @n TodoFilterProperty is only used in this type filter. The search result with this filter is a list of CalTodo. */
	CB_FI_TYPE_CALENDAR,		/**< The filter for the calendar of Calendarbook @n CalendarFilterProperty is only used in this type filter. The search result with this filter is a list of Calendar. */
	CB_FI_TYPE_ALL_DAY_EVENT_INSTANCE,			/**< The filter for all day event instance of Calendarbook @n EventInstanceFilterProperty is only used in this type filter. The search result with this filter is a list of CalEventInstance. */
	CB_FI_TYPE_NON_ALL_DAY_EVENT_INSTANCE		/**< The filter for non-all day event instance of Calendarbook @n EventInstanceFilterProperty is only used in this type filter. The search result with this filter is a list of CalEventInstance. */
};

/**
 * @enum EventFilterProperty
 * Defines the property for filtering the events. @n
 * These properties can be used to create a CalendarbookFilter of CB_FI_TYPE_EVENT type.
 *
 * @since	2.0
 */
enum EventFilterProperty
{
	EVENT_FI_PR_EVENT_ID = 1,		/**< The event ID: int (RecordId) */
	EVENT_FI_PR_CALENDAR_ID,		/**< The calendar ID: long long (RecordId) */
	EVENT_FI_PR_SUBJECT,				/**< The subject of the event: String */
	EVENT_FI_PR_DESCRIPTION,		/**< The description of the event: String */
	EVENT_FI_PR_LOCATION,			/**< The location of the event: String */
	EVENT_FI_PR_BUSY_STATUS,			/**< The busy status of the event: int (BusyStatus) */
	EVENT_FI_PR_PRIORITY,				/**< The priority of the event: int (EventPriority) */
	EVENT_FI_PR_SENSITIVITY,			/**< The sensitivity of the event: int (RecordSensitivity) */
	EVENT_FI_PR_STATUS,			/**< The status of the event: int (EventStatus) */
	EVENT_FI_PR_UID,				/**< The uid of the event: String */
	EVENT_FI_PR_LATITUDE,				/**< The latitude of the event: Double */
	EVENT_FI_PR_LONGITUDE,			/**< The longitude of the event: Double */
	EVENT_FI_PR_LAST_REVISED_TIME,			/**< The last revised time of the event: DateTime */
	EVENT_FI_PR_HAS_REMINDER,			/**< Whether the event has the reminder or not: bool*/
	EVENT_FI_PR_HAS_ATTENDEE			/**< Whether the event has the attendee or not: bool*/
};

/**
* @enum TodoFilterProperty
* Defines the property for filtering the to-dos. @n
* These properties can be used to create a CalendarbookFilter of CB_FI_TYPE_TODO type.
*
* @since	2.0
*/
enum TodoFilterProperty
{
	TODO_FI_PR_TODO_ID = 100,			/**< The todo ID: long long (RecordId) */
	TODO_FI_PR_CALENDAR_ID,			/**< The calendar ID: long long (RecordId) */
	TODO_FI_PR_START_DATE,			/**< The start date of the to-do: DateTime*/
	TODO_FI_PR_DUE_DATE,			/**< The due date of the to-do: DateTime */
	TODO_FI_PR_SUBJECT,			/**< The subject of the to-do: String */
	TODO_FI_PR_DESCRIPTION,			/**< The description of the to-do: String */
	TODO_FI_PR_LOCATION,				/**< The location of the to-do: String */
	TODO_FI_PR_PRIORITY,				/**< The priority of the to-do: int (TodoPriority)*/
	TODO_FI_PR_SENSITIVITY,			/**< The sensitivity of the to-do: int (RecordSensitivity) */
	TODO_FI_PR_STATUS,				/**< The status of the to-do: int (TodoStatus) */
	TODO_FI_PR_LATITUDE,			/**< The latitude of the to-do: double*/
	TODO_FI_PR_LONGITUDE,			/**< The longitude of the to-do: double*/
	TODO_FI_PR_LAST_REVISED_TIME,			/**< The last revised time of the to-do: DateTime */
	TODO_FI_PR_HAS_REMINDER				/**< Whether the to-do has the reminder or not: bool*/
};

/**
* @enum EventInstanceFilterProperty
* Defines the property for filtering the all day event instances or non-all day event instances. @n
* These properties can be used to create a CalendarbookFilter of CB_FI_TYPE_ALL_DAY_EVENT_INSTANCE type or CB_FI_TYPE_NON_ALL_DAY_EVENT_INSTANCE type.
*
* @since	2.0
*/
enum EventInstanceFilterProperty
{
	EVENT_INST_FI_PR_ORIGINAL_EVENT_ID = 200,			/**< The original event ID: int (RecordId) */
	EVENT_INST_FI_PR_CALENDAR_ID,			/**< The calendar ID: int (RecordId) */
	EVENT_INST_FI_PR_START_TIME,			/**< The start time of the event instance: DateTime */
	EVENT_INST_FI_PR_END_TIME,			/**< The end time of the event instance: DateTime */
	EVENT_INST_FI_PR_SUBJECT,				/**< The subject of the event instance: String */
	EVENT_INST_FI_PR_DESCRIPTION,			/**< The description of the event instance: String */
	EVENT_INST_FI_PR_LOCATION,				/**< The location of the event instance: String */
	EVENT_INST_FI_PR_BUSY_STATUS,			/**< The busy status of the event instance: int (BusyStatus) */
	EVENT_INST_FI_PR_PRIORITY,				/**< The priority of the event instance: int (EventPriority) */
	EVENT_INST_FI_PR_SENSITIVITY,			/**< The sensitivity of the event instance: int (RecordSensitivity) */
	EVENT_INST_FI_PR_STATUS,				/**< The status of the event instance: int (EventStatus) */
	EVENT_INST_FI_PR_LATITUDE,			/**< The latitude of the event instance: Double */
	EVENT_INST_FI_PR_LONGITUDE,			/**< The latitude of the event instance: Double */
	EVENT_INST_FI_PR_IS_RECURRING,			/**< Whether the event instance is the recurring event or not: bool*/
	EVENT_INST_FI_PR_HAS_REMINDER			/**< Whether the event instance has the reminder or not: bool*/
};

/**
* @enum CalendarFilterProperty
* Defines the property for filtering the calendars. @n
* These properties can be used to create a CalendarbookFilter of CB_FI_TYPE_CALENDAR type.
*
* @since	2.0
*/
enum CalendarFilterProperty
{
	CALENDAR_FI_PR_CALENDAR_ID = 400,			/**< The calendar ID: int (RecordId) */
	CALENDAR_FI_PR_ACCOUNT_ID,			/**< The account ID of calendar: int (AccountId) */
	CALENDAR_FI_PR_NAME,						/**< The name of calendar: String */
	CALENDAR_FI_PR_ITEM_TYPE				/**< The type of calendar: int (CalendarItemType) */
};

}}	// Tizen::Social

#endif // _FSCL_TYPES_H_
