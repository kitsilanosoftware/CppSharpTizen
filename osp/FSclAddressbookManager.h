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
 * @file	FSclAddressbookManager.h
 * @brief	This is the header file for the %AddressbookManager class.
 *
 * This header file contains the declarations of the %AddressbookManager class.
 */
#ifndef _FSCL_ADDRESSBOOK_MANAGER_H_
#define _FSCL_ADDRESSBOOK_MANAGER_H_

#include <unique_ptr.h>
#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
namespace Collection
{
class IList;
template<class Type1> class IListT;
}
}}

namespace Tizen { namespace Social
{
class Category;
class Contact;
class Person;
class Addressbook;
class AddressbookFilter;
class IAddressbookEventListener;

/**
 * @class	AddressbookManager
 * @brief	This class manages addressbooks and all contacts in the device storage.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %AddressbookManager class provides methods for managing addressbooks and contacts in the device storage.
 */
class _OSP_EXPORT_ AddressbookManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Creates an addressbook with the specified account ID and name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An addressbook instance
	 * @param[in]	accountId	The account ID
	 * @param[in]	name		The addressbook name
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG       The specified @c accountId is invalid or specified @ name is an empty string.
	 * @exception	E_OBJ_ALREADY_EXIST The addressbook with the specified name already exists.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Addressbook* CreateAddressbookN(AccountId accountId, const Tizen::Base::String& name);

	/**
	 * Deletes an addressbook. @n
	 * If the addressbook has been deleted successfully,
	 * the contacts and categories that belong to the addressbook are also deleted.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	addressbookId	The addressbook ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c addressbookId is invalid or the addressbook specified by @c addressbookId is a default addressbook.
	 * @exception	E_OBJ_NOT_FOUND	    The specified @c addressbookId does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result DeleteAddressbook(AddressbookId addressbookId);

	/**
	 * Gets the addressbooks associated with the specified account ID.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of addressbooks, @n
	 *				    else an empty list if there is no addressbook, or @c null if an exception occurs (@ref Addressbook list)
	 * @param[in]	accountId	The account ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c accountId is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAddressbooksByAccountN(AccountId accountId) const;

	/**
	 * Gets a list of all addressbooks.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of addressbooks, @n
	 *				    else an empty list if there is no addressbook, or @c null if an exception occurs (@ref Addressbook list)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	 Tizen::Base::Collection::IList* GetAllAddressbooksN(void) const;

	/**
	 * Gets an instance of an addressbook specified by the addressbook ID.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	An addressbook instance
	 * @param[in]	addressbookId		The addressbook ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c addressbookId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	    The specified @c addressbookId does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	 Addressbook* GetAddressbookN(AddressbookId addressbookId = DEFAULT_ADDRESSBOOK_ID) const;

	 /**
	  * Sets an addressbook change event listener. @n
	  * The listener is called when a contact or a category has been changed.
	  * To reset the event listener, @c null must be passed.
	  *
	  * @since	2.0
	  * @privilege	%http://tizen.org/privilege/contact.read
	  *
	  * @return	An error code
	  * @param[in]	pListener	The event listener
	  * @exception	E_SUCCESS		The method is successful.
	  * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	  * @exception	E_SYSTEM		A system error has occurred.
	  */
	 result SetEventListener(IAddressbookEventListener* pListener);

	/**
	 * Adds a contact to the specified addressbook. @n
	 * At least one property of the contact must have been set. @n
	 * If the contact has been added successfully, a contact ID is assigned to it.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return		An error code
	 * @param[in,out]	contact		The contact to add
	 * @param[in]		addressbookId	The addressbook ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The contact ID is not #INVALID_RECORD_ID. @n
	 *									- The properties of the contact have not been set. @n
	 *									- The specified @c addressbookId is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified addressbook is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The #CONTACT_PROPERTY_ID_DISPLAY_NAME and #CONTACT_PROPERTY_ID_LAST_REVISION
	 * properties cannot be set. @n #CONTACT_PROPERTY_ID_DISPLAY_NAME is automatically generated from the first name and
	 * the last name. And #CONTACT_PROPERTY_ID_LAST_REVISION is automatically updated with the last update time.
	 */
	result AddContact(Contact& contact, AddressbookId addressbookId);

