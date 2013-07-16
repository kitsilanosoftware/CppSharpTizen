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
 * @file		FSclPhoneNumberContact.h
 * @brief		This is the header file for the %PhoneNumberContact class.
 *
 * This header file contains the declarations of the %PhoneNumberContact class.
 */
#ifndef _FSCL_PHONE_NUMBER_CONTACT_H_
#define _FSCL_PHONE_NUMBER_CONTACT_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>
#include <FSclPhoneNumber.h>

namespace Tizen { namespace Social
{
 /**
 * @class	PhoneNumberContact
 * @brief	This class provides summarized contact information with phone number.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %PhoneNumberContact class provides summarized contact information. @n
 * This provides part of contact information - ID, person ID, addressbook ID, display name, ringtone, thumbnail, and phone number.
 */
class _OSP_EXPORT_ PhoneNumberContact
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	PhoneNumberContact(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %PhoneNumberContact
	 */
	PhoneNumberContact(const PhoneNumberContact& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~PhoneNumberContact(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the addressbook ID.
	 *
	 * @since	2.0
	 *
	 * @return	The addressbook ID
	 */
	AddressbookId GetAddressbookId(void) const;

	/**
	 * Gets the person ID.
	 *
	 * @since	2.0
	 *
	 * @return	The person ID
	 */
	PersonId GetPersonId(void) const;

	/**
	 * Gets the contact ID.
	 *
	 * @since	2.0
	 *
	 * @return	The contact ID
	 */
	RecordId GetContactId(void) const;

	/**
	 * Gets the display name.
	 *
	 * @since	2.0
	 *
	 * @return	The display name
	 */
	Tizen::Base::String GetDisplayName(void) const;

        /**
         * Gets the ringtone path.
         *
         * @since	2.0
         *
         * @return      The ringtone path, @n
		 *              else an empty string if the ringtone path has not been set for this contact
         */
	Tizen::Base::String GetRingtonePath(void) const;

	/**
         * Gets the thumbnail path.
         *
         * @since	2.0
         *
         * @return      The thumbnail path, @n
		 *              else an empty string if the thumbnail path has not been set for this contact
         */
	Tizen::Base::String GetThumbnailPath(void) const;

	/**
	 * Gets the phone number.
	 *
	 * @since	2.0
	 *
	 * @return      A PhoneNumber instance
	 */
	PhoneNumber GetPhoneNumber(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %PhoneNumberContact
	 */
	PhoneNumberContact& operator =(const PhoneNumberContact& rhs);

private:
	friend class _PhoneNumberContactImpl;
	class _PhoneNumberContactImpl* __pPhoneNumberContactImpl;

};	// PhoneNumberContact

}}	// Tizen::Social

#endif // _FSCL_PHONE_NUMBER_CONTACT_H_
