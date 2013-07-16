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
* @file			FMsgDetailedEmailMessage.h
* @brief		This is the header file for the %DetailedEmailMessage class.
*
* This header file contains the declarations of the %DetailedEmailMessage class.
*/

#ifndef _FMSG_DETAILED_EMAIL_MESSAGE_H_
#define _FMSG_DETAILED_EMAIL_MESSAGE_H_

namespace Tizen { namespace Base
{
class String;
class DateTime;
namespace Collection
{
	class IList;
}
} }

#include <FMsgTypes.h>
#include <FMsgEmailAttachment.h>

namespace Tizen { namespace Messaging
{
	/**
	* @enum EmailMessageClass
	*
	* Defines the class of the email messages.
	*
	* @since		2.0
	*
	*/
	enum EmailMessageClass
	{
		EMAIL_MESSAGE_CLASS_UNSPECIFIED = 0,							/**<Unspecified	*/
		EMAIL_MESSAGE_CLASS_UNKNOWN,									/**<Unknown	*/
		EMAIL_MESSAGE_CLASS_NOTE,										/**<Normal email message	*/
		EMAIL_MESSAGE_CLASS_NOTE_RULES_OOF_TEMPLATE_MICROSOFT,			/**<Out-of-office template	*/
		EMAIL_MESSAGE_CLASS_NOTE_SMIME,									/**<The message is encrypted and can also be signed	*/
		EMAIL_MESSAGE_CLASS_NOTE_SMIME_MULTIPART_SIGNED,				/**<The message is clear signed	*/
		EMAIL_MESSAGE_CLASS_NOTIFICATION_MEETING,						/**<Meeting notification	*/
		EMAIL_MESSAGE_CLASS_OCTEL_VOICE,								/**<Octel voice message	*/
		EMAIL_MESSAGE_CLASS_SCHEDULE_MEETING_REQUEST,					/**<Meeting request	*/
		EMAIL_MESSAGE_CLASS_SCHEDULE_MEETING_CANCELLED,					/**<Meeting cancelled	*/
		EMAIL_MESSAGE_CLASS_SCHEDULE_MEETING_POSITIVE_RESPONSE,			/**<Positive meeting response	*/
		EMAIL_MESSAGE_CLASS_SCHEDULE_MEETING_TENTATIVE_RESPONSE,		/**<Tentative meeting response	*/
		EMAIL_MESSAGE_CLASS_SCHEDULE_MEETING_NEGATIVE_RESPONSE,			/**<Negative meeting response	*/
		EMAIL_MESSAGE_CLASS_POST,										/**<Post	*/
		EMAIL_MESSAGE_CLASS_INFO_PATH_FORM,								/**<An InfoPath form	*/
		EMAIL_MESSAGE_CLASS_VOICE_NOTES,								/**<Electronic voice notes	*/
		EMAIL_MESSAGE_CLASS_SHARING,									/**<Shared message	*/
		//EMAIL_MESSAGE_CLASS_NOTE_EXCHANGE_ACTIVE_SYNC_REMOTE_WIPE_CONFIRMATION,	// should be added
		EMAIL_MESSAGE_CLASS_VOICE_MAIL,									/**<Voice mail	*/
		//EMAIL_MESSAGE_CLASS_SMS,
		//EMAIL_MESSAGE_CLASS_SMART_REPLY = 0x01000000,
		//EMAIL_MESSAGE_CLASS_SMART_FORWARD = 0x02000000,
		EMAIL_MESSAGE_CLASS_REPORT_NOT_READ_REPORT = 0x10000000,		/**<Not read report for a standard message	*/
		EMAIL_MESSAGE_CLASS_REPORT_READ_REPORT = 0x20000000,			/**<Read report for a standard message	*/
		EMAIL_MESSAGE_CLASS_REPORT_NON_DELIVERY_RECEIPT = 0x40000000,	/**<Non-delivery report for a standard message	*/
		EMAIL_MESSAGE_CLASS_REPORT_DELIVERY_RECEIPT = 0x80000000		/**<Delivery receipt for a standard message	*/
	};

	/**
	* @enum EmailDigestType
	*
	* Defines the digest type of the email messages.
	*
	* @since		2.0
	*/
	enum EmailDigestType
	{
		EMAIL_DIGEST_TYPE_MD5 = 0,	/**<The MD5 type */
		EMAIL_DIGEST_TYPE_SHA1		/**<The SHA-1 type */
	};

