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
 * @file		FSclContact.h
 * @brief		This is the header file for the %Contact class.
 *
 * This header file contains the declarations of the %Contact class.
 */
#ifndef _FSCL_CONTACT_H_
#define _FSCL_CONTACT_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseDateTime.h>
#include <FBaseColIList.h>
#include <FGrpBitmap.h>
#include <FSclTypes.h>
#include <FSclRecord.h>

namespace Tizen { namespace Social
{

class Address;
class PhoneNumber;
class Email;
class Url;
class ImAddress;
class Organization;
class ContactEvent;
class Relationship;

/**
 * @class	Contact
 * @brief	This class provides a contact.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Contact class provides a contact, a record that represents the contact information of a person. It provides the properties declared in
 * the #ContactPropertyId and #ContactMultiPropertyId enumerators. Check the descriptions for each property ID carefully to know the exact type
 * of the property and its value. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/contact.htm">Contact</a>.
 *
 * The following example demonstrates how to use the %Contact class.
 *
 * @code
 *
	#include <FSocial.h>

	using namespace Tizen::Base;
	using namespace Tizen::Base::Collection;
	using namespace Tizen::Social;

	void
	ContactExample(void)
	{
		// Creates a contact
		Contact contact;

		// Sets the contact's properties
		contact.SetValue(CONTACT_PROPERTY_ID_FIRST_NAME, L"Thomas");
		contact.SetValue(CONTACT_PROPERTY_ID_LAST_NAME, L"A Anderson");

		PhoneNumber phoneNumber(PHONENUMBER_TYPE_MOBILE, L"820223459876");
		contact.AddPhoneNumber(phoneNumber);

		// Gets the contact's properties
		String firstName, lastName;
		contact.GetValue(CONTACT_PROPERTY_ID_FIRST_NAME, firstName);
		contact.GetValue(CONTACT_PROPERTY_ID_LAST_NAME, lastName);

		IList* pPhoneNumberList = contact.GetValuesN(CONTACT_MPROPERTY_ID_PHONE_NUMBERS);
		if (pPhoneNumberList != null)
		{
			PhoneNumber* pPhoneNumber = null;
			String number;
			IEnumerator* pEnum = pPhoneNumberList->GetEnumeratorN();
			while (pEnum->MoveNext() == E_SUCCESS)
			{
				pPhoneNumber = (PhoneNumber*) pEnum->GetCurrent();
				number = pPhoneNumber->GetPhoneNumber();
				// Uses the phone number
				// ..
			}

			delete pEnum;
			pPhoneNumberList->RemoveAll(true);
			delete pPhoneNumberList;
		}
	}
 *
 * @endcode
 *
 */
class _OSP_EXPORT_ Contact
	: public Record
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Contact(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Contact
	 */
	Contact(const Contact& rhs);

	/**
	 * This destructor overrides Tizen::Social::Record::~Record().
	 *
	 * @since	2.0
	 *
	 */
	virtual ~Contact(void);

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
	 * @if OSPDEPREC
	 * Gets the @c Tizen::Graphics::Bitmap object of the thumbnail image. @n
	 * If the thumbnail is not set, @c null is returned.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated. Instead of using this method, use GetThumbnailPath()
	 * @since	2.0
	 *
	 * @return		The @c Tizen::Graphics::Bitmap object of the thumbnail image
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see	SetThumbnail()
	 * @endif
	 */
	Tizen::Graphics::Bitmap* GetThumbnailN(void) const;

	/**
	 * Gets the thumbnail path.
	 *
	 * @since	2.0
	 *
	 * @return     The file path of the thumbnail
	 * @remarks    If the thumbnail has not been set, an empty string is returned.
	 */
	Tizen::Base::String GetThumbnailPath(void) const;

	/**
	 * Sets the thumbnail image. @n
	 * If the specified @c filePath is an empty string, the current thumbnail image is removed.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	filePath		The file path of the thumbnail image
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified @c filePath exceeds system limitations.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @see	GetThumbnailPath()
	 */
	result SetThumbnail(const Tizen::Base::String& filePath);

	/**
	 * Sets the value of the property having the specified ID to the specified value.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	id			The ID of the property whose value is to set
	 * @param[in]	value			A new string value to set
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_ARG		The @c id is #CONTACT_PROPERTY_ID_DISPLAY_NAME or @if OSPDEPREC #CONTACT_PROPERTY_ID_THUMBNAIL, or @endif
	 *									the ringtone file path (value) is invalid if @c id is #CONTACT_PROPERTY_ID_RINGTONE.
	 * @remarks		
	 *		- The #CONTACT_PROPERTY_ID_DISPLAY_NAME property cannot be set. @n
	 *		- The #CONTACT_PROPERTY_ID_RINGTONE can be set to the path string of the ringtone file. @n
	 * @if OSPDEPREC
	 *		- The The #CONTACT_PROPERTY_ID_THUMBNAIL property cannot be set. @n
	 *		- In case @c id is set to #CONTACT_PROPERTY_ID_NICK_NAME, @n
	 *                         	- If this contact has nicknames, the first nickname among them is set to the @c value. @n
	 *                         	- If not, a new nickname is added to this contact. @n
	 *		- In case @c id is set to #CONTACT_PROPERTY_ID_NOTE, @n
	 *                         	- If this contact has notes, the first note among them is set to the @c value. @n
	 *                         	- If not, a new note is added to this contact. @n
	 *		- In case @c id is set to #CONTACT_PROPERTY_ID_COMPANY, @n
	 *                         	- If this contact has organizations, the name value of the first organization among them is set to the @c value. @n
	 *                         	- If not, a new organization is added to this contact. @n
	 *		- In case @c id is set to #CONTACT_PROPERTY_ID_JOB_TITLE, @n
	 *                         	- If this contact has organizations, the job title value of the first organization among them is set to the @c value. @n
	 *                         	- If not, a new organization is added to this contact. @n
	 * @endif
	 */
	result SetValue(ContactPropertyId id, const Tizen::Base::String& value);

	/**
	 */

	/**
	 * Sets the specified value for the property having the specified ID.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	id			The ID of the property whose value is to set
	 * @param[in]	value			An instance of Tizen::Base::DateTime value to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The property with the specified contact property ID is not of Tizen::Base::DateTime type, or
	 *									the property is read-only.
	 * @if OSPDEPREC
	 * @remarks    
	 *		- In case @c id is set to #CONTACT_PROPERTY_ID_BIRTHDAY, @n
	 *                         -	If this contact has events whose types are #CONTACT_EVENT_TYPE_BIRTHDAY, the date value of the first event among them is set to the @c value. @n
	 *                         -	If not, a new event whose type is #CONTACT_EVENT_TYPE_BIRTHDAY is added to this contact. @n
	 *		- In case @c id is set to #CONTACT_PROPERTY_ID_ANNIVERSARY, @n
	 *                         -	If this contact has events whose types are #CONTACT_EVENT_TYPE_ANNIVERSARY, the date value of the first event among them is set to the @c value. @n
	 *                         -	If not, a new event whose type is #CONTACT_EVENT_TYPE_ANNIVERSARY is added to this contact. @n        
	 * @endif
	 */
	result SetValue(ContactPropertyId id, const Tizen::Base::DateTime& value);

	/**
	 * Gets the value of the specified property.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	id			The property ID
	 * @param[out]	value			The property value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified contact property ID is not supported.
	 */
	result GetValue(ContactPropertyId id, Tizen::Base::String& value) const;

	/**
	 * Gets the value of the specified Tizen::Base::DateTime property such as birthday. @n
	 * If the Tizen::Base::DateTime value has not been set for the specified property, the property has value, '1899, 12, 31, 00:00:00'.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	id			The property ID
	 * @param[out]	value			The property value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified contact property ID is not supported.
	 */
	result GetValue(ContactPropertyId id, Tizen::Base::DateTime& value) const;

	/**
	 * Sets the specified phone number at the specified index.
	 *
	 * @since	2.0
	 *
	 * @return     An error code
	 * @param[in]  index          An index to set the value
	 * @param[in]  phoneNumber    An instance of PhoneNumber to set, @n
	 *                            else @c false
	 * @exception  E_SUCCESS      The method is successful.
	 * @exception  E_INVALID_ARG  The specified @c phoneNumber is empty.
	 * @exception  E_OUT_OF_RANGE The specified @c index is outside the bounds of the properties.
	 */
	result SetPhoneNumberAt(int index, const PhoneNumber& phoneNumber);

	/**
	 * Sets the specified email corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				An index to set the value
	 * @param[in]	email				An instance of Email
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c email is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetEmailAt(int index, const Email& email);

	/**
	 * Sets the specified URL corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				An index to set the value
	 * @param[in]	url					An instance of Url
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c url is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetUrlAt(int index, const Url& url);

	/**
	 * Sets the specified address corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				An index to set the value
	 * @param[in]	address				An instance of Address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c address is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetAddressAt(int index, const Address& address);

	/**
	 * Sets the specified ImAddress corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				An index to set the value
	 * @param[in]	imAddress			An instance of ImAddress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c imAddress is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetImAddressAt(int index, const ImAddress& imAddress);

	/**
	 * Sets the specified note corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	index			An index to set the value
	 * @param[in]	note			The note to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c note is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetNoteAt(int index, const Tizen::Base::String& note);

	/**
	 * Sets the specified nick name corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	index			An index to set the value
	 * @param[in]	nickname		The nick name to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c nickname is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetNicknameAt(int index, const Tizen::Base::String& nickname);

	/**
	 * Sets the specified event corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	index			An index to set the value
	 * @param[in]	event			The event to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The date of the specified @c event has not been set.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetEventAt(int index, const ContactEvent& event);

	/**
	 * Sets the specified organization corresponding to the specified index.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	index			An index to set the value
	 * @param[in]	organization		The organization to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c organization is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetOrganizationAt(int index, const Organization& organization);

	/**
	 * Sets the specified @c relationship corresponding to the specified @c index.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[in]	index			An index to set the value
	 * @param[in]	relationship		The relationship to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c relationship is empty.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result SetRelationshipAt(int index, const Relationship& relationship);

	/**
	 * Gets the addressbook ID.
	 *
	 * @since	2.0
	 *
	 * @return	The addressbook ID
	 */
	AddressbookId GetAddressbookId(void) const;

	/**
	 * Gets the person ID to which this contact is linked.
	 *
	 * @since	2.0
	 *
	 * @return	The person ID
	 */
	PersonId GetPersonId(void) const;

	/**
	 * Gets a list of the values belonging to the specific multi value property.
	 *
	 * @since	2.0
	 *
	 * @return	A list of the values belonging to the specific multi value property
	 * @param[in]	id			A property ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetValuesN(ContactMultiPropertyId id) const;

	/**
	 * Adds the specified phone number to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	phoneNumber		The phone number to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c phoneNumber is empty.
	 */
	result AddPhoneNumber(const PhoneNumber& phoneNumber);

	/**
	 * Adds the specified email to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	email		The mail address to add
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c email is empty.
	 */
	result AddEmail(const Email& email);

	/**
	 * Adds the specified URL to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	url		The URL to add
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c url is empty.
	 */
	result AddUrl(const Url& url);

	/**
	 * Adds the specified address to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	address		The address to add
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c address is empty.
	 */
	result AddAddress(const Address& address);

	/**
	 * Adds the specified instant message information to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	imAddress	The IM address to add
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c imAddress is empty.
	 */
	result AddImAddress(const ImAddress& imAddress);

	/**
	 * Adds the specified note to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	note			The note to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c note is empty.
	 */
	result AddNote(const Tizen::Base::String& note);

	/**
	 * Adds the specified nick name to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	nickname		The nick name to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c nickname is empty.
	 */
	result AddNickname(const Tizen::Base::String& nickname);

	/**
	 * Adds the specified event to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	event			The event to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The date of the specified @c event has not been set.
	 */
	result AddEvent(const ContactEvent& event);

	/**
	 * Adds the specified organization to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	organization		The organization to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c organization is empty.
	 */
	result AddOrganization(const Organization& organization);

	/**
	 * Adds the specified relationship to the contact.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	relationship		The relationship to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c organization is empty.
	 */
	result AddRelationship(const Relationship& relationship);


	/**
	 * Removes the specific value at the specified index of the multi value property.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	id			A property ID
	 * @param[in]	index			The index of the value to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the properties.
	 */
	result RemoveAt(ContactMultiPropertyId id, int index);

	/**
	 * Checks whether this contact is a favorite or not.
	 *
	 * @since	2.1
	 *
	 * @return     @c true if this contact is a favorite, @n
	 *              else @c false
	 * @see	SetAsFavorite()
	 */
	bool IsFavorite(void) const;

	/**
	 * Sets whether this contact is a favorite or not.
	 *
	 * @since	2.1
	 * @see IsFavorite()
	 */
	void SetAsFavorite(bool isFavorite = true);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Contact
	 */
	Contact& operator =(const Contact& rhs);

private:
	friend class _ContactImpl;
	class _ContactImpl* __pContactImpl;

}; // Contact

}} // Tizen::Social

#endif // _FSCL_CONTACT_H_
