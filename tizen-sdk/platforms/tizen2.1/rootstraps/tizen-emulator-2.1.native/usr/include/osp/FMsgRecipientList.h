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
 * @file		FMsgRecipientList.h
 * @brief		This is the header file for the %RecipientList class.
 *
 * This header file contains the declarations of the %RecipientList class.
 */

#ifndef _FMSG_RECIPIENT_LIST_H_
#define _FMSG_RECIPIENT_LIST_H_

// Includes
#include <FBase.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{

	// forward declaration
	class _RecipientListImpl;
	/**
	* @class		RecipientList
	* @brief		This class provides the abstract data type and methods for handling recipients.
	*
	* @since		2.0
	*
	* The %RecipientList class provides methods for handling message recipients. It allows you to add, remove, set,
	* and get the list of recipients. A recipient is an email address for an email message and a telephone number
    * for an SMS or MMS message.
	*
	* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.

	*/
	class _OSP_EXPORT_ RecipientList
		: public Tizen::Base::Object
	{
		// Life cycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since		2.0
		*/
		RecipientList(void);

		/**
		* This is the copy constructor for the %RecipientList class.
		*
		* @since		2.0
		*
		* @param[in]	value	An instance of %RecipientList
		*/
		RecipientList(const RecipientList& value);

		/**
		*	This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~RecipientList(void);

		//Operator
	public:
		/**
		* This is the assignment operator for this class. @n
		* Copies the recipient list from the specified instance of %RecipientList to the calling instance of %RecipientList.
		*
		* @since		2.0
		*
		* @param[in]	rhs		A reference to the %RecipientList instance
		*/
		RecipientList& operator =(const RecipientList& rhs);

		/**
		* This operator compares the two recipient lists.
		*
		* @since		2.0
		*
		* @return		@c true if both instances are equal, @n
		*					else @c false
		* @param[in]	rhs		A reference to the %RecipientList instance on the right-hand side of the operator
		*/
		bool operator ==(const RecipientList& rhs) const;

		/**
		* This operator compares the specified instance with the calling instance for inequality.
		*
		* @since		2.0
		*
		* @return		@c true if both instances are not equal, @n
		*					else @c false
		* @param[in]	rhs	 A reference to the %RecipientList instance on the right-hand side of the operator
		*/
		bool operator !=(const RecipientList& rhs) const;

		/**
		* Gets the hash value of the current instance.
		*
		* @since		2.0
		*
		* @return		The hash value of the current instance
		* @remarks 		
		*				- Two equal instances should return the same hash value.
		*				- For better performance, the used hash function must generate a random distribution for all inputs.
		*/
		virtual int GetHashCode(void) const;

		// Operation
	public:
		/**
		* Compares the specified instance with the calling instance.
		*
		* @since		2.0
		*
		* @return		@c true if both instances are equal, @n
		*				else @c false
		* @param[in]	value		An instance of %RecipientList
		*/
		virtual bool Equals(const Tizen::Base::Object& value) const;

		/**
		* Adds a recipient string.
		*
		* @since		2.0
		*
		* @return		An error code
		* @param[in]	type				The type of recipient
		* @param[in]	recipient			The recipient string
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_OBJ_ALREADY_EXIST	The specified @c recipient is already added.
		* @exception	E_INVALID_ARG		The specified @c recipient string length is too short (< 3) or too long (> 320), or
		* 									the specified @c type is invalid.
		* @remarks		
		*				- The limit of the number of recipients is not checked in this method. This is done in the SmsManager::Send(), 
		*				MmsManager::Send(), and EmailManager::Send() methods.
		* 				- The minimum length of a recipient is @c 3 for a phone number and @c 5 for an email address.
		* 				- The maximum length of a recipient is @c 41 for a phone number and @c 320 for an email address.
		* @see			Set()
        * @see  		GetListN()
        * @see  		SmsManager::Send()
        * @see  		MmsManager::Send()
        * @see  		EmailManager::Send()
		*/
		result Add(RecipientType type, const Tizen::Base::String& recipient);

		/**
		* Removes the recipient.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	type			The type of recipient
		* @param[in]	recipient		The recipient string
		* @exception	E_SUCCESS		The method is successful.
		* @exception	E_INVALID_ARG	The specified @c recipient string length is too short (< 3) or too long (> 320), or
		* 								the specified @c type is invalid.
		* @exception	E_OBJ_NOT_FOUND	The specified @c recipient does not exist.
		* @see			Add()
		*/
		result Remove(RecipientType type, const Tizen::Base::String& recipient);


		/**
		* Sets a recipient list.
		*
		* @since		2.0
		*
		* @return			An error code
		* @param[in]	type				The type of recipient
		* @param[in]	list				A list of recipient strings
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The length of one of the recipients in the list is too short (< 3) or too long (> 320), or
		* 									the specified @c type is invalid.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_OBJ_ALREADY_EXIST	A duplicate recipient in the recipient list already exists.
		* @remarks		
		*				- The limit of recipients is not checked in this method.
		*				- This is done in the SmsManager::Send(), MmsManager::Send(), and EmailManager::Send() methods.
		* @see			Add()
		* @see			GetListN()
		*/
		result Set(RecipientType type, const Tizen::Base::Collection::IList& list);

		/**
		* Gets the recipient list of the specific recipient type.
		*
		* @since		2.0
		*
		* @return			A pointer to the list of recipient type
		* @param[in]	type				The type of recipient
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @remarks		
		*				- The recipient is an email address for an email message or a telephone number for an SMS or MMS message.
		* 				- The specified @c type contains @c RECIPIENT_TYPE_TO, @c RECIPIENT_TYPE_CC, @c RECIPIENT_TYPE_BCC. @n
		* 				- The specific error code can be accessed using the GetLastResult() method.
		* @see			Add()
        * @see  		Set()
		*/
		Tizen::Base::Collection::IList* GetListN(RecipientType type) const;

	private:
		_RecipientListImpl* __pImpl;

		// friend class
		friend class _RecipientListImpl;
	}; // RecipientList

} } // Tizen::Messaging

#endif // _FMSG_RECIPIENT_LIST_H_