	/**
	 * Removes a contact.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	contactId		The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	    The specified @c contactId does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveContact(RecordId contactId);

	/**
	 * Updates the specified contact. @n
	 * At least one property of the contact must have been set.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	contact			The contact to update
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	    The specified @c contact does not exist in this address book.
	 * @exception	E_INVALID_ARG		The specified @c contact is invalid, or
	 *									the properties of the specified @c contact have not been set.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result UpdateContact(const Contact& contact);

	/**
	 * Adds a category to the specified addressbook. @n
	 * The name of the category must have been set. @n
	 * If the category has been added successfully, a category ID is assigned to it.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in,out]	category	The category to add
	 * @param[in]		addressbookId	The addressbook ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The name of the category has not been set. @n
	 *									- One of the member contacts is invalid. @n
	 *									- The category ID of the @c category is not #INVALID_RECORD_ID. @n
	 *									- The specified @c addressbookId is invalid.
	 * @exception   E_STORAGE_FULL		The capacity of this address book is full.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result AddCategory(Category& category, AddressbookId addressbookId);

	/**
	 * Removes a category.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	categoryId		The category ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c categoryId is invalid or the category specified by @c categoryId is a default category.
	 * @exception	E_OBJ_NOT_FOUND	    The specified @c categoryId does not exist in this address book.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see Category::IsDefault()
	 */
	result RemoveCategory(RecordId categoryId);

	/**
	 * Updates a category.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param[in]	category		The category to update
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	    The specified @c category does not exist in this address book.
	 * @exception	E_INVALID_ARG		The specified @c category is invalid, or
	 *									one of the contact members is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result UpdateCategory(const Category& category);

	/**
	 * Gets all contacts on the device. @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all contacts on the device, @n
	 *				    else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
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
	 * If the specified @c categoryId is INVALID_RECORD_ID, this method returns the list of contacts that are not member of any category.
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of contacts that are members of the specified category, @n
	 *				    else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	categoryId		The category ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c categoryId is less than INVALID_RECORD_ID.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetContactsByCategoryN(RecordId categoryId) const;

	/**
	 * Gets the contacts linked to the person specified by the person ID.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of contacts that are linked to this person, @n
	 *                                  else @c null if an exception occurs (@ref Contact list)
	 * @param[in]   personId                The person ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c personId is invalid.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetContactsByPersonN(PersonId personId) const;

	/**
	 * Gets the categories whose member is the person specified by the person ID. @n
	 * A person is a member of a category if a contact linked to it is a member of the category.
	 * The categories are ordered by name.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return              A list of categories that has the specified person as a member, @n
	 *                                  else an empty list if there is no category, or @c null if an exception occurs (@ref Category list)
	 * @param[in]   personId                The person ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c personId is invalid.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetCategoriesByPersonN(PersonId personId) const;

	/**
	 * Gets the contact with the specified contact ID.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The matched contact, @n
	 *				else @c null if no contact matches the specified contact ID
	 * @param[in]	contactId		The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	 	The specified @c contactId is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Contact* GetContactN(RecordId contactId) const;

	/**
	 * Gets the number of contacts in all addressbooks.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The number of contacts in the address book, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetContactCount(void) const;

	/**
	 * Adds the specified contact to the specified category.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param [in]	categoryId		The category ID
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified contact or category does not exist,
	 *					or the specified contact and category are not in the same addressbook.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks If the contact is already a member of the category, this method does nothing.
	 */
	result AddMemberToCategory(RecordId categoryId, RecordId contactId);

	/**
	 * Removes the specified contact from the specified category.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.write
	 *
	 * @return	An error code
	 * @param [in]	categoryId		The category ID
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified contact or category does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks If the contact is not a member of the category, this method does nothing.
	 */
	result RemoveMemberFromCategory(RecordId categoryId, RecordId contactId);

