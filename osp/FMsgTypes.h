//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file		FMsgTypes.h
 * @brief		This is the header file for the enumerations of the Messaging namespace.
 *
 * This header file contains the type declarations of the Messaging namespace.
 */

#ifndef _FMSG_TYPES_H_
#define _FMSG_TYPES_H_

namespace Tizen { namespace Messaging
{
	/**
	* @enum RecipientType
	*
	* Defines the recipient type for a Short Message Service(SMS), Multimedia %Messaging Service(MMS), and email messages.
	*
	* @since		2.0
	*/
	enum RecipientType
	{
		RECIPIENT_TYPE_TO = 0,          /**<The recipient is in 'To' list */
		RECIPIENT_TYPE_CC,              /**<The recipient is in 'Cc' list */
		RECIPIENT_TYPE_BCC              /**<The recipient is in 'Bcc' list */
	};

	/**
	* @enum AddressType
	*
	* Defines the type of an address. @n
	* All recipient addresses must be either in a phone or an email format.
	*
	* @since		2.0
	*/
	enum AddressType
	{
		ADDRESS_TYPE_PHONE = 0,         /**<The phone number type*/
		ADDRESS_TYPE_EMAIL              /**<The email type*/
	};

	/**
	* @enum MmsAttachmentFormat
	*
	* Defines the attachment type for Multimedia %Messaging Service (MMS) messages.
	*
	* @since		2.0
	*/
	enum MmsAttachmentFormat
	{
		MMS_IMAGE = 0,		/**< The image type */
		MMS_AUDIO,			/**< The audio type */
		MMS_VIDEO,			/**< The video type */
		MMS_VCARD,			/**< The vCard type */
		MMS_VCALENDAR		/**< The vCalendar type */
	};

	/**
	* @enum SmsMessageBoxType
	*
	* Defines the message box type for Short Message Service(SMS) messages.
	*
	* @since		2.0
	*/
	enum SmsMessageBoxType
	{
		SMS_MESSAGE_BOX_TYPE_NONE = -1,         /**< None */
		SMS_MESSAGE_BOX_TYPE_INBOX = 0,         /**< The Inbox type */
		SMS_MESSAGE_BOX_TYPE_SENTBOX = 1,       /**< The Sentbox type */
		SMS_MESSAGE_BOX_TYPE_OUTBOX = 2,        /**< The Outbox type */
		SMS_MESSAGE_BOX_TYPE_ALL = 10           /**< All message box type */
	};

	/**
	* @enum EmailMessagePriority
	*
	* Defines the priority level for an email.
	*
	* @since		2.0
	*/
	enum EmailMessagePriority
	{
		EMAIL_MESSAGE_PRIORITY_HIGH = 1,	/**< High priority */
		EMAIL_MESSAGE_PRIORITY_NORMAL = 3,	/**< Normal priority */
		EMAIL_MESSAGE_PRIORITY_LOW = 5		/**< Low priority */
	};

	/**
	* @enum    PushAction
	*
	* Defines the push action. @n
	* This action is performed when the application is not running.
	*
	* @since		2.0
	*/
	enum PushAction
	{
		PUSH_ACTION_SILENT = 0,		/**< Store the message without alerting the user */
		PUSH_ACTION_DISCARD,		/**< Discard the message */
		PUSH_ACTION_ALERT,			/**< Store the message and alert the user */
		PUSH_ACTION_LAUNCH          /**< Launch the application @b Since: @b 2.1 */
	};

} } // Tizen::Messaging

#endif  // _FMSG_TYPES_H_
