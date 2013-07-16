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
 * @file	FTelNetworkStatus.h
 * @brief	This is the header file for the %NetworkStatus class.
 *
 * This header file contains the declarations of the %NetworkStatus class.
 */
#ifndef _FTEL_NETWORK_STATUS_H_
#define _FTEL_NETWORK_STATUS_H_

#include <FBase.h>

namespace Tizen { namespace Telephony
{
class _NetworkStatusImpl;

/**
 * @class	NetworkStatus`
 * @brief	This class provides status information of the current network.
 *
 * @since	2.0
 *
 * The %NetworkStatus class provides methods to get status information of the current network, such as the roaming status, whether call service is available or not, and whether data service is available or not.
 *
 * The following example demonstrates how to use the %NetworkStatus class to get the network status information.
 *
 * @code
 *
 *  #include <FBase.h>
 *  #include <FTelephony.h>
 *
 *   using namespace Tizen::Base;
 *   using namespace Tizen::Telephony;
 *
 *   class MyClass
 *  	 : public Object
 *  	 , public ITelephonyNetworkEventListener
 *   {
 *     public:
 *  	 MyClass(void) {}
 *  	 ~MyClass(void) {}
 *
 *  	 // ITelephonyNetworkEventListener
 *  	 void OnTelephonyNetworkStatusChanged(const NetworkStatus& networkStatus);
 *
 *  	 void GetNetworkStatus (void);
 *   };
 *   void
 *   MyClass::OnTelephonyNetworkStatusChanged(const NetworkStatus& networkStatus)
 *   {
 *  	//Do something.
 *   }
 *
 *   void
 *   MyClass::GetNetworkStatus(void)
 *   {
 *  	 NetworkStatus networkStatus;
 *
 *  	 NetworkManager* pNetworkManager = new (std::nothrow) NetworkManager();
 *  	 result r = pNetworkManager->Construct(this);
 *  	 if (IsFailed(r))
 *  	 {
 *  		 delete pNetworkManager;
 *  		 return;
 *  	 }
 *
 *  	 r = pNetworkManager->GetNetworkStatus(networkStatus);
 *  	 if (IsFailed(r))
 *  	 {
 *  		 delete pNetworkManager;
 *  		 return;
 *  	 }
 *
 *  	 bool isCallAvailable = networkStatus.IsCallServiceAvailable();
 *  	 bool isDataAvailable = networkStatus.IsDataServiceAvailable();
 *  	 bool isRoaming = networkStatus.IsRoaming();
 *
 *  	 delete pNetworkManager;
 *  	 return;
 *   }
 *
 * @endcode
 */
class _OSP_EXPORT_ NetworkStatus
	: public Tizen::Base::Object
{
public:
	/**
     * This is the default constructor for this class.
     *
     * @since	2.0
     */
	NetworkStatus(void);

	/**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since	2.0
     */
	virtual ~NetworkStatus(void);

	/**
     * Checks whether the current network is in roaming status or not.
     *
     * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return	@c true if the current network is in roaming status, @n
     *                  else @c false
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	bool IsRoaming(void) const;

    /**
     * Checks whether call service is available or not.
     *
     * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return	@c true if call service is available, @n
     *          else @c false
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	bool IsCallServiceAvailable(void) const;

	/**
     * Checks whether data service is available or not.
     *
     * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return	@c true if data service is available, @n
     *          else @c false
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	bool IsDataServiceAvailable(void) const;

private:
	/**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %NetworkStatus
     */
	NetworkStatus(const NetworkStatus& rhs);

	/**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %NetworkStatus
     */
	NetworkStatus& operator =(const NetworkStatus& rhs);

private:
	_NetworkStatusImpl* __pNetworkStatusImpl;

	friend class _NetworkStatusImpl;
}; // NetworkStatus

}} // Tizen::Telephony
#endif // _FTEL_NETWORK_STATUS_H_