	/**
	* @enum EmailSmimeType
	*
	* Defines the S/MIME type of the email messages.
	*
	* @since		2.0
	*/
	enum EmailSmimeType
	{
		EMAIL_SMIME_TYPE_NONE				= 0,	/**<The undefined type */
		EMAIL_SMIME_TYPE_SIGNED,					/**<The signed type */
		EMAIL_SMIME_TYPE_ENCRYPTED,					/**<The encrypted type */
		EMAIL_SMIME_TYPE_SIGNED_AND_ENCRYPTED		/**<Both signed and encrypted type */
	};

	/**
	* @enum EmailReturnReceiptType
	*
	* Defines the return receipt type for an email message.
	*
	* @since		2.0
	*/
	enum EmailReturnReceiptType
	{
		EMAIL_RETURN_RECEIPT_TYPE_NONE = 0x00,		/**<Normal Mail	*/
		EMAIL_RETURN_RECEIPT_TYPE_REQUEST = 0x03,	/**<MDN-requesting mail*/	// should be deprecated
		EMAIL_RETURN_RECEIPT_TYPE_DSN = 0x04,		/**<Delivery Status Notification (DSN - Delivery Status Mail)*/
		EMAIL_RETURN_RECEIPT_TYPE_MDN = 0x08,		/**<Message Disposition Notification (MDN - Read Status Mail)*/
		//EMAIL_RETURN_RECEIPT_TYPE_REQUEST_DSN = 0x10,
		//EMAIL_RETURN_RECEIPT_TYPE_REQUEST_MDN = 0x20,
	};

	/**
	* @enum EmailMessageBodyType
	*
	* Defines the type of an email message body.
	*
	* @since		2.0
	*/
	enum EmailMessageBodyType
	{
		EMAIL_MESSAGE_BODY_TYPE_PLAIN_TEXT = 0,	/**<The plain text type */
		EMAIL_MESSAGE_BODY_TYPE_HTML,			/**<The HTML type */
		EMAIL_MESSAGE_BODY_TYPE_MIME			/**<The MIME type */
	};


	// forward declaration
	class _DetailedEmailMessageImpl;

	/**
	* @class	DetailedEmailMessage
	* @brief	This class provides methods for handling detailed email messages.
	*
	* @since		2.0
	*
	* The %DetailedEmailMessage class provides methods for handling detailed email messages.
	*/
	class _OSP_EXPORT_ DetailedEmailMessage
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since		2.0
		*/
		DetailedEmailMessage(void);

		/**
		* This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~DetailedEmailMessage(void);

		/**
		* This is the copy constructor for the %DetailedEmailMessage class. @n
		* Copying of objects using this copy constructor is allowed.
		*
		* @since		2.0
		*
		* @param[in]	rhs		An instance of %DetailedEmailMessage
		*/
		DetailedEmailMessage(const DetailedEmailMessage& rhs);


	public:
		/**
		* Assigns the value of the specified instance to the current instance of %DetailedEmailMessage. @n
		* Copying of objects using this copy assignment operator is allowed.
		*
		* @since		2.0
		*
		* @return		The reference of this instance
		* @param[in]	rhs		An instance of %DetailedEmailMessage
		*/
		DetailedEmailMessage& operator =(const DetailedEmailMessage& rhs);

		/**
		* Compares the calling instance with the specified instance.
		*
		* @since		2.0
		*
		* @return		@c true if the specified instance of Tizen::Base::Object is equal to the calling %DetailedEmailMessage instance, @n
		*				else @c false
		* @param[in]	obj		An instance of Tizen::Base::Object to compare
		*/
		virtual bool Equals(const Tizen::Base::Object& obj) const;

		/**
		* Gets the hash value of the current instance.
		*
		* @since		2.0
		*
		* @return		The hash value of the current instance
		*/
		virtual int GetHashCode(void) const;

		// Operation
	public:
		///////////////////////////////////////////////////////////////
		// Getters
		///////////////////////////////////////////////////////////////
		/**
		* Gets the message ID.
		*
		* @since		2.0
		*
		* @return		The message ID
		* @see			SetMessageId()
		*/
		Tizen::Base::String GetMessageId(void) const;

		/**
		* Gets the subject of an email message.
		*
		* @since		2.0
		*
		* @return		The subject of an email message
		* @see			SetSubject()
		*/
		Tizen::Base::String GetSubject(void) const;

