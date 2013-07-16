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
 * @file	FSclCategory.h
 * @brief	This is the header file for the %Category class.
 *
 * This header file contains the declarations of the %Category class.
 */
#ifndef _FSCL_CATEGORY_H_
#define _FSCL_CATEGORY_H_

#include <FBaseResult.h>
#include <FBaseString.h>
#include <FSclRecord.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @class	Category
 * @brief	This class represents a category in the contact database.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Category class represents a category in the contact database. Each contact can belong to multiple categories.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/category.htm">Category</a>.
 */
class _OSP_EXPORT_ Category
	: public Record
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @remarks		In order to add a new category to Addressbook, the category name needs to be set using SetName().
	 * @see			Addressbook::AddCategory()
	 */
	Category(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param [in]	rhs		An instance of %Category
	 */
	Category(const Category& rhs);

	/**
	 * This destructor overrides Tizen::Social::Record::~Record().
	 *
	 * @since	2.0
	 */
	virtual ~Category(void);

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
	 * @if OSPDEPREC
	 * Adds the specified contact to the category.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated. Instead of using this method, use Addressbook::AddMemberToCategory().
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c contactId is already a member of this category.
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @endif
	 */
	result AddMember(RecordId contactId);

	/**
	 * Gets the total number of members in the category.
	 *
	 * @since	2.0
	 *
	 * @return	The number of members in the category
	 */
	int GetMemberCount(void) const;

	/**
	 * Gets the name of the category.
	 *
	 * @since	2.0
	 *
	 * @return	The name of the category
	 * @see SetName()
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * @if OSPDEPREC
	 * Checks whether the category contains the specified contact.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated. Instead of using this method, use Addressbook::GetCategoriesByContactN().
	 * @since	2.0
	 *
	 * @return	@c true if the category contains the specified contact, @n
	 *				else @c false
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c contactId is invalid.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	bool HasMember(RecordId contactId) const;

	/**
	 * @if OSPDEPREC
	 * Removes the specified contact from the category.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated. Instead of using this method, use Addressbook::RemoveMemberFromCategory().
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param [in]	contactId		The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c contactId is invalid.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @endif
	 */
	result RemoveMember(RecordId contactId);

	/**
	 * Sets the specified @c name for the category.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param [in]	name			The category name
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c name is an empty string.
	 * @exception   E_INVALID_OPERATION     This category is a default category.
	 * @remarks 	It is not allowed to change the name of a default category.
 	 * @see GetName()
	 * @see	IsDefault()
	 */
	result SetName(const Tizen::Base::String& name);

	/**
	 */

	/**
	 * Sets the specified ringtone for the category.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param [in]	filePath		The file path of the ringtone
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified @c filePath exceeds system limitations.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @see GetRingtonePath()
	 */
	result SetRingtonePath(const Tizen::Base::String& filePath);

	/**
	 * Gets the ringtone for the category.
	 *
	 * @since	2.0
	 *
	 * @return	The file path of the ringtone
	 * @see SetRingtonePath()
	 */
	Tizen::Base::String GetRingtonePath(void) const;

	/**
	 * Checks whether this category is a default category or not. @n
	 * If a category is default, it is not possible to update the category’s name and delete the category.
	 * However it is still possible to add or remove contacts and change thumbnail and ringtone.
	 *  
	 * @since	2.0
	 *
	 * @return     @c true if this is a default category, @n
	 *             else @c false
	 */
	bool IsDefault(void) const;   

	/**
	 * Sets the thumbnail image. @n
	 * If the specified @c filePath is an empty string, the thumbnail of this category is reset.
	 *
	 * @since	2.0
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
	 * Gets the thumbnail path.
	 *
	 * @since	2.0
	 *
	 * @return     The file path of the thumbnail
	 * @remarks    If the thumbnail has not been set, an empty string is returned.
	 */
	Tizen::Base::String GetThumbnailPath(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param [in]	rhs		An instance of %Category
	 */
	Category& operator =(const Category& rhs);

private:
	friend class _CategoryImpl;
	class _CategoryImpl* __pCategoryImpl;
};	// Category

}}	// Tizen::Social

#endif // _FSCL_CATEGORY_H_
