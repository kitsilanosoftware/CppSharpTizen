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
* @file		FSclContactEvent.h
* @brief	This is the header file for the %ContactEvent class.
*
* This header file contains the declarations of the %ContactEvent class.
*/
#ifndef _FSCL_CONTACT_EVENT_H_
#define _FSCL_CONTACT_EVENT_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseDateTime.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
* @class	ContactEvent
* @brief	This class represents an event.
*
* @since	2.0
*
* @final	This class is not intended for extension.
*
* The %ContactEvent class represents an event. An event consists of the event date, type, and label. 
*
*/
class _OSP_EXPORT_ ContactEvent
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ContactEvent(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %ContactEvent
	 */
	ContactEvent(const ContactEvent& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ContactEvent(void);

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
	 * Gets the hash value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	An integer value indicating the hash value of the current instance of Tizen::Base::Object
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the event type.
	 *
	 * @since	2.0
	 *
	 * @return	The type of the event
	 */
	ContactEventType GetType(void) const;

	/**
	 * Gets the event date.
	 *
	 * @since	2.0
	 *
	 * @return	The event date
	 */
	Tizen::Base::DateTime GetDate(void) const;

	/**
	 * Gets the label of an event.
	 *
	 * @since	2.0
	 *
	 * @return	The event label
	 * @see SetLabel()
	 */
	Tizen::Base::String GetLabel(void) const;

	/**
	 * Sets the event type.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type	The type of the event
	 */
	void SetType(ContactEventType type);

	/**
	 * Sets the label of an event. 
	 *
	 * @since	2.0
	 *
	 * @param[in]	label	The event label
	 * @see GetLabel()
	 */
	void SetLabel(const Tizen::Base::String& label);

	/**
	 * Sets the event date. @n
	 * The time portion of Tizen::Base::DateTime is ignored. The default time is 00:00:00.
	 *
	 * @since	2.0
	 *
	 * @param[in]	date	The event date
	 */
	void SetDate(const Tizen::Base::DateTime& date);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %ContactEvent
	 */
	ContactEvent& operator =(const ContactEvent& rhs);

	/**
	 * Checks whether the data in the specified instance of %ContactEvent is equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance equals the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ContactEvent
	 */
	bool operator ==(const ContactEvent& rhs) const;

	/**
	 * Checks whether the data in the specified instance of %ContactEvent is not equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ContactEvent
	 */
	bool operator !=(const ContactEvent& rhs) const;

private:
	friend class _ContactEventImpl;
	class _ContactEventImpl* __pContactEventImpl;

}; // ContactEvent

}} // Tizen::Social

#endif // _FSCL_CONTACT_EVENT_H_
