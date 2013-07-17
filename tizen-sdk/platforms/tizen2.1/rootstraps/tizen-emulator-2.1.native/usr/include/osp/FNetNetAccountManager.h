//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FNetNetAccountManager.h
 * @brief		This is the header file for the %NetAccountManager class.
 *
 * This header file contains the declarations of the %NetAccountManager class.
 */
#ifndef _FNET_NET_ACCOUNT_MANAGER_H_
#define _FNET_NET_ACCOUNT_MANAGER_H_

#include <FBaseString.h>
#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseColIList.h>
#include <FBaseColArrayList.h>
#include <FBaseColArrayListT.h>
#include <FNetNetTypes.h>
#include <FNetNetAccountInfo.h>

namespace Tizen { namespace Net
{
class _NetAccountManagerImpl;

/**
 * @class	NetAccountManager
 * @brief	This class provides methods for creating, deleting, and administering network accounts in the system.
 *
 * @since	2.0
 *
 * The %NetAccountManager class provides methods for creating, deleting, and administering components that can be used for configuring the
 * network accounts. These accounts can then be used for connecting to the network.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/network_accounts.htm">Network Accounts</a>.
 */
class _OSP_EXPORT_ NetAccountManager
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	NetAccountManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~NetAccountManager(void);

	/**
	 * Initializes this instance of %NetAccountManager.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An internal initialization procedure has failed.
	 */
	result Construct(void);

public:
	/**
	 * Creates a new network account.
	 *
	 * @since			2.0
	 *
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/network.account
	 * @feature			%http://tizen.org/feature/network.telephony
	 *
	 * @return			The @c NetAccountId assigned by the creation of a new network account, @n
	 *					else @c	INVALID_HANDLE if an error occurs
	 * @param[in,out]	netAccountInfo		A NetAccountInfo instance containing network information to create an account
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_MAX_EXCEEDED		The registry is full. @n Cannot create a new network account.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception		E_UNSUPPORTED_OPERATION	The target device does not support the required feature. @b Since: @b 2.1
	 * 						For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 * 					- This method creates a new network account and returns a @c NetAccountId value that can be used in method calls later to operate on the
	 * 						account. If @c INVALID_HANDLE is returned, the specific error code can be accessed using the GetLastResult() method. A Wi-Fi account
	 * 						cannot be created using %NetAccountManager.
	 * 					- Before calling this method, check whether the feature is supported by 
	 *					Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see				GetNetAccountInfoN()
	 * @see				UpdateNetAccount()
	 * @see				DeleteNetAccount()
	 */
	NetAccountId CreateNetAccount(NetAccountInfo& netAccountInfo);

	/**
	 * Deletes a network account from the registry. @n
	 * If the account is read-only or in service, the deletion fails. The Wi-Fi accounts cannot be deleted by %NetAccountManager.
	 *
	 * @since		2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/network.account
	 *
	 * @return		An error code
	 * @param[in]	netAccountId		A NetAccountId instance containing valid account information
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ACCOUNT	The specified network account is invalid.
	 * @exception	E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		If the network account is created by another application, this method fails.
	 *				This method must use a warning pop-up to notify the user.
	 * @see			CreateNetAccount()
	 * @see			GetNetAccountInfoN()
	 * @see			UpdateNetAccount()
	 */
	result DeleteNetAccount(NetAccountId netAccountId);

	/**
	 * Updates an existing network account.
	 *
	 * @since			2.0
	 *
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/network.account
	 * @feature			%http://tizen.org/feature/network.telephony
	 *
	 * @return			An error code
	 * @param[in]		netAccountInfo		A NetAccountInfo instance containing network information to update an account
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception		E_INVALID_ACCOUNT	The input is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception		E_UNSUPPORTED_OPERATION	The target device does not support the required feature. @b Since: @b 2.1
	 * 						For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 * 					- This method fails if the network account is read-only, in service, or created by another application.
	 * 						A Wi-Fi account cannot be updated using %NetAccountManager.
	 * 						This method must use a warning pop-up to notify the user.
	 * 					- Before calling this method, check whether the feature is supported by 
	 *					Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see				CreateNetAccount()
	 * @see				GetNetAccountInfoN()
	 * @see				UpdateNetAccount()
	 * @see				DeleteNetAccount()
	 */
	result UpdateNetAccount(const NetAccountInfo& netAccountInfo);

