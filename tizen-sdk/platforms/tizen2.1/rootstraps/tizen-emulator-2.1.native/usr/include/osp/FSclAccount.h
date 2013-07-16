//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file	FSclAccount.h
 * @brief	This is the header file for the %Account class.
 *
 * This header file contains the declarations of the %Account class.
 */
#ifndef _FSCL_ACCOUNT_H_
#define _FSCL_ACCOUNT_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;
namespace Collection
{
class IMap;
}
}}

namespace Tizen { namespace Social
{
class AccountProvider;

/**
 * @class	Account
 * @brief	This class represents the account information.
 * @since	2.1
 *
 * @final	This class is not intended for extension.
 *
 * This %Account class represents the account information.
 */
class _OSP_EXPORT_ Account
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * It creates a fully initialized instance of the %Account class.
	 *
	 * @since		2.1
	 *
	 * @param[in]	userName		The user name
	 */
	Account(const Tizen::Base::String& userName);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs		An instance of %Account
	 */
	Account(const Account& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~Account(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.1
	 *
	 * @return	An integer value indicating the hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the ID of an account.
	 *
	 * @since	2.1
	 *
	 * @return	The account ID
	 */
	AccountId GetId(void) const;

	/**
	 * Gets the account provider.
	 *
	 * @since	2.1
	 *
	 * @return	The account provider
	 */
	AccountProvider GetAccountProvider(void) const;

	/**
	 * Gets the user name.
	 *
	 * @since	2.1
	 *
	 * @return	The user name
	 */
	Tizen::Base::String GetUserName(void) const;

	/**
	 * Gets the extended data.
	 *
	 * @since	2.1
	 *
	 * @return	The key-value lists of the extended data, @n
	 *				else an empty list if there is no extended data, or @c null if an exception occurs (String, String list)
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IMap* GetExtendedDataN(void) const;

	/**
	 * Sets the user name.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	userName		The user name
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c userName is an empty string.
	 */
	result SetUserName(const Tizen::Base::String& userName);

	/**
	 * Sets the extended data with the specified @c key and @c value. @n
	 * If the specified @c key already exists, the corresponding value is overwritten with the specified @c value.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	key				The key of the extended data
	 * @param[in]	value			The value of the extended data
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c key is an empty string.
	 */
	result SetExtendedData(const Tizen::Base::String& key, const Tizen::Base::String& value);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs		An instance of %Account
	 */
	Account& operator =(const Account& rhs);

private:
	friend class _AccountImpl;
	class _AccountImpl* __pAccountImpl;

}; // Account

}} // Tizen::Social

#endif //_FSCL_ACCOUNT_H_