		/**
		* Gets the time when an email message is created.
		*
		* @since		2.0
		*
		* @return		The time when an email message is created
		* @remarks		The creation time may be updated by mail server when an email is sent.
		* @see			SetCreationTime()
		*/
		Tizen::Base::DateTime GetCreationTime(void) const;

		/**
		* Gets the email address of the specific recipient type.
		*
		* @since		2.0
		*
		* @return		The email address of the specific recipient type
		* @param[in]	type				The type of recipient
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @remarks		
		*				- The values for the various recipients can be a string with multiple email addresses separated by semi-colons(;).
		*				- The specified @c type contains @c RECIPIENT_TYPE_TO, @c RECIPIENT_TYPE_CC, @c RECIPIENT_TYPE_BCC.
		*				- The specific error code can be accessed using the GetLastResult() method.
		* @see			SetAddress()
		*
		*/
		Tizen::Base::String GetAddress(RecipientType type) const;

		/**
		* Gets the email address of an author.
		*
		* @since		2.0
		*
		* @return		The email address of an author
		* @see			SetFromAddress()
		*/
		Tizen::Base::String GetFromAddress(void) const;

		/**
		* Gets the email address used to reply to a message.
		*
		* @since		2.0
		*
		* @return		The email address used to reply to a message
		* @see			SetReplyToAddress()
		*/
		Tizen::Base::String GetReplyToAddress(void) const;

		/**
		* Gets the return path.
		*
		* @since		2.0
		*
		* @return		The return path
		* @see			SetReturnPath()
		*/
		Tizen::Base::String GetReturnPath(void) const;

		/**
		* Gets the file path of the specified message body type.
		*
		* @since		2.0
		*
		* @return		The file path of the message body
		* @param[in]	type				The type of message body
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			SetFilePath()
		*/
		Tizen::Base::String GetFilePath(EmailMessageBodyType type) const;

		/**
		* Gets the priority of a message.
		*
		* @since		2.0
		*
		* @return		The priority of a message
		* @see			SetPriority()
		*/
		EmailMessagePriority GetPriority(void) const;

		/**
		* Gets the return receipt type of a message.
		*
		* @since		2.0
		*
		* @return		The return receipt type of a message
		* @see			SetReturnReceiptType()
		*/
		EmailReturnReceiptType GetReturnReceiptType(void) const;

		/**
		* Gets the inline content count of a message.
		*
		* @since		2.0
		*
		* @return		The inline content count of a message
		* @see			SetInlineContentCount()
		*/
		int GetInlineContentCount(void) const;

		/**
		* Gets the class of a message.
		*
		* @since		2.0
		*
		* @return		The class of a message
		* @see			SetClass()
		*/
		EmailMessageClass GetClass(void) const;

		/**
		* Gets the digest type of a message.
		*
		* @since		2.0
		*
		* @return		The digest type of the message
		* @see			SetDigestType()
		*/
		EmailDigestType GetDigestType(void) const;

		/**
		* Gets the S/MIME type of a message.
		*
		* @since		2.0
		*
		* @return		The S/MIME type of a message
		* @see			SetSmimeType()
		*/
		EmailSmimeType GetSmimeType(void) const;

		/**
		* Gets the attachment list of this message.
		*
		* @since		2.0
		*
		* @return		A pointer to the attachment list
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @remarks		
		*				- The specific error code can be accessed using the GetLastResult() method.
		*				- After using the attachment list, you can call Tizen::Base::Collection::IList::RemoveAll(true) to clean up items in the list.
		* @see			EmailAttachment
		* @see			SetAttachmentList()
		*/
		Tizen::Base::Collection::IList* GetAttachmentListN(void);


	public:
		///////////////////////////////////////////////////////////////
		// Setters
		///////////////////////////////////////////////////////////////
		/**
		* Sets the message ID.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	messageId			The message ID
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The length of the specified @c messageId is @c 0.
		* @remarks		
		*				- The message ID is an automatically generated field.
		*				- It is used to prevent multiple delivery and for reference in In-Reply-To.
		* @see			GetMessageId()
		*/
		result SetMessageId(const Tizen::Base::String& messageId);

		/**
		* Sets the subject of an email message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	subject				The subject of the email message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The subject length of the message exceeds the maximum limit (Maximum 256 characters).
		* @see			GetSubject()
		*/
		result SetSubject(const Tizen::Base::String& subject);

		/**
		* Sets the time when an email message is created.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	dateTime			The time when the email message is created
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c dateTime is invalid. @n
		* 									The valid range of the time can be from "January 1 1900 00:00:00" to "December 31 2100 23:59:59".
		* @see			GetCreationTime()
		*/
		result SetCreationTime(const Tizen::Base::DateTime& dateTime);

