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
* @file    FTelITelephonyNetworkSettingListener.h
* @brief   This is the header file for the %ITelephonyNetworkSettingListener interface.
*
* This header file contains the declarations of the %ITelephonyNetworkSettingListener interface.
*/
#ifndef _FTEL_ITELEPHONY_NETWORK_SETTING_LISTENER_H_
#define _FTEL_ITELEPHONY_NETWORK_SETTING_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
} } } // Tizen::Base::Collection

namespace Tizen { namespace Telephony
{
/**
* @interface   ITelephonyNetworkSettingListener
* @brief       This interface provides result of the network settings.
*
* @since 2.0
*
* The %ITelephonyNetworkSettingListener interface provides result of the network search and response by selection mode.
*/
class _OSP_EXPORT_ ITelephonyNetworkSettingListener
    : virtual public Tizen::Base::Runtime::IEventListener
{
public:
    /**
     * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since 2.0
     */
    virtual ~ITelephonyNetworkSettingListener(void) {}

    /**
     * Called when a response of the network selection mode request is received.
     *
     * @since 2.0
     *
     * @param[in]   isManual    @c true if the network selection is in manual mode, @n
     *                          else @c false
     * @param[in]   r           An error code
     * @exception   E_SUCCESS                  The method is successful.
     * @exception   E_NOT_RESPONDING    The server on the telephony network is not responding.
     * @exception   E_SYSTEM                     The method cannot proceed due to a severe telephony modem error.
     * @see NetworkManager::GetNetworkSelectionMode()
     */
    virtual void OnTelephonyNetworkSelectionModeReceived(bool isManual, result r) = 0;

    /**
     * Called when the network search process is completed.
     *
     * @since 2.0
     *
     * @param[in]   pNetworkInfoList    The list of NetworkInfo information representing the network discovered by the search
     * @param[in]   r                   An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_NOT_RESPONDING    The server on the telephony network is not responding.
     * @exception   E_SYSTEM            The method cannot proceed due to a severe telephony modem error.
     * @see NetworkManager::SearchNetwork()
     */
    virtual void OnTelephonyNetworkSearchCompletedN(Tizen::Base::Collection::IList* pNetworkInfoList, result r) = 0;

    /**
     * Called when a response of the network selection request is completed.
     *
     * @since 2.0
     *
     * @param[in]   r   An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_NOT_RESPONDING    The server on the telephony network is not responding.
     * @exception   E_SYSTEM            The method cannot proceed due to a severe telephony modem error.
     * @see NetworkManager::SelectNetwork()
     */
    virtual void OnTelephonyNetworkSelectionCompleted(result r) = 0;

protected:
    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    // This method is reserved and may change its name at any time without prior notice.
    //
    // @since 2.0
    //
    virtual void ITelephonyNetworkSettingListener_Reserved1(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    // This method is reserved and may change its name at any time without prior notice.
    //
    // @since 2.0
    //
    virtual void ITelephonyNetworkSettingListener_Reserved2(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    // This method is reserved and may change its name at any time without prior notice.
    //
    // @since 2.0
    //
    virtual void ITelephonyNetworkSettingListener_Reserved3(void) {}
}; // ITelephonyNetworkSettingListener

}} // Tizen::Telephony
#endif // _FTEL_ITELEPHONY_NETWORK_SETTING_LISTENER_H_

