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
 * @file	FSclRecord.h
 * @brief	This is the header file for the %Record class.
 *
 * This header file contains the declarations of the %Record class.
 */

#ifndef _FSCL_RECORD_H_
#define _FSCL_RECORD_H_

#include <FBaseObject.h>
#include <FBaseColIList.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @enum RecordType
 *
 * Defines the possible types of a record.
 *
 * @since	2.0
 */
enum RecordType
{
	RECORD_TYPE_CONTACT = 0x01,	 /**< The contact type */
	RECORD_TYPE_CATEGORY = 0x02,	/**< The category type */
	RECORD_TYPE_EVENT = 0x04,		/**< The event type */
	RECORD_TYPE_TODO = 0x08,		 /**< The to-do type */
	RECORD_TYPE_CALENDAR = 0x10		 /**< The calendar type */
};

/**
 * @class	Record
 * @brief	This class defines the general behavior of records used in the Social namespace.
 *
 * @since	2.0
 *
 * The %Record class defines the general behavior of records used in the Social namespace. Users cannot create an instance directly from this
 *	class. Instead, instantiate the classes derived from %Record.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/social_records.htm">Social Records</a>.
 */
class _OSP_EXPORT_ Record
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the type of the record.
	 *
	 * @since	2.0
	 *
	 * @return	The type of the record
	 */
	RecordType GetRecordType(void) const;

	/**
	 * Gets the local-wide unique ID of the current instance of %Record. @n
	 * The @c RecordId is assigned by an address book when a record is added to it. @n
	 * A newly constructed record instance has @c INVALID_RECORD_ID.
	 *
	 * @since	2.0
	 *
	 * @return	The ID of the record
	 */
	RecordId GetRecordId(void) const;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Initializes this instance of %Record with the specified type.
	//
	// @since	2.0
	//
	// @param[in]	type	The record type
	//
	Record(RecordType type);

	//
	// This copy constructor is intentionally declared as private to prohibit copying of objects by users.
	//
	// @since	2.0
	//
	// @param[in]	rhs		The source instance of %Record
	//
	Record(const Record& rhs);

	//
	// This destructor is intentionally declared as private so that only the platform can delete an instance.
	//
	// @since	2.0
	//
	virtual ~Record(void);

	//
	// This copy assignment operator is intentionally declared as private to prohibit copying of objects by users.
	//
	// @since	2.0
	//
	// @param[in]	rhs		An instance of %Record
	//
	Record& operator =(const Record& rhs);

private:
	friend class _RecordImpl;
	class _RecordImpl* __pRecordImpl;

}; // Record

}} // Tizen::Social

#endif // _FSCL_RECORD_H_
