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
 * @file		FSclCategoryChangeInfo.h
 * @brief		This is the header file for the %CategoryChangeInfo class.
 *
 * This header file contains the declarations of the %CategoryChangeInfo class.
 */
#ifndef _FSCL_CATEGORY_CHANGE_INFO_H_
#define _FSCL_CATEGORY_CHANGE_INFO_H_

#include <FBaseObject.h>
#include <FSclTypes.h>
#include <FSclRecord.h>

namespace Tizen { namespace Social
{

/**
 * @class	CategoryChangeInfo
 * @brief	This class provides a category change information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %CategoryChangeInfo class provides a category change information.
 *
 */
class _OSP_EXPORT_ CategoryChangeInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CategoryChangeInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CategoryChangeInfo
	 */
	CategoryChangeInfo(const CategoryChangeInfo& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~CategoryChangeInfo(void);

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
	 * Gets the addressbook ID of the changed category.
	 *
	 * @since	2.0
	 *
	 * @return	The addressbook ID
	 */
	AddressbookId GetAddressbookId(void) const;

	/**
	 * Gets the ID of the changed category.
	 *
	 * @since	2.0
	 *
	 * @return	The category ID
	 */
	RecordId GetCategoryId(void) const;

	/**
	 * Gets the version.
	 *
	 * @since	2.0
	 *
	 * @return	The version of the category
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
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CategoryChangeInfo
	 */
	CategoryChangeInfo& operator =(const CategoryChangeInfo& rhs);

private:
	friend class _CategoryChangeInfoImpl;
	class _CategoryChangeInfoImpl* __pCategoryChangeInfoImpl;

};	// CategoryChangeInfo

}}	// Tizen::Social

#endif // _FSCL_CATEGORY_CHANGE_INFO_H_
