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
 * @file	FSclAttendee.h
 * @brief	This is the header file for the %Attendee class.
 *
 * This header file contains the declarations of the %Attendee class.
 */
#ifndef _FSCL_ATTENDEE_H_
#define _FSCL_ATTENDEE_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @class	Attendee
 * @brief	This class represents the information of an attendee.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Attendee class represents the information of an attendee. The attendee details include a mandatory
 * email and an optional name. In addition, the attendee has a role and status information.
 */
class _OSP_EXPORT_ Attendee
	: public Tizen::Base::Object
{
public:
	/**
	 * Initializes this instance of %Attendee with the specified email address.
	 *
	 * @since	2.0
	 *
	 * @param[in]	email	The email address
	 */
	Attendee(const Tizen::Base::String& email);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Attendee
	 */
	Attendee(const Attendee& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Attendee(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %Attendee instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %Attendee instance, @n
	 *				else @c false
	 * @param[in]	rhs	The object instance to compare with the calling object
	 * @see			GetHashCode()
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the name of the attendee.
	 *
	 * @since	2.0
	 *
	 * @return		The name
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the email address of the attendee.
	 *
	 * @since	2.0
	 *
	 * @return		The email address
	 */
	Tizen::Base::String GetEmail(void) const;

	/**
	 * Gets the role of the attendee. @n
	 * The default value is @c #ATTENDEE_ROLE_ATTENDEE.
	 *
	 * @since	2.0
	 *
	 * @return		The role of the attendee
	 */
	AttendeeRole GetRole(void) const;

	/**
	 * Gets the status of the attendee. @n
	 * The default value is @c #ATTENDEE_STATUS_NONE.
	 *
	 * @since	2.0
	 *
	 * @return		The attendee status
	 */
	AttendeeStatus GetStatus(void) const;

	/**
	 * Sets the name.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	name			The common name of the attendee
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c name is an empty string.
	 */
	result SetName(const Tizen::Base::String& name);

	/**
	 */

	/**
	 * Sets the email address of the attendee. @n
	 * This is the identifier of an attendee.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	email			The email address
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c email is an empty string.
	 */
	result SetEmail(const Tizen::Base::String& email);

	/**
	 */

	/**
	 * Sets the role of the attendee. @n
	 * The default value is @c #ATTENDEE_ROLE_ATTENDEE.
	 *
	 * @since	2.0
	 *
	 * @param[in]	role	The role of the attendee @n
	 *						The default value is @c #ATTENDEE_ROLE_ATTENDEE.
	 */
	void SetRole(AttendeeRole role);

	/**
	 * Sets the status of the attendee. @n
	 * The default value is @c #ATTENDEE_STATUS_NONE.
	 *
	 * @since	2.0
	 *
	 * @param[in]	status	The status of the attendee @n
	 *						The default value is @c #ATTENDEE_STATUS_NONE.
	 */
	void SetStatus(AttendeeStatus status);

	/**
	 * Sets the phone number.
	 *
	 * @since	2.0
	 *
	 * @param[in]	phoneNumber		The phone number
	 */
	void SetPhoneNumber(const Tizen::Base::String& phoneNumber);

	/**
	 * Gets the phone number.
	 *
	 * @since	2.0
	 *
	 * @return		The phone number
	 */
	Tizen::Base::String GetPhoneNumber(void) const;

	/*
	 * Sets the person ID that is an identifier used for Addressbook APIs.
	 *
	 * @since	2.0
	 *
	 * @param[in]	personId		The person ID
	 */
	void SetPersonId(PersonId personId);

	/*
	 * Gets the person ID that is an identifier used for Addressbook APIs.
	 *
	 * @since	2.0
	 *
	 * @return		The person ID
	 */
	PersonId GetPersonId(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Attendee
	 */
	Attendee& operator =(const Attendee& rhs);

	/**
	 * Checks whether the data in the specified instance of %Attendee is equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance equals the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Attendee
	 */
	bool operator ==(const Attendee& rhs) const;

	/**
	 * Compares the specified instance of %Attendee with the calling instance for inequality.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Attendee
	 */
	bool operator !=(const Attendee& rhs) const;

private:
	Tizen::Base::String	__name;
	Tizen::Base::String	__email;
	Tizen::Base::String	__phoneNumber;
	AttendeeRole	__attendeeRole;
	AttendeeStatus	__attendeeStatus;
	PersonId __personId;

	friend class _AttendeeImpl;
	class _AttendeeImpl* __pAttendeeImpl;
};	// Attendee

}}	// Tizen::Social

#endif //_FSCL_ATTENDEE_H_
