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
 * @file    FNetWifiWifiManager.h
 * @brief   This is the header file for the %WifiManager class.
 *
 * This header file contains the declarations of the %WifiManager class.
 */
#ifndef _FNET_WIFI_WIFI_MANAGER_H_
#define _FNET_WIFI_WIFI_MANAGER_H_

#include <FBaseTypes.h>
#include <FBaseResult.h>
#include <FNetWifiWifiTypes.h>
#include <FNetWifiIWifiManagerEventListener.h>

namespace Tizen { namespace Net { namespace Wifi
{
class WifiBssInfo;
class _WifiManagerImpl;
class IWifiSystemMonitoringEventListener;

/**
 * @class   WifiManager
 * @brief   This class provides methods for the local Wi-Fi device management.
 *
 * @since   2.0
 *
 *  The %WifiManager class provides methods for creating a %WifiManager instance, and managing the local Wi-Fi devices. It also allows the
 *      listener to get the events from the local Wi-Fi devices.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 *
 * The following example demonstrates how to use the %WifiManager class.
 *
 * @code
 *
 * using namespace Tizen::Net::Wifi;
 *
 * result
 * MyClass::WifiManagerSample(void)
 * {
 * 	WifiManager wifiMgr;            // Creates an instance of WifiManager
 * 	MyListenerClass wifiListener;   // Creates a listener for WifiManager
 * 	result r;
 *
 * 	// Initializes wifiMgr using the Construct method
 * 	r = wifiMgr.Construct(wifiListener);
 * 	if (IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 *
 * 	// Activates the local Wi-Fi device
 * 	r = wifiMgr.Activate();
 * 	if (IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 *
 * 	// Checks the current connection status
 * 	if (!wifiMgr.IsConnected())
 * 	{
 * 		// Deactivates the local Wi-Fi device
 * 		r = wifiMgr.Deactivate();
 * 		if (IsFailed(r))
 * 		{
 * 			goto CATCH;
 * 		}
 * 	}
 *
 * 	return r;
 *
 * CATCH:
 * 	// Do some exception handling.
 * 	return r;
 * }
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ WifiManager
	: public Tizen::Base::Object
{
public:
    /**
     * This is the default constructor for this class.
     *
     * @since       2.0
	 *
     * @remarks     After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
     * @see         Construct()
     */
    WifiManager(void);

    /**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since       2.0
     */
    virtual ~WifiManager(void);

    /**
     * Initializes this instance of %WifiManager with the specified listener.
     *
     * @since       2.0
	 *
     * @return      An error code
     * @param[in]   listener        A reference to the listener instance
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
     * @remarks     The @c listener instance must not be deleted before destructing this instance.
     */
    result Construct(IWifiManagerEventListener& listener);

    /**
     * Activates the local Wi-Fi device.
     *
     * @since       2.0
     * @privilege   %http://tizen.org/privilege/wifi.admin
     *
     * @return      An error code
     * @exception   E_SUCCESS           The activation is successful.
     * @exception   E_FAILURE           The method has failed to activate.
     * @exception   E_IN_PROGRESS       The activate process is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
     *                                  For example, the Wi-Fi is already activated.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see IWifiManagerEventListener::OnWifiActivated()
     */
    result Activate(void) const;

    /**
     * Deactivates the local Wi-Fi device.
     *
     * @since       2.0
     * @privilege   %http://tizen.org/privilege/wifi.admin
     *
     * @return      An error code
     * @exception   E_SUCCESS           The deactivation is successful.
     * @exception   E_FAILURE           The method has failed to deactivate.
     * @exception   E_IN_PROGRESS       The deactivate process is in progress.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
     *                                  For example, the Wi-Fi is already deactivated.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @see         IWifiManagerEventListener::OnWifiDeactivated()
     */
    result Deactivate(void) const;

    /**
     * Gets the current power status of the local Wi-Fi device.
     *
     * @since   2.0
	 *
     * @return  The current power status of the local Wi-Fi device
     */
    WifiPowerStatus GetPowerStatus(void) const;

    /**
     * Gets the MAC address of the Wi-Fi device.
     *
     * @since   2.0
	 *
     * @return  The MAC address in the form '00-00-00-00-00-00'
     * @remarks This MAC address is different from the MAC address provided by the WifiDirectDevice class.
     */
    Tizen::Base::String GetMacAddress(void) const;

    /**
     * Checks whether the local device is activated.
     *
     * @since   2.0
	 *
     * @return  @c true if the local device is activated, @n
     *          else @c false
     */
    bool IsActivated(void) const;

    /**
     * Checks whether the local device is connected with a remote Access Point(AP).
     *
     * @since   2.0
	 *
     * @return  @c true if the local device is connected with a remote Access Point(AP), @n
     *          else @c false
     */
    bool IsConnected(void) const;

    /**
     * Scans for a nearby BSS with both the infrastructure and independent modes.
     *
     * @since       2.0
     * @privilege   %http://tizen.org/privilege/wifi.read
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_FAILURE           The method has failed.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @remarks     Only active scan (probing for Access Points(APs) and ad hoc stations in the range) is supported.
     *              This operation does not work while the Wi-Fi Direct scanning or connection is in progress.
     * @see         IWifiManagerEventListener::OnWifiScanCompletedN()
     */
    result Scan(void);

    /**
     * Connects to a specific access point that is a BSS with an infrastructure mode.
     *
     * @since       2.0
     * @privilege   %http://tizen.org/privilege/wifi.admin
     *
     * @return      An error code
     * @param[in]   targetApInfo        A BSS information representing the target access point
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_FAILURE           The method has failed.
     * @exception   E_IN_PROGRESS       The previous request is in progress.
     * @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
     *                                  For example, the BSS type is an independent mode.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @remarks     If a connection to another access point is already established, it will be disconnected and the new connection
     *              of this method will be established.
     * @see IWifiManagerEventListener::OnWifiConnected()
     */
    result Connect(const WifiBssInfo& targetApInfo);

private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]   value   An instance of %WifiManager
     */
    WifiManager(const WifiManager& value);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]   rhs     An instance of %WifiManager
     */
    WifiManager& operator=(const WifiManager& rhs);

private:
    _WifiManagerImpl* __pWifiManagerImpl;

    friend class _WifiManagerImpl;
}; // WifiManager

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_MANAGER_H_
