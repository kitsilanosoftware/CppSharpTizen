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
* @file			FMsgEmailAttachment.h
* @brief		This is the header file for the %EmailAttachment class.
*
* This header file contains the declarations of the %EmailAttachment class.
*/

#ifndef _FMSG_EMAIL_ATTACHMENT_H_
#define _FMSG_EMAIL_ATTACHMENT_H_

namespace Tizen { namespace Base
{
class String;
} }

#include <FBaseObject.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{
	// forward declaration
	class _EmailAttachmentImpl;

	/**
	* @class	EmailAttachment
	* @brief	This class provides methods for handling email attachments.
	*
	* @since		2.0
	*
	* The %EmailAttachment class provides methods for handling email attachments.
	*/
	class _OSP_EXPORT_ EmailAttachment
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since		2.0
		*/
		EmailAttachment(void);

		/**
		* This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~EmailAttachment(void);

		/**
		* This is the copy constructor for the %EmailAttachment class. @n
		* Copying of objects using this copy constructor is allowed.
		*
		* @since		2.0
		*
		* @param[in]	rhs		An instance of %EmailAttachment
		*/
		EmailAttachment(const EmailAttachment& rhs);

	public:
		/**
		* Assigns the value of the specified instance to the current instance of %EmailAttachment. @n
		* Copying of objects using this copy assignment operator is allowed.
		*
		* @since		2.0
		*
		* @return		The reference of this instance
		* @param[in]	rhs		An instance of %EmailAttachment
		*/
		EmailAttachment& operator =(const EmailAttachment& rhs);

		/**
		* Compares the calling instance with the specified instance.
		*
		* @since		2.0
		*
		* @return		@c true if the specified instance of Tizen::Base::Object is equal to the calling %EmailAttachment instance, @n
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
		* Gets the name of an email attachment.
		*
		* @since		2.0
		*
		* @return		The name of an email attachment
		* @see			SetName()
		*/
		Tizen::Base::String GetName(void) const;

		/**
		* Gets the file path of an email attachment.
		*
		* @since		2.0
		*
		* @return		The file path of an email attachment
		* @see			SetFilePath()
		*/
		Tizen::Base::String GetFilePath(void) const;

		/**
		* Gets the size of an email attachment.
		*
		* @since		2.0
		*
		* @return		The size of an email attachment
		*/
		int GetSize(void) const;

		/**
		* Gets the inline-content status of an email attachment.
		*
		* @since		2.0
		*
		* @return		@c true if an email attachment has inline-content(s), @n
		*				else @c false
		* @see			SetInlineContentStatus()
		*/
		bool GetInlineContentStatus(void) const;

		/**
		* Gets the DRM status of an email attachment.
		*
		* @since		2.0
		*
		* @return		@c true if an email attachment contains DRM, @n
		*				else @c false
		* @see			SetDrmStatus()
		*/
		bool GetDrmStatus(void) const;

		/**
		* Gets the MIME type of an email attachment.
		*
		* @since		2.0
		*
		* @return		The MIME type of an email attachment
		* @see			SetMimeType()
		*/
		Tizen::Base::String GetMimeType(void) const;


	public:
		///////////////////////////////////////////////////////////////
		// Setters
		///////////////////////////////////////////////////////////////
		/**
		* Sets the name of an email attachment.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	name				The name of the email attachment
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The length of the name exceeds the maximum limit (Maximum 256 characters).
		* @see			GetName()
		*/
		result SetName(const Tizen::Base::String& name);

		/**
		* Sets the file path of an email attachment.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	filePath			The file path of the attachment
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The length of the specified @c filePath is too long or @c 0.
		* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
		* @see			GetFilePath()
		*/
		result SetFilePath(const Tizen::Base::String& filePath);

		/**
		* Sets the inline-content status of an email attachment.
		*
		* @since		2.0
		*
		* @param[in]	status				Set to @c true to change the inline-content status of the attachment to true, @n
		*									else @c false
		* @see			GetInlineContentStatus()
		*/
		void SetInlineContentStatus(bool status);

		/**
		* Sets the DRM status of an email attachment.
		*
		* @since		2.0
		*
		* @param[in]	status				Set to @c true to change the DRM status of the attachment to true, @n
		*									else @c false
		* @see			GetDrmStatus()
		*/
		void SetDrmStatus(bool status);

		/**
		* Sets the MIME type of an email attachment.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The MIME type of the attachment
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The length of the specified @c type is @c 0.
		* @see			GetMimeType()
		*/
		result SetMimeType(const Tizen::Base::String& type);

	private:
		_EmailAttachmentImpl* __pImpl;

		// friend class
		friend class _EmailAttachmentImpl;
	}; // EmailAttachment
} } // Tizen::Messaging

#endif // _FMSG_EMAIL_ATTACHMENT_H_
