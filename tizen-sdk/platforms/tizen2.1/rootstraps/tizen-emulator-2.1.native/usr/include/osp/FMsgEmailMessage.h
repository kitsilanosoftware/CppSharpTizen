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
 * @file		FMsgEmailMessage.h
 * @brief		This is the header file for the %EmailMessage class.
 *
 * This header file contains the declarations of the %EmailMessage class.
 */

#ifndef _FMSG_EMAIL_MESSAGE_H_
#define _FMSG_EMAIL_MESSAGE_H_

#include <FBase.h>

namespace Tizen { namespace Messaging
{
	class _EmailMessageImpl;

	/**
	* @class	EmailMessage
	* @brief	This class provides methods for handling email messages.
	*
	* @since		2.0
	*
	* The %EmailMessage class provides methods for handling email messages.
	* It allows you to set the subject and body text of an email message,
	* and add or remove the files sent as email attachments.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _OSP_EXPORT_ EmailMessage
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since		2.0
		*/
		EmailMessage(void);

		/**
		* This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~EmailMessage(void);

		/**
		* This is the copy constructor for the %EmailMessage class.
		*
		* @since		2.0
		*
		* @param[in]	value	An instance of %EmailMessage
		*/
		EmailMessage(const EmailMessage& value);


	public:
		/**
		* This assignment operator copies an email message from the specified instance of %EmailMessage to the calling instance of %EmailMessage.
		*
		* @since		2.0
		*
		* @return			The reference of this instance
		* @param[in]	rhs		A reference to the %EmailMessage instance to copy
		*/
		EmailMessage& operator =(const EmailMessage& rhs);

		/**
		* Compares the calling instance with the specified instance.
		*
		* @since		2.0
		*
		* @return			@c true if the specified instance of Tizen::Base::Object is equal to the calling %EmailMessage instance, @n
		*						else @c false
		* @param[in]		obj		The object to compare
		*/
		virtual bool Equals(const Tizen::Base::Object& obj) const;

		/**
		* Gets the hash value of the current instance.
		*
		* @since		2.0
		*
		* @return			The hash value of the current instance
		*/
		virtual int GetHashCode(void) const;

		// Operation
	public:
		/**
		* Sets the subject of the email.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	subject				The subject of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The subject length of the message exceeds the maximum limit (Maximum 256 characters),
	    *                                   	or the total size of the subject, body, and attachment(s) exceeds the maximum limit (5MB).
		* @see			GetSubject()
		*/
		result SetSubject(const Tizen::Base::String& subject);

		/**
		* Sets the body of the message.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	text				The body of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The body length of the message exceeds the maximum limit (Maximum 2000 characters),
		*                                   or the total size of the subject, body, and attachment(s) exceeds the maximum limit (5MB).
		* @see			GetText()
		*/
		result SetText(const Tizen::Base::String& text);
		/**
		* Adds a file attachment to the email.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	filePath				The path of the file to attach
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			The length of the specified @c filePath is too long or @c 0.
		* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
		* @exception	E_FILE_ALREADY_EXIST	The file is already attached.
		* @exception	E_MAX_EXCEEDED			The total size of the subject, body, and attachment(s) exceeds the maximum limit (5MB), or
        *                                       the number of attachments exceeds the limit (20 files). @n
        *                                       The total size of attachments must not exceed 5MB, and the total number of attached files must not exceed 20 files.
		* @see			GetAttachmentListN()
		*/
		result AddAttachment(const Tizen::Base::String& filePath);


		/**
		* Removes an attachment from an email.
		* 
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	filePath				The path of the file to remove
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_FILE_NOT_FOUND		The corresponding format file is not found.
		* @see			AddAttachment()
		* @see			GetAttachmentListN()
		*/
		result RemoveAttachment(const Tizen::Base::String& filePath);

		/**
		* Gets the subject of the message.
		*
		* @since		2.0
		*
		* @return		The subject of the message
		* @see			SetSubject()
		*/
		Tizen::Base::String GetSubject(void) const;

		/**
		* Gets the body of the message.
		*
		* @since		2.0
		*
		* @return		The body of the message
		* @see			SetText()
		*/
		Tizen::Base::String GetText(void) const;

		/**
		* Gets the list of attachments for the email.
		*
		* @since		2.0
		*
		* @return			The list of the attached files
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			AddAttachment()
		*/
		Tizen::Base::Collection::IList* GetAttachmentListN(void) const;

	private:
		_EmailMessageImpl* __pImpl;

		// friend class
		friend class _EmailMessageImpl;
	}; // EmailMessage
} } // Tizen::Messaging

#endif // _FMSG_EMAIL_MESSAGE_H_
