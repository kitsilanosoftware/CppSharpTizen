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
* @file		FSclAccountAccessor.h
* @brief	This is the header file for the %AccountAccessor class.
*
* This header file contains the declarations of the %AccountAccessor class.
*/
#ifndef _FSCL_ACCOUNT_ACCESSOR_H_
#define _FSCL_ACCOUNT_ACCESSOR_H_

#include <unique_ptr.h>
#include <FAppTypes.h>
#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;

namespace Collection
{
class IList;
}
}}

namespace Tizen { namespace Social
{
class Account;
class IAccountEventListener;

/**
 * @class	AccountAccessor
 * @brief	This class provides methods for accessing accounts and account providers.
 * @since	2.1
 *
 * @final	This class is not intended for extension.
 *
 * This %AccountAccessor class provides methods for accessing accounts and account providers.
 */
class _OSP_EXPORT_ AccountAccessor
	: public Tizen::Base::Object
{
public:
	/**
	 * Sets an account change event listener that is called when an account is changed. @n
	 * To reset the event listener, @c null must be passed.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		An error code
	 * @param[in]	pListener				The event listener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @remarks		The platform will not take the ownership of @c pListener after this call.
	 */
	result SetEventListener(IAccountEventListener* pListener);

	/**
	 * Gets an account with a specified account ID.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		An account with the specified @c accountId
	 * @param[in]	accountId				The account ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c accountId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c accountId is not found.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Account GetAccount(AccountId accountId) const;

	/**
	 * Gets accounts associated with the account provider that has a specified application ID.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		A list of accounts, @n
	 * 					else an empty list if there is no account, or @c null if an exception occurs (@ref Account list)
	 * @param[in]	accountProviderAppId	The application ID of the account provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c accountProviderAppId is empty.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAccountsByAccountProviderN(const Tizen::App::AppId& accountProviderAppId) const;

	/**
	 * Gets all accounts.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		A list of accounts, @n
	 *					else an empty list if there is no account, or @c null if an exception occurs (@ref Account list)
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAllAccountsN(void) const;

	/**
	 * Gets an account provider with a specified application ID.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		An account provider with the specified @c accountProviderAppId ID
	 * @param[in]	accountProviderAppId	The application ID of the account provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c accountProviderAppId is empty.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c accountProviderAppId is not found.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	AccountProvider GetAccountProvider(const Tizen::App::AppId& accountProviderAppId) const;

	/**
	 * Gets account providers that have the specified @c capability.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		A list of account providers, @n
	 * 					else an empty list if there is no account provider, or @c null if an exception occurs (@ref AccountProvider list)
	 * @param[in]	capability				The predefined capability or the vendor-specific capability defined as the IRI format
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c capability is empty.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAccountProvidersByCapabilityN(const Tizen::Base::String& capability) const;

	/**
	 * Gets all currently registered account providers.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.read
	 *
	 * @return		A list of account providers, @n
	 *					else an empty list if there is no account provider, or @c null if an exception occurs (@ref AccountProvider list)
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAllAccountProvidersN(void) const;

	/**
	 * Gets the %AccountAccessor instance.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the %AccountAccessor instance, @n
	 *					else @c null if it fails
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static AccountAccessor* GetInstance(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since		2.1
	//
	AccountAccessor(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since		2.1
	//
	virtual ~AccountAccessor(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		2.1
	//
	AccountAccessor(const AccountAccessor& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		2.1
	//
	AccountAccessor& operator =(const AccountAccessor& rhs);

	//
	// Constructs an instance of this class.
	//
	// @since		2.1
	//
	// @return		An error code
	// @exception	E_SUCCESS			The method is successful.
	// @exception   E_SYSTEM			The method cannot proceed due to a severe system error.
	//
	result Construct(void);

	//
	// Initializes an instance of this class.
	//
	// @since		2.1
	//
	static void InitAccountAccessor(void);

	//
	// Destroys an instance of this class.
	//
	// @since		2.1
	//
	static void DestroyAccountAccessor(void);

private:
	static AccountAccessor* __pInstance;
	friend struct std::default_delete<AccountAccessor>;

	friend class _AccountAccessorImpl;
	class _AccountAccessorImpl* __pAccountAccessorImpl;

};	// AccountAccessor

}}	// Tizen::Social

#endif //_FSCL_ACCOUNT_ACCESSOR_H_
