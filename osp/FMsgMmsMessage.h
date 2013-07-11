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
 * @file		FMsgMmsMessage.h
 * @brief		This is the header file for the %MmsMessage class.
 *
 * This header file contains the declarations of the %MmsMessage class.
 */

#ifndef _FMSG_MMS_MESSAGE_H_
#define _FMSG_MMS_MESSAGE_H_

// Includes
#include <FBase.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{

	// forward declaration
	class _MmsMessageImpl;
	/**
	* @class	MmsMessage
	* @brief	This class provides methods for handling an MMS message.
	*
	* @since		2.0
	*
	* The %MmsMessage class provides methods for handling MMS messages. It allows you to set
	* the subject and body text of an MMS message, and add or remove the files sent as MMS attachments.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _OSP_EXPORT_ MmsMessage
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		*	This is the default constructor for this class.
		*
		* @since		2.0
		*/
		MmsMessage(void);

		/**
		*	This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~MmsMessage(void);

		/**
		* This is the copy constructor for the %MmsMessage class.
		*
		* @since		2.0
		*
		* @param[in]	value	An instance of %MmsMessage
		*/
		MmsMessage(const MmsMessage& value);

		/**
		* This assignment operator copies an MMS message from the specified instance of %MmsMessage to the calling instance of %MmsMessage.
		*
		* @since		2.0
		*
		* @return		A reference to the %MmsMessage instance
		* @param[in]	rhs		A reference to the %MmsMessage instance to be copied
		*/
		MmsMessage& operator =(const MmsMessage& rhs);

		/**
		* Compares the calling instance with the specified instance.
		*
		* @since		2.0
		*
		* @return			@c true if the specified instance of Object is equal to the calling %MmsMessage instance, @n
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
		* Sets the subject of the MMS message.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	subject				The subject of the MMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The subject length of the message exceeds the maximum limit (Maximum 40 characters). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetSubject()
		*/
		result SetSubject(const Tizen::Base::String& subject);

		/**
		* Sets the body of the MMS message.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	text				The body of the MMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The body length of the message exceeds the maximum limit (Maximum 1000 characters). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetText()
		*/
		result SetText(const Tizen::Base::String& text);

		/**
		* Adds the attachment of the specific type.
		*
		* @if OSPCOMPAT
		* @brief <i> [Compatibility] </i>
		* @endif
		* @since		2.0
		* @if OSPCOMPAT
		* @compatibility	This method has compatibility issues with OSP compatible applications. @n
		*					For more information, see @ref CompIoPathPage "here".
		* @endif
		*
		* @return		An error code
		* @param[in]	format				The format of the attachment
		* @param[in]	filePath			The path of the file to attach
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
		* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
		*									- The length of the specified @c filePath is too long or @c 0. @n
		* 									- The specified file format is already attached. @n
		* 									- The specified @c format is invalid. @n
		* 									- The specified file contains invalid or the media is not supported. @n
		* 									- The specified file format cannot be attached.@n
		* 									(An MMS attachment may contain either an image, audio, video, vCard, or a vCalendar file or a combination of an image, audio, vCard, and vCalendar file. @n
		* 									MMS attachments cannot contain a video file in combination with an image or audio file.)
		* @exception	E_MAX_EXCEEDED		The size of the file exceeds the maximum limit (Maximum 295KB). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetAttachment()
		*/
		result AddAttachment(MmsAttachmentFormat format, const Tizen::Base::String& filePath);

		/**
		* Gets the subject of the MMS message.
		*
		* @since		2.0
		*
		* @return		The subject of the MMS message
		* @see			SetSubject()
		*/
		Tizen::Base::String GetSubject(void) const;

		/**
		* Gets the body of the MMS message.
		*
		* @since		2.0
		*
		* @return		The body of the MMS message
		* @see			SetText()
		*/
		Tizen::Base::String GetText(void) const;

		/**
		* Gets the attachment file of the specific type.
		*
		* @since		2.0
		*
		* @return			The path of the attached file
		* @param[in]	format					The format of the attachment
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_CONDITION		The file is not attached.
		* @exception	E_INVALID_ARG			The specified @c format is invalid.
		* @remarks  	The specific error code can be accessed using the GetLastResult() method.
		* @see			AddAttachment()
		*/
		Tizen::Base::String GetAttachment(MmsAttachmentFormat format) const;

		/**
		* Removes the attachment of the specific type.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	format					The format of the attachment to remove
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_FILE_NOT_FOUND		The corresponding format file is not found.
		* @exception	E_INVALID_ARG			The specified @c format is invalid.
		* @see			AddAttachment()
        * @see  		GetAttachment()
		*/
		result RemoveAttachment(MmsAttachmentFormat format);

	private:
		_MmsMessageImpl* __pImpl;

		// friend class
		friend class _MmsMessageImpl;
	}; // MmsMessage
} } // Tizen::Messaging

#endif // _FMSG_MMS_MESSAGE_H_