	/**
	 * Gets all categories on the device. @n
	 * The categories are ordered by name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of categories on the device, @n
	 *				else an empty list if there is no category, or @c null if an exception occurs (@ref Category list)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAllCategoriesN(void) const;

	/**
	 * Gets all categories whose member is the specified contact. @n
	 * The categories are ordered by name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		A list of categories that has the specified contact as a member, @n
	 *				    else an empty list if there is no category, or @c null if an exception occurs (@ref Category list)
	 * @param[in] contactId		The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetCategoriesByContactN(RecordId contactId) const;

	/**
	 * Gets the number of categories on the device.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The number of categories on the device, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCategoryCount(void) const;

	/**
	 * Gets the category with the specified category ID.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The matched category, @n
	 *				else @c null if no category matches the specified category ID
	 * @param[in]	categoryId		The category ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c categoryId is invalid.
	 * @exception	E_OBJ_NOT_FOUND	    The specified record is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Category* GetCategoryN(RecordId categoryId) const;

	/**
	 * Searches the contacts whose email address contains the specified @c email string. @n
	 * The search operation is performed with a case insensitive key (param: @c email). @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all matched contacts, @n
	 *				else an empty list if there is no matched contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	email			The substring of the email to search
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c email is an empty string.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchContactsByEmailN(const Tizen::Base::String& email) const;

	/**
	 * Searches the contacts that have the specified @c name as a substring of their display name. @n
	 * The display name is a concatenation of the first name, space, and the last name. @n
	 * The search operation is performed with a case insensitive key (param: @c name). @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all matched contacts, @n
	 *				else an empty list if there is no matched contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	name			The substring of the name to search
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c name is an empty string.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchContactsByNameN(const Tizen::Base::String& name) const;

	/**
	 * Searches the contacts that have the specified @c phoneNumber string as a substring of one of their phone numbers. @n
	 * This method returns the contacts whose phone number match the value of the specified @c phoneNumber. @n
	 * The search operation is performed with a case insensitive key (param: @c phoneNumber). @n
	 * The contacts are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of all matched contacts, @n
	 *				    else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]	phoneNumber		The substring of the phone number to search
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c phoneNumber is an empty string.
	 * @exception	E_SYSTEM	        A system error has occurred.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchContactsByPhoneNumberN(const Tizen::Base::String& phoneNumber) const;

	/**
	 * Gets the latest change version.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return		The latest change version, @n
	 *			else @c -1 if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see GetChangedContactsAfterN()
	 * @see GetChangedCategoriesAfterN()
	 */
	int GetLatestVersion(void) const;

	/**
	 * Gets the change information of the contacts that have been changed after the specified change version.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of contact change information, @n
	 *				    else an empty list if there is no changed contact, or @c null if an exception occurs (@ref ContactChangeInfo list)
	 * @param[in]	version			The change version
	 * @param[out]	latestVersion	The latest change version among the changed contacts
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c version is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see GetLatestVersion()
	 * @see ContactChangeInfo
	 *
	 * The following example demonstrates how to use the %GetChangedContactsAfterN() method.
	 * @code
	 * void
	 * MyApplication::PrintChangedContacts(void)
	 * {
	 *    IList* pChangedContacts = __pAddressbookManager->GetChangedContactsAfterN(__version, __version);
	 *
	 *    IEnumerator* pEnum = pChangedContacts->GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      ContactChangeInfo* pInfo = static_cast<ContactChangeInfo*>(pEnum->GetCurrent());
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
	 * Gets the change information of the categories that have been changed after the specified change version.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/contact.read
	 *
	 * @return	A list of category change information, @n
	 *				    else an empty list if there is no changed category, or @c null if an exception occurs (@ref CategoryChangeInfo list)
	 * @param[in]	version			The change version
	 * @param[out]	latestVersion	The latest change version among the changed categories
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c version is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see GetLatestVersion()
	 * @see CategoryChangeInfo
	 *
	 * The following example demonstrates how to use the %GetChangedCategoriesAfterN() method.
	 * @code
	 * void
	 * MyApplication::PrintChangedCategories(void)
	 * {
	 *    IList* pChangedCategories = __pAddressbookManager->GetChangedCategoriesAfterN(__version, __version);
	 *
	 *    IEnumerator* pEnum = pChangedCategories->GetEnumeratorN();
	 *    while (pEnum->MoveNext() == E_SUCCESS)
	 *    {
	 *      CategoryChangeInfo* pInfo = static_cast<CategoryChangeInfo*>(pEnum->GetCurrent());
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
	 * Gets the person with the specified person ID.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      The matched person, @n
	 *                              else @c null if an exception occurs
	 * @param[in]   personId                The person ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c personId is invalid.
	 * @exception   E_OBJ_NOT_FOUND         The specified @c personId is not found.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Person* GetPersonN(PersonId personId) const;

	/**
	 * Removes a person. @n
	 * All contacts linked to the person will be removed, too.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return      An error code
	 * @param[in]   personId                The person ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c personId is invalid.
	 * @exception   E_OBJ_NOT_FOUND         The specified person does not exist.
	 * @exception   E_SYSTEM      The method cannot be proceed due to a severe system error.
	 */
	result RemovePerson(PersonId personId);

