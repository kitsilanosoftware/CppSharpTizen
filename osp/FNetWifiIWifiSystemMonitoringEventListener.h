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
 * @file        FNetWifiIWifiSystemMonitoringEventListener.h
 * @brief       This is the header file for the %IWifiSyWifiSystemMonitoringntListener interface.
 *
 * This header file contains the declarations of the %IWifiSystemMonitoringEventListener interface.
 *
 */
#ifndef _FNET_WIFI_IWIFI_SYSTEM_MONITORING_EVENT_LISTENER_H_
#define _FNET_WIFI_IWIFI_SYSTEM_MONITORING_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Net { namespace Wifi
{
/**
 * @interface   IWifiSystemMonitoringEventListener
 * @brief       This interface provides the listeners for monitoring the Wi-Fi underlying system.
 *
 * @since 2.0
 *
 * The %IWifiSystemMonitoringEventListener interface specifies the methods used for creating notifications about the different
 * kinds of Wi-Fi system monitoring events. When a Wi-Fi system monitoring event is generated, one of these methods is called.
 */
class _OSP_EXPORT_ IWifiSystemMonitoringEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IWifiSystemMonitoringEventListener(void) {}

	/**
	 * Called to notify the application that the state of local Wi-Fi connection is changed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   state               The state of the Wi-Fi current connection
	 * @remarks     When the local device is connected with a particular access point,
	 *              IWifiManagerEventListener::OnWifiConnected() as well as this method with
	 *              @c WIFI_CONN_STATE_CONNECTED are called. Therefore, be careful to manipulate only one of those
	 *              methods. So are the cases of IWifiManagerEventListener::OnWifiDisconnected() and this method with
	 *              @c WIFI_CONN_STATE_NOT_CONNECTED.
	 */
	virtual void OnWifiConnectionStateChanged(WifiConnectionState state) = 0;

	/**
	 * Called to notify the application that the scan result of Wi-Fi system on background is updated.
	 *
	 * @since       2.0
	 *
	 * @remarks     Call WifiManager::GetSystemScanResultN() for checking the content of this update.
	 */
	virtual void OnWifiSystemScanResultUpdated(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related
	// issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void IWifiSystemMonitoringEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related
	// issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IWifiSystemMonitoringEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related
	// issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IWifiSystemMonitoringEventListener_Reserved3(void) {}

}; // IWifiSystemMonitoringEventListener

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_IWIFI_SYSTEM_MONITORING_EVENT_LISTENER_H_
