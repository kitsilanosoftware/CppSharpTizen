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
 * @file		FSclCalTodoChangeInfo.h
 * @brief	This is the header file for the %CalTodoChangeInfo class.
 *
 * This header file contains the declarations of the %CalTodoChangeInfo class.
 */
#ifndef _FSCL_CAL_TODO_CHANGE_INFO_H_
#define _FSCL_CAL_TODO_CHANGE_INFO_H_

#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @class	CalTodoChangeInfo
 * @brief	This class represents the calendar to-do change information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 *	The %CalTodoChangeInfo class represents the change information of a to-do that is managed in calendarbook.
 */
class _OSP_EXPORT_ CalTodoChangeInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CalTodoChangeInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalTodoChangeInfo
	 */
	CalTodoChangeInfo(const CalTodoChangeInfo& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~CalTodoChangeInfo(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %CalTodoChangeInfo instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %CalTodoChangeInfo instance, @n
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
	 * Gets the change type.
	 *
	 * @since	2.0
	 *
	 * @return		The change type
	 */
	RecordChangeType GetChangeType(void) const;

	/**
	 * Gets the changed to-do ID.
	 *
	 * @since	2.0
	 *
	 * @return		The changed to-do ID
	 */
	RecordId GetTodoId(void) const;

	/**
	 * Gets the calendar ID to which the changed to-do belongs.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar ID to which the changed to-do belongs
	 */
	RecordId GetCalendarId(void) const;

	/**
	 * Gets the version of the change.
	 *
	 * @since	2.0
	 *
	 * @return		The version of the change
	 */
	int GetVersion(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalTodoChangeInfo
	 */
	CalTodoChangeInfo& operator =(const CalTodoChangeInfo& rhs);

private:
	friend class _CalTodoChangeInfoImpl;
	class _CalTodoChangeInfoImpl* __pCalTodoChangeInfoImpl;

};	// CalTodoChangeInfo

}}	// Tizen::Social

#endif // _FSCL_CAL_TODO_CHANGE_INFO_H_

