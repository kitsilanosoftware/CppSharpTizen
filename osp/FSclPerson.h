//
// Open Service Platform
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
 * @file		FSclPerson.h
 * @brief		This is the header file for the %Person class.
 *
 * This header file contains the declarations of the %Person class.
 */
#ifndef _FSCL_PERSON_H_
#define _FSCL_PERSON_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclRecord.h>
#include <FSclTypes.h>
#include <FSclPhoneNumber.h>
#include <FSclEmail.h>

namespace Tizen { namespace Base
{
namespace Collection
{
template<typename Type>
class IListT;
}
} }

namespace Tizen { namespace Graphics
{
class Bitmap;
} }

namespace Tizen { namespace Social
{

/**
 * @class      Person
 * @brief      This class provides an aggregated contact information.
 *
 * @since	2.0
 *
 * @final      This class is not intended for extension.
 *
 * The %Person class provides an aggregated contact information of a person. @n 
 * There can be more than one contact of the same person because contacts can be synchronized from multiple service providers. @n
 * %Person has the following information of an individual. @n
 * - Display name
 * - Thumbnail
 * - Ringtone 
 * - Primary phone number
 * - Primary email
 *
 * Each information is collected from contacts linked to the person. @n
 *
 * There is no explicit way to create a person. When a contact is added, the system creates a new person and links the contact to the person.
 * It is possible to merge two persons into one or unlink a contact from a person.
 */

class _OSP_EXPORT_ Person
        : public Tizen::Base::Object
{
public:
        /**
         * This destructor overrides Tizen::Base::Object::~Object().
         *
         * @since	2.0
         */
	virtual ~Person(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return     @c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *                     else @c false
	 * @param[in]  rhs            An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return     The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the display name.
	 *
	 * @since	2.0
	 *
	 * @return     The display name
	 */
	Tizen::Base::String GetDisplayName(void) const;

	/**
	 * Checks whether this is a favorite or not.
	 *
	 * @since	2.0
	 *
	 * @return     @c true if this is a favorite, @n
	 *              else @c false
	 * @see	SetAsFavorite()
	 */
	bool IsFavorite(void) const;

	/**
	 * Gets the thumbnail path.
	 *
	 * @since	2.0
	 *
	 * @return     The file path of the thumbnail
	 * @remarks    If the thumbnail path has not been set, empty string is returned.
	 */
	Tizen::Base::String GetThumbnailPath(void) const;

	/**
	 * Gets the ringtone path.
	 *
	 * @since	2.0
	 *
	 * @return     The file path of the ringtone
	 * @remarks    If the ringtone path has not been set, empty string is returned.
	 */
	Tizen::Base::String GetRingtonePath(void) const;

	/**
	 * Checks whether this has phone numbers or not.
	 *
	 * @since	2.0
	 *
	 * @return     @c true if this has phone numbers, @n
	 *              else @c false
	 */
	bool HasPhoneNumber(void) const;

	/**
	 * Checks whether this has emails or not.
	 *
	 * @since	2.0
	 *
	 * @return     @c true if this has emails, @n
	 *              else @c false
	 */
	bool HasEmail(void) const;

	/**
	 * Gets the list of account ID of contacts linked to the person.
	 *
	 * @since	2.0
	 *
	 * @return		The account ID list
	 * @exception	E_SUCCESS              The method is successful.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IListT<AccountId>* GetAccountIdsN(void) const;

	/**
	 * Gets the ID of this person.
	 *
	 * @since	2.0
	 *
	 * @return	The person ID
	 */
	PersonId GetId(void) const;

	/**
	 * Sets whether this person is a favorite or not.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return      An error code
	 * @param[in]   isFavorite    Set to @c true to set this person as a favorite, @n
	 *                            else @c false to set this person as non-favorite
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @see IsFavorite()
	 * @see	AddressbookManager::GetFavoritePersonsN()
	 */
	result SetAsFavorite(bool isFavorite = true);


	/**
	 * Sets the specified phone number as the primary phone number of this person.
	 * The phone number must be one of the instances returned by calling Contact::GetValuesN(CONTACT_MPROPERTY_ID_PHONE_NUMBERS) on the instance of the contacts of this person.@n
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return     An error code
	 * @param[in]  phoneNumber    The phone number
	 * @exception  E_SUCCESS      The method is successful.
	 * @exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception  E_INVALID_ARG          The specified @c phoneNumber is invalid.
	 * @exception  E_SYSTEM     The method cannot proceed due to a severe system error.
	 * @see	GetPrimaryPhoneNumber()
	 *
	 * The following example demonstractes how to use %SetAsPrimaryPhoneNumber() method
	 * @code
	 * void
	 * MyApplication::SetPrimaryPhoneNumber(void)
	 * {
	 *        IList* pContacts = pAddressbookManager->GetContactsByPersonN(pPerson->GetId());
	 *        Contact* pContact = static_cast<Contact*>(pContacts->GetAt(0));
	 *        IList* pPhoneNumbers = pContact->GetValuesN(CONTACT_MPROPERTY_ID_PHONE_NUMBERS);
	 *
	 *        PhoneNumber* pPhoneNumber = static_cast<PhoneNumber*>(pPhoneNumbers->GetAt(0));
	 *
	 *        // Set the first phone number of the first contact of the person as the primary phone number
	 *        pPerson->SetAsPrimaryPhoneNumber(*pPhoneNumber);
	 *        
	 *	  pPhoneNumbers->RemoveAll(true);
	 *	  delete pPhoneNumbers;
	 *
	 *	  pContacts->RemoveAll(true);
	 *	  delete pContacts;
	 * }
	 * @endcode
	 */
	result SetAsPrimaryPhoneNumber(const PhoneNumber& phoneNumber);

	/**
	 * Sets the specified email as the primary email of this person.
	 * The email must be one of the instances returned by calling Contact::GetValuesN(CONTACT_MPROPERTY_ID_EMAILS) on the instance of the contacts of this person.@n
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return     An error code
	 * @param[in]  email          The email
	 * @exception  E_SUCCESS      The method is successful.
	 * @exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception  E_INVALID_ARG          The specified @c phoneNumber is invalid.
	 * @exception  E_SYSTEM     The method cannot proceed due to a severe system error.
	 * @see	GetPrimaryEmail()
	 * The following example demonstractes how to use %SetAsPrimaryEmail() method
	 * @code
	 * void
	 * MyApplication::SetPrimaryEmail(void)
	 * {
	 *        IList* pContacts = pAddressbookManager->GetContactsByPersonN(pPerson->GetId());
	 *        Contact* pContact = static_cast<Contact*>(pContacts->GetAt(0));
	 *        IList* pEmails = pContact->GetValuesN(CONTACT_MPROPERTY_ID_EMAILS);
	 *
	 *        Email* pEmail = static_cast<Email*>(pEmails->GetAt(0));
	 *
	 *        // Set the first email of the first contact of the person as the primary email
	 *        pPerson->SetAsPrimaryEmail(*pEmail);
	 *        
	 *	  pEmails->RemoveAll(true);
	 *	  delete pEmails;
	 *
	 *	  pContacts->RemoveAll(true);
	 *	  delete pContacts;
	 * }
	 * @endcode

	 */
	result SetAsPrimaryEmail(const Email& email);

	/**
	 * Gets the primary phone number of this person.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return	The primary phone number @n If this instance does not have the primary email, an empty PhoneNumber instance is returned.
	 * @exception  E_SUCCESS      		The method is successful.
	 * @exception  E_PRIVILEGE_DENIED      	The application does not have the privilege to call this method.
	 * @exception  E_SYSTEM     The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see SetAsPrimaryPhoneNumber()
	 */
	PhoneNumber GetPrimaryPhoneNumber(void) const;

	/**
	 * Gets the primary email of this person.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return	The primary email @n If this instance does not have the primary email, an empty Email instance is returned.
	 * @exception  E_SUCCESS      		The method is successful.
	 * @exception  E_PRIVILEGE_DENIED      	The application does not have the privilege to call this method.
	 * @exception  E_SYSTEM     The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see SetAsPrimaryEmail()
	 */
	Email GetPrimaryEmail(void) const;

private:
	/**
	 * This constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @since	2.0
	 */
	Person(void);

	/**
	 * This copy constructor is intentionally declared as private to prohibit copying of objects by users.
	 *
	 * @since	2.0
	 *
	 * @param[in]  rhs            An instance of %Person
	 */
	Person(const Person& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 *
	 * @param[in]  rhs            An instance of %Person
	 */
	Person& operator =(const Person& rhs);

private:
        friend class _PersonImpl;
        class _PersonImpl* __pPersonImpl;

        friend class _AddressbookManagerImpl;
        friend class _AddressbookUtil;
}; 	// Person

}}	// Tizen::Social

#endif // _FSCL_PERSON_H_
