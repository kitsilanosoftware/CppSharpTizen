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
 * @file	FNetWifiIWifiManagerEventListener.h
 * @brief	This is the header file for the %IWifiManagerEventListener interface.
 *
 * This header file contains the declarations of the %IWifiManagerEventListener interface.
 *
 */
#ifndef _FNET_WIFI_IWIFI_MANAGER_EVENT_LISTENER_H_
#define _FNET_WIFI_IWIFI_MANAGER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseColArrayList.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Net { namespace Wifi
{
/**
 * @interface   IWifiManagerEventListener
 * @brief       This interface provides the listeners for WifiManager events.
 *
 * @since   2.0
 *
 * The %IWifiManagerEventListener interface specifies the methods used for creating notifications about the different kinds of WifiManager events. These events are only sent
 *  out when using %WifiManager. When a %WifiManager event is generated, a method of this class is called. Thus, if an application provides any functionality related to the %WifiManager events, override and use the methods of this interface.
 *  This interface specifies the methods used for creating notifications about the different kinds of %WifiManager events.
 *  
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */
class _OSP_EXPORT_ IWifiManagerEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
    /**
     * This polymorphic destructor should be overridden if required. This way, 
     * the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since  2.0
     */
    virtual ~IWifiManagerEventListener(void) {}

    /**
      * Called to notify the application that the local Wi-Fi radio is activated.
      *
      * @since       2.0
	  *
      * @param[in]   r           The error code that occurs during the activation
      * @exception   E_SUCCESS   The activation is successful.
      * @exception   E_FAILURE   The method has failed to activate.
      * @see         WifiManager::Activate()
      */
    virtual void OnWifiActivated(result r) = 0;

    /**
      * Called to notify the application that the local Wi-Fi radio is deactivated.
      *
      * @since       2.0
	  *
      * @param[in]   r           The error code that occurs during the deactivation
      * @exception   E_SUCCESS   The deactivation is successful.
      * @exception   E_FAILURE   The method has failed to deactivate.
      * @see WifiManager::Deactivate()
      */
    virtual void OnWifiDeactivated(result r) = 0;

    /**
      * Called to notify that the connection to an access point (only an infrastructure mode BSS) has been completely established.
      *
      * @since       2.0
	  *
      * @param[in]   ssid                The SSID of the connected BSS
      * @param[in]   r                   The error code that occurs during the connection
      * @exception   E_SUCCESS           The connection is successful.
      * @exception   E_FAILURE           The method has failed to connect.
      * @exception   E_AUTHENTICATION    The authentication fails when Wi-Fi is connected.
      * @exception   E_NOT_RESPONDING    The target is not responding when Wi-Fi is connected.
      * @exception   E_DHCP              The DHCP fails in case of a dynamic IP.
      * @see         WifiManager::Connect()
      */
    virtual void OnWifiConnected(const Tizen::Base::String& ssid, result r) = 0;

    /**
      * Called to notify that the connection to a BSS has been terminated.
      *
      * @since   2.0
      */
    virtual void OnWifiDisconnected(void) = 0;

    /**
      * Called to notify that the Received Signal Strength Indication (RSSI) from BSS has been changed.
      *
      * @since       2.0
	  *
      * @param[in]   rssi    The updated RSSI value (dbm)
      */
    virtual void OnWifiRssiChanged(long rssi) = 0;

    /**
      * Called to notify that the scan to find the access points has been completed.
      *
      * @since       2.0
	  *
      * @param[in]   pWifiBssInfoList    The list of WifiBssInfo information representing the access points discovered by the scan
      * @param[in]   r                   The error code that occurs during the scan
      * @exception   E_SUCCESS           The scan is successful.
      * @exception   E_FAILURE           The scan has failed.
      * @see         WifiManager::Scan()
      */
    virtual void OnWifiScanCompletedN(const Tizen::Base::Collection::IList* pWifiBssInfoList, result r) = 0;

protected:
    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    // This method is reserved and may change its name at any time without prior notice.
    //
    // @since 2.0
    //
    virtual void IWifiManagerEventListener_Reserved1(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    // This method is reserved and may change its name at any time without prior notice.
    //
    // @since 2.0
    //
    virtual void IWifiManagerEventListener_Reserved2(void) {}
}; // IWifiManagerEventListener

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_IWIFI_MANAGER_EVENT_LISTENER_H_
