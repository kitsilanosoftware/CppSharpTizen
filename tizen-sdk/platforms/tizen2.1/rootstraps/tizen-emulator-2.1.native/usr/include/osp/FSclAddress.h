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
 * @file	FSclAddress.h
 * @brief	This is the header file for the %Address class.
 *
 * This header file contains the declarations of the %Address class.
 */
#ifndef _FSCL_ADDRESS_H_
#define _FSCL_ADDRESS_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @if OSPDEPREC
 * The maximum length of the extended field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_ADDR_EXTENDED_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the street field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_ADDR_STREET_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the city field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_ADDR_CITY_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the state field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_ADDR_STATE_LENGTH = 50;

/**
 * @if OSPDEPREC
 * The maximum length of the postal code field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_ADDR_POSTAL_CODE_LENGTH = 20;

/**
 * @if OSPDEPREC
 * The maximum length of the country field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because the maximum length of the country name has been changed.
* @since	2.0
 * @endif
 */
static const int MAX_ADDR_COUNTRY_LENGTH = 20;

/**
 * @if OSPDEPREC
 * The maximum length of the post office box number field.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
* @since	2.0
 * @endif
 */
static const int MAX_ADDR_POBOXNUM_LENGTH = 20;

/**
 * @class	Address
 * @brief	This class represents the structured address type representing the ADR type definition of the vCard.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Address class represents the structured address type representing the ADR type definition of the vCard.
 *	It is based on the MIME directory profile specification (RFC 2426).
 * The address information consists of country, city, state, street, post office box number, postal code, and the address type.
 * This class represents the structured address type representing the ADR type definition of the vCard.
 * It is based on the MIME directory profile specification (RFC 2426).
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/social/addressbook_namespace.htm">Addressbook</a>.
 */
class _OSP_EXPORT_ Address
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * It creates a fully initialized instance of the %Address class.
	 *
	 * @since	2.0
	 */
	Address(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Address
	 */
	Address(const Address& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Address(void);

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
	 * Gets the type of the address.
	 *
	 * @since	2.0
	 *
	 * @return      The type of the address
	 */
	AddressType GetType(void) const;

	/**
	 */

	/**
	 * Gets the extended field of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The extended field of the address
	 */
	Tizen::Base::String GetExtended(void) const;

	/**
	 * Gets the street of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The street of the address
	 */
	Tizen::Base::String GetStreet(void) const;

	/**
	 * Gets the city of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The city of the address
	 */
	Tizen::Base::String GetCity(void) const;

	/**
	 * Gets the state of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The state of the address
	 */
	Tizen::Base::String GetState(void) const;

	/**
	 * Gets the postal code of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The postal code of the address
	 */
	Tizen::Base::String GetPostalCode(void) const;

	/**
	 * Gets the country of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The country of the address
	 */
	Tizen::Base::String GetCountry(void) const;

	/**
	 * Gets the post office box number of the address.
	 *
	 * @since	2.0
	 *
	 * @return	The post office box number of the address
	 */
	Tizen::Base::String GetPostOfficeBoxNumber(void) const;

	/**
	 * Sets the type of the address.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type	The address type to set
	 * @see	AddressType()
	 */
	void SetType(AddressType type);

	/**
	 * Sets the extended field of the address.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	extended		The new extended value to set
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetExtended(const Tizen::Base::String& extended);

	/**
	 */

	/**
	 * Sets the street of the address.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	street			The new street value to set
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetStreet(const Tizen::Base::String& street);

	/**
	 */

	/**
	 * Sets the city of the address.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	city			The new city value to set
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetCity(const Tizen::Base::String& city);

	/**
	 */

	/**
	 * Sets the state of the address.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	state			The new state value to set
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetState(const Tizen::Base::String& state);

	/**
	 */

	/**
	 * Sets the postal code of the address.
	 *
	 * @since	2.0
	 *
	 *
	 * @return		An error code
	 * @param[in]	postalCode		The new postal code value to set
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetPostalCode(const Tizen::Base::String& postalCode);

	/**
	 */

	/**
	 * Sets the country of the address.
	 *
	 * @since	2.0
	 *
	 *
	 * @return		An error code
	 * @param[in]	country			The new country value to set
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result SetCountry(const Tizen::Base::String& country);

	/**
	 */

	/**
	 * Sets the post office box number of the address.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	postOfficeBoxNumber		The new post office box number value to set
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetPostOfficeBoxNumber(const Tizen::Base::String& postOfficeBoxNumber);

	/**
	 */

	/**
	 * Gets the label of an address.
	 *
	 * @since	2.0
	 *
	 * @return	The address label
	 * @see SetLabel()
	 */
	Tizen::Base::String GetLabel(void) const;

	/**
	 * Sets the label of an address.
	 *
	 * @since	2.0
	 *
	 * @param[in]	label	The address label
	 * @see GetLabel()
	 */
	void SetLabel(const Tizen::Base::String& label);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Address
	 */
	Address& operator =(const Address& rhs);

	/**
	 * Compares the specified instance of %Address with the calling instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data of the specified instance is equal to the data of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		The source data
	 */
	bool operator ==(const Address& rhs) const;

	/**
	 * Compares the specified instance to the calling instance for inequality.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data of the specified instance is not equal to the data of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		The source data
	 */
	bool operator !=(const Address& rhs) const;

private:
	friend class _AddressImpl;
	class _AddressImpl* __pAddressImpl;
}; // Address

}} // Tizen::Social

#endif //_FSCL_ADDRESS_H_