	/**
	 * Updates an existing system network account.
	 *
	 * @since       2.0
	 *
	 * @privlevel   platform
	 * @privilege   %http://tizen.org/privilege/networkmanager
	 * @feature		%http://tizen.org/feature/network.telephony for the NET_BEARER_PS value and @n
	 * 				%http://tizen.org/feature/network.telephony.mms for the NET_BEARER_MMS value of @c netAccountInfo.GetBearerType()
	 *
	 * @return      An error code
	 * @param[in]   netAccountInfo         A NetAccountInfo instance containing network information to update an account
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_INVALID_ARG          The specified input parameter is invalid.
	 * @exception   E_INVALID_ACCOUNT      The input account ID is invalid.
	 * @exception   E_OPERATION_FAILED     This request operation has failed due to an internal error.
	 * @exception   E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
	 * @exception	E_UNSUPPORTED_OPERATION	The target device does not support the required feature. @b Since: @b 2.1
	 * 					For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks		Before calling this method, check whether the feature is supported by 
	 *				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         GetNetAccountInfoN()
	 * @see			UpdateNetAccount()
	 */
	result UpdateSystemNetAccount(const NetAccountInfo& netAccountInfo);

	/**
	 * Gets the information on a network account.
	 *
	 * @since			2.0
	 *
	 * @return			A NetAccountInfo instance containing account information
	 * @param[in]		netAccountId		The account ID whose information is required
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ACCOUNT	The specified network account is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception		E_INVALID_PROXY		The proxy address is invalid.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @remarks			This method returns:
	 *					- the NetAccountInfo instance for a PS account (NET_BEARER_PS) @n
	 *					- the WifiNetAccountInfo instance for a WLAN account (NET_BEARER_WIFI) in the %NetAccountInfo type @n
	 *					The Wi-Fi account info contains the default %NetAccountInfo and additional Wi-Fi specific information. @n
	 *					To determine the type of instance returned, use the GetBearerType() method.
	 *					The instance can then be cast down to %WifiNetAccountInfo and used in a NET_BEARER_WIFI case. If the
	 *					application gets the last result by E_INVALID_PROXY, it must use a warning pop-up to notify the user.
	 * @see				CreateNetAccount()
	 * @see				UpdateNetAccount()
	 * @see				DeleteNetAccount()
	 */
	NetAccountInfo* GetNetAccountInfoN(NetAccountId netAccountId) const;

