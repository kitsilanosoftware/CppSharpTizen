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
 * @file	FSclCalendar.h
 * @brief	This is the header file for the %Calendar class.
 *
 * This header file contains the declarations of the %Calendar class.
 */
#ifndef _FSCL_CALENDAR_H_
#define _FSCL_CALENDAR_H_

#include <FBaseDataType.h>
#include <FSclTypes.h>
#include <FSclRecord.h>

namespace Tizen { namespace Base
{
class Object;
class String;
}}

namespace Tizen { namespace Social
{

/**
 * @class	Calendar
 * @brief	This class represents calendar information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Calendar class represents calendar information. @n
 * Multiple calendars can be created, each of which can have its own events and to-dos. An event or to-do can be retrieved using the respective calendar ID.
 */
class _OSP_EXPORT_ Calendar
	: public Record
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	itemType			The calendar item type to specify which kind of item the calendar can contain
	 */
	explicit Calendar(CalendarItemType itemType);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Calendar
	 */
	Calendar(const Calendar& rhs);

	/**
	 * This destructor overrides Tizen::Social::Record::~Record().
	 *
	 * @since	2.0
	 */
	virtual ~Calendar(void);

	/**
	 * Compares the input Tizen::Base::Object with the calling %Calendar instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the input object equals the calling %Calendar instance, @n
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
	 * Gets the calendar name.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar name
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the calendar item type.
	 *
	 * @since	2.0
	 *
	 * @return		The calendar item type
	 */
	CalendarItemType GetItemType(void) const;

	/**
	 * Gets the account ID.
	 *
	 * @since	2.0
	 *
	 * @return		The account ID
	 */
	AccountId GetAccountId(void) const;

	/**
	 * Gets the calendar color. @n
	 * If the color has not been set, all color components are set with 0x0 and E_DATE_NOT_FOUND exception is returned.
	 *
	 * @since	2.0
	 *
	 * @param[out]		r		The red component
	 * @param[out]		g		The green component
	 * @param[out]		b		The blue component
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_DATA_NOT_FOUND		The color has not been set.
	 */
	result GetColor(byte& r, byte& g, byte& b) const;

	/**
	 * Sets the calendar name.
	 *
	 * @since	2.0
	 *
	 * @param[in]	name					The calendar name
	 */
	void SetName(const Tizen::Base::String& name);

	/**
	 * Sets the calendar color.
	 *
	 * @since	2.0
	 *
	 * @param[in]		r		The red component
	 * @param[in]		g		The green component
	 * @param[in]		b		The blue component
	 */
	void SetColor(byte r, byte g, byte b);

	/**
	 * Clears the calendar color.
	 *
	 * @since	2.0
	 */
	void ClearColor(void);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Calendar
	 */
	Calendar& operator =(const Calendar& rhs);

private:
	friend class _CalendarImpl;
	class _CalendarImpl* __pCalendarImpl;

};	// Calendar

}}	// Tizen::Social

#endif // _FSCL_CALENDAR_H_