	/**
	 * Gets all persons on the device. @n
	 * The persons are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of all persons on the device, @n
	 *                                  else an empty list if there is no person, or @c null if an exception occurs (@ref Person list)
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM      The method cannot be proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetAllPersonsN(void) const;

	/**
	 * Gets the persons that are members of the specified category where a person is a member of a category if a contact linked to it is a member of the category. @n
	 * If the specified @c categoryId is INVALID_RECORD_ID, this method returns the persons that are not members of any category.@n
	 * The persons are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of persons that are members of the specified category, @n
	 *                                  else an empty list if there is no person, or @c null if an exception occurs (@ref Person list)
	 * @param[in]   categoryId              The category ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c categoryId is invalid.
	 * @exception   E_OBJ_NOT_FOUND         The specified category does not exist.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* GetPersonsByCategoryN(RecordId categoryId) const;

	/**
	 * Gets a list of the favorite persons. @n
	 * The persons are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of the favorite persons, @n
	 *                                  else an empty list if there is no favorite person, or @c null if an exception occurs (@ref Person list)
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
         * @see SetPersonAsFavorite()
         */
	Tizen::Base::Collection::IList* GetFavoritePersonsN() const;

	/**
	 * Searches the persons that contains the specified @c keyword string in its properties. @n
	 * The search operation is performed with a case insensitive key (param: @c keyword). @n
	 * The persons are ordered by display name.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      A list of all matched persons, @n
	 *                                  else an empty list if there is no matched person, or @c null if an exception occurs (@ref Person list)
	 * @param[in]   keyword                 The key to search
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c keyword is an empty string.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	Tizen::Base::Collection::IList* SearchPersonsN(const Tizen::Base::String& keyword) const;

	/**
	 * Sets whether the specified person is a favorite or not.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return      An error code
	 * @param[in]   personId       The person ID
	 * @param[in]   isFavorite    Set to @c true to set the specified person as a favorite, @n
	 *                            else @c false to set the specified person as a non-favorite
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c personId is invalid.
	 * @exception   E_OBJ_NOT_FOUND         The specified person does not exist.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 * @see GetFavoritePersonsN()
	 * @see Person::IsFavorite()
	 */
	result SetPersonAsFavorite(PersonId personId, bool isFavorite = true);

	/**
	 * Merges the source person with the target person. @n
	 * The following are done during merging:
	 *      - Unlinks the contacts linked to the source person.
	 *      - Links the unlinked contacts to the target person.
	 *      - Removes the source person.
	 *      - Updates information of the target person.
	 *
	 * This method does nothing if the source or target person does not exist.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return      An error code
	 * @param[in]   sourcePersonId          The source person ID
	 * @param[in]   targetPersonId          The target person ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c sourcePersonId or @c targetPersonId is invalid.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 */
        result MergePersons(PersonId sourcePersonId, PersonId targetPersonId);

