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
* @file		FSclAccountManager.h
* @brief	This is the header file for the %AccountManager class.
*
* This header file contains the declarations of the %AccountManager class.
*/
#ifndef _FSCL_ACCOUNT_MANAGER_H_
#define _FSCL_ACCOUNT_MANAGER_H_

#include <unique_ptr.h>
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
class AccountProvider;

/**
 * @class	AccountManager
 * @brief	This class provides the method for managing accounts.
 * @since	2.1
 *
 * @final	This class is not intended for extension.
 *
 * The %AccountManager class provides the method for managing accounts.
 */
class _OSP_EXPORT_ AccountManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Adds an account. @n
	 * The user name must be set in the account.
	 * If the account is added successfully, an account ID is newly assigned to it.
	 * The %AddAccount() method can be used only by the application belonging to a package of an application that registers its own account provider.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.write
	 *
	 * @return			An error code
	 * @param[in,out]	account					The account to add
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 											- The user name is an empty string in the specified @c account. @n
	 * 											- The account ID is not #INVALID_ACCOUNT_ID. @n
	 * @exception		E_INVALID_OPERATION		Either of the following conditions has occurred: @n
	 * 											- The caller application does not belong to a package of an application that registers its own account provider. @n
	 * 											- The account has already been added with the multiple accounts support set to @c false.
	 * @exception		E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result AddAccount(Account& account);

	/**
	 * Removes an account. @n
	 * The %RemoveAccount() method can be used only by an application belonging to a package of an application that registers its own account provider.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.write
	 *
	 * @return		An error code
	 * @param[in]	accountId				The account ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c accountId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c accountId does not exist.
	 * @exception	E_INVALID_OPERATION		This operation is not allowed if the caller application does not belong to a package of an application that registers its own account provider.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result RemoveAccount(AccountId accountId);

	/**
	 * Updates an account. @n
	 * The user name must be set in an account.
	 * The %UpdateAccount() method can be used only by an application belonging to a package of an application that registers its own account provider.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/account.write
	 *
	 * @return		An error code
	 * @param[in]	account					The account to update
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 										- The user name is an empty string in the specified @c account. @n
	 * 										- The account ID is invalid. @n
	 * @exception	E_OBJ_NOT_FOUND			The specified @c account does not exist.
	 * @exception	E_INVALID_OPERATION		This operation is not allowed if the caller application does not belong to a package of an application that registers its own account provider.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 */
	result UpdateAccount(const Account& account);

	/**
	 * Gets the %AccountManager instance.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the %AccountManager instance, @n
	 *				else @c null if it fails
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static AccountManager* GetInstance(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since		2.1
	//
	AccountManager(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since		2.1
	//
	virtual ~AccountManager(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		2.1
	//
	AccountManager(const AccountManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		2.1
	//
	AccountManager& operator =(const AccountManager& rhs);

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
	static void InitAccountManager(void);

	//
	// Destroys an instance of this class.
	//
	// @since		2.1
	//
	static void DestroyAccountManager(void);

private:
	static AccountManager* __pInstance;
	friend struct std::default_delete<AccountManager>;

	friend class _AccountManagerImpl;
	class _AccountManagerImpl* __pAccountManagerImpl;

};	// AccountManager

}}	// Tizen::Social

#endif //_FSCL_ACCOUNT_MANAGER_H_
