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
* @file		FSclAddressbook.h
* @brief	This is the header file for the %Addressbook class.
*
* This header file contains the declarations of the %Addressbook class.
*/

#ifndef _FSCL_ADDRESSBOOK_H_
#define _FSCL_ADDRESSBOOK_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FSclRecord.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;
namespace Collection
{
class IList;
template<class Type> class IListT;
}
}}

namespace Tizen { namespace Social
{
class Category;
class Contact;
class UserProfile;
class IRecordEventListener;
class IAddressbookEventListener;
class IAddressbookChangeEventListener;
class IRecordEventListener;

/**
 * @class	Addressbook
 * @brief	This class handles the address book database.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Addressbook class handles the %Addressbook database, which is a centralized database used by multiple applications to store a subset of the contact information.
 * It also supports the categorizing of the contacts.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/addressbook_namespace.htm">Address Book</a>.
 *
 * The following example demonstrates how to use the %Addressbook class to create the categories and add contacts to them.
 *
 * @code
 *
	#include <FSocial.h>

	using namespace Tizen::Social;
	using namespace Tizen::Base;

	void
	AddressbookExample::CreateExample(void)
	{
		result r = E_SUCCESS;

		// Get default addressbook instance
		Addressbook* pAddressbook = AddressbookManager::GetInstance()->GetAddressbookN();

		// Creates and constructs a contact
		Contact contact;

		// Sets the contact's properties: first name and last name
		contact.SetValue(CONTACT_PROPERTY_ID_FIRST_NAME , L"Thomas");
		contact.SetValue(CONTACT_PROPERTY_ID_LAST_NAME , L"Anderson");

		// Sets the contact's properties: add a phone number
		PhoneNumber phoneNumber(PHONENUMBER_TYPE_MOBILE, L"820223459876");
		contact.AddPhoneNumber(phoneNumber);

		// Sets the contact's properties: add an address
		Address address;
		address.SetCountry(L"KOR");
		address.SetCity(L"Seoul");
		contact.AddAddress(address);

		// Adds the contact to the address book (when it is added, the recordId is created)
		r = pAddressbook->AddContact(contact);
		if (IsFailed(r))
		{
			AppLogException( "Fails to add a contact");

			delete pAddressbook;
			return;
		}

		// Creates and constructs a category ("Friends")
		Category category;
		category.SetName(L"Friends");


		// Adds the category to the address book
		r = pAddressbook->AddCategory(category);
		if (IsFailed(r))
		{
			delete pAddressbook;
			return;
		}

		// Adds the contact to the category
		r = pAddressbook->AddMemberToCategory(category.GetRecordId(), contact.GetRecordId());
		if (IsFailed(r))
		{
			delete pAddressbook;
			return;
		}

		delete pAddressbook;
	}
 *
 * @endcode
 *
 * The following example demonstrates how to use the %Addressbook class to retrieve the contacts associated with each category.
 * @code
 *
	#include <FSocial.h>

	using namespace Tizen::Base;
	using namespace Tizen::Base::Collection;
	using namespace Tizen::Social;

	void
	AddressbookExample::GetContactsExample(void)
	{
		result r = E_SUCCESS;

		// Get default addressbook instance
		Addressbook* pAddressbook = AddressbookManager::GetInstance()->GetAddressbookN();

		// Gets all the categories.
		IList* pCategoryList = pAddressbook->GetAllCategoriesN();
		if (pCategoryList == null)
		{
			delete pAddressbook;
			return;
		}

		Category* pCategory = null;
		Contact* pContact = null;
		IList* pContactList = null;
		IEnumerator* pContactEnum = null;
		String firstName;
		String lastName;
		IEnumerator* pCategoryEnum = pCategoryList->GetEnumeratorN();
		while (pCategoryEnum->MoveNext() == E_SUCCESS)
		{
			pCategory = static_cast<Category*>(pCategoryEnum->GetCurrent());

			// Gets all the contacts of each category.
			pContactList = pAddressbook->GetContactsByCategoryN(pCategory->GetRecordId());
			if (pContactList == null)
			{
				continue;
			}

			pContactEnum = pContactList->GetEnumeratorN();
			while (pContactEnum->MoveNext() == E_SUCCESS)
			{
				pContact = static_cast<Contact*>(pContactEnum->GetCurrent());

				//Gets the name.
				pContact->GetValue(CONTACT_PROPERTY_ID_FIRST_NAME, firstName);
				pContact->GetValue(CONTACT_PROPERTY_ID_LAST_NAME, lastName);

				// Displays the first name and last name.
				// ...
			}
			delete pContactEnum;
			pContactList->RemoveAll(true);
			delete pContactList;
		}

		delete pCategoryEnum;
		pCategoryList->RemoveAll(true);
		delete pCategoryList;

		delete pAddressbook;
	}

 *
 * @endcode
 *
 * The following example demonstrates how to use the %Addressbook class to search for a contact.
 *
 * @code
 *
	#include <FSocial.h>

	using namespace Tizen::Base;
	using namespace Tizen::Base::Collection;
	using namespace Tizen::Social;

	void
	AddressbookExample::SearchExample(void)
	{
		result r = E_SUCCESS;

		// Get default addressbook instance
		Addressbook* pAddressbook = AddressbookManager::GetInstance()->GetAddressbookN();

		//Searches contacts by name ("Anderson").
		IList* pContactList = pAddressbook->SearchContactsByNameN(L"Anderson");
		if (pContactList == null)
		{
			delete pAddressbook;

			return;
		}

		Contact* pContact = null;
		String firstName;
		String lastName;
		IEnumerator* pContactEnum = pContactList->GetEnumeratorN();
		while (pContactEnum->MoveNext() == E_SUCCESS)
		{
			pContact = static_cast<Contact*>(pContactEnum->GetCurrent());

			//Gets the contact's name.
			pContact->GetValue(CONTACT_PROPERTY_ID_FIRST_NAME, firstName);
			pContact->GetValue(CONTACT_PROPERTY_ID_LAST_NAME, lastName);

			// Displays the first name and last name.
			// ...
		}

		delete pContactEnum;
		pContactList->RemoveAll(true);
		delete pContactList;

		delete pAddressbook;
	}
 *
 * @endcode
 */
class _OSP_EXPORT_ Addressbook
	: public Tizen::Base::Object
{
public:
	/**
	 *
	 * The object is not fully constructed after this constructor is called. @n
	 * An application must use AddressbookManager::GetAddressbookN() to get fully constructed %Addressbook instance.
	 * @since	2.0
	 *
	 * @see AddressbookManager::GetAddressbookN()
	 *
	 * The following example demonstrates how to create an %Addressbook instance.
	 * @code
	 * result
	 * MyApplication::UpdateContact(Contact* pContact)
	 * {
	 *    Addressbook* pAddressbook = AddressbookManager::GetInstance()->GetAddressbookN();
	 *
	 *    result r = pAddressbook->UpdateContact(*pContact);
	 *
	 *    delete pAddressbook;
	 *
	 *    return r;
	 * }
	 * @endcode
	 */
	Addressbook(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Addressbook(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %Addressbook with the specified listener.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method and IRecordEventListener are deprecated. Instead of using this method, use AddressbookManager::GetAddressbookN() and SetEventListener().
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pListener		The event listener to register
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @endif
	 */
	result Construct(IRecordEventListener* pListener = null);

	/**
	 * Sets addressbook change event listener. @n
	 * The listener is called when a contact or a category has been changed.
	 * To reset the event listener, @c null must be passed.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method and IAddressbookEventListener are deprecated. Instead of using this method, use SetAddressbookChangeEventListener()
	 * and IAddressbookChangeEventListener.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	An error code
	 * @param[in]	pListener	The event listener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	result SetEventListener(IAddressbookEventListener* pListener);

	/**
	 * Sets addressbook change event listener. @n
	 * The listener is called when a contact or a category has been changed.
	 * To reset the event listener, @c null must be passed.
	 *
	 * @since       2.1
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      An error code
	 * @param[in]   pListener       The event listener
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error
	 */
	result SetAddressbookChangeEventListener(IAddressbookChangeEventListener* pListener);

	/**
	 * Adds a contact to the address book. @n
	 * At least one property of the contact must have been set. @n
	 * If the contact has been added successfully, a contact ID is assigned to it.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in,out]	contact			The contact to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The contact ID is not #INVALID_RECORD_ID, or
	 *									the properties of the contact have not been set.
	 * @exception	E_STORAGE_FULL		The storage is insufficient.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks   The #CONTACT_PROPERTY_ID_DISPLAY_NAME and #CONTACT_PROPERTY_ID_LAST_REVISION properties cannot be set.
	 * @n #CONTACT_PROPERTY_ID_DISPLAY_NAME is automatically generated from the first name and last name.
	 * And #CONTACT_PROPERTY_ID_LAST_REVISION automatically updated with the last update time.
	 */
	result AddContact(Contact& contact);

	/**
	 * Removes a contact from the address book. @n
	 * After this operation is done successfully, the ID of the Contact instance is #INVALID_RECORD_ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in,out]	contact			The contact to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c contact is invalid.
	 * @exception	E_OBJ_NOT_FOUND	    	The specified @c contact does not exist.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	result RemoveContact(Contact& contact);

	/**
	 * Removes a contact from the address book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	    	The specified @c contactId does not exist.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	result RemoveContact(RecordId contactId);

	/**
	 * Updates the specified contact. @n
	 * At least one property of the contact must have been set.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	contact			The contact to update
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_OBJ_NOT_FOUND	    	The specified @c contact does not exist in this address book.
	 * @exception	E_INVALID_ARG		The specified @c contact is invalid, or
	 *									the properties of the specified @c contact have not been set.
	 * @exception	E_STORAGE_FULL		The storage is insufficient.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	result UpdateContact(const Contact& contact);

	/**
	 * Adds a category to the address book. @n
	 * If the category has been added successfully, a category ID is assigned to it.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in,out]	category		The category to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The name of the category has not been set. @n
	 *									- The category ID of the @c category is not #INVALID_RECORD_ID. @n
	 *									- One of the contact members is invalid.
	 * @exception	E_STORAGE_FULL		The storage is insufficient.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	result AddCategory(Category& category);

	/**
	 */


	/**
	 * Removes a category from the address book. @n
	 * If the category has been deleted successfully, the record ID of this instance is #INVALID_RECORD_ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in,out]	category		The category to remove
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c category is invalid or a default category.
	 * @exception	E_OBJ_NOT_FOUND 	The specified @c category does not exist in this address book.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @see		Category::IsDefault()
	 */
	result RemoveCategory(Category& category);

	/**
	 * Removes a category from the address book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	categoryId		The category ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c categoryId is invalid or the category specified by @ categoryId is a default category.
	 * @exception	E_OBJ_NOT_FOUND	    	The specified @c categoryId does not exist in this address book.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @see		Category::IsDefault()
	 */
	result RemoveCategory(RecordId categoryId);

	/**
	 * Updates a category in the address book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	category		The category to update
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_OBJ_NOT_FOUND	    	The specified @c category does not exist in this address book.
	 * @exception	E_INVALID_ARG		The specified @c category is invalid, or
	 *									one of the contact members is invalid.
	 * @exception	E_STORAGE_FULL		The storage is insufficient.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	result UpdateCategory(const Category& category);

	/**
	 */


	/**
	 * Gets all contacts in the addressbook. @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all contacts in the addressbook, @n
	 *				    else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetAllContactsN(void) const;

	/**
	 * Gets the member contacts of the specified category. @n
	 * If the specified @c category is INVALID_RECORD_ID, this method returns the list of contacts that are not member of any category.
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of contacts that are members of the specified category, @n
	 *				    else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	categoryId		The category ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c categoryId is less than INVALID_RECORD_ID.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetContactsByCategoryN(RecordId categoryId) const;

	/**
	 * Gets contacts in the specified range in the address book. @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of contacts in the specified range, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	pageNo			The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The maximum count of the result items on a page
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_OUT_OF_RANGE		The specified @c pageNo or @c countPerPage is less than @c 1.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.

	 */
	Tizen::Base::Collection::IList* GetContactsN(int pageNo, int countPerPage) const;

	/**
	 * Gets contacts that are in the specified range of the specified category. @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of contacts in the specified range of the specified category, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	category		The category
	 * @param[in]	pageNo			The page number of the result list, which starts from @c 1
	 * @param[in]	countPerPage		The maximum count of the result items on a page
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_OUT_OF_RANGE		The specified @c pageNo or @c countPerPage is less than @c 1.
	 * @exception	E_INVALID_ARG		The specified @c category is invalid, or
	 *									one of the contact members is invalid.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetContactsInN(const Category& category, int pageNo, int countPerPage) const;

	/**
	 * Gets the contact with the specified contact ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The matched contact, @n
	 *				else @c null if no contact matches the specified contact ID
	 * @param[in]	contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	 	The specified @c contactId is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Contact* GetContactN(RecordId contactId) const;

	/**
	 * Gets the number of contacts in the address book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The number of contacts in the address book, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetContactCount(void) const;

	/**
	 * Adds the specified contact to the specified category.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param [in]	categoryId		The category ID
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified contact or category does not exist, or the specified contact and category are not in this addressbook.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks If the contact is already a member of the category, this method does nothing.
	 */
	result AddMemberToCategory(RecordId categoryId, RecordId contactId);

	/**
	 * Removes the specified contact from the specified category.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param [in]	categoryId		The category ID
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified contact or category does not exist, or the specified contact and category are not in this addressbook.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks If the contact is not a member of the category, this method does nothing.
	 */
	result RemoveMemberFromCategory(RecordId categoryId, RecordId contactId);

	/**
	 * Gets all categories in the address book. @n
	 * The categories are ordered by name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of categories in the address book, @n
	 *				else an empty list if there is no category, or @c null if an exception occurs (@ref Category list)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAllCategoriesN(void) const;

	/**
	 * Gets all categories whose member is the specified contact. @n
	 * The categories are ordered by name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		A list of categories that has the specified contact as a member, @n
	 *				    else an empty list if there is no category, or @c null if an exception occurs (@ref Category list)
	 * @param[in] contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetCategoriesByContactN(RecordId contactId) const;

	/**
	 * Gets the number of categories in the address book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The number of categories in the address book, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS		        The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM		        The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCategoryCount(void) const;

	/**
	 * Gets the category with the specified category ID.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The matched category, @n
	 *				else @c null if no category matches the specified category ID
	 * @param[in]	categoryId		The category ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c categoryId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	      	The specified record is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Category* GetCategoryN(RecordId categoryId) const;

	/**
	 * Searches the contacts whose email address contains the specified @c email string. @n
	 * The search operation is performed with a case insensitive key (param: @c email). @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all the matched contacts, @n
	 *				else an empty list if there is no matched contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	email			The substring of the email to search
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c email is an empty string.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - There is a high probability for an occurrence of an out-of-memory exception. @n If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n 
	 *                For more information on how to handle the out-of-memory exception, refer  
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchContactsByEmailN(const Tizen::Base::String& email) const;

	/**
	 * Searches the contacts that have the specified @c name as a substring of their display name. @n
	 * The search operation is performed with a case insensitive key (param: @c name). @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all the matched contacts, @n
	 *				else an empty list if there is no matched contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	name			The substring of the name to search
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c name is an empty string.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - There is a high probability for an occurrence of an out-of-memory exception.@n If possible, check whether the exception is E_OUT_OF_MEMORY or not.@n
	 *                For more information on how to handle the out-of-memory exception, refer  
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchContactsByNameN(const Tizen::Base::String& name) const;

	/**
	 * Searches the contacts that have the specified @c phoneNumber string as a substring of one of their phone numbers. @n
	 * The %SearchContactsByPhoneNumberN() method returns the contacts whose phone number match the value of the specified @c phoneNumber. @n
	 * The search operation is performed with a case insensitive key (param: @c phoneNumber). @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all the matched contacts, @n
	 *				    else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	phoneNumber		The substring of the phone number to search
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c phoneNumber is an empty string.
	 * @exception	E_SYSTEM	        The method cannot proceed due to a severe system error.
	 * @remarks
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - There is a high probability for an occurrence of an out-of-memory exception. @n If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n 
	 *                For more information on how to handle the out-of-memory exception, refer  
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchContactsByPhoneNumberN(const Tizen::Base::String& phoneNumber) const;

	/**
	 * Gets the latest change version of the address book.
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The latest change version, @c
	 *			else @c -1 if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see GetChangedContactsAfterN()
	 * @see	GetChangedCategoriesAfterN()
	 */
	int GetLatestVersion(void) const;

	/**
	 * Gets the change information of the contacts that have been changed after the specified change version. @n
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated. Instead of using this method, use GetChangedContactInfoListN().
	 *
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of contact change information, @n
	 *				    else an empty list if there is no changed contact, or @c null if an exception occurs (@ref ContactChangeInfo list)
	 * @param[in]	version			The change version
	 * @param[out]	latestVersion	The latest change version among the changed contacts
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c version is invalid.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see GetLatestVersion()
	 *
	 * The following example demonstrates how to use the %GetChangedContactsAfterN() method.
	 * @code
	 * void
	 * MyApplication::GetChangedContacts(void)
	 * {
	 *    IList* pChangedContacts = __pAddressbook->GetChangedContactsAfterN(__version, __version);
	 *
	 *    IEnumerator* pEnum = pChangedContacts->GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      ContactChangeInfo* pInfo = (ContactChangeInfo*) pEnum->GetCurrent();
	 *
	 *      AppLog("Contact changed: type(%d), id(%d), version(%d)", pInfo->GetChangeType(), pInfo->GetContctId(), pInfo->GetVersion());
	 *    }
	 *    delete pEnum;
	 *    pChangedContacts->RemoveAll(true);
	 *    delete pChangedContacts;
	 * }
	 * @endcode
	 */
	Tizen::Base::Collection::IList* GetChangedContactsAfterN(int version, int& latestVersion) const;

	/**
	 * Gets the change information of the contacts that have been changed after the specified change version. @n
	 *
	 * @since       2.1
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of contact change information, @n
	 *                                  else an empty list if there is no changed contact or @c null if an exception occurs (@ref ContactChangeInfo list)
	 * @param[in]   version                 The change version
	 * @param[out]  latestVersion   The latest change version among the changed contacts
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception   E_INVALID_ARG           The specified @c version is invalid.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error
	 * @remarks             The specific error code can be accessed using the GetLastResult() method.
	 * @see GetLatestVersion()
	 *
	 * The following example demonstrates how to use the %GetChangedContactInfoListN() method.
	 * @code
	 * void
	 * MyApplication::GetChangedContacts(void)
	 * {
	 *    IList* pChangedContacts = __pAddressbook->GetChangedContactInfoListN (__version, __version);
	 *
	 *    IEnumerator* pEnum = pChangedContacts->GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      ContactChangeInfo* pInfo = (ContactChangeInfo*) pEnum->GetCurrent();
	 *
	 *      AppLog("Contact changed: type(%d), id(%d), version(%d)", pInfo->GetChangeType(), pInfo->GetContctId(), pInfo->GetVersion());
	 *    }
	 *    delete pEnum;
	 *    pChangedContacts->RemoveAll(true);
	 *    delete pChangedContacts;
	 * }
	 * @endcode
	 */
	Tizen::Base::Collection::IList* GetChangedContactInfoListN(int version, int& latestVersion) const;

	/**
	 * Gets the change information of the categories that have been changed after the specified version.
	 *
	* @brief <i> [Deprecated] </i>
	* @deprecated This method is deprecated. Instead of using this method, use GetChangedCategoryInfoListN().
	*
	 * @since	2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of category change information, @n
	 *				    else an empty list if there is no changed category, or @c null if an exception occurs (@ref CategoryChangeInfo list)
	 *		
	 * @param[in]	version			The change version
	 * @param[out]	latestVersion	The latest change version among the changed categories
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception	E_INVALID_ARG		The specified @c version is invalid.
	* @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see GetLatestVersion()
	*
	* The following example demonstrates how to use the %GetChangedCategoriesAfterN() method.
	* @code
	* void
	* MyApplication::GetChangedCategories(void)
	* {
	*    IList* pChangedCategories = __pAddressbook->GetChangedCategoriesAfterN(__version, __version);
	*
	*    IEnumerator* pEnum = pChangedCategories->GetEnumeratorN();
	*    while (pEnum->MoveNext() == E_SUCCESS)
	*    {
	*      CategoryChangeInfo* pInfo = (CategoryChangeInfo*) pEnum->GetCurrent();
	*
	*      AppLog("Category changed: type(%d), id(%d), version(%d)", pInfo->GetChangeType(), pInfo->GetCategoryId(), pInfo->GetVersion());
	*    }
	*    delete pEnum;
	*    pChangedCategories->RemoveAll(true);
	*    delete pChangedCategories;
	* }
	* @endcode
	*/
	Tizen::Base::Collection::IList* GetChangedCategoriesAfterN(int version, int& latestVersion) const;

	/**
	 * Gets the change information of the categories that have been changed after the specified version.
	 *
	 * @since       2.1
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of category change information, @n
	 *                                  else an empty list if there is no changed category or @c null if an exception occurs (@ref CategoryChangeInfo list)
	 *
	 * @param[in]   version                 The change version
	 * @param[out]  latestVersion           The latest change version among the changed categories
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception   E_INVALID_ARG           The specified @c version is invalid.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error
	 * @remarks             The specific error code can be accessed using the GetLastResult() method.
	 * @see GetLatestVersion()
	 *
	 * The following example demonstrates how to use the %GetChangedCategoryInfoListN() method.
	 * @code
	 * void
	 * MyApplication::GetChangedCategories(void)
	 * {
	 *    IList* pChangedCategories = __pAddressbook->GetChangedCategoryInfoN(__version, __version);
	 *
	 *    IEnumerator* pEnum = pChangedCategories->GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      CategoryChangeInfo* pInfo = (CategoryChangeInfo*) pEnum->GetCurrent();
	 *
	 *      AppLog("Category changed: type(%d), id(%d), version(%d)", pInfo->GetChangeType(), pInfo->GetCategoryId(), pInfo->GetVersion());
	 *    }
	 *    delete pEnum;
	 *    pChangedCategories->RemoveAll(true);
	 *    delete pChangedCategories;
	 * }
	 * @endcode
	 */
	Tizen::Base::Collection::IList* GetChangedCategoryInfoListN(int version, int& latestVersion) const;

	/**
	 * Sets a user profile of this addressbook. @n
	 * To remove the user profile, @c null must be passed.
	 *
	 * @since			2.1
	 * @privlevel	 	public
	 * @privilege		%http://tizen.org/privilege/userprofile.write
	 *
	 * @return		An error code
	 * @param[in]		pUserProfile	The user profile to set
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	result SetUserProfile(const UserProfile* pUserProfile);

	/**
	 * Gets a user profile of this addressbook.
	 *
	 * @since			2.1
	 * @privlevel 		public
	 * @privilege		%http://tizen.org/privilege/userprofile.read
	 *
	 * @return		The user profile, @n
	 *				else @c null if the user profile does not exist, or if an exception has occurred
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM 	The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	UserProfile* GetUserProfileN(void) const;

	/**
	 * Checks whether the user profile of this address book has been changed after the specified version or not.
	 * If the user profile does not exist, this method returns false.
	 *
	 * @since       2.1
	 * @privlevel 		public
	 * @privilege   %http://tizen.org/privilege/userprofile.read
	 *
	 * @return     @c true if the user profile has been changed, @n
	 *              else @c false
	 * @param[in]   version                  The change version
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_INVALID_ARG		The specified @c version is invalid.
	 * @exception   E_SYSTEM                 The method cannot proceed due to a severe system error.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see SetUserProfile()
	 */
	bool IsUserProfileChangedAfter(int version) const;

	/**
	 * Gets the addressbook name.
	 *
	 * @since	2.0
	 *
	 * @return		The addressbook name
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the addressbook ID.
	 *
	 * @since	2.0
	 *
	 * @return		The addressbook ID
	 */
	AddressbookId GetId(void) const;

	/**
	 * Gets the account ID associated with the addressbook.
	 *
	 * @since	2.0
	 *
	 * @return		The account ID
	 */
	AccountId GetAccountId(void) const;

	/**
	* Adds the contacts to the addressbook.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege	%http://tizen.org/privilege/contact.write
	*
	* @return		An error code
	* @param[in]	contactList				The contacts to add @n The list should contain the Contact instances.
	* @param[out]	pContactIdList			A pointer to the list of contact IDs that have been added successfully @n Pass @c null if the contact IDs are not necessary.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred:
	*														- The specified @c contactList is empty.
	*														- The specified @c contactList contains an empty contact.
	*														- The specified @c contactList contains a contact whose ID is not INVALID_RECORD_ID.
	* @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks		If an exception occurs during adding contacts, the changes are getting rollbacked. @n
	*				This method blocks the execution of the calling thread until all contacts in the list has been added to the addressbook or if an exception occurs.
	*				It is recommended to call this method on any thread other than the main thread.
	*/
	result AddContacts(const Tizen::Base::Collection::IList& contactList, Tizen::Base::Collection::IListT<RecordId>* pContactIdList = null);

	/**
	* Updates the contacts.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege	%http://tizen.org/privilege/contact.write
	*
	* @return		An error code
	* @param[in]	contactList				The contacts to update @n The list should contain the Contact instances.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred:
	*														- The specified @c contactList is empty.
	*														- The specified @c contactList contains an empty contact.
	*														- The specified @c contactList contains a contact whose ID is invalid.
	* @exception	E_OBJ_NOT_FOUND			The specified @c contact does not exist.
	* @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks		If an exception occurs during updating contacts, the changes are getting rollbacked. @n
	*				This method blocks the execution of the calling thread until all contacts in the list has been updated or if an exception occurs. @n
	*				It is recommended to call this method on any thread other than the main thread.
	*/
	result UpdateContacts(const Tizen::Base::Collection::IList& contactList);

	/**
	* Removes the contacts. @n If the contact specified by a contact ID in the list does not exist, the contact ID is ignored.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege	%http://tizen.org/privilege/contact.write
	*
	* @return		An error code
	* @param[in]	contactIdList			The list of contact IDs to delete
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	* @exception	E_INVALID_ARG			The specified @c contactIdList is empty or contains an invalid ID.
	* @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks		If an exception occurs during removing contacts, the changes are getting rollbacked. @n
	*				This method blocks the execution of the calling thread until all contacts in the list has been removed or if an exception occurs. @n
	*				It is recommended to call this method on any thread other than the main thread.
	*/
	result RemoveContacts(const Tizen::Base::Collection::IListT<RecordId>& contactIdList);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	Addressbook(const Addressbook& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	Addressbook& operator =(const Addressbook& rhs);

private:
	friend class _AddressbookImpl;
	class _AddressbookImpl* __pAddressbookImpl;
};	// Addressbook

}}	// Tizen::Social

#endif //_FSCL_ADDRESSBOOK_H_
