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
  * @file		FSclCalEventChangeInfo.h
  * @brief	This is the header file for the %CalEventChangeInfo class.
  *
  * This header file contains the declarations of the %CalEventChangeInfo class.
  */
#ifndef _FSCL_CAL_EVENT_CHANGE_INFO_H_
#define _FSCL_CAL_EVENT_CHANGE_INFO_H_

#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @class	CalEventChangeInfo
 * @brief	This class represents the calendar event change information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 *	The %CalEventChangeInfo class represents the change information of an event that is managed in calendarbook.
 */
class _OSP_EXPORT_ CalEventChangeInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CalEventChangeInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %CalEventChangeInfo
	 */
	CalEventChangeInfo(const CalEventChangeInfo& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~CalEventChangeInfo(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %CalEventChangeInfo instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %CalEventChangeInfo instance, @n
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
	 * Gets the changed event ID.
	 *
	 * @since	2.0
	 *
	 * @return		The changed event ID
	 */
	RecordId GetEventId(void) const;

	/**
	 * Gets the calendar ID to which the changed event belongs.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar ID to which the changed event belongs
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
	 * @param[in]	rhs		An instance of %CalEventChangeInfo
	 */
	CalEventChangeInfo& operator =(const CalEventChangeInfo& rhs);

private:
	friend class _CalEventChangeInfoImpl;
	class _CalEventChangeInfoImpl* __pCalEventChangeInfoImpl;

};	// CalEventChangeInfo

}}	// Tizen::Social

#endif // _FSCL_CAL_EVENT_CHANGE_INFO_H_