	/**
	 * Gets a list of all the accounts in the registry.
	 *
	 * @since		2.0
	 *
	 * @return      A Tizen::Base::Collection::IList with NetAccoundIds, which are in the registry
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The NetAccountInfo is not found in the registry.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IListT <NetAccountId>* GetNetAccountIdsN(void) const;

	/**
	 * Gets a list of names of all the registered accounts.
	 *
	 * @since		2.0
	 *
	 * @return		A Tizen::Base::Collection::IList containing the indexes to the NetAccountInfos in the registry
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The NetAccountInfo is not found in the registry.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetNetAccountNamesN(void) const;

	/**
	 * Gets a network account, which has the specified name.
	 *
	 * @since		2.0
	 *
	 * @return		The NetAccountID with the specified name, @n
	 *				else @c INVALID_HANDLE in case of an error or if NetAccountInfo is not found
	 * @param[in]	netAccountName		The network account name to search for
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c netAccountName is invalid or NetAccountInfo with this name does not exist.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetAccountId GetNetAccountId(const Tizen::Base::String& netAccountName) const;

	/**
	 * Gets a network account, which is set for the Tizen application on each bearer.
	 *
	 * @since		2.0
	 *
	 * @feature		%http://tizen.org/feature/network.telephony for the NET_BEARER_PS value and @n
	 * 				%http://tizen.org/feature/network.wifi for the NET_BEARER_WIFI value and @n
	 * 				%http://tizen.org/feature/network.wifi,direct for the NET_BEARER_WIFI_DIRECT value and @n
	 * 				%http://tizen.org/feature/usb.host for the NET_BEARER_USB value and @n
	 * 				%http://tizen.org/feature/network.telephony.mms for the NET_BEARER_MMS value of @c netBearerType
	 *
	 * @return		The network account, @n
	 *				else INVALID_HANDLE in case of an error or if NetAccountInfo is not found
	 * @param[in]	netBearerType		The network account type of bearer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband).
	 * @exception	E_UNSUPPORTED_OPERATION	The target device does not support the required feature. @b Since: @b 2.1
	 * 					For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 * 				- The specific error code can be accessed using the GetLastResult() method.
	 * 				- Before calling this method, check whether the feature is supported by 
	 *				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	NetAccountId GetNetAccountId(NetBearerType netBearerType = NET_BEARER_PS) const;

	/**
	 * Gets a network account, which is set for the application like email, IM, and so on.
	 *
	 * @since		2.0
	 *
	 * @privlevel   partner
	 * @privilege	%http://tizen.org/privilege/customnetaccount
	 * @feature		%http://tizen.org/feature/network.telephony for the L"Internet" value and @n
	 * 				%http://tizen.org/feature/network.telephony.mms for the L"Mms" value of @c netProfileName
	 *
	 * @return		The @c NetAccountID with the specified name, @n
	 *				else INVALID_HANDLE is returned in case of an error or if %NetAccountInfo is not found
	 * @param[in]	netProfileName		The network profile name for an application such as email
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The @c netAccountName is invalid or %NetAccountInfo with this name does not exist.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_UNSUPPORTED_OPERATION	The target device does not support the required feature. @b Since: @b 2.1
	 * 					For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 * 				- The specific error code can be accessed using the GetLastResult() method.
	 * 				- Before calling this method, check whether the feature is supported by 
	 *				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	NetAccountId GetAppNetAccountId(const Tizen::Base::String& netProfileName) const;

	/**
	 * Sets the application-wise default account ID to the one specified by the input argument value.
	 *
	 * @since           2.0
	 *
	 * @privlevel		partner
	 * @privilege		%http://tizen.org/privilege/customnetaccount
	 *
	 * @return			An error code
	 * @param[in]		netAccountId		The network account ID
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c netAccountId is invalid.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result SetNetAccountId(NetAccountId netAccountId);

	/**
	 * @if OSPDEPREC
	 * Gets the preferred network.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated because it is moved to the NetConnectionManager class.
	 * @since		2.0
	 *
	 * @return		The preferred network, @n
	 *				else @c NET_WIFI_FIRST in case of an error or if the preferred network is not set
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	NetPreferenceType GetNetPreference(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the preferred network.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated		This method is deprecated because it is moved to the NetConnectionManager class.
	 * @since			2.0
	 *
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/network.connection
	 * @feature			%http://tizen.org/feature/network.wifi for the NET_WIFI_ONLY value and @n
	 * 					%http://tizen.org/feature/network.telephony for the NET_PS_ONLY value of @c netPreference
	 *
	 * @return			An error code
	 * @param[in]		netPreference		The preferred network
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_OPERATION	This operation is not allowed.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception		E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception		E_UNSUPPORTED_OPERATION	The target device does not support the required feature. @b Since: @b 2.1
	 * 						For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 * 					- If this method is not used, the default connection works in the Wi-Fi first mode.
	 * 					- Before calling this method, check whether the feature is supported by 
	 *					Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @endif
	 */
	result SetNetPreference(NetPreferenceType netPreference = NET_WIFI_FIRST);

private:
	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %NetAccountManager
	 */
	NetAccountManager(const NetAccountManager& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs An instance of %NetAccountManager
	 */
	NetAccountManager& operator =(const NetAccountManager& rhs);

private:
	_NetAccountManagerImpl* __pNetAccountManagerImpl;

	friend class _NetAccountManagerImpl;
}; // NetAccountManager

} } //Tizen::Net
#endif // _FNET_NET_ACCOUNT_MANAGER_H_
