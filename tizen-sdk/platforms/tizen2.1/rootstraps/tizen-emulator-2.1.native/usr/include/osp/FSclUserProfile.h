//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
* @file                FSclUserProfile.h
* @brief               This is the header file for the %UserProfile class.
*
* This header file contains the declarations of the %UserProfile class.
*/
#ifndef _FSCL_USER_PROFILE_H_
#define _FSCL_USER_PROFILE_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;

namespace Collection
{
class IList;
}
}}

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
 * @class       UserProfile
 * @brief       This class represents the user’s contact information.
 *
 * @since       2.1
 *
 * @final       This class is not intended for extension.
 *
 * The %UserProfile class provides the contact information of the owner of an addressbook.
 *
 *
 */
class _OSP_EXPORT_ UserProfile
        : public Tizen::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.1
	 */
	UserProfile(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since       2.1
	 *
	 * @param[in]   rhs             An instance of %UserProfile
	 */
    UserProfile(const UserProfile& rhs);

	/**
	 * This destructor overrides Tizen::Social::Object::~Object().
	 *
	 * @since       2.1
	 *
	 */
	virtual ~UserProfile(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since       2.1
	 *
	 * @return      @c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *              else @c false
	 * @param[in]   rhs             An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since       2.1
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the thumbnail file path.
	 *
	 * @since       2.1
	 *
	 * @return     The file path of a thumbnail
	 * @remarks    If the thumbnail has not been set, an empty string is returned.
	 */
	Tizen::Base::String GetThumbnailPath(void) const;

	/**
	 * Sets the thumbnail image. @n
	 * If the specified @c filePath is an empty string, the current thumbnail image is removed.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   filePath                The file path of the thumbnail image
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The length of the specified @c filePath exceeds system limitations.
	 * @exception   E_FILE_NOT_FOUND        The specified file cannot be found or accessed.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 * @see GetThumbnailPath()
	 */
	result SetThumbnail(const Tizen::Base::String& filePath);

	/**
	 * Sets the value of the property having a specified ID to the specified @c value.
	 *
	 *
	 * @return      An error code
	 * @param[in]   id                      The ID of the property whose value is set
	 * @param[in]   value                   A new string value to set
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified property is read-only.
	 */

	result SetValue(UserProfilePropertyId id, const Tizen::Base::String& value);

	/**
	 * Gets the value of a specified property.
	 *
	 * @since       2.1
	 *
	 * @return      The property value
	 * @param[in]   id                              The property ID
	 */
	Tizen::Base::String GetValue(UserProfilePropertyId id) const;

	/**
	 * Sets a specified phone number at the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return     An error code
	 * @param[in]  index          	An index at which the value is set
	 * @param[in]  phoneNumber    	An instance of PhoneNumber to set
	 * @exception  E_SUCCESS      	The method is successful.
	 * @exception  E_INVALID_ARG  	The specified @c phoneNumber is empty.
	 * @exception  E_OUT_OF_RANGE 	The specified @c index is outside the bounds of the properties.
	 */
	result SetPhoneNumberAt(int index, const PhoneNumber& phoneNumber);

	/**
	 * Sets the specified @c email corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   email                   An instance of Email
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c email is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetEmailAt(int index, const Email& email);

	/**
	 * Sets a specified URL corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   url                     An instance of Url
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c url is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetUrlAt(int index, const Url& url);

	/**
	 * Sets the specified @c address corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   address                 An instance of Address
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c address is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetAddressAt(int index, const Address& address);

	/**
	 * Sets the specified @c imAddress corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   imAddress               An instance of ImAddress
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c imAddress is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetImAddressAt(int index, const ImAddress& imAddress);

	/**
	 * Sets the specified @c note corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   note                    The note to set
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c note is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetNoteAt(int index, const Tizen::Base::String& note);

	/**
	 * Sets a specified nick name corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   nickname                The nick name to set
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetNicknameAt(int index, const Tizen::Base::String& nickname);

	/**
	 * Sets the specified @c event corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   event                   The event to set
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c event is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetEventAt(int index, const ContactEvent& event);

	/**
	 * Sets the specified organization corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   index                   An index at which the value is set
	 * @param[in]   organization            The organization to set
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c organization is empty.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result SetOrganizationAt(int index, const Organization& organization);

	/**
	 * Sets the specified @c relationship corresponding to the specified @c index.
	 *
	 * @since       2.1
	 *
	 * @return     An error code
	 * @param[in]  index          	An index at which the value is set
	 * @param[in]  relationship    	An instance of Relationship to set
	 * @exception  E_SUCCESS      	The method is successful.
	 * @exception  E_INVALID_ARG  	The specified @c relationship is empty.
	 * @exception  E_OUT_OF_RANGE 	The specified @c index is outside the bounds of the properties.
	 */
	result SetRelationshipAt(int index, const Relationship& relationship);

	/**
	 * Gets the addressbook ID.
	 *
	 * @since       2.1
	 *
	 * @return      The addressbook ID
	 */
	AddressbookId GetAddressbookId(void) const;

	/**
	 * Gets a list of the values belonging to a specific multi value property.
	 *
	 * @since       2.1
	 *
	 * @return      A list of the values belonging to the specific multi value property
	 * @param[in]   id                      A property ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception 	E_OUT_OF_MEMORY         The memory is insufficient.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetValuesN(UserProfileMultiPropertyId id) const;

	/**
	 * Adds a specified phone number to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   phoneNumber             The phone number to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c phoneNumber is empty.
	 */
	result AddPhoneNumber(const PhoneNumber& phoneNumber);

	/**
	 * Adds the specified @c email to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   email           The email address to add
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c email is empty.
	 */
	result AddEmail(const Email& email);

	/**
	 * Adds a specified URL to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   url             The URL to add
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c url is empty.
	 */

	result AddUrl(const Url& url);

	/**
	 * Adds the specified @c address to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   address         The address to add
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c address is empty.
	 */
	result AddAddress(const Address& address);

	/**
	 * Adds a specified instant message information to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   imAddress       The IM address to add
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c imAddress is empty.
	 */
	result AddImAddress(const ImAddress& imAddress);

	/**
	 * Adds the specified @c note to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   note                    The note to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c note is empty.
	 */
	result AddNote(const Tizen::Base::String& note);

	/**
	 * Adds a specified nick name to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   nickname                The nick name to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c nickname is empty.
	 */
	result AddNickname(const Tizen::Base::String& nickname);

	/**
	 * Adds the specified @c event to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   event                   The event to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c event is empty.
	 */
	result AddEvent(const ContactEvent& event);

	/**
	 * Adds the specified @c organization to a contact.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   organization            The organization to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c organization is empty.
	 */
	result AddOrganization(const Organization& organization);

	/**
	 * Adds the specified @c relationship to the user profile.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   relationship            The relationship to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c relationship is empty.
	 */
	result AddRelationship(const Relationship& relationship);

	/**
	 * Removes a specific value at the specified @c index of a multi value property.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   id                      A property ID
	 * @param[in]   index                   The index at which the value is removed
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The specified @c index is outside the bounds of the properties.
	 */
	result RemoveAt(UserProfileMultiPropertyId id, int index);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since       2.1
	 *
	 * @param[in]   rhs             An instance of %UserProfile
	 */
	UserProfile& operator =(const UserProfile& rhs);

private:
	friend class _UserProfileImpl;
	class _UserProfileImpl* __pUserProfileImpl;

}; // UserProfile

}} // Tizen::Social

#endif // _FSCL_USER_PROFILE_H_