		/**
		* Sets the recipient list of the specific recipient type.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The type of recipient
		* @param[in]	recipients			The recipients string
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid, or
		* 									the specified @c recipients string length is too short (< 5).
		* @remarks		
		*				- The values for the various recipients can be a string with multiple email addresses separated by semi-colons(;).
		*				- The specified @c type contains @c RECIPIENT_TYPE_TO, @c RECIPIENT_TYPE_CC, @c RECIPIENT_TYPE_BCC.
		* @see			GetAddress()
		*/
		result SetAddress(RecipientType type, const Tizen::Base::String& recipients);

		/**
		* Sets the email address of an author.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	address				The email address of the author
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c address string length is too short (< 5).
		* @see			GetFromAddress()
		*/
		result SetFromAddress(const Tizen::Base::String& address);

		/**
		* Sets the email address used to reply to a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	address				The email address used to reply to the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c address string length is too short (< 5).
		* @see			GetReplyToAddress()
		*/
		result SetReplyToAddress(const Tizen::Base::String& address);

		/**
		* Sets the return path.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	address				The return path
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c address string length is too short (< 5).
		* @see			GetReturnPath()
		*
		*/
		result SetReturnPath(const Tizen::Base::String& address);

		/**
		* Sets the file path of the specified message body type.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The type of message body
		* @param[in]	filePath			The file path of the message body
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid, or
		* 									the length of the specified @c filePath is too long or @c 0.
		* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
		* @see			GetFilePath()
		*
		*/
		result SetFilePath(EmailMessageBodyType type, const Tizen::Base::String& filePath);

		/**
		* Sets the priority of a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	priority			The priority of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c priority is invalid.
		* @see			GetPriority()
		*/
		result SetPriority(EmailMessagePriority priority);

		/**
		* Sets the return receipt type of a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The return receipt type of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @see			GetReturnReceiptType()
		*/
		result SetReturnReceiptType(EmailReturnReceiptType type);

		/**
		* Sets the inline content count of a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	count				The inline content count of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c count is less than @c 0.
		* @see			GetInlineContentCount()
		*/
		result SetInlineContentCount(int count);

		/**
		* Sets the class of a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	messageClass		The class of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c messageClass is invalid.
		* @see			GetClass()
		*/
		result SetClass(EmailMessageClass messageClass);

		/**
		* Sets the digest type of a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The digest type of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @see			GetDigestType()
		*/
		result SetDigestType(EmailDigestType type);

		/**
		* Sets the S/MIME type of a message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The S/MIME type of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @see			GetSmimeType()
		*/
		result SetSmimeType(EmailSmimeType type);

		/**
		* Sets the attachment list for this message.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	pList				A list of EmailAttachment
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The list is not made of EmailAttachment.
		* @see			EmailAttachment
		* @see			GetAttachmentListN()
		*/
		result SetAttachmentList(const Tizen::Base::Collection::IList* pList);


		///////////////////////////////////////////////////////////////
		// static methods
		///////////////////////////////////////////////////////////////
		/**
		* Parses the MIME file to %DetailedEmailMessage format.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	filePath			The MIME file path to parse
		* @param[out]	message				The parsed message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
		* @exception	E_PARSING_FAILED	The method has failed to parse the MIME file.
		* @exception	E_SYSTEM			A system error has occurred.
		* @see			WriteToMimeFile()
		*/
		static result ParseMimeFile(const Tizen::Base::String& filePath, DetailedEmailMessage& message);

		/**
		* Writes to the MIME file from %DetailedEmailMessage.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	message					The message to read
		* @param[in]	filePath				The file path of the MIME file to write
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			The value of the specified @c message is invalid. @n
		* 										(The subject, body, recipients and from address field of the message are all empty.)
		* @exception	E_ILLEGAL_ACCESS 		The specified @c filePath is inaccessible as per the Tizen platform policy.
		* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
		* @exception	E_SYSTEM				A system error has occurred.
		* @see			ParseMimeFile()
		*/
		static result WriteToMimeFile(const DetailedEmailMessage& message, const Tizen::Base::String& filePath);

	private:
		_DetailedEmailMessageImpl* __pImpl;

		// friend class
		friend class _DetailedEmailMessageImpl;
	}; // DetailedEmailMessage
} } // Tizen::Messaging

#endif // _FMSG_DETAILED_EMAIL_MESSAGE_H_
