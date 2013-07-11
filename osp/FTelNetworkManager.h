//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file	FTelNetworkManager.h
 * @brief	This is the header file for the %NetworkManager class.
 *
 * This header file contains the declarations of the %NetworkManager class.
 */
#ifndef _FTEL_NETWORK_MANAGER_H_
#define _FTEL_NETWORK_MANAGER_H_


#include <FBase.h>
#include <FTelNetworkInfo.h>
#include <FTelNetworkStatus.h>


namespace Tizen { namespace Telephony
{
class _NetworkManagerImpl;
class ITelephonyNetworkEventListener;
class ITelephonyNetworkSettingListener;

/**
 * @class	NetworkManager
 * @brief	This class provides information about the current active network.
 *
 * @since	2.0
 *
 * The %NetworkManager class is used to register listeners who monitor network status changes,
 * as well as get information about current active network.
 *
 * The following example demonstrates how to use the %NetworkManager class to get the network information.
 *
 * @code
 *
 *	result
 *	MyClass::GetNetworkManagerInfo(void)
 *	{
 *		NetworkStatus networkStatus;
 *		NetworkInfo networkInfo;
 *
 *		NetworkManager* pNetworkManager = new NetworkManager();
 *
 *		result r = pNetworkManager->Construct(this);
 *		if (IsFailed(r))
 *		{
 *			delete pNetworkManager;
 *			return r;
 *		}
 *
 *		r = pNetworkManager->GetNetworkStatus(networkStatus);
 *		if (IsFailed(r))
 *		{
 *			delete pNetworkManager;
 *			return r;
 *		}
 *
 *		r = pNetworkManager->GetNetworkInfo(networkInfo);
 *		if (IsFailed(r))
 *		{
 *			delete pNetworkManager;
 *			return r;
 *		}
 *
 *		delete pNetworkManager;
 *		return E_SUCCESS;
 *	}
 *
 *	void
 *	MyClass::OnTelephonyNetworkStatusChanged(const NetworkStatus& networkStatus)
 *	{
 *		bool isCallAvail = networkStatus.IsCallServiceAvailable();
 *		bool isDataAvail = networkStatus.IsDataServiceAvailable();
 *		bool isRoaming = networkStatus.IsRoaming();
 *	}
 *
 * @endcode
 */
class _OSP_EXPORT_ NetworkManager
	: public Tizen::Base::Object
{
public:
	/**
     * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since   2.0
     */
	NetworkManager(void);

	/**
     *	This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since	2.0
     */
	virtual ~NetworkManager(void);

	/**
     *	Initializes a new instance of this class. @n
     *	This is the two phase construction.
	 * If a @c null pointer is passed during the construction, then there
     *	is no listener for telephony network status change callbacks.
     *
     * @since		2.0
	 *
     * @return		An error code
	 * @param[in]   pListener   	The listener for change in status of a telephony network
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_SYSTEM		A system error has occurred.
     */
	result Construct(ITelephonyNetworkEventListener* pListener);

	/**
     * Gets the network status.
     *
     * @since		2.0
     * @privilege   %http://tizen.org/privilege/systeminfo
     *
     * @return		An error code
     * @param[out]	networkStatus	The network status
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_NETWORK_UNAVAILABLE	The operation has failed because the device is in the offline mode.
     * @exception	E_SERVICE_UNAVAILABLE	The operation has failed because the device is out of the coverage area or in the emergency mode.
     * @exception	E_SYSTEM	A system error has occurred.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     */
	result GetNetworkStatus(NetworkStatus& networkStatus) const;

	/**
     * Gets the network information.
     *
     * @since	2.0
     * @privilege   %http://tizen.org/privilege/systeminfo
     *
     * @return	An error code
     * @param[out]	networkInfo	The network information
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_NETWORK_UNAVAILABLE	The operation has failed because the device is in the offline mode.
     * @exception	E_SERVICE_UNAVAILABLE	The operation has failed because the device is out of the coverage area or in the emergency mode.
     * @exception	E_SYSTEM	A system error has occurred.
     * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     */
	result GetNetworkInfo(NetworkInfo& networkInfo) const;


private:
	/**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %NetworkManager
     */
	NetworkManager(const NetworkManager& rhs);

	/**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %NetworkManager
     */
	NetworkManager& operator =(const NetworkManager& rhs);

private:
	_NetworkManagerImpl * __pNetworkManagerImpl;

	friend class _NetworkManagerImpl;
}; // NetworkManager

}} // Tizen::Telephony
#endif // _FTEL_NETWORK_MANAGER_H_
