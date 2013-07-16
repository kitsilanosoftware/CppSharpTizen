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
 * @file    FNetWifiWifiDirectDeviceManager.h
 * @brief   This is the header file for the %WifiDirectDeviceManager class.
 *
 * This header file contains the declarations of the %WifiDirectDeviceManager class.
 */
#ifndef _FNET_WIFI_WIFI_DIRECT_DEVICE_MANAGER_H_
#define _FNET_WIFI_WIFI_DIRECT_DEVICE_MANAGER_H_

#include <FBaseObject.h>
#include <FNetWifiWifiTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
} } } // Tizen::Base::Collection

namespace Tizen { namespace Net { namespace Wifi
{
class _WifiDirectDeviceManagerImpl;
class WifiDirectDevice;
class WifiDirectDeviceInfo;

/**
 * @class  WifiDirectDeviceManager
 * @brief  This class provides methods for the Wi-Fi Direct device management.
 *
 * @since 2.0
 *
 * The %WifiDirectDeviceManager class provides methods for creating a WifiDirectDevice instance and
 * managing the Wi-Fi Direct devices.
 */

class _OSP_EXPORT_ WifiDirectDeviceManager
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	WifiDirectDeviceManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~WifiDirectDeviceManager(void);

	/**
	 * Gets a list of all the devices and also their information provided by the system.
	 *
	 * @since       2.0
	 *
	 * @feature     %http://tizen.org/feature/network.wifi.direct
	 *
	 * @return      A Tizen::Base::Collection::IList containing WifiDirectDeviceInfo of local devices in the system if
	 *              successful, @n
	 *              else @c null
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_SYSTEM                An internal error has occurred.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_UNSUPPORTED_OPERATION The device does not support the Wi-Fi Direct feature. For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @remarks
	 *              - Currently, a single WifiDirectDeviceInfo instance is returned because the concurrent mode is not supported.
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - Before calling this method, check whether the feature is supported by
	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	static Tizen::Base::Collection::IList* GetAllDeviceInfoN(void);

	/**
	 * Gets an instance of WifiDirectDevice.
	 *
	 * @since       2.0
	 *
	 * @feature     %http://tizen.org/feature/network.wifi.direct
	 *
	 * @return      An instance of WifiDirectDevice if successful, @n
	 *              else @c null
	 * @param[in]   pLocalDeviceInfo        A pointer to WifiDirectDeviceInfo
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_SYSTEM                An internal error has occurred.
	 * @exception   E_INVALID_ARG           The specified input parameter is invalid.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_UNSUPPORTED_OPERATION The device does not support the Wi-Fi Direct feature. For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @remarks
	 *              - If the value of @c pLocalDeviceInfo is @c null, the WifiDirectDevice instance is created for the
	 *                system default device. Otherwise, the value of @c pLocalDeviceInfo should be one of the elements
	 *                obtained from WifiDirectDeviceManager::GetAllDeviceInfoN() to create a valid %WifiDirectDevice
	 *                instance.
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - Before calling this method, check whether the feature is supported by 
	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	static WifiDirectDevice* GetWifiDirectDeviceN(const WifiDirectDeviceInfo* pLocalDeviceInfo = null);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]   value   An instance of %WifiDirectDeviceManager
	 */
	WifiDirectDeviceManager(const WifiDirectDeviceManager& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit
	 * copying of objects.
	 *
	 * @param[in]   rhs An instance of %WifiDirectDeviceManager
	 */
	WifiDirectDeviceManager& operator =(const WifiDirectDeviceManager& rhs);

private:
	_WifiDirectDeviceManagerImpl* __pWifiDirectDeviceManagerImpl;

	friend class _WifiDirectDeviceManagerImpl;
}; // WifiDirectDeviceManager

} } } // Tizen::Net::Wifi
#endif // _FNET_WIFI_WIFI_DIRECT_DEVICE_MANAGER_H_