	/**
	 * Unlinks the specified contact from the specified person. @n
	 * The following are done during unlinking:
	 *      - Unlinks the contact specified by @c contactId.
	 *      - Creates a new person.
	 *      - Links the unlinked contact to the new person.
	 *      - Updates information of the persons.
	 *
	 * It is not allowed to unlink a contact if it is the only one contact linked to a person.
	 * This method does nothing if the contact has not been linked to the person or does not exist.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.write
	 *
	 * @return      An error code
	 * @param[in]   personId                The ID of the person that the contact is unlinked from
	 * @param[in]   contactId               The contact to unlink
	 * @param[out]  newPersonId             The ID of the new person
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c personId or @c contactId is invalid.
	 * @exception   E_SYSTEM      The method cannot proceed due to a severe system error.
	 */
        result UnlinkContact(PersonId personId, RecordId contactId, PersonId& newPersonId);

	/**
	 * Searches items of the addressbook with the filter. @n
	 * The filter specifies the item type and condition for searching.
	 * The searched results are ordered by the @c propertyToSort and @c sortOrder.
	 * If the @c offset is M and the @c maxCount are N, then the first M items are omitted from the result set returned by the searching operation and the next N items are returned.
	 *
	 * @since	2.0
	 * @privilege    %http://tizen.org/privilege/contact.read
	 *
	 * @return       A list of searched results (The list of Addressbook, Person, Contact, Category, PhoneNumberContact, EmailContact), @n
	 *                 else an empty list if there is no searched result, or @c null if an exception occurs
	 * @param[in]    filter              The filter that specifies the search condition @n If the filter is empty, all items that are specified by the type of this filter will be searched.
	 * @param[in]    propertyToSort      The property for sorting @n The searched results are ordered by the values of this property.
	 * @param[in]    sortOrder           The order for sorting
	 * @param[in]    offset              The offset of the searched results @n If this value is @c 0, it will be ignored.
	 * @param[in]    maxCount            The maximum count of the searched results @n If this value is @c 0, it will be ignored.
	 * @exception    E_SUCCESS                          The method is successful.
	 * @exception    E_PRIVILEGE_DENIED                 The application does not have the privilege to call this method.
	 * @exception    E_INVALID_ARG                      The specified @c offset or @c maxCount is less than @c 0.
	 *                                                  Or, the @c propertyToSort is not an elements of the enumerator that corresponds with the type of the specified @c filter.
	 * @exception    E_SYSTEM                A system error has occurred.
	 * @remarks
	 *		- The specific error code can be accessed using the GetLastResult() method.
	 *		- There is a high probability for an occurrence of an out-of-memory exception.
	 *		  If possible, check whether the exception is E_OUT_OF_MEMORY or not. @n
	 *		  For more information on how to handle the out-of-memory exception, refer
	 *                <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 * @see AddressbookFilterProperty
	 * @see PersonFilterProperty
	 * @see ContactFilterProperty
	 * @see CategoryFilterProperty
	 * @see PhoneContactFilterProperty
	 * @see EmailContactFilterProperty
	 */
	Tizen::Base::Collection::IList* SearchN(const AddressbookFilter& filter, 
			unsigned long propertyToSort = 0, Tizen::Base::SortOrder sortOrder = Tizen::Base::SORT_ORDER_NONE, int offset = 0, int maxCount = 0);

	/**
	 * Gets the matched item count of the search results with the filter. @n
	 * The filter specifies the item type and condition for searching.
	 *
	 * @since	2.0
	 * @privilege    %http://tizen.org/privilege/contact.read
	 *
	 * @return       The count of the searched results
	 * @param[in]    filter                  The filter that specifies the search condition @n If the filter is empty, all items that are specified by the type of this filter will be searched.
	 * @exception    E_SUCCESS               The method is successful.
	 * @exception    E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception    E_SYSTEM                A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see AddressbookFilterProperty
	 * @see PersonFilterProperty
	 * @see ContactFilterProperty
	 * @see CategoryFilterProperty
	 * @see PhoneContactFilterProperty
	 * @see EmailContactFilterProperty
	 */
	int GetMatchedItemCount(const AddressbookFilter& filter);

