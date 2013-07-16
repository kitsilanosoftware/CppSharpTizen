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
 * @file		FSclContactChangeInfo.h
 * @brief		This is the header file for the %ContactChangeInfo class.
 *
 * This header file contains the declarations of the %ContactChangeInfo class.
 */
#ifndef _FSCL_CONTACT_CHANGE_INFO_H_
#define _FSCL_CONTACT_CHANGE_INFO_H_

#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @class	ContactChangeInfo
 * @brief	This class provides a contact change information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ContactChangeInfo class provides a contact change information.
 *
 */
class _OSP_EXPORT_ ContactChangeInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ContactChangeInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %ContactChangeInfo
	 */
	ContactChangeInfo(const ContactChangeInfo& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ContactChangeInfo(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of Tizen::Base::Object to compare
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
	 * Gets the addressbook ID of the changed contact.
	 *
	 * @since	2.0
	 *
	 * @return	The addressbook ID
	 */
	AddressbookId GetAddressbookId(void) const;

	/**
	 * Gets the ID of the changed contact.
	 *
	 * @since	2.0
	 *
	 * @return	The contact ID
	 */
	RecordId GetContactId(void) const;

	/**
	 * Gets the version.
	 *
	 * @since	2.0
	 *
	 * @return	The version of the contact
	 */
	int GetVersion(void) const;

	/**
	 * Gets the change type.
	 *
	 * @since	2.0
	 *
	 * @return	The change type
	 */
	RecordChangeType GetChangeType(void) const;

	/**
	 * Checks whether the thumbnail has been changed or not.
	 *
	 * @since       2.1
	 *
	 * @return     @c true if the thumbnail has been changed, @n
	 *              else @c false
	 */
	bool IsThumbnailChanged(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %ContactChangeInfo
	 */
	ContactChangeInfo& operator =(const ContactChangeInfo& rhs);

private:
	friend class _ContactChangeInfoImpl;
	class _ContactChangeInfoImpl* __pContactChangeInfoImpl;

};	// ContactChangeInfo

}}	// Tizen::Social

#endif // _FSCL_CONTACT_CHANGE_INFO_H_
