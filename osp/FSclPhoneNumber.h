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
* @file		FSclPhoneNumber.h
* @brief	This is the header file for the %PhoneNumber class.
*
* This header file contains the declarations of the %PhoneNumber class.
*/
#ifndef _FSCL_PHONE_NUMBER_H_
#define _FSCL_PHONE_NUMBER_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
* @class	PhoneNumber
* @brief	This class stores the information of a phone number.
*
* @since	2.0
*
* @final	This class is not intended for extension.
*
* The %PhoneNumber class consists of the phone number and phone number type.
*
* The following example demonstrates how to use the %PhoneNumber class.
*
* @code
using namespace Tizen::Base;
using namespace Tizen::Social::Services;

void
MyClass::SomeMethod(void)
{
	result r = E_SUCCESS;

	// Creates an instance of PhoneNumber
	PhoneNumber phoneNumber = PhoneNumber();

	// Sets the number
	r = phoneNumber.SetPhoneNumber(L"010-111-2222");
	if (IsFailed(r))
	{
		return r;
	}

	// Sets the type
	phoneNumber.SetType(PHONENUMBER_TYPE_MOBILE);

	return E_SUCCESS;
}
* @endcode
*/
class _OSP_EXPORT_ PhoneNumber
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
 	 *
	 * @since	2.0
	 */
	PhoneNumber(void);

	/**
	 * Initializes this instance of %PhoneNumber with the specified type and phone number.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type		The type of the phone number
	 * @param[in]	number		The phone number
	 */
	PhoneNumber(PhoneNumberType type, const Tizen::Base::String& number);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %PhoneNumber
	 */
	PhoneNumber(const PhoneNumber& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~PhoneNumber(void);

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
     * Gets the type of the phone number.
     *
	 * @since	2.0
	 *
     * @return	The type of the phone number
     */
	PhoneNumberType GetType(void) const;

	/**
	 */

	/**
	 * Gets the phone number.
	 *
	 * @since	2.0
	 *
	 * @return	The phone number
	 */
	Tizen::Base::String GetPhoneNumber(void) const;

	/**
	 * Sets the type of the phone number.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type		The type of the phone number
	 */
	void SetType(PhoneNumberType type);

	/**
	 * Sets the specified phone number.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	number		The phone number to set
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified number is an empty string.
	 */
	result SetPhoneNumber(const Tizen::Base::String& number);

	/**
	 */

	/**
	 * Gets the label of a phone number.
	 *
	 * @since	2.0
	 *
	 * @return	The phone number label
	 * @see SetLabel()
	 */
	Tizen::Base::String GetLabel(void) const;

	/**
	 * Sets the label of an event. 
	 *
	 * @since	2.0
	 *
	 * @param[in]	label	The phone number label
	 * @see GetLabel()
	 */
	void SetLabel(const Tizen::Base::String& label);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %PhoneNumber
	 */
	PhoneNumber& operator =(const PhoneNumber& rhs);

	/**
	 * Checks whether the data in the specified instance of %PhoneNumber is equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance equals the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %PhoneNumber
	 */
	bool operator ==(const PhoneNumber& rhs) const;

	/**
	 * Checks whether the data in the specified instance of %PhoneNumber is not equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %PhoneNumber
	 */
	bool operator !=(const PhoneNumber& rhs) const;

private:
	friend class _PhoneNumberImpl;
	class _PhoneNumberImpl * __pPhoneNumberImpl;

}; // PhoneNumber

}} // Tizen::Social

#endif // _FSCL_PHONE_NUMBER_H_