	/**
	 * Parses contacts from the specified vCard file. @n
	 * This method supports vCard formation 2.1 and 3.0.
	 *
	 * @since	2.0
	 *
	 * @return      A list of contacts, @n
	 *                                  else an empty list if there is no contact, or @c null if an exception occurs (@ref Contact list)
	 * @param[in]   vcardPath               The file path of a vCard file  
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c vcardPath is invalid.
	 * @exception   E_ILLEGAL_ACCESS        Access is denied due to insufficient permission.
	 * @exception   E_FILE_NOT_FOUND        The specified file cannot be found.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* ParseContactsFromVcardN(const Tizen::Base::String& vcardPath);

	/**
	 * Exports a person to the specified vCard 3.0 file. 
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      An error code
	 * @param[in]   person                  The person to export
	 * @param[in]   vcardPath               The file path of a vCard file
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           The specified @c person is invalid.
	 * @exception   E_ILLEGAL_ACCESS        Access is denied due to insufficient permission.
	 * @exception   E_FILE_ALREADY_EXIST    The specified file already exists.
	 * @exception   E_STORAGE_FULL          The disk space is full.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 */
	result ExportPersonToVcard(const Person& person, const Tizen::Base::String& vcardPath);

	/**
	 * Exports a person list to the specified vCard 3.0 file.
	 *
	 * @since	2.0
	 * @privilege   %http://tizen.org/privilege/contact.read
	 *
	 * @return      An error code
	 * @param[in]   personList              The person list to export @n The list should contain Person instances.
	 * @param[in]   vcardPath               The file path of a vCard file 
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG           Either the specified @c personList is invalid or
	 *                                      the specified @c vcardPath is invalid.
	 * @exception   E_ILLEGAL_ACCESS        Access is denied due to insufficient permission.
	 * @exception   E_FILE_ALREADY_EXIST    The specified file already exists.
	 * @exception   E_STORAGE_FULL          The disk space is full.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 */
	result ExportPersonsToVcard(const Tizen::Base::Collection::IList& personList, const Tizen::Base::String& vcardPath);

	/**
	 * Exports a contact to the specified vCard 3.0 file.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]   contact               	The contact to export
	 * @param[in]   vcardPath               The file path of a vCard file
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c contact is invalid.
	 * @exception   E_ILLEGAL_ACCESS        Access is denied due to insufficient permission.
	 * @exception   E_FILE_ALREADY_EXIST    The specified file already exists.
	 * @exception   E_STORAGE_FULL          The disk space is full.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 */
	result ExportContactToVcard(const Contact& contact, const Tizen::Base::String& vcardPath);

	/**
	 * Exports a contact list to the specified vCard 3.0 file.
	 *
	 * @since	2.0
	 *
	 * @return      An error code
	 * @param[in]   contactList             The contact list to export @n The list should contain Contact instances.
	 * @param[in]   vcardPath               The file path of a vCard file  
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           Either the specified @c contactList is invalid or
	 *                                      the specified @c vcardPath is invalid.
	 * @exception   E_ILLEGAL_ACCESS        Access is denied due to insufficient permission.
	 * @exception   E_FILE_ALREADY_EXIST    The specified file already exists.
	 * @exception   E_STORAGE_FULL          The disk space is full.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 */
	result ExportContactsToVcard(const Tizen::Base::Collection::IList& contactList, const Tizen::Base::String& vcardPath);

	/**
	 * Gets the addressbook manager instance.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the %AddressbookManager instance, @n
	 *			else @c null if it fails
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static AddressbookManager* GetInstance(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since	2.0
	//
	AddressbookManager(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since	2.0
	//
	virtual ~AddressbookManager(void);

	//
	// This function is only for internal usage.
	//
	// @since	2.0
	//
	// @return	An error code
	//
	result Construct(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	AddressbookManager(const AddressbookManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	AddressbookManager& operator =(const AddressbookManager& rhs);

	static void InitAddressbookManager(void);
	static void DestroyAddressbookManager(void);

private:
	static AddressbookManager* __pInstance;
	friend struct std::default_delete< AddressbookManager >;

	friend class _AddressbookManagerImpl;
	class _AddressbookManagerImpl* __pAddressbookManagerImpl;
}; // AddressbookManager

}} // Tizen::Social

#endif //_FSCL_ADDRESSBOOK_MANAGER_H_
